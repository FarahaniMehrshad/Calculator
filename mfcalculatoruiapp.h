/////////////////////////////////////////////////////////////////////////////
// Name:        mfcalculatoruiapp.h
// Purpose:     
// Author:      Mehrshad Jafari Farahani
// Modified by: 
// Created:     02/12/2021 19:02:28
// RCS-ID:      
// Copyright:   You are free to use, copy, and edit this software as they way you wish!
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#ifndef _MFCALCULATORUIAPP_H_
#define _MFCALCULATORUIAPP_H_


/*!
 * Includes
 */

////@begin includes
#include "wx/image.h"
#include "mainwindow.h"
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
 * MfCalculatorUIApp class declaration
 */

class MfCalculatorUIApp: public wxApp
{    
    DECLARE_CLASS( MfCalculatorUIApp )
    DECLARE_EVENT_TABLE()

public:
    /// Constructor
    MfCalculatorUIApp();

    void Init();

    /// Initialises the application
    virtual bool OnInit();

    /// Called on exit
    virtual int OnExit();

////@begin MfCalculatorUIApp event handler declarations

////@end MfCalculatorUIApp event handler declarations

////@begin MfCalculatorUIApp member function declarations

////@end MfCalculatorUIApp member function declarations

////@begin MfCalculatorUIApp member variables
////@end MfCalculatorUIApp member variables
};

/*!
 * Application instance declaration 
 */

////@begin declare app
DECLARE_APP(MfCalculatorUIApp)
////@end declare app

#endif
    // _MFCALCULATORUIAPP_H_
