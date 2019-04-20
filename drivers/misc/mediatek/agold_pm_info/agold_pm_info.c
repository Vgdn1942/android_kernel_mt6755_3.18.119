
/*
*创建 agold_lcmcam_info 文件，用于获取TP、LCM 和 CAM 的型号
*Author:Fengjun
*Time:2013.01.25
*/
#ifdef AGOLD_HARDWARE_INFO

#include <asm/io.h>
#include <linux/spinlock.h>
#include <linux/interrupt.h>
#include <linux/types.h>
#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/delay.h>
//#include <linux/xlog.h>

#include <asm/uaccess.h>
    
//#include <mach/mt_typedefs.h>
#include <linux/slab.h>



extern void agold_get_driver(void);
extern char* agold_driver_get_camera_string(void);
extern char* agold_driver_get_sub_camera_string(void);
extern char* agold_driver_get_lcm_string(void);

extern char* agold_driver_get_tp_string(void);
extern int agold_driver_tpd_get_fw_ver(void);

#if defined(AGOLD_FACTORY_TEST_CONFIG)
static ssize_t agold_factory_test_item_read(struct file *file, char *buffer, size_t count, loff_t *ppos);
extern char* agold_get_factory_test_item_list(void);
#endif

//static struct proc_dir_entry *entry = NULL;

ssize_t agold_hardware_info_read(struct file *file, char __user *buffer, size_t count, loff_t *ppos)
{
	char *page = NULL;
    char *ptr = NULL;
    int len, err = -1;

	page = kmalloc(PAGE_SIZE, GFP_KERNEL);	
	if (!page) 
	{		
		kfree(page);		
		return -ENOMEM;	
	}

    ptr = page; 
    ptr += sprintf(ptr, "Camera Main:%s, Sub:%s \n", agold_driver_get_camera_string(), agold_driver_get_sub_camera_string());
	ptr += sprintf(ptr, "Lcm: %s\n", agold_driver_get_lcm_string());
	len = ptr - page; 			 	
	if(*ppos >= len)
	{		
		kfree(page); 		
		return 0; 	
	}	
	err = copy_to_user(buffer,(char *)page,len); 			
	*ppos += len; 	
	if(err) 
	{		
	    kfree(page); 		
		return err; 	
	}	
	kfree(page); 	
	return len;	
}

static const struct file_operations lcmcam_info_proc_fops = {
	.read = agold_hardware_info_read,
};

static void create_lcmcam_info(void)
{
	proc_create("agold_lcmcam_info", 0644, NULL,&lcmcam_info_proc_fops);
}

static ssize_t agold_tpd_info_read(struct file *file, char __user *buffer, size_t count, loff_t *ppos)
{
    char *page = NULL;
    char *ptr = NULL;
    int len, err = -1;

	page = kmalloc(PAGE_SIZE, GFP_KERNEL);	
	if (!page) 
	{		
		kfree(page);		
		return -ENOMEM;	
	}

    ptr = page; 
    ptr += sprintf(ptr, "%s\n", agold_driver_get_tp_string());
    ptr += sprintf(ptr, ", VER:0x%x\n",agold_driver_tpd_get_fw_ver());

	len = ptr - page; 			 	
	if(*ppos >= len)
	{		
		kfree(page); 		
		return 0; 	
	}	
	
	err = copy_to_user(buffer,(char *)page,len); 			
	*ppos += len; 	
	if(err) 
	{		
	    kfree(page); 		
		return err; 	
	}	
	kfree(page); 	
	
	return len;	
}
#if defined(AGOLD_FACTORY_TEST_CONFIG)
static const struct file_operations agold_factory_proc_fops = {
	.read = agold_factory_test_item_read,
};

static ssize_t agold_factory_test_item_read(struct file *file, char __user *buffer, size_t count, loff_t *ppos)
{
	char *page = NULL;
    char *ptr = NULL;
    int len = 0;
	int err = -1;

	page = kmalloc(PAGE_SIZE, GFP_KERNEL);	
	if (!page) 
	{		
		kfree(page);		
		return -ENOMEM;	
	}

    ptr = page; 
    ptr += sprintf(ptr, "%s\n", agold_get_factory_test_item_list());

	len = ptr - page; 			 	
	if(*ppos >= len)
	{		
		kfree(page); 		
		return 0; 	
	}	
	
	err = copy_to_user(buffer,(char *)page,len); 			
	*ppos += len; 	
	if(err) 
	{		
	    kfree(page); 		
		return err; 	
	}	
	kfree(page); 	
	
	return len;	
}
static void create_agold_factory_test_item(void)
{
   	proc_create("agold_factory_test_item", 0644, NULL,&agold_factory_proc_fops);
}
#endif
static const struct file_operations agold_tpd_info_proc_fops = {
	.read = agold_tpd_info_read,
};

static void create_touchpanel_info(void)
{
	proc_create("agold_tpd_info", 0644, NULL,&agold_tpd_info_proc_fops);	
}

static int __init Agold_pm_info_init(void)
{
	create_lcmcam_info();

	create_touchpanel_info();
#if defined(AGOLD_FACTORY_TEST_CONFIG)
	create_agold_factory_test_item();
#endif
	return 0;
}

static void __exit Agold_pm_info_exit(void)
{
	return;
}

module_init(Agold_pm_info_init)
module_exit(Agold_pm_info_exit)
MODULE_DESCRIPTION("Agold_pm_info");
MODULE_AUTHOR("xxx@agoldcomm.com");
MODULE_LICENSE("GPL");
#endif
