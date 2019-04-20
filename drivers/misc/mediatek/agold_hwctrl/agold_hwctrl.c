/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 */
/* MediaTek Inc. (C) 2010. All rights reserved.
 *
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 * RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER ON
 * AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
 * NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
 * SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
 * SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES TO LOOK ONLY TO SUCH
 * THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES
 * THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES
 * CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK
 * SOFTWARE RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND
 * CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
 * AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
 * OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
 * MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 * The following software/firmware and/or related documentation ("MediaTek Software")
 * have been modified by MediaTek Inc. All revisions are subject to any receiver's
 * applicable license agreements with MediaTek Inc.
 */

#include <linux/i2c.h>
#include <linux/sched.h>
#include <linux/kthread.h>
#include <linux/wait.h>
#include <linux/delay.h>
#include <mach/mt_gpio.h>
//#include <mach/mt_devs.h>
#include <mach/mt_typedefs.h>

#include <linux/interrupt.h>
#include <linux/time.h>
#include <mach/mt_boot.h>

#include <cust_eint.h>
#include <linux/rtpm_prio.h>
#include <linux/miscdevice.h>
#include <asm/uaccess.h>
#include <linux/dma-mapping.h>

#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/platform_device.h>

#ifdef CONFIG_OF
#include <linux/of_fdt.h>
#endif

#include "agold_hwctrl.h"


#ifdef AGOLD_HWCTRL_ENABLE


#define HWCTRL_TAG                  "[agold/hwctrl] "
#define HWCTRL_FUN(f)               printk("%s\n", __FUNCTION__)
#define HWCTRL_ERR printk
#define HWCTRL_LOG  printk

#define AGOLD_DEVNAME "AGOLD_DRIVER"

extern void agoldSettingSerialNumber(char *name);

extern void agoldModifiedVibratorFeel(int vibVol, int vibTime);

extern void agoldModifiedButtonLedValue(int value);


static struct class *hwctrl_class = NULL;
static int hwctrl_major = 0;
static dev_t hwctrl_devno;
static struct cdev *hwctrl_cdev;
//agold wlg start change ram 20130911
//extern void agoldSetTotalAndFree(int total,int free,int cached);
//end


struct ctrlInfoStruct
{
	char serialName[32];
    int vibratorVol;
	int vibratorTime;
	int ledValue;
};

static int hwctrl_open(struct inode *inode, struct file *file)
{
    printk("liulou hwctrl_open\n");
	HWCTRL_FUN();

	return nonseekable_open(inode, file);

}

static int hwctrl_release(struct inode *inode, struct file *file)
{
	HWCTRL_FUN();

	file->private_data = NULL;
	return 0;
}

#ifdef CONFIG_COMPAT
static long hwctrl_compat_ioctl(struct file *file, unsigned int cmd,
       unsigned long arg)
{
    long err = 0;

	void __user *arg32 = compat_ptr(arg);
	
	if (!file->f_op || !file->f_op->unlocked_ioctl)
		return -ENOTTY;
	
    if (arg32 == NULL)
    {
        err = -EINVAL;
        return err;  
    }

    err = file->f_op->unlocked_ioctl(file, cmd, arg32);
    if (err){
        printk("hwctrl_ioctl unlocked_ioctl failed.");
        return err;
    }

    return err;
}
#endif


static int hwctrl_ioctl(struct file *file, unsigned int cmd,
       unsigned long arg)
{
	int err = 0;
	void __user *ptr = (void __user*) arg;

	struct ctrlInfoStruct ctrlInfo;
        AGOLD_CHANGE_RAM changeRam;
    printk("liulou hwctrl_ioctl\n");
	HWCTRL_LOG("%s(cmd=%d)", __FUNCTION__,cmd);

	switch (cmd)
	{
		case HWCTRL_MODIFIED_VALUE:
			printk("----------agold-----00000---\n");
			if(copy_from_user(&ctrlInfo, ptr, sizeof(struct ctrlInfoStruct)))
			{
				printk("----------agold-----11111---\n");
				err = -EFAULT;
				goto err_out;
			}
			//agoldSettingSerialNumber(ctrlInfo.serialName);
			agoldModifiedVibratorFeel(ctrlInfo.vibratorVol, ctrlInfo.vibratorTime);
			agoldModifiedButtonLedValue(ctrlInfo.ledValue);

			printk("-----fengjun----ctrlInfo.vibratorVol=%d, ctrlInfo.vibratorTime=%d\n", ctrlInfo.vibratorVol, ctrlInfo.vibratorTime);

			printk("serialNumberName.infoName=%s\n", ctrlInfo.serialName);

			break;

                 //agold wlg change ram wlg 20130911
                 case RAMCTRL_MODIFIED_VALUE:
                        printk("----- agold-------ram change value\n");
                        if(copy_from_user(&changeRam, ptr, sizeof(AGOLD_CHANGE_RAM)))
                        {
                                printk("-------------agold change value error");
                                err = -EFAULT;
                                goto err_out; 
                        }

                        //agoldSetTotalAndFree(changeRam.total,changeRam.free,changeRam.cached);                     

                        break;    
                  //end
         //agold liulou add         
        case SIMLOAD_MODIFIED_VALUE:
            printk("%s liulou SIMLOAD_MODIFIED_VALUE = 0x%04x", __FUNCTION__, cmd);

			HWCTRL_ERR("%s liulou SIMLOAD_MODIFIED_VALUE = 0x%04x", __FUNCTION__, cmd);
			extern void changeSimLoadState();
            changeSimLoadState();
        
            break;
         //liulou end
		default:
			printk("%s not supported = 0x%04x", __FUNCTION__, cmd);

			HWCTRL_ERR("%s not supported = 0x%04x", __FUNCTION__, cmd);
			err = -ENOIOCTLCMD;
			break;
	}

	err_out:
	return err;    
}

static struct file_operations hwctrl_fops = {
	.owner = THIS_MODULE,
	.open = hwctrl_open,
	.release = hwctrl_release,
	.unlocked_ioctl = hwctrl_ioctl,
	#ifdef CONFIG_COMPAT
	.compat_ioctl = hwctrl_compat_ioctl,
	#endif
};

/* 
 * Register platform driver
 */
static int hwctrl_probe(struct platform_device *dev)
{ 
	HWCTRL_FUN();

	return 0;
}

static int hwctrl_remove(struct platform_device *dev)
{
	HWCTRL_FUN();
	return 0;
}

static void hwctrl_shutdown(struct platform_device *dev)
{
	HWCTRL_FUN();
}

static int hwctrl_suspend(struct platform_device *dev, pm_message_t state)
{    
	HWCTRL_FUN();
	return 0;
}

static int hwctrl_resume(struct platform_device *dev)
{   
	HWCTRL_FUN();
	return 0;
}

static struct platform_driver hwctrl_driver = {
	.probe       = hwctrl_probe,
	.remove      = hwctrl_remove,
	.shutdown    = hwctrl_shutdown,
	.suspend     = hwctrl_suspend,
	.resume      = hwctrl_resume,
	.driver      = {
	.name        = AGOLD_DEVNAME,
	},
};

static struct platform_device agold_device = {
	.name     = AGOLD_DEVNAME,
	.id       = 0,
};

static int __init agold_drv_init(void)
{
	struct class_device *class_dev = NULL;
	int err=0;
	int ret=0;
	struct proc_dir_entry *prEntry;

	HWCTRL_FUN();

        /*create ioctrl*/
	ret = alloc_chrdev_region(&hwctrl_devno, 0, 1, AGOLD_DEVNAME);
	if (ret) 
	{
		HWCTRL_ERR("Can't Get Major number for agold hwctrl \n");
		return ret;
	}

	hwctrl_cdev = cdev_alloc();
	hwctrl_cdev->owner = THIS_MODULE;
	hwctrl_cdev->ops = &hwctrl_fops;
	ret = cdev_add(hwctrl_cdev, hwctrl_devno, 1);

	if(ret)
	{
		HWCTRL_ERR("matv Error: cdev_add\n");
		return ret;
	}

	hwctrl_major = MAJOR(hwctrl_devno);
	hwctrl_class = class_create(THIS_MODULE, AGOLD_DEVNAME);
	class_dev = (struct class_device *)device_create(hwctrl_class, 
							NULL, 
							hwctrl_devno, 
							NULL, 
							AGOLD_DEVNAME);

/*
	if (platform_device_register(&agold_device)){
		HWCTRL_ERR("fail to register device\n");
		ret = -ENODEV;
		return ret;
	}
*/

	if (platform_driver_register(&hwctrl_driver)){
		HWCTRL_ERR("fail to register driver\n");
		//platform_device_unregister(&agold_device);
		ret = -ENODEV;
		return ret;
	}

	return 0;

}
   
static void __exit agold_drv_exit(void)
{
	HWCTRL_FUN();

	platform_driver_unregister(&hwctrl_driver);
	platform_device_unregister(&agold_device);    
	
	return;
}

/*----------------------------------------------------------------------------*/
module_init(agold_drv_init);
module_exit(agold_drv_exit);
/*----------------------------------------------------------------------------*/
MODULE_AUTHOR("agold xxd");
MODULE_DESCRIPTION("agold hwctrl driver");
MODULE_LICENSE("GPL");
#endif
