/*
 * Copyright (C) ST-Ericsson SA 2009
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#ifndef __ASM_ARCH_CLOCK
#define __ASM_ARCH_CLOCK

/* Enable all clocks u-boot needs in db8500 SoC platform */
void db8500_clocks_init(void);

/* Legacy function to allow drivers to enable their clock */
void u8500_clock_enable(int periph, int cluster, int kern);

/* Function to get the clock speed of ARM cpu */
u32 db8500_clock_cpu_khz(void);
u32 db9540_clock_cpu_khz(void);

#endif /* __ASM_ARCH_CLOCK */
