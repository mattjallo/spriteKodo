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
////@begin SpriteKodoApp initialisation
	// Remove the comment markers above and below this block
	// to make permanent changes to the code.

#if wxUSE_XPM
	wxImage::AddHandler(new wxXPMHandler);
#endif
#if wxUSE_LIBPNG
	wxImage::AddHandler(new wxPNGHandler);
#endif
#if wxUSE_LIBJPEG
	wxImage::AddHandler(new wxJPEGHandler);
#endif
#if wxUSE_GIF
	wxImage::AddHandler(new wxGIFHandler);
#endif
	spriteKodoMainWnd* mainWindow = new spriteKodoMainWnd( NULL );
	mainWindow->Show(true);
////@end SpriteKodoApp initialisation

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

