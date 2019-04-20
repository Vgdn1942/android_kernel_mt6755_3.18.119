#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/spinlock.h>
#include <linux/suspend.h>
#include <linux/console.h>
#include <linux/proc_fs.h>
#include <linux/fs.h>
#include <linux/vmalloc.h>
#include <linux/uaccess.h>
#include <linux/wakelock.h>
#include <linux/time.h>
#include <linux/kthread.h>
#include <linux/gpio.h>
#include <linux/delay.h>
#include "mt_auxadc.h"

#ifdef CONFIG_OF
#include <linux/of_fdt.h>
#endif
#include <linux/slab.h>

#include "board_version.h"

#ifndef USER_BUILD_KERNEL
	#define DEBUG(fmt, arg...)    printk(KERN_EMERG "[qnmd] %s: " fmt, __FUNCTION__ ,##arg)
#else
	#define DEBUG(fmt, arg...)
#endif

#define ERRLOG(fmt, arg...)    printk(KERN_EMERG "[qnmd] %s: " fmt, __FUNCTION__ ,##arg)

#define 	AVERAGE 		2

/* hardware version register */
#define VER_BASE            (DEVINFO_BASE)
#define APHW_CODE           (VER_BASE)
#define APHW_SUBCODE        (VER_BASE + 0x04)
#define APHW_VER            (VER_BASE + 0x08)
#define APSW_VER            (VER_BASE + 0x0C)

#define	GPIO_RF_DETECT_PIN1  82
#define	GPIO_RF_DETECT_PIN2  81
#define	GPIO_RF_DETECT_PIN3  80

struct kobject * board_v_kobj;

extern int IMM_GetOneChannelValue(int dwChannel, int data[4], int* rawdata);
extern int IMM_GetOneChannelValue_Cali(int Channel, int*voltage);
extern void mt_auxadc_hal_init(void);

static int g_voltage_adc0;
static int g_voltage_adc1;
static int g_voltage_adc2;
static int g_gpio_state = 0;

static ssize_t lcm_id_show(struct kobject * kobj,struct kobj_attribute *attr,char *buf);

agold_version g_board[BOARD_VERSION_TOTAL] =
{
	{
		.range = {BOARD_VERSION_V1},
		.name = Board_V1,
	},
	{
		.range = {BOARD_VERSION_V2},
		.name = Board_V2,
	},
	{
		.range = {BOARD_VERSION_V3},
		.name = Board_V3,
	},
	{
		.range = {BOARD_VERSION_V4},
		.name = Board_V4,
	},
	{
		.range = {BOARD_VERSION_V5},
		.name = Board_V5,
	},
	{
		.range = {BOARD_VERSION_V6},
		.name = Board_V6,
	},
	{
		.range = {BOARD_VERSION_V7},
		.name = Board_V7,
	},
	{
		.range = {BOARD_VERSION_V8},
		.name = Board_V8,
	},
};


agold_version g_lcm_id[LCM_ID_TOTAL] =
{
	{
		.range = {LCM_ID_V1},
		.name = LCM_V1,
	},
	{
		.range = {LCM_ID_V2},
		.name = LCM_V2,
	},
	{
		.range = {LCM_ID_V3},
		.name = LCM_V3,
	},
	{
		.range = {LCM_ID_V4},
		.name = LCM_V4,
	},
	{
		.range = {LCM_ID_V5},
		.name = LCM_V5,
	},
	{
		.range = {LCM_ID_V6},
		.name = LCM_V6,
	},
	{
		.range = {LCM_ID_V7},
		.name = LCM_V7,
	},
	{
		.range = {LCM_ID_V8},
		.name = LCM_V8,
	},
};

agold_version g_modem[8][UL1CUSTOM_ADC_LEVEL_TOTAL] =
{
	//3M_A_FDD & 4M 0~8
	{
		{
			.range = {ADC_LVL0_RANGE},
			.name = BAND_A_3M_FDD_V1,
		},
		{
			.range = {ADC_LVL1_RANGE},
			.name = BAND_A_3M_FDD_V2,
		},
		{
			.range = {ADC_LVL2_RANGE},
			.name = BAND_A_3M_FDD_V3,
		},
		{
			.range = {ADC_LVL3_RANGE},
			.name = BAND_A_3M_FDD_V4,
		},
		{
			.range = {ADC_LVL4_RANGE},
			.name = BAND_A_3M_FDD_V5,
		},
		{
			.range = {ADC_LVL5_RANGE},
			.name = BAND_A_3M_FDD_V6,
		},
		{
			.range = {ADC_LVL6_RANGE},
			.name = BAND_A_3M_FDD_V7,
		},
		{
			.range = {ADC_LVL7_RANGE},
			.name = BAND_A_3M_FDD_V8,
		},
	},
	//3M_A_FDD & 4M 8~16
	{
		{
			.range = {ADC_LVL0_RANGE},
			.name = BAND_A_3M_FDD_V9,
		},
		{
			.range = {ADC_LVL1_RANGE},
			.name = BAND_A_3M_FDD_V10,
		},
		{
			.range = {ADC_LVL2_RANGE},
			.name = BAND_A_3M_FDD_V11,
		},
		{
			.range = {ADC_LVL3_RANGE},
			.name = BAND_A_3M_FDD_V12,
		},
		{
			.range = {ADC_LVL4_RANGE},
			.name = BAND_A_3M_FDD_V13,
		},
		{
			.range = {ADC_LVL5_RANGE},
			.name = BAND_A_3M_FDD_V14,
		},
		{
			.range = {ADC_LVL6_RANGE},
			.name = BAND_A_3M_FDD_V15,
		},
		{
			.range = {ADC_LVL7_RANGE},
			.name = BAND_A_3M_FDD_V16,
		},
	},

	//3M_B_FDD & 4M 0~8
	{
		{
			.range = {ADC_LVL0_RANGE},
			.name = BAND_B_3M_FDD_V1,
		},
		{
			.range = {ADC_LVL1_RANGE},
			.name = BAND_B_3M_FDD_V2,
		},
		{
			.range = {ADC_LVL2_RANGE},
			.name = BAND_B_3M_FDD_V3,
		},
		{
			.range = {ADC_LVL3_RANGE},
			.name = BAND_B_3M_FDD_V4,
		},
		{
			.range = {ADC_LVL4_RANGE},
			.name = BAND_B_3M_FDD_V5,
		},
		{
			.range = {ADC_LVL5_RANGE},
			.name = BAND_B_3M_FDD_V6,
		},
		{
			.range = {ADC_LVL6_RANGE},
			.name = BAND_B_3M_FDD_V7,
		},
		{
			.range = {ADC_LVL7_RANGE},
			.name = BAND_B_3M_FDD_V8,
		},
	},
	//3M_B_FDD & 4M 8~16
	{
		{
			.range = {ADC_LVL0_RANGE},
			.name = BAND_B_3M_FDD_V9,
		},
		{
			.range = {ADC_LVL1_RANGE},
			.name = BAND_B_3M_FDD_V10,
		},
		{
			.range = {ADC_LVL2_RANGE},
			.name = BAND_B_3M_FDD_V11,
		},
		{
			.range = {ADC_LVL3_RANGE},
			.name = BAND_B_3M_FDD_V12,
		},
		{
			.range = {ADC_LVL4_RANGE},
			.name = BAND_B_3M_FDD_V13,
		},
		{
			.range = {ADC_LVL5_RANGE},
			.name = BAND_B_3M_FDD_V14,
		},
		{
			.range = {ADC_LVL6_RANGE},
			.name = BAND_B_3M_FDD_V15,
		},
		{
			.range = {ADC_LVL7_RANGE},
			.name = BAND_B_3M_FDD_V16,
		},
	},
	//5M
	{
		{
			.range = {ADC_LVL0_RANGE},
			.name = BAND_5M_V1,
		},
		{
			.range = {ADC_LVL1_RANGE},
			.name = BAND_5M_V2,
		},
		{
			.range = {ADC_LVL2_RANGE},
			.name = BAND_5M_V3,
		},
		{
			.range = {ADC_LVL3_RANGE},
			.name = BAND_5M_V4,
		},
		{
			.range = {ADC_LVL4_RANGE},
			.name = BAND_5M_V5,
		},
		{
			.range = {ADC_LVL5_RANGE},
			.name = BAND_5M_V6,
		},
		{
			.range = {ADC_LVL6_RANGE},
			.name = BAND_5M_V7,
		},
		{
			.range = {ADC_LVL7_RANGE},
			.name = BAND_5M_V8,
		},
	},
	//NULL
	{
		{
			.range = {ADC_LVL0_RANGE},
			.name = BAND_NONE,
		},
		{
			.range = {ADC_LVL1_RANGE},
			.name = BAND_NONE,
		},
		{
			.range = {ADC_LVL2_RANGE},
			.name = BAND_NONE,
		},
		{
			.range = {ADC_LVL3_RANGE},
			.name = BAND_NONE,
		},
		{
			.range = {ADC_LVL4_RANGE},
			.name = BAND_NONE,
		},
		{
			.range = {ADC_LVL5_RANGE},
			.name = BAND_NONE,
		},
		{
			.range = {ADC_LVL6_RANGE},
			.name = BAND_NONE,
		},
		{
			.range = {ADC_LVL7_RANGE},
			.name = BAND_NONE,
		},
	},
	//3M_TDD
	{
		{
			.range = {ADC_LVL0_RANGE},
			.name = BAND_3M_TDD_V1,
		},
		{
			.range = {ADC_LVL1_RANGE},
			.name = BAND_3M_TDD_V2,
		},
		{
			.range = {ADC_LVL2_RANGE},
			.name = BAND_3M_TDD_V3,
		},
		{
			.range = {ADC_LVL3_RANGE},
			.name = BAND_3M_TDD_V4,
		},
		{
			.range = {ADC_LVL4_RANGE},
			.name = BAND_3M_TDD_V5,
		},
		{
			.range = {ADC_LVL5_RANGE},
			.name = BAND_3M_TDD_V6,
		},
		{
			.range = {ADC_LVL6_RANGE},
			.name = BAND_3M_TDD_V7,
		},
		{
			.range = {ADC_LVL7_RANGE},
			.name = BAND_3M_TDD_V8,
		},
	},

	//6M
	{
		{
			.range = {ADC_LVL0_RANGE},
			.name = BAND_6M_V1,
		},
		{
			.range = {ADC_LVL1_RANGE},
			.name = BAND_6M_V2,
		},
		{
			.range = {ADC_LVL2_RANGE},
			.name = BAND_6M_V3,
		},
		{
			.range = {ADC_LVL3_RANGE},
			.name = BAND_6M_V4,
		},
		{
			.range = {ADC_LVL4_RANGE},
			.name = BAND_6M_V5,
		},
		{
			.range = {ADC_LVL5_RANGE},
			.name = BAND_6M_V6,
		},
		{
			.range = {ADC_LVL6_RANGE},
			.name = BAND_6M_V7,
		},
		{
			.range = {ADC_LVL7_RANGE},
			.name = BAND_6M_V8,
		},
	}
};

/* return hardware version */
unsigned int agold_get_chip_code(void)
{     
    return 0;//DRV_Reg32(APHW_CODE);
}

unsigned int agold_get_chip_hw_ver_code(void)
{   
    return 0;//DRV_Reg32(APHW_VER);
}

unsigned int agold_get_chip_sw_ver_code(void)
{  
    return 0;//DRV_Reg32(APSW_VER);
}

unsigned int agold_get_chip_hw_subcode(void)
{
    return 0;//DRV_Reg32(APHW_SUBCODE);
}

int init_version(void)
{
	int tmp0 = 0, tmp1 = 0, tmp2 = 0;
	int i = 0;
	int ret = 0;
	int voltage_adc0 = 0;
	int voltage_adc1 = 0;
	int voltage_adc2 = 0;
	
	for(;i < AVERAGE;i++)
	{
		
		ret |= IMM_GetOneChannelValue_Cali(14,&tmp0);
		msleep(1);
		ret |= IMM_GetOneChannelValue_Cali(14,&tmp0);

		ret |= IMM_GetOneChannelValue_Cali(12,&tmp1);
		msleep(1);
		ret |= IMM_GetOneChannelValue_Cali(12,&tmp1);

		ret |= IMM_GetOneChannelValue_Cali(13,&tmp2);
		msleep(1);
		ret |= IMM_GetOneChannelValue_Cali(13,&tmp2);
		
		voltage_adc0 += tmp0;
		voltage_adc1 += tmp1;
		voltage_adc2 += tmp2;
		
		if(ret < 0)
		{
			ERRLOG("get voltage error ret = %d\n",ret);
			return -1;
		} 
	}
	g_voltage_adc0 = voltage_adc0/(AVERAGE);
	g_voltage_adc1 = voltage_adc1/(AVERAGE);
	g_voltage_adc2 = voltage_adc2/(AVERAGE);
	ERRLOG("voltage_adc0 = %u,voltage_adc1 = %d,\ng_voltage_adc0 = %u,g_voltage_adc1 = %d,g_voltage_adc2 = %d\n",voltage_adc0,voltage_adc1,g_voltage_adc0,g_voltage_adc1,g_voltage_adc2);
#if 0	
	for(i = 0;i < BOARD_VERSION_TOTAL;i++)
	{
		DEBUG(" %s ,max = %d,min = %d\n",g_board[i].name,g_board[i].range.max,g_board[i].range.min);
	}
	for(i = 0;i < UL1CUSTOM_ADC_LEVEL_TOTAL;i++)
	{
		DEBUG(" %s ,max = %d,min = %d\n",g_modem[i].name,g_modem[i].range.max,g_modem[i].range.min);
	}
#endif
	return 0;
}

int get_version_index(agold_version * ver,int max_num,int voltage)
{
	int index = -1;
	int i;
	
	for(i = 0; i < max_num; i++)
	{
		if(ver[i].range.min <= voltage && voltage <= ver[i].range.max)
		{
			index = i;
			break;
		}
	}
	
	return index;
}
int get_version_modem_index(agold_version ver[8][UL1CUSTOM_ADC_LEVEL_TOTAL],int max_num,int voltage,int state)
{
	int index = -1;
	int i;
	init_version();
	for(i = 0; i < max_num; i++)
	{
		if(ver[state][i].range.min <= voltage && voltage <= ver[state][i].range.max)
		{
			index = i;
			break;
		}
	}
	
	return index;
}

//[agold][xfl][20160609][start]
int get_board_version_index(void)
{
	return get_version_index(g_board,BOARD_VERSION_TOTAL,g_voltage_adc1);
}
//[agold][xfl][20160609][end]

static ssize_t board_version_show(struct kobject * kobj,struct kobj_attribute *attr,char *buf)
{
	ssize_t len = 0;
	int index;
	
	index = get_version_index(g_board,BOARD_VERSION_TOTAL,g_voltage_adc1);
	
	if(index < 0)
		len = sprintf(buf,"board version : unknow \n");
	else
		len = sprintf(buf,"board version : %s \n",g_board[index].name);
		
	return len;
}

static struct kobj_attribute agold_board_version_attr = {
    .attr = {
        .name = "board_version",
        .mode = S_IWUGO|S_IRUGO,
    },
    .show = &board_version_show,
};

static ssize_t modem_version_show(struct kobject * kobj,struct kobj_attribute *attr,char *buf)
{
	ssize_t len = 0;
	int index;
	
	index = get_version_modem_index(g_modem,UL1CUSTOM_ADC_LEVEL_TOTAL,g_voltage_adc0,g_gpio_state);//get_version_index(g_modem,UL1CUSTOM_ADC_LEVEL_TOTAL,g_voltage_adc0);
	printk("[agoldboard][2] %d, %d, %d\n",gpio_get_value(GPIO_RF_DETECT_PIN1),gpio_get_value(GPIO_RF_DETECT_PIN2),gpio_get_value(GPIO_RF_DETECT_PIN3));
	printk("[agoldboard] index=%d, g_gpio_state=%d, g_voltage_adc0=%d, g_voltage_adc1=%d modem:%s\n",index,g_gpio_state,g_voltage_adc0,g_voltage_adc1,g_modem[g_gpio_state][index].name);
	if(index < 0)
		len = sprintf(buf,"modem : unknow \n");
	else
		len = sprintf(buf,"modem : %s \n",g_modem[g_gpio_state][index].name);
		
	return len;
}

static struct kobj_attribute agold_modem_version_attr = {
    .attr = {
        .name = "modem_version",
        .mode = S_IWUGO|S_IRUGO,
    },
    .show = &modem_version_show,
};

static ssize_t board_information_show(struct kobject * kobj,struct kobj_attribute *attr,char *buf)
{
	ssize_t len = 0;
	
	len = sprintf(buf,"chip code : 0x%04X , chip subcode : 0x%04X , chip hw ver code : 0x%04X , chip sw ver code : 0x%04X \n",
	             agold_get_chip_code(),agold_get_chip_hw_subcode(),agold_get_chip_hw_ver_code(),agold_get_chip_sw_ver_code());
	return len;
}

static struct kobj_attribute agold_board_information_attr = {
    .attr = {
        .name = "board_information",
        .mode = S_IWUGO|S_IRUGO,
    },
    .show = &board_information_show,
};

static struct kobj_attribute agold_lcm_id_attr = {
    .attr = {
        .name = "lcm_id",
        .mode = S_IWUGO|S_IRUGO,
    },
    .show = &lcm_id_show,
};

int lcm_id_index(int b)
{
	int a=0;
	
	a=get_version_index(g_lcm_id,LCM_ID_TOTAL,g_voltage_adc2);
	return a;

}
EXPORT_SYMBOL(lcm_id_index);

static ssize_t lcm_id_show(struct kobject * kobj,struct kobj_attribute *attr,char *buf)
{
	
	ssize_t len = 0;
	int index;
	int b=0;
	index = lcm_id_index(b);
	
	if(index < 0)
		len = sprintf(buf,"LCM ID : unknow \n");
	else
		len = sprintf(buf,"LCM ID : %s \n",g_lcm_id[index].name);
		
	return len;
}

static struct attribute *agold_board_v_attrs[] = {
    &agold_board_version_attr.attr,
    &agold_modem_version_attr.attr,
    &agold_board_information_attr.attr,
	&agold_lcm_id_attr.attr,
    NULL
};

static struct attribute_group agold_board_v_attr_group = {
    .attrs = agold_board_v_attrs,
};


static int board_version_create_dev(void)
{
	int ret;
    	
    board_v_kobj = kobject_create_and_add("board_version", NULL);
    
    if(!board_v_kobj)
    {
    	ERRLOG(" %s:register  kobject_create_and_add failed\n", __FILE__);
    	return -1;
    }
    else
    	ret = sysfs_create_group(board_v_kobj,&agold_board_v_attr_group);
    
    if(ret)
    {
    	ERRLOG(" %s:sysfs_create_group failed,ret = %d\n", __FILE__,ret);
    	return ret;
    }
    return 0;
}


static int __init board_v_init(void)
{
	DEBUG(" board version init.\n");
	mt_auxadc_hal_init();
	init_version();
	board_version_create_dev();

	gpio_direction_input(GPIO_RF_DETECT_PIN1);
	gpio_direction_input(GPIO_RF_DETECT_PIN2);
	gpio_direction_input(GPIO_RF_DETECT_PIN3);

	g_gpio_state = gpio_get_value(GPIO_RF_DETECT_PIN1)+gpio_get_value(GPIO_RF_DETECT_PIN2)*2+gpio_get_value(GPIO_RF_DETECT_PIN3)*4;

	printk("[agoldboard][1] %d, %d, %d\n",gpio_get_value(GPIO_RF_DETECT_PIN1),gpio_get_value(GPIO_RF_DETECT_PIN2),gpio_get_value(GPIO_RF_DETECT_PIN3));
	return 0;
}
/*----------------------------------------------------------------------------*/
static void __exit board_v_exit(void)
{
	DEBUG(" good bye.\n");
}

/*----------------------------------------------------------------------------*/
module_init(board_v_init);
module_exit(board_v_exit);
/*----------------------------------------------------------------------------*/
MODULE_AUTHOR("wang xing");
MODULE_DESCRIPTION("board_version driver");
MODULE_LICENSE("GPL");
