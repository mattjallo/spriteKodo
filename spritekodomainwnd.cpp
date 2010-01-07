// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

////@begin includes
#include "wx/mstream.h"
#include "wx/imaglist.h"
////@end includes

#include "spritekodomainwnd.h"
#include "CSourceImage.h"
#include <wx/colordlg.h>
#include "CKodoUtil.h"

#include "goat.inc"

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

    EVT_BUTTON( ID_REMOVEIMAGE, spriteKodoMainWnd::OnRemoveimageClick )

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
    SetIcon(GetIconResource(wxT("goat.png")));
    Centre();
////@end spriteKodoMainWnd creation

    _sourceImages->InsertColumn(0, _("Name"), wxLIST_FORMAT_LEFT, 300);

    _outputFormat->Append(_("PNG"));
    _outputFormat->Append(_("JPG"));
    _outputFormat->Append(_("BMP"));
    _outputFormat->Append(_("XPM"));

    UpdateSourceImageList();

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
    _cssPrefix = NULL;
    _outputSizer = NULL;
    _outputFormat = NULL;
    _spriteFilename = NULL;
    _cssFilename = NULL;
    _previewSizer = NULL;
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
    wxStaticBox* itemStaticBoxSizer12Static = new wxStaticBox(itemPanel11, wxID_ANY, wxEmptyString);
    wxStaticBoxSizer* itemStaticBoxSizer12 = new wxStaticBoxSizer(itemStaticBoxSizer12Static, wxVERTICAL);
    itemPanel11->SetSizer(itemStaticBoxSizer12);

    wxStaticBox* itemStaticBoxSizer13Static = new wxStaticBox(itemPanel11, wxID_ANY, _("Background"));
    wxStaticBoxSizer* itemStaticBoxSizer13 = new wxStaticBoxSizer(itemStaticBoxSizer13Static, wxVERTICAL);
    itemStaticBoxSizer12->Add(itemStaticBoxSizer13, 0, wxGROW|wxALL, 1);
    _cbTransparentBackground = new wxCheckBox( itemPanel11, ID_CHECKBOX, _("Transparent Background"), wxDefaultPosition, wxDefaultSize, 0 );
    _cbTransparentBackground->SetValue(false);
    itemStaticBoxSizer13->Add(_cbTransparentBackground, 0, wxALIGN_LEFT|wxALL, 1);

    wxBoxSizer* itemBoxSizer15 = new wxBoxSizer(wxHORIZONTAL);
    itemStaticBoxSizer13->Add(itemBoxSizer15, 0, wxGROW|wxALL, 1);
    wxButton* itemButton16 = new wxButton( itemPanel11, ID_COLORCHOOSE, _("Set Color"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer15->Add(itemButton16, 1, wxALIGN_CENTER_VERTICAL|wxALL, 1);

    _backgroundColor = new wxStaticText( itemPanel11, wxID_STATIC, _("SAMPLE"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
    _backgroundColor->SetForegroundColour(wxColour(255, 255, 255));
    _backgroundColor->SetBackgroundColour(wxColour(255, 255, 255));
    _backgroundColor->SetFont(wxFont(14, wxSWISS, wxNORMAL, wxBOLD, false, wxT("Sans")));
    itemBoxSizer15->Add(_backgroundColor, 1, wxGROW|wxALL, 5);

    wxStaticBox* itemStaticBoxSizer18Static = new wxStaticBox(itemPanel11, wxID_ANY, _("CSS"));
    wxStaticBoxSizer* itemStaticBoxSizer18 = new wxStaticBoxSizer(itemStaticBoxSizer18Static, wxVERTICAL);
    itemStaticBoxSizer12->Add(itemStaticBoxSizer18, 0, wxGROW|wxALL, 1);
    wxBoxSizer* itemBoxSizer19 = new wxBoxSizer(wxHORIZONTAL);
    itemStaticBoxSizer18->Add(itemBoxSizer19, 0, wxGROW|wxALL, 1);
    wxStaticText* itemStaticText20 = new wxStaticText( itemPanel11, wxID_STATIC, _("Class name prefix:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer19->Add(itemStaticText20, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    _cssPrefix = new wxTextCtrl( itemPanel11, ID_TEXTCTRL, _(".spr-"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer19->Add(_cssPrefix, 1, wxALIGN_CENTER_VERTICAL|wxALL, 1);

    itemNotebook4->AddPage(itemPanel11, _("Options"));

    wxPanel* itemPanel22 = new wxPanel( itemNotebook4, ID_GENERATIONNB, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
    wxStaticBox* itemStaticBoxSizer23Static = new wxStaticBox(itemPanel22, wxID_ANY, wxEmptyString);
    wxStaticBoxSizer* itemStaticBoxSizer23 = new wxStaticBoxSizer(itemStaticBoxSizer23Static, wxVERTICAL);
    itemPanel22->SetSizer(itemStaticBoxSizer23);

    wxButton* itemButton24 = new wxButton( itemPanel22, ID_GENERATE, _("Generate"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStaticBoxSizer23->Add(itemButton24, 0, wxGROW|wxALL, 1);

    wxStaticLine* itemStaticLine25 = new wxStaticLine( itemPanel22, wxID_STATIC, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
    itemStaticBoxSizer23->Add(itemStaticLine25, 0, wxGROW|wxALL, 5);

    _outputSizer = new wxStaticBox(itemPanel22, wxID_ANY, _("Sprite Output"));
    wxStaticBoxSizer* itemStaticBoxSizer26 = new wxStaticBoxSizer(_outputSizer, wxVERTICAL);
    itemStaticBoxSizer23->Add(itemStaticBoxSizer26, 0, wxGROW|wxALL, 1);
    wxBoxSizer* itemBoxSizer27 = new wxBoxSizer(wxHORIZONTAL);
    itemStaticBoxSizer26->Add(itemBoxSizer27, 0, wxGROW|wxALL, 1);
    wxStaticText* itemStaticText28 = new wxStaticText( itemPanel22, wxID_STATIC, _("Output Format:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer27->Add(itemStaticText28, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxArrayString _outputFormatStrings;
    _outputFormat = new wxChoice( itemPanel22, ID_OUTPUTFORMAT, wxDefaultPosition, wxDefaultSize, _outputFormatStrings, 0 );
    itemBoxSizer27->Add(_outputFormat, 2, wxALIGN_CENTER_VERTICAL|wxALL, 1);

    wxStaticText* itemStaticText30 = new wxStaticText( itemPanel22, wxID_STATIC, _("Filename:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStaticBoxSizer26->Add(itemStaticText30, 0, wxALIGN_LEFT|wxALL, 1);

    wxBoxSizer* itemBoxSizer31 = new wxBoxSizer(wxHORIZONTAL);
    itemStaticBoxSizer26->Add(itemBoxSizer31, 0, wxGROW|wxALL, 1);
    _spriteFilename = new wxTextCtrl( itemPanel22, ID_SPRITEFN, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer31->Add(_spriteFilename, 4, wxALIGN_CENTER_VERTICAL|wxALL, 1);

    wxButton* itemButton33 = new wxButton( itemPanel22, ID_BROWSESPRITE, _("..."), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer31->Add(itemButton33, 1, wxALIGN_CENTER_VERTICAL|wxALL, 1);

    wxButton* itemButton34 = new wxButton( itemPanel22, ID_SAVE, _("Save"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStaticBoxSizer26->Add(itemButton34, 0, wxGROW|wxALL, 1);

    wxStaticBox* itemStaticBoxSizer35Static = new wxStaticBox(itemPanel22, wxID_ANY, _("CSS Output"));
    wxStaticBoxSizer* itemStaticBoxSizer35 = new wxStaticBoxSizer(itemStaticBoxSizer35Static, wxVERTICAL);
    itemStaticBoxSizer23->Add(itemStaticBoxSizer35, 0, wxGROW|wxALL, 1);
    wxStaticText* itemStaticText36 = new wxStaticText( itemPanel22, wxID_STATIC, _("Filename:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStaticBoxSizer35->Add(itemStaticText36, 0, wxALIGN_LEFT|wxALL, 1);

    wxBoxSizer* itemBoxSizer37 = new wxBoxSizer(wxHORIZONTAL);
    itemStaticBoxSizer35->Add(itemBoxSizer37, 0, wxGROW|wxALL, 1);
    _cssFilename = new wxTextCtrl( itemPanel22, ID_CSSFILENAME, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer37->Add(_cssFilename, 4, wxALIGN_CENTER_VERTICAL|wxALL, 1);

    wxButton* itemButton39 = new wxButton( itemPanel22, ID_BROWSECSS, _("..."), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer37->Add(itemButton39, 1, wxALIGN_CENTER_VERTICAL|wxALL, 1);

    wxButton* itemButton40 = new wxButton( itemPanel22, ID_CSSSAVE, _("Save"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStaticBoxSizer35->Add(itemButton40, 0, wxGROW|wxALL, 1);

    itemNotebook4->AddPage(itemPanel22, _("Generate"));

    itemStaticBoxSizer3->Add(itemNotebook4, 1, wxGROW|wxALL, 1);

    wxStaticBox* itemStaticBoxSizer41Static = new wxStaticBox(itemFrame1, wxID_ANY, _("Preview"));
    wxStaticBoxSizer* itemStaticBoxSizer41 = new wxStaticBoxSizer(itemStaticBoxSizer41Static, wxVERTICAL);
    itemBoxSizer2->Add(itemStaticBoxSizer41, 3, wxGROW|wxALL, 1);

    wxNotebook* itemNotebook42 = new wxNotebook( itemFrame1, ID_NOTEBOOK, wxDefaultPosition, wxDefaultSize, wxBK_DEFAULT );

    wxPanel* itemPanel43 = new wxPanel( itemNotebook42, ID_PANEL, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
    _previewSizer = new wxBoxSizer(wxVERTICAL);
    itemPanel43->SetSizer(_previewSizer);

    _staticPreview = new wxStaticBitmap( itemPanel43, wxID_STATIC, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
    _previewSizer->Add(_staticPreview, 1, wxGROW|wxALL, 1);

    itemNotebook42->AddPage(itemPanel43, _("Sprite"));

    wxPanel* itemPanel46 = new wxPanel( itemNotebook42, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
    wxBoxSizer* itemBoxSizer47 = new wxBoxSizer(wxVERTICAL);
    itemPanel46->SetSizer(itemBoxSizer47);

    _cssPreview = new wxTextCtrl( itemPanel46, ID_CSSPREVIEW, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_READONLY );
    itemBoxSizer47->Add(_cssPreview, 1, wxGROW|wxALL, 1);

    itemNotebook42->AddPage(itemPanel46, _("CSS"));

    itemStaticBoxSizer41->Add(itemNotebook42, 1, wxGROW|wxALL, 1);

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
    if (name == _T("goat.png"))
    {
        wxMemoryInputStream memStream(goat_png, sizeof(goat_png));
        wxBitmap bitmap(wxImage(memStream, wxBITMAP_TYPE_ANY, -1), -1);
        wxIcon icon;
        icon.CopyFromBitmap(bitmap);
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
    wxFileDialog fdSourceImages(this, _("Choose source images to add"), _(""), _(""), _("Images (bmp, gif, jpg, png)|*.bmp;*.gif;*.jpg;*.jpeg;*.png"), wxFD_MULTIPLE | wxFD_OPEN, wxDefaultPosition);
    if(fdSourceImages.ShowModal() == wxID_OK)
    {
        fdSourceImages.GetPaths(paths);
        size_t fileCount = paths.GetCount();
        for(size_t i=0; i<fileCount; i++)
        {
            CKodoUtil::Instance()->AddImageFile(paths[i]);
        }
    }
    CKodoUtil::Instance()->SortImagesByName();
    UpdateSourceImageList();
}

void spriteKodoMainWnd::UpdateSourceImageList()
{
    SourceImageList* _imageList = CKodoUtil::Instance()->GetSourceImageListReference();
    _sourceImages->DeleteAllItems();
    size_t imageCount = _imageList->GetCount();
    for(size_t i = 0; i<imageCount; i++)
    {
        _sourceImages->InsertItem((long)i, (*_imageList)[i].GetName()); 
    }
    _cbTransparentBackground->SetValue(CKodoUtil::Instance()->GetTransparentBackground());
    _backgroundColor->SetBackgroundColour(CKodoUtil::Instance()->GetBackgroundColor());
    _backgroundColor->SetForegroundColour(CKodoUtil::Instance()->GetBackgroundColor());
    _outputFormat->SetStringSelection(CKodoUtil::Instance()->GetOutputType());
    _cssPrefix->SetValue(CKodoUtil::Instance()->GetCssPrefix());
}

/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_GENERATE
 */

void spriteKodoMainWnd::OnGenerateClick( wxCommandEvent& event )
{
    GeneratePreview();
}

void spriteKodoMainWnd::GeneratePreview()
{
    CKodoUtil::Instance()->SetBackgroundColor(_backgroundColor->GetBackgroundColour());
    CKodoUtil::Instance()->SetTransparentBackground(_cbTransparentBackground->IsChecked());
    CKodoUtil::Instance()->SetOutputType(_outputFormat->GetStringSelection());
    CKodoUtil::Instance()->SetCssPrefix(_cssPrefix->GetValue());
    
    CKodoUtil::Instance()->Generate();
    
    wxBitmap _bitmap = CKodoUtil::Instance()->GetBitmapPreview();
    
    int bmpWidth = _bitmap.GetWidth();
    int bmpHeight = _bitmap.GetHeight();
    
    int previewWidth = bmpWidth;
    int previewHeight = bmpHeight;
    
	_previewSizer->RecalcSizes();
	wxSize previewSize = _previewSizer->GetSize();
    
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
    
    wxImage image = _bitmap.ConvertToImage();
    wxBitmap bmp(image.Scale(previewWidth, previewHeight));
	_staticPreview->SetBitmap(bmp); 
    _cssPreview->SetValue(CKodoUtil::Instance()->GetCSSPreview());
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
        _backgroundColor->SetForegroundColour(dialog.GetColourData().GetColour());
        _backgroundColor->Refresh();
        _backgroundColor->Update();
    }
}


/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_SAVE
 */

void spriteKodoMainWnd::OnSaveClick( wxCommandEvent& event )
{
	GeneratePreview();
	wxString filename = _spriteFilename->GetValue();
    CKodoUtil::Instance()->SaveBitmap(filename);
}

/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON1
 */

void spriteKodoMainWnd::OnCsssaveClick( wxCommandEvent& event )
{
    GeneratePreview();
	wxString filename = _cssFilename->GetValue();
    CKodoUtil::Instance()->SaveCSS(filename);
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


/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_REMOVEIMAGE
 */

void spriteKodoMainWnd::OnRemoveimageClick( wxCommandEvent& event )
{
    SourceImageList* _imageList = CKodoUtil::Instance()->GetSourceImageListReference();
    for(int index=0; index<_sourceImages->GetItemCount(); index++)
    {
        if(_sourceImages->GetItemState(index, wxLIST_STATE_SELECTED) > 0)
        {
            _imageList->RemoveAt((size_t)index, 1);
            _sourceImages->DeleteItem(index);
            index--;
        }
    }
}

