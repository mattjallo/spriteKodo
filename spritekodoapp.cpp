/////////////////////////////////////////////////////////////////////////////
// Name:        spritekodoapp.cpp
// Purpose:     
// Author:      Matthew D. Jallo
// Modified by: 
// Created:     14/12/2009 09:39:21
// RCS-ID:      
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

////@begin includes
////@end includes

#include "spritekodoapp.h"

////@begin XPM images
////@end XPM images

#include <wx/file.h>

/*
 * Application instance implementation
 */

////@begin implement app
IMPLEMENT_APP( SpriteKodoApp )
////@end implement app


/*
 * SpriteKodoApp type definition
 */

IMPLEMENT_CLASS( SpriteKodoApp, wxApp )


/*
 * SpriteKodoApp event table definition
 */

BEGIN_EVENT_TABLE( SpriteKodoApp, wxApp )

////@begin SpriteKodoApp event table entries
////@end SpriteKodoApp event table entries

END_EVENT_TABLE()


/*
 * Constructor for SpriteKodoApp
 */

SpriteKodoApp::SpriteKodoApp()
{
    Init();
}


/*
 * Member initialisation
 */

void SpriteKodoApp::Init()
{
////@begin SpriteKodoApp member initialisation
////@end SpriteKodoApp member initialisation
}

/*
 * Initialisation for SpriteKodoApp
 */

bool SpriteKodoApp::OnInit()
{    
	wxImage::AddHandler(new wxXPMHandler);
	wxImage::AddHandler(new wxPNGHandler);
	wxImage::AddHandler(new wxJPEGHandler);
	wxImage::AddHandler(new wxGIFHandler);
    
    if (!wxApp::OnInit())
        return false;

	spriteKodoMainWnd* mainWindow = new spriteKodoMainWnd( NULL );
	mainWindow->Show(true);

    return true;
}


/*
 * Cleanup for SpriteKodoApp
 */

int SpriteKodoApp::OnExit()
{    
////@begin SpriteKodoApp cleanup
	return wxApp::OnExit();
////@end SpriteKodoApp cleanup
}


void SpriteKodoApp::OnInitCmdLine(wxCmdLineParser& parser)
{
    parser.SetDesc(g_cmdLineDesc);
    parser.SetSwitchChars (wxT("-"));
}
 
bool SpriteKodoApp::OnCmdLineParsed(wxCmdLineParser& parser)
{
    bool silent_mode = parser.Found(wxT("s"));
 
    // this is the input file list
    wxArrayString files;
    for (unsigned int i = 0; i < parser.GetParamCount(); i++)
    {
        files.Add(parser.GetParam(i));
    }
 
    if(files.Count() > 0)
    {
        size_t fileCount = files.Count();
        for(size_t i=0; i<fileCount; i++)
        {
            CKodoUtil::Instance()->AddImageFile(files[i]);
        }
    }

    if(parser.Found(wxT("t")))
        CKodoUtil::Instance()->SetTransparentBackground(true);
    else
        CKodoUtil::Instance()->SetTransparentBackground(!silent_mode);

    wxColour backgroundColor(_("#FFFFFF"));
    wxString colorString;
    if(parser.Found(wxT("b"), &colorString)) 
    {
        if(!backgroundColor.Set(colorString))
            CKodoUtil::WriteToStdErr(_("Error: could not parse background color string '") + colorString + _("'"));
    }
    CKodoUtil::Instance()->SetBackgroundColor(backgroundColor);

    long maxWidth = 4000;
    if(parser.Found(wxT("w"), &maxWidth))
    {
        if(maxWidth <= 0)
            CKodoUtil::WriteToStdErr(_("Error: invalid maximum width specified."));
    }
    CKodoUtil::Instance()->SetMaxWidth((int)maxWidth);

    wxString imageType;
    if(parser.Found(wxT("i"), &imageType))
    {
        imageType = imageType.Upper();
        if(imageType!=_("PNG") && imageType!=_("JPG") && imageType!=_("BMP") && imageType!=_("XPM"))
        {
            CKodoUtil::WriteToStdErr(_("Error: invalid output image format specified. Defaulting to PNG."));
            imageType = _("PNG");
        }
    }
    CKodoUtil::Instance()->SetOutputType(imageType);
   
    wxString cssPrefix;
    cssPrefix = _(".spr-");
    parser.Found(wxT("p"), &cssPrefix);
    CKodoUtil::Instance()->SetCssPrefix(cssPrefix);
    
    if(silent_mode)
    {
        wxString spriteFileName;
        if(parser.Found(wxT("f"), &spriteFileName))
        {
            //generate the sprite
            CKodoUtil::Instance()->Generate();
            CKodoUtil::Instance()->SaveBitmap(spriteFileName);
            
            wxString cssFileName;
            if(parser.Found(wxT("c"), &cssFileName))
                CKodoUtil::Instance()->SaveCSS(cssFileName);
            else
            {
                wxFile outlog;
                outlog.Attach(wxFile::fd_stdout);
                outlog.Write(CKodoUtil::Instance()->GetCSSPreview());
                outlog.Flush();
            }
        }
        else
            CKodoUtil::WriteToStdErr(_("Error: -f must be specified for silent mode."));
        return false;
    }

    return true;
}
