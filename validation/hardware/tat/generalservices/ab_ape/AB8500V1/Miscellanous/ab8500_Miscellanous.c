/****************************************************************************
 * File : c:/Lisp/Production/ab8500/ab8500_Miscellanous/Linux/ab8500_Miscellanous.c
 * 
 *
 * Generated on the 26/02/2010 09:22 by the 'gen-I2C' code generator 
 *
 * Generator written in Common Lisp, created by  R�mi PRUD'HOMME - ST 
 * with the help of : Gr�gory GOSCINIACK - ST, Ir�n�e BROCHIER - Teamlog
 *
 ***************************************************************************
 *  Copyrigtht ST Microelectronics  2009
 ***************************************************************************/
#include "ab8500_Miscellanous.h"

extern unsigned char SPIRead( unsigned short register_address);
extern void SPIWrite( unsigned short register_address, unsigned char data );


/***************************************************************************
 *
 * Function : set_ape_i2c_data_pullup
 *
 * IN   : param, a value to write to the regiter I2cPadControl
 * OUT  : 
 *
 * RET  : Return the value of register I2cPadControl
 *
 * Notes : From register 0x1067, bits 3:3
 *
 **************************************************************************/
unsigned char set_ape_i2c_data_pullup( enum ape_i2c_data_pullup_enable param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = SPIRead(I_2C_PAD_CONTROL_REG);

    /* 
     * 0: enable internal pull-up 
     * 1: Disable internal pull-up 
     */ 
    switch( param )
      {
        case APE_I_2C_DATA_PULLUP_DISABLE_E: 
           value = old_value | APE_I_2C_DATA_PULLUP_ENABLE_PARAM_MASK; 
           break;
        case APE_I_2C_DATA_PULLUP_ENABLE_E: 
           value = old_value & ~ APE_I_2C_DATA_PULLUP_ENABLE_PARAM_MASK;
           break;
      }
  

    SPIWrite(I_2C_PAD_CONTROL_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_ape_i2c_data_pullup
 *
 * RET  : Return the value of register I2cPadControl
 *
 * Notes : From register 0x1067, bits 3:3
 *
 **************************************************************************/
unsigned char get_ape_i2c_data_pullup()
  {
    unsigned char value;


    /* 
     * 0: enable internal pull-up 
     * 1: Disable internal pull-up 
     */ 
    value = (SPIRead(I_2C_PAD_CONTROL_REG) & APE_I_2C_DATA_PULLUP_ENABLE_PARAM_MASK) >> 3;
    return value;
  }


/***************************************************************************
 *
 * Function : set_ape_i2c_clock_pullup
 *
 * IN   : param, a value to write to the regiter I2cPadControl
 * OUT  : 
 *
 * RET  : Return the value of register I2cPadControl
 *
 * Notes : From register 0x1067, bits 2:2
 *
 **************************************************************************/
unsigned char set_ape_i2c_clock_pullup( enum ape_i2c_clock_pullup_enable param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = SPIRead(I_2C_PAD_CONTROL_REG);

    /* 
     * 0: enable internal pull-up 
     * 1: Disable internal pull-up 
     */ 
    switch( param )
      {
        case APE_I_2C_CLOCK_PULLUP_DISABLE_E: 
           value = old_value | APE_I_2C_CLOCK_PULLUP_ENABLE_PARAM_MASK; 
           break;
        case APE_I_2C_CLOCK_PULLUP_ENABLE_E: 
           value = old_value & ~ APE_I_2C_CLOCK_PULLUP_ENABLE_PARAM_MASK;
           break;
      }
  

    SPIWrite(I_2C_PAD_CONTROL_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_ape_i2c_clock_pullup
 *
 * RET  : Return the value of register I2cPadControl
 *
 * Notes : From register 0x1067, bits 2:2
 *
 **************************************************************************/
unsigned char get_ape_i2c_clock_pullup()
  {
    unsigned char value;


    /* 
     * 0: enable internal pull-up 
     * 1: Disable internal pull-up 
     */ 
    value = (SPIRead(I_2C_PAD_CONTROL_REG) & APE_I_2C_CLOCK_PULLUP_ENABLE_PARAM_MASK) >> 2;
    return value;
  }


/***************************************************************************
 *
 * Function : set_modem_i2c_data_pullup
 *
 * IN   : param, a value to write to the regiter I2cPadControl
 * OUT  : 
 *
 * RET  : Return the value of register I2cPadControl
 *
 * Notes : From register 0x1067, bits 1:1
 *
 **************************************************************************/
unsigned char set_modem_i2c_data_pullup( enum modem_i2c_data_pullup_enable param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = SPIRead(I_2C_PAD_CONTROL_REG);

    /* 
     * 0: enable internal pull-up 
     * 1: Disable internal pull-up 
     */ 
    switch( param )
      {
        case MODEM_I_2C_DATA_PULLUP_DISABLE_E: 
           value = old_value | MODEM_I_2C_DATA_PULLUP_ENABLE_PARAM_MASK; 
           break;
        case MODEM_I_2C_DATA_PULLUP_ENABLE_E: 
           value = old_value & ~ MODEM_I_2C_DATA_PULLUP_ENABLE_PARAM_MASK;
           break;
      }
  

    SPIWrite(I_2C_PAD_CONTROL_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_modem_i2c_data_pullup
 *
 * RET  : Return the value of register I2cPadControl
 *
 * Notes : From register 0x1067, bits 1:1
 *
 **************************************************************************/
unsigned char get_modem_i2c_data_pullup()
  {
    unsigned char value;


    /* 
     * 0: enable internal pull-up 
     * 1: Disable internal pull-up 
     */ 
    value = (SPIRead(I_2C_PAD_CONTROL_REG) & MODEM_I_2C_DATA_PULLUP_ENABLE_PARAM_MASK) >> 1;
    return value;
  }


/***************************************************************************
 *
 * Function : set_modem_i2c_clock_pullup
 *
 * IN   : param, a value to write to the regiter I2cPadControl
 * OUT  : 
 *
 * RET  : Return the value of register I2cPadControl
 *
 * Notes : From register 0x1067, bits 0:0
 *
 **************************************************************************/
unsigned char set_modem_i2c_clock_pullup( enum modem_i2c_pullup_enable param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = SPIRead(I_2C_PAD_CONTROL_REG);

    /* 
     * 0: enable internal pull-up 
     * 1: Disable internal pull-up 
     */ 
    switch( param )
      {
        case MODEM_I_2C_PULLUP_DISABLE_E: 
           value = old_value | MODEM_I_2C_PULLUP_ENABLE_PARAM_MASK; 
           break;
        case MODEM_I_2C_PULLUP_ENABLE_E: 
           value = old_value & ~ MODEM_I_2C_PULLUP_ENABLE_PARAM_MASK;
           break;
      }
  

    SPIWrite(I_2C_PAD_CONTROL_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_modem_i2c_clock_pullup
 *
 * RET  : Return the value of register I2cPadControl
 *
 * Notes : From register 0x1067, bits 0:0
 *
 **************************************************************************/
unsigned char get_modem_i2c_clock_pullup()
  {
    unsigned char value;


    /* 
     * 0: enable internal pull-up 
     * 1: Disable internal pull-up 
     */ 
    value = (SPIRead(I_2C_PAD_CONTROL_REG) & MODEM_I_2C_PULLUP_ENABLE_PARAM_MASK);
    return value;
  }


/***************************************************************************
 *
 * Function : get_full_mask_set_revision
 *
 * RET  : Return the value of register stw4500Revision
 *
 * Notes : From register 0x1080, bits 7:4
 *
 **************************************************************************/
unsigned char get_full_mask_set_revision()
  {
    unsigned char value;


    /* 
     * Full mask set revision 
     */ 
    value = (SPIRead(STW_4500_REVISION_REG) & FULL_MASK_REVISION_PARAM_MASK) >> 4;
    return value;
  }


/***************************************************************************
 *
 * Function : get_metal_fix_revision
 *
 * RET  : Return the value of register stw4500Revision
 *
 * Notes : From register 0x1080, bits 3:0
 *
 **************************************************************************/
unsigned char get_metal_fix_revision()
  {
    unsigned char value;


    /* 
     * Full mask set revision 
     */ 
    value = (SPIRead(STW_4500_REVISION_REG) & METAL_REVISION_PARAM_MASK);
    return value;
  }


