#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/spinlock.h>
#include <linux/suspend.h>
#include <linux/console.h>
#include <mt-plat/aee.h>
#include <linux/proc_fs.h>
#include <linux/fs.h>
#include <linux/vmalloc.h>
#include <linux/uaccess.h>
#include <linux/wakelock.h>
#include <linux/time.h>
#include <linux/kthread.h>

#ifdef CONFIG_OF
#include <linux/of_fdt.h>
#endif


struct tag_agold_hw_info {
	//lcm drv
	char lcm_drv_name[32];
	//camera
	char camera_drv_name1[32];
	char camera_drv_name2[32];
#if defined(CONFIG_MTK_CAMERA_VERSION)
	char camera_version[2][32];
#endif
};

extern void agold_get_driver(void);

struct tag_agold_hw_info g_agold_hw_info =
{
	//lcm
	"", //lcm_driver_index
	//camera
	"",//camera_driver_index
	"",//sub_camera_driver_index
#if defined(CONFIG_MTK_CAMERA_VERSION)
	{{""},//main_camera_version
	{""}},//sub_camera_version
#endif
};

void agold_driver_set_lcm_driver_name(char* lcm_drv_name)
{
	strcpy(lcm_drv_name,g_agold_hw_info.lcm_drv_name);
}
void agold_driver_set_camera_driver_name(char *camera_drv_name1,char *camera_drv_name2)
{
	strcpy(camera_drv_name1,g_agold_hw_info.camera_drv_name1);
	strcpy(camera_drv_name2,g_agold_hw_info.camera_drv_name2);
}

long agold_strtol(char *str)
{
	if(strstr(str,"0x") || strstr(str,"0X"))
	{
		return simple_strtol(str+2, NULL, 16);
	}
	else
	{
		return simple_strtol(str, NULL, 10);
	}
}
EXPORT_SYMBOL_GPL(agold_strtol);

#if defined(CONFIG_MTK_CAMERA_VERSION)
void agold_driver_set_camera_version(char *camera_version1,char *camera_version2)
{
	strcpy(camera_version1,g_agold_hw_info.camera_version[0]);
	strcpy(camera_version2,g_agold_hw_info.camera_version[1]);
}
#endif

static int __init agold_hw_compatible(unsigned long node, const char* uname, int depth, void* data)
{
	struct tag_agold_hw_info *agold_hw_info;
	if (depth != 1 || (strcmp(uname, "chosen") != 0 && strcmp(uname, "chosen@0") != 0))
		return 0;

	agold_hw_info = (struct tag_agold_hw_info *)of_get_flat_dt_prop(node, "atag,agold_hw",NULL);
	if(agold_hw_info)
	{
		memcpy(&g_agold_hw_info, agold_hw_info, sizeof(g_agold_hw_info));
		printk("[kernel][%s][lcm:%s][camera:%s,%s]\n",
		__func__,
		g_agold_hw_info.lcm_drv_name,
		g_agold_hw_info.camera_drv_name1,
		g_agold_hw_info.camera_drv_name2);
	}
	agold_get_driver();
	return 1;
}

static int __init agold_hw_compatible_init(void)
{
	of_scan_flat_dt(agold_hw_compatible, NULL);
	return 0;
}

static void __exit agold_hw_compatible_exit(void)
{
	return;
}
#ifdef CONFIG_OF
early_initcall(agold_hw_compatible_init);
#endif
//module_exit(agold_hw_compatible_exit);

MODULE_LICENSE("GPL");

