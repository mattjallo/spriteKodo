#ifndef _SPRITEKODOMAINWND_H_
#define _SPRITEKODOMAINWND_H_


/*!
 * Includes
 */

////@begin includes
#include "wx/frame.h"
#include "wx/notebook.h"
#include "wx/listctrl.h"
#include "wx/statline.h"
////@end includes

#include "CSourceImage.h"

/*!
 * Forward declarations
 */

////@begin forward declarations
class wxListCtrl;
////@end forward declarations

/*!
 * Control identifiers
 */

////@begin control identifiers
#define ID_SPRITEKODOMAINWND 10000
#define ID_OPERATIONSNB 10009
#define ID_SOURCESNB 10010
#define ID_LISTCTRL 10001
#define ID_ADDIMAGES 10002
#define ID_REMOVEIMAGE 10003
#define ID_OPTIONSNB 10011
#define ID_CHECKBOX 10005
#define ID_COLORCHOOSE 10006
#define ID_GENERATIONNB 10012
#define ID_GENERATE 10004
#define ID_OUTPUTFORMAT 10007
#define ID_SPRITEFN 10013
#define ID_BROWSESPRITE 10014
#define ID_SAVE 10008
#define ID_CSSFILENAME 10016
#define ID_BROWSECSS 10017
#define ID_CSSSAVE 10018
#define ID_NOTEBOOK 10015
#define ID_PANEL 10019
#define ID_PANEL1 10020
#define ID_CSSPREVIEW 10021
#define SYMBOL_SPRITEKODOMAINWND_STYLE wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU|wxMAXIMIZE|wxMINIMIZE_BOX|wxMAXIMIZE_BOX|wxCLOSE_BOX
#define SYMBOL_SPRITEKODOMAINWND_TITLE _("spriteKodo")
#define SYMBOL_SPRITEKODOMAINWND_IDNAME ID_SPRITEKODOMAINWND
#define SYMBOL_SPRITEKODOMAINWND_SIZE wxSize(800, 480)
#define SYMBOL_SPRITEKODOMAINWND_POSITION wxDefaultPosition
////@end control identifiers


/*!
 * spriteKodoMainWnd class declaration
 */

class spriteKodoMainWnd: public wxFrame
{    
    DECLARE_CLASS( spriteKodoMainWnd )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    spriteKodoMainWnd();
    spriteKodoMainWnd( wxWindow* parent, wxWindowID id = SYMBOL_SPRITEKODOMAINWND_IDNAME, const wxString& caption = SYMBOL_SPRITEKODOMAINWND_TITLE, const wxPoint& pos = SYMBOL_SPRITEKODOMAINWND_POSITION, const wxSize& size = SYMBOL_SPRITEKODOMAINWND_SIZE, long style = SYMBOL_SPRITEKODOMAINWND_STYLE );

    bool Create( wxWindow* parent, wxWindowID id = SYMBOL_SPRITEKODOMAINWND_IDNAME, const wxString& caption = SYMBOL_SPRITEKODOMAINWND_TITLE, const wxPoint& pos = SYMBOL_SPRITEKODOMAINWND_POSITION, const wxSize& size = SYMBOL_SPRITEKODOMAINWND_SIZE, long style = SYMBOL_SPRITEKODOMAINWND_STYLE );

    /// Destructor
    ~spriteKodoMainWnd();

    /// Initialises member variables
    void Init();

    /// Creates the controls and sizers
    void CreateControls();
    
    static spriteKodoMainWnd* Instance();

////@begin spriteKodoMainWnd event handler declarations

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_ADDIMAGES
    void OnAddimagesClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_COLORCHOOSE
    void OnColorchooseClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_GENERATE
    void OnGenerateClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BROWSESPRITE
    void OnBrowsespriteClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_SAVE
    void OnSaveClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BROWSECSS
    void OnBrowsecssClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_CSSSAVE
    void OnCsssaveClick( wxCommandEvent& event );

////@end spriteKodoMainWnd event handler declarations

////@begin spriteKodoMainWnd member function declarations

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end spriteKodoMainWnd member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin spriteKodoMainWnd member variables
    wxListCtrl* _sourceImages;
    wxButton* _cmdAddImages;
    wxCheckBox* _cbTransparentBackground;
    wxStaticText* _backgroundColor;
    wxStaticBox* _outputSizer;
    wxChoice* _outputFormat;
    wxTextCtrl* _spriteFilename;
    wxTextCtrl* _cssFilename;
    wxStaticBitmap* _staticPreview;
    wxTextCtrl* _cssPreview;
////@end spriteKodoMainWnd member variables
   
    protected:

    SourceImageList _sourceImageList;
    wxBitmap* _bitmap;
    wxString _css;

    void UpdateSourceImageList();
    void GenerateBitmap();
    void GeneratePreview();
    void GenerateCSS();
    bool AddImageFile(wxString path);
};

#endif
    // _SPRITEKODOMAINWND_H_
