/* linux/drivers/hwmon/lis33de.c
 *
 * (C) Copyright 2008 
 * MediaTek <www.mediatek.com>
 *
 * HSPPAD030 driver for MT6582
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */
#ifndef HSPPAD030_H
#define HSPPAD030_H 
	 
#include <linux/ioctl.h>

#define HSPPAD030_I2C_SLAVE_ADDR		0x48
	 
#define TRUE 1
#define FALSE 0

#define HSPPAD030_SUCCESS						0
#define HSPPAD030_ERR_I2C						-1
#define HSPPAD030_ERR_STATUS					-3
#define HSPPAD030_ERR_SETUP_FAILURE				-4
#define HSPPAD030_ERR_GETGSENSORDATA			-5
#define HSPPAD030_ERR_IDENTIFICATION			-6
	 
#define HSPPAD030_BUFSIZE				3
	 
#endif

