/****************************************************************************
 * File : c:/Lisp/Production/ab8500/ab8500_Latch/Linux/ab8500_Latch.c
 * 
 *
 * Generated on the 25/05/2011 17:59 by the 'gen-I2C' code generator 
 *
 * Generator written in Common Lisp, created by  R�mi PRUD'HOMME - ST 
 * with the help of : Gr�gory GOSCINIACK - ST, Ir�n�e BROCHIER - Teamlog
 *
 ***************************************************************************
 *  Copyright STEricsson  2011
 *
 *  Reference document : STw4500 Registers Specification Rev 2.61 5 January 2011
 *
 ***************************************************************************/
#include "ab8500_Latch.h"

extern unsigned char I2CRead( unsigned short register_address);
extern void I2CWrite( unsigned short register_address, unsigned char data );


/***************************************************************************
 *
 * Function : get_latched_interrupt1
 *
 * RET  : Return the value of register LatchedInterrupt1
 *
 * Notes : From register 0x0E20, bits 7:0
 *
 **************************************************************************/
unsigned char get_latched_interrupt1()
  {
    unsigned char value;


    /* 
     * IntSource1 Status (cleared once reading) 
     */ 
   value = I2CRead(LATCHED_INTERRUPT_1_REG) ;
    return value;
  }


/***************************************************************************
 *
 * Function : get_main_charger_allowed_latched_interrupt
 *
 * RET  : Return the value of register LatchedInterrupt1
 *
 * Notes : From register 0x0E20, bits 0:0
 *
 **************************************************************************/
unsigned char get_main_charger_allowed_latched_interrupt()
  {
    unsigned char value;


    /* 
     * Main charger connected is not an allowed one 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_1_REG) & MAIN_CHARGER_ALLOWED_LATCHED_INTERRUPT_PARAM_MASK);
    return value;
  }


/***************************************************************************
 *
 * Function : get_un_plug_tv_latched_interrupt
 *
 * RET  : Return the value of register LatchedInterrupt1
 *
 * Notes : From register 0x0E20, bits 1:1
 *
 **************************************************************************/
unsigned char get_un_plug_tv_latched_interrupt()
  {
    unsigned char value;


    /* 
     * Tvset (75 Ohms) disconnection on CVBS ball detected 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_1_REG) & UN_PLUG_TV_LATCHED_INTERRUPT_PARAM_MASK) >> 1;
    return value;
  }


/***************************************************************************
 *
 * Function : get_plug_tv_latched_interrupt
 *
 * RET  : Return the value of register LatchedInterrupt1
 *
 * Notes : From register 0x0E20, bits 2:2
 *
 **************************************************************************/
unsigned char get_plug_tv_latched_interrupt()
  {
    unsigned char value;


    /* 
     * Tvset (75 Ohms) connection on CVBS ball detected 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_1_REG) & PLUG_TV_LATCHED_INTERRUPT_PARAM_MASK) >> 2;
    return value;
  }


/***************************************************************************
 *
 * Function : get_thermal_warning_latched_interrupt
 *
 * RET  : Return the value of register LatchedInterrupt1
 *
 * Notes : From register 0x0E20, bits 3:3
 *
 **************************************************************************/
unsigned char get_thermal_warning_latched_interrupt()
  {
    unsigned char value;


    /* 
     * Thermal warning 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_1_REG) & THERMAL_WARNING_LATCHED_INTERRUPT_PARAM_MASK) >> 3;
    return value;
  }


/***************************************************************************
 *
 * Function : get_falling_pon_key2_latched_interrupt
 *
 * RET  : Return the value of register LatchedInterrupt1
 *
 * Notes : From register 0x0E20, bits 4:4
 *
 **************************************************************************/
unsigned char get_falling_pon_key2_latched_interrupt()
  {
    unsigned char value;


    /* 
     * Falling edge on PonKey2 ball detected 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_1_REG) & FALLING_PON_KEY_2_LATCHED_INTERRUPT_PARAM_MASK) >> 4;
    return value;
  }


/***************************************************************************
 *
 * Function : get_rising_pon_key2_latched_interrupt
 *
 * RET  : Return the value of register LatchedInterrupt1
 *
 * Notes : From register 0x0E20, bits 5:5
 *
 **************************************************************************/
unsigned char get_rising_pon_key2_latched_interrupt()
  {
    unsigned char value;


    /* 
     * Rising edge on PonKey2 ball detected 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_1_REG) & RISING_PON_KEY_2_LATCHED_INTERRUPT_PARAM_MASK) >> 5;
    return value;
  }


/***************************************************************************
 *
 * Function : get_falling_pon_key1_latched_interrupt
 *
 * RET  : Return the value of register LatchedInterrupt1
 *
 * Notes : From register 0x0E20, bits 6:6
 *
 **************************************************************************/
unsigned char get_falling_pon_key1_latched_interrupt()
  {
    unsigned char value;


    /* 
     * Falling edge on PonKey1 ball detected 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_1_REG) & FALLING_PON_KEY_1_LATCHED_INTERRUPT_PARAM_MASK) >> 6;
    return value;
  }


/***************************************************************************
 *
 * Function : get_rising_pon_key1_latched_interrupt
 *
 * RET  : Return the value of register LatchedInterrupt1
 *
 * Notes : From register 0x0E20, bits 7:7
 *
 **************************************************************************/
unsigned char get_rising_pon_key1_latched_interrupt()
  {
    unsigned char value;


    /* 
     * Rising edge on PonKey1 ball detected 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_1_REG) & RISING_PON_KEY_1_LATCHED_INTERRUPT_PARAM_MASK) >> 7;
    return value;
  }


/***************************************************************************
 *
 * Function : get_latched_interrupt2
 *
 * RET  : Return the value of register LatchedInterrupt2
 *
 * Notes : From register 0x0E21, bits 7:0
 *
 **************************************************************************/
unsigned char get_latched_interrupt2()
  {
    unsigned char value;


    /* 
     * IntSource2 Status (cleared once reading) 
     */ 
   value = I2CRead(LATCHED_INTERRUPT_2_REG) ;
    return value;
  }


/***************************************************************************
 *
 * Function : get_battery_over_voltage_latch
 *
 * RET  : Return the value of register LatchedInterrupt2
 *
 * Notes : From register 0x0E21, bits 0:0
 *
 **************************************************************************/
unsigned char get_battery_over_voltage_latch()
  {
    unsigned char value;


    /* 
     * TVbatA ball goes upper over voltage threshold (charge 
     * stopped) 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_2_REG) & BATTERY_OVER_VOLTAGE_LATCH_PARAM_MASK);
    return value;
  }


/***************************************************************************
 *
 * Function : get_main_charger_un_plug_latch
 *
 * RET  : Return the value of register LatchedInterrupt2
 *
 * Notes : From register 0x0E21, bits 2:2
 *
 **************************************************************************/
unsigned char get_main_charger_un_plug_latch()
  {
    unsigned char value;


    /* 
     * Main charger unplug detected 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_2_REG) & MAIN_CHARGER_UN_PLUG_LATCH_PARAM_MASK) >> 2;
    return value;
  }


/***************************************************************************
 *
 * Function : get_main_charger_plug_latch
 *
 * RET  : Return the value of register LatchedInterrupt2
 *
 * Notes : From register 0x0E21, bits 3:3
 *
 **************************************************************************/
unsigned char get_main_charger_plug_latch()
  {
    unsigned char value;


    /* 
     * Main charger plug detected 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_2_REG) & MAIN_CHARGER_PLUG_LATCH_PARAM_MASK) >> 3;
    return value;
  }


/***************************************************************************
 *
 * Function : get_vbus_falling_edge_latch
 *
 * RET  : Return the value of register LatchedInterrupt2
 *
 * Notes : From register 0x0E21, bits 6:6
 *
 **************************************************************************/
unsigned char get_vbus_falling_edge_latch()
  {
    unsigned char value;


    /* 
     * Falling edge on Vbus ball detected 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_2_REG) & VBUS_FALLING_EDGE_LATCH_PARAM_MASK) >> 6;
    return value;
  }


/***************************************************************************
 *
 * Function : get_vbus_rising_edge_latch
 *
 * RET  : Return the value of register LatchedInterrupt2
 *
 * Notes : From register 0x0E21, bits 7:7
 *
 **************************************************************************/
unsigned char get_vbus_rising_edge_latch()
  {
    unsigned char value;


    /* 
     * Rising edge on Vbus ball detected 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_2_REG) & VBUS_RISING_EDGE_LATCH_PARAM_MASK) >> 7;
    return value;
  }


/***************************************************************************
 *
 * Function : get_latched_interrupt3
 *
 * RET  : Return the value of register LatchedInterrupt3
 *
 * Notes : From register 0x0E22, bits 7:0
 *
 **************************************************************************/
unsigned char get_latched_interrupt3()
  {
    unsigned char value;


    /* 
     * IntSource3 Status (cleared once reading) 
     */ 
   value = I2CRead(LATCHED_INTERRUPT_3_REG) ;
    return value;
  }


/***************************************************************************
 *
 * Function : get_usb_charger_dropout_latch
 *
 * RET  : Return the value of register LatchedInterrupt3
 *
 * Notes : From register 0x0E22, bits 0:0
 *
 **************************************************************************/
unsigned char get_usb_charger_dropout_latch()
  {
    unsigned char value;


    /* 
     * Usb charger was in dropout and internal input current 
     * loop update current regulation to avoid usb charger to 
     * drop 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_3_REG) & USB_DROP_OUT_LATCH_PARAM_MASK);
    return value;
  }


/***************************************************************************
 *
 * Function : get_rtc60s_latch
 *
 * RET  : Return the value of register LatchedInterrupt3
 *
 * Notes : From register 0x0E22, bits 1:1
 *
 **************************************************************************/
unsigned char get_rtc60s_latch()
  {
    unsigned char value;


    /* 
     * RTC timer reaches a 60s period 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_3_REG) & PERIOD_6_0S_LATCH_PARAM_MASK) >> 1;
    return value;
  }


/***************************************************************************
 *
 * Function : get_rtc_alarm_latch
 *
 * RET  : Return the value of register LatchedInterrupt3
 *
 * Notes : From register 0x0E22, bits 2:2
 *
 **************************************************************************/
unsigned char get_rtc_alarm_latch()
  {
    unsigned char value;


    /* 
     * RTC timer reaches alarm time 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_3_REG) & REACH_ALARM_TIME_LATCH_PARAM_MASK) >> 2;
    return value;
  }


/***************************************************************************
 *
 * Function : get_battery_removal_latch
 *
 * RET  : Return the value of register LatchedInterrupt3
 *
 * Notes : From register 0x0E22, bits 4:4
 *
 **************************************************************************/
unsigned char get_battery_removal_latch()
  {
    unsigned char value;


    /* 
     * Battery removal 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_3_REG) & BATTERY_REMOVAL_LATCH_PARAM_MASK) >> 4;
    return value;
  }


/***************************************************************************
 *
 * Function : get_watchdog_charger_expiration_latch
 *
 * RET  : Return the value of register LatchedInterrupt3
 *
 * Notes : From register 0x0E22, bits 5:5
 *
 **************************************************************************/
unsigned char get_watchdog_charger_expiration_latch()
  {
    unsigned char value;


    /* 
     * Watchdog charger expiration detected 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_3_REG) & WATCHDOG_CHARGER_EXPIRATION_LATCH_PARAM_MASK) >> 5;
    return value;
  }


/***************************************************************************
 *
 * Function : get_overvoltage_on_vbus_latch
 *
 * RET  : Return the value of register LatchedInterrupt3
 *
 * Notes : From register 0x0E22, bits 6:6
 *
 **************************************************************************/
unsigned char get_overvoltage_on_vbus_latch()
  {
    unsigned char value;


    /* 
     * Overvoltage on Vbus ball detected 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_3_REG) & OVERVOLTAGE_ON_VBUS_LATCH_PARAM_MASK) >> 6;
    return value;
  }


/***************************************************************************
 *
 * Function : get_main_charger_over_current_latch
 *
 * RET  : Return the value of register LatchedInterrupt3
 *
 * Notes : From register 0x0E22, bits 7:7
 *
 **************************************************************************/
unsigned char get_main_charger_over_current_latch()
  {
    unsigned char value;


    /* 
     * Icharge > Icharge max programmed detected 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_3_REG) & MAIN_CHARGER_OVER_CURRENT_LATCH_PARAM_MASK) >> 7;
    return value;
  }


/***************************************************************************
 *
 * Function : get_latched_interrupt4
 *
 * RET  : Return the value of register LatchedInterrupt4
 *
 * Notes : From register 0x0E23, bits 7:0
 *
 **************************************************************************/
unsigned char get_latched_interrupt4()
  {
    unsigned char value;


    /* 
     * IntSource4 Status (cleared once reading) 
     */ 
   value = I2CRead(LATCHED_INTERRUPT_4_REG) ;
    return value;
  }


/***************************************************************************
 *
 * Function : get_accumulation_conversion_latch
 *
 * RET  : Return the value of register LatchedInterrupt4
 *
 * Notes : From register 0x0E23, bits 0:0
 *
 **************************************************************************/
unsigned char get_accumulation_conversion_latch()
  {
    unsigned char value;


    /* 
     * Accumulation of N sample conversion is detected 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_4_REG) & ACCUMULATION_CONVERSION_LATCH_PARAM_MASK);
    return value;
  }


/***************************************************************************
 *
 * Function : get_audio_latch
 *
 * RET  : Return the value of register LatchedInterrupt4
 *
 * Notes : From register 0x0E23, bits 1:1
 *
 **************************************************************************/
unsigned char get_audio_latch()
  {
    unsigned char value;


    /* 
     * Audio interrupt form audio digital part detected 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_4_REG) & AUDIO_LATCH_PARAM_MASK) >> 1;
    return value;
  }


/***************************************************************************
 *
 * Function : get_coulomb_ended_latch
 *
 * RET  : Return the value of register LatchedInterrupt4
 *
 * Notes : From register 0x0E23, bits 2:2
 *
 **************************************************************************/
unsigned char get_coulomb_ended_latch()
  {
    unsigned char value;


    /* 
     * Coulomb Counter has ended data convertion 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_4_REG) & COULOMB_COUNTER_ENDED_LATCH_PARAM_MASK) >> 2;
    return value;
  }


/***************************************************************************
 *
 * Function : get_coulomb_calibration_endedd_latch
 *
 * RET  : Return the value of register LatchedInterrupt4
 *
 * Notes : From register 0x0E23, bits 3:3
 *
 **************************************************************************/
unsigned char get_coulomb_calibration_endedd_latch()
  {
    unsigned char value;


    /* 
     * Coulomb Counter has ended its calibration 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_4_REG) & COULOMB_CALIBRATION_ENDEDD_LATCH_PARAM_MASK) >> 3;
    return value;
  }


/***************************************************************************
 *
 * Function : get_low_battery_latch
 *
 * RET  : Return the value of register LatchedInterrupt4
 *
 * Notes : From register 0x0E23, bits 4:4
 *
 **************************************************************************/
unsigned char get_low_battery_latch()
  {
    unsigned char value;


    /* 
     * VbatA voltage goes below LowBat register programmed 
     * threshold 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_4_REG) & LOW_BATTERY_LATCH_PARAM_MASK) >> 4;
    return value;
  }


/***************************************************************************
 *
 * Function : get_high_battery_latch
 *
 * RET  : Return the value of register LatchedInterrupt4
 *
 * Notes : From register 0x0E23, bits 5:5
 *
 **************************************************************************/
unsigned char get_high_battery_latch()
  {
    unsigned char value;


    /* 
     * VbatA voltage goes above LowBat register programmed 
     * threshold 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_4_REG) & HIGH_BATTERY_LATCH_PARAM_MASK) >> 5;
    return value;
  }


/***************************************************************************
 *
 * Function : get_rtc_battery_low_latch
 *
 * RET  : Return the value of register LatchedInterrupt4
 *
 * Notes : From register 0x0E23, bits 6:6
 *
 **************************************************************************/
unsigned char get_rtc_battery_low_latch()
  {
    unsigned char value;


    /* 
     * BackUpBat ball voltage goes below RtcBackupChg register 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_4_REG) & RTC_BATTERY_LOW_LATCH_PARAM_MASK) >> 6;
    return value;
  }


/***************************************************************************
 *
 * Function : get_rtc_battery_high_latch
 *
 * RET  : Return the value of register LatchedInterrupt4
 *
 * Notes : From register 0x0E23, bits 7:7
 *
 **************************************************************************/
unsigned char get_rtc_battery_high_latch()
  {
    unsigned char value;


    /* 
     * BackUpBat ball voltage goes above RtcBackupChg register 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_4_REG) & RTC_BATTERY_HIGH_LATCH_PARAM_MASK) >> 7;
    return value;
  }


/***************************************************************************
 *
 * Function : get_latched_interrupt5
 *
 * RET  : Return the value of register LatchedInterrupt5
 *
 * Notes : From register 0x0E24, bits 7:0
 *
 **************************************************************************/
unsigned char get_latched_interrupt5()
  {
    unsigned char value;


    /* 
     * IntSource5 Status 
     */ 
   value = I2CRead(LATCHED_INTERRUPT_5_REG) ;
    return value;
  }


/***************************************************************************
 *
 * Function : get_adc_software_control_latch
 *
 * RET  : Return the value of register LatchedInterrupt5
 *
 * Notes : From register 0x0E24, bits 0:0
 *
 **************************************************************************/
unsigned char get_adc_software_control_latch()
  {
    unsigned char value;


    /* 
     * GP ADC conversion requested thru software control is 
     * ended (data are available) 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_5_REG) & ADC_SOFTWARE_CONTROL_PARAM_MASK);
    return value;
  }


/***************************************************************************
 *
 * Function : get_accessory1_low_voltage_latch
 *
 * RET  : Return the value of register LatchedInterrupt5
 *
 * Notes : From register 0x0E24, bits 1:1
 *
 **************************************************************************/
unsigned char get_accessory1_low_voltage_latch()
  {
    unsigned char value;


    /* 
     * AccDetect1 ball voltage level goes below AccDetect1Th 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_5_REG) & ACCESSORY_1_LOW_VOLTAGE_LATCH_PARAM_MASK) >> 1;
    return value;
  }


/***************************************************************************
 *
 * Function : get_accessory1_high_voltage_latch
 *
 * RET  : Return the value of register LatchedInterrupt5
 *
 * Notes : From register 0x0E24, bits 2:2
 *
 **************************************************************************/
unsigned char get_accessory1_high_voltage_latch()
  {
    unsigned char value;


    /* 
     * AccDetect1 ball voltage level goes above AccDetect1Th 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_5_REG) & ACCESSORY_1_HIGH_VOLTAGE_PARAM_MASK) >> 2;
    return value;
  }


/***************************************************************************
 *
 * Function : get_accessory22_low_voltage_latch
 *
 * RET  : Return the value of register LatchedInterrupt5
 *
 * Notes : From register 0x0E24, bits 3:3
 *
 **************************************************************************/
unsigned char get_accessory22_low_voltage_latch()
  {
    unsigned char value;


    /* 
     * AccDetect2 ball voltage level goes below AccDetect22Th 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_5_REG) & ACCESSORY_22_LOW_VOLTAGE_PARAM_MASK) >> 3;
    return value;
  }


/***************************************************************************
 *
 * Function : get_accessory22_high_voltage_latch
 *
 * RET  : Return the value of register LatchedInterrupt5
 *
 * Notes : From register 0x0E24, bits 4:4
 *
 **************************************************************************/
unsigned char get_accessory22_high_voltage_latch()
  {
    unsigned char value;


    /* 
     * AccDetect2 ball voltage level goes above AccDetect22Th 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_5_REG) & ACCESSORY_22_HIGH_VOLTAGE_LATCH_PARAM_MASK) >> 4;
    return value;
  }


/***************************************************************************
 *
 * Function : get_accessory21_low_voltage_latch
 *
 * RET  : Return the value of register LatchedInterrupt5
 *
 * Notes : From register 0x0E24, bits 5:5
 *
 **************************************************************************/
unsigned char get_accessory21_low_voltage_latch()
  {
    unsigned char value;


    /* 
     * AccDetect2 ball voltage level goes below AccDetect21Th 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_5_REG) & ACCESSORY_21_LOW_VOLTAGE_LATCH_PARAM_MASK) >> 5;
    return value;
  }


/***************************************************************************
 *
 * Function : get_accessory21_high_voltage_latch
 *
 * RET  : Return the value of register LatchedInterrupt5
 *
 * Notes : From register 0x0E24, bits 6:6
 *
 **************************************************************************/
unsigned char get_accessory21_high_voltage_latch()
  {
    unsigned char value;


    /* 
     * AccDetect2 ball voltage level goes above AccDetect21Th 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_5_REG) & ACCESSORY_21_HIGH_VOLTAGE_PARAM_MASK) >> 6;
    return value;
  }


/***************************************************************************
 *
 * Function : get_adc_hardware_control_latch
 *
 * RET  : Return the value of register LatchedInterrupt5
 *
 * Notes : From register 0x0E24, bits 7:7
 *
 **************************************************************************/
unsigned char get_adc_hardware_control_latch()
  {
    unsigned char value;


    /* 
     * GP ADC conversion requested thru Hardware control 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_5_REG) & ADC_HARDWARE_CONTROL_PARAM_MASK) >> 7;
    return value;
  }


/***************************************************************************
 *
 * Function : get_latched_interrupt7
 *
 * RET  : Return the value of register LatchedInterrupt7
 *
 * Notes : From register 0x0E26, bits 7:0
 *
 **************************************************************************/
unsigned char get_latched_interrupt7()
  {
    unsigned char value;


    /* 
     * IntSource7 Status 
     */ 
   value = I2CRead(LATCHED_INTERRUPT_7_REG) ;
    return value;
  }


/***************************************************************************
 *
 * Function : get_gpio13_rising_latch
 *
 * RET  : Return the value of register LatchedInterrupt7
 *
 * Notes : From register 0x0E26, bits 7:7
 *
 **************************************************************************/
unsigned char get_gpio13_rising_latch()
  {
    unsigned char value;


    /* 
     * Rising edge detected on GPIO13 ball 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_7_REG) & GPIO_13_RISING_LATCH_EVENT_PARAM_MASK) >> 7;
    return value;
  }


/***************************************************************************
 *
 * Function : get_gpio12_rising_latch
 *
 * RET  : Return the value of register LatchedInterrupt7
 *
 * Notes : From register 0x0E26, bits 6:6
 *
 **************************************************************************/
unsigned char get_gpio12_rising_latch()
  {
    unsigned char value;


    /* 
     * Rising edge detected on GPIO12 ball 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_7_REG) & GPIO_12_RISING_LATCH_EVENT_PARAM_MASK) >> 6;
    return value;
  }


/***************************************************************************
 *
 * Function : get_gpio11_rising_latch
 *
 * RET  : Return the value of register LatchedInterrupt7
 *
 * Notes : From register 0x0E26, bits 5:5
 *
 **************************************************************************/
unsigned char get_gpio11_rising_latch()
  {
    unsigned char value;


    /* 
     * Rising edge detected on GPIO11 ball 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_7_REG) & GPIO_11_RISING_LATCH_EVENT_PARAM_MASK) >> 5;
    return value;
  }


/***************************************************************************
 *
 * Function : get_gpio10_rising_latch
 *
 * RET  : Return the value of register LatchedInterrupt7
 *
 * Notes : From register 0x0E26, bits 4:4
 *
 **************************************************************************/
unsigned char get_gpio10_rising_latch()
  {
    unsigned char value;


    /* 
     * Rising edge detected on GPIO10 ball 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_7_REG) & GPIO_10_RISING_LATCH_EVENT_PARAM_MASK) >> 4;
    return value;
  }


/***************************************************************************
 *
 * Function : get_gpio9_rising_latch
 *
 * RET  : Return the value of register LatchedInterrupt7
 *
 * Notes : From register 0x0E26, bits 3:3
 *
 **************************************************************************/
unsigned char get_gpio9_rising_latch()
  {
    unsigned char value;


    /* 
     * Rising edge detected on GPIO9 ball 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_7_REG) & GPIO_9_RISING_LATCH_EVENT_PARAM_MASK) >> 3;
    return value;
  }


/***************************************************************************
 *
 * Function : get_gpio8_rising_latch
 *
 * RET  : Return the value of register LatchedInterrupt7
 *
 * Notes : From register 0x0E26, bits 2:2
 *
 **************************************************************************/
unsigned char get_gpio8_rising_latch()
  {
    unsigned char value;


    /* 
     * Rising edge detected on GPIO8 ball 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_7_REG) & GPIO_8_RISING_LATCH_EVENT_PARAM_MASK) >> 2;
    return value;
  }


/***************************************************************************
 *
 * Function : get_gpio7_rising_latch
 *
 * RET  : Return the value of register LatchedInterrupt7
 *
 * Notes : From register 0x0E26, bits 1:1
 *
 **************************************************************************/
unsigned char get_gpio7_rising_latch()
  {
    unsigned char value;


    /* 
     * Rising edge detected on GPIO7 ball 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_7_REG) & GPIO_7_RISING_LATCH_EVENT_PARAM_MASK) >> 1;
    return value;
  }


/***************************************************************************
 *
 * Function : get_gpio6_rising_latch
 *
 * RET  : Return the value of register LatchedInterrupt7
 *
 * Notes : From register 0x0E26, bits 0:0
 *
 **************************************************************************/
unsigned char get_gpio6_rising_latch()
  {
    unsigned char value;


    /* 
     * Rising edge detected on GPIO6 ball 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_7_REG) & GPIO_6_RISING_LATCH_EVENT_PARAM_MASK);
    return value;
  }


/***************************************************************************
 *
 * Function : get_latched_interrupt8
 *
 * RET  : Return the value of register LatchedInterrupt8
 *
 * Notes : From register 0x0E27, bits 7:0
 *
 **************************************************************************/
unsigned char get_latched_interrupt8()
  {
    unsigned char value;


    /* 
     * IntSource8 Status 
     */ 
   value = I2CRead(LATCHED_INTERRUPT_8_REG) ;
    return value;
  }


/***************************************************************************
 *
 * Function : get_gpio41_rising_latch
 *
 * RET  : Return the value of register LatchedInterrupt8
 *
 * Notes : From register 0x0E27, bits 7:7
 *
 **************************************************************************/
unsigned char get_gpio41_rising_latch()
  {
    unsigned char value;


    /* 
     * Rising edge detected on GPIO41 ball 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_8_REG) & GPIO_41_RISING_LATCH_EVENT_PARAM_MASK) >> 7;
    return value;
  }


/***************************************************************************
 *
 * Function : get_gpio40_rising_latch
 *
 * RET  : Return the value of register LatchedInterrupt8
 *
 * Notes : From register 0x0E27, bits 6:6
 *
 **************************************************************************/
unsigned char get_gpio40_rising_latch()
  {
    unsigned char value;


    /* 
     * Rising edge detected on GPIO40 ball 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_8_REG) & GPIO_40_RISING_LATCH_EVENT_PARAM_MASK) >> 6;
    return value;
  }


/***************************************************************************
 *
 * Function : get_gpio39_rising_latch
 *
 * RET  : Return the value of register LatchedInterrupt8
 *
 * Notes : From register 0x0E27, bits 5:5
 *
 **************************************************************************/
unsigned char get_gpio39_rising_latch()
  {
    unsigned char value;


    /* 
     * Rising edge detected on GPIO39 ball 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_8_REG) & GPIO_39_RISING_LATCH_EVENT_PARAM_MASK) >> 5;
    return value;
  }


/***************************************************************************
 *
 * Function : get_gpio38_rising_latch
 *
 * RET  : Return the value of register LatchedInterrupt8
 *
 * Notes : From register 0x0E27, bits 4:4
 *
 **************************************************************************/
unsigned char get_gpio38_rising_latch()
  {
    unsigned char value;


    /* 
     * Rising edge detected on GPIO38 ball 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_8_REG) & GPIO_38_RISING_LATCH_EVENT_PARAM_MASK) >> 4;
    return value;
  }


/***************************************************************************
 *
 * Function : get_gpio37_rising_latch
 *
 * RET  : Return the value of register LatchedInterrupt8
 *
 * Notes : From register 0x0E27, bits 3:3
 *
 **************************************************************************/
unsigned char get_gpio37_rising_latch()
  {
    unsigned char value;


    /* 
     * Rising edge detected on GPIO37 ball 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_8_REG) & GPIO_37_RISING_LATCH_EVENT_PARAM_MASK) >> 3;
    return value;
  }


/***************************************************************************
 *
 * Function : get_gpio36_rising_latch
 *
 * RET  : Return the value of register LatchedInterrupt8
 *
 * Notes : From register 0x0E27, bits 2:2
 *
 **************************************************************************/
unsigned char get_gpio36_rising_latch()
  {
    unsigned char value;


    /* 
     * Rising edge detected on GPIO36 ball 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_8_REG) & GPIO_36_RISING_LATCH_EVENT_PARAM_MASK) >> 2;
    return value;
  }


/***************************************************************************
 *
 * Function : get_gpio25_rising_latch
 *
 * RET  : Return the value of register LatchedInterrupt8
 *
 * Notes : From register 0x0E27, bits 1:1
 *
 **************************************************************************/
unsigned char get_gpio25_rising_latch()
  {
    unsigned char value;


    /* 
     * Rising edge detected on GPIO25 ball 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_8_REG) & GPIO_25_RISING_LATCH_EVENT_PARAM_MASK) >> 1;
    return value;
  }


/***************************************************************************
 *
 * Function : get_gpio24_rising_latch
 *
 * RET  : Return the value of register LatchedInterrupt8
 *
 * Notes : From register 0x0E27, bits 0:0
 *
 **************************************************************************/
unsigned char get_gpio24_rising_latch()
  {
    unsigned char value;


    /* 
     * Rising edge detected on GPIO24 ball 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_8_REG) & GPIO_24_RISING_LATCH_EVENT_PARAM_MASK);
    return value;
  }


/***************************************************************************
 *
 * Function : get_latched_interrupt9
 *
 * RET  : Return the value of register LatchedInterrupt9
 *
 * Notes : From register 0x0E28, bits 7:0
 *
 **************************************************************************/
unsigned char get_latched_interrupt9()
  {
    unsigned char value;


    /* 
     * IntSource9 Status 
     */ 
   value = I2CRead(LATCHED_INTERRUPT_9_REG) ;
    return value;
  }


/***************************************************************************
 *
 * Function : get_gpio13_falling_latch
 *
 * RET  : Return the value of register LatchedInterrupt9
 *
 * Notes : From register 0x0E28, bits 7:7
 *
 **************************************************************************/
unsigned char get_gpio13_falling_latch()
  {
    unsigned char value;


    /* 
     * Falling edge detected on GPIO13 ball 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_9_REG) & GPIO_13_FALLING_LATCH_EVENT_PARAM_MASK) >> 7;
    return value;
  }


/***************************************************************************
 *
 * Function : get_gpio12_falling_latch
 *
 * RET  : Return the value of register LatchedInterrupt9
 *
 * Notes : From register 0x0E28, bits 6:6
 *
 **************************************************************************/
unsigned char get_gpio12_falling_latch()
  {
    unsigned char value;


    /* 
     * Falling edge detected on GPIO12 ball 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_9_REG) & GPIO_12_FALLING_LATCH_EVENT_PARAM_MASK) >> 6;
    return value;
  }


/***************************************************************************
 *
 * Function : get_gpio11_falling_latch
 *
 * RET  : Return the value of register LatchedInterrupt9
 *
 * Notes : From register 0x0E28, bits 5:5
 *
 **************************************************************************/
unsigned char get_gpio11_falling_latch()
  {
    unsigned char value;


    /* 
     * Falling edge detected on GPIO11 ball 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_9_REG) & GPIO_11_FALLING_LATCH_EVENT_PARAM_MASK) >> 5;
    return value;
  }


/***************************************************************************
 *
 * Function : get_gpio10_falling_latch
 *
 * RET  : Return the value of register LatchedInterrupt9
 *
 * Notes : From register 0x0E28, bits 4:4
 *
 **************************************************************************/
unsigned char get_gpio10_falling_latch()
  {
    unsigned char value;


    /* 
     * Falling edge detected on GPIO10 ball 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_9_REG) & GPIO_10_FALLING_LATCH_EVENT_PARAM_MASK) >> 4;
    return value;
  }


/***************************************************************************
 *
 * Function : get_gpio9_falling_latch
 *
 * RET  : Return the value of register LatchedInterrupt9
 *
 * Notes : From register 0x0E28, bits 3:3
 *
 **************************************************************************/
unsigned char get_gpio9_falling_latch()
  {
    unsigned char value;


    /* 
     * Falling edge detected on GPIO9 ball 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_9_REG) & GPIO_9_FALLING_LATCH_EVENT_PARAM_MASK) >> 3;
    return value;
  }


/***************************************************************************
 *
 * Function : get_gpio8_falling_latch
 *
 * RET  : Return the value of register LatchedInterrupt9
 *
 * Notes : From register 0x0E28, bits 2:2
 *
 **************************************************************************/
unsigned char get_gpio8_falling_latch()
  {
    unsigned char value;


    /* 
     * Falling edge detected on GPIO8 ball 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_9_REG) & GPIO_8_FALLING_LATCH_EVENT_PARAM_MASK) >> 2;
    return value;
  }


/***************************************************************************
 *
 * Function : get_gpio7_falling_latch
 *
 * RET  : Return the value of register LatchedInterrupt9
 *
 * Notes : From register 0x0E28, bits 1:1
 *
 **************************************************************************/
unsigned char get_gpio7_falling_latch()
  {
    unsigned char value;


    /* 
     * Falling edge detected on GPIO7 ball 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_9_REG) & GPIO_7_FALLING_LATCH_EVENT_PARAM_MASK) >> 1;
    return value;
  }


/***************************************************************************
 *
 * Function : get_gpio6_falling_latch
 *
 * RET  : Return the value of register LatchedInterrupt9
 *
 * Notes : From register 0x0E28, bits 0:0
 *
 **************************************************************************/
unsigned char get_gpio6_falling_latch()
  {
    unsigned char value;


    /* 
     * Falling edge detected on GPIO6 ball 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_9_REG) & GPIO_6_FALLING_LATCH_EVENT_PARAM_MASK);
    return value;
  }


/***************************************************************************
 *
 * Function : get_latched_interrupt10
 *
 * RET  : Return the value of register LatchedInterrupt10
 *
 * Notes : From register 0x0E29, bits 7:0
 *
 **************************************************************************/
unsigned char get_latched_interrupt10()
  {
    unsigned char value;


    /* 
     * IntSource10 Status 
     */ 
   value = I2CRead(LATCHED_INTERRUPT_10_REG) ;
    return value;
  }


/***************************************************************************
 *
 * Function : get_gpio41_falling_latch
 *
 * RET  : Return the value of register LatchedInterrupt10
 *
 * Notes : From register 0x0E29, bits 7:7
 *
 **************************************************************************/
unsigned char get_gpio41_falling_latch()
  {
    unsigned char value;


    /* 
     * Falling edge detected on GPIO41 ball 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_10_REG) & GPIO_41_FALLING_LATCH_EVENT_PARAM_MASK) >> 7;
    return value;
  }


/***************************************************************************
 *
 * Function : get_gpio40_falling_latch
 *
 * RET  : Return the value of register LatchedInterrupt10
 *
 * Notes : From register 0x0E29, bits 6:6
 *
 **************************************************************************/
unsigned char get_gpio40_falling_latch()
  {
    unsigned char value;


    /* 
     * Falling edge detected on GPIO40 ball 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_10_REG) & GPIO_40_FALLING_LATCH_EVENT_PARAM_MASK) >> 6;
    return value;
  }


/***************************************************************************
 *
 * Function : get_gpio39_falling_latch
 *
 * RET  : Return the value of register LatchedInterrupt10
 *
 * Notes : From register 0x0E29, bits 5:5
 *
 **************************************************************************/
unsigned char get_gpio39_falling_latch()
  {
    unsigned char value;


    /* 
     * Falling edge detected on GPIO39 ball 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_10_REG) & GPIO_39_FALLING_LATCH_EVENT_PARAM_MASK) >> 5;
    return value;
  }


/***************************************************************************
 *
 * Function : get_gpio38_falling_latch
 *
 * RET  : Return the value of register LatchedInterrupt10
 *
 * Notes : From register 0x0E29, bits 4:4
 *
 **************************************************************************/
unsigned char get_gpio38_falling_latch()
  {
    unsigned char value;


    /* 
     * Falling edge detected on GPIO38 ball 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_10_REG) & GPIO_38_FALLING_LATCH_EVENT_PARAM_MASK) >> 4;
    return value;
  }


/***************************************************************************
 *
 * Function : get_gpio37_falling_latch
 *
 * RET  : Return the value of register LatchedInterrupt10
 *
 * Notes : From register 0x0E29, bits 3:3
 *
 **************************************************************************/
unsigned char get_gpio37_falling_latch()
  {
    unsigned char value;


    /* 
     * Falling edge detected on GPIO37 ball 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_10_REG) & GPIO_37_FALLING_LATCH_EVENT_PARAM_MASK) >> 3;
    return value;
  }


/***************************************************************************
 *
 * Function : get_gpio36_falling_latch
 *
 * RET  : Return the value of register LatchedInterrupt10
 *
 * Notes : From register 0x0E29, bits 2:2
 *
 **************************************************************************/
unsigned char get_gpio36_falling_latch()
  {
    unsigned char value;


    /* 
     * Falling edge detected on GPIO36 ball 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_10_REG) & GPIO_36_FALLING_LATCH_EVENT_PARAM_MASK) >> 2;
    return value;
  }


/***************************************************************************
 *
 * Function : get_gpio25_falling_latch
 *
 * RET  : Return the value of register LatchedInterrupt10
 *
 * Notes : From register 0x0E29, bits 1:1
 *
 **************************************************************************/
unsigned char get_gpio25_falling_latch()
  {
    unsigned char value;


    /* 
     * Falling edge detected on GPIO25 ball 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_10_REG) & GPIO_25_FALLING_LATCH_EVENT_PARAM_MASK) >> 1;
    return value;
  }


/***************************************************************************
 *
 * Function : get_gpio24_falling_latch
 *
 * RET  : Return the value of register LatchedInterrupt10
 *
 * Notes : From register 0x0E29, bits 0:0
 *
 **************************************************************************/
unsigned char get_gpio24_falling_latch()
  {
    unsigned char value;


    /* 
     * Falling edge detected on GPIO24 ball 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_10_REG) & GPIO_24_FALLING_LATCH_EVENT_PARAM_MASK);
    return value;
  }


/***************************************************************************
 *
 * Function : get_latched_interrupt12
 *
 * RET  : Return the value of register LatchedInterrupt12
 *
 * Notes : From register 0x0E2B, bits 7:0
 *
 **************************************************************************/
unsigned char get_latched_interrupt12()
  {
    unsigned char value;


    /* 
     * LatchedInterrupt12 Status 
     */ 
   value = I2CRead(LATCHED_INTERRUPT_12_REG) ;
    return value;
  }


/***************************************************************************
 *
 * Function : get_usb_link_status_latch
 *
 * RET  : Return the value of register LatchedInterrupt12
 *
 * Notes : From register 0x0E2B, bits 7:7
 *
 **************************************************************************/
unsigned char get_usb_link_status_latch()
  {
    unsigned char value;


    /* 
     * 0: UsbLink status unchanged 
     * 1: UsbLink status changed 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_12_REG) & USB_LINK_STATUS_CHANGED_LATCH_EVENT_PARAM_MASK) >> 7;
    return value;
  }


/***************************************************************************
 *
 * Function : get_usb_phy_power_error
 *
 * RET  : Return the value of register LatchedInterrupt12
 *
 * Notes : From register 0x0E2B, bits 6:6
 *
 **************************************************************************/
unsigned char get_usb_phy_power_error()
  {
    unsigned char value;


    /* 
     * 0: inactive 
     * 1: USB PHY has been reset due to a power loss 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_12_REG) & USB_PHY_POWER_ERROR_PARAM_MASK) >> 6;
    return value;
  }


/***************************************************************************
 *
 * Function : get_adp_sense_off_latch
 *
 * RET  : Return the value of register LatchedInterrupt12
 *
 * Notes : From register 0x0E2B, bits 4:4
 *
 **************************************************************************/
unsigned char get_adp_sense_off_latch()
  {
    unsigned char value;


    /* 
     * 0: Current source Off 
     * 1: Current source On 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_12_REG) & CURRENT_SOURCE_ON_LATCH_EVENT_PARAM_MASK) >> 4;
    return value;
  }


/***************************************************************************
 *
 * Function : get_adp_probe_un_plug_latch
 *
 * RET  : Return the value of register LatchedInterrupt12
 *
 * Notes : From register 0x0E2B, bits 3:3
 *
 **************************************************************************/
unsigned char get_adp_probe_un_plug_latch()
  {
    unsigned char value;


    /* 
     * 0: previous state 
     * 1: accessory unplug on Vbus 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_12_REG) & ADP_PROBE_UN_PLUG_LATCH_EVENT_PARAM_MASK) >> 3;
    return value;
  }


/***************************************************************************
 *
 * Function : get_adp_probe_plug_latch
 *
 * RET  : Return the value of register LatchedInterrupt12
 *
 * Notes : From register 0x0E2B, bits 2:2
 *
 **************************************************************************/
unsigned char get_adp_probe_plug_latch()
  {
    unsigned char value;


    /* 
     * 0: previous state 
     * 1: accessory plug on Vbus 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_12_REG) & ADP_PROBE_PLUG_LATCH_EVENT_PARAM_MASK) >> 2;
    return value;
  }


/***************************************************************************
 *
 * Function : get_adp_sink_error_latch
 *
 * RET  : Return the value of register LatchedInterrupt12
 *
 * Notes : From register 0x0E2B, bits 1:1
 *
 **************************************************************************/
unsigned char get_adp_sink_error_latch()
  {
    unsigned char value;


    /* 
     * 0: inactive 
     * 1: no detection after 2046*32Khz clock cycles (about 
     * 62ms) 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_12_REG) & ADP_SINK_ERROR_LATCH_EVENT_PARAM_MASK) >> 1;
    return value;
  }


/***************************************************************************
 *
 * Function : get_adp_source_error_latch
 *
 * RET  : Return the value of register LatchedInterrupt12
 *
 * Notes : From register 0x0E2B, bits 0:0
 *
 **************************************************************************/
unsigned char get_adp_source_error_latch()
  {
    unsigned char value;


    /* 
     * 0: inactive 
     * 1: no detection after inactive no detection after 
     * 2046*32Khz clock cycles (about 62ms) 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_12_REG) & ADP_SOURCE_ERROR_LATCH_EVENT_PARAM_MASK);
    return value;
  }


/***************************************************************************
 *
 * Function : get_latched_source19
 *
 * RET  : Return the value of register LatchedSource19
 *
 * Notes : From register 0x0E32, bits 7:0
 *
 **************************************************************************/
unsigned char get_latched_source19()
  {
    unsigned char value;


    /* 
     * Latch 19 Status 
     */ 
   value = I2CRead(LATCHED_SOURCE_19_REG) ;
    return value;
  }


/***************************************************************************
 *
 * Function : get_battery_temperature_high_latch
 *
 * RET  : Return the value of register LatchedSource19
 *
 * Notes : From register 0x0E32, bits 3:3
 *
 **************************************************************************/
unsigned char get_battery_temperature_high_latch()
  {
    unsigned char value;


    /* 
     * 0: Btemp < BtempHigh 
     * 1: Btemp > BtempHigh 
     */ 
    value = (I2CRead(LATCHED_SOURCE_19_REG) & BATTERY_TEMPERATURE_HIGH_LATCH_PARAM_MASK) >> 3;
    return value;
  }


/***************************************************************************
 *
 * Function : get_battery_temperature_medium_high_latch
 *
 * RET  : Return the value of register LatchedSource19
 *
 * Notes : From register 0x0E32, bits 2:2
 *
 **************************************************************************/
unsigned char get_battery_temperature_medium_high_latch()
  {
    unsigned char value;


    /* 
     * 0: Btemp < BtempMedium or Btemp > BtempHigh 
     * 1: BtempHigh > Btemp > BtempMedium 
     */ 
    value = (I2CRead(LATCHED_SOURCE_19_REG) & BATTERY_TEMPERATURE_MEDIUM_HIGH_LATCH_PARAM_MASK) >> 2;
    return value;
  }


/***************************************************************************
 *
 * Function : get_battery_temperature_low_medium_latch
 *
 * RET  : Return the value of register LatchedSource19
 *
 * Notes : From register 0x0E32, bits 1:1
 *
 **************************************************************************/
unsigned char get_battery_temperature_low_medium_latch()
  {
    unsigned char value;


    /* 
     * 0: Btemp < BtempLow or Btemp > BtempMedium 
     * 1: BtempMedium > Btemp > BtempLow 
     */ 
    value = (I2CRead(LATCHED_SOURCE_19_REG) & BATTERY_TEMPERATURE_LOW_MEDIUM_LATCH_PARAM_MASK) >> 1;
    return value;
  }


/***************************************************************************
 *
 * Function : get_battery_temperature_low_latch
 *
 * RET  : Return the value of register LatchedSource19
 *
 * Notes : From register 0x0E32, bits 0:0
 *
 **************************************************************************/
unsigned char get_battery_temperature_low_latch()
  {
    unsigned char value;


    /* 
     * 0: Btemp > BtempLow 
     * 1: BtempLow > Btemp 
     */ 
    value = (I2CRead(LATCHED_SOURCE_19_REG) & BATTERY_TEMPERATURE_LOW_LATCH_PARAM_MASK);
    return value;
  }


/***************************************************************************
 *
 * Function : get_latched_interrupt20
 *
 * RET  : Return the value of register LatchedInterrupt20
 *
 * Notes : From register 0x0E33, bits 7:0
 *
 **************************************************************************/
unsigned char get_latched_interrupt20()
  {
    unsigned char value;


    /* 
     * IntSource20 Status 
     */ 
   value = I2CRead(LATCHED_INTERRUPT_20_REG) ;
    return value;
  }


/***************************************************************************
 *
 * Function : get_srpd_dected
 *
 * RET  : Return the value of register LatchedInterrupt20
 *
 * Notes : From register 0x0E33, bits 0:0
 *
 **************************************************************************/
unsigned char get_srpd_dected()
  {
    unsigned char value;


    /* 
     * 0: Inactive 
     * 1: SRP detected 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_20_REG) & SRPD_DECTED_LATCH_PARAM_MASK);
    return value;
  }


/***************************************************************************
 *
 * Function : get_usb_charger_plug_latch
 *
 * RET  : Return the value of register LatchedInterrupt20
 *
 * Notes : From register 0x0E33, bits 1:1
 *
 **************************************************************************/
unsigned char get_usb_charger_plug_latch()
  {
    unsigned char value;


    /* 
     * not allowed USB charger detected on Vbus ball 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_20_REG) & USB_BAD_CHARGER_PLUG_LATCH_PARAM_MASK) >> 1;
    return value;
  }


/***************************************************************************
 *
 * Function : get_id_up_rising_event_latch
 *
 * RET  : Return the value of register LatchedInterrupt20
 *
 * Notes : From register 0x0E33, bits 2:2
 *
 **************************************************************************/
unsigned char get_id_up_rising_event_latch()
  {
    unsigned char value;


    /* 
     * Rising edge detected on ID 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_20_REG) & ID_UP_RISING_EVENT_LATCH_PARAM_MASK) >> 2;
    return value;
  }


/***************************************************************************
 *
 * Function : get_id_detection_greater37k_latch
 *
 * RET  : Return the value of register LatchedInterrupt20
 *
 * Notes : From register 0x0E33, bits 4:4
 *
 **************************************************************************/
unsigned char get_id_detection_greater37k_latch()
  {
    unsigned char value;


    /* 
     * ID resistance greater than 37k detected 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_20_REG) & ID_DETECTION_GREATER_3_7K_LATCH_PARAM_MASK) >> 4;
    return value;
  }


/***************************************************************************
 *
 * Function : get_id_detection_greater69k_latch
 *
 * RET  : Return the value of register LatchedInterrupt20
 *
 * Notes : From register 0x0E33, bits 5:5
 *
 **************************************************************************/
unsigned char get_id_detection_greater69k_latch()
  {
    unsigned char value;


    /* 
     * ID resistance greater than 69k detected 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_20_REG) & ID_DETECTION_GREATER_6_9K_LATCH_PARAM_MASK) >> 5;
    return value;
  }


/***************************************************************************
 *
 * Function : get_id_detection_greater125k_latch
 *
 * RET  : Return the value of register LatchedInterrupt20
 *
 * Notes : From register 0x0E33, bits 6:6
 *
 **************************************************************************/
unsigned char get_id_detection_greater125k_latch()
  {
    unsigned char value;


    /* 
     * ID resistance greater than 125k detected 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_20_REG) & ID_DETECTION_GREATER_12_5K_LATCH_PARAM_MASK) >> 6;
    return value;
  }


/***************************************************************************
 *
 * Function : get_id_detection_greater220k_latch
 *
 * RET  : Return the value of register LatchedInterrupt20
 *
 * Notes : From register 0x0E33, bits 7:7
 *
 **************************************************************************/
unsigned char get_id_detection_greater220k_latch()
  {
    unsigned char value;


    /* 
     * ID resistance greater than 220k detected 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_20_REG) & ID_DETECTION_GREATER_22_0K_LATCH_PARAM_MASK) >> 7;
    return value;
  }


/***************************************************************************
 *
 * Function : get_latched_interrupt21
 *
 * RET  : Return the value of register LatchedInterrupt21
 *
 * Notes : From register 0x0E34, bits 7:0
 *
 **************************************************************************/
unsigned char get_latched_interrupt21()
  {
    unsigned char value;


    /* 
     * IntSource21 Status 
     */ 
   value = I2CRead(LATCHED_INTERRUPT_21_REG) ;
    return value;
  }


/***************************************************************************
 *
 * Function : get_id_wake_up_falling_latch
 *
 * RET  : Return the value of register LatchedInterrupt21
 *
 * Notes : From register 0x0E34, bits 0:0
 *
 **************************************************************************/
unsigned char get_id_wake_up_falling_latch()
  {
    unsigned char value;


    /* 
     * Falling edge detected on ID 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_21_REG) & ID_WAKE_UP_FALLING_EVENT_LATCH_PARAM_MASK);
    return value;
  }


/***************************************************************************
 *
 * Function : get_id_falling_event_latch
 *
 * RET  : Return the value of register LatchedInterrupt20
 *
 * Notes : From register 0x0E34, bits 1:1
 *
 **************************************************************************/
unsigned char get_id_falling_event_latch()
  {
    unsigned char value;


    /* 
     * falling edge detected on ID 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_20_REG) & ID_FALLING_EVENT_LATCH_PARAM_MASK) >> 1;
    return value;
  }


/***************************************************************************
 *
 * Function : get_id_detection37k_latch
 *
 * RET  : Return the value of register LatchedInterrupt21
 *
 * Notes : From register 0x0E34, bits 2:2
 *
 **************************************************************************/
unsigned char get_id_detection37k_latch()
  {
    unsigned char value;


    /* 
     * ID resistance lower than 37k detected 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_21_REG) & ID_DETECTION_3_7K_LATCH_PARAM_MASK) >> 2;
    return value;
  }


/***************************************************************************
 *
 * Function : get_id_detection69k_latch
 *
 * RET  : Return the value of register LatchedInterrupt21
 *
 * Notes : From register 0x0E34, bits 3:3
 *
 **************************************************************************/
unsigned char get_id_detection69k_latch()
  {
    unsigned char value;


    /* 
     * ID resistance lower than 69k detected 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_21_REG) & ID_DETECTION_6_9K_LATCH_PARAM_MASK) >> 3;
    return value;
  }


/***************************************************************************
 *
 * Function : get_id_detection125k_latch
 *
 * RET  : Return the value of register LatchedInterrupt21
 *
 * Notes : From register 0x0E34, bits 4:4
 *
 **************************************************************************/
unsigned char get_id_detection125k_latch()
  {
    unsigned char value;


    /* 
     * ID resistance lower than 125k detected 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_21_REG) & ID_DETECTION_12_5K_LATCH_PARAM_MASK) >> 4;
    return value;
  }


/***************************************************************************
 *
 * Function : get_id_detection220k_latch
 *
 * RET  : Return the value of register LatchedInterrupt21
 *
 * Notes : From register 0x0E34, bits 5:5
 *
 **************************************************************************/
unsigned char get_id_detection220k_latch()
  {
    unsigned char value;


    /* 
     * ID resistance lower than 220k detected 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_21_REG) & ID_DETECTION_22_0K_LATCH_PARAM_MASK) >> 5;
    return value;
  }


/***************************************************************************
 *
 * Function : get_latched_interrupt22
 *
 * RET  : Return the value of register LatchedInterrupt22
 *
 * Notes : From register 0x0E35, bits 7:0
 *
 **************************************************************************/
unsigned char get_latched_interrupt22()
  {
    unsigned char value;


    /* 
     * IntSource22 Status 
     */ 
   value = I2CRead(LATCHED_INTERRUPT_22_REG) ;
    return value;
  }


/***************************************************************************
 *
 * Function : get_charging_current_limited_h_s_chirp_latch
 *
 * RET  : Return the value of register LatchedInterrupt22
 *
 * Notes : From register 0x0E35, bits 6:6
 *
 **************************************************************************/
unsigned char get_charging_current_limited_h_s_chirp_latch()
  {
    unsigned char value;


    /* 
     * 0: Inactive 
     * 1: In USB HS or Chirp modes, charging current is limited 
     * to a setting defined in registers. 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_22_REG) & CHARGING_CURRENT_LIMITED_HS_CHIRP_LATCH_PARAM_MASK) >> 6;
    return value;
  }


/***************************************************************************
 *
 * Function : get_charging_current_no_more_limited_latch
 *
 * RET  : Return the value of register LatchedInterrupt22
 *
 * Notes : From register 0x0E35, bits 5:5
 *
 **************************************************************************/
unsigned char get_charging_current_no_more_limited_latch()
  {
    unsigned char value;


    /* 
     * 0: inactive 
     * 1: Charging current is no more limited (USB PHY is not in 
     * HS or Chirp modes) 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_22_REG) & CHARGING_CURRENT_NO_MORE_LIMITED_LATCH_PARAM_MASK) >> 5;
    return value;
  }


/***************************************************************************
 *
 * Function : get_main_charger_thermal_above_latch
 *
 * RET  : Return the value of register LatchedInterrupt22
 *
 * Notes : From register 0x0E35, bits 3:3
 *
 **************************************************************************/
unsigned char get_main_charger_thermal_above_latch()
  {
    unsigned char value;


    /* 
     * 0: Die temperature is above than main charger thermal 
     * protection threshold (charge stopped) 
     * 1: Die temperature is upper than main charger thermal 
     * protection threshold (charge stopped) 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_22_REG) & MAIN_CHARGER_THERMAL_ABOVE_PARAM_MASK) >> 3;
    return value;
  }


/***************************************************************************
 *
 * Function : get_main_charger_thermal_below_latch
 *
 * RET  : Return the value of register LatchedInterrupt22
 *
 * Notes : From register 0x0E35, bits 2:2
 *
 **************************************************************************/
unsigned char get_main_charger_thermal_below_latch()
  {
    unsigned char value;


    /* 
     * 0: Die temperature is below than main charger thermal 
     * protection threshold (charge stopped) 
     * 1: Die temperature is upper than main charger thermal 
     * protection threshold (charge stopped) 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_22_REG) & MAIN_CHARGER_THERMAL_BELOW_PARAM_MASK) >> 2;
    return value;
  }


/***************************************************************************
 *
 * Function : get_usb_charger_thermal_above_latch
 *
 * RET  : Return the value of register LatchedInterrupt22
 *
 * Notes : From register 0x0E35, bits 1:1
 *
 **************************************************************************/
unsigned char get_usb_charger_thermal_above_latch()
  {
    unsigned char value;


    /* 
     * 0: Die temperature is above than usb charger thermal 
     * protection threshold (charge stopped) 
     * 1: Die temperature is upper than usb charger thermal 
     * protection threshold (charge stopped) 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_22_REG) & USB_CHARGER_THERMAL_ABOVE_PARAM_MASK) >> 1;
    return value;
  }


/***************************************************************************
 *
 * Function : get_usb_charger_thermal_below_latch
 *
 * RET  : Return the value of register LatchedInterrupt22
 *
 * Notes : From register 0x0E35, bits 0:0
 *
 **************************************************************************/
unsigned char get_usb_charger_thermal_below_latch()
  {
    unsigned char value;


    /* 
     * 0: Die temperature is above than usb charger thermal 
     * protection threshold (charge stopped) 
     * 1: Die temperature is upper than usb charger thermal 
     * protection threshold (charge stopped) 
     */ 
    value = (I2CRead(LATCHED_INTERRUPT_22_REG) & USB_CHARGER_THERMAL_BELOW_PARAM_MASK);
    return value;
  }


