/* ST LSM6DS3 Accelerometer and Gyroscope sensor driver
 *
 *
 *
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

#include <linux/interrupt.h>
#include <linux/i2c.h>
#include <linux/slab.h>
#include <linux/irq.h>
#include <linux/miscdevice.h>
#include <asm/uaccess.h>
#include <linux/delay.h>
#include <linux/input.h>
#include <linux/workqueue.h>
#include <linux/kobject.h>
#include <linux/platform_device.h>

#include "lsm6ds3.h"
#include <linux/kernel.h>
#include <cust_acc.h>
#include <accel.h>

//#define LSM6DS3_STEP_COUNTER 			//it depends on the MACRO LSM6DS3_NEW_ARCH
//#define LSM6DS3_TILT_FUNC 				//dependency on LSM6DS3_STEP_COUNTER
//#define LSM6DS3_SIGNIFICANT_MOTION  	//dependency on LSM6DS3_STEP_COUNTER

#define DEBUG 1
#define CONFIG_LSM6DS3_LOWPASS   /*apply low pass filter on output*/       
#define LSM6DS3_AXIS_X          0
#define LSM6DS3_AXIS_Y          1
#define LSM6DS3_AXIS_Z          2
#define LSM6DS3_ACC_AXES_NUM        3
#define LSM6DS3_GYRO_AXES_NUM       3
#define LSM6DS3_ACC_DATA_LEN        6   
#define LSM6DS3_GYRO_DATA_LEN       6   
#define LSM6DS3_ACC_DEV_NAME        "LSM6DS3_ACCEL"
/*----------------------------------------------------------------------------*/
static const struct i2c_device_id lsm6ds3_i2c_id[] = {{LSM6DS3_ACC_DEV_NAME,0},{}};
#ifdef CONFIG_MTK_LEGACY
static struct i2c_board_info __initdata i2c_lsm6ds3={ I2C_BOARD_INFO(LSM6DS3_ACC_DEV_NAME, (0xD6>>1))};
#endif

#define SW_CALIBRATION

/*----------------------------------------------------------------------------*/
static int lsm6ds3_i2c_probe(struct i2c_client *client, const struct i2c_device_id *id);
static int lsm6ds3_i2c_remove(struct i2c_client *client);
//static int lsm6ds3_i2c_detect(struct i2c_client *client, int kind, struct i2c_board_info *info);
static int LSM6DS3_init_client(struct i2c_client *client, bool enable);
static int LSM6DS3_acc_SetPowerMode(struct i2c_client *client, bool enable);

static int LSM6DS3_ReadAccRawData(struct i2c_client *client, s16 data[LSM6DS3_ACC_AXES_NUM]);
#ifndef CONFIG_HAS_EARLYSUSPEND

static int lsm6ds3_acc_suspend(struct i2c_client *client, pm_message_t msg);
static int lsm6ds3_acc_resume(struct i2c_client *client);
#endif
static int LSM6DS3_acc_SetSampleRate(struct i2c_client *client, u8 sample_rate);

/*----------------------------------------------------------------------------*/
typedef enum {
    ADX_TRC_FILTER  = 0x01,
    ADX_TRC_RAWDATA = 0x02,
    ADX_TRC_IOCTL   = 0x04,
    ADX_TRC_CALI	= 0X08,
    ADX_TRC_INFO	= 0X10,
} ADX_TRC;
/*----------------------------------------------------------------------------*/
typedef enum {
    ACCEL_TRC_FILTER  = 0x01,
    ACCEL_TRC_RAWDATA = 0x02,
    ACCEL_TRC_IOCTL   = 0x04,
    ACCEL_TRC_CALI	= 0X08,
    ACCEL_TRC_INFO	= 0X10,
    ACCEL_TRC_DATA	= 0X20,
} ACCEL_TRC;
/*----------------------------------------------------------------------------*/
struct scale_factor{
    u8  whole;
    u8  fraction;
};
/*----------------------------------------------------------------------------*/
struct data_resolution {
    struct scale_factor scalefactor;
    int                 sensitivity;
};
/*----------------------------------------------------------------------------*/
#define C_MAX_FIR_LENGTH (32)
/*----------------------------------------------------------------------------*/
struct data_filter {
    s16 raw[C_MAX_FIR_LENGTH][LSM6DS3_ACC_AXES_NUM];
    int sum[LSM6DS3_ACC_AXES_NUM];
    int num;
    int idx;
};
struct gyro_data_filter {
    s16 raw[C_MAX_FIR_LENGTH][LSM6DS3_GYRO_AXES_NUM];
    int sum[LSM6DS3_GYRO_AXES_NUM];
    int num;
    int idx;
};
/*----------------------------------------------------------------------------*/
struct lsm6ds3_i2c_data {
    struct i2c_client *client;
	struct acc_hw *hw;
    struct hwmsen_convert   cvt;
    atomic_t 				layout;
    /*misc*/
    //struct data_resolution *reso;
    struct work_struct	eint_work;				
    atomic_t                trace;
    atomic_t                suspend;
    atomic_t                selftest;
    atomic_t				filter;
    s16                     cali_sw[LSM6DS3_GYRO_AXES_NUM+1];

    /*data*/
	s8                      offset[LSM6DS3_ACC_AXES_NUM+1];  /*+1: for 4-byte alignment*/
    s16                     data[LSM6DS3_ACC_AXES_NUM+1];
	
	int 					sensitivity;
	int 					sample_rate;

#if defined(CONFIG_LSM6DS3_LOWPASS)
    atomic_t                firlen;
    atomic_t                fir_en;
    struct data_filter      fir;
#endif 
    /*early suspend*/
#if defined(CONFIG_HAS_EARLYSUSPEND)
    struct early_suspend    early_drv;
#endif     
};

#ifdef CONFIG_OF
static const struct of_device_id acc_of_match[] = {
	{.compatible = "mediatek,GSENSOR"},
	{},
};
#endif
/*----------------------------------------------------------------------------*/
static struct i2c_driver lsm6ds3_i2c_driver = {
    .driver = {
        //.owner          = THIS_MODULE,
        .name           = LSM6DS3_ACC_DEV_NAME,
		#ifdef CONFIG_OF
	   .of_match_table = acc_of_match,
		#endif
    },
	.probe      		= lsm6ds3_i2c_probe,
	.remove    			= lsm6ds3_i2c_remove,
#if !defined(CONFIG_HAS_EARLYSUSPEND)    
    .suspend            = lsm6ds3_acc_suspend,
    .resume             = lsm6ds3_acc_resume,
#endif
	.id_table = lsm6ds3_i2c_id,
};
static int lsm6ds3_local_init(void);
static int lsm6ds3_local_uninit(void);
static int lsm6ds3_acc_init_flag = -1;
static unsigned long lsm6ds3_init_flag_test = 0; //initial state
static DEFINE_MUTEX(lsm6ds3_init_mutex);
static DEFINE_MUTEX(lsm6ds3_read_mutex);
typedef enum {
	LSM6DS3_ACC = 1,
	LSM6DS3_STEP_C = 2,
	LSM6DS3_TILT = 3,
}LSM6DS3_INIT_TYPE;
static struct acc_init_info  lsm6ds3_init_info = {
	.name   = LSM6DS3_ACC_DEV_NAME,
	.init   = lsm6ds3_local_init,
	.uninit = lsm6ds3_local_uninit,
};

/*----------------------------------------------------------------------------*/
static struct i2c_client *lsm6ds3_i2c_client = NULL;

static struct lsm6ds3_i2c_data *obj_i2c_data = NULL;
static bool sensor_power = false;
static bool enable_status = false;
static bool pedo_enable_status = false;
static bool tilt_enable_status = false;

/* Maintain  cust info here */
struct acc_hw accel_cust;
static struct acc_hw *hw = &accel_cust;

/* For  driver get cust info */
struct acc_hw *get_cust_acc_hw(void)
{
	return &accel_cust;
}
/*----------------------------------------------------------------------------*/
//#define LSM6DS3_LOG
#define GSE_TAG                  "[accel] "
#define GSE_ERR(fmt, args...)    printk(KERN_ERR GSE_TAG "%s %d : " fmt, __FUNCTION__, __LINE__, ##args)

#ifdef LSM6DS3_LOG
#define GSE_FUN(f)               printk(KERN_ERR GSE_TAG"%s\n", __FUNCTION__)
#define GSE_LOG(fmt, args...)    printk(KERN_ERR GSE_TAG "%s %d : " fmt, __FUNCTION__, __LINE__, ##args)
#else
#define GSE_FUN(f)
#define GSE_LOG(fmt, args...)
#endif
/*----------------------------------------------------------------------------*/

static int lsm6ds0_acc_read_byte_sr(struct i2c_client *client, u8 addr, u8 *data, u8 len)
{
#if 0
    int ret = 0;
	unsigned short length = 0;

    client->addr = (client->addr & I2C_MASK_FLAG) | I2C_WR_FLAG |I2C_RS_FLAG;
    data[0] = addr;
	length = (len << 8) | 1;
	
	ret = i2c_master_send(client, (const char*)data, length);
    if (ret < 0) {
        GSE_ERR("lsm6ds0_acc_read_byte_sr error!!\n");
        return -EFAULT;
    }
	
	client->addr &= I2C_MASK_FLAG;
	
    return 0;
#else
	return hwmsen_read_block(client, addr, data, len);
#endif
}

int lsm6ds0_common_read_byte_sr(struct i2c_client *client, u8 addr, u8 *data, u8 len)
{
	return lsm6ds0_acc_read_byte_sr(lsm6ds3_i2c_client,addr,data,len);
}
EXPORT_SYMBOL(lsm6ds0_common_read_byte_sr);

int lsm6ds0_common_write_byte_sr(struct i2c_client *client, u8 *data, u8 len)
{
	int ret = 0;
	unsigned short length = 0;
	
	client = lsm6ds3_i2c_client;
	
	if(NULL == client)
	{
		GSE_ERR("lsm6ds0_acc_read_byte_sr client is NULL !!\n");
		return -EFAULT;
	}	
	
	GSE_ERR("xfl write client->addr=%d\n", client->addr);
    client->addr = (client->addr & I2C_MASK_FLAG) |I2C_RS_FLAG;
	length = len ;
	
	ret = i2c_master_send(client, (const char*)data, length);
    if (ret < 0) {
        GSE_ERR("lsm6ds0_acc_read_byte_sr error!!\n");
        return -EFAULT;
    }
	
	client->addr &= I2C_MASK_FLAG;
	
    return 0;
}
EXPORT_SYMBOL(lsm6ds0_common_write_byte_sr);

static void LSM6DS3_dumpReg(struct i2c_client *client)
{
  int i=0;
  u8 addr = 0x10;
  u8 regdata=0;
  for(i=0; i<25 ; i++)
  {
    //dump all
    lsm6ds0_acc_read_byte_sr(client,addr,&regdata,1);
	HWM_LOG("Reg addr=%x regdata=%x\n",addr,regdata);
	addr++;	
  }
}

static void LSM6DS3_power(struct acc_hw *hw, unsigned int on) 
{
	static unsigned int power_on = 0;
/*
	if(hw->power_id != POWER_NONE_MACRO)		// have externel LDO
	{        
		GSE_LOG("power %s\n", on ? "on" : "off");
		if(power_on == on)	// power status not change
		{
			GSE_LOG("ignore power control: %d\n", on);
		}
		else if(on)	// power on
		{
			if(!hwPowerOn(hw->power_id, hw->power_vol, "LSM6DS3"))
			{
				GSE_ERR("power on fails!!\n");
			}
		}
		else	// power off
		{
			if (!hwPowerDown(hw->power_id, "LSM6DS3"))
			{
				GSE_ERR("power off fail!!\n");
			}			  
		}
	}
*/
	power_on = on;    
}
/*----------------------------------------------------------------------------*/
#ifdef SW_CALIBRATION
#else
static int LSM6DS3_acc_write_rel_calibration(struct lsm6ds3_i2c_data *obj, int dat[LSM6DS3_GYRO_AXES_NUM])
{
    obj->cali_sw[LSM6DS3_AXIS_X] = obj->cvt.sign[LSM6DS3_AXIS_X]*dat[obj->cvt.map[LSM6DS3_AXIS_X]];
    obj->cali_sw[LSM6DS3_AXIS_Y] = obj->cvt.sign[LSM6DS3_AXIS_Y]*dat[obj->cvt.map[LSM6DS3_AXIS_Y]];
    obj->cali_sw[LSM6DS3_AXIS_Z] = obj->cvt.sign[LSM6DS3_AXIS_Z]*dat[obj->cvt.map[LSM6DS3_AXIS_Z]];
#if DEBUG		
		if(atomic_read(&obj->trace) & ACCEL_TRC_CALI)
		{
			GSE_LOG("test  (%5d, %5d, %5d) ->(%5d, %5d, %5d)->(%5d, %5d, %5d))\n", 
				obj->cvt.sign[LSM6DS3_AXIS_X],obj->cvt.sign[LSM6DS3_AXIS_Y],obj->cvt.sign[LSM6DS3_AXIS_Z],
				dat[LSM6DS3_AXIS_X], dat[LSM6DS3_AXIS_Y], dat[LSM6DS3_AXIS_Z],
				obj->cvt.map[LSM6DS3_AXIS_X],obj->cvt.map[LSM6DS3_AXIS_Y],obj->cvt.map[LSM6DS3_AXIS_Z]);
			GSE_LOG("write gyro calibration data  (%5d, %5d, %5d)\n", 
				obj->cali_sw[LSM6DS3_AXIS_X],obj->cali_sw[LSM6DS3_AXIS_Y],obj->cali_sw[LSM6DS3_AXIS_Z]);
		}
#endif
    return 0;
}
#endif
/*----------------------------------------------------------------------------*/
static int LSM6DS3_acc_ResetCalibration(struct i2c_client *client)
{
	struct lsm6ds3_i2c_data *obj = i2c_get_clientdata(client);	

	memset(obj->cali_sw, 0x00, sizeof(obj->cali_sw));
	return 0;    
}

/*----------------------------------------------------------------------------*/
static int LSM6DS3_acc_ReadCalibration(struct i2c_client *client, int dat[LSM6DS3_GYRO_AXES_NUM])
{
    struct lsm6ds3_i2c_data *obj = i2c_get_clientdata(client);
#ifdef SW_CALIBRATION
	dat[0] = obj->cali_sw[LSM6DS3_AXIS_X];
	dat[1] = obj->cali_sw[LSM6DS3_AXIS_Y];
	dat[2] = obj->cali_sw[LSM6DS3_AXIS_Z];
#else
    dat[obj->cvt.map[LSM6DS3_AXIS_X]] = obj->cvt.sign[LSM6DS3_AXIS_X]*obj->cali_sw[LSM6DS3_AXIS_X];
    dat[obj->cvt.map[LSM6DS3_AXIS_Y]] = obj->cvt.sign[LSM6DS3_AXIS_Y]*obj->cali_sw[LSM6DS3_AXIS_Y];
    dat[obj->cvt.map[LSM6DS3_AXIS_Z]] = obj->cvt.sign[LSM6DS3_AXIS_Z]*obj->cali_sw[LSM6DS3_AXIS_Z];
#endif
#if DEBUG		
		if(atomic_read(&obj->trace) & ACCEL_TRC_CALI)
		{
			GSE_LOG("Read gyro calibration data  (%5d, %5d, %5d)\n", 
				dat[LSM6DS3_AXIS_X],dat[LSM6DS3_AXIS_Y],dat[LSM6DS3_AXIS_Z]);
		}
#endif
                                       
    return 0;
}
/*----------------------------------------------------------------------------*/

static int LSM6DS3_acc_WriteCalibration(struct i2c_client *client, int dat[LSM6DS3_GYRO_AXES_NUM])
{
	struct lsm6ds3_i2c_data *obj = i2c_get_clientdata(client);
	int err = 0;
#ifdef SW_CALIBRATION 
#else
	int cali[LSM6DS3_GYRO_AXES_NUM];
#endif

	GSE_FUN();
	if(!obj || ! dat)
	{
		GSE_ERR("null ptr!!\n");
		return -EINVAL;
	}
	else
	{ 
#ifdef SW_CALIBRATION 
		obj->cali_sw[0] += dat[0];
		obj->cali_sw[1] += dat[1];
		obj->cali_sw[2] += dat[2];
#else      		
		cali[obj->cvt.map[LSM6DS3_AXIS_X]] = obj->cvt.sign[LSM6DS3_AXIS_X]*obj->cali_sw[LSM6DS3_AXIS_X];
		cali[obj->cvt.map[LSM6DS3_AXIS_Y]] = obj->cvt.sign[LSM6DS3_AXIS_Y]*obj->cali_sw[LSM6DS3_AXIS_Y];
		cali[obj->cvt.map[LSM6DS3_AXIS_Z]] = obj->cvt.sign[LSM6DS3_AXIS_Z]*obj->cali_sw[LSM6DS3_AXIS_Z]; 
		cali[LSM6DS3_AXIS_X] += dat[LSM6DS3_AXIS_X];
		cali[LSM6DS3_AXIS_Y] += dat[LSM6DS3_AXIS_Y];
		cali[LSM6DS3_AXIS_Z] += dat[LSM6DS3_AXIS_Z];
	#if DEBUG		
		if(atomic_read(&obj->trace) & ACCEL_TRC_CALI)
		{
			GSE_LOG("write gyro calibration data  (%5d, %5d, %5d)-->(%5d, %5d, %5d)\n", 
				dat[LSM6DS3_AXIS_X], dat[LSM6DS3_AXIS_Y], dat[LSM6DS3_AXIS_Z],
				cali[LSM6DS3_AXIS_X],cali[LSM6DS3_AXIS_Y],cali[LSM6DS3_AXIS_Z]);
		}
	#endif
		return LSM6DS3_acc_write_rel_calibration(obj, cali);
#endif
	} 

	return err;
}
/*----------------------------------------------------------------------------*/

static int LSM6DS3_CheckDeviceID(struct i2c_client *client)
{
	u8 databuf[10];    
	int res = 0;
	memset(databuf, 0, sizeof(u8)*10);    
	databuf[0] = LSM6DS3_FIXED_DEVID;    

	res = lsm6ds0_acc_read_byte_sr(client,LSM6DS3_WHO_AM_I,databuf,1);
	if (res < 0)
	{
		return LSM6DS3_ERR_I2C;
	}

    GSE_LOG("[accel] LSM6DS3  id %x!\n",databuf[0]);
	if(databuf[0]!=LSM6DS3_FIXED_DEVID)
	{
		return LSM6DS3_ERR_IDENTIFICATION;
	}
	
	return LSM6DS3_SUCCESS;
}

static int LSM6DS3_acc_SetPowerMode(struct i2c_client *client, bool enable)
{
	u8 databuf[2] = {0};    
	int res = 0;
	struct lsm6ds3_i2c_data *obj = i2c_get_clientdata(client);//obj_i2c_data;

	if(enable == sensor_power)
	{
		GSE_LOG("Sensor power status is newest!\n");
		return LSM6DS3_SUCCESS;
	}

	if(lsm6ds0_acc_read_byte_sr(client, LSM6DS3_CTRL1_XL, databuf,1))
	{
		GSE_ERR("read lsm6ds3 power ctl register err!\n");
		return LSM6DS3_ERR_I2C;
	}
	GSE_LOG("LSM6DS3_CTRL1_XL:databuf[0] =  %x!\n", databuf[0]);


	if(true == enable)
	{
		databuf[0] &= ~LSM6DS3_ACC_ODR_MASK;//clear lsm6ds3 gyro ODR bits
		databuf[0] |= obj->sample_rate;//LSM6DS3_ACC_ODR_104HZ; //default set 100HZ for LSM6DS3 acc
	}
	else
	{
		// do nothing
		databuf[0] &= ~LSM6DS3_ACC_ODR_MASK;//clear lsm6ds3 acc ODR bits
		databuf[0] |= LSM6DS3_ACC_ODR_POWER_DOWN;
	}
	databuf[1] = databuf[0];
	databuf[0] = LSM6DS3_CTRL1_XL;    
	res = i2c_master_send(client, databuf, 0x2);
	if(res <= 0)
	{
		GSE_LOG("LSM6DS3 set power mode: ODR 100hz failed!\n");
		return LSM6DS3_ERR_I2C;
	}	
	else
	{
		GSE_LOG("set LSM6DS3 gyro power mode:ODR 100HZ ok %d!\n", enable);
	}	

	if(lsm6ds0_acc_read_byte_sr(client, LSM6DS3_CTRL1_XL, databuf,1))
	{
		GSE_ERR("read lsm6ds3 power ctl register err!\n");
		return LSM6DS3_ERR_I2C;
	}
	GSE_LOG("LSM6DS3_CTRL1_XL:databuf[0] =  %x!\n", databuf[0]);

	sensor_power = enable;
	
	return LSM6DS3_SUCCESS;    
}


/*----------------------------------------------------------------------------*/
static int LSM6DS3_acc_SetFullScale(struct i2c_client *client, u8 acc_fs)
{
	u8 databuf[2] = {0};    
	int res = 0;
	struct lsm6ds3_i2c_data *obj = i2c_get_clientdata(client);
	
	GSE_FUN();     
		
	if(lsm6ds0_acc_read_byte_sr(client, LSM6DS3_CTRL1_XL, databuf,1))
	{
		GSE_ERR("read LSM6DS3_CTRL1_XL err!\n");
		return LSM6DS3_ERR_I2C;
	}
	else
	{
		GSE_LOG("read  LSM6DS3_CTRL1_XL register: 0x%x\n", databuf[0]);
	}

	databuf[0] &= ~LSM6DS3_ACC_RANGE_MASK;//clear 
	databuf[0] |= acc_fs;
	
	databuf[1] = databuf[0];
	databuf[0] = LSM6DS3_CTRL1_XL; 
	
	res = i2c_master_send(client, databuf, 0x2);
	if(res <= 0)
	{
		GSE_ERR("write full scale register err!\n");
		return LSM6DS3_ERR_I2C;
	}
	switch(acc_fs)
	{
		case LSM6DS3_ACC_RANGE_2g:
			obj->sensitivity = LSM6DS3_ACC_SENSITIVITY_2G;
			break;
		case LSM6DS3_ACC_RANGE_4g:
			obj->sensitivity = LSM6DS3_ACC_SENSITIVITY_4G;
			break;
		case LSM6DS3_ACC_RANGE_8g:
			obj->sensitivity = LSM6DS3_ACC_SENSITIVITY_8G;
			break;
		case LSM6DS3_ACC_RANGE_16g:
			obj->sensitivity = LSM6DS3_ACC_SENSITIVITY_16G;
			break;
		default:
			obj->sensitivity = LSM6DS3_ACC_SENSITIVITY_2G;
			break;
	}

	if(lsm6ds0_acc_read_byte_sr(client, LSM6DS3_CTRL9_XL, databuf,1))
	{
		GSE_ERR("read LSM6DS3_CTRL9_XL err!\n");
		return LSM6DS3_ERR_I2C;
	}
	else
	{
		GSE_LOG("read  LSM6DS3_CTRL9_XL register: 0x%x\n", databuf[0]);
	}

	databuf[0] &= ~LSM6DS3_ACC_ENABLE_AXIS_MASK;//clear 
	databuf[0] |= LSM6DS3_ACC_ENABLE_AXIS_X | LSM6DS3_ACC_ENABLE_AXIS_Y| LSM6DS3_ACC_ENABLE_AXIS_Z;
	
	databuf[1] = databuf[0];
	databuf[0] = LSM6DS3_CTRL9_XL; 
	
	res = i2c_master_send(client, databuf, 0x2);
	if(res <= 0)
	{
		GSE_ERR("write full scale register err!\n");
		return LSM6DS3_ERR_I2C;
	}

	return LSM6DS3_SUCCESS;    
}

/*----------------------------------------------------------------------------*/
// set the acc sample rate
static int LSM6DS3_acc_SetSampleRate(struct i2c_client *client, u8 sample_rate)
{
	u8 databuf[2] = {0}; 
	int res = 0;
	GSE_FUN();    

	res = LSM6DS3_acc_SetPowerMode(client, true);	//set Sample Rate will enable power and should changed power status
	if(res != LSM6DS3_SUCCESS)	
	{
		return res;
	}

	if(lsm6ds0_acc_read_byte_sr(client, LSM6DS3_CTRL1_XL, databuf,1))
	{
		GSE_ERR("read acc data format register err!\n");
		return LSM6DS3_ERR_I2C;
	}
	else
	{
		GSE_LOG("read  acc data format register: 0x%x\n", databuf[0]);
	}

	databuf[0] &= ~LSM6DS3_ACC_ODR_MASK;//clear 
	databuf[0] |= sample_rate;
	
	databuf[1] = databuf[0];
	databuf[0] = LSM6DS3_CTRL1_XL; 
		
	res = i2c_master_send(client, databuf, 0x2);
	if(res <= 0)
	{
		GSE_ERR("write sample rate register err!\n");
		return LSM6DS3_ERR_I2C;
	}

	return LSM6DS3_SUCCESS;    
}

/*----------------------------------------------------------------------------*/
static int LSM6DS3_ReadAccData(struct i2c_client *client, char *buf, int bufsize)
{
	struct lsm6ds3_i2c_data *obj = (struct lsm6ds3_i2c_data*)i2c_get_clientdata(client);
	u8 databuf[20];
	int acc[LSM6DS3_ACC_AXES_NUM];
	int res = 0;
	memset(databuf, 0, sizeof(u8)*10);

	if(NULL == buf)
	{
		return -1;
	}
	if(NULL == client)
	{
		*buf = 0;
		return -2;
	}

	if(sensor_power == false)
	{
		res = LSM6DS3_acc_SetPowerMode(client, true);
		if(res)
		{
			GSE_ERR("Power on lsm6ds3 error %d!\n", res);
		}
		msleep(20);
	}
	
	res = LSM6DS3_ReadAccRawData(client, obj->data);
	if(res < 0)
	{        
		GSE_ERR("I2C error: ret value=%d", res);
		return -3;
	}
	else
	{
	#if 1
		obj->data[LSM6DS3_AXIS_X] = (long)(obj->data[LSM6DS3_AXIS_X]) * obj->sensitivity*GRAVITY_EARTH_1000/(1000*1000); //NTC
		obj->data[LSM6DS3_AXIS_Y] = (long)(obj->data[LSM6DS3_AXIS_Y]) * obj->sensitivity*GRAVITY_EARTH_1000/(1000*1000);
		obj->data[LSM6DS3_AXIS_Z] = (long)(obj->data[LSM6DS3_AXIS_Z]) * obj->sensitivity*GRAVITY_EARTH_1000/(1000*1000);
			
		/*remap coordinate*/
		acc[obj->cvt.map[LSM6DS3_AXIS_X]] = obj->cvt.sign[LSM6DS3_AXIS_X]*obj->data[LSM6DS3_AXIS_X];
		acc[obj->cvt.map[LSM6DS3_AXIS_Y]] = obj->cvt.sign[LSM6DS3_AXIS_Y]*obj->data[LSM6DS3_AXIS_Y];
		acc[obj->cvt.map[LSM6DS3_AXIS_Z]] = obj->cvt.sign[LSM6DS3_AXIS_Z]*obj->data[LSM6DS3_AXIS_Z];

		acc[LSM6DS3_AXIS_X] += obj->cali_sw[LSM6DS3_AXIS_X];
		acc[LSM6DS3_AXIS_Y] += obj->cali_sw[LSM6DS3_AXIS_Y];
		acc[LSM6DS3_AXIS_Z] += obj->cali_sw[LSM6DS3_AXIS_Z];

		//GSE_LOG("Mapped gsensor data: %d, %d, %d!\n", acc[LSM6DS3_AXIS_X], acc[LSM6DS3_AXIS_Y], acc[LSM6DS3_AXIS_Z]);

		//Out put the mg
		/*
		acc[LSM6DS3_AXIS_X] = acc[LSM6DS3_AXIS_X] * GRAVITY_EARTH_1000 / obj->reso->sensitivity;
		acc[LSM6DS3_AXIS_Y] = acc[LSM6DS3_AXIS_Y] * GRAVITY_EARTH_1000 / obj->reso->sensitivity;
		acc[LSM6DS3_AXIS_Z] = acc[LSM6DS3_AXIS_Z] * GRAVITY_EARTH_1000 / obj->reso->sensitivity;		
		*/
	#endif


		sprintf(buf, "%04x %04x %04x", acc[LSM6DS3_AXIS_X], acc[LSM6DS3_AXIS_Y], acc[LSM6DS3_AXIS_Z]);
	
		if(atomic_read(&obj->trace) & ADX_TRC_IOCTL)//atomic_read(&obj->trace) & ADX_TRC_IOCTL
		{
			//GSE_LOG("gsensor data: %s!\n", buf);
			GSE_LOG("raw data:obj->data:%04x %04x %04x\n", obj->data[LSM6DS3_AXIS_X], obj->data[LSM6DS3_AXIS_Y], obj->data[LSM6DS3_AXIS_Z]);
			GSE_LOG("acc:%04x %04x %04x\n", acc[LSM6DS3_AXIS_X], acc[LSM6DS3_AXIS_Y], acc[LSM6DS3_AXIS_Z]);
	
			//LSM6DS3_dumpReg(client);
		}
	}
	
	return 0;
}
static int LSM6DS3_ReadAccRawData(struct i2c_client *client, s16 data[LSM6DS3_ACC_AXES_NUM])
{
	int err = 0;
	char databuf[6] = {0};
	
	if(NULL == client)
	{
		err = -EINVAL;
	}	
	else
	{
		if(hwmsen_read_block(client, LSM6DS3_OUTX_L_XL, databuf, 6))
		{
			GSE_ERR("LSM6DS3 read acc data  error\n");
			return -2;
		}
		else
		{
			data[LSM6DS3_AXIS_X] = (s16)((databuf[LSM6DS3_AXIS_X*2+1] << 8) | (databuf[LSM6DS3_AXIS_X*2]));
			data[LSM6DS3_AXIS_Y] = (s16)((databuf[LSM6DS3_AXIS_Y*2+1] << 8) | (databuf[LSM6DS3_AXIS_Y*2]));
			data[LSM6DS3_AXIS_Z] = (s16)((databuf[LSM6DS3_AXIS_Z*2+1] << 8) | (databuf[LSM6DS3_AXIS_Z*2]));	
		}      
	}
	return err;
}

/*----------------------------------------------------------------------------*/
static int LSM6DS3_ReadChipInfo(struct i2c_client *client, char *buf, int bufsize)
{
	u8 databuf[10];    

	memset(databuf, 0, sizeof(u8)*10);

	if((NULL == buf)||(bufsize<=30))
	{
		return -1;
	}
	
	if(NULL == client)
	{
		*buf = 0;
		return -2;
	}

	sprintf(buf, "LSM6DS3 Chip");
	return 0;
}

/*----------------------------------------------------------------------------*/
static ssize_t show_chipinfo_value(struct device_driver *ddri, char *buf)
{
	struct i2c_client *client = lsm6ds3_i2c_client;
	char strbuf[LSM6DS3_BUFSIZE];
	if(NULL == client)
	{
		GSE_ERR("i2c client is null!!\n");
		return 0;
	}
	
	LSM6DS3_ReadChipInfo(client, strbuf, LSM6DS3_BUFSIZE);
	return snprintf(buf, PAGE_SIZE, "%s\n", strbuf);        
}
/*----------------------------------------------------------------------------*/
static ssize_t show_sensordata_value(struct device_driver *ddri, char *buf)
{
	struct i2c_client *client = lsm6ds3_i2c_client;
	char strbuf[LSM6DS3_BUFSIZE];
	int x,y,z;
	
	if(NULL == client)
	{
		GSE_ERR("i2c client is null!!\n");
		return 0;
	}
	
	LSM6DS3_ReadAccData(client, strbuf, LSM6DS3_BUFSIZE);
	sscanf(strbuf, "%x %x %x", &x, &y, &z);	
	return snprintf(buf, PAGE_SIZE, "%d, %d, %d\n", x,y,z);            
}
static ssize_t show_sensorrawdata_value(struct device_driver *ddri, char *buf)
{
	struct i2c_client *client = lsm6ds3_i2c_client;
	s16 data[LSM6DS3_ACC_AXES_NUM] = {0};
	
	if(NULL == client)
	{
		GSE_ERR("i2c client is null!!\n");
		return 0;
	}
	
	LSM6DS3_ReadAccRawData(client, data);
	return snprintf(buf, PAGE_SIZE, "%x,%x,%x\n", data[0],data[1],data[2]);            
}

/*
static ssize_t show_trace_value(struct device_driver *ddri, char *buf)
{
	ssize_t res;
	struct lsm6ds3_i2c_data *obj = obj_i2c_data;
	
	if (obj == NULL)
	{
		GSE_ERR("i2c_data obj is null!!\n");
		return 0;
	}
	
	res = snprintf(buf, PAGE_SIZE, "0x%04X\n", atomic_read(&obj->trace));     
	return res;    
}

static ssize_t store_trace_value(struct device_driver *ddri, const char *buf, size_t count)
{
	struct lsm6ds3_i2c_data *obj = obj_i2c_data;
	int trace;
	if (obj == NULL)
	{
		GSE_ERR("i2c_data obj is null!!\n");
		return count;
	}
	
	if(1 == sscanf(buf, "0x%x", &trace))
	{
		atomic_set(&obj->trace, trace);
	}	
	else
	{
		GSE_ERR("invalid content: '%s', length = %zu\n", buf, count);
	}
	
	return count;    
}
*/
/*
static ssize_t show_chipinit_value(struct device_driver *ddri, char *buf)
{
	ssize_t res;
	struct lsm6ds3_i2c_data *obj = obj_i2c_data;
	if (obj == NULL)
	{
		GSE_ERR("i2c_data obj is null!!\n");
		return 0;
	}
	
	res = snprintf(buf, PAGE_SIZE, "0x%04X\n", atomic_read(&obj->trace));     
	return res;    
}
*/
/*
static ssize_t store_chipinit_value(struct device_driver *ddri, const char *buf, size_t count)
{
	struct lsm6ds3_i2c_data *obj = obj_i2c_data;

	if (obj == NULL)
	{
		GSE_ERR("i2c_data obj is null!!\n");
		return count;
	}
	
	LSM6DS3_init_client(obj->client, true);
	LSM6DS3_dumpReg(obj->client);
	
	return count;    
}
*/
static ssize_t show_status_value(struct device_driver *ddri, char *buf)
{
	ssize_t len = 0;    
	struct lsm6ds3_i2c_data *obj = obj_i2c_data;
	if (obj == NULL)
	{
		GSE_ERR("i2c_data obj is null!!\n");
		return 0;
	}	
	
	if(obj->hw)
	{
		len += snprintf(buf+len, PAGE_SIZE-len, "CUST: i2c_num=%d, direction=%d, sensitivity = %d,(power_id=%d, power_vol=%d)\n", 
	            obj->hw->i2c_num, obj->hw->direction, obj->sensitivity, obj->hw->power_id, obj->hw->power_vol);   
	LSM6DS3_dumpReg(obj->client);
	}
	else
	{
		len += snprintf(buf+len, PAGE_SIZE-len, "CUST: NULL\n");
	}
	return len;    
}
static ssize_t show_layout_value(struct device_driver *ddri, char *buf)
{
	struct lsm6ds3_i2c_data *data = obj_i2c_data;
	if(NULL == data)
	{
		GSE_LOG("lsm6ds3_i2c_data is null!!\n");
		return -1;
	}

	return sprintf(buf, "(%d, %d)\n[%+2d %+2d %+2d]\n[%+2d %+2d %+2d]\n",
		data->hw->direction,atomic_read(&data->layout),	data->cvt.sign[0], data->cvt.sign[1],
		data->cvt.sign[2],data->cvt.map[0], data->cvt.map[1], data->cvt.map[2]);
}
/*----------------------------------------------------------------------------*/
static ssize_t store_layout_value(struct device_driver *ddri, const char *buf, size_t count)
{
	int layout = 0;
	struct lsm6ds3_i2c_data *data = obj_i2c_data;

	if(NULL == data)
	{
		GSE_LOG("lsm6ds3_i2c_data is null!!\n");
		return count;
	}

	

	if(1 == sscanf(buf, "%d", &layout))
	{
		atomic_set(&data->layout, layout);
		if(!hwmsen_get_convert(layout, &data->cvt))
		{
			GSE_LOG("HWMSEN_GET_CONVERT function error!\r\n");
		}
		else if(!hwmsen_get_convert(data->hw->direction, &data->cvt))
		{
			GSE_LOG("invalid layout: %d, restore to %d\n", layout, data->hw->direction);
		}
		else
		{
			GSE_LOG("invalid layout: (%d, %d)\n", layout, data->hw->direction);
			hwmsen_get_convert(0, &data->cvt);
		}
	}
	else
	{
		GSE_LOG("invalid format = '%s'\n", buf);
	}

	return count;
}

/*----------------------------------------------------------------------------*/

static DRIVER_ATTR(chipinfo,             S_IRUGO, show_chipinfo_value,      NULL);
static DRIVER_ATTR(sensorrawdata,           S_IRUGO, show_sensorrawdata_value,    NULL);
static DRIVER_ATTR(sensordata,           S_IRUGO, show_sensordata_value,    NULL);
static DRIVER_ATTR(status,               S_IRUGO, show_status_value,        NULL);
//static DRIVER_ATTR(trace,      S_IWUGO | S_IRUGO, show_trace_value,         store_trace_value);
//static DRIVER_ATTR(chipinit,      S_IWUGO | S_IRUGO, show_chipinit_value,         store_chipinit_value);
static DRIVER_ATTR(layout,      S_IRUGO | S_IWUSR, show_layout_value, store_layout_value);

/*----------------------------------------------------------------------------*/
static struct driver_attribute *LSM6DS3_attr_list[] = {
	&driver_attr_chipinfo,     /*chip information*/
	&driver_attr_sensordata,   /*dump sensor data*/	
	&driver_attr_sensorrawdata,   /*dump sensor raw data*/	
	&driver_attr_status,  
	//&driver_attr_trace,        /*trace log*/
	&driver_attr_layout,
	//&driver_attr_chipinit,
};
/*----------------------------------------------------------------------------*/
static int lsm6ds3_create_attr(struct device_driver *driver) 
{
	int idx, err = 0;
	int num = (int)(sizeof(LSM6DS3_attr_list)/sizeof(LSM6DS3_attr_list[0]));
	if (driver == NULL)
	{
		return -EINVAL;
	}

	for(idx = 0; idx < num; idx++)
	{
		if(0 != (err = driver_create_file(driver,  LSM6DS3_attr_list[idx])))
		{            
			GSE_ERR("driver_create_file (%s) = %d\n",  LSM6DS3_attr_list[idx]->attr.name, err);
			break;
		}
	}    
	return err;
}
/*----------------------------------------------------------------------------*/
static int lsm6ds3_delete_attr(struct device_driver *driver)
{
	int idx ,err = 0;
	int num = (int)(sizeof( LSM6DS3_attr_list)/sizeof( LSM6DS3_attr_list[0]));

	if(driver == NULL)
	{
		return -EINVAL;
	}	

	for(idx = 0; idx < num; idx++)
	{
		driver_remove_file(driver,  LSM6DS3_attr_list[idx]);
	}
	return err;
}
static int LSM6DS3_Set_RegInc(struct i2c_client *client, bool inc)
{
	u8 databuf[2] = {0};    
	int res = 0;
	//GSE_FUN();     
	
	if(lsm6ds0_acc_read_byte_sr(client, LSM6DS3_CTRL3_C, databuf,1))
	{
		GSE_ERR("read LSM6DS3_CTRL3_XL err!\n");
		return LSM6DS3_ERR_I2C;
	}
	else
	{
		GSE_LOG("read  LSM6DS3_CTRL3_C register: 0x%x\n", databuf[0]);
	}
	if(inc)
	{
		databuf[0] |= LSM6DS3_CTRL3_C_IFINC;
		
		databuf[1] = databuf[0];
		databuf[0] = LSM6DS3_CTRL3_C; 
		
		res = i2c_master_send(client, databuf, 0x2);
		if(res <= 0)
		{
			GSE_ERR("write full scale register err!\n");
			return LSM6DS3_ERR_I2C;
		}
	}

	return LSM6DS3_SUCCESS;    
}

/*----------------------------------------------------------------------------*/
static int LSM6DS3_init_client(struct i2c_client *client, bool enable)
{
	struct lsm6ds3_i2c_data *obj = i2c_get_clientdata(client);
	int res = 0;
	GSE_FUN();	
	res = LSM6DS3_CheckDeviceID(client);
	if(res != LSM6DS3_SUCCESS)
	{
		return res;
	}

	res = LSM6DS3_Set_RegInc(client, true);
	if(res != LSM6DS3_SUCCESS) 
	{
		return res;
	}

	res = LSM6DS3_acc_SetFullScale(client,LSM6DS3_ACC_RANGE_2g);//we have only this choice
	if(res != LSM6DS3_SUCCESS) 
	{
		return res;
	}

	//res = LSM6DS3_acc_SetSampleRate(client, LSM6DS3_ACC_ODR_104HZ);
	res = LSM6DS3_acc_SetSampleRate(client, obj->sample_rate);
	if(res != LSM6DS3_SUCCESS ) 
	{
		return res;
	}
	
	res = LSM6DS3_acc_SetPowerMode(client, enable);
	if(res != LSM6DS3_SUCCESS)
	{
		return res;
	}

	GSE_LOG("LSM6DS3_init_client OK!\n");
	//acc setting
		
#ifdef CONFIG_LSM6DS3_LOWPASS
	memset(&obj->fir, 0x00, sizeof(obj->fir));  
#endif

	return LSM6DS3_SUCCESS;
}
/*----------------------------------------------------------------------------*/
static int lsm6ds3_open_report_data(int open)
{
    //should queuq work to report event if  is_report_input_direct=true
	
    return 0;
}

// if use  this typ of enable , Gsensor only enabled but not report inputEvent to HAL

static int lsm6ds3_enable_nodata(int en)
{
	int value = en;
	int err = 0;
	struct lsm6ds3_i2c_data *priv = obj_i2c_data;

	if(priv == NULL)
	{
		GSE_ERR("obj_i2c_data is NULL!\n");
		return -1;
	}

	if(value == 1)
	{
		enable_status = true;
	}
	else
	{
		enable_status = false;
		priv->sample_rate = LSM6DS3_ACC_ODR_104HZ; //default rate
	}
	GSE_LOG("enable value=%d, sensor_power =%d\n",value,sensor_power);
	
	if(((value == 0) && (sensor_power == false)) ||((value == 1) && (sensor_power == true)))
	{
		GSE_LOG("Gsensor device have updated!\n");
	}
	else if(!pedo_enable_status && !tilt_enable_status)
	{
		err = LSM6DS3_acc_SetPowerMode( priv->client, enable_status);					
	}

    GSE_LOG("%s OK!\n",__FUNCTION__);
    return err;
}

static int lsm6ds3_set_delay(u64 ns)
{
    int value =0;
	int err = 0;
	int sample_delay = 0;
	struct lsm6ds3_i2c_data *priv = obj_i2c_data;

	value = (int)ns/1000/1000;
	if(priv == NULL)
	{
		return -1;
	}
					
	if(value <= 5)
	{
		sample_delay = LSM6DS3_ACC_ODR_208HZ;
	}
	else if(value <= 10)
	{
		sample_delay = LSM6DS3_ACC_ODR_104HZ;
	}
	else
	{
		sample_delay = LSM6DS3_ACC_ODR_52HZ;
	}
	priv->sample_rate = sample_delay;
	err = LSM6DS3_acc_SetSampleRate(priv->client, sample_delay);
	if(err != LSM6DS3_SUCCESS ) 
	{
		GSE_ERR("Set delay parameter error!\n");
	}

	if(value >= 50)
	{
		atomic_set(&priv->filter, 0);
	}
	else
	{				
		priv->fir.num = 0;
		priv->fir.idx = 0;
		priv->fir.sum[LSM6DS3_AXIS_X] = 0;
		priv->fir.sum[LSM6DS3_AXIS_Y] = 0;
		priv->fir.sum[LSM6DS3_AXIS_Z] = 0;
		atomic_set(&priv->filter, 1);
	}

    return 0;
}

static int agold_get_raw_data(int* x, int* y, int* z)
{
	char buff[LSM6DS3_BUFSIZE];
   	mutex_lock(&lsm6ds3_init_mutex);
	LSM6DS3_ReadAccData(obj_i2c_data->client, buff, LSM6DS3_BUFSIZE);
	mutex_unlock(&lsm6ds3_init_mutex);
	sscanf(buff, "%x %x %x", x, y, z);
	return 0;
}

static int lsm6ds3_get_data(int* x, int* y, int* z, int *status)
{
    char buff[LSM6DS3_BUFSIZE];
	struct lsm6ds3_i2c_data *priv = obj_i2c_data;
		
	if(priv == NULL)
	{
		GSE_LOG("[accel],obj_i2c_data is NULL!\n");
		return -1;
	}
	if(atomic_read(&priv->trace) & ACCEL_TRC_DATA)
	{
		GSE_LOG("[accel],%s (%d),  \n",__FUNCTION__,__LINE__);
	}
	memset(buff, 0, sizeof(buff));
	mutex_lock(&lsm6ds3_read_mutex);
	LSM6DS3_ReadAccData(obj_i2c_data->client, buff, LSM6DS3_BUFSIZE);
	mutex_unlock(&lsm6ds3_read_mutex);	
	sscanf(buff, "%x %x %x", x, y, z);	
	*status = SENSOR_STATUS_ACCURACY_MEDIUM;				
    return 0;
}


/****************************************************************************** 
 * Function Configuration
******************************************************************************/
static int lsm6ds3_open(struct inode *inode, struct file *file)
{
	file->private_data = lsm6ds3_i2c_client;

	if(file->private_data == NULL)
	{
		GSE_ERR("null pointer!!\n");
		return -EINVAL;
	}
	return nonseekable_open(inode, file);
}
/*----------------------------------------------------------------------------*/
static int lsm6ds3_release(struct inode *inode, struct file *file)
{
	file->private_data = NULL;
	return 0;
}
/*----------------------------------------------------------------------------*/
static long lsm6ds3_acc_unlocked_ioctl(struct file *file, unsigned int cmd,
       unsigned long arg)
{
	struct i2c_client *client = (struct i2c_client*)file->private_data;
	struct lsm6ds3_i2c_data *obj = (struct lsm6ds3_i2c_data*)i2c_get_clientdata(client);	
	char strbuf[LSM6DS3_BUFSIZE];
	void __user *data;
	struct SENSOR_DATA sensor_data;
	int err = 0;
	int cali[3];

	//GSE_FUN(f);
	if(_IOC_DIR(cmd) & _IOC_READ)
	{
		err = !access_ok(VERIFY_WRITE, (void __user *)arg, _IOC_SIZE(cmd));
	}
	else if(_IOC_DIR(cmd) & _IOC_WRITE)
	{
		err = !access_ok(VERIFY_READ, (void __user *)arg, _IOC_SIZE(cmd));
	}

	if(err)
	{
		GSE_ERR("access error: %08X, (%2d, %2d)\n", cmd, _IOC_DIR(cmd), _IOC_SIZE(cmd));
		return -EFAULT;
	}

	switch(cmd)
	{
		case GSENSOR_IOCTL_INIT:			
			break;

		case GSENSOR_IOCTL_READ_CHIPINFO:
			data = (void __user *) arg;
			if(data == NULL)
			{
				err = -EINVAL;
				break;	  
			}
						
			LSM6DS3_ReadChipInfo(client, strbuf, LSM6DS3_BUFSIZE);
			
			if(copy_to_user(data, strbuf, strlen(strbuf)+1))
			{
				err = -EFAULT;
				break;
			}				 
			break;	  

		case GSENSOR_IOCTL_READ_SENSORDATA:
			data = (void __user *) arg;
			if(data == NULL)
			{
				err = -EINVAL;
				break;	  
			}
			
			LSM6DS3_ReadAccData(client, strbuf, LSM6DS3_BUFSIZE);
			
			if(copy_to_user(data, strbuf, strlen(strbuf)+1))
			{
				err = -EFAULT;
				break;	  
			}				 
			break;

		case GSENSOR_IOCTL_READ_GAIN:
			data = (void __user *) arg;
			if(data == NULL)
			{
				err = -EINVAL;
				break;	  
			}			

			break;

		case GSENSOR_IOCTL_READ_OFFSET:
			data = (void __user *) arg;
			if(data == NULL)
			{
				err = -EINVAL;
				break;	  
			}

			break;

		case GSENSOR_IOCTL_READ_RAW_DATA:
			data = (void __user *) arg;
			if(data == NULL)
			{
				err = -EINVAL;
				break;	  
			}
			
			LSM6DS3_ReadAccRawData(client, (s16 *)strbuf);
			if(copy_to_user(data, strbuf, strlen(strbuf)+1))
			{
				err = -EFAULT;
				break;	  
			}
			break;	  

		case GSENSOR_IOCTL_SET_CALI:
			data = (void __user*)arg;
			if(data == NULL)
			{
				err = -EINVAL;
				break;	  
			}
			if(copy_from_user(&sensor_data, data, sizeof(sensor_data)))
			{
				err = -EFAULT;
				break;	  
			}
			if(atomic_read(&obj->suspend))
			{
				GSE_ERR("Perform calibration in suspend state!!\n");
				err = -EINVAL;
			}
			else
			{
		#if 0
			cali[LSM6DS3_AXIS_X] = (s64)(sensor_data.x) * 1000*1000/(obj->sensitivity*GRAVITY_EARTH_1000); //NTC
			cali[LSM6DS3_AXIS_Y] = (s64)(sensor_data.y) * 1000*1000/(obj->sensitivity*GRAVITY_EARTH_1000);
			cali[LSM6DS3_AXIS_Z] = (s64)(sensor_data.z) * 1000*1000/(obj->sensitivity*GRAVITY_EARTH_1000);
		#else
			cali[LSM6DS3_AXIS_X] = (s64)(sensor_data.x);
			cali[LSM6DS3_AXIS_Y] = (s64)(sensor_data.y);	
			cali[LSM6DS3_AXIS_Z] = (s64)(sensor_data.z);	
		#endif
				err = LSM6DS3_acc_WriteCalibration(client, cali);			 
			}
			break;

		case GSENSOR_IOCTL_CLR_CALI:
			err = LSM6DS3_acc_ResetCalibration(client);
			break;

		case GSENSOR_IOCTL_GET_CALI:
			data = (void __user*)arg;
			if(data == NULL)
			{
				err = -EINVAL;
				break;	  
			}
			err = LSM6DS3_acc_ReadCalibration(client, cali);
			if(err < 0)
			{
				break;
			}
					
		#if 0
			sensor_data.x = (s64)(cali[LSM6DS3_AXIS_X]) * obj->sensitivity*GRAVITY_EARTH_1000/(1000*1000); //NTC
			sensor_data.y = (s64)(cali[LSM6DS3_AXIS_Y]) * obj->sensitivity*GRAVITY_EARTH_1000/(1000*1000);
			sensor_data.z = (s64)(cali[LSM6DS3_AXIS_Z]) * obj->sensitivity*GRAVITY_EARTH_1000/(1000*1000);
		#else
			sensor_data.x = (s64)(cali[LSM6DS3_AXIS_X]);
			sensor_data.y = (s64)(cali[LSM6DS3_AXIS_Y]);
			sensor_data.z = (s64)(cali[LSM6DS3_AXIS_Z]);
		#endif
			if(copy_to_user(data, &sensor_data, sizeof(sensor_data)))
			{
				err = -EFAULT;
				break;
			}		
			break;
		
		default:
			GSE_ERR("unknown IOCTL: 0x%08x\n", cmd);
			err = -ENOIOCTLCMD;
			break;
			
	}

	return err;
}
#ifdef CONFIG_COMPAT
static long lsm6ds3_acc_compat_ioctl(struct file *file, unsigned int cmd,
       unsigned long arg)
{
    long err = 0;

	void __user *arg32 = compat_ptr(arg);
	
	if (!file->f_op || !file->f_op->unlocked_ioctl)
		return -ENOTTY;
	
    switch (cmd)
    {
        case COMPAT_GSENSOR_IOCTL_READ_SENSORDATA:
            if (arg32 == NULL)
            {
                err = -EINVAL;
                break;    
            }
		
		    err = file->f_op->unlocked_ioctl(file, GSENSOR_IOCTL_READ_SENSORDATA, (unsigned long)arg32);
		    if (err){
		        GSE_ERR("GSENSOR_IOCTL_READ_SENSORDATA unlocked_ioctl failed.");
		        return err;
		    }
			break;
			
        case COMPAT_GSENSOR_IOCTL_SET_CALI:
            if (arg32 == NULL)
            {
                err = -EINVAL;
                break;    
            }
		
		    err = file->f_op->unlocked_ioctl(file, GSENSOR_IOCTL_SET_CALI, (unsigned long)arg32);
		    if (err){
		        GSE_ERR("GSENSOR_IOCTL_SET_CALI unlocked_ioctl failed.");
		        return err;
		    }
			break;
			
        case COMPAT_GSENSOR_IOCTL_GET_CALI:
            if (arg32 == NULL)
            {
                err = -EINVAL;
                break;    
            }
		
		    err = file->f_op->unlocked_ioctl(file, GSENSOR_IOCTL_GET_CALI, (unsigned long)arg32);
		    if (err){
		        GSE_ERR("GSENSOR_IOCTL_GET_CALI unlocked_ioctl failed.");
		        return err;
		    }
			break;
			
        case COMPAT_GSENSOR_IOCTL_CLR_CALI:
            if (arg32 == NULL)
            {
                err = -EINVAL;
                break;    
            }
		
		    err = file->f_op->unlocked_ioctl(file, GSENSOR_IOCTL_CLR_CALI, (unsigned long)arg32);
		    if (err){
		        GSE_ERR("GSENSOR_IOCTL_CLR_CALI unlocked_ioctl failed.");
		        return err;
		    }
			break;

        default:
            GSE_ERR("unknown IOCTL: 0x%08x\n", cmd);
            err = -ENOIOCTLCMD;
        break;

    }

    return err;
}
#endif

/*----------------------------------------------------------------------------*/
static struct file_operations lsm6ds3_acc_fops = {
	.owner = THIS_MODULE,
	.open = lsm6ds3_open,
	.release = lsm6ds3_release,
	.unlocked_ioctl = lsm6ds3_acc_unlocked_ioctl,
#ifdef CONFIG_COMPAT
	.compat_ioctl = lsm6ds3_acc_compat_ioctl,
#endif
};
/*----------------------------------------------------------------------------*/
static struct miscdevice lsm6ds3_acc_device = {
	.minor = MISC_DYNAMIC_MINOR,
	.name = "lsm6ds3_acc",
	.fops = &lsm6ds3_acc_fops,
};
/*----------------------------------------------------------------------------*/
#ifndef CONFIG_HAS_EARLYSUSPEND
/*----------------------------------------------------------------------------*/
static int lsm6ds3_acc_suspend(struct i2c_client *client, pm_message_t msg) 
{
	struct lsm6ds3_i2c_data *obj = i2c_get_clientdata(client);    
	int err = 0;
	
	GSE_FUN();
	if(msg.event == PM_EVENT_SUSPEND)
	{   
		if(obj == NULL)
		{
			GSE_ERR("null pointer!!\n");
			return -EINVAL;
		}
		atomic_set(&obj->suspend, 1);

		if(pedo_enable_status  || tilt_enable_status)
		{
			return 0;
		}
		err = LSM6DS3_acc_SetPowerMode(obj->client, false);
		if(err)
		{
			GSE_ERR("write power control fail!!\n");
			return err;
		}
		
		sensor_power = false;
		
		LSM6DS3_power(obj->hw, 0);

	}
	return err;
}
/*----------------------------------------------------------------------------*/
static int lsm6ds3_acc_resume(struct i2c_client *client)
{
	struct lsm6ds3_i2c_data *obj = i2c_get_clientdata(client);        
	int err = 0;

	GSE_FUN();
	if(obj == NULL)
	{
		GSE_ERR("null pointer!!\n");
		return -1;
	}

	if(pedo_enable_status  || tilt_enable_status)
	{
		atomic_set(&obj->suspend, 0);
		return 0;
	}
	LSM6DS3_power(obj->hw, 1);
	err = LSM6DS3_acc_SetPowerMode(obj->client, enable_status);
	if(err)
	{
		GSE_ERR("initialize client fail! err code %d!\n", err);
		return err ;        
	}
	atomic_set(&obj->suspend, 0);  

	return 0;
}
/*----------------------------------------------------------------------------*/
#else /*CONFIG_HAS_EARLY_SUSPEND is defined*/
/*----------------------------------------------------------------------------*/
static void lsm6ds3_early_suspend(struct early_suspend *h) 
{
	struct lsm6ds3_i2c_data *obj = container_of(h, struct lsm6ds3_i2c_data, early_drv);   
	int err;
	GSE_FUN();    

	if(obj == NULL)
	{
		GSE_ERR("null pointer!!\n");
		return;
	}
	atomic_set(&obj->suspend, 1);

	if(pedo_enable_status  || tilt_enable_status)
	{
		return;
	}
	err = LSM6DS3_acc_SetPowerMode(obj->client, false);
	if(err)
	{
		GSE_ERR("write power control fail!!\n");
		return;
	}

	sensor_power = false;
	
	LSM6DS3_power(obj->hw, 0);
}
/*----------------------------------------------------------------------------*/
static void lsm6ds3_late_resume(struct early_suspend *h)
{
	struct lsm6ds3_i2c_data *obj = container_of(h, struct lsm6ds3_i2c_data, early_drv);         
	int err;
	GSE_FUN();

	if(obj == NULL)
	{
		GSE_ERR("null pointer!!\n");
		return;
	}
	
	if(pedo_enable_status  || tilt_enable_status)
	{
		atomic_set(&obj->suspend, 0);
		return;
	}

	LSM6DS3_power(obj->hw, 1);
	
	err = LSM6DS3_acc_SetPowerMode(obj->client, enable_status);

	if(err)
	{
		GSE_ERR("initialize client fail! err code %d!\n", err);
		return;        
	}
	atomic_set(&obj->suspend, 0);    
}
#endif /*CONFIG_HAS_EARLYSUSPEND*/

static int agold_LSM6DS3_acc_calibration(int type, int cali[3])
{
	int err=0;
	struct lsm6ds3_i2c_data *obj = obj_i2c_data;
	if(NULL == obj)
	{
		GSE_ERR("cali == NULL!\n");
		return -1;
	}
	switch(type)
	{
		case SETCALI:			  
			 err = LSM6DS3_acc_WriteCalibration(obj->client, cali);
			 //GSE_LOG("%s : [SETCALI](%d,%d,%d)\n",__func__,cali[0],cali[1],cali[2]);
			 break;
		
		case CLRCALI:
			 err =LSM6DS3_acc_ResetCalibration(obj->client);
			 break;

		case GETCALI:
			 err = LSM6DS3_acc_ReadCalibration(obj->client,cali);
			 //GSE_LOG("%s : [GETCALI](%d,%d,%d)\n",__func__,cali[0],cali[1],cali[2]);
			 break;
		default:
			GSE_ERR("%s : cmd err!\n",__func__);
			err = -1;
			break;
					 
	}
	return err;
}

/*----------------------------------------------------------------------------*/
static int lsm6ds3_i2c_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
	struct i2c_client *new_client;
	struct lsm6ds3_i2c_data *obj;
	int err = 0;

	GSE_FUN();
	if(!(obj = kzalloc(sizeof(*obj), GFP_KERNEL)))
	{
		GSE_ERR("[accel],kzalloc error!\n");
		err = -ENOMEM;
		goto exit;
	}
	
	memset(obj, 0, sizeof(struct lsm6ds3_i2c_data));
	client->addr = 0x6b;
	obj->hw = get_cust_acc_hw(); 
	obj->sample_rate = LSM6DS3_ACC_ODR_104HZ;
	
	atomic_set(&obj->layout, obj->hw->direction);
	err = hwmsen_get_convert(obj->hw->direction, &obj->cvt);
	if(err)
	{
		GSE_ERR("invalid direction: %d\n", obj->hw->direction);
		goto exit_kfree;
	}

	obj_i2c_data = obj;
	obj->client = client;
	new_client = obj->client;
	i2c_set_clientdata(new_client,obj);
	
	atomic_set(&obj->trace, 0);
	atomic_set(&obj->suspend, 0);
	
	lsm6ds3_i2c_client = new_client;	
	err = LSM6DS3_init_client(new_client, false);
	if(err)
	{
		GSE_ERR("[accel],init_client error!\n");
		goto exit_init_failed;
	}
	
	err = misc_register(&lsm6ds3_acc_device);
	if(err)
	{
		GSE_ERR("lsm6ds3_gyro_device misc register failed!\n");
		goto exit_misc_device_register_failed;
	}
	if(err)
	{
		GSE_ERR("lsm6ds3 create attribute err = %d\n", err);
		goto exit_create_attr_failed;
	}	


#ifdef CONFIG_HAS_EARLYSUSPEND
	obj->early_drv.level    = EARLY_SUSPEND_LEVEL_DISABLE_FB - 1,
	obj->early_drv.suspend  = lsm6ds3_early_suspend,
	obj->early_drv.resume   = lsm6ds3_late_resume,    
	register_early_suspend(&obj->early_drv);
#endif 
#ifdef CONFIG_CUSTOM_KERNEL_STEP_COUNTER
	pedo_enable_status = true;
#endif
	lsm6ds3_acc_init_flag = 0;
	GSE_LOG("%s: OK\n", __func__);    
	return 0;

exit_create_attr_failed:
	misc_deregister(&lsm6ds3_acc_device);
exit_misc_device_register_failed:
exit_init_failed:
exit_kfree:
	kfree(obj);
exit:
	lsm6ds3_acc_init_flag = -1;
	GSE_ERR("%s: err = %d\n", __func__, err);        
	return err;
}

/*----------------------------------------------------------------------------*/
static int lsm6ds3_i2c_remove(struct i2c_client *client)
{
	int err = 0;	

	if(test_bit(LSM6DS3_ACC, &lsm6ds3_init_flag_test))
	{
		err = lsm6ds3_delete_attr(&(lsm6ds3_init_info.platform_diver_addr->driver));
	}
	lsm6ds3_acc_init_flag = -1;
	if(err)
	{
		GSE_ERR("lsm6ds3_i2c_remove fail: %d\n", err);
	}

	err = misc_deregister(&lsm6ds3_acc_device);
	if(err)
	{
		GSE_ERR("misc_deregister lsm6ds3_gyro_device fail: %d\n", err);
	}

	lsm6ds3_i2c_client = NULL;
	i2c_unregister_device(client);
	kfree(i2c_get_clientdata(client));
	return 0;
}
/*----------------------------------------------------------------------------*/
static int lsm6ds3_local_init_common(void)
{
	struct acc_hw *accel_hw = get_cust_acc_hw();
	//GSE_FUN();
	
	LSM6DS3_power(accel_hw, 1);
	
	if(i2c_add_driver(&lsm6ds3_i2c_driver))
	{
		GSE_ERR("add driver error\n");
		return -1;
	}

	return 0;
}
static int lsm6ds3_local_init(void)
{
	int res = 0;
	struct acc_control_path ctl={0};
    struct acc_data_path data={0};
	struct lsm6ds3_i2c_data *obj = NULL; 

	mutex_lock(&lsm6ds3_init_mutex);
	
	set_bit(LSM6DS3_ACC, &lsm6ds3_init_flag_test);

	if((0==test_bit(LSM6DS3_STEP_C, &lsm6ds3_init_flag_test)) \
		&& (0 == test_bit(LSM6DS3_TILT, &lsm6ds3_init_flag_test)))
	{
		res = lsm6ds3_local_init_common();
		if(res < 0)
		{
			goto lsm6ds3_local_init_failed;
		}
		
	}


	if(lsm6ds3_acc_init_flag == -1)
	{
		mutex_unlock(&lsm6ds3_init_mutex);
		GSE_LOG("[accel],%s init failed!\n", __FUNCTION__);
		return -1;
	}
	else
	{
		obj = obj_i2c_data;
		if(NULL == obj)
		{
			GSE_LOG("[accel],i2c_data obj is null!!\n");
			goto lsm6ds3_local_init_failed;
		}
		
		res = lsm6ds3_create_attr(&(lsm6ds3_init_info.platform_diver_addr->driver));
		if(res < 0)
		{
			goto lsm6ds3_local_init_failed;
		}
	    ctl.open_report_data= lsm6ds3_open_report_data;
	    ctl.enable_nodata = lsm6ds3_enable_nodata;
		ctl.acc_calibration = agold_LSM6DS3_acc_calibration;
	    ctl.set_delay  = lsm6ds3_set_delay;
	    ctl.is_report_input_direct = false;
	    ctl.is_support_batch = obj->hw->is_batch_supported;

	    res = acc_register_control_path(&ctl);
	    if(res)
	    {
	         GSE_LOG("[accel],register acc control path err\n");
			 goto lsm6ds3_local_init_failed;

	    }

	    data.get_data = lsm6ds3_get_data;
	    data.vender_div = 1000;
	    data.get_raw_data = agold_get_raw_data;
	    res = acc_register_data_path(&data);
	    if(res)
	    {
	        GSE_LOG("[accel],register acc data path err= %d\n", res);
			goto lsm6ds3_local_init_failed;

	    }
	}
	mutex_unlock(&lsm6ds3_init_mutex);
	return 0;
lsm6ds3_local_init_failed:
	GSE_ERR("[accel],%s init failed\n", __FUNCTION__);
	mutex_unlock(&lsm6ds3_init_mutex);
	return res;

}
static int lsm6ds3_local_uninit(void)
{
	struct acc_hw *accel_hw = get_cust_acc_hw();
	clear_bit(LSM6DS3_ACC, &lsm6ds3_init_flag_test);

    //GSE_FUN();    
    LSM6DS3_power(accel_hw, 0);  	
    i2c_del_driver(&lsm6ds3_i2c_driver);
    return 0;
}
/*----------------------------------------------------------------------------*/
static int __init lsm6ds3_init(void)
{
	const char *name = "mediatek,lsm6ds3";

	hw = get_accel_dts_func(name, hw);
	if (!hw)
		GSE_ERR("get cust_accel dts info fail\n");
	GSE_LOG("%s: i2c_number=%d\n", __func__, hw->i2c_num);
	acc_driver_add(&lsm6ds3_init_info);
	return 0;    
}

static void __exit lsm6ds3_exit(void)
{
	GSE_FUN();

}
module_init(lsm6ds3_init);
module_exit(lsm6ds3_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("LSM6DS3 Accelerometer");
MODULE_AUTHOR("xj.wang@mediatek.com, darren.han@st.com");
