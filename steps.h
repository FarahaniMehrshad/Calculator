/////////////////////////////////////////////////////////////////////////////
// Name:        steps.h
// Purpose:     
// Author:      Mehrshad Jafari Farahani
// Modified by: 
// Created:     05/12/2021 23:11:12
// RCS-ID:      
// Copyright:   You are free to use, copy, and edit this software as they way you wish!
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#ifndef _STEPS_H_
#define _STEPS_H_


/*!
 * Includes
 */

////@begin includes
////@end includes

/*!
 * Forward declarations
 */

////@begin forward declarations
class wxBoxSizer;
////@end forward declarations

/*!
 * Control identifiers
 */

#define ID_STEPS 10000
#define ID_Panel 10001
#define ID_StepsTxtCtrl 10002
#define SYMBOL_STEPS_STYLE wxCAPTION|wxSYSTEM_MENU|wxCLOSE_BOX|wxTAB_TRAVERSAL
#define SYMBOL_STEPS_TITLE _("Steps")
#define SYMBOL_STEPS_IDNAME ID_STEPS
#define SYMBOL_STEPS_SIZE wxSize(400, 300)
#define SYMBOL_STEPS_POSITION wxDefaultPosition



/*!
 * Steps class declaration
 */

class Steps: public wxDialog
{    
    DECLARE_DYNAMIC_CLASS( Steps )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    Steps();
    Steps( wxWindow* parent, wxWindowID id = SYMBOL_STEPS_IDNAME, const wxString& caption = SYMBOL_STEPS_TITLE, const wxPoint& pos = SYMBOL_STEPS_POSITION, const wxSize& size = SYMBOL_STEPS_SIZE, long style = SYMBOL_STEPS_STYLE );

    /// Creation
    bool Create( wxWindow* parent, wxWindowID id = SYMBOL_STEPS_IDNAME, const wxString& caption = SYMBOL_STEPS_TITLE, const wxPoint& pos = SYMBOL_STEPS_POSITION, const wxSize& size = SYMBOL_STEPS_SIZE, long style = SYMBOL_STEPS_STYLE );

    /// Destructor
    ~Steps();

    /// Initialises member variables
    void Init();

    /// Creates the controls and sizers
    void CreateControls();

////@begin Steps event handler declarations

////@end Steps event handler declarations

////@begin Steps member function declarations

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end Steps member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin Steps member variables
    wxBoxSizer* m_BoxSizerV1;
    wxPanel* m_Panel;
    wxBoxSizer* m_BoxSizerV2;
    wxTextCtrl* m_StepsTxtCtrl;
////@end Steps member variables
};

#endif
    // _STEPS_H_
