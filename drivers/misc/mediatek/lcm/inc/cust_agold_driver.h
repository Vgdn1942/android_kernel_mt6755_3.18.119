#ifndef CUST_AGOLD_DRIVER_H
#define CUST_AGOLD_DRIVER_H

#if defined(AGOLD_HW_COMPATIBLE)
#define AGOLD_LCM_DRV_NUM_MAX 30
#define AGOLD_CAM_DRV_NUM_MAX 30
#define AGOLD_CAM_VER_NUM_MAX 100

typedef struct
{
 char lcm_drv_name[32];
 LCM_DRIVER *func;
}AGOLD_LCM_DRV_LIST;

typedef struct
{
 char camera_drv_name[32];
}AGOLD_CAM_DRV_LIST;

typedef struct
{
 char camera_version[32];
}AGOLD_CAM_VER_LIST;

typedef struct
{
 char lcm_drv_magic_name[16];//magic word AGOLD
 unsigned short main_ver; //main version number,2 bytes
 unsigned short sub_ver;//sub version number,2 bytes
 unsigned int reserver[16]; //reserved 16 bytes
 char lcm_drv_name[32]; //selected lcm name
 AGOLD_LCM_DRV_LIST agold_lcd_drv_lists[AGOLD_LCM_DRV_NUM_MAX] ;//lcm list ended by AGOLD#LCM#DRV
 char camera_drv_magic_name[16];//magic word AGOLD
 char camera_drv_name1[32]; //main camera name
 char camera_drv_name2[32]; //sub camera name
 AGOLD_CAM_DRV_LIST agold_cam_drv_lists[AGOLD_CAM_DRV_NUM_MAX];//cam list started by AGOLD#NCAM#DRV
 char camera_ver_magic_name[16];//magic word AGOLD
 char camera_version[2][32]; //selected camera version
 AGOLD_CAM_VER_LIST agold_cam_ver_lists[AGOLD_CAM_VER_NUM_MAX] ;//cam ver list ended by AGOLD#NCAM#VER
}AGOLD_LCM_DRV_DATA;


AGOLD_LCM_DRV_DATA agold_lcm_drv_data=
{
 "AGOLD$NLCM$DRV",
 0,
 0,
 {0},
	"auto_detect",
	{
		{"auto_detect", 0},	
		{"FL11281", 0},
		{"NT35521_SHM047160B", 0},
		{"SHM047160A", 0},
		{"ILI988IC_S047HAB003_A00", 0},
		{"ILI9881_HSD47", 0},
		{"ILI988IC_J0CPB_AB30_BOE", 0},
		{"AGOLD#NLCM#DRV", 0},
	},
	"AGOLD$NCAM$DRV",
	"auto_detect",
	"auto_detect",
	{
		{"auto_detect"},
		{"imx258_mipi_raw"},
		{"s5k3l8_mipi_raw"},
		{"ov5648_mipi_raw"},
		{"ov13853_mipi_raw"},
		{"ov5670_mipi_raw"},
		{"imx214_mipi_raw"},
		{"hi551_mipi_raw"},
		{"hi553_mipi_raw"},
		{"AGOLD#NCAM#DRV"}
	},
	"AGOLD$CAM$VER",
	{
		{"DEFAULT"},
		{"DEFAULT"}
	},
	{
		{"DEFAULT"},
		{"imx258_mipi_raw+0SYX_0AQH5_v1"},
		{"s5k3l8_mipi_raw+0BLX_50065B_v1"},
		{"s5k3l8_mipi_raw+0JLX_50064_v1"},
		{"s5k3l8_mipi_raw+0SY_50065_v1"},
		{"ov13853_mipi_raw+0SYX_50016A_v1"},
		{"ov5670_mipi_raw+0SYX_M509_v1"},
		{"AGOLD#CAM#VER"}
	}
};

extern LCM_DRIVER FL11281_lcm_drv;
extern LCM_DRIVER NT35521_SHM047160B_lcm_drv;
extern LCM_DRIVER SHM047160A_lcm_drv;
extern LCM_DRIVER ILI988IC_S047HAB003_A00_lcm_drv;
extern LCM_DRIVER ILI9881_HSD47_lcm_drv;
extern LCM_DRIVER ILI988IC_J0CPB_AB30_BOE_lcm_drv;

LCM_DRIVER* lcm_driver_list[] =
{
	&FL11281_lcm_drv,
	&NT35521_SHM047160B_lcm_drv,
	&SHM047160A_lcm_drv,
	&ILI988IC_S047HAB003_A00_lcm_drv,
	&ILI9881_HSD47_lcm_drv,
	&ILI988IC_J0CPB_AB30_BOE_lcm_drv,
};

#endif
#endif

