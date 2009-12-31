#ifndef _SPRITEKODOAPP_H_
#define _SPRITEKODOAPP_H_


/*!
 * Includes
 */

////@begin includes
#include "wx/image.h"
#include "spritekodomainwnd.h"
////@end includes

#include <wx/cmdline.h>
#include "CKodoUtil.h"

/*!
 * Forward declarations
 */

////@begin forward declarations
////@end forward declarations

/*!
 * Control identifiers
 */

////@begin control identifiers
////@end control identifiers

/*!
 * SpriteKodoApp class declaration
 */

class SpriteKodoApp: public wxApp
{    
    DECLARE_CLASS( SpriteKodoApp )
    DECLARE_EVENT_TABLE()

public:
    /// Constructor
    SpriteKodoApp();

    void Init();

    /// Initialises the application
    virtual bool OnInit();

    /// Called on exit
    virtual int OnExit();
    
    virtual void OnInitCmdLine(wxCmdLineParser& parser);
    
    virtual bool OnCmdLineParsed(wxCmdLineParser& parser);
    
    CKodoUtil kodoUtil;

////@begin SpriteKodoApp event handler declarations

////@end SpriteKodoApp event handler declarations

////@begin SpriteKodoApp member function declarations

////@end SpriteKodoApp member function declarations

////@begin SpriteKodoApp member variables
////@end SpriteKodoApp member variables
};

static const wxCmdLineEntryDesc g_cmdLineDesc [] =
{
     { wxCMD_LINE_SWITCH, wxT("h"), wxT("help"), wxT("displays help on the command line parameters"),
          wxCMD_LINE_VAL_NONE, wxCMD_LINE_OPTION_HELP },
     { wxCMD_LINE_SWITCH, wxT("s"), wxT("silent"), wxT("disables the GUI") },
 
     { wxCMD_LINE_NONE }
};

/*!
 * Application instance declaration 
 */

////@begin declare app
DECLARE_APP(SpriteKodoApp)
////@end declare app

#endif
    // _SPRITEKODOAPP_H_
