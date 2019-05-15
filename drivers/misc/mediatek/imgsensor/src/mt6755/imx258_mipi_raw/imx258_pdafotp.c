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

#define IMX258_PDAFOTP_DEBUG
#ifdef IMX258_PDAFOTP_DEBUG
#define PFX "IMX258_pdafotp"
#define LOG_INF(format, args...)    pr_debug(PFX "[%s] " format, __FUNCTION__, ##args)
#else
#define LOG_INF(format, args...)
#endif

#include "kd_camera_typedef.h"
#include "kd_imgsensor.h"
#include "kd_imgsensor_define.h"
#include "kd_imgsensor_errcode.h"


#if defined(CONFIG_MTK_CAMERA_VERSION)

#include "agold_camera_info.h"

#endif


extern int g_cur_cam_sensor;


extern int iReadRegI2C(u8 *a_pSendData , u16 a_sizeSendData, u8 * a_pRecvData, u16 a_sizeRecvData, u16 i2cId);
extern int iWriteRegI2C(u8 *a_pSendData , u16 a_sizeSendData, u16 i2cId);
extern void kdSetI2CSpeed(u16 i2cSpeed);
//extern int iBurstWriteReg_multi(u8 *pData, u32 bytes, u16 i2cId, u16 transfer_length);
extern int iMultiReadReg(u16 a_u2Addr , u8 * a_puBuff , u16 i2cId, u8 number);


#define USHORT             unsigned short
#define BYTE               unsigned char
#define Sleep(ms) mdelay(ms)

#if defined(AGOLD_IMX258_OTP_XL)
#define IMX258_EEPROM_READ_ID  0xA0
#define IMX258_EEPROM_WRITE_ID   0xA1
#else
#define IMX258_EEPROM_READ_ID  0xB1
#define IMX258_EEPROM_WRITE_ID   0xB0
#endif
#define IMX258_I2C_SPEED        100
#define IMX258_MAX_OFFSET		0xFFFF

#define DATA_SIZE 2048
BYTE imx258_eeprom_data[DATA_SIZE]= {0};
//static bool get_done = false;
//static int last_size = 0;
//static int last_offset = 0;

typedef struct {
//        u8     	proc1_flag;                      // 0x0x790
	u8    	proc1_data[496];		 // 0x791---0x980
//	u8     	proc1_checksum;	                //  0x981
//        u8     	proc2_flag;                     //  0x982
	u8    	proc2_data[860];		//  0x0983------0x0ca8
//	u8     	proc2_checksum;	                 // 0x0ca9

}PDAF_MTK_TYPE;

typedef union {
        u8 Data[DATA_SIZE];
        PDAF_MTK_TYPE       MtkPdafData;
} PDAF_DATA_UNIO;

PDAF_DATA_UNIO imx258_pdaf_data = {{0}};

static int read_cmos_sensor(kal_uint16 slave_id,kal_uint16 addr,BYTE* data)
{
    char puSendCmd[2] = {(char)(addr >> 8) , (char)(addr & 0xFF) };
    return iReadRegI2C(puSendCmd , 2, data, 1, slave_id);
}


int read_imx258_eeprom(u8 slv_id, u16 offset, u8* data)
{
    int ret = 0;
    ret = read_cmos_sensor(slv_id,offset,data);
//    CAM_CALINF("imx258 read_imx258_eeprom= %x %x\n",offset, *data);
    return ret;
}

int read_imx258_eeprom_size(u8 slv_id, u16 offset, u8* data,int size)
{
	int i = 0;
	for(i = 0; i < size; i++){
		if(read_imx258_eeprom(slv_id, offset+i, data+i) != 0)
			return -1;
	}
	return 0;
}

bool read_imx258_eeprom_SPC( kal_uint16 addr, BYTE* data, kal_uint32 size){

//	addr = 0x0F73;//0x0F73;
//	size = 126;

//	LOG_INF("read imx258 eeprom, size = %d\n", size);


		if(!read_imx258_eeprom_size(IMX258_EEPROM_READ_ID,addr, imx258_eeprom_data, size))
		{
			return false;
		}
	memcpy(data, imx258_eeprom_data, size);
    return true;
}

kal_bool read_imx258_otp_eeprom( kal_uint16 addr, BYTE* data, kal_uint32 size)
{
	#if defined(AGOLD_IMX258_OTP_XL)
		size = 1404;
		addr=0xA0;

		read_imx258_eeprom_size(addr,0x0801,imx258_eeprom_data,1404);
		memcpy(data, imx258_eeprom_data, size);
	#else
	int i;
	//addr_1 = 0x0800;
	//int total_size = 1404;
	size = 1404;
	addr=0xb1;



	LOG_INF("read imx258 eeprom, size = %d\n", size);


       	read_imx258_eeprom_size(addr,0x0791,imx258_pdaf_data.MtkPdafData.proc1_data,496);
	memcpy(data, imx258_pdaf_data.MtkPdafData.proc1_data,496);
	for(i = 0; i < 496; i++){
		LOG_INF("imx258_pdaf_data.MtkPdafData.proc1_data[ %d]= %d   \n", i,imx258_pdaf_data.MtkPdafData.proc1_data[i]);
	}

       	read_imx258_eeprom_size(addr,0x0983,imx258_pdaf_data.MtkPdafData.proc2_data,860);
	memcpy(data+496, imx258_pdaf_data.MtkPdafData.proc2_data,860);
	for(i = 0; i < 860; i++){
		LOG_INF("imx258_pdaf_data.MtkPdafData.proc2_data[ %d]= %d   \n", i,imx258_pdaf_data.MtkPdafData.proc2_data[i]);
	}
	#endif
    return KAL_TRUE;
}

bool IMX258CheckLensVersion(void)
{
    kal_uint8 otp_flag = 0;
    kal_uint8 data[8] = { 0 };



    LOG_INF("IMX258CheckLensVersion enter\n");
    read_cmos_sensor(IMX258_EEPROM_READ_ID,0x0000,&otp_flag);
    LOG_INF("[zbl]read imx258 otp flag = %d\n", otp_flag);

    if(otp_flag!=0x01)
    {
        LOG_INF("[zbl]read otp failed!\n");
        return false;
    }

    read_imx258_eeprom_size(IMX258_EEPROM_READ_ID,0x0001,data,7);

#if defined(CONFIG_MTK_CAMERA_VERSION)
	//#if defined(AGOLD_IMX258_OTP_XL)
	agold_camera_info[g_cur_cam_sensor-1].mf_id = data[3];
    agold_camera_info[g_cur_cam_sensor-1].date[0] = data[0];
    agold_camera_info[g_cur_cam_sensor-1].date[1] = data[1];
    agold_camera_info[g_cur_cam_sensor-1].date[2] = data[2];
    agold_camera_info[g_cur_cam_sensor-1].lens_id = data[4];
    agold_camera_info[g_cur_cam_sensor-1].sen_id = 0x00;

	//#else
    agold_camera_info[g_cur_cam_sensor-1].mf_id = data[0];
    agold_camera_info[g_cur_cam_sensor-1].date[0] = data[4];
    agold_camera_info[g_cur_cam_sensor-1].date[1] = data[5];
    agold_camera_info[g_cur_cam_sensor-1].date[2] = data[6];
    agold_camera_info[g_cur_cam_sensor-1].lens_id = data[1];
    agold_camera_info[g_cur_cam_sensor-1].sen_id = data[2];

    printk("[zbl]read imx258 otp year = %d\n", data[4]);
    printk("[zbl]read imx258 otp month = %d\n", data[5]);
    printk("[zbl]read imx258 otp day = %d\n", data[6]);
    printk("[zbl]read imx258 otp mid = %x\n", data[0]);
    printk("[zbl]read imx258 otp Lens_ID = %x\n", data[1]);
    printk("[zbl]read imx258 otp VCM_ID = %x\n", data[2]);
    printk("[zbl]read imx258 otp VCM_Driver_ID = %x\n", data[3]);
	//#endif
//    LOG_INF("[zbl]read imx258 otp corlo temperature = %d\n", data[8]);
#endif

    return true;
}

