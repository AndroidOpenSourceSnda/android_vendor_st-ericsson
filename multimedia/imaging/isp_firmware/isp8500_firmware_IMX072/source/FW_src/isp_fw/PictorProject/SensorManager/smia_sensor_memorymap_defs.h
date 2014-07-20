/* 
 * Copyright (C) ST-Ericsson SA 2010. All rights reserved. 
 * This code is ST-Ericsson proprietary and confidential. 
 * Any use of the code for whatever purpose is subject to 
 * specific written permission of ST-Ericsson SA. 
 */ 
 
/**
 \defgroup  SmiaSensor SMIA specific sensor register addresses
 \details   SMIA specific sensor register addresses
*/

/**
 \if INCLUDE_IN_HTML_ONLY
 \file    smia_sensor_memorymap_defs.h
 \brief   The file contain register accesses for SMIA compliant sensor
 \ingroup SmiaSensor
 \endif
*/
#ifndef _SMIA_SENSOR_MEMORYMAP_DEFS_H_
#   define _SMIA_SENSOR_MEMORYMAP_DEFS_H_

////////////////////////////////////////////////////////////
// Status Registers � [0x0000-0x00FF]
////////////////////////////////////////////////////////////
// General Status Registers � [0x0000-0x000F]
#   define SENSOR_STATUS__MODEL_ID_HI      0
#   define SENSOR_STATUS__MODEL_ID_LO      1
#   define SENSOR_STATUS__REVISION_NUMBER  2
#   define SENSOR_STATUS__MANUFACTURER_ID  3
#   define SENSOR_STATUS__SMIA_VERSION     4
#   define SENSOR_STATUS__FRAME_COUNT      5
#   define SENSOR_STATUS__PIXEL_ORDER      6
#   define SENSOR_STATUS__DATA_PEDESTAL_HI 8
#   define SENSOR_STATUS__DATA_PEDESTAL_LO 9
#   define SENSOR_STATUS__PIXEL_DEPTH      12

// Frame Format Description � [0x0040-0x007F]
#   define SENSOR_STATUS__FRAME_FORMAT_MODEL_TYPE      0x40
#   define SENSOR_STATUS__FRAME_FORMAT_MODEL_SUBTYPE   0x41
#   define SENSOR_STATUS__FRAME_FORMAT_DESCRIPTOR_0_HI 0x42
#   define SENSOR_STATUS__FRAME_FORMAT_DESCRIPTOR_0_LO 0x43
#   define SENSOR_STATUS__FRAME_FORMAT_DESCRIPTOR_1_HI 0x44
#   define SENSOR_STATUS__FRAME_FORMAT_DESCRIPTOR_1_LO 0x45
#   define SENSOR_STATUS__FRAME_FORMAT_DESCRIPTOR_2_HI 0x46
#   define SENSOR_STATUS__FRAME_FORMAT_DESCRIPTOR_2_LO 0x47
#   define SENSOR_STATUS__FRAME_FORMAT_DESCRIPTOR_3_HI 0x48
#   define SENSOR_STATUS__FRAME_FORMAT_DESCRIPTOR_3_LO 0x49
#   define SENSOR_STATUS__FRAME_FORMAT_DESCRIPTOR_4_HI 0x4a
#   define SENSOR_STATUS__FRAME_FORMAT_DESCRIPTOR_4_LO 0x4b

// Analogue Gain Description Registers � [0x0080-0x0097]
#   define SENSOR_STATUS__ANALOGUE_GAIN_CAPABILITY_HI  0x80
#   define SENSOR_STATUS__ANALOGUE_GAIN_CAPABILITY_LO  0x81
#   define SENSOR_STATUS__ANALOGUE_GAIN_CODE_MIN_HI    0x84
#   define SENSOR_STATUS__ANALOGUE_GAIN_CODE_MIN_LO    0x85
#   define SENSOR_STATUS__ANALOGUE_GAIN_CODE_MAX_HI    0x86
#   define SENSOR_STATUS__ANALOGUE_GAIN_CODE_MAX_LO    0x87
#   define SENSOR_STATUS__ANALOGUE_GAIN_CODE_STEP_HI   0x88
#   define SENSOR_STATUS__ANALOGUE_GAIN_CODE_STEP_LO   0x89
#   define SENSOR_STATUS__ANALOGUE_GAIN_TYPE_HI        0x8a
#   define SENSOR_STATUS__ANALOGUE_GAIN_TYPE_LO        0x8b
#   define SENSOR_STATUS__ANALOGUE_GAIN_M0_HI          0x8c
#   define SENSOR_STATUS__ANALOGUE_GAIN_M0_LO          0x8d
#   define SENSOR_STATUS__ANALOGUE_GAIN_C0_HI          0x8e
#   define SENSOR_STATUS__ANALOGUE_GAIN_C0_LO          0x8f
#   define SENSOR_STATUS__ANALOGUE_GAIN_M1_HI          0x90
#   define SENSOR_STATUS__ANALOGUE_GAIN_M1_LO          0x91
#   define SENSOR_STATUS__ANALOGUE_GAIN_C1_HI          0x92
#   define SENSOR_STATUS__ANALOGUE_GAIN_C1_LO          0x93

// Data Format Description � [0x00C0-0x00FF]
#   define SENSOR_STATUS__DATA_FORMAT_MODEL_TYPE       0xc0
#   define SENSOR_STATUS__DATA_FORMAT_MODEL_SUBTYPE    0xc1
#   define SENSOR_STATUS__DATA_FORMAT_DESCRIPTOR_0_HI  0xc2
#   define SENSOR_STATUS__DATA_FORMAT_DESCRIPTOR_0_LO  0xc3
#   define SENSOR_STATUS__DATA_FORMAT_DESCRIPTOR_1_HI  0xc4
#   define SENSOR_STATUS__DATA_FORMAT_DESCRIPTOR_1_LO  0xc5
#   define SENSOR_STATUS__DATA_FORMAT_DESCRIPTOR_2_HI  0xc6
#   define SENSOR_STATUS__DATA_FORMAT_DESCRIPTOR_2_LO  0xc7

////////////////////////////////////////////////////////////
// Set-up Registers � [0x0100-0x01FF]
////////////////////////////////////////////////////////////
// General Set-up Registers � [0x0100-0x010F]
#   define SENSOR_SETUP__MODE_SELECT               0x100
#   define SENSOR_SETUP__IMAGE_ORIENTATION         0x101
#   define SENSOR_SETUP__SOFTWARE_RESET            0x103
#   define SENSOR_SETUP__GROUPED_PARAMETER_HOLD    0x104
#   define SENSOR_SETUP__MASK_CORRUPTED_FRAMES     0x105

// Output Set-up Registers � [0x0110-0x011F]
#   define SENSOR_SETUP__CSI_CHANNEL_IDENTIFIER    0x110
#   define SENSOR_SETUP__CSI_SIGNALLING_MODE       0x111
#   define SENSOR_SETUP__CSI_DATA_FORMAT_HI        0x112
#   define SENSOR_SETUP__CSI_DATA_FORMAT_LO        0x113

// Integration Time and Gain Set-up Registers � [0x0120-0x012F]
#   define SENSOR_SETUP__GAIN_MODE 0x120

////////////////////////////////////////////////////////////
// Integration Time and Gain Registers � [0x0200-0x02FF]
////////////////////////////////////////////////////////////
// Integration Time Registers � [0x2000-0x2003]
#   define SENSOR_INTEGRATION__FINE_INTEGRATION_TIME_HI    0x200
#   define SENSOR_INTEGRATION__FINE_INTEGRATION_TIME_LO    0x201
#   define SENSOR_INTEGRATION__COARSE_INTEGRATION_TIME_HI  0x202
#   define SENSOR_INTEGRATION__COARSE_INTEGRATION_TIME_LO  0x203

// Analogue Gain Registers � [0x0204-0x020D]
#   define SENSOR_INTEGRATION__ANALOGUE_GAIN_CODE_GLOBAL_HI    0x204
#   define SENSOR_INTEGRATION__ANALOGUE_GAIN_CODE_GLOBAL_LO    0x205

// Digital Gain Registers � [0x020E-0x0215]
#   define SENSOR_INTEGRATION__DIGITAL_GAIN_GREENR_HI  0x20E
#   define SENSOR_INTEGRATION__DIGITAL_GAIN_GREENR_LO  0x20F
#   define SENSOR_INTEGRATION__DIGITAL_GAIN_RED_HI     0x210
#   define SENSOR_INTEGRATION__DIGITAL_GAIN_RED_LO     0x211
#   define SENSOR_INTEGRATION__DIGITAL_GAIN_BLUE_HI    0x212
#   define SENSOR_INTEGRATION__DIGITAL_GAIN_BLUE_LO    0x213
#   define SENSOR_INTEGRATION__DIGITAL_GAIN_GREENB_HI  0x214
#   define SENSOR_INTEGRATION__DIGITAL_GAIN_GREENB_LO  0x215

////////////////////////////////////////////////////////////
// Video Timing Registers � [0x0300-0x03FF]
////////////////////////////////////////////////////////////
// Clock Set-up Registers � [0x0300-0x0307]
#   define SENSOR_VIDEO_TIMING__VT_PIX_CLK_DIV_HI  0x300
#   define SENSOR_VIDEO_TIMING__VT_PIX_CLK_DIV_LO  0x301
#   define SENSOR_VIDEO_TIMING__VT_SYS_CLK_DIV_HI  0x302
#   define SENSOR_VIDEO_TIMING__VT_SYS_CLK_DIV_LO  0x303
#   define SENSOR_VIDEO_TIMING__PRE_PLL_CLK_DIV_HI 0x304
#   define SENSOR_VIDEO_TIMING__PRE_PLL_CLK_DIV_LO 0x305
#   define SENSOR_VIDEO_TIMING__PLL_MULTIPLIER_HI  0x306
#   define SENSOR_VIDEO_TIMING__PLL_MULTIPLIER_LO  0x307
#   define SENSOR_VIDEO_TIMING__OP_PIX_CLK_DIV_HI  0x308
#   define SENSOR_VIDEO_TIMING__OP_PIX_CLK_DIV_LO  0x309
#   define SENSOR_VIDEO_TIMING__OP_SYS_CLK_DIV_HI  0x30a
#   define SENSOR_VIDEO_TIMING__OP_SYS_CLK_DIV_LO  0x30b

// Frame Timing Registers � [0x0340-0x0343]
#   define SENSOR_VIDEO_TIMING__FRAME_LENGTH_LINES_HI  0x340
#   define SENSOR_VIDEO_TIMING__FRAME_LENGTH_LINES_LO  0x341
#   define SENSOR_VIDEO_TIMING__LINE_LENGTH_PCK_HI     0x342
#   define SENSOR_VIDEO_TIMING__LINE_LENGTH_PCK_LO     0x343

// Image Size Registers � [0x0344-0x034F]
#   define SENSOR_VIDEO_TIMING__X_ADDR_START_HI    0x344
#   define SENSOR_VIDEO_TIMING__X_ADDR_START_LO    0x345
#   define SENSOR_VIDEO_TIMING__Y_ADDR_START_HI    0x346
#   define SENSOR_VIDEO_TIMING__Y_ADDR_START_LO    0x347
#   define SENSOR_VIDEO_TIMING__X_ADDR_END_HI      0x348
#   define SENSOR_VIDEO_TIMING__X_ADDR_END_LO      0x349
#   define SENSOR_VIDEO_TIMING__Y_ADDR_END_HI      0x34a
#   define SENSOR_VIDEO_TIMING__Y_ADDR_END_LO      0x34b
#   define SENSOR_VIDEO_TIMING__X_OUTPUT_SIZE_HI   0x34c
#   define SENSOR_VIDEO_TIMING__X_OUTPUT_SIZE_LO   0x34d
#   define SENSOR_VIDEO_TIMING__Y_OUTPUT_SIZE_HI   0x34e
#   define SENSOR_VIDEO_TIMING__Y_OUTPUT_SIZE_LO   0x34f

// Sub-Sampling Registers � [0x0380-0x0387]
#   define SENSOR_VIDEO_TIMING__X_EVEN_INC_HI  0x380
#   define SENSOR_VIDEO_TIMING__X_EVEN_INC_LO  0x381
#   define SENSOR_VIDEO_TIMING__X_ODD_INC_HI   0x382
#   define SENSOR_VIDEO_TIMING__X_ODD_INC_LO   0x383
#   define SENSOR_VIDEO_TIMING__Y_EVEN_INC_HI  0x384
#   define SENSOR_VIDEO_TIMING__Y_EVEN_INC_LO  0x385
#   define SENSOR_VIDEO_TIMING__Y_ODD_INC_HI   0x386
#   define SENSOR_VIDEO_TIMING__Y_ODD_INC_LO   0x387

////////////////////////////////////////////////////////////
// Image Scaling Registers � [0x0400-0x04FF]
////////////////////////////////////////////////////////////
#   define SENSOR_SCALING__SCALING_MODE_HI     0x400
#   define SENSOR_SCALING__SCALING_MODE_LO     0x401
#   define SENSOR_SCALING__SPATIAL_SAMPLING_HI 0x402
#   define SENSOR_SCALING__SPATIAL_SAMPLING_LO 0x403
#   define SENSOR_SCALING__SCALE_M_HI          0x404
#   define SENSOR_SCALING__SCALE_M_LO          0x405
#   define SENSOR_SCALING__SCALE_N_HI          0x406
#   define SENSOR_SCALING__SCALE_N_LO          0x407

////////////////////////////////////////////////////////////
// Image Compression Registers � [0x0500-0x05FF]
////////////////////////////////////////////////////////////
#   define SENSOR_COMPRESSION__COMPRESSION_ALGORITHIM_HI   0x500
#   define SENSOR_COMPRESSION__COMPRESSION_ALGORITHIM_LO   0x501

////////////////////////////////////////////////////////////
// Test Pattern Registers � [0x0600-0x06FF]
////////////////////////////////////////////////////////////
#   define SENSOR_TEST_PATTERN__TEST_PATTERN_MODE_HI           0x600
#   define SENSOR_TEST_PATTERN__TEST_PATTERN_MODE_LO           0x601
#   define SENSOR_TEST_PATTERN__TEST_DATA_RED_HI               0x602
#   define SENSOR_TEST_PATTERN__TEST_DATA_RED_LO               0x603
#   define SENSOR_TEST_PATTERN__TEST_DATA_GREENR_HI            0x604
#   define SENSOR_TEST_PATTERN__TEST_DATA_GREENR_LO            0x605
#   define SENSOR_TEST_PATTERN__TEST_DATA_BLUE_HI              0x606
#   define SENSOR_TEST_PATTERN__TEST_DATA_BLUE_LO              0x607
#   define SENSOR_TEST_PATTERN__TEST_DATA_GREENB_HI            0x608
#   define SENSOR_TEST_PATTERN__TEST_DATA_GREENB_LO            0x609
#   define SENSOR_TEST_PATTERN__HORIZONTAL_CURSOR_WIDTH_HI     0x60a
#   define SENSOR_TEST_PATTERN__HORIZONTAL_CURSOR_WIDTH_LO     0x60b
#   define SENSOR_TEST_PATTERN__HORIZONTAL_CURSOR_POSITION_HI  0x60c
#   define SENSOR_TEST_PATTERN__HORIZONTAL_CURSOR_POSITION_LO  0x60d
#   define SENSOR_TEST_PATTERN__VERTICAL_CURSOR_WIDTH_HI       0x60e
#   define SENSOR_TEST_PATTERN__VERTICAL_CURSOR_WIDTH_LO       0x60f
#   define SENSOR_TEST_PATTERN__VERTICAL_CURSOR_POSITION_HI    0x610
#   define SENSOR_TEST_PATTERN__VERTICAL_CURSOR_POSITION_LO    0x611

////////////////////////////////////////////////////////////
// FIFO Registers- [0x0700 - 0x07FF]
////////////////////////////////////////////////////////////
#   define SENSOR_FIFO__FIFO_WATER_MARK_PIXELS_HI  0x700
#   define SENSOR_FIFO__FIFO_WATER_MARK_PIXELS_LO  0x701

////////////////////////////////////////////////////////////
// Integration Time and Gain Parameter Limit Registers � [0x1000-0x10FF]
////////////////////////////////////////////////////////////
// Integration Time Parameter Limit Registers � [0x1000-0x100B]
#   define SENSOR_INTEGAIN_LIMIT__INTEGRATION_TIME_CAPABILITY_HI           0x1000
#   define SENSOR_INTEGAIN_LIMIT__INTEGRATION_TIME_CAPABILITY_LO           0x1001
#   define SENSOR_INTEGAIN_LIMIT__COARSE_INTEGRATION_TIME_MIN_HI           0x1004
#   define SENSOR_INTEGAIN_LIMIT__COARSE_INTEGRATION_TIME_MIN_LO           0x1005
#   define SENSOR_INTEGAIN_LIMIT__COARSE_INTEGRATION_TIME_MAX_MARGIN_HI    0x1006
#   define SENSOR_INTEGAIN_LIMIT__COARSE_INTEGRATION_TIME_MAX_MARGIN_LO    0x1007
#   define SENSOR_INTEGAIN_LIMIT__FINE_INTEGRATION_TIME_MIN_HI             0x1008
#   define SENSOR_INTEGAIN_LIMIT__FINE_INTEGRATION_TIME_MIN_LO             0x1009
#   define SENSOR_INTEGAIN_LIMIT__FINE_INTEGRATION_TIME_MAX_MARGIN_HI      0x100a
#   define SENSOR_INTEGAIN_LIMIT__FINE_INTEGRATION_TIME_MAX_MARGIN_LO      0x100b

// Digital Gain Parameter Limit Registers � [0x1080-0x1089]
#   define SENSOR_STATUS__DIGITAL_GAIN_CAPABILITY_HI   SENSOR_INTEGAIN_LIMIT__DIGITAL_GAIN_CAPABILITY_HI
#   define SENSOR_STATUS__DIGITAL_GAIN_MIN_HI          SENSOR_INTEGAIN_LIMIT__DIGITAL_GAIN_MIN_HI
#   define SENSOR_INTEGAIN_LIMIT__DIGITAL_GAIN_CAPABILITY_HI   0x1080
#   define SENSOR_INTEGAIN_LIMIT__DIGITAL_GAIN_CAPABILITY_LO   0x1081
#   define SENSOR_INTEGAIN_LIMIT__DIGITAL_GAIN_MIN_HI          0x1084
#   define SENSOR_INTEGAIN_LIMIT__DIGITAL_GAIN_MIN_LO          0x1085
#   define SENSOR_INTEGAIN_LIMIT__DIGITAL_GAIN_MAX_HI          0x1086
#   define SENSOR_INTEGAIN_LIMIT__DIGITAL_GAIN_MAX_LO          0x1087
#   define SENSOR_INTEGAIN_LIMIT__DIGITAL_GAIN_STEP_SIZE_HI    0x1088
#   define SENSOR_INTEGAIN_LIMIT__DIGITAL_GAIN_STEP_SIZE_LO    0x1089

////////////////////////////////////////////////////////////
// Video Timing Parameter Limit Registers � [0x1100-0x11FF]
////////////////////////////////////////////////////////////
// Pre-PLL and PLL Clock Set-up Capability Registers - [0x1100-0x111F]
#   define SENSOR_VTIMING_LIMIT__MIN_EXT_CLK_FREQ_MHZ_3    0x1100
#   define SENSOR_VTIMING_LIMIT__MIN_EXT_CLK_FREQ_MHZ_2    0x1101
#   define SENSOR_VTIMING_LIMIT__MIN_EXT_CLK_FREQ_MHZ_1    0x1102
#   define SENSOR_VTIMING_LIMIT__MIN_EXT_CLK_FREQ_MHZ_0    0x1103
#   define SENSOR_VTIMING_LIMIT__MAX_EXT_CLK_FREQ_MHZ_3    0x1104
#   define SENSOR_VTIMING_LIMIT__MAX_EXT_CLK_FREQ_MHZ_2    0x1105
#   define SENSOR_VTIMING_LIMIT__MAX_EXT_CLK_FREQ_MHZ_1    0x1106
#   define SENSOR_VTIMING_LIMIT__MAX_EXT_CLK_FREQ_MHZ_0    0x1107
#   define SENSOR_VTIMING_LIMIT__MIN_PRE_PLL_CLK_DIV_HI    0x1108
#   define SENSOR_VTIMING_LIMIT__MIN_PRE_PLL_CLK_DIV_LO    0x1109
#   define SENSOR_VTIMING_LIMIT__MAX_PRE_PLL_CLK_DIV_HI    0x110a
#   define SENSOR_VTIMING_LIMIT__MAX_PRE_PLL_CLK_DIV_LO    0x110b
#   define SENSOR_VTIMING_LIMIT__MIN_PLL_IP_FREQ_MHZ_3     0x110c
#   define SENSOR_VTIMING_LIMIT__MIN_PLL_IP_FREQ_MHZ_2     0x110d
#   define SENSOR_VTIMING_LIMIT__MIN_PLL_IP_FREQ_MHZ_1     0x110e
#   define SENSOR_VTIMING_LIMIT__MIN_PLL_IP_FREQ_MHZ_0     0x110f
#   define SENSOR_VTIMING_LIMIT__MAX_PLL_IP_FREQ_MHZ_3     0x1110
#   define SENSOR_VTIMING_LIMIT__MAX_PLL_IP_FREQ_MHZ_2     0x1111
#   define SENSOR_VTIMING_LIMIT__MAX_PLL_IP_FREQ_MHZ_1     0x1112
#   define SENSOR_VTIMING_LIMIT__MAX_PLL_IP_FREQ_MHZ_0     0x1113
#   define SENSOR_VTIMING_LIMIT__MIN_PLL_MULTIPLIER_HI     0x1114
#   define SENSOR_VTIMING_LIMIT__MIN_PLL_MULTIPLIER_LO     0x1115
#   define SENSOR_VTIMING_LIMIT__MAX_PLL_MULTIPLIER_HI     0x1116
#   define SENSOR_VTIMING_LIMIT__MAX_PLL_MULTIPLIER_LO     0x1117
#   define SENSOR_VTIMING_LIMIT__MIN_PLL_OP_FREQ_MHZ_3     0x1118
#   define SENSOR_VTIMING_LIMIT__MIN_PLL_OP_FREQ_MHZ_2     0x1119
#   define SENSOR_VTIMING_LIMIT__MIN_PLL_OP_FREQ_MHZ_1     0x111a
#   define SENSOR_VTIMING_LIMIT__MIN_PLL_OP_FREQ_MHZ_0     0x111b
#   define SENSOR_VTIMING_LIMIT__MAX_PLL_OP_FREQ_MHZ_3     0x111c
#   define SENSOR_VTIMING_LIMIT__MAX_PLL_OP_FREQ_MHZ_2     0x111d
#   define SENSOR_VTIMING_LIMIT__MAX_PLL_OP_FREQ_MHZ_1     0x111e
#   define SENSOR_VTIMING_LIMIT__MAX_PLL_OP_FREQ_MHZ_0     0x111f

// Video Timing Clock Set-up Capability Registers - [0x1120-0x1137]
#   define SENSOR_VTIMING_LIMIT__MIN_VT_SYS_CLK_DIV_HI     0x1120
#   define SENSOR_VTIMING_LIMIT__MIN_VT_SYS_CLK_DIV_LO     0x1121
#   define SENSOR_VTIMING_LIMIT__MAX_VT_SYS_CLK_DIV_HI     0x1122
#   define SENSOR_VTIMING_LIMIT__MAX_VT_SYS_CLK_DIV_LO     0x1123
#   define SENSOR_VTIMING_LIMIT__MIN_VT_SYS_CLK_FREQ_MHZ_3 0x1124
#   define SENSOR_VTIMING_LIMIT__MIN_VT_SYS_CLK_FREQ_MHZ_2 0x1125
#   define SENSOR_VTIMING_LIMIT__MIN_VT_SYS_CLK_FREQ_MHZ_1 0x1126
#   define SENSOR_VTIMING_LIMIT__MIN_VT_SYS_CLK_FREQ_MHZ_0 0x1127
#   define SENSOR_VTIMING_LIMIT__MAX_VT_SYS_CLK_FREQ_MHZ_3 0x1128
#   define SENSOR_VTIMING_LIMIT__MAX_VT_SYS_CLK_FREQ_MHZ_2 0x1129
#   define SENSOR_VTIMING_LIMIT__MAX_VT_SYS_CLK_FREQ_MHZ_1 0x112a
#   define SENSOR_VTIMING_LIMIT__MAX_VT_SYS_CLK_FREQ_MHZ_0 0x112b
#   define SENSOR_VTIMING_LIMIT__MIN_VT_PIX_CLK_FREQ_MHZ_3 0x112c
#   define SENSOR_VTIMING_LIMIT__MIN_VT_PIX_CLK_FREQ_MHZ_2 0x112d
#   define SENSOR_VTIMING_LIMIT__MIN_VT_PIX_CLK_FREQ_MHZ_1 0x112e
#   define SENSOR_VTIMING_LIMIT__MIN_VT_PIX_CLK_FREQ_MHZ_0 0x112f
#   define SENSOR_VTIMING_LIMIT__MAX_VT_PIX_CLK_FREQ_MHZ_3 0x1130
#   define SENSOR_VTIMING_LIMIT__MAX_VT_PIX_CLK_FREQ_MHZ_2 0x1131
#   define SENSOR_VTIMING_LIMIT__MAX_VT_PIX_CLK_FREQ_MHZ_1 0x1132
#   define SENSOR_VTIMING_LIMIT__MAX_VT_PIX_CLK_FREQ_MHZ_0 0x1133
#   define SENSOR_VTIMING_LIMIT__MIN_VT_PIX_CLK_DIV_HI     0x1134
#   define SENSOR_VTIMING_LIMIT__MIN_VT_PIX_CLK_DIV_LO     0x1135
#   define SENSOR_VTIMING_LIMIT__MAX_VT_PIX_CLK_DIV_HI     0x1136
#   define SENSOR_VTIMING_LIMIT__MAX_VT_PIX_CLK_DIV_LO     0x1137

// Frame Timing Parameter Limit Registers � [0x1140-0x1149]
#   define SENSOR_VTIMING_LIMIT__MIN_FRAME_LENGTH_LINES_HI 0x1140
#   define SENSOR_VTIMING_LIMIT__MIN_FRAME_LENGTH_LINES_LO 0x1141
#   define SENSOR_VTIMING_LIMIT__MAX_FRAME_LENGTH_LINES_HI 0x1142
#   define SENSOR_VTIMING_LIMIT__MAX_FRAME_LENGTH_LINES_LO 0x1143
#   define SENSOR_VTIMING_LIMIT__MIN_LINE_LENGTH_PCK_HI    0x1144
#   define SENSOR_VTIMING_LIMIT__MIN_LINE_LENGTH_PCK_LO    0x1145
#   define SENSOR_VTIMING_LIMIT__MAX_LINE_LENGTH_PCK_HI    0x1146
#   define SENSOR_VTIMING_LIMIT__MAX_LINE_LENGTH_PCK_LO    0x1147
#   define SENSOR_VTIMING_LIMIT__MIN_LINE_BLANKING_PCK_HI  0x1148
#   define SENSOR_VTIMING_LIMIT__MIN_LINE_BLANKING_PCK_LO  0x1149

// Output Clock Set-up Capability Registers - [0x1160-0x1177]
#   define SENSOR_VTIMING_LIMIT__MIN_OP_SYS_CLK_DIV_HI     0x1160
#   define SENSOR_VTIMING_LIMIT__MIN_OP_SYS_CLK_DIV_LO     0x1161
#   define SENSOR_VTIMING_LIMIT__MAX_OP_SYS_CLK_DIV_HI     0x1162
#   define SENSOR_VTIMING_LIMIT__MAX_OP_SYS_CLK_DIV_LO     0x1163
#   define SENSOR_VTIMING_LIMIT__MIN_OP_SYS_CLK_FREQ_MHZ_3 0x1164
#   define SENSOR_VTIMING_LIMIT__MIN_OP_SYS_CLK_FREQ_MHZ_2 0x1165
#   define SENSOR_VTIMING_LIMIT__MIN_OP_SYS_CLK_FREQ_MHZ_1 0x1166
#   define SENSOR_VTIMING_LIMIT__MIN_OP_SYS_CLK_FREQ_MHZ_0 0x1167
#   define SENSOR_VTIMING_LIMIT__MAX_OP_SYS_CLK_FREQ_MHZ_3 0x1168
#   define SENSOR_VTIMING_LIMIT__MAX_OP_SYS_CLK_FREQ_MHZ_2 0x1169
#   define SENSOR_VTIMING_LIMIT__MAX_OP_SYS_CLK_FREQ_MHZ_1 0x116a
#   define SENSOR_VTIMING_LIMIT__MAX_OP_SYS_CLK_FREQ_MHZ_0 0x116b
#   define SENSOR_VTIMING_LIMIT__MIN_OP_PIX_CLK_DIV_HI     0x116c
#   define SENSOR_VTIMING_LIMIT__MIN_OP_PIX_CLK_DIV_LO     0x116d
#   define SENSOR_VTIMING_LIMIT__MAX_OP_PIX_CLK_DIV_HI     0x116e
#   define SENSOR_VTIMING_LIMIT__MAX_OP_PIX_CLK_DIV_LO     0x116f
#   define SENSOR_VTIMING_LIMIT__MIN_OP_PIX_CLK_FREQ_MHZ_3 0x1170
#   define SENSOR_VTIMING_LIMIT__MIN_OP_PIX_CLK_FREQ_MHZ_2 0x1171
#   define SENSOR_VTIMING_LIMIT__MIN_OP_PIX_CLK_FREQ_MHZ_1 0x1172
#   define SENSOR_VTIMING_LIMIT__MIN_OP_PIX_CLK_FREQ_MHZ_0 0x1173
#   define SENSOR_VTIMING_LIMIT__MAX_OP_PIX_CLK_FREQ_MHZ_3 0x1174
#   define SENSOR_VTIMING_LIMIT__MAX_OP_PIX_CLK_FREQ_MHZ_2 0x1175
#   define SENSOR_VTIMING_LIMIT__MAX_OP_PIX_CLK_FREQ_MHZ_1 0x1176
#   define SENSOR_VTIMING_LIMIT__MAX_OP_PIX_CLK_FREQ_MHZ_0 0x1177

// Image Size Parameter Limit Registers � [0x1180-0x1187]
#   define SENSOR_VTIMING_LIMIT__X_ADDR_MIN_HI 0x1180
#   define SENSOR_VTIMING_LIMIT__X_ADDR_MIN_LO 0x1181
#   define SENSOR_VTIMING_LIMIT__Y_ADDR_MIN_HI 0x1182
#   define SENSOR_VTIMING_LIMIT__Y_ADDR_MIN_LO 0x1183
#   define SENSOR_VTIMING_LIMIT__X_ADDR_MAX_HI 0x1184
#   define SENSOR_VTIMING_LIMIT__X_ADDR_MAX_LO 0x1185
#   define SENSOR_VTIMING_LIMIT__Y_ADDR_MAX_HI 0x1186
#   define SENSOR_VTIMING_LIMIT__Y_ADDR_MAX_LO 0x1187

// Sub-Sampling Parameter Limit Registers � [0x11C0-0x011C7]
#   define SENSOR_VTIMING_LIMIT__MIN_EVEN_INC_HI   0x11c0
#   define SENSOR_VTIMING_LIMIT__MIN_EVEN_INC_LO   0x11c1
#   define SENSOR_VTIMING_LIMIT__MAX_EVEN_INC_HI   0x11c2
#   define SENSOR_VTIMING_LIMIT__MAX_EVEN_INC_LO   0x11c3
#   define SENSOR_VTIMING_LIMIT__MIN_ODD_INC_HI    0x11c4
#   define SENSOR_VTIMING_LIMIT__MIN_ODD_INC_LO    0x11c5
#   define SENSOR_VTIMING_LIMIT__MAX_ODD_INC_HI    0x11c6
#   define SENSOR_VTIMING_LIMIT__MAX_ODD_INC_LO    0x11c7

////////////////////////////////////////////////////////////
// Image Scaling Parameter Limit Registers � [0x1200-0x12FF]
////////////////////////////////////////////////////////////
#   define SENSOR_SCALING_LIMIT__SCALING_CAPABILITY_HI 0x1200
#   define SENSOR_SCALING_LIMIT__SCALING_CAPABILITY_LO 0x1201
#   define SENSOR_SCALING_LIMIT__SCALE_M_MIN_HI        0x1204
#   define SENSOR_SCALING_LIMIT__SCALE_M_MIN_LO        0x1205
#   define SENSOR_SCALING_LIMIT__SCALE_M_MAX_HI        0x1206
#   define SENSOR_SCALING_LIMIT__SCALE_M_MAX_LO        0x1207
#   define SENSOR_SCALING_LIMIT__SCALE_N_MIN_HI        0x1208
#   define SENSOR_SCALING_LIMIT__SCALE_N_MIN_LO        0x1209
#   define SENSOR_SCALING_LIMIT__SCALE_N_MAX_HI        0x120a
#   define SENSOR_SCALING_LIMIT__SCALE_N_MAX_LO        0x120b

////////////////////////////////////////////////////////////
// Image Compression Capability Registers � [0x1300-0x13FF]
////////////////////////////////////////////////////////////
#   define SENSOR_COMPRESSION__COMPRESSION_CAPABILITY_HI   0x1300
#   define SENSOR_COMPRESSION__COMPRESSION_CAPABILITY_LO   0x1301

////////////////////////////////////////////////////////////
// Colour Matrix Registers � [0x1400-0x14FF]
////////////////////////////////////////////////////////////
#   define SENSOR_COLOUR_MATRIX__MATRIX_ELEMENT_REDINRED_HI        0x1400
#   define SENSOR_COLOUR_MATRIX__MATRIX_ELEMENT_REDINRED_LO        0x1401
#   define SENSOR_COLOUR_MATRIX__MATRIX_ELEMENT_GREENINRED_HI      0x1402
#   define SENSOR_COLOUR_MATRIX__MATRIX_ELEMENT_GREENINRED_LO      0x1403
#   define SENSOR_COLOUR_MATRIX__MATRIX_ELEMENT_BLUEINRED_HI       0x1404
#   define SENSOR_COLOUR_MATRIX__MATRIX_ELEMENT_BLUEINRED_LO       0x1405
#   define SENSOR_COLOUR_MATRIX__MATRIX_ELEMENT_REDINGREEN_HI      0x1406
#   define SENSOR_COLOUR_MATRIX__MATRIX_ELEMENT_REDINGREEN_LO      0x1407
#   define SENSOR_COLOUR_MATRIX__MATRIX_ELEMENT_GREENINGREEN_HI    0x1408
#   define SENSOR_COLOUR_MATRIX__MATRIX_ELEMENT_GREENINGREEN_LO    0x1409
#   define SENSOR_COLOUR_MATRIX__MATRIX_ELEMENT_BLUEINGREEN_HI     0x140a
#   define SENSOR_COLOUR_MATRIX__MATRIX_ELEMENT_BLUEINGREEN_LO     0x140b
#   define SENSOR_COLOUR_MATRIX__MATRIX_ELEMENT_REDINBLUE_HI       0x140c
#   define SENSOR_COLOUR_MATRIX__MATRIX_ELEMENT_REDINBLUE_LO       0x140d
#   define SENSOR_COLOUR_MATRIX__MATRIX_ELEMENT_GREENINBLUE_HI     0x140e
#   define SENSOR_COLOUR_MATRIX__MATRIX_ELEMENT_GREENINBLUE_LO     0x140f
#   define SENSOR_COLOUR_MATRIX__MATRIX_ELEMENT_BLUEINBLUE_HI      0x1410
#   define SENSOR_COLOUR_MATRIX__MATRIX_ELEMENT_BLUEINBLUE_LO      0x1411

////////////////////////////////////////////////////////////
// FIFO Capability Registers [0x1500 - 0x15FF]
////////////////////////////////////////////////////////////
#   define SENSOR_FIFO_CAPABILITY__FIFO_SIZE_PIXELS_HI 0x1500
#   define SENSOR_FIFO_CAPABILITY__FIFO_SIZE_PIXELS_LO 0x1501

////////////////////////////////////////////////////////////
// Image Statistics Registers - [0x2000-0x2FFF]
////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////
// Manufacturer Specific Registers � [0x3000-0x3FFF]
////////////////////////////////////////////////////////////
#   define MAN_SPEC_DARK_CAL__DARK_AVG_HI          0x3000
#   define MAN_SPEC_DARK_CAL__DARK_AVG_LO          0x3001
#   define MAN_SPEC_DARK_CAL__DARK_CAL_FLAGS       0x3002
#   define MAN_SPEC_DARK_CAL__DARK_OFFSET_SETUP    0x3003
#   define MAN_SPEC_DARK_CAL__DARK_OFFSET_HI       0x3004
#   define MAN_SPEC_DARK_CAL__DARK_OFFSET_LO       0x3005

#   define MAN_SPEC_MEDIAN__CTRL                   0x3010

#   define MAN_SPEC_VTIMING__CTRL                  0x3020
#   define MAN_SPEC_VTIMING__FRAMES_TO_SEND        0x3021
#   define MAN_SPEC_VTIMING__GCC_INC               0x3022

#   define MAN_SPEC_ANALOG__GAIN_BLK               0x3101
#   define MAN_SPEC_ANALOG__BLACK_LINES_OFFSET     0x3102
#   define MAN_SPEC_ANALOG__ADC_OFFSET_GLOBAL      0x3103
#   define MAN_SPEC_ANALOG__BIST_CONTROL           0x3109
#   define MAN_SPEC_ANALOG__BIST_RESULTS           0x310a
#   define MAN_SPEC_ANALOG__AMUX_SEL               0x3110
#   define MAN_SPEC_ANALOG__TIMING_1               0x3112
#   define MAN_SPEC_ANALOG__TIMING_2               0x3113
#   define MAN_SPEC_ANALOG__TIMING_3               0x3114
#   define MAN_SPEC_ANALOG__TIMING_4               0x3115
#   define MAN_SPEC_ANALOG__RAMP_SCALE             0x3116
#   define MAN_SPEC_ANALOG__COLUMN_SETUP           0x3117
#   define MAN_SPEC_ANALOG__TG_LEVELS_SETUP        0x3118
#   define MAN_SPEC_ANALOG__LEVEL_SLOPES_SETUP     0x3119
#   define MAN_SPEC_ANALOG__VOLT_LEVEL_SETUP       0x311a

#   define MAN_SPEC_ANALOG__BTL_LEVEL_SETUP        0x311b
#   define MAN_SPEC_ANALOG__VRT_SETUP              0x311c
#   define MAN_SPEC_ANALOG__MISC_SETUP             0x311d
#   define MAN_SPEC_ANALOG__GCC_TRIGGER_HI         0x311e
#   define MAN_SPEC_ANALOG__GCC_TRIGGER_LO         0x311f
#   define MAN_SPEC_ANALOG__POWER_MAN_ENABLE_1     0x3140
#   define MAN_SPEC_ANALOG__POWER_MAN_ENABLE_2     0x3141

#   define MAN_SPEC_AF__CONTROL                    0x3180
#   define MAN_SPEC_AF__IBIAS_CTRL                 0x3181
#   define MAN_SPEC_AF__OFFSET                     0x3182
#   define MAN_SPEC_AF__GAIN                       0x3183
#   define MAN_SPEC_AF__REFSEL                     0x3184
#   define MAN_SPEC_AF__DATA1_HI                   0x3186
#   define MAN_SPEC_AF__DATA1_LO                   0x3187
#   define MAN_SPEC_AF__DATA2_HI                   0x3188
#   define MAN_SPEC_AF__DATA2_LO                   0x3189

#   define MAN_SPEC_AF__DUMMY_REGISTER             0x318a

#   define PRIVATE_PLL__PRE_DIV                    0x3800
#   define PRIVATE_PLL__CTRL                       0x3801
#   define PRIVATE_PLL__COEFF_M                    0x3802
#   define PRIVATE_PLL__COEFF_N                    0x3803
#   define PRIVATE_PLL__STATUS                     0x3804

#   define PRIVATE_PLL__INC_STEP_HI                0x3805
#   define PRIVATE_PLL__INC_STEP_LO                0x3806
#   define PRIVATE_PLL__MOD_PERIOD_HI              0x3807
#   define PRIVATE_PLL__MOD_PERIOD_LO              0x3808
#   define PRIVATE_PLL__MISC_PM_CONTROL            0x3809

#   define PRIVATE_UIA__CTRL                       0x3810
#   define PRIVATE_IDP__CLK_CTRL                   0x3811
#   define PRIVATE_IDP__CLK_SYS_DIV                0x3812
#   define PRIVATE_IDP__CLK_PIX_DIV                0x3813
#   define PRIVATE_TX__CLK_SYS_DIV                 0x3814
#   define PRIVATE_TX__CLK_PIX_DIV                 0x3815
#   define PRIVATE_TX__CTRL                        0x3816
#   define PRIVATE_PWR_MAN_INT__FL                 0x3817
#   define PRIVATE_PWR_MAN_INT__EN                 0x3818

#   define PRIVATE_CODER__CTRL                     0x3819

#   define PRIVATE_VT__START                       0x381a
#   define PRIVATE_VT__PARRST                      0x381b
#   define PRIVATE_VT__PARINT                      0x381c

#   define PRIVATE_TEST__PLL_CTRL                  0x3820
#   define PRIVATE_TEST__TMS                       0x3821
#   define PRIVATE_TEST__STARTUP                   0x3822
#   define PRIVATE_TEST__LVDS_DATA_HI              0x3824
#   define PRIVATE_TEST__LVDS_DATA_LO              0x3825

#   define PRIVATE_LVDS__DAC                       0x3830

#   define PRIVATE_SYNC__THRESHOLD_HI              0x3840
#   define PRIVATE_SYNC__THRESHOLD_LO              0x3841
#   define PRIVATE_ASYNC__THRESHOLD                0x3842
#endif // _SMIA_SENSOR_MEMORYMAP_DEFS_H_

