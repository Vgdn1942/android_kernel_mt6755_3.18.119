#include "agold_camera_info.h"
#include "kd_imgsensor.h"

#ifdef DEBUG_MODE
#define INFO "[agold_cam_info]"
#define DEBUG_LOG(fmt, arg...)         printk(INFO, fmt, ##arg)
#else
#define DEBUG_LOG(fmt, args...)
#endif

extern int sprintf(char * buf, const char * fmt, ...);
extern void agold_get_cam_soft_info(char* version1, char* version2);

//[agold][xfl][20151102]
#if defined(AGOLD_LENS_AUTO_DETECT)
AGOLD_CAMERA_LENS_TABLE_STRUCT agold_camera_lens_table[] =
{
	//cam_name,sensor_id,lens_id,lens_driver_name,otp_mf_id,otp_lens_id
	{"imx214_mipi_raw",  IMX214_SENSOR_ID,  "DW9714AF", 0x07, 0x01},  //xhgt s12
	{"imx214_mipi_raw",  IMX214_SENSOR_ID,  "DW9714AF", 0x08, 0x01}, //lemu s12
	{"imx258_mipi_raw",  IMX258_SENSOR_ID,  "DW9714AF", 0x02, 0x00},
	{"imx258_mipi_raw",  IMX258_SENSOR_ID,  "DW9714AF", 0x02, 0xf9},
	{"imx258_mipi_raw",  IMX258_SENSOR_ID,  "DW9763AF", 0x52, 0x12},
	{"ov13850_mipi_raw",  OV13850_SENSOR_ID,  "DW9714AF", 0xfc, 0xfd},//TSC
	{"ov13850_mipi_raw",  OV13850_SENSOR_ID,  "DW9714AF", 0xec, 0xf7},//lemu s12
	{"ov13853_mipi_raw",  OV13850_SENSOR_ID,  "DW9763AF", 0x12, 0x01},//Jk s12
	{"s5k3l8_mipi_raw",   S5K3L8_SENSOR_ID,  "DW9714AF", 0x01, 0x01},//kw c239v55
	{"s5k3l8_mipi_raw",   S5K3L8_SENSOR_ID,  "DW9763XAF", 0x52, 0x12},//kw c239v55
	{"s5k3l8_mipi_raw",   S5K3L8_SENSOR_ID,  "DW9763AF", 0x01, 0x06},//jk s12v55
	{"s5k3l8_mipi_raw",   S5K3L8_SENSOR_ID,  "DW9763AF", 0x49, 0x06},//jk s12v55
	{"s5k3l8_mipi_raw",   S5K3L8_SENSOR_ID,  "DW9763AF", 0x12, 0x33},//yh s16v55c2k
};
#endif

AGOLD_CAMERA_TABLE_STRUCT agold_camera_version_table[] =
{
	{"imx135_mipi_raw",0xffffff,"YL_GS8811_v1",{0xff,0xff},"dw9714af_v12"},   //fm
    {"imx214_mipi_raw",0xee0801,"KE_50021A_v1",{0x231,0x262},"dw9714af_v4"},   //lemu s12
    {"imx214_mipi_raw",0xed0701,"BK_40100A_v0",{0x13A,0x128},"dw9714af_v5"},//xhgt_bk s12v55c2k
    {"imx214_mipi_raw",0xed0700,"ZL_40100A_v0",{0x13A,0x128},"dw9714af_v14"},//xhgt_zlkj s12v55c2k
	{"imx214_mipi_raw",0xf00402,"HZWY_40100_v4",{0x13C,0x130},"dw9714af_v12"},//xhgt_hzwy s12v55c2k
	{"imx214_mipi_raw",0xffffff,"HZWY_40100_v4",{0x13C,0x130},"dw9714af_v12"},//xhgt_hzwy s12v55c2k
	{"imx214_mipi_raw",0xf00701,"HZ_40100A_v1",{0x269,0x275},"dw9714af_v6"},   //xjd s12
	{"imx214_mipi_raw",0xfc0200,"TSC_F4512A_v1",{0x11d,0x141},"dw9714af_v7"},//xjd s12
	{"imx214_mipi_raw",0xffffff,"ZRT_50013A_v1",{0xff,0xff},"dw9714af_v11"},//fm s12
	{"imx219_mipi_raw",0xfc0200,"TSC_9569A6_v1",{0xff,0xff},"null"},//xjd s12
    {"imx258_mipi_raw",0x020000,"XL_4033_v0",{0xff,0xff},"dw9714af_v1"},
    {"imx230_mipi_raw",0x020103,"XL_9625A5_v1",{0xff,0xff},"dw9800af_v2"},  //kewei c239v55_kw_h9
    {"imx230_mipi_raw",0x010103,"SY_9625A1_v1",{0xff,0xff},"dw9800af_v3"},  //jy c239
    {"imx258_mipi_raw",0x02f900,"XL_4033_v0",{0xff,0xff},"dw9714af_v1"},
    {"imx298_mipi_raw",0x020101,"XL_9563A6_v1",{0xff,0xff},"dw9800af_v1"},  //dfl_XL_G3 g3v55cmcc
	{"imx258_mipi_raw",0x521200,"SYX_0AQH5_v1",{0x241,0x2d5},"dw9763af_v2"}, //jk s12v55
	{"s5k3l8_mipi_raw",0x521200,"JLX_50064_v1",{0xff,0xff},"dw9736xaf_v1"},  //jk s12v55
	{"s5k3l8_mipi_raw",0x010101,"SY_U5BM13_v1",{0x21d,0x210},"dw9714af_v8"},	//kw U3
	{"s5k3l8_mipi_raw",0x010605,"SY_50065_v1",{0x227,0x21F},"dw9763af_v3"},  //jk s12v55
    {"ov8856_mipi_raw",0x020100,"XL_DIF4174_v1",{0x140,0x132},"null"},      //dfl_XL_G3 g3v55cmcc
    {"imx219_mipi_raw",0xffffff,"ZK_TK468_v1",{0xff,0xff},"null"},
    {"mn34152_mipi_raw",0xffffff,"ZK_500166_v00",{0xff,0xff},"dw9714af_v2"},
	{"ov8858_mipi_raw",0x020000,"XL_CMB046_v1",{0xff,0xff},"null"},
    {"ov8858_mipi_raw",0x02fb00,"XL_CMB046_v1",{0xff,0xff},"null"},
	//{"ov13850_mipi_raw",0xfcfd7f,"TSC_50064_v1",{0xff,0xff},"null"},
	{"ov13850_mipi_raw",0xfcfd00,"TSC_50064_v1",{0x119,0x130},"null"},
	{"ov13850_mipi_raw",0xfcfde2,"TSC_50064_v1",{0x119,0x130},"null"},
	{"ov13850_mipi_raw",0x0c5000,"YH_1111_v1",{0xff,0xff},"dw9714af_v9"}, //s16v55c2k yh 
    {"ov13850_mipi_raw",0x0caf00,"YH_1111_v2",{0xff,0xff},"dw9714af_v9"}, //s16v55c2k yh-2
	{"ov13850_mipi_raw",0xecf701,"JCX_50021A_v1",{0xff,0xff},"dw9714af_v3"},     //lemu s12v55c2k 
	{"ov13853_mipi_raw",0x521201,"SYX_50016A_v1",{0x16a,0x189},"dw9763af_v1"},     //Jk s12v55
	
	{"ov5648_mipi_raw",0x7cfd00,"TSC_HY517_v1",{0x159,0x13f},"null"},
	{"ov5648_mipi_raw",0x7cfd81,"TSC_HY517_v1",{0x159,0x13f},"null"},
	{"ov5648_mipi_raw",0x0dfb02,"KMJ_40093A1_v1",{0xff,0xff},"null"},     //lemu s12
	
	{"s5k3p3sx_mipi_raw",0x230201,"NB_50016_v1",{0xff,0xff},"dw9714af_v10"},     //JS s12v55c2k_j9s_f

	{"gc5024_mipi_raw",0xed0201,"SBT_DL520_v1",{0xff,0xff},"null"},   //ysf s12v55c2k
	{"ov13850_mipi_raw",0xedfc02,"SBT_9595A1_v1",{0x125,0x131},"dw9714af_v13"},     //ysf s12v55c2k
	{"ov5695_mipi_raw",0xffffff,"BLX_40145A1_v1",{0xff,0xff},"null"},  //jk s12v55
	{"gc5025_mipi_raw",0xffffff,"YD_535A_v1",{0xff,0xff},"null"},  //xhgt s12v55c2k
	{"s5k3l8_mipi_raw",0x490603,"BLX_50065B_v1",{0x259,0x261},"dw9763af_v4"},  //jk s12v55
	//{"s5k3l8_mipi_raw",0x0c2100,"SLS_50016_v1",{0x120,0xfa},"dw9763af_v5"},  //yh s16v55c2k
	{NULL, 0, NULL, {0, 0}, "DEFAULT"},
};


AGOLD_OTP_DEFAULT_RATIO_STRUCT  agold_otp_default_table[] = 
{
	{SENSOR_DRVNAME_OV8825_MIPI_RAW, {0x56, 0x57}},
	{SENSOR_DRVNAME_OV8865_MIPI_RAW, {0x13f, 0x120}},
	{SENSOR_DRVNAME_IMX135_MIPI_RAW, {0x260, 0x252}},
    {SENSOR_DRVNAME_OV8858_MIPI_RAW, {0x13C, 0x12C}},
	{SENSOR_DRVNAME_S5K3M2_MIPI_RAW, {0x22d, 0x332}},
	{NULL, {0, 0}},
};

AGOLD_CAMERA_M_STRUCT mf_list_ov[] =
{
	{0x01, "Sunny"},		//舜宇
	{0x02, "Truly"},
	{0x03, "A-kerr"},
	{0x04, "LieArray"},
	{0x05, "Darling"},		//大凌
	{0x06, "Qtech"},
	{0x07, "OFlim"},		//欧菲光
	{0x08, "Kingcom"},
	{0x09, "Booyi"},
	{0x0a, "Laimu"},		//莱木
	{0x0b, "WDSEN"},		//华德森
	{0x0c, "Sunrise"},		//晨兴
	{0x0d, "CameraKing"},	//凯木金
	{0x0e, "Sunniness"},
	{0x0f, "Tongju"},
	{0x10, "Seasons"},
	{0x11, "Foxconn"},
	{0x12, "Importek"},
	{0x13, "Altek"},
	{0x14, "Ability"},
	{0x15, "Lite-on"},
	{0x16, "Chicony"},
	{0x17, "Primax"},
	{0x21, "Sharp"},
	{0x31, "MCNEX"},
	{0x32, "SEMCO"},
	{0x33, "Partron"},
	{0x41, "Reach"},		//众联成
	{0x42, "BYD"},
	{0x44, "Chippack"},     //昌硕
	{0x45, "Jiali"},        //佳立
	{0x46, "Chippack"},
	{0x47, "RongSheng"},
	{0x48, "ShenTai"},
	{0x49, "Brodsands"},
	{0x51, "Method"},
    {0x52, "Sunwin"}, 	     
	{0x7c, "TSC"},          //天时创
	{0xfc, "TSC"},
	{0x00, "Unknown"},
};

AGOLD_CAMERA_L_STRUCT lens_list_ov8825[] =
{
	{0x01, "Largan 9486"},
	{0x02, "Largan 40016"},
	{0x03, "Kantasu G5AE"},
	{0x04, "Largan 40028"},
	{0x05, "Largan 40019"},
	{0x06, "Largan 9547A1"},
	{0x07, "Largan 9486B"},
	{0x08, "Sunny 3807"},
	{0x09, "Konica A54D"},
	{0x0a, "Kantatsu W5AR"},
	{0x0b, "Kantatsu G5AG08"},
	{0x0c, "Copal KV4026"},
	{0x0d, "Largan 9555"},
	{0x0e, "Largan 9566A1"},
	{0x0f, "Kantatsu R5AC"},
	{0x10, "Kantatsu Q5BG"},
	{0x11, "Sunny 3803A"},
	{0x12, "Sunny 3805A"},
	{0x13, "Largan 40085"},
	{0x14, "Largan 50008A1"},
	{0x15, "Largan 9547A1/A3"},
	{0x16, "Sunny 3809B"},
	{0x17, "Kantatsu U5AM08"},
	{0x18, "Kantatsu G5AX08A/B"},
	{0x19, "Kavas KV4026"},
    {0x6e, "Sunny 3809"},
	{0x00, "Unknown"},
};
AGOLD_CAMERA_L_STRUCT lens_list_ov8858[] =
{
    {0x00, "Sunny 3824A"},
	{0x10, "Largan 9565A1"},
	{0x11, "Largan 9570A1"},
	{0x12, "Largan 9569A3"},
	{0x13, "Largan 40108"},
	{0x30, "Sunny 3813A"},
	{0x50, "Kantatsu R5AV08/BV"},
	{0x78, "GSEO 8738"},
	{0x79, "GSEO 8744"},
	{0x7a, "GSEO 8742"},
	{0x80, "Foxconn 8028"},
};

AGOLD_CAMERA_L_STRUCT lens_list_ov8865[] =
{
	{0x01, "Largan 9547A1"},
	{0x11, "Largan 50008Ax"},
	{0x12, "Largan 9555C2/C3/C4/C8"},
	{0x13, "Largan 9574A1/A3"},
	{0x14, "Largan 40085"},
	{0x30, "Sunny 3809B"},
	{0x50, "Kantatsu U5AM08"},
	{0x51, "Kantatsu G5AX08A/B"},
	{0x68, "Konica A54D"},
	{0x00, "Unknown"},
};

AGOLD_CAMERA_L_STRUCT lens_list_ov12830[] =
{
	{0x01, "Kantatsu W5BR"},
	{0x02, "Kantatsu L5AQ"},
	{0x03, "Konica A54E"},
	{0x04, "Konica K6JR"},
	{0x05, "Kinko 3781"},
	{0x06, "Largan 9587B"},
	{0x07, "Largan 9547A1"},
	{0x08, "Konica A54D"},
	{0x09, "Kantatsu W5AR"},
	{0x0d, "Largan 50013A1"},
	{0x0e, "Largan 50016A1"},
	{0x0f, "Largan 9587B1"},
	{0x10, "Largan 9563A1"},
	{0x11, "Kantatsu U5AM13A"},
	{0x12, "Kantatsu G5AX13"},
	{0xfc, "Largan 50016A2"},
	{0xfd, "Largan 50013A7"},
	{0xfe, "Kantatsu U5AM13A"},
	{0x00, "Unknown"},
};

AGOLD_CAMERA_L_STRUCT lens_list_imx135[] =
{
	{0x01, "Largan 50016A3"},
	{0x00, "Unknown"},
};

AGOLD_CAMERA_L_STRUCT lens_list_imx258[] =
{
    {0xf9, "Sunny 4033"},
	{0x00, "Sunny 4033"},
	{0x12, "XPT-0AQH5-C"},
//	{0x00, "Unknown"},
};

AGOLD_CAMERA_L_STRUCT lens_list_ov13850[] =
{
    {0xfd, "largan 50064B2"},
	{0x00, "Unknown"},
};
AGOLD_CAMERA_L_STRUCT lens_list_ov8856[] =
{
    {0x01, "Kinko DIF-4174A"},
	{0x00, "Unknown"},
};


AGOLD_CAMERA_LIST_STRUCT agold_camera_list[] =
{
	{
		"ov8825_mipi_raw",
		mf_list_ov,
		lens_list_ov8825,
	},
	{
		"ov12830mipi_raw",
		mf_list_ov,
		lens_list_ov12830,
	},
	{
		"ov8865_mipi_raw",
		mf_list_ov,
		lens_list_ov8865,
	},
	{
		"imx135mipi_raw",
		mf_list_ov,
		lens_list_imx135,
	},
	{
		"ov8858_mipi_raw",
		mf_list_ov,
		lens_list_ov8858,
	},
	{
		"imx258_mipi_raw",
		mf_list_ov,
		lens_list_imx258,
	},
	{
		"ov13850_mipi_raw",
		mf_list_ov,
		lens_list_ov13850,
	},
	{
		"ov8856_mipi_raw",
		mf_list_ov,
		lens_list_ov8856,
	},
	{
		NULL,
		NULL,
		NULL,
	},
};

AGOLD_CAMERA_INFO_STRUCT agold_camera_info[2] =
{
	{
		.mf_id = 0x00,
		.mf_name = "Unknown",
		.lens_id = 0x00,
		.lens_name = "Unknown",
		.otp_magic = 0x00,
	},
	{
		.mf_id = 0x00,
		.mf_name = "Unknown",
		.lens_id = 0x00,
		.lens_name = "Unknown",
		.otp_magic = 0x00,
	}
};

int cur_bg_ratio;
int cur_rg_ratio;
void agold_get_rbg_ratio(int index)
{
	cur_bg_ratio = g_bg_ratio[index];
	cur_rg_ratio = g_rg_ratio[index];
	DEBUG_LOG("cur_bg_ratio=0x%02x cur_rg_ratio=0x%02x\n", cur_bg_ratio, cur_rg_ratio);
}

int agold_get_bg_ratio(int index)
{
	char version[2][32] = {"DEFAULT", "DEFAULT"};    //ma chongze debug
	agold_get_version_proc(version);
	cur_bg_ratio = g_bg_ratio[index];
	return cur_bg_ratio;
}

int agold_get_rg_ratio(int index)
{
	char version[2][32] = {"DEFAULT", "DEFAULT"};    //ma chongze debug
	agold_get_version_proc(version);
	cur_rg_ratio = g_rg_ratio[index];
	return cur_rg_ratio;
}

ssize_t agold_hw_get_camera_lens(struct file *file, char __user *buffer, size_t count, loff_t *ppos)
{
    char *page = NULL;
    char *ptr = NULL;
	ssize_t len = 0;
    int err = -1;
	int i = 0, j = 0;
	AGOLD_CAMERA_M_STRUCT* agold_camera_mf = NULL;
	AGOLD_CAMERA_L_STRUCT* agold_camera_lens = NULL;
	char version[2][32] = {"DEFAULT", "DEFAULT"};
	char* p = NULL;

	page = kmalloc(PAGE_SIZE, GFP_KERNEL);	
	if (!page) 
	{		
		kfree(page);		
		return -ENOMEM;	
	}
	agold_get_version_proc(version);

	for(i = 0; i < 2; i++)
	{
		p = strstr(version[i], "+");
		if(p)
		{
			memcpy(version[i], p+2, 32);
		}

		for(j = 0; agold_camera_list[j].cam_name; j++)
		{
			if(!strcmp(agold_camera_info[i].cam_name, agold_camera_list[j].cam_name))
			{
				break;
			}
		}
		DEBUG_LOG("get list %d %s", j, agold_camera_list[j].cam_name);

		if(agold_camera_list[j].cam_name)
		{
			agold_camera_mf = agold_camera_list[j].mf_list;
			agold_camera_lens = agold_camera_list[j].lens_list;
		}
		else
		{
			continue;
		}


		if(agold_camera_info[i].mf_id)
		{
			for(j = 0; agold_camera_mf[j].mf_id; j++)
			{
				if((agold_camera_info[i].mf_id & 0x7f) == agold_camera_mf[j].mf_id)
				{
					break;
				}
			}
			memcpy(agold_camera_info[i].mf_name, agold_camera_mf[j].mf_name, sizeof(agold_camera_mf[j].mf_name));
			DEBUG_LOG("menufacturer %d %d %x %s", i, j, agold_camera_info[i].mf_id, agold_camera_info[i].mf_name);
		}

		if(agold_camera_info[i].lens_id)
		{
			for(j = 0; agold_camera_lens[j].lens_id; j++)
			{
				if(agold_camera_info[i].lens_id == agold_camera_lens[j].lens_id)
				{
					break;
				}
			}
			memcpy(agold_camera_info[i].lens_name, agold_camera_lens[j].lens_name, sizeof(agold_camera_lens[j].lens_name));
			DEBUG_LOG("lens %d %d %x %s", i, j, agold_camera_info[i].lens_id, agold_camera_info[i].lens_name);
		}
		DEBUG_LOG("get lens info %s %s %d.%d.%d %x", agold_camera_info[i].cam_name, agold_camera_info[i].mf_name,
				agold_camera_info[i].date[0], agold_camera_info[i].date[1],
				agold_camera_info[i].date[2], agold_camera_info[i].sen_id);
	}


/***************************************************************
	Main:m_otp, m_mid, m_lens, m_soft, m_time	//m_otp == bank
	Sub: s_otp, s_mid, s_lens, s_soft, s_time	//s_otp == bank
	m_otp, m_id
	s_otp, s_id

	sw:
	main_name+main_ver
	sub_name+sub_ver

	cur:
	main_ver, sub_ver

	m_otp:fac, lens, version, RG, BG, magic
	s_otp:fac, lens, version, RG, BG, magic
***************************************************************/
	agold_get_cam_soft_info(agold_camera_info[0].version, agold_camera_info[1].version);
	

    ptr = page; 
    ptr += sprintf(ptr, "Main:0x%02x,0x%02x%02x%02x,Time:%02d.%02d.%02d  Sub:0x%02x,0x%02x%02x%02x,Time:%02d.%02d.%02d  sw:%s+%s,%s+%s  cur:%s,%s  Main:%s,Lens:%s,Sen:0x%02x,RG:0x%x,BG:0x%x,AF:%s,%c  Sub:%s,Lens:%s,Sen:0x%02x,RG:0x%x,BG:0x%x,AF:%s,%c",
				agold_camera_info[0].otp_magic, agold_camera_info[0].mf_id,
				agold_camera_info[0].lens_id, agold_camera_info[0].sen_id,
				agold_camera_info[0].date[0],agold_camera_info[0].date[1], agold_camera_info[0].date[2],
				agold_camera_info[1].otp_magic, agold_camera_info[1].mf_id,
				agold_camera_info[1].lens_id, agold_camera_info[1].sen_id,
				agold_camera_info[1].date[0],agold_camera_info[1].date[1], agold_camera_info[1].date[2],
				//sw
				agold_camera_info[0].cam_name, agold_camera_info[0].version+1,
				agold_camera_info[1].cam_name, agold_camera_info[1].version+1, version[0], version[1],
				agold_camera_info[0].mf_name, agold_camera_info[0].lens_name,
				agold_camera_info[0].sen_id, g_rg_ratio[0], g_bg_ratio[0],
				g_lens_para[0], agold_camera_info[0].version[0],
				agold_camera_info[1].mf_name, agold_camera_info[1].lens_name,
				agold_camera_info[1].sen_id, g_rg_ratio[1], g_bg_ratio[1],
				g_lens_para[1], agold_camera_info[1].version[0]);

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

//[agold][xfl][20151102]
#if defined(AGOLD_LENS_AUTO_DETECT)
int agold_get_lens_driver(char *name, int *sensor_id)
{
	int i = 0;
	if ((NULL==name) || (NULL==sensor_id))
	{
		DEBUG_LOG("null point err!\n");
		return -1;
	}
	DEBUG_LOG("[xfl]agold_camera_info[0].cam_name:%s,agold_camera_info[0].mf_id=0x%x, agold_camera_info[0].lens_id=0x%x,agold_camera_info[0].otp_magic=0x%x\n", agold_camera_info[0].cam_name, agold_camera_info[0].mf_id, agold_camera_info[0].lens_id, agold_camera_info[0].otp_magic);
	for (i=0; i<sizeof(agold_camera_lens_table)/sizeof(AGOLD_CAMERA_LENS_TABLE_STRUCT); i++)
	{
		if ((!strcmp(agold_camera_lens_table[i].cam_name, agold_camera_info[0].cam_name)) && (agold_camera_lens_table[i].otp_mf_id== agold_camera_info[0].mf_id) && (agold_camera_lens_table[i].otp_lens_id==agold_camera_info[0].lens_id))
		{
			DEBUG_LOG("[xfl]main_cam:%s, af:%s\n", agold_camera_info[0].cam_name, agold_camera_lens_table[i].lens_driver_name);
			strcpy(name, agold_camera_lens_table[i].lens_driver_name);
			*sensor_id = agold_camera_lens_table[i].sensor_id;
			break;
		}
	}
	if (i == sizeof(agold_camera_lens_table)/sizeof(AGOLD_CAMERA_LENS_TABLE_STRUCT))
	{
		DEBUG_LOG("[xfl]otp macth failed.main_cam:%s, mf_id:0x%x, lens_id:0x%x\n", agold_camera_info[0].cam_name, agold_camera_info[0].mf_id, agold_camera_info[0].lens_id);
		return -1;
	}
	return 0;
}
#endif

