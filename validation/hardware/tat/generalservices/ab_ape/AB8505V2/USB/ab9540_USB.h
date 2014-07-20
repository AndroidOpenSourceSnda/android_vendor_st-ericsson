/****************************************************************************
 * File : c:/Lisp/Production/ab9540/ab9540_USB/Linux/ab9540_USB.h
 * 
 *
 * Generated on the 13/01/2012 09:19 by the 'super-cool' code generator 
 *
 * Generator written in Common Lisp, created by  Remi PRUD'HOMME - STEricsson 
 * with the help of : 
 *
 ***************************************************************************
 *  Copyright STEricsson  2012
 *
 *  Reference document : User Manual ref : CD00291561 Rev 3, May 2011
 *
 ***************************************************************************/

// This file is generated. Don't modify it 

#ifndef C__LISP_PRODUCTION_AB9540_AB9540_USB_LINUX_AB9540_USB_H
#define C__LISP_PRODUCTION_AB9540_AB9540_USB_LINUX_AB9540_USB_H


#ifdef __cplusplus
extern "C" {
#endif
#include "ab9540_USB_types.h"

unsigned char set_charger_pull_up( enum id_detection_thru_adc_enable param );
unsigned char get_charger_pull_up();
unsigned char set_usb_switch_ctrl( enum usb_switch param );
unsigned char get_usb_switch_ctrl();
unsigned char set_phy_reset( enum reset_active_low param );
unsigned char get_phy_reset();
unsigned char set_dp_pull_up( enum dp_pull_up_enable param );
unsigned char get_dp_pull_up();
unsigned char set_dm_pull_down( enum dm_pull_down_enable param );
unsigned char get_dm_pull_down();
unsigned char set_dp_pull_down( enum dp_pull_down_enable param );
unsigned char get_dp_pull_down();
unsigned char set_dm_pull_up( enum dm_pull_up_enable param );
unsigned char get_dm_pull_up();
unsigned char set_device_detection( enum detection param );
unsigned char get_device_detection();
unsigned char set_id_host_detection( enum detection param );
unsigned char get_id_host_detection();
unsigned char set_vbus_valid( enum valid_compatrator_enable param );
unsigned char get_vbus_valid();
unsigned char set_usb_host_mode( enum usb_host_mode_enable param );
unsigned char get_usb_host_mode();
unsigned char set_usb_device_mode( enum usb_device_mode_enable param );
unsigned char get_usb_device_mode();
unsigned char get_usb_link_status();
unsigned char set_id_wakeup( enum resitance param );
unsigned char get_id_wakeup();
unsigned char set_id_det_r1( enum id_resitance param );
unsigned char get_id_det_r1();
unsigned char set_id_det_r2( enum id_resitance param );
unsigned char get_id_det_r2();
unsigned char set_id_det_r3( enum id_resitance param );
unsigned char get_id_det_r3();
unsigned char set_id_det_r4( enum id_resitance param );
unsigned char get_id_det_r4();
unsigned char set_drive_vbus( enum vbus_generation_enable param );
unsigned char get_drive_vbus();
unsigned char get_dplus_cmp_out();
unsigned char get_dminus_cmp_out();
unsigned char get_host_charger_detected();
unsigned char get_charger_type();
unsigned char get_uart_mode();
unsigned char set_usb_charger_detection( enum usb_charger_detection_enable param );
unsigned char get_usb_charger_detection();
unsigned char set_gate_sys_ulp_clock( enum gate_ulp_clock param );
unsigned char get_gate_sys_ulp_clock();
unsigned char set_uart_low_power_mode( enum uart_low_power_mode_enable param );
unsigned char get_uart_low_power_mode();
unsigned char set_charger_mux_ctrl( enum charger_mux_ctrl param );
unsigned char get_charger_mux_ctrl();
unsigned char set_dm_pull_down_disable( enum dm_pull param );
unsigned char get_dm_pull_down_disable();
unsigned char set_idat_sink( enum idat_sink_enable param );
unsigned char get_idat_sink();
unsigned char set_vdat_source( enum vdat_source_enable param );
unsigned char get_vdat_source();
unsigned char set_sdp_src_switch( enum sdp_src_switch_opened param );
unsigned char get_sdp_src_switch();
unsigned char set_sdm_src_switch( enum sdm_src_switch_opened param );
unsigned char get_sdm_src_switch();
unsigned char set_sdp_snk_switch( enum sdp_snk_switch_opened param );
unsigned char get_sdp_snk_switch();
unsigned char set_sdm_snk_switch( enum sdm_snk_switch_opened param );
unsigned char get_sdm_snk_switch();
unsigned char set_data_connect_source( enum data_connect_source_enable param );
unsigned char get_data_connect_source();
unsigned char set_data_connect_detection( enum data_connect_detection_enable param );
unsigned char get_data_connect_detection();
unsigned char set_adp_probe_time( unsigned char param );
unsigned char get_adp_probe_time();
unsigned char set_adp( enum adp_enabled param );
unsigned char get_adp();
unsigned char get_suspend_mode();
unsigned char get_chirp_mode();
unsigned char get_high_speed_mode();
unsigned char set_usb_adp_probe_time_current( unsigned char param );
unsigned char get_usb_adp_probe_time_current();


#ifdef __cplusplus
}
#endif

#endif
