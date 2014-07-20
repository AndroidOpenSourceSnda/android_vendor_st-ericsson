/*
 * Copyright (C) ST-Ericsson SA 2010
 * Code ported from Nomadik GPIO driver in ST-Ericsson Linux kernel code.
 * The purpose is that GPIO config found in kernel should work by simply
 * copy-paste it to U-boot.
 *
 * Ported to U-boot by:
 * Copyright (C) 2010 Hans Holmberg <hans.xh.holmberg AT stericsson.com>
 *
 * License terms: GNU General Public License, version 2
 * Author: Rabin Vincent <rabin.vincent@stericsson.com>
 */

#ifndef __DB5500_PINS_H
#define __DB5500_PINS_H

#define GPIO0_GPIO		PIN_CFG(0, GPIO)
#define GPIO0_SM_CS3n		PIN_CFG(0, ALT_A)

#define GPIO1_GPIO		PIN_CFG(1, GPIO)
#define GPIO1_SM_A3		PIN_CFG(1, ALT_A)

#define GPIO2_GPIO		PIN_CFG(2, GPIO)
#define GPIO2_SM_A4		PIN_CFG(2, ALT_A)
#define GPIO2_SM_AVD		PIN_CFG(2, ALT_B)

#define GPIO3_GPIO		PIN_CFG(3, GPIO)
#define GPIO3_I2C1_SCL		PIN_CFG(3, ALT_A)

#define GPIO4_GPIO		PIN_CFG(4, GPIO)
#define GPIO4_I2C1_SDA		PIN_CFG(4, ALT_A)

#define GPIO5_GPIO		PIN_CFG(5, GPIO)
#define GPIO5_MC0_DAT0		PIN_CFG(5, ALT_A)
#define GPIO5_SM_ADQ8		PIN_CFG(5, ALT_B)

#define GPIO6_GPIO		PIN_CFG(6, GPIO)
#define GPIO6_MC0_DAT1		PIN_CFG(6, ALT_A)
#define GPIO6_SM_ADQ0		PIN_CFG(6, ALT_B)

#define GPIO7_GPIO		PIN_CFG(7, GPIO)
#define GPIO7_MC0_DAT2		PIN_CFG(7, ALT_A)
#define GPIO7_SM_ADQ9		PIN_CFG(7, ALT_B)

#define GPIO8_GPIO		PIN_CFG(8, GPIO)
#define GPIO8_MC0_DAT3		PIN_CFG(8, ALT_A)
#define GPIO8_SM_ADQ1		PIN_CFG(8, ALT_B)

#define GPIO9_GPIO		PIN_CFG(9, GPIO)
#define GPIO9_MC0_DAT4		PIN_CFG(9, ALT_A)
#define GPIO9_SM_ADQ10		PIN_CFG(9, ALT_B)

#define GPIO10_GPIO		PIN_CFG(10, GPIO)
#define GPIO10_MC0_DAT5		PIN_CFG(10, ALT_A)
#define GPIO10_SM_ADQ2		PIN_CFG(10, ALT_B)

#define GPIO11_GPIO		PIN_CFG(11, GPIO)
#define GPIO11_MC0_DAT6		PIN_CFG(11, ALT_A)
#define GPIO11_SM_ADQ11		PIN_CFG(11, ALT_B)

#define GPIO12_GPIO		PIN_CFG(12, GPIO)
#define GPIO12_MC0_DAT7		PIN_CFG(12, ALT_A)
#define GPIO12_SM_ADQ3		PIN_CFG(12, ALT_B)

#define GPIO13_GPIO		PIN_CFG(13, GPIO)
#define GPIO13_MC0_CMD		PIN_CFG(13, ALT_A)
#define GPIO13_SM_BUSY0n	PIN_CFG(13, ALT_B)
#define GPIO13_SM_WAIT0n	PIN_CFG(13, ALT_C)

#define GPIO14_GPIO		PIN_CFG(14, GPIO)
#define GPIO14_MC0_CLK		PIN_CFG(14, ALT_A)
#define GPIO14_SM_CS1n		PIN_CFG(14, ALT_B)
#define GPIO14_SM_CKO		PIN_CFG(14, ALT_C)

#define GPIO15_GPIO		PIN_CFG(15, GPIO)
#define GPIO15_SM_A5		PIN_CFG(15, ALT_A)
#define GPIO15_SM_CLE		PIN_CFG(15, ALT_B)

#define GPIO16_GPIO		PIN_CFG(16, GPIO)
#define GPIO16_MC2_CMD		PIN_CFG(16, ALT_A)
#define GPIO16_SM_OEn		PIN_CFG(16, ALT_B)

#define GPIO17_GPIO		PIN_CFG(17, GPIO)
#define GPIO17_MC2_CLK		PIN_CFG(17, ALT_A)
#define GPIO17_SM_WEn		PIN_CFG(17, ALT_B)

#define GPIO18_GPIO		PIN_CFG(18, GPIO)
#define GPIO18_SM_A6		PIN_CFG(18, ALT_A)
#define GPIO18_SM_ALE		PIN_CFG(18, ALT_B)
#define GPIO18_SM_AVDn		PIN_CFG(18, ALT_C)

#define GPIO19_GPIO		PIN_CFG(19, GPIO)
#define GPIO19_MC2_DAT1		PIN_CFG(19, ALT_A)
#define GPIO19_SM_ADQ4		PIN_CFG(19, ALT_B)

#define GPIO20_GPIO		PIN_CFG(20, GPIO)
#define GPIO20_MC2_DAT3		PIN_CFG(20, ALT_A)
#define GPIO20_SM_ADQ5		PIN_CFG(20, ALT_B)

#define GPIO21_GPIO		PIN_CFG(21, GPIO)
#define GPIO21_MC2_DAT5		PIN_CFG(21, ALT_A)
#define GPIO21_SM_ADQ6		PIN_CFG(21, ALT_B)

#define GPIO22_GPIO		PIN_CFG(22, GPIO)
#define GPIO22_MC2_DAT7		PIN_CFG(22, ALT_A)
#define GPIO22_SM_ADQ7		PIN_CFG(22, ALT_B)

#define GPIO23_GPIO		PIN_CFG(23, GPIO)
#define GPIO23_MC2_DAT0		PIN_CFG(23, ALT_A)
#define GPIO23_SM_ADQ12		PIN_CFG(23, ALT_B)
#define GPIO23_MC0_DAT1		PIN_CFG(23, ALT_C)

#define GPIO24_GPIO		PIN_CFG(24, GPIO)
#define GPIO24_MC2_DAT2		PIN_CFG(24, ALT_A)
#define GPIO24_SM_ADQ13		PIN_CFG(24, ALT_B)
#define GPIO24_MC0_DAT3		PIN_CFG(24, ALT_C)

#define GPIO25_GPIO		PIN_CFG(25, GPIO)
#define GPIO25_MC2_DAT4		PIN_CFG(25, ALT_A)
#define GPIO25_SM_ADQ14		PIN_CFG(25, ALT_B)
#define GPIO25_MC0_CMD		PIN_CFG(25, ALT_C)

#define GPIO26_GPIO		PIN_CFG(26, GPIO)
#define GPIO26_MC2_DAT6		PIN_CFG(26, ALT_A)
#define GPIO26_SM_ADQ15		PIN_CFG(26, ALT_B)

#define GPIO27_GPIO		PIN_CFG(27, GPIO)
#define GPIO27_SM_CS0n		PIN_CFG(27, ALT_A)
#define GPIO27_SM_PS0n		PIN_CFG(27, ALT_B)

#define GPIO28_GPIO		PIN_CFG(28, GPIO)
#define GPIO28_U0_TXD		PIN_CFG(28, ALT_A)
#define GPIO28_SM_A0		PIN_CFG(28, ALT_B)

#define GPIO29_GPIO		PIN_CFG(29, GPIO)
#define GPIO29_U0_RXD		PIN_CFG(29, ALT_A)
#define GPIO29_SM_A1		PIN_CFG(29, ALT_B)
#define GPIO29_PWM_0		PIN_CFG(29, ALT_C)

#define GPIO30_GPIO		PIN_CFG(30, GPIO)
#define GPIO30_MC0_DAT5		PIN_CFG(30, ALT_A)
#define GPIO30_SM_A2		PIN_CFG(30, ALT_B)
#define GPIO30_PWM_1		PIN_CFG(30, ALT_C)

#define GPIO31_GPIO		PIN_CFG(31, GPIO)
#define GPIO31_MC0_DAT7		PIN_CFG(31, ALT_A)
#define GPIO31_SM_CS2n		PIN_CFG(31, ALT_B)
#define GPIO31_PWM_2		PIN_CFG(31, ALT_C)

#define GPIO32_GPIO		PIN_CFG(32, GPIO)
#define GPIO32_MSP0_TCK		PIN_CFG(32, ALT_A)
#define GPIO32_ACCI2S0_SCK	PIN_CFG(32, ALT_B)

#define GPIO33_GPIO		PIN_CFG(33, GPIO)
#define GPIO33_MSP0_TFS		PIN_CFG(33, ALT_A)
#define GPIO33_ACCI2S0_WS	PIN_CFG(33, ALT_B)

#define GPIO34_GPIO		PIN_CFG(34, GPIO)
#define GPIO34_MSP0_TXD		PIN_CFG(34, ALT_A)
#define GPIO34_ACCI2S0_DLD	PIN_CFG(34, ALT_B)

#define GPIO35_GPIO		PIN_CFG(35, GPIO)
#define GPIO35_MSP0_RXD		PIN_CFG(35, ALT_A)
#define GPIO35_ACCI2S0_ULD	PIN_CFG(35, ALT_B)

#define GPIO64_GPIO		PIN_CFG(64, GPIO)
#define GPIO64_USB_DAT0		PIN_CFG(64, ALT_A)
#define GPIO64_U0_TXD		PIN_CFG(64, ALT_B)

#define GPIO65_GPIO		PIN_CFG(65, GPIO)
#define GPIO65_USB_DAT1		PIN_CFG(65, ALT_A)
#define GPIO65_U0_RXD		PIN_CFG(65, ALT_B)

#define GPIO66_GPIO		PIN_CFG(66, GPIO)
#define GPIO66_USB_DAT2		PIN_CFG(66, ALT_A)

#define GPIO67_GPIO		PIN_CFG(67, GPIO)
#define GPIO67_USB_DAT3		PIN_CFG(67, ALT_A)

#define GPIO68_GPIO		PIN_CFG(68, GPIO)
#define GPIO68_USB_DAT4		PIN_CFG(68, ALT_A)

#define GPIO69_GPIO		PIN_CFG(69, GPIO)
#define GPIO69_USB_DAT5		PIN_CFG(69, ALT_A)

#define GPIO70_GPIO		PIN_CFG(70, GPIO)
#define GPIO70_USB_DAT6		PIN_CFG(70, ALT_A)

#define GPIO71_GPIO		PIN_CFG(71, GPIO)
#define GPIO71_USB_DAT7		PIN_CFG(71, ALT_A)

#define GPIO72_GPIO		PIN_CFG(72, GPIO)
#define GPIO72_USB_STP		PIN_CFG(72, ALT_A)

#define GPIO73_GPIO		PIN_CFG(73, GPIO)
#define GPIO73_USB_DIR		PIN_CFG(73, ALT_A)

#define GPIO74_GPIO		PIN_CFG(74, GPIO)
#define GPIO74_USB_NXT		PIN_CFG(74, ALT_A)

#define GPIO75_GPIO		PIN_CFG(75, GPIO)
#define GPIO75_USB_XCLK		PIN_CFG(75, ALT_A)

#define GPIO76_GPIO		PIN_CFG(76, GPIO)

#define GPIO77_GPIO		PIN_CFG(77, GPIO)
#define GPIO77_ACCTX_ON		PIN_CFG(77, ALT_A)

#define GPIO78_GPIO		PIN_CFG(78, GPIO)
#define GPIO78_IRQn		PIN_CFG(78, ALT_A)

#define GPIO79_GPIO		PIN_CFG(79, GPIO)
#define GPIO79_ACCSIM_Clk	PIN_CFG(79, ALT_A)

#define GPIO80_GPIO		PIN_CFG(80, GPIO)
#define GPIO80_ACCSIM_Da	PIN_CFG(80, ALT_A)

#define GPIO81_GPIO		PIN_CFG(81, GPIO)
#define GPIO81_ACCSIM_Reset	PIN_CFG(81, ALT_A)

#define GPIO82_GPIO		PIN_CFG(82, GPIO)
#define GPIO82_ACCSIM_DDir	PIN_CFG(82, ALT_A)

#define GPIO96_GPIO		PIN_CFG(96, GPIO)
#define GPIO96_MSP1_TCK		PIN_CFG(96, ALT_A)
#define GPIO96_PRCMU_DEBUG3	PIN_CFG(96, ALT_B)
#define GPIO96_PRCMU_DEBUG7	PIN_CFG(96, ALT_C)

#define GPIO97_GPIO		PIN_CFG(97, GPIO)
#define GPIO97_MSP1_TFS		PIN_CFG(97, ALT_A)
#define GPIO97_PRCMU_DEBUG2	PIN_CFG(97, ALT_B)
#define GPIO97_PRCMU_DEBUG6	PIN_CFG(97, ALT_C)

#define GPIO98_GPIO		PIN_CFG(98, GPIO)
#define GPIO98_MSP1_TXD		PIN_CFG(98, ALT_A)
#define GPIO98_PRCMU_DEBUG1	PIN_CFG(98, ALT_B)
#define GPIO98_PRCMU_DEBUG5	PIN_CFG(98, ALT_C)

#define GPIO99_GPIO		PIN_CFG(99, GPIO)
#define GPIO99_MSP1_RXD		PIN_CFG(99, ALT_A)
#define GPIO99_PRCMU_DEBUG0	PIN_CFG(99, ALT_B)
#define GPIO99_PRCMU_DEBUG4	PIN_CFG(99, ALT_C)

#define GPIO100_GPIO		PIN_CFG(100, GPIO)
#define GPIO100_I2C0_SCL	PIN_CFG(100, ALT_A)

#define GPIO101_GPIO		PIN_CFG(101, GPIO)
#define GPIO101_I2C0_SDA	PIN_CFG(101, ALT_A)

#define GPIO128_GPIO		PIN_CFG(128, GPIO)
#define GPIO128_KP_I0		PIN_CFG(128, ALT_A)
#define GPIO128_BUSMON_D0	PIN_CFG(128, ALT_B)

#define GPIO129_GPIO		PIN_CFG(129, GPIO)
#define GPIO129_KP_O0		PIN_CFG(129, ALT_A)
#define GPIO129_BUSMON_D1	PIN_CFG(129, ALT_B)

#define GPIO130_GPIO		PIN_CFG(130, GPIO)
#define GPIO130_KP_I1		PIN_CFG(130, ALT_A)
#define GPIO130_BUSMON_D2	PIN_CFG(130, ALT_B)

#define GPIO131_GPIO		PIN_CFG(131, GPIO)
#define GPIO131_KP_O1		PIN_CFG(131, ALT_A)
#define GPIO131_BUSMON_D3	PIN_CFG(131, ALT_B)

#define GPIO132_GPIO		PIN_CFG(132, GPIO)
#define GPIO132_KP_I2		PIN_CFG(132, ALT_A)
#define GPIO132_ETM_D15		PIN_CFG(132, ALT_B)
#define GPIO132_STMAPE_CLK	PIN_CFG(132, ALT_C)

#define GPIO133_GPIO		PIN_CFG(133, GPIO)
#define GPIO133_KP_O2		PIN_CFG(133, ALT_A)
#define GPIO133_ETM_D14		PIN_CFG(133, ALT_B)
#define GPIO133_U0_RXD		PIN_CFG(133, ALT_C)

#define GPIO134_GPIO		PIN_CFG(134, GPIO)
#define GPIO134_KP_I3		PIN_CFG(134, ALT_A)
#define GPIO134_ETM_D13		PIN_CFG(134, ALT_B)
#define GPIO134_STMAPE_DAT0	PIN_CFG(134, ALT_C)

#define GPIO135_GPIO		PIN_CFG(135, GPIO)
#define GPIO135_KP_O3		PIN_CFG(135, ALT_A)
#define GPIO135_ETM_D12		PIN_CFG(135, ALT_B)
#define GPIO135_STMAPE_DAT1	PIN_CFG(135, ALT_C)

#define GPIO136_GPIO		PIN_CFG(136, GPIO)
#define GPIO136_KP_I4		PIN_CFG(136, ALT_A)
#define GPIO136_ETM_D11		PIN_CFG(136, ALT_B)
#define GPIO136_STMAPE_DAT2	PIN_CFG(136, ALT_C)

#define GPIO137_GPIO		PIN_CFG(137, GPIO)
#define GPIO137_KP_O4		PIN_CFG(137, ALT_A)
#define GPIO137_ETM_D10		PIN_CFG(137, ALT_B)
#define GPIO137_STMAPE_DAT3	PIN_CFG(137, ALT_C)

#define GPIO138_GPIO		PIN_CFG(138, GPIO)
#define GPIO138_KP_I5		PIN_CFG(138, ALT_A)
#define GPIO138_ETM_D9		PIN_CFG(138, ALT_B)
#define GPIO138_U0_TXD		PIN_CFG(138, ALT_C)

#define GPIO139_GPIO		PIN_CFG(139, GPIO)
#define GPIO139_KP_O5		PIN_CFG(139, ALT_A)
#define GPIO139_ETM_D8		PIN_CFG(139, ALT_B)
#define GPIO139_BUSMON_D11	PIN_CFG(139, ALT_C)

#define GPIO140_GPIO		PIN_CFG(140, GPIO)
#define GPIO140_KP_I6		PIN_CFG(140, ALT_A)
#define GPIO140_ETM_D7		PIN_CFG(140, ALT_B)
#define GPIO140_STMAPE_CLK	PIN_CFG(140, ALT_C)

#define GPIO141_GPIO		PIN_CFG(141, GPIO)
#define GPIO141_KP_O6		PIN_CFG(141, ALT_A)
#define GPIO141_ETM_D6		PIN_CFG(141, ALT_B)
#define GPIO141_U0_RXD		PIN_CFG(141, ALT_C)

#define GPIO142_GPIO		PIN_CFG(142, GPIO)
#define GPIO142_KP_I7		PIN_CFG(142, ALT_A)
#define GPIO142_ETM_D5		PIN_CFG(142, ALT_B)
#define GPIO142_STMAPE_DAT0	PIN_CFG(142, ALT_C)

#define GPIO143_GPIO		PIN_CFG(143, GPIO)
#define GPIO143_KP_O7		PIN_CFG(143, ALT_A)
#define GPIO143_ETM_D4		PIN_CFG(143, ALT_B)
#define GPIO143_STMAPE_DAT1	PIN_CFG(143, ALT_C)

#define GPIO144_GPIO		PIN_CFG(144, GPIO)
#define GPIO144_I2C3_SCL	PIN_CFG(144, ALT_A)
#define GPIO144_ETM_D3		PIN_CFG(144, ALT_B)
#define GPIO144_STMAPE_DAT2	PIN_CFG(144, ALT_C)

#define GPIO145_GPIO		PIN_CFG(145, GPIO)
#define GPIO145_I2C3_SDA	PIN_CFG(145, ALT_A)
#define GPIO145_ETM_D2		PIN_CFG(145, ALT_B)
#define GPIO145_STMAPE_DAT3	PIN_CFG(145, ALT_C)

#define GPIO146_GPIO		PIN_CFG(146, GPIO)
#define GPIO146_PWM_0		PIN_CFG(146, ALT_A)
#define GPIO146_ETM_D1		PIN_CFG(146, ALT_B)

#define GPIO147_GPIO		PIN_CFG(147, GPIO)
#define GPIO147_PWM_1		PIN_CFG(147, ALT_A)
#define GPIO147_ETM_D0		PIN_CFG(147, ALT_B)

#define GPIO148_GPIO		PIN_CFG(148, GPIO)
#define GPIO148_PWM_2		PIN_CFG(148, ALT_A)
#define GPIO148_ETM_CLK		PIN_CFG(148, ALT_B)

#define GPIO160_GPIO		PIN_CFG(160, GPIO)
#define GPIO160_CLKOUT_REQn	PIN_CFG(160, ALT_A)

#define GPIO161_GPIO		PIN_CFG(161, GPIO)
#define GPIO161_CLKOUT_0	PIN_CFG(161, ALT_A)

#define GPIO162_GPIO		PIN_CFG(162, GPIO)
#define GPIO162_CLKOUT_1	PIN_CFG(162, ALT_A)

#define GPIO163_GPIO		PIN_CFG(163, GPIO)

#define GPIO164_GPIO		PIN_CFG(164, GPIO)
#define GPIO164_GPS_START	PIN_CFG(164, ALT_A)

#define GPIO165_GPIO		PIN_CFG(165, GPIO)
#define GPIO165_SPI1_CS2n	PIN_CFG(165, ALT_A)
#define GPIO165_U3_RXD		PIN_CFG(165, ALT_B)
#define GPIO165_BUSMON_D20	PIN_CFG(165, ALT_C)

#define GPIO166_GPIO		PIN_CFG(166, GPIO)
#define GPIO166_SPI1_CS1n	PIN_CFG(166, ALT_A)
#define GPIO166_U3_TXD		PIN_CFG(166, ALT_B)
#define GPIO166_BUSMON_D21	PIN_CFG(166, ALT_C)

#define GPIO167_GPIO		PIN_CFG(167, GPIO)
#define GPIO167_SPI1_CS0n	PIN_CFG(167, ALT_A)
#define GPIO167_U3_RTSn		PIN_CFG(167, ALT_B)
#define GPIO167_BUSMON_D22	PIN_CFG(167, ALT_C)

#define GPIO168_GPIO		PIN_CFG(168, GPIO)
#define GPIO168_SPI1_RXD	PIN_CFG(168, ALT_A)
#define GPIO168_U3_CTSn		PIN_CFG(168, ALT_B)
#define GPIO168_BUSMON_D23	PIN_CFG(168, ALT_C)

#define GPIO169_GPIO		PIN_CFG(169, GPIO)
#define GPIO169_SPI1_TXD	PIN_CFG(169, ALT_A)
#define GPIO169_DDR_RC		PIN_CFG(169, ALT_B)
#define GPIO169_BUSMON_D24	PIN_CFG(169, ALT_C)

#define GPIO170_GPIO		PIN_CFG(170, GPIO)
#define GPIO170_SPI1_CLK	PIN_CFG(170, ALT_A)

#define GPIO171_GPIO		PIN_CFG(171, GPIO)
#define GPIO171_MC3_DAT0	PIN_CFG(171, ALT_A)
#define GPIO171_SPI3_RXD	PIN_CFG(171, ALT_B)
#define GPIO171_BUSMON_D25	PIN_CFG(171, ALT_C)

#define GPIO172_GPIO		PIN_CFG(172, GPIO)
#define GPIO172_MC3_DAT1	PIN_CFG(172, ALT_A)
#define GPIO172_SPI3_CS1n	PIN_CFG(172, ALT_B)
#define GPIO172_BUSMON_D26	PIN_CFG(172, ALT_C)

#define GPIO173_GPIO		PIN_CFG(173, GPIO)
#define GPIO173_MC3_DAT2	PIN_CFG(173, ALT_A)
#define GPIO173_SPI3_CS2n	PIN_CFG(173, ALT_B)
#define GPIO173_BUSMON_D27	PIN_CFG(173, ALT_C)

#define GPIO174_GPIO		PIN_CFG(174, GPIO)
#define GPIO174_MC3_DAT3	PIN_CFG(174, ALT_A)
#define GPIO174_SPI3_CS0n	PIN_CFG(174, ALT_B)
#define GPIO174_BUSMON_D28	PIN_CFG(174, ALT_C)

#define GPIO175_GPIO		PIN_CFG(175, GPIO)
#define GPIO175_MC3_CMD		PIN_CFG(175, ALT_A)
#define GPIO175_SPI3_TXD	PIN_CFG(175, ALT_B)
#define GPIO175_BUSMON_D29	PIN_CFG(175, ALT_C)

#define GPIO176_GPIO		PIN_CFG(176, GPIO)
#define GPIO176_MC3_CLK		PIN_CFG(176, ALT_A)
#define GPIO176_SPI3_CLK	PIN_CFG(176, ALT_B)

#define GPIO177_GPIO		PIN_CFG(177, GPIO)
#define GPIO177_U2_RXD		PIN_CFG(177, ALT_A)
#define GPIO177_I2C3_SCL	PIN_CFG(177, ALT_B)
#define GPIO177_BUSMON_D30	PIN_CFG(177, ALT_C)

#define GPIO178_GPIO		PIN_CFG(178, GPIO)
#define GPIO178_U2_TXD		PIN_CFG(178, ALT_A)
#define GPIO178_I2C3_SDA	PIN_CFG(178, ALT_B)
#define GPIO178_BUSMON_D31	PIN_CFG(178, ALT_C)

#define GPIO179_GPIO		PIN_CFG(179, GPIO)
#define GPIO179_U2_CTSn		PIN_CFG(179, ALT_A)
#define GPIO179_U3_RXD		PIN_CFG(179, ALT_B)
#define GPIO179_BUSMON_D32	PIN_CFG(179, ALT_C)

#define GPIO180_GPIO		PIN_CFG(180, GPIO)
#define GPIO180_U2_RTSn		PIN_CFG(180, ALT_A)
#define GPIO180_U3_TXD		PIN_CFG(180, ALT_B)
#define GPIO180_BUSMON_D33	PIN_CFG(180, ALT_C)

#define GPIO185_GPIO		PIN_CFG(185, GPIO)
#define GPIO185_SPI3_CS2n	PIN_CFG(185, ALT_A)
#define GPIO185_MC4_DAT0	PIN_CFG(185, ALT_B)

#define GPIO186_GPIO		PIN_CFG(186, GPIO)
#define GPIO186_SPI3_CS1n	PIN_CFG(186, ALT_A)
#define GPIO186_MC4_DAT1	PIN_CFG(186, ALT_B)

#define GPIO187_GPIO		PIN_CFG(187, GPIO)
#define GPIO187_SPI3_CS0n	PIN_CFG(187, ALT_A)
#define GPIO187_MC4_DAT2	PIN_CFG(187, ALT_B)

#define GPIO188_GPIO		PIN_CFG(188, GPIO)
#define GPIO188_SPI3_RXD	PIN_CFG(188, ALT_A)
#define GPIO188_MC4_DAT3	PIN_CFG(188, ALT_B)

#define GPIO189_GPIO		PIN_CFG(189, GPIO)
#define GPIO189_SPI3_TXD	PIN_CFG(189, ALT_A)
#define GPIO189_MC4_CMD		PIN_CFG(189, ALT_B)

#define GPIO190_GPIO		PIN_CFG(190, GPIO)
#define GPIO190_SPI3_CLK	PIN_CFG(190, ALT_A)
#define GPIO190_MC4_CLK		PIN_CFG(190, ALT_B)

#define GPIO191_GPIO		PIN_CFG(191, GPIO)
#define GPIO191_MC1_DAT0	PIN_CFG(191, ALT_A)
#define GPIO191_MC4_DAT4	PIN_CFG(191, ALT_B)
#define GPIO191_STMAPE_DAT0	PIN_CFG(191, ALT_C)

#define GPIO192_GPIO		PIN_CFG(192, GPIO)
#define GPIO192_MC1_DAT1	PIN_CFG(192, ALT_A)
#define GPIO192_MC4_DAT5	PIN_CFG(192, ALT_B)
#define GPIO192_STMAPE_DAT1	PIN_CFG(192, ALT_C)

#define GPIO193_GPIO		PIN_CFG(193, GPIO)
#define GPIO193_MC1_DAT2	PIN_CFG(193, ALT_A)
#define GPIO193_MC4_DAT6	PIN_CFG(193, ALT_B)
#define GPIO193_STMAPE_DAT2	PIN_CFG(193, ALT_C)

#define GPIO194_GPIO		PIN_CFG(194, GPIO)
#define GPIO194_MC1_DAT3	PIN_CFG(194, ALT_A)
#define GPIO194_MC4_DAT7	PIN_CFG(194, ALT_B)
#define GPIO194_STMAPE_DAT3	PIN_CFG(194, ALT_C)

#define GPIO195_GPIO		PIN_CFG(195, GPIO)
#define GPIO195_MC1_CLK		PIN_CFG(195, ALT_A)
#define GPIO195_STMAPE_CLK	PIN_CFG(195, ALT_B)
#define GPIO195_BUSMON_CLK	PIN_CFG(195, ALT_C)

#define GPIO196_GPIO		PIN_CFG(196, GPIO)
#define GPIO196_MC1_CMD		PIN_CFG(196, ALT_A)
#define GPIO196_U0_RXD		PIN_CFG(196, ALT_B)
#define GPIO196_BUSMON_D38	PIN_CFG(196, ALT_C)

#define GPIO197_GPIO		PIN_CFG(197, GPIO)
#define GPIO197_MC1_CMDDIR	PIN_CFG(197, ALT_A)
#define GPIO197_BUSMON_D39	PIN_CFG(197, ALT_B)

#define GPIO198_GPIO		PIN_CFG(198, GPIO)
#define GPIO198_MC1_FBCLK	PIN_CFG(198, ALT_A)

#define GPIO199_GPIO		PIN_CFG(199, GPIO)
#define GPIO199_MC1_DAT0DIR	PIN_CFG(199, ALT_A)
#define GPIO199_BUSMON_D40	PIN_CFG(199, ALT_B)

#define GPIO200_GPIO		PIN_CFG(200, GPIO)
#define GPIO200_U1_TXD		PIN_CFG(200, ALT_A)
#define GPIO200_ACCU0_RTSn	PIN_CFG(200, ALT_B)

#define GPIO201_GPIO		PIN_CFG(201, GPIO)
#define GPIO201_U1_RXD		PIN_CFG(201, ALT_A)
#define GPIO201_ACCU0_CTSn	PIN_CFG(201, ALT_B)

#define GPIO202_GPIO		PIN_CFG(202, GPIO)
#define GPIO202_U1_CTSn		PIN_CFG(202, ALT_A)
#define GPIO202_ACCU0_RXD	PIN_CFG(202, ALT_B)

#define GPIO203_GPIO		PIN_CFG(203, GPIO)
#define GPIO203_U1_RTSn		PIN_CFG(203, ALT_A)
#define GPIO203_ACCU0_TXD	PIN_CFG(203, ALT_B)

#define GPIO204_GPIO		PIN_CFG(204, GPIO)
#define GPIO204_SPI0_CS2n	PIN_CFG(204, ALT_A)
#define GPIO204_ACCGPIO_000	PIN_CFG(204, ALT_B)
#define GPIO204_LCD_VSI1	PIN_CFG(204, ALT_C)

#define GPIO205_GPIO		PIN_CFG(205, GPIO)
#define GPIO205_SPI0_CS1n	PIN_CFG(205, ALT_A)
#define GPIO205_ACCGPIO_001	PIN_CFG(205, ALT_B)
#define GPIO205_LCD_D3		PIN_CFG(205, ALT_C)

#define GPIO206_GPIO		PIN_CFG(206, GPIO)
#define GPIO206_SPI0_CS0n	PIN_CFG(206, ALT_A)
#define GPIO206_ACCGPIO_002	PIN_CFG(206, ALT_B)
#define GPIO206_LCD_D2		PIN_CFG(206, ALT_C)

#define GPIO207_GPIO		PIN_CFG(207, GPIO)
#define GPIO207_SPI0_RXD	PIN_CFG(207, ALT_A)
#define GPIO207_ACCGPIO_003	PIN_CFG(207, ALT_B)
#define GPIO207_LCD_D1		PIN_CFG(207, ALT_C)

#define GPIO208_GPIO		PIN_CFG(208, GPIO)
#define GPIO208_SPI0_TXD	PIN_CFG(208, ALT_A)
#define GPIO208_ACCGPIO_004	PIN_CFG(208, ALT_B)
#define GPIO208_LCD_D0		PIN_CFG(208, ALT_C)

#define GPIO209_GPIO		PIN_CFG(209, GPIO)
#define GPIO209_SPI0_CLK	PIN_CFG(209, ALT_A)
#define GPIO209_ACCGPIO_005	PIN_CFG(209, ALT_B)
#define GPIO209_LCD_CLK		PIN_CFG(209, ALT_C)

#define GPIO210_GPIO		PIN_CFG(210, GPIO)
#define GPIO210_LCD_VSO		PIN_CFG(210, ALT_A)
#define GPIO210_PRCMU_PWRCTRL1	PIN_CFG(210, ALT_B)

#define GPIO211_GPIO		PIN_CFG(211, GPIO)
#define GPIO211_LCD_VSI0	PIN_CFG(211, ALT_A)
#define GPIO211_PRCMU_PWRCTRL2	PIN_CFG(211, ALT_B)

#define GPIO212_GPIO		PIN_CFG(212, GPIO)
#define GPIO212_SPI2_CS2n	PIN_CFG(212, ALT_A)
#define GPIO212_LCD_HSO		PIN_CFG(212, ALT_B)

#define GPIO213_GPIO		PIN_CFG(213, GPIO)
#define GPIO213_SPI2_CS1n	PIN_CFG(213, ALT_A)
#define GPIO213_LCD_DE		PIN_CFG(213, ALT_B)
#define GPIO213_BUSMON_D16	PIN_CFG(213, ALT_C)

#define GPIO214_GPIO		PIN_CFG(214, GPIO)
#define GPIO214_SPI2_CS0n	PIN_CFG(214, ALT_A)
#define GPIO214_LCD_D7		PIN_CFG(214, ALT_B)
#define GPIO214_BUSMON_D17	PIN_CFG(214, ALT_C)

#define GPIO215_GPIO		PIN_CFG(215, GPIO)
#define GPIO215_SPI2_RXD	PIN_CFG(215, ALT_A)
#define GPIO215_LCD_D6		PIN_CFG(215, ALT_B)
#define GPIO215_BUSMON_D18	PIN_CFG(215, ALT_C)

#define GPIO216_GPIO		PIN_CFG(216, GPIO)
#define GPIO216_SPI2_CLK	PIN_CFG(216, ALT_A)
#define GPIO216_LCD_D5		PIN_CFG(216, ALT_B)

#define GPIO217_GPIO		PIN_CFG(217, GPIO)
#define GPIO217_SPI2_TXD	PIN_CFG(217, ALT_A)
#define GPIO217_LCD_D4		PIN_CFG(217, ALT_B)
#define GPIO217_BUSMON_D19	PIN_CFG(217, ALT_C)

#define GPIO218_GPIO		PIN_CFG(218, GPIO)
#define GPIO218_I2C2_SCL	PIN_CFG(218, ALT_A)
#define GPIO218_LCD_VSO		PIN_CFG(218, ALT_B)

#define GPIO219_GPIO		PIN_CFG(219, GPIO)
#define GPIO219_I2C2_SDA	PIN_CFG(219, ALT_A)
#define GPIO219_LCD_D3		PIN_CFG(219, ALT_B)

#define GPIO220_GPIO		PIN_CFG(220, GPIO)
#define GPIO220_MSP2_TCK	PIN_CFG(220, ALT_A)
#define GPIO220_LCD_D2		PIN_CFG(220, ALT_B)

#define GPIO221_GPIO		PIN_CFG(221, GPIO)
#define GPIO221_MSP2_TFS	PIN_CFG(221, ALT_A)
#define GPIO221_LCD_D1		PIN_CFG(221, ALT_B)

#define GPIO222_GPIO		PIN_CFG(222, GPIO)
#define GPIO222_MSP2_TXD	PIN_CFG(222, ALT_A)
#define GPIO222_LCD_D0		PIN_CFG(222, ALT_B)

#define GPIO223_GPIO		PIN_CFG(223, GPIO)
#define GPIO223_MSP2_RXD	PIN_CFG(223, ALT_A)
#define GPIO223_LCD_CLK		PIN_CFG(223, ALT_B)

#define GPIO224_GPIO		PIN_CFG(224, GPIO)
#define GPIO224_PRCMU_PWRCTRL0	PIN_CFG(224, ALT_A)
#define GPIO224_LCD_VSI1	PIN_CFG(224, ALT_B)

#define GPIO225_GPIO		PIN_CFG(225, GPIO)
#define GPIO225_PRCMU_PWRCTRL1	PIN_CFG(225, ALT_A)
#define GPIO225_IRDA_RXD	PIN_CFG(225, ALT_B)

#define GPIO226_GPIO		PIN_CFG(226, GPIO)
#define GPIO226_PRCMU_PWRCTRL2	PIN_CFG(226, ALT_A)
#define GPIO226_IRRC_DAT	PIN_CFG(226, ALT_B)

#define GPIO227_GPIO		PIN_CFG(227, GPIO)
#define GPIO227_IRRC_DAT	PIN_CFG(227, ALT_A)
#define GPIO227_IRDA_TXD	PIN_CFG(227, ALT_B)

#endif
