#ifdef AGOLD_LED_AW2013

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
#include <asm/atomic.h>

#define AW2013_DEV_NAME        "AW2013"
#define AW2013_MAX_PWM_LEVEL      8
#define AW2013_TAG "[aw2013] "

/*----------------------------log-------------------------------------------*/
//#define AW2013_LOG_ON
#ifdef AW2013_LOG_ON

#define AW2013_FUNC() 				printk("aw2013::func is %s\n",__func__)
#define AW2013_LOG(fmt, args...)    printk(AW2013_TAG"[line:%d] : "fmt ,__LINE__, ##args)

#else

#define AW2013_FUNC()
#define AW2013_LOG(fmt, args...)

#endif

#define AW2013_ERR(fmt, args...)    printk(KERN_ERR AW2013_TAG"[line:%d] is some error: "fmt ,__LINE__, ##args)

/*------------------------------------------------------------------------*/

#define AW2013_RST_REG      0x00  //复位寄存器，写入0x54 对LED控制器模块复位，写入0x55，对所有寄存器复位，读操作始终返回0x33,可以作为ID
#define AW2013_GC_REG       0x01  //全局控制寄存器，bit0 led子模块使能，bit5:7 分别为led0-led2的编程中断使能
#define AW2013_STATUS       0x02  //LED状态寄存器  bit5:7 分别为led0-led2的呼吸中断状态，0为无，1为一次编程结束 
#define AW2013_LED_EN_REG   0x30  //LED通道使能寄存器，bit5 IC时钟选择，0=250HZ，1=125HZ，bit0:2分别为led0-led2的使能位，0=控制模块停止工作，输出关闭 1=正常工作 
#define AW2013_LED0_CFG_REG 0x31  //LED控制寄存器 bit 0:1 led 最大电流 bit4 一次编程模式使能 bit5 淡入使能 bit6 淡出使能
#define AW2013_LED1_CFG_REG 0x32
#define AW2013_LED2_CFG_REG 0x33
#define AW2013_LED0_PWM_REG 0x34  //LED亮度控制，值越高，亮度越亮
#define AW2013_LED1_PWM_REG 0x35
#define AW2013_LED2_PWM_REG 0x36

#define AW2013_LED0_ON_REG  0x37  //led0控制寄存器 bit0:2 亮保持时间，bit4:6 淡入（逐渐变亮）时间
#define AW2013_LED0_OFF_REG 0x38  //led0控制寄存器 bit0:2 灭保持时间，bit4:6 淡出（逐渐变暗）时间
#define AW2013_LED0_CTL_REG 0x39  //led0控制寄存器 bit0:3 重复次数（0为不停止），bit4:7 闪烁启动延迟时间

#define AW2013_LED1_ON_REG  0x3A  //led1控制寄存器 bit0:2 亮保持时间，bit4:6 淡入（逐渐变亮）时间
#define AW2013_LED1_OFF_REG 0x3B  //led1控制寄存器 bit0:2 灭保持时间，bit4:6 淡出（逐渐变暗）时间
#define AW2013_LED1_CTL_REG 0x3C  //led1控制寄存器 bit0:3 重复次数（0为不停止），bit4:7 闪烁启动延迟时间

#define AW2013_LED2_ON_REG  0x3D  //led2控制寄存器 bit0:2 亮保持时间，bit4:6 淡入（逐渐变亮）时间
#define AW2013_LED2_OFF_REG 0x3E  //led2控制寄存器 bit0:2 灭保持时间，bit4:6 淡出（逐渐变暗）时间
#define AW2013_LED2_CTL_REG 0x3F  //led2控制寄存器 bit0:3 重复次数（0为不停止），bit4:7 闪烁启动延迟时间


//extern  AGOLD_LED_DATA agold_led_data;

typedef enum
{
	AW2013_LED_RED,
	AW2013_LED_GREEN,
	AW2013_LED_BLUE,
	AW2013_LED_NUM=AW2013_LED_BLUE
} AW2013_LED_TYPE;

typedef enum
{
	AW2013_LED_CURRENT_0MA,
	AW2013_LED_CURRENT_5MA,
	AW2013_LED_CURRENT_10MA,
	AW2013_LED_CURRENT_15MA
} AW2013_LED_CURRENT;

//[agold][xfl][20160519][start]
#ifdef AGOLD_AW2013_GREEN_CURRENT__INT
#define AW2013_DEFAULT_GREEN_CURRENT AGOLD_AW2013_GREEN_CURRENT__INT
#else
#define AW2013_DEFAULT_GREEN_CURRENT AW2013_LED_CURRENT_5MA
#endif

#ifdef AGOLD_AW2013_RED_CURRENT__INT
#define AW2013_DEFAULT_RED_CURRENT AGOLD_AW2013_RED_CURRENT__INT
#else
#define AW2013_DEFAULT_RED_CURRENT AW2013_LED_CURRENT_10MA
#endif

#ifdef AGOLD_AW2013_BLUE_CURRENT__INT
#define AW2013_DEFAULT_BLUE_CURRENT AGOLD_AW2013_BLUE_CURRENT__INT
#else
#define AW2013_DEFAULT_BLUE_CURRENT AW2013_LED_CURRENT_10MA
#endif
//[agold][xfl][20160519][start]

typedef enum
{
	AW2013_LED_MODE_NORMAL,
	AW2013_LED_MODE_AUTO
} AW2013_LED_MODE;

typedef enum
{
	AW2013_LED_ENABLE,
	AW2013_LED_CURR,
	AW2013_LED_MOD,
	AW2013_LED_FADE_IN,
	AW2013_LED_FADE_OUT,
	AW2013_LED_PWM,
	AW2013_LED_HOLD_TIME,
	AW2013_LED_RISE_TIME,
	AW2013_LED_OFF_TIME,
	AW2013_LED_FALL_TIME,
	AW2013_LED_REPEAT_NUM,
	AW2013_LED_DELAY_TIME
} AW2013_LED_PROPERTY;

typedef struct{
	u8 led_cfg;  //bit 0:1 led 最大电流 bit 4 工作模式 bit 5 淡入使能 bit 6 淡出使能
	u8 pwm;
	u8 on_cfg;
	u8 off_cfg;
	u8 ctl_cfg;
} AW2013_LED_STRUCT;

typedef struct
{
	u8 aw2013_rst;
	u8 aw2013_gc;
	u8 aw2013_status;
	u8 AW2013_led_en;
	AW2013_LED_STRUCT aw2013_led[AW2013_LED_NUM];
} AW2013_CTL_STRUCT;

#define AW2013_CHECK_LED(led)    if(led > AW2013_LED_NUM){ return -1; }
#define AW2013_CHECK_CURRENT(curr)    if(curr>AW2013_LED_CURRENT_15MA){ return -1; }
#define AW2013_SET_BIT(data,bit,value) if(value){data |=(1<<bit);}else{ data &=~(1<<bit); }

static AW2013_LED_STRUCT led_default=
{
#if defined(AGOLD_LED_CUR)
	.led_cfg=AGOLD_LED_CUR,
#else
	.led_cfg=0x71,  //agold zjn 20131128 modify// 0x73     //0b01110010==>0x72;
#endif
#if defined(AGOLD_LED_BRT)
	.pwm=AGOLD_LED_BRT,//agold lcx 20140324
#else
	.pwm=0xff,
#endif
	.on_cfg=0x13,
#if defined(AGOLD_LED_OFF_TIME)
	.off_cfg=AGOLD_LED_OFF_TIME,
#else
	.off_cfg=0x15, //agold zjn 20131128 modify// 0x13
#endif
	.ctl_cfg=0x00
};

#define order_mode_time 3
#define AW2013_DEFAULT_CURRENT AW2013_LED_CURRENT_5MA

static AW2013_CTL_STRUCT aw2013_ctl;
static struct i2c_client *aw2013_i2c_client = NULL;

//static struct platform_driver aw2013_leds_driver;
static struct i2c_driver aw2013_i2c_driver;
/*----------------------------------------------------------------------------*/
static const struct i2c_device_id aw2013_i2c_id[] = {{AW2013_DEV_NAME,0},{}};

//static struct i2c_board_info __initdata i2c_AW2013={ I2C_BOARD_INFO("AW2013", 0X45)};
/*
static int aw2013_reset_led(void)
{
	u8 data=0x54;
	AW2013_FUNC();
	if (aw2013_i2c_client == NULL)
	{
		AW2013_LOG("i2c_data obj is null!!\n");
		return 0;
	}
	return i2c_smbus_write_i2c_block_data(aw2013_i2c_client, AW2013_RST_REG, 1, &data);
}
*/
static int aw2013_reset_all(void)
{
	u8 data=0x55;
	AW2013_FUNC();
	if (aw2013_i2c_client == NULL)
	{
		AW2013_ERR("i2c_data obj is null!!\n");
		return -1;
	}
	return i2c_smbus_write_i2c_block_data(aw2013_i2c_client, AW2013_RST_REG, 1, &data);
}

static int aw2013_enable_led(AW2013_LED_TYPE led,bool enable)
{
	u8 data=0;
	AW2013_FUNC();
	
	AW2013_CHECK_LED(led);

	if (aw2013_i2c_client == NULL)
	{
		AW2013_ERR("i2c_data obj is null!!\n");
		return -1;
	}

	if (i2c_smbus_read_i2c_block_data(aw2013_i2c_client, AW2013_LED_EN_REG, 1, &data) < 0)
	{
		AW2013_ERR();
		return -1;
	}
	AW2013_LOG("%s: led=%d,enable=%d,data=%#x\n",__func__,led,enable,data);

	AW2013_SET_BIT(data,led,enable);
	AW2013_LOG("%s: led=%d,enable=%d,data=%#x\n",__func__,led,enable,data);

	return i2c_smbus_write_i2c_block_data(aw2013_i2c_client, AW2013_LED_EN_REG, 1, &data);
}

static u8 aw2013_led_get_enable(AW2013_LED_TYPE led)
{
	u8 data=0;
	
	AW2013_FUNC();
	AW2013_CHECK_LED(led);
	if (aw2013_i2c_client == NULL)
	{
		AW2013_LOG("i2c_data obj is null!!\n");
		return 0;
	}
	if (i2c_smbus_read_i2c_block_data(aw2013_i2c_client, AW2013_LED_EN_REG,1, &data)<0)
	{
		AW2013_ERR();
		return -1;
	}

	return (data>>led)&0x01;
}

static int aw2013_led_cfg_led_current(AW2013_LED_TYPE led,AW2013_LED_CURRENT curr)
{
	u8 data=0;

	AW2013_FUNC();
	AW2013_CHECK_LED(led);
	AW2013_CHECK_CURRENT(curr);

	if (aw2013_i2c_client == NULL)
	{
		AW2013_ERR("i2c_data obj is null!!\n");
		return -1;
	}
	if (i2c_smbus_read_i2c_block_data(aw2013_i2c_client, AW2013_LED0_CFG_REG+led,1, &data)<0)
	{
		AW2013_ERR();
		return -1;
	}
	
	data = (data&0xfc)|(u8)curr;

	return i2c_smbus_write_i2c_block_data(aw2013_i2c_client, AW2013_LED0_CFG_REG+led, 1, &data);
}

static u8 aw2013_led_get_current(AW2013_LED_TYPE led)
{
	u8 data=0;

	AW2013_FUNC();
	AW2013_CHECK_LED(led);
	if (aw2013_i2c_client == NULL)
	{
		printk("i2c_data obj is null!!\n");
		return 0;
	}
	if(i2c_smbus_read_i2c_block_data(aw2013_i2c_client, AW2013_LED0_CFG_REG+led,1, &data)<0)
	{
		AW2013_ERR();
		return -1;
	}
	
	return data&0x07;
}


static int aw2013_led_cfg_led_mode(AW2013_LED_TYPE led,AW2013_LED_MODE mod)
{
	u8 data=0;

	AW2013_FUNC();
	AW2013_CHECK_LED(led);

	if (aw2013_i2c_client == NULL)
	{
		AW2013_ERR("i2c_data obj is null!!\n");
		return -1;
	}

	if(i2c_smbus_read_i2c_block_data(aw2013_i2c_client, AW2013_LED0_CFG_REG+led,1, &data)<0)
	{
		AW2013_ERR();
		return -1;
	}

	AW2013_SET_BIT(data,4,mod);

	return i2c_smbus_write_i2c_block_data(aw2013_i2c_client, AW2013_LED0_CFG_REG+led, 1, &data);
}

static u8 aw2013_led_get_mode(AW2013_LED_TYPE led)
{
	u8 data=0;

	AW2013_FUNC();
	AW2013_CHECK_LED(led);
	if (aw2013_i2c_client == NULL)
	{
		printk("i2c_data obj is null!!\n");
		return 0;
	}
	if(i2c_smbus_read_i2c_block_data(aw2013_i2c_client, AW2013_LED0_CFG_REG+led,1, &data)<0)
	{
		AW2013_ERR();
		return -1;
	}
	return (data>>4)&0x01;
}

static int aw2013_led_cfg_fade_in(AW2013_LED_TYPE led,bool enable)
{
	u8 data=0;

	AW2013_FUNC();
	AW2013_CHECK_LED(led);
	if (aw2013_i2c_client == NULL)
	{
		AW2013_ERR("i2c_data obj is null!!\n");
		return -1;
	}
	if(i2c_smbus_read_i2c_block_data(aw2013_i2c_client, AW2013_LED0_CFG_REG+led,1, &data)<0)  //AW2013_LED0_CFG_REG 0x31
	{
		AW2013_ERR();
		return -1;
	}
	AW2013_SET_BIT(data,5,enable);

	return i2c_smbus_write_i2c_block_data(aw2013_i2c_client, AW2013_LED0_CFG_REG+led, 1, &data);
	
}

static u8 aw2013_led_get_fade_in(AW2013_LED_TYPE led)
{
	u8 data=0;

	AW2013_FUNC();
	AW2013_CHECK_LED(led);
	if (aw2013_i2c_client == NULL)
	{
		AW2013_LOG("i2c_data obj is null!!\n");
		return 0;
	}
	if(i2c_smbus_read_i2c_block_data(aw2013_i2c_client, AW2013_LED0_CFG_REG+led,1, &data)<0)   
	{
		AW2013_ERR();
		return -1;
	}

	return (data>>5)&0x01;
	
}

static int aw2013_led_cfg_fade_out(AW2013_LED_TYPE led,bool enable)
{
	u8 data=0;

	AW2013_FUNC();
	AW2013_CHECK_LED(led);

	if (aw2013_i2c_client == NULL)
	{
		AW2013_ERR("i2c_data obj is null!!\n");
		return -1;
	}

	if (i2c_smbus_read_i2c_block_data(aw2013_i2c_client, AW2013_LED0_CFG_REG+led,1, &data) < 0)
	{
		AW2013_ERR();
		return -1;
	}

	AW2013_SET_BIT(data,6,enable);

	return i2c_smbus_write_i2c_block_data(aw2013_i2c_client, AW2013_LED0_CFG_REG+led, 1, &data);	
}

static u8 aw2013_led_get_fade_out(AW2013_LED_TYPE led)
{
	u8 data=0;

	AW2013_FUNC();
	AW2013_CHECK_LED(led);
	if (aw2013_i2c_client == NULL)
	{
		printk("i2c_data obj is null!!\n");
		return 0;
	}
	if(i2c_smbus_read_i2c_block_data(aw2013_i2c_client, AW2013_LED0_CFG_REG+led,1, &data)<0)
	{
		AW2013_ERR();
		return -1;
	}

	return (data>>6)&0x01;
	
}

static int aw2013_led_set_pwm(AW2013_LED_TYPE led,u8 pwm)
{
	AW2013_FUNC();
	AW2013_CHECK_LED(led);
	if (aw2013_i2c_client == NULL)
	{
		AW2013_ERR("i2c_data obj is null!!\n");
		return -1;
	}

	//[agold][xfl][20160828][start][应用不会改PWM，只能驱动来改了]
	#if defined(AGOLD_LED_BRIGHTNESS_PERCENT__INT)
	pwm = pwm * AGOLD_LED_BRIGHTNESS_PERCENT__INT/100;
	#endif
	//[agold][xfl][20160828][end]

	return i2c_smbus_write_i2c_block_data(aw2013_i2c_client, AW2013_LED0_PWM_REG+led, 1, &pwm);
	
}

static u8 aw2013_led_get_pwm(AW2013_LED_TYPE led)
{
	u8 data=0;
	AW2013_FUNC();
	AW2013_CHECK_LED(led);
	if (aw2013_i2c_client == NULL)
	{
		printk("i2c_data obj is null!!\n");
		return 0;
	}
	if(i2c_smbus_read_i2c_block_data(aw2013_i2c_client, AW2013_LED0_PWM_REG+led, 1, &data)<0)
	{
		AW2013_ERR();
		return -1;
	}
	
	return data;
	
}

static int aw2013_led_set_hold_time(AW2013_LED_TYPE led,u8 time)
{
	u8 data=0;
	AW2013_FUNC();

	AW2013_CHECK_LED(led);
	if (aw2013_i2c_client == NULL)
	{
		AW2013_ERR("i2c_data obj is null!!\n");
		return -1;
	}
	if(i2c_smbus_read_i2c_block_data(aw2013_i2c_client, AW2013_LED0_ON_REG+led*3,1, &data)<0)  //AW2013_LED0_ON_REG <==>0x37
	{
		AW2013_ERR();
		return -1;
	}
	time=(time>5)?5:time;
	data= (data&0xf8)|time;

	return i2c_smbus_write_i2c_block_data(aw2013_i2c_client, AW2013_LED0_ON_REG+led*3, 1, &data);
	
}

static u8 aw2013_led_get_hold_time(AW2013_LED_TYPE led)
{
	u8 data=0;
	AW2013_FUNC();

	AW2013_CHECK_LED(led);
	if (aw2013_i2c_client == NULL)
	{
		printk("i2c_data obj is null!!\n");
		return -1;
	}
	if(i2c_smbus_read_i2c_block_data(aw2013_i2c_client, AW2013_LED0_ON_REG+led*3,1, &data)<0)
	{
		AW2013_ERR();
		return -1;
	}

	return data&0x07;
	
}

static int aw2013_led_set_rise_time(AW2013_LED_TYPE led,u8 time)
{
	u8 data=0;
	AW2013_FUNC();

	AW2013_CHECK_LED(led);
	if (aw2013_i2c_client == NULL)
	{
		AW2013_ERR("i2c_data obj is null!!\n");
		return -1;
	}
	if(i2c_smbus_read_i2c_block_data(aw2013_i2c_client, AW2013_LED0_ON_REG+led*3,1, &data)<0)
	{
		AW2013_ERR();
		return -1;
	}
	time=(time>7)?7:time;
	data= (data&0x0f)|(time<<4);

	return i2c_smbus_write_i2c_block_data(aw2013_i2c_client, AW2013_LED0_ON_REG+led*3, 1, &data);
	
}

static u8 aw2013_led_get_rise_time(AW2013_LED_TYPE led)
{
	u8 data=0;

	AW2013_FUNC();
	AW2013_CHECK_LED(led);
	if (aw2013_i2c_client == NULL)
	{
		printk("i2c_data obj is null!!\n");
		return 0;
	}
	if(i2c_smbus_read_i2c_block_data(aw2013_i2c_client, AW2013_LED0_ON_REG+led*3,1, &data)<0)
	{
		AW2013_ERR();
		return -1;
	}

	return (data>>4)&0x07;
	
}

static int aw2013_led_set_off_time(AW2013_LED_TYPE led,u8 time)
{
	u8 data=0;

	AW2013_FUNC();
	AW2013_CHECK_LED(led);

	if (aw2013_i2c_client == NULL)
	{
		AW2013_ERR("i2c_data obj is null!!\n");
		return -1;
	}

	if (i2c_smbus_read_i2c_block_data(aw2013_i2c_client, AW2013_LED0_OFF_REG+led*3,1, &data)<0)
	{
		AW2013_ERR();
		return -1;
	}

	time=(time>7)?7:time;
	data= (data&0xf8)|time;

	return i2c_smbus_write_i2c_block_data(aw2013_i2c_client, AW2013_LED0_OFF_REG+led*3, 1, &data);
	
}

static u8 aw2013_led_get_off_time(AW2013_LED_TYPE led)
{
	u8 data=0;

	AW2013_FUNC();
	AW2013_CHECK_LED(led);
	if (aw2013_i2c_client == NULL)
	{
		printk("i2c_data obj is null!!\n");
		return 0;
	}
	if(i2c_smbus_read_i2c_block_data(aw2013_i2c_client, AW2013_LED0_OFF_REG+led*3,1, &data)<0)
	{
		AW2013_ERR();
		return -1;
	}

	return data&0x07;
	
}

static int aw2013_led_set_fall_time(AW2013_LED_TYPE led,u8 time)
{
	u8 data=0;

	AW2013_FUNC();
	AW2013_CHECK_LED(led);

	if (aw2013_i2c_client == NULL)
	{
		printk("i2c_data obj is null!!\n");
		return -1;
	}

	if (i2c_smbus_read_i2c_block_data(aw2013_i2c_client, AW2013_LED0_OFF_REG+led*3,1, &data) < 0)
	{
		AW2013_ERR();
		return -1;
	}

	time=(time>7)?7:time;
	data= (data&0x0f)|(time<<4);

	return i2c_smbus_write_i2c_block_data(aw2013_i2c_client, AW2013_LED0_OFF_REG+led*3, 1, &data);
	
}

static u8 aw2013_led_get_fall_time(AW2013_LED_TYPE led)
{
	u8 data=0;

	AW2013_FUNC();
	AW2013_CHECK_LED(led);
	if (aw2013_i2c_client == NULL)
	{
		printk("i2c_data obj is null!!\n");
		return 0;
	}
	if(i2c_smbus_read_i2c_block_data(aw2013_i2c_client, AW2013_LED0_OFF_REG+led*3,1, &data)<0)
	{
		AW2013_ERR();
		return -1;
	}

	return (data>>4)&0x07;
	
}

static int aw2013_led_set_repeat_num(AW2013_LED_TYPE led,u8 num)
{
	u8 data=0;
	AW2013_FUNC();

	AW2013_CHECK_LED(led);

	if (aw2013_i2c_client == NULL)
	{
		AW2013_ERR("i2c_data obj is null!!\n");
		return -1;
	}

	if (i2c_smbus_read_i2c_block_data(aw2013_i2c_client, AW2013_LED0_CTL_REG+led*3,1, &data) < 0)
	{
		AW2013_ERR();
		return -1;
	}

	num=(num>7)?7:num;
	data= (data&0xf0)|num;

	return i2c_smbus_write_i2c_block_data(aw2013_i2c_client, AW2013_LED0_CTL_REG+led*3, 1, &data);
	
}

static u8 aw2013_led_get_repeat_num(AW2013_LED_TYPE led)
{
	u8 data=0;

	AW2013_FUNC();
	AW2013_CHECK_LED(led);
	if (aw2013_i2c_client == NULL)
	{
		printk("i2c_data obj is null!!\n");
		return 0;
	}
	if(i2c_smbus_read_i2c_block_data(aw2013_i2c_client, AW2013_LED0_CTL_REG+led*3,1, &data)<0)
	{
		AW2013_ERR();
		return -1;
	}

	return data&0x07;
	
}

static int aw2013_led_set_delay_time(AW2013_LED_TYPE led,u8 time)
{
	u8 data=0;

	AW2013_FUNC();
	AW2013_CHECK_LED(led);

	if (aw2013_i2c_client == NULL)
	{
		AW2013_ERR("i2c_data obj is null!!\n");
		return -1;
	}

	if (i2c_smbus_read_i2c_block_data(aw2013_i2c_client, AW2013_LED0_CTL_REG+led*3,1, &data) < 0)
	{
		AW2013_ERR();
		return -1;
	}

	time=(time>8)?8:time;
	data= (data&0x0f)|(time<<4);

	return i2c_smbus_write_i2c_block_data(aw2013_i2c_client, AW2013_LED0_CTL_REG+led*3, 1, &data);
	
}

static u8 aw2013_led_get_delay_time(AW2013_LED_TYPE led)
{
	u8 data=0;
	AW2013_FUNC();

	AW2013_CHECK_LED(led);
	if (aw2013_i2c_client == NULL)
	{
		printk("i2c_data obj is null!!\n");
		return 0;
	}
	if(i2c_smbus_read_i2c_block_data(aw2013_i2c_client, AW2013_LED0_CTL_REG+led*3,1, &data)<0)
	{
		AW2013_ERR();
		return -1;
	}

	return (data>>4)&0x0f;
	
}
/*
static int aw1023_led_set(AW2013_LED_TYPE led,AW2013_LED_CURRENT curr,AW2013_LED_MODE mode, 
			bool fade_in,bool fade_out,u8 pwm, 
			u8 hold_time,u8 rise_time,u8 off_time,u8 fall_time, 
			u8 repeat_num,u8 delay_time)
{
	int ret=0;

	AW2013_FUNC();
	if (aw2013_i2c_client == NULL)
	{
		printk("i2c_data obj is null!!\n");
		return 0;
	}
	ret|= aw2013_led_cfg_led_current(led,curr);
	ret|= aw2013_led_cfg_led_mode(led,mode);
	ret|= aw2013_led_cfg_fade_in(led,fade_in);
	ret|= aw2013_led_cfg_fade_out(led,fade_out);
	ret|= aw2013_led_set_pwm(led,pwm);

	if(AW2013_LED_MODE_AUTO==mode)
	{
		ret|= aw2013_led_set_hold_time(led,hold_time);
		ret|= aw2013_led_set_rise_time(led,rise_time);
		ret|= aw2013_led_set_off_time(led,off_time);
		ret|= aw2013_led_set_fall_time(led,fall_time);
		ret|= aw2013_led_set_repeat_num(led,repeat_num);
		ret|= aw2013_led_set_delay_time(led,delay_time);
	}

	return ret;
	
}
*/
static int aw1023_led_set_by_property(AW2013_LED_TYPE led,AW2013_LED_PROPERTY property,u8 value)
{
	int ret=0;

	AW2013_FUNC();
	switch(property)
	{
		case AW2013_LED_ENABLE:
			ret=aw2013_enable_led(led,(bool)value);
			break;
		case AW2013_LED_CURR:
			ret=aw2013_led_cfg_led_current(led,(AW2013_LED_CURRENT)value);
			break;
		case AW2013_LED_MOD:
			ret=aw2013_led_cfg_led_mode(led,(AW2013_LED_MODE)value);
			break;
		case AW2013_LED_FADE_IN:
			ret=aw2013_led_cfg_fade_in(led,(bool)value);
			break;
		case AW2013_LED_FADE_OUT:
			ret=aw2013_led_cfg_fade_out(led,(bool)value);
			break;
		case AW2013_LED_PWM:
			ret=aw2013_led_set_pwm(led,value);
			break;
		case AW2013_LED_HOLD_TIME:
			ret=aw2013_led_set_hold_time(led,value);
			break;
		case AW2013_LED_RISE_TIME:
			ret=aw2013_led_set_rise_time(led,value);
			break;
		case AW2013_LED_OFF_TIME:
			ret=aw2013_led_set_off_time(led,value);
			break;
		case AW2013_LED_FALL_TIME:
			ret=aw2013_led_set_fall_time(led,value);
			break;
		case AW2013_LED_REPEAT_NUM:
			ret=aw2013_led_set_repeat_num(led,value);
			break;
		case AW2013_LED_DELAY_TIME:
			ret=aw2013_led_set_delay_time(led,value);
			break;
		default:
			AW2013_LOG("aw1023_led_set_by_property error==>undefault cmd %#x\n",property);
			break;
	}

	return ret;
}
static u8 aw1023_led_get_by_property(AW2013_LED_TYPE led,AW2013_LED_PROPERTY property)
{
	u8 ret=0;

	AW2013_FUNC();
	switch(property)
	{
		case AW2013_LED_ENABLE:
			ret=aw2013_led_get_enable(led);
			break;
		case AW2013_LED_CURR:
			ret=aw2013_led_get_current(led);
			break;
		case AW2013_LED_MOD:
			ret=aw2013_led_get_mode(led);
			break;
		case AW2013_LED_FADE_IN:
			ret=aw2013_led_get_fade_in(led);
			break;
		case AW2013_LED_FADE_OUT:
			ret=aw2013_led_get_fade_out(led);
			break;
		case AW2013_LED_PWM:
			ret=aw2013_led_get_pwm(led);
			break;
		case AW2013_LED_HOLD_TIME:
			ret=aw2013_led_get_hold_time(led);
			break;
		case AW2013_LED_RISE_TIME:
			ret=aw2013_led_get_rise_time(led);
			break;
		case AW2013_LED_OFF_TIME:
			ret=aw2013_led_get_off_time(led);
			break;
		case AW2013_LED_FALL_TIME:
			ret=aw2013_led_get_fall_time(led);
			break;
		case AW2013_LED_REPEAT_NUM:
			ret=aw2013_led_get_repeat_num(led);
			break;
		case AW2013_LED_DELAY_TIME:
			ret=aw2013_led_get_delay_time(led);
			break;
		default:
			AW2013_LOG("aw1023_led_get_by_property error==>undefault cmd %#x\n",property);
			break;
	}

	return ret;
}

static int aw2013_init_led(void)
{
	u8 data = 0x01;
	int ret = 0;
	AW2013_LED_TYPE led=AW2013_LED_RED;

	AW2013_FUNC();

	if (aw2013_i2c_client == NULL)
	{
		printk("i2c_data obj is null!!\n");
		return -1;
	}

    ret += aw2013_enable_led(AW2013_LED_RED, false);
    ret += aw2013_enable_led(AW2013_LED_GREEN, false);
    ret += aw2013_enable_led(AW2013_LED_BLUE, false);

	ret += i2c_smbus_write_i2c_block_data(aw2013_i2c_client, AW2013_GC_REG, 1, &data);

	while(led <= AW2013_LED_NUM)
	{
		ret += i2c_smbus_write_i2c_block_data(aw2013_i2c_client, AW2013_LED0_CFG_REG+led, 1, &led_default.led_cfg);
		ret += i2c_smbus_write_i2c_block_data(aw2013_i2c_client, AW2013_LED0_PWM_REG+led, 1, &led_default.pwm);
		ret += i2c_smbus_write_i2c_block_data(aw2013_i2c_client, AW2013_LED0_ON_REG+led*3, 1, &led_default.on_cfg);
		ret += i2c_smbus_write_i2c_block_data(aw2013_i2c_client, AW2013_LED0_OFF_REG+led*3, 1, &led_default.off_cfg);
		ret += i2c_smbus_write_i2c_block_data(aw2013_i2c_client, AW2013_LED0_CTL_REG+led*3, 1, &led_default.ctl_cfg);
		led++;
	}

	AW2013_LOG("zam %s:ret=%#x,led_default.led_cfg=%d\n",__func__,ret,led_default.led_cfg);
	return ret;
}

static int aw2013_flinger_mode_config(AW2013_LED_TYPE led, u8 pwm, u8 on_time, u8 off_time, u8 fade_in_time, u8 fade_out_time, u8 repeat_num)
{
	int ret = 0;

	AW2013_FUNC();

	if (aw2013_i2c_client == NULL)
	{
		AW2013_ERR("i2c_data obj is null!!\n");
		return ret;
	}

	if (aw2013_led_set_pwm(led, pwm)) //设定最大亮度
	{
		AW2013_ERR("aw2013_led_set_pwm fail!!\n");
		return -1;
	}

	AW2013_LOG("led=%d,on_time==%d,off_time==%d,fade_in_time=%d,fade_out_time=%d\n",led,on_time,off_time,fade_in_time,fade_out_time);

	if (on_time && off_time) 
	{	
		/* 一次编程模式*/
		ret += aw2013_led_cfg_led_mode(led, AW2013_LED_MODE_AUTO);		//设定模式为一次编程模式
		ret += aw2013_led_cfg_led_current(0, AW2013_DEFAULT_RED_CURRENT);
		ret += aw2013_led_cfg_led_current(1, AW2013_DEFAULT_GREEN_CURRENT);
		ret += aw2013_led_cfg_led_current(2, AW2013_DEFAULT_BLUE_CURRENT);
		ret += aw2013_led_set_hold_time(led, on_time); //设定灯亮保持时间
		ret += aw2013_led_cfg_fade_in(led, true);	//设定亮度逐渐变亮
		ret += aw2013_led_set_rise_time(led, fade_in_time); //设定上升时间
		ret += aw2013_led_set_off_time(led, off_time); //设定灯灭保持时间
		ret += aw2013_led_cfg_fade_out(led, true);  //设定亮度逐渐变暗
		ret += aw2013_led_set_fall_time(led, fade_out_time); //设定下降时间
		ret += aw2013_led_set_delay_time(led, 0);
		ret += aw2013_led_set_repeat_num(led, repeat_num); //repeat_num == 0 无限次闪烁
	}
	else
	{		
	 	ret += aw2013_led_cfg_fade_in(led, false);  //设定灯的亮度的突变亮
		ret += aw2013_led_cfg_fade_out(led, false); //设定灯的亮度的突变暗
		ret += aw2013_led_cfg_led_current(led, AW2013_DEFAULT_CURRENT);
		ret += aw2013_led_cfg_led_mode(led, AW2013_LED_MODE_NORMAL); //设定模式为非闪烁状态，亮度直接由PWM控制
	
	}

	return ret;
}

 														
void aw2013_order_config(u8 red_pwm,u8 green_pwm,u8 bule_pwm,u8 repeat_num)
{
	AW2013_LED_TYPE led=AW2013_LED_RED;
	AW2013_FUNC();
	if (aw2013_i2c_client == NULL)
	{
		printk("i2c_data obj is null!!\n");
		return;
	}
	//set red
	led = AW2013_LED_RED;
	aw2013_led_cfg_led_mode(led,AW2013_LED_MODE_AUTO);
	aw2013_led_cfg_led_current(led,AW2013_DEFAULT_CURRENT);
	aw2013_led_set_hold_time(led,order_mode_time);
	aw2013_led_cfg_fade_in(led,true);
	aw2013_led_set_rise_time(led,order_mode_time);
	aw2013_led_set_off_time(led,order_mode_time);
	aw2013_led_cfg_fade_out(led,true);
	aw2013_led_set_fall_time(led,order_mode_time);
	aw2013_led_set_delay_time(led,order_mode_time+3);
	aw2013_led_set_repeat_num(led,repeat_num);
	//set green
	led = AW2013_LED_GREEN;
	aw2013_led_cfg_led_mode(led,AW2013_LED_MODE_AUTO);
	aw2013_led_cfg_led_current(led,AW2013_DEFAULT_CURRENT);
	aw2013_led_set_hold_time(led,order_mode_time);
	aw2013_led_cfg_fade_in(led,true);
	aw2013_led_set_rise_time(led,order_mode_time);
	aw2013_led_set_off_time(led,order_mode_time+3);
	aw2013_led_cfg_fade_out(led,true);
	aw2013_led_set_fall_time(led,order_mode_time);
	aw2013_led_set_delay_time(led,order_mode_time+2);
	aw2013_led_set_repeat_num(led,repeat_num);
	//set blue
	led = AW2013_LED_BLUE;
	aw2013_led_cfg_led_mode(led,AW2013_LED_MODE_AUTO);
	aw2013_led_cfg_led_current(led,AW2013_DEFAULT_CURRENT);
	aw2013_led_set_hold_time(led,order_mode_time);
	aw2013_led_cfg_fade_in(led,true);
	aw2013_led_set_rise_time(led,order_mode_time);
	aw2013_led_set_off_time(led,order_mode_time+3);
	aw2013_led_cfg_fade_out(led,true);
	aw2013_led_set_fall_time(led,order_mode_time);
	aw2013_led_set_delay_time(led,order_mode_time+3);
	aw2013_led_set_repeat_num(led,repeat_num);
	
}

static int aw2013_all_led_enable(bool enable)
{
	u8 data=0;

	if (aw2013_i2c_client == NULL)
	{
		AW2013_ERR("i2c_data obj is null!!\n");
		return -1;
	}

	if (i2c_smbus_read_i2c_block_data(aw2013_i2c_client, AW2013_LED_EN_REG,1, &data)<0)
	{
		AW2013_ERR();
		return -1;
	}

	if (enable)
	{	
		data |= 0x07;
	}
	else
	{
		data &= ~0x07;
	}
	
	return i2c_smbus_write_i2c_block_data(aw2013_i2c_client, AW2013_LED_EN_REG, 1, &data);
}

typedef enum
{
	AW2013_LED_WORK_MODE_FLINGER, //混合色，	
	AW2013_LED_WORK_MODE_ORDER,
	AW2013_LED_WORK_MODE_MAX=AW2013_LED_WORK_MODE_ORDER
}AW2013_LED_WORK_MODE;

void aw2013_changetime_to_level(int *time)
{
	if(*time<= 130)
	{
		*time =0;
	}
	else if(*time<= 260)
	{
		*time =1;
	}
	else if(*time<= 520)
	{
		*time =2;
	}
	else if(*time<= 1040)
	{
		*time =3;
	}
	else if(*time<= 2080)
	{
		*time =4;
	}
	else if(*time<= 4160)
	{
		*time =5;
	}
	else if(*time<= 8320)
	{
		*time =6;
	}
	else
	{
		*time =7;
	}
}


int aw2013_set_rgb(int level,int red,int green,int blue,int delayon,int delayoff, int rising, int falling)
{
    int ret=0;
	u8 data=0x01;
	int time = 0;//agold_led_data.time;
    int fadein = 5;
    int fadeoff = 5;

	fadein = rising;
	fadeoff = falling;

	if (aw2013_i2c_client == NULL)
	{
		AW2013_ERR("i2c_data obj is null!!\n");
		return -1;
	}

	AW2013_LOG("%s:level=%d\n",__func__,level);

	if(!level)
	{
		ret = aw2013_all_led_enable(false);
		if (ret)
		{
			AW2013_ERR("aw2013_all_led_enable fail\n");
		}
		return ret; 
	}
 
	AW2013_LOG("%s:level=%d  ,  delayon = %d  delayoff = %d  red = %d green = %d   blue = %d rising = %d falling = %d \n",__func__,level,delayon,delayoff,red,green,blue, rising, falling);

	if (aw2013_reset_all())
	{
		AW2013_ERR("aw2013_reset_all error!\n");
		return -1;
	}

	ret += i2c_smbus_write_i2c_block_data(aw2013_i2c_client, AW2013_GC_REG,1, &data);

	aw2013_changetime_to_level(&delayon);
	aw2013_changetime_to_level(&delayoff);
	aw2013_changetime_to_level(&fadein);
	aw2013_changetime_to_level(&fadeoff);

	AW2013_LOG("%s:level=%d  ,  delayon = %d  delayoff = %d  red = %d green = %d   blue = %d rising = %d falling = %d \n",__func__,level,delayon,delayoff,red,green,blue, rising, falling);
			
	ret += aw2013_all_led_enable(false);
	ret += aw2013_flinger_mode_config(AW2013_LED_RED,(u8)red,(u8)delayon,(u8)delayoff,(u8)fadein,(u8)fadeoff,(u8)time);
	ret += aw2013_flinger_mode_config(AW2013_LED_GREEN,(u8)green,(u8)delayon,(u8)delayoff,(u8)fadein,(u8)fadeoff,(u8)time);
	ret += aw2013_flinger_mode_config(AW2013_LED_BLUE,(u8)blue,(u8)delayon,(u8)delayoff,(u8)fadein,(u8)fadeoff,(u8)time);
	ret += aw2013_all_led_enable(true);
	
   	return ret;   
}



unsigned int aw2013_set_red_led(int level)
{
	int ret=0;
        int div = 0;  
	u8 data=0xff*AW2013_MAX_PWM_LEVEL/AW2013_MAX_PWM_LEVEL;
	
	AW2013_FUNC();
	if(!aw2013_i2c_client)
	{
		return -1;
	}



	if(level)
	{
		 aw2013_led_cfg_led_mode(AW2013_LED_RED,(AW2013_LED_MODE)div);
                 aw2013_led_cfg_fade_in(AW2013_LED_RED,div);
                 aw2013_led_cfg_fade_out(AW2013_LED_RED,div);
		ret=i2c_smbus_write_i2c_block_data(aw2013_i2c_client, AW2013_LED0_PWM_REG+AW2013_LED_RED,1, &data);
		ret+=aw2013_enable_led(AW2013_LED_RED,true);
	}
	else
	{
		ret=aw2013_enable_led(AW2013_LED_RED,false);
	}

	return ret;
}

unsigned int aw2013_set_green_led(int level)
{
	int ret=0;
        int div = 0;
	u8 data=0xff*AW2013_MAX_PWM_LEVEL/AW2013_MAX_PWM_LEVEL;
	AW2013_FUNC();
	
	if(!aw2013_i2c_client)
	{
		return -1;
	}

	AW2013_LOG(" agold wlg %s:level=%d  div = %d \n",__func__,level,div);		

	if(level)
	{
		aw2013_led_cfg_led_mode(AW2013_LED_GREEN,(AW2013_LED_MODE)div);
                aw2013_led_cfg_fade_in(AW2013_LED_GREEN,div);
                aw2013_led_cfg_fade_out(AW2013_LED_GREEN,div);
		ret=i2c_smbus_write_i2c_block_data(aw2013_i2c_client, AW2013_LED0_PWM_REG+AW2013_LED_GREEN,1, &data);
		ret+=aw2013_enable_led(AW2013_LED_GREEN,true);
	}
	else
	{
		ret=aw2013_enable_led(AW2013_LED_GREEN,false);
	}

	return ret;
}

unsigned int aw2013_set_blue_led(int level)
{
	int ret=0;
    int div = 0;
	u8 data=0xff*AW2013_MAX_PWM_LEVEL/AW2013_MAX_PWM_LEVEL;
	AW2013_FUNC();

	if(!aw2013_i2c_client)
	{
		return -1;
	}

	if(level)
	{
		aw2013_led_cfg_led_mode(AW2013_LED_BLUE,(AW2013_LED_MODE)div);
		aw2013_led_cfg_fade_in(AW2013_LED_BLUE,div);
        aw2013_led_cfg_fade_out(AW2013_LED_BLUE,div);
		ret=i2c_smbus_write_i2c_block_data(aw2013_i2c_client, AW2013_LED0_PWM_REG+AW2013_LED_BLUE,1, &data);
		ret+=aw2013_enable_led(AW2013_LED_BLUE,true);
	}
	else
	{
		ret=aw2013_enable_led(AW2013_LED_BLUE,false);
	}

	return ret;
}

/*----------------------------------------------------------------------------*/
static ssize_t aw2013_show_reg_value(struct device_driver *ddri, char *buf)
{
	ssize_t len = 0;
	u8 data=0;
	u8 reg=AW2013_LED_EN_REG;
	AW2013_FUNC();

	if (aw2013_i2c_client == NULL)
	{
		printk("i2c_data obj is null!!\n");
		return 0;
	}
	
	while(reg<=AW2013_LED2_CTL_REG)
	{
		if(i2c_smbus_read_i2c_block_data(aw2013_i2c_client, reg,1, &data)<0)
		{
			len += snprintf(buf+len, PAGE_SIZE-len, "read reg(0x%04X) fail\n",reg);
			return len;
		}
		len += snprintf(buf+len, PAGE_SIZE-len, "read reg(0x%04X)=%02X\n",reg,data);
		reg++;
	}
	   
	return len;    
}
/*----------------------------------------------------------------------------*/
static ssize_t aw2013_store_reg_value(struct device_driver *ddri, const char *buf, size_t count)
{
	int reg=0, value=0;
	u8 data=0;

	AW2013_FUNC();

	if (aw2013_i2c_client == NULL)
	{
		printk("i2c_data obj is null!!\n");
		return 0;
	}
	if(2 == sscanf(buf, "0x%02X 0x%02X", &reg, &value))
	{
		printk("write reg %#x==%#x\n",reg,value);
		data=(u8)value;
		i2c_smbus_write_i2c_block_data(aw2013_i2c_client, (u8)reg, 1, &data);		
	}
	else
	{
		printk("invalid format  %#x==%#x\n",reg,value);
	}
	
	return count;    
}

//[Agold][GengDong][20151212][add start][add debug]
/*----------------------------------------------------------------------------*/
static ssize_t aw2013_store_constant_value(struct device_driver *ddri, const char *buf, size_t count) 	/* 控制呼吸灯的常亮 */
{
	int ret = 0, led_num = -2,light_num=0;
	//AW2013_FUNC();
	if (2 != sscanf(buf, "%d,%d", &led_num, &light_num) )
	{
		AW2013_ERR("debug constant read buf error\n");
		return -1;
	}
	
	AW2013_LOG("constant : ( %d, %d)\n",led_num,light_num);	

	light_num = (light_num > 255)?255:light_num;

	if (led_num == AW2013_LED_RED)
	{
		ret = aw2013_set_rgb(light_num, light_num, 0, 0, 0, 0, 0, 0);
	}

	else if (led_num == AW2013_LED_GREEN)
	{
		ret = aw2013_set_rgb(light_num, 0, light_num, 0, 0, 0, 0, 0);
	}

	else if (led_num == AW2013_LED_BLUE)
	{
		ret = aw2013_set_rgb(light_num, 0, 0, light_num, 0, 0, 0, 0);
	}

	else if (led_num == -1)
	{
		ret = aw2013_set_rgb(0, 0, 0, 0, 0, 0, 0, 0);
	}
	
	else
	{
		AW2013_ERR("%s : cmd error\n",__func__);
		ret = -1;
	}

	if (ret)
	{
		AW2013_LOG("set constant fail\n");
		return -1;
	}
	
	AW2013_LOG("set led : (%d,%d) constant successful\n",led_num, light_num);
	return count;    
}


/*----------------------------------------------------------------------------*/
static ssize_t aw2013_store_flick_value(struct device_driver *ddri, const char *buf, size_t count)	/* 控制呼吸灯的闪烁 */
{	
	int ret = 0, led_num = -2, light_num=0;
	//AW2013_FUNC();
	if (2 != sscanf(buf, "%d,%d", &led_num, &light_num) )
	{
		AW2013_ERR("debug flick read buf error\n");
		return -1;
	}
	
	AW2013_LOG("flick : ( %d, %d)\n",led_num,light_num);	

	light_num = (light_num > 255)?255:light_num;

	if (led_num == AW2013_LED_RED)
	{
		ret = aw2013_set_rgb(light_num, light_num, 0, 0, 500, 2000, 0, 0);
	}

	else if (led_num == AW2013_LED_GREEN)
	{
		ret = aw2013_set_rgb(light_num, 0, light_num, 0, 500, 2000, 0, 0);
	}

	else if (led_num == AW2013_LED_BLUE)
	{
		ret = aw2013_set_rgb(light_num, 0, 0, light_num, 500, 2000, 0, 0);
	}

	else if (led_num == -1)
	{
		ret = aw2013_set_rgb(0, 0, 0, 0, 0, 0, 0, 0);
	}
	
	else
	{
		AW2013_ERR("%s : cmd error\n",__func__);
		ret = -1;
	}

	if (ret)
	{
		AW2013_LOG("set flick fail\n");
		return -1;
	}
	
	AW2013_LOG("set led : (%d,%d) flick successful\n",led_num, light_num);
	return count;   
}
//[Agold][GengDong][20151212][add end][add debug]
/*----------------------------------------------------------------------------*/
static DRIVER_ATTR(reg, S_IWUSR | S_IRUGO, aw2013_show_reg_value, aw2013_store_reg_value);
static DRIVER_ATTR(constant, S_IWUSR | S_IRUGO, NULL, aw2013_store_constant_value);
static DRIVER_ATTR(flick, S_IWUSR | S_IRUGO, NULL, aw2013_store_flick_value);
/*----------------------------------------------------------------------------*/
static struct driver_attribute *aw2013_attr_list[] = {
	&driver_attr_reg,
	&driver_attr_constant,
	&driver_attr_flick,
	
};

//[Agold][GengDong][20151212][add start][add debug]
/*----------------------------------------------------------------------------*/
static int aw2013_create_attr(struct device_driver *driver) 
{
	int idx;
	int num = (int)(sizeof(aw2013_attr_list)/sizeof(aw2013_attr_list[0]));

	if (driver == NULL)
	{
		return -EINVAL;
	}

	for(idx = 0; idx < num; idx++)
	{
		if(driver_create_file(driver, aw2013_attr_list[idx]))
		{            
			AW2013_ERR("driver_create_file (%s) fail\n", aw2013_attr_list[idx]->attr.name);
			return -1;
		}
	} 
   
	return 0;
}
/*----------------------------------------------------------------------------*/
static int aw2013_delete_attr(struct device_driver *driver)
{
	int idx;
	int num = (int)(sizeof(aw2013_attr_list)/sizeof(aw2013_attr_list[0]));

	if(driver == NULL)
	{
		return -EINVAL;
	}
	
	for(idx = 0; idx < num; idx++)
	{
		driver_remove_file(driver, aw2013_attr_list[idx]);
	}
	
	return 0;
}
//[Agold][GengDong][20151212][add end][add debug]
/****************************************************************************** 
 * Function Configuration
******************************************************************************/
static int aw2013_open(struct inode *inode, struct file *file)
{

	file->private_data = aw2013_i2c_client;
	AW2013_FUNC();

	if(file->private_data == NULL)
	{
		printk("null pointer!!\n");
		return -EINVAL;
	}
	return nonseekable_open(inode, file);
}
/*----------------------------------------------------------------------------*/
static int aw2013_release(struct inode *inode, struct file *file)
{

	file->private_data = NULL;
	return 0;
}
/*----------------------------------------------------------------------------*/
typedef struct
{
	u8 led;
	u8 property;
	u8 data;
}AW2013_IOCTL_DATA;


typedef struct
{
    int   level;
    int     red;
    int   green;
    int    blue;
    int delayon;
    int delayoff;
    int   rising;
    int  falling;        
}AW2013_LED_DATA;


#define AW2013							0X88
#define AW2013_IOCTL_INIT					_IO(AW2013, 0x00)
#define AW2013_IOCTL_READ					_IOR(AW2013, 0x01,AW2013_IOCTL_DATA)
#define AW2013_IOCTL_WRITE					_IOW(AW2013, 0x02,AW2013_IOCTL_DATA)
#define AW2013_IOCTL_SETRGB_BRIGHNESS       _IOW(AW2013, 0x03,AW2013_LED_DATA)

 
/*
#define AW2013_IOCTL_ENABLE					_IO(AW2013, 0x01)
#define AW2013_IOCTL_SET_CURRENT				_IOW(AW2013, 0x02,AW2013_IOCTL_DATA)
#define AW2013_IOCTL_SET_MOD					_IOW(AW2013, 0x03,AW2013_IOCTL_DATA)
#define AW2013_IOCTL_SET_FADE_IN				_IOW(AW2013, 0x04,AW2013_IOCTL_DATA)
#define AW2013_IOCTL_SET_FADE_OUT				_IOW(AW2013, 0x05,AW2013_IOCTL_DATA)
#define AW2013_IOCTL_SET_PWM					_IOW(AW2013, 0x06,AW2013_IOCTL_DATA)
#define AW2013_IOCTL_SET_HOLD_TIME				_IOW(AW2013, 0x07,AW2013_IOCTL_DATA)
#define AW2013_IOCTL_SET_RISE_TIME				_IOW(AW2013, 0x08,AW2013_IOCTL_DATA)
#define AW2013_IOCTL_SET_OFF_TIME				_IOW(AW2013, 0x09,AW2013_IOCTL_DATA)
#define AW2013_IOCTL_SET_FALL_TIME				_IOW(AW2013, 0x0a,AW2013_IOCTL_DATA)
#define AW2013_IOCTL_SET_REPEAT_NUM				_IOW(AW2013, 0x0b,AW2013_IOCTL_DATA)
#define AW2013_IOCTL_SET_DELAY_TIME				_IOW(AW2013, 0x0c,AW2013_IOCTL_DATA)
*/

static long aw2013_unlocked_ioctl(struct file *file, unsigned int cmd,
       unsigned long arg)
{
	int err = 0;
	void __user *data = (void __user*)arg;
	
	AW2013_IOCTL_DATA aw2013_ioctl={0};
	AW2013_LED_DATA led_data = {0};

	printk(" aw2013_unlocked_ioctl  cmd = %d \n",cmd);

	//待完善
	switch(cmd)
	{
		case AW2013_IOCTL_INIT:

			aw2013_init_led();

			break;

		case AW2013_IOCTL_READ:

			if(copy_from_user(&aw2013_ioctl, data, sizeof(aw2013_ioctl)))
			{
				return -1;	  
			}

			aw2013_ioctl.data=aw1023_led_get_by_property((AW2013_LED_TYPE)aw2013_ioctl.led, 
															(AW2013_LED_PROPERTY)aw2013_ioctl.property);

			if(copy_to_user(data, &aw2013_ioctl, sizeof(aw2013_ioctl)))
			{
				return -1;	  
			}

			break;

		case AW2013_IOCTL_WRITE:
			
			if(copy_from_user(&aw2013_ioctl, data, sizeof(aw2013_ioctl)))
			{
				return -1;	  
			}

			aw1023_led_set_by_property((AW2013_LED_TYPE)aw2013_ioctl.led, 
										(AW2013_LED_PROPERTY)aw2013_ioctl.property, aw2013_ioctl.data);

			break;

        case AW2013_IOCTL_SETRGB_BRIGHNESS:
       
			printk(" action ioctl AW2013_IOCTL_SETRGB_BRIGHNESS!\n");

			if (copy_from_user(&led_data, data, sizeof(led_data)))
			{
				printk(" AW2013_IOCTL_SETRGB_BRIGHNESS copy_from_user error !\n");
				return -1;	  
			}
	
            printk(" copy_from_user success !\n");

            err = aw2013_set_rgb(led_data.level, led_data.red, led_data.green,
									led_data.blue, led_data.delayon, led_data.delayoff, led_data.rising, led_data.falling);
			if (err)
			{
				AW2013_ERR("ioctl SETRGB_BRIGHNESS error\n");
			}
			 
            break;
/*
		case AW2013_IOCTL_ENABLE:
			aw2013_enable_led((AW2013_LED_TYPE)aw2013_ioctl.led,(bool)aw2013_ioctl.data);
			break;
		case AW2013_IOCTL_SET_CURRENT:
			aw2013_led_cfg_led_current((AW2013_LED_TYPE)aw2013_ioctl.led,(AW2013_LED_CURRENT)aw2013_ioctl.data);
			break;
		case AW2013_IOCTL_SET_MOD:
			aw2013_led_cfg_led_mode((AW2013_LED_TYPE)aw2013_ioctl.led,(AW2013_LED_MODE)aw2013_ioctl.data);
			break;
		case AW2013_IOCTL_SET_FADE_IN:
			aw2013_led_cfg_fade_in((AW2013_LED_TYPE)aw2013_ioctl.led,(bool)aw2013_ioctl.data);
			break;
		case AW2013_IOCTL_SET_FADE_OUT:
			aw2013_led_cfg_fade_out((AW2013_LED_TYPE)aw2013_ioctl.led,(bool)aw2013_ioctl.data);
			break;
		case AW2013_IOCTL_SET_PWM:
			aw2013_led_set_pwm((AW2013_LED_TYPE)aw2013_ioctl.led,aw2013_ioctl.data);
			break;
		case AW2013_IOCTL_SET_HOLD_TIME:
			aw2013_led_set_hold_time((AW2013_LED_TYPE)aw2013_ioctl.led,aw2013_ioctl.data);
			break;
		case AW2013_IOCTL_SET_RISE_TIME:
			aw2013_led_set_rise_time((AW2013_LED_TYPE)aw2013_ioctl.led,aw2013_ioctl.data);
			break;
		case AW2013_IOCTL_SET_OFF_TIME:
			aw2013_led_set_off_time((AW2013_LED_TYPE)aw2013_ioctl.led,aw2013_ioctl.data);
			break;
		case AW2013_IOCTL_SET_FALL_TIME:
			aw2013_led_set_fall_time((AW2013_LED_TYPE)aw2013_ioctl.led,aw2013_ioctl.data);
			break;
		case AW2013_IOCTL_SET_REPEAT_NUM:
			aw2013_led_set_repeat_num((AW2013_LED_TYPE)aw2013_ioctl.led,aw2013_ioctl.data);
			break;
		case AW2013_IOCTL_SET_DELAY_TIME:
			aw2013_led_set_delay_time((AW2013_LED_TYPE)aw2013_ioctl.led,aw2013_ioctl.data);
			break;
*/
		default:
			printk("aw2013:ioctl error==>undefault cmd %#x\n",cmd);
			break;
	}
	return err;
}
/*----------------------------------------------------------------------------*/
static struct file_operations aw2013_fops = {
	.owner = THIS_MODULE,
	.open = aw2013_open,
	.release = aw2013_release,
	.unlocked_ioctl = aw2013_unlocked_ioctl,
};
/*----------------------------------------------------------------------------*/
static struct miscdevice aw2013_device = {
	.minor = MISC_DYNAMIC_MINOR,
	.name = "aw2013",
	.fops = &aw2013_fops,
};
/*----------------------------------------------------------------------------*/

static int aw2013_i2c_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
	u8 data = 0;

    AW2013_FUNC();  
	aw2013_i2c_client = client;

	//hwPowerOn(MT6320_POWER_LDO_VGP,VOL_2800,"aw");
	memset(&aw2013_ctl,0,sizeof(aw2013_ctl));
	
	if (aw2013_i2c_client == NULL)
	{
		AW2013_ERR("i2c_data obj is null!!\n");
		goto exit;
	}

	i2c_smbus_read_i2c_block_data(aw2013_i2c_client, 0x00, 1, &data);

	printk("aw2013::IC ID value is %2x\n",data);

	if (0x33 != data)
	{
		AW2013_ERR("aw2013 read id error!!\n");
		goto exit;
	} 

	if (aw2013_init_led())
	{
		AW2013_ERR("aw2013_device init failed\n");
		goto exit_misc_device_register_failed;
	}

	if (misc_register(&aw2013_device))
	{
		AW2013_ERR("aw2013_device register failed\n");
		goto exit_misc_device_register_failed;
	}


	if (aw2013_create_attr(&aw2013_i2c_driver.driver))
	{
		AW2013_ERR("create aw2013 attribute err\n");
		goto exit_create_attr_failed;
	}

/*	if (driver_create_file(&aw2013_leds_driver.driver, &driver_attr_reg))
	{
		AW2013_ERR("create aw2013 attribute err\n");
		goto exit_create_attr_failed;
	}
*/
	printk("%s : ok!\n",__func__);
	return 0;

exit_create_attr_failed:
	misc_deregister(&aw2013_device);

exit_misc_device_register_failed:
exit:
	aw2013_i2c_client = NULL;
	printk("%s: err \n", __func__);        
	return -1;

}

bool aw2013_is_exist(void)
{
	if(aw2013_i2c_client == NULL)
	{
		return false;
	}
	
	return true;
}
/*----------------------------------------------------------------------------*/
static int aw2013_i2c_remove(struct i2c_client *client)
{	

	if(aw2013_delete_attr(&aw2013_i2c_driver.driver))
	{
		AW2013_ERR("aw2013_delete_attr fail\n");
	}
	if(misc_deregister(&aw2013_device))
	{
		AW2013_ERR("misc_deregister fail\n");
	}
	
	i2c_unregister_device(client);
	return 0;
}

#ifdef CONFIG_OF
static const struct of_device_id aw2013_of_match[] = {
	{.compatible = "mediatek,LED"},
	{},
};
#endif

/*----------------------------------------------------------------------------*/
static struct i2c_driver aw2013_i2c_driver = {
    .driver = {
//        .owner          = THIS_MODULE,
        .name           = AW2013_DEV_NAME,
#ifdef CONFIG_OF
		.of_match_table = aw2013_of_match
#endif
    },
	.probe      		= aw2013_i2c_probe,
	.remove    			= aw2013_i2c_remove,
	.id_table = aw2013_i2c_id,
};

/*
static struct platform_device agold_aw2013_dev = {
    .name   = "aw2013",
    .id     = -1,
};


static int aw2013_probe(struct platform_device *pdev) 
{
	AW2013_FUNC();

	if(i2c_add_driver(&aw2013_i2c_driver))
	{
		printk("add driver error\n");
		return -1;
	}
	return 0;
}*/
/*----------------------------------------------------------------------------*/
/*
static int aw2013_remove(struct platform_device *pdev)
{	
    AW2013_FUNC();  
    i2c_del_driver(&aw2013_i2c_driver);
    return 0;
}
static struct platform_driver aw2013_leds_driver = {
	.probe      = aw2013_probe,
	.remove     = aw2013_remove,    
	.driver     = {
		.name  = "aw2013",
		.owner = THIS_MODULE,
	}
};*/

/*----------------------------------------------------------------------------*/
static int __init aw2013_init(void)
{
			
	AW2013_FUNC();
	//i2c_register_board_info(I2C_LED_CHANNEL, &i2c_AW2013, 1);
	/*
	if(platform_device_register(&agold_aw2013_dev))
	{
		printk("agold_aw2013_dev register error\n");
		return -1;
	}

	if(platform_driver_register(&aw2013_leds_driver))
	{
		printk("failed to register driver");
		return -ENODEV;
	}*/

	if(i2c_add_driver(&aw2013_i2c_driver))
	{
		printk("add driver error\n");
		return -1;
	}

	return 0;    
}
/*----------------------------------------------------------------------------*/
static void __exit aw2013_exit(void)
{
	AW2013_FUNC();
	//platform_device_unregister(&agold_aw2013_dev);
	//platform_driver_unregister(&aw2013_leds_driver);
}
/*----------------------------------------------------------------------------*/
module_init(aw2013_init);
module_exit(aw2013_exit);
/*----------------------------------------------------------------------------*/
#endif
