/* 
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */
/*
 * Definitions for TXC PA12201001 als/ps sensor chip.
 */
#ifndef __PA12201001_H__
#define __PA12201001_H__

#include <linux/ioctl.h>


/*pa12201001 als/ps Default*/
#define PA12_I2C_ADDRESS        0x1E  	//7 bit Address

#define GET_TH_HIGH		1
#define GET_TH_LOW		2
#define SET_TH			3
#define GET_TH_RESULT		4

#define PA12_ALS_TH_HIGH	35000
#define PA12_ALS_TH_LOW		0
#define PA12_PS_TH_HIGH		130
#define PA12_PS_TH_LOW		0

#define PA12_PS_OFFSET_DEFAULT  0 	// for X-talk cannceling

#define PA12_ALS_GAIN		0 	// 0:125lux 1:1000lux 2:2000lux 3:10000lux
#define PA12_LED_CURR		0 	// 0:150mA 1:100mA 2:50mA 3:25mA

#define PA12_PS_PRST		2	// 0:1point 1:2points 2:4points 3:8points (for INT)
#define PA12_ALS_PRST		0	// 0:1point 1:2points 2:4points 3:8points (for INT)

#define PA12_PS_SET			1	// 0:ALS only 1:PS only 3:BOTH
#define PA12_PS_MODE		3	// 0:OFFSET 3:NORMAL

#define PA12_INT_TYPE		0 	// 0:Window type 1:Hysteresis type for Auto Clear flag
#define PA12_PS_PERIOD		0	// 6.25 ms
#define PA12_ALS_PERIOD		0	// 0 ms 



/*pa12201001 als/ps sensor register map*/
#define REG_CFG0 		0X00  	// ALS_GAIN(D5-4),PS_ON(D1) ALS_ON(D0)
#define REG_CFG1 		0X01  	// LED_CURR(D5-4),PS_PRST(D3-2),ALS_PRST(D1-0)
#define REG_CFG2 		0X02  	// PS_MODE(D7-6),CLEAR(D4),INT_SET(D3-2),PS_INT(D1),ALS_INT(D0)
#define REG_CFG3		0X03  	// INT_TYPE(D6),PS_PERIOD(D5-3),ALS_PERIOD(D2-0)
#define REG_ALS_TL_LSB		0X04  	// ALS Threshold Low LSB
#define REG_ALS_TL_MSB		0X05  	// ALS Threshold Low MSB
#define REG_ALS_TH_LSB		0X06  	// ALS Threshold high LSB
#define REG_ALS_TH_MSB		0X07  	// ALS Threshold high MSB
#define REG_PS_TL		0X08  	// PS Threshold Low
#define REG_PS_TH		0X0A  	// PS Threshold High
#define REG_ALS_DATA_LSB	0X0B  	// ALS DATA
#define REG_ALS_DATA_MSB	0X0C  	// ALS DATA
#define REG_PS_DATA		0X0E  	// PS DATA
#define REG_PS_OFFSET		0X10  	// TBD
#define REG_PS_SET		0X11  	// 0x03


/*----------------------------------------------------------------------------*/
typedef enum{
    PA12_NOTIFY_PROXIMITY_CHANGE = 1,
}PA12_NOTIFY_TYPE;
/*----------------------------------------------------------------------------*/
typedef enum{
    PA12_CUST_ACTION_SET_CUST = 1,
    PA12_CUST_ACTION_CLR_CALI,
    PA12_CUST_ACTION_SET_CALI,
    PA12_CUST_ACTION_SET_PS_THRESHODL,
    PA12_CUST_ACTION_SET_EINT_INFO,
    PA12_CUST_ACTION_GET_ALS_RAW_DATA,
    PA12_CUST_ACTION_GET_PS_RAW_DATA,
}PA12_CUST_ACTION;
/*----------------------------------------------------------------------------*/
typedef struct
{
    uint16_t    action;
}PA12_CUST;
/*----------------------------------------------------------------------------*/
typedef struct
{
    uint16_t    action;
    uint16_t    part;
    int32_t    data[0];
}PA12_SET_CUST;
/*----------------------------------------------------------------------------*/
typedef PA12_CUST PA12_CLR_CALI;
/*----------------------------------------------------------------------------*/
typedef struct
{
    uint16_t    action;
    int32_t     cali;
}PA12_SET_CALI;
/*----------------------------------------------------------------------------*/
typedef struct
{
    uint16_t    action;
    int32_t     threshold[2];
}PA12_SET_PS_THRESHOLD;
/*----------------------------------------------------------------------------*/
typedef struct
{
    uint16_t    action;
    uint32_t    gpio_pin;
    uint32_t    gpio_mode;
    uint32_t    eint_num;
    uint32_t    eint_is_deb_en;
    uint32_t    eint_type;
}PA12_SET_EINT_INFO;
/*----------------------------------------------------------------------------*/
typedef struct
{
    uint16_t    action;
    uint16_t    als;
}PA12_GET_ALS_RAW_DATA;
/*----------------------------------------------------------------------------*/
typedef struct
{
    uint16_t    action;
    uint16_t    ps;
} PA12_GET_PS_RAW_DATA;
/*----------------------------------------------------------------------------*/
typedef union
{
    uint32_t                    data[10];
    PA12_CUST                cust;
    PA12_SET_CUST            setCust;
    PA12_CLR_CALI            clearCali;
    PA12_SET_CALI            setCali;
    PA12_SET_PS_THRESHOLD    setPSThreshold;
    PA12_SET_EINT_INFO       setEintInfo;
    PA12_GET_ALS_RAW_DATA    getALSRawData;
    PA12_GET_PS_RAW_DATA     getPSRawData;
}PA12_CUST_DATA;
/*----------------------------------------------------------------------------*/
#endif

