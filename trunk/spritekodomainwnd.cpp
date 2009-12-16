// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

////@begin includes
#include "wx/imaglist.h"
////@end includes

#include "spritekodomainwnd.h"
#include "CSourceImage.h"
#include "Packing.h"
#include <wx/colordlg.h>
////@begin XPM images
////@end XPM images


/*
 * spriteKodoMainWnd type definition
 */

IMPLEMENT_CLASS( spriteKodoMainWnd, wxFrame )


/*
 * spriteKodoMainWnd event table definition
 */

BEGIN_EVENT_TABLE( spriteKodoMainWnd, wxFrame )

////@begin spriteKodoMainWnd event table entries
    EVT_BUTTON( ID_ADDIMAGES, spriteKodoMainWnd::OnAddimagesClick )

    EVT_BUTTON( ID_COLORCHOOSE, spriteKodoMainWnd::OnColorchooseClick )

    EVT_BUTTON( ID_GENERATE, spriteKodoMainWnd::OnGenerateClick )

    EVT_BUTTON( ID_SAVE, spriteKodoMainWnd::OnSaveClick )

////@end spriteKodoMainWnd event table entries

END_EVENT_TABLE()


/*
 * spriteKodoMainWnd constructors
 */

spriteKodoMainWnd::spriteKodoMainWnd()
{
    Init();
}

spriteKodoMainWnd::spriteKodoMainWnd( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
    Init();
    Create( parent, id, caption, pos, size, style );
}


/*
 * spriteKodoMainWnd creator
 */

bool spriteKodoMainWnd::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
////@begin spriteKodoMainWnd creation
    wxFrame::Create( parent, id, caption, pos, size, style );

    CreateControls();
    SetIcon(GetIconResource(wxT("goat.ico")));
    Centre();
////@end spriteKodoMainWnd creation

    _sourceImages->InsertColumn(0, _("Name"), wxLIST_FORMAT_LEFT, 300);

    _outputFormat->Append(_("PNG"));
    _outputFormat->Append(_("JPG"));
    _outputFormat->Append(_("BMP"));
    _outputFormat->Append(_("XPM"));

    return true;
}


/*
 * spriteKodoMainWnd destructor
 */

spriteKodoMainWnd::~spriteKodoMainWnd()
{
////@begin spriteKodoMainWnd destruction
////@end spriteKodoMainWnd destruction
}


/*
 * Member initialisation
 */

void spriteKodoMainWnd::Init()
{
////@begin spriteKodoMainWnd member initialisation
    _sourceImages = NULL;
    _cmdAddImages = NULL;
    _cbTransparentBackground = NULL;
    _backgroundColor = NULL;
    _outputSizer = NULL;
    _outputFormat = NULL;
    _staticPreview = NULL;
////@end spriteKodoMainWnd member initialisation
}


/*
 * Control creation for spriteKodoMainWnd
 */

void spriteKodoMainWnd::CreateControls()
{    
////@begin spriteKodoMainWnd content construction
    spriteKodoMainWnd* itemFrame1 = this;

    wxBoxSizer* itemBoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    itemFrame1->SetSizer(itemBoxSizer2);

    wxStaticBox* itemStaticBoxSizer3Static = new wxStaticBox(itemFrame1, wxID_ANY, _("Operations"));
    wxStaticBoxSizer* itemStaticBoxSizer3 = new wxStaticBoxSizer(itemStaticBoxSizer3Static, wxVERTICAL);
    itemBoxSizer2->Add(itemStaticBoxSizer3, 1, wxGROW|wxALL, 1);

    wxStaticText* itemStaticText4 = new wxStaticText( itemFrame1, wxID_STATIC, _("Source Images:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStaticBoxSizer3->Add(itemStaticText4, 0, wxALIGN_LEFT|wxALL, 2);

    _sourceImages = new wxListCtrl( itemFrame1, ID_LISTCTRL, wxDefaultPosition, wxSize(100, 100), wxLC_REPORT );
    itemStaticBoxSizer3->Add(_sourceImages, 1, wxGROW|wxALL, 1);

    wxBoxSizer* itemBoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
    itemStaticBoxSizer3->Add(itemBoxSizer6, 0, wxGROW|wxALL, 0);

    _cmdAddImages = new wxButton( itemFrame1, ID_ADDIMAGES, _("Add"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer6->Add(_cmdAddImages, 1, wxALIGN_CENTER_VERTICAL|wxALL, 1);

    wxButton* itemButton8 = new wxButton( itemFrame1, ID_REMOVEIMAGE, _("Button"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer6->Add(itemButton8, 1, wxALIGN_CENTER_VERTICAL|wxALL, 1);

    wxStaticLine* itemStaticLine9 = new wxStaticLine( itemFrame1, wxID_STATIC, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
    itemStaticBoxSizer3->Add(itemStaticLine9, 0, wxGROW|wxALL, 5);

    wxStaticBox* itemStaticBoxSizer10Static = new wxStaticBox(itemFrame1, wxID_ANY, _("Background"));
    wxStaticBoxSizer* itemStaticBoxSizer10 = new wxStaticBoxSizer(itemStaticBoxSizer10Static, wxVERTICAL);
    itemStaticBoxSizer3->Add(itemStaticBoxSizer10, 0, wxGROW|wxALL, 1);

    _cbTransparentBackground = new wxCheckBox( itemFrame1, ID_CHECKBOX, _("Transparent Background"), wxDefaultPosition, wxDefaultSize, 0 );
    _cbTransparentBackground->SetValue(false);
    itemStaticBoxSizer10->Add(_cbTransparentBackground, 0, wxALIGN_LEFT|wxALL, 1);

    wxBoxSizer* itemBoxSizer12 = new wxBoxSizer(wxHORIZONTAL);
    itemStaticBoxSizer10->Add(itemBoxSizer12, 0, wxGROW|wxALL, 1);

    wxButton* itemButton13 = new wxButton( itemFrame1, ID_COLORCHOOSE, _("Set Color"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer12->Add(itemButton13, 1, wxALIGN_CENTER_VERTICAL|wxALL, 1);

    _backgroundColor = new wxStaticText( itemFrame1, wxID_STATIC, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    _backgroundColor->SetBackgroundColour(wxColour(255, 255, 255));
    itemBoxSizer12->Add(_backgroundColor, 1, wxGROW|wxALL, 5);

    wxButton* itemButton15 = new wxButton( itemFrame1, ID_GENERATE, _("Generate"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStaticBoxSizer3->Add(itemButton15, 0, wxGROW|wxALL, 1);

    _outputSizer = new wxStaticBox(itemFrame1, wxID_ANY, _("Output"));
    wxStaticBoxSizer* itemStaticBoxSizer16 = new wxStaticBoxSizer(_outputSizer, wxVERTICAL);
    itemStaticBoxSizer3->Add(itemStaticBoxSizer16, 0, wxGROW|wxALL, 1);

    wxBoxSizer* itemBoxSizer17 = new wxBoxSizer(wxHORIZONTAL);
    itemStaticBoxSizer16->Add(itemBoxSizer17, 0, wxGROW|wxALL, 1);

    wxStaticText* itemStaticText18 = new wxStaticText( itemFrame1, wxID_STATIC, _("Output Format:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer17->Add(itemStaticText18, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxArrayString _outputFormatStrings;
    _outputFormat = new wxChoice( itemFrame1, ID_OUTPUTFORMAT, wxDefaultPosition, wxDefaultSize, _outputFormatStrings, 0 );
    itemBoxSizer17->Add(_outputFormat, 2, wxALIGN_CENTER_VERTICAL|wxALL, 1);

    wxButton* itemButton20 = new wxButton( itemFrame1, ID_SAVE, _("Save"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStaticBoxSizer16->Add(itemButton20, 0, wxGROW|wxALL, 1);

    wxStaticBox* itemStaticBoxSizer21Static = new wxStaticBox(itemFrame1, wxID_ANY, _("Preview"));
    wxStaticBoxSizer* itemStaticBoxSizer21 = new wxStaticBoxSizer(itemStaticBoxSizer21Static, wxVERTICAL);
    itemBoxSizer2->Add(itemStaticBoxSizer21, 3, wxGROW|wxALL, 1);

    _staticPreview = new wxStaticBitmap( itemFrame1, wxID_STATIC, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
    itemStaticBoxSizer21->Add(_staticPreview, 1, wxGROW|wxALL, 1);

////@end spriteKodoMainWnd content construction
}


/*
 * Should we show tooltips?
 */

bool spriteKodoMainWnd::ShowToolTips()
{
    return true;
}

/*
 * Get bitmap resources
 */

wxBitmap spriteKodoMainWnd::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin spriteKodoMainWnd bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end spriteKodoMainWnd bitmap retrieval
}

/*
 * Get icon resources
 */

wxIcon spriteKodoMainWnd::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin spriteKodoMainWnd icon retrieval
    wxUnusedVar(name);
    if (name == _T("goat.ico"))
    {
        wxIcon icon(_T("goat.ico"), wxBITMAP_TYPE_ICO);
        return icon;
    }
    return wxNullIcon;
////@end spriteKodoMainWnd icon retrieval
}


/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_ADDIMAGES
 */

void spriteKodoMainWnd::OnAddimagesClick( wxCommandEvent& event )
{
    wxArrayString paths = wxArrayString();
    wxFileDialog* fdSourceImages = new wxFileDialog(this, _("Choose source images to add"), _(""), _(""), _("Images (bmp, gif, jpg, png)|*.bmp;*.gif;*.jpg;*.jpeg;*.png"), wxFD_MULTIPLE | wxFD_OPEN, wxDefaultPosition);
    if(fdSourceImages->ShowModal() == wxID_OK)
    {
        fdSourceImages->GetPaths(paths);
        size_t fileCount = paths.GetCount();
        for(size_t i=0; i<fileCount; i++)
        {
            CSourceImage image = CSourceImage();
            if(image.LoadImage(paths[i]))
            {
                _sourceImageList.Add(image);
            }
        }
    }
    delete fdSourceImages;
    _sourceImageList.Sort(CSourceImage::Compare);
    UpdateSourceImageList();
}

void spriteKodoMainWnd::UpdateSourceImageList()
{
    _sourceImages->DeleteAllItems();
    size_t imageCount = _sourceImageList.GetCount();
    for(size_t i = 0; i<imageCount; i++)
    {
        _sourceImages->InsertItem((long)i, _sourceImageList[i].GetName()); 
    }
}


/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_GENERATE
 */

void spriteKodoMainWnd::OnGenerateClick( wxCommandEvent& event )
{
    GeneratePreview();
}

void spriteKodoMainWnd::GenerateBitmap()
{
    _sourceImageList.Sort(CSourceImage::CompareArea);
    
    RP_Node node;
    node.left = 0;
    node.top = 0;
    node.width = 2000;
    node.height = 10000;
    
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
    
    _bitmap = new wxBitmap(maxWidth, maxHeight);
    
    wxMemoryDC mdc;
    mdc.SelectObject(*_bitmap);
    
    int bgStyle = (_cbTransparentBackground->IsChecked() ? wxTRANSPARENT : wxSOLID);
    wxBrush bgBrush(_backgroundColor->GetBackgroundColour(), bgStyle);
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

void spriteKodoMainWnd::GeneratePreview()
{
    this->GenerateBitmap();
    
    int bmpWidth = _bitmap->GetWidth();
    int bmpHeight = _bitmap->GetHeight();
    
    int previewWidth = bmpWidth;
    int previewHeight = bmpHeight;
    
    wxSize previewSize = _staticPreview->GetClientSize();
    
    if(previewHeight > previewSize.GetHeight())
    {
        float heightScale = ((float)previewSize.GetHeight()) / ((float)previewHeight);
        previewWidth = (int)(previewWidth * heightScale);
        previewHeight = (int)(previewHeight * heightScale);
    }

    if(previewWidth > previewSize.GetWidth())
    {
        float widthScale = ((float)previewSize.GetWidth()) / ((float)previewWidth);
        previewWidth = (int)(previewWidth * widthScale);
        previewHeight = (int)(previewHeight * widthScale);
    }
    
    wxImage image = _bitmap->ConvertToImage();
    wxBitmap bmp(image.Scale(previewWidth, previewHeight));
    _staticPreview->SetBitmap(bmp); 
}




/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_COLORCHOOSE
 */

void spriteKodoMainWnd::OnColorchooseClick( wxCommandEvent& event )
{
    wxColour bgColor = _backgroundColor->GetBackgroundColour();
    wxColourData cData;
    cData.SetColour(bgColor);
    wxColourDialog dialog(this, &cData);
    if(dialog.ShowModal()==wxID_OK)
    {
        _backgroundColor->SetBackgroundColour(dialog.GetColourData().GetColour());
        _backgroundColor->Refresh();
        _backgroundColor->Update();
    }
}


/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_SAVE
 */

void spriteKodoMainWnd::OnSaveClick( wxCommandEvent& event )
{
    if(_bitmap == NULL)
        GenerateBitmap();
        
    int type = 0;
    wxString filter = _("*.*");
    
    int cSel = _outputFormat->GetSelection();
    if(cSel == 0)
    {
        type = wxBITMAP_TYPE_PNG;
        filter = _("*.png");
    }
    if(cSel == 1)
    {
        type = wxBITMAP_TYPE_JPEG;
        filter = _("*.jpg");
    }
    if(cSel == 2)
    {
        type = wxBITMAP_TYPE_BMP;
        filter = _("*.bmp");
    }
    if(cSel == 3)
    {
        type = wxBITMAP_TYPE_XPM;
        filter = _("*.xpm");
    }
    
    wxImage image = _bitmap->ConvertToImage();
    
    wxFileDialog fdialog(this, _("Choose filename"), _(""), _(""), filter, wxFD_SAVE | wxFD_OVERWRITE_PROMPT);
    if(fdialog.ShowModal()==wxID_OK)
    {
        wxString filename = fdialog.GetPath();
        image.SaveFile(filename, type);
    }
}

