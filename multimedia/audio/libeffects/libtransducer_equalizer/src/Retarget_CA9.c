/*****************************************************************************/
/*
 * Copyright (C) ST-Ericsson SA 2009,2010. All rights reserved.
 *
 * 
 *
 * This code is ST-Ericsson proprietary and confidential.
 * Any use of the code for whatever purpose is subject to
 * specific written permission of ST-Ericsson SA.
 *
 */

/**
 * \file   Retarget_CA9.c
 * \brief  
 * \author ST-Ericsson
 */
/*****************************************************************************/
/*
** Copyright (C) ARM Limited, 2005. All rights reserved.
*/

#include <stdio.h>
#include <rt_misc.h>
 
// Heap base from scatter file
extern int Image$$HEAP$$ZI$$Base;
//#pragma import(__use_two_region_memory)

extern void core_init(void);

/*
The functions below are patched onto main.
*/

extern void $Super$$main(void);

void $Sub$$main(void)
{
  core_init();                    // does some extra setup work
  
  $Super$$main();                 // calls the original function
}


/*
This function re-implements the C Library semihosted function. The stack pointer
has aready been set and is passed back to the function, The base of the heap is
set from the scatter file
*/
__value_in_regs struct __initial_stackheap __user_initial_stackheap(
        unsigned R0, unsigned SP, unsigned R2, unsigned SL)
{
    struct __initial_stackheap config;

    config.heap_base = (unsigned int)&Image$$HEAP$$ZI$$Base; // placed by scatterfile
    config.stack_base = SP;   // inherit SP from the execution environment

    return config;
}
