/////////////////////////////////////////////////////////////////////////////
// Name:        mfcalculatoruiapp.cpp
// Purpose:     
// Author:      Mehrshad Jafari Farahani
// Modified by: 
// Created:     02/12/2021 19:02:28
// RCS-ID:      
// Copyright:   You are free to use, copy, and edit this software as they way you wish!
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

#include "mfcalculatoruiapp.h"

////@begin XPM images
////@end XPM images


/*
 * Application instance implementation
 */

////@begin implement app
IMPLEMENT_APP( MfCalculatorUIApp )
////@end implement app


/*
 * MfCalculatorUIApp type definition
 */

IMPLEMENT_CLASS( MfCalculatorUIApp, wxApp )


/*
 * MfCalculatorUIApp event table definition
 */

BEGIN_EVENT_TABLE( MfCalculatorUIApp, wxApp )

////@begin MfCalculatorUIApp event table entries
////@end MfCalculatorUIApp event table entries

END_EVENT_TABLE()


/*
 * Constructor for MfCalculatorUIApp
 */

MfCalculatorUIApp::MfCalculatorUIApp()
{
    Init();
}


/*
 * Member initialisation
 */

void MfCalculatorUIApp::Init()
{
////@begin MfCalculatorUIApp member initialisation
////@end MfCalculatorUIApp member initialisation
}

/*
 * Initialisation for MfCalculatorUIApp
 */

bool MfCalculatorUIApp::OnInit()
{    
////@begin MfCalculatorUIApp initialisation
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
	MainWindow* mainWindow = new MainWindow( NULL );
	mainWindow->Show(true);
////@end MfCalculatorUIApp initialisation

    return true;
}


/*
 * Cleanup for MfCalculatorUIApp
 */

int MfCalculatorUIApp::OnExit()
{    
////@begin MfCalculatorUIApp cleanup
	return wxApp::OnExit();
////@end MfCalculatorUIApp cleanup
}

