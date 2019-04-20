/* drivers/i2c/chips/hshcal002.c - HSHCAL002 motion sensor driver
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
#include <linux/uaccess.h>
#include <linux/delay.h>
#include <linux/input.h>
#include <linux/workqueue.h>
#include <linux/kobject.h>
#include <linux/platform_device.h>
#include <linux/atomic.h>
#include <linux/module.h>
#include <linux/math64.h>
#include "hshcal002.h"
#include "cust_temp.h"
#include "temperature.h"


//#define POWER_NONE_MACRO MT65XX_POWER_NONE

#define DEBUG 1

#define HSHCAL002_DEV_NAME        "hshcal002"

extern int get_temprerature_data(void);
static const struct i2c_device_id hshcal002_i2c_id[] = {{HSHCAL002_DEV_NAME,0},{}};
static int hshcal002_i2c_probe(struct i2c_client *client, const struct i2c_device_id *id); 
static int hshcal002_i2c_remove(struct i2c_client *client);
static int hshcal002_i2c_detect(struct i2c_client *client,struct i2c_board_info *info);
static int hshcal002_enable(struct i2c_client *client, int enable);
static int hshcal002_release(struct inode *inode, struct file *file);

static int hshcal002_suspend(struct i2c_client *client, pm_message_t msg);
static int hshcal002_resume(struct i2c_client *client);

static int hshcal002_local_init(void);
static int hshcal002_local_remove(void);

struct temp_hw temp_cust;
static struct temp_hw *hw = &temp_cust;
/* For alsp driver get cust info */
struct temp_hw *get_cust_temp(void)
{
	return &temp_cust;
}
static struct temp_init_info hshcal002_init_info = {
		.name = "hshcal002",
		.init = hshcal002_local_init,
		.uninit = hshcal002_local_remove,
	
};

#ifdef CONFIG_OF
static const struct of_device_id temp_of_match[] = {
	{.compatible = "mediatek,temperature"},
	{},
};
#endif
typedef enum {
    BAR_TRC_READ  = 0x01,
    BAR_TRC_RAWDATA = 0x02,
    BAR_TRC_IOCTL   = 0x04,
    BAR_TRC_FILTER  = 0x08,
} BAR_TRC;

#define C_MAX_FIR_LENGTH (32)
#define HSHCAL002_DATA_NUM 2
//#define CONFIG_HSHCAL002_LOWPASS   /*apply low pass filter on output*/     

struct data_filter {
    u32 raw[C_MAX_FIR_LENGTH][HSHCAL002_DATA_NUM];
    int sum[HSHCAL002_DATA_NUM];
    int num;
    int idx;
};


struct hshcal002_i2c_data {
    struct i2c_client *client;
    struct temp_hw *hw;
    struct hwmsen_convert   cvt;
    
    /*misc*/
    struct data_resolution *reso;
    atomic_t                trace;
    atomic_t                suspend;
    /*data*/
    int status;
    u32   data[2];
	atomic_t                enable;
	atomic_t				filter;
#if defined(CONFIG_HSHCAL002_LOWPASS)
    atomic_t                firlen;
    atomic_t                fir_en;
    struct data_filter      fir;
#endif 
	
    /*early suspend*/ 
#if defined(CONFIG_HAS_EARLYSUSPEND)
    struct early_suspend    early_drv;
#endif    
};

static struct i2c_driver hshcal002_i2c_driver = {
    .driver = {
       // .owner          = THIS_MODULE,
        .name           = HSHCAL002_DEV_NAME,
#ifdef CONFIG_OF
        .of_match_table = temp_of_match,
#endif  
    },
	.probe      		= hshcal002_i2c_probe,
	.remove    			= hshcal002_i2c_remove,
	.detect				= hshcal002_i2c_detect,
#if !defined(CONFIG_HAS_EARLYSUSPEND)    
    .suspend            = hshcal002_suspend,
    .resume             = hshcal002_resume,
#endif
	.id_table = hshcal002_i2c_id,
};

static int hshcal002_init_flag =-1; // 0<==>OK -1 <==> fail

static struct i2c_client *hshcal002_i2c_client = NULL;
static struct platform_driver hsuddd001_temp_driver;
static struct hshcal002_i2c_data *obj_i2c_data = NULL;
//static bool sensor_power = false;
/*
#define TEMP_HUMI_TAG                  "[HSHCAL002] "
#define //(f)               printk(KERN_INFO TEMP_HUMI_TAG"%s\n", __FUNCTION__)
#define TEMP_HUMI_ERR(fmt, args...)    printk(KERN_ERR TEMP_HUMI_TAG"%s %d : "fmt, __FUNCTION__, __LINE__, ##args)
#define TEMP_HUMI_LOG(fmt, args...)    printk(KERN_INFO TEMP_HUMI_TAG fmt, ##args)
*/
#define TEMP_HUMI_TAG	"<HSHCAL002> "
#define TEMP_HUMI_FUN	printk
#define TEMP_HUMI_ERR	printk
#define TEMP_HUMI_LOG	printk


static int hshcal002_i2c_send(struct i2c_client *client,char cmd)
{
    u8 databuf[10];    
	int res = 0;
	memset(databuf, 0, sizeof(u8)*10);    
	databuf[0] = cmd;  
  
	res = i2c_master_send(client, databuf, 0x1);
	//printk("[hshcal002] addr = 0x%x, databuf[0]= 0x%x\n",client->addr, databuf[0]);
	if(res < 0)
	{
		TEMP_HUMI_ERR("hshcal002_i2c_send fail!! res = %d\n",res);
	}
	return res;
}

/*static int hshcal002_i2c_recv(struct i2c_client *client,u8 *data,u8 len)
{
    int res = 0;
    if(NULL == data)
    {
		return -1;
		TEMP_HUMI_ERR("hshcal002_i2c_recv NULL pointer!!\n");
    }	  
	res = i2c_master_recv(client, data, len);
	
	if(res < 0)
	{
		TEMP_HUMI_ERR("hshcal002_i2c_recv fail!! res = %d\n",res);
		res = -1;
	}
	return res;
}*/


static int hshcal002_get_temperature_data(struct i2c_client *client, int *buf)
{
	//struct hshcal002_i2c_data *priv = i2c_get_clientdata(client);

	int err = 0;
	u8 lbyte = 0, hbyte = 0;
	//();
	if(NULL == client)
	{
		*buf = 0;
		return -2;
	}
	else
	{	
		err = hwmsen_read_byte(client, HSHCAL002_TEMP_LOW_DATA_REG, &lbyte);
		printk("[zp],lbyte = %d\n",lbyte);
		if(err != HSHCAL002_SUCCESS)
		{
			TEMP_HUMI_ERR("read temperature low data register Error.\n");
			return err;	
		}
		err = hwmsen_read_byte(client, HSHCAL002_TEMP_HIGH_DATA_REG, &hbyte);
		printk("[zp],hbyte = %d\n",hbyte);
		if(err != HSHCAL002_SUCCESS)
		{
			TEMP_HUMI_ERR("read temperature high data register Error.\n");
			return err;	
		}
		buf[0] = (int)(((hbyte & 0x1f) << 8) | lbyte)*2 - 4192; //divide 100
		
		//TEMP_HUMI_LOG("[Agold spl] =============> temperature = %d.\n", buf[0]);
		printk("[zp],temperature is %d\n",buf[0]);
	}
	
	err  = hshcal002_i2c_send(client,HSHCAL002_DETECT_REG);
	if(err < 0)
	{
		TEMP_HUMI_ERR("[Agold spl][HSHCAL002] write detect register Error.\n");
		return err;
	}		

	return 0;
}

static int HSHCAL002_client_Init(struct i2c_client *client, int reset_cali)
{
	//struct hshcal002_i2c_data *obj = obj_i2c_data;
	int err =0;
	//char buf[2] = {0,0};
	u8 version_info = 0, alps_info = 0;
	int chipinfo = 0;
	//();
	err  = hshcal002_i2c_send(client,HSHCAL002_RESET_REG);
	if(err < 0)
	{
		TEMP_HUMI_ERR("write reset register Error.\n");
		return err;
	}	
	err = hwmsen_write_byte(client,HSHCAL002_CONTROL_REG,0x72);	
	if(err != HSHCAL002_SUCCESS)
	{
		TEMP_HUMI_ERR("write control register Error.\n");
		return err;
	}
	err = hwmsen_read_byte(client, HSHCAL002_ALPSINFO_REG, &alps_info);
	if(err != HSHCAL002_SUCCESS)
	{
		TEMP_HUMI_ERR("read alpsinfo register Error.\n");
		return err;	
	}
	err = hwmsen_read_byte(client, HSHCAL002_VERSION_REG, &version_info);
	if(err != HSHCAL002_SUCCESS)
	{
		TEMP_HUMI_ERR("read alpsinfo register Error.\n");
		return err;	
	}
	
	chipinfo = ((alps_info << 8) | version_info);
	if(HSHCAL002_CHIP_ID != chipinfo)
	{
		TEMP_HUMI_ERR("chip id is error.\n");
		return -1;
	}
	TEMP_HUMI_LOG("chipinfo = 0x%x.\n",chipinfo);

	if((err  = hshcal002_i2c_send(client,HSHCAL002_DETECT_REG)) < 0)
	{
		TEMP_HUMI_ERR("write dectet register Error.\n");
		return err;
	}	
	mdelay(20);
	printk("%s OK.\n",__func__);
	
	return 0;
}

static int hshcal002_enable(struct i2c_client *client, int enable)
{
	int err = 0;
	//struct hshcal002_i2c_data *obj = obj_i2c_data;
	if(enable)
	{
    	if((err  = hshcal002_i2c_send(client,HSHCAL002_DETECT_REG)) < 0)
		{
			TEMP_HUMI_ERR("write detect register Error.\n");
			return err;
		}	
	}
	return HSHCAL002_SUCCESS;
}

static int hshcal002_self_test(struct i2c_client *client)
{
	int ret = 0,err;
	u8 testdata = 0;
	ret = hwmsen_read_byte(client, HSHCAL002_SELFTESTR_REG, &testdata);
	if(ret !=HSHCAL002_SUCCESS )
	{
		TEMP_HUMI_ERR("read self-test r register Error.\n");
		return 1;	
	}
	mdelay(1);
	if(testdata != 0x55)
	{
		TEMP_HUMI_ERR("error self-test register data is ox%x.\n",testdata);
		return 2;
	}

	//do self-test
	if((err  = hshcal002_i2c_send(client,HSHCAL002_SELFTES_REG)) < 0)
	{
		TEMP_HUMI_ERR("write self test register Error.\n");
		return 3;
	}	
	mdelay(5);
	
	ret = hwmsen_read_byte(client, HSHCAL002_SELFTESTR_REG, &testdata);
	if(ret != HSHCAL002_SUCCESS)
	{
		TEMP_HUMI_ERR("read self-test r register Error.\n");
		return 4;	
	}
	mdelay(1);
	if(testdata != 0xAA)
	{
		TEMP_HUMI_ERR("error self-test register data is ox%x.\n",testdata);
		return 5;
	}

	//get 2nd value of self-test register
	ret = hwmsen_read_byte(client, HSHCAL002_SELFTESTR_REG, &testdata);
	if(ret != HSHCAL002_SUCCESS)
	{
		TEMP_HUMI_ERR("read self-test r register Error.\n");
		return 6;	
	}
	mdelay(1);
	if(testdata != 0x55)
	{
		TEMP_HUMI_ERR("error self-test r register data is ox%x.\n",testdata);
		return 7;
	}
	
	return 0;
}

static ssize_t show_hshcal002_chipinfo(struct device_driver *ddri, char *buf)
{  
	ssize_t len = 0;

	len += snprintf(buf+len,PAGE_SIZE-len,"hshcal002\n");
	
	return len;       
}


static ssize_t show_temperature_value(struct device_driver *ddri, char *buf)
{
	struct i2c_client *client = hshcal002_i2c_client;
	int strbuf[1] = {0};
	if(NULL == client)
	{
		TEMP_HUMI_ERR("i2c client is null!!\n");
		return 0;
	}
	hshcal002_get_temperature_data(client, strbuf);

	printk("[Agold spl] Read sensor data OK.T = %d\n",strbuf[0]);

	return snprintf(buf, PAGE_SIZE, "%d \n", strbuf[0]);              
}

static ssize_t show_trace_value(struct device_driver *ddri, char *buf)
{
	ssize_t res;
	struct hshcal002_i2c_data *obj = obj_i2c_data;
	TEMP_HUMI_LOG(" show_trace_value \n");
	if (obj == NULL)
	{
		TEMP_HUMI_ERR("i2c_data obj is null!!\n");
		return 0;
	}
	res = snprintf(buf, PAGE_SIZE, "0x%04X\n", atomic_read(&obj->trace));     
	return res;    
}

static ssize_t store_trace_value(struct device_driver *ddri, const char *buf, size_t count)
{
    
	struct hshcal002_i2c_data *obj = obj_i2c_data;
	int trace;
	TEMP_HUMI_LOG(" store_trace_value \n");
	if (obj == NULL)
	{
		TEMP_HUMI_ERR("i2c_data obj is null!!\n");
		return 0;
	}
	
	if(1 == sscanf(buf, "0x%x", &trace))
	{
		atomic_set(&obj->trace, trace);
	}	
	else
	{
		TEMP_HUMI_ERR("invalid content: '%s', length = %ld\n", buf, count);
	}
	
	return count;    
}

static ssize_t store_enable_hshcal002(struct device_driver *ddri, const char *buf, size_t count)
{
    
	struct hshcal002_i2c_data *obj = obj_i2c_data;
	struct i2c_client *client = hshcal002_i2c_client;
	int enable;
	TEMP_HUMI_LOG(" store_enable_value \n");
	if (obj == NULL)
	{
		TEMP_HUMI_ERR("i2c_data obj is null!!\n");
		return 0;
	}
	
	if(1 == sscanf(buf, "0x%x", &enable))
	{
		atomic_set(&obj->enable, enable);
		hshcal002_enable(client, enable);
	}	
	else
	{
		TEMP_HUMI_ERR("invalid content: '%s', length = %ld\n", buf, count);
	}
	
	return count;    
}

static ssize_t show_status_value(struct device_driver *ddri, char *buf)
{
	ssize_t len = 0;  
	TEMP_HUMI_LOG(" show_status_value \n");
	
	return len;    
}

static ssize_t show_enable_hshcal002(struct device_driver *ddri, char *buf)
{
	ssize_t len = 0;  
	TEMP_HUMI_LOG(" show_enable_hshcal002 \n");
	
	return len;    
}

static ssize_t show_hshcal002_selftest_result(struct device_driver *ddri, char *buf)
{
	struct i2c_client *client = hshcal002_i2c_client;
	//int strbuf[10];
	int res = 0;

	if(NULL == client)
	{
		printk("i2c client is null!!\n");
		return 0;
	}
	
	res = hshcal002_self_test(client);

	return sprintf(buf, "selftest res: %d\n", res);               
}

static DRIVER_ATTR(chipinfo,             S_IRUGO,      			show_hshcal002_chipinfo,						NULL);
static DRIVER_ATTR(enable,      		 S_IWUSR | S_IRUGO, 	show_enable_hshcal002,							store_enable_hshcal002);
static DRIVER_ATTR(temp, 		 		 S_IRUGO, 	   			show_temperature_value,							NULL);
static DRIVER_ATTR(trace,      			 S_IWUSR | S_IRUGO, 	show_trace_value, 								store_trace_value);
static DRIVER_ATTR(status,               S_IRUGO, 				show_status_value,              				NULL);
static DRIVER_ATTR(selftest,             S_IRUGO, 				show_hshcal002_selftest_result,				NULL);

static struct driver_attribute *hshcal002_attr_list[] = {
	&driver_attr_chipinfo,      /*chip information*/
	&driver_attr_enable,		/*enable or disable*/
	&driver_attr_temp,   		/*get temperature data*/
	&driver_attr_trace,         /*trace log*/
	&driver_attr_status,            
	&driver_attr_selftest, 
};

static int hshcal002_create_attr(struct device_driver *driver) 
{
	int idx, err = 0;
	int num = (int)(sizeof(hshcal002_attr_list)/sizeof(hshcal002_attr_list[0]));
	if (driver == NULL)
	{
		return -EINVAL;
	}

	for(idx = 0; idx < num; idx++)
	{
		if((err = driver_create_file(driver, hshcal002_attr_list[idx])))
		{            
			TEMP_HUMI_ERR("driver_create_file (%s) = %d\n", hshcal002_attr_list[idx]->attr.name, err);
			break;
		}
	}    
	return err;
}

static int hshcal002_delete_attr(struct device_driver *driver)
{
	int idx ,err = 0;
	int num = (int)(sizeof(hshcal002_attr_list)/sizeof(hshcal002_attr_list[0]));

	if(driver == NULL)
	{
		return -EINVAL;
	}
	
	for(idx = 0; idx < num; idx++)
	{
		driver_remove_file(driver, hshcal002_attr_list[idx]);
	}
	

	return err;
}

static int hshcal002_temperature_operate(void* self, uint32_t command, void* buff_in, int size_in,
		void* buff_out, int size_out, int* actualout)
{
	int err = 0;
	int value;	
	struct hshcal002_i2c_data *priv = (struct hshcal002_i2c_data*)self;
	struct hwm_sensor_data* hshcal002_data;
	int buff[3];
	//int buff1[3];
	switch (command)
	{
		case SENSOR_DELAY:
			break;

		case SENSOR_ENABLE:
			if((buff_in == NULL) || (size_in < sizeof(int)))
			{
				TEMP_HUMI_ERR("Enable sensor parameter error!\n");
				err = -EINVAL;
			}
			else
			{
				value = *(int *)buff_in;
				if(value == 0)
				{
					//clear filter buffer
					//memset(&(priv->fir), 0, sizeof(struct data_filter));
				}		
			}
			break;

		case SENSOR_GET_DATA:
			//TEMP_HUMI_LOG(" sensor operate get data\n");
			if((buff_out == NULL) || (size_out< sizeof(struct hwm_sensor_data)))
			{
				TEMP_HUMI_ERR("get sensor data parameter error!\n");
				err = -EINVAL;
			}
			else
			{
				hshcal002_data = (struct hwm_sensor_data *)buff_out;
				err = hshcal002_get_temperature_data(priv->client, buff);
				if(err)
				{
					TEMP_HUMI_ERR("get sensor data parameter error!\n");
					return -1;
				}
				//sscanf(buff, "%x %x %x", &hshcal002_data->values[0], &hshcal002_data->values[1], &hshcal002_data->values[2]);		
				hshcal002_data->values[0] = buff[0];
				hshcal002_data->status = SENSOR_STATUS_ACCURACY_MEDIUM;				
				hshcal002_data->value_divide = 100;
			}
			break;
		default:
			TEMP_HUMI_ERR("temperature operate function no this parameter %d!\n", command);
			err = -1;
			break;
	}
	
	return err;
}


static int hshcal002_open(struct inode *inode, struct file *file)
{
	file->private_data = hshcal002_i2c_client;

	if(file->private_data == NULL)
	{
		TEMP_HUMI_ERR("null pointer!!\n");
		return -EINVAL;
	}
	return nonseekable_open(inode, file);
}

static int hshcal002_release(struct inode *inode, struct file *file)
{
	file->private_data = NULL;
	return 0;
}

static long hshcal002_unlock_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
	struct i2c_client *client = (struct i2c_client*)file->private_data;
	struct hshcal002_i2c_data *obj = i2c_get_clientdata(client);
	int strbuf[1] = {0};
	s32 dat=0;
	void __user *ptr = (void __user*) arg;
	int err = 0;
	/*
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
		TEMP_HUMI_ERR("access error: %08X, (%2d, %2d)\n", cmd, _IOC_DIR(cmd), _IOC_SIZE(cmd));
		return -EFAULT;
	}
	*/

	switch(cmd)
	{
		case TEMPERATURE_IOCTL_INIT:
			TEMP_HUMI_LOG("BAROSENSOR_IOCTL_INIT\n");
			HSHCAL002_client_Init(obj->client, 0);			
			break;

		case TEMPERATURE_IOCTL_READ_CHIPINFO:
			 TEMP_HUMI_LOG("BAROSENSOR_IOCTL_READ_CHIPINFO\n");
			
			break;	  

		case TEMPERATURE_GET_TEMP_DATA:
			
			hshcal002_get_temperature_data(obj->client, strbuf);
			dat = strbuf[0];
			if(copy_to_user(ptr, &dat, sizeof(dat)))
			{
				err = -EFAULT;
				break;	  
			}				 
			break;

		default:
			TEMP_HUMI_ERR("unknown IOCTL: 0x%08x\n", cmd);
			err = -ENOIOCTLCMD;
			break;		
	}
	return err;
}

static struct file_operations hshcal002_fops = {
	.owner = THIS_MODULE,
	.open = hshcal002_open,
	.release = hshcal002_release,
	.unlocked_ioctl = hshcal002_unlock_ioctl,
};

static struct miscdevice hshcal002_device = {
	.minor = MISC_DYNAMIC_MINOR,
	.name = "hshcal002",
	.fops = &hshcal002_fops,
};


static int hshcal002_open_report_data(int open)
{
	//should queuq work to report event if  is_report_input_direct=true
	return 0;
}

// if use  this typ of enable , Gsensor only enabled but not report inputEvent to HAL

static int hshcal002_enable_nodata(int en)
{
	return  0;

}

static int hshcal002_set_delay(u64 ns)
{
   

	return 0;
}

static int hshcal002_get_data(int *value, int *status)
{
	int buf[1] = {0};
	struct i2c_client *client = hshcal002_i2c_client;
	*status = SENSOR_STATUS_ACCURACY_MEDIUM;
	
	if(hshcal002_get_temperature_data(client,buf))
		return -1;
	*value = *buf;
	
	return 0;
}

static int hshcal002_get_raw_data(int type, int *value)
{
	int buf[1] = {0};
	struct i2c_client *client = hshcal002_i2c_client;
	
	if(hshcal002_get_temperature_data(client,buf))
		return -1;
	*value = *buf;
		
	return 0;
}


#ifndef CONFIG_HAS_EARLYSUSPEND
static int hshcal002_suspend(struct i2c_client *client, pm_message_t msg) 
{
	struct hshcal002_i2c_data *obj = i2c_get_clientdata(client);    
	int err = 0;
	//u8  dat=0;
	//();
	if(msg.event == PM_EVENT_SUSPEND)
	{   
		if(obj == NULL)
		{
			TEMP_HUMI_ERR("null pointer!!\n");
			return -EINVAL;
		}
		atomic_set(&obj->suspend, 1);
		    

	}
	return err;
}

static int hshcal002_resume(struct i2c_client *client)
{
	struct hshcal002_i2c_data *obj = i2c_get_clientdata(client);        
	//int err;
	//();

	if(obj == NULL)
	{
		TEMP_HUMI_ERR("null pointer!!\n");
		return -EINVAL;
	}


	atomic_set(&obj->suspend, 0);

	return 0;
}

#else 

static void hshcal002_early_suspend(struct early_suspend *h) 
{
	struct hshcal002_i2c_data *obj = container_of(h, struct hshcal002_i2c_data, early_drv);   
	//();  
  
	if(obj == NULL)
	{
		TEMP_HUMI_ERR("null pointer!!\n");
		return;
	}
	atomic_set(&obj->suspend, 1); 
	sensor_power = false;
	
}

static void hshcal002_late_resume(struct early_suspend *h)
{
	struct hshcal002_i2c_data *obj = container_of(h, struct hshcal002_i2c_data, early_drv);         
	int err;
	//();
	if(obj == NULL)
	{
		TEMP_HUMI_ERR("null pointer!!\n");
		return;
	}

	atomic_set(&obj->suspend, 0);    
}

#endif /*CONFIG_HAS_EARLYSUSPEND*/

static int hshcal002_i2c_detect(struct i2c_client *client,struct i2c_board_info *info) 
{    
	strcpy(info->type, HSHCAL002_DEV_NAME);
	return 0;
}

static int hshcal002_i2c_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
	struct i2c_client *new_client;
	struct hshcal002_i2c_data *obj;
	//struct hwmsen_object sobj;
	struct hwmsen_object obj_temp;
	struct temp_control_path ctl={0};
	struct temp_data_path data={0};
	int err = 0;
	//();
	printk("[hdmy] func : %s , line : %d\n", __func__, __LINE__);
	if(!(obj = kzalloc(sizeof(*obj), GFP_KERNEL)))
	{
		err = -ENOMEM;
		goto exit;
	}
	
	memset(obj, 0, sizeof(struct hshcal002_i2c_data));

	client->addr = HSHCAL002_I2C_SLAVE_ADDR;
	obj->hw = hw;
	obj_i2c_data = obj;
	obj->client = client;
	new_client = obj->client;
	i2c_set_clientdata(new_client,obj);//obj 作为new_client 下dev中的指针
	
	atomic_set(&obj->trace, 0);
	atomic_set(&obj->suspend, 0);
	//
#ifdef CONFIG_HSHCAL002_LOWPASS

    atomic_set(&obj->filter, 1);
	if(obj->hw->firlen > C_MAX_FIR_LENGTH)
	{
		atomic_set(&obj->firlen, C_MAX_FIR_LENGTH);
	}	
	else
	{
		atomic_set(&obj->firlen, obj->hw->firlen);
	}
	
	if(atomic_read(&obj->firlen) > 0)
	{
		atomic_set(&obj->fir_en, 1);
	}
	TEMP_HUMI_LOG("hshcal002_device  filter len =%d \n",atomic_read(&obj->firlen));
#endif
printk("[hdmy] func : %s , line : %d\n", __func__, __LINE__);
	hshcal002_i2c_client = new_client;	

	if((err = HSHCAL002_client_Init(new_client, 1)))
	{
		goto exit_init_failed;
	}
	
	if((err = misc_register(&hshcal002_device)))
	{
		TEMP_HUMI_ERR("hshcal002_device register failed\n");
		goto exit_misc_device_register_failed;
	}

	if((err = hshcal002_create_attr(&hshcal002_init_info.platform_diver_addr->driver)))
	{
		TEMP_HUMI_ERR("create attribute err = %d\n", err);
		goto exit_create_attr_failed;
	}
    printk("[hdmy] func : %s , line : %d\n", __func__, __LINE__);

	//*************************add data path ************************* 
	ctl.open_report_data= hshcal002_open_report_data;
	ctl.enable_nodata = hshcal002_enable_nodata;
	ctl.set_delay  = hshcal002_set_delay;
    //ctl.batch = kxtj2_1009_set_batch;
	ctl.is_report_input_direct = false;
    ctl.is_support_batch = false;
    ctl.is_report_input_direct = false;
    ctl.is_use_common_factory = false;
printk("[hdmy] func : %s , line : %d\n", __func__, __LINE__); 

	err = temp_register_control_path(&ctl);
	if(err)
	{
	 	TEMP_HUMI_ERR("register acc control path err\n");
		goto exit_create_attr_failed;
	}
	
	data.get_data = hshcal002_get_data;
	data.vender_div = 100;
	//Bruce
	data.get_raw_data = hshcal002_get_raw_data;
	
	err = temp_register_data_path(&data);
	if(err)
	{
	 	TEMP_HUMI_ERR("register acc data path err\n");
		goto exit_create_attr_failed;
	}
	
	err = batch_register_support_info(ID_AMBIENT_TEMPERATURE, ctl.is_support_batch, 1000, 0);
    if(err)
    {
        TEMP_HUMI_ERR("register gsensor batch support err = %d\n", err);
        goto exit_create_attr_failed;
    }

//**************************************************************** 

	obj_temp.self = obj;
    obj_temp.polling = 1;
    obj_temp.sensor_operate = hshcal002_temperature_operate;
	if((err = hwmsen_attach(ID_AMBIENT_TEMPERATURE, &obj_temp)))
	{
		TEMP_HUMI_ERR("attach fail = %d\n", err);
		goto exit_kfree;
	}

#ifdef CONFIG_HAS_EARLYSUSPEND
	obj->early_drv.level    = EARLY_SUSPEND_LEVEL_DISABLE_FB - 1,
	obj->early_drv.suspend  = hshcal002_early_suspend,
	obj->early_drv.resume   = hshcal002_late_resume,    
	register_early_suspend(&obj->early_drv);
#endif 

	printk("%s: OK\n", __func__); 
 	hshcal002_init_flag =0;
	return 0;

	exit_create_attr_failed:
	misc_deregister(&hshcal002_device);
	exit_misc_device_register_failed:
	exit_init_failed:
	//i2c_detach_client(new_client);
	exit_kfree:
	kfree(obj);
	exit:
	TEMP_HUMI_ERR("%s: err = %d\n", __func__, err); 
	hshcal002_init_flag =-1;       
	return err;
}

static int hshcal002_i2c_remove(struct i2c_client *client)
{
	int err = 0;	
	
	if((err = hshcal002_delete_attr(&hsuddd001_temp_driver.driver)))
	{
		TEMP_HUMI_ERR("hshcal002_delete_attr fail: %d\n", err);
	}
	
	if((err = misc_deregister(&hshcal002_device)))
	{
		TEMP_HUMI_ERR("misc_deregister fail: %d\n", err);
	}

	if((err = hwmsen_detach(ID_AMBIENT_TEMPERATURE)))
	{
		TEMP_HUMI_ERR("hwmsen_detach ID_AMBIENT_TEMPERATURE fail: %d\n", err);
	}

	if((err = hwmsen_detach(ID_AMBIENT_TEMPERATURE)))
	{
		TEMP_HUMI_ERR("hwmsen_detach ID_AMBIENT_TEMPERATURE fail: %d\n", err);
	}
	    
	hshcal002_i2c_client = NULL;
	i2c_unregister_device(client);
	kfree(i2c_get_clientdata(client));
	return 0;
}


/*static struct platform_device hshcal002_tempureature_devices = {
	.name = "temperature",
	.id = -1,
};*/


static int hshcal002_local_init(void)
{

	printk("[hdmy] func : %s , line : %d\n", __func__, __LINE__);
	if(i2c_add_driver(&hshcal002_i2c_driver))
	{
		TEMP_HUMI_ERR("add driver error\n");
		return -1;
	}
	if(-1 == hshcal002_init_flag)
	{
	   return -1;
	}
	return 0;
}

static int hshcal002_local_remove(void)
{
   
    i2c_del_driver(&hshcal002_i2c_driver);
    return 0;
}


static int __init hshcal002_init(void)
{
	const char *name = "mediatek,hshcal002";
	printk("[hdmy]%s [line: %d]\n", __func__,__LINE__);
	//();	

	hw = get_temp_dts_func(name, hw);
	if (!hw) 
	{
		TEMP_HUMI_ERR("get_alsps_dts_func fail\n");
		return 0;
	}

	temp_driver_add(&hshcal002_init_info);
	return 0; 
}
   
static void __exit hshcal002_exit(void)
{
	//();

}

module_init(hshcal002_init);
module_exit(hshcal002_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("HSHCAL002 I2C driver");
MODULE_AUTHOR("shipeilong@agoldcomm.com");
