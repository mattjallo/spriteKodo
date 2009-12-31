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

    wxImage::AddHandler(new wxBMPHandler);
	wxImage::AddHandler(new wxXPMHandler);
	wxImage::AddHandler(new wxPNGHandler);
	wxImage::AddHandler(new wxJPEGHandler);
	wxImage::AddHandler(new wxGIFHandler);

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
 
    // add to dropdown box if in GUI mode
    if(!silent_mode)
    {
        
    }
 
    // and other command line parameters
 
    // then do what you need with them.
 
    return true;
}
