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
 * Definitions for PA12201001 als/ps sensor chip.
 */
#ifndef __PA12201001_H__
#define __PA12201001_H__

#include <linux/ioctl.h>

/*PA12201001 als/ps sensor register related macro*/
#define PA12201001_REG_ALS_UV_CONF		0X00
#define PA12201001_REG_ALS_THDH		0X01
#define PA12201001_REG_ALS_THDL		0X02
#define PA12201001_REG_PS_CONF1_2		0X03
#define PA12201001_REG_PS_CONF3_MS		0X04
#define PA12201001_REG_PS_CANC			0X05
#define PA12201001_REG_PS_THDL			0X06
#define PA12201001_REG_PS_THDH			0X07
#define PA12201001_REG_PS_DATA			0X08
#define PA12201001_REG_ALS_DATA		0X09
#define PA12201001_REG_UVAS_DATA		0X0B
#define PA12201001_REG_UVBS_DATA		0X0C
#define PA12201001_REG_INT_FLAG		0X0D
#define PA12201001_REG_ID				0X0E

/*PA12201001 related driver tag macro*/
#define PA12201001_SUCCESS						0
#define PA12201001_ERR_I2C						-1
#define PA12201001_ERR_STATUS					-3
#define PA12201001_ERR_SETUP_FAILURE			-4
#define PA12201001_ERR_GETGSENSORDATA			-5
#define PA12201001_ERR_IDENTIFICATION			-6

/*----------------------------------------------------------------------------*/
typedef enum {
	PA12201001_NOTIFY_PROXIMITY_CHANGE = 1,
} PA12201001_NOTIFY_TYPE;
/*----------------------------------------------------------------------------*/
typedef enum {
	PA12201001_CUST_ACTION_SET_CUST = 1,
	PA12201001_CUST_ACTION_CLR_CALI,
	PA12201001_CUST_ACTION_SET_CALI,
	PA12201001_CUST_ACTION_SET_PS_THRESHODL,
	PA12201001_CUST_ACTION_SET_EINT_INFO,
	PA12201001_CUST_ACTION_GET_ALS_RAW_DATA,
	PA12201001_CUST_ACTION_GET_PS_RAW_DATA,
} PA12201001_CUST_ACTION;
/*----------------------------------------------------------------------------*/
typedef struct {
	uint16_t action;
} PA12201001_CUST;
/*----------------------------------------------------------------------------*/
typedef struct {
	uint16_t action;
	uint16_t part;
	int32_t data[0];
} PA12201001_SET_CUST;
/*----------------------------------------------------------------------------*/
typedef PA12201001_CUST PA12201001_CLR_CALI;
/*----------------------------------------------------------------------------*/
typedef struct {
	uint16_t action;
	int32_t cali;
} PA12201001_SET_CALI;
/*----------------------------------------------------------------------------*/
typedef struct {
	uint16_t action;
	int32_t threshold[2];
} PA12201001_SET_PS_THRESHOLD;
/*----------------------------------------------------------------------------*/
typedef struct {
	uint16_t action;
	uint32_t gpio_pin;
	uint32_t gpio_mode;
	uint32_t eint_num;
	uint32_t eint_is_deb_en;
	uint32_t eint_type;
} PA12201001_SET_EINT_INFO;
/*----------------------------------------------------------------------------*/
typedef struct {
	uint16_t action;
	uint16_t als;
} PA12201001_GET_ALS_RAW_DATA;
/*----------------------------------------------------------------------------*/
typedef struct {
	uint16_t action;
	uint16_t ps;
} PA12201001_GET_PS_RAW_DATA;
/*----------------------------------------------------------------------------*/
typedef union {
	uint32_t data[10];
	PA12201001_CUST cust;
	PA12201001_SET_CUST setCust;
	PA12201001_CLR_CALI clearCali;
	PA12201001_SET_CALI setCali;
	PA12201001_SET_PS_THRESHOLD setPSThreshold;
	PA12201001_SET_EINT_INFO setEintInfo;
	PA12201001_GET_ALS_RAW_DATA getALSRawData;
	PA12201001_GET_PS_RAW_DATA getPSRawData;
} PA12201001_CUST_DATA;
/*----------------------------------------------------------------------------*/

extern struct platform_device *get_alsps_platformdev(void);
#endif
