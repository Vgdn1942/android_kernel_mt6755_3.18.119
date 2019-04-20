#ifndef TOUCHPANEL_H__
#define TOUCHPANEL_H__

/* Pre-defined definition */
#define TPD_TYPE_CAPACITIVE
// #define TPD_TYPE_RESISTIVE
#define TPD_POWER_SOURCE MT6328_POWER_LDO_VGP1
#define TPD_I2C_NUMBER           1
#define TPD_WAKEUP_TRIAL         60
#define TPD_WAKEUP_DELAY         100


#define GPIO_CTP_RST_PIN         (10| 0x80000000)
#define GPIO_CTP_INT_PIN         (1| 0x80000000)

#define TPD_DELAY                (2*HZ/100)
//#define TPD_RES_X                480
//#define TPD_RES_Y                800
#define TPD_CALIBRATION_MATRIX  {1980,0,0,0,1805,0,0,0};

/* for different ctp resolution */
#if defined(AGOLD_CONFIG_FOR_QHD)
	#define TPD_RES_X                540
	#define TPD_RES_Y                960
#elif defined(AGOLD_CONFIG_FOR_HD)
	#define TPD_RES_X                720
	#define TPD_RES_Y                1280
#elif defined(AGOLD_CONFIG_FOR_FWVGA)
	#define TPD_RES_X                480
	#define TPD_RES_Y                854
#elif defined(AGOLD_CONFIG_FOR_WSVGA)
	#define TPD_RES_X                600
	#define TPD_RES_Y                1024
#elif defined(AGOLD_CONFIG_FOR_FHD)
	#define TPD_RES_X                1080
	#define TPD_RES_Y                1920
#elif defined(AGOLD_CONFIG_FOR_WVGA)
	#define TPD_RES_X                480
	#define TPD_RES_Y                800
#else
	#define TPD_RES_X                AGOLD_TPD_RES_X
	#define TPD_RES_Y                AGOLD_TPD_RES_Y
#endif

//#define TPD_HAVE_CALIBRATION
//#define TPD_HAVE_BUTTON               //report key as coordinate,Vibration feedback
//#define TPD_HAVE_TOUCH_KEY            //report key as key_value
//#define TPD_HAVE_TREMBLE_ELIMINATION

//#define TPD_NO_GPIO
//#define TPD_RESET_PIN_ADDR   (PERICFG_BASE + 0xC000)
//#define TPD_HAVE_BUTTON
#if defined(AGOLD_CTP_BUTTON_CONFIG_FOR_E2001_JBL)	
	#define AGOLD_CONFIG_FOR_HD
	#define TPD_BUTTON_HEIGH        (100)
	#define TPD_KEY_COUNT           2
	#define TPD_KEYS                { KEY_MENU, KEY_BACK}
	#define TPD_KEYS_DIM            {{60,1360,100,TPD_BUTTON_HEIGH},{180,1360,100,TPD_BUTTON_HEIGH}}
	
#elif defined(AGOLD_CTP_BUTTON_CONFIG_FOR_E2006_CXQ_JL_FHD_XS)	
	#define AGOLD_CONFIG_FOR_FHD
	#define TPD_BUTTON_HEIGH        (100)
	#define TPD_KEY_COUNT           2
	#define TPD_KEYS                { KEY_MENU, KEY_BACK}
	#define TPD_KEYS_DIM            {{60,2040,100,TPD_BUTTON_HEIGH},{180,2040,100,TPD_BUTTON_HEIGH}}
	
#elif defined(AGOLD_CTP_BUTTON_CONFIG_FOR_E2001_GQ_YJT_FWVGA)	
	#define AGOLD_CONFIG_FOR_FWVGA
	#define TPD_BUTTON_HEIGH        (100)
	#define TPD_KEY_COUNT           2
	#define TPD_KEYS                { KEY_MENU, KEY_BACK}
	#define TPD_KEYS_DIM            {{60,910,100,TPD_BUTTON_HEIGH},{180,910,100,TPD_BUTTON_HEIGH}}
	
#else
	#define TPD_BUTTON_HEIGH 		(100)
	#define TPD_KEY_COUNT 			4
	#define TPD_KEYS 				{KEY_MENU,KEY_BACK,KEY_HOME,KEY_SEARCH}
	#define TPD_KEYS_DIM 			{{60,AGOLD_TPD_RES_Y*850/800,120,TPD_BUTTON_HEIGH},{180,AGOLD_TPD_RES_Y*850/800,120,TPD_BUTTON_HEIGH},\
									 {300,AGOLD_TPD_RES_Y*850/800,120,TPD_BUTTON_HEIGH},{420,AGOLD_TPD_RES_Y*850/800,120,TPD_BUTTON_HEIGH}}
									 
#endif


#endif /* TOUCHPANEL_H__ */
