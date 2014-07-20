/****************************************************************************
 * File : c:/Lisp/Production/ab9540/ab9540_SIM/Linux/ab9540_SIM_types.h
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

#ifndef C__LISP_PRODUCTION_AB9540_AB9540_SIM_LINUX_AB9540_SIM_TYPES_H
#define C__LISP_PRODUCTION_AB9540_AB9540_SIM_LINUX_AB9540_SIM_TYPES_H


#ifdef __cplusplus
extern "C" {
#endif


//  
//  0: Counter reset inactive 
//  1: Counter reset active.
//  Register SimInterfaceControl 0x0480, Bits 0:0, typedef counter_reset
//   
//  
#define COUNTER_RESET_MASK 0x1U
#define COUNTER_RESET_OFFSET 0
#define COUNTER_RESET_STOP_BIT 0
#define COUNTER_RESET_START_BIT 0
#define COUNTER_RESET_WIDTH 1

#define SIM_INTERFACE_CONTROL_REG 0x480

typedef enum counter_reset {
    COUNTER_UN_RESET_E,
    COUNTER_RESET_E
} COUNTER_RESET_T ;
#define COUNTER_RESET_PARAM_MASK  0x1



//  
//  0: SIMIfClk/2 not selected to counter 
//  1: SIMIfClk/2 selected to counter.
//  Register SimInterfaceControl 0x0480, Bits 1:1, typedef card_clock_selected
//   
//  
#define CARD_CLOCK_SELECTED_MASK 0x2U
#define CARD_CLOCK_SELECTED_OFFSET 1
#define CARD_CLOCK_SELECTED_STOP_BIT 1
#define CARD_CLOCK_SELECTED_START_BIT 1
#define CARD_CLOCK_SELECTED_WIDTH 1


typedef enum card_clock_selected {
    CARD_CLOCK_UN_SELECT_E,
    CARD_CLOCK_SELECT_E
} CARD_CLOCK_SELECTED_T ;
#define CARD_CLOCK_SELECTED_PARAM_MASK  0x2



//  
//  0: Clk32k not selected to counter 
//  1: Clk32k selected to counter.
//  Register SimInterfaceControl 0x0480, Bits 2:2, typedef clock32_selected
//   
//  
#define CLOCK_32_SELECTED_MASK 0x4U
#define CLOCK_32_SELECTED_OFFSET 2
#define CLOCK_32_SELECTED_STOP_BIT 2
#define CLOCK_32_SELECTED_START_BIT 2
#define CLOCK_32_SELECTED_WIDTH 1


typedef enum clock32_selected {
    CLOCK_32_UN_SELECT_E,
    CLOCK_32_SELECT_E
} CLOCK_32_SELECTED_T ;
#define CLOCK_32_SELECTED_PARAM_MASK  0x4



//  
//  0: SIM power off by MCU 
//  1: SIM power on by MCU.
//  Register SimInterfaceControl 0x0480, Bits 3:3, typedef sim_power_on
//   
//  
#define SIM_POWER_ON_MASK 0x8U
#define SIM_POWER_ON_OFFSET 3
#define SIM_POWER_ON_STOP_BIT 3
#define SIM_POWER_ON_START_BIT 3
#define SIM_POWER_ON_WIDTH 1


typedef enum sim_power_on {
    SIM_POWER_OFF_E,
    SIM_POWER_ON_E
} SIM_POWER_ON_T ;
#define SIM_POWER_ON_PARAM_MASK  0x8



//  
//  An externally reset card 
//  1: An internally reset card.
//  Register SimInterfaceControl 0x0480, Bits 4:4, typedef internally_reset
//   
//  
#define INTERNALLY_RESET_MASK 0x10U
#define INTERNALLY_RESET_OFFSET 4
#define INTERNALLY_RESET_STOP_BIT 4
#define INTERNALLY_RESET_START_BIT 4
#define INTERNALLY_RESET_WIDTH 1


typedef enum internally_reset {
    EXTERNALLY_RESET_CARD_E,
    INTERNALLY_RESET_CARD_E
} INTERNALLY_RESET_T ;
#define INTERNALLY_RESET_PARAM_MASK  0x10



//  
//  0: Warm reset of the card is NOT active 
//  1: Warm reset of the card active.
//  Register SimInterfaceControl 0x0480, Bits 5:5, typedef warm_reset_enable
//   
//  
#define WARM_RESET_MASK 0x20U
#define WARM_RESET_OFFSET 5
#define WARM_RESET_STOP_BIT 5
#define WARM_RESET_START_BIT 5
#define WARM_RESET_WIDTH 1


typedef enum warm_reset_enable {
    WARM_RESET_DISABLE_E,
    WARM_RESET_ENABLE_E
} WARM_RESET_ENABLE_T ;
#define WARM_RESET_PARAM_MASK  0x20



//  
//  0: SIM reset active 400 card clock cycles after the clock is applied 
//  1: SIM reset active 40000 card clock cycles after the clock is applied.
//  Register SimInterfaceControl 0x0480, Bits 6:6, typedef reset_duration
//   
//  
#define RESET_DURATION_MASK 0x40U
#define RESET_DURATION_OFFSET 6
#define RESET_DURATION_STOP_BIT 6
#define RESET_DURATION_START_BIT 6
#define RESET_DURATION_WIDTH 1


typedef enum reset_duration {
    ACTIVE_400_CARD_CLOCK_E,
    ACTIVE_40000_CARD_CLOCK_E
} RESET_DURATION_T ;
#define RESET_DURATION_PARAM_MASK  0x40



//  
//  0: If ATRErrInt is generated, power down procedure is activated (card powered down) 
//  1: If ATRErrInt is generated, power down procedure is NOT activated.
//  Register SimInterfaceControl 0x0480, Bits 7:7, typedef powe_down_procedure_enable
//   
//  
#define POWER_DOWN_PROCEDURE_MASK 0x80U
#define POWER_DOWN_PROCEDURE_OFFSET 7
#define POWER_DOWN_PROCEDURE_STOP_BIT 7
#define POWER_DOWN_PROCEDURE_START_BIT 7
#define POWER_DOWN_PROCEDURE_WIDTH 1


typedef enum powe_down_procedure_enable {
    POWE_DOWN_PROCEDURE_ENABLE_E,
    POWE_DOWN_PROCEDURE_DISABLE_E
} POWE_DOWN_PROCEDURE_ENABLE_T ;
#define POWER_DOWN_PROCEDURE_PARAM_MASK  0x80


#define CARD_DETECTION_TIMEOUT_REG 0x481
#define COMP_VALUE_LOW_BYTE_REG 0x482
#define COMP_VALUE_HIGH_BYTE_REG 0x483

//  
//  0: SIM interface in normal use 
//  1: ISO-UICC disabled, SIM IOs gen. purpose outputs.
//  Register SimSupplyManagement 0x0484, Bits 0:0, typedef sim_io_normal
//   
//  
#define SIM_IO_NORMAL_MASK 0x1U
#define SIM_IO_NORMAL_OFFSET 0
#define SIM_IO_NORMAL_STOP_BIT 0
#define SIM_IO_NORMAL_START_BIT 0
#define SIM_IO_NORMAL_WIDTH 1

#define SIM_SUPPLY_MANAGEMENT_REG 0x484

typedef enum sim_io_normal {
    SIM_INTERFACE_NORMAL_USE_E,
    GENERAL_PURPOSE_OUTPUT_E
} SIM_IO_NORMAL_T ;
#define SIM_IO_NORMAL_PARAM_MASK  0x1



//  
//  00: VSIM1 voltage level 1.2V 
//  01: VSIM1 voltage level 1.8V 
//  10: VSIM1 voltage level 3.0V.
//  Register SimSupplyManagement 0x0484, Bits 1:2, typedef vsim_voltage
//   
//  
#define VSIM_VOLTAGE_MASK 0x6U
#define VSIM_VOLTAGE_OFFSET 2
#define VSIM_VOLTAGE_STOP_BIT 2
#define VSIM_VOLTAGE_START_BIT 1
#define VSIM_VOLTAGE_WIDTH 2

#define  LEVEL_1_POINT_2V 0
#define  LEVEL_1_POINT_8V 1
#define  LEVEL_3V 2

typedef enum vsim_voltage {
    LEVEL_1_POINT_2V_E,
    LEVEL_1_POINT_8V_E,
    LEVEL_3V_E
} VSIM_VOLTAGE_T ;
#define VSIM_VOLTAGE_PARAM_MASK  0x6



//  
//  0: VSIM regulator follows start-up order 
//  1: VSIM regulator always on.
//  Register SimSupplyManagement 0x0484, Bits 3:3, typedef vsim_regulator
//   
//  
#define VSIM_REGULATOR_MASK 0x8U
#define VSIM_REGULATOR_OFFSET 3
#define VSIM_REGULATOR_STOP_BIT 3
#define VSIM_REGULATOR_START_BIT 3
#define VSIM_REGULATOR_WIDTH 1


typedef enum vsim_regulator {
    REGULATOR_FOLLOWS_START_UP_ORDER_E,
    REGULATOR_ALWAYS_ON_E
} VSIM_REGULATOR_T ;
#define VSIM_REGULATOR_PARAM_MASK  0x8



//  
//  0: SIMIf detects removal from BatCtrl only 
//  1: SIMIf detects removal from SIMCarDetX also.
//  Register SimSupplyManagement 0x0484, Bits 4:4, typedef removal_detection
//   
//  
#define REMOVAL_DETECTION_MASK 0x10U
#define REMOVAL_DETECTION_OFFSET 4
#define REMOVAL_DETECTION_STOP_BIT 4
#define REMOVAL_DETECTION_START_BIT 4
#define REMOVAL_DETECTION_WIDTH 1


typedef enum removal_detection {
    REMOVAL_FROM_BATCTRL_ONLY_E,
    REMOVAL_FROM_SIMCARDETX_ALSO_E
} REMOVAL_DETECTION_T ;
#define REMOVAL_DETECTION_PARAM_MASK  0x10



//  
//  0: SIMCardDetX comparator disabled 
//  1: SIMCardDetX comparator enabled.
//  Register SimSupplyManagement 0x0484, Bits 5:5, typedef comparator_enabled
//   
//  
#define SIM_COMP_DETECTION_MASK 0x20U
#define SIM_COMP_DETECTION_OFFSET 5
#define SIM_COMP_DETECTION_STOP_BIT 5
#define SIM_COMP_DETECTION_START_BIT 5
#define SIM_COMP_DETECTION_WIDTH 1


typedef enum comparator_enabled {
    COMPARATOR_DISABLE_E,
    COMPARATOR_ENABLE_E
} COMPARATOR_ENABLED_T ;
#define SIM_COMP_DETECTION_PARAM_MASK  0x20



//  
//  0: SIMDa pull up is R1 only 
//  1: SIMDa pull up is R1 + R2.
//  Register SimSupplyManagement 0x0484, Bits 6:6, typedef sim_da_pull_up
//   
//  
#define SIM_DA_PULL_UP_MASK 0x40U
#define SIM_DA_PULL_UP_OFFSET 6
#define SIM_DA_PULL_UP_STOP_BIT 6
#define SIM_DA_PULL_UP_START_BIT 6
#define SIM_DA_PULL_UP_WIDTH 1


typedef enum sim_da_pull_up {
    BY_R1_ONLY_E,
    BY_R1_PLUS_R2_E
} SIM_DA_PULL_UP_T ;
#define SIM_DA_PULL_UP_PARAM_MASK  0x40



//  
//  0: VSIM controlled by SleepX (if VSIM is on) 
//  1: VSIM always in active mode (if VSIM is on).
//  Register SimSupplyManagement 0x0484, Bits 7:7, typedef vsim_active_mode
//   
//  
#define VSIM_ACTIVE_MODE_MASK 0x80U
#define VSIM_ACTIVE_MODE_OFFSET 7
#define VSIM_ACTIVE_MODE_STOP_BIT 7
#define VSIM_ACTIVE_MODE_START_BIT 7
#define VSIM_ACTIVE_MODE_WIDTH 1


typedef enum vsim_active_mode {
    VSIM_CONTROLLED_BY_SLEEPX_E,
    VSIM_ALWAYS_ACTIVE_MODE_E
} VSIM_ACTIVE_MODE_T ;
#define VSIM_ACTIVE_MODE_PARAM_MASK  0x80



//  
//  0: Select VbatVsim ball to supply Vsim LDO 
//  1: Select VinVsim ball to supply Vsim LDO.
//  Register SimSupplyManagement2 0x0485, Bits 0:0, typedef select_vsim_power
//   
//  
#define SELECT_VSIM_POWER_MASK 0x1U
#define SELECT_VSIM_POWER_OFFSET 0
#define SELECT_VSIM_POWER_STOP_BIT 0
#define SELECT_VSIM_POWER_START_BIT 0
#define SELECT_VSIM_POWER_WIDTH 1

#define SIM_SUPPLY_MANAGEMENT_2_REG 0x485

typedef enum select_vsim_power {
    SELECT_VBAT_E,
    SELECT_VIN_E
} SELECT_VSIM_POWER_T ;
#define SELECT_VSIM_POWER_PARAM_MASK  0x1



//  
//  0: No Card plug : CUiccDetect ball is PullUp to Battery ;Card plug ; CUiccDetect ball 
//  is grounded (Switch Closed) 
//  1: No Card plug : CUiccDetect ball is grouded Card plug ; CUiccDetect ball is PullUp 
//  to Battery (Switch Open).
//  Register SimSupplyManagement2 0x0485, Bits 1:1, typedef switch_open
//   
//  
#define SIM_CARD_DET_POLARITY_MASK 0x2U
#define SIM_CARD_DET_POLARITY_OFFSET 1
#define SIM_CARD_DET_POLARITY_STOP_BIT 1
#define SIM_CARD_DET_POLARITY_START_BIT 1
#define SIM_CARD_DET_POLARITY_WIDTH 1


typedef enum switch_open {
    SWITCH_CLOSE_E,
    SWITCH_OPEN_E
} SWITCH_OPEN_T ;
#define SIM_CARD_DET_POLARITY_PARAM_MASK  0x2



//  
//  1: SIM Card Detected Interrupt pending (Activates at both edges).
//  Register SimSourceInterrupts 0x0486, Bits 1:1, typedef intr_card_detected
//   
//  
#define INTR_CARD_DETECTED_MASK 0x2U
#define INTR_CARD_DETECTED_OFFSET 1
#define INTR_CARD_DETECTED_STOP_BIT 1
#define INTR_CARD_DETECTED_START_BIT 1
#define INTR_CARD_DETECTED_WIDTH 1

#define SIM_SOURCE_INTERRUPTS_REG 0x486



//  
//  1: ISO-UICC SIM ATR(Answer to Reset) Error Interrupt pending (Activates if no ATR 
//  received.
//  Register SimSourceInterrupts 0x0486, Bits 2:2, typedef intr_atr_error
//   
//  
#define INTR_ATR_ERROR_MASK 0x4U
#define INTR_ATR_ERROR_OFFSET 2
#define INTR_ATR_ERROR_STOP_BIT 2
#define INTR_ATR_ERROR_START_BIT 2
#define INTR_ATR_ERROR_WIDTH 1




//  
//  Tx Error Interrupt.
//  Register SimSourceInterrupts 0x0486, Bits 3:3, typedef intr_tx_error
//   
//  
#define INTR_TX_ERROR_MASK 0x8U
#define INTR_TX_ERROR_OFFSET 3
#define INTR_TX_ERROR_STOP_BIT 3
#define INTR_TX_ERROR_START_BIT 3
#define INTR_TX_ERROR_WIDTH 1




//  
//  1: SIM Card Detected Interrupt pending (Activates at both edges).
//  Register SimLatchInterrupts 0x0487, Bits 1:1, typedef latch_card_detected
//   
//  
#define LATCH_CARD_DETECTED_MASK 0x2U
#define LATCH_CARD_DETECTED_OFFSET 1
#define LATCH_CARD_DETECTED_STOP_BIT 1
#define LATCH_CARD_DETECTED_START_BIT 1
#define LATCH_CARD_DETECTED_WIDTH 1

#define SIM_LATCH_INTERRUPTS_REG 0x487



//  
//  1: ISO-UICC SIM ATR(Answer to Reset) Error Interrupt pending (Activates if no ATR 
//  received.
//  Register SimLatchInterrupts 0x0487, Bits 2:2, typedef latch_atr_error
//   
//  
#define LATCH_ATR_ERROR_MASK 0x4U
#define LATCH_ATR_ERROR_OFFSET 2
#define LATCH_ATR_ERROR_STOP_BIT 2
#define LATCH_ATR_ERROR_START_BIT 2
#define LATCH_ATR_ERROR_WIDTH 1




//  
//  Tx Error Interrupt.
//  Register SimLatchInterrupts 0x0487, Bits 3:3, typedef latch_tx_error
//   
//  
#define LATCH_TX_ERROR_MASK 0x8U
#define LATCH_TX_ERROR_OFFSET 3
#define LATCH_TX_ERROR_STOP_BIT 3
#define LATCH_TX_ERROR_START_BIT 3
#define LATCH_TX_ERROR_WIDTH 1




//  
//  1: SIM Card Detected Interrupt pending (Activates at both edges).
//  Register SimMaskInterrupts 0x0488, Bits 1:1, typedef mask_card_detected
//   
//  
#define MASK_CARD_DETECTED_MASK 0x2U
#define MASK_CARD_DETECTED_OFFSET 1
#define MASK_CARD_DETECTED_STOP_BIT 1
#define MASK_CARD_DETECTED_START_BIT 1
#define MASK_CARD_DETECTED_WIDTH 1

#define SIM_MASK_INTERRUPTS_REG 0x488



//  
//  1: ISO-UICC SIM ATR(Answer to Reset) Error Interrupt pending (Activates if no ATR 
//  received.
//  Register SimMaskInterrupts 0x0488, Bits 2:2, typedef mask_atr_error
//   
//  
#define MASK_ATR_ERROR_MASK 0x4U
#define MASK_ATR_ERROR_OFFSET 2
#define MASK_ATR_ERROR_STOP_BIT 2
#define MASK_ATR_ERROR_START_BIT 2
#define MASK_ATR_ERROR_WIDTH 1




//  
//  Tx Error Interrupt.
//  Register SimMaskInterrupts 0x0488, Bits 3:3, typedef mask_tx_error
//   
//  
#define MASK_TX_ERROR_MASK 0x8U
#define MASK_TX_ERROR_OFFSET 3
#define MASK_TX_ERROR_STOP_BIT 3
#define MASK_TX_ERROR_START_BIT 3
#define MASK_TX_ERROR_WIDTH 1




//  
//  0: USB SIM not in use. (VSIM powered down, weak pull-down activated and strong 
//  pull-down 
//  activated when VSIM voltage low) 
//  1: USB SIM powered up (VSIM Powered up, all put-downs released.
//  Register SimIfContol 0x0489, Bits 0:0, typedef usim_power_on
//   
//  
#define USIM_POWER_MASK 0x1U
#define USIM_POWER_OFFSET 0
#define USIM_POWER_STOP_BIT 0
#define USIM_POWER_START_BIT 0
#define USIM_POWER_WIDTH 1

#define SIM_IF_CONTOL_REG 0x489

typedef enum usim_power_on {
    USIM_POWER_OFF_E,
    USIM_POWER_ON_E
} USIM_POWER_ON_T ;
#define USIM_POWER_PARAM_MASK  0x1



//  
//  0: Data line load less then 21pF 
//  1: Data line load 21-30pF.
//  Register SimIfContol 0x0489, Bits 1:1, typedef usim_load
//   
//  
#define USIM_LOAD_MASK 0x2U
#define USIM_LOAD_OFFSET 1
#define USIM_LOAD_STOP_BIT 1
#define USIM_LOAD_START_BIT 1
#define USIM_LOAD_WIDTH 1


typedef enum usim_load {
    UNDER_21_PF_E,
    ABOVE_21_PF_E
} USIM_LOAD_T ;
#define USIM_LOAD_PARAM_MASK  0x2



//  
//  0: CIsoReset ball controlled by traditional SIM IF 
//  1: CIsoreset ball driven by Simrst value.
//  Register SimIfContol 0x0489, Bits 2:2, typedef sim_reset_control
//   
//  
#define SIM_RESET_CONTROL_MASK 0x4U
#define SIM_RESET_CONTROL_OFFSET 2
#define SIM_RESET_CONTROL_STOP_BIT 2
#define SIM_RESET_CONTROL_START_BIT 2
#define SIM_RESET_CONTROL_WIDTH 1


typedef enum sim_reset_control {
    CONTROLLED_BY_SIM_IF_E,
    DRIVEN_HIGH_E
} SIM_RESET_CONTROL_T ;
#define SIM_RESET_CONTROL_PARAM_MASK  0x4



//  
//  0: USB SIM in normal use 
//  1: All decoding logic and single-ended zero filter bypassed. Only data drivers in 
//  use..
//  Register SimIfContol 0x0489, Bits 3:3, typedef usim_by_pass
//   
//  
#define USIM_BY_PASS_MASK 0x8U
#define USIM_BY_PASS_OFFSET 3
#define USIM_BY_PASS_STOP_BIT 3
#define USIM_BY_PASS_START_BIT 3
#define USIM_BY_PASS_WIDTH 1


typedef enum usim_by_pass {
    ALL_DECODING_LOGIG_BYPASSED_E,
    NORMAL_USE_E
} USIM_BY_PASS_T ;
#define USIM_BY_PASS_PARAM_MASK  0x8



//  
//  0: CIsoReset pad driven low if Simrst_force=1 
//  1: CIsoReset pad driven high if Simrst_force.
//  Register SimIfContol 0x0489, Bits 4:4, typedef sim_reset_value
//   
//  
#define SIM_RESET_VALUE_MASK 0x10U
#define SIM_RESET_VALUE_OFFSET 4
#define SIM_RESET_VALUE_STOP_BIT 4
#define SIM_RESET_VALUE_START_BIT 4
#define SIM_RESET_VALUE_WIDTH 1


typedef enum sim_reset_value {
    RESET_DRIVEN_LOW_E,
    RESET_DRIVEN_HIGH_E
} SIM_RESET_VALUE_T ;
#define SIM_RESET_VALUE_PARAM_MASK  0x10



//  
//  0: USB-UICC data lines weak pull down active 
//  1: USB-UICC data lines weak pull down not active.
//  Register SimIfContol 0x0489, Bits 5:5, typedef weak_pull_down
//   
//  
#define WEAK_PULL_DOWN_MASK 0x20U
#define WEAK_PULL_DOWN_OFFSET 5
#define WEAK_PULL_DOWN_STOP_BIT 5
#define WEAK_PULL_DOWN_START_BIT 5
#define WEAK_PULL_DOWN_WIDTH 1


typedef enum weak_pull_down {
    WEAK_PULL_DOWN_ACTIVE_E,
    WEAK_PULL_DOWN_NOT_ACTIVE_E
} WEAK_PULL_DOWN_T ;
#define WEAK_PULL_DOWN_PARAM_MASK  0x20


#define SIM_DELAY_PARAM_MASK  0x7
#define SIM_DELAY_MASK 0x7U
#define SIM_DELAY_OFFSET 2
#define SIM_DELAY_STOP_BIT 2
#define SIM_DELAY_START_BIT 0
#define SIM_DELAY_WIDTH 3

typedef enum sim_delay {
    SIM_DELAY_108_MICRO_SECOND = 0x0,
    SIM_DELAY_210_MICRO_SECOND = 0x1,
    SIM_DELAY_312_MICRO_SECOND = 0x2,
    SIM_DELAY_414_MICRO_SECOND = 0x3,
    SIM_DELAY_516_MICRO_SECOND = 0x4,
    SIM_DELAY_618_MICRO_SECOND = 0x5,
    SIM_DELAY_720_MICRO_SECOND = 0x6,
    SIM_DELAY_822_MICRO_SECOND = 0x7,
    SIM_DELAY_924_MICRO_SECOND = 0x8
} SIM_DELAY_T ;

//  
//  0:Filter active 
//  1:Filter disabled (bypass).
//  Register SimDelay 0x048A, Bits 3:3, typedef filter_enable
//   
//  
#define FILTER_ACTIVE_MASK 0x8U
#define FILTER_ACTIVE_OFFSET 3
#define FILTER_ACTIVE_STOP_BIT 3
#define FILTER_ACTIVE_START_BIT 3
#define FILTER_ACTIVE_WIDTH 1

#define SIM_DELAY_REG 0x48A

typedef enum filter_enable {
    FILTER_ENABLE_E,
    FILTER_DISABLE_E
} FILTER_ENABLE_T ;
#define FILTER_ACTIVE_PARAM_MASK  0x8



//  
//  This bit is active only if 'VmodSelCtrlSel'=1, 0:Vmod ouput voltage is set by 
//  VmodSel1 register 
//  1:Vmod ouput voltage is set by VmodSel2 register.
//  Register SimSupplyManagement3 0x048B, Bits 2:2, typedef v_mod_select
//   
//  
#define V_MOD_SELECT_MASK 0x4U
#define V_MOD_SELECT_OFFSET 2
#define V_MOD_SELECT_STOP_BIT 2
#define V_MOD_SELECT_START_BIT 2
#define V_MOD_SELECT_WIDTH 1

#define SIM_SUPPLY_MANAGEMENT_3_REG 0x48B

typedef enum v_mod_select {
    VMOD_SELECT_BY_VMODSEL1_E,
    VMOD_SELECT_BY_VMODSEL2_E
} V_MOD_SELECT_T ;
#define V_MOD_SELECT_PARAM_MASK  0x4



//  
//  Vmod output voltage.
//  Register VmodSel34CtrlReg 0x048C, Bits 0:1, typedef vmod_output_voltage
//   
//  
#define VMOD_OUTPUT_VOLTAGE_MASK 0x3U
#define VMOD_OUTPUT_VOLTAGE_OFFSET 1
#define VMOD_OUTPUT_VOLTAGE_STOP_BIT 1
#define VMOD_OUTPUT_VOLTAGE_START_BIT 0
#define VMOD_OUTPUT_VOLTAGE_WIDTH 2

#define VMOD_SEL_34_CTRL_REG_REG 0x48C
#define  VMOD_VOLTAGE_DEFINED_BY_VMODSEL1_OR_VMODSEL2 0
#define  VMOD_VOLTAGE_DEFINED_BY_VMODSEL3 1
#define  VMOD_VOLTAGE_DEFINED_BY_VMODSEL4 2

typedef enum vmod_output_voltage {
    VMOD_VOLTAGE_DEFINED_BY_VMODSEL1_OR_VMODSEL2_E,
    VMOD_VOLTAGE_DEFINED_BY_VMODSEL3_E,
    VMOD_VOLTAGE_DEFINED_BY_VMODSEL4_E
} VMOD_OUTPUT_VOLTAGE_T ;
#define VMOD_OUTPUT_VOLTAGE_PARAM_MASK  0x3


#endif
