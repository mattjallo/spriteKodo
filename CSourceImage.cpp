#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include <wx/wfstream.h>
#include <wx/filename.h>
#include "CSourceImage.h"

IMPLEMENT_CLASS(CSourceImage, wxObject)

bool CSourceImage::LoadImage(const wxString& path)
{
    try
    {
        wxFileName fname;
        fname.Assign(path);
        this->name = fname.GetName();
        wxFileInputStream inputStream(path);
        this->sourceImage = new wxImage(inputStream);
        this->left = -1;
        this->top = -1;
        this->width = this->sourceImage->GetWidth();
        this->height = this->sourceImage->GetHeight();
    }
    catch(...)
    {
        return false;
    }
    return true;
}

CSourceImage::~CSourceImage()
{
    
}

CSourceImage::CSourceImage()
{
    this->sourceImage = NULL;
}

wxString CSourceImage::GetName()
{
    return this->name;
}

int CSourceImage::GetWidth()
{
    return this->width;
}

int CSourceImage::GetHeight()
{
    return this->height;
}

int CSourceImage::GetLeft()
{
    return this->left;
}

int CSourceImage::GetTop()
{
    return this->top;
}

void CSourceImage::SetLeft(int left)
{
    this->left = left;
}    

void CSourceImage::SetTop(int top)
{
    this->top = top;
}

//Compare, based alphabetically on name
int CSourceImage::Compare(CSourceImage **first, CSourceImage **second)
{
    return (*first)->GetName().CmpNoCase((*second)->GetName());
}

//Compare, based on image area
int CSourceImage::CompareArea(CSourceImage **first, CSourceImage **second)
{
    int areaFirst = (*first)->GetWidth()*(*first)->GetHeight();
    int areaSecond = (*second)->GetWidth()*(*second)->GetHeight();
    
    if(areaFirst == areaSecond)
        return 0;
    if(areaFirst > areaSecond)
        return -1;
    return 1;
}

wxImage* CSourceImage::GetImage()
{
    return this->sourceImage;
}

#include <wx/arrimpl.cpp>
WX_DEFINE_OBJARRAY(SourceImageList);

