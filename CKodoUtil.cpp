#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include "CKodoUtil.h"
#include <wx/file.h>
#include "Packing.h"
#include "CSourceImage.h"

IMPLEMENT_CLASS(CKodoUtil, wxObject)

CKodoUtil* CKodoUtil::instance = NULL;

CKodoUtil* CKodoUtil::Instance()
{
    wxASSERT(instance!=NULL);
    return instance;
}

CKodoUtil::CKodoUtil()
{
    instance = this;
    _bitmap = NULL;
    _backgroundColor = new wxColour;
    _backgroundColor->Set(_("#FFFFFF"));
    _cssPrefix = _(".spr-");
    _outputType = _("PNG");
    _transparentBackground = true;
    _maxWidth = 4000;
}

CKodoUtil::~CKodoUtil()
{
    if(_bitmap!=NULL)
        delete _bitmap;
    delete _backgroundColor;
}

void CKodoUtil::SetBackgroundColor(const wxColour& color)
{
    (*_backgroundColor)=color;
}

wxColour CKodoUtil::GetBackgroundColor()
{
    wxColour newColor( (*_backgroundColor) );
    return newColor;
}

void CKodoUtil::SetTransparentBackground(bool transparent)
{
    _transparentBackground = transparent;
}

bool CKodoUtil::GetTransparentBackground()
{
    return _transparentBackground;
}

void CKodoUtil::SetMaxWidth(int maxWidth)
{
    _maxWidth = maxWidth;
}

int CKodoUtil::GetMaxWidth()
{
    return _maxWidth;
}

void CKodoUtil::SetCssPrefix(const wxString& prefix)
{
    _cssPrefix = prefix;
}

wxString CKodoUtil::GetCssPrefix()
{
    return _cssPrefix;
}

void CKodoUtil::SetOutputType(const wxString& outputType)
{
    _outputType = outputType;
}

wxString CKodoUtil::GetOutputType()
{
    return _outputType;
}

bool CKodoUtil::AddImageFile(const wxString& path)
{
    try
    {
        CSourceImage image;
        if(image.LoadImage(path))
        {
            _sourceImageList.Add(image);
            return true;
        }
        else
        {
            WriteToStdErr(_("Warning: ") + path + _(" not included."));
            return false;
        }
    }
    catch(...)
    {
        WriteToStdErr(_("Error: While loading ") + path);
        return false;
    }
}

void CKodoUtil::Generate()
{
    try
    {
        GenerateBitmap();
        GenerateCSS();
    }
    catch(...)
    {
        WriteToStdErr(_("Error: Failed to generate sprite/css."));
    }
}

void CKodoUtil::GenerateBitmap()
{
    _sourceImageList.Sort(CSourceImage::CompareArea);
    
    RP_Node node;
    node.left = 0;
    node.top = 0;
    node.width = _maxWidth;
    node.height = 100000;
    
    size_t imageCount = _sourceImageList.GetCount();
    for(size_t i=0; i<imageCount; i++)
    {
        CSourceImage* srcImage = &(_sourceImageList[i]);
        node.Insert(srcImage);
    }
    
    node.Unwind();
    
    int maxWidth = 0;
    int maxHeight = 0;
    
    for(size_t i=0; i<imageCount; i++)
    {
        CSourceImage img = _sourceImageList[i];
        if(img.GetLeft() + img.GetWidth() > maxWidth)
            maxWidth = img.GetLeft() + img.GetWidth();
        if(img.GetTop() + img.GetHeight() > maxHeight)
            maxHeight = img.GetTop() + img.GetHeight();
    }
    
    if(_bitmap != NULL)
        delete _bitmap;
    _bitmap = new wxBitmap(maxWidth, maxHeight);
    
    wxMemoryDC mdc;
    mdc.SelectObject(*_bitmap);
    
    int bgStyle = (_transparentBackground ? wxTRANSPARENT : wxSOLID);
    wxBrush bgBrush(*_backgroundColor, bgStyle);
    mdc.SetBackground(bgBrush);
    mdc.Clear();
    
    for(size_t i=0; i<imageCount; i++)
    {
        wxMemoryDC sourceDC;
        wxBitmap sourceBitmap(*_sourceImageList[i].GetImage());
        sourceDC.SelectObjectAsSource(sourceBitmap);
        
        mdc.Blit(_sourceImageList[i].GetLeft(), _sourceImageList[i].GetTop(), _sourceImageList[i].GetWidth(), _sourceImageList[i].GetHeight(), &sourceDC, 0, 0, wxCOPY, true);
    }
    
    mdc.SelectObject(wxNullBitmap);
    
    _sourceImageList.Sort(CSourceImage::Compare);
}

void CKodoUtil::GenerateCSS()
{  
    _css.Clear();
    size_t imageCount = _sourceImageList.Count();
    for(size_t i=0; i<imageCount; i++)
    {
        wxString cssClass = _cssPrefix + _sourceImageList[i].GetName() 
            + wxString::Format(_(" {\n  background-position: -%dpx -%dpx;\n  width: %dpx;\n  height: %dpx;\n}\n"),
                    _sourceImageList[i].GetLeft(), _sourceImageList[i].GetTop(), 
                    _sourceImageList[i].GetWidth(), _sourceImageList[i].GetHeight());
        _css.Append(cssClass);
    }
}

bool CKodoUtil::SaveBitmap(const wxString& path)
{
    try
    {
        if(_bitmap == NULL)
            Generate();
            
        int type = 0;
       
        if(_outputType == _("PNG"))
        {
            type = wxBITMAP_TYPE_PNG;
        }
        if(_outputType == _("JPG"))
        {
            type = wxBITMAP_TYPE_JPEG;
        }
        if(_outputType == _("BMP"))
        {
            type = wxBITMAP_TYPE_BMP;
        }
        if(_outputType == _("XPM"))
        {
            type = wxBITMAP_TYPE_XPM;
        }
        
        wxImage image = _bitmap->ConvertToImage();
        
        image.SaveFile(path, type);
        return true;
    }
    catch(...)
    {
        WriteToStdErr(_("Error: Failed to save image ") + path);
        return false;
    }
}

bool CKodoUtil::SaveCSS(const wxString& path)
{
    try
    {
        wxFile output(path, wxFile::write);
        output.Write(_css);
        output.Close();
        return true;
    }
    catch(...)
    {
        WriteToStdErr(_("Error: Failed to save CSS ") + path);
        return false;
    }
}

wxBitmap CKodoUtil::GetBitmapPreview()
{
    if(_bitmap==NULL)
        Generate();
    wxBitmap newBitmap(*_bitmap);
    return newBitmap;
}

wxString CKodoUtil::GetCSSPreview()
{
    return _css;
}

SourceImageList* CKodoUtil::GetSourceImageListReference()
{
    return &_sourceImageList;
}

void CKodoUtil::SortImagesByName()
{
    _sourceImageList.Sort(CSourceImage::Compare);
}

void CKodoUtil::WriteToStdErr(const wxString& errText)
{
    wxFile errLog;
    errLog.Attach(wxFile::fd_stderr);
    errLog.Write(errText);
    errLog.Flush();
}
