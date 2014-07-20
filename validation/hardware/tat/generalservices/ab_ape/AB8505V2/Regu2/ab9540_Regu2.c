/****************************************************************************
 * File : c:/Lisp/Production/ab9540/ab9540_Regu2/Linux/ab9540_Regu2.c
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

#ifndef C__LISP_PRODUCTION_AB9540_AB9540_REGU2_LINUX_AB9540_REGU2_C
#define C__LISP_PRODUCTION_AB9540_AB9540_REGU2_LINUX_AB9540_REGU2_C


#ifdef __cplusplus
extern "C" {
#endif
#include "ab9540_Regu2.h"

extern unsigned char I2CRead( unsigned short register_address);
extern void I2CWrite( unsigned short register_address, unsigned char data );


/***************************************************************************
 *
 * Function : set_arm_ouput_regulation
 *
 * IN   : param, a value to write to the regiter ArmVoltageManagement
 * OUT  : 
 *
 * RET  : Return the value of register 0xArmVoltageManagement
 *
 * Notes : From register 0x400, bits 1:0
 *
 **************************************************************************/
unsigned char set_arm_ouput_regulation( enum regulation param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(ARM_VOLTAGE_MANAGEMENT_REG);

    /* 
     * 00: force Varm disabled 
     * 01: force enabled in HP mode 
     * 10: allows HW (internal VarmRequest signal) to control 
     * Varm supply if 
     * VarmRequestCtrl[1:0]=0x. Forced in HP mode if 
     * VarmRequestCtrl[1:0]=1x 
     * 11: force enable in LP mode 
     */ 
  

     value =  old_value & ~ARM_OUPUT_REGULATION_MASK ;

    switch(  param ){

           case REGULATION_DISABLE_E:
                value =  value | REGULATION_DISABLE ;
                break;
           case REGULATION_FORCE_HP_MODE_E:
                value =  value | REGULATION_FORCE_HP_MODE ;
                break;
           case REGULATION_ALLOW_HW_E:
                value =  value | REGULATION_ALLOW_HW ;
                break;
           case REGULATION_FORCE_LOW_POWER_E:
                value =  value | REGULATION_FORCE_LOW_POWER ;
                break;
    }
  

    I2CWrite(ARM_VOLTAGE_MANAGEMENT_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_arm_ouput_regulation
 *
 * RET  : Return the value of register 0xArmVoltageManagement
 *
 * Notes : From register 0x400, bits 1:0
 *
 **************************************************************************/
unsigned char get_arm_ouput_regulation()
  {
    unsigned char value;


    /* 
     * 00: force Varm disabled 
     * 01: force enabled in HP mode 
     * 10: allows HW (internal VarmRequest signal) to control 
     * Varm supply if 
     * VarmRequestCtrl[1:0]=0x. Forced in HP mode if 
     * VarmRequestCtrl[1:0]=1x 
     * 11: force enable in LP mode 
     */ 
    value = (I2CRead(ARM_VOLTAGE_MANAGEMENT_REG) & ARM_OUPUT_REGULATION_MASK);
    return value;
  }


/***************************************************************************
 *
 * Function : set_arm_ouput_volage_select
 *
 * IN   : param, a value to write to the regiter ArmVoltageManagement
 * OUT  : 
 *
 * RET  : Return the value of register 0xArmVoltageManagement
 *
 * Notes : From register 0x400, bits 3:2
 *
 **************************************************************************/
unsigned char set_arm_ouput_volage_select( enum selection param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(ARM_VOLTAGE_MANAGEMENT_REG);

    /* 
     * 00: Varm output voltage is defined by VarmSel1 register 
     * 01: Varm output voltage is defined by VarmSel2 register 
     * 1x: Varm output voltage is defined by VarmSel3 register 
     */ 
  

     value =  old_value & ~ARM_OUPUT_VOLAGE_SELECT_MASK ;

    switch(  param ){

           case SEL1_REGISTER_E:
                value  = value  | (SEL1_REGISTER << 0x2);
                break;
           case SEL2_REGISTER_E:
                value  = value  | (SEL2_REGISTER << 0x2);
                break;
           case SEL3_REGISTER_E:
                value  = value  | (SEL3_REGISTER << 0x2);
                break;
    }
  

    I2CWrite(ARM_VOLTAGE_MANAGEMENT_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_arm_ouput_volage_select
 *
 * RET  : Return the value of register 0xArmVoltageManagement
 *
 * Notes : From register 0x400, bits 3:2
 *
 **************************************************************************/
unsigned char get_arm_ouput_volage_select()
  {
    unsigned char value;


    /* 
     * 00: Varm output voltage is defined by VarmSel1 register 
     * 01: Varm output voltage is defined by VarmSel2 register 
     * 1x: Varm output voltage is defined by VarmSel3 register 
     */ 
    value = (I2CRead(ARM_VOLTAGE_MANAGEMENT_REG) & ARM_OUPUT_VOLAGE_SELECT_MASK) >> 2;
    return value;
  }


/***************************************************************************
 *
 * Function : set_vbbp_selection_control
 *
 * IN   : param, a value to write to the regiter ArmVoltageManagement
 * OUT  : 
 *
 * RET  : Return the value of register 0xArmVoltageManagement
 *
 * Notes : From register 0x400, bits 4:4
 *
 **************************************************************************/
unsigned char set_vbbp_selection_control( enum selection1 param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(ARM_VOLTAGE_MANAGEMENT_REG);

    /* 
     * 0: VBBP output voltage is defined by VBBNSel1 register 
     * 1: VBBP output voltage is defined by VBBNSel2 register 
     */ 
    switch( param ){
        case VBBNSEL2_REGISTER_E: 
           value = old_value | VBBP_SELECTION_CONTROL_MASK; 
           break;
        case VBBNSEL1_REGISTER_E: 
           value = old_value & ~ VBBP_SELECTION_CONTROL_MASK;
           break;
    }
  

    I2CWrite(ARM_VOLTAGE_MANAGEMENT_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_vbbp_selection_control
 *
 * RET  : Return the value of register 0xArmVoltageManagement
 *
 * Notes : From register 0x400, bits 4:4
 *
 **************************************************************************/
unsigned char get_vbbp_selection_control()
  {
    unsigned char value;


    /* 
     * 0: VBBP output voltage is defined by VBBNSel1 register 
     * 1: VBBP output voltage is defined by VBBNSel2 register 
     */ 
    value = (I2CRead(ARM_VOLTAGE_MANAGEMENT_REG) & VBBP_SELECTION_CONTROL_MASK) >> 4;
    return value;
  }


/***************************************************************************
 *
 * Function : set_vbbn_selection_control
 *
 * IN   : param, a value to write to the regiter ArmVoltageManagement
 * OUT  : 
 *
 * RET  : Return the value of register 0xArmVoltageManagement
 *
 * Notes : From register 0x400, bits 5:5
 *
 **************************************************************************/
unsigned char set_vbbn_selection_control( enum selection1 param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(ARM_VOLTAGE_MANAGEMENT_REG);

    /* 
     * 0: VBBN output voltage is defined by VBBNSel1 register 
     * 1: VBBN output voltage is defined by VBBNSel2 register 
     */ 
    switch( param ){
        case VBBNSEL2_REGISTER_E: 
           value = old_value | VBBN_SELECTION_CONTROL_MASK; 
           break;
        case VBBNSEL1_REGISTER_E: 
           value = old_value & ~ VBBN_SELECTION_CONTROL_MASK;
           break;
    }
  

    I2CWrite(ARM_VOLTAGE_MANAGEMENT_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_vbbn_selection_control
 *
 * RET  : Return the value of register 0xArmVoltageManagement
 *
 * Notes : From register 0x400, bits 5:5
 *
 **************************************************************************/
unsigned char get_vbbn_selection_control()
  {
    unsigned char value;


    /* 
     * 0: VBBN output voltage is defined by VBBNSel1 register 
     * 1: VBBN output voltage is defined by VBBNSel2 register 
     */ 
    value = (I2CRead(ARM_VOLTAGE_MANAGEMENT_REG) & VBBN_SELECTION_CONTROL_MASK) >> 5;
    return value;
  }


/***************************************************************************
 *
 * Function : set_arm_voltage_auto_mode
 *
 * IN   : param, a value to write to the regiter ArmVoltageManagement
 * OUT  : 
 *
 * RET  : Return the value of register 0xArmVoltageManagement
 *
 * Notes : From register 0x400, bits 6:6
 *
 **************************************************************************/
unsigned char set_arm_voltage_auto_mode( enum auto_mode_enable param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(ARM_VOLTAGE_MANAGEMENT_REG);

    /* 
     * 0: Varm is not in AutoMode 
     * 1: Varm is in AutoMode 
     */ 
    switch( param ){
        case AUTO_MODE_ENABLE_E: 
           value = old_value | ARM_VOLTAGE_AUTO_MODE_MASK; 
           break;
        case AUTO_MODE_DISABLE_E: 
           value = old_value & ~ ARM_VOLTAGE_AUTO_MODE_MASK;
           break;
    }
  

    I2CWrite(ARM_VOLTAGE_MANAGEMENT_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_arm_voltage_auto_mode
 *
 * RET  : Return the value of register 0xArmVoltageManagement
 *
 * Notes : From register 0x400, bits 6:6
 *
 **************************************************************************/
unsigned char get_arm_voltage_auto_mode()
  {
    unsigned char value;


    /* 
     * 0: Varm is not in AutoMode 
     * 1: Varm is in AutoMode 
     */ 
    value = (I2CRead(ARM_VOLTAGE_MANAGEMENT_REG) & ARM_VOLTAGE_AUTO_MODE_MASK) >> 6;
    return value;
  }


/***************************************************************************
 *
 * Function : set_arm_voltage_pwm_mode
 *
 * IN   : param, a value to write to the regiter ArmVoltageManagement
 * OUT  : 
 *
 * RET  : Return the value of register 0xArmVoltageManagement
 *
 * Notes : From register 0x400, bits 7:7
 *
 **************************************************************************/
unsigned char set_arm_voltage_pwm_mode( enum forced param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(ARM_VOLTAGE_MANAGEMENT_REG);

    /* 
     * 0: inactive (Varm can be in PWM or PFM mode) 
     * 1: Varm is forced in PWM mode 
     */ 
    switch( param ){
        case FORCED_E: 
           value = old_value | ARM_VOLTAGE_PWM_MODE_MASK; 
           break;
        case INACTIVE_E: 
           value = old_value & ~ ARM_VOLTAGE_PWM_MODE_MASK;
           break;
    }
  

    I2CWrite(ARM_VOLTAGE_MANAGEMENT_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_arm_voltage_pwm_mode
 *
 * RET  : Return the value of register 0xArmVoltageManagement
 *
 * Notes : From register 0x400, bits 7:7
 *
 **************************************************************************/
unsigned char get_arm_voltage_pwm_mode()
  {
    unsigned char value;


    /* 
     * 0: inactive (Varm can be in PWM or PFM mode) 
     * 1: Varm is forced in PWM mode 
     */ 
    value = (I2CRead(ARM_VOLTAGE_MANAGEMENT_REG) & ARM_VOLTAGE_PWM_MODE_MASK) >> 7;
    return value;
  }


/***************************************************************************
 *
 * Function : set_vbbp_regulation
 *
 * IN   : param, a value to write to the regiter ArmVoltageBackManagement
 * OUT  : 
 *
 * RET  : Return the value of register 0xArmVoltageBackManagement
 *
 * Notes : From register 0x401, bits 1:0
 *
 **************************************************************************/
unsigned char set_vbbp_regulation( enum regulation param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(ARM_VOLTAGE_BACK_MANAGEMENT_REG);

    /* 
     * 00: force Vbbp disabled (switch between Varm and ground 
     * closed) 
     * 01: force enabled in HP mode 
     * 10: allows HW (internal VbbpRequest signal) to control 
     * Vbbp supply if VbbpRequestCtrl[1:0]=0x. Forced in HP mode 
     * if VbbpRequestCtrl[1:0]=1x 
     * 11: force enable in LP mode 
     */ 
  

     value =  old_value & ~VBBP_REGULATION_MASK ;

    switch(  param ){

           case REGULATION_DISABLE_E:
                value =  value | REGULATION_DISABLE ;
                break;
           case REGULATION_FORCE_HP_MODE_E:
                value =  value | REGULATION_FORCE_HP_MODE ;
                break;
           case REGULATION_ALLOW_HW_E:
                value =  value | REGULATION_ALLOW_HW ;
                break;
           case REGULATION_FORCE_LOW_POWER_E:
                value =  value | REGULATION_FORCE_LOW_POWER ;
                break;
    }
  

    I2CWrite(ARM_VOLTAGE_BACK_MANAGEMENT_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_vbbp_regulation
 *
 * RET  : Return the value of register 0xArmVoltageBackManagement
 *
 * Notes : From register 0x401, bits 1:0
 *
 **************************************************************************/
unsigned char get_vbbp_regulation()
  {
    unsigned char value;


    /* 
     * 00: force Vbbp disabled (switch between Varm and ground 
     * closed) 
     * 01: force enabled in HP mode 
     * 10: allows HW (internal VbbpRequest signal) to control 
     * Vbbp supply if VbbpRequestCtrl[1:0]=0x. Forced in HP mode 
     * if VbbpRequestCtrl[1:0]=1x 
     * 11: force enable in LP mode 
     */ 
    value = (I2CRead(ARM_VOLTAGE_BACK_MANAGEMENT_REG) & VBBP_REGULATION_MASK);
    return value;
  }


/***************************************************************************
 *
 * Function : set_vbbn_regulation
 *
 * IN   : param, a value to write to the regiter ArmVoltageBackManagement
 * OUT  : 
 *
 * RET  : Return the value of register 0xArmVoltageBackManagement
 *
 * Notes : From register 0x401, bits 3:2
 *
 **************************************************************************/
unsigned char set_vbbn_regulation( enum regulation param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(ARM_VOLTAGE_BACK_MANAGEMENT_REG);

    /* 
     * 00: force Vbbn disabled (switch between VBBN and ground 
     * closed) 
     * 01: force enabled in HP mode 
     * 10: allows HW (internal VbbnRequest signal) to control 
     * Vbbn supply if 
     * VbbnRequestCtrl[1:0]=0x. Forced in HP mode if 
     * VbbnRequestCtrl[1:0]=1x 
     * 11: force enable in LP mode 
     */ 
  

     value =  old_value & ~VBBN_REGULATION_MASK ;

    switch(  param ){

           case REGULATION_DISABLE_E:
                value  = value  | (REGULATION_DISABLE << 0x2);
                break;
           case REGULATION_FORCE_HP_MODE_E:
                value  = value  | (REGULATION_FORCE_HP_MODE << 0x2);
                break;
           case REGULATION_ALLOW_HW_E:
                value  = value  | (REGULATION_ALLOW_HW << 0x2);
                break;
           case REGULATION_FORCE_LOW_POWER_E:
                value  = value  | (REGULATION_FORCE_LOW_POWER << 0x2);
                break;
    }
  

    I2CWrite(ARM_VOLTAGE_BACK_MANAGEMENT_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_vbbn_regulation
 *
 * RET  : Return the value of register 0xArmVoltageBackManagement
 *
 * Notes : From register 0x401, bits 3:2
 *
 **************************************************************************/
unsigned char get_vbbn_regulation()
  {
    unsigned char value;


    /* 
     * 00: force Vbbn disabled (switch between VBBN and ground 
     * closed) 
     * 01: force enabled in HP mode 
     * 10: allows HW (internal VbbnRequest signal) to control 
     * Vbbn supply if 
     * VbbnRequestCtrl[1:0]=0x. Forced in HP mode if 
     * VbbnRequestCtrl[1:0]=1x 
     * 11: force enable in LP mode 
     */ 
    value = (I2CRead(ARM_VOLTAGE_BACK_MANAGEMENT_REG) & VBBN_REGULATION_MASK) >> 2;
    return value;
  }


/***************************************************************************
 *
 * Function : set_vaux3_output_voltage
 *
 * IN   : param, a value to write to the regiter ArmVoltageBackManagement
 * OUT  : 
 *
 * RET  : Return the value of register 0xArmVoltageBackManagement
 *
 * Notes : From register 0x401, bits 4:4
 *
 **************************************************************************/
unsigned char set_vaux3_output_voltage( enum vaux3_output_voltage_on param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(ARM_VOLTAGE_BACK_MANAGEMENT_REG);

    /* 
     * 0: Vaux3 output voltage is fixed by 'Vaux3Sel[2:0]' bits 
     * (VRF1Vaux3Sel register) 
     * 1: Vaux3 output voltage is equal to 3.05V (if Vaux3 
     * previously enabled) 
     */ 
    switch( param ){
        case VAUX_3_OUTPUT_VOLTAGE_ON_E: 
           value = old_value | VAUX_3_OUTPUT_VOLTAGE_MASK; 
           break;
        case VAUX_3_OUTPUT_VOLTAGE_OFF_E: 
           value = old_value & ~ VAUX_3_OUTPUT_VOLTAGE_MASK;
           break;
    }
  

    I2CWrite(ARM_VOLTAGE_BACK_MANAGEMENT_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_vaux3_output_voltage
 *
 * RET  : Return the value of register 0xArmVoltageBackManagement
 *
 * Notes : From register 0x401, bits 4:4
 *
 **************************************************************************/
unsigned char get_vaux3_output_voltage()
  {
    unsigned char value;


    /* 
     * 0: Vaux3 output voltage is fixed by 'Vaux3Sel[2:0]' bits 
     * (VRF1Vaux3Sel register) 
     * 1: Vaux3 output voltage is equal to 3.05V (if Vaux3 
     * previously enabled) 
     */ 
    value = (I2CRead(ARM_VOLTAGE_BACK_MANAGEMENT_REG) & VAUX_3_OUTPUT_VOLTAGE_MASK) >> 4;
    return value;
  }


/***************************************************************************
 *
 * Function : set_vbbp_pulldonw
 *
 * IN   : param, a value to write to the regiter ArmVoltageBackManagement
 * OUT  : 
 *
 * RET  : Return the value of register 0xArmVoltageBackManagement
 *
 * Notes : From register 0x401, bits 5:5
 *
 **************************************************************************/
unsigned char set_vbbp_pulldonw( enum vbbp_pulldonw_enable param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(ARM_VOLTAGE_BACK_MANAGEMENT_REG);

    /* 
     * 0: disable pull-down (switch) between VBBN and gnd 
     * 1: enable pull-down (switch) between VBBN and gnd] 
     */ 
    switch( param ){
        case VBBP_PULLDONW_ENABLE_E: 
           value = old_value | VBBP_PULLDONW_MASK; 
           break;
        case VBBP_PULLDONW_DISABLE_E: 
           value = old_value & ~ VBBP_PULLDONW_MASK;
           break;
    }
  

    I2CWrite(ARM_VOLTAGE_BACK_MANAGEMENT_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_vbbp_pulldonw
 *
 * RET  : Return the value of register 0xArmVoltageBackManagement
 *
 * Notes : From register 0x401, bits 5:5
 *
 **************************************************************************/
unsigned char get_vbbp_pulldonw()
  {
    unsigned char value;


    /* 
     * 0: disable pull-down (switch) between VBBN and gnd 
     * 1: enable pull-down (switch) between VBBN and gnd] 
     */ 
    value = (I2CRead(ARM_VOLTAGE_BACK_MANAGEMENT_REG) & VBBP_PULLDONW_MASK) >> 5;
    return value;
  }


/***************************************************************************
 *
 * Function : set_force_no_step
 *
 * IN   : param, a value to write to the regiter ArmVoltageBackManagement
 * OUT  : 
 *
 * RET  : Return the value of register 0xArmVoltageBackManagement
 *
 * Notes : From register 0x401, bits 6:6
 *
 **************************************************************************/
unsigned char set_force_no_step( enum force_no_step param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(ARM_VOLTAGE_BACK_MANAGEMENT_REG);

    /* 
     * 1: inactive 
     * 0: Force no voltage step between Vbbp and Varm whatever 
     * is VbbpSelx[3:0] 
     */ 
    switch( param ){
        case FORCE_NO_VOLTAGE_INACTIVE_E: 
           value = old_value | FORCE_NO_STEP_MASK; 
           break;
        case FORCE_NO_VOLTAGE_FORCED_E: 
           value = old_value & ~ FORCE_NO_STEP_MASK;
           break;
    }
  

    I2CWrite(ARM_VOLTAGE_BACK_MANAGEMENT_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_force_no_step
 *
 * RET  : Return the value of register 0xArmVoltageBackManagement
 *
 * Notes : From register 0x401, bits 6:6
 *
 **************************************************************************/
unsigned char get_force_no_step()
  {
    unsigned char value;


    /* 
     * 1: inactive 
     * 0: Force no voltage step between Vbbp and Varm whatever 
     * is VbbpSelx[3:0] 
     */ 
    value = (I2CRead(ARM_VOLTAGE_BACK_MANAGEMENT_REG) & FORCE_NO_STEP_MASK) >> 6;
    return value;
  }


/***************************************************************************
 *
 * Function : set_vape_regulation
 *
 * IN   : param, a value to write to the regiter VapeVoltageManagement
 * OUT  : 
 *
 * RET  : Return the value of register 0xVapeVoltageManagement
 *
 * Notes : From register 0x402, bits 1:0
 *
 **************************************************************************/
unsigned char set_vape_regulation( enum regulation param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(VAPE_VOLTAGE_MANAGEMENT_REG);

    /* 
     * 00: force Vape disabled 
     * 01: force enabled in HP mode 
     * 10: allows HW (internal VapeRequest signal) to control 
     * Vape supply if 
     * VapeRequestCtrl[1:0]=0x. Forced in HP mode if 
     * VapeRequestCtrl[1:0]=1x 
     * 11: force enable in LP mode 
     */ 
  

     value =  old_value & ~VAPE_REGULATION_MASK ;

    switch(  param ){

           case REGULATION_DISABLE_E:
                value =  value | REGULATION_DISABLE ;
                break;
           case REGULATION_FORCE_HP_MODE_E:
                value =  value | REGULATION_FORCE_HP_MODE ;
                break;
           case REGULATION_ALLOW_HW_E:
                value =  value | REGULATION_ALLOW_HW ;
                break;
           case REGULATION_FORCE_LOW_POWER_E:
                value =  value | REGULATION_FORCE_LOW_POWER ;
                break;
    }
  

    I2CWrite(VAPE_VOLTAGE_MANAGEMENT_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_vape_regulation
 *
 * RET  : Return the value of register 0xVapeVoltageManagement
 *
 * Notes : From register 0x402, bits 1:0
 *
 **************************************************************************/
unsigned char get_vape_regulation()
  {
    unsigned char value;


    /* 
     * 00: force Vape disabled 
     * 01: force enabled in HP mode 
     * 10: allows HW (internal VapeRequest signal) to control 
     * Vape supply if 
     * VapeRequestCtrl[1:0]=0x. Forced in HP mode if 
     * VapeRequestCtrl[1:0]=1x 
     * 11: force enable in LP mode 
     */ 
    value = (I2CRead(VAPE_VOLTAGE_MANAGEMENT_REG) & VAPE_REGULATION_MASK);
    return value;
  }


/***************************************************************************
 *
 * Function : set_vape_selection_control1
 *
 * IN   : param, a value to write to the regiter VapeVoltageManagement
 * OUT  : 
 *
 * RET  : Return the value of register 0xVapeVoltageManagement
 *
 * Notes : From register 0x402, bits 2:2
 *
 **************************************************************************/
unsigned char set_vape_selection_control1( enum ape_selection1 param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(VAPE_VOLTAGE_MANAGEMENT_REG);

    /* 
     * 0: Vape output voltage is defined by VapeSel1 register 
     * 1: Vape output voltage is defined by VapeSel2 register 
     */ 
    switch( param ){
        case V_APE_SEL2_REGISTER_E: 
           value = old_value | VAPE_SELECTION_CONTROL_1_MASK; 
           break;
        case V_APE_SEL1_REGISTER_E: 
           value = old_value & ~ VAPE_SELECTION_CONTROL_1_MASK;
           break;
    }
  

    I2CWrite(VAPE_VOLTAGE_MANAGEMENT_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_vape_selection_control1
 *
 * RET  : Return the value of register 0xVapeVoltageManagement
 *
 * Notes : From register 0x402, bits 2:2
 *
 **************************************************************************/
unsigned char get_vape_selection_control1()
  {
    unsigned char value;


    /* 
     * 0: Vape output voltage is defined by VapeSel1 register 
     * 1: Vape output voltage is defined by VapeSel2 register 
     */ 
    value = (I2CRead(VAPE_VOLTAGE_MANAGEMENT_REG) & VAPE_SELECTION_CONTROL_1_MASK) >> 2;
    return value;
  }


/***************************************************************************
 *
 * Function : set_vape_auto_mode
 *
 * IN   : param, a value to write to the regiter VapeVoltageManagement
 * OUT  : 
 *
 * RET  : Return the value of register 0xVapeVoltageManagement
 *
 * Notes : From register 0x402, bits 3:3
 *
 **************************************************************************/
unsigned char set_vape_auto_mode( enum auto_mode param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(VAPE_VOLTAGE_MANAGEMENT_REG);

    /* 
     * 0: Vape is not in AutoMode 
     * 1: Vape is in AutoMode 
     */ 
    switch( param ){
        case AUTO_MODE_ACTIVE_E: 
           value = old_value | VAPE_AUTO_MODE_MASK; 
           break;
        case AUTO_MODE_NOT_ACTIVE_E: 
           value = old_value & ~ VAPE_AUTO_MODE_MASK;
           break;
    }
  

    I2CWrite(VAPE_VOLTAGE_MANAGEMENT_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_vape_auto_mode
 *
 * RET  : Return the value of register 0xVapeVoltageManagement
 *
 * Notes : From register 0x402, bits 3:3
 *
 **************************************************************************/
unsigned char get_vape_auto_mode()
  {
    unsigned char value;


    /* 
     * 0: Vape is not in AutoMode 
     * 1: Vape is in AutoMode 
     */ 
    value = (I2CRead(VAPE_VOLTAGE_MANAGEMENT_REG) & VAPE_AUTO_MODE_MASK) >> 3;
    return value;
  }


/***************************************************************************
 *
 * Function : set_vape_pwm_mode_forced
 *
 * IN   : param, a value to write to the regiter VapeVoltageManagement
 * OUT  : 
 *
 * RET  : Return the value of register 0xVapeVoltageManagement
 *
 * Notes : From register 0x402, bits 4:4
 *
 **************************************************************************/
unsigned char set_vape_pwm_mode_forced( enum forced param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(VAPE_VOLTAGE_MANAGEMENT_REG);

    /* 
     * 0: inactive (Vape can be in PWM or PFM mode) 
     * 1: Vape is forced in PWM mode 
     */ 
    switch( param ){
        case FORCED_E: 
           value = old_value | VAPE_PWM_MODE_FORCED_MASK; 
           break;
        case INACTIVE_E: 
           value = old_value & ~ VAPE_PWM_MODE_FORCED_MASK;
           break;
    }
  

    I2CWrite(VAPE_VOLTAGE_MANAGEMENT_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_vape_pwm_mode_forced
 *
 * RET  : Return the value of register 0xVapeVoltageManagement
 *
 * Notes : From register 0x402, bits 4:4
 *
 **************************************************************************/
unsigned char get_vape_pwm_mode_forced()
  {
    unsigned char value;


    /* 
     * 0: inactive (Vape can be in PWM or PFM mode) 
     * 1: Vape is forced in PWM mode 
     */ 
    value = (I2CRead(VAPE_VOLTAGE_MANAGEMENT_REG) & VAPE_PWM_MODE_FORCED_MASK) >> 4;
    return value;
  }


/***************************************************************************
 *
 * Function : set_vape_selection_control2
 *
 * IN   : param, a value to write to the regiter VapeVoltageManagement
 * OUT  : 
 *
 * RET  : Return the value of register 0xVapeVoltageManagement
 *
 * Notes : From register 0x402, bits 5:5
 *
 **************************************************************************/
unsigned char set_vape_selection_control2( enum ape_selection2 param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(VAPE_VOLTAGE_MANAGEMENT_REG);

    /* 
     * 0: 'VapeSelCtrl1' bit select Vape output voltage 
     * 1: VapeSel3 register selects Vape output voltage 
     */ 
    switch( param ){
        case VAPE_SELECTED_BY_SEL3_E: 
           value = old_value | VAPE_SELECTION_CONTROL_2_MASK; 
           break;
        case VAPE_SELECTED_BY_CTRL1_E: 
           value = old_value & ~ VAPE_SELECTION_CONTROL_2_MASK;
           break;
    }
  

    I2CWrite(VAPE_VOLTAGE_MANAGEMENT_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_vape_selection_control2
 *
 * RET  : Return the value of register 0xVapeVoltageManagement
 *
 * Notes : From register 0x402, bits 5:5
 *
 **************************************************************************/
unsigned char get_vape_selection_control2()
  {
    unsigned char value;


    /* 
     * 0: 'VapeSelCtrl1' bit select Vape output voltage 
     * 1: VapeSel3 register selects Vape output voltage 
     */ 
    value = (I2CRead(VAPE_VOLTAGE_MANAGEMENT_REG) & VAPE_SELECTION_CONTROL_2_MASK) >> 5;
    return value;
  }


/***************************************************************************
 *
 * Function : set_vsmps1_regulation
 *
 * IN   : param, a value to write to the regiter Vsmps1VoltageManagement
 * OUT  : 
 *
 * RET  : Return the value of register 0xVsmps1VoltageManagement
 *
 * Notes : From register 0x403, bits 1:0
 *
 **************************************************************************/
unsigned char set_vsmps1_regulation( enum regulation param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(VSMPS_1_VOLTAGE_MANAGEMENT_REG);

    /* 
     * 00: force Vsmps1 disabled 
     * 01: force enabled in HP mode 
     * 10: allows HW (internal Vsmps1Request signal) to control 
     * Vsmps1 supply if 
     * Vsmps1RequestCtrl[1:0]=0x. Forced in HP mode if 
     * Vsmps1RequestCtrl[1:0]=1x 
     * 11: force enable in LP mode 
     */ 
  

     value =  old_value & ~VSMPS_1_REGULATION_MASK ;

    switch(  param ){

           case REGULATION_DISABLE_E:
                value =  value | REGULATION_DISABLE ;
                break;
           case REGULATION_FORCE_HP_MODE_E:
                value =  value | REGULATION_FORCE_HP_MODE ;
                break;
           case REGULATION_ALLOW_HW_E:
                value =  value | REGULATION_ALLOW_HW ;
                break;
           case REGULATION_FORCE_LOW_POWER_E:
                value =  value | REGULATION_FORCE_LOW_POWER ;
                break;
    }
  

    I2CWrite(VSMPS_1_VOLTAGE_MANAGEMENT_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_vsmps1_regulation
 *
 * RET  : Return the value of register 0xVsmps1VoltageManagement
 *
 * Notes : From register 0x403, bits 1:0
 *
 **************************************************************************/
unsigned char get_vsmps1_regulation()
  {
    unsigned char value;


    /* 
     * 00: force Vsmps1 disabled 
     * 01: force enabled in HP mode 
     * 10: allows HW (internal Vsmps1Request signal) to control 
     * Vsmps1 supply if 
     * Vsmps1RequestCtrl[1:0]=0x. Forced in HP mode if 
     * Vsmps1RequestCtrl[1:0]=1x 
     * 11: force enable in LP mode 
     */ 
    value = (I2CRead(VSMPS_1_VOLTAGE_MANAGEMENT_REG) & VSMPS_1_REGULATION_MASK);
    return value;
  }


/***************************************************************************
 *
 * Function : set_vsmps1_ouput_volage_select
 *
 * IN   : param, a value to write to the regiter Vsmps1VoltageManagement
 * OUT  : 
 *
 * RET  : Return the value of register 0xVsmps1VoltageManagement
 *
 * Notes : From register 0x403, bits 3:2
 *
 **************************************************************************/
unsigned char set_vsmps1_ouput_volage_select( enum selection param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(VSMPS_1_VOLTAGE_MANAGEMENT_REG);

    /* 
     * 00: Vsmps1 output voltage is defined by Vsmps1Sel1 
     * register 
     * 01: Vsmps1 output voltage is defined by Vsmps1Sel2 
     * register 
     * 1x: Vsmps1 output voltage is defined by Vsmps1Sel3 
     * register 
     */ 
  

     value =  old_value & ~VSMPS_1_OUPUT_VOLAGE_SELECT_MASK ;

    switch(  param ){

           case SEL1_REGISTER_E:
                value  = value  | (SEL1_REGISTER << 0x2);
                break;
           case SEL2_REGISTER_E:
                value  = value  | (SEL2_REGISTER << 0x2);
                break;
           case SEL3_REGISTER_E:
                value  = value  | (SEL3_REGISTER << 0x2);
                break;
    }
  

    I2CWrite(VSMPS_1_VOLTAGE_MANAGEMENT_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_vsmps1_ouput_volage_select
 *
 * RET  : Return the value of register 0xVsmps1VoltageManagement
 *
 * Notes : From register 0x403, bits 3:2
 *
 **************************************************************************/
unsigned char get_vsmps1_ouput_volage_select()
  {
    unsigned char value;


    /* 
     * 00: Vsmps1 output voltage is defined by Vsmps1Sel1 
     * register 
     * 01: Vsmps1 output voltage is defined by Vsmps1Sel2 
     * register 
     * 1x: Vsmps1 output voltage is defined by Vsmps1Sel3 
     * register 
     */ 
    value = (I2CRead(VSMPS_1_VOLTAGE_MANAGEMENT_REG) & VSMPS_1_OUPUT_VOLAGE_SELECT_MASK) >> 2;
    return value;
  }


/***************************************************************************
 *
 * Function : set_vsmps1_auto_mode
 *
 * IN   : param, a value to write to the regiter Vsmps1VoltageManagement
 * OUT  : 
 *
 * RET  : Return the value of register 0xVsmps1VoltageManagement
 *
 * Notes : From register 0x403, bits 4:4
 *
 **************************************************************************/
unsigned char set_vsmps1_auto_mode( enum auto_mode param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(VSMPS_1_VOLTAGE_MANAGEMENT_REG);

    /* 
     * 0: Vape is not in AutoMode 
     * 1: Vape is in AutoMode 
     */ 
    switch( param ){
        case AUTO_MODE_ACTIVE_E: 
           value = old_value | VSMPS_1_AUTO_MODE_MASK; 
           break;
        case AUTO_MODE_NOT_ACTIVE_E: 
           value = old_value & ~ VSMPS_1_AUTO_MODE_MASK;
           break;
    }
  

    I2CWrite(VSMPS_1_VOLTAGE_MANAGEMENT_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_vsmps1_auto_mode
 *
 * RET  : Return the value of register 0xVsmps1VoltageManagement
 *
 * Notes : From register 0x403, bits 4:4
 *
 **************************************************************************/
unsigned char get_vsmps1_auto_mode()
  {
    unsigned char value;


    /* 
     * 0: Vape is not in AutoMode 
     * 1: Vape is in AutoMode 
     */ 
    value = (I2CRead(VSMPS_1_VOLTAGE_MANAGEMENT_REG) & VSMPS_1_AUTO_MODE_MASK) >> 4;
    return value;
  }


/***************************************************************************
 *
 * Function : set_vsmps1_voltage_pwm_mode
 *
 * IN   : param, a value to write to the regiter Vsmps1VoltageManagement
 * OUT  : 
 *
 * RET  : Return the value of register 0xVsmps1VoltageManagement
 *
 * Notes : From register 0x403, bits 5:5
 *
 **************************************************************************/
unsigned char set_vsmps1_voltage_pwm_mode( enum forced param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(VSMPS_1_VOLTAGE_MANAGEMENT_REG);

    /* 
     * 0: inactive (Vsmps1 can be in PWM or PFM mode) 
     * 1: Vsmps1 is forced in PWM mode 
     */ 
    switch( param ){
        case FORCED_E: 
           value = old_value | VSMPS_1_VOLTAGE_PWM_MODE_MASK; 
           break;
        case INACTIVE_E: 
           value = old_value & ~ VSMPS_1_VOLTAGE_PWM_MODE_MASK;
           break;
    }
  

    I2CWrite(VSMPS_1_VOLTAGE_MANAGEMENT_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_vsmps1_voltage_pwm_mode
 *
 * RET  : Return the value of register 0xVsmps1VoltageManagement
 *
 * Notes : From register 0x403, bits 5:5
 *
 **************************************************************************/
unsigned char get_vsmps1_voltage_pwm_mode()
  {
    unsigned char value;


    /* 
     * 0: inactive (Vsmps1 can be in PWM or PFM mode) 
     * 1: Vsmps1 is forced in PWM mode 
     */ 
    value = (I2CRead(VSMPS_1_VOLTAGE_MANAGEMENT_REG) & VSMPS_1_VOLTAGE_PWM_MODE_MASK) >> 5;
    return value;
  }


/***************************************************************************
 *
 * Function : set_vsmps2_regulation
 *
 * IN   : param, a value to write to the regiter Vsmps2VoltageManagement
 * OUT  : 
 *
 * RET  : Return the value of register 0xVsmps2VoltageManagement
 *
 * Notes : From register 0x404, bits 1:0
 *
 **************************************************************************/
unsigned char set_vsmps2_regulation( enum regulation param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(VSMPS_2_VOLTAGE_MANAGEMENT_REG);

    /* 
     * 00: force Vsmps2 disabled 
     * 01: force enabled in HP mode 
     * 10: allows HW (internal Vsmps2Request signal) to control 
     * Vsmps2 supply if 
     * Vsmps2RequestCtrl[1:0]=0x. Forced in HP mode if 
     * Vsmps2RequestCtrl[1:0]=1x 
     * 11: force enable in LP mode 
     */ 
  

     value =  old_value & ~VSMPS_2_REGULATION_MASK ;

    switch(  param ){

           case REGULATION_DISABLE_E:
                value =  value | REGULATION_DISABLE ;
                break;
           case REGULATION_FORCE_HP_MODE_E:
                value =  value | REGULATION_FORCE_HP_MODE ;
                break;
           case REGULATION_ALLOW_HW_E:
                value =  value | REGULATION_ALLOW_HW ;
                break;
           case REGULATION_FORCE_LOW_POWER_E:
                value =  value | REGULATION_FORCE_LOW_POWER ;
                break;
    }
  

    I2CWrite(VSMPS_2_VOLTAGE_MANAGEMENT_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_vsmps2_regulation
 *
 * RET  : Return the value of register 0xVsmps2VoltageManagement
 *
 * Notes : From register 0x404, bits 1:0
 *
 **************************************************************************/
unsigned char get_vsmps2_regulation()
  {
    unsigned char value;


    /* 
     * 00: force Vsmps2 disabled 
     * 01: force enabled in HP mode 
     * 10: allows HW (internal Vsmps2Request signal) to control 
     * Vsmps2 supply if 
     * Vsmps2RequestCtrl[1:0]=0x. Forced in HP mode if 
     * Vsmps2RequestCtrl[1:0]=1x 
     * 11: force enable in LP mode 
     */ 
    value = (I2CRead(VSMPS_2_VOLTAGE_MANAGEMENT_REG) & VSMPS_2_REGULATION_MASK);
    return value;
  }


/***************************************************************************
 *
 * Function : set_vsmps2_ouput_volage_select
 *
 * IN   : param, a value to write to the regiter Vsmps2VoltageManagement
 * OUT  : 
 *
 * RET  : Return the value of register 0xVsmps2VoltageManagement
 *
 * Notes : From register 0x404, bits 3:2
 *
 **************************************************************************/
unsigned char set_vsmps2_ouput_volage_select( enum selection param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(VSMPS_2_VOLTAGE_MANAGEMENT_REG);

    /* 
     * 00: Vsmps2 output voltage is defined by Vsmps2Sel1 
     * register 
     * 01: Vsmps2 output voltage is defined by Vsmps2Sel2 
     * register 
     * 1x: Vsmps2 output voltage is defined by Vsmps2Sel3 
     * register 
     */ 
  

     value =  old_value & ~VSMPS_2_OUPUT_VOLAGE_SELECT_MASK ;

    switch(  param ){

           case SEL1_REGISTER_E:
                value  = value  | (SEL1_REGISTER << 0x2);
                break;
           case SEL2_REGISTER_E:
                value  = value  | (SEL2_REGISTER << 0x2);
                break;
           case SEL3_REGISTER_E:
                value  = value  | (SEL3_REGISTER << 0x2);
                break;
    }
  

    I2CWrite(VSMPS_2_VOLTAGE_MANAGEMENT_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_vsmps2_ouput_volage_select
 *
 * RET  : Return the value of register 0xVsmps2VoltageManagement
 *
 * Notes : From register 0x404, bits 3:2
 *
 **************************************************************************/
unsigned char get_vsmps2_ouput_volage_select()
  {
    unsigned char value;


    /* 
     * 00: Vsmps2 output voltage is defined by Vsmps2Sel1 
     * register 
     * 01: Vsmps2 output voltage is defined by Vsmps2Sel2 
     * register 
     * 1x: Vsmps2 output voltage is defined by Vsmps2Sel3 
     * register 
     */ 
    value = (I2CRead(VSMPS_2_VOLTAGE_MANAGEMENT_REG) & VSMPS_2_OUPUT_VOLAGE_SELECT_MASK) >> 2;
    return value;
  }


/***************************************************************************
 *
 * Function : set_vsmps2_auto_mode
 *
 * IN   : param, a value to write to the regiter Vsmps2VoltageManagement
 * OUT  : 
 *
 * RET  : Return the value of register 0xVsmps2VoltageManagement
 *
 * Notes : From register 0x404, bits 4:4
 *
 **************************************************************************/
unsigned char set_vsmps2_auto_mode( enum auto_mode param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(VSMPS_2_VOLTAGE_MANAGEMENT_REG);

    /* 
     * 0: Vape is not in AutoMode 
     * 1: Vape is in AutoMode 
     */ 
    switch( param ){
        case AUTO_MODE_ACTIVE_E: 
           value = old_value | VSMPS_2_AUTO_MODE_MASK; 
           break;
        case AUTO_MODE_NOT_ACTIVE_E: 
           value = old_value & ~ VSMPS_2_AUTO_MODE_MASK;
           break;
    }
  

    I2CWrite(VSMPS_2_VOLTAGE_MANAGEMENT_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_vsmps2_auto_mode
 *
 * RET  : Return the value of register 0xVsmps2VoltageManagement
 *
 * Notes : From register 0x404, bits 4:4
 *
 **************************************************************************/
unsigned char get_vsmps2_auto_mode()
  {
    unsigned char value;


    /* 
     * 0: Vape is not in AutoMode 
     * 1: Vape is in AutoMode 
     */ 
    value = (I2CRead(VSMPS_2_VOLTAGE_MANAGEMENT_REG) & VSMPS_2_AUTO_MODE_MASK) >> 4;
    return value;
  }


/***************************************************************************
 *
 * Function : set_vsmps2_voltage_pwm_mode
 *
 * IN   : param, a value to write to the regiter Vsmps2VoltageManagement
 * OUT  : 
 *
 * RET  : Return the value of register 0xVsmps2VoltageManagement
 *
 * Notes : From register 0x404, bits 5:5
 *
 **************************************************************************/
unsigned char set_vsmps2_voltage_pwm_mode( enum forced param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(VSMPS_2_VOLTAGE_MANAGEMENT_REG);

    /* 
     * 0: inactive (Vsmps2 can be in PWM or PFM mode) 
     * 1: Vsmps2 is forced in PWM mode 
     */ 
    switch( param ){
        case FORCED_E: 
           value = old_value | VSMPS_2_VOLTAGE_PWM_MODE_MASK; 
           break;
        case INACTIVE_E: 
           value = old_value & ~ VSMPS_2_VOLTAGE_PWM_MODE_MASK;
           break;
    }
  

    I2CWrite(VSMPS_2_VOLTAGE_MANAGEMENT_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_vsmps2_voltage_pwm_mode
 *
 * RET  : Return the value of register 0xVsmps2VoltageManagement
 *
 * Notes : From register 0x404, bits 5:5
 *
 **************************************************************************/
unsigned char get_vsmps2_voltage_pwm_mode()
  {
    unsigned char value;


    /* 
     * 0: inactive (Vsmps2 can be in PWM or PFM mode) 
     * 1: Vsmps2 is forced in PWM mode 
     */ 
    value = (I2CRead(VSMPS_2_VOLTAGE_MANAGEMENT_REG) & VSMPS_2_VOLTAGE_PWM_MODE_MASK) >> 5;
    return value;
  }


/***************************************************************************
 *
 * Function : set_vsmps3_regulation
 *
 * IN   : param, a value to write to the regiter Vsmps3VoltageManagement
 * OUT  : 
 *
 * RET  : Return the value of register 0xVsmps3VoltageManagement
 *
 * Notes : From register 0x405, bits 1:0
 *
 **************************************************************************/
unsigned char set_vsmps3_regulation( enum regulation param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(VSMPS_3_VOLTAGE_MANAGEMENT_REG);

    /* 
     * 00: force Vsmps3 disabled 
     * 01: force enabled in HP mode 
     * 10: allows HW (internal Vsmps3Request signal) to control 
     * Vsmps3 supply if 
     * Vsmps3RequestCtrl[1:0]=0x. Forced in HP mode if 
     * Vsmps3RequestCtrl[1:0]=1x 
     * 11: force enable in LP mode 
     */ 
  

     value =  old_value & ~VSMPS_3_REGULATION_MASK ;

    switch(  param ){

           case REGULATION_DISABLE_E:
                value =  value | REGULATION_DISABLE ;
                break;
           case REGULATION_FORCE_HP_MODE_E:
                value =  value | REGULATION_FORCE_HP_MODE ;
                break;
           case REGULATION_ALLOW_HW_E:
                value =  value | REGULATION_ALLOW_HW ;
                break;
           case REGULATION_FORCE_LOW_POWER_E:
                value =  value | REGULATION_FORCE_LOW_POWER ;
                break;
    }
  

    I2CWrite(VSMPS_3_VOLTAGE_MANAGEMENT_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_vsmps3_regulation
 *
 * RET  : Return the value of register 0xVsmps3VoltageManagement
 *
 * Notes : From register 0x405, bits 1:0
 *
 **************************************************************************/
unsigned char get_vsmps3_regulation()
  {
    unsigned char value;


    /* 
     * 00: force Vsmps3 disabled 
     * 01: force enabled in HP mode 
     * 10: allows HW (internal Vsmps3Request signal) to control 
     * Vsmps3 supply if 
     * Vsmps3RequestCtrl[1:0]=0x. Forced in HP mode if 
     * Vsmps3RequestCtrl[1:0]=1x 
     * 11: force enable in LP mode 
     */ 
    value = (I2CRead(VSMPS_3_VOLTAGE_MANAGEMENT_REG) & VSMPS_3_REGULATION_MASK);
    return value;
  }


/***************************************************************************
 *
 * Function : set_vsmps3_ouput_volage_select
 *
 * IN   : param, a value to write to the regiter Vsmps3VoltageManagement
 * OUT  : 
 *
 * RET  : Return the value of register 0xVsmps3VoltageManagement
 *
 * Notes : From register 0x405, bits 3:2
 *
 **************************************************************************/
unsigned char set_vsmps3_ouput_volage_select( enum selection param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(VSMPS_3_VOLTAGE_MANAGEMENT_REG);

    /* 
     * 00: Vsmps3 output voltage is defined by Vsmps3Sel1 
     * register 
     * 01: Vsmps3 output voltage is defined by Vsmps3Sel2 
     * register 
     * 1x: Vsmps3 output voltage is defined by Vsmps3Sel3 
     * register 
     */ 
  

     value =  old_value & ~VSMPS_3_OUPUT_VOLAGE_SELECT_MASK ;

    switch(  param ){

           case SEL1_REGISTER_E:
                value  = value  | (SEL1_REGISTER << 0x2);
                break;
           case SEL2_REGISTER_E:
                value  = value  | (SEL2_REGISTER << 0x2);
                break;
           case SEL3_REGISTER_E:
                value  = value  | (SEL3_REGISTER << 0x2);
                break;
    }
  

    I2CWrite(VSMPS_3_VOLTAGE_MANAGEMENT_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_vsmps3_ouput_volage_select
 *
 * RET  : Return the value of register 0xVsmps3VoltageManagement
 *
 * Notes : From register 0x405, bits 3:2
 *
 **************************************************************************/
unsigned char get_vsmps3_ouput_volage_select()
  {
    unsigned char value;


    /* 
     * 00: Vsmps3 output voltage is defined by Vsmps3Sel1 
     * register 
     * 01: Vsmps3 output voltage is defined by Vsmps3Sel2 
     * register 
     * 1x: Vsmps3 output voltage is defined by Vsmps3Sel3 
     * register 
     */ 
    value = (I2CRead(VSMPS_3_VOLTAGE_MANAGEMENT_REG) & VSMPS_3_OUPUT_VOLAGE_SELECT_MASK) >> 2;
    return value;
  }


/***************************************************************************
 *
 * Function : set_vsmps3_auto_mode
 *
 * IN   : param, a value to write to the regiter Vsmps3VoltageManagement
 * OUT  : 
 *
 * RET  : Return the value of register 0xVsmps3VoltageManagement
 *
 * Notes : From register 0x405, bits 4:4
 *
 **************************************************************************/
unsigned char set_vsmps3_auto_mode( enum auto_mode param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(VSMPS_3_VOLTAGE_MANAGEMENT_REG);

    /* 
     * 0: Vape is not in AutoMode 
     * 1: Vape is in AutoMode 
     */ 
    switch( param ){
        case AUTO_MODE_ACTIVE_E: 
           value = old_value | VSMPS_3_AUTO_MODE_MASK; 
           break;
        case AUTO_MODE_NOT_ACTIVE_E: 
           value = old_value & ~ VSMPS_3_AUTO_MODE_MASK;
           break;
    }
  

    I2CWrite(VSMPS_3_VOLTAGE_MANAGEMENT_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_vsmps3_auto_mode
 *
 * RET  : Return the value of register 0xVsmps3VoltageManagement
 *
 * Notes : From register 0x405, bits 4:4
 *
 **************************************************************************/
unsigned char get_vsmps3_auto_mode()
  {
    unsigned char value;


    /* 
     * 0: Vape is not in AutoMode 
     * 1: Vape is in AutoMode 
     */ 
    value = (I2CRead(VSMPS_3_VOLTAGE_MANAGEMENT_REG) & VSMPS_3_AUTO_MODE_MASK) >> 4;
    return value;
  }


/***************************************************************************
 *
 * Function : set_vsmps3_voltage_pwm_mode
 *
 * IN   : param, a value to write to the regiter Vsmps3VoltageManagement
 * OUT  : 
 *
 * RET  : Return the value of register 0xVsmps3VoltageManagement
 *
 * Notes : From register 0x405, bits 5:5
 *
 **************************************************************************/
unsigned char set_vsmps3_voltage_pwm_mode( enum forced param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(VSMPS_3_VOLTAGE_MANAGEMENT_REG);

    /* 
     * 0: inactive (Vsmps3 can be in PWM or PFM mode) 
     * 1: Vsmps3 is forced in PWM mode 
     */ 
    switch( param ){
        case FORCED_E: 
           value = old_value | VSMPS_3_VOLTAGE_PWM_MODE_MASK; 
           break;
        case INACTIVE_E: 
           value = old_value & ~ VSMPS_3_VOLTAGE_PWM_MODE_MASK;
           break;
    }
  

    I2CWrite(VSMPS_3_VOLTAGE_MANAGEMENT_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_vsmps3_voltage_pwm_mode
 *
 * RET  : Return the value of register 0xVsmps3VoltageManagement
 *
 * Notes : From register 0x405, bits 5:5
 *
 **************************************************************************/
unsigned char get_vsmps3_voltage_pwm_mode()
  {
    unsigned char value;


    /* 
     * 0: inactive (Vsmps3 can be in PWM or PFM mode) 
     * 1: Vsmps3 is forced in PWM mode 
     */ 
    value = (I2CRead(VSMPS_3_VOLTAGE_MANAGEMENT_REG) & VSMPS_3_VOLTAGE_PWM_MODE_MASK) >> 5;
    return value;
  }


/***************************************************************************
 *
 * Function : set_vpll_regulation
 *
 * IN   : param, a value to write to the regiter VanaVoltageManagement
 * OUT  : 
 *
 * RET  : Return the value of register 0xVanaVoltageManagement
 *
 * Notes : From register 0x406, bits 1:0
 *
 **************************************************************************/
unsigned char set_vpll_regulation( enum regulation param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(VANA_VOLTAGE_MANAGEMENT_REG);

    /* 
     * 00: force Vpll disabled 
     * 01: force enabled in HP mode 
     * 10: allows HW (internal VpllRequest signal) to control 
     * Vpll supply if 
     * VpllRequestCtrl[1:0]=0x. Forced in HP mode if 
     * VpllRequestCtrl[1:0]=1x 
     * 11: force enable in LP mode 
     */ 
  

     value =  old_value & ~VPLL_REGULATION_MASK ;

    switch(  param ){

           case REGULATION_DISABLE_E:
                value =  value | REGULATION_DISABLE ;
                break;
           case REGULATION_FORCE_HP_MODE_E:
                value =  value | REGULATION_FORCE_HP_MODE ;
                break;
           case REGULATION_ALLOW_HW_E:
                value =  value | REGULATION_ALLOW_HW ;
                break;
           case REGULATION_FORCE_LOW_POWER_E:
                value =  value | REGULATION_FORCE_LOW_POWER ;
                break;
    }
  

    I2CWrite(VANA_VOLTAGE_MANAGEMENT_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_vpll_regulation
 *
 * RET  : Return the value of register 0xVanaVoltageManagement
 *
 * Notes : From register 0x406, bits 1:0
 *
 **************************************************************************/
unsigned char get_vpll_regulation()
  {
    unsigned char value;


    /* 
     * 00: force Vpll disabled 
     * 01: force enabled in HP mode 
     * 10: allows HW (internal VpllRequest signal) to control 
     * Vpll supply if 
     * VpllRequestCtrl[1:0]=0x. Forced in HP mode if 
     * VpllRequestCtrl[1:0]=1x 
     * 11: force enable in LP mode 
     */ 
    value = (I2CRead(VANA_VOLTAGE_MANAGEMENT_REG) & VPLL_REGULATION_MASK);
    return value;
  }


/***************************************************************************
 *
 * Function : set_vana_regulation
 *
 * IN   : param, a value to write to the regiter VanaVoltageManagement
 * OUT  : 
 *
 * RET  : Return the value of register 0xVanaVoltageManagement
 *
 * Notes : From register 0x406, bits 3:2
 *
 **************************************************************************/
unsigned char set_vana_regulation( enum regulation param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(VANA_VOLTAGE_MANAGEMENT_REG);

    /* 
     * 00: force Vana disabled 
     * 01: force enabled in HP mode 
     * 10: allows HW (internal VanaRequest signal) to control 
     * Vana supply if 
     * VanaRequestCtrl[1:0]=0x. Forced in HP mode if 
     * VanaRequestCtrl[1:0]=1x 
     * 11: force enable in LP mode 
     */ 
  

     value =  old_value & ~VANA_REGULATION_MASK ;

    switch(  param ){

           case REGULATION_DISABLE_E:
                value  = value  | (REGULATION_DISABLE << 0x2);
                break;
           case REGULATION_FORCE_HP_MODE_E:
                value  = value  | (REGULATION_FORCE_HP_MODE << 0x2);
                break;
           case REGULATION_ALLOW_HW_E:
                value  = value  | (REGULATION_ALLOW_HW << 0x2);
                break;
           case REGULATION_FORCE_LOW_POWER_E:
                value  = value  | (REGULATION_FORCE_LOW_POWER << 0x2);
                break;
    }
  

    I2CWrite(VANA_VOLTAGE_MANAGEMENT_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_vana_regulation
 *
 * RET  : Return the value of register 0xVanaVoltageManagement
 *
 * Notes : From register 0x406, bits 3:2
 *
 **************************************************************************/
unsigned char get_vana_regulation()
  {
    unsigned char value;


    /* 
     * 00: force Vana disabled 
     * 01: force enabled in HP mode 
     * 10: allows HW (internal VanaRequest signal) to control 
     * Vana supply if 
     * VanaRequestCtrl[1:0]=0x. Forced in HP mode if 
     * VanaRequestCtrl[1:0]=1x 
     * 11: force enable in LP mode 
     */ 
    value = (I2CRead(VANA_VOLTAGE_MANAGEMENT_REG) & VANA_REGULATION_MASK) >> 2;
    return value;
  }


/***************************************************************************
 *
 * Function : set_vref_ddr
 *
 * IN   : param, a value to write to the regiter VrefDdrVoltageManagement
 * OUT  : 
 *
 * RET  : Return the value of register 0xVrefDdrVoltageManagement
 *
 * Notes : From register 0x407, bits 0:0
 *
 **************************************************************************/
unsigned char set_vref_ddr( enum vref_ddr_enable param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(VREF_DDR_VOLTAGE_MANAGEMENT_REG);

    /* 
     * 0: disable VrefDDR (output grounded) 
     * 1: enable VrefDDR 
     */ 
    switch( param ){
        case VREF_DDR_ENABLE_E: 
           value = old_value | VREF_DDR_MASK; 
           break;
        case VREF_DDR_DISABLE_E: 
           value = old_value & ~ VREF_DDR_MASK;
           break;
    }
  

    I2CWrite(VREF_DDR_VOLTAGE_MANAGEMENT_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_vref_ddr
 *
 * RET  : Return the value of register 0xVrefDdrVoltageManagement
 *
 * Notes : From register 0x407, bits 0:0
 *
 **************************************************************************/
unsigned char get_vref_ddr()
  {
    unsigned char value;


    /* 
     * 0: disable VrefDDR (output grounded) 
     * 1: enable VrefDDR 
     */ 
    value = (I2CRead(VREF_DDR_VOLTAGE_MANAGEMENT_REG) & VREF_DDR_MASK);
    return value;
  }


/***************************************************************************
 *
 * Function : set_vref_ddr_sleep_mode
 *
 * IN   : param, a value to write to the regiter VrefDdrVoltageManagement
 * OUT  : 
 *
 * RET  : Return the value of register 0xVrefDdrVoltageManagement
 *
 * Notes : From register 0x407, bits 1:1
 *
 **************************************************************************/
unsigned char set_vref_ddr_sleep_mode( enum sleep_mode param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(VREF_DDR_VOLTAGE_MANAGEMENT_REG);

    /* 
     * 0: inactive 
     * 1: enable 50KOhms pulldown 
     */ 
    switch( param ){
        case SLEEP_MODE_ENABLE_E: 
           value = old_value | VREF_DDR_SLEEP_MODE_MASK; 
           break;
        case SLEEP_MODE_INACTIVE_E: 
           value = old_value & ~ VREF_DDR_SLEEP_MODE_MASK;
           break;
    }
  

    I2CWrite(VREF_DDR_VOLTAGE_MANAGEMENT_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_vref_ddr_sleep_mode
 *
 * RET  : Return the value of register 0xVrefDdrVoltageManagement
 *
 * Notes : From register 0x407, bits 1:1
 *
 **************************************************************************/
unsigned char get_vref_ddr_sleep_mode()
  {
    unsigned char value;


    /* 
     * 0: inactive 
     * 1: enable 50KOhms pulldown 
     */ 
    value = (I2CRead(VREF_DDR_VOLTAGE_MANAGEMENT_REG) & VREF_DDR_SLEEP_MODE_MASK) >> 1;
    return value;
  }


/***************************************************************************
 *
 * Function : set_vext_suppply1_regulation
 *
 * IN   : param, a value to write to the regiter VextSuppply1VoltageManagement
 * OUT  : 
 *
 * RET  : Return the value of register 0xVextSuppply1VoltageManagement
 *
 * Notes : From register 0x408, bits 1:0
 *
 **************************************************************************/
unsigned char set_vext_suppply1_regulation( enum regulation param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(VEXT_SUPPPLY_1_VOLTAGE_MANAGEMENT_REG);

    /* 
     * 00: force VextSuppply1 disabled 
     * 01: force enabled in HP mode 
     * 10: allows HW (internal VextSuppply1Request signal) to 
     * control VextSuppply1 supply if 
     * VextSuppply1RequestCtrl[1:0]=0x. Forced in HP mode if 
     * VextSuppply1RequestCtrl[1:0]=1x 
     * 11: force enable in LP mode 
     */ 
  

     value =  old_value & ~VEXT_SUPPPLY_1_REGULATION_MASK ;

    switch(  param ){

           case REGULATION_DISABLE_E:
                value =  value | REGULATION_DISABLE ;
                break;
           case REGULATION_FORCE_HP_MODE_E:
                value =  value | REGULATION_FORCE_HP_MODE ;
                break;
           case REGULATION_ALLOW_HW_E:
                value =  value | REGULATION_ALLOW_HW ;
                break;
           case REGULATION_FORCE_LOW_POWER_E:
                value =  value | REGULATION_FORCE_LOW_POWER ;
                break;
    }
  

    I2CWrite(VEXT_SUPPPLY_1_VOLTAGE_MANAGEMENT_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_vext_suppply1_regulation
 *
 * RET  : Return the value of register 0xVextSuppply1VoltageManagement
 *
 * Notes : From register 0x408, bits 1:0
 *
 **************************************************************************/
unsigned char get_vext_suppply1_regulation()
  {
    unsigned char value;


    /* 
     * 00: force VextSuppply1 disabled 
     * 01: force enabled in HP mode 
     * 10: allows HW (internal VextSuppply1Request signal) to 
     * control VextSuppply1 supply if 
     * VextSuppply1RequestCtrl[1:0]=0x. Forced in HP mode if 
     * VextSuppply1RequestCtrl[1:0]=1x 
     * 11: force enable in LP mode 
     */ 
    value = (I2CRead(VEXT_SUPPPLY_1_VOLTAGE_MANAGEMENT_REG) & VEXT_SUPPPLY_1_REGULATION_MASK);
    return value;
  }


/***************************************************************************
 *
 * Function : set_vext_suppply2_regulation
 *
 * IN   : param, a value to write to the regiter VextSuppply1VoltageManagement
 * OUT  : 
 *
 * RET  : Return the value of register 0xVextSuppply1VoltageManagement
 *
 * Notes : From register 0x408, bits 3:2
 *
 **************************************************************************/
unsigned char set_vext_suppply2_regulation( enum regulation param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(VEXT_SUPPPLY_1_VOLTAGE_MANAGEMENT_REG);

    /* 
     * 00: force VextSuppply2 disabled 
     * 01: force enabled in HP mode 
     * 10: allows HW (internal VextSuppply2Request signal) to 
     * control VextSuppply2 supply if 
     * VextSuppply2RequestCtrl[1:0]=0x. Forced in HP mode if 
     * VextSuppply2RequestCtrl[1:0]=1x 
     * 11: force enable in LP mode 
     */ 
  

     value =  old_value & ~VEXT_SUPPPLY_2_REGULATION_MASK ;

    switch(  param ){

           case REGULATION_DISABLE_E:
                value  = value  | (REGULATION_DISABLE << 0x2);
                break;
           case REGULATION_FORCE_HP_MODE_E:
                value  = value  | (REGULATION_FORCE_HP_MODE << 0x2);
                break;
           case REGULATION_ALLOW_HW_E:
                value  = value  | (REGULATION_ALLOW_HW << 0x2);
                break;
           case REGULATION_FORCE_LOW_POWER_E:
                value  = value  | (REGULATION_FORCE_LOW_POWER << 0x2);
                break;
    }
  

    I2CWrite(VEXT_SUPPPLY_1_VOLTAGE_MANAGEMENT_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_vext_suppply2_regulation
 *
 * RET  : Return the value of register 0xVextSuppply1VoltageManagement
 *
 * Notes : From register 0x408, bits 3:2
 *
 **************************************************************************/
unsigned char get_vext_suppply2_regulation()
  {
    unsigned char value;


    /* 
     * 00: force VextSuppply2 disabled 
     * 01: force enabled in HP mode 
     * 10: allows HW (internal VextSuppply2Request signal) to 
     * control VextSuppply2 supply if 
     * VextSuppply2RequestCtrl[1:0]=0x. Forced in HP mode if 
     * VextSuppply2RequestCtrl[1:0]=1x 
     * 11: force enable in LP mode 
     */ 
    value = (I2CRead(VEXT_SUPPPLY_1_VOLTAGE_MANAGEMENT_REG) & VEXT_SUPPPLY_2_REGULATION_MASK) >> 2;
    return value;
  }


/***************************************************************************
 *
 * Function : set_vext_suppply3_regulation
 *
 * IN   : param, a value to write to the regiter VextSuppply1VoltageManagement
 * OUT  : 
 *
 * RET  : Return the value of register 0xVextSuppply1VoltageManagement
 *
 * Notes : From register 0x408, bits 5:4
 *
 **************************************************************************/
unsigned char set_vext_suppply3_regulation( enum regulation param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(VEXT_SUPPPLY_1_VOLTAGE_MANAGEMENT_REG);

    /* 
     * 00: force VextSuppply3 disabled 
     * 01: force enabled in HP mode 
     * 10: allows HW (internal VextSuppply3Request signal) to 
     * control VextSuppply3 supply if 
     * VextSuppply3RequestCtrl[1:0]=0x. Forced in HP mode if 
     * VextSuppply3RequestCtrl[1:0]=1x 
     * 11: force enable in LP mode 
     */ 
  

     value =  old_value & ~VEXT_SUPPPLY_3_REGULATION_MASK ;

    switch(  param ){

           case REGULATION_DISABLE_E:
                value  = value  | (REGULATION_DISABLE << 0x4);
                break;
           case REGULATION_FORCE_HP_MODE_E:
                value  = value  | (REGULATION_FORCE_HP_MODE << 0x4);
                break;
           case REGULATION_ALLOW_HW_E:
                value  = value  | (REGULATION_ALLOW_HW << 0x4);
                break;
           case REGULATION_FORCE_LOW_POWER_E:
                value  = value  | (REGULATION_FORCE_LOW_POWER << 0x4);
                break;
    }
  

    I2CWrite(VEXT_SUPPPLY_1_VOLTAGE_MANAGEMENT_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_vext_suppply3_regulation
 *
 * RET  : Return the value of register 0xVextSuppply1VoltageManagement
 *
 * Notes : From register 0x408, bits 5:4
 *
 **************************************************************************/
unsigned char get_vext_suppply3_regulation()
  {
    unsigned char value;


    /* 
     * 00: force VextSuppply3 disabled 
     * 01: force enabled in HP mode 
     * 10: allows HW (internal VextSuppply3Request signal) to 
     * control VextSuppply3 supply if 
     * VextSuppply3RequestCtrl[1:0]=0x. Forced in HP mode if 
     * VextSuppply3RequestCtrl[1:0]=1x 
     * 11: force enable in LP mode 
     */ 
    value = (I2CRead(VEXT_SUPPPLY_1_VOLTAGE_MANAGEMENT_REG) & VEXT_SUPPPLY_3_REGULATION_MASK) >> 4;
    return value;
  }


/***************************************************************************
 *
 * Function : set_external_smps_by_pass_ext_supply2
 *
 * IN   : param, a value to write to the regiter VextSuppply1VoltageManagement
 * OUT  : 
 *
 * RET  : Return the value of register 0xVextSuppply1VoltageManagement
 *
 * Notes : From register 0x408, bits 6:6
 *
 **************************************************************************/
unsigned char set_external_smps_by_pass_ext_supply2( enum by_pass param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(VEXT_SUPPPLY_1_VOLTAGE_MANAGEMENT_REG);

    /* 
     * External Smps is with ByPass mode ExtSupply2 
     */ 
    switch( param ){
        case WITH_BYPASS_E: 
           value = old_value | EXTERNAL_SMPS_BY_PASS_EXT_SUPPLY_2_MASK; 
           break;
        case WITHOUT_BYPASS_E: 
           value = old_value & ~ EXTERNAL_SMPS_BY_PASS_EXT_SUPPLY_2_MASK;
           break;
    }
  

    I2CWrite(VEXT_SUPPPLY_1_VOLTAGE_MANAGEMENT_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_external_smps_by_pass_ext_supply2
 *
 * RET  : Return the value of register 0xVextSuppply1VoltageManagement
 *
 * Notes : From register 0x408, bits 6:6
 *
 **************************************************************************/
unsigned char get_external_smps_by_pass_ext_supply2()
  {
    unsigned char value;


    /* 
     * External Smps is with ByPass mode ExtSupply2 
     */ 
    value = (I2CRead(VEXT_SUPPPLY_1_VOLTAGE_MANAGEMENT_REG) & EXTERNAL_SMPS_BY_PASS_EXT_SUPPLY_2_MASK) >> 6;
    return value;
  }


/***************************************************************************
 *
 * Function : set_external_smps_by_pass_ext_supply3
 *
 * IN   : param, a value to write to the regiter VextSuppply1VoltageManagement
 * OUT  : 
 *
 * RET  : Return the value of register 0xVextSuppply1VoltageManagement
 *
 * Notes : From register 0x408, bits 7:7
 *
 **************************************************************************/
unsigned char set_external_smps_by_pass_ext_supply3( enum by_pass param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(VEXT_SUPPPLY_1_VOLTAGE_MANAGEMENT_REG);

    /* 
     * External Smps is with ByPass mode ExtSupply3 
     */ 
    switch( param ){
        case WITH_BYPASS_E: 
           value = old_value | EXTERNAL_SMPS_BY_PASS_EXT_SUPPLY_3_MASK; 
           break;
        case WITHOUT_BYPASS_E: 
           value = old_value & ~ EXTERNAL_SMPS_BY_PASS_EXT_SUPPLY_3_MASK;
           break;
    }
  

    I2CWrite(VEXT_SUPPPLY_1_VOLTAGE_MANAGEMENT_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_external_smps_by_pass_ext_supply3
 *
 * RET  : Return the value of register 0xVextSuppply1VoltageManagement
 *
 * Notes : From register 0x408, bits 7:7
 *
 **************************************************************************/
unsigned char get_external_smps_by_pass_ext_supply3()
  {
    unsigned char value;


    /* 
     * External Smps is with ByPass mode ExtSupply3 
     */ 
    value = (I2CRead(VEXT_SUPPPLY_1_VOLTAGE_MANAGEMENT_REG) & EXTERNAL_SMPS_BY_PASS_EXT_SUPPLY_3_MASK) >> 7;
    return value;
  }


/***************************************************************************
 *
 * Function : set_vaux1_regulation
 *
 * IN   : param, a value to write to the regiter VauxVoltageManagement
 * OUT  : 
 *
 * RET  : Return the value of register 0xVauxVoltageManagement
 *
 * Notes : From register 0x409, bits 1:0
 *
 **************************************************************************/
unsigned char set_vaux1_regulation( enum regulation param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(VAUX_VOLTAGE_MANAGEMENT_REG);

    /* 
     * 00: force Vaux1 disabled 
     * 01: force enabled in HP mode 
     * 10: allows HW (internal Vaux1Request signal) to control 
     * Vaux1 supply if 
     * Vaux1RequestCtrl[1:0]=0x. Forced in HP mode if 
     * Vaux1RequestCtrl[1:0]=1x 
     * 11: force enable in LP mode 
     */ 
  

     value =  old_value & ~VAUX_1_REGULATION_MASK ;

    switch(  param ){

           case REGULATION_DISABLE_E:
                value =  value | REGULATION_DISABLE ;
                break;
           case REGULATION_FORCE_HP_MODE_E:
                value =  value | REGULATION_FORCE_HP_MODE ;
                break;
           case REGULATION_ALLOW_HW_E:
                value =  value | REGULATION_ALLOW_HW ;
                break;
           case REGULATION_FORCE_LOW_POWER_E:
                value =  value | REGULATION_FORCE_LOW_POWER ;
                break;
    }
  

    I2CWrite(VAUX_VOLTAGE_MANAGEMENT_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_vaux1_regulation
 *
 * RET  : Return the value of register 0xVauxVoltageManagement
 *
 * Notes : From register 0x409, bits 1:0
 *
 **************************************************************************/
unsigned char get_vaux1_regulation()
  {
    unsigned char value;


    /* 
     * 00: force Vaux1 disabled 
     * 01: force enabled in HP mode 
     * 10: allows HW (internal Vaux1Request signal) to control 
     * Vaux1 supply if 
     * Vaux1RequestCtrl[1:0]=0x. Forced in HP mode if 
     * Vaux1RequestCtrl[1:0]=1x 
     * 11: force enable in LP mode 
     */ 
    value = (I2CRead(VAUX_VOLTAGE_MANAGEMENT_REG) & VAUX_1_REGULATION_MASK);
    return value;
  }


/***************************************************************************
 *
 * Function : set_vaux2_regulation
 *
 * IN   : param, a value to write to the regiter VauxVoltageManagement
 * OUT  : 
 *
 * RET  : Return the value of register 0xVauxVoltageManagement
 *
 * Notes : From register 0x409, bits 3:2
 *
 **************************************************************************/
unsigned char set_vaux2_regulation( enum regulation param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(VAUX_VOLTAGE_MANAGEMENT_REG);

    /* 
     * 00: force Vaux2 disabled 
     * 01: force enabled in HP mode 
     * 10: allows HW (internal Vaux2Request signal) to control 
     * Vaux2 supply if 
     * Vaux2RequestCtrl[1:0]=0x. Forced in HP mode if 
     * Vaux2RequestCtrl[1:0]=1x 
     * 11: force enable in LP mode 
     */ 
  

     value =  old_value & ~VAUX_2_REGULATION_MASK ;

    switch(  param ){

           case REGULATION_DISABLE_E:
                value  = value  | (REGULATION_DISABLE << 0x2);
                break;
           case REGULATION_FORCE_HP_MODE_E:
                value  = value  | (REGULATION_FORCE_HP_MODE << 0x2);
                break;
           case REGULATION_ALLOW_HW_E:
                value  = value  | (REGULATION_ALLOW_HW << 0x2);
                break;
           case REGULATION_FORCE_LOW_POWER_E:
                value  = value  | (REGULATION_FORCE_LOW_POWER << 0x2);
                break;
    }
  

    I2CWrite(VAUX_VOLTAGE_MANAGEMENT_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_vaux2_regulation
 *
 * RET  : Return the value of register 0xVauxVoltageManagement
 *
 * Notes : From register 0x409, bits 3:2
 *
 **************************************************************************/
unsigned char get_vaux2_regulation()
  {
    unsigned char value;


    /* 
     * 00: force Vaux2 disabled 
     * 01: force enabled in HP mode 
     * 10: allows HW (internal Vaux2Request signal) to control 
     * Vaux2 supply if 
     * Vaux2RequestCtrl[1:0]=0x. Forced in HP mode if 
     * Vaux2RequestCtrl[1:0]=1x 
     * 11: force enable in LP mode 
     */ 
    value = (I2CRead(VAUX_VOLTAGE_MANAGEMENT_REG) & VAUX_2_REGULATION_MASK) >> 2;
    return value;
  }


/***************************************************************************
 *
 * Function : set_vaux3_regulation
 *
 * IN   : param, a value to write to the regiter Vaux3VoltageManagement
 * OUT  : 
 *
 * RET  : Return the value of register 0xVaux3VoltageManagement
 *
 * Notes : From register 0x40A, bits 1:0
 *
 **************************************************************************/
unsigned char set_vaux3_regulation( enum regulation param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(VAUX_3_VOLTAGE_MANAGEMENT_REG);

    /* 
     * 00: force Vaux3 disabled 
     * 01: force enabled in HP mode 
     * 10: allows HW (internal Vaux3Request signal) to control 
     * Vaux3 supply if 
     * Vaux3RequestCtrl[1:0]=0x. Forced in HP mode if 
     * Vaux3RequestCtrl[1:0]=1x 
     * 11: force enable in LP mode 
     */ 
  

     value =  old_value & ~VAUX_3_REGULATION_MASK ;

    switch(  param ){

           case REGULATION_DISABLE_E:
                value =  value | REGULATION_DISABLE ;
                break;
           case REGULATION_FORCE_HP_MODE_E:
                value =  value | REGULATION_FORCE_HP_MODE ;
                break;
           case REGULATION_ALLOW_HW_E:
                value =  value | REGULATION_ALLOW_HW ;
                break;
           case REGULATION_FORCE_LOW_POWER_E:
                value =  value | REGULATION_FORCE_LOW_POWER ;
                break;
    }
  

    I2CWrite(VAUX_3_VOLTAGE_MANAGEMENT_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_vaux3_regulation
 *
 * RET  : Return the value of register 0xVaux3VoltageManagement
 *
 * Notes : From register 0x40A, bits 1:0
 *
 **************************************************************************/
unsigned char get_vaux3_regulation()
  {
    unsigned char value;


    /* 
     * 00: force Vaux3 disabled 
     * 01: force enabled in HP mode 
     * 10: allows HW (internal Vaux3Request signal) to control 
     * Vaux3 supply if 
     * Vaux3RequestCtrl[1:0]=0x. Forced in HP mode if 
     * Vaux3RequestCtrl[1:0]=1x 
     * 11: force enable in LP mode 
     */ 
    value = (I2CRead(VAUX_3_VOLTAGE_MANAGEMENT_REG) & VAUX_3_REGULATION_MASK);
    return value;
  }


/***************************************************************************
 *
 * Function : set_vrf1_regulation
 *
 * IN   : param, a value to write to the regiter Vaux3VoltageManagement
 * OUT  : 
 *
 * RET  : Return the value of register 0xVaux3VoltageManagement
 *
 * Notes : From register 0x40A, bits 3:2
 *
 **************************************************************************/
unsigned char set_vrf1_regulation( enum regulation param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(VAUX_3_VOLTAGE_MANAGEMENT_REG);

    /* 
     * 00: force Vrf1 disabled 
     * 01: force enabled in HP mode 
     * 10: allows HW (internal Vrf1Request signal) to control 
     * Vrf1 supply if 
     * Vrf1RequestCtrl[1:0]=0x. Forced in HP mode if 
     * Vrf1RequestCtrl[1:0]=1x 
     * 11: force enable in LP mode 
     */ 
  

     value =  old_value & ~VRF_1_REGULATION_MASK ;

    switch(  param ){

           case REGULATION_DISABLE_E:
                value  = value  | (REGULATION_DISABLE << 0x2);
                break;
           case REGULATION_FORCE_HP_MODE_E:
                value  = value  | (REGULATION_FORCE_HP_MODE << 0x2);
                break;
           case REGULATION_ALLOW_HW_E:
                value  = value  | (REGULATION_ALLOW_HW << 0x2);
                break;
           case REGULATION_FORCE_LOW_POWER_E:
                value  = value  | (REGULATION_FORCE_LOW_POWER << 0x2);
                break;
    }
  

    I2CWrite(VAUX_3_VOLTAGE_MANAGEMENT_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_vrf1_regulation
 *
 * RET  : Return the value of register 0xVaux3VoltageManagement
 *
 * Notes : From register 0x40A, bits 3:2
 *
 **************************************************************************/
unsigned char get_vrf1_regulation()
  {
    unsigned char value;


    /* 
     * 00: force Vrf1 disabled 
     * 01: force enabled in HP mode 
     * 10: allows HW (internal Vrf1Request signal) to control 
     * Vrf1 supply if 
     * Vrf1RequestCtrl[1:0]=0x. Forced in HP mode if 
     * Vrf1RequestCtrl[1:0]=1x 
     * 11: force enable in LP mode 
     */ 
    value = (I2CRead(VAUX_3_VOLTAGE_MANAGEMENT_REG) & VRF_1_REGULATION_MASK) >> 2;
    return value;
  }


/***************************************************************************
 *
 * Function : set_varm_output_sel1
 *
 * IN   : param, a value to write to the regiter VarmOutputSel1
 * OUT  : 
 *
 * RET  : Return the value of register 0xVarmOutputSel1
 *
 * Notes : From register 0x40B, bits 6:0
 *
 **************************************************************************/
unsigned char set_varm_output_sel1( enum output_supply param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(VARM_OUTPUT_SEL_1_REG);

    /* 
     * Defined Varm output voltage from 0.7V to 1.4V by 12.5mV 
     * step 
     */ 
  
    value =  old_value & ~VARM_OUTPUT_SEL_1_MASK;


    value |=  param ;  
    I2CWrite(VARM_OUTPUT_SEL_1_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_varm_output_sel1
 *
 * RET  : Return the value of register 0xVarmOutputSel1
 *
 * Notes : From register 0x40B, bits 6:0
 *
 **************************************************************************/
unsigned char get_varm_output_sel1()
  {
    unsigned char value;


    /* 
     * Defined Varm output voltage from 0.7V to 1.4V by 12.5mV 
     * step 
     */ 
    value = (I2CRead(VARM_OUTPUT_SEL_1_REG) & VARM_OUTPUT_SEL_1_MASK);
    return value;
  }


/***************************************************************************
 *
 * Function : set_varm_output_sel2
 *
 * IN   : param, a value to write to the regiter VarmOutputSel2
 * OUT  : 
 *
 * RET  : Return the value of register 0xVarmOutputSel2
 *
 * Notes : From register 0x40C, bits 6:0
 *
 **************************************************************************/
unsigned char set_varm_output_sel2( enum output_supply param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(VARM_OUTPUT_SEL_2_REG);

    /* 
     * Defined Varm output voltage from 0.7V to 1.4V by 12.5mV 
     * step 
     */ 
  
    value =  old_value & ~VARM_OUTPUT_SEL_2_MASK;


    value |=  param ;  
    I2CWrite(VARM_OUTPUT_SEL_2_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_varm_output_sel2
 *
 * RET  : Return the value of register 0xVarmOutputSel2
 *
 * Notes : From register 0x40C, bits 6:0
 *
 **************************************************************************/
unsigned char get_varm_output_sel2()
  {
    unsigned char value;


    /* 
     * Defined Varm output voltage from 0.7V to 1.4V by 12.5mV 
     * step 
     */ 
    value = (I2CRead(VARM_OUTPUT_SEL_2_REG) & VARM_OUTPUT_SEL_2_MASK);
    return value;
  }


/***************************************************************************
 *
 * Function : set_varm_output_sel3
 *
 * IN   : param, a value to write to the regiter VarmOutputSel3
 * OUT  : 
 *
 * RET  : Return the value of register 0xVarmOutputSel3
 *
 * Notes : From register 0x40D, bits 6:0
 *
 **************************************************************************/
unsigned char set_varm_output_sel3( enum output_supply param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(VARM_OUTPUT_SEL_3_REG);

    /* 
     * Defined Varm output voltage from 0.7V to 1.45V by 12.5mV 
     * step 
     */ 
  
    value =  old_value & ~VARM_OUTPUT_SEL_3_MASK;


    value |=  param ;  
    I2CWrite(VARM_OUTPUT_SEL_3_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_varm_output_sel3
 *
 * RET  : Return the value of register 0xVarmOutputSel3
 *
 * Notes : From register 0x40D, bits 6:0
 *
 **************************************************************************/
unsigned char get_varm_output_sel3()
  {
    unsigned char value;


    /* 
     * Defined Varm output voltage from 0.7V to 1.45V by 12.5mV 
     * step 
     */ 
    value = (I2CRead(VARM_OUTPUT_SEL_3_REG) & VARM_OUTPUT_SEL_3_MASK);
    return value;
  }


/***************************************************************************
 *
 * Function : set_vape_output_sel1
 *
 * IN   : param, a value to write to the regiter VapeOutputSel1
 * OUT  : 
 *
 * RET  : Return the value of register 0xVapeOutputSel1
 *
 * Notes : From register 0x40E, bits 5:0
 *
 **************************************************************************/
unsigned char set_vape_output_sel1( enum output_supply param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(VAPE_OUTPUT_SEL_1_REG);

    /* 
     * Defined Vape output voltage from 0.7V to 1.3625VV by 
     * 12.5mV step 
     */ 
  
    value =  old_value & ~VAPE_OUTPUT_SEL_1_MASK;


    value |=  param ;  
    I2CWrite(VAPE_OUTPUT_SEL_1_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_vape_output_sel1
 *
 * RET  : Return the value of register 0xVapeOutputSel1
 *
 * Notes : From register 0x40E, bits 5:0
 *
 **************************************************************************/
unsigned char get_vape_output_sel1()
  {
    unsigned char value;


    /* 
     * Defined Vape output voltage from 0.7V to 1.3625VV by 
     * 12.5mV step 
     */ 
    value = (I2CRead(VAPE_OUTPUT_SEL_1_REG) & VAPE_OUTPUT_SEL_1_MASK);
    return value;
  }


/***************************************************************************
 *
 * Function : set_vape_output_sel2
 *
 * IN   : param, a value to write to the regiter VapeOutputSel2
 * OUT  : 
 *
 * RET  : Return the value of register 0xVapeOutputSel2
 *
 * Notes : From register 0x40F, bits 6:0
 *
 **************************************************************************/
unsigned char set_vape_output_sel2( enum output_supply param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(VAPE_OUTPUT_SEL_2_REG);

    /* 
     * Defined Vape output voltage from 0.7V to 1.4V by 12.5mV 
     * step 
     */ 
  
    value =  old_value & ~VAPE_OUTPUT_SEL_2_MASK;


    value |=  param ;  
    I2CWrite(VAPE_OUTPUT_SEL_2_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_vape_output_sel2
 *
 * RET  : Return the value of register 0xVapeOutputSel2
 *
 * Notes : From register 0x40F, bits 6:0
 *
 **************************************************************************/
unsigned char get_vape_output_sel2()
  {
    unsigned char value;


    /* 
     * Defined Vape output voltage from 0.7V to 1.4V by 12.5mV 
     * step 
     */ 
    value = (I2CRead(VAPE_OUTPUT_SEL_2_REG) & VAPE_OUTPUT_SEL_2_MASK);
    return value;
  }


/***************************************************************************
 *
 * Function : set_vape_output_sel3
 *
 * IN   : param, a value to write to the regiter VapeOutputSel3
 * OUT  : 
 *
 * RET  : Return the value of register 0xVapeOutputSel3
 *
 * Notes : From register 0x410, bits 6:0
 *
 **************************************************************************/
unsigned char set_vape_output_sel3( enum output_supply param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(VAPE_OUTPUT_SEL_3_REG);

    /* 
     * Defined Vape output voltage from 0.7V to 1.4V by 12.5mV 
     * step 
     */ 
  
    value =  old_value & ~VAPE_OUTPUT_SEL_3_MASK;


    value |=  param ;  
    I2CWrite(VAPE_OUTPUT_SEL_3_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_vape_output_sel3
 *
 * RET  : Return the value of register 0xVapeOutputSel3
 *
 * Notes : From register 0x410, bits 6:0
 *
 **************************************************************************/
unsigned char get_vape_output_sel3()
  {
    unsigned char value;


    /* 
     * Defined Vape output voltage from 0.7V to 1.4V by 12.5mV 
     * step 
     */ 
    value = (I2CRead(VAPE_OUTPUT_SEL_3_REG) & VAPE_OUTPUT_SEL_3_MASK);
    return value;
  }


/***************************************************************************
 *
 * Function : set_vbb_negative_selection1
 *
 * IN   : param, a value to write to the regiter VbbOutputSupply1
 * OUT  : 
 *
 * RET  : Return the value of register 0xVbbOutputSupply1
 *
 * Notes : From register 0x411, bits 7:4
 *
 **************************************************************************/
unsigned char set_vbb_negative_selection1( enum negative_voltage_selection param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(VBB_OUTPUT_SUPPLY_1_REG);

    /* 
     * VBBN output supply value management 
     */ 
  

     value =  old_value & ~VBB_NEGATIVE_SELECTION_1_MASK ;

    switch(  param ){

           case VBBN_0V_E:
                value  = value  | (VBBN_0V << 0x4);
                break;
           case VBBN_MINUS_01V_E:
                value  = value  | (VBBN_MINUS_01V << 0x4);
                break;
           case VBBN_MINUS_02V_E:
                value  = value  | (VBBN_MINUS_02V << 0x4);
                break;
           case VBBN_MINUS_03V_E:
                value  = value  | (VBBN_MINUS_03V << 0x4);
                break;
           case VBBN_MINUS_04V_E:
                value  = value  | (VBBN_MINUS_04V << 0x4);
                break;
           case VBBN_MINUS_0V_E:
                value  = value  | (VBBN_MINUS_0V << 0x4);
                break;
           case VBBN_01V_E:
                value  = value  | (VBBN_01V << 0x4);
                break;
           case VBBN_02V_E:
                value  = value  | (VBBN_02V << 0x4);
                break;
           case VBBN_03V_E:
                value  = value  | (VBBN_03V << 0x4);
                break;
           case VBBN_04V_E:
                value  = value  | (VBBN_04V << 0x4);
                break;
    }
  

    I2CWrite(VBB_OUTPUT_SUPPLY_1_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_vbb_negative_selection1
 *
 * RET  : Return the value of register 0xVbbOutputSupply1
 *
 * Notes : From register 0x411, bits 7:4
 *
 **************************************************************************/
unsigned char get_vbb_negative_selection1()
  {
    unsigned char value;


    /* 
     * VBBN output supply value management 
     */ 
    value = (I2CRead(VBB_OUTPUT_SUPPLY_1_REG) & VBB_NEGATIVE_SELECTION_1_MASK) >> 4;
    return value;
  }


/***************************************************************************
 *
 * Function : set_vbb_positive_selection1
 *
 * IN   : param, a value to write to the regiter VbbOutputSupply1
 * OUT  : 
 *
 * RET  : Return the value of register 0xVbbOutputSupply1
 *
 * Notes : From register 0x411, bits 3:0
 *
 **************************************************************************/
unsigned char set_vbb_positive_selection1( enum positive_voltage_selection param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(VBB_OUTPUT_SUPPLY_1_REG);

    /* 
     * VBBP output supply value management 
     */ 
  

     value =  old_value & ~VBB_POSITIVE_SELECTION_1_MASK ;

    switch(  param ){

           case VBBPFB_E:
                value =  value | VBBPFB ;
                break;
           case VBBPFB_01V_E:
                value =  value | VBBPFB_01V ;
                break;
           case VBBPFB_02V_E:
                value =  value | VBBPFB_02V ;
                break;
           case VBBPFB_03V_E:
                value =  value | VBBPFB_03V ;
                break;
           case VBBPFB_04V_E:
                value =  value | VBBPFB_04V ;
                break;
           case VBBPFB_MINUS_04V_E:
                value =  value | VBBPFB_MINUS_04V ;
                break;
           case VBBPFB_MINUS_03V_E:
                value =  value | VBBPFB_MINUS_03V ;
                break;
           case VBBPFB_MINUS_02V_E:
                value =  value | VBBPFB_MINUS_02V ;
                break;
           case VBBPFB_MINUS_01V_E:
                value =  value | VBBPFB_MINUS_01V ;
                break;
    }
  

    I2CWrite(VBB_OUTPUT_SUPPLY_1_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_vbb_positive_selection1
 *
 * RET  : Return the value of register 0xVbbOutputSupply1
 *
 * Notes : From register 0x411, bits 3:0
 *
 **************************************************************************/
unsigned char get_vbb_positive_selection1()
  {
    unsigned char value;


    /* 
     * VBBP output supply value management 
     */ 
    value = (I2CRead(VBB_OUTPUT_SUPPLY_1_REG) & VBB_POSITIVE_SELECTION_1_MASK);
    return value;
  }


/***************************************************************************
 *
 * Function : set_vbb_negative_selection2
 *
 * IN   : param, a value to write to the regiter VbbOutputSupply2
 * OUT  : 
 *
 * RET  : Return the value of register 0xVbbOutputSupply2
 *
 * Notes : From register 0x412, bits 7:4
 *
 **************************************************************************/
unsigned char set_vbb_negative_selection2( enum negative_voltage_selection param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(VBB_OUTPUT_SUPPLY_2_REG);

    /* 
     * VBBN output supply value management 
     */ 
  

     value =  old_value & ~VBB_NEGATIVE_SELECTION_2_MASK ;

    switch(  param ){

           case VBBN_0V_E:
                value  = value  | (VBBN_0V << 0x4);
                break;
           case VBBN_MINUS_01V_E:
                value  = value  | (VBBN_MINUS_01V << 0x4);
                break;
           case VBBN_MINUS_02V_E:
                value  = value  | (VBBN_MINUS_02V << 0x4);
                break;
           case VBBN_MINUS_03V_E:
                value  = value  | (VBBN_MINUS_03V << 0x4);
                break;
           case VBBN_MINUS_04V_E:
                value  = value  | (VBBN_MINUS_04V << 0x4);
                break;
           case VBBN_MINUS_0V_E:
                value  = value  | (VBBN_MINUS_0V << 0x4);
                break;
           case VBBN_01V_E:
                value  = value  | (VBBN_01V << 0x4);
                break;
           case VBBN_02V_E:
                value  = value  | (VBBN_02V << 0x4);
                break;
           case VBBN_03V_E:
                value  = value  | (VBBN_03V << 0x4);
                break;
           case VBBN_04V_E:
                value  = value  | (VBBN_04V << 0x4);
                break;
    }
  

    I2CWrite(VBB_OUTPUT_SUPPLY_2_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_vbb_negative_selection2
 *
 * RET  : Return the value of register 0xVbbOutputSupply2
 *
 * Notes : From register 0x412, bits 7:4
 *
 **************************************************************************/
unsigned char get_vbb_negative_selection2()
  {
    unsigned char value;


    /* 
     * VBBN output supply value management 
     */ 
    value = (I2CRead(VBB_OUTPUT_SUPPLY_2_REG) & VBB_NEGATIVE_SELECTION_2_MASK) >> 4;
    return value;
  }


/***************************************************************************
 *
 * Function : set_vbb_positive_selection2
 *
 * IN   : param, a value to write to the regiter VbbOutputSupply2
 * OUT  : 
 *
 * RET  : Return the value of register 0xVbbOutputSupply2
 *
 * Notes : From register 0x412, bits 3:0
 *
 **************************************************************************/
unsigned char set_vbb_positive_selection2( enum positive_voltage_selection param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(VBB_OUTPUT_SUPPLY_2_REG);

    /* 
     * VBBP output supply value management 
     */ 
  

     value =  old_value & ~VBB_POSITIVE_SELECTION_2_MASK ;

    switch(  param ){

           case VBBPFB_E:
                value =  value | VBBPFB ;
                break;
           case VBBPFB_01V_E:
                value =  value | VBBPFB_01V ;
                break;
           case VBBPFB_02V_E:
                value =  value | VBBPFB_02V ;
                break;
           case VBBPFB_03V_E:
                value =  value | VBBPFB_03V ;
                break;
           case VBBPFB_04V_E:
                value =  value | VBBPFB_04V ;
                break;
           case VBBPFB_MINUS_04V_E:
                value =  value | VBBPFB_MINUS_04V ;
                break;
           case VBBPFB_MINUS_03V_E:
                value =  value | VBBPFB_MINUS_03V ;
                break;
           case VBBPFB_MINUS_02V_E:
                value =  value | VBBPFB_MINUS_02V ;
                break;
           case VBBPFB_MINUS_01V_E:
                value =  value | VBBPFB_MINUS_01V ;
                break;
    }
  

    I2CWrite(VBB_OUTPUT_SUPPLY_2_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_vbb_positive_selection2
 *
 * RET  : Return the value of register 0xVbbOutputSupply2
 *
 * Notes : From register 0x412, bits 3:0
 *
 **************************************************************************/
unsigned char get_vbb_positive_selection2()
  {
    unsigned char value;


    /* 
     * VBBP output supply value management 
     */ 
    value = (I2CRead(VBB_OUTPUT_SUPPLY_2_REG) & VBB_POSITIVE_SELECTION_2_MASK);
    return value;
  }


/***************************************************************************
 *
 * Function : set_vsmps1_sel1_output
 *
 * IN   : param, a value to write to the regiter Vsmps1Sel1Output
 * OUT  : 
 *
 * RET  : Return the value of register 0xVsmps1Sel1Output
 *
 * Notes : From register 0x413, bits 5:0
 *
 **************************************************************************/
unsigned char set_vsmps1_sel1_output( enum output_supply_med param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(VSMPS_1_SEL_1_OUTPUT_REG);

    /* 
     * Defined Vsmps1Sel1 output voltage from 0.7V to 1.3625V by 
     * 12.5mV step 
     */ 
  
    value =  old_value & ~VSMPS_1_SEL_1_OUTPUT_MASK;


    value |=  param ;  
    I2CWrite(VSMPS_1_SEL_1_OUTPUT_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_vsmps1_sel1_output
 *
 * RET  : Return the value of register 0xVsmps1Sel1Output
 *
 * Notes : From register 0x413, bits 5:0
 *
 **************************************************************************/
unsigned char get_vsmps1_sel1_output()
  {
    unsigned char value;


    /* 
     * Defined Vsmps1Sel1 output voltage from 0.7V to 1.3625V by 
     * 12.5mV step 
     */ 
    value = (I2CRead(VSMPS_1_SEL_1_OUTPUT_REG) & VSMPS_1_SEL_1_OUTPUT_MASK);
    return value;
  }


/***************************************************************************
 *
 * Function : set_vsmps1_sel2_output
 *
 * IN   : param, a value to write to the regiter Vsmps1Sel2Output
 * OUT  : 
 *
 * RET  : Return the value of register 0xVsmps1Sel2Output
 *
 * Notes : From register 0x414, bits 5:0
 *
 **************************************************************************/
unsigned char set_vsmps1_sel2_output( enum output_supply_med param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(VSMPS_1_SEL_2_OUTPUT_REG);

    /* 
     * Defined Vsmps1Sel2 output voltage from 0.7V to 1.3625V by 
     * 12.5mV step 
     */ 
  
    value =  old_value & ~VSMPS_1_SEL_2_OUTPUT_MASK;


    value |=  param ;  
    I2CWrite(VSMPS_1_SEL_2_OUTPUT_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_vsmps1_sel2_output
 *
 * RET  : Return the value of register 0xVsmps1Sel2Output
 *
 * Notes : From register 0x414, bits 5:0
 *
 **************************************************************************/
unsigned char get_vsmps1_sel2_output()
  {
    unsigned char value;


    /* 
     * Defined Vsmps1Sel2 output voltage from 0.7V to 1.3625V by 
     * 12.5mV step 
     */ 
    value = (I2CRead(VSMPS_1_SEL_2_OUTPUT_REG) & VSMPS_1_SEL_2_OUTPUT_MASK);
    return value;
  }


/***************************************************************************
 *
 * Function : set_vsmps1_sel3_output
 *
 * IN   : param, a value to write to the regiter Vsmps1Sel3Output
 * OUT  : 
 *
 * RET  : Return the value of register 0xVsmps1Sel3Output
 *
 * Notes : From register 0x415, bits 5:0
 *
 **************************************************************************/
unsigned char set_vsmps1_sel3_output( enum output_supply_med param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(VSMPS_1_SEL_3_OUTPUT_REG);

    /* 
     * Defined Vsmps1Sel3 output voltage from 0.7V to 1.3625V by 
     * 12.5mV step 
     */ 
  
    value =  old_value & ~VSMPS_1_SEL_3_OUTPUT_MASK;


    value |=  param ;  
    I2CWrite(VSMPS_1_SEL_3_OUTPUT_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_vsmps1_sel3_output
 *
 * RET  : Return the value of register 0xVsmps1Sel3Output
 *
 * Notes : From register 0x415, bits 5:0
 *
 **************************************************************************/
unsigned char get_vsmps1_sel3_output()
  {
    unsigned char value;


    /* 
     * Defined Vsmps1Sel3 output voltage from 0.7V to 1.3625V by 
     * 12.5mV step 
     */ 
    value = (I2CRead(VSMPS_1_SEL_3_OUTPUT_REG) & VSMPS_1_SEL_3_OUTPUT_MASK);
    return value;
  }


/***************************************************************************
 *
 * Function : set_vsmps2_sel1_output
 *
 * IN   : param, a value to write to the regiter Vsmps2Sel1Output
 * OUT  : 
 *
 * RET  : Return the value of register 0xVsmps2Sel1Output
 *
 * Notes : From register 0x417, bits 5:0
 *
 **************************************************************************/
unsigned char set_vsmps2_sel1_output( enum output_supply_large param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(VSMPS_2_SEL_1_OUTPUT_REG);

    /* 
     * Defined Vsmps2Sel1 output voltage from 1.8 to 1.875 by 
     * 12.5 mV step 
     */ 
  
    value =  old_value & ~VSMPS_2_SEL_1_OUTPUT_MASK;


    value |=  param ;  
    I2CWrite(VSMPS_2_SEL_1_OUTPUT_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_vsmps2_sel1_output
 *
 * RET  : Return the value of register 0xVsmps2Sel1Output
 *
 * Notes : From register 0x417, bits 5:0
 *
 **************************************************************************/
unsigned char get_vsmps2_sel1_output()
  {
    unsigned char value;


    /* 
     * Defined Vsmps2Sel1 output voltage from 1.8 to 1.875 by 
     * 12.5 mV step 
     */ 
    value = (I2CRead(VSMPS_2_SEL_1_OUTPUT_REG) & VSMPS_2_SEL_1_OUTPUT_MASK);
    return value;
  }


/***************************************************************************
 *
 * Function : set_vsmps2_sel2_output
 *
 * IN   : param, a value to write to the regiter Vsmps2Sel2Output
 * OUT  : 
 *
 * RET  : Return the value of register 0xVsmps2Sel2Output
 *
 * Notes : From register 0x418, bits 5:0
 *
 **************************************************************************/
unsigned char set_vsmps2_sel2_output( enum output_supply_large param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(VSMPS_2_SEL_2_OUTPUT_REG);

    /* 
     * Defined Vsmps2Sel2 output voltage from 1.8V to 1.875V by 
     * 12.5mV step 
     */ 
  
    value =  old_value & ~VSMPS_2_SEL_2_OUTPUT_MASK;


    value |=  param ;  
    I2CWrite(VSMPS_2_SEL_2_OUTPUT_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_vsmps2_sel2_output
 *
 * RET  : Return the value of register 0xVsmps2Sel2Output
 *
 * Notes : From register 0x418, bits 5:0
 *
 **************************************************************************/
unsigned char get_vsmps2_sel2_output()
  {
    unsigned char value;


    /* 
     * Defined Vsmps2Sel2 output voltage from 1.8V to 1.875V by 
     * 12.5mV step 
     */ 
    value = (I2CRead(VSMPS_2_SEL_2_OUTPUT_REG) & VSMPS_2_SEL_2_OUTPUT_MASK);
    return value;
  }


/***************************************************************************
 *
 * Function : set_vsmps2_sel3_output
 *
 * IN   : param, a value to write to the regiter Vsmps2Sel3Output
 * OUT  : 
 *
 * RET  : Return the value of register 0xVsmps2Sel3Output
 *
 * Notes : From register 0x419, bits 5:0
 *
 **************************************************************************/
unsigned char set_vsmps2_sel3_output( enum output_supply_large param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(VSMPS_2_SEL_3_OUTPUT_REG);

    /* 
     * Defined Vsmps2Sel3 output voltage from 1.8 to 1.875 by 
     * 12.5 mV step 
     */ 
  
    value =  old_value & ~VSMPS_2_SEL_3_OUTPUT_MASK;


    value |=  param ;  
    I2CWrite(VSMPS_2_SEL_3_OUTPUT_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_vsmps2_sel3_output
 *
 * RET  : Return the value of register 0xVsmps2Sel3Output
 *
 * Notes : From register 0x419, bits 5:0
 *
 **************************************************************************/
unsigned char get_vsmps2_sel3_output()
  {
    unsigned char value;


    /* 
     * Defined Vsmps2Sel3 output voltage from 1.8 to 1.875 by 
     * 12.5 mV step 
     */ 
    value = (I2CRead(VSMPS_2_SEL_3_OUTPUT_REG) & VSMPS_2_SEL_3_OUTPUT_MASK);
    return value;
  }


/***************************************************************************
 *
 * Function : set_vsmps3_sel1_output
 *
 * IN   : param, a value to write to the regiter Vsmps3Sel1Output
 * OUT  : 
 *
 * RET  : Return the value of register 0xVsmps3Sel1Output
 *
 * Notes : From register 0x41B, bits 6:0
 *
 **************************************************************************/
unsigned char set_vsmps3_sel1_output( enum output_supply3 param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(VSMPS_3_SEL_1_OUTPUT_REG);

    /* 
     * Defined Vsmps3 output voltage from 0.7V to 1.3625 by 
     * 12.5mV steps 
     */ 
  
    value =  old_value & ~VSMPS_3_SEL_1_OUTPUT_MASK;


    value |=  param ;  
    I2CWrite(VSMPS_3_SEL_1_OUTPUT_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_vsmps3_sel1_output
 *
 * RET  : Return the value of register 0xVsmps3Sel1Output
 *
 * Notes : From register 0x41B, bits 6:0
 *
 **************************************************************************/
unsigned char get_vsmps3_sel1_output()
  {
    unsigned char value;


    /* 
     * Defined Vsmps3 output voltage from 0.7V to 1.3625 by 
     * 12.5mV steps 
     */ 
    value = (I2CRead(VSMPS_3_SEL_1_OUTPUT_REG) & VSMPS_3_SEL_1_OUTPUT_MASK);
    return value;
  }


/***************************************************************************
 *
 * Function : set_vsmps3_sel2_output
 *
 * IN   : param, a value to write to the regiter Vsmps3Sel2Output
 * OUT  : 
 *
 * RET  : Return the value of register 0xVsmps3Sel2Output
 *
 * Notes : From register 0x41C, bits 6:0
 *
 **************************************************************************/
unsigned char set_vsmps3_sel2_output( enum output_supply3 param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(VSMPS_3_SEL_2_OUTPUT_REG);

    /* 
     * Defined Vsmps3 output voltage from 0.7V to 1.3625 by 
     * 12.5mV steps 
     */ 
  
    value =  old_value & ~VSMPS_3_SEL_2_OUTPUT_MASK;


    value |=  param ;  
    I2CWrite(VSMPS_3_SEL_2_OUTPUT_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_vsmps3_sel2_output
 *
 * RET  : Return the value of register 0xVsmps3Sel2Output
 *
 * Notes : From register 0x41C, bits 6:0
 *
 **************************************************************************/
unsigned char get_vsmps3_sel2_output()
  {
    unsigned char value;


    /* 
     * Defined Vsmps3 output voltage from 0.7V to 1.3625 by 
     * 12.5mV steps 
     */ 
    value = (I2CRead(VSMPS_3_SEL_2_OUTPUT_REG) & VSMPS_3_SEL_2_OUTPUT_MASK);
    return value;
  }


/***************************************************************************
 *
 * Function : set_vsmps3_sel3_output
 *
 * IN   : param, a value to write to the regiter Vsmps3Sel3Output
 * OUT  : 
 *
 * RET  : Return the value of register 0xVsmps3Sel3Output
 *
 * Notes : From register 0x41D, bits 6:0
 *
 **************************************************************************/
unsigned char set_vsmps3_sel3_output( enum output_supply3 param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(VSMPS_3_SEL_3_OUTPUT_REG);

    /* 
     * Defined Vsmps3 output voltage from 0.7V to 1.3625 by 
     * 12.5mV steps 
     */ 
  
    value =  old_value & ~VSMPS_3_SEL_3_OUTPUT_MASK;


    value |=  param ;  
    I2CWrite(VSMPS_3_SEL_3_OUTPUT_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_vsmps3_sel3_output
 *
 * RET  : Return the value of register 0xVsmps3Sel3Output
 *
 * Notes : From register 0x41D, bits 6:0
 *
 **************************************************************************/
unsigned char get_vsmps3_sel3_output()
  {
    unsigned char value;


    /* 
     * Defined Vsmps3 output voltage from 0.7V to 1.3625 by 
     * 12.5mV steps 
     */ 
    value = (I2CRead(VSMPS_3_SEL_3_OUTPUT_REG) & VSMPS_3_SEL_3_OUTPUT_MASK);
    return value;
  }


/***************************************************************************
 *
 * Function : set_vaux1_sel_output
 *
 * IN   : param, a value to write to the regiter Vaux1Sel1Output
 * OUT  : 
 *
 * RET  : Return the value of register 0xVaux1Sel1Output
 *
 * Notes : From register 0x41F, bits 3:0
 *
 **************************************************************************/
unsigned char set_vaux1_sel_output( enum vaux_output param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(VAUX_1_SEL_1_OUTPUT_REG);

    /* 
     * Vaux1 output supply value management 
     */ 
  

     value =  old_value & ~VAUX_1_SEL_OUTPUT_MASK ;

    switch(  param ){

           case VAUX_1200MV_E:
                value =  value | VAUX_1200MV ;
                break;
           case VAUX_1500MV_E:
                value =  value | VAUX_1500MV ;
                break;
           case VAUX_1800MV_E:
                value =  value | VAUX_1800MV ;
                break;
           case VAUX_2100MV_E:
                value =  value | VAUX_2100MV ;
                break;
           case VAUX_2500MV_E:
                value =  value | VAUX_2500MV ;
                break;
           case VAUX_2750MV_E:
                value =  value | VAUX_2750MV ;
                break;
           case VAUX_2790MV_E:
                value =  value | VAUX_2790MV ;
                break;
           case VAUX_2910MV_E:
                value =  value | VAUX_2910MV ;
                break;
    }
  

    I2CWrite(VAUX_1_SEL_1_OUTPUT_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_vaux1_sel_output
 *
 * RET  : Return the value of register 0xVaux1Sel1Output
 *
 * Notes : From register 0x41F, bits 3:0
 *
 **************************************************************************/
unsigned char get_vaux1_sel_output()
  {
    unsigned char value;


    /* 
     * Vaux1 output supply value management 
     */ 
    value = (I2CRead(VAUX_1_SEL_1_OUTPUT_REG) & VAUX_1_SEL_OUTPUT_MASK);
    return value;
  }


/***************************************************************************
 *
 * Function : set_vaux2_sel_output
 *
 * IN   : param, a value to write to the regiter Vaux2Sel1Output
 * OUT  : 
 *
 * RET  : Return the value of register 0xVaux2Sel1Output
 *
 * Notes : From register 0x420, bits 3:0
 *
 **************************************************************************/
unsigned char set_vaux2_sel_output( enum vaux_output param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(VAUX_2_SEL_1_OUTPUT_REG);

    /* 
     * Vaux2 output supply value management 
     */ 
  

     value =  old_value & ~VAUX_2_SEL_OUTPUT_MASK ;

    switch(  param ){

           case VAUX_1200MV_E:
                value =  value | VAUX_1200MV ;
                break;
           case VAUX_1500MV_E:
                value =  value | VAUX_1500MV ;
                break;
           case VAUX_1800MV_E:
                value =  value | VAUX_1800MV ;
                break;
           case VAUX_2100MV_E:
                value =  value | VAUX_2100MV ;
                break;
           case VAUX_2500MV_E:
                value =  value | VAUX_2500MV ;
                break;
           case VAUX_2750MV_E:
                value =  value | VAUX_2750MV ;
                break;
           case VAUX_2790MV_E:
                value =  value | VAUX_2790MV ;
                break;
           case VAUX_2910MV_E:
                value =  value | VAUX_2910MV ;
                break;
    }
  

    I2CWrite(VAUX_2_SEL_1_OUTPUT_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_vaux2_sel_output
 *
 * RET  : Return the value of register 0xVaux2Sel1Output
 *
 * Notes : From register 0x420, bits 3:0
 *
 **************************************************************************/
unsigned char get_vaux2_sel_output()
  {
    unsigned char value;


    /* 
     * Vaux2 output supply value management 
     */ 
    value = (I2CRead(VAUX_2_SEL_1_OUTPUT_REG) & VAUX_2_SEL_OUTPUT_MASK);
    return value;
  }


/***************************************************************************
 *
 * Function : set_vrf1_sel_output
 *
 * IN   : param, a value to write to the regiter Vaux3Sel1Output
 * OUT  : 
 *
 * RET  : Return the value of register 0xVaux3Sel1Output
 *
 * Notes : From register 0x421, bits 5:4
 *
 **************************************************************************/
unsigned char set_vrf1_sel_output( enum vrf1_output param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(VAUX_3_SEL_1_OUTPUT_REG);

    /* 
     * Vrf1 output supply value management 
     */ 
  

     value =  old_value & ~VRF_1_SEL_OUTPUT_MASK ;

    switch(  param ){

           case VRF1_1800_MV_E:
                value  = value  | (VRF1_1800_MV << 0x4);
                break;
           case VRF1_2000_MV_E:
                value  = value  | (VRF1_2000_MV << 0x4);
                break;
           case VRF1_2150_MV_E:
                value  = value  | (VRF1_2150_MV << 0x4);
                break;
           case VRF1_2500_MV_E:
                value  = value  | (VRF1_2500_MV << 0x4);
                break;
    }
  

    I2CWrite(VAUX_3_SEL_1_OUTPUT_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_vrf1_sel_output
 *
 * RET  : Return the value of register 0xVaux3Sel1Output
 *
 * Notes : From register 0x421, bits 5:4
 *
 **************************************************************************/
unsigned char get_vrf1_sel_output()
  {
    unsigned char value;


    /* 
     * Vrf1 output supply value management 
     */ 
    value = (I2CRead(VAUX_3_SEL_1_OUTPUT_REG) & VRF_1_SEL_OUTPUT_MASK) >> 4;
    return value;
  }


/***************************************************************************
 *
 * Function : set_vaux3_sel_output
 *
 * IN   : param, a value to write to the regiter Vaux3Sel1Output
 * OUT  : 
 *
 * RET  : Return the value of register 0xVaux3Sel1Output
 *
 * Notes : From register 0x421, bits 2:0
 *
 **************************************************************************/
unsigned char set_vaux3_sel_output( enum vaux_output param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(VAUX_3_SEL_1_OUTPUT_REG);

    /* 
     * Vaux2 output supply value management 
     */ 
  

     value =  old_value & ~VAUX_3_SEL_OUTPUT_MASK ;

    switch(  param ){

           case VAUX_1200MV_E:
                value =  value | VAUX_1200MV ;
                break;
           case VAUX_1500MV_E:
                value =  value | VAUX_1500MV ;
                break;
           case VAUX_1800MV_E:
                value =  value | VAUX_1800MV ;
                break;
           case VAUX_2100MV_E:
                value =  value | VAUX_2100MV ;
                break;
           case VAUX_2500MV_E:
                value =  value | VAUX_2500MV ;
                break;
           case VAUX_2750MV_E:
                value =  value | VAUX_2750MV ;
                break;
           case VAUX_2790MV_E:
                value =  value | VAUX_2790MV ;
                break;
           case VAUX_2910MV_E:
                value =  value | VAUX_2910MV ;
                break;
    }
  

    I2CWrite(VAUX_3_SEL_1_OUTPUT_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_vaux3_sel_output
 *
 * RET  : Return the value of register 0xVaux3Sel1Output
 *
 * Notes : From register 0x421, bits 2:0
 *
 **************************************************************************/
unsigned char get_vaux3_sel_output()
  {
    unsigned char value;


    /* 
     * Vaux2 output supply value management 
     */ 
    value = (I2CRead(VAUX_3_SEL_1_OUTPUT_REG) & VAUX_3_SEL_OUTPUT_MASK);
    return value;
  }


/***************************************************************************
 *
 * Function : set_ext_supply_force_low
 *
 * IN   : param, a value to write to the regiter ExternalSupplyControl
 * OUT  : 
 *
 * RET  : Return the value of register 0xExternalSupplyControl
 *
 * Notes : From register 0x422, bits 0:0
 *
 **************************************************************************/
unsigned char set_ext_supply_force_low( enum ext_supply_force_low param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(EXTERNAL_SUPPLY_CONTROL_REG);

    /* 
     * 0: inactive 
     * 1: Force ExtSupply12LPn = Low when 
     * 'ExtSup12LPnClkSel[1:0]' = 00 
     * (ExtSup12LPn/ExtSupply12Clk pad functionality = 
     * ExtSupply12LPn) 
     */ 
    switch( param ){
        case FORCE_E: 
           value = old_value | EXT_SUPPLY_FORCE_LOW_MASK; 
           break;
        case INNACTIVE_E: 
           value = old_value & ~ EXT_SUPPLY_FORCE_LOW_MASK;
           break;
    }
  

    I2CWrite(EXTERNAL_SUPPLY_CONTROL_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_ext_supply_force_low
 *
 * RET  : Return the value of register 0xExternalSupplyControl
 *
 * Notes : From register 0x422, bits 0:0
 *
 **************************************************************************/
unsigned char get_ext_supply_force_low()
  {
    unsigned char value;


    /* 
     * 0: inactive 
     * 1: Force ExtSupply12LPn = Low when 
     * 'ExtSup12LPnClkSel[1:0]' = 00 
     * (ExtSup12LPn/ExtSupply12Clk pad functionality = 
     * ExtSupply12LPn) 
     */ 
    value = (I2CRead(EXTERNAL_SUPPLY_CONTROL_REG) & EXT_SUPPLY_FORCE_LOW_MASK);
    return value;
  }


/***************************************************************************
 *
 * Function : get_modem_control2
 *
 * RET  : Return the value of register 0xModemControl2
 *
 * Notes : From register 0x423, bits 7:0
 *
 **************************************************************************/
unsigned char get_modem_control2()
  {
    unsigned char value;


    /* 
     * Get the value from a register 
     */ 
   value = I2CRead(MODEM_CONTROL_2_REG) ;
    return value;
  }


/***************************************************************************
 *
 * Function : set_modem_control2
 *
 * IN   : param, a value to write to the regiter ModemControl2
 * OUT  : 
 *
 * RET  : Return the value of register 0xModemControl2
 *
 * Notes : From register 0x423, bits 7:0
 *
 **************************************************************************/
unsigned char set_modem_control2( unsigned char param )
  {
    unsigned char value;

    value = I2CRead(MODEM_CONTROL_2_REG);

    /* 
     * Set the value to a register 
     */ 
    I2CWrite(MODEM_CONTROL_2_REG, param);
    return value;

  }


/***************************************************************************
 *
 * Function : get_varm_selection4
 *
 * RET  : Return the value of register 0xVarmSelection4
 *
 * Notes : From register 0x424, bits 7:0
 *
 **************************************************************************/
unsigned char get_varm_selection4()
  {
    unsigned char value;


    /* 
     * Get the value from a register 
     */ 
   value = I2CRead(VARM_SELECTION_4_REG) ;
    return value;
  }


/***************************************************************************
 *
 * Function : set_varm_selection4
 *
 * IN   : param, a value to write to the regiter VarmSelection4
 * OUT  : 
 *
 * RET  : Return the value of register 0xVarmSelection4
 *
 * Notes : From register 0x424, bits 7:0
 *
 **************************************************************************/
unsigned char set_varm_selection4( unsigned char param )
  {
    unsigned char value;

    value = I2CRead(VARM_SELECTION_4_REG);

    /* 
     * Set the value to a register 
     */ 
    I2CWrite(VARM_SELECTION_4_REG, param);
    return value;

  }


/***************************************************************************
 *
 * Function : get_varm_selection5
 *
 * RET  : Return the value of register 0xVarmSelection5
 *
 * Notes : From register 0x425, bits 7:0
 *
 **************************************************************************/
unsigned char get_varm_selection5()
  {
    unsigned char value;


    /* 
     * Get the value from a register 
     */ 
   value = I2CRead(VARM_SELECTION_5_REG) ;
    return value;
  }


/***************************************************************************
 *
 * Function : set_varm_selection5
 *
 * IN   : param, a value to write to the regiter VarmSelection5
 * OUT  : 
 *
 * RET  : Return the value of register 0xVarmSelection5
 *
 * Notes : From register 0x425, bits 7:0
 *
 **************************************************************************/
unsigned char set_varm_selection5( unsigned char param )
  {
    unsigned char value;

    value = I2CRead(VARM_SELECTION_5_REG);

    /* 
     * Set the value to a register 
     */ 
    I2CWrite(VARM_SELECTION_5_REG, param);
    return value;

  }


/***************************************************************************
 *
 * Function : get_varm_selection6
 *
 * RET  : Return the value of register 0xVarmSelection6
 *
 * Notes : From register 0x426, bits 7:0
 *
 **************************************************************************/
unsigned char get_varm_selection6()
  {
    unsigned char value;


    /* 
     * Get the value from a register 
     */ 
   value = I2CRead(VARM_SELECTION_6_REG) ;
    return value;
  }


/***************************************************************************
 *
 * Function : set_varm_selection6
 *
 * IN   : param, a value to write to the regiter VarmSelection6
 * OUT  : 
 *
 * RET  : Return the value of register 0xVarmSelection6
 *
 * Notes : From register 0x426, bits 7:0
 *
 **************************************************************************/
unsigned char set_varm_selection6( unsigned char param )
  {
    unsigned char value;

    value = I2CRead(VARM_SELECTION_6_REG);

    /* 
     * Set the value to a register 
     */ 
    I2CWrite(VARM_SELECTION_6_REG, param);
    return value;

  }


/***************************************************************************
 *
 * Function : get_varm_selection7
 *
 * RET  : Return the value of register 0xVarmSelection7
 *
 * Notes : From register 0x427, bits 7:0
 *
 **************************************************************************/
unsigned char get_varm_selection7()
  {
    unsigned char value;


    /* 
     * Get the value from a register 
     */ 
   value = I2CRead(VARM_SELECTION_7_REG) ;
    return value;
  }


/***************************************************************************
 *
 * Function : set_varm_selection7
 *
 * IN   : param, a value to write to the regiter VarmSelection7
 * OUT  : 
 *
 * RET  : Return the value of register 0xVarmSelection7
 *
 * Notes : From register 0x427, bits 7:0
 *
 **************************************************************************/
unsigned char set_varm_selection7( unsigned char param )
  {
    unsigned char value;

    value = I2CRead(VARM_SELECTION_7_REG);

    /* 
     * Set the value to a register 
     */ 
    I2CWrite(VARM_SELECTION_7_REG, param);
    return value;

  }


/***************************************************************************
 *
 * Function : get_varm_sel4567_ctrl
 *
 * RET  : Return the value of register 0xVarmSel4567Ctrl
 *
 * Notes : From register 0x428, bits 7:0
 *
 **************************************************************************/
unsigned char get_varm_sel4567_ctrl()
  {
    unsigned char value;


    /* 
     * Get the value from a register 
     */ 
   value = I2CRead(VARM_SEL_4567_CTRL_REG) ;
    return value;
  }


/***************************************************************************
 *
 * Function : set_varm_sel4567_ctrl
 *
 * IN   : param, a value to write to the regiter VarmSel4567Ctrl
 * OUT  : 
 *
 * RET  : Return the value of register 0xVarmSel4567Ctrl
 *
 * Notes : From register 0x428, bits 7:0
 *
 **************************************************************************/
unsigned char set_varm_sel4567_ctrl( unsigned char param )
  {
    unsigned char value;

    value = I2CRead(VARM_SEL_4567_CTRL_REG);

    /* 
     * Set the value to a register 
     */ 
    I2CWrite(VARM_SEL_4567_CTRL_REG, param);
    return value;

  }


/***************************************************************************
 *
 * Function : get_vana_vpll_sel
 *
 * RET  : Return the value of register 0xVanaVpllSel
 *
 * Notes : From register 0x429, bits 7:0
 *
 **************************************************************************/
unsigned char get_vana_vpll_sel()
  {
    unsigned char value;


    /* 
     * Get the value from a register 
     */ 
   value = I2CRead(VANA_VPLL_SEL_REG) ;
    return value;
  }


/***************************************************************************
 *
 * Function : set_vana_vpll_sel
 *
 * IN   : param, a value to write to the regiter VanaVpllSel
 * OUT  : 
 *
 * RET  : Return the value of register 0xVanaVpllSel
 *
 * Notes : From register 0x429, bits 7:0
 *
 **************************************************************************/
unsigned char set_vana_vpll_sel( unsigned char param )
  {
    unsigned char value;

    value = I2CRead(VANA_VPLL_SEL_REG);

    /* 
     * Set the value to a register 
     */ 
    I2CWrite(VANA_VPLL_SEL_REG, param);
    return value;

  }


/***************************************************************************
 *
 * Function : set_vmod_regulation
 *
 * IN   : param, a value to write to the regiter VmodSupplyManagement
 * OUT  : 
 *
 * RET  : Return the value of register 0xVmodSupplyManagement
 *
 * Notes : From register 0x440, bits 1:0
 *
 **************************************************************************/
unsigned char set_vmod_regulation( enum vmod_regulation param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(VMOD_SUPPLY_MANAGEMENT_REG);

    /* 
     * 00: force Vmod disabled 
     * 01: force enabled in HP mode 
     * 10: allows HW (internal Vmod signal) to control Vmod 
     * supply if VmodRequestCtrl[1:0]=0x. 
     * Forced in HP mode if VmodRequestCtrl[1:0]=1x 
     * 11: force enable in LP mode 
     */ 
  

     value =  old_value & ~VMOD_REGULATION_MASK ;

    switch(  param ){

           case FORCE_VMOD_DISABLED_E:
                value =  value | FORCE_VMOD_DISABLED ;
                break;
           case FORCE_ENABLED_IN_HP_MODE_E:
                value =  value | FORCE_ENABLED_IN_HP_MODE ;
                break;
           case ALLOWS_HW_CONTROL_E:
                value =  value | ALLOWS_HW_CONTROL ;
                break;
           case FORCE_ENABLE_IN_LP_MODE_E:
                value =  value | FORCE_ENABLE_IN_LP_MODE ;
                break;
    }
  

    I2CWrite(VMOD_SUPPLY_MANAGEMENT_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_vmod_regulation
 *
 * RET  : Return the value of register 0xVmodSupplyManagement
 *
 * Notes : From register 0x440, bits 1:0
 *
 **************************************************************************/
unsigned char get_vmod_regulation()
  {
    unsigned char value;


    /* 
     * 00: force Vmod disabled 
     * 01: force enabled in HP mode 
     * 10: allows HW (internal Vmod signal) to control Vmod 
     * supply if VmodRequestCtrl[1:0]=0x. 
     * Forced in HP mode if VmodRequestCtrl[1:0]=1x 
     * 11: force enable in LP mode 
     */ 
    value = (I2CRead(VMOD_SUPPLY_MANAGEMENT_REG) & VMOD_REGULATION_MASK);
    return value;
  }


/***************************************************************************
 *
 * Function : set_vmod_selection_control
 *
 * IN   : param, a value to write to the regiter VmodSupplyManagement
 * OUT  : 
 *
 * RET  : Return the value of register 0xVmodSupplyManagement
 *
 * Notes : From register 0x440, bits 2:2
 *
 **************************************************************************/
unsigned char set_vmod_selection_control( enum vmod_selection param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(VMOD_SUPPLY_MANAGEMENT_REG);

    /* 
     * 0: Vmod output voltage is defined by VmodSel1 register 
     * 1: Vmod output voltage is defined by VmodSel2 register 
     */ 
    switch( param ){
        case VMOD_SELECT2_E: 
           value = old_value | VMOD_SELECTION_CONTROL_MASK; 
           break;
        case VMOD_SELECT1_E: 
           value = old_value & ~ VMOD_SELECTION_CONTROL_MASK;
           break;
    }
  

    I2CWrite(VMOD_SUPPLY_MANAGEMENT_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_vmod_selection_control
 *
 * RET  : Return the value of register 0xVmodSupplyManagement
 *
 * Notes : From register 0x440, bits 2:2
 *
 **************************************************************************/
unsigned char get_vmod_selection_control()
  {
    unsigned char value;


    /* 
     * 0: Vmod output voltage is defined by VmodSel1 register 
     * 1: Vmod output voltage is defined by VmodSel2 register 
     */ 
    value = (I2CRead(VMOD_SUPPLY_MANAGEMENT_REG) & VMOD_SELECTION_CONTROL_MASK) >> 2;
    return value;
  }


/***************************************************************************
 *
 * Function : set_vmod_auto_mode
 *
 * IN   : param, a value to write to the regiter VmodSupplyManagement
 * OUT  : 
 *
 * RET  : Return the value of register 0xVmodSupplyManagement
 *
 * Notes : From register 0x440, bits 3:3
 *
 **************************************************************************/
unsigned char set_vmod_auto_mode( enum vmod_auto_mode_enable param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(VMOD_SUPPLY_MANAGEMENT_REG);

    /* 
     * 0: Vmod is not in AutoMode 
     * 1: Vmod is in AutoMode 
     */ 
    switch( param ){
        case VMOD_AUTO_MODE_ENABLE_E: 
           value = old_value | VMOD_AUTO_MODE_MASK; 
           break;
        case VMOD_AUTO_MODE_DISABLE_E: 
           value = old_value & ~ VMOD_AUTO_MODE_MASK;
           break;
    }
  

    I2CWrite(VMOD_SUPPLY_MANAGEMENT_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_vmod_auto_mode
 *
 * RET  : Return the value of register 0xVmodSupplyManagement
 *
 * Notes : From register 0x440, bits 3:3
 *
 **************************************************************************/
unsigned char get_vmod_auto_mode()
  {
    unsigned char value;


    /* 
     * 0: Vmod is not in AutoMode 
     * 1: Vmod is in AutoMode 
     */ 
    value = (I2CRead(VMOD_SUPPLY_MANAGEMENT_REG) & VMOD_AUTO_MODE_MASK) >> 3;
    return value;
  }


/***************************************************************************
 *
 * Function : set_vmod_p_w_m_mode
 *
 * IN   : param, a value to write to the regiter VmodSupplyManagement
 * OUT  : 
 *
 * RET  : Return the value of register 0xVmodSupplyManagement
 *
 * Notes : From register 0x440, bits 4:4
 *
 **************************************************************************/
unsigned char set_vmod_p_w_m_mode( enum vmod_forced_enable param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(VMOD_SUPPLY_MANAGEMENT_REG);

    /* 
     * 0: inactive (Vmod can be in PWM or PFM mode) 
     * 1: Vmod is forced in PWM mode when output voltage is 
     * programm to a lower value (energy sent to the battery 
     */ 
    switch( param ){
        case VMOD_FORCED_ENABLE_E: 
           value = old_value | VMOD_PWM_MODE_MASK; 
           break;
        case VMOD_FORCED_DISABLE_E: 
           value = old_value & ~ VMOD_PWM_MODE_MASK;
           break;
    }
  

    I2CWrite(VMOD_SUPPLY_MANAGEMENT_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_vmod_p_w_m_mode
 *
 * RET  : Return the value of register 0xVmodSupplyManagement
 *
 * Notes : From register 0x440, bits 4:4
 *
 **************************************************************************/
unsigned char get_vmod_p_w_m_mode()
  {
    unsigned char value;


    /* 
     * 0: inactive (Vmod can be in PWM or PFM mode) 
     * 1: Vmod is forced in PWM mode when output voltage is 
     * programm to a lower value (energy sent to the battery 
     */ 
    value = (I2CRead(VMOD_SUPPLY_MANAGEMENT_REG) & VMOD_PWM_MODE_MASK) >> 4;
    return value;
  }


/***************************************************************************
 *
 * Function : set_mod_sys_clk_req1_valid
 *
 * IN   : param, a value to write to the regiter VmodSupplyManagement
 * OUT  : 
 *
 * RET  : Return the value of register 0xVmodSupplyManagement
 *
 * Notes : From register 0x440, bits 5:5
 *
 **************************************************************************/
unsigned char set_mod_sys_clk_req1_valid( enum modem_system_clock_request_valid param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(VMOD_SUPPLY_MANAGEMENT_REG);

    /* 
     * 0: doesn't valid SysClkReq1 input to request system clock 
     * 1: Valid SysClkReq1 input to request system clock 
     */ 
    switch( param ){
        case VALID_SYSTEM_CLOCK_E: 
           value = old_value | MOD_SYS_CLK_REQ_1_VALID_MASK; 
           break;
        case DOESNOT_VALID_SYSTEM_CLOCK_E: 
           value = old_value & ~ MOD_SYS_CLK_REQ_1_VALID_MASK;
           break;
    }
  

    I2CWrite(VMOD_SUPPLY_MANAGEMENT_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_mod_sys_clk_req1_valid
 *
 * RET  : Return the value of register 0xVmodSupplyManagement
 *
 * Notes : From register 0x440, bits 5:5
 *
 **************************************************************************/
unsigned char get_mod_sys_clk_req1_valid()
  {
    unsigned char value;


    /* 
     * 0: doesn't valid SysClkReq1 input to request system clock 
     * 1: Valid SysClkReq1 input to request system clock 
     */ 
    value = (I2CRead(VMOD_SUPPLY_MANAGEMENT_REG) & MOD_SYS_CLK_REQ_1_VALID_MASK) >> 5;
    return value;
  }


/***************************************************************************
 *
 * Function : set_vmod_resquet_control
 *
 * IN   : param, a value to write to the regiter VmodSupplyManagement
 * OUT  : 
 *
 * RET  : Return the value of register 0xVmodSupplyManagement
 *
 * Notes : From register 0x440, bits 7:6
 *
 **************************************************************************/
unsigned char set_vmod_resquet_control( enum vmod_resquet_control param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(VMOD_SUPPLY_MANAGEMENT_REG);

    /* 
     * 00: allows to set Vmod in HP/LP modes depending on 
     * VxRequest signal. 
     * 01: allows to set Vmod in HP/OFF modes depending on 
     * VxRequest signal. 
     * 1x: force Vmod in HP whatever VmodRequest signal value 
     */ 
  

     value =  old_value & ~VMOD_RESQUET_CONTROL_MASK ;

    switch(  param ){

           case ALLOWS_TO_SET_HP_LP_MODE_E:
                value  = value  | (ALLOWS_TO_SET_HP_LP_MODE << 0x6);
                break;
           case ALLOWS_TO_SET_HP_OFF_MODE_E:
                value  = value  | (ALLOWS_TO_SET_HP_OFF_MODE << 0x6);
                break;
           case FORCE_VMOD_IN_HP_E:
                value  = value  | (FORCE_VMOD_IN_HP << 0x6);
                break;
    }
  

    I2CWrite(VMOD_SUPPLY_MANAGEMENT_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_vmod_resquet_control
 *
 * RET  : Return the value of register 0xVmodSupplyManagement
 *
 * Notes : From register 0x440, bits 7:6
 *
 **************************************************************************/
unsigned char get_vmod_resquet_control()
  {
    unsigned char value;


    /* 
     * 00: allows to set Vmod in HP/LP modes depending on 
     * VxRequest signal. 
     * 01: allows to set Vmod in HP/OFF modes depending on 
     * VxRequest signal. 
     * 1x: force Vmod in HP whatever VmodRequest signal value 
     */ 
    value = (I2CRead(VMOD_SUPPLY_MANAGEMENT_REG) & VMOD_RESQUET_CONTROL_MASK) >> 6;
    return value;
  }


/***************************************************************************
 *
 * Function : set_vmod_sel1_output
 *
 * IN   : param, a value to write to the regiter VmodSel1Output
 * OUT  : 
 *
 * RET  : Return the value of register 0xVmodSel1Output
 *
 * Notes : From register 0x441, bits 5:0
 *
 **************************************************************************/
unsigned char set_vmod_sel1_output( enum output_supply param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(VMOD_SEL_1_OUTPUT_REG);

    /* 
     * Defined VmodSel1 output voltage from 0.7V to 1.3625V by 
     * 12.5mV step and from 1.8 to 1.875 by 12.5 mV step 
     */ 
  
    value =  old_value & ~VMOD_SEL_1_OUTPUT_MASK;


    value |=  param ;  
    I2CWrite(VMOD_SEL_1_OUTPUT_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_vmod_sel1_output
 *
 * RET  : Return the value of register 0xVmodSel1Output
 *
 * Notes : From register 0x441, bits 5:0
 *
 **************************************************************************/
unsigned char get_vmod_sel1_output()
  {
    unsigned char value;


    /* 
     * Defined VmodSel1 output voltage from 0.7V to 1.3625V by 
     * 12.5mV step and from 1.8 to 1.875 by 12.5 mV step 
     */ 
    value = (I2CRead(VMOD_SEL_1_OUTPUT_REG) & VMOD_SEL_1_OUTPUT_MASK);
    return value;
  }


/***************************************************************************
 *
 * Function : set_vmod_sel2_output
 *
 * IN   : param, a value to write to the regiter VmodSel2Output
 * OUT  : 
 *
 * RET  : Return the value of register 0xVmodSel2Output
 *
 * Notes : From register 0x442, bits 5:0
 *
 **************************************************************************/
unsigned char set_vmod_sel2_output( enum output_supply param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(VMOD_SEL_2_OUTPUT_REG);

    /* 
     * Defined VmodSel2 output voltage from 0.7V to 1.3625V by 
     * 12.5mV step and from 1.8 to 1.875 by 12.5 mV step 
     */ 
  
    value =  old_value & ~VMOD_SEL_2_OUTPUT_MASK;


    value |=  param ;  
    I2CWrite(VMOD_SEL_2_OUTPUT_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_vmod_sel2_output
 *
 * RET  : Return the value of register 0xVmodSel2Output
 *
 * Notes : From register 0x442, bits 5:0
 *
 **************************************************************************/
unsigned char get_vmod_sel2_output()
  {
    unsigned char value;


    /* 
     * Defined VmodSel2 output voltage from 0.7V to 1.3625V by 
     * 12.5mV step and from 1.8 to 1.875 by 12.5 mV step 
     */ 
    value = (I2CRead(VMOD_SEL_2_OUTPUT_REG) & VMOD_SEL_2_OUTPUT_MASK);
    return value;
  }


/***************************************************************************
 *
 * Function : set_vpll_discharge_time
 *
 * IN   : param, a value to write to the regiter SupplyDischargeTime
 * OUT  : 
 *
 * RET  : Return the value of register 0xSupplyDischargeTime
 *
 * Notes : From register 0x443, bits 0:0
 *
 **************************************************************************/
unsigned char set_vpll_discharge_time( enum supply_discharge_time param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(SUPPLY_DISCHARGE_TIME_REG);

    /* 
     * 0: short discharge time when disabled 
     * 1: long discharge time when disabled 
     */ 
    switch( param ){
        case SHORT_DISCHARGE_TIME_E: 
           value = old_value | VPLL_DISCHARGE_TIME_MASK; 
           break;
        case LONG_DISCHARGE_TIME_E: 
           value = old_value & ~ VPLL_DISCHARGE_TIME_MASK;
           break;
    }
  

    I2CWrite(SUPPLY_DISCHARGE_TIME_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_vpll_discharge_time
 *
 * RET  : Return the value of register 0xSupplyDischargeTime
 *
 * Notes : From register 0x443, bits 0:0
 *
 **************************************************************************/
unsigned char get_vpll_discharge_time()
  {
    unsigned char value;


    /* 
     * 0: short discharge time when disabled 
     * 1: long discharge time when disabled 
     */ 
    value = (I2CRead(SUPPLY_DISCHARGE_TIME_REG) & VPLL_DISCHARGE_TIME_MASK);
    return value;
  }


/***************************************************************************
 *
 * Function : set_vrf1_discharge_time
 *
 * IN   : param, a value to write to the regiter SupplyDischargeTime
 * OUT  : 
 *
 * RET  : Return the value of register 0xSupplyDischargeTime
 *
 * Notes : From register 0x443, bits 1:1
 *
 **************************************************************************/
unsigned char set_vrf1_discharge_time( enum supply_discharge_time param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(SUPPLY_DISCHARGE_TIME_REG);

    /* 
     * 0: short discharge time when disabled 
     * 1: long discharge time when disabled 
     */ 
    switch( param ){
        case SHORT_DISCHARGE_TIME_E: 
           value = old_value | VRF_1_DISCHARGE_TIME_MASK; 
           break;
        case LONG_DISCHARGE_TIME_E: 
           value = old_value & ~ VRF_1_DISCHARGE_TIME_MASK;
           break;
    }
  

    I2CWrite(SUPPLY_DISCHARGE_TIME_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_vrf1_discharge_time
 *
 * RET  : Return the value of register 0xSupplyDischargeTime
 *
 * Notes : From register 0x443, bits 1:1
 *
 **************************************************************************/
unsigned char get_vrf1_discharge_time()
  {
    unsigned char value;


    /* 
     * 0: short discharge time when disabled 
     * 1: long discharge time when disabled 
     */ 
    value = (I2CRead(SUPPLY_DISCHARGE_TIME_REG) & VRF_1_DISCHARGE_TIME_MASK) >> 1;
    return value;
  }


/***************************************************************************
 *
 * Function : set_vaux1_discharge_time
 *
 * IN   : param, a value to write to the regiter SupplyDischargeTime
 * OUT  : 
 *
 * RET  : Return the value of register 0xSupplyDischargeTime
 *
 * Notes : From register 0x443, bits 2:2
 *
 **************************************************************************/
unsigned char set_vaux1_discharge_time( enum supply_discharge_time param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(SUPPLY_DISCHARGE_TIME_REG);

    /* 
     * 0: short discharge time when disabled 
     * 1: long discharge time when disabled 
     */ 
    switch( param ){
        case SHORT_DISCHARGE_TIME_E: 
           value = old_value | VAUX_1_DISCHARGE_TIME_MASK; 
           break;
        case LONG_DISCHARGE_TIME_E: 
           value = old_value & ~ VAUX_1_DISCHARGE_TIME_MASK;
           break;
    }
  

    I2CWrite(SUPPLY_DISCHARGE_TIME_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_vaux1_discharge_time
 *
 * RET  : Return the value of register 0xSupplyDischargeTime
 *
 * Notes : From register 0x443, bits 2:2
 *
 **************************************************************************/
unsigned char get_vaux1_discharge_time()
  {
    unsigned char value;


    /* 
     * 0: short discharge time when disabled 
     * 1: long discharge time when disabled 
     */ 
    value = (I2CRead(SUPPLY_DISCHARGE_TIME_REG) & VAUX_1_DISCHARGE_TIME_MASK) >> 2;
    return value;
  }


/***************************************************************************
 *
 * Function : set_vaux2_discharge_time
 *
 * IN   : param, a value to write to the regiter SupplyDischargeTime
 * OUT  : 
 *
 * RET  : Return the value of register 0xSupplyDischargeTime
 *
 * Notes : From register 0x443, bits 3:3
 *
 **************************************************************************/
unsigned char set_vaux2_discharge_time( enum supply_discharge_time param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(SUPPLY_DISCHARGE_TIME_REG);

    /* 
     * 0: short discharge time when disabled 
     * 1: long discharge time when disabled 
     */ 
    switch( param ){
        case SHORT_DISCHARGE_TIME_E: 
           value = old_value | VAUX_2_DISCHARGE_TIME_MASK; 
           break;
        case LONG_DISCHARGE_TIME_E: 
           value = old_value & ~ VAUX_2_DISCHARGE_TIME_MASK;
           break;
    }
  

    I2CWrite(SUPPLY_DISCHARGE_TIME_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_vaux2_discharge_time
 *
 * RET  : Return the value of register 0xSupplyDischargeTime
 *
 * Notes : From register 0x443, bits 3:3
 *
 **************************************************************************/
unsigned char get_vaux2_discharge_time()
  {
    unsigned char value;


    /* 
     * 0: short discharge time when disabled 
     * 1: long discharge time when disabled 
     */ 
    value = (I2CRead(SUPPLY_DISCHARGE_TIME_REG) & VAUX_2_DISCHARGE_TIME_MASK) >> 3;
    return value;
  }


/***************************************************************************
 *
 * Function : set_vint_core12_discharge_time
 *
 * IN   : param, a value to write to the regiter SupplyDischargeTime
 * OUT  : 
 *
 * RET  : Return the value of register 0xSupplyDischargeTime
 *
 * Notes : From register 0x443, bits 5:5
 *
 **************************************************************************/
unsigned char set_vint_core12_discharge_time( enum supply_discharge_time param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(SUPPLY_DISCHARGE_TIME_REG);

    /* 
     * 0: short discharge time when disabled 
     * 1: long discharge time when disabled 
     */ 
    switch( param ){
        case SHORT_DISCHARGE_TIME_E: 
           value = old_value | VINT_CORE_12_DISCHARGE_TIME_MASK; 
           break;
        case LONG_DISCHARGE_TIME_E: 
           value = old_value & ~ VINT_CORE_12_DISCHARGE_TIME_MASK;
           break;
    }
  

    I2CWrite(SUPPLY_DISCHARGE_TIME_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_vint_core12_discharge_time
 *
 * RET  : Return the value of register 0xSupplyDischargeTime
 *
 * Notes : From register 0x443, bits 5:5
 *
 **************************************************************************/
unsigned char get_vint_core12_discharge_time()
  {
    unsigned char value;


    /* 
     * 0: short discharge time when disabled 
     * 1: long discharge time when disabled 
     */ 
    value = (I2CRead(SUPPLY_DISCHARGE_TIME_REG) & VINT_CORE_12_DISCHARGE_TIME_MASK) >> 5;
    return value;
  }


/***************************************************************************
 *
 * Function : set_vtv_out_discharge_time
 *
 * IN   : param, a value to write to the regiter SupplyDischargeTime
 * OUT  : 
 *
 * RET  : Return the value of register 0xSupplyDischargeTime
 *
 * Notes : From register 0x443, bits 6:6
 *
 **************************************************************************/
unsigned char set_vtv_out_discharge_time( enum supply_discharge_time param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(SUPPLY_DISCHARGE_TIME_REG);

    /* 
     * 0: short discharge time when disabled 
     * 1: long discharge time when disabled 
     */ 
    switch( param ){
        case SHORT_DISCHARGE_TIME_E: 
           value = old_value | VTV_OUT_DISCHARGE_TIME_MASK; 
           break;
        case LONG_DISCHARGE_TIME_E: 
           value = old_value & ~ VTV_OUT_DISCHARGE_TIME_MASK;
           break;
    }
  

    I2CWrite(SUPPLY_DISCHARGE_TIME_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_vtv_out_discharge_time
 *
 * RET  : Return the value of register 0xSupplyDischargeTime
 *
 * Notes : From register 0x443, bits 6:6
 *
 **************************************************************************/
unsigned char get_vtv_out_discharge_time()
  {
    unsigned char value;


    /* 
     * 0: short discharge time when disabled 
     * 1: long discharge time when disabled 
     */ 
    value = (I2CRead(SUPPLY_DISCHARGE_TIME_REG) & VTV_OUT_DISCHARGE_TIME_MASK) >> 6;
    return value;
  }


/***************************************************************************
 *
 * Function : set_vaudio_discharge_time
 *
 * IN   : param, a value to write to the regiter SupplyDischargeTime
 * OUT  : 
 *
 * RET  : Return the value of register 0xSupplyDischargeTime
 *
 * Notes : From register 0x443, bits 7:7
 *
 **************************************************************************/
unsigned char set_vaudio_discharge_time( enum supply_discharge_time param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(SUPPLY_DISCHARGE_TIME_REG);

    /* 
     * 0: short discharge time when disabled 
     * 1: long discharge time when disabled 
     */ 
    switch( param ){
        case SHORT_DISCHARGE_TIME_E: 
           value = old_value | VAUDIO_DISCHARGE_TIME_MASK; 
           break;
        case LONG_DISCHARGE_TIME_E: 
           value = old_value & ~ VAUDIO_DISCHARGE_TIME_MASK;
           break;
    }
  

    I2CWrite(SUPPLY_DISCHARGE_TIME_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_vaudio_discharge_time
 *
 * RET  : Return the value of register 0xSupplyDischargeTime
 *
 * Notes : From register 0x443, bits 7:7
 *
 **************************************************************************/
unsigned char get_vaudio_discharge_time()
  {
    unsigned char value;


    /* 
     * 0: short discharge time when disabled 
     * 1: long discharge time when disabled 
     */ 
    value = (I2CRead(SUPPLY_DISCHARGE_TIME_REG) & VAUDIO_DISCHARGE_TIME_MASK) >> 7;
    return value;
  }


/***************************************************************************
 *
 * Function : set_vsim_discharge_time
 *
 * IN   : param, a value to write to the regiter SupplyDischargeTime2
 * OUT  : 
 *
 * RET  : Return the value of register 0xSupplyDischargeTime2
 *
 * Notes : From register 0x444, bits 0:0
 *
 **************************************************************************/
unsigned char set_vsim_discharge_time( enum supply_discharge_time param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(SUPPLY_DISCHARGE_TIME_2_REG);

    /* 
     * 0: short discharge time when disabled 
     * 1: long discharge time when disabled 
     */ 
    switch( param ){
        case SHORT_DISCHARGE_TIME_E: 
           value = old_value | VSIM_DISCHARGE_TIME_MASK; 
           break;
        case LONG_DISCHARGE_TIME_E: 
           value = old_value & ~ VSIM_DISCHARGE_TIME_MASK;
           break;
    }
  

    I2CWrite(SUPPLY_DISCHARGE_TIME_2_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_vsim_discharge_time
 *
 * RET  : Return the value of register 0xSupplyDischargeTime2
 *
 * Notes : From register 0x444, bits 0:0
 *
 **************************************************************************/
unsigned char get_vsim_discharge_time()
  {
    unsigned char value;


    /* 
     * 0: short discharge time when disabled 
     * 1: long discharge time when disabled 
     */ 
    value = (I2CRead(SUPPLY_DISCHARGE_TIME_2_REG) & VSIM_DISCHARGE_TIME_MASK);
    return value;
  }


/***************************************************************************
 *
 * Function : set_vana_discharge_time
 *
 * IN   : param, a value to write to the regiter SupplyDischargeTime2
 * OUT  : 
 *
 * RET  : Return the value of register 0xSupplyDischargeTime2
 *
 * Notes : From register 0x444, bits 1:1
 *
 **************************************************************************/
unsigned char set_vana_discharge_time( enum supply_discharge_time param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(SUPPLY_DISCHARGE_TIME_2_REG);

    /* 
     * 0: short discharge time when disabled 
     * 1: long discharge time when disabled 
     */ 
    switch( param ){
        case SHORT_DISCHARGE_TIME_E: 
           value = old_value | VANA_DISCHARGE_TIME_MASK; 
           break;
        case LONG_DISCHARGE_TIME_E: 
           value = old_value & ~ VANA_DISCHARGE_TIME_MASK;
           break;
    }
  

    I2CWrite(SUPPLY_DISCHARGE_TIME_2_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_vana_discharge_time
 *
 * RET  : Return the value of register 0xSupplyDischargeTime2
 *
 * Notes : From register 0x444, bits 1:1
 *
 **************************************************************************/
unsigned char get_vana_discharge_time()
  {
    unsigned char value;


    /* 
     * 0: short discharge time when disabled 
     * 1: long discharge time when disabled 
     */ 
    value = (I2CRead(SUPPLY_DISCHARGE_TIME_2_REG) & VANA_DISCHARGE_TIME_MASK) >> 1;
    return value;
  }


/***************************************************************************
 *
 * Function : set_vdmic_pull_down
 *
 * IN   : param, a value to write to the regiter SupplyDischargeTime2
 * OUT  : 
 *
 * RET  : Return the value of register 0xSupplyDischargeTime2
 *
 * Notes : From register 0x444, bits 2:2
 *
 **************************************************************************/
unsigned char set_vdmic_pull_down( enum vdmic_pull_down_enable param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(SUPPLY_DISCHARGE_TIME_2_REG);

    /* 
     * 0: When Vdmic is disabled, pull down is disabled 
     * 1: When Vdmic is disabled, pull down is enabled 
     */ 
    switch( param ){
        case VDMIC_PULL_DOWN_ENABLE_E: 
           value = old_value | VDMIC_PULL_DOWN_MASK; 
           break;
        case VDMIC_PULL_DOWN_DISABLE_E: 
           value = old_value & ~ VDMIC_PULL_DOWN_MASK;
           break;
    }
  

    I2CWrite(SUPPLY_DISCHARGE_TIME_2_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_vdmic_pull_down
 *
 * RET  : Return the value of register 0xSupplyDischargeTime2
 *
 * Notes : From register 0x444, bits 2:2
 *
 **************************************************************************/
unsigned char get_vdmic_pull_down()
  {
    unsigned char value;


    /* 
     * 0: When Vdmic is disabled, pull down is disabled 
     * 1: When Vdmic is disabled, pull down is enabled 
     */ 
    value = (I2CRead(SUPPLY_DISCHARGE_TIME_2_REG) & VDMIC_PULL_DOWN_MASK) >> 2;
    return value;
  }


/***************************************************************************
 *
 * Function : set_vpll_pull_down
 *
 * IN   : param, a value to write to the regiter SupplyDischargeTime2
 * OUT  : 
 *
 * RET  : Return the value of register 0xSupplyDischargeTime2
 *
 * Notes : From register 0x444, bits 3:3
 *
 **************************************************************************/
unsigned char set_vpll_pull_down( enum vpll_pull_down_enable param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(SUPPLY_DISCHARGE_TIME_2_REG);

    /* 
     * 0: When Vpll is disabled, pull down is disabled 
     * 1: When Vpll is disabled, pull down is enabled 
     */ 
    switch( param ){
        case VPLL_PULL_DOWN_ENABLE_E: 
           value = old_value | VPLL_PULL_DOWN_MASK; 
           break;
        case VPLL_PULL_DOWN_DISABLE_E: 
           value = old_value & ~ VPLL_PULL_DOWN_MASK;
           break;
    }
  

    I2CWrite(SUPPLY_DISCHARGE_TIME_2_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_vpll_pull_down
 *
 * RET  : Return the value of register 0xSupplyDischargeTime2
 *
 * Notes : From register 0x444, bits 3:3
 *
 **************************************************************************/
unsigned char get_vpll_pull_down()
  {
    unsigned char value;


    /* 
     * 0: When Vpll is disabled, pull down is disabled 
     * 1: When Vpll is disabled, pull down is enabled 
     */ 
    value = (I2CRead(SUPPLY_DISCHARGE_TIME_2_REG) & VPLL_PULL_DOWN_MASK) >> 3;
    return value;
  }


/***************************************************************************
 *
 * Function : set_vdmic_discharge_time
 *
 * IN   : param, a value to write to the regiter SupplyDischargeTime2
 * OUT  : 
 *
 * RET  : Return the value of register 0xSupplyDischargeTime2
 *
 * Notes : From register 0x444, bits 4:4
 *
 **************************************************************************/
unsigned char set_vdmic_discharge_time( enum supply_discharge_time param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(SUPPLY_DISCHARGE_TIME_2_REG);

    /* 
     * 0: short discharge time when disabled 
     * 1: long discharge time when disabled 
     */ 
    switch( param ){
        case SHORT_DISCHARGE_TIME_E: 
           value = old_value | VDMIC_DISCHARGE_TIME_MASK; 
           break;
        case LONG_DISCHARGE_TIME_E: 
           value = old_value & ~ VDMIC_DISCHARGE_TIME_MASK;
           break;
    }
  

    I2CWrite(SUPPLY_DISCHARGE_TIME_2_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_vdmic_discharge_time
 *
 * RET  : Return the value of register 0xSupplyDischargeTime2
 *
 * Notes : From register 0x444, bits 4:4
 *
 **************************************************************************/
unsigned char get_vdmic_discharge_time()
  {
    unsigned char value;


    /* 
     * 0: short discharge time when disabled 
     * 1: long discharge time when disabled 
     */ 
    value = (I2CRead(SUPPLY_DISCHARGE_TIME_2_REG) & VDMIC_DISCHARGE_TIME_MASK) >> 4;
    return value;
  }




#ifdef __cplusplus
}
#endif

#endif
