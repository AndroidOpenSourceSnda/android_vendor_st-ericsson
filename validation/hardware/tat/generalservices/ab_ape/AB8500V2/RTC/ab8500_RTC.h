/****************************************************************************
 * File : c:/Lisp/Production/ab8500_V2/ab8500_RTC/Linux/ab8500_RTC.h
 * 
 *
 * Generated on the 20/04/2011 10:26 by the 'gen-I2C' code generator 
 *
 * Generator written in Common Lisp, created by  R�mi PRUD'HOMME - ST 
 * with the help of : Gr�gory GOSCINIACK - ST, Ir�n�e BROCHIER - Teamlog
 *
 ***************************************************************************
 *  Copyright STEricsson  2011
 *
 *  Reference document : UM0836 User manual, AB8500_V2 Mixed signal multimedia and power management Rev 1
 *
 ***************************************************************************/

// This file is generated. Don't modify it 

#ifndef C__LISP_PRODUCTION_AB8500_V2_AB8500_RTC_LINUX_AB8500_RTC_H
#define C__LISP_PRODUCTION_AB8500_V2_AB8500_RTC_LINUX_AB8500_RTC_H


#ifdef __cplusplus
extern "C" {
#endif
#include "ab8500_RTC_types.h"

unsigned char get_rtc_thermal_shutdown();
unsigned char get_long_pressure();
unsigned char get_low_battery();
unsigned char get_no_signal_c_lock32();
unsigned char get_wathgod_expired();
unsigned char get_battery_very_low();
unsigned char get_rtc_thermal_protection();
unsigned char get_switch_cmd_off();
unsigned char set_coulomb_counter_power_off( enum coulomb_counter_power_off_enable param );
unsigned char get_coulomb_counter_power_off();
unsigned char set_rtc_write_request( enum rtc_write_enable param );
unsigned char get_rtc_write_request();
unsigned char set_rtc_read_request( enum rtc_read_enable param );
unsigned char get_rtc_read_request();
unsigned char set_watch_time_sec_low( unsigned char param );
unsigned char get_watch_time_sec_low();
unsigned char set_watch_time_sec_high( unsigned char param );
unsigned char get_watch_time_sec_high();
unsigned char set_watch_time_min_low( unsigned char param );
unsigned char get_watch_time_min_low();
unsigned char set_watch_time_min_mid( unsigned char param );
unsigned char get_watch_time_min_mid();
unsigned char set_watch_time_min_high( unsigned char param );
unsigned char get_watch_time_min_high();
unsigned char set_alarm_min_low( unsigned char param );
unsigned char get_alarm_min_low();
unsigned char set_alarm_min_mid( unsigned char param );
unsigned char get_alarm_min_mid();
unsigned char set_alarm_min_high( unsigned char param );
unsigned char get_alarm_min_high();
unsigned char set_charge_backup_battery( enum charge_backup_battery_enable param );
unsigned char get_charge_backup_battery();
unsigned char set_backup_charger_enable( enum backup_charger_enable param );
unsigned char get_backup_charger_enable();
unsigned char set_backup_present_enable( enum backup_present_enable param );
unsigned char get_backup_present_enable();
unsigned char set_rtc_alarm_enable( enum rtc_alarm_enable param );
unsigned char get_rtc_alarm_enable();
unsigned char set_rtc_status_data( enum rtc_status_data param );
unsigned char get_rtc_status_data();
unsigned char set_backup_current_select( void );
unsigned char get_backup_current_select();
unsigned char set_backup_voltage_select( void );
unsigned char get_backup_voltage_select();
unsigned char set_backup_force( enum backup_force param );
unsigned char get_backup_force();
unsigned char set_rtc_derivation( unsigned char param );
unsigned char get_rtc_derivation();
unsigned char get_oscillator32k_status();
unsigned char get_clock32_status();


#ifdef __cplusplus
}
#endif

#endif
