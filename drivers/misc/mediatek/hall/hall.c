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
#include <asm/io.h>
#include <linux/wakelock.h>
#include <linux/ioctl.h>
#include <linux/switch.h>

#include <linux/sched.h>
#include <linux/of.h>
#include <linux/of_address.h>
#include <linux/of_irq.h>

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/time.h>
#include <linux/types.h>
#include <linux/seq_file.h>
#include <linux/list.h>
#include <linux/proc_fs.h>
#include <generated/autoconf.h>
#include <linux/regulator/consumer.h>
#include <linux/gpio.h>

#define DEBUG(fmt, arg...)    printk(KERN_EMERG "   %s: " fmt, __FUNCTION__ ,##arg)

#define AGOLD_HALL_DEBUG
#if defined(AGOLD_HALL_DEBUG)
#define HALL_DEBUG(fmt, arg...) printk("[Agold][HALL_DEBUG]" fmt, ##arg);
#define HALL_INFO(fmt, arg...) printk("[Agold][HALL_INFO]" fmt, ##arg);
#else
#define HALL_DEBUG(fmt, arg...)
#define HALL_INFO(fmt, arg...)
#endif

#define HALL_ERR(fmt, arg...) printk("[Agold][HALL_ERRor]" fmt, ##arg);

#define		AGOLD_HALL_STATE		_IOWR(0x88,1,int)

#ifndef HALL_KEY
//#if 1//defined(AGOLD_HALL_ONLY_LOCKSCR_FOR_ZXD)
#if defined(AGOLD_HALL_ONLY_LOCKSCR_FOR_ZXD)//AGOLD zhengzhibin
#define HALL_KEY KEY_POWER//AGOLD LCX 
#else
#define HALL_KEY KEY_F12//KEY_FUNC1
#endif
#endif
#define HALL_DEVICE "hall_1"

#define GPIO_HALL_1_PIN 3

struct delayed_work  eint_work;
static DEFINE_SPINLOCK(hall_lock);
int Hall_Gpio_State;
struct input_dev * kpd;
struct kobject * hall_kobj;
struct switch_dev hall_dev;

static struct pinctrl *pinctrl1;
static struct pinctrl_state *hall_eint_as_gpio, *hall_eint_as_int;
static unsigned int hall_irq = 0;
static int hall_remove(struct platform_device *pdev);
static int hall_probe(struct platform_device *pdev);

static irqreturn_t hall_eint_func(unsigned irq, struct irq_desc *desc)
{
	int data;
	disable_irq_nosync(hall_irq);
	data = gpio_get_value(GPIO_HALL_1_PIN);
	if(data)
	{
		if(Hall_Gpio_State == 1)
		{
			//enable_percpu_irq(hall_irq,IRQF_TRIGGER_FALLING);
			enable_irq(hall_irq);
			return IRQ_HANDLED;
		}		
	}
	else
	{
		if(Hall_Gpio_State == 0)
		{
			//enable_percpu_irq(hall_irq,IRQF_TRIGGER_RISING);
			enable_irq(hall_irq);
			return IRQ_HANDLED;
		}
	}
	
	schedule_delayed_work(&eint_work, 0);
	return IRQ_HANDLED;
}

static void hall_eint_work(struct work_struct *work)
{
	if(Hall_Gpio_State)
	{
		spin_lock(&hall_lock);
		Hall_Gpio_State = 0;
		spin_unlock(&hall_lock);
		//mt_eint_set_polarity(CUST_EINT_HALL_1_NUM, MT_EINT_POL_POS);	
		//enable_percpu_irq(hall_irq,IRQF_TRIGGER_FALLING);
		DEBUG("[wangxing] hall close.\n");
	} 
	else
	{
		spin_lock(&hall_lock);
		Hall_Gpio_State = 1;
		spin_unlock(&hall_lock);
		//mt_eint_set_polarity(CUST_EINT_HALL_1_NUM, MT_EINT_POL_NEG);
		//enable_percpu_irq(hall_irq,IRQF_TRIGGER_RISING);
		DEBUG("[wangxing] hall far.\n");
	}
	
	input_report_key(kpd, HALL_KEY, 1);
	input_sync(kpd);
	msleep(10);
	input_report_key(kpd, HALL_KEY, 0);
	input_sync(kpd);
	
	DEBUG("HALL_KEY = %d \n",HALL_KEY);

	switch_set_state(&hall_dev, Hall_Gpio_State);
	enable_irq(hall_irq);
}

static int hall_open(struct inode * inode, struct file *file)
{
	return nonseekable_open(inode, file);
}

static int hall_release(struct inode * inode, struct file *file)
{
	return 0;
}

static long hall_ioctl(struct file *file,unsigned int cmd, unsigned long arg)
{
	void __user *ptr = (void __user*) arg;
	int data;
	long err;
	DEBUG("kernel_cmd = %d\n",cmd);
	switch(cmd)
	{
		case AGOLD_HALL_STATE:
			spin_lock(&hall_lock);
			data = Hall_Gpio_State;
			spin_unlock(&hall_lock);
			if(copy_to_user(ptr, &data, sizeof(data)))
			{
				err = -EFAULT;
				return err;
			}
			break;	
		default:
			return 1;
	}
	return 0;
}

static ssize_t hall_show_status(struct kobject * kobj,struct kobj_attribute *attr,char *buf)
{
	ssize_t len = 0;
	int data;
	
	spin_lock(&hall_lock);
	data = gpio_get_value(GPIO_HALL_1_PIN);
	spin_unlock(&hall_lock);
	
	len += sprintf(buf + len,"%d \n",data);	
	return len;
}


static const struct file_operations hall_dev_file =
{
	.owner				= THIS_MODULE,
    .open				= hall_open,
    .unlocked_ioctl 	= hall_ioctl,
    .release			= hall_release,
};

static struct kobj_attribute agold_hall_status_attr = {
    .attr = {
        .name = "hall_status",
        .mode = S_IWUGO|S_IRUGO,
    },
    .show = &hall_show_status,
};

static struct attribute *agold_hall_attrs[] = {
    &agold_hall_status_attr.attr,
    NULL
};

static struct attribute_group agold_hall_attr_group = {
    .attrs = agold_hall_attrs,
};


static int hall_create_dev(void)
{
	int ret;
	struct class *hall_dev_class;
    
    ret = register_chrdev(0, "hall_dev", &hall_dev_file);
    if (ret <= 0) 
    {
		DEBUG(" %s:register chrdev failed,ret = %d\n", __FILE__,ret);
		return ret;
    }
    
    hall_dev_class = class_create(THIS_MODULE, "hall_dev");
    if (IS_ERR(hall_dev_class)) 
    {
		ret = PTR_ERR(hall_dev_class);
		class_destroy(hall_dev_class);
		return ret;
    }
    else
    	device_create(hall_dev_class, NULL, MKDEV(ret,0), NULL, "halldev");
    	
    hall_kobj = kobject_create_and_add("hall_status", NULL);	
    
    if(!hall_kobj)
    {
    	DEBUG(" %s:register  kobject_create_and_add failed\n", __FILE__);
    	return -1;
    }
    else
    	ret = sysfs_create_group(hall_kobj,&agold_hall_attr_group);
    
    if(ret)
    {
    	DEBUG(" %s:sysfs_create_group failed,ret = %d\n", __FILE__,ret);
    	return ret;
    }

	hall_dev.name = "agoldhall";
	hall_dev.index = 0;
	hall_dev.state = 0;

    ret = switch_dev_register(&hall_dev);
	switch_set_state(&hall_dev, Hall_Gpio_State);

	if(ret) 
	{
		HALL_ERR("%s: register switch dev failed, ret = %d\n", __func__, ret);
		return ret;
	}
    return 0;
}

static void hall_kpd_init(void)
{
	kpd=input_allocate_device();
	kpd->name = "hall-kpd";
	set_bit(EV_KEY, kpd->evbit);
	__set_bit( HALL_KEY, kpd->keybit);
	kpd->id.bustype = BUS_HOST;
    kpd->id.vendor  = 0x0077;
    kpd->id.product = 0x6577;
    kpd->id.version = 0x0100;
    if(input_register_device(kpd))
        DEBUG("input_register_device failed.(hall)\n");
}
#ifdef CONFIG_OF
struct of_device_id hall_of_match[] = {
	{ .compatible = "mediatek,hall_1", },
	{},
};
#endif
static struct platform_driver hall_driver = {
	.remove = hall_remove,
	.shutdown = NULL,
	.probe = hall_probe,
	.driver = {
		.name = HALL_DEVICE,
		#ifdef CONFIG_OF
		.of_match_table = hall_of_match,
		#endif
	},
};

static int hall_irq_registration(void)
{
	struct device_node *node = NULL;
	int ret = 0;
	u32 ints[2] = { 0, 0 };

	DEBUG("Device Tree hall_irq_registration!");

	node = of_find_matching_node(node, hall_of_match);
	if (node) {
		of_property_read_u32_array(node, "debounce", ints, ARRAY_SIZE(ints));
		gpio_set_debounce(ints[0], ints[1]);

		hall_irq = irq_of_parse_and_map(node, 0);
		DEBUG("Device Hall_Gpio_State = %d!", Hall_Gpio_State);
		if (!Hall_Gpio_State) {/*EINTF_TRIGGER*/
			ret = request_irq(hall_irq, (irq_handler_t) hall_eint_func, IRQF_TRIGGER_RISING|IRQF_TRIGGER_FALLING,"hall_1-eint", NULL);
			if (ret > 0) {
				ret = -1;
				DEBUG("hall request_irq IRQ LINE NOT AVAILABLE!.");
			}
		} else {
			ret = request_irq(hall_irq, (irq_handler_t) hall_eint_func, IRQF_TRIGGER_RISING|IRQF_TRIGGER_FALLING,"hall_1-eint", NULL);
			if (ret > 0) {
				ret = -1;
				DEBUG("hall request_irq IRQ LINE NOT AVAILABLE!.");
			}
		}
	} else {
		DEBUG("hall request_irq can not find hall eint device node!.");
		ret = -1;
	}
	enable_irq(hall_irq);
	DEBUG("[%s]irq:%d, debounce:%d-%d, hall_irq:%d", __func__, hall_irq, ints[0], ints[1],hall_irq);
	return ret;
}

int hall_get_gpio_info(struct platform_device *pdev)
{
	int ret;

	DEBUG(" hall_pinctrl+++++++++++++++++\n");
	pinctrl1 = devm_pinctrl_get(&pdev->dev);
	if (IS_ERR(pinctrl1)) {
		ret = PTR_ERR(pinctrl1);
		dev_err(&pdev->dev, "fwq Cannot find hall pinctrl1!\n");
		return ret;
	}
	hall_eint_as_gpio = pinctrl_lookup_state(pinctrl1, "hall_eint_as_gpio");
	if (IS_ERR(hall_eint_as_gpio)) {
		ret = PTR_ERR(hall_eint_as_gpio);
		dev_err(&pdev->dev, "fwq Cannot find hall pinctrl hall_eint_as_gpio %d!\n", ret);
	}
	hall_eint_as_int = pinctrl_lookup_state(pinctrl1, "hall_eint_as_int");
	if (IS_ERR(hall_eint_as_int)) {
		ret = PTR_ERR(hall_eint_as_int);
		dev_err(&pdev->dev, "fwq Cannot find hall pinctrl hall_eint_as_int!\n");
		return ret;
	}

	pinctrl_select_state(pinctrl1, hall_eint_as_gpio);
	DEBUG("hall_pinctrl-end---------\n");
	return 0;
}

static int hall_probe(struct platform_device *pdev)
{
	int data = 0;
	DEBUG("start hall_probe.\n");
	hall_get_gpio_info(pdev);

	data = gpio_get_value(GPIO_HALL_1_PIN);
	if (data)
		Hall_Gpio_State = 1;
	else
		Hall_Gpio_State = 0;

	disable_irq_nosync(hall_irq);
	INIT_DELAYED_WORK(&eint_work, hall_eint_work);
	//hall_setup_eint();
	hall_irq_registration();
	hall_kpd_init();
	hall_create_dev();
	DEBUG("end of hall_probe.\n");
	return 0;
}

static int hall_remove(struct platform_device *pdev)
{
	DEBUG("hall_remove\n");
	return 0;
}

static int __init hall_init(void)
{
	DEBUG("hall init.\n");
	if (platform_driver_register(&hall_driver))
	{
		DEBUG("platform_driver_registe hall failed!\n");
		return -1;
	}

	return 0;
}
/*----------------------------------------------------------------------------*/
static void __exit hall_exit(void)
{

}
/*----------------------------------------------------------------------------*/
module_init(hall_init);
module_exit(hall_exit);
/*----------------------------------------------------------------------------*/


