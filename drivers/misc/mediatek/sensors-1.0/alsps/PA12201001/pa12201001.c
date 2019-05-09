/*
 * Author: chester hsu (TXC) <chesterhsu@txc.com.tw>
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
#include <linux/gpio.h>
#include <linux/miscdevice.h>
#include <asm/uaccess.h>
#include <linux/delay.h>
#include <linux/input.h>
#include <linux/workqueue.h>
#include <linux/kobject.h>
#include <linux/platform_device.h>
#include <asm/atomic.h>
#include <asm/io.h>
#include <cust_alsps.h>
#include <alsps.h>
#include "pa12201001.h"
#include <linux/of.h>
#include <linux/of_address.h>
#include <linux/of_irq.h>
#include <linux/sched.h>

/******************************************************************************
 * configuration
*******************************************************************************/
/**Global Variable**/
u8 ps_count=0;
u8 ps_offset=0;
u16 als_count=0;

#ifdef CUSTOM_KERNEL_SENSORHUB
#include <SCP_sensorHub.h>
#endif
/*----------------------------------------------------------------------------*/
#define PA12201001_DEV_NAME     "pa12201001"
/*----------------------------------------------------------------------------*/
#define APS_TAG                  "[ALS/PS] "
#define APS_FUN(f)               printk(APS_TAG"%s\n", __FUNCTION__)
#define APS_ERR(fmt, args...)    printk(APS_TAG"%s %d : "fmt, __FUNCTION__, __LINE__, ##args)
#define APS_LOG(fmt, args...)    printk(APS_TAG fmt, ##args)
#define APS_DBG(fmt, args...)    printk(APS_TAG fmt, ##args)

#define I2C_FLAG_WRITE	0
#define I2C_FLAG_READ	1

#ifndef AGOLD_DEFINED_ALSPS_PA12201001_PS_THD_VALUE
#define AGOLD_DEFINED_ALSPS_PA12201001_PS_THD_VALUE	"0x60"
#endif
#define AGOLD_PA12201001_THRESHOLD_MIN 0X30
extern long agold_strtol(char *str);

static unsigned int PA12201001_Current_Ps_Thd_Value = 0x60;
static int intr_flag_value = 0;
static DEFINE_SPINLOCK(ps_cali_lock);

static int g_interrupt_flag = 0;
struct alsps_hw alsps_cust_pa122001001;
static struct alsps_hw *hw = &alsps_cust_pa122001001;
struct platform_device *alsps_PltFmDev;

static int pa12201001_local_init(void);
static int pa12201001_remove(void);
static int pa12201001_init_flag =-1; // 0<==>OK -1 <==> fail
static struct alsps_init_info pa12201001_init_info = {
		.name = "pa12201001",
		.init = pa12201001_local_init,
		.uninit = pa12201001_remove,

};

/*----------------------------------------------------------------------------*/
static int pa12201001_i2c_probe(struct i2c_client *client, const struct i2c_device_id *id);
static int pa12201001_i2c_remove(struct i2c_client *client);
static int pa12201001_i2c_detect(struct i2c_client *client, struct i2c_board_info *info);
static int pa12201001_i2c_suspend(struct i2c_client *client, pm_message_t msg);
static int pa12201001_i2c_resume(struct i2c_client *client);

static const struct i2c_device_id pa12201001_i2c_id[] = {{PA12201001_DEV_NAME,0},{}};

static int pa12201001_read_als(struct i2c_client *client, u16 *data);
static int pa12201001_read_ps(struct i2c_client *client, u8 *data);
/*----------------------------------------------------------------------------*/
struct pa12201001_priv {
	struct alsps_hw  *hw;
	struct i2c_client *client;
	struct work_struct	eint_work;

	/*misc*/
	u16 		als_modulus;
	atomic_t	i2c_retry;
	atomic_t	als_suspend;
	atomic_t	als_debounce;	/*debounce time after enabling als*/
	atomic_t	als_deb_on; 	/*indicates if the debounce is on*/
#ifdef CONFIG_64BIT
	atomic64_t als_deb_end;	/*the jiffies representing the end of debounce */
#else
	atomic_t als_deb_end;	/*the jiffies representing the end of debounce */
#endif
	atomic_t	ps_mask;		/*mask ps: always return far away*/
	atomic_t	ps_debounce;	/*debounce time after enabling ps*/
	atomic_t	ps_deb_on;		/*indicates if the debounce is on*/
#ifdef CONFIG_64BIT
	atomic64_t ps_deb_end;	/*the jiffies representing the end of debounce */
#else
	atomic_t ps_deb_end;	/*the jiffies representing the end of debounce */
#endif
	atomic_t	ps_suspend;
	atomic_t 	trace;

	#ifdef CUSTOM_KERNEL_SENSORHUB
    struct work_struct init_done_work;
	#endif
	struct device_node *irq_node;
	int irq;

	/*data*/
	u16			als;
	u8 			ps;
	u8			_align;
	u16			als_level_num;
	u16			als_value_num;
	u32			als_level[C_CUST_ALS_LEVEL-1];
	u32			als_value[C_CUST_ALS_LEVEL];

	atomic_t	als_cmd_val;	/*the cmd value can't be read, stored in ram*/
	atomic_t	ps_cmd_val; 	/*the cmd value can't be read, stored in ram*/
	atomic_t	ps_thd_val_high;	 /*the cmd value can't be read, stored in ram*/
	atomic_t	ps_thd_val_low; 	/*the cmd value can't be read, stored in ram*/
	atomic_t	als_thd_val_high;	 /*the cmd value can't be read, stored in ram*/
	atomic_t	als_thd_val_low; 	/*the cmd value can't be read, stored in ram*/
	atomic_t	ps_thd_val;
	ulong		enable; 		/*enable mask*/
	ulong		pending_intr;	/*pending interrupt*/
	int			ps_cali;

};
/*----------------------------------------------------------------------------*/
#ifdef CONFIG_OF
static const struct of_device_id alsps_of_match[] = {
	{.compatible = "mediatek,alsps"},
	{},
};
#endif

static struct i2c_driver pa12201001_i2c_driver = {
	.probe      = pa12201001_i2c_probe,
	.remove     = pa12201001_i2c_remove,
	.detect     = pa12201001_i2c_detect,
	.suspend    = pa12201001_i2c_suspend,
	.resume     = pa12201001_i2c_resume,
	.id_table   = pa12201001_i2c_id,
	.driver = {
		.name = PA12201001_DEV_NAME,
#ifdef CONFIG_OF
		.of_match_table = alsps_of_match,
#endif
	},
};


/*----------------------------------------------------------------------------*/

static struct i2c_client *pa12201001_i2c_client = NULL;
static struct pa12201001_priv *g_pa12201001_ptr = NULL; //Trash
static struct pa12201001_priv *pa12201001_obj = NULL;

/*----------------------------------------------------------------------------*/

static DEFINE_MUTEX(pa12201001_mutex); //TBD

/*----------------------------------------------------------------------------*/
typedef enum {
	CMC_BIT_ALS    = 1,
	CMC_BIT_PS	   = 2,
}CMC_BIT;
/*-----------------------------CMC for debugging-------------------------------*/
typedef enum {
    CMC_TRC_ALS_DATA= 0x0001,
    CMC_TRC_PS_DATA = 0x0002,
    CMC_TRC_EINT    = 0x0004,
    CMC_TRC_IOCTL   = 0x0008,
    CMC_TRC_I2C     = 0x0010,
    CMC_TRC_CVT_ALS = 0x0020,
    CMC_TRC_CVT_PS  = 0x0040,
    CMC_TRC_DEBUG   = 0x8000,
} CMC_TRC;
/*-----------------------------------------------------------------------------*/
static int pa12201001_enable_ps(struct i2c_client *client, int enable)
{
	struct pa12201001_priv *obj = i2c_get_clientdata(client);
	int res;
	u8 regdata=0;
	u8 sendvalue=0;

	if(enable == 1)
	{
		APS_LOG("pa12201001 enable ps sensor\n");
		res=hwmsen_read_byte(client,REG_CFG0,&regdata); //Read Status
		if(res<0)
		{
			APS_ERR("i2c_read function err\n");
			return -1;
		}
		else
		{
			APS_LOG("CFG0 Status: %d\n",regdata);
			sendvalue=regdata & 0xFD; //clear bit
			sendvalue=sendvalue | 0x02; //0x02 PS Flag
			res=hwmsen_write_byte(client,REG_CFG0,sendvalue); //Write PS enable
			if(res<0)
			{
				APS_ERR("i2c_write function err\n");
				return res;
		    }
		}

		atomic_set(&obj->ps_deb_on, 1);
		atomic_set(&obj->ps_deb_end, jiffies+atomic_read(&obj->ps_debounce)/(1000/HZ));

	}
	else
	{

		APS_LOG("pa12201001 disaple ps sensor\n");
		res=hwmsen_read_byte(client,REG_CFG0,&regdata); //Read Status
		if(res<0)
		{
			APS_ERR("i2c_read function err\n");
			return res;
		}
		else
		{
			APS_LOG("CFG0 Status: %d\n",regdata);
			sendvalue=regdata & 0xFD; //clear bit

			res=hwmsen_write_byte(client,REG_CFG0,sendvalue); //Write PS enable
			if(res<0)
			{
				APS_ERR("i2c_write function err\n");
				return res;
		    }
		}

		atomic_set(&obj->ps_deb_on, 0);
	}

	return 0;
}
/********************************************************************/
static int pa12201001_enable_als(struct i2c_client *client, int enable)
{
	struct pa12201001_priv *obj = i2c_get_clientdata(client);
	int res;
	u8 regdata=0;
	u8 sendvalue=0;

	if(enable == 1)
	{
		APS_LOG("pa12201001 enable als sensor\n");
		res=hwmsen_read_byte(client,REG_CFG0,&regdata); //Read Status
		if(res<0)
		{
			APS_ERR("i2c_read function err\n");
			return -1;
		}
		else
		{
			APS_LOG("CFG0 Status: %d\n",regdata);
			sendvalue=regdata & 0xFE; //clear bit
			sendvalue=sendvalue | 0x01; //0x02 PS Flag
			res=hwmsen_write_byte(client,REG_CFG0,sendvalue); //Write ALS enable
			if(res<0)
			{
				APS_ERR("i2c_write function err\n");
				return res;
		    }
		}

		atomic_set(&obj->als_deb_on, 1);
		atomic_set(&obj->als_deb_end, jiffies+atomic_read(&obj->als_debounce)/(1000/HZ));

	}
	else
	{

		APS_LOG("pa12201001 disaple als sensor\n");
		res=hwmsen_read_byte(client,REG_CFG0,&regdata); //Read Status
		if(res<0)
		{
			APS_ERR("i2c_read function err\n");
			return res;

		}
		else
		{
			APS_LOG("CFG0 Status: %d\n",regdata);
			sendvalue=regdata & 0xFE; //clear bit

			res=hwmsen_write_byte(client,REG_CFG0,sendvalue); //Write PS enable
			if(res<0)
			{
				APS_ERR("i2c_write function err\n");
				return res;
		    }
		}

		atomic_set(&obj->als_deb_on, 0);
	}

	return 0;

}
/********************************************************************/
static int pa12201001_read_ps(struct i2c_client *client, u8 *data)
{
	int res;

	APS_FUN(f);
	res = hwmsen_read_byte(client,REG_PS_DATA,data); //Read PS Data
	if(res < 0)
	{
		APS_ERR("i2c_send function err\n");
	}
	APS_LOG("[mcz] read ps = 0x%x\n",*data);
	return res;
}
/********************************************************************/
static int pa12201001_read_als(struct i2c_client *client, u16 *data)
{
	int res;
	u8 dataLSB;
	u8 dataMSB;

	APS_FUN(f);

	res = hwmsen_read_byte(client,REG_ALS_DATA_LSB,&dataLSB); //Read ALS Data LSB
	if(res < 0)
	{
		APS_ERR("i2c_send function err\n");
		return res;
	}

	res = hwmsen_read_byte(client,REG_ALS_DATA_MSB,&dataMSB); //Read ALS Data MSB
	if(res < 0)
	{
		APS_ERR("i2c_send function err\n");
		return res;
	}

	APS_LOG("PA12201001_ALS_DATA value_low = %x, value_high = %x\n",dataLSB,dataMSB);

	*data = ((dataMSB<<8)|dataLSB);

	return 0;

}
/**Change to lux ****************************************************/
static int pa12201001_get_ps_value(struct pa12201001_priv *obj, u8 ps)
{
	int val;
	int invalid;
	int val_temp;
	int mask = atomic_read(&obj->ps_mask);

    APS_LOG("[mcz] get ps = 0x%x\n",ps);
    printk("pa12201001_get_ps_value, ps = %d\n",ps);

	if(ps >= PA12201001_Current_Ps_Thd_Value)
	{
		val = 0;  /*close*/
		val_temp = 0;
		intr_flag_value = 0;
	}
	else if(ps < PA12201001_Current_Ps_Thd_Value)
	{
		val = 1;  /*far away*/
		val_temp = 1;
		intr_flag_value = 1;
	}
	else
	{
		val = val_temp;
	}

	APS_LOG("[mcz]atomic_read(&obj->ps_deb_on) = 0x%x\n",atomic_read(&obj->ps_deb_on));
	APS_LOG("[mcz]atomic_read(&obj->ps_suspend) = 0x%x\n",atomic_read(&obj->ps_suspend));
	if(atomic_read(&obj->ps_suspend))
	{
		invalid = 1;
	}

	else if(1 == atomic_read(&obj->ps_deb_on))
	{
		unsigned long endt = atomic_read(&obj->ps_deb_end);
		APS_LOG("[mcz] endt = 0x%lu\n",endt);
		if(time_after(jiffies, endt))
		{
			atomic_set(&obj->ps_deb_on, 0);
		}

		if (1 == atomic_read(&obj->ps_deb_on))
		{
			invalid = 1;
		}

	}
	APS_LOG("[mcz] invalid = 0x%x \n",invalid);
	if(!invalid)
	{
		APS_LOG("[mcz] !invalid \n");
		if(unlikely(atomic_read(&obj->trace) & CMC_TRC_CVT_PS))
		{
			if(mask)
			{
				APS_DBG("PS:  %05d => %05d [M] \n", ps, val);
			}
			else
			{
				APS_DBG("PS:  %05d => %05d\n", ps, val);
			}
		}
		if(0 == test_bit(CMC_BIT_PS,  &obj->enable))
		{
		    //if ps is disable do not report value
		    APS_DBG("PS: not enable and do not report this value\n");
		    return -1;
		}
		else
		{
			APS_LOG("[mcz] return val = %d\n",val);
		    return val;
		}

	}
	else
	{
		if(unlikely(atomic_read(&obj->trace) & CMC_TRC_CVT_PS))
		{
			APS_DBG("PS:  %05d => %05d (-1)\n", ps, val);
		}
		return -1;
	}
}
/**Change to far/near************************************************/
static int pa12201001_get_als_value(struct pa12201001_priv *obj, u16 als)
{
		int idx;
		int invalid = 0;
		for(idx = 0; idx < obj->als_level_num; idx++)
		{
			if(als < obj->hw->als_level[idx])
			{
				break;
			}
		}
		if(idx >= obj->als_value_num)
		{
			APS_ERR("exceed range\n");
			idx = obj->als_value_num - 1;
		}

		if(1 == atomic_read(&obj->als_deb_on))
		{
			unsigned long endt = atomic_read(&obj->als_deb_end);
			if(time_after(jiffies, endt))
			{
				atomic_set(&obj->als_deb_on, 0);
			}

			if(1 == atomic_read(&obj->als_deb_on))
			{
				invalid = 1;
			}
		}

		if(!invalid)
		{
			if (atomic_read(&obj->trace) & CMC_TRC_CVT_ALS)
			{
				APS_DBG("ALS: %05d => %05d\n", als, obj->hw->als_value[idx]);
			}

			return obj->hw->als_value[idx];
		}
		else
		{
			if(atomic_read(&obj->trace) & CMC_TRC_CVT_ALS)
			{
				APS_DBG("ALS: %05d => %05d (-1)\n", als, obj->hw->als_value[idx]);
			}
			return -1;
		}

}

static int pa12201001_get_ps_raw_data(int *psdata)
{
	u8 raw_ps = 0;
	pa12201001_read_ps(pa12201001_obj->client, &raw_ps );
	*psdata = raw_ps;
	return 0;
}

static int pa12201001_get_als_raw_data(int *psdata)
{
	u16 raw_als = 0;
	pa12201001_read_als(pa12201001_obj->client, &raw_als );
	*psdata = raw_als;
	return 0;
}


/*-------------------------------attribute file for debugging----------------------------------*/

/******************************************************************************
 * Sysfs attributes
*******************************************************************************/
static ssize_t pa12201001_show_config(struct device_driver *ddri, char *buf)
{
	ssize_t res;

	if(!pa12201001_obj)
	{
		APS_ERR("pa12201001_obj is null!!\n");
		return 0;
	}

	res = snprintf(buf, PAGE_SIZE, "(%d %d %d %d %d)\n",
		atomic_read(&pa12201001_obj->i2c_retry), atomic_read(&pa12201001_obj->als_debounce),
		atomic_read(&pa12201001_obj->ps_mask), atomic_read(&pa12201001_obj->ps_thd_val), atomic_read(&pa12201001_obj->ps_debounce));
	return res;
}
/*----------------------------------------------------------------------------*/
static ssize_t pa12201001_store_config(struct device_driver *ddri, const char *buf, size_t count)
{
	int retry, als_deb, ps_deb, mask, thres;
	if(!pa12201001_obj)
	{
		APS_ERR("pa12201001_obj is null!!\n");
		return 0;
	}

	if(5 == sscanf(buf, "%d %d %d %d %d", &retry, &als_deb, &mask, &thres, &ps_deb))
	{
		atomic_set(&pa12201001_obj->i2c_retry, retry);
		atomic_set(&pa12201001_obj->als_debounce, als_deb);
		atomic_set(&pa12201001_obj->ps_mask, mask);
		atomic_set(&pa12201001_obj->ps_thd_val, thres);
		atomic_set(&pa12201001_obj->ps_debounce, ps_deb);
	}
	else
	{
		APS_ERR("invalid content: '%s', length = %ld\n", buf, count);
	}
	return count;
}
/*----------------------------------------------------------------------------*/
static ssize_t pa12201001_show_trace(struct device_driver *ddri, char *buf)
{
	ssize_t res;
	if(!pa12201001_obj)
	{
		APS_ERR("pa12201001_obj is null!!\n");
		return 0;
	}

	res = snprintf(buf, PAGE_SIZE, "0x%04X\n", atomic_read(&pa12201001_obj->trace));
	return res;
}
/*----------------------------------------------------------------------------*/
static ssize_t pa12201001_store_trace(struct device_driver *ddri, const char *buf, size_t count)
{
    int trace;
    if(!pa12201001_obj)
	{
		APS_ERR("pa12201001_obj is null!!\n");
		return 0;
	}

	if(1 == sscanf(buf, "0x%x", &trace))
	{
		atomic_set(&pa12201001_obj->trace, trace);
	}
	else
	{
		APS_ERR("invalid content: '%s', length = %ld\n", buf, count);
	}
	return count;
}
/*----------------------------------------------------------------------------*/
static ssize_t pa12201001_show_als(struct device_driver *ddri, char *buf)
{
	int res;

	if(!pa12201001_obj)
	{
		APS_ERR("pa12201001_obj is null!!\n");
		return 0;
	}

	res = pa12201001_read_als(pa12201001_obj->client, &pa12201001_obj->als);
	if(res)
	{
		return snprintf(buf, PAGE_SIZE, "ERROR: %d\n", res);
	}
	else
	{
		return snprintf(buf, PAGE_SIZE, "0x%04X\n", pa12201001_obj->als);
	}
}
/*----------------------------------------------------------------------------*/
static ssize_t pa12201001_show_ps(struct device_driver *ddri, char *buf)
{
	int res;
	ssize_t dat;
	u8 raw_ps;
	if(!pa12201001_obj)
	{
		APS_ERR("cm3623_obj is null!!\n");
		return 0;
	}

	res = pa12201001_read_ps(pa12201001_obj->client, &raw_ps);
	if(res)
	{
		return snprintf(buf, PAGE_SIZE, "ERROR: %d\n", res);
	}
	else
	{
		#if defined(AGOLD_PROX_CALI_ENABLE)
	    if( raw_ps > PA12201001_Current_Ps_Thd_Value)
		#else
	    if( raw_ps > (ssize_t)atomic_read(&pa12201001_obj->ps_thd_val_high))
		#endif
		{
			dat = 0x80;
        }
        else
     	{
     		dat = 0x00;
		}
		return snprintf(buf, PAGE_SIZE, "%ld\n", dat);
	}
}
/*----------------------------------------------------------------------------*/
static ssize_t pa12201001_show_reg(struct device_driver *ddri, char *buf)
{
	u8 regdata;
	int i;
	int res=0;
	int count=0;
	if(!pa12201001_obj)
	{
		APS_ERR("pa12201001_obj is null!!\n");
		return 0;
	}
	for(i=0;i<14;i++)
	{
		res=hwmsen_read_byte(pa12201001_obj->client,0x00+i,&regdata);
		if(res<0)
		{
			break;
		}
		else
		{
			count+=sprintf(buf+count,"[%x] = (%x)\n",0x00+i,regdata);
		}
	}
	return count;
}
/*----------------------------------------------------------------------------*/
static ssize_t pa12201001_show_send(struct device_driver *ddri, char *buf)
{
    return 0;
}
/*----------------------------------------------------------------------------*/
static ssize_t pa12201001_store_send(struct device_driver *ddri, const char *buf, size_t count)
{
	int addr, cmd;
	u8 dat;

	if(!pa12201001_obj)
	{
		APS_ERR("pa12201001_obj is null!!\n");
		return 0;
	}
	else if(2 != sscanf(buf, "%x %x", &addr, &cmd))
	{
		APS_ERR("invalid format: '%s'\n", buf);
		return 0;
	}

	dat = (u8)cmd;

	return count;
}
/*----------------------------------------------------------------------------*/
static ssize_t pa12201001_show_recv(struct device_driver *ddri, char *buf)
{
    return 0;
}
/*----------------------------------------------------------------------------*/
static ssize_t pa12201001_store_recv(struct device_driver *ddri, const char *buf, size_t count)
{
	int addr;

	if(!pa12201001_obj)
	{
		APS_ERR("pa12201001_obj is null!!\n");
		return 0;
	}
	else if(1 != sscanf(buf, "%x", &addr))
	{
		APS_ERR("invalid format: '%s'\n", buf);
		return 0;
	}

	return count;
}
/*----------------------------------------------------------------------------*/
static ssize_t pa12201001_show_status(struct device_driver *ddri, char *buf)
{
	ssize_t len = 0;

	if(!pa12201001_obj)
	{
		APS_ERR("pa12201001_obj is null!!\n");
		return 0;
	}

	if(pa12201001_obj->hw)
	{
		len += snprintf(buf+len, PAGE_SIZE-len, "CUST: %d, (%d %d)\n",
			pa12201001_obj->hw->i2c_num, pa12201001_obj->hw->power_id, pa12201001_obj->hw->power_vol);
	}
	else
	{
		len += snprintf(buf+len, PAGE_SIZE-len, "CUST: NULL\n");
	}

	len += snprintf(buf+len, PAGE_SIZE-len, "REGS: %02X %02X %02X %02lX %02lX\n",
				atomic_read(&pa12201001_obj->als_cmd_val), atomic_read(&pa12201001_obj->ps_cmd_val),
				atomic_read(&pa12201001_obj->ps_thd_val),pa12201001_obj->enable, pa12201001_obj->pending_intr);

	len += snprintf(buf+len, PAGE_SIZE-len, "MISC: %d %d\n", atomic_read(&pa12201001_obj->als_suspend), atomic_read(&pa12201001_obj->ps_suspend));

	return len;
}
/*----------------------------------------------------------------------------*/
#define IS_SPACE(CH) (((CH) == ' ') || ((CH) == '\n'))
/*----------------------------------------------------------------------------*/
static int read_int_from_buf(struct pa12201001_priv *obj, const char* buf, size_t count, u32 data[], int len)
{
	int idx = 0;
	char *cur = (char*)buf, *end = (char*)(buf+count);

	while(idx < len)
	{
		while((cur < end) && IS_SPACE(*cur))
		{
			cur++;
		}

		if(1 != sscanf(cur, "%d", &data[idx]))
		{
			break;
		}

		idx++;
		while((cur < end) && !IS_SPACE(*cur))
		{
			cur++;
		}
	}
	return idx;
}
/*----------------------------------------------------------------------------*/
static ssize_t pa12201001_show_alslv(struct device_driver *ddri, char *buf)
{
	ssize_t len = 0;
	int idx;
	if(!pa12201001_obj)
	{
		APS_ERR("pa12201001_obj is null!!\n");
		return 0;
	}

	for(idx = 0; idx < pa12201001_obj->als_level_num; idx++)
	{
		len += snprintf(buf+len, PAGE_SIZE-len, "%d ", pa12201001_obj->hw->als_level[idx]);
	}
	len += snprintf(buf+len, PAGE_SIZE-len, "\n");
	return len;
}
/*----------------------------------------------------------------------------*/
static ssize_t pa12201001_store_alslv(struct device_driver *ddri, const char *buf, size_t count)
{
	if(!pa12201001_obj)
	{
		APS_ERR("pa12201001_obj is null!!\n");
		return 0;
	}
	else if(!strcmp(buf, "def"))
	{
		memcpy(pa12201001_obj->als_level, pa12201001_obj->hw->als_level, sizeof(pa12201001_obj->als_level));
	}
	else if(pa12201001_obj->als_level_num != read_int_from_buf(pa12201001_obj, buf, count,
			pa12201001_obj->hw->als_level, pa12201001_obj->als_level_num))
	{
		APS_ERR("invalid format: '%s'\n", buf);
	}
	return count;
}
/*----------------------------------------------------------------------------*/
static ssize_t pa12201001_show_alsval(struct device_driver *ddri, char *buf)
{
	ssize_t len = 0;
	int idx;
	if(!pa12201001_obj)
	{
		APS_ERR("pa12201001_obj is null!!\n");
		return 0;
	}

	for(idx = 0; idx < pa12201001_obj->als_value_num; idx++)
	{
		len += snprintf(buf+len, PAGE_SIZE-len, "%d ", pa12201001_obj->hw->als_value[idx]);
	}
	len += snprintf(buf+len, PAGE_SIZE-len, "\n");
	return len;
}

static ssize_t pa12201001_store_alsval(struct device_driver *ddri, const char *buf, size_t count)
{
	if(!pa12201001_obj)
	{
		APS_ERR("pa12201001_obj is null!!\n");
		return 0;
	}
	else if(!strcmp(buf, "def"))
	{
		memcpy(pa12201001_obj->als_value, pa12201001_obj->hw->als_value, sizeof(pa12201001_obj->als_value));
	}
	else if(pa12201001_obj->als_value_num != read_int_from_buf(pa12201001_obj, buf, count,
			pa12201001_obj->hw->als_value, pa12201001_obj->als_value_num))
	{
		APS_ERR("invalid format: '%s'\n", buf);
	}
	return count;
}

static ssize_t pa12201001_show_chipinfo(struct device_driver *ddri, char *buf)
{
    ssize_t len = 0;

	len += snprintf(buf+len,PAGE_SIZE-len,"PA12201001\n");

    return len;

}

/*---Offset At-------------------------------------------------------------------------*/
static ssize_t pa12201001_show_ps_offset(struct device_driver *ddri, char *buf)
{
	return 0;
}

static ssize_t pa12201001_set_ps_offset(struct device_driver *ddri, const char *buf, size_t count)
{
	return 0;
}

/*---------------------------------------------------------------------------------------*/
static DRIVER_ATTR(als,     S_IWUSR | S_IRUGO, pa12201001_show_als, NULL);
static DRIVER_ATTR(ps,      S_IWUSR | S_IRUGO, pa12201001_show_ps, NULL);
static DRIVER_ATTR(config,  S_IWUSR | S_IRUGO, pa12201001_show_config,	pa12201001_store_config);
static DRIVER_ATTR(alslv,   S_IWUSR | S_IRUGO, pa12201001_show_alslv, pa12201001_store_alslv);
static DRIVER_ATTR(alsval,  S_IWUSR | S_IRUGO, pa12201001_show_alsval, pa12201001_store_alsval);
static DRIVER_ATTR(trace,   S_IWUSR | S_IRUGO, pa12201001_show_trace,		pa12201001_store_trace);
static DRIVER_ATTR(status,  S_IWUSR | S_IRUGO, pa12201001_show_status, NULL);
static DRIVER_ATTR(send,    S_IWUSR | S_IRUGO, pa12201001_show_send, pa12201001_store_send); // No func
static DRIVER_ATTR(recv,    S_IWUSR | S_IRUGO, pa12201001_show_recv, pa12201001_store_recv);    // No func
static DRIVER_ATTR(reg,     S_IWUSR | S_IRUGO, pa12201001_show_reg, NULL);
static DRIVER_ATTR(setpsoffset, S_IWUSR | S_IRUGO, pa12201001_show_ps_offset,pa12201001_set_ps_offset);
static DRIVER_ATTR(chipinfo,     S_IWUSR | S_IRUGO, pa12201001_show_chipinfo,   NULL);

/*----------------------------------------------------------------------------*/
static struct driver_attribute *pa12201001_attr_list[] = {
    &driver_attr_als,
    &driver_attr_ps,
    &driver_attr_trace,        /*trace log*/
    &driver_attr_config,
    &driver_attr_alslv,
    &driver_attr_alsval,
    &driver_attr_status,
    &driver_attr_send,
    &driver_attr_recv,
    &driver_attr_reg,
    &driver_attr_setpsoffset,
    &driver_attr_chipinfo,
};

/*----------------------------------------------------------------------------*/
static int pa12201001_create_attr(struct device_driver *driver)
{
	int idx, err = 0;
	int num = (int)(sizeof(pa12201001_attr_list)/sizeof(pa12201001_attr_list[0]));
	if (driver == NULL)
	{
		return -EINVAL;
	}

	for(idx = 0; idx < num; idx++)
	{
		if((err = driver_create_file(driver, pa12201001_attr_list[idx])))
		{
			APS_ERR("driver_create_file (%s) = %d\n", pa12201001_attr_list[idx]->attr.name, err);
			break;
		}
	}
	return err;
}
/*----------------------------------------------------------------------------*/
static int pa12201001_delete_attr(struct device_driver *driver)
{
	int idx ,err = 0;
	int num = (int)(sizeof(pa12201001_attr_list)/sizeof(pa12201001_attr_list[0]));

	if (!driver)
	return -EINVAL;

	for (idx = 0; idx < num; idx++)
	{
		driver_remove_file(driver, pa12201001_attr_list[idx]);
	}

	return err;
}

/*----------------------------------interrupt functions-----------------------*/
static int intr_flag = 0;
/*----------------------------------------------------------------------------*/
#ifndef CUSTOM_KERNEL_SENSORHUB
static int pa12201001_check_intr(struct i2c_client *client)
{
	int res;
	u8 psdata=0;
	u8 cfgdata=0;

	res = hwmsen_read_byte(client,REG_PS_DATA,&psdata);
	if(res<0)
	{
		APS_ERR("i2c_read function err res = %d\n",res);
		return -1;
	}

	APS_LOG("PA12201001_REG_PS_DATA value = %x \n",psdata);

	res = hwmsen_read_byte(client,REG_CFG2,&cfgdata);
	if(res<0)
	{
		APS_ERR("i2c_read function err res = %d\n",res);
		return -1;
	}

	APS_LOG("PA12201001_READ INT STATUS:CFG2 cfgdata = 0x%x\n",cfgdata);

	if(cfgdata & 0x02)
	{
		APS_LOG("[mcz] if\n");
	 	intr_flag = 0;//for close
	}
	else
	{
		APS_LOG("[mcz] else\n");
		intr_flag = 1;//for away
	}

	return 0;
}

static int pa12201001_clear_int_flag(struct i2c_client *client)
{
	//Clear INT FLAG
	int res = 0;
	u8 cfgdata = 0;
	res = hwmsen_read_byte(client,REG_CFG2,&cfgdata);
	if(res<0)
	{
		APS_ERR("i2c_read function err res = %d\n",res);
		return -1;
	}

	APS_LOG("PA12201001_READ INT STATUS:CFG2 cfgdata = 0x%x\n",cfgdata);
	if(cfgdata & 0x02)
	{
		cfgdata=cfgdata & 0xFD ; //Clear PS INT
		res = hwmsen_write_byte(client,REG_CFG2,cfgdata);
	  	if(res<0)
	  	{
			APS_ERR("i2c_send function err res = %d\n",res);
			return -1;
		}
	}
	APS_LOG("PA12201001_REG_INT_FLAG clear!\n");

	return 0;
}
#endif  //#ifndef CUSTOM_KERNEL_SENSORHUB
/*----------------------------------------------------------------------------*/
static void pa12201001_eint_work(struct work_struct *work)
{
	int res = 0;
	int sendvalue = 0;
	u8 cfgdata=0;

	#ifdef CUSTOM_KERNEL_SENSORHUB
	int psvalue = 0;
	if((pa12201001_read_ps(obj->client, &obj->ps)))
	{
		printk("pa12201001 read ps data: %d\n", err);
	}
    psvalue = pa12201001_get_ps_value(obj, obj->ps);
    res = ps_report_interrupt_data(intr_flag_value);
    if(res != 0)
    {
        printk("pa12201001_eint_work err\n");
    }
	#else //#ifdef CUSTOM_KERNEL_SENSORHUB

	struct pa12201001_priv *obj = (struct pa12201001_priv *)container_of(work, struct pa12201001_priv, eint_work);

	res = pa12201001_check_intr(obj->client);
	if((pa12201001_read_ps(obj->client, &obj->ps)))
	{
		printk("pa12201001 read ps data err\n");
	}
	pa12201001_get_ps_value(obj, obj->ps);
	if(!intr_flag_value)
	{
		g_interrupt_flag = 1;
		printk("[ALS/PS][ljj]  closing...\n");
	}
	if(!intr_flag_value)
	{
		APS_LOG("[mcz] AGOLD_PROX_CALI_ENABLE intr_flag_value\n");
		// Set PS threshold
		sendvalue=0xff;
		res=hwmsen_write_byte(obj->client,REG_PS_TH,sendvalue); //set TH threshold

		sendvalue=(u8)(PA12201001_Current_Ps_Thd_Value & 0xFF);
		res=hwmsen_write_byte(obj->client,REG_PS_TL,sendvalue); //set TL threshold
	}
	else
	{
		APS_LOG("[mcz]else AGOLD_PROX_CALI_ENABLE intr_flag_value \n");
		// Set PS threshold
		sendvalue=(u8)(PA12201001_Current_Ps_Thd_Value & 0xFF);
		res=hwmsen_write_byte(obj->client,REG_PS_TH,sendvalue); //set TH threshold

		sendvalue=0;
		res=hwmsen_write_byte(obj->client,REG_PS_TL,sendvalue); //set TL threshold

	}
	pa12201001_clear_int_flag(obj->client);
	res = hwmsen_read_byte(obj->client,REG_CFG2,&cfgdata);
	if(res<0)
	{
		APS_ERR("i2c_read function err res = %d\n",res);
	}

	APS_LOG("[eint_work][after clear int flsg] CFG2 cfgdata = 0x%x\n",cfgdata);

	if(res != 0)
	{
		goto EXIT_INTR_ERR;
	}
	else
	{
		printk("pa12201001 interrupt value = %d\n", intr_flag_value);
		res = ps_report_interrupt_data(intr_flag_value);
	}

	enable_irq(obj->irq);
	return;

EXIT_INTR_ERR:
	pa12201001_check_intr(obj->client);
	enable_irq(obj->irq);
	printk("pa12201001_eint_work err: %d\n", res);
	return;
	#endif //#ifdef CUSTOM_KERNEL_SENSORHUB

}



#ifdef CUSTOM_KERNEL_SENSORHUB
static void pa12201001_init_done_work(struct work_struct *work)
{
    struct pa12201001_priv *obj = pa12201001_obj;
    PA12_CUST_DATA *p_cust_data;
    SCP_SENSOR_HUB_DATA data;
    int max_cust_data_size_per_packet;
    int i;
    uint sizeOfCustData;
    uint len;
    char *p = (char *)obj->hw;

    APS_FUN();

    p_cust_data = (PA12_CUST_DATA *)data.set_cust_req.custData;
    sizeOfCustData = sizeof(*(obj->hw));
    max_cust_data_size_per_packet = sizeof(data.set_cust_req.custData) - offsetof(PA12_SET_CUST, data);

    for (i=0;sizeOfCustData>0;i++)
    {
        data.set_cust_req.sensorType = ID_PROXIMITY;
        data.set_cust_req.action = SENSOR_HUB_SET_CUST;
        p_cust_data->setCust.action = PA12_CUST_ACTION_SET_CUST;
        p_cust_data->setCust.part = i;

        if (sizeOfCustData > max_cust_data_size_per_packet)
        {
            len = max_cust_data_size_per_packet;
        }
        else
        {
            len = sizeOfCustData;
        }

        memcpy(p_cust_data->setCust.data, p, len);
        sizeOfCustData -= len;
        p += len;

        len += offsetof(SCP_SENSOR_HUB_SET_CUST_REQ, custData) + offsetof(PA12_SET_CUST, data);
        SCP_sensorHub_req_send(&data, &len, 1);
    }

    data.set_cust_req.sensorType = ID_PROXIMITY;
    data.set_cust_req.action = SENSOR_HUB_SET_CUST;
    p_cust_data->setEintInfo.action = PA12_CUST_ACTION_SET_EINT_INFO;
    p_cust_data->setEintInfo.gpio_mode = GPIO_ALS_EINT_PIN_M_EINT;
    p_cust_data->setEintInfo.gpio_pin = GPIO_ALS_EINT_PIN;
    p_cust_data->setEintInfo.eint_num = CUST_EINT_ALS_NUM;
    p_cust_data->setEintInfo.eint_is_deb_en = CUST_EINT_ALS_DEBOUNCE_EN;
    p_cust_data->setEintInfo.eint_type = CUST_EINT_ALS_TYPE;
    len = offsetof(SCP_SENSOR_HUB_SET_CUST_REQ, custData) + sizeof(p_cust_data->setEintInfo);
    SCP_sensorHub_req_send(&data, &len, 1);

}
#endif //#ifdef CUSTOM_KERNEL_SENSORHUB

/*----------------------------------------------------------------------------*/
#ifdef CUSTOM_KERNEL_SENSORHUB
static int pa12201001_irq_handler(void* data, uint len)
{
	struct pa12201001_priv *obj = pa12201001_obj;
    SCP_SENSOR_HUB_DATA_P rsp = (SCP_SENSOR_HUB_DATA_P)data;

	if(!obj)
	{
		return -1;
	}

    printk("len = %d, type = %d, action = %d, errCode = %d\n", len, rsp->rsp.sensorType, rsp->rsp.action, rsp->rsp.errCode);

    switch(rsp->rsp.action)
    {
        case SENSOR_HUB_NOTIFY:
            switch(rsp->notify_rsp.event)
            {
                case SCP_INIT_DONE:
                    schedule_work(&obj->init_done_work);
                    //schedule_delayed_work(&obj->init_done_work, HZ);
                    break;
                case SCP_NOTIFY:
                    if (PA12_NOTIFY_PROXIMITY_CHANGE == rsp->notify_rsp.data[0])
                    {
                        intr_flag_value = rsp->notify_rsp.data[1];
                        pa12201001_eint_func();
                    }
                    else
                    {
                        printk("Unknow notify");
                    }
                    break;
                default:
                    printk("Error sensor hub notify");
                    break;
            }
            break;
        default:
            printk("Error sensor hub action");
            break;
    }

    return 0;
}
#endif //#ifdef CUSTOM_KERNEL_SENSORHUB


/*----------------------------------------------------------------------------*/

static void pa12201001_eint_func(void)
{
	struct pa12201001_priv *obj = g_pa12201001_ptr;
	if(!obj)
	{
		return;
	}
	schedule_work(&obj->eint_work);
}
/*-------------------------------MISC device related------------------------------------------*/
#if defined(CONFIG_OF)
static irqreturn_t pa12201001_eint_handler(int irq, void *desc)
{
	pa12201001_eint_func();
	disable_irq_nosync(pa12201001_obj->irq);

	return IRQ_HANDLED;
}
#endif
/*----------------------------------------------------------------------------*/
int pa12201001_setup_eint(struct i2c_client *client)
{
#if defined(CONFIG_OF)
	u32 ints[2] = { 0, 0 };
#endif

	int ret;
	struct pinctrl *pinctrl;
	struct pinctrl_state *pins_default;
	struct pinctrl_state *pins_cfg;

	struct pa12201001_priv *obj = i2c_get_clientdata(client);

	g_pa12201001_ptr = obj;

	alsps_PltFmDev = get_alsps_platformdev();

	pinctrl = devm_pinctrl_get(&alsps_PltFmDev->dev);
	if (IS_ERR(pinctrl))
	{
		ret = PTR_ERR(pinctrl);
		APS_ERR("Cannot find alsps pinctrl!\n");
	}
	pins_default = pinctrl_lookup_state(pinctrl, "pin_default");
	if (IS_ERR(pins_default))
	{
		ret = PTR_ERR(pins_default);
		APS_ERR("Cannot find alsps pinctrl default!\n");

	}

	pins_cfg = pinctrl_lookup_state(pinctrl, "pin_cfg");
	if (IS_ERR(pins_cfg))
	{
		ret = PTR_ERR(pins_cfg);
		APS_ERR("Cannot find alsps pinctrl pin_cfg!\n");

	}
	pinctrl_select_state(pinctrl, pins_cfg);

	if (pa12201001_obj->irq_node)
	{
		of_property_read_u32_array(pa12201001_obj->irq_node, "debounce", ints,
					   ARRAY_SIZE(ints));
		gpio_request(ints[0], "p-sensor");
		gpio_set_debounce(ints[0], ints[1]);
		APS_LOG("ints[0] = %d, ints[1] = %d!!\n", ints[0], ints[1]);

		pa12201001_obj->irq = irq_of_parse_and_map(pa12201001_obj->irq_node, 0);
		APS_LOG("pa12201001_obj->irq = %d\n", pa12201001_obj->irq);
		if (!pa12201001_obj->irq)
		{
			APS_ERR("irq_of_parse_and_map fail!!\n");
			return -EINVAL;
		}

		if (request_irq(pa12201001_obj->irq, pa12201001_eint_handler, IRQF_TRIGGER_NONE, "ALS-eint", NULL))
		{
			APS_ERR("IRQ LINE NOT AVAILABLE!!\n");
			return -EINVAL;
		}

		enable_irq(pa12201001_obj->irq);
	}
	else
	{
		APS_ERR("null irq node!!\n");
		return -EINVAL;
	}

	return 0;
}

/************************************************************/
static int pa12201001_open(struct inode *inode, struct file *file)
{
	file->private_data = pa12201001_i2c_client;

	if (!file->private_data)
	{
		APS_ERR("null pointer!!\n");
		return -EINVAL;
	}
	return nonseekable_open(inode, file);
}
/************************************************************/

static int pa12201001_release(struct inode *inode, struct file *file)
{
	file->private_data = NULL;
	return 0;
}


int pa12201001_set_ps_threshold_factory(struct i2c_client *client,int ps_thd_value,int high_th)
{
	u8 databuf[2];
	int res = 0;
	if(high_th == 1)
	{
		databuf[0] = REG_PS_TH;
		databuf[1] = (u8)(ps_thd_value & 0xFF);
		res = i2c_master_send(client, databuf, 0x2);
		if(res <= 0)
		{
			return res;
		}
	}
	else
	{
		databuf[0] = REG_PS_TL;
		databuf[1] = (u8)(ps_thd_value & 0xFF);
		res = i2c_master_send(client, databuf, 0x2);
		if(res <= 0)
		{
			return res;
		}
	}
	return 0;
}

/************************************************************/

#if defined(AGOLD_PROX_CALI_ENABLE)
int PA12201001_set_ps_threshold(struct i2c_client *client,int ps_thd_value)
{
	int res = 0;
	u8 ps_value = 0;

	// Set PS threshold
	APS_LOG("[mcz]PA12201001_set_ps_threshold\n");
	res=hwmsen_write_byte(client,REG_PS_TH,ps_thd_value); //set TH threshold
	if(res < 0)
	{
		return res;
	}
	//低门限值是不是应该设为0
	res=hwmsen_write_byte(client,REG_PS_TL,ps_thd_value); //set TL threshold
	if(res < 0)
	{
		return res;
	}

	res=hwmsen_read_byte(client,REG_PS_TH,&ps_value);
	if(res < 0)
	{
		return res;
	}
	APS_LOG("[mcz][set]REG_PS_TH = 0x%x\n",ps_value);
	res=hwmsen_read_byte(client,REG_PS_TL,&ps_value);
	if(res < 0)
	{
		return res;
	}
	APS_LOG("[mcz][set]REG_PS_TL = 0x%x\n",ps_value);

	return 0;
}

#define PA12201001_PPCOUNT_MIN 0
#define PA12201001_PPCOUNT_MAX 4
#define PA12201001_READ_TIMES  5
#define PA12201001_MAX_PS_VALUE  0xFF
#define  PS_CALI_TIMES 25

static int pcount1 = 0;
static int pcount2 = 0;

#if 1
static int PA12201001_get_ps_data_for_cali(struct i2c_client *client, int flag)
{
	u8 ps_tmp_dat = 0;
	int max_ps_value = 0;
	int min_ps_value = 0;
	u8 i = 0 ;
	int res = 0;

	printk("[Agold spl] PA12201001_get_ps_data_for_cali Start, flag = %d.\n", flag);

	disable_irq_nosync(pa12201001_obj->irq);

	if((res = pa12201001_enable_ps(client, 1)))
	{
		APS_ERR("enable als fail: %d\n", res);
		return res;
	}

	if(1 == flag)
	{
		for(i=0; i<PS_CALI_TIMES; i++)
		{
			res = pa12201001_read_ps(client, &ps_tmp_dat);
			if(res)
			{
				APS_LOG("[Bruce] Read ps data err.\n");
				return res;
			}
			APS_LOG("[Bruce] ps_tmp_dat = 0x%x.\n",ps_tmp_dat);
			if(i == 0)
			{
				min_ps_value = ps_tmp_dat;
			}
			if(min_ps_value > ps_tmp_dat)
			{
				min_ps_value = 0xff&ps_tmp_dat;
			}
			msleep(1);
		}
		res = min_ps_value ;
	}
	else if(2 == flag)
	{
		for(i=0; i<PS_CALI_TIMES; i++)
		{
			res = pa12201001_read_ps(client, &ps_tmp_dat);
			if(res)
			{
				APS_LOG("[Bruce] Read ps data err.\n");
				return res;
			}
			APS_LOG("[Bruce] ps_tmp_dat = 0x%x.\n",ps_tmp_dat);
			if(max_ps_value < ps_tmp_dat)
			{
				max_ps_value = 0xff&ps_tmp_dat;
			}
			msleep(1);
		}
		res = max_ps_value;
	}

	printk("[Agold spl] PA12201001_get_ps_data_for_cali end.\n");

	enable_irq(pa12201001_obj->irq);

	return res;
}

#else
static int PA12201001_get_ps_data_for_cali(struct i2c_client *client, int flag)
{
	u8 ps_tmp_dat = 0;
	int  ps_dat[2] = {0,0};
	int max_ps_value = 0;
	int i = 0 ,pcount = 0;
	int res = 0;
	int ps_count_data[30] = {0};
	char databuf[2] = {0,0};
	int ps_raw =0 ;


	//first we shold disable als ps and set wait time min
	if((res = pa12201001_enable_als(client, 0)))
	{
		APS_ERR("enable als fail: %ld\n", res);
		return res;
	}
	if((res = pa12201001_enable_ps(client, 0)))
	{
		APS_ERR("enable als fail: %ld\n", res);
		return res;
	}

	if((res = pa12201001_enable_ps(client, 1)))
	{
		APS_ERR("enable als fail: %ld\n", res);
		return res;
	}

	//set LED current 100mA
	APS_LOG("[mcz] pcount = 0x%x\n",pcount);

	mdelay(130);
	max_ps_value = 0;
	for(i = 0;i < PA12201001_READ_TIMES ; i++)
	{
		if(res = pa12201001_read_ps(client, &ps_tmp_dat))
		{
			APS_LOG("[Agold mcz] Read ps data err.\n");
			return res;
		}
		APS_LOG("[Agold mcz] ps_tmp_dat = 0x%x.\n",ps_tmp_dat);
		if(max_ps_value < ps_tmp_dat)
		{
			max_ps_value = 0xff&ps_tmp_dat;
		}
		msleep(1);
	}

	APS_LOG("[Agold mcz] max_ps_value = 0x%x\n",max_ps_value);

	//last we shold enable als and set wait time 200ms
	if((res = pa12201001_enable_ps(client, 0)))
	{
		APS_ERR("enable als fail: %ld\n", res);
		return res;
	}
	mdelay(200);
	if((res = pa12201001_enable_ps(client, 1)))
	{
		APS_ERR("enable als fail: %ld\n", res);
		return res;
	}
	if((res = pa12201001_enable_als(client, 1)))
	{
		APS_ERR("enable als fail: %ld\n", res);
		return res;
	}
	return 0;
}
#endif
#endif
static long pa12201001_unlocked_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
		struct i2c_client *client = (struct i2c_client*)file->private_data;
		struct pa12201001_priv *obj = i2c_get_clientdata(client);
		long err = 0;
		void __user *ptr = (void __user*) arg;
		u8 dat;
		uint32_t enable;
		int ps_result;
		int  ps_dat[2] = {0,0};
		int ps_cali_data;
		#ifdef CUSTOM_KERNEL_SENSORHUB
		SCP_SENSOR_HUB_DATA data;
		PA12_CUST_DATA *pCustData;
		int len;

		data.set_cust_req.sensorType = ID_PROXIMITY;
		data.set_cust_req.action = SENSOR_HUB_SET_CUST;
		pCustData = (PA12_CUST_DATA *)(&data.set_cust_req.custData);
		#endif //#ifdef CUSTOM_KERNEL_SENSORHUB

		switch (cmd)
		{
			case ALSPS_SET_PS_MODE:
				if(copy_from_user(&enable, ptr, sizeof(enable)))
				{
					err = -EFAULT;
					goto err_out;
				}
				if(enable)
				{
					if((err = pa12201001_enable_ps(obj->client, 1)))
					{
						APS_ERR("enable ps fail: %ld\n", err);
						goto err_out;
					}

					set_bit(CMC_BIT_PS, &obj->enable);
				}
				else
				{
					if((err = pa12201001_enable_ps(obj->client, 0)))
					{
						APS_ERR("disable ps fail: %ld\n", err);
						goto err_out;
					}
					clear_bit(CMC_BIT_PS, &obj->enable);
				}
				break;

			case ALSPS_GET_PS_MODE:
				enable = test_bit(CMC_BIT_PS, &obj->enable) ? (1) : (0);
				if(copy_to_user(ptr, &enable, sizeof(enable)))
				{
					err = -EFAULT;
					goto err_out;
				}
				break;

			case ALSPS_GET_PS_DATA:
				if((err = pa12201001_read_ps(obj->client, &obj->ps)))
				{
					goto err_out;
				}

				dat = pa12201001_get_ps_value(obj, obj->ps);
				if(copy_to_user(ptr, &dat, sizeof(dat)))
				{
					err = -EFAULT;
					goto err_out;
				}
				break;

			case ALSPS_GET_PS_RAW_DATA:

			#if defined(AGOLD_PROX_CALI_ENABLE)
			err = pa12201001_read_ps(obj->client, &dat);
			if(err)
			{
				goto err_out;
			}
			ps_dat[0] = dat;
			ps_dat[1] = PA12201001_Current_Ps_Thd_Value;
			APS_LOG("[Agold mcz] ps_dat[0] = %d , ps_dat[1] = %d.\n",ps_dat[0],ps_dat[1]);
			if(copy_to_user(ptr, ps_dat, sizeof(ps_dat)))
			{
				err = -EFAULT;
				goto err_out;
			}
			#else

			if((err = pa12201001_read_ps(obj->client, &obj->ps)))
			{
				goto err_out;
			}

			dat = obj->ps;
			if(copy_to_user(ptr, &dat, sizeof(dat)))
			{
				err = -EFAULT;
				goto err_out;
			}
			#endif
				break;

			case ALSPS_SET_ALS_MODE:

				if(copy_from_user(&enable, ptr, sizeof(enable)))
				{
					err = -EFAULT;
					goto err_out;
				}
				if(enable)
				{
					if((err = pa12201001_enable_als(obj->client, 1)))
					{
						APS_ERR("enable als fail: %ld\n", err);
						goto err_out;
					}
					set_bit(CMC_BIT_ALS, &obj->enable);
				}
				else
				{
					if((err = pa12201001_enable_als(obj->client, 0)))
					{
						APS_ERR("disable als fail: %ld\n", err);
						goto err_out;
					}
					clear_bit(CMC_BIT_ALS, &obj->enable);
				}
				break;

			case ALSPS_GET_ALS_MODE:
				enable = test_bit(CMC_BIT_ALS, &obj->enable) ? (1) : (0);
				if(copy_to_user(ptr, &enable, sizeof(enable)))
				{
					err = -EFAULT;
					goto err_out;
				}
				break;

			case ALSPS_GET_ALS_DATA:
				if((err = pa12201001_read_als(obj->client, &obj->als)))
				{
					goto err_out;
				}

				dat = pa12201001_get_als_value(obj, obj->als);
				if(copy_to_user(ptr, &dat, sizeof(dat)))
				{
					err = -EFAULT;
					goto err_out;
				}
				break;

			case ALSPS_GET_ALS_RAW_DATA:
				if((err = pa12201001_read_als(obj->client, &obj->als)))
				{
					goto err_out;
				}

				dat = obj->als;
				if(copy_to_user(ptr, &dat, sizeof(dat)))
				{
					err = -EFAULT;
					goto err_out;
				}
				break;

			/*----------------------------------for factory mode test---------------------------------------*/
			case ALSPS_GET_PS_TEST_RESULT:
				if((err = pa12201001_read_ps(obj->client, &obj->ps)))
				{
					goto err_out;
				}
				if(obj->ps > atomic_read(&obj->ps_thd_val_high))
					{
						ps_result = 0;
					}
				else	ps_result = 1;

				if(copy_to_user(ptr, &ps_result, sizeof(ps_result)))
				{
					err = -EFAULT;
					goto err_out;
				}
				break;
			/*------------------------------------------------------------------------------------------*/
			case ALSPS_IOCTL_CLR_CALI:
				if(copy_from_user(&dat, ptr, sizeof(dat)))
				{
					err = -EFAULT;
					goto err_out;
				}
				if(dat == 0)
					obj->ps_cali = 0;

				#ifdef CUSTOM_KERNEL_SENSORHUB
		        pCustData->clearCali.action = PA12_CUST_ACTION_CLR_CALI;
		        len = offsetof(SCP_SENSOR_HUB_SET_CUST_REQ, custData) + sizeof(pCustData->clearCali);

		        err = SCP_sensorHub_req_send(&data, &len, 1);
				#endif

				break;
			case ALSPS_IOCTL_SET_CALI:
				if(copy_from_user(&ps_cali_data, ptr, sizeof(ps_cali_data)))
				{
					err = -EFAULT;
					goto err_out;
				}

				obj->ps_cali = ps_cali_data;

				#ifdef CUSTOM_KERNEL_SENSORHUB
				pCustData->setCali.action = PA12_CUST_ACTION_SET_CALI;
				pCustData->setCali.cali = ps_cali_data;
				len = offsetof(SCP_SENSOR_HUB_SET_CUST_REQ, custData) + sizeof(pCustData->setCali);

				err = SCP_sensorHub_req_send(&data, &len, 1);
				#endif


				default:
					APS_ERR("%s not supported = 0x%04x", __FUNCTION__, cmd);
					err = -ENOIOCTLCMD;
					break;
		}

		err_out:
		return err;
}

#if defined(AGOLD_PROX_CALI_ENABLE)
static void agold_pa12201001_set_ps_cali(AGOLD_PS_CALI_DATA_STRUCT ps_cali_dat)
{

	disable_irq_nosync(pa12201001_obj->irq);

	if(ps_cali_dat.close > AGOLD_PA12201001_THRESHOLD_MIN && ps_cali_dat.close <= 0xF0)
	{
		spin_lock(&ps_cali_lock);
		PA12201001_Current_Ps_Thd_Value = ps_cali_dat.close;
		spin_unlock(&ps_cali_lock);
	}
	else
	{
		spin_lock(&ps_cali_lock);
		#if defined(AGOLD_DEFINED_ALSPS_PA12201001_PS_THD_VALUE)
		PA12201001_Current_Ps_Thd_Value = agold_strtol(AGOLD_DEFINED_ALSPS_PA12201001_PS_THD_VALUE);

		if( PA12201001_Current_Ps_Thd_Value < AGOLD_PA12201001_THRESHOLD_MIN )
			PA12201001_Current_Ps_Thd_Value = AGOLD_PA12201001_THRESHOLD_MIN;
		else if ( PA12201001_Current_Ps_Thd_Value > 0xF0 )
			PA12201001_Current_Ps_Thd_Value = 0xF0;

		ps_cali_dat.close = PA12201001_Current_Ps_Thd_Value;
		ps_cali_dat.far_away = PA12201001_Current_Ps_Thd_Value;
		#else
		PA12201001_Current_Ps_Thd_Value = AGOLD_PA12201001_THRESHOLD_MIN;
		ps_cali_dat.close = AGOLD_PA12201001_THRESHOLD_MIN;
		ps_cali_dat.far_away = AGOLD_PA12201001_THRESHOLD_MIN;
		#endif
		spin_unlock(&ps_cali_lock);
	}
	printk("[Bruce] %d, ps_cali_dat.close = 0x%x ,ps_cali_dat.ppcount = 0x%x\n ",__LINE__,ps_cali_dat.close,ps_cali_dat.ppcount);
	printk("[Bruce] ps_cali_dat.valid = %d,PA12201001_Current_Ps_Thd_Value = 0x%x \n ",ps_cali_dat.valid, PA12201001_Current_Ps_Thd_Value);

	PA12201001_set_ps_threshold(pa12201001_i2c_client,(unsigned int)(PA12201001_Current_Ps_Thd_Value));

	enable_irq(pa12201001_obj->irq);
}

static int agold_pa12201001_get_ps_deep_cali_data(void)
{

	pcount1 = PA12201001_get_ps_data_for_cali(pa12201001_i2c_client, 1);
	printk("pcount1 = %d\n",pcount1);
	return 1;
}

static int agold_pa12201001_get_ps_raw_data_for_cali(AGOLD_PS_CALI_DATA_STRUCT *ps_cali_dat)
{
	int res = 0;

	pcount2 = PA12201001_get_ps_data_for_cali(pa12201001_i2c_client, 2);
	disable_irq_nosync(pa12201001_obj->irq);

	printk("[Agold spl] agold_pa12201001_get_ps_raw_data_for_cali start, pcount1 = %d, pcount2 = %d\n",pcount1, pcount2);
	if(pcount1 > 0xF0)//stucture is not good
	{
		ps_cali_dat->deep_cali_flag = DEEP_CALI_STRUCTE_NOT_GOOD;
		ps_cali_dat->close = 0;
		ps_cali_dat->far_away = 0;
		ps_cali_dat->valid = 0;
		ps_cali_dat->ppcount = 0;
		ps_cali_dat->no_barrier_flag = 0;
		printk("[Bruce] Warning the structure not good,ps_cali_dat->deep_cali_flag = %d\n",ps_cali_dat->deep_cali_flag);
		res = DEEP_CALI_STRUCTE_NOT_GOOD;
	}
	else if((pcount1 - pcount2 >= 0x02)||pcount1 > 0xA0) //get ps raw error,maybe you have place obstacle when getting ps raw data
	{
		ps_cali_dat->deep_cali_flag = DEEP_CALI_GET_PS_RAW_DATA_ERROR;
		ps_cali_dat->close = 0;
		ps_cali_dat->far_away = 0;
		ps_cali_dat->valid = 0;
		ps_cali_dat->ppcount = 0;
		ps_cali_dat->no_barrier_flag = 0;
		printk("[Bruce] get ps raw error,maybe you have place obstacle when getting ps raw data,ps_cali_dat->deep_cali_flag = %d\n",ps_cali_dat->deep_cali_flag);
		res = DEEP_CALI_GET_PS_RAW_DATA_ERROR;
	}
	else if(pcount2 -pcount1 < 0x15)//too far or no barrier,need set near
	{
		ps_cali_dat->deep_cali_flag = DEEP_CALI_SET_NEAR;
		ps_cali_dat->close = 0;
		ps_cali_dat->far_away = 0;
		ps_cali_dat->valid = 0;
		ps_cali_dat->ppcount = 0;
		ps_cali_dat->no_barrier_flag = 0;
		printk("[Bruce] too far,need set near,ps_cali_dat->deep_cali_flag = %d\n",ps_cali_dat->deep_cali_flag);
		res =  DEEP_CALI_SET_NEAR;
	}
	else
	{
		ps_cali_dat->close = pcount2;
		if(ps_cali_dat->close >= 0xf0)
		{
			ps_cali_dat->close = 0xf0;
		}
		ps_cali_dat->far_away = ps_cali_dat->close ;//ps_tmp_dat;
		ps_cali_dat->ppcount = 0;
		ps_cali_dat->valid = 1;
		res = DEEP_CALI_SUCCESS;
	}

	enable_irq(pa12201001_obj->irq);
	printk("[Agold spl] agold_pa12201001_get_ps_raw_data_for_cali end, res = %d\n",res);
	return res;
}


#endif

/*--------------------misc device related operation functions--------------------------*/
static struct file_operations pa12201001_fops = {
	.owner = THIS_MODULE,
	.open = pa12201001_open,
	.release = pa12201001_release,
	.unlocked_ioctl = pa12201001_unlocked_ioctl,
};

static struct miscdevice pa12201001_device = {
	.minor = MISC_DYNAMIC_MINOR,
	.name = "pa12201001",
	.fops = &pa12201001_fops,
};

/*--------------------------------------------------------------------------------------*/

// if use  this typ of enable , Gsensor should report inputEvent(x, y, z ,stats, div) to HAL
static int als_open_report_data(int open)
{
	//should queuq work to report event if  is_report_input_direct=true
	return 0;
}

// if use  this typ of enable , Gsensor only enabled but not report inputEvent to HAL

static int als_enable_nodata(int en)
{
	int res = 0;
#ifdef CUSTOM_KERNEL_SENSORHUB
    SCP_SENSOR_HUB_DATA req;
    int len;
#endif //#ifdef CUSTOM_KERNEL_SENSORHUB

    printk("pa12201001_obj als enable value = %d\n", en);

#ifdef CUSTOM_KERNEL_SENSORHUB
    req.activate_req.sensorType = ID_LIGHT;
    req.activate_req.action = SENSOR_HUB_ACTIVATE;
    req.activate_req.enable = en;
    len = sizeof(req.activate_req);
    res = SCP_sensorHub_req_send(&req, &len, 1);
#else //#ifdef CUSTOM_KERNEL_SENSORHUB
	if(!pa12201001_obj)
	{
		printk("pa12201001_obj is null!!\n");
		return -1;
	}
	res=	pa12201001_enable_als(pa12201001_obj->client, en);
#endif //#ifdef CUSTOM_KERNEL_SENSORHUB
	if(res){
		printk("als_enable_nodata is failed!!\n");
		return -1;
	}
	return 0;
}

static int als_set_delay(u64 ns)
{
	return 0;
}

static int als_get_data(int* value, int* status)
{
	int err = 0;
#ifdef CUSTOM_KERNEL_SENSORHUB
    SCP_SENSOR_HUB_DATA req;
    int len;
#else
    struct pa12201001_priv *obj = NULL;
#endif //#ifdef CUSTOM_KERNEL_SENSORHUB

#ifdef CUSTOM_KERNEL_SENSORHUB
    req.get_data_req.sensorType = ID_LIGHT;
    req.get_data_req.action = SENSOR_HUB_GET_DATA;
    len = sizeof(req.get_data_req);
    err = SCP_sensorHub_req_send(&req, &len, 1);
    if (err)
    {
        printk("SCP_sensorHub_req_send fail!\n");
    }
    else
    {
        *value = req.get_data_rsp.int16_Data[0];
        *status = SENSOR_STATUS_ACCURACY_MEDIUM;
    }

    if(atomic_read(&pa12201001_obj->trace) & CMC_TRC_PS_DATA)
	{
        printk("value = %d\n", *value);
        //show data
	}
#else //#ifdef CUSTOM_KERNEL_SENSORHUB
	if(!pa12201001_obj)
	{
		printk("pa12201001_obj is null!!\n");
		return -1;
	}
	obj = pa12201001_obj;
	if((err = pa12201001_read_als(obj->client, &obj->als)))
	{
		err = -1;
	}
	else
	{
		*value = pa12201001_get_als_value(obj, obj->als);
		*status = SENSOR_STATUS_ACCURACY_MEDIUM;
	}
#endif //#ifdef CUSTOM_KERNEL_SENSORHUB

	return err;
}

// if use  this typ of enable , Gsensor should report inputEvent(x, y, z ,stats, div) to HAL
static int ps_open_report_data(int open)
{
	//should queuq work to report event if  is_report_input_direct=true
	return 0;
}

// if use  this typ of enable , Gsensor only enabled but not report inputEvent to HAL

static int ps_enable_nodata(int en)
{
	int res = 0;
#ifdef CUSTOM_KERNEL_SENSORHUB
    SCP_SENSOR_HUB_DATA req;
    int len;
#endif //#ifdef CUSTOM_KERNEL_SENSORHUB

    printk("pa12201001_obj als enable value = %d\n", en);

#ifdef CUSTOM_KERNEL_SENSORHUB
    req.activate_req.sensorType = ID_PROXIMITY;
    req.activate_req.action = SENSOR_HUB_ACTIVATE;
    req.activate_req.enable = en;
    len = sizeof(req.activate_req);
    res = SCP_sensorHub_req_send(&req, &len, 1);
#else //#ifdef CUSTOM_KERNEL_SENSORHUB
	if(!pa12201001_obj)
	{
		printk("pa12201001_obj is null!!\n");
		return -1;
	}
	res=	pa12201001_enable_ps(pa12201001_obj->client, en);
#endif //#ifdef CUSTOM_KERNEL_SENSORHUB

	if(res){
		printk("als_enable_nodata is failed!!\n");
		return -1;
	}
	return 0;

}

static int ps_set_delay(u64 ns)
{
	return 0;
}

static int ps_get_data(int* value, int* status)
{
    int err = 0;
#ifdef CUSTOM_KERNEL_SENSORHUB
    SCP_SENSOR_HUB_DATA req;
    int len;
#endif //#ifdef CUSTOM_KERNEL_SENSORHUB
#ifdef CUSTOM_KERNEL_SENSORHUB
    req.get_data_req.sensorType = ID_PROXIMITY;
    req.get_data_req.action = SENSOR_HUB_GET_DATA;
    len = sizeof(req.get_data_req);
    err = SCP_sensorHub_req_send(&req, &len, 1);
    if (err)
    {
        printk("SCP_sensorHub_req_send fail!\n");
    }
    else
    {
        *value = req.get_data_rsp.int16_Data[0];
        *status = SENSOR_STATUS_ACCURACY_MEDIUM;
    }

    if(atomic_read(&pa12201001_obj->trace) & CMC_TRC_PS_DATA)
	{
        printk("value = %d\n", *value);
        //show data
	}
#else //#ifdef CUSTOM_KERNEL_SENSORHUB
    if(!pa12201001_obj)
	{
		printk("pa12201001_obj is null!!\n");
		return -1;
	}

    if((err = pa12201001_read_ps(pa12201001_obj->client, &pa12201001_obj->ps)))
    {
        err = -1;;
    }
    else
    {
        *value = pa12201001_get_ps_value(pa12201001_obj, pa12201001_obj->ps);
        *status = SENSOR_STATUS_ACCURACY_MEDIUM;
    }
#endif //#ifdef CUSTOM_KERNEL_SENSORHUB

	return 0;
}
static int pa12201001_init_client(struct i2c_client *client)
{
	struct pa12201001_priv *obj = i2c_get_clientdata(client);

	u8 sendvalue=0;
	int res = 0;
	u8 test=0;
	int intmode;
  	APS_LOG("[mcz]enter %s\n",__func__);
	//Initialize Sensor
	sendvalue=(PA12_ALS_GAIN	<< 4);
	res=hwmsen_write_byte(client,REG_CFG0,sendvalue);

	sendvalue=((PA12_LED_CURR	<< 4)| (PA12_PS_PRST << 2)| (PA12_ALS_PRST));
	res=hwmsen_write_byte(client,REG_CFG1,sendvalue);

	sendvalue=((PA12_PS_MODE	<< 6)| (PA12_PS_SET << 2));

	APS_LOG("[mcz] REG_CFG2 sendvalue=0x%x\n",sendvalue);
	res=hwmsen_write_byte(client,REG_CFG2,sendvalue);

	sendvalue=((PA12_INT_TYPE	<< 6)| (PA12_PS_PERIOD << 3)| (PA12_ALS_PERIOD));
	res=hwmsen_write_byte(client,REG_CFG3,sendvalue);

	res=hwmsen_write_byte(client,REG_PS_SET,0x03); //PSET

	// Set ALS threshold
	sendvalue=(PA12_ALS_TH_HIGH >> 8);
	res=hwmsen_write_byte(client,REG_ALS_TH_MSB,sendvalue); //set TH threshold

	sendvalue=(PA12_ALS_TH_HIGH & 0xFF);
	res=hwmsen_write_byte(client,REG_ALS_TH_LSB,sendvalue); //set TH threshold

	sendvalue=(PA12_ALS_TH_LOW >> 8);
	res=hwmsen_write_byte(client,REG_ALS_TL_MSB,sendvalue); //set TL threshold

	sendvalue=(PA12_ALS_TH_LOW & 0xFF);
	res=hwmsen_write_byte(client,REG_ALS_TL_LSB,sendvalue); //set TL threshold

	// Set PS threshold
	sendvalue=PA12_PS_TH_HIGH;
	res=hwmsen_write_byte(client,REG_PS_TH,sendvalue); //set TH threshold

	res=hwmsen_read_byte(client,REG_PS_TH,&sendvalue);

	APS_LOG("[MCZ][PROBE]REG_PS_TH value = 0X%X\n",sendvalue);

	sendvalue=PA12_PS_TH_LOW;
	res=hwmsen_write_byte(client,REG_PS_TL,sendvalue); //set TL threshold


	// Polling Setting
	intmode = (((obj->hw->polling_mode_ps)<<1) | ((obj->hw->polling_mode_als)));
	APS_LOG("[mcz]intmode = 0x%x\n",intmode);
	res=hwmsen_read_byte(client,REG_CFG2,&sendvalue);
	APS_LOG("[mcz] read: REG_CFG2 sendvalue=0x%x\n",sendvalue);

	sendvalue=sendvalue & 0xF3;//new:0xF8;// //clear int set

	APS_LOG("[mcz] after clear int set: REG_CFG2 sendvalue=0x%x\n",sendvalue);
	/*
	switch(intmode)
	{

  	case 1:
  		//sendvalue=sendvalue | 0x06;//0x00;//new:
  		 APS_LOG("[mcz] case 1 sendvalue=0x%x\n",sendvalue);
		res=hwmsen_write_byte(client,REG_CFG2,sendvalue); //set int mode:PS int only,ALS polling
  		break;
  	case 2:
  		sendvalue=sendvalue & 0x04;//new: | 0x01;//
  		 APS_LOG("[mcz] case 2 sendvalue=0x%x\n",sendvalue);
		res=hwmsen_write_byte(client,REG_CFG2,sendvalue); //set int mode:PS polling , ALS int
  		break;
  	case 3:
  		 APS_LOG("[mcz] case 3 sendvalue=0x%x\n",sendvalue);
  		sendvalue=sendvalue | 0x0C;//new: 0x08;//
		res=hwmsen_write_byte(client,REG_CFG2,sendvalue); //set int mode:ALS PS polling
  		break;
  	default:
  		break;
	}
	*/
	sendvalue = 0xC6;
	res=hwmsen_write_byte(client,REG_CFG2,sendvalue); //set int mode:PS int only,ALS polling

	hwmsen_read_byte(client,REG_CFG2,&test);
	APS_LOG("[mcz] after write: REG_CFG2 value=0x%x\n",test);

	if(res < 0)
	{
		APS_ERR("i2c_send function err\n");
		goto EXIT_ERR;
	}

	// Regsit int
	res = pa12201001_setup_eint(client);
	if(res!=0)
	{
		APS_ERR("PA12201001 setup eint: %d\n", res);
		return res;
	}

	return 0;

	EXIT_ERR:
	APS_ERR("pa12201001 init dev fail!!!!: %d\n", res);
	return res;
}
/*--------------------------------------------------------------------------------*/

int pa12201001_ps_operate(void* self, uint32_t command, void* buff_in, int size_in,
		void* buff_out, int size_out, int* actualout)
{
	int err = 0;
	int value;
	struct hwm_sensor_data* sensor_data;
	struct pa12201001_priv *obj = (struct pa12201001_priv *)self;
	APS_FUN(f);
	switch (command)
	{
		case SENSOR_DELAY:
			APS_ERR("pa12201001 ps delay command!\n");
			if((buff_in == NULL) || (size_in < sizeof(int)))
			{
				APS_ERR("Set delay parameter error!\n");
				err = -EINVAL;
			}
			break;

		case SENSOR_ENABLE:
			APS_ERR("pa12201001 ps enable command!\n");
			if((buff_in == NULL) || (size_in < sizeof(int)))
			{
				APS_ERR("Enable sensor parameter error!\n");
				err = -EINVAL;
			}
			else
			{
				value = *(int *)buff_in;
				if(value)
				{
					if((err = pa12201001_enable_ps(obj->client, 1)))
					{
						APS_ERR("enable ps fail: %d\n", err);
						return -1;
					}
					set_bit(CMC_BIT_PS, &obj->enable);
				}
				else
				{
					if((err = pa12201001_enable_ps(obj->client, 0)))
					{
						APS_ERR("disable ps fail: %d\n", err);
						return -1;
					}
					clear_bit(CMC_BIT_PS, &obj->enable);
				}
			}
			break;

		case SENSOR_GET_DATA:
			APS_ERR("pa12201001 ps get data command!\n");
			if((buff_out == NULL) || (size_out< sizeof(struct hwm_sensor_data)))
			{
				APS_ERR("get sensor data parameter error!\n");
				err = -EINVAL;
			}
			else
			{
				sensor_data = (struct hwm_sensor_data *)buff_out;

				if((err = pa12201001_read_ps(obj->client, &obj->ps)))
				{
					err = -1;;
				}
				else
				{
					sensor_data->values[0] = pa12201001_get_ps_value(obj, obj->ps);
					sensor_data->value_divide = 1;
					sensor_data->status = SENSOR_STATUS_ACCURACY_MEDIUM;
				}
			}
			break;
		default:
			APS_ERR("proxmy sensor operate function no this parameter %d!\n", command);
			err = -1;
			break;
	}
	return err;
}

int pa12201001_als_operate(void* self, uint32_t command, void* buff_in, int size_in,
		void* buff_out, int size_out, int* actualout)
{
	int err = 0;
	int value;
	struct hwm_sensor_data* sensor_data;
	struct pa12201001_priv *obj = (struct pa12201001_priv *)self;
	APS_FUN(f);
	switch (command)
	{
		case SENSOR_DELAY:
			APS_ERR("pa12201001 als delay command!\n");
			if((buff_in == NULL) || (size_in < sizeof(int)))
			{
				APS_ERR("Set delay parameter error!\n");
				err = -EINVAL;
			}
			break;

		case SENSOR_ENABLE:
			APS_ERR("pa12201001 als enable command!\n");
			if((buff_in == NULL) || (size_in < sizeof(int)))
			{
				APS_ERR("Enable sensor parameter error!\n");
				err = -EINVAL;
			}
			else
			{
				value = *(int *)buff_in;
				if(value)
				{
					if((err = pa12201001_enable_als(obj->client, 1)))
					{
						APS_ERR("enable als fail: %d\n", err);
						return -1;
					}
					set_bit(CMC_BIT_ALS, &obj->enable);
				}
				else
				{
					if((err = pa12201001_enable_als(obj->client, 0)))
					{
						APS_ERR("disable als fail: %d\n", err);
						return -1;
					}
					clear_bit(CMC_BIT_ALS, &obj->enable);
				}

			}
			break;

		case SENSOR_GET_DATA:
			APS_ERR("pa12201001 als get data command!\n");
			if((buff_out == NULL) || (size_out< sizeof(struct hwm_sensor_data)))
			{
				APS_ERR("get sensor data parameter error!\n");
				err = -EINVAL;
			}
			else
			{
				sensor_data = (struct hwm_sensor_data *)buff_out;

				if((err = pa12201001_read_als(obj->client, &obj->als)))
				{
					err = -1;;
				}
				else
				{
					#if defined(MTK_AAL_SUPPORT)
					sensor_data->values[0] = obj->als;
					#else
					sensor_data->values[0] = pa12201001_get_als_value(obj, obj->als);
					#endif
					sensor_data->value_divide = 1;
					sensor_data->status = SENSOR_STATUS_ACCURACY_MEDIUM;
				}
			}
			break;
		default:
			APS_ERR("light sensor operate function no this parameter %d!\n", command);
			err = -1;
			break;
	}

	return err;

}
/*--------------------------------------------------------------------------------*/

static int pa12201001_get_ps_threshold_setting(int type, int value[2])
{
	int ps_result = -1;

	if(GET_TH_HIGH == type)
	{
		value[0] = atomic_read(&pa12201001_obj->ps_thd_val_high);
		printk("[ALS/PS][ljj]   pa12201001_obj->ps_thd_val_high = %d \n",value[0]);
	}
	else if ( GET_TH_LOW == type)
	{
		value[0] = atomic_read(&pa12201001_obj->ps_thd_val_low);
		printk("[ALS/PS][ljj]   pa12201001_obj->ps_thd_val_low = %d \n",value[0]);
	}
	else if ( SET_TH == type)
	{
	//TODO
	}
	else if ( GET_TH_RESULT == type)
	{
		if(pa12201001_read_ps(pa12201001_obj->client, &pa12201001_obj->ps))
		{
			printk("[ALS/PS][ljj] \n");
			return -1;
		}
		if(pa12201001_obj->ps > atomic_read(&pa12201001_obj->ps_thd_val_high))
		{
			ps_result = 1;
		}
		else
		{
			ps_result = 0;
		}
		value[0] = ps_result;
	}
	return 0;
}
/*-----------------------------------i2c operations----------------------------------*/
static int pa12201001_i2c_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
	struct pa12201001_priv *obj;

	int err = 0;
	u8 value = 0;
	int ret = 0;

	struct als_control_path als_ctl = { 0 };
	struct als_data_path als_data = { 0 };
	struct ps_control_path ps_ctl = { 0 };
	struct ps_data_path ps_data = { 0 };

	if(!(obj = kzalloc(sizeof(*obj), GFP_KERNEL)))
	{
		err = -ENOMEM;
		goto exit;
	}

	memset(obj, 0, sizeof(*obj));memset(obj, 0, sizeof(*obj));
	pa12201001_obj = obj;

	obj->hw = hw;

	INIT_WORK(&obj->eint_work, pa12201001_eint_work);

	#ifdef CUSTOM_KERNEL_SENSORHUB
    INIT_WORK(&obj->init_done_work, pa12201001_init_done_work);
	#endif

	obj->client = client;
	i2c_set_clientdata(client, obj);

	/*-----------------------------value need to be confirmed-----------------------------------------*/
	atomic_set(&obj->als_debounce, 200);
	atomic_set(&obj->als_deb_on, 0);
	atomic_set(&obj->als_deb_end, 0);
	atomic_set(&obj->ps_debounce, 50);//200
	atomic_set(&obj->ps_deb_on, 0);
	atomic_set(&obj->ps_deb_end, 0);
	atomic_set(&obj->ps_mask, 0);
	atomic_set(&obj->als_suspend, 0);
	atomic_set(&obj->als_cmd_val, 0xDF);
	atomic_set(&obj->ps_cmd_val,  0xC1);
	atomic_set(&obj->ps_thd_val_high,  obj->hw->ps_threshold_high);
	atomic_set(&obj->ps_thd_val_low,  obj->hw->ps_threshold_low);
	atomic_set(&obj->als_thd_val_high,  obj->hw->als_threshold_high);
	atomic_set(&obj->als_thd_val_low,  obj->hw->als_threshold_low);

	obj->enable = 0;
	obj->pending_intr = 0;
	obj->als_level_num = sizeof(obj->hw->als_level)/sizeof(obj->hw->als_level[0]);
	obj->als_value_num = sizeof(obj->hw->als_value)/sizeof(obj->hw->als_value[0]);

	obj->irq_node = of_find_compatible_node(NULL, NULL, "mediatek, ALS-eint");
	/*-----------------------------value need to be confirmed-----------------------------------------*/

	BUG_ON(sizeof(obj->als_level) != sizeof(obj->hw->als_level));
	memcpy(obj->als_level, obj->hw->als_level, sizeof(obj->als_level));
	BUG_ON(sizeof(obj->als_value) != sizeof(obj->hw->als_value));
	memcpy(obj->als_value, obj->hw->als_value, sizeof(obj->als_value));
	atomic_set(&obj->i2c_retry, 3);
	set_bit(CMC_BIT_ALS, &obj->enable);
	set_bit(CMC_BIT_PS, &obj->enable);

	pa12201001_i2c_client = client;


	ret=hwmsen_read_byte(client,REG_CFG2,&value);
	APS_LOG("[mcz] ret = 0x%x, value = 0x%x\n",ret, value);

	err = pa12201001_init_client(client);
	if(err)
	{
		goto exit_init_failed;
	}
	APS_LOG("pa12201001_init_client() OK!\n");

	err = misc_register(&pa12201001_device);
	if(err)
	{
		APS_ERR("pa12201001_device register failed\n");
		goto exit_misc_device_register_failed;
	}
	APS_LOG("pa12201001_device misc_register OK!\n");

	/*------------------------pa12201001 attribute file for debug--------------------------------------*/

	err = pa12201001_create_attr(&(pa12201001_init_info.platform_diver_addr->driver));
	if(err)
	{
		APS_ERR("create attribute err = %d\n", err);
		goto exit_create_attr_failed;
	}
	/*------------------------pa12201001 attribute file for debug--------------------------------------*/


	als_ctl.open_report_data= als_open_report_data;
	als_ctl.enable_nodata = als_enable_nodata;
	als_ctl.set_delay  = als_set_delay;
	als_ctl.is_report_input_direct = false;
#ifdef CUSTOM_KERNEL_SENSORHUB
	als_ctl.is_support_batch = obj->hw->is_batch_supported_als;
#else
    als_ctl.is_support_batch = false;
#endif

	err = als_register_control_path(&als_ctl);
	if(err)
	{
		printk("register fail = %d\n", err);
		goto exit;
	}

	als_data.get_data = als_get_data;
	als_data.als_get_raw_data = pa12201001_get_als_raw_data;
	als_data.vender_div = 100;
	err = als_register_data_path(&als_data);
	if(err)
	{
		printk("tregister fail = %d\n", err);
		goto exit;
	}

	ps_ctl.open_report_data= ps_open_report_data;
	ps_ctl.enable_nodata = ps_enable_nodata;
	ps_ctl.set_delay  = ps_set_delay;
	ps_ctl.is_report_input_direct = true;
#ifdef CUSTOM_KERNEL_SENSORHUB
	ps_ctl.is_support_batch = obj->hw->is_batch_supported_ps;
#else
    ps_ctl.is_support_batch = false;
#endif

	ps_ctl.ps_threshold_setting = pa12201001_get_ps_threshold_setting;

#if defined(AGOLD_PROX_CALI_ENABLE)
	ps_ctl.agold_alsps_set_ps_cali = agold_pa12201001_set_ps_cali;
	ps_ctl.agold_alsps_get_ps_deep_cali_data = agold_pa12201001_get_ps_deep_cali_data;
	ps_ctl.agold_alsps_get_ps_raw_data_for_cali = agold_pa12201001_get_ps_raw_data_for_cali;
#endif

	err = ps_register_control_path(&ps_ctl);
	if(err)
	{
		printk("register fail = %d\n", err);
		goto exit;
	}

	ps_data.get_data = ps_get_data;
	ps_data.ps_get_raw_data = pa12201001_get_ps_raw_data;
	ps_data.vender_div = 100;
	err = ps_register_data_path(&ps_data);
	if(err)
	{
		printk("tregister fail = %d\n", err);
		goto exit;
	}

	err = batch_register_support_info(ID_LIGHT,als_ctl.is_support_batch, 100, 0);
	if(err)
	{
		printk("register light batch support err = %d\n", err);
		goto exit;
	}

	err = batch_register_support_info(ID_PROXIMITY,ps_ctl.is_support_batch, 100, 0);
	if(err)
	{
		printk("register proximity batch support err = %d\n", err);
		goto exit;
	}

	APS_LOG("%s: OK\n", __func__);

	pa12201001_init_flag = 0;
	return 0;

	exit_create_attr_failed:
	exit_misc_device_register_failed:
		misc_deregister(&pa12201001_device);
	exit_init_failed:
		kfree(obj);
	exit:
	pa12201001_i2c_client = NULL;
	APS_ERR("%s: err = %d\n", __func__, err);
	pa12201001_init_flag = -1;
	return err;
}

static int pa12201001_i2c_remove(struct i2c_client *client)
{
	int err;

	err = pa12201001_delete_attr(&pa12201001_i2c_driver.driver);
	if(err)
	{
		APS_ERR("pa12201001_delete_attr fail: %d\n", err);
	}

	err = misc_deregister(&pa12201001_device);
	if(err)
	{
		APS_ERR("misc_deregister fail: %d\n", err);
	}

	pa12201001_i2c_client = NULL;
	i2c_unregister_device(client);
	kfree(i2c_get_clientdata(client));
	return 0;

}

static int pa12201001_i2c_detect(struct i2c_client *client, struct i2c_board_info *info)
{
	strcpy(info->type, PA12201001_DEV_NAME);
	return 0;

}

static int pa12201001_i2c_suspend(struct i2c_client *client, pm_message_t msg)
{
	APS_FUN();
	return 0;
}

static int pa12201001_i2c_resume(struct i2c_client *client)
{
	APS_FUN();
	return 0;
}

/*----------------------------------------------------------------------------*/
static int pa12201001_local_init(void)
{
	if(i2c_add_driver(&pa12201001_i2c_driver))
	{
		APS_ERR("add driver error\n");
		return -1;
	}
	if(-1 == pa12201001_init_flag)
	{
		APS_ERR("[mcz] i2c del driver.\n");
		i2c_del_driver(&pa12201001_i2c_driver);
		return -1;
	}
	return 0;
}

/*----------------------------------------------------------------------------*/
static int pa12201001_remove(void)
{
	i2c_del_driver(&pa12201001_i2c_driver);
	return 0;
}

/*----------------------------------------------------------------------------*/
static int __init pa12201001_init(void)
{
	const char *name = "mediatek,pa12201001";

	hw = get_alsps_dts_func(name, hw);
	if (!hw)
	{
		APS_ERR("get_alsps_dts_func fail\n");
		return 0;
	}
	alsps_driver_add(&pa12201001_init_info);
	return 0;
}

/*----------------------------------------------------------------------------*/
static void __exit pa12201001_exit(void)
{
	APS_FUN();
}

/*----------------------------------------------------------------------------*/
module_init(pa12201001_init);
module_exit(pa12201001_exit);

/*----------------------------------------------------------------------------*/
MODULE_AUTHOR("TXC Corp");
MODULE_DESCRIPTION("pa12201001 driver");
MODULE_LICENSE("GPL");

