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


#define PFX "S5K3P3_pdafotp"
#define LOG_INF(format, args...)	pr_debug(PFX "[%s] " format, __FUNCTION__, ##args)

#include "kd_camera_hw.h"
#include "kd_imgsensor.h"
#include "kd_imgsensor_define.h"
#include "kd_imgsensor_errcode.h"


#if defined(AGOLD_CAMERA_VERSION)

#include "agold_camera_info.h"
#define BoverGr_dec_base 0x22d  //cur_bg_ratio
#define RoverGr_dec_base 0x332  //cur_rg_ratio

#endif



extern int iReadRegI2C(u8 *a_pSendData , u16 a_sizeSendData, u8 * a_pRecvData, u16 a_sizeRecvData, u16 i2cId);
extern int iWriteRegI2C(u8 *a_pSendData , u16 a_sizeSendData, u16 i2cId);
extern void kdSetI2CSpeed(u16 i2cSpeed);
//extern int iBurstWriteReg_multi(u8 *pData, u32 bytes, u16 i2cId, u16 transfer_length);
extern int iMultiReadReg(u16 a_u2Addr , u8 * a_puBuff , u16 i2cId, u8 number);


#define USHORT             unsigned short
#define BYTE               unsigned char
#define Sleep(ms) mdelay(ms)

#define S5K3P3_EEPROM_READ_ID  0xA1
#define S5K3P3_EEPROM_WRITE_ID   0xA0
#define S5K3P3_I2C_SPEED        100
#define S5K3P3_MAX_OFFSET		0xFFFF

#define DATA_SIZE 2048
BYTE s5k3P3_eeprom_data[DATA_SIZE]= {0};
static bool get_done = false;
static int last_size = 0;
static int last_offset = 0;


static bool selective_read_eeprom(kal_uint16 addr, BYTE* data)
{
	char pu_send_cmd[2] = {(char)(addr >> 8) , (char)(addr & 0xFF) };
    if(addr > S5K3P3_MAX_OFFSET)
        return false;
	kdSetI2CSpeed(S5K3P3_I2C_SPEED);

	if(iReadRegI2C(pu_send_cmd, 2, (u8*)data, 1, S5K3P3_EEPROM_WRITE_ID)<0)
		return false;
    return true;
}

static bool _read_3P3_eeprom(kal_uint16 addr, BYTE* data, kal_uint32 size ){
	int i = 0;
	int offset = addr;
	for(i = 0; i < size; i++) {
		if(!selective_read_eeprom(offset, &data[i])){
			return false;
		}
		LOG_INF("read_eeprom 0x%0x %d\n",offset, data[i]);
		offset++;
	}
	get_done = true;
	last_size = size;
	last_offset = addr;
    return true;
}

bool read_3P3_eeprom( kal_uint16 addr, BYTE* data, kal_uint32 size){
	addr = 0x763;
	size = 1404;
	//BYTE header[9]= {0};
	//_read_3P3_eeprom(0x0000, header, 9);

	LOG_INF("read 3P3 eeprom, size = %d\n", size);

	if(!get_done || last_size != size || last_offset != addr) {
		if(!_read_3P3_eeprom(addr, s5k3P3_eeprom_data, size)){
			get_done = 0;
            last_size = 0;
            last_offset = 0;
			return false;
		}
	}

	memcpy(data, s5k3P3_eeprom_data, size);
    return true;
}

kal_bool S5K3P3CheckLensVersion(void)
{
    kal_uint8 otp_flag = 0;
    kal_uint8 data[10] = {0};

    _read_3P3_eeprom(0x0000,&otp_flag,1);
    LOG_INF("[S5K3P3] S5K3P3_EEPROM_READ_ID:0x%x ,otp_flag =0x%2x\n", S5K3P3_EEPROM_WRITE_ID ,otp_flag);
    if (otp_flag!=0x01)
    
	{
	    LOG_INF("[s5k3p3] Read OTP failed!!---- \n");  
            return KAL_FALSE;
	}
    _read_3P3_eeprom(0x0001,data,10);
  
    agold_camera_info[g_cur_cam_sensor-1].mf_id = data[3];
	agold_camera_info[g_cur_cam_sensor-1].date[0] = data[0];  //year
	agold_camera_info[g_cur_cam_sensor-1].date[1] = data[1];  //month
	agold_camera_info[g_cur_cam_sensor-1].date[2] = data[2];  //date	
	agold_camera_info[g_cur_cam_sensor-1].lens_id = data[4];
	agold_camera_info[g_cur_cam_sensor-1].sen_id = data[5];	
	

    _read_3P3_eeprom(0x0011,&otp_flag,1);
    LOG_INF("s5k3p3 awb/af flag = 0x%x\n",otp_flag);
    _read_3P3_eeprom(0x001E,data,2);
    LOG_INF("s5k3p3 lsc size lsb 0x%x\n",data[0]);
    LOG_INF("s5k3p3 lsc size Msb 0x%x\n",data[1]);
    
    _read_3P3_eeprom(0x001A,data,4);
    LOG_INF("s5k3p3 AF inf lsb 0x%x\n",data[0]);
    LOG_INF("s5k3p3 AF inf Msb 0x%x\n",data[1]);
    LOG_INF("s5k3p3 AF mac lsb 0x%x\n",data[2]);
    LOG_INF("s5k3p3 AF mac Msb 0x%x\n",data[3]);

	LOG_INF("[S5K3p3]otp_log read mf_id,id=0x%2x\n", agold_camera_info[g_cur_cam_sensor-1].mf_id);
	LOG_INF("[S5K3p3]otp_log read lens_id,id=0x%2x\n", agold_camera_info[g_cur_cam_sensor-1].lens_id);
	LOG_INF("[S5K3p3]otp_log read soft_id,id=0x%2x\n", agold_camera_info[g_cur_cam_sensor-1].sen_id);
	LOG_INF("s5k3p3 driver ic id = %d\n",data[6]);
    return KAL_TRUE;

}


