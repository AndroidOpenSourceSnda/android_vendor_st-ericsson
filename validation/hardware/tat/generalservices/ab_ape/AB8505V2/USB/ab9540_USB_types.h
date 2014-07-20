/****************************************************************************
 * File : c:/Lisp/Production/ab9540/ab9540_USB/Linux/ab9540_USB_types.h
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

#ifndef C__LISP_PRODUCTION_AB9540_AB9540_USB_LINUX_AB9540_USB_TYPES_H
#define C__LISP_PRODUCTION_AB9540_AB9540_USB_LINUX_AB9540_USB_TYPES_H


#ifdef __cplusplus
extern "C" {
#endif


//  
//  0: DM Single Ended Receiver output is low 
//  1: DMSingle Ended Receiver output is high.
//  Register UsbLineStatus 0x0580, Bits 0:0, typedef dplus_receiver_high
//   
//  
#define DPLUS_CMP_OUT_MASK 0x1U
#define DPLUS_CMP_OUT_OFFSET 0
#define DPLUS_CMP_OUT_STOP_BIT 0
#define DPLUS_CMP_OUT_START_BIT 0
#define DPLUS_CMP_OUT_WIDTH 1

#define USB_LINE_STATUS_REG 0x580

typedef enum dplus_receiver_high {
    DPLUS_RECEIVER_LOW_E,
    DPLUS_RECEIVER_HIGH_E
} DPLUS_RECEIVER_HIGH_T ;
#define DPLUS_CMP_OUT_PARAM_MASK  0x1



//  
//  0: DM Single Ended Receiver output is low 
//  1: DMSingle Ended Receiver output is high.
//  Register UsbLineStatus 0x0580, Bits 1:1, typedef dminus_receiver_high
//   
//  
#define DMINUS_CMP_OUT_MASK 0x2U
#define DMINUS_CMP_OUT_OFFSET 1
#define DMINUS_CMP_OUT_STOP_BIT 1
#define DMINUS_CMP_OUT_START_BIT 1
#define DMINUS_CMP_OUT_WIDTH 1


typedef enum dminus_receiver_high {
    DMINUS_RECEIVER_LOW_E,
    DMINUS_RECEIVER_HIGH_E
} DMINUS_RECEIVER_HIGH_T ;
#define DMINUS_CMP_OUT_PARAM_MASK  0x2



//  
//  0: No Host charger detected 
//  1: Host Charger detected.
//  Register UsbLineStatus 0x0580, Bits 2:2, typedef host_charger_detected
//   
//  
#define HOST_CHARGER_DETECTED_MASK 0x4U
#define HOST_CHARGER_DETECTED_OFFSET 2
#define HOST_CHARGER_DETECTED_STOP_BIT 2
#define HOST_CHARGER_DETECTED_START_BIT 2
#define HOST_CHARGER_DETECTED_WIDTH 1


typedef enum host_charger_detected {
    HOST_CHARGER_UN_DETECTED_E,
    HOST_CHARGER_DETECTED_E
} HOST_CHARGER_DETECTED_T ;
#define HOST_CHARGER_DETECTED_PARAM_MASK  0x4



//  
//  0000: Not configured 
//  0001: Standard Host, not charging 
//  0010: Standard Host, charging, not suspended 
//  0011: Standard Host, charging, suspended 
//  0100: Host charger, normal mode 
//  0101: Host charger, HS mode 
//  0110: Host charger, HS Chirp mode 
//  0111: Dedicated USx charger 
//  1000: ACA RID_A configuration 
//  1001: ACA RID_B configuration 
//  
#define CHARGER_TYPE_MASK 0x78U
#define CHARGER_TYPE_OFFSET 6
#define CHARGER_TYPE_STOP_BIT 6
#define CHARGER_TYPE_START_BIT 3
#define CHARGER_TYPE_WIDTH 4

#define  CHARGER_NOT_CONFIGURED 0
#define  CHARGER_STANDARD_HOST_NOT_CHARGING 1
#define  CHARGER_STANDARD_HOST_CHARGING_CHARGING 2
#define  CHARGER_STANDARD_HOST_CHARGING_SUSPENDED 3
#define  CHARGER_HOST_CHARGER_CPD 4
#define  CHARGER_RES1 5
#define  CHARGER_RES2 6
#define  CHARGER_HOST_CHARGER_DCP 7
#define  CHARGER_HOST_CHARGER_ACA_A 8
#define  CHARGER_HOST_CHARGER_ACA_B 9
#define  CHARGER_HOST_CHARGER_ACA_C 10
#define  CHARGER_RES3 11
#define  CHARGER_RES4 12
#define  CHARGER_USB_STANDART_UPSTREAM_PORT 13
#define  CHARGER_USB_CHARGER_PORT_NOT_OK 14
#define  CHARGER_USB_CHARGER_WITH_DM_HIGH 15

typedef enum charger_type {
    CHARGER_NOT_CONFIGURED_E,
    CHARGER_STANDARD_HOST_NOT_CHARGING_E,
    CHARGER_STANDARD_HOST_CHARGING_CHARGING_E,
    CHARGER_STANDARD_HOST_CHARGING_SUSPENDED_E,
    CHARGER_HOST_CHARGER_CPD_E,
    CHARGER_RES1_E,
    CHARGER_RES2_E,
    CHARGER_HOST_CHARGER_DCP_E,
    CHARGER_HOST_CHARGER_ACA_A_E,
    CHARGER_HOST_CHARGER_ACA_B_E,
    CHARGER_HOST_CHARGER_ACA_C_E,
    CHARGER_RES3_E,
    CHARGER_RES4_E,
    CHARGER_USB_STANDART_UPSTREAM_PORT_E,
    CHARGER_USB_CHARGER_PORT_NOT_OK_E,
    CHARGER_USB_CHARGER_WITH_DM_HIGH_E
} CHARGER_TYPE_T ;
#define CHARGER_TYPE_PARAM_MASK  0x78



//  
//  0: Uart mode is not active 
//  1: Uart mode is active.
//  Register UsbLineStatus 0x0580, Bits 7:7, typedef uart_mmode_enable
//   
//  
#define UART_MODE_MASK 0x80U
#define UART_MODE_OFFSET 7
#define UART_MODE_STOP_BIT 7
#define UART_MODE_START_BIT 7
#define UART_MODE_WIDTH 1


typedef enum uart_mmode_enable {
    UART_MMODE_DISABLE_E,
    UART_MMODE_ENABLE_E
} UART_MMODE_ENABLE_T ;
#define UART_MODE_PARAM_MASK  0x80



//  
//  0: disable Id detection thru ADC 
//  1: enable Id detection thru ADC.
//  Register UsbPhyMmanagement 0x0581, Bits 0:0, typedef id_detection_thru_adc_enable
//   
//  
#define CHARGER_PULL_UP_MASK 0x1U
#define CHARGER_PULL_UP_OFFSET 0
#define CHARGER_PULL_UP_STOP_BIT 0
#define CHARGER_PULL_UP_START_BIT 0
#define CHARGER_PULL_UP_WIDTH 1

#define USB_PHY_MMANAGEMENT_REG 0x581

typedef enum id_detection_thru_adc_enable {
    ID_DETECTION_THRU_ADC_DISABLE_E,
    ID_DETECTION_THRU_ADC_ENABLE_E
} ID_DETECTION_THRU_ADC_ENABLE_T ;
#define CHARGER_PULL_UP_PARAM_MASK  0x1



//  
//  0: Pull-up and Pull-down switches (including ENC switches) are controlled by SPI 
//  register 
//  1: Pull-up and Pull-down switches (including ENC switches) are controlled by ULPI 
//  register.
//  Register UsbPhyMmanagement 0x0581, Bits 1:1, typedef usb_switch
//   
//  
#define USB_SWITCH_CTRL_MASK 0x2U
#define USB_SWITCH_CTRL_OFFSET 1
#define USB_SWITCH_CTRL_STOP_BIT 1
#define USB_SWITCH_CTRL_START_BIT 1
#define USB_SWITCH_CTRL_WIDTH 1


typedef enum usb_switch {
    CONTROLED_BY_SPI_E,
    CONTROLED_BY_ULPI_E
} USB_SWITCH_T ;
#define USB_SWITCH_CTRL_PARAM_MASK  0x2



//  
//  0: PHY is reset (active low) 
//  1: PHY is not reset.
//  Register UsbPhyMmanagement 0x0581, Bits 2:2, typedef reset_active_low
//   
//  
#define PHY_RESET_MASK 0x4U
#define PHY_RESET_OFFSET 2
#define PHY_RESET_STOP_BIT 2
#define PHY_RESET_START_BIT 2
#define PHY_RESET_WIDTH 1


typedef enum reset_active_low {
    PHY_IS_RESET_E,
    PHY_IS_NOT_RESET_E
} RESET_ACTIVE_LOW_T ;
#define PHY_RESET_PARAM_MASK  0x4



//  
//  0: DpPull Up disable 
//  1: DM Pull Up enable.
//  Register UsbPhyMmanagement 0x0581, Bits 3:3, typedef dp_pull_up_enable
//   
//  
#define DP_PULL_UP_MASK 0x8U
#define DP_PULL_UP_OFFSET 3
#define DP_PULL_UP_STOP_BIT 3
#define DP_PULL_UP_START_BIT 3
#define DP_PULL_UP_WIDTH 1


typedef enum dp_pull_up_enable {
    DP_PULLUP_ENABLE_E,
    DP_PULLUP_DISABLE_E
} DP_PULL_UP_ENABLE_T ;
#define DP_PULL_UP_PARAM_MASK  0x8



//  
//  0: DMPull Up disable 
//  1: DM Pull down enable.
//  Register UsbPhyMmanagement 0x0581, Bits 4:4, typedef dm_pull_down_enable
//   
//  
#define DM_PULL_DOWN_MASK 0x10U
#define DM_PULL_DOWN_OFFSET 4
#define DM_PULL_DOWN_STOP_BIT 4
#define DM_PULL_DOWN_START_BIT 4
#define DM_PULL_DOWN_WIDTH 1


typedef enum dm_pull_down_enable {
    DM1_PULLDOWN_ENABLE_E,
    DM1_PULLDOWN_DISABLE_E
} DM_PULL_DOWN_ENABLE_T ;
#define DM_PULL_DOWN_PARAM_MASK  0x10



//  
//  0: DpMPull Down disable 
//  1: DpM Pulldown enable.
//  Register UsbPhyMmanagement 0x0581, Bits 5:5, typedef dp_pull_down_enable
//   
//  
#define DP_PULL_DOWN_MASK 0x20U
#define DP_PULL_DOWN_OFFSET 5
#define DP_PULL_DOWN_STOP_BIT 5
#define DP_PULL_DOWN_START_BIT 5
#define DP_PULL_DOWN_WIDTH 1


typedef enum dp_pull_down_enable {
    DP_PULLDOWN_ENABLE_E,
    DP_PULLDOWN_DISABLE_E
} DP_PULL_DOWN_ENABLE_T ;
#define DP_PULL_DOWN_PARAM_MASK  0x20



//  
//  0: DMPull Up disable 
//  1: DM Pull Up enable.
//  Register UsbPhyMmanagement 0x0581, Bits 6:6, typedef dm_pull_up_enable
//   
//  
#define DM_PULL_UP_MASK 0x40U
#define DM_PULL_UP_OFFSET 6
#define DM_PULL_UP_STOP_BIT 6
#define DM_PULL_UP_START_BIT 6
#define DM_PULL_UP_WIDTH 1


typedef enum dm_pull_up_enable {
    DM_PULLUP_ENABLE_E,
    DM_PULLUP_DISABLE_E
} DM_PULL_UP_ENABLE_T ;
#define DM_PULL_UP_PARAM_MASK  0x40



//  
//  0: disable USB charger detection 
//  1: enable USB charger detection.
//  Register UsbPhyMmanagement2 0x0582, Bits 0:0, typedef usb_charger_detection_enable
//   
//  
#define USB_CHARGER_DETECTION_MASK 0x1U
#define USB_CHARGER_DETECTION_OFFSET 0
#define USB_CHARGER_DETECTION_STOP_BIT 0
#define USB_CHARGER_DETECTION_START_BIT 0
#define USB_CHARGER_DETECTION_WIDTH 1

#define USB_PHY_MMANAGEMENT_2_REG 0x582

typedef enum usb_charger_detection_enable {
    USB_CHARGER_DETECTION_DISABLE_E,
    USB_CHARGER_DETECTION_ENABLE_E
} USB_CHARGER_DETECTION_ENABLE_T ;
#define USB_CHARGER_DETECTION_PARAM_MASK  0x1



//  
//  0: clock not gated 
//  1: clock gated, sent only to audio digital.
//  Register UsbPhyMmanagement2 0x0582, Bits 4:4, typedef gate_ulp_clock
//   
//  
#define GATE_SYS_ULP_CLOCK_MASK 0x10U
#define GATE_SYS_ULP_CLOCK_OFFSET 4
#define GATE_SYS_ULP_CLOCK_STOP_BIT 4
#define GATE_SYS_ULP_CLOCK_START_BIT 4
#define GATE_SYS_ULP_CLOCK_WIDTH 1


typedef enum gate_ulp_clock {
    ULPCLOCK_NOT_GATED_E,
    ULPCLOCK_GATED_E
} GATE_ULP_CLOCK_T ;
#define GATE_SYS_ULP_CLOCK_PARAM_MASK  0x10



//  
//  0: inactive 
//  1: Uart low power mode is enabled.
//  Register UsbPhyMmanagement2 0x0582, Bits 5:5, typedef uart_low_power_mode_enable
//   
//  
#define UART_LOW_POWER_MODE_MASK 0x20U
#define UART_LOW_POWER_MODE_OFFSET 5
#define UART_LOW_POWER_MODE_STOP_BIT 5
#define UART_LOW_POWER_MODE_START_BIT 5
#define UART_LOW_POWER_MODE_WIDTH 1


typedef enum uart_low_power_mode_enable {
    UART_LOW_POWER_MODE_DISABLE_E,
    UART_LOW_POWER_MODE_ENABLE_E
} UART_LOW_POWER_MODE_ENABLE_T ;
#define UART_LOW_POWER_MODE_PARAM_MASK  0x20



//  
//  0: DM 19.25kOhms pull down and Single Ended Receiver controlled by ULPI 
//  1: DM 19.25kOhms pull down and Single Ended Receiver controlled by I2C for 
//  charger.
//  Register UsbPhyMmanagement2 0x0582, Bits 6:6, typedef charger_mux_ctrl
//   
//  
#define CHARGER_MUX_CTRL_MASK 0x40U
#define CHARGER_MUX_CTRL_OFFSET 6
#define CHARGER_MUX_CTRL_STOP_BIT 6
#define CHARGER_MUX_CTRL_START_BIT 6
#define CHARGER_MUX_CTRL_WIDTH 1


typedef enum charger_mux_ctrl {
    UPLI_E,
    I2C_E
} CHARGER_MUX_CTRL_T ;
#define CHARGER_MUX_CTRL_PARAM_MASK  0x40



//  
//  0: Disable DM 19.25KOhms pull down 
//  1: Enable DM 19.25kOhms pull down.
//  Register UsbPhyMmanagement2 0x0582, Bits 7:7, typedef dm_pull
//   
//  
#define DM_PULL_DOWN_DISABLE_MASK 0x80U
#define DM_PULL_DOWN_DISABLE_OFFSET 7
#define DM_PULL_DOWN_DISABLE_STOP_BIT 7
#define DM_PULL_DOWN_DISABLE_START_BIT 7
#define DM_PULL_DOWN_DISABLE_WIDTH 1

#define  DM_PULLDOWN_ENABLE 0
#define  DM_PULLDOWN_DISABLE 1

typedef enum dm_pull {
    DM_PULLDOWN_ENABLE_E,
    DM_PULLDOWN_DISABLE_E
} DM_PULL_T ;
#define DM_PULL_DOWN_DISABLE_PARAM_MASK  0x80



//  
//  0: USB IDAT SIN current source, VDAT DET comparator, VDAT_REF reference are disabled 
//  1: USB IDAT SIN current source, VDAT DET comparator, VDAT_REF reference are 
//  enabled.
//  Register UsbPhyMmanagement3 0x0583, Bits 0:0, typedef idat_sink_enable
//   
//  
#define IDAT_SINK_MASK 0x1U
#define IDAT_SINK_OFFSET 0
#define IDAT_SINK_STOP_BIT 0
#define IDAT_SINK_START_BIT 0
#define IDAT_SINK_WIDTH 1

#define USB_PHY_MMANAGEMENT_3_REG 0x583

typedef enum idat_sink_enable {
    IDAT_SINK_DISABLE_E,
    IDAT_SINK_ENABLE_E
} IDAT_SINK_ENABLE_T ;
#define IDAT_SINK_PARAM_MASK  0x1



//  
//  0: USB VDAT SRC comparator, VDAT DET comparator, VDAT_REF reference are disabled 
//  1: USB VDAT SRC comparator, VDAT DET comparator, VDAT_REF reference comparators are 
//  enabled.
//  Register UsbPhyMmanagement3 0x0583, Bits 1:1, typedef vdat_source_enable
//   
//  
#define VDAT_SOURCE_MASK 0x2U
#define VDAT_SOURCE_OFFSET 1
#define VDAT_SOURCE_STOP_BIT 1
#define VDAT_SOURCE_START_BIT 1
#define VDAT_SOURCE_WIDTH 1


typedef enum vdat_source_enable {
    VDAT_SOURCE_DISABLE_E,
    VDAT_SOURCE_ENABLE_E
} VDAT_SOURCE_ENABLE_T ;
#define VDAT_SOURCE_PARAM_MASK  0x2



//  
//  0: SDP_SRC USB switch is opened 
//  1: SDP_SRC USB switch is closed.
//  Register UsbPhyMmanagement3 0x0583, Bits 2:2, typedef sdp_src_switch_opened
//   
//  
#define SDP_SRC_SWITCH_MASK 0x4U
#define SDP_SRC_SWITCH_OFFSET 2
#define SDP_SRC_SWITCH_STOP_BIT 2
#define SDP_SRC_SWITCH_START_BIT 2
#define SDP_SRC_SWITCH_WIDTH 1


typedef enum sdp_src_switch_opened {
    SDP_SRC_SWITCH_CLOSE_E,
    SDP_SRC_SWITCH_OPEN_E
} SDP_SRC_SWITCH_OPENED_T ;
#define SDP_SRC_SWITCH_PARAM_MASK  0x4



//  
//  0: SDM_SRC USB switch is opened 
//  1: SDM_SRC USB switch is closed.
//  Register UsbPhyMmanagement3 0x0583, Bits 3:3, typedef sdm_src_switch_opened
//   
//  
#define SDM_SRC_SWITCH_MASK 0x8U
#define SDM_SRC_SWITCH_OFFSET 3
#define SDM_SRC_SWITCH_STOP_BIT 3
#define SDM_SRC_SWITCH_START_BIT 3
#define SDM_SRC_SWITCH_WIDTH 1


typedef enum sdm_src_switch_opened {
    SDM_SRC_SWITCH_CLOSE_E,
    SDM_SRC_SWITCH_OPEN_E
} SDM_SRC_SWITCH_OPENED_T ;
#define SDM_SRC_SWITCH_PARAM_MASK  0x8



//  
//  0: SDP_SNK USB switch is opened 
//  1: SDP_SNK USB switch is closed.
//  Register UsbPhyMmanagement3 0x0583, Bits 4:4, typedef sdp_snk_switch_opened
//   
//  
#define SDP_SNK_SWITCH_MASK 0x10U
#define SDP_SNK_SWITCH_OFFSET 4
#define SDP_SNK_SWITCH_STOP_BIT 4
#define SDP_SNK_SWITCH_START_BIT 4
#define SDP_SNK_SWITCH_WIDTH 1


typedef enum sdp_snk_switch_opened {
    SDP_SNK_SWITCH_CLOSE_E,
    SDP_SNK_SWITCH_OPEN_E
} SDP_SNK_SWITCH_OPENED_T ;
#define SDP_SNK_SWITCH_PARAM_MASK  0x10



//  
//  0: SDM_SNK USB switch is opened 
//  1: SDM_SNK USB switch is closed.
//  Register UsbPhyMmanagement3 0x0583, Bits 5:5, typedef sdm_snk_switch_opened
//   
//  
#define SDM_SNK_SWITCH_MASK 0x20U
#define SDM_SNK_SWITCH_OFFSET 5
#define SDM_SNK_SWITCH_STOP_BIT 5
#define SDM_SNK_SWITCH_START_BIT 5
#define SDM_SNK_SWITCH_WIDTH 1


typedef enum sdm_snk_switch_opened {
    SDM_SNK_SWITCH_CLOSE_E,
    SDM_SNK_SWITCH_OPEN_E
} SDM_SNK_SWITCH_OPENED_T ;
#define SDM_SNK_SWITCH_PARAM_MASK  0x20



//  
//  0: Data Connect source is disabled 
//  1:Data Connect source is enable.
//  Register UsbPhyMmanagement3 0x0583, Bits 6:6, typedef data_connect_source_enable
//   
//  
#define DATA_CONNECT_SOURCE_MASK 0x40U
#define DATA_CONNECT_SOURCE_OFFSET 6
#define DATA_CONNECT_SOURCE_STOP_BIT 6
#define DATA_CONNECT_SOURCE_START_BIT 6
#define DATA_CONNECT_SOURCE_WIDTH 1


typedef enum data_connect_source_enable {
    DATA_CONNECT_SOURCE_DISABLE_E,
    DATA_CONNECT_SOURCE_ENABLE_E
} DATA_CONNECT_SOURCE_ENABLE_T ;
#define DATA_CONNECT_SOURCE_PARAM_MASK  0x40



//  
//  0: inactive 
//  1: force 60 Mhz PLL on.
//  Register UsbPhyMmanagement3 0x0583, Bits 7:7, typedef data_connect_detection_enable
//   
//  
#define DATA_CONNECT_DETECTION_MASK 0x80U
#define DATA_CONNECT_DETECTION_OFFSET 7
#define DATA_CONNECT_DETECTION_STOP_BIT 7
#define DATA_CONNECT_DETECTION_START_BIT 7
#define DATA_CONNECT_DETECTION_WIDTH 1


typedef enum data_connect_detection_enable {
    DATA_CONNECT_DETECTION_DISABLE_E,
    DATA_CONNECT_DETECTION_ENABLE_E
} DATA_CONNECT_DETECTION_ENABLE_T ;
#define DATA_CONNECT_DETECTION_PARAM_MASK  0x80



//  
//  0: Disable ID Device detection 
//  1: Enable ID Device detection(default).
//  Register UsbPhyAdaptation 0x0587, Bits 0:0, typedef detection
//   
//  
#define DEVICE_DETECTION_MASK 0x1U
#define DEVICE_DETECTION_OFFSET 0
#define DEVICE_DETECTION_STOP_BIT 0
#define DEVICE_DETECTION_START_BIT 0
#define DEVICE_DETECTION_WIDTH 1

#define USB_PHY_ADAPTATION_REG 0x587
#define  ENABLE_DETECTION 0
#define  DISABLE_DETECTION 1

typedef enum detection {
    ENABLE_DETECTION_E,
    DISABLE_DETECTION_E
} DETECTION_T ;
#define DEVICE_DETECTION_PARAM_MASK  0x1



//  
//  0: Disable ID Host detection 
//  1: Enable ID Host detection.
//  Register UsbPhyAdaptation 0x0587, Bits 1:1, typedef detection
//   
//  
#define ID_HOST_DETECTION_MASK 0x2U
#define ID_HOST_DETECTION_OFFSET 1
#define ID_HOST_DETECTION_STOP_BIT 1
#define ID_HOST_DETECTION_START_BIT 1
#define ID_HOST_DETECTION_WIDTH 1

#define  ENABLE_DETECTION 0
#define  DISABLE_DETECTION 1

#define ID_HOST_DETECTION_PARAM_MASK  0x2



//  
//  0: Disable VBUS Valid comparator 
//  1: Enable VBUS Valid comparator.
//  Register UsbPhyAdaptation 0x0587, Bits 5:5, typedef valid_compatrator_enable
//   
//  
#define VBUS_VALID_MASK 0x20U
#define VBUS_VALID_OFFSET 5
#define VBUS_VALID_STOP_BIT 5
#define VBUS_VALID_START_BIT 5
#define VBUS_VALID_WIDTH 1


typedef enum valid_compatrator_enable {
    VALID_COMPATRATOR_DISABLE_E,
    VALID_COMPATRATOR_ENABLE_E
} VALID_COMPATRATOR_ENABLE_T ;
#define VBUS_VALID_PARAM_MASK  0x20



//  
//  0: ID resistance is floating (no micro-A plug detected) 
//  1: ID resistance is grounded (micro-A plug detected)k.
//  Register OtgIdResistance 0x0588, Bits 0:0, typedef resitance
//   
//  
#define ID_WAKEUP_MASK 0x1U
#define ID_WAKEUP_OFFSET 0
#define ID_WAKEUP_STOP_BIT 0
#define ID_WAKEUP_START_BIT 0
#define ID_WAKEUP_WIDTH 1

#define OTG_ID_RESISTANCE_REG 0x588

typedef enum resitance {
    FLOATING_E,
    GROUNDED_E
} RESITANCE_T ;
#define ID_WAKEUP_PARAM_MASK  0x1



//  
//  0: ID resistance is above R1 
//  1: ID resistance is below R1.
//  Register OtgIdResistance 0x0588, Bits 1:1, typedef id_resitance
//   
//  
#define ID_DET_R1_MASK 0x2U
#define ID_DET_R1_OFFSET 1
#define ID_DET_R1_STOP_BIT 1
#define ID_DET_R1_START_BIT 1
#define ID_DET_R1_WIDTH 1

#define  BELOW 0
#define  ABOVE 1

typedef enum id_resitance {
    BELOW_E,
    ABOVE_E
} ID_RESITANCE_T ;
#define ID_DET_R1_PARAM_MASK  0x2



//  
//  0: ID resistance is above R2 
//  1: ID resistance is below R2.
//  Register OtgIdResistance 0x0588, Bits 2:2, typedef id_resitance
//   
//  
#define ID_DET_R2_MASK 0x4U
#define ID_DET_R2_OFFSET 2
#define ID_DET_R2_STOP_BIT 2
#define ID_DET_R2_START_BIT 2
#define ID_DET_R2_WIDTH 1

#define  BELOW 0
#define  ABOVE 1

#define ID_DET_R2_PARAM_MASK  0x4



//  
//  0: ID resistance is above R3 
//  1: ID resistance is below R3.
//  Register OtgIdResistance 0x0588, Bits 3:3, typedef id_resitance
//   
//  
#define ID_DET_R3_MASK 0x8U
#define ID_DET_R3_OFFSET 3
#define ID_DET_R3_STOP_BIT 3
#define ID_DET_R3_START_BIT 3
#define ID_DET_R3_WIDTH 1

#define  BELOW 0
#define  ABOVE 1

#define ID_DET_R3_PARAM_MASK  0x8



//  
//  0: ID resistance is above R4 
//  1: ID resistance is below R4.
//  Register OtgIdResistance 0x0588, Bits 4:4, typedef id_resitance
//   
//  
#define ID_DET_R4_MASK 0x10U
#define ID_DET_R4_OFFSET 4
#define ID_DET_R4_STOP_BIT 4
#define ID_DET_R4_START_BIT 4
#define ID_DET_R4_WIDTH 1

#define  BELOW 0
#define  ABOVE 1

#define ID_DET_R4_PARAM_MASK  0x10



//  
//  0: 5V generation is disabled 
//  1: 5V generation is enabled.
//  Register OtgIdResistance 0x0588, Bits 5:5, typedef vbus_generation_enable
//   
//  
#define DRIVE_VBUS_MASK 0x20U
#define DRIVE_VBUS_OFFSET 5
#define DRIVE_VBUS_STOP_BIT 5
#define DRIVE_VBUS_START_BIT 5
#define DRIVE_VBUS_WIDTH 1


typedef enum vbus_generation_enable {
    VBUS_GENERATION_DISABLE_E,
    VBUS_GENERATION_ENABLE_E
} VBUS_GENERATION_ENABLE_T ;
#define DRIVE_VBUS_PARAM_MASK  0x20



//  
//  .
//  Register UsbPhyStatus 0x0589, Bits 0:0, typedef suspend_mode
//   
//  
#define SUSPEND_MODE_MASK 0x1U
#define SUSPEND_MODE_OFFSET 0
#define SUSPEND_MODE_STOP_BIT 0
#define SUSPEND_MODE_START_BIT 0
#define SUSPEND_MODE_WIDTH 1

#define USB_PHY_STATUS_REG 0x589



//  
//  .
//  Register UsbPhyStatus 0x0589, Bits 1:1, typedef chirp_mode
//   
//  
#define CHIRP_MODE_MASK 0x2U
#define CHIRP_MODE_OFFSET 1
#define CHIRP_MODE_STOP_BIT 1
#define CHIRP_MODE_START_BIT 1
#define CHIRP_MODE_WIDTH 1




//  
//  .
//  Register UsbPhyStatus 0x0589, Bits 2:2, typedef high_speed_mode
//   
//  
#define HIGH_SPEED_MODE_MASK 0x4U
#define HIGH_SPEED_MODE_OFFSET 2
#define HIGH_SPEED_MODE_STOP_BIT 2
#define HIGH_SPEED_MODE_START_BIT 2
#define HIGH_SPEED_MODE_WIDTH 1




//  
//  0: doesn't turn on USB PHY 
//  1: turn on USB PHY in host mode.
//  Register UsbPhyControl 0x058A, Bits 0:0, typedef usb_host_mode_enable
//   
//  
#define USB_HOST_MODE_MASK 0x1U
#define USB_HOST_MODE_OFFSET 0
#define USB_HOST_MODE_STOP_BIT 0
#define USB_HOST_MODE_START_BIT 0
#define USB_HOST_MODE_WIDTH 1

#define USB_PHY_CONTROL_REG 0x58A

typedef enum usb_host_mode_enable {
    USB_HOST_MODE_DISABLE_E,
    USB_HOST_MODE_ENABLE_E
} USB_HOST_MODE_ENABLE_T ;
#define USB_HOST_MODE_PARAM_MASK  0x1



//  
//  0: doesn't turn on USB PHY 
//  1: turn on USB PHY in Device mode (turn on sequence of USB PHY with no Vbus 
//  generation).
//  Register UsbPhyControl 0x058A, Bits 1:1, typedef usb_device_mode_enable
//   
//  
#define USB_DEVICE_MODE_MASK 0x2U
#define USB_DEVICE_MODE_OFFSET 1
#define USB_DEVICE_MODE_STOP_BIT 1
#define USB_DEVICE_MODE_START_BIT 1
#define USB_DEVICE_MODE_WIDTH 1


typedef enum usb_device_mode_enable {
    USB_DEVICE_MODE_DISABLE_E,
    USB_DEVICE_MODE_ENABLE_E
} USB_DEVICE_MODE_ENABLE_T ;
#define USB_DEVICE_MODE_PARAM_MASK  0x2


#define TIME_TWO_THRESHOLDS_LSB_REG 0x591

//  
//  Time between two thresholds: UsbAdpTimeCurrent[10:0] x Clk32kHz period (max about 
//  63.9ms).
//  Register TimeTwoThresholdsMsb 0x0592, Bits 0:0, typedef adp_probe_time
//   
//  
#define USB_ADP_PROBE_TIME_CURRENT_MASK 0x1U
#define USB_ADP_PROBE_TIME_CURRENT_OFFSET 0
#define USB_ADP_PROBE_TIME_CURRENT_STOP_BIT 0
#define USB_ADP_PROBE_TIME_CURRENT_START_BIT 0
#define USB_ADP_PROBE_TIME_CURRENT_WIDTH 1

#define TIME_TWO_THRESHOLDS_MSB_REG 0x592



//  
//  Threshold tolerance of AdpProbeTimeCurrent[10:0] measurement.
//  Register UsbAdpProbe 0x0593, Bits 1:3, typedef tolerance
//   
//  
#define ADP_PROBE_TIME_MASK 0xEU
#define ADP_PROBE_TIME_OFFSET 3
#define ADP_PROBE_TIME_STOP_BIT 3
#define ADP_PROBE_TIME_START_BIT 1
#define ADP_PROBE_TIME_WIDTH 3

#define USB_ADP_PROBE_REG 0x593



//  
//  0: inactive 
//  1: ADP is enabled.
//  Register UsbAdpProbe 0x0593, Bits 0:0, typedef adp_enabled
//   
//  
#define ADP_MASK 0x1U
#define ADP_OFFSET 0
#define ADP_STOP_BIT 0
#define ADP_START_BIT 0
#define ADP_WIDTH 1


typedef enum adp_enabled {
    ADP_DISABLE_E,
    ADP_ENABLE_E
} ADP_ENABLED_T ;
#define ADP_PARAM_MASK  0x1



//  
//  LinkStatus.
//  Register UsbLinkStatus 0x0594, Bits 3:7, typedef link_status
//   
//  
#define USB_LINK_STATUS_MASK 0xF8U
#define USB_LINK_STATUS_OFFSET 7
#define USB_LINK_STATUS_STOP_BIT 7
#define USB_LINK_STATUS_START_BIT 3
#define USB_LINK_STATUS_WIDTH 5

#define USB_LINK_STATUS_REG 0x594
#define  NOT_CONFIGURED 0
#define  STANDARD_HOST_NOT_CHARGING 1
#define  STANDARD_HOST_CHARGING_CHARGING 2
#define  STANDARD_HOST_CHARGING_SUSPENDED 3
#define  HOST_CHARGER_CPD 4
#define  RES1 5
#define  RES2 6
#define  HOST_CHARGER_DCP 7

typedef enum link_status {
    NOT_CONFIGURED_E,
    STANDARD_HOST_NOT_CHARGING_E,
    STANDARD_HOST_CHARGING_CHARGING_E,
    STANDARD_HOST_CHARGING_SUSPENDED_E,
    HOST_CHARGER_CPD_E,
    RES1_E,
    RES2_E,
    HOST_CHARGER_DCP_E
} LINK_STATUS_T ;
#define USB_LINK_STATUS_PARAM_MASK  0xF8


#endif
