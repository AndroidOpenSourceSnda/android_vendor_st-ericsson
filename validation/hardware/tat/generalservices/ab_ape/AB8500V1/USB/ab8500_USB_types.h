/****************************************************************************
 * File : c:/Lisp/Production/ab8500/ab8500_USB/Linux/ab8500_USB_types.h
 * 
 *
 * Generated on the 26/02/2010 09:06 by the 'gen-I2C' code generator 
 *
 * Generator written in Common Lisp, created by  R�mi PRUD'HOMME - ST 
 * with the help of : Gr�gory GOSCINIACK - ST, Ir�n�e BROCHIER - Teamlog
 *
 ***************************************************************************
 *  Copyrigtht ST Microelectronics  2009
 ***************************************************************************/

/****************************************************************************
 * Modifications:
 *  CAP_948_001: 22 March 2010 by Karine Boclaud
 *
 ***************************************************************************/

#ifndef C__LISP_PRODUCTION_AB8500_AB8500_USB_LINUX_AB8500_USB_TYPES_H
#define C__LISP_PRODUCTION_AB8500_AB8500_USB_LINUX_AB8500_USB_TYPES_H



#define  NOT_CONFIGURED 0
#define  STANDARD_HOST_NOT_CHARGING 1
#define  STANDARD_HOST_CHARGING_NOT_SUSPENDED 2
#define  STANDARD_HOST_CHARGING_SUSPENDED 3
#define  HOST_CHARGER_NORMAL_MODE 4
#define  HOST_CHARGER_HS_MODE 5
#define  HOST_CHARGER_HS_CHIRP_MODE 6
#define  DEDICATED_USX_CHARGER 7
#define  ACA_RID_A_CONFIGURATION 8
#define  ACA_RID_B_CONFIGURATION 9
#define  ACA_RID_C_CONFIGURATION_NORMAL_MODE 10
#define  ACA_RID_C_CONFIGURATION_HS_MODE 11
#define  ACA_RID_C_CONFIGURATION_HS_CHIRP_MODE 12
#define  HOST_MODE 13
#define  RESERVED 14
#define  USB_LINK_NOT_VALID 15



typedef enum charger_type {
    NOT_CONFIGURED_E,
    STANDARD_HOST_NOT_CHARGING_E,
    STANDARD_HOST_CHARGING_NOT_SUSPENDED_E,
    STANDARD_HOST_CHARGING_SUSPENDED_E,
    HOST_CHARGER_NORMAL_MODE_E,
    HOST_CHARGER_HS_MODE_E,
    HOST_CHARGER_HS_CHIRP_MODE_E,
    DEDICATED_USX_CHARGER_E,
    ACA_RID_A_CONFIGURATION_E,
    ACA_RID_B_CONFIGURATION_E,
    ACA_RID_C_CONFIGURATION_NORMAL_MODE_E,
    ACA_RID_C_CONFIGURATION_HS_MODE_E,
    ACA_RID_C_CONFIGURATION_HS_CHIRP_MODE_E,
    HOST_MODE_E,
    RESERVED_E,
    USB_LINK_NOT_VALID_E
} CHARGER_TYPE_T ;




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
#define CHARGER_TYPE_MASK 0x78
#define CHARGER_TYPE_OFFSET 6
#define CHARGER_TYPE_STOP_BIT 6
#define CHARGER_TYPE_START_BIT 3
#define CHARGER_TYPE_WIDTH 4

#define USB_LINE_STATUS_REG 0x580
#define CHARGER_TYPE_PARAM_MASK  0x78

//  
//  0: No Host charger detected 
//  1: Host Charger detected.
//  Register UsbLineStatus 0x0580, Bits 2:2, typedef host_charger_detected
//   
//  
#define HOST_CHARGER_DETECTED_MASK 0x4
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
//  0: DM Single Ended Receiver output is low 
//  1: DMSingle Ended Receiver output is high.
//  Register UsbLineStatus 0x0580, Bits 1:1, typedef dminus_receiver_high
//   
//  
#define DMINUS_CMP_OUT_MASK 0x2
#define DMINUS_CMP_OUT_OFFSET 1
#define DMINUS_CMP_OUT_STOP_BIT 1
#define DMINUS_CMP_OUT_START_BIT 1
#define DMINUS_CMP_OUT_WIDTH 1


typedef enum dminus_receiver_high {
    DMINUS_RECEIVER_LOW_E,
    DMINUS_RECEIVER_HIGH_E
} DMINUS_RECEIVER_HIGH_T ;

#define DMINUS_RECEIVER_HIGH_PARAM_MASK  0x2

//  
//  0: DM Single Ended Receiver output is low 
//  1: DMSingle Ended Receiver output is high.
//  Register UsbLineStatus 0x0580, Bits 0:0, typedef dplus_receiver_high
//   
//  
#define DPLUS_CMP_OUT_MASK 0x1
#define DPLUS_CMP_OUT_OFFSET 0
#define DPLUS_CMP_OUT_STOP_BIT 0
#define DPLUS_CMP_OUT_START_BIT 0
#define DPLUS_CMP_OUT_WIDTH 1


typedef enum dplus_receiver_high {
    DPLUS_RECEIVER_LOW_E,
    DPLUS_RECEIVER_HIGH_E
} DPLUS_RECEIVER_HIGH_T ;

#define DPLUS_RECEIVER_HIGH_PARAM_MASK  0x1

/*+CAP_948_001*/
typedef enum dm_pull {
    DM_PULLDOWN_DISABLE_E,
    DM_PULLDOWN_ENABLE_E
} DM_PULL_T ;
/*-CAP_948_001*/



//  
//  0: DMPull Up disable 
//  1: DM Pull Up enable.
//  Register UsbPhyMmanagement 0x0581, Bits 6:6, typedef dm_pull_up_enable
//   
//  
#define DM_PULL_UP_MASK 0x40
#define DM_PULL_UP_OFFSET 6
#define DM_PULL_UP_STOP_BIT 6
#define DM_PULL_UP_START_BIT 6
#define DM_PULL_UP_WIDTH 1

#define USB_PHY_MMANAGEMENT_REG 0x581

typedef enum dm_pull_up_enable {
    DM_PULL_UP_DISABLE_E,
    DM_PULL_UP_ENABLE_E
} DM_PULL_UP_ENABLE_T ;

#define DM_PULL_UP_ENABLE_PARAM_MASK  0x40

//  
//  0: DpMPull Down disable 
//  1: DpM Pulldown enable.
//  Register UsbPhyMmanagement 0x0581, Bits 5:5, typedef dm_pull
//   
//  
#define DP_PULL_DOWN_MASK 0x20
#define DP_PULL_DOWN_OFFSET 5
#define DP_PULL_DOWN_STOP_BIT 5
#define DP_PULL_DOWN_START_BIT 5
#define DP_PULL_DOWN_WIDTH 1

#define DP_PULL_DOWN_PARAM_MASK  0x20
#define DM_PULL_PARAM_MASK  0x20

//  
//  0: DMPull Up disable 
//  1: DM Pull down enable.
//  Register UsbPhyMmanagement 0x0581, Bits 4:4, typedef dm_pull_down_enable
//   
//  
#define DM_PULL_DOWN_MASK 0x10
#define DM_PULL_DOWN_OFFSET 4
#define DM_PULL_DOWN_STOP_BIT 4
#define DM_PULL_DOWN_START_BIT 4
#define DM_PULL_DOWN_WIDTH 1


typedef enum dm_pull_down_enable {
    DM_PULL_DOWN_DISABLE_E,
    DM_PULL_DOWN_ENABLE_E
} DM_PULL_DOWN_ENABLE_T ;

#define DM_PULL_DOWN_ENABLE_PARAM_MASK  0x10

//  
//  0: DpPull Up disable 
//  1: DM Pull Up enable.
//  Register UsbPhyMmanagement 0x0581, Bits 3:3, typedef dp_pull_up_enable
//   
//  
#define DP_PULL_UP_MASK 0x8
#define DP_PULL_UP_OFFSET 3
#define DP_PULL_UP_STOP_BIT 3
#define DP_PULL_UP_START_BIT 3
#define DP_PULL_UP_WIDTH 1


typedef enum dp_pull_up_enable {
    DP_PULL_UP_DISABLE_E,
    DP_PULL_UP_ENABLE_E
} DP_PULL_UP_ENABLE_T ;

#define DP_PULL_UP_ENABLE_PARAM_MASK  0x8

//  
//  0: Pull-up and Pull-down switches (including ENC switches) are controlled by SPI 
//  register 
//  1: Pull-up and Pull-down switches (including ENC switches) are controlled by ULPI 
//  register.
//  Register UsbPhyMmanagement 0x0581, Bits 1:1, typedef usb_switch
//   
//  
#define USB_SWITCH_CTRL_MASK 0x2
#define USB_SWITCH_CTRL_OFFSET 1
#define USB_SWITCH_CTRL_STOP_BIT 1
#define USB_SWITCH_CTRL_START_BIT 1
#define USB_SWITCH_CTRL_WIDTH 1

#define  USB_SWITCH 2

/*+CAP_948_001*/
typedef enum usb_switch {
     CONTROLED_BY_SPI_E,
	 CONTROLED_BY_ULPI_E
} USB_SWITCH_T ;
/*-CAP_948_001*/
#define USB_SWITCH_PARAM_MASK  0x2



//  
//  0: S4 switch is open (disables Charger pull up on Dplus line) 
//  1: S4 switch is closed (enables Charger pull up on Dplus line).
//  Register UsbPhyMmanagement 0x0581, Bits 0:0, typedef charger_pull_up_close
//   
//  
#define CHARGER_PULL_UP_MASK 0x1
#define CHARGER_PULL_UP_OFFSET 0
#define CHARGER_PULL_UP_STOP_BIT 0
#define CHARGER_PULL_UP_START_BIT 0
#define CHARGER_PULL_UP_WIDTH 1

#define  CHARGER_PULL_UP_CLOSE 1

/*+CAP_948_001*/
typedef enum charger_pull_up_close {
   CHARGER_PULLUP_OPEN_E,
   CHARGER_PULLUP_CLOSED_E
} CHARGER_PULL_UP_CLOSE_T ;
/*-CAP_948_001*/
#define CHARGER_PULL_UP_CLOSE_PARAM_MASK  0x1



//  
//  0: Disable DM 19.25KOhms pull down 
//  1: Enable DM 19.25kOhms pull down.
//  Register UsbPhyMmanagement2 0x0582, Bits 7:7, typedef dm_pull
//   
//  
#define DM_PULL_DOWN_DISABLE_MASK 0x80
#define DM_PULL_DOWN_DISABLE_OFFSET 7
#define DM_PULL_DOWN_DISABLE_STOP_BIT 7
#define DM_PULL_DOWN_DISABLE_START_BIT 7
#define DM_PULL_DOWN_DISABLE_WIDTH 1

#define USB_PHY_MMANAGEMENT_2_REG 0x582
#define DM_PULL_DOWN_DISABLE_PARAM_MASK  0x80

//  
//  0: DM 19.25kOhms pull down and Single Ended Receiver controlled by ULPI 
//  1: DM 19.25kOhms pull down and Single Ended Receiver controlled by SPI for 
//  charger.
//  Register UsbPhyMmanagement2 0x0582, Bits 6:6, typedef charger_mux_ctrl
//   
//  
#define CHARGER_MUX_CTRL_MASK 0x40
#define CHARGER_MUX_CTRL_OFFSET 6
#define CHARGER_MUX_CTRL_STOP_BIT 6
#define CHARGER_MUX_CTRL_START_BIT 6
#define CHARGER_MUX_CTRL_WIDTH 1

#define  CHARGER_MUX_CTRL 64

/*+CAP_948_001*/
typedef enum charger_mux_ctrl {
    UPLI_E,
    SPI_E
} CHARGER_MUX_CTRL_T ;
/*-CAP_948_001*/
#define CHARGER_MUX_CTRL_PARAM_MASK  0x40



//  
//  0: disable USB charger detection 
//  1: enable USB charger detection.
//  Register UsbPhyMmanagement2 0x0582, Bits 0:0, typedef usb_charger_detection_enable
//   
//  
#define USB_CHARGER_DETECTION_MASK 0x1
#define USB_CHARGER_DETECTION_OFFSET 0
#define USB_CHARGER_DETECTION_STOP_BIT 0
#define USB_CHARGER_DETECTION_START_BIT 0
#define USB_CHARGER_DETECTION_WIDTH 1


typedef enum usb_charger_detection_enable {
    USB_CHARGER_DETECTION_DISABLE_E,
    USB_CHARGER_DETECTION_ENABLE_E
} USB_CHARGER_DETECTION_ENABLE_T ;

#define USB_CHARGER_DETECTION_ENABLE_PARAM_MASK  0x1

//  
//  0: inactive 
//  1: force 60 Mhz PLL on.
//  Register UsbPhyMmanagement3 0x0583, Bits 7:7, typedef data_connect_detection_enable
//   
//  
#define DATA_CONNECT_DETECTION_ENABLE_MASK 0x80
#define DATA_CONNECT_DETECTION_ENABLE_OFFSET 7
#define DATA_CONNECT_DETECTION_ENABLE_STOP_BIT 7
#define DATA_CONNECT_DETECTION_ENABLE_START_BIT 7
#define DATA_CONNECT_DETECTION_ENABLE_WIDTH 1

#define USB_PHY_MMANAGEMENT_3_REG 0x583

typedef enum data_connect_detection_enable {
    DATA_CONNECT_DETECTION_DISABLE_E,
    DATA_CONNECT_DETECTION_ENABLE_E
} DATA_CONNECT_DETECTION_ENABLE_T ;

#define DATA_CONNECT_DETECTION_ENABLE_PARAM_MASK  0x80

//  
//  0: Data Connect source is disabled 
//  1:Data Connect source is enable.
//  Register UsbPhyMmanagement3 0x0583, Bits 6:6, typedef data_connect_source_enable
//   
//  
#define DATA_CONNECT_SOURCE_ENABLE_MASK 0x40
#define DATA_CONNECT_SOURCE_ENABLE_OFFSET 6
#define DATA_CONNECT_SOURCE_ENABLE_STOP_BIT 6
#define DATA_CONNECT_SOURCE_ENABLE_START_BIT 6
#define DATA_CONNECT_SOURCE_ENABLE_WIDTH 1


typedef enum data_connect_source_enable {
    DATA_CONNECT_SOURCE_DISABLE_E,
    DATA_CONNECT_SOURCE_ENABLE_E
} DATA_CONNECT_SOURCE_ENABLE_T ;

#define DATA_CONNECT_SOURCE_ENABLE_PARAM_MASK  0x40

//  
//  0: SDM_SNK USB switch is opened 
//  1: SDM_SNK USB switch is closed.
//  Register UsbPhyMmanagement3 0x0583, Bits 5:5, typedef sdm_snk_switch_opened
//   
//  
#define SDM_SNK_SWITCH_MASK 0x20
#define SDM_SNK_SWITCH_OFFSET 5
#define SDM_SNK_SWITCH_STOP_BIT 5
#define SDM_SNK_SWITCH_START_BIT 5
#define SDM_SNK_SWITCH_WIDTH 1


/*+CAP_948_001*/
typedef enum sdm_snk_switch_opened {
     SDM_SNK_SWITCH_OPEN_E,
	 SDM_SNK_SWITCH_CLOSE_E
} SDM_SNK_SWITCH_OPENED_T ;
/*-CAP_948_001*/

#define SDM_SNK_SWITCH_OPENED_PARAM_MASK  0x20

//  
//  0: SDP_SNK USB switch is opened 
//  1: SDP_SNK USB switch is closed.
//  Register UsbPhyMmanagement3 0x0583, Bits 4:4, typedef sdp_snk_switch_opened
//   
//  
#define SDP_SNK_SWITCH_MASK 0x10
#define SDP_SNK_SWITCH_OFFSET 4
#define SDP_SNK_SWITCH_STOP_BIT 4
#define SDP_SNK_SWITCH_START_BIT 4
#define SDP_SNK_SWITCH_WIDTH 1


/*+CAP_948_001*/
typedef enum sdp_snk_switch_opened {
    SDP_SNK_SWITCH_OPEN_E,
    SDP_SNK_SWITCH_CLOSE_E
} SDP_SNK_SWITCH_OPENED_T ;
/*-CAP_948_001*/

#define SDP_SNK_SWITCH_OPENED_PARAM_MASK  0x10

//  
//  0: SDM_SRC USB switch is opened 
//  1: SDM_SRC USB switch is closed.
//  Register UsbPhyMmanagement3 0x0583, Bits 3:3, typedef sdm_src_switch_opened
//   
//  
#define SDM_SRC_SWITCH_MASK 0x8
#define SDM_SRC_SWITCH_OFFSET 3
#define SDM_SRC_SWITCH_STOP_BIT 3
#define SDM_SRC_SWITCH_START_BIT 3
#define SDM_SRC_SWITCH_WIDTH 1


/*+CAP_948_001*/
typedef enum sdm_src_switch_opened {
    SDM_SRC_SWITCH_OPEN_E,
	SDM_SRC_SWITCH_CLOSE_E
} SDM_SRC_SWITCH_OPENED_T ;
/*-CAP_948_001*/

#define SDM_SRC_SWITCH_OPENED_PARAM_MASK  0x8

//  
//  0: SDP_SRC USB switch is opened 
//  1: SDP_SRC USB switch is closed.
//  Register UsbPhyMmanagement3 0x0583, Bits 2:2, typedef sdp_src_switch_opened
//   
//  
#define SDP_SRC_SWITCH_MASK 0x4
#define SDP_SRC_SWITCH_OFFSET 2
#define SDP_SRC_SWITCH_STOP_BIT 2
#define SDP_SRC_SWITCH_START_BIT 2
#define SDP_SRC_SWITCH_WIDTH 1


/*+CAP_948_001*/
typedef enum sdp_src_switch_opened {
    SDP_SRC_SWITCH_OPEN_E,
    SDP_SRC_SWITCH_CLOSE_E
} SDP_SRC_SWITCH_OPENED_T ;
/*-CAP_948_001*/

#define SDP_SRC_SWITCH_OPENED_PARAM_MASK  0x4

//  
//  0: USB VDAT SRC comparator, VDAT DET comparator, VDAT_REF reference are disabled 
//  1: USB VDAT SRC comparator, VDAT DET comparator, VDAT_REF reference comparators are 
//  enabled.
//  Register UsbPhyMmanagement3 0x0583, Bits 1:1, typedef vdat_source_enable
//   
//  
#define VDAT_SOURCE_MASK 0x2
#define VDAT_SOURCE_OFFSET 1
#define VDAT_SOURCE_STOP_BIT 1
#define VDAT_SOURCE_START_BIT 1
#define VDAT_SOURCE_WIDTH 1


typedef enum vdat_source_enable {
    VDAT_SOURCE_DISABLE_E,
    VDAT_SOURCE_ENABLE_E
} VDAT_SOURCE_ENABLE_T ;

#define VDAT_SOURCE_ENABLE_PARAM_MASK  0x2

//  
//  0: USB IDAT SIN current source, VDAT DET comparator, VDAT_REF reference are disabled 
//  1: USB IDAT SIN current source, VDAT DET comparator, VDAT_REF reference are 
//  enabled.
//  Register UsbPhyMmanagement3 0x0583, Bits 0:0, typedef idat_sink_enable
//   
//  
#define IDAT_SINK_MASK 0x1
#define IDAT_SINK_OFFSET 0
#define IDAT_SINK_STOP_BIT 0
#define IDAT_SINK_START_BIT 0
#define IDAT_SINK_WIDTH 1


typedef enum idat_sink_enable {
    IDAT_SINK_DISABLE_E,
    IDAT_SINK_ENABLE_E
} IDAT_SINK_ENABLE_T ;

#define IDAT_SINK_ENABLE_PARAM_MASK  0x1

/*+CAP_948_001*/
typedef enum detection {
     DISABLE_DETECTION_E,
	 ENABLE_DETECTION_E
} DETECTION_T ;
/*-CAP_948_001*/



//  
//  0: Disable VBUS comparators 
//  1: Enable VBUS comparator.
//  Register UsbPhyAdaptation 0x0587, Bits 6:6, typedef compatrator_enable
//   
//  
#define VBUS_COMP_MASK 0x40
#define VBUS_COMP_OFFSET 6
#define VBUS_COMP_STOP_BIT 6
#define VBUS_COMP_START_BIT 6
#define VBUS_COMP_WIDTH 1

#define USB_PHY_ADAPTATION_REG 0x587

typedef enum compatrator_enable {
    COMPATRATOR_DISABLE_E,
    COMPATRATOR_ENABLE_E
} COMPATRATOR_ENABLE_T ;

#define COMPATRATOR_ENABLE_PARAM_MASK  0x40

//  
//  0: Disable VBUS Valid comparator 
//  1: Enable VBUS Valid comparator.
//  Register UsbPhyAdaptation 0x0587, Bits 5:5, typedef valid_compatrator_enable
//   
//  
#define VBUS_VALID_MASK 0x20
#define VBUS_VALID_OFFSET 5
#define VBUS_VALID_STOP_BIT 5
#define VBUS_VALID_START_BIT 5
#define VBUS_VALID_WIDTH 1


typedef enum valid_compatrator_enable {
    VALID_COMPATRATOR_DISABLE_E,
    VALID_COMPATRATOR_ENABLE_E
} VALID_COMPATRATOR_ENABLE_T ;

#define VALID_COMPATRATOR_ENABLE_PARAM_MASK  0x20

//  
//  0: Disable ID Host detection 
//  1: Enable ID Host detection.
//  Register UsbPhyAdaptation 0x0587, Bits 1:1, typedef detection
//   
//  
#define ID_HOST_DETECTION_MASK 0x2
#define ID_HOST_DETECTION_OFFSET 1
#define ID_HOST_DETECTION_STOP_BIT 1
#define ID_HOST_DETECTION_START_BIT 1
#define ID_HOST_DETECTION_WIDTH 1

#define ID_HOST_DETECTION_PARAM_MASK  0x2
#define DETECTION_PARAM_MASK  0x2

//  
//  0: Disable ID Device detection 
//  1: Enable ID Device detection.
//  Register UsbPhyAdaptation 0x0587, Bits 0:0, typedef detection
//   
//  
#define DEVICE_DETECTION_MASK 0x1
#define DEVICE_DETECTION_OFFSET 0
#define DEVICE_DETECTION_STOP_BIT 0
#define DEVICE_DETECTION_START_BIT 0
#define DEVICE_DETECTION_WIDTH 1

#define DEVICE_DETECTION_PARAM_MASK  0x1

/*+CAP_948_001*/
typedef enum id_resitance {
     BELOW_E,
	 ABOVE_E
} ID_RESITANCE_T ;
/*-CAP_948_001*/



//  
//  0: ID resistance is below 330k 
//  1: ID resistance is above 330k.
//  Register OtgIdResistance 0x0588, Bits 4:4, typedef id_resitance
//   
//  
#define ID_DET_33_0K_MASK 0x10
#define ID_DET_33_0K_OFFSET 4
#define ID_DET_33_0K_STOP_BIT 4
#define ID_DET_33_0K_START_BIT 4
#define ID_DET_33_0K_WIDTH 1

#define OTG_ID_RESISTANCE_REG 0x588
#define ID_DET_33_0K_PARAM_MASK  0x10
#define ID_RESITANCE_PARAM_MASK  0x10

//  
//  0: ID resistance is below 220k 
//  1: ID resistance is above 220k.
//  Register OtgIdResistance 0x0588, Bits 3:3, typedef id_resitance
//   
//  
#define ID_DET_22_0K_MASK 0x8
#define ID_DET_22_0K_OFFSET 3
#define ID_DET_22_0K_STOP_BIT 3
#define ID_DET_22_0K_START_BIT 3
#define ID_DET_22_0K_WIDTH 1

#define ID_DET_22_0K_PARAM_MASK  0x8

//  
//  0: ID resistance is below 140k 
//  1: ID resistance is above 140k.
//  Register OtgIdResistance 0x0588, Bits 2:2, typedef id_resitance
//   
//  
#define ID_DET_14_0K_MASK 0x4
#define ID_DET_14_0K_OFFSET 2
#define ID_DET_14_0K_STOP_BIT 2
#define ID_DET_14_0K_START_BIT 2
#define ID_DET_14_0K_WIDTH 1

#define ID_DET_14_0K_PARAM_MASK  0x4

//  
//  0: ID resistance is below 80k 
//  1: ID resistance is above 80k.
//  Register OtgIdResistance 0x0588, Bits 1:1, typedef id_resitance
//   
//  
#define ID_DET_8_0K_MASK 0x2
#define ID_DET_8_0K_OFFSET 1
#define ID_DET_8_0K_STOP_BIT 1
#define ID_DET_8_0K_START_BIT 1
#define ID_DET_8_0K_WIDTH 1

#define ID_DET_8_0K_PARAM_MASK  0x2

//  
//  0: ID resistance is floating (no micro-A plug detected) 
//  1: ID resistance is grounded (micro-A plug detected)k.
//  Register OtgIdResistance 0x0588, Bits 0:0, typedef resitance
//   
//  
#define ID_WAKEUP_MASK 0x1
#define ID_WAKEUP_OFFSET 0
#define ID_WAKEUP_STOP_BIT 0
#define ID_WAKEUP_START_BIT 0
#define ID_WAKEUP_WIDTH 1

#define  RESITANCE 1

/*+CAP_948_001*/
typedef enum resitance {
     FLOATING_E,
	 GROUNDED_E
} RESITANCE_T ;
/*-CAP_948_001*/
#define RESITANCE_PARAM_MASK  0x1



//  
//  .
//  Register UsbPhyStatus 0x0589, Bits 2:2, typedef high_speed_mode
//   
//  
#define HIGH_SPEED_MODE_MASK 0x4
#define HIGH_SPEED_MODE_OFFSET 2
#define HIGH_SPEED_MODE_STOP_BIT 2
#define HIGH_SPEED_MODE_START_BIT 2
#define HIGH_SPEED_MODE_WIDTH 1

#define USB_PHY_STATUS_REG 0x589
#define HIGH_SPEED_MODE_PARAM_MASK  0x4

//  
//  .
//  Register UsbPhyStatus 0x0589, Bits 1:1, typedef chirp_mode
//   
//  
#define CHIRP_MODE_MASK 0x2
#define CHIRP_MODE_OFFSET 1
#define CHIRP_MODE_STOP_BIT 1
#define CHIRP_MODE_START_BIT 1
#define CHIRP_MODE_WIDTH 1

#define CHIRP_MODE_PARAM_MASK  0x2

//  
//  .
//  Register UsbPhyStatus 0x0589, Bits 0:0, typedef suspend_mode
//   
//  
#define SUSPEND_MODE_MASK 0x1
#define SUSPEND_MODE_OFFSET 0
#define SUSPEND_MODE_STOP_BIT 0
#define SUSPEND_MODE_START_BIT 0
#define SUSPEND_MODE_WIDTH 1

#define SUSPEND_MODE_PARAM_MASK  0x1

//  
//  0: doesn�t turn on USB PHY 
//  1: turn on USB PHY in Device mode (turn on sequence of USB PHY with no Vbus 
//  generation).
//  Register UsbPhyControl 0x058A, Bits 1:1, typedef usb_device_mode_enable
//   
//  
#define USB_DEVICE_MODE_ENABLE_MASK 0x2
#define USB_DEVICE_MODE_ENABLE_OFFSET 1
#define USB_DEVICE_MODE_ENABLE_STOP_BIT 1
#define USB_DEVICE_MODE_ENABLE_START_BIT 1
#define USB_DEVICE_MODE_ENABLE_WIDTH 1

#define USB_PHY_CONTROL_REG 0x58A

typedef enum usb_device_mode_enable {
    USB_DEVICE_MODE_DISABLE_E,
    USB_DEVICE_MODE_ENABLE_E
} USB_DEVICE_MODE_ENABLE_T ;

#define USB_DEVICE_MODE_ENABLE_PARAM_MASK  0x2

//  
//  0: doesn�t turn on USB PHY 
//  1: turn on USB PHY in host mode.
//  Register UsbPhyControl 0x058A, Bits 0:0, typedef usb_host_mode_enable
//   
//  
#define USB_HOST_MODE_ENABLE_MASK 0x1
#define USB_HOST_MODE_ENABLE_OFFSET 0
#define USB_HOST_MODE_ENABLE_STOP_BIT 0
#define USB_HOST_MODE_ENABLE_START_BIT 0
#define USB_HOST_MODE_ENABLE_WIDTH 1


typedef enum usb_host_mode_enable {
    USB_HOST_MODE_DISABLE_E,
    USB_HOST_MODE_ENABLE_E
} USB_HOST_MODE_ENABLE_T ;

#define USB_HOST_MODE_ENABLE_PARAM_MASK  0x1
#endif
