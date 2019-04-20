/* linux/drivers/hwmon/lis33de.c
 *
 * (C) Copyright 2008 
 * MediaTek <www.mediatek.com>
 *
 * HSHCAL002 driver for MT6582
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
#ifndef HSHCAL002_H
#define HSHCAL002_H 
	 
#include <linux/ioctl.h>

#define HSHCAL002_I2C_SLAVE_ADDR		0x18  //7bit  8bit:0x30


#define HSHCAL002_SELFTESTR_REG     		0x0C
#define HSHCAL002_VERSION_REG      			0x0D
#define HSHCAL002_ALPSINFO_REG     			0x0E
#define HSHCAL002_ID_REG					0x0F
#define HSHCAL002_HUMIDITY_LOW_DATA_REG     0x10
#define HSHCAL002_HUMIDITY_HIGH_DATA_REG    0x11
#define HSHCAL002_TEMP_LOW_DATA_REG     	0x12
#define HSHCAL002_TEMP_HIGH_DATA_REG    	0x13
#define HSHCAL002_STATUS_REG     			0x18
#define HSHCAL002_CONTROL_REG 			    0x1B
#define HSHCAL002_RDATA1_REG     			0x20
#define HSHCAL002_RDATA2_REG    			0x21
#define HSHCAL002_RDATA3_REG		        0x22
#define HSHCAL002_RDATA4_REG    			0x23

#define  HSHCAL002_RESET_REG       			0x30
#define  HSHCAL002_DETECT_REG   			0x31
#define  HSHCAL002_SELFTES_REG       		0x32
	 
#define  HSHCAL002_CHIP_ID       			0x2311

#define TRUE 1
#define FALSE 0

#define HSHCAL002_SUCCESS						0
#define HSHCAL002_ERR_I2C						-1
#define HSHCAL002_ERR_STATUS					-3
#define HSHCAL002_ERR_SETUP_FAILURE				-4
#define HSHCAL002_ERR_GETGSENSORDATA			-5
#define HSHCAL002_ERR_IDENTIFICATION			-6
	 
#define HSHCAL002_BUFSIZE				3
	 
#endif

