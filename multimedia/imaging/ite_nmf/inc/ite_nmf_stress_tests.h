/*
 * Copyright (C) ST-Ericsson SA 2010. All rights reserved.
 * This code is ST-Ericsson proprietary and confidential.
 * Any use of the code for whatever purpose is subject to
 * specific written permission of ST-Ericsson SA.
 */
 
#ifndef ITE_NMF_STRESS_TESTS_H_
#define ITE_NMF_STRESS_TESTS_H_


CMD_COMPLETION C_ite_StressTests_cmd(int a_nb_args, char ** ap_args);

void ITE_StressTests(char * ap_test_id, char * ap_grabvpip_options);

#endif /*ITE_NMF_STRESS_TESTS_H_ */
