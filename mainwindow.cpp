/////////////////////////////////////////////////////////////////////////////
// Name:        mainwindow.cpp
// Purpose:     
// Author:      Mehrshad Jafari Farahani
// Modified by: 
// Created:     02/12/2021 19:03:16
// RCS-ID:      
// Copyright:   You are free to use, copy, and edit this software as they way you wish!
// Licence:     
/////////////////////////////////////////////////////////////////////////////

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"
#include <fstream>
#include <Windows.h>
#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif


////@begin includes
////@end includes

#include "mainwindow.h"

////@begin XPM images
////@end XPM images


/*
 * MainWindow type definition
 */

IMPLEMENT_CLASS( MainWindow, wxFrame )


/*
 * MainWindow event table definition
 */

BEGIN_EVENT_TABLE( MainWindow, wxFrame )

////@begin MainWindow event table entries
    EVT_TEXT( ID_InpTextCtrl, MainWindow::OnInpTextCtrlTextUpdated )
    EVT_BUTTON( ID_PlusBtn, MainWindow::OnPlusBtnClick )
    EVT_BUTTON( ID_MinusBtn, MainWindow::OnMinusBtnClick )
    EVT_BUTTON( ID_MultiplyBtn, MainWindow::OnMultiplyBtnClick )
    EVT_BUTTON( ID_DivisionBtn, MainWindow::OnDivisionBtnClick )
    EVT_BUTTON( ID_OneBtn, MainWindow::OnOneBtnClick )
    EVT_BUTTON( ID_TwoBtn, MainWindow::OnTwoBtnClick )
    EVT_BUTTON( ID_ThreeBtn, MainWindow::OnThreeBtnClick )
    EVT_BUTTON( ID_PowerBtn, MainWindow::OnPowerBtnClick )
    EVT_BUTTON( ID_FourBtn, MainWindow::OnFourBtnClick )
    EVT_BUTTON( ID_FiveBtn, MainWindow::OnFiveBtnClick )
    EVT_BUTTON( ID_SixBtn, MainWindow::OnSixBtnClick )
    EVT_BUTTON( ID_AcBtn, MainWindow::OnAcBtnClick )
    EVT_BUTTON( ID_SevenBtn, MainWindow::OnSevenBtnClick )
    EVT_BUTTON( ID_EightBtn, MainWindow::OnEightBtnClick )
    EVT_BUTTON( ID_NineBtn, MainWindow::OnNineBtnClick )
    EVT_BUTTON( ID_DelBtn, MainWindow::OnDelBtnClick )
    EVT_BUTTON( ID_ZeroBtn, MainWindow::OnZeroBtnClick )
    EVT_BUTTON( ID_DotBtn, MainWindow::OnDotBtnClick )
    EVT_BUTTON( ID_OpBtn, MainWindow::OnOpBtnClick )
    EVT_BUTTON( ID_CpBtn, MainWindow::OnCpBtnClick )
    EVT_MENU( wxID_CLOSE, MainWindow::OnCloseClick )
    EVT_MENU( ID_STEPSMENU, MainWindow::OnStepsmenuClick )
    EVT_MENU( ID_TREEMENU, MainWindow::OnTreemenuClick )
    EVT_MENU( wxID_ABOUT, MainWindow::OnAboutClick )
////@end MainWindow event table entries

END_EVENT_TABLE()


/*
 * MainWindow constructors
 */

MainWindow::MainWindow()
{
    Init();
}

MainWindow::MainWindow( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
    Init();
    Create( parent, id, caption, pos, size, style );
	m_calculator = new mf::Calculator();
}


/*
 * MainWindow creator
 */

bool MainWindow::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
////@begin MainWindow creation
    wxFrame::Create( parent, id, caption, pos, size, style );

    this->SetBackgroundColour(wxColour(168, 191, 126));
    CreateControls();
    Centre();
////@end MainWindow creation
    return true;
}


/*
 * MainWindow destructor
 */

MainWindow::~MainWindow()
{
	delete m_calculator;
}


/*
 * Member initialisation
 */

void MainWindow::Init()
{
////@begin MainWindow member initialisation
    m_BoxSizerH1 = NULL;
    m_BoxSizerV2 = NULL;
    m_BoxSizerH3 = NULL;
    m_Panel = NULL;
    m_BoxSizerV4 = NULL;
    m_BoxSizerH5 = NULL;
    m_BoxSizerV6 = NULL;
    m_InpTextCtrl = NULL;
    m_OutTextCtrl = NULL;
    m_BoxSizerH7 = NULL;
    m_PlusBtn = NULL;
    m_MinusBtn = NULL;
    m_MultiplyBtn = NULL;
    m_DivisionBtn = NULL;
    m_BoxSizerH8 = NULL;
    m_OneBtn = NULL;
    m_TwoBtn = NULL;
    m_ThreeBtn = NULL;
    m_PowerBtn = NULL;
    m_BoxSizerH9 = NULL;
    m_FourBtn = NULL;
    m_FiveBtn = NULL;
    m_SixBtn = NULL;
    m_AcBtn = NULL;
    m_BoxSizer9 = NULL;
    m_SevenBtn = NULL;
    m_EightBtn = NULL;
    m_NineBtn = NULL;
    m_DelBtn = NULL;
    m_BoxSizerH10 = NULL;
    m_ZeroBtn = NULL;
    m_DotBtn = NULL;
    m_OpBtn = NULL;
    m_CpBtn = NULL;
    m_fileMenu = NULL;
    m_viewMenu = NULL;
    m_helpMenu = NULL;
////@end MainWindow member initialisation
}


/*
 * Control creation for MainWindow
 */

void MainWindow::CreateControls()
{    
////@begin MainWindow content construction
    MainWindow* itemFrame1 = this;

    wxMenuBar* menuBar = new wxMenuBar;
    m_fileMenu = new wxMenu;
    m_fileMenu->Append(wxID_CLOSE, _("Exit"), wxEmptyString, wxITEM_NORMAL);
    menuBar->Append(m_fileMenu, _("File"));
    m_viewMenu = new wxMenu;
    m_viewMenu->Append(ID_STEPSMENU, _("Steps"), wxEmptyString, wxITEM_NORMAL);
    m_viewMenu->Enable(ID_STEPSMENU, false);
    m_viewMenu->Append(ID_TREEMENU, _("Tree"), wxEmptyString, wxITEM_NORMAL);
    m_viewMenu->Enable(ID_TREEMENU, false);
    menuBar->Append(m_viewMenu, _("View"));
    m_helpMenu = new wxMenu;
    m_helpMenu->Append(wxID_ABOUT, _("About"), wxEmptyString, wxITEM_NORMAL);
    menuBar->Append(m_helpMenu, _("Help"));
    itemFrame1->SetMenuBar(menuBar);

    m_BoxSizerH1 = new wxBoxSizer(wxHORIZONTAL);
    itemFrame1->SetSizer(m_BoxSizerH1);

    m_BoxSizerV2 = new wxBoxSizer(wxVERTICAL);
    m_BoxSizerH1->Add(m_BoxSizerV2, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_BoxSizerH3 = new wxBoxSizer(wxHORIZONTAL);
    m_BoxSizerV2->Add(m_BoxSizerH3, 0, wxALIGN_CENTER_HORIZONTAL|wxLEFT|wxRIGHT|wxFIXED_MINSIZE, 5);

    m_Panel = new wxPanel( itemFrame1, ID_Panel, wxDefaultPosition, wxSize(327, 535), wxNO_BORDER|wxFULL_REPAINT_ON_RESIZE|wxTAB_TRAVERSAL );
    m_Panel->SetExtraStyle(wxWS_EX_VALIDATE_RECURSIVELY);
    m_BoxSizerH3->Add(m_Panel, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_BoxSizerV4 = new wxBoxSizer(wxVERTICAL);
    m_Panel->SetSizer(m_BoxSizerV4);

    m_BoxSizerV4->Add(3, 10, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    m_BoxSizerH5 = new wxBoxSizer(wxHORIZONTAL);
    m_BoxSizerV4->Add(m_BoxSizerH5, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    m_BoxSizerH5->Add(40, 6, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_BoxSizerV6 = new wxBoxSizer(wxVERTICAL);
    m_BoxSizerH5->Add(m_BoxSizerV6, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_InpTextCtrl = new wxTextCtrl( m_Panel, ID_InpTextCtrl, wxEmptyString, wxDefaultPosition, wxSize(200, 175), wxTE_MULTILINE|wxNO_BORDER|wxWANTS_CHARS );
    m_InpTextCtrl->SetForegroundColour(wxColour(255, 255, 255));
    m_InpTextCtrl->SetBackgroundColour(wxColour(99, 134, 150));
    m_InpTextCtrl->SetFont(wxFont(12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Consolas")));
    m_BoxSizerV6->Add(m_InpTextCtrl, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    m_BoxSizerV6->Add(5, 0, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    m_OutTextCtrl = new wxTextCtrl( m_Panel, ID_OutTextCtrl, wxEmptyString, wxDefaultPosition, wxSize(200, -1), wxTE_READONLY|wxNO_BORDER );
    m_OutTextCtrl->SetForegroundColour(wxColour(255, 255, 255));
    m_OutTextCtrl->SetBackgroundColour(wxColour(99, 134, 150));
    m_OutTextCtrl->SetFont(wxFont(12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Consolas")));
    m_BoxSizerV6->Add(m_OutTextCtrl, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    m_BoxSizerH7 = new wxBoxSizer(wxHORIZONTAL);
    m_BoxSizerV4->Add(m_BoxSizerH7, 0, wxALIGN_CENTER_HORIZONTAL|wxLEFT|wxRIGHT, 5);

    m_PlusBtn = new wxBitmapButton( m_Panel, ID_PlusBtn, itemFrame1->GetBitmapResource(wxT("Images/RedButton/OperatorsNormal/RedButtonNormalPlus.png")), wxDefaultPosition, wxSize(66, 40), wxBU_AUTODRAW );
    wxBitmap m_PlusBtnBitmapHover(itemFrame1->GetBitmapResource(wxT("Images/RedButton/OperatorsHover/RedButtonHoverPlus.png")));
    m_PlusBtn->SetBitmapHover(m_PlusBtnBitmapHover);
    m_BoxSizerH7->Add(m_PlusBtn, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_MinusBtn = new wxBitmapButton( m_Panel, ID_MinusBtn, itemFrame1->GetBitmapResource(wxT("Images/RedButton/OperatorsNormal/RedButtonNormalMinus.png")), wxDefaultPosition, wxSize(66, 40), wxBU_AUTODRAW );
    wxBitmap m_MinusBtnBitmapHover(itemFrame1->GetBitmapResource(wxT("Images/RedButton/OperatorsHover/RedButtonHoverMinus.png")));
    m_MinusBtn->SetBitmapHover(m_MinusBtnBitmapHover);
    m_BoxSizerH7->Add(m_MinusBtn, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_MultiplyBtn = new wxBitmapButton( m_Panel, ID_MultiplyBtn, itemFrame1->GetBitmapResource(wxT("Images/RedButton/OperatorsNormal/RedButtonNormalMuliply.png")), wxDefaultPosition, wxSize(66, 40), wxBU_AUTODRAW );
    wxBitmap m_MultiplyBtnBitmapHover(itemFrame1->GetBitmapResource(wxT("Images/RedButton/OperatorsHover/RedButtonHoverMultiply.png")));
    m_MultiplyBtn->SetBitmapHover(m_MultiplyBtnBitmapHover);
    m_BoxSizerH7->Add(m_MultiplyBtn, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_DivisionBtn = new wxBitmapButton( m_Panel, ID_DivisionBtn, itemFrame1->GetBitmapResource(wxT("Images/RedButton/OperatorsNormal/RedButtonNormalDivision.png")), wxDefaultPosition, wxSize(66, 40), wxBU_AUTODRAW );
    wxBitmap m_DivisionBtnBitmapHover(itemFrame1->GetBitmapResource(wxT("Images/RedButton/OperatorsHover/RedButtonHoverDivision.png")));
    m_DivisionBtn->SetBitmapHover(m_DivisionBtnBitmapHover);
    m_BoxSizerH7->Add(m_DivisionBtn, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_BoxSizerH8 = new wxBoxSizer(wxHORIZONTAL);
    m_BoxSizerV4->Add(m_BoxSizerH8, 0, wxALIGN_CENTER_HORIZONTAL|wxLEFT|wxRIGHT, 5);

    m_OneBtn = new wxBitmapButton( m_Panel, ID_OneBtn, itemFrame1->GetBitmapResource(wxT("Images/BlueButton/NumbersNormal/BlueButtonNormal1.png")), wxDefaultPosition, wxSize(66, 40), wxBU_AUTODRAW );
    wxBitmap m_OneBtnBitmapHover(itemFrame1->GetBitmapResource(wxT("Images/BlueButton/NumbersHover/BlueButtonNormal1.png")));
    m_OneBtn->SetBitmapHover(m_OneBtnBitmapHover);
    m_BoxSizerH8->Add(m_OneBtn, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_TwoBtn = new wxBitmapButton( m_Panel, ID_TwoBtn, itemFrame1->GetBitmapResource(wxT("Images/BlueButton/NumbersNormal/BlueButtonNormal2.png")), wxDefaultPosition, wxSize(66, 40), wxBU_AUTODRAW );
    wxBitmap m_TwoBtnBitmapHover(itemFrame1->GetBitmapResource(wxT("Images/BlueButton/NumbersHover/BlueButtonNormal2.png")));
    m_TwoBtn->SetBitmapHover(m_TwoBtnBitmapHover);
    m_BoxSizerH8->Add(m_TwoBtn, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_ThreeBtn = new wxBitmapButton( m_Panel, ID_ThreeBtn, itemFrame1->GetBitmapResource(wxT("Images/BlueButton/NumbersNormal/BlueButtonNormal3.png")), wxDefaultPosition, wxSize(66, 40), wxBU_AUTODRAW );
    wxBitmap m_ThreeBtnBitmapHover(itemFrame1->GetBitmapResource(wxT("Images/BlueButton/NumbersHover/BlueButtonNormal3.png")));
    m_ThreeBtn->SetBitmapHover(m_ThreeBtnBitmapHover);
    m_BoxSizerH8->Add(m_ThreeBtn, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_PowerBtn = new wxBitmapButton( m_Panel, ID_PowerBtn, itemFrame1->GetBitmapResource(wxT("Images/RedButton/OperatorsNormal/RedButtonNormalPower.png")), wxDefaultPosition, wxSize(66, 40), wxBU_AUTODRAW );
    wxBitmap m_PowerBtnBitmapHover(itemFrame1->GetBitmapResource(wxT("Images/RedButton/OperatorsHover/RedButtonHoverPower.png")));
    m_PowerBtn->SetBitmapHover(m_PowerBtnBitmapHover);
    m_BoxSizerH8->Add(m_PowerBtn, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_BoxSizerH9 = new wxBoxSizer(wxHORIZONTAL);
    m_BoxSizerV4->Add(m_BoxSizerH9, 0, wxALIGN_CENTER_HORIZONTAL|wxLEFT|wxRIGHT, 5);

    m_FourBtn = new wxBitmapButton( m_Panel, ID_FourBtn, itemFrame1->GetBitmapResource(wxT("Images/BlueButton/NumbersNormal/BlueButtonNormal4.png")), wxDefaultPosition, wxSize(66, 40), wxBU_AUTODRAW );
    wxBitmap m_FourBtnBitmapHover(itemFrame1->GetBitmapResource(wxT("Images/BlueButton/NumbersHover/BlueButtonNormal4.png")));
    m_FourBtn->SetBitmapHover(m_FourBtnBitmapHover);
    m_BoxSizerH9->Add(m_FourBtn, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_FiveBtn = new wxBitmapButton( m_Panel, ID_FiveBtn, itemFrame1->GetBitmapResource(wxT("Images/BlueButton/NumbersNormal/BlueButtonNormal5.png")), wxDefaultPosition, wxSize(66, 40), wxBU_AUTODRAW );
    wxBitmap m_FiveBtnBitmapHover(itemFrame1->GetBitmapResource(wxT("Images/BlueButton/NumbersHover/BlueButtonNormal5.png")));
    m_FiveBtn->SetBitmapHover(m_FiveBtnBitmapHover);
    m_BoxSizerH9->Add(m_FiveBtn, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_SixBtn = new wxBitmapButton( m_Panel, ID_SixBtn, itemFrame1->GetBitmapResource(wxT("Images/BlueButton/NumbersNormal/BlueButtonNormal6.png")), wxDefaultPosition, wxSize(66, 40), wxBU_AUTODRAW );
    wxBitmap m_SixBtnBitmapHover(itemFrame1->GetBitmapResource(wxT("Images/BlueButton/NumbersHover/BlueButtonNormal6.png")));
    m_SixBtn->SetBitmapHover(m_SixBtnBitmapHover);
    m_BoxSizerH9->Add(m_SixBtn, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_AcBtn = new wxBitmapButton( m_Panel, ID_AcBtn, itemFrame1->GetBitmapResource(wxT("Images/YellowButton/OperatorsNormal/YellowButtonNormalAC.png")), wxDefaultPosition, wxSize(66, 40), wxBU_AUTODRAW );
    wxBitmap m_AcBtnBitmapHover(itemFrame1->GetBitmapResource(wxT("Images/YellowButton/OperatorsHover/YellowButtonHoverAC.png")));
    m_AcBtn->SetBitmapHover(m_AcBtnBitmapHover);
    m_BoxSizerH9->Add(m_AcBtn, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_BoxSizer9 = new wxBoxSizer(wxHORIZONTAL);
    m_BoxSizerV4->Add(m_BoxSizer9, 0, wxALIGN_CENTER_HORIZONTAL|wxLEFT|wxRIGHT, 5);

    m_SevenBtn = new wxBitmapButton( m_Panel, ID_SevenBtn, itemFrame1->GetBitmapResource(wxT("Images/BlueButton/NumbersNormal/BlueButtonNormal7.png")), wxDefaultPosition, wxSize(66, 40), wxBU_AUTODRAW );
    wxBitmap m_SevenBtnBitmapHover(itemFrame1->GetBitmapResource(wxT("Images/BlueButton/NumbersHover/BlueButtonNormal7.png")));
    m_SevenBtn->SetBitmapHover(m_SevenBtnBitmapHover);
    m_BoxSizer9->Add(m_SevenBtn, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_EightBtn = new wxBitmapButton( m_Panel, ID_EightBtn, itemFrame1->GetBitmapResource(wxT("Images/BlueButton/NumbersNormal/BlueButtonNormal8.png")), wxDefaultPosition, wxSize(66, 40), wxBU_AUTODRAW );
    wxBitmap m_EightBtnBitmapHover(itemFrame1->GetBitmapResource(wxT("Images/BlueButton/NumbersHover/BlueButtonNormal8.png")));
    m_EightBtn->SetBitmapHover(m_EightBtnBitmapHover);
    m_BoxSizer9->Add(m_EightBtn, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_NineBtn = new wxBitmapButton( m_Panel, ID_NineBtn, itemFrame1->GetBitmapResource(wxT("Images/BlueButton/NumbersNormal/BlueButtonNormal9.png")), wxDefaultPosition, wxSize(66, 40), wxBU_AUTODRAW );
    wxBitmap m_NineBtnBitmapHover(itemFrame1->GetBitmapResource(wxT("Images/BlueButton/NumbersHover/BlueButtonNormal9.png")));
    m_NineBtn->SetBitmapHover(m_NineBtnBitmapHover);
    m_BoxSizer9->Add(m_NineBtn, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_DelBtn = new wxBitmapButton( m_Panel, ID_DelBtn, itemFrame1->GetBitmapResource(wxT("Images/YellowButton/OperatorsNormal/YellowButtonNormalDel.png")), wxDefaultPosition, wxSize(66, 40), wxBU_AUTODRAW );
    wxBitmap m_DelBtnBitmapHover(itemFrame1->GetBitmapResource(wxT("Images/YellowButton/OperatorsHover/YellowButtonHoverDel.png")));
    m_DelBtn->SetBitmapHover(m_DelBtnBitmapHover);
    m_BoxSizer9->Add(m_DelBtn, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_BoxSizerH10 = new wxBoxSizer(wxHORIZONTAL);
    m_BoxSizerV4->Add(m_BoxSizerH10, 0, wxALIGN_CENTER_HORIZONTAL|wxLEFT|wxRIGHT, 5);

    m_ZeroBtn = new wxBitmapButton( m_Panel, ID_ZeroBtn, itemFrame1->GetBitmapResource(wxT("Images/BlueButton/NumbersNormal/BlueButtonNormal0.png")), wxDefaultPosition, wxSize(66, 40), wxBU_AUTODRAW );
    wxBitmap m_ZeroBtnBitmapHover(itemFrame1->GetBitmapResource(wxT("Images/BlueButton/NumbersHover/BlueButtonNormal0.png")));
    m_ZeroBtn->SetBitmapHover(m_ZeroBtnBitmapHover);
    m_BoxSizerH10->Add(m_ZeroBtn, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_DotBtn = new wxBitmapButton( m_Panel, ID_DotBtn, itemFrame1->GetBitmapResource(wxT("Images/BlueButton/NumbersNormal/BlueButtonNormalDot.png")), wxDefaultPosition, wxSize(66, 40), wxBU_AUTODRAW );
    wxBitmap m_DotBtnBitmapHover(itemFrame1->GetBitmapResource(wxT("Images/BlueButton/NumbersHover/BlueButtonNormalDot.png")));
    m_DotBtn->SetBitmapHover(m_DotBtnBitmapHover);
    m_BoxSizerH10->Add(m_DotBtn, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_OpBtn = new wxBitmapButton( m_Panel, ID_OpBtn, itemFrame1->GetBitmapResource(wxT("Images/YellowButton/OperatorsNormal/YellowButtonNormalOp.png")), wxDefaultPosition, wxSize(66, 40), wxBU_AUTODRAW );
    wxBitmap m_OpBtnBitmapHover(itemFrame1->GetBitmapResource(wxT("Images/YellowButton/OperatorsHover/YellowButtonOp.png")));
    m_OpBtn->SetBitmapHover(m_OpBtnBitmapHover);
    m_BoxSizerH10->Add(m_OpBtn, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_CpBtn = new wxBitmapButton( m_Panel, ID_CpBtn, itemFrame1->GetBitmapResource(wxT("Images/YellowButton/OperatorsNormal/YellowButtonNormalCp.png")), wxDefaultPosition, wxSize(66, 40), wxBU_AUTODRAW );
    wxBitmap m_CpBtnBitmapHover(itemFrame1->GetBitmapResource(wxT("Images/YellowButton/OperatorsHover/YellowButtonCp.png")));
    m_CpBtn->SetBitmapHover(m_CpBtnBitmapHover);
    m_BoxSizerH10->Add(m_CpBtn, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_BoxSizerV4->Add(5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    // Connect events and objects
    m_Panel->Connect(ID_Panel, wxEVT_PAINT, wxPaintEventHandler(MainWindow::OnPaint), NULL, this);
////@end MainWindow content construction
}


/*
 * Should we show tooltips?
 */

bool MainWindow::ShowToolTips()
{
    return true;
}

/*
 * Get bitmap resources
 */

wxBitmap MainWindow::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin MainWindow bitmap retrieval
    wxUnusedVar(name);
    if (name == wxT("Images/Panel/Panel.png"))
    {
        wxBitmap bitmap(wxT("Images/Panel/Panel.png"), wxBITMAP_TYPE_PNG);
        return bitmap;
    }
    else if (name == wxT("Images/RedButton/OperatorsNormal/RedButtonNormalPlus.png"))
    {
        wxBitmap bitmap(wxT("Images/RedButton/OperatorsNormal/RedButtonNormalPlus.png"), wxBITMAP_TYPE_PNG);
        return bitmap;
    }
    else if (name == wxT("Images/RedButton/OperatorsHover/RedButtonHoverPlus.png"))
    {
        wxBitmap bitmap(wxT("Images/RedButton/OperatorsHover/RedButtonHoverPlus.png"), wxBITMAP_TYPE_PNG);
        return bitmap;
    }
    else if (name == wxT("Images/RedButton/OperatorsNormal/RedButtonNormalMinus.png"))
    {
        wxBitmap bitmap(wxT("Images/RedButton/OperatorsNormal/RedButtonNormalMinus.png"), wxBITMAP_TYPE_PNG);
        return bitmap;
    }
    else if (name == wxT("Images/RedButton/OperatorsHover/RedButtonHoverMinus.png"))
    {
        wxBitmap bitmap(wxT("Images/RedButton/OperatorsHover/RedButtonHoverMinus.png"), wxBITMAP_TYPE_PNG);
        return bitmap;
    }
    else if (name == wxT("Images/RedButton/OperatorsNormal/RedButtonNormalMuliply.png"))
    {
        wxBitmap bitmap(wxT("Images/RedButton/OperatorsNormal/RedButtonNormalMuliply.png"), wxBITMAP_TYPE_PNG);
        return bitmap;
    }
    else if (name == wxT("Images/RedButton/OperatorsHover/RedButtonHoverMultiply.png"))
    {
        wxBitmap bitmap(wxT("Images/RedButton/OperatorsHover/RedButtonHoverMultiply.png"), wxBITMAP_TYPE_PNG);
        return bitmap;
    }
    else if (name == wxT("Images/RedButton/OperatorsNormal/RedButtonNormalDivision.png"))
    {
        wxBitmap bitmap(wxT("Images/RedButton/OperatorsNormal/RedButtonNormalDivision.png"), wxBITMAP_TYPE_PNG);
        return bitmap;
    }
    else if (name == wxT("Images/RedButton/OperatorsHover/RedButtonHoverDivision.png"))
    {
        wxBitmap bitmap(wxT("Images/RedButton/OperatorsHover/RedButtonHoverDivision.png"), wxBITMAP_TYPE_PNG);
        return bitmap;
    }
    else if (name == wxT("Images/BlueButton/NumbersNormal/BlueButtonNormal1.png"))
    {
        wxBitmap bitmap(wxT("Images/BlueButton/NumbersNormal/BlueButtonNormal1.png"), wxBITMAP_TYPE_PNG);
        return bitmap;
    }
    else if (name == wxT("Images/BlueButton/NumbersHover/BlueButtonNormal1.png"))
    {
        wxBitmap bitmap(wxT("Images/BlueButton/NumbersHover/BlueButtonNormal1.png"), wxBITMAP_TYPE_PNG);
        return bitmap;
    }
    else if (name == wxT("Images/BlueButton/NumbersNormal/BlueButtonNormal2.png"))
    {
        wxBitmap bitmap(wxT("Images/BlueButton/NumbersNormal/BlueButtonNormal2.png"), wxBITMAP_TYPE_PNG);
        return bitmap;
    }
    else if (name == wxT("Images/BlueButton/NumbersHover/BlueButtonNormal2.png"))
    {
        wxBitmap bitmap(wxT("Images/BlueButton/NumbersHover/BlueButtonNormal2.png"), wxBITMAP_TYPE_PNG);
        return bitmap;
    }
    else if (name == wxT("Images/BlueButton/NumbersNormal/BlueButtonNormal3.png"))
    {
        wxBitmap bitmap(wxT("Images/BlueButton/NumbersNormal/BlueButtonNormal3.png"), wxBITMAP_TYPE_PNG);
        return bitmap;
    }
    else if (name == wxT("Images/BlueButton/NumbersHover/BlueButtonNormal3.png"))
    {
        wxBitmap bitmap(wxT("Images/BlueButton/NumbersHover/BlueButtonNormal3.png"), wxBITMAP_TYPE_PNG);
        return bitmap;
    }
    else if (name == wxT("Images/RedButton/OperatorsNormal/RedButtonNormalPower.png"))
    {
        wxBitmap bitmap(wxT("Images/RedButton/OperatorsNormal/RedButtonNormalPower.png"), wxBITMAP_TYPE_PNG);
        return bitmap;
    }
    else if (name == wxT("Images/RedButton/OperatorsHover/RedButtonHoverPower.png"))
    {
        wxBitmap bitmap(wxT("Images/RedButton/OperatorsHover/RedButtonHoverPower.png"), wxBITMAP_TYPE_PNG);
        return bitmap;
    }
    else if (name == wxT("Images/BlueButton/NumbersNormal/BlueButtonNormal4.png"))
    {
        wxBitmap bitmap(wxT("Images/BlueButton/NumbersNormal/BlueButtonNormal4.png"), wxBITMAP_TYPE_PNG);
        return bitmap;
    }
    else if (name == wxT("Images/BlueButton/NumbersHover/BlueButtonNormal4.png"))
    {
        wxBitmap bitmap(wxT("Images/BlueButton/NumbersHover/BlueButtonNormal4.png"), wxBITMAP_TYPE_PNG);
        return bitmap;
    }
    else if (name == wxT("Images/BlueButton/NumbersNormal/BlueButtonNormal5.png"))
    {
        wxBitmap bitmap(wxT("Images/BlueButton/NumbersNormal/BlueButtonNormal5.png"), wxBITMAP_TYPE_PNG);
        return bitmap;
    }
    else if (name == wxT("Images/BlueButton/NumbersHover/BlueButtonNormal5.png"))
    {
        wxBitmap bitmap(wxT("Images/BlueButton/NumbersHover/BlueButtonNormal5.png"), wxBITMAP_TYPE_PNG);
        return bitmap;
    }
    else if (name == wxT("Images/BlueButton/NumbersNormal/BlueButtonNormal6.png"))
    {
        wxBitmap bitmap(wxT("Images/BlueButton/NumbersNormal/BlueButtonNormal6.png"), wxBITMAP_TYPE_PNG);
        return bitmap;
    }
    else if (name == wxT("Images/BlueButton/NumbersHover/BlueButtonNormal6.png"))
    {
        wxBitmap bitmap(wxT("Images/BlueButton/NumbersHover/BlueButtonNormal6.png"), wxBITMAP_TYPE_PNG);
        return bitmap;
    }
    else if (name == wxT("Images/YellowButton/OperatorsNormal/YellowButtonNormalAC.png"))
    {
        wxBitmap bitmap(wxT("Images/YellowButton/OperatorsNormal/YellowButtonNormalAC.png"), wxBITMAP_TYPE_PNG);
        return bitmap;
    }
    else if (name == wxT("Images/YellowButton/OperatorsHover/YellowButtonHoverAC.png"))
    {
        wxBitmap bitmap(wxT("Images/YellowButton/OperatorsHover/YellowButtonHoverAC.png"), wxBITMAP_TYPE_PNG);
        return bitmap;
    }
    else if (name == wxT("Images/BlueButton/NumbersNormal/BlueButtonNormal7.png"))
    {
        wxBitmap bitmap(wxT("Images/BlueButton/NumbersNormal/BlueButtonNormal7.png"), wxBITMAP_TYPE_PNG);
        return bitmap;
    }
    else if (name == wxT("Images/BlueButton/NumbersHover/BlueButtonNormal7.png"))
    {
        wxBitmap bitmap(wxT("Images/BlueButton/NumbersHover/BlueButtonNormal7.png"), wxBITMAP_TYPE_PNG);
        return bitmap;
    }
    else if (name == wxT("Images/BlueButton/NumbersNormal/BlueButtonNormal8.png"))
    {
        wxBitmap bitmap(wxT("Images/BlueButton/NumbersNormal/BlueButtonNormal8.png"), wxBITMAP_TYPE_PNG);
        return bitmap;
    }
    else if (name == wxT("Images/BlueButton/NumbersHover/BlueButtonNormal8.png"))
    {
        wxBitmap bitmap(wxT("Images/BlueButton/NumbersHover/BlueButtonNormal8.png"), wxBITMAP_TYPE_PNG);
        return bitmap;
    }
    else if (name == wxT("Images/BlueButton/NumbersNormal/BlueButtonNormal9.png"))
    {
        wxBitmap bitmap(wxT("Images/BlueButton/NumbersNormal/BlueButtonNormal9.png"), wxBITMAP_TYPE_PNG);
        return bitmap;
    }
    else if (name == wxT("Images/BlueButton/NumbersHover/BlueButtonNormal9.png"))
    {
        wxBitmap bitmap(wxT("Images/BlueButton/NumbersHover/BlueButtonNormal9.png"), wxBITMAP_TYPE_PNG);
        return bitmap;
    }
    else if (name == wxT("Images/YellowButton/OperatorsNormal/YellowButtonNormalDel.png"))
    {
        wxBitmap bitmap(wxT("Images/YellowButton/OperatorsNormal/YellowButtonNormalDel.png"), wxBITMAP_TYPE_PNG);
        return bitmap;
    }
    else if (name == wxT("Images/YellowButton/OperatorsHover/YellowButtonHoverDel.png"))
    {
        wxBitmap bitmap(wxT("Images/YellowButton/OperatorsHover/YellowButtonHoverDel.png"), wxBITMAP_TYPE_PNG);
        return bitmap;
    }
    else if (name == wxT("Images/BlueButton/NumbersNormal/BlueButtonNormal0.png"))
    {
        wxBitmap bitmap(wxT("Images/BlueButton/NumbersNormal/BlueButtonNormal0.png"), wxBITMAP_TYPE_PNG);
        return bitmap;
    }
    else if (name == wxT("Images/BlueButton/NumbersHover/BlueButtonNormal0.png"))
    {
        wxBitmap bitmap(wxT("Images/BlueButton/NumbersHover/BlueButtonNormal0.png"), wxBITMAP_TYPE_PNG);
        return bitmap;
    }
    else if (name == wxT("Images/BlueButton/NumbersNormal/BlueButtonNormalDot.png"))
    {
        wxBitmap bitmap(wxT("Images/BlueButton/NumbersNormal/BlueButtonNormalDot.png"), wxBITMAP_TYPE_PNG);
        return bitmap;
    }
    else if (name == wxT("Images/BlueButton/NumbersHover/BlueButtonNormalDot.png"))
    {
        wxBitmap bitmap(wxT("Images/BlueButton/NumbersHover/BlueButtonNormalDot.png"), wxBITMAP_TYPE_PNG);
        return bitmap;
    }
    else if (name == wxT("Images/YellowButton/OperatorsNormal/YellowButtonNormalOp.png"))
    {
        wxBitmap bitmap(wxT("Images/YellowButton/OperatorsNormal/YellowButtonNormalOp.png"), wxBITMAP_TYPE_PNG);
        return bitmap;
    }
    else if (name == wxT("Images/YellowButton/OperatorsHover/YellowButtonOp.png"))
    {
        wxBitmap bitmap(wxT("Images/YellowButton/OperatorsHover/YellowButtonOp.png"), wxBITMAP_TYPE_PNG);
        return bitmap;
    }
    else if (name == wxT("Images/YellowButton/OperatorsNormal/YellowButtonNormalCp.png"))
    {
        wxBitmap bitmap(wxT("Images/YellowButton/OperatorsNormal/YellowButtonNormalCp.png"), wxBITMAP_TYPE_PNG);
        return bitmap;
    }
    else if (name == wxT("Images/YellowButton/OperatorsHover/YellowButtonCp.png"))
    {
        wxBitmap bitmap(wxT("Images/YellowButton/OperatorsHover/YellowButtonCp.png"), wxBITMAP_TYPE_PNG);
        return bitmap;
    }
    return wxNullBitmap;
////@end MainWindow bitmap retrieval
}

/*
 * Get icon resources
 */

wxIcon MainWindow::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin MainWindow icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end MainWindow icon retrieval
}


/*
 * wxEVT_PAINT event handler for ID_PANEL
 */

void MainWindow::OnPaint( wxPaintEvent& event )
{
////@begin wxEVT_PAINT event handler for ID_PANEL in MainWindow.
    wxWindow* window = wxDynamicCast(event.GetEventObject(), wxWindow);
    wxPaintDC dc(window);
    wxRect rect = window->GetClientRect();
    wxBitmap texture = GetBitmapResource(wxT("Images/Panel/Panel.png"));
    if (texture.Ok() && texture.GetWidth() > 0 && texture.GetHeight() > 0)
    {
        wxSize sz = rect.GetSize();
        dc.DrawBitmap(texture, ((sz.x - texture.GetWidth())/2), ((sz.y - texture.GetHeight())/2), false);
    }
////@end wxEVT_PAINT event handler for ID_PANEL in MainWindow. 
}


/*
 * wxEVT_COMMAND_TEXT_UPDATED event handler for ID_InpTextCtrl
 */

void MainWindow::OnInpTextCtrlTextUpdated( wxCommandEvent& event )
{
	m_viewMenu->Enable(ID_STEPSMENU, false);
	m_viewMenu->Enable(ID_TREEMENU, false);

	wxString temp = wxT("");

	for (int i = 0; i < m_InpTextCtrl->GetNumberOfLines(); ++i)
	{
		temp += m_InpTextCtrl->GetLineText(i);
	}

	if (temp != wxT(""))
	{
		try
		{
			m_calculator->calculate(temp.ToStdString());
			m_answer = m_calculator->getAnswer();
			m_steps = m_calculator->getSteps();

			if (std::isinf(m_answer))
			{
				m_OutTextCtrl->SetLabelText(wxT("Too big!"));
			}
			else
			{
				m_OutTextCtrl->SetLabelText(m_calculator->getAnswerString());
			}

			auto postfix = m_calculator->getPostfix();

			std::ofstream file("postfix.txt");

			for (std::string cur : *postfix)
			{
				file << cur << std::endl;
			}

			if (postfix->getSize() > 1)
			{
				m_viewMenu->Enable(ID_STEPSMENU, true);
				m_viewMenu->Enable(ID_TREEMENU, true);
			}
		}
		catch (char* error)
		{
			m_OutTextCtrl->SetLabelText(error);
		}
		catch (...)
		{
			m_OutTextCtrl->SetLabelText("Syntax Error");
		}
	}
	else
	{
		m_OutTextCtrl->SetLabelText("");
	}

    event.Skip();
}


/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_PlusBtn
 */

void MainWindow::OnPlusBtnClick( wxCommandEvent& event )
{
	m_InpTextCtrl->AppendText(wxT("+"));
	event.Skip();
}


/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_MinusBtn
 */

void MainWindow::OnMinusBtnClick( wxCommandEvent& event )
{
	m_InpTextCtrl->AppendText(wxT("-"));
	event.Skip();
}


/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_MultiplyBtn
 */

void MainWindow::OnMultiplyBtnClick( wxCommandEvent& event )
{
	m_InpTextCtrl->AppendText(wxT("*"));
	event.Skip();
}


/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_DivisionBtn
 */

void MainWindow::OnDivisionBtnClick( wxCommandEvent& event )
{
	m_InpTextCtrl->AppendText(wxT("/"));
	event.Skip();
}


/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_OneBtn
 */

void MainWindow::OnOneBtnClick( wxCommandEvent& event )
{
	m_InpTextCtrl->AppendText(wxT("1"));
    event.Skip();
}


/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_TwoBtn
 */

void MainWindow::OnTwoBtnClick( wxCommandEvent& event )
{
	m_InpTextCtrl->AppendText(wxT("2"));
	event.Skip();
}


/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_ThreeBtn
 */

void MainWindow::OnThreeBtnClick( wxCommandEvent& event )
{
	m_InpTextCtrl->AppendText(wxT("3"));
	event.Skip();
}


/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_PowerBtn
 */

void MainWindow::OnPowerBtnClick( wxCommandEvent& event )
{
	m_InpTextCtrl->AppendText(wxT("^"));
	event.Skip();
}


/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_FourBtn
 */

void MainWindow::OnFourBtnClick( wxCommandEvent& event )
{
	m_InpTextCtrl->AppendText(wxT("4"));
	event.Skip();
}


/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_FiveBtn
 */

void MainWindow::OnFiveBtnClick( wxCommandEvent& event )
{
	m_InpTextCtrl->AppendText(wxT("5"));
	event.Skip();
}


/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_SixBtn
 */

void MainWindow::OnSixBtnClick( wxCommandEvent& event )
{
	m_InpTextCtrl->AppendText(wxT("6"));
	event.Skip();
}


/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_AcBtn
 */

void MainWindow::OnAcBtnClick( wxCommandEvent& event )
{
	m_InpTextCtrl->SetLabelText(wxT(""));
	m_OutTextCtrl->SetLabelText(wxT(""));
    m_steps = "";
	event.Skip();
}


/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_SevenBtn
 */

void MainWindow::OnSevenBtnClick( wxCommandEvent& event )
{
	m_InpTextCtrl->AppendText(wxT("7"));
	event.Skip();
}


/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_EightBtn
 */

void MainWindow::OnEightBtnClick( wxCommandEvent& event )
{
	m_InpTextCtrl->AppendText(wxT("8"));
	event.Skip();
}


/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_NineBtn
 */

void MainWindow::OnNineBtnClick( wxCommandEvent& event )
{
	m_InpTextCtrl->AppendText(wxT("9"));
	event.Skip();
}


/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_DelBtn
 */

void MainWindow::OnDelBtnClick( wxCommandEvent& event )
{
	if(m_InpTextCtrl->GetLineText(0) != wxT(""))
	{
		wxString temp = wxT("");
		for (int i = 0; i < m_InpTextCtrl->GetNumberOfLines(); ++i)
		{
			temp += m_InpTextCtrl->GetLineText(i);
		}

		m_InpTextCtrl->SetLabelText(wxT(""));

		for (int i = 0; i < temp.Length() - 1; ++i)
		{
			m_InpTextCtrl->AppendText(temp[i]);
		}

		if (m_InpTextCtrl->GetLineText(0) == wxT(""))
		{
			m_OutTextCtrl->SetLabelText(wxT(""));
		}

	}

    event.Skip();
 
}


/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_ZeroBtn
 */

void MainWindow::OnZeroBtnClick( wxCommandEvent& event )
{
	m_InpTextCtrl->AppendText(wxT("0"));
	event.Skip();
}


/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_DotBtn
 */

void MainWindow::OnDotBtnClick( wxCommandEvent& event )
{
	m_InpTextCtrl->AppendText(wxT("."));
	event.Skip();
}


/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_OpBtn
 */

void MainWindow::OnOpBtnClick( wxCommandEvent& event )
{
	m_InpTextCtrl->AppendText(wxT("("));
	event.Skip();
}


/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_CpBtn
 */

void MainWindow::OnCpBtnClick( wxCommandEvent& event )
{
	m_InpTextCtrl->AppendText(wxT(")"));
	event.Skip();
}


/*
 * wxEVT_COMMAND_MENU_SELECTED event handler for ID_MENUITEM
 */

void MainWindow::OnCloseClick( wxCommandEvent& event )
{
    this->Close();
    event.Skip();
}


/*
 * wxEVT_COMMAND_MENU_SELECTED event handler for wxID_ABOUT
 */

void MainWindow::OnAboutClick( wxCommandEvent& event )
{
    wxAboutDialogInfo aboutInfo;
    aboutInfo.SetName("mfCalculator");
    aboutInfo.SetVersion(_("1.0"));
    aboutInfo.SetDescription(_("A simple calculator made with c++ and wxWidgets :)"));
    aboutInfo.AddDeveloper("Mehrshad Jafari Farahani");
    wxAboutBox(aboutInfo);
    event.Skip();

}


/*
 * wxEVT_COMMAND_MENU_SELECTED event handler for ID_STEPS
 */

void MainWindow::OnStepsmenuClick( wxCommandEvent& event )
{
    Steps* stepsDialog = new Steps(this, wxID_ANY, wxT("Steps"));
    
    wxString temp = wxT("");

	for (int i = 0; i < m_InpTextCtrl->GetNumberOfLines(); ++i)
	{
		temp += m_InpTextCtrl->GetLineText(i);
	}
    
    stepsDialog->m_StepsTxtCtrl->AppendText(temp);
    stepsDialog->m_StepsTxtCtrl->AppendText("\n");
    stepsDialog->m_StepsTxtCtrl->AppendText(m_steps);
    stepsDialog->Show();
    event.Skip();

}


/*
 * wxEVT_COMMAND_MENU_SELECTED event handler for ID_TREEMENU
 */

void MainWindow::OnTreemenuClick( wxCommandEvent& event )
{
	STARTUPINFO startInfo = { 0 };

	PROCESS_INFORMATION processInfo = { 0 };

	BOOL bSuccess = CreateProcess(TEXT("mfTreeUi.exe"), NULL, NULL, NULL, FALSE, NULL, NULL,
		NULL, &startInfo, &processInfo);

    event.Skip();
}

