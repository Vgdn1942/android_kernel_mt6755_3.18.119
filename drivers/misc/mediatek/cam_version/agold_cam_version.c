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

#ifdef CONFIG_OF
#include <linux/of_fdt.h>
#endif
#include <linux/slab.h>

#include "agold_camera_info.h"
#include "agold_cam_version.h"

#define DEBUG_MODE

#ifdef DEBUG_MODE
#define INFO "[agold_cam_version]"
#define DEBUG_LOG(fmt, arg...)        printk("[agold_cam_info]" fmt "\n", ##arg);
#else
#define DEBUG_LOG(fmt, args...)
#endif

int g_bg_ratio[2] = {0, 0};
int g_rg_ratio[2] = {0, 0};
char g_lens_para[2][32] = {"DEFAULT", "DEFAULT"};

typedef struct
{
	char* sensor_name;
	char* lens_name;
} AGOLD_SENSOR_LENS_STRUCT;

const AGOLD_SENSOR_LENS_STRUCT LensList[] =
{
	{"imx179p", "BU6429AF"},
	{"ov5647", "FM50AF"},
	{"ov8825", "OV8825AF"},
	{"s5k3h2", "FM50AF"},
	{"s5k4h5", "FM50AF"},
	{"ov12830", "FM50AF"},
	{"ov13850", "FM50AF"},
	{"ov8850","FM50AF"},
 	{"s5k4e1", "FM50AF"},
	{"ov5648", "FM50AF"},
	{"imx111", "FM50AF"},
#if defined(E2702V82) || defined(E2702V92)
	{"imx135", "BU6424AF"},
#else
	{"imx135", "FM50AF"},
#endif
	{"mt9p017", "MT9P017AF"},
	{"s5k3h7", "FM50AF"},
	{"ov8858", "FM50AF"},
	{"ov8865", "FM50AF"},
	{"hm8030", "FM50AF"},
	{"gc5004", "FM50AF"},
	{"imx179", "BU6424AF"},   //ma chongze
	{"imx219", "FM50AF"},
	{"s5k2p8", "lc898122af"},
	{"imx175", "BU64291AF"},
	{"s5k3m2m", "BU64297AF"},
	{"s5k3m2", "DW9800AF"},
	{NULL, "Dummy"}
};

char agold_main_lens[32];
char agold_sub_lens[32];

#ifdef AGOLD_CAMERA_AUTO_DETECT
extern char agold_main_camera_drv_name[32];
extern char agold_sub_camera_drv_name[32];
#endif

int agold_get_camver_index(int index);
extern void agold_driver_set_camera_driver_name(char* camera_drv_name1,char* camera_drv_name2);
extern void agold_driver_set_camera_version(char* camera_version1,char* camera_version2);

typedef struct
{
	char camera_version[2][32]; //selected camera version
} camera_para;

camera_para agold_cam_version;

void agold_get_version_proc(char version[][32])
{
	char def[] = "DEFAULT";
	char* p;
	int i=0,j=0,ip=0;


	for(i = 0; i < 2; i++)
	{
		p = NULL;
		ip = 0;
		DEBUG_LOG("agold_cam_version.camera_version[%d] = %s\n",i, agold_cam_version.camera_version[i]);
		if(strcmp(agold_cam_version.camera_version[i], def))
		{
			p = strstr(agold_cam_version.camera_version[i], "+");
		}

		DEBUG_LOG("p= %s, p+2 = %s\n",p, p+2);
		if(p)
		{
			ip = (int)*(p+1) - 48;
			sprintf(*(version+i), "%s+0%s", agold_camera_info[i].cam_name, p+2);

			for(j = 0; agold_camera_version_table[j].cam_ver; j++)
			{
				DEBUG_LOG("%s, %s   %s, %s\n",agold_camera_info[i].cam_name, agold_camera_version_table[j].cam_name,p+2, agold_camera_version_table[j].cam_ver);
				if(!strcmp(agold_camera_info[i].cam_name, agold_camera_version_table[j].cam_name) && !strcmp(p+2, agold_camera_version_table[j].cam_ver))
				{
					g_rg_ratio[i] = agold_camera_version_table[j].otp_ratio.RG_Ratio;
					g_bg_ratio[i] = agold_camera_version_table[j].otp_ratio.BG_Ratio;
					sprintf(g_lens_para[i], "%s", agold_camera_version_table[j].cam_lens);
					sprintf(*(version+i), "%s", agold_cam_version.camera_version[i]);
					DEBUG_LOG("get camera[%d] bg=0x%x, rg=0x%x lens=%s otp ver %s\n", i, g_bg_ratio[i], g_rg_ratio[i], g_lens_para[i], *(version+i));
					break;
				}
			}

			DEBUG_LOG("ip=%d magic=%x\n",ip,agold_camera_info[i].otp_magic);
			if(!ip && (agold_camera_info[i].otp_magic&0xf0) && (agold_camera_info[i].otp_magic&0x0f))
			{
				j = agold_get_camver_index(i);
				if(agold_camera_version_table[j].cam_ver)
				{
					g_bg_ratio[i] = agold_camera_version_table[j].otp_ratio.BG_Ratio;
					g_rg_ratio[i] = agold_camera_version_table[j].otp_ratio.RG_Ratio;
					sprintf(g_lens_para[i], "%s", agold_camera_version_table[j].cam_lens);
					sprintf(*(version+i), "%s+0%s", agold_camera_info[i].cam_name, agold_camera_version_table[j].cam_ver);
					DEBUG_LOG("match camera[%d] bg=0x%x, rg=0x%x lens=%s otp ver %s\n", i, g_bg_ratio[i], g_rg_ratio[i], g_lens_para[i], *(version+i));
				}
			}
		}
		else
		{
			j = agold_get_camver_index(i);
			if(agold_camera_version_table[j].cam_ver)
			{
				g_bg_ratio[i] = agold_camera_version_table[j].otp_ratio.BG_Ratio;
				g_rg_ratio[i] = agold_camera_version_table[j].otp_ratio.RG_Ratio;
				sprintf(g_lens_para[i], "%s", agold_camera_version_table[j].cam_lens);
				sprintf(*(version+i), "%s+0%s", agold_camera_info[i].cam_name, agold_camera_version_table[j].cam_ver);
				DEBUG_LOG("match camera[%d] bg=0x%x, rg=0x%x lens=%s otp ver %s\n", i, g_bg_ratio[i], g_rg_ratio[i], g_lens_para[i], *(version+i));
			}
		}

		if(g_bg_ratio[i] == 0 || g_rg_ratio[i] == 0)
		{
			for(j = 0; agold_otp_default_table[j].cam_name; j++)
			{
				if(!strcmp(agold_camera_info[i].cam_name, agold_otp_default_table[j].cam_name))
				{
					g_rg_ratio[i] = agold_otp_default_table[j].otp_ratio.RG_Ratio;
					g_bg_ratio[i] = agold_otp_default_table[j].otp_ratio.BG_Ratio;
					break;
				}
			}
			DEBUG_LOG("reset default bg[%d]=0x%x, rg[%d]=0x%x lens=%s otp ver %s\n", i, g_bg_ratio[i], i, g_rg_ratio[i], g_lens_para[i], *(version+i));
		}
	}
}

void agold_get_cam_soft_info(char* version1, char* version2)
{
	char* p = NULL;

	p = strstr(agold_cam_version.camera_version[0], "+");
	if(p)
	{
		sprintf(version1, "%s", p+1);
	}
	else
	{
		sprintf(version1, "0%s", agold_cam_version.camera_version[0]);
	}

	p = NULL;
	p = strstr(agold_cam_version.camera_version[1], "+");
	if(p)
	{
		sprintf(version2, "%s", p+1);
	}
	else
	{
		sprintf(version2, "0%s", agold_cam_version.camera_version[1]);
	}
}

int agold_get_camver_index(int index)
{
	int vnum = agold_camera_info[index].mf_id<<16 | agold_camera_info[index].lens_id<<8 |agold_camera_info[index].sen_id;
	int i;

	DEBUG_LOG("get ver index:%d mf:%x len:%x sen:%x\n", index, agold_camera_info[index].mf_id, agold_camera_info[index].lens_id, agold_camera_info[index].sen_id);

	for(i = 0; agold_camera_version_table[i].cam_otp; i++)
	{
		if(vnum == agold_camera_version_table[i].cam_otp && !strcmp(agold_camera_info[index].cam_name, agold_camera_version_table[i].cam_name))
			break;
	}
	DEBUG_LOG("get version index %d 0x%06x %s\n", i, vnum, agold_camera_version_table[i].cam_ver);
	return i;
}


ssize_t agold_hw_get_camera_version(struct file *file, char __user *buffer, size_t count, loff_t *ppos)
{
    char *page = NULL;
    char *ptr = NULL;
    int len = 0, err = -1;
	char version[2][32] = {"DEFAULT", "DEFAULT"};

	page = kmalloc(PAGE_SIZE, GFP_KERNEL);
	if (!page)
	{
		kfree(page);
		return -ENOMEM;
	}
	agold_get_version_proc(version);
	DEBUG_LOG("get version %s %s\n", version[0], version[1]);
    ptr = page;
    ptr += sprintf(ptr, "%s,%s", version[0], version[1]);

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

ssize_t agold_hw_get_camera_lens_ver(struct file *file, char __user *buffer, size_t count, loff_t *ppos)
{
    char *page = NULL;
    char *ptr = NULL;
    int len = 0, err = -1;
	char version[2][32] = {"DEFAULT", "DEFAULT"};

	page = kmalloc(PAGE_SIZE, GFP_KERNEL);
	if (!page)
	{
		kfree(page);
		return -ENOMEM;
	}
	agold_get_version_proc(version);
	DEBUG_LOG("get lens %s %s\n", g_lens_para[0], g_lens_para[1]);

    ptr = page;
    ptr += sprintf(ptr, "%s,%s", g_lens_para[0], g_lens_para[1]);

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

#if 0
void agold_set_lens(void)
{
	int i = 0;
	#ifdef AGOLD_CAMERA_AUTO_DETECT
	DEBUG_LOG("agold_main_camera_drv_name=%s, agold_sub_camera_drv_name = %s\n",agold_main_camera_drv_name, agold_sub_camera_drv_name);
	#endif

	while(LensList[i].sensor_name)
	{
		//DEBUG_LOG("LensList[%d].sensor_name=%s, cur_camera_name=%s", i, LensList[i].sensor_name, agold_lcm_drv_data.camera_drv_name1);
		#ifdef AGOLD_CAMERA_AUTO_DETECT
		if(!strncmp(LensList[i].sensor_name, agold_main_camera_drv_name, strlen(LensList[i].sensor_name)))
		#else
		if(!strncmp(LensList[i].sensor_name, agold_lcm_drv_data.camera_drv_name1, strlen(LensList[i].sensor_name)))
		#endif
		{
			break;
		}
		i++;
	}

	strcpy(agold_main_lens, LensList[i].lens_name);
	DEBUG_LOG(" i=%d, agold_main_lens=%s", i, agold_main_lens);

	i = 0;
	while(LensList[i].sensor_name)
	{
		//DEBUG_LOG("LensList[%d].sensor_name=%s, cur_camera_name=%s", i, LensList[i].sensor_name, agold_lcm_drv_data.camera_drv_name2);
		#ifdef AGOLD_CAMERA_AUTO_DETECT
		if(!strncmp(LensList[i].sensor_name, agold_sub_camera_drv_name, strlen(LensList[i].sensor_name)))
		#else
		if(!strncmp(LensList[i].sensor_name, agold_lcm_drv_data.camera_drv_name2, strlen(LensList[i].sensor_name)))
		#endif
		{
			break;
		}
		i++;
	}

	strcpy(agold_sub_lens, LensList[i].lens_name);
	DEBUG_LOG("i=%d, agold_sub_lens=%s", i, agold_sub_lens);

	return;
}
#endif

ssize_t agold_get_camera_index(struct file *file, char __user *buffer, size_t count, loff_t *ppos)
{
    char *page = NULL;
    char *ptr = NULL;
    int len = 0, err = -1;

	page = kmalloc(PAGE_SIZE, GFP_KERNEL);
	if (!page)
	{
		kfree(page);
		return -ENOMEM;
	}
    ptr = page;
    ptr += sprintf(ptr, "%d", g_cur_cam_sensor);

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


int agold_get_lens_index(char* lens_name)
{
	int lens_index = 0;
	if(!strcmp(lens_name, agold_main_lens))
	{
		lens_index |= 1;
	}
#if defined(AGOLD_SUB_AF)
	if(!strcmp(lens_name, agold_sub_lens))
	{
		lens_index |= 2;
	}
#endif

	DEBUG_LOG("lens_index = %d", lens_index);

	return lens_index;
}

static struct file_operations fcamera_version_fops = {

	.read = agold_hw_get_camera_version,
	.write = NULL
};

static  struct file_operations fcamera_lens_fops = {
    .read = agold_hw_get_camera_lens,
    .write = NULL,
};
static  struct file_operations fcamera_af_fops = {
    .read = agold_hw_get_camera_lens_ver,
    .write = NULL,
};

static  struct file_operations fcamera_index_fops = {
    .read = agold_get_camera_index,
    .write = NULL,
};

//[agold][xfl][20151102]
#if defined(AGOLD_LENS_AUTO_DETECT)
ssize_t agold_get_camera_lens_driver(struct file *file, char __user *buffer, size_t count, loff_t *ppos)
{
	char *page = NULL;
    char *ptr = NULL;
    int len = 0;
	int err = -1;
	char lens_deriver_name[16]={0};
	unsigned int sensor_id = 0;
	err = agold_get_lens_driver(lens_deriver_name, &sensor_id);
	if (-1 == err)
	{
		return err;
	}
	DEBUG_LOG("[xfl]lens_deriver_name:%s, sensor_id:%d\n", lens_deriver_name, sensor_id);
	page = kmalloc(PAGE_SIZE, GFP_KERNEL);
	if (!page)
	{
		kfree(page);
		return -ENOMEM;
	}
	ptr = page;
	ptr += sprintf(ptr, "%s,%d", lens_deriver_name, sensor_id);
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

static  struct file_operations fcamera_lens_driver = {
    .read = agold_get_camera_lens_driver,
    .write = NULL,
};
#endif

static int __init agold_cam_version_init(void)
{
	agold_driver_set_camera_version(agold_cam_version.camera_version[0],agold_cam_version.camera_version[1]);

	proc_create("driver/camera_index", 0, NULL, &fcamera_index_fops);
	proc_create("driver/camera_version", 0, NULL, &fcamera_version_fops);
	proc_create("driver/camera_lens", 0, NULL, &fcamera_lens_fops);
    proc_create("driver/camera_af", 0, NULL, &fcamera_af_fops);
	//[agold][xfl][20151102]
	#if defined(AGOLD_LENS_AUTO_DETECT)
	proc_create("driver/camera_lens_driver", 0, NULL, &fcamera_lens_driver);
	#endif
	return 0;
}

static void __exit agold_cam_version_exit(void)
{

	return;
}

module_init(agold_cam_version_init);
module_exit(agold_cam_version_exit);

MODULE_DESCRIPTION("agold cam version driver");
MODULE_AUTHOR("shipeilong@agoldcomm.com");
MODULE_LICENSE("GPL");
