/////////////////////////////////////////////////////////////////////////////
// Name:        mainwindow.h
// Purpose:     
// Author:      Mehrshad Jafari Farahani
// Modified by: 
// Created:     02/12/2021 19:03:16
// RCS-ID:      
// Copyright:   You are free to use, copy, and edit this software as they way you wish!
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#ifndef _MAINWINDOW_H_
#define _MAINWINDOW_H_

#include "mfCalculator.h"
#include <wx/aboutdlg.h>
#include "Steps.h"

/*!
 * Includes
 */

////@begin includes
#include "wx/frame.h"
////@end includes

/*!
 * Forward declarations
 */

////@begin forward declarations
class wxBoxSizer;
class wxMenu;
////@end forward declarations

/*!
 * Control identifiers
 */

////@begin control identifiers
#define ID_MAINWINDOW 10000
#define ID_Panel 10001
#define ID_InpTextCtrl 10025
#define ID_OutTextCtrl 10026
#define ID_PlusBtn 10002
#define ID_MinusBtn 10004
#define ID_MultiplyBtn 10005
#define ID_DivisionBtn 10003
#define ID_OneBtn 10007
#define ID_TwoBtn 10008
#define ID_ThreeBtn 10009
#define ID_PowerBtn 10006
#define ID_FourBtn 10010
#define ID_FiveBtn 10011
#define ID_SixBtn 10012
#define ID_AcBtn 10013
#define ID_SevenBtn 10014
#define ID_EightBtn 10015
#define ID_NineBtn 10016
#define ID_DelBtn 10017
#define ID_ZeroBtn 10018
#define ID_DotBtn 10019
#define ID_OpBtn 10021
#define ID_CpBtn 10020
#define ID_STEPSMENU 10022
#define ID_TREEMENU 10023
#define SYMBOL_MAINWINDOW_STYLE wxCAPTION|wxSYSTEM_MENU|wxMINIMIZE_BOX|wxCLOSE_BOX|wxSIMPLE_BORDER
#define SYMBOL_MAINWINDOW_TITLE _("Calculator")
#define SYMBOL_MAINWINDOW_IDNAME ID_MAINWINDOW
#define SYMBOL_MAINWINDOW_SIZE wxSize(380, 615)
#define SYMBOL_MAINWINDOW_POSITION wxDefaultPosition
////@end control identifiers


/*!
 * MainWindow class declaration
 */

class MainWindow: public wxFrame
{    
    DECLARE_CLASS( MainWindow )
    DECLARE_EVENT_TABLE()

private:

	mf::Calculator* m_calculator = nullptr;
    wxDialog* StepsDialog = nullptr;
	double m_answer = 0.0;
	std::string m_steps;

public:
    /// Constructors
    MainWindow();
    MainWindow( wxWindow* parent, wxWindowID id = SYMBOL_MAINWINDOW_IDNAME, const wxString& caption = SYMBOL_MAINWINDOW_TITLE, const wxPoint& pos = SYMBOL_MAINWINDOW_POSITION, const wxSize& size = SYMBOL_MAINWINDOW_SIZE, long style = SYMBOL_MAINWINDOW_STYLE );

    bool Create( wxWindow* parent, wxWindowID id = SYMBOL_MAINWINDOW_IDNAME, const wxString& caption = SYMBOL_MAINWINDOW_TITLE, const wxPoint& pos = SYMBOL_MAINWINDOW_POSITION, const wxSize& size = SYMBOL_MAINWINDOW_SIZE, long style = SYMBOL_MAINWINDOW_STYLE );

    /// Destructor
    ~MainWindow();

    /// Initialises member variables
    void Init();

    /// Creates the controls and sizers
    void CreateControls();

////@begin MainWindow event handler declarations

    /// wxEVT_PAINT event handler for ID_Panel
    void OnPaint( wxPaintEvent& event );

    /// wxEVT_COMMAND_TEXT_UPDATED event handler for ID_InpTextCtrl
    void OnInpTextCtrlTextUpdated( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_PlusBtn
    void OnPlusBtnClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_MinusBtn
    void OnMinusBtnClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_MultiplyBtn
    void OnMultiplyBtnClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_DivisionBtn
    void OnDivisionBtnClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_OneBtn
    void OnOneBtnClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_TwoBtn
    void OnTwoBtnClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_ThreeBtn
    void OnThreeBtnClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_PowerBtn
    void OnPowerBtnClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_FourBtn
    void OnFourBtnClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_FiveBtn
    void OnFiveBtnClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_SixBtn
    void OnSixBtnClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_AcBtn
    void OnAcBtnClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_SevenBtn
    void OnSevenBtnClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_EightBtn
    void OnEightBtnClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_NineBtn
    void OnNineBtnClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_DelBtn
    void OnDelBtnClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_ZeroBtn
    void OnZeroBtnClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_DotBtn
    void OnDotBtnClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_OpBtn
    void OnOpBtnClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_CpBtn
    void OnCpBtnClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_MENU_SELECTED event handler for wxID_CLOSE
    void OnCloseClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_MENU_SELECTED event handler for ID_STEPSMENU
    void OnStepsmenuClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_MENU_SELECTED event handler for ID_TREEMENU
    void OnTreemenuClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_MENU_SELECTED event handler for wxID_ABOUT
    void OnAboutClick( wxCommandEvent& event );

////@end MainWindow event handler declarations

////@begin MainWindow member function declarations

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end MainWindow member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin MainWindow member variables
    wxBoxSizer* m_BoxSizerH1;
    wxBoxSizer* m_BoxSizerV2;
    wxBoxSizer* m_BoxSizerH3;
    wxPanel* m_Panel;
    wxBoxSizer* m_BoxSizerV4;
    wxBoxSizer* m_BoxSizerH5;
    wxBoxSizer* m_BoxSizerV6;
    wxTextCtrl* m_InpTextCtrl;
    wxTextCtrl* m_OutTextCtrl;
    wxBoxSizer* m_BoxSizerH7;
    wxBitmapButton* m_PlusBtn;
    wxBitmapButton* m_MinusBtn;
    wxBitmapButton* m_MultiplyBtn;
    wxBitmapButton* m_DivisionBtn;
    wxBoxSizer* m_BoxSizerH8;
    wxBitmapButton* m_OneBtn;
    wxBitmapButton* m_TwoBtn;
    wxBitmapButton* m_ThreeBtn;
    wxBitmapButton* m_PowerBtn;
    wxBoxSizer* m_BoxSizerH9;
    wxBitmapButton* m_FourBtn;
    wxBitmapButton* m_FiveBtn;
    wxBitmapButton* m_SixBtn;
    wxBitmapButton* m_AcBtn;
    wxBoxSizer* m_BoxSizer9;
    wxBitmapButton* m_SevenBtn;
    wxBitmapButton* m_EightBtn;
    wxBitmapButton* m_NineBtn;
    wxBitmapButton* m_DelBtn;
    wxBoxSizer* m_BoxSizerH10;
    wxBitmapButton* m_ZeroBtn;
    wxBitmapButton* m_DotBtn;
    wxBitmapButton* m_OpBtn;
    wxBitmapButton* m_CpBtn;
    wxMenu* m_fileMenu;
    wxMenu* m_viewMenu;
    wxMenu* m_helpMenu;
////@end MainWindow member variables
};

#endif
    // _MAINWINDOW_H_
