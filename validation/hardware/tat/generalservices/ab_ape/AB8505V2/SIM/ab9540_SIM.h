/****************************************************************************
 * File : c:/Lisp/Production/ab9540/ab9540_SIM/Linux/ab9540_SIM.h
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

#ifndef C__LISP_PRODUCTION_AB9540_AB9540_SIM_LINUX_AB9540_SIM_H
#define C__LISP_PRODUCTION_AB9540_AB9540_SIM_LINUX_AB9540_SIM_H


#ifdef __cplusplus
extern "C" {
#endif
#include "ab9540_SIM_types.h"

unsigned char set_latch_card_detected( unsigned char param );
unsigned char get_latch_card_detected();
unsigned char set_latch_atr_error( unsigned char param );
unsigned char get_latch_atr_error();
unsigned char set_latch_tx_error( unsigned char param );
unsigned char get_latch_tx_error();
unsigned char set_select_vsim_power( enum select_vsim_power param );
unsigned char get_select_vsim_power();
unsigned char set_sim_card_det_polarity( enum switch_open param );
unsigned char get_sim_card_det_polarity();
unsigned char set_usim_power( enum usim_power_on param );
unsigned char get_usim_power();
unsigned char set_usim_load( enum usim_load param );
unsigned char get_usim_load();
unsigned char set_sim_reset_control( enum sim_reset_control param );
unsigned char get_sim_reset_control();
unsigned char set_usim_by_pass( enum usim_by_pass param );
unsigned char get_usim_by_pass();
unsigned char set_sim_reset_value( enum sim_reset_value param );
unsigned char get_sim_reset_value();
unsigned char set_weak_pull_down( enum weak_pull_down param );
unsigned char get_weak_pull_down();
unsigned char set_counter_reset( enum counter_reset param );
unsigned char get_counter_reset();
unsigned char set_card_clock_selected( enum card_clock_selected param );
unsigned char get_card_clock_selected();
unsigned char set_clock32_selected( enum clock32_selected param );
unsigned char get_clock32_selected();
unsigned char set_sim_power_on( enum sim_power_on param );
unsigned char get_sim_power_on();
unsigned char set_internally_reset( enum internally_reset param );
unsigned char get_internally_reset();
unsigned char set_warm_reset( enum warm_reset_enable param );
unsigned char get_warm_reset();
unsigned char set_reset_duration( enum reset_duration param );
unsigned char get_reset_duration();
unsigned char set_power_down_procedure( enum powe_down_procedure_enable param );
unsigned char get_power_down_procedure();
unsigned char set_mask_card_detected( unsigned char param );
unsigned char get_mask_card_detected();
unsigned char set_mask_atr_error( unsigned char param );
unsigned char get_mask_atr_error();
unsigned char set_mask_tx_error( unsigned char param );
unsigned char get_mask_tx_error();
unsigned char set_v_mod_select( enum v_mod_select param );
unsigned char get_v_mod_select();
unsigned char set_sim_delay( enum sim_delay param );
unsigned char get_sim_delay();
unsigned char set_filter_active( enum filter_enable param );
unsigned char get_filter_active();
unsigned char set_intr_card_detected( unsigned char param );
unsigned char get_intr_card_detected();
unsigned char set_intr_atr_error( unsigned char param );
unsigned char get_intr_atr_error();
unsigned char set_intr_tx_error( unsigned char param );
unsigned char get_intr_tx_error();
unsigned char set_sim_io_normal( enum sim_io_normal param );
unsigned char get_sim_io_normal();
unsigned char set_vsim_voltage( enum vsim_voltage param );
unsigned char get_vsim_voltage();
unsigned char set_vsim_regulator( enum vsim_regulator param );
unsigned char get_vsim_regulator();
unsigned char set_removal_detection( enum removal_detection param );
unsigned char get_removal_detection();
unsigned char set_sim_comp_detection( enum comparator_enabled param );
unsigned char get_sim_comp_detection();
unsigned char set_sim_da_pull_up( enum sim_da_pull_up param );
unsigned char get_sim_da_pull_up();
unsigned char set_vsim_active_mode( enum vsim_active_mode param );
unsigned char get_vsim_active_mode();
unsigned char set_vmod_output_voltage( enum vmod_output_voltage param );
unsigned char get_vmod_output_voltage();


#ifdef __cplusplus
}
#endif

#endif
