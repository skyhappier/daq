/////////////////////////////////////////////////////////////////////////////
// Name:        common_ch_control.h
// Purpose:     
// Author:      NDA
// Modified by: 
// Created:     04/04/2006 14:30:53
// RCS-ID:      
// Copyright:   CAEN S.p.A All rights reserved.
// Licence:     
/////////////////////////////////////////////////////////////////////////////

// Generated by DialogBlocks (unregistered), 04/04/2006 14:30:53

#ifndef _COMMON_CH_CONTROL_H_
#define _COMMON_CH_CONTROL_H_

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma interface "common_ch_control.h"
#endif

/*!
 * Includes
 */

////@begin includes
#include "wx/tglbtn.h"
#include "wx/spinbutt.h"
////@end includes

#include "generic_board.h"
#include "physical_board_channel.h"
#include "common_ch_control_base.h"

/*!
 * Forward declarations
 */

////@begin forward declarations
class wxToggleButton;
class wxSpinButton;
////@end forward declarations

/*!
 * Control identifiers
 */

////@begin control identifiers
#define ID_COMMON_CH_DIALOG 10030
#define SYMBOL_COMMONCHCONTROL_STYLE 0
#define SYMBOL_COMMONCHCONTROL_TITLE _("CommonChControl")
#define SYMBOL_COMMONCHCONTROL_IDNAME ID_COMMON_CH_DIALOG
#define SYMBOL_COMMONCHCONTROL_SIZE wxDefaultSize
#define SYMBOL_COMMONCHCONTROL_POSITION wxDefaultPosition
#define ID_ENABLE_TOGGLEBUTTON 10000
#define ID_BUTTON 10002
#define ID_SPINBUTTON 10003
////@end control identifiers

/*!
 * Compatibility
 */

#ifndef wxCLOSE_BOX
#define wxCLOSE_BOX 0x1000
#endif

/*!
 * CommonChControl class declaration
 */

class CommonChControl: public CommonChControlBase
{    
    DECLARE_DYNAMIC_CLASS( CommonChControl )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    CommonChControl( );
    CommonChControl( wxWindow* parent, bool show_dac= true, wxWindowID id = SYMBOL_COMMONCHCONTROL_IDNAME, const wxPoint& pos = SYMBOL_COMMONCHCONTROL_POSITION, const wxSize& size = SYMBOL_COMMONCHCONTROL_SIZE, long style = SYMBOL_COMMONCHCONTROL_STYLE );

    /// Creation
    bool Create( wxWindow* parent, wxWindowID id = SYMBOL_COMMONCHCONTROL_IDNAME, const wxPoint& pos = SYMBOL_COMMONCHCONTROL_POSITION, const wxSize& size = SYMBOL_COMMONCHCONTROL_SIZE, long style = SYMBOL_COMMONCHCONTROL_STYLE );

    /// Creates the controls and sizers
    void CreateControls();

////@begin CommonChControl event handler declarations

    /// wxEVT_COMMAND_CHECKBOX_CLICKED event handler for ID_ENABLE_TOGGLEBUTTON
    void OnEnableTogglebuttonClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON
    void OnButtonClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_SPINCTRL_UPDATED event handler for ID_SPINBUTTON
    void OnSpinbuttonUpdated( wxSpinEvent& event );

////@end CommonChControl event handler declarations

////@begin CommonChControl member function declarations

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end CommonChControl member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin CommonChControl member variables
    wxStaticBox* m_main_sizer_text;
    wxToggleButton* m_ch_enable_control;
    wxStaticBoxSizer* m_DAC_sizer;
    wxButton* m_ch_DAC_reset_control;
    wxSpinButton* m_ch_DAC_control;
    wxStaticText* m_medium_value_control;
    wxStaticText* m_overload_control;
////@end CommonChControl member variables

	bool SetupBoard( GenericBoard* p_board, int ch_index, int ch_count);
	bool UpdateControls( );
	void SetEnable( bool enable, bool disable_all);
	void SetMediumLabel( double value);
	void SetOverloadBackground( const wxColor& color);
private: 
	// Generic Board pointer
	GenericBoard* m_p_board;
	PhysicalBoardChannel* m_p_board_channel;
	int m_ch_index;
	int m_ch_count;
	void UpdateDAC( void);
protected:
	bool m_show_dac;

};

#endif
    // _COMMON_CH_CONTROL_H_
