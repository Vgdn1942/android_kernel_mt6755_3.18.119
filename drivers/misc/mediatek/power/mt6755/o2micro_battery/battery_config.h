/* ========================================================================== */
/*                                                                            */
/*   battery_config.h                                                      */
/*   (c) 2001 Author                                                          */
/*                                                                            */
/*   Description                                                              */
/* This program is free software; you can redistribute it and/or modify it    */
/* under the terms of the GNU General Public License version 2 as published   */
/* by the Free Software Foundation.											  */
/*																			  */
/* This program is distributed in the hope that it will be useful, but        */
/* WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY */
/* or FITNESS FOR A PARTICULAR PURPOSE.										  */
/* See the GNU General Public License for more details.						  */
/*																			  */
/* You should have received a copy of the GNU General Public License along	  */
/* with this program.  If not, see <http://www.gnu.org/licenses/>.			  */
/* ========================================================================== */

#ifndef	__O2_BATTERY_CONFIG_H 
#define	__O2_BATTERY_CONFIG_H __FILE__


#define OZ88106_I2C_NUM    0

//#define	EXT_THERMAL_READ   0
		
#define OZ8806_VOLTAGE  		4350
#define O2_CONFIG_CAPACITY  		4411
#define O2_CONFIG_RSENSE  			10
#define O2_CONFIG_EOC  				300
#define OZ8806_EOD 				3450
#define O2_CONFIG_BOARD_OFFSET		20


#define BATTERY_WORK_INTERVAL		10

#define RPULL (68000)
#define RDOWN (5100)


#ifdef CONFIG_OZ115_SUPPORT
	#define O2_CHARGER_SUPPORT
#endif

#define ENABLE_10MIN_END_CHARGE_FUN

// ****************************MTK MACH*************************
#ifdef CONFIG_MEDIATEK_SOLUTION
	#define MTK_MACH_SUPPORT
	#define USERSPACE_READ_SAVED_CAP

#elif defined INTEL_MACH
	#define O2_GAUGE_POWER_SUPPOLY_SUPPORT
    #define O2_GAUGE_WORK_SUPPORT

// ****************************default*************************
#else
    #define TQ210_TEST
    #define O2_GAUGE_POWER_SUPPOLY_SUPPORT 
    #define O2_GAUGE_WORK_SUPPORT

#endif


#endif
