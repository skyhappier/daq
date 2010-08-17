/////////////////////////////////////////////////////////////////////////////
// Name:        record_ch_control.cpp
// Purpose:     
// Author:      NDA
// Modified by: 
// Created:     03/10/2006 11:01:16
// RCS-ID:      
// Copyright:   CAEN S.p.A All rights reserved.
// Licence:     
/////////////////////////////////////////////////////////////////////////////

// Generated by DialogBlocks (unregistered), 03/10/2006 11:01:16

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma implementation "record_ch_control.h"
#endif

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

#include "record_ch_control.h"

////@begin XPM images
////@end XPM images

/*!
 * RecordChControl type definition
 */

IMPLEMENT_DYNAMIC_CLASS( RecordChControl, wxPanel )

/*!
 * RecordChControl event table definition
 */

BEGIN_EVENT_TABLE( RecordChControl, wxPanel )

////@begin RecordChControl event table entries
    EVT_TOGGLEBUTTON( ID_TOGGLEBUTTON, RecordChControl::OnTogglebuttonClick )

    EVT_SPINCTRL( ID_RATE_DIVIDER_SPINCTRL, RecordChControl::OnRateDividerSpinctrlUpdated )

    EVT_CHOICE( ID_FORMAT_CHOICE, RecordChControl::OnFormatChoiceSelected )

////@end RecordChControl event table entries
    EVT_TEXT_ENTER( ID_RATE_DIVIDER_SPINCTRL, RecordChControl::OnRateDividerSpinctrlTextUpdated )

END_EVENT_TABLE()

/*!
 * RecordChControl constructors
 */

RecordChControl::RecordChControl( )
{
}

RecordChControl::RecordChControl( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style )
{
    Create(parent, id, pos, size, style);
}

/*!
 * RecordChControl creator
 */

bool RecordChControl::Create( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style )
{
////@begin RecordChControl member initialisation
    m_main_sizer_text = NULL;
    m_ch_enable_control = NULL;
    m_ch_rate_divider_control = NULL;
    m_format_control = NULL;
////@end RecordChControl member initialisation

////@begin RecordChControl creation
    wxPanel::Create( parent, id, pos, size, style );

    CreateControls();
    if (GetSizer())
    {
        GetSizer()->SetSizeHints(this);
    }
    Centre();
////@end RecordChControl creation
    return true;
}

/*!
 * Control creation for RecordChControl
 */

void RecordChControl::CreateControls()
{    
////@begin RecordChControl content construction
    // Generated by DialogBlocks, 10/10/2006 11:44:52 (unregistered)

    RecordChControl* itemPanel1 = this;

    this->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, _T("Verdana")));
    m_main_sizer_text = new wxStaticBox(itemPanel1, wxID_ANY, _("???"));
    wxStaticBoxSizer* itemStaticBoxSizer2 = new wxStaticBoxSizer(m_main_sizer_text, wxVERTICAL);
    itemPanel1->SetSizer(itemStaticBoxSizer2);

    m_ch_enable_control = new wxToggleButton( itemPanel1, ID_TOGGLEBUTTON, _("???"), wxDefaultPosition, wxSize(75, -1), 0 );
    m_ch_enable_control->SetValue(true);
    m_ch_enable_control->SetHelpText(_("Enable/Disable channel record"));
    if (ShowToolTips())
        m_ch_enable_control->SetToolTip(_("Enable/Disable channel  record"));
    m_ch_enable_control->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxBOLD, false, _T("Verdana")));
    itemStaticBoxSizer2->Add(m_ch_enable_control, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 0);

    m_ch_rate_divider_control = new wxSpinCtrl( itemPanel1, ID_RATE_DIVIDER_SPINCTRL, _T("1"), wxDefaultPosition, wxSize(75, -1), wxSP_ARROW_KEYS, 1, 99999, 1 );
    m_ch_rate_divider_control->SetHelpText(_("Set sample rate divider"));
    if (ShowToolTips())
        m_ch_rate_divider_control->SetToolTip(_("Set sample rate divider"));
    itemStaticBoxSizer2->Add(m_ch_rate_divider_control, 0, wxALIGN_CENTER_HORIZONTAL|wxTOP, 3);

    wxString* m_format_controlStrings = NULL;
    m_format_control = new wxChoice( itemPanel1, ID_FORMAT_CHOICE, wxDefaultPosition, wxSize(80, -1), 0, m_format_controlStrings, 0 );
    m_format_control->SetStringSelection(_("HEX"));
    m_format_control->SetHelpText(_("Select output file format"));
    if (ShowToolTips())
        m_format_control->SetToolTip(_("Select output file format"));
    itemStaticBoxSizer2->Add(m_format_control, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

////@end RecordChControl content construction

	this->m_format_control->Append( _("HEX"));
	this->m_format_control->Append( _("ASCII DEC"));
	this->m_format_control->Append( _("ASCII HEX"));

}

/*!
 * wxEVT_COMMAND_CHECKBOX_CLICKED event handler for ID_TOGGLEBUTTON
 */

void RecordChControl::OnTogglebuttonClick( wxCommandEvent& /*event*/ )
{
	this->m_p_board_channel->m_record_enabled= this->m_ch_enable_control->GetValue( )!= 0;
	this->m_ch_enable_control->SetLabel( this->m_p_board_channel->m_record_enabled? _("Disable"): _("Enable"));
}

/*!
 * wxEVT_COMMAND_SPINCTRL_UPDATED event handler for ID_RATE_DIVIDER_SPINCTRL
 */

void RecordChControl::OnRateDividerSpinctrlUpdated( wxSpinEvent& event)
{
	this->UpdateRateDivider( event.GetPosition());
}

/*!
 * wxEVT_COMMAND_TEXT_UPDATED event handler for ID_RATE_DIVIDER_SPINCTRL
 */

void RecordChControl::OnRateDividerSpinctrlTextUpdated( wxCommandEvent& /*event*/)
{
  int value= atoi( this->m_ch_rate_divider_control->GetLabel().ToAscii());
	this->UpdateRateDivider( value);
}

/*!
 * Should we show tooltips?
 */

bool RecordChControl::ShowToolTips()
{
    return true;
}

/*!
 * Get bitmap resources
 */

wxBitmap RecordChControl::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin RecordChControl bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end RecordChControl bitmap retrieval
}

/*!
 * Get icon resources
 */

wxIcon RecordChControl::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin RecordChControl icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end RecordChControl icon retrieval
}

bool RecordChControl::SetupBoard( GenericBoard* p_board, int ch_index, int ch_count, bool is_virtual)
{
	this->m_is_virtual= is_virtual;
	this->m_p_board= p_board;
	this->m_ch_index= ch_index;
	this->m_ch_count= ch_count;
	if( this->m_is_virtual)
	{
		if( ( size_t)this->m_ch_index>= this->m_p_board->m_virtual_channel_array.GetCount())
			return false;
		this->m_p_board_channel= (GenericBoardChannel*)this->m_p_board->m_virtual_channel_array[ this->m_ch_index];
	}
	else
	{
		if( ( size_t)this->m_ch_index>= this->m_p_board->m_channel_array.GetCount())
			return false;
		this->m_p_board_channel= (GenericBoardChannel*)this->m_p_board->m_channel_array[ this->m_ch_index];
	}
	this->m_p_board_channel->m_p_record_ch_control= this;
	
	if( !this->UpdateControls())
		return false;
	return true;
}
bool RecordChControl::UpdateControls( void)
{
	if( this->m_is_virtual)
	{
	  this->m_main_sizer_text->SetLabel( wxString::Format(_("VIRT %d"), this->m_ch_count));
	}
	else
	{
	  this->m_main_sizer_text->SetLabel( wxString::Format(_("%d"), this->m_ch_count));
	}
	this->m_ch_rate_divider_control->SetValue( this->m_p_board_channel->m_record_rate_divider);
	this->m_ch_enable_control->SetValue( this->m_p_board_channel->m_record_enabled);
	this->m_ch_enable_control->SetLabel( this->m_ch_enable_control->GetValue( )? _("Disable"): _("Enable"));
	this->m_format_control->SetSelection( this->m_p_board_channel->m_record_format_type);

	return true;
}
void RecordChControl::UpdateRateDivider( int value)
{
	this->m_p_board_channel->m_record_rate_divider= value;
}
/*!
 * wxEVT_COMMAND_CHOICE_SELECTED event handler for ID_FORMAT_CHOICE
 */

void RecordChControl::OnFormatChoiceSelected( wxCommandEvent& /*event*/ )
{
	this->m_p_board_channel->m_record_format_type= ( GenericBoardChannel::RECORD_FORMAT_TYPE)this->m_format_control->GetSelection();
}

void RecordChControl::SetEnable( bool enable)
{
    this->m_main_sizer_text->Enable( enable);
    this->m_ch_enable_control->Enable( enable);
    this->m_ch_rate_divider_control->Enable( enable);
    this->m_format_control->Enable( enable);
}
