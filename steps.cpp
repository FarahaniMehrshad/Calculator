/////////////////////////////////////////////////////////////////////////////
// Name:        steps.cpp
// Purpose:     
// Author:      Mehrshad Jafari Farahani
// Modified by: 
// Created:     05/12/2021 23:11:12
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

#include "steps.h"

////@begin XPM images
////@end XPM images


/*
 * Steps type definition
 */

IMPLEMENT_DYNAMIC_CLASS( Steps, wxDialog )


/*
 * Steps event table definition
 */

BEGIN_EVENT_TABLE( Steps, wxDialog )

////@begin Steps event table entries
////@end Steps event table entries

END_EVENT_TABLE()


/*
 * Steps constructors
 */

Steps::Steps()
{
    Init();
}

Steps::Steps( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
    Init();
    Create(parent, id, caption, pos, size, style);
}


/*
 * Steps creator
 */

bool Steps::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
////@begin Steps creation
    SetExtraStyle(wxWS_EX_VALIDATE_RECURSIVELY|wxWS_EX_BLOCK_EVENTS);
    wxDialog::Create( parent, id, caption, pos, size, style );

    CreateControls();
    if (GetSizer())
    {
        GetSizer()->SetSizeHints(this);
    }
    Centre();
////@end Steps creation
    return true;
}


/*
 * Steps destructor
 */

Steps::~Steps()
{
////@begin Steps destruction
////@end Steps destruction
}


/*
 * Member initialisation
 */

void Steps::Init()
{
////@begin Steps member initialisation
    m_BoxSizerV1 = NULL;
    m_Panel = NULL;
    m_BoxSizerV2 = NULL;
    m_StepsTxtCtrl = NULL;
////@end Steps member initialisation
}


/*
 * Control creation for Steps
 */

void Steps::CreateControls()
{    
////@begin Steps content construction
    Steps* itemDialog1 = this;

    this->SetBackgroundColour(wxColour(168, 191, 126));
    m_BoxSizerV1 = new wxBoxSizer(wxVERTICAL);
    itemDialog1->SetSizer(m_BoxSizerV1);

    m_Panel = new wxPanel( itemDialog1, ID_Panel, wxDefaultPosition, wxDefaultSize, wxNO_BORDER|wxTAB_TRAVERSAL );
    m_Panel->SetExtraStyle(wxWS_EX_VALIDATE_RECURSIVELY);
    m_BoxSizerV1->Add(m_Panel, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    m_BoxSizerV2 = new wxBoxSizer(wxVERTICAL);
    m_Panel->SetSizer(m_BoxSizerV2);

    m_StepsTxtCtrl = new wxTextCtrl( m_Panel, ID_StepsTxtCtrl, wxEmptyString, wxDefaultPosition, wxSize(600, 400), wxTE_MULTILINE|wxTE_READONLY|wxHSCROLL );
    m_StepsTxtCtrl->SetForegroundColour(wxColour(255, 255, 255));
    m_StepsTxtCtrl->SetBackgroundColour(wxColour(99, 134, 150));
    m_StepsTxtCtrl->SetFont(wxFont(12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Consolas")));
    m_BoxSizerV2->Add(m_StepsTxtCtrl, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

////@end Steps content construction
}


/*
 * Should we show tooltips?
 */

bool Steps::ShowToolTips()
{
    return true;
}

/*
 * Get bitmap resources
 */

wxBitmap Steps::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin Steps bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end Steps bitmap retrieval
}

/*
 * Get icon resources
 */

wxIcon Steps::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin Steps icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end Steps icon retrieval
}
