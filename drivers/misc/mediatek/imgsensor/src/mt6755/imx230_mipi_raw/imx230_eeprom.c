#include <linux/videodev2.h>
#include <linux/i2c.h>
#include <linux/platform_device.h>
#include <linux/delay.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include <linux/fs.h>
#include <asm/atomic.h>
#include <linux/slab.h>
//#include <linux/xlog.h>


#define PFX "IMX230_pdafotp"
#define LOG_INF(format, args...)	pr_debug(PFX "[%s] " format, __FUNCTION__, ##args)

#include "kd_camera_hw.h"
#include "kd_imgsensor.h"
#include "kd_imgsensor_define.h"
#include "kd_imgsensor_errcode.h"


#if defined(AGOLD_CAMERA_VERSION)

#include "agold_camera_info.h" 

#endif


extern int iReadRegI2C(u8 *a_pSendData , u16 a_sizeSendData, u8 * a_pRecvData, u16 a_sizeRecvData, u16 i2cId);
extern int iWriteRegI2C(u8 *a_pSendData , u16 a_sizeSendData, u16 i2cId);
extern void kdSetI2CSpeed(u16 i2cSpeed);
//extern int iBurstWriteReg_multi(u8 *pData, u32 bytes, u16 i2cId, u16 transfer_length);
extern int iMultiReadReg(u16 a_u2Addr , u8 * a_puBuff , u16 i2cId, u8 number);


#define USHORT             unsigned short
#define BYTE               unsigned char
#define Sleep(ms) mdelay(ms)

#define IMX230_EEPROM_READ_ID  0xA0
#define IMX230_EEPROM_WRITE_ID   0xA1
#define IMX230_I2C_SPEED        100  
#define IMX230_MAX_OFFSET		0xFFFF

#define DATA_SIZE 2048

BYTE IMX230_DCC_data[96]= {0};
BYTE IMX230_SPC_data[352]= {0};
BYTE imx230_eeprom_data[DATA_SIZE]= {0};


static bool get_done = false;
static int last_size = 0;
static int last_offset = 0;


static bool selective_read_eeprom(kal_uint16 addr, BYTE* data)
{
	char pu_send_cmd[2] = {(char)(addr >> 8) , (char)(addr & 0xFF) };
    if(addr > IMX230_MAX_OFFSET)
        return false;
	kdSetI2CSpeed(IMX230_I2C_SPEED);

	if(iReadRegI2C(pu_send_cmd, 2, (u8*)data, 1, IMX230_EEPROM_READ_ID)<0)
		return false;
    return true;
}

static bool _read_imx230_eeprom(kal_uint16 addr, BYTE* data, int size ){
	int i = 0;
	int offset = addr;
	LOG_INF("enter _read_eeprom size = %d\n",size);
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
bool read_imx230_eeprom( kal_uint16 addr, BYTE* data, kal_uint32 size)
{
//	LOG_INF("read imx258 eeprom, size = %d\n", size);

	if(!get_done || last_size != size || last_offset != addr) {
		if(!_read_imx230_eeprom(addr, imx230_eeprom_data, size)){
			get_done = 0;
            last_size = 0;
            last_offset = 0;
			return false;
		}
	}

	memcpy(data, imx230_eeprom_data, size);
    return true;
}


void read_imx230_SPC(BYTE* data){
	//int i;
	int addr = 0x801;
	int size = 352;
	
	LOG_INF("read imx230 SPC, size = %d\n", size);
	
	if(!get_done || last_size != size || last_offset != addr) {
		if(!_read_imx230_eeprom(addr, IMX230_SPC_data, size)){
			get_done = 0;
            last_size = 0;
            last_offset = 0;
			//return false;
		}
	}

	memcpy(data, IMX230_SPC_data , size);
   //return true;
}


void read_imx230_DCC( kal_uint16 addr,BYTE* data, kal_uint32 size){
	//int i;
	addr = 0x963;
	size = 96;
	
	LOG_INF("read imx230 DCC, size = %d\n", size);
	
	if(!get_done || last_size != size || last_offset != addr) {
		if(!_read_imx230_eeprom(addr, IMX230_DCC_data, size)){
			get_done = 0;
            last_size = 0;
            last_offset = 0;
			//return false;
		}
	}
	//LOG_INF("data addr 0x%x\n",data);
	memcpy(data, IMX230_DCC_data , size);
    //return true;
}

bool IMX230CheckLensVersion(void)
{
    kal_uint8 otp_flag = 0;   
    kal_uint8 data[8] = { 0 };
    static int checkVersion = 0;
  
  
    LOG_INF("IMX230CheckLensVersion enter\n");
    if(!checkVersion)
    {
        read_imx230_eeprom(0x0000,&otp_flag,1);
        LOG_INF("[zbl]read imx230 otp flag = %d\n", otp_flag);
        
        if(!otp_flag)
        {
            LOG_INF("[zbl]read otp failed!\n");
            return false;
        }
        
        read_imx230_eeprom(0x0001,data,7);
        
        agold_camera_info[g_cur_cam_sensor-1].mf_id = data[3];
        agold_camera_info[g_cur_cam_sensor-1].date[0] = data[0];
        agold_camera_info[g_cur_cam_sensor-1].date[1] = data[1];
        agold_camera_info[g_cur_cam_sensor-1].date[2] = data[2];
        agold_camera_info[g_cur_cam_sensor-1].lens_id = data[4];
        agold_camera_info[g_cur_cam_sensor-1].sen_id = data[5];
            
        LOG_INF("[zbl]read imx230 otp year = %d\n", data[0]);
        LOG_INF("[zbl]read imx230 otp month = %d\n", data[1]);
        LOG_INF("[zbl]read imx230 otp day = %d\n", data[2]);
        LOG_INF("[zbl]read imx230 otp mid = %d\n", data[3]);
        LOG_INF("[zbl]read imx230 otp Lens_ID = %d\n", data[4]);
        LOG_INF("[zbl]read imx230 otp VCM_ID = %d\n", data[5]);
        LOG_INF("[zbl]read imx230 otp VCM_Driver_ID = %d\n", data[6]);

     
     //    LOG_INF("[zbl]read imx258 otp corlo temperature = %d\n", data[8]);
        checkVersion=1;
     }    
    return true;
}


