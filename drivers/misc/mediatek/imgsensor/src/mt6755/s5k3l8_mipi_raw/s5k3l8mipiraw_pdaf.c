/*
 * Copyright (C) 2015 MediaTek Inc.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */

#include <linux/videodev2.h>
#include <linux/i2c.h>
#include <linux/platform_device.h>
#include <linux/delay.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include <linux/fs.h>
#include <asm/atomic.h>
#include <linux/slab.h>

#ifdef S5K3L8_PDAFOTP_DEBUG
#define PFX "S5K3L8_pdafotp"
#define LOG_INF(format, args...)    pr_debug(PFX "[%s] " format, __FUNCTION__, ##args)
#else
#define LOG_INF(format, args...)
#endif

#include "kd_camera_typedef.h"
#include "kd_imgsensor.h"
#include "kd_imgsensor_define.h"
#include "kd_imgsensor_errcode.h"

extern int iReadRegI2C(u8 *a_pSendData , u16 a_sizeSendData, u8 * a_pRecvData, u16 a_sizeRecvData, u16 i2cId);
extern int iWriteRegI2C(u8 *a_pSendData , u16 a_sizeSendData, u16 i2cId);
extern void kdSetI2CSpeed(u16 i2cSpeed);
//extern int iBurstWriteReg_multi(u8 *pData, u32 bytes, u16 i2cId, u16 transfer_length);
extern int iMultiReadReg(u16 a_u2Addr , u8 * a_puBuff , u16 i2cId, u8 number);

#define USHORT             unsigned short
#define BYTE               unsigned char
#define Sleep(ms) mdelay(ms)

#define S5K3L8_EEPROM_READ_ID  0xA0
#define S5K3L8_EEPROM_WRITE_ID   0xA1
#define S5K3L8_I2C_SPEED        100
#define S5K3L8_MAX_OFFSET		0xFFFF

#define DATA_SIZE 1404
BYTE s5k3l8_eeprom_data[DATA_SIZE]= {0};
static bool get_done = false;
static int last_size = 0;
static int last_offset = 0;


static bool selective_read_eeprom(kal_uint16 addr, BYTE* data)
{
	char pu_send_cmd[2] = {(char)(addr >> 8) , (char)(addr & 0xFF) };
    if(addr > S5K3L8_MAX_OFFSET)
        return false;

	kdSetI2CSpeed(S5K3L8_I2C_SPEED);

	if(iReadRegI2C(pu_send_cmd, 2, (u8*)data, 1, S5K3L8_EEPROM_READ_ID)<0)
		return false;
    return true;
}

static bool _read_s5k3l8_eeprom(kal_uint16 addr, BYTE* data, kal_uint32 size ){
	int i = 0;
	int offset = addr;
	for(i = 0; i < size; i++) {
		if(!selective_read_eeprom(offset, &data[i])){
			return false;
		}
//		LOG_INF("read_eeprom 0x%0x %d\n",offset, data[i]);
		offset++;
	}
	get_done = true;
	last_size = size;
	last_offset = addr;
    return true;
}

bool read_s5k3l8_eeprom( kal_uint16 addr, BYTE* data, kal_uint32 size){
//	addr = 0x0763;
//	size = 1404;

//	LOG_INF("read s5k3l8 eeprom, size = %d\n", size);

	if(!get_done || last_size != size || last_offset != addr) {
		if(!_read_s5k3l8_eeprom(addr, s5k3l8_eeprom_data, size)){
			get_done = 0;
            last_size = 0;
            last_offset = 0;
			return false;
		}
	}

	memcpy(data, s5k3l8_eeprom_data, size);
    return true;
}

bool read_s5k3l8_eeprom_SPC( kal_uint16 addr, BYTE* data, kal_uint32 size){

//	addr = 0x0F73;//0x0F73;
//	size = 126;

//	LOG_INF("read s5k3l8 eeprom, size = %d\n", size);

	if(!get_done || last_size != size || last_offset != addr) {
		if(!_read_s5k3l8_eeprom(addr, s5k3l8_eeprom_data, size)){
			get_done = 0;
            last_size = 0;
            last_offset = 0;
			return false;
		}
	}

	memcpy(data, s5k3l8_eeprom_data, size);
    return true;
}

bool S5K3L8CheckLensVersion(void)
{
    kal_uint8 otp_flag = 0;
    kal_uint8 data[8] = { 0 };



    printk("S5K3L8CheckLensVersion enter\n");
    read_s5k3l8_eeprom(0x0c00,&otp_flag,1);
    printk("[fj]read s5k3l8 otp flag = %d\n", otp_flag);

    if(!otp_flag)
    {
        LOG_INF("[fj]read otp failed!\n");
        return false;
    }

    read_s5k3l8_eeprom(0x0c01,data,8);

    printk("[fj1]read s5k3l8 otp year = %d\n", data[5]);
    printk("[fj1]read s5k3l8 otp month = %d\n", data[6]);
    printk("[fj1]read s5k3l8 otp day = %d\n", data[7]);
    printk("[fj1]read s5k3l8 otp mid = %d\n", data[0]);
    printk("[fj1]read s5k3l8 otp Lens_ID = %d\n", data[1]);
	printk("[fj1]read s5k3l8 otp sen_id = %d\n", data[2]);
    printk("[fj1]read s5k3l8 otp VCM_ID = %d\n", data[3]);
    printk("[fj1]read s5k3l8 otp VCM_Driver_ID = %d\n", data[4]);
//    LOG_INF("[fj]read s5k3l8 otp corlo temperature = %d\n", data[8]);

    return true;
}

