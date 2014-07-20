/****************************************************************************
 * File : c:/Lisp/Production/ab8500_V2/ab8500_TVOut/Linux/ab8500_TVOut.c
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
#include "ab8500_TVOut.h"

extern unsigned char I2CRead( unsigned short register_address);
extern void I2CWrite( unsigned short register_address, unsigned char data );


/***************************************************************************
 *
 * Function : set_tvout_standard
 *
 * IN   : param, a value to write to the regiter TvoutConfiguration0
 * OUT  : 
 *
 * RET  : Return the value of register TvoutConfiguration0
 *
 * Notes : From register 0x0600, bits 7:6
 *
 **************************************************************************/
unsigned char set_tvout_standard( void )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(TVOUT_CONFIGURATION_0_REG);

    /* 
     * TVOut standard selection 
     */ 
    I2CWrite(TVOUT_CONFIGURATION_0_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_tvout_standard
 *
 * RET  : Return the value of register TvoutConfiguration0
 *
 * Notes : From register 0x0600, bits 7:6
 *
 **************************************************************************/
unsigned char get_tvout_standard()
  {
    unsigned char value;


    /* 
     * TVOut standard selection 
     */ 
    value = (I2CRead(TVOUT_CONFIGURATION_0_REG) & TVOUT_STANDARD_PARAM_MASK) >> 6;
    return value;
  }


/***************************************************************************
 *
 * Function : set_tvout_synchro_mode
 *
 * IN   : param, a value to write to the regiter TvoutConfiguration0
 * OUT  : 
 *
 * RET  : Return the value of register TvoutConfiguration0
 *
 * Notes : From register 0x0600, bits 5:3
 *
 **************************************************************************/
unsigned char set_tvout_synchro_mode( void )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(TVOUT_CONFIGURATION_0_REG);

    /* 
     * TVOut synchro mode selection 
     */ 
    I2CWrite(TVOUT_CONFIGURATION_0_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_tvout_synchro_mode
 *
 * RET  : Return the value of register TvoutConfiguration0
 *
 * Notes : From register 0x0600, bits 5:3
 *
 **************************************************************************/
unsigned char get_tvout_synchro_mode()
  {
    unsigned char value;


    /* 
     * TVOut synchro mode selection 
     */ 
    value = (I2CRead(TVOUT_CONFIGURATION_0_REG) & TVOUT_SYNCHRO_MODE_PARAM_MASK) >> 3;
    return value;
  }


/***************************************************************************
 *
 * Function : set_soft_reset
 *
 * IN   : param, a value to write to the regiter TvoutConfiguration6
 * OUT  : 
 *
 * RET  : Return the value of register TvoutConfiguration6
 *
 * Notes : From register 0x0606, bits 7:7
 *
 **************************************************************************/
unsigned char set_soft_reset( enum soft_reset param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(TVOUT_CONFIGURATION_6_REG);

    /* 
     * Software reset. Automatically reset after internal reset 
     * generation. Active during 4 
     * PIX_CLK periods. When softreset is activated, all the 
     * device is reset as with hardware reset 
     * except for the first nine user registers 
     */ 
    switch( param ){
        case SOFT_RESET_E: 
           value = old_value | SOFT_RESET_PARAM_MASK; 
           break;
        case SOFT_UN_RESET_E: 
           value = old_value & ~ SOFT_RESET_PARAM_MASK;
           break;
    }
  

    I2CWrite(TVOUT_CONFIGURATION_6_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_soft_reset
 *
 * RET  : Return the value of register TvoutConfiguration6
 *
 * Notes : From register 0x0606, bits 7:7
 *
 **************************************************************************/
unsigned char get_soft_reset()
  {
    unsigned char value;


    /* 
     * Software reset. Automatically reset after internal reset 
     * generation. Active during 4 
     * PIX_CLK periods. When softreset is activated, all the 
     * device is reset as with hardware reset 
     * except for the first nine user registers 
     */ 
    value = (I2CRead(TVOUT_CONFIGURATION_6_REG) & SOFT_RESET_PARAM_MASK) >> 7;
    return value;
  }


/***************************************************************************
 *
 * Function : set_jump_enable
 *
 * IN   : param, a value to write to the regiter TvoutConfiguration6
 * OUT  : 
 *
 * RET  : Return the value of register TvoutConfiguration6
 *
 * Notes : From register 0x0606, bits 6:6
 *
 **************************************************************************/
unsigned char set_jump_enable( enum jump_enable param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(TVOUT_CONFIGURATION_6_REG);

    /* 
     * 00: normal mode (no line skip/insert capability) 
     * ITU-R (CCIR): 313/312 or 263/262 
     * non-interlaced: 312/312 or 262/262 
     * 0x1: manual mode for: 
     * line insert ('dec_ninc'=0) or, skip ('dec_ninc'=1) 
     * capability. Both fields of all the frames following the 
     * writing of this value 
     * are modified according to 'lref[8:0]' and 'ltarg[8:0]' 
     * bits of line_reg1 to line_reg3 registers (by default, 
     * "lref[8:0]"=000000000 and "ltarg[8:0]"=000000001 which 
     * leads to normal mode above). 
     * 100: automatic line insert mode. The 2nd field of the 
     * frame following the writing of this value is increased. 
     * Line insertion is done after line 245 in 525/60 and after 
     * line 290 in 625/50. "lref[8:0]" and "ltarg[8:0]" are 
     * ignored. bit 'jump' is automatically reset after use. Two 
     * lines are skipped (inserted) in 525/60 and four lines in 
     * 625/50 standards. 
     * 110: automatic line skip mode. The 2nd field of the frame 
     * following the writing of this value is decreased. Line 
     * suppression is done after line 245 in 525/60 and after 
     * line 290 in 625/50. "lref[8:0]" and "ltarg[8:0]" are 
     * ignored. Bit 'jump' is automatically reset after use. Two 
     * lines are skipped (inserted) in 525/60 and four lines in 
     * 625/50 standards. 
     * 1x1: must not be used. 
     */ 
    switch( param ){
        case JUMP_ENABLE_E: 
           value = old_value | JUMP_ENABLE_PARAM_MASK; 
           break;
        case JUMP_DISABLE_E: 
           value = old_value & ~ JUMP_ENABLE_PARAM_MASK;
           break;
    }
  

    I2CWrite(TVOUT_CONFIGURATION_6_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_jump_enable
 *
 * RET  : Return the value of register TvoutConfiguration6
 *
 * Notes : From register 0x0606, bits 6:6
 *
 **************************************************************************/
unsigned char get_jump_enable()
  {
    unsigned char value;


    /* 
     * 00: normal mode (no line skip/insert capability) 
     * ITU-R (CCIR): 313/312 or 263/262 
     * non-interlaced: 312/312 or 262/262 
     * 0x1: manual mode for: 
     * line insert ('dec_ninc'=0) or, skip ('dec_ninc'=1) 
     * capability. Both fields of all the frames following the 
     * writing of this value 
     * are modified according to 'lref[8:0]' and 'ltarg[8:0]' 
     * bits of line_reg1 to line_reg3 registers (by default, 
     * "lref[8:0]"=000000000 and "ltarg[8:0]"=000000001 which 
     * leads to normal mode above). 
     * 100: automatic line insert mode. The 2nd field of the 
     * frame following the writing of this value is increased. 
     * Line insertion is done after line 245 in 525/60 and after 
     * line 290 in 625/50. "lref[8:0]" and "ltarg[8:0]" are 
     * ignored. bit 'jump' is automatically reset after use. Two 
     * lines are skipped (inserted) in 525/60 and four lines in 
     * 625/50 standards. 
     * 110: automatic line skip mode. The 2nd field of the frame 
     * following the writing of this value is decreased. Line 
     * suppression is done after line 245 in 525/60 and after 
     * line 290 in 625/50. "lref[8:0]" and "ltarg[8:0]" are 
     * ignored. Bit 'jump' is automatically reset after use. Two 
     * lines are skipped (inserted) in 525/60 and four lines in 
     * 625/50 standards. 
     * 1x1: must not be used. 
     */ 
    value = (I2CRead(TVOUT_CONFIGURATION_6_REG) & JUMP_ENABLE_PARAM_MASK) >> 6;
    return value;
  }


/***************************************************************************
 *
 * Function : set_dec_ninc_enable
 *
 * IN   : param, a value to write to the regiter TvoutConfiguration6
 * OUT  : 
 *
 * RET  : Return the value of register TvoutConfiguration6
 *
 * Notes : From register 0x0606, bits 5:5
 *
 **************************************************************************/
unsigned char set_dec_ninc_enable( enum dec_ninc_enable param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(TVOUT_CONFIGURATION_6_REG);

    /* 
     * 00: normal mode (no line skip/insert capability) 
     * ITU-R (CCIR): 313/312 or 263/262 
     * non-interlaced: 312/312 or 262/262 
     * 0x1: manual mode for: 
     * line insert ('dec_ninc'=0) or, skip ('dec_ninc'=1) 
     * capability. Both fields of all the frames following the 
     * writing of this value 
     * are modified according to 'lref[8:0]' and 'ltarg[8:0]' 
     * bits of line_reg1 to line_reg3 registers (by default, 
     * "lref[8:0]"=000000000 and "ltarg[8:0]"=000000001 which 
     * leads to normal mode above). 
     * 100: automatic line insert mode. The 2nd field of the 
     * frame following the writing of this value is increased. 
     * Line insertion is done after line 245 in 525/60 and after 
     * line 290 in 625/50. "lref[8:0]" and "ltarg[8:0]" are 
     * ignored. bit 'jump' is automatically reset after use. Two 
     * lines are skipped (inserted) in 525/60 and four lines in 
     * 625/50 standards. 
     * 110: automatic line skip mode. The 2nd field of the frame 
     * following the writing of this value is decreased. Line 
     * suppression is done after line 245 in 525/60 and after 
     * line 290 in 625/50. "lref[8:0]" and "ltarg[8:0]" are 
     * ignored. Bit 'jump' is automatically reset after use. Two 
     * lines are skipped (inserted) in 525/60 and four lines in 
     * 625/50 standards. 
     * 1x1: must not be used. 
     */ 
    switch( param ){
        case DEC_NINC_ENABLE_E: 
           value = old_value | DEC_NINC_ENABLE_PARAM_MASK; 
           break;
        case DEC_NINC_DISABLE_E: 
           value = old_value & ~ DEC_NINC_ENABLE_PARAM_MASK;
           break;
    }
  

    I2CWrite(TVOUT_CONFIGURATION_6_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_dec_ninc_enable
 *
 * RET  : Return the value of register TvoutConfiguration6
 *
 * Notes : From register 0x0606, bits 5:5
 *
 **************************************************************************/
unsigned char get_dec_ninc_enable()
  {
    unsigned char value;


    /* 
     * 00: normal mode (no line skip/insert capability) 
     * ITU-R (CCIR): 313/312 or 263/262 
     * non-interlaced: 312/312 or 262/262 
     * 0x1: manual mode for: 
     * line insert ('dec_ninc'=0) or, skip ('dec_ninc'=1) 
     * capability. Both fields of all the frames following the 
     * writing of this value 
     * are modified according to 'lref[8:0]' and 'ltarg[8:0]' 
     * bits of line_reg1 to line_reg3 registers (by default, 
     * "lref[8:0]"=000000000 and "ltarg[8:0]"=000000001 which 
     * leads to normal mode above). 
     * 100: automatic line insert mode. The 2nd field of the 
     * frame following the writing of this value is increased. 
     * Line insertion is done after line 245 in 525/60 and after 
     * line 290 in 625/50. "lref[8:0]" and "ltarg[8:0]" are 
     * ignored. bit 'jump' is automatically reset after use. Two 
     * lines are skipped (inserted) in 525/60 and four lines in 
     * 625/50 standards. 
     * 110: automatic line skip mode. The 2nd field of the frame 
     * following the writing of this value is decreased. Line 
     * suppression is done after line 245 in 525/60 and after 
     * line 290 in 625/50. "lref[8:0]" and "ltarg[8:0]" are 
     * ignored. Bit 'jump' is automatically reset after use. Two 
     * lines are skipped (inserted) in 525/60 and four lines in 
     * 625/50 standards. 
     * 1x1: must not be used. 
     */ 
    value = (I2CRead(TVOUT_CONFIGURATION_6_REG) & DEC_NINC_ENABLE_PARAM_MASK) >> 5;
    return value;
  }


/***************************************************************************
 *
 * Function : set_free_jump_enable
 *
 * IN   : param, a value to write to the regiter TvoutConfiguration6
 * OUT  : 
 *
 * RET  : Return the value of register TvoutConfiguration6
 *
 * Notes : From register 0x0606, bits 4:4
 *
 **************************************************************************/
unsigned char set_free_jump_enable( enum free_jump_enable param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(TVOUT_CONFIGURATION_6_REG);

    /* 
     * 00: normal mode (no line skip/insert capability) 
     * ITU-R (CCIR): 313/312 or 263/262 
     * non-interlaced: 312/312 or 262/262 
     * 0x1: manual mode for: 
     * line insert ('dec_ninc'=0) or, skip ('dec_ninc'=1) 
     * capability. Both fields of all the frames following the 
     * writing of this value 
     * are modified according to 'lref[8:0]' and 'ltarg[8:0]' 
     * bits of line_reg1 to line_reg3 registers (by default, 
     * "lref[8:0]"=000000000 and "ltarg[8:0]"=000000001 which 
     * leads to normal mode above). 
     * 100: automatic line insert mode. The 2nd field of the 
     * frame following the writing of this value is increased. 
     * Line insertion is done after line 245 in 525/60 and after 
     * line 290 in 625/50. "lref[8:0]" and "ltarg[8:0]" are 
     * ignored. bit 'jump' is automatically reset after use. Two 
     * lines are skipped (inserted) in 525/60 and four lines in 
     * 625/50 standards. 
     * 110: automatic line skip mode. The 2nd field of the frame 
     * following the writing of this value is decreased. Line 
     * suppression is done after line 245 in 525/60 and after 
     * line 290 in 625/50. "lref[8:0]" and "ltarg[8:0]" are 
     * ignored. Bit 'jump' is automatically reset after use. Two 
     * lines are skipped (inserted) in 525/60 and four lines in 
     * 625/50 standards. 
     * 1x1: must not be used. 
     */ 
    switch( param ){
        case FREE_JUMP_ENABLE_E: 
           value = old_value | FREE_JUMP_ENABLE_PARAM_MASK; 
           break;
        case FREE_JUMP_DISABLE_E: 
           value = old_value & ~ FREE_JUMP_ENABLE_PARAM_MASK;
           break;
    }
  

    I2CWrite(TVOUT_CONFIGURATION_6_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_free_jump_enable
 *
 * RET  : Return the value of register TvoutConfiguration6
 *
 * Notes : From register 0x0606, bits 4:4
 *
 **************************************************************************/
unsigned char get_free_jump_enable()
  {
    unsigned char value;


    /* 
     * 00: normal mode (no line skip/insert capability) 
     * ITU-R (CCIR): 313/312 or 263/262 
     * non-interlaced: 312/312 or 262/262 
     * 0x1: manual mode for: 
     * line insert ('dec_ninc'=0) or, skip ('dec_ninc'=1) 
     * capability. Both fields of all the frames following the 
     * writing of this value 
     * are modified according to 'lref[8:0]' and 'ltarg[8:0]' 
     * bits of line_reg1 to line_reg3 registers (by default, 
     * "lref[8:0]"=000000000 and "ltarg[8:0]"=000000001 which 
     * leads to normal mode above). 
     * 100: automatic line insert mode. The 2nd field of the 
     * frame following the writing of this value is increased. 
     * Line insertion is done after line 245 in 525/60 and after 
     * line 290 in 625/50. "lref[8:0]" and "ltarg[8:0]" are 
     * ignored. bit 'jump' is automatically reset after use. Two 
     * lines are skipped (inserted) in 525/60 and four lines in 
     * 625/50 standards. 
     * 110: automatic line skip mode. The 2nd field of the frame 
     * following the writing of this value is decreased. Line 
     * suppression is done after line 245 in 525/60 and after 
     * line 290 in 625/50. "lref[8:0]" and "ltarg[8:0]" are 
     * ignored. Bit 'jump' is automatically reset after use. Two 
     * lines are skipped (inserted) in 525/60 and four lines in 
     * 625/50 standards. 
     * 1x1: must not be used. 
     */ 
    value = (I2CRead(TVOUT_CONFIGURATION_6_REG) & FREE_JUMP_ENABLE_PARAM_MASK) >> 4;
    return value;
  }


/***************************************************************************
 *
 * Function : set_cfc
 *
 * IN   : param, a value to write to the regiter TvoutConfiguration6
 * OUT  : 
 *
 * RET  : Return the value of register TvoutConfiguration6
 *
 * Notes : From register 0x0606, bits 3:2
 *
 **************************************************************************/
unsigned char set_cfc( enum cfc param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(TVOUT_CONFIGURATION_6_REG);

    /* 
     * Colour frequency control via CFC line. 
     */ 
  

     value =  old_value & ~CFC_PARAM_MASK ;

    switch(  param ){

           case CFC_0_E:
                value  = value  | (CFC_0 << 0x2);
                break;
           case CFC_1_E:
                value  = value  | (CFC_1 << 0x2);
                break;
           case CFC_2_E:
                value  = value  | (CFC_2 << 0x2);
                break;
           case CFC_3_E:
                value  = value  | (CFC_3 << 0x2);
                break;
    }
  

    I2CWrite(TVOUT_CONFIGURATION_6_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_cfc
 *
 * RET  : Return the value of register TvoutConfiguration6
 *
 * Notes : From register 0x0606, bits 3:2
 *
 **************************************************************************/
unsigned char get_cfc()
  {
    unsigned char value;


    /* 
     * Colour frequency control via CFC line. 
     */ 
    value = (I2CRead(TVOUT_CONFIGURATION_6_REG) & CFC_PARAM_MASK) >> 2;
    return value;
  }


/***************************************************************************
 *
 * Function : set_max_dyn_enable
 *
 * IN   : param, a value to write to the regiter TvoutConfiguration6
 * OUT  : 
 *
 * RET  : Return the value of register TvoutConfiguration6
 *
 * Notes : From register 0x0606, bits 0:0
 *
 **************************************************************************/
unsigned char set_max_dyn_enable( enum max_dyn_enable param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(TVOUT_CONFIGURATION_6_REG);

    /* 
     * Max dynamic magnitude allowed on YCrCb inputs for 
     * encoding. EAV and SAV words are replaced by blanking 
     * values before being fed to luminance and chrominance 
     * processing. 
     */ 
    switch( param ){
        case MAX_DYN_ENABLE_E: 
           value = old_value | MAX_DYN_ENABLE_PARAM_MASK; 
           break;
        case MAX_DYN_DISABLE_E: 
           value = old_value & ~ MAX_DYN_ENABLE_PARAM_MASK;
           break;
    }
  

    I2CWrite(TVOUT_CONFIGURATION_6_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_max_dyn_enable
 *
 * RET  : Return the value of register TvoutConfiguration6
 *
 * Notes : From register 0x0606, bits 0:0
 *
 **************************************************************************/
unsigned char get_max_dyn_enable()
  {
    unsigned char value;


    /* 
     * Max dynamic magnitude allowed on YCrCb inputs for 
     * encoding. EAV and SAV words are replaced by blanking 
     * values before being fed to luminance and chrominance 
     * processing. 
     */ 
    value = (I2CRead(TVOUT_CONFIGURATION_6_REG) & MAX_DYN_ENABLE_PARAM_MASK);
    return value;
  }


/***************************************************************************
 *
 * Function : set_phase_reset_mode
 *
 * IN   : param, a value to write to the regiter TvoutConfiguration8
 * OUT  : 
 *
 * RET  : Return the value of register TvoutConfiguration8
 *
 * Notes : From register 0x0608, bits 7:6
 *
 **************************************************************************/
unsigned char set_phase_reset_mode( enum phase_reset_mode param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(TVOUT_CONFIGURATION_8_REG);

    /* 
     * Phase reset mode selection Automatically set back to 00 
     * following the oscillator reset in modes 01 and 10. 
     * 00: disabled 
     * 01: enabled - phase is updated with value from phase 
     * buffer register (see Configuration2 register bit 
     * "rstosc_buf") at the beginning of the next video line. In 
     * the mean time, the increment is updated with hard or soft 
     * values depending on selrst_inc value (see Configuration5 
     * register). 
     * 10: enabled - phase is updated with values from 
     * Increment_dfs1 and Increment_dfs2 registers, based on the 
     * next increment update from cfc (depending on cfc loading 
     * moment andConfiguration6 register 'cfc[1:0]' bits. 
     * 11: enabled - phase is reset following the detection of 
     * 'rst' bit on cfc line, up to 9 pix_clk after loading of 
     * cfc's LSB. 
     */ 
  

     value =  old_value & ~PHASE_RESET_MODE_PARAM_MASK ;

    switch(  param ){

           case TVOUT_PHASE_RESET_DISABLED_E:
                value  = value  | (TVOUT_PHASE_RESET_DISABLED << 0x6);
                break;
           case TVOUT_PHASE_MODE_1_E:
                value  = value  | (TVOUT_PHASE_MODE_1 << 0x6);
                break;
           case TVOUT_PHASE_MODE_2_E:
                value  = value  | (TVOUT_PHASE_MODE_2 << 0x6);
                break;
           case TVOUT_PHASE_MODE_3_E:
                value  = value  | (TVOUT_PHASE_MODE_3 << 0x6);
                break;
    }
  

    I2CWrite(TVOUT_CONFIGURATION_8_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_phase_reset_mode
 *
 * RET  : Return the value of register TvoutConfiguration8
 *
 * Notes : From register 0x0608, bits 7:6
 *
 **************************************************************************/
unsigned char get_phase_reset_mode()
  {
    unsigned char value;


    /* 
     * Phase reset mode selection Automatically set back to 00 
     * following the oscillator reset in modes 01 and 10. 
     * 00: disabled 
     * 01: enabled - phase is updated with value from phase 
     * buffer register (see Configuration2 register bit 
     * "rstosc_buf") at the beginning of the next video line. In 
     * the mean time, the increment is updated with hard or soft 
     * values depending on selrst_inc value (see Configuration5 
     * register). 
     * 10: enabled - phase is updated with values from 
     * Increment_dfs1 and Increment_dfs2 registers, based on the 
     * next increment update from cfc (depending on cfc loading 
     * moment andConfiguration6 register 'cfc[1:0]' bits. 
     * 11: enabled - phase is reset following the detection of 
     * 'rst' bit on cfc line, up to 9 pix_clk after loading of 
     * cfc's LSB. 
     */ 
    value = (I2CRead(TVOUT_CONFIGURATION_8_REG) & PHASE_RESET_MODE_PARAM_MASK) >> 6;
    return value;
  }


/***************************************************************************
 *
 * Function : set_val422_mux
 *
 * IN   : param, a value to write to the regiter TvoutConfiguration8
 * OUT  : 
 *
 * RET  : Return the value of register TvoutConfiguration8
 *
 * Notes : From register 0x0608, bits 4:4
 *
 **************************************************************************/
unsigned char set_val422_mux( enum val422_mux_set param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(TVOUT_CONFIGURATION_8_REG);

    /* 
     * Should be programmed to 1 only after each reset 
     */ 
    switch( param ){
        case VAL_422_MUX_SET_E: 
           value = old_value | VAL_422_MUX_SET_PARAM_MASK; 
           break;
        case VAL_422_MUX_RESET_SET_E: 
           value = old_value & ~ VAL_422_MUX_SET_PARAM_MASK;
           break;
    }
  

    I2CWrite(TVOUT_CONFIGURATION_8_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_val422_mux
 *
 * RET  : Return the value of register TvoutConfiguration8
 *
 * Notes : From register 0x0608, bits 4:4
 *
 **************************************************************************/
unsigned char get_val422_mux()
  {
    unsigned char value;


    /* 
     * Should be programmed to 1 only after each reset 
     */ 
    value = (I2CRead(TVOUT_CONFIGURATION_8_REG) & VAL_422_MUX_SET_PARAM_MASK) >> 4;
    return value;
  }


/***************************************************************************
 *
 * Function : set_blanking_all_enable
 *
 * IN   : param, a value to write to the regiter TvoutConfiguration8
 * OUT  : 
 *
 * RET  : Return the value of register TvoutConfiguration8
 *
 * Notes : From register 0x0608, bits 3:3
 *
 **************************************************************************/
unsigned char set_blanking_all_enable( enum blanking_all_enable param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(TVOUT_CONFIGURATION_8_REG);

    /* 
     * Enable/Disable blanking of all video lines 
     */ 
    switch( param ){
        case BLANKING_ALL_ENABLE_E: 
           value = old_value | BLANKING_ALL_ENABLE_PARAM_MASK; 
           break;
        case BLANKING_ALL_DISABLE_E: 
           value = old_value & ~ BLANKING_ALL_ENABLE_PARAM_MASK;
           break;
    }
  

    I2CWrite(TVOUT_CONFIGURATION_8_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_blanking_all_enable
 *
 * RET  : Return the value of register TvoutConfiguration8
 *
 * Notes : From register 0x0608, bits 3:3
 *
 **************************************************************************/
unsigned char get_blanking_all_enable()
  {
    unsigned char value;


    /* 
     * Enable/Disable blanking of all video lines 
     */ 
    value = (I2CRead(TVOUT_CONFIGURATION_8_REG) & BLANKING_ALL_ENABLE_PARAM_MASK) >> 3;
    return value;
  }


/***************************************************************************
 *
 * Function : set_tv_load_r_c
 *
 * IN   : param, a value to write to the regiter TvOutControl
 * OUT  : 
 *
 * RET  : Return the value of register TvOutControl
 *
 * Notes : From register 0x0680, bits 6:6
 *
 **************************************************************************/
unsigned char set_tv_load_r_c( enum tv_load_r_c_set param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(TV_OUT_CONTROL_REG);

    /* 
     * TV capacitive load 
     */ 
    switch( param ){
        case TV_LOAD_RC_SET_E: 
           value = old_value | TV_LOAD_RC_SET_PARAM_MASK; 
           break;
        case TV_LOAD_RC_RESET_SET_E: 
           value = old_value & ~ TV_LOAD_RC_SET_PARAM_MASK;
           break;
    }
  

    I2CWrite(TV_OUT_CONTROL_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_tv_load_r_c
 *
 * RET  : Return the value of register TvOutControl
 *
 * Notes : From register 0x0680, bits 6:6
 *
 **************************************************************************/
unsigned char get_tv_load_r_c()
  {
    unsigned char value;


    /* 
     * TV capacitive load 
     */ 
    value = (I2CRead(TV_OUT_CONTROL_REG) & TV_LOAD_RC_SET_PARAM_MASK) >> 6;
    return value;
  }


/***************************************************************************
 *
 * Function : set_plug_tv_time
 *
 * IN   : param, a value to write to the regiter TvOutControl
 * OUT  : 
 *
 * RET  : Return the value of register TvOutControl
 *
 * Notes : From register 0x0680, bits 5:3
 *
 **************************************************************************/
unsigned char set_plug_tv_time( enum plug_tv_time param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(TV_OUT_CONTROL_REG);

    /* 
     */ 
  

     value =  old_value & ~PLUG_TV_TIME_PARAM_MASK ;

    switch(  param ){

           case TV_OUT_PLUG_TIM_0S5_E:
                value  = value  | (TV_OUT_PLUG_TIM_0S5 << 0x3);
                break;
           case TV_OUT_PLUG_TIM_1S_E:
                value  = value  | (TV_OUT_PLUG_TIM_1S << 0x3);
                break;
           case TV_OUT_PLUG_TIM_1S5_E:
                value  = value  | (TV_OUT_PLUG_TIM_1S5 << 0x3);
                break;
           case TV_OUT_PLUG_TIM_2S_E:
                value  = value  | (TV_OUT_PLUG_TIM_2S << 0x3);
                break;
           case TV_OUT_PLUG_TIM_2S5_E:
                value  = value  | (TV_OUT_PLUG_TIM_2S5 << 0x3);
                break;
           case TV_OUT_PLUG_TIM_3S_E:
                value  = value  | (TV_OUT_PLUG_TIM_3S << 0x3);
                break;
    }
  

    I2CWrite(TV_OUT_CONTROL_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_plug_tv_time
 *
 * RET  : Return the value of register TvOutControl
 *
 * Notes : From register 0x0680, bits 5:3
 *
 **************************************************************************/
unsigned char get_plug_tv_time()
  {
    unsigned char value;


    /* 
     */ 
    value = (I2CRead(TV_OUT_CONTROL_REG) & PLUG_TV_TIME_PARAM_MASK) >> 3;
    return value;
  }


/***************************************************************************
 *
 * Function : set_plug_tv_detect_enable
 *
 * IN   : param, a value to write to the regiter TvOutControl
 * OUT  : 
 *
 * RET  : Return the value of register TvOutControl
 *
 * Notes : From register 0x0680, bits 2:2
 *
 **************************************************************************/
unsigned char set_plug_tv_detect_enable( enum plug_tv_detect_enable param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(TV_OUT_CONTROL_REG);

    /* 
     * Enable/Disable plug/unplug TV detection 
     */ 
    switch( param ){
        case PLUG_TV_DETECT_ENABLE_E: 
           value = old_value | PLUG_TV_DETECT_ENABLE_PARAM_MASK; 
           break;
        case PLUG_TV_DETECT_DISABLE_E: 
           value = old_value & ~ PLUG_TV_DETECT_ENABLE_PARAM_MASK;
           break;
    }
  

    I2CWrite(TV_OUT_CONTROL_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_plug_tv_detect_enable
 *
 * RET  : Return the value of register TvOutControl
 *
 * Notes : From register 0x0680, bits 2:2
 *
 **************************************************************************/
unsigned char get_plug_tv_detect_enable()
  {
    unsigned char value;


    /* 
     * Enable/Disable plug/unplug TV detection 
     */ 
    value = (I2CRead(TV_OUT_CONTROL_REG) & PLUG_TV_DETECT_ENABLE_PARAM_MASK) >> 2;
    return value;
  }


/***************************************************************************
 *
 * Function : set_tvout_dac_ctrl
 *
 * IN   : param, a value to write to the regiter TvOutControl
 * OUT  : 
 *
 * RET  : Return the value of register TvOutControl
 *
 * Notes : From register 0x0680, bits 1:0
 *
 **************************************************************************/
unsigned char set_tvout_dac_ctrl( enum tvout_dac_enable param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(TV_OUT_CONTROL_REG);

    /* 
     * [00]: DAC is disabled 
     * [01]: DAC is off 
     * [1x]: DAC is enabled 
     */ 
  

     value =  old_value & ~TVOUT_DAC_ENABLE_PARAM_MASK ;

    switch(  param ){

           case TVOUT_DAC_DISABLE_E:
                value =  value | TVOUT_DAC_DISABLE ;
                break;
           case TVOUT_DAC_OFF_E:
                value =  value | TVOUT_DAC_OFF ;
                break;
           case TVOUT_DAC_ENALE_E:
                value =  value | TVOUT_DAC_ENALE ;
                break;
    }
  

    I2CWrite(TV_OUT_CONTROL_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_tvout_dac_ctrl
 *
 * RET  : Return the value of register TvOutControl
 *
 * Notes : From register 0x0680, bits 1:0
 *
 **************************************************************************/
unsigned char get_tvout_dac_ctrl()
  {
    unsigned char value;


    /* 
     * [00]: DAC is disabled 
     * [01]: DAC is off 
     * [1x]: DAC is enabled 
     */ 
    value = (I2CRead(TV_OUT_CONTROL_REG) & TVOUT_DAC_ENABLE_PARAM_MASK);
    return value;
  }


/***************************************************************************
 *
 * Function : set_tv_dual_data_mode
 *
 * IN   : param, a value to write to the regiter TvOutControl2
 * OUT  : 
 *
 * RET  : Return the value of register TvOutControl2
 *
 * Notes : From register 0x0681, bits 1:1
 *
 **************************************************************************/
unsigned char set_tv_dual_data_mode( enum clock_mode param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(TV_OUT_CONTROL_2_REG);

    /* 
     * 0: in DDR mode LSB data is on clock rising edge 
     * 1: in DDR mode LSB data is on clock falling edge 
     */ 
    switch( param ){
        case CLOCK_FAILLING_EDGE_E: 
           value = old_value | CLOCK_MODE_PARAM_MASK; 
           break;
        case CLOCK_RISING_EDGE_E: 
           value = old_value & ~ CLOCK_MODE_PARAM_MASK;
           break;
    }
  

    I2CWrite(TV_OUT_CONTROL_2_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_tv_dual_data_mode
 *
 * RET  : Return the value of register TvOutControl2
 *
 * Notes : From register 0x0681, bits 1:1
 *
 **************************************************************************/
unsigned char get_tv_dual_data_mode()
  {
    unsigned char value;


    /* 
     * 0: in DDR mode LSB data is on clock rising edge 
     * 1: in DDR mode LSB data is on clock falling edge 
     */ 
    value = (I2CRead(TV_OUT_CONTROL_2_REG) & CLOCK_MODE_PARAM_MASK) >> 1;
    return value;
  }


/***************************************************************************
 *
 * Function : set_tv_double_data_rate
 *
 * IN   : param, a value to write to the regiter TvOutControl2
 * OUT  : 
 *
 * RET  : Return the value of register TvOutControl2
 *
 * Notes : From register 0x0681, bits 0:0
 *
 **************************************************************************/
unsigned char set_tv_double_data_rate( enum double_data_rate param )
  {
    unsigned char value = 0;
    unsigned char old_value;

    old_value = I2CRead(TV_OUT_CONTROL_2_REG);

    /* 
     * 0: DENC is set in SDR input data flow 
     * 1: DENC is set in DDR input data flow 
     */ 
    switch( param ){
        case DOUBLE_DATA_RATE_E: 
           value = old_value | DOUBLE_DATA_RATE_PARAM_MASK; 
           break;
        case SIMPLE_DATA_RATE_E: 
           value = old_value & ~ DOUBLE_DATA_RATE_PARAM_MASK;
           break;
    }
  

    I2CWrite(TV_OUT_CONTROL_2_REG, value);

    return old_value;
  }


/***************************************************************************
 *
 * Function : get_tv_double_data_rate
 *
 * RET  : Return the value of register TvOutControl2
 *
 * Notes : From register 0x0681, bits 0:0
 *
 **************************************************************************/
unsigned char get_tv_double_data_rate()
  {
    unsigned char value;


    /* 
     * 0: DENC is set in SDR input data flow 
     * 1: DENC is set in DDR input data flow 
     */ 
    value = (I2CRead(TV_OUT_CONTROL_2_REG) & DOUBLE_DATA_RATE_PARAM_MASK);
    return value;
  }


