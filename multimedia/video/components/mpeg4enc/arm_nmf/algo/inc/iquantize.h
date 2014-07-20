/*
 * Copyright (C) ST-Ericsson SA 2010. All rights reserved.
 * This code is ST-Ericsson proprietary and confidential.
 * Any use of the code for whatever purpose is subject to
 * specific written permission of ST-Ericsson SA.
 */

#ifndef I_QUANTIZE_H
#define I_QUANTIZE_H

#ifndef __ARM_NEON__

void mp4e_iquantize(short *qcoeff, short *rcoeff, int QP);

#else //__ARM_NEON__

void mp4e_iquantize_NEON(short *qcoeff, short *rcoeff, int QP);

#endif //__ARM_NEON__

void mp4e_iquantize_DC(short qcoeff, short *rcoeff, int blk_num, int QP, int shortHeader);

#ifdef H263_P3
void mp4e_H263P3_InvQuantize(t_sint32 mquant, t_sint16 *block, t_sint16 *dequant_block, t_sint32 inter, mp4_parameters *mp4_par);
#endif

#endif
