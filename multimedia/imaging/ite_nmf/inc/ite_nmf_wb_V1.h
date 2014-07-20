/*
 * Copyright (C) ST-Ericsson SA 2010. All rights reserved.
 * This code is ST-Ericsson proprietary and confidential.
 * Any use of the code for whatever purpose is subject to
 * specific written permission of ST-Ericsson SA.
 */
 
#ifndef ITE_NMF_WB_H_
#define ITE_NMF_WB_H_

#include "VhcElementDefs.h"

typedef enum
{
	WB_PRESET_OFF,
	WB_PRESET_AUTO,
	WB_PRESET_DAYLIGHT,
	WB_PRESET_CLOUDY,
	WB_PRESET_SHADE,
	WB_PRESET_TUNGSTEN,
	WB_PRESET_FLUORESCENT,
	WB_PRESET_INCANDESCENT,
	WB_PRESET_FLASH,
	WB_PRESET_HORIZON	
} e_Constrained_WBPreset;

typedef enum
{
    ///  No White balance,all gains will be unity in this mode
       WB_OFF,
    ///  Automatic mode, relative step is computed here
       WB_AUTOMATIC,
    ///  Auto instant mode
       WB_AUTO_INSTANT,
    ///  User manual mode, gains are applied manually
       WB_MANUAL_RGB,
    ///  DAYLIGHT and all the modes below, fixed value of gains are applied here.
       WB_DAYLIGHT_PRESET,
       WB_TUNGSTEN_PRESET,
       WB_FLUORESCENT_PRESET,
       WB_HORIZON_PRESET,
    ///  for flashgun
       WB_FLASHGUN_PRESET
} WhiteBalanceMode_e;

t_uint8  ITE_NMF_CheckWBStatus(float refRedGain, float refGreenGain, float refBlueGain);
void  ITE_NMF_ReadWBGainStatus(float *fpRedGain, float *fpGreenGain, float *fpBlueGain);
t_uint8  ITE_NMF_ReadConstrainedWBGain(float *fpConsRedGain, float *fpConsGreenGain, float *fpConsBlueGain);
t_uint8  ITE_NMF_ReadConstrainedWBStatus(float *fpLocusGradient, float *fpDistanceFromLocus, float *fpConstrainedRedPoint, float *fpConstrainedBluePoint);
t_uint8  ITE_NMF_TestConstrainedWB(float RedB, float BlueB, float fpMaxDistanceFromLocus);
void  ITE_NMF_SetWBMode(WhiteBalanceMode_e WBCommand);
void  ITE_NMF_SetManualWBGain(t_uint16 manualR, t_uint16 manualG, t_uint16 manualB);

#endif /* ITE_NMF_WB_H_ */
