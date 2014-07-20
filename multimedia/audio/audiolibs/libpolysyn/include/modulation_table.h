/*
 * Copyright (C) ST-Ericsson SA 2010. All rights reserved.
 * This code is ST-Ericsson proprietary and confidential.
 * Any use of the code for whatever purpose is subject to
 * specific written permission of ST-Ericsson SA.
 */


#ifndef _modulation_table_
#define _modulation_table_

#define POLYSYN_MODULATION_TABLE_SIZE (128+1)

extern Float const POLYSYN_MEM          polysyn_filter_even[POLYSYN_MODULATION_TABLE_SIZE];
extern Float const POLYSYN_MEM          polysyn_filter_odd[POLYSYN_MODULATION_TABLE_SIZE];

extern Float const POLYSYN_MEM * AUDIOLIBS_UPLOAD_MEM polysyn_p_filter_even;
extern Float const POLYSYN_MEM * AUDIOLIBS_UPLOAD_MEM polysyn_p_filter_odd;  

#endif /* Do not edit below this line */
