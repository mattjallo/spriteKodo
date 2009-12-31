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
#include <wx/file.h>

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

    EVT_BUTTON( ID_BROWSESPRITE, spriteKodoMainWnd::OnBrowsespriteClick )

    EVT_BUTTON( ID_SAVE, spriteKodoMainWnd::OnSaveClick )

    EVT_BUTTON( ID_BROWSECSS, spriteKodoMainWnd::OnBrowsecssClick )

    EVT_BUTTON( ID_CSSSAVE, spriteKodoMainWnd::OnCsssaveClick )

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
    _spriteFilename = NULL;
    _cssFilename = NULL;
    _staticPreview = NULL;
    _cssPreview = NULL;
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
    itemBoxSizer2->Add(itemStaticBoxSizer3, 2, wxGROW|wxALL, 1);

    wxNotebook* itemNotebook4 = new wxNotebook( itemFrame1, ID_OPERATIONSNB, wxDefaultPosition, wxDefaultSize, wxBK_DEFAULT );

    wxPanel* itemPanel5 = new wxPanel( itemNotebook4, ID_SOURCESNB, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
    wxStaticBox* itemStaticBoxSizer6Static = new wxStaticBox(itemPanel5, wxID_ANY, _("Source Images"));
    wxStaticBoxSizer* itemStaticBoxSizer6 = new wxStaticBoxSizer(itemStaticBoxSizer6Static, wxVERTICAL);
    itemPanel5->SetSizer(itemStaticBoxSizer6);

    _sourceImages = new wxListCtrl( itemPanel5, ID_LISTCTRL, wxDefaultPosition, wxSize(100, 100), wxLC_REPORT );
    itemStaticBoxSizer6->Add(_sourceImages, 1, wxGROW|wxALL, 1);

    wxBoxSizer* itemBoxSizer8 = new wxBoxSizer(wxHORIZONTAL);
    itemStaticBoxSizer6->Add(itemBoxSizer8, 0, wxGROW|wxALL, 0);
    _cmdAddImages = new wxButton( itemPanel5, ID_ADDIMAGES, _("Add"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer8->Add(_cmdAddImages, 1, wxALIGN_CENTER_VERTICAL|wxALL, 1);

    wxButton* itemButton10 = new wxButton( itemPanel5, ID_REMOVEIMAGE, _("Remove"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer8->Add(itemButton10, 1, wxALIGN_CENTER_VERTICAL|wxALL, 1);

    itemNotebook4->AddPage(itemPanel5, _("Sources"));

    wxPanel* itemPanel11 = new wxPanel( itemNotebook4, ID_OPTIONSNB, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
    wxStaticBox* itemStaticBoxSizer12Static = new wxStaticBox(itemPanel11, wxID_ANY, _("Background"));
    wxStaticBoxSizer* itemStaticBoxSizer12 = new wxStaticBoxSizer(itemStaticBoxSizer12Static, wxVERTICAL);
    itemPanel11->SetSizer(itemStaticBoxSizer12);

    _cbTransparentBackground = new wxCheckBox( itemPanel11, ID_CHECKBOX, _("Transparent Background"), wxDefaultPosition, wxDefaultSize, 0 );
    _cbTransparentBackground->SetValue(false);
    itemStaticBoxSizer12->Add(_cbTransparentBackground, 0, wxALIGN_LEFT|wxALL, 1);

    wxBoxSizer* itemBoxSizer14 = new wxBoxSizer(wxHORIZONTAL);
    itemStaticBoxSizer12->Add(itemBoxSizer14, 0, wxGROW|wxALL, 1);
    wxButton* itemButton15 = new wxButton( itemPanel11, ID_COLORCHOOSE, _("Set Color"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer14->Add(itemButton15, 1, wxALIGN_CENTER_VERTICAL|wxALL, 1);

    _backgroundColor = new wxStaticText( itemPanel11, wxID_STATIC, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    _backgroundColor->SetBackgroundColour(wxColour(255, 255, 255));
    itemBoxSizer14->Add(_backgroundColor, 1, wxGROW|wxALL, 5);

    itemNotebook4->AddPage(itemPanel11, _("Options"));

    wxPanel* itemPanel17 = new wxPanel( itemNotebook4, ID_GENERATIONNB, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
    wxStaticBox* itemStaticBoxSizer18Static = new wxStaticBox(itemPanel17, wxID_ANY, wxEmptyString);
    wxStaticBoxSizer* itemStaticBoxSizer18 = new wxStaticBoxSizer(itemStaticBoxSizer18Static, wxVERTICAL);
    itemPanel17->SetSizer(itemStaticBoxSizer18);

    wxButton* itemButton19 = new wxButton( itemPanel17, ID_GENERATE, _("Generate"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStaticBoxSizer18->Add(itemButton19, 0, wxGROW|wxALL, 1);

    wxStaticLine* itemStaticLine20 = new wxStaticLine( itemPanel17, wxID_STATIC, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
    itemStaticBoxSizer18->Add(itemStaticLine20, 0, wxGROW|wxALL, 5);

    _outputSizer = new wxStaticBox(itemPanel17, wxID_ANY, _("Sprite Output"));
    wxStaticBoxSizer* itemStaticBoxSizer21 = new wxStaticBoxSizer(_outputSizer, wxVERTICAL);
    itemStaticBoxSizer18->Add(itemStaticBoxSizer21, 0, wxGROW|wxALL, 1);
    wxBoxSizer* itemBoxSizer22 = new wxBoxSizer(wxHORIZONTAL);
    itemStaticBoxSizer21->Add(itemBoxSizer22, 0, wxGROW|wxALL, 1);
    wxStaticText* itemStaticText23 = new wxStaticText( itemPanel17, wxID_STATIC, _("Output Format:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer22->Add(itemStaticText23, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxArrayString _outputFormatStrings;
    _outputFormat = new wxChoice( itemPanel17, ID_OUTPUTFORMAT, wxDefaultPosition, wxDefaultSize, _outputFormatStrings, 0 );
    itemBoxSizer22->Add(_outputFormat, 2, wxALIGN_CENTER_VERTICAL|wxALL, 1);

    wxStaticText* itemStaticText25 = new wxStaticText( itemPanel17, wxID_STATIC, _("Filename:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStaticBoxSizer21->Add(itemStaticText25, 0, wxALIGN_LEFT|wxALL, 1);

    wxBoxSizer* itemBoxSizer26 = new wxBoxSizer(wxHORIZONTAL);
    itemStaticBoxSizer21->Add(itemBoxSizer26, 0, wxGROW|wxALL, 1);
    _spriteFilename = new wxTextCtrl( itemPanel17, ID_SPRITEFN, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer26->Add(_spriteFilename, 4, wxALIGN_CENTER_VERTICAL|wxALL, 1);

    wxButton* itemButton28 = new wxButton( itemPanel17, ID_BROWSESPRITE, _("..."), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer26->Add(itemButton28, 1, wxALIGN_CENTER_VERTICAL|wxALL, 1);

    wxButton* itemButton29 = new wxButton( itemPanel17, ID_SAVE, _("Save"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStaticBoxSizer21->Add(itemButton29, 0, wxGROW|wxALL, 1);

    wxStaticBox* itemStaticBoxSizer30Static = new wxStaticBox(itemPanel17, wxID_ANY, _("CSS Output"));
    wxStaticBoxSizer* itemStaticBoxSizer30 = new wxStaticBoxSizer(itemStaticBoxSizer30Static, wxVERTICAL);
    itemStaticBoxSizer18->Add(itemStaticBoxSizer30, 0, wxGROW|wxALL, 1);
    wxStaticText* itemStaticText31 = new wxStaticText( itemPanel17, wxID_STATIC, _("Filename:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStaticBoxSizer30->Add(itemStaticText31, 0, wxALIGN_LEFT|wxALL, 1);

    wxBoxSizer* itemBoxSizer32 = new wxBoxSizer(wxHORIZONTAL);
    itemStaticBoxSizer30->Add(itemBoxSizer32, 0, wxGROW|wxALL, 1);
    _cssFilename = new wxTextCtrl( itemPanel17, ID_CSSFILENAME, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer32->Add(_cssFilename, 4, wxALIGN_CENTER_VERTICAL|wxALL, 1);

    wxButton* itemButton34 = new wxButton( itemPanel17, ID_BROWSECSS, _("..."), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer32->Add(itemButton34, 1, wxALIGN_CENTER_VERTICAL|wxALL, 1);

    wxButton* itemButton35 = new wxButton( itemPanel17, ID_CSSSAVE, _("Save"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStaticBoxSizer30->Add(itemButton35, 0, wxGROW|wxALL, 1);

    itemNotebook4->AddPage(itemPanel17, _("Generate"));

    itemStaticBoxSizer3->Add(itemNotebook4, 1, wxGROW|wxALL, 1);

    wxStaticBox* itemStaticBoxSizer36Static = new wxStaticBox(itemFrame1, wxID_ANY, _("Preview"));
    wxStaticBoxSizer* itemStaticBoxSizer36 = new wxStaticBoxSizer(itemStaticBoxSizer36Static, wxVERTICAL);
    itemBoxSizer2->Add(itemStaticBoxSizer36, 3, wxGROW|wxALL, 1);

    wxNotebook* itemNotebook37 = new wxNotebook( itemFrame1, ID_NOTEBOOK, wxDefaultPosition, wxDefaultSize, wxBK_DEFAULT );

    wxPanel* itemPanel38 = new wxPanel( itemNotebook37, ID_PANEL, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
    wxBoxSizer* itemBoxSizer39 = new wxBoxSizer(wxVERTICAL);
    itemPanel38->SetSizer(itemBoxSizer39);

    _staticPreview = new wxStaticBitmap( itemPanel38, wxID_STATIC, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer39->Add(_staticPreview, 1, wxGROW|wxALL, 1);

    itemNotebook37->AddPage(itemPanel38, _("Sprite"));

    wxPanel* itemPanel41 = new wxPanel( itemNotebook37, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
    wxBoxSizer* itemBoxSizer42 = new wxBoxSizer(wxVERTICAL);
    itemPanel41->SetSizer(itemBoxSizer42);

    _cssPreview = new wxTextCtrl( itemPanel41, ID_CSSPREVIEW, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_READONLY );
    itemBoxSizer42->Add(_cssPreview, 1, wxGROW|wxALL, 1);

    itemNotebook37->AddPage(itemPanel41, _("CSS"));

    itemStaticBoxSizer36->Add(itemNotebook37, 1, wxGROW|wxALL, 1);

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
            AddImageFile(paths[i]);
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

spriteKodoMainWnd* spriteKodoMainWnd::Instance()
{
    return NULL;
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
    
    this->GenerateCSS();
    _cssPreview->SetValue(_css);
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
   
    int cSel = _outputFormat->GetSelection();
    if(cSel == 0)
    {
        type = wxBITMAP_TYPE_PNG;
    }
    if(cSel == 1)
    {
        type = wxBITMAP_TYPE_JPEG;
    }
    if(cSel == 2)
    {
        type = wxBITMAP_TYPE_BMP;
    }
    if(cSel == 3)
    {
        type = wxBITMAP_TYPE_XPM;
    }
    
    wxImage image = _bitmap->ConvertToImage();
    
    wxString filename = _spriteFilename->GetValue();
    image.SaveFile(filename, type);
}

void spriteKodoMainWnd::GenerateCSS()
{
    wxString cssPrefix = _(".spr-");
    
    _css.Clear();
    size_t imageCount = _sourceImageList.Count();
    for(size_t i=0; i<imageCount; i++)
    {
        wxString cssClass = cssPrefix + _sourceImageList[i].GetName() + wxString::Format(_(" {\n  background-position: -%dpx -%dpx;\n  width: %dpx;\n  height: %dpx;\n}\n"), _sourceImageList[i].GetLeft(), _sourceImageList[i].GetTop(), _sourceImageList[i].GetWidth(), _sourceImageList[i].GetHeight());
        _css.Append(cssClass);
    }
}

/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON1
 */

void spriteKodoMainWnd::OnCsssaveClick( wxCommandEvent& event )
{
    if(_bitmap == NULL)
    {
        GenerateBitmap();
        GenerateCSS();
    }
    wxString filename = _cssFilename->GetValue();
    wxFile output(filename, wxFile::write);
    output.Write(_css);
    output.Close();
}


/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BROWSESPRITE
 */

void spriteKodoMainWnd::OnBrowsespriteClick( wxCommandEvent& event )
{
    wxString filter = _("*.*");
    
    int cSel = _outputFormat->GetSelection();
    if(cSel == 0)
    {
        filter = _("*.png");
    }
    if(cSel == 1)
    {
        filter = _("*.jpg");
    }
    if(cSel == 2)
    {
        filter = _("*.bmp");
    }
    if(cSel == 3)
    {
        filter = _("*.xpm");
    }
    
    wxFileDialog fdialog(this, _("Choose filename"), _(""), _(""), filter, wxFD_SAVE);
    if(fdialog.ShowModal()==wxID_OK)
    {
        _spriteFilename->SetValue(fdialog.GetPath());
    }
}


/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BROWSECSS
 */

void spriteKodoMainWnd::OnBrowsecssClick( wxCommandEvent& event )
{
    wxFileDialog fdialog(this, _("Choose filename"), _(""), _(""), _("*.css"), wxFD_SAVE);
    if(fdialog.ShowModal()==wxID_OK)
    {
        _cssFilename->SetValue(fdialog.GetPath());
    }
}
