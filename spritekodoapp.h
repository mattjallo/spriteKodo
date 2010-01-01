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
     { wxCMD_LINE_SWITCH, wxT("s"), wxT("silent"), wxT("prevents the GUI from displaying") },
     { wxCMD_LINE_SWITCH, wxT("t"), wxT("transparent"), wxT("use a transparent background if output type supports it") },
     { wxCMD_LINE_OPTION, wxT("b"), wxT("backgroundcolor"), wxT("the default background color of the sprite, as HTML hex color code. Default is #FFFFFF"),
          wxCMD_LINE_VAL_STRING, wxCMD_LINE_PARAM_OPTIONAL },
     { wxCMD_LINE_OPTION, wxT("w"), wxT("maxwidth"), wxT("the maximum width of the sprite in pixels, default 4000"),
          wxCMD_LINE_VAL_NUMBER, wxCMD_LINE_PARAM_OPTIONAL },
     { wxCMD_LINE_OPTION, wxT("i"), wxT("imagetype"), wxT("the format of the output image [PNG|JPG|BMP|XPM], default PNG"),
          wxCMD_LINE_VAL_STRING, wxCMD_LINE_PARAM_OPTIONAL },
     { wxCMD_LINE_OPTION, wxT("p"), wxT("cssprefix"), wxT("the string to prefix to filename bases for the css class names, default '.spr-'"),
          wxCMD_LINE_VAL_STRING, wxCMD_LINE_PARAM_OPTIONAL },
     { wxCMD_LINE_OPTION, wxT("f"), wxT("file"), wxT("the filename for the output sprite image.  Required for --silent mode."),
          wxCMD_LINE_VAL_STRING, wxCMD_LINE_PARAM_OPTIONAL },
     { wxCMD_LINE_OPTION, wxT("c"), wxT("cssfile"), wxT("the filename for the CSS file.  If not specified in --silent mode, the CSS will be output to stdout."),
          wxCMD_LINE_VAL_STRING, wxCMD_LINE_PARAM_OPTIONAL },
     { wxCMD_LINE_PARAM, wxT("m"), wxT("sources"), wxT("source image files"),
          wxCMD_LINE_VAL_STRING, wxCMD_LINE_PARAM_MULTIPLE | wxCMD_LINE_PARAM_OPTIONAL },
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
