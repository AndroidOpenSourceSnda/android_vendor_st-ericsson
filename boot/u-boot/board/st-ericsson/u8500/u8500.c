/*
 * Copyright (C) ST-Ericsson SA 2009
 *
 * License terms: GNU General Public License (GPL), version 2.
 */

#include <config.h>
#include <common.h>
#include <i2c.h>
#include "malloc.h"
#include <mmc.h>
#include <asm/types.h>
#include <asm/mach-types.h>
#include <asm/io.h>
#include <asm/errno.h>
#include <asm/arch/clock.h>
#include <asm/arch/cpu.h>
#include <asm/arch/hardware.h>
#include <asm/arch/ab8500.h>
#include <asm/arch/prcmu.h>
#include <asm/arch/itp.h>
#include <tc35892.h>
#include <u8500_mmc_host.h>
#include <u8500_keypad.h>

#include <asm/arch/common.h>

#ifdef CONFIG_LCD
#include <lcd.h>
#endif

#include "db8500_pincfg.h"
#include "db8500_pins.h"
#include "android_bcb.h"

#ifdef CONFIG_VIDEO_LOGO
#include "mcde_display.h"
#endif

/*
 * Memory controller register
 */
#define DMC_BASE_ADDR			0x80156000
#define DMC_CTL_96			(DMC_BASE_ADDR + 0x180)
#define DMC_CTL_97			(DMC_BASE_ADDR + 0x184)

#define DMC1_BASE_ADDR		0x8015a000
#define DMC1_CTL_96			(DMC1_BASE_ADDR + 0x180)
#define DMC1_CTL_97			(DMC1_BASE_ADDR + 0x184)

#define MBYTE				(1024 * 1024)

#ifdef CONFIG_LCD
extern void lcd_setfgcolor (int color);
extern void lcd_setbgcolor (int color);

void *lcd_base;         /* Start of framebuffer memory  */
void *lcd_console_address;  /* Start of console buffer  */

int lcd_line_length;
int lcd_color_fg;
int lcd_color_bg;

short console_col;
short console_row;

vidinfo_t panel_info = {
    .vl_col = 540,
    .vl_row = 960,
    .vl_bpix = LCD_BPP,
};

/**************************************************/
/*lcd init has been done while splash logo imge,
  so the following funtions are not implemented*/
void lcd_initcolregs(void)
{
}

void lcd_setcolreg(ushort regno, ushort red, ushort green, ushort blue)
{
}

void lcd_enable(void)
{
}

void lcd_disable(void)
{
}

void lcd_ctrl_init(void *lcdbase)
{

}
/**************************************************/
ulong calc_fbsize(void)
{
    return panel_info.vl_row * panel_info.vl_col * 2 \
        * NBITS(panel_info.vl_bpix) / 8;
}
#endif

/*
 * GPIO pin config common for MOP500/HREF boards
 */
pin_cfg_t gpio_cfg_common[] = {
	/* I2C */
	GPIO147_I2C0_SCL,
	GPIO148_I2C0_SDA,
	GPIO16_I2C1_SCL,
	GPIO17_I2C1_SDA,
	GPIO10_I2C2_SDA,
	GPIO11_I2C2_SCL,
	GPIO229_I2C3_SDA,
	GPIO230_I2C3_SCL,

	/* SSP0, to AB8500 */
	GPIO143_SSP0_CLK,
	GPIO144_SSP0_FRM,
	GPIO145_SSP0_RXD | PIN_PULL_DOWN,
	GPIO146_SSP0_TXD,

	/* MMC0 (MicroSD card) */
	GPIO18_MC0_CMDDIR	| PIN_OUTPUT_HIGH,
	GPIO19_MC0_DAT0DIR	| PIN_OUTPUT_HIGH,
	GPIO20_MC0_DAT2DIR	| PIN_OUTPUT_HIGH,
	GPIO21_MC0_DAT31DIR	| PIN_OUTPUT_HIGH,
	GPIO22_MC0_FBCLK	| PIN_INPUT_NOPULL,
	GPIO23_MC0_CLK		| PIN_OUTPUT_LOW,
	GPIO24_MC0_CMD		| PIN_INPUT_PULLUP,
	GPIO25_MC0_DAT0		| PIN_INPUT_PULLUP,
	GPIO26_MC0_DAT1		| PIN_INPUT_PULLUP,
	GPIO27_MC0_DAT2		| PIN_INPUT_PULLUP,
	GPIO28_MC0_DAT3		| PIN_INPUT_PULLUP,

	/* MMC2 (POP eMMC) */
	GPIO128_MC2_CLK		| PIN_OUTPUT_LOW,
	GPIO129_MC2_CMD		| PIN_INPUT_PULLUP,
	GPIO130_MC2_FBCLK	| PIN_INPUT_NOPULL,
	GPIO131_MC2_DAT0	| PIN_INPUT_PULLUP,
	GPIO132_MC2_DAT1	| PIN_INPUT_PULLUP,
	GPIO133_MC2_DAT2	| PIN_INPUT_PULLUP,
	GPIO134_MC2_DAT3	| PIN_INPUT_PULLUP,
	GPIO135_MC2_DAT4	| PIN_INPUT_PULLUP,
	GPIO136_MC2_DAT5	| PIN_INPUT_PULLUP,
	GPIO137_MC2_DAT6	| PIN_INPUT_PULLUP,
	GPIO138_MC2_DAT7	| PIN_INPUT_PULLUP,

	/* MMC4 (On-board eMMC) */
	GPIO197_MC4_DAT3	| PIN_INPUT_PULLUP,
	GPIO198_MC4_DAT2	| PIN_INPUT_PULLUP,
	GPIO199_MC4_DAT1	| PIN_INPUT_PULLUP,
	GPIO200_MC4_DAT0	| PIN_INPUT_PULLUP,
	GPIO201_MC4_CMD		| PIN_INPUT_PULLUP,
	GPIO202_MC4_FBCLK	| PIN_INPUT_NOPULL,
	GPIO203_MC4_CLK		| PIN_OUTPUT_LOW,
	GPIO204_MC4_DAT7	| PIN_INPUT_PULLUP,
	GPIO205_MC4_DAT6	| PIN_INPUT_PULLUP,
	GPIO206_MC4_DAT5	| PIN_INPUT_PULLUP,
	GPIO207_MC4_DAT4	| PIN_INPUT_PULLUP,

	/*KEYPAD GPIO*/
#ifdef CONFIG_VIA_KEYPAD
/*
    GPIO163_KP_I1 | PIN_INPUT_PULLUP,
    GPIO162_KP_I2 | PIN_INPUT_PULLUP,
    GPIO165_KP_O3 | PIN_OUTPUT_HIGH,
    GPIO166_KP_O2 | PIN_OUTPUT_HIGH,
*/ 
/*xyliu with this config, keypad in kernel is abnormal, use peter's mothed instead of this one.*/
	GPIO162_GPIO| PIN_INPUT_PULLUP,
	GPIO163_GPIO | PIN_INPUT_PULLUP,
	GPIO165_GPIO | PIN_OUTPUT_HIGH,
	GPIO166_GPIO | PIN_OUTPUT_HIGH, 
#else
	GPIO72_KP_O3 | PIN_OUTPUT_HIGH,
	GPIO73_KP_O2 | PIN_OUTPUT_HIGH,
	GPIO74_KP_I5 | PIN_INPUT_PULLUP,
#endif

	/* UART2, console */
	GPIO29_U2_RXD	| PIN_INPUT_PULLUP,
	GPIO30_U2_TXD	| PIN_OUTPUT_HIGH,
	GPIO31_U2_CTSn	| PIN_INPUT_PULLUP,
	GPIO32_U2_RTSn	| PIN_OUTPUT_HIGH,

	/*
	 * USB, pin 256-267 USB, Is probably already setup correctly from
	 * BootROM/boot stages, but we don't trust that and set it up anyway
	 */
	GPIO256_USB_NXT,
	GPIO257_USB_STP,
	GPIO258_USB_XCLK,
	GPIO259_USB_DIR,
	GPIO260_USB_DAT7,
	GPIO261_USB_DAT6,
	GPIO262_USB_DAT5,
	GPIO263_USB_DAT4,
	GPIO264_USB_DAT3,
	GPIO265_USB_DAT2,
	GPIO266_USB_DAT1,
	GPIO267_USB_DAT0,

	/*for USB & noraml boot switch config*/
	GPIO90_GPIO | PIN_INPUT_NOPULL,
	GPIO218_GPIO | PIN_OUTPUT_LOW,
};

pin_cfg_t gpio_cfg_usb_ulpi[] = {
        /*
         * USB, pin 256-267 USB, Is probably already setup correctly from
         * BootROM/boot stages, but we don't trust that and set it up anyway
         */
        GPIO256_USB_NXT,
        GPIO257_USB_STP,
        GPIO258_USB_XCLK,
        GPIO259_USB_DIR,
        GPIO260_USB_DAT7,
        GPIO261_USB_DAT6,
        GPIO262_USB_DAT5,
        GPIO263_USB_DAT4,
        GPIO264_USB_DAT3,
        GPIO265_USB_DAT2,
        GPIO266_USB_DAT1,
        GPIO267_USB_DAT0,
};

pin_cfg_t gpio_cfg_uart_ulpi[] = {
        /*
         * USB, pin 256-267 USB, Is probably already setup correctly from
         * BootROM/boot stages, but we don't trust that and set it up anyway
         */
        GPIO256_GPIO    | PIN_INPUT_PULLDOWN,
        GPIO257_GPIO    | PIN_INPUT_PULLDOWN,
        GPIO258_GPIO    | PIN_INPUT_PULLDOWN,
        GPIO259_GPIO    | PIN_INPUT_PULLDOWN,
        GPIO260_GPIO    | PIN_INPUT_PULLDOWN,
        GPIO261_GPIO    | PIN_INPUT_PULLDOWN,
        GPIO262_GPIO    | PIN_INPUT_PULLDOWN,
        GPIO263_GPIO    | PIN_INPUT_PULLDOWN,
        GPIO264_GPIO    | PIN_INPUT_PULLDOWN,
        GPIO265_GPIO    | PIN_INPUT_PULLDOWN,
        GPIO266_U2_RXD,
        GPIO267_U2_TXD,
};

/*
 * GPIO pin config for HREF+ V60 board.
 * Contains additional settings to common mop500 settings above.
 */
pin_cfg_t gpio_cfg_hrefv60[] = {
       /* SDMMC */
	GPIO169_GPIO	| PIN_OUTPUT_LOW,	/* SDMMC_Enable */
	GPIO5_GPIO	| PIN_OUTPUT_LOW,	/* SDMMC_1V8_3V_SEL */
	GPIO95_GPIO	| PIN_INPUT_PULLUP,	/* SDMMC_CD */

#if defined(CONFIG_VIA_DISPLAY_DPI)
	GPIO139_GPIO	| PIN_OUTPUT_LOW,	/* DISP1 RST */

	GPIO64_LCDB_DE,
	GPIO65_LCDB_HSO,
	GPIO66_LCDB_VSO,
	GPIO67_LCDB_CLK,

	GPIO70_LCD_D0,
	GPIO71_LCD_D1,
	GPIO72_LCD_D2,
	GPIO73_LCD_D3,
	GPIO74_LCD_D4,
	GPIO75_LCD_D5,
	GPIO76_LCD_D6,
	GPIO77_LCD_D7,
	GPIO78_LCD_D8,
	GPIO79_LCD_D9,
	GPIO80_LCD_D10,
	GPIO81_LCD_D11,
	GPIO82_LCD_D12,
	GPIO83_LCD_D13,
	GPIO84_LCD_D14,
	GPIO85_LCD_D15,
	GPIO86_LCD_D16,
	GPIO87_LCD_D17,
#elif defined(CONFIG_VIA_DISPLAY_DSI)  
	GPIO139_GPIO| PIN_OUTPUT_LOW,	/* DISP1 RST */ 		  
	
	GPIO64_GPIO | PIN_OUTPUT_LOW,
	GPIO65_GPIO | PIN_OUTPUT_HIGH,
	GPIO66_GPIO | PIN_OUTPUT_LOW,
	GPIO67_GPIO | PIN_OUTPUT_LOW,

	GPIO70_GPIO | PIN_OUTPUT_LOW,
	GPIO71_GPIO | PIN_OUTPUT_LOW,
	GPIO72_GPIO | PIN_OUTPUT_LOW,
	GPIO73_GPIO | PIN_OUTPUT_LOW,
	GPIO74_GPIO | PIN_OUTPUT_LOW,
	GPIO75_GPIO | PIN_OUTPUT_LOW,
	GPIO76_GPIO | PIN_OUTPUT_LOW,
	GPIO77_GPIO | PIN_OUTPUT_LOW,
	GPIO78_GPIO | PIN_OUTPUT_LOW,
	GPIO79_GPIO | PIN_OUTPUT_LOW,
	GPIO80_GPIO | PIN_OUTPUT_LOW,
	GPIO81_GPIO | PIN_OUTPUT_LOW,
	GPIO82_GPIO | PIN_OUTPUT_LOW,
	GPIO83_GPIO | PIN_OUTPUT_LOW,
	GPIO84_GPIO | PIN_OUTPUT_LOW,
	GPIO85_GPIO | PIN_OUTPUT_LOW,
	GPIO86_GPIO | PIN_OUTPUT_LOW,
	GPIO87_GPIO | PIN_OUTPUT_LOW,

	GPIO143_GPIO | PIN_OUTPUT_LOW,
	GPIO144_GPIO | PIN_OUTPUT_HIGH,
	GPIO146_GPIO | PIN_OUTPUT_LOW,
#else                                                  
	GPIO65_GPIO | PIN_OUTPUT_LOW,	/* DISP1 RST */
	GPIO66_GPIO | PIN_OUTPUT_LOW,	/* DISP2 RST */
#endif
#if defined(BOARD_C7_P0)
	GPIO159_GPIO | PIN_OUTPUT_LOW, /* VDD_3V3/VDD_1V8/VDD_1V2 */
	GPIO95_GPIO  | PIN_OUTPUT_HIGH, /* LVDS_RST_N */
	GPIO139_GPIO | PIN_OUTPUT_LOW, /* LCD_RST */
	GPIO154_GPIO | PIN_OUTPUT_LOW, /* LCD_STBYB */
	GPIO167_GPIO | PIN_OUTPUT_LOW, /* PWR_EN1 VCC_3V3 */
	GPIO153_GPIO | PIN_OUTPUT_LOW, /* VG_EN AVDD_BIAS VCOM */
	
	/* debug version always on */
	GPIO68_GPIO | PIN_OUTPUT_HIGH, /* LCD_BL_EN */
	GPIO138_GPIO | PIN_OUTPUT_LOW, /* SELE low if LVDS is 8 bits*/
	GPIO155_GPIO | PIN_OUTPUT_LOW, /* CABCEN1 */ /* CABC off */
	GPIO156_GPIO | PIN_OUTPUT_LOW, /* CABCEN0 */
	
	/* L/R=1 U/D=0 left to right top to bottom */
	GPIO157_GPIO | PIN_OUTPUT_HIGH, /* LR */
	GPIO158_GPIO | PIN_OUTPUT_LOW, /* UD */
	GPIO156_GPIO | PIN_OUTPUT_LOW, /* UD */
	GPIO168_GPIO | PIN_OUTPUT_LOW, /* UD */
	GPIO218_GPIO | PIN_OUTPUT_LOW, /* UD */
	GPIO157_GPIO | PIN_OUTPUT_HIGH, /* LR */
	GPIO167_GPIO | PIN_OUTPUT_LOW, /* PWR_EN1 VCC_3V3 */
	
#endif
};

/*
 * GPIO pin config for HREF+ U8520 board.
 * Contains additional settings to common mop500 settings above.
 */
pin_cfg_t gpio_cfg_u8520[] = {
       /* SDMMC */
        GPIO78_GPIO     | PIN_OUTPUT_LOW,       /* SDMMC_Enable */
        GPIO5_GPIO      | PIN_OUTPUT_LOW,       /* SDMMC_1V8_3V_SEL */
        GPIO95_GPIO     | PIN_INPUT_PULLUP,     /* SDMMC_CD */

        /* Display Interface */
        GPIO65_GPIO     | PIN_OUTPUT_LOW,       /* DISP1 RST */
        GPIO66_GPIO     | PIN_OUTPUT_LOW,       /* DISP2 RST */
};

/*
 * GPIO pin config for 9540 CCU board.
 * Contains additional settings to common mop500 settings above.
 */
pin_cfg_t gpio_cfg_ccu9540[] = {
       /* SDMMC */
        GPIO21_GPIO     | PIN_OUTPUT_LOW,       /* SDMMC_Enable */
        GPIO20_GPIO     | PIN_OUTPUT_LOW,       /* SDMMC_1V8_3V_SEL */
        GPIO230_GPIO    | PIN_INPUT_PULLUP,     /* SDMMC_CD */

        /* Display Interface */
        GPIO65_GPIO     | PIN_OUTPUT_LOW,       /* DISP1 RST */
        GPIO66_GPIO     | PIN_OUTPUT_LOW,       /* DISP2 RST */
};

#define BOARD_ID_MOP500		0
#define BOARD_ID_HREF		1
#define BOARD_ID_HREFV60	2
#define BOARD_ID_8520		3
#define BOARD_ID_9540		4
int board_id;	/* set in probe_href() */

int errno;

#ifdef CONFIG_VIDEO_LOGO
static int mcde_error = -EINVAL;
#endif

/* Defined in cmd_recovery */
extern int check_for_recovery_condition (void);

/*
 * Flag to indicate from where to where we have to copy the initialised data.
 * In case we were loaded, its value is -1 and .data must be saved for an
 * eventual restart. It is 1 if .data was restored, i.e. we were restarted,
 * e.g. by kexec.
 */
static volatile int data_init_flag = -1; /* -1 to get it into .data section */

/* Get hold of gd pointer */
DECLARE_GLOBAL_DATA_PTR;

int restarted(void)
{
	return data_init_flag > 0;
}

#if defined(CONFIG_SHOW_BOOT_PROGRESS)
void show_boot_progress(int progress)
{
    printf("Boot reached stage %d\n", progress);
}
#endif

void db8500_apmux_uart_ulpi(void)
{
        // mux UART on ULPI-UART.
        db8500_gpio_config_pins(gpio_cfg_uart_ulpi, ARRAY_SIZE(gpio_cfg_uart_ulpi));
}
void db8500_apmux_usb_ulpi(void)
{
        // mux UART on ULPI-UART.
        db8500_gpio_config_pins(gpio_cfg_usb_ulpi, ARRAY_SIZE(gpio_cfg_usb_ulpi));
}


void ux500_mux_usb_ulpi(void)
{
        int ret;

        ret = ab8500_read(0x0B, 0xA3);
        if (ret < 0)
                return;
        if ((ret & 4) == 0)
                return;

        ab8500_write(0x0B, 0xA3, ret & 0xFB);           // ULPI mode back.
        ab8500_write(0x05, 0x8A, 0); // USB PHY off
        udelay(50000);
        db8500_gpio_config_pins(gpio_cfg_usb_ulpi, ARRAY_SIZE(gpio_cfg_usb_ulpi));
}

#ifdef CONFIG_BOOT_MENU

static const char *menu_items[] = {
	"| 0.Normal boot |",
	"| 1.Recovery    |",
	"| 2.Power off   |",
};

#define PRESS_KEY_TIME_SHORT 2
#define PRESS_KEY_TIME_LONG 5

#define MAX_MENU_ITEMS_NUM 3

/* define gpio key states */
#define RELEASED 	0
#define PRESSING 	1
#define PRESSED 	2
#define RELEASING 	3

#define DEBAUNCE 20

static int handle_keys_events(void)
{
	unsigned int down0, up0;
	unsigned int down1, up1;
	unsigned char state0 = RELEASED;
	unsigned char state1 = RELEASED;
	down0 = up0 = 0;
	down1 = up1 = 0;

	unsigned int pressed0 = 0;
	unsigned int pressed1 = 0;
	int pos = 0;
	int ret = -1;
	int power_flag = 0;
	int duration;
	int pre_val = -1;
	block_dev_desc_t * dev_desc;

	lcd_setfgcolor(CONSOLE_COLOR_RED);
	lcd_setbgcolor(CONSOLE_COLOR_GREEN);
	lcd_puts("\nBambook Phone\n\n");
	lcd_puts("Press volume +/- key to switch items\n");
	lcd_puts("Long press power key to select\n\n");

	lcd_puts("+--- Modes -----+\n");

	int start_row = console_row;
	debug("start_row: %d\n", start_row);
	lcd_setfgcolor(CONSOLE_COLOR_GREEN);
	lcd_setbgcolor(CONSOLE_COLOR_RED);
	lcd_puts("| 0.Normal boot |\n");

	lcd_setfgcolor(CONSOLE_COLOR_RED);
	lcd_setbgcolor(CONSOLE_COLOR_GREEN);
	lcd_puts("| 1.Recovery    |\n");
	lcd_puts("| 2.Power off   |\n");
	lcd_puts("+---------------+\n");
	mcde_splash_txt();
	int end_row = console_row;
	debug("end_row: %d\n", console_row);

	while(1) {
		mdelay(5);
		ret = detect_lunch_key();
		/////// volume up ///////
		switch(state0) {
			/*no press or released*/
			case RELEASED:
				down0 = up0 = 0;
				if (ret == VOLUME_UP_PRESS) {
					state0 = PRESSING;
				}
				break;

			/*now,pressing on*/
			case PRESSING:
				if (ret == VOLUME_UP_PRESS) {
					/*continue press*/
					if (down0++ == PRESS_KEY_TIME_SHORT) {
						state0 = PRESSED;
						pressed0++;
						printf("volume up PRESSED! <%d>\n", pressed0);

						/*volume up key pressed,selcet the mode*/
						if (pos >= 1){
							printf("===== up key (%d) =====\n", pressed0);
							console_row = start_row + pos;
							debug("pos: %d\n", pos);
							debug("0. console_row: %d\n", console_row);
							lcd_setfgcolor(CONSOLE_COLOR_RED);
							lcd_setbgcolor(CONSOLE_COLOR_GREEN);
							lcd_puts(menu_items[pos]);
							lcd_puts("\n");
							debug("1. console_row: %d\n", console_row);
							lcd_setfgcolor(CONSOLE_COLOR_GREEN);
							lcd_setbgcolor(CONSOLE_COLOR_RED);
							console_row = start_row + pos % MAX_MENU_ITEMS_NUM - 1;
							lcd_puts(menu_items[pos % MAX_MENU_ITEMS_NUM - 1]);
							lcd_puts("\n");
							mcde_splash_txt();
							debug("2. console_row: %d\n", console_row);
							pos--;
							printf("pos: %d\n", pos);
						}
					}
				} else
					/*press time short,ignore!*/
					state0 = RELEASED;
				break;

			case PRESSED:
				if (ret != VOLUME_UP_PRESS) {
					state0 = RELEASING;
				}
				break;
			case RELEASING:
				if (ret != VOLUME_UP_PRESS) {
					if (up0++ == PRESS_KEY_TIME_LONG) {
						state0 = RELEASED;
					}
				}
				break;
		}//	end switch(state0)

		/////// volume down ///////
		switch(state1) {
			/*no press or released*/
			case RELEASED:
				down1 = up1 = 0;
				if (ret == VOLUME_DOWN_PRESS) {
					state1 = PRESSING;
				}
				break;

			/*now,pressing on*/
			case PRESSING:
				if (ret == VOLUME_DOWN_PRESS) {
					/*continue press*/
					if (down1++ == PRESS_KEY_TIME_SHORT) {
						state1 = PRESSED;
						pressed1++;
						printf("volume down PRESSED! <%d>\n", pressed1);

						/*volume down key pressed,selcet the mode*/
						if (pos <= 1) {
							printf("===== down key (%d) =====\n", pressed1);
							console_row = start_row + pos;
							debug("pos: %d\n", pos);
							debug("0. console_row: %d\n", console_row);
							lcd_setfgcolor(CONSOLE_COLOR_RED);
							lcd_setbgcolor(CONSOLE_COLOR_GREEN);
							lcd_puts(menu_items[pos]);
							lcd_puts("\n");
							debug("1. console_row: %d\n", console_row);
							lcd_setfgcolor(CONSOLE_COLOR_GREEN);
							lcd_setbgcolor(CONSOLE_COLOR_RED);
							console_row = start_row + pos % MAX_MENU_ITEMS_NUM + 1;
							lcd_puts(menu_items[pos % MAX_MENU_ITEMS_NUM + 1]);
							lcd_puts("\n");
							mcde_splash_txt();
							debug("2. console_row: %d\n", console_row);
							pos++;
							printf("pos: %d\n", pos);
						}
					}
				} else
					/*press time short,ignore!*/
					state1 = RELEASED;
				break;

			case PRESSED:
				if (ret != VOLUME_DOWN_PRESS) {
					state1 = RELEASING;
				}
				break;
			case RELEASING:
				if (ret != VOLUME_DOWN_PRESS) {
					if (up1++ == PRESS_KEY_TIME_LONG) {
						state1 = RELEASED;
					}
				}
				break;
		}//	end switch(state1)


		power_flag = 0;
		duration = ab8500_read(AB8500_SYS_CTRL1_BLOCK,AB8500_PONKEY1_PRESS_STAT_REG);
		if (duration != pre_val && duration > 3 && duration < 10 && pre_val > 0) {
			printf("\n power on key detected!!!\n");
			power_flag = 1;
		}
		pre_val = duration;

		/* detect power key,enter the mode*/
		if (power_flag == 1)
		{
			console_row = end_row;
			printf("power key PRESSED!!\n");
			switch (pos) {
				case 0:
					lcd_puts("    Now enter normal boot mode, please wait...\n");
					mcde_splash_txt();
					goto out;
				case 1:
					{
						/*always emmc 0 here*/
						dev_desc = get_dev("mmc", 0);
						if(dev_desc == NULL) {
							lcd_puts("    RECOVERY:ERROR -- Invalid Device!\n");
							mcde_splash_txt();
							return 1;
						}
						lcd_puts("    Now enter recovery mode, please wait...\n");
						mcde_splash_txt();
						setenv("bootcmd", CONFIG_RECOVERY_BOOTCOMMAND);
						ret = android_bcb_boot(dev_desc, BCB_RECOVERY_MISC_ERASE);
					}
					goto out;
				case 2:
					lcd_puts("    Now power off your system, please wait...\n");
					mcde_splash_txt();
					{
						ab8500_write(AB8500_SYS_CTRL1_BLOCK, AB8500_CTRL1_REG,0x3);
					}
					break;
				default:
					break;
			}
		}//end power key detect
	}//end while(1)
out:
	return 0;
}
#endif

/*
 * Miscellaneous platform dependent initialisations
 */

#define BOOT_INFO_BACKUPRAM1                    0x80150000 + 0x1f7c
#define BOARD_VERSION_MASK			0xffff
#define BOARD_FAMILY_MASK			0xff00
#define BOARD_FAMILY_8520              	0x2000

int board_init(void)
{
	extern char _idata_start[];
	extern char _data_start[];
	extern char _data_end[];
	unsigned long data_len;

	data_len = _data_end - _data_start;
	if (++data_init_flag == 0) {
		/*
		 * first init after reset/loading
		 * save .data section for restart
		 */
		memcpy(_idata_start, _data_start, data_len);
	} else {
		/*
		 * restart, e.g. by kexec
		 * copy back .data section
		 */
		memcpy(_data_start, _idata_start, data_len);
		/* memcpy set data_init_flag back to zero */
		++data_init_flag;
	}

	/*
	 * Setup board (bd) and board-info (bi).
	 * bi_arch_number: Unique id for this board. It will passed in r1 to
	 *    Linux startup code and is the machine_id.
	 * bi_boot_params: Where this board expects params.
	 */
	if (cpu_is_a9500_generic()) {
		gd->bd->bi_arch_number = MACH_TYPE_A9500;
	} else if (cpu_is_u9540v10()) {
		gd->bd->bi_arch_number = MACH_TYPE_U9540;
	} else {
		/* check board profile in backup ram */
		u32 *boot_info = (u32 *) (BOOT_INFO_BACKUPRAM1);

		if ((*boot_info & BOARD_FAMILY_MASK) == BOARD_FAMILY_8520) {
			gd->bd->bi_arch_number = MACH_TYPE_U8520;
		} else
			gd->bd->bi_arch_number = MACH_TYPE_U8500;
	}

	gd->bd->bi_boot_params = 0x00000100;
#ifdef CONFIG_LCD
	gd->fb_base = CONFIG_SYS_VIDEO_FB_ADRS;
#endif
	/* Configure GPIO pins needed by U-boot */
	db8500_gpio_config_pins(gpio_cfg_common, ARRAY_SIZE(gpio_cfg_common));

	return 0;
}

int dram_init(void)
{
	uint32_t unused_cols_rows_96;
	uint32_t unused_cols_rows_97;
	unsigned int nrows_cs0;
	unsigned int nrows_cs1;
	unsigned int ncols_cs0;
	unsigned int ncols_cs1;
	unsigned int size_cs0;
	unsigned int size_cs1;


	gd->bd->bi_dram[0].start = 0;
	if (u8500_is_earlydrop()) {
		gd->bd->bi_dram[0].size = 0x10000000;	/* 256 MiB */
		return 0;
	}

	/*
	 * Assumption: 2 CS active.
	 *             15 rows max, 11 cols max (controller spec).
	 *             memory chip has 8 banks, I/O width 32 bit.
	 * The correct way would be to read MR#8: I/O width and density,
	 * but this requires locking against the PRCMU firmware.
	 * Simplified approach:
	 * Read number of unused rows and columns from mem controller.
	 * size = 2^(rows+cols) x nbanks x buswidth_bytes
	 */
	unused_cols_rows_96 = readl(DMC_CTL_96);
	unused_cols_rows_97 = readl(DMC_CTL_97);
	nrows_cs0 = 15 - ((unused_cols_rows_96 & 0x07000000) >> 24);
	nrows_cs1 = 15 - (unused_cols_rows_97 & 0x07);
	ncols_cs0 = 11 - ((unused_cols_rows_97 & 0x0700) >> 8);
	ncols_cs1 = 11 - ((unused_cols_rows_97 & 0x070000) >> 16);
	size_cs0 = (1 << (nrows_cs0 + ncols_cs0)) * 8 * 4;
	size_cs1 = (1 << (nrows_cs1 + ncols_cs1)) * 8 * 4;
	gd->bd->bi_dram[0].size = size_cs0 + size_cs1;

	if (!cpu_is_u9540v10())
		return 0;

	/* U9540 has two DDR controllers, just repeat the sequence */
	unused_cols_rows_96 = readl(DMC1_CTL_96);
	unused_cols_rows_97 = readl(DMC1_CTL_97);
	nrows_cs0 = 15 - ((unused_cols_rows_96 & 0x07000000) >> 24);
	nrows_cs1 = 15 - (unused_cols_rows_97 & 0x07);
	ncols_cs0 = 11 - ((unused_cols_rows_97 & 0x0700) >> 8);
	ncols_cs1 = 11 - ((unused_cols_rows_97 & 0x070000) >> 16);
	size_cs0 = (1 << (nrows_cs0 + ncols_cs0)) * 8 * 4;
	size_cs1 = (1 << (nrows_cs1 + ncols_cs1)) * 8 * 4;
	gd->bd->bi_dram[0].size += size_cs0 + size_cs1;

	return 0;
}

#ifdef CONFIG_GENERIC_MMC
static u64 emmc_capacity;
/*
 * board_mmc_init - initialize all the mmc/sd host controllers.
 * Called by generic mmc framework.
 */
int board_mmc_init(bd_t *bis)
{
	int error;
	struct mmc *dev;

	debug("mmc_host - board_mmc_init\n");

	(void) bis;  /* Parameter not used! */

	dev = u8500_alloc_mmc_struct();
	if (!dev)
		return -1;

	/* PoPed eMMC */
	error = u8500_emmc_host_init(dev,
			(struct sdi_registers *)U8500_SDI2_BASE);
	if (error) {
		printf("emmc_host_init() %d \n", error);
		return -1;
	}
	/*
	 * It is necessary to register before mmc_init(), since it calls
	 * the block_dev read function after successful card initialisation.
	 */
	mmc_register(dev);
	debug("registered emmc interface number is:%d\n", dev->block_dev.dev);

	error = mmc_init(dev);
	if (error) {
		/*
		 * Might be a configuration without PoPed eMMC.
		 * Try on-board eMMC (SDI4).
		 */
		(void) u8500_emmc_host_init(dev,
				(struct sdi_registers *)U8500_SDI4_BASE);
		/*
		 * Do not register again, since we want the eMMC always on
		 * dev#0. There is no unregister.
		 */
		error = mmc_init(dev);
		if (!error)
			printf("Using on-board eMMC (SDI4).\n");
	}

	emmc_capacity = dev->capacity;
	/*
	 * In a perfect world board_early_access shouldn't be here but we want
	 * some functionality to be loaded as quickly as possible and putting it
	 * here will get the shortest time to start that functionality. Time
	 * saved by putting it here compared to later is somewhere between
	 * 0.3-0.7s. That is enough to be able to justify putting it here.
	 */

	/*
	 * Since we are interrupting the 'generic' MMC device printouts,
	 * we reformat a bit due to the early access code
	 */
	printf("\n");
	board_early_access(&dev->block_dev);
	printf("  ");

	dev = u8500_alloc_mmc_struct();
	if (!dev)
		return -1;

#ifdef CONFIG_MMC_DEV_NUM
	/* MMC/SD card */
	error = u8500_mmc_host_init(dev,
			(struct sdi_registers *)U8500_SDI0_BASE);
	if (error) {
		printf("mmc_host_init() %d \n", error);
		return -1;
	}
	mmc_register(dev);
	debug("registered mmc/sd interface number is:%d\n", dev->block_dev.dev);
#endif
	return 0;
}
#endif /* CONFIG_GENERIC_MMC */

#ifdef CONFIG_VIDEO_LOGO

#if CONFIG_SYS_DISPLAY_DSI
#if !defined(BOARD_C7_P0)
static int mcde_display_reset_gpioe(void)
{
	int ret;

	/* Only main display should be initialized */
	ret = tc35892_gpio_dir(CONFIG_SYS_I2C_GPIOE_ADDR,
				TC35892_PIN_KPY7, 1);
	if (ret) {
		printf("%s:Could not set direction for gpio\n", __func__);
		return -EINVAL;
	}
	ret = tc35892_gpio_set(CONFIG_SYS_I2C_GPIOE_ADDR,
				TC35892_PIN_KPY7, 0);
	if (ret) {
		printf("%s:Could reset gpio\n", __func__);
		return -EINVAL;
	}
	mdelay(main_display_data.reset_delay);
	ret = tc35892_gpio_set(CONFIG_SYS_I2C_GPIOE_ADDR,
				TC35892_PIN_KPY7, 1);
	if (ret) {
		printf("%s:Could set gpio\n", __func__);
		return -EINVAL;
	}
	mdelay(main_display_data.reset_delay);

	return ret;
}
#endif
/*
 * Reset the primary display - called from mcde driver.
 */
int board_mcde_display_reset(void)
{
	int ret = 0;
#if !defined(BOARD_C7_P0)
	if (board_id >= BOARD_ID_HREFV60) {
#if defined(CONFIG_VIA_DISPLAY_DPI)||defined(CONFIG_VIA_DISPLAY_DSI)
        db8500_gpio_set_output(GPIO139_GPIO, 1);
        mdelay(100);
		db8500_gpio_set_output(GPIO139_GPIO, 0); /* DISP1 reset */
		mdelay(100);
		mdelay(main_display_data.reset_delay);
		db8500_gpio_set_output(GPIO139_GPIO, 1);
		mdelay(200);
#else
		db8500_gpio_set_output(GPIO65_GPIO, 0); /* DISP1 reset */
		mdelay(main_display_data.reset_delay);
		db8500_gpio_set_output(GPIO65_GPIO, 1);
#endif	
		mdelay(main_display_data.reset_delay);
	} else
		ret = mcde_display_reset_gpioe();
#else

    printf("tc358764 power on\n");
	db8500_gpio_set_output(GPIO159_GPIO, 1); /* power on the tc358764 chip */
	mdelay(1);
	printf("tc358764 reset\n");
	db8500_gpio_set_output(GPIO95_GPIO, 0);  /* reset enable the tc358764 chip */
	mdelay(1);	
	db8500_gpio_set_output(GPIO95_GPIO, 1);  /* reset disable the tc358764 chip */
	mdelay(1);
#endif
	return ret;
}
#endif /* CONFIG_SYS_DISPLAY_DSI */

static int dss_init(void)
{
	puts("  MCDE:  ");

	boottime_tag("splash");

	if (!cpu_is_u8500v11() && !cpu_is_u8500v2()) {
		printf("Only HREF+ or V2 is supported\n");
		goto mcde_error;
	}
	if (mcde_splash_image()) {
		printf("startup failed\n");
		goto mcde_error;
	}

	printf("ready\n");
	return 0;

mcde_error:
	return -EINVAL;

}
#endif

/*
 * probe_href - set board_id according to HREF version
 *
 * side-effect: configures additional GPIO pins if necessary.
 */
static void probe_href(void)
{
	uchar byte;

	/*
	 * Determine and set board_id
	 * 0: mop500, 1: href500, 2: href500 2.0 V60 or later
	 * Above boards have different GPIO expander chips which we can
	 * distinguish by the chip id.
	 * HREF+ 2.0 V60 and later have no GPIOE.
	 *
	 */

	if (gd->bd->bi_arch_number == MACH_TYPE_U8500 ||
	    gd->bd->bi_arch_number == MACH_TYPE_A9500) {
		(void) i2c_set_bus_num(0);
		if (!i2c_read(CONFIG_SYS_I2C_GPIOE_ADDR, 0x80, 1, &byte, 1)) {
			if (byte == 0x01)
				board_id = BOARD_ID_MOP500;
			else
				board_id = BOARD_ID_HREF;
		}
		else {
			/* No GPIOE => HREF+ 2.0 V60 or later */
			if (gd->bd->bi_arch_number == MACH_TYPE_U8500) {
				gd->bd->bi_arch_number = MACH_TYPE_HREFV60;
			}
		}
	}

	if (gd->bd->bi_arch_number == MACH_TYPE_HREFV60||
	    gd->bd->bi_arch_number == MACH_TYPE_A9500) {
		db8500_gpio_config_pins(gpio_cfg_hrefv60,
					ARRAY_SIZE(gpio_cfg_hrefv60));
		board_id = BOARD_ID_HREFV60;
	}

	if (gd->bd->bi_arch_number == MACH_TYPE_U8520) {
		db8500_gpio_config_pins(gpio_cfg_u8520,
					ARRAY_SIZE(gpio_cfg_u8520));
		board_id = BOARD_ID_8520;
	}

	if (gd->bd->bi_arch_number == MACH_TYPE_U9540) {
		db8500_gpio_config_pins(gpio_cfg_ccu9540,
					ARRAY_SIZE(gpio_cfg_ccu9540));
		board_id = BOARD_ID_9540;
	}
}

void detect_ponkey_press(void)
{
	int duration, ret, ret1;
	int pre_val = -1;

    ret1 = readl(PRCM_RESET_STATUS);
    printf("PRCM_RESET_STATUS = : 0x%x\n", ret1);

	ret = ab8500_read(AB8500_SYS_CTRL1_BLOCK, AB8500_TURNON_STAT_REG);
	printf("turn status: 0x%x\n", ret);
	if (!(ret & 0x2) || !(ret1 & 0x20))
		return;

	do {
		duration = ab8500_read(AB8500_SYS_CTRL1_BLOCK,
			AB8500_PONKEY1_PRESS_STAT_REG);
		if (duration == pre_val) { 
			puts("shutdown");
			ab8500_write(AB8500_SYS_CTRL1_BLOCK, AB8500_CTRL1_REG,0x3);
		}
		pre_val = duration;
		mdelay(150);
	} while (duration < 8);	//if power key presse time < 1s, loop

	return;
}

#define BATT_OK_SEL1_TH_F_MASK		0xF0
#define BATT_OK_SEL1_TH_F_2V71		0x70

/*
 * board_early_access - for functionality that needs to run before
 * board_late_init but after board_init and emmc init.
 */
int board_early_access(block_dev_desc_t *block_dev)
{
	int ret;
	int battok_regval;
	unsigned long prcmu_reset_status_reg;

	/* set board_id according to HREF version */
	probe_href();

	/*
	 * In AB8500 rev2.0, the cut-off voltage threshold is set too low
	 * and the AB will power-off when we start with a drained battery
	 * and a charger connected when the backlight is turned on.
	 * Here we will lower the cut-off voltage threshold before
	 * power consumption goes up
	 */
	ret = ab8500_read(AB8500_SYS_CTRL2_BLOCK, AB8500_BATT_OK_REG);
	if (ret < 0)
		return -EINVAL;

	battok_regval = ret;

	/* Mask and set BattOkSel1ThF */
	ret = ab8500_write(AB8500_SYS_CTRL2_BLOCK, AB8500_BATT_OK_REG,
		(battok_regval & ~BATT_OK_SEL1_TH_F_MASK) |
		BATT_OK_SEL1_TH_F_2V71);
	if (ret < 0)
		return -EINVAL;

	/*
	 * Don't load itp, modem and splash if restarted (eg crashdump).
	 */
	prcmu_reset_status_reg = readl(PRCM_RESET_STATUS);
	if (!(restarted() ||
	      (prcmu_reset_status_reg & PRCM_A9_CPU_WATCHDOG_RESET) ||
	      (prcmu_crashed()))) {

#ifdef CONFIG_ITP_LOAD
		if (!cpu_is_a9500_generic())
			itp_read_config(block_dev);
#endif

#ifdef CONFIG_VIDEO_LOGO
		/* only load splash if not itp */
#ifdef CONFIG_ITP_LOAD
		if (!cpu_is_u9540v10()) {
			if (!itp_is_itp_in_config() ||
					cpu_is_a9500_generic())
				mcde_error = dss_init();
		}
#else
		mcde_error = dss_init();
#endif
#endif

#ifdef CONFIG_ITP_LOAD
		if (!cpu_is_u9540v10()) {
			if (!cpu_is_a9500_generic() &&
					itp_load_itp_and_modem(block_dev))
				return 1;
		}
#endif
	}
	return 0;
}

#ifdef BOARD_LATE_INIT
#ifdef CONFIG_MMC

#define LDO_VAUX3_ENABLE_MASK		0x3
#define LDO_VAUX3_ENABLE_VAL		0x1
#define LDO_VAUX3_SEL_MASK		0xf
#define LDO_VAUX3_SEL_2V9		0xd
#define LDO_VAUX3_V2_SEL_MASK		0x7
#define LDO_VAUX3_V2_SEL_2V91		0x7

static int hrefplus_mmc_power_init(void)
{
	int ret;
	int voltage_regval;
	int enable_regval;
	int ab8500_revision;

	if (!cpu_is_u8500v11() && !cpu_is_u8500v2() && !cpu_is_u9540v10())
		return 0;

	/* Get AB8500 revision */
	ret = ab8500_read(AB8500_MISC, AB8500_REV_REG);
	if (ret < 0)
		goto out;

	ab8500_revision = ret;

	/*
	 * On v1.1 HREF boards (HREF+) and v2 boards, Vaux3 needs to be
	 * enabled for the SD card to work.  This is done by enabling
	 * the regulators in the AB8500 via PRCMU I2C transactions.
	 *
	 * This code is derived from the handling of AB8500_LDO_VAUX3 in
	 * ab8500_ldo_enable() and ab8500_ldo_disable() in Linux.
	 *
	 * Turn off and delay is required to have it work across soft reboots.
	 */

	/* Turn off (read-modify-write) */
	ret = ab8500_read(AB8500_REGU_CTRL2, AB8500_REGU_VRF1VAUX3_REGU_REG);
	if (ret < 0)
		goto out;

	enable_regval = ret;

	ret = ab8500_write(AB8500_REGU_CTRL2, AB8500_REGU_VRF1VAUX3_REGU_REG,
		enable_regval & ~LDO_VAUX3_ENABLE_MASK);
	if (ret < 0)
		goto out;

	/* Delay */
	udelay(10 * 1000);

	/* Set the voltage to 2.91 V or 2.9 V without overriding VRF1 value */
	ret = ab8500_read(AB8500_REGU_CTRL2, AB8500_REGU_VRF1VAUX3_SEL_REG);
	if (ret < 0)
		goto out;

	voltage_regval = ret;

	if (ab8500_revision < 0x20 && !cpu_is_u9540v10()) {
		voltage_regval &= ~LDO_VAUX3_SEL_MASK;
		voltage_regval |= LDO_VAUX3_SEL_2V9;
	} else {
		voltage_regval &= ~LDO_VAUX3_V2_SEL_MASK;
		voltage_regval |= LDO_VAUX3_V2_SEL_2V91;
	}

	ret = ab8500_write(AB8500_REGU_CTRL2, AB8500_REGU_VRF1VAUX3_SEL_REG,
		voltage_regval);
	if (ret < 0)
		goto out;

	/* Turn on the supply */
	enable_regval &= ~LDO_VAUX3_ENABLE_MASK;
	enable_regval |= LDO_VAUX3_ENABLE_VAL;

	ret = ab8500_write(AB8500_REGU_CTRL2, AB8500_REGU_VRF1VAUX3_REGU_REG,
		enable_regval);

out:
	return ret;
}
#endif /* CONFIG_MMC */

/*
 * Set the androidboot.serialno. USB is froming the serial number by
 * reading contents of Backup Ram (PUBLIC_ID_BACKUPRAM1). Exactly
 * same mechanism is used here.
 *
 */
#define UBOOT_PUBLIC_ID_BACKUPRAM1		(0x80150000 + 0x01000 + 0x0FC0)
#define UBOOT_MAX_USB_SERIAL_NUMBER_LEN 31

static void db8500_set_androidboot_serialnum(void)
{
	u32 bufer[4], len;
	char buf[UBOOT_MAX_USB_SERIAL_NUMBER_LEN + 10];
	char *env_ptr = NULL;
	char *arg_str = NULL;
	char def_arg_str[] = "setenv bootargs ${bootargs}";
	u32 *backup_ram = (u32 *) (UBOOT_PUBLIC_ID_BACKUPRAM1);

	if (backup_ram) {
		bufer[0] = backup_ram[0];
		bufer[1] = backup_ram[1];
		bufer[2] = backup_ram[2];
		bufer[3] = backup_ram[3];

		/* Form the serial number */
		sprintf(buf, "%.8X%.8X%.8X%.8X",
				bufer[0], bufer[1], bufer[2],
				bufer[3]);

	} else
		return;

	/* Append the Serial number to the boot arguments */
	env_ptr = getenv("extraargs");

	if (env_ptr == NULL) {
		/* extraargs is not defined. Define it */
		env_ptr = def_arg_str;
	}

	len = UBOOT_MAX_USB_SERIAL_NUMBER_LEN + strlen(env_ptr)
		+ strlen(" androidboot.serialno=") + 1;

	arg_str = (char *) malloc(len);

	if (arg_str) {
		sprintf(arg_str, "%s androidboot.serialno=", env_ptr);
	} else {
		printf("WARN: maloc failled.\n");
		return;
	}

	strncat(arg_str, buf, UBOOT_MAX_USB_SERIAL_NUMBER_LEN);
	setenv("extraargs", arg_str);
	free(arg_str);

	return;
}

/*
 * Called after all initialisation was done.
 */
int board_late_init(void)
{
#ifdef CONFIG_MMC
	uchar byte;
	uchar byte_array[] = {0x02, 0x02};
#endif
	char strbuf[80];
	unsigned long prcmu_reset_status_reg;

	/*
	 * The board_id environment variable is needed for the Linux bootargs.
	 */
	if (board_id == 0)
		setenv("board_id", "0");
	else
		setenv("board_id", "1");

#ifdef CONFIG_MMC
	hrefplus_mmc_power_init();

	/*
	 * config extended GPIO pins for level shifter and
	 * SDMMC_ENABLE
	 */
	if (board_id == 0) {
		/* MOP500 */
		byte = 0x0c;
		(void) i2c_write(CONFIG_SYS_I2C_GPIOE_ADDR, 0x89, 1, &byte, 1);
		(void) i2c_write(CONFIG_SYS_I2C_GPIOE_ADDR, 0x83, 1, &byte, 1);
	} else if (board_id == 1) {
		/* HREF < V60 */
		/* set the direction of GPIO KPY9 and KPY10 */
		byte = 0x06;
		(void) i2c_write(CONFIG_SYS_I2C_GPIOE_ADDR, 0xC8, 1, &byte, 1);
		/* must be a multibyte access */
		(void) i2c_write(CONFIG_SYS_I2C_GPIOE_ADDR, 0xC4, 1,
						&byte_array[0], 2);
	} else if (board_id == BOARD_ID_9540) {
		db8500_gpio_set_output(GPIO21_GPIO, 1);
	} else {
		/* HREF V60 and later */
		/* enable SDMMC */
		if (board_id == BOARD_ID_8520)
			db8500_gpio_set_output(GPIO78_GPIO, 1);
		else
			db8500_gpio_set_output(GPIO169_GPIO, 1);
	}
#endif /* CONFIG_MMC */

#ifdef CONFIG_VIDEO_LOGO
	if (mcde_error) {
		setenv("startup_graphics", "0");
		setenv("logo", "0");
	} else {
		setenv("startup_graphics", "1");
		setenv("logo", "nologo");
	}
#endif
	if (!getenv("memargs")) {
		/*
		 * Create a memargs variable which uses the memargs256,
		 * memargs512, memargs768,... environment variable, depending
		 * on the memory size. memargs is used to build the bootargs,
		 * memargs256, memargs512, memargs768,... are stored in the
		 * environment.
		 */
		if (gd->bd->bi_dram[0].size == 0x10000000) {
			setenv("memargs",
				"setenv bootargs ${bootargs} ${memargs256}");
			setenv("mem", "256M");
		} else if (gd->bd->bi_dram[0].size == 0x20000000) {
			setenv("memargs",
				"setenv bootargs ${bootargs} ${memargs512}");
			setenv("mem", "512M");
		} else if (gd->bd->bi_dram[0].size == 0x30000000) {
			setenv("memargs",
				"setenv bootargs ${bootargs} ${memargs768}");
			setenv("mem", "768M");
		} else if (gd->bd->bi_dram[0].size == 0x40000000) {
			setenv("memargs",
				"setenv bootargs ${bootargs} ${memargs1024}");
			setenv("mem", "1024M");
		} else if (gd->bd->bi_dram[0].size == 0x80000000) {
			setenv("memargs",
				"setenv bootargs ${bootargs} ${memargs2048}");
			setenv("mem", "2048M");
		} else {
			printf("INFO: No $memargsXXX exists for "
				"memory size %lu MB. Falling back to 512MB.\n",
				gd->bd->bi_dram[0].size / MBYTE);
			setenv("memargs",
				"setenv bootargs ${bootargs} ${memargs512}");
			setenv("mem", "512M");
		}
	}

#ifdef CONFIG_GENERIC_MMC
	u64 total_blk;
	char emmcpart7size[32];
	int emmcpart7offset;
	char *offset_env;

	offset_env = getenv("emmcpart7offset");
	if (offset_env != NULL && getenv("emmcargs")) {
		emmcpart7offset = (int)simple_strtoul(offset_env, NULL, 10);
		total_blk = emmc_capacity/512;
		sprintf(emmcpart7size, "%d", (int)(total_blk - emmcpart7offset));
		printf("\n EMMC Capacity:%lld, total_blk:%lld, emmcpart7offset:%d,emmcpart7size:%s.\n", \
				emmc_capacity,total_blk, emmcpart7offset, emmcpart7size);
		setenv("emmcpart7size", emmcpart7size);
	}
#endif

	/*init keypad*/
#ifndef CONFIG_VIA_KEYPAD
	keypad_init();
#endif

#ifdef CONFIG_BOOT_MENU
	/* when phone power-up, if volume up key pressed, enter menu mode */
	if (detect_lunch_key() == VOLUME_UP_PRESS)
	{
		mdelay(10);
		if(detect_lunch_key() == VOLUME_UP_PRESS)
		{
			printf("\nVolume + pressed, show phone menu.\n");
			handle_keys_events();
		}
		else
			printf("pressed time too short,ignore!!!\n");
	}
#endif

#ifdef CONFIG_RECOVERY_MODE
	run_command("recovery",0);
#endif

	db8500_set_androidboot_serialnum();

	/*
	 * Create crashkernel env dynamically since it depends on U-Boot start
	 * address. U-Boot itself is used for dumping.
	 * The 32K offset is hardcoded in the kexec-tools.
	 * Parsed by Linux setup.c:reserve_crashkernel() using
	 * lib/cmdline.c:memparse().
	 * crashkernel=ramsize-range:size[,...][@offset]
	 */
	sprintf(strbuf, "crashkernel=1M@0x%lx", _armboot_start - 0x8000);
	setenv("crashkernel", strbuf);

	/*
	 * Check for a crashdump, if data_init_flag > 0, i.e. we were
	 * restarted e.g. by kexec. Do not check for crashdump if we were just
	 * loaded from the x-loader.
	 */
	prcmu_reset_status_reg = readl(PRCM_RESET_STATUS);
	if (restarted() ||
	    (prcmu_reset_status_reg & (PRCM_A9_CPU_WATCHDOG_RESET)) ||
	    prcmu_crashed())
		setenv("preboot", "checkcrash");

	if (cpu_is_a9500_generic() || cpu_is_a9500v1()) {
		setenv ("pinsfor", "a9500");
	}

	/*
	 * On U9540 a CSPSA fast-parameter can indicate whether the modem
	 * should be booted in normal or ITP mode. This is passed into the
	 * kernel to be exported to userspace in order to be used by modem
	 * utilities.
	 */
	if (cpu_is_u9540v10()) {
		if (itp_is_modem_itp_in_config())
			setenv("modem_boot_type", "itp");
		else
			setenv("modem_boot_type", "normal");
	}

	return (0);
}

#endif /* BOARD_LATE_INIT */
