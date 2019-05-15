#if !defined(AGOLD_CAMERA_INFO_H)
#define AGOLD_CAMERA_INFO_H
#include <linux/proc_fs.h>  //proc file use
#include <asm/io.h>
#include <linux/spinlock.h>
#include <linux/interrupt.h>
#include <linux/types.h>
#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/delay.h>
#include <asm/uaccess.h>  
#include <linux/slab.h>

#define AGOLD_CAMVER_DEBUG
#if defined(AGOLD_CAMVER_DEBUG)
#define CAMVER_DEBUG(fmt, arg...) printk("[agold_cam_info]" fmt "\n", ##arg);
#endif

#define AGOLD_CAMVER_INFO
#if defined(AGOLD_CAMVER_INFO)
#define CAMVER_INFO(fmt, arg...) printk("[agold_cam_info]" fmt "\n", ##arg);
#define CAMVER_ERR(fmt, arg...) printk("[agold_cam_info]" fmt, ##arg);
#endif


typedef struct
{
	char cam_name[32];
	char version[32];
	int mf_id;
	char mf_name[32];
	int lens_id;
	char lens_name[32];
	int date[3];
	int sen_id;
	int otp_magic;
} AGOLD_CAMERA_INFO_STRUCT;

//[agold][xfl][20151102]
#if defined(AGOLD_LENS_AUTO_DETECT)
typedef struct
{
	char cam_name[32];
	unsigned int sensor_id;
	char lens_driver_name[32];
	int otp_mf_id;
	int otp_lens_id;
} AGOLD_CAMERA_LENS_TABLE_STRUCT;
#endif

typedef struct
{
	int mf_id;
	char mf_name[32];
} AGOLD_CAMERA_M_STRUCT;

typedef struct
{
	int lens_id;
	char lens_name[32];
} AGOLD_CAMERA_L_STRUCT;

typedef struct
{
	char* cam_name;
	AGOLD_CAMERA_M_STRUCT* mf_list;
	AGOLD_CAMERA_L_STRUCT* lens_list;
} AGOLD_CAMERA_LIST_STRUCT;

typedef struct
{
	int RG_Ratio;
	int BG_Ratio;
} AGOLD_OTP_RATIO_STRUCT;

typedef struct
{
	char *cam_name;
	int cam_otp;
	char *cam_ver;
	AGOLD_OTP_RATIO_STRUCT otp_ratio;
	char *cam_lens;
} AGOLD_CAMERA_TABLE_STRUCT;

typedef struct
{
	char* cam_name;
	AGOLD_OTP_RATIO_STRUCT otp_ratio;
} AGOLD_OTP_DEFAULT_RATIO_STRUCT;

extern int cur_bg_ratio;
extern int cur_rg_ratio;
extern int g_bg_ratio[];
extern int g_rg_ratio[];
extern char g_lens_para[][32];
extern int g_cur_cam_sensor;
extern AGOLD_CAMERA_TABLE_STRUCT agold_camera_version_table[];
extern AGOLD_CAMERA_INFO_STRUCT agold_camera_info[2];
extern AGOLD_OTP_DEFAULT_RATIO_STRUCT  agold_otp_default_table[];

extern int agold_hw_camera_get_version(struct file *file, char *buffer, size_t count, loff_t *ppos);
extern void agold_get_version_proc(char version[][32]);
ssize_t agold_hw_get_camera_lens_ver(struct file *file, char __user *buffer, size_t count, loff_t *ppos);

//[agold][xfl][20151102]
#if defined(AGOLD_LENS_AUTO_DETECT)
extern int agold_get_lens_driver(char *name, int *index);
extern AGOLD_CAMERA_LENS_TABLE_STRUCT agold_camera_lens_table[];
#endif
ssize_t agold_hw_get_camera_lens(struct file *file, char __user *buffer, size_t count, loff_t *ppos);
void agold_get_rbg_ratio(int index);
int agold_get_bg_ratio(int index);
int agold_get_rg_ratio(int index);

#endif
