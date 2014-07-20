/*
 * Copyright (c) 2009, Google Inc.
 * All rights reserved.
 * Copyright (c) 2009-2011, Code Aurora Forum. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *  * Neither the name of Google, Inc. nor the names of its contributors
 *    may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include <debug.h>
#include <lib/ptable.h>
#include <smem.h>
#include <platform/iomap.h>
#include <mmc.h>
#include <platform/timer.h>
#include <reg.h>
#include <dev/keys.h>
#include <dev/pm8921.h>
#include <dev/ssbi.h>
#include <gsbi.h>
#include <target.h>
#include <platform.h>

#define LINUX_MACHTYPE_8960_SIM     3230
#define LINUX_MACHTYPE_8960_RUMI3   3231
#define LINUX_MACHTYPE_8960_CDP     3396
#define LINUX_MACHTYPE_8960_MTP     3397
#define LINUX_MACHTYPE_8960_FLUID   3398
#define LINUX_MACHTYPE_8960_APQ     3399
#define LINUX_MACHTYPE_8960_LIQUID  3535
#define LINUX_MACHTYPE_8930_CDP     3727
#define LINUX_MACHTYPE_8930_MTP     3728
#define LINUX_MACHTYPE_8930_FLUID   3729

extern void dmb(void);
extern void keypad_init(void);
extern void panel_backlight_on(void);

static unsigned mmc_sdc_base[] = { MSM_SDC1_BASE, MSM_SDC2_BASE, MSM_SDC3_BASE, MSM_SDC4_BASE};

static pm8921_dev_t pmic;

static const uint8_t uart_gsbi_id  = GSBI_ID_5;

void shutdown_device(void)
{
	dprintf(CRITICAL, "Shutdown system.\n");
	pm8921_config_reset_pwr_off(0);

	/* Actually reset the chip */
	writel(0, MSM_PSHOLD_CTL_SU);
	mdelay(5000);

	dprintf (CRITICAL, "Shutdown failed.\n");
}

void target_init(void)
{
	unsigned base_addr;
	unsigned char slot;
	dprintf(INFO, "target_init()\n");

	/* Initialize PMIC driver */
	pmic.read  = (pm8921_read_func) &pa1_ssbi2_read_bytes;
	pmic.write = (pm8921_write_func) &pa1_ssbi2_write_bytes;

	pm8921_init(&pmic);
	/* Keypad init */
	keys_init();
	keypad_init();

	/* Display splash screen if enabled */
#if DISPLAY_SPLASH_SCREEN
	panel_backlight_on();
	display_init();
	dprintf(SPEW, "Diplay initialized\n");
	display_image_on_screen();
#endif

	/* Trying Slot 1 first */
	slot = 1;
	base_addr = mmc_sdc_base[slot-1];
	if(mmc_boot_main(slot, base_addr))
	{
		/* Trying Slot 3 next */
		slot = 3;
		base_addr = mmc_sdc_base[slot-1];
		if(mmc_boot_main(slot, base_addr))
		{
			dprintf(CRITICAL, "mmc init failed!");
			ASSERT(0);
		}
	}
}

unsigned board_machtype(void)
{
	struct smem_board_info_v6 board_info_v6;
	unsigned int board_info_len = 0;
	unsigned smem_status = 0;
	unsigned format = 0;
	unsigned id = HW_PLATFORM_UNKNOWN;
	unsigned mach_id;


	smem_status = smem_read_alloc_entry_offset(SMEM_BOARD_INFO_LOCATION,
					&format, sizeof(format), 0);
	if(!smem_status)
	{
		if (format == 6)
		{
			board_info_len = sizeof(board_info_v6);

			smem_status = smem_read_alloc_entry(SMEM_BOARD_INFO_LOCATION,
							&board_info_v6, board_info_len);
			if(!smem_status)
			{
				id = board_info_v6.board_info_v3.hw_platform;
			}
		}
	}

	/* Detect the board we are running on */
	if (board_info_v6.board_info_v3.msm_id == MSM8960)
	{
		switch(id)
		{
			case HW_PLATFORM_SURF:
				mach_id = LINUX_MACHTYPE_8960_CDP;
				break;
			case HW_PLATFORM_MTP:
				mach_id = LINUX_MACHTYPE_8960_MTP;
				break;
			case HW_PLATFORM_FLUID:
				mach_id = LINUX_MACHTYPE_8960_FLUID;
				break;
			case HW_PLATFORM_LIQUID:
				mach_id = LINUX_MACHTYPE_8960_LIQUID;
				break;
			default:
				mach_id = LINUX_MACHTYPE_8960_CDP;
		}
	}
	else if (board_info_v6.board_info_v3.msm_id == MSM8930)
	{
		switch(id)
		{
			case HW_PLATFORM_SURF:
				mach_id = LINUX_MACHTYPE_8930_CDP;
				break;
			case HW_PLATFORM_MTP:
				mach_id = LINUX_MACHTYPE_8930_MTP;
				break;
			case HW_PLATFORM_FLUID:
				mach_id = LINUX_MACHTYPE_8930_FLUID;
				break;
			default:
				mach_id = LINUX_MACHTYPE_8930_CDP;
		}
	}

	return mach_id;
}

void reboot_device(unsigned reboot_reason)
{
	/* Actually reset the chip */
	pm8921_config_reset_pwr_off(1);
	writel(0, MSM_PSHOLD_CTL_SU);
	mdelay(10000);

	dprintf (CRITICAL, "Rebooting failed\n");
	return;
}

unsigned check_reboot_mode(void)
{
	unsigned restart_reason = 0;

	/* Read reboot reason and scrub it */
	restart_reason = readl(RESTART_REASON_ADDR);
	writel(0x00, RESTART_REASON_ADDR);

	return restart_reason;
}

void target_serialno(unsigned char *buf)
{
	unsigned int serialno;
	if(target_is_emmc_boot())
	{
		serialno =  mmc_get_psn();
		sprintf((char *) buf,"%x",serialno);
	}
}

void target_battery_charging_enable(unsigned enable, unsigned disconnect)
{
}

/* Do any target specific intialization needed before entering fastboot mode */
void target_fastboot_init(void)
{
	/* Set the BOOT_DONE flag in PM8921 */
	pm8921_boot_done();
}

uint8_t target_uart_gsbi(void)
{
	return uart_gsbi_id;
}
