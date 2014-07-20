/****************************************************************************
 * File : c:/Lisp/Production/ab8500/ab8500_GPIO/Linux/ab8500_GPIO.h
 * 
 *
 * Generated on the 23/09/2009 15:06 by the 'gen-I2C' code generator 
 *
 * Generator written in Common Lisp, created by  R�mi PRUD'HOMME - ST 
 * with the help of : Gr�gory GOSCINIACK - ST, Ir�n�e BROCHIER - Teamlog
 *
 ***************************************************************************
 *  Copyrigtht ST Microelectronics  2009
 ***************************************************************************/

// This file is generated. Don't modify it 

#ifndef C__LISP_PRODUCTION_AB8500_AB8500_GPIO_LINUX_AB8500_GPIO_H
#define C__LISP_PRODUCTION_AB8500_AB8500_GPIO_LINUX_AB8500_GPIO_H


#ifdef __cplusplus
extern "C" {
#endif
#include "ab8500_GPIO_types.h"

unsigned char set_gpio_pad_control1( unsigned char param );
unsigned char get_gpio_pad_control1();
unsigned char set_gpio_pad_control2( unsigned char param );
unsigned char get_gpio_pad_control2();
unsigned char set_gpio_pad_control3( unsigned char param );
unsigned char get_gpio_pad_control3();
unsigned char set_gpio_pad_control4( unsigned char param );
unsigned char get_gpio_pad_control4();
unsigned char set_gpio_pad_control5( unsigned char param );
unsigned char get_gpio_pad_control5();
unsigned char set_gpio_pad_control6( unsigned char param );
unsigned char get_gpio_pad_control6();
unsigned char set_gpio_direction1( unsigned char param );
unsigned char get_gpio_direction1();
unsigned char set_gpio_direction2( unsigned char param );
unsigned char get_gpio_direction2();
unsigned char set_gpio_direction3( unsigned char param );
unsigned char get_gpio_direction3();
unsigned char set_gpio_direction4( unsigned char param );
unsigned char get_gpio_direction4();
unsigned char set_gpio_direction5( unsigned char param );
unsigned char get_gpio_direction5();
unsigned char set_gpio_direction6( unsigned char param );
unsigned char get_gpio_direction6();
unsigned char set_gpio_set_ouput1( unsigned char param );
unsigned char get_gpio_set_ouput1();
unsigned char set_gpio_set_ouput2( unsigned char param );
unsigned char get_gpio_set_ouput2();
unsigned char set_gpio_set_ouput3( unsigned char param );
unsigned char get_gpio_set_ouput3();
unsigned char set_gpio_set_ouput4( unsigned char param );
unsigned char get_gpio_set_ouput4();
unsigned char set_gpio_set_ouput5( unsigned char param );
unsigned char get_gpio_set_ouput5();
unsigned char set_gpio_set_ouput6( unsigned char param );
unsigned char get_gpio_set_ouput6();
unsigned char set_gpio_pull_down1( unsigned char param );
unsigned char get_gpio_pull_down1();
unsigned char set_gpio_pull_down2( unsigned char param );
unsigned char get_gpio_pull_down2();
unsigned char set_gpio_pull_down3( unsigned char param );
unsigned char get_gpio_pull_down3();
unsigned char set_gpio_pull_down4( unsigned char param );
unsigned char get_gpio_pull_down4();
unsigned char set_gpio_pull_down5( unsigned char param );
unsigned char get_gpio_pull_down5();
unsigned char set_gpio_pull_down6( unsigned char param );
unsigned char get_gpio_pull_down6();
unsigned char set_gpio_get_input1( unsigned char param );
unsigned char get_gpio_get_input1();
unsigned char set_gpio_get_input2( unsigned char param );
unsigned char get_gpio_get_input2();
unsigned char set_gpio_get_input3( unsigned char param );
unsigned char get_gpio_get_input3();
unsigned char set_gpio_get_input4( unsigned char param );
unsigned char get_gpio_get_input4();
unsigned char set_gpio_get_input5( unsigned char param );
unsigned char get_gpio_get_input5();
unsigned char set_gpio_get_input6( unsigned char param );
unsigned char get_gpio_get_input6();
unsigned char set_gpio8_pad_selection( enum gpio_pad_selection param );
unsigned char get_gpio8_pad_selection();
unsigned char set_gpio7_pad_selection( enum gpio_pad_selection param );
unsigned char get_gpio7_pad_selection();
unsigned char set_gpio6_pad_selection( enum gpio_pad_selection param );
unsigned char get_gpio6_pad_selection();
unsigned char set_gpio4_pad_selection( enum gpio_pad_selection param );
unsigned char get_gpio4_pad_selection();
unsigned char set_gpio3_pad_selection( enum gpio_pad_selection param );
unsigned char get_gpio3_pad_selection();
unsigned char set_gpio2_pad_selection( enum gpio_pad_selection param );
unsigned char get_gpio2_pad_selection();
unsigned char set_gpio1_pad_selection( enum gpio_pad_selection param );
unsigned char get_gpio1_pad_selection();
unsigned char set_gpio16_pad_selection( enum gpio_pad_selection param );
unsigned char get_gpio16_pad_selection();
unsigned char set_gpio15_pad_selection( enum gpio_pad_selection param );
unsigned char get_gpio15_pad_selection();
unsigned char set_gpio14_pad_selection( enum gpio_pad_selection param );
unsigned char get_gpio14_pad_selection();
unsigned char set_gpio13_pad_selection( enum gpio_pad_selection param );
unsigned char get_gpio13_pad_selection();
unsigned char set_gpio12_pad_selection( enum gpio_pad_selection param );
unsigned char get_gpio12_pad_selection();
unsigned char set_gpio11_pad_selection( enum gpio_pad_selection param );
unsigned char get_gpio11_pad_selection();
unsigned char set_gpio10_pad_selection( enum gpio_pad_selection param );
unsigned char get_gpio10_pad_selection();
unsigned char set_gpio9_pad_selection( enum gpio_pad_selection param );
unsigned char get_gpio9_pad_selection();
unsigned char set_gpio24_pad_selection( enum gpio_pad_selection param );
unsigned char get_gpio24_pad_selection();
unsigned char set_gpio23_pad_selection( enum gpio_pad_selection param );
unsigned char get_gpio23_pad_selection();
unsigned char set_gpio22_pad_selection( enum gpio_pad_selection param );
unsigned char get_gpio22_pad_selection();
unsigned char set_gpio21_pad_selection( enum gpio_pad_selection param );
unsigned char get_gpio21_pad_selection();
unsigned char set_gpio17_20_pad_selection( enum gpio_pad_selection param );
unsigned char get_gpio17_20_pad_selection();
unsigned char set_gpio31_32_pad_selection( enum gpio_pad_selection param );
unsigned char get_gpio31_32_pad_selection();
unsigned char set_gpio29_30_pad_selection( enum gpio_pad_selection param );
unsigned char get_gpio29_30_pad_selection();
unsigned char set_gpio27_28_pad_selection( enum gpio_pad_selection param );
unsigned char get_gpio27_28_pad_selection();
unsigned char set_gpio25_pad_selection( enum gpio_pad_selection param );
unsigned char get_gpio25_pad_selection();
unsigned char set_gpio40_pad_selection( enum gpio_pad_selection param );
unsigned char get_gpio40_pad_selection();
unsigned char set_gpio39_pad_selection( enum gpio_pad_selection param );
unsigned char get_gpio39_pad_selection();
unsigned char set_gpio38_pad_selection( enum gpio_pad_selection param );
unsigned char get_gpio38_pad_selection();
unsigned char set_gpio37_pad_selection( enum gpio_pad_selection param );
unsigned char get_gpio37_pad_selection();
unsigned char set_gpio36_pad_selection( enum gpio_pad_selection param );
unsigned char get_gpio36_pad_selection();
unsigned char set_gpio34_pad_selection( enum gpio_pad_selection param );
unsigned char get_gpio34_pad_selection();
unsigned char set_gpio42_pad_selection( enum gpio_pad_selection param );
unsigned char get_gpio42_pad_selection();
unsigned char set_gpio41_pad_selection( enum gpio_pad_selection param );
unsigned char get_gpio41_pad_selection();
unsigned char set_gpio8_direction( enum gpio_direction param );
unsigned char get_gpio8_direction();
unsigned char set_gpio7_direction( enum gpio_direction param );
unsigned char get_gpio7_direction();
unsigned char set_gpio6_direction( enum gpio_direction param );
unsigned char get_gpio6_direction();
unsigned char set_gpio4_direction( enum gpio_direction param );
unsigned char get_gpio4_direction();
unsigned char set_gpio3_direction( enum gpio_direction param );
unsigned char get_gpio3_direction();
unsigned char set_gpio2_direction( enum gpio_direction param );
unsigned char get_gpio2_direction();
unsigned char set_gpio1_direction( enum gpio_direction param );
unsigned char get_gpio1_direction();
unsigned char set_gpio16_direction( enum gpio_direction param );
unsigned char get_gpio16_direction();
unsigned char set_gpio15_direction( enum gpio_direction param );
unsigned char get_gpio15_direction();
unsigned char set_gpio14_direction( enum gpio_direction param );
unsigned char get_gpio14_direction();
unsigned char set_gpio13_direction( enum gpio_direction param );
unsigned char get_gpio13_direction();
unsigned char set_gpio12_direction( enum gpio_direction param );
unsigned char get_gpio12_direction();
unsigned char set_gpio11_direction( enum gpio_direction param );
unsigned char get_gpio11_direction();
unsigned char set_gpio10_direction( enum gpio_direction param );
unsigned char get_gpio10_direction();
unsigned char set_gpio9_direction( enum gpio_direction param );
unsigned char get_gpio9_direction();
unsigned char set_gpio24_direction( enum gpio_direction param );
unsigned char get_gpio24_direction();
unsigned char set_gpio23_direction( enum gpio_direction param );
unsigned char get_gpio23_direction();
unsigned char set_gpio22_direction( enum gpio_direction param );
unsigned char get_gpio22_direction();
unsigned char set_gpio21_direction( enum gpio_direction param );
unsigned char get_gpio21_direction();
unsigned char set_gpio20_direction( enum gpio_direction param );
unsigned char get_gpio20_direction();
unsigned char set_gpio19_direction( enum gpio_direction param );
unsigned char get_gpio19_direction();
unsigned char set_gpio18_direction( enum gpio_direction param );
unsigned char get_gpio18_direction();
unsigned char set_gpio17_direction( enum gpio_direction param );
unsigned char get_gpio17_direction();
unsigned char set_gpio32_direction( enum gpio_direction param );
unsigned char get_gpio32_direction();
unsigned char set_gpio31_direction( enum gpio_direction param );
unsigned char get_gpio31_direction();
unsigned char set_gpio30_direction( enum gpio_direction param );
unsigned char get_gpio30_direction();
unsigned char set_gpio29_direction( enum gpio_direction param );
unsigned char get_gpio29_direction();
unsigned char set_gpio28_direction( enum gpio_direction param );
unsigned char get_gpio28_direction();
unsigned char set_gpio27_direction( enum gpio_direction param );
unsigned char get_gpio27_direction();
unsigned char set_gpio26_direction( enum gpio_direction param );
unsigned char get_gpio26_direction();
unsigned char set_gpio25_direction( enum gpio_direction param );
unsigned char get_gpio25_direction();
unsigned char set_gpio40_direction( enum gpio_direction param );
unsigned char get_gpio40_direction();
unsigned char set_gpio39_direction( enum gpio_direction param );
unsigned char get_gpio39_direction();
unsigned char set_gpio38_direction( enum gpio_direction param );
unsigned char get_gpio38_direction();
unsigned char set_gpio37_direction( enum gpio_direction param );
unsigned char get_gpio37_direction();
unsigned char set_gpio36_direction( enum gpio_direction param );
unsigned char get_gpio36_direction();
unsigned char set_gpio35_direction( enum gpio_direction param );
unsigned char get_gpio35_direction();
unsigned char set_gpio34_direction( enum gpio_direction param );
unsigned char get_gpio34_direction();
unsigned char set_gpio42_direction( enum gpio_direction param );
unsigned char get_gpio42_direction();
unsigned char set_gpio41_direction( enum gpio_direction param );
unsigned char get_gpio41_direction();
unsigned char set_gpio8_output( enum gpio_output param );
unsigned char get_gpio8_output();
unsigned char set_gpio7_output( enum gpio_output param );
unsigned char get_gpio7_output();
unsigned char set_gpio6_output( enum gpio_output param );
unsigned char get_gpio6_output();
unsigned char set_gpio4_output( enum gpio_output param );
unsigned char get_gpio4_output();
unsigned char set_gpio3_output( enum gpio_output param );
unsigned char get_gpio3_output();
unsigned char set_gpio2_output( enum gpio_output param );
unsigned char get_gpio2_output();
unsigned char set_gpio1_output( enum gpio_output param );
unsigned char get_gpio1_output();
unsigned char set_gpio16_output( enum gpio_output param );
unsigned char get_gpio16_output();
unsigned char set_gpio15_output( enum gpio_output param );
unsigned char get_gpio15_output();
unsigned char set_gpio14_output( enum gpio_output param );
unsigned char get_gpio14_output();
unsigned char set_gpio13_output( enum gpio_output param );
unsigned char get_gpio13_output();
unsigned char set_gpio12_output( enum gpio_output param );
unsigned char get_gpio12_output();
unsigned char set_gpio11_output( enum gpio_output param );
unsigned char get_gpio11_output();
unsigned char set_gpio10_output( enum gpio_output param );
unsigned char get_gpio10_output();
unsigned char set_gpio9_output( enum gpio_output param );
unsigned char get_gpio9_output();
unsigned char set_gpio24_output( enum gpio_output param );
unsigned char get_gpio24_output();
unsigned char set_gpio23_output( enum gpio_output param );
unsigned char get_gpio23_output();
unsigned char set_gpio22_output( enum gpio_output param );
unsigned char get_gpio22_output();
unsigned char set_gpio21_output( enum gpio_output param );
unsigned char get_gpio21_output();
unsigned char set_gpio20_output( enum gpio_output param );
unsigned char get_gpio20_output();
unsigned char set_gpio19_output( enum gpio_output param );
unsigned char get_gpio19_output();
unsigned char set_gpio18_output( enum gpio_output param );
unsigned char get_gpio18_output();
unsigned char set_gpio17_output( enum gpio_output param );
unsigned char get_gpio17_output();
unsigned char set_gpio32_output( enum gpio_output param );
unsigned char get_gpio32_output();
unsigned char set_gpio31_output( enum gpio_output param );
unsigned char get_gpio31_output();
unsigned char set_gpio30_output( enum gpio_output param );
unsigned char get_gpio30_output();
unsigned char set_gpio29_output( enum gpio_output param );
unsigned char get_gpio29_output();
unsigned char set_gpio28_output( enum gpio_output param );
unsigned char get_gpio28_output();
unsigned char set_gpio27_output( enum gpio_output param );
unsigned char get_gpio27_output();
unsigned char set_gpio26_output( enum gpio_output param );
unsigned char get_gpio26_output();
unsigned char set_gpio25_output( enum gpio_output param );
unsigned char get_gpio25_output();
unsigned char set_gpio40_output( enum gpio_output param );
unsigned char get_gpio40_output();
unsigned char set_gpio39_output( enum gpio_output param );
unsigned char get_gpio39_output();
unsigned char set_gpio38_output( enum gpio_output param );
unsigned char get_gpio38_output();
unsigned char set_gpio37_output( enum gpio_output param );
unsigned char get_gpio37_output();
unsigned char set_gpio36_output( enum gpio_output param );
unsigned char get_gpio36_output();
unsigned char set_gpio35_output( enum gpio_output param );
unsigned char get_gpio35_output();
unsigned char set_gpio34_output( enum gpio_output param );
unsigned char get_gpio34_output();
unsigned char set_gpio42_output( enum gpio_output param );
unsigned char get_gpio42_output();
unsigned char set_gpio41_output( enum gpio_output param );
unsigned char get_gpio41_output();
unsigned char set_gpio8_pulldown( enum gpio_pulldown param );
unsigned char get_gpio8_pulldown();
unsigned char set_gpio7_pulldown( enum gpio_pulldown param );
unsigned char get_gpio7_pulldown();
unsigned char set_gpio6_pulldown( enum gpio_pulldown param );
unsigned char get_gpio6_pulldown();
unsigned char set_gpio4_pulldown( enum gpio_pulldown param );
unsigned char get_gpio4_pulldown();
unsigned char set_gpio3_pulldown( enum gpio_pulldown param );
unsigned char get_gpio3_pulldown();
unsigned char set_gpio2_pulldown( enum gpio_pulldown param );
unsigned char get_gpio2_pulldown();
unsigned char set_gpio1_pulldown( enum gpio_pulldown param );
unsigned char get_gpio1_pulldown();
unsigned char set_gpio16_pulldown( enum gpio_pulldown param );
unsigned char get_gpio16_pulldown();
unsigned char set_gpio15_pulldown( enum gpio_pulldown param );
unsigned char get_gpio15_pulldown();
unsigned char set_gpio14_pulldown( enum gpio_pulldown param );
unsigned char get_gpio14_pulldown();
unsigned char set_gpio13_pulldown( enum gpio_pulldown param );
unsigned char get_gpio13_pulldown();
unsigned char set_gpio12_pulldown( enum gpio_pulldown param );
unsigned char get_gpio12_pulldown();
unsigned char set_gpio11_pulldown( enum gpio_pulldown param );
unsigned char get_gpio11_pulldown();
unsigned char set_gpio10_pulldown( enum gpio_pulldown param );
unsigned char get_gpio10_pulldown();
unsigned char set_gpio9_pulldown( enum gpio_pulldown param );
unsigned char get_gpio9_pulldown();
unsigned char set_gpio24_pulldown( enum gpio_pulldown param );
unsigned char get_gpio24_pulldown();
unsigned char set_gpio23_pulldown( enum gpio_pulldown param );
unsigned char get_gpio23_pulldown();
unsigned char set_gpio22_pulldown( enum gpio_pulldown param );
unsigned char get_gpio22_pulldown();
unsigned char set_gpio21_pulldown( enum gpio_pulldown param );
unsigned char get_gpio21_pulldown();
unsigned char set_gpio20_pulldown( enum gpio_pulldown param );
unsigned char get_gpio20_pulldown();
unsigned char set_gpio19_pulldown( enum gpio_pulldown param );
unsigned char get_gpio19_pulldown();
unsigned char set_gpio18_pulldown( enum gpio_pulldown param );
unsigned char get_gpio18_pulldown();
unsigned char set_gpio17_pulldown( enum gpio_pulldown param );
unsigned char get_gpio17_pulldown();
unsigned char set_gpio32_pulldown( enum gpio_pulldown param );
unsigned char get_gpio32_pulldown();
unsigned char set_gpio31_pulldown( enum gpio_pulldown param );
unsigned char get_gpio31_pulldown();
unsigned char set_gpio30_pulldown( enum gpio_pulldown param );
unsigned char get_gpio30_pulldown();
unsigned char set_gpio29_pulldown( enum gpio_pulldown param );
unsigned char get_gpio29_pulldown();
unsigned char set_gpio28_pulldown( enum gpio_pulldown param );
unsigned char get_gpio28_pulldown();
unsigned char set_gpio27_pulldown( enum gpio_pulldown param );
unsigned char get_gpio27_pulldown();
unsigned char set_gpio26_pulldown( enum gpio_pulldown param );
unsigned char get_gpio26_pulldown();
unsigned char set_gpio25_pulldown( enum gpio_pulldown param );
unsigned char get_gpio25_pulldown();
unsigned char set_gpio40_pulldown( enum gpio_pulldown param );
unsigned char get_gpio40_pulldown();
unsigned char set_gpio39_pulldown( enum gpio_pulldown param );
unsigned char get_gpio39_pulldown();
unsigned char set_gpio38_pulldown( enum gpio_pulldown param );
unsigned char get_gpio38_pulldown();
unsigned char set_gpio37_pulldown( enum gpio_pulldown param );
unsigned char get_gpio37_pulldown();
unsigned char set_gpio36_pulldown( enum gpio_pulldown param );
unsigned char get_gpio36_pulldown();
unsigned char set_gpio35_pulldown( enum gpio_pulldown param );
unsigned char get_gpio35_pulldown();
unsigned char set_gpio34_pulldown( enum gpio_pulldown param );
unsigned char get_gpio34_pulldown();
unsigned char set_gpio42_pulldown( enum gpio_pulldown param );
unsigned char get_gpio42_pulldown();
unsigned char set_gpio41_pulldown( enum gpio_pulldown param );
unsigned char get_gpio41_pulldown();
unsigned char get_gpio8_input();
unsigned char get_gpio7_input();
unsigned char get_gpio6_input();
unsigned char get_gpio4_input();
unsigned char get_gpio3_input();
unsigned char get_gpio2_input();
unsigned char get_gpio1_input();
unsigned char get_gpio16_input();
unsigned char get_gpio15_input();
unsigned char get_gpio14_input();
unsigned char get_gpio13_input();
unsigned char get_gpio12_input();
unsigned char get_gpio11_input();
unsigned char get_gpio10_input();
unsigned char get_gpio9_input();
unsigned char get_gpio24_input();
unsigned char get_gpio23_input();
unsigned char get_gpio22_input();
unsigned char get_gpio21_input();
unsigned char get_gpio20_input();
unsigned char get_gpio19_input();
unsigned char get_gpio18_input();
unsigned char get_gpio17_input();
unsigned char get_gpio32_input();
unsigned char get_gpio31_input();
unsigned char get_gpio30_input();
unsigned char get_gpio29_input();
unsigned char get_gpio28_input();
unsigned char get_gpio27_input();
unsigned char get_gpio26_input();
unsigned char get_gpio25_input();
unsigned char get_gpio40_input();
unsigned char get_gpio39_input();
unsigned char get_gpio38_input();
unsigned char get_gpio37_input();
unsigned char get_gpio36_input();
unsigned char get_gpio35_input();
unsigned char get_gpio34_input();
unsigned char get_gpio33_input();
unsigned char get_gpio42_input();
unsigned char get_gpio41_input();
unsigned char set_gpio13_alternate( enum gpio13_alternate param );
unsigned char get_gpio13_alternate();
unsigned char set_gpio12_alternate( enum gpio12_alternate param );
unsigned char get_gpio12_alternate();
unsigned char set_gpio11_alternate( enum gpio11_alternate param );
unsigned char get_gpio11_alternate();
unsigned char set_gpio10_alternate( enum gpio10_alternate param );
unsigned char get_gpio10_alternate();


#ifdef __cplusplus
}
#endif

#endif
