/////////////////////////////////////////////////////////////////////////////
// Name:        spritekodoapp.h
// Purpose:     
// Author:      Matthew D. Jallo
// Modified by: 
// Created:     14/12/2009 09:39:21
// RCS-ID:      
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#ifndef _SPRITEKODOAPP_H_
#define _SPRITEKODOAPP_H_


/*!
 * Includes
 */

////@begin includes
#include "wx/image.h"
#include "spritekodomainwnd.h"
////@end includes

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

////@begin SpriteKodoApp event handler declarations

////@end SpriteKodoApp event handler declarations

////@begin SpriteKodoApp member function declarations

////@end SpriteKodoApp member function declarations

////@begin SpriteKodoApp member variables
////@end SpriteKodoApp member variables
};

/*!
 * Application instance declaration 
 */

////@begin declare app
DECLARE_APP(SpriteKodoApp)
////@end declare app

#endif
    // _SPRITEKODOAPP_H_
