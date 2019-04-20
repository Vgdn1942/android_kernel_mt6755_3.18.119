
#ifdef AGOLD_RF_DETECT
#ifdef BUILD_LK
#include <lcm_drv.h>
struct gpio_info
{
	int gpio_pull_addr;
	int gpio_mode_addr;
	int gpio_mode_value;
	int gpio_dir_addr;
	int gpio_dir_value;
	int gpio_data_addr;
	int gpio_offset;	
};

struct adc_info
{
	int base_addr;
	int channel;
	int max;
	int min;
};

typedef struct RF_DETECT
{
	char tag[16];
	struct gpio_info pin[3];
	struct adc_info adc;
	int flag;
	char msg[16][32];
}RF_CHECK_STRUCT;

#define	GPIO_FDD_BAND_SUPPORT_DETECT_1ST_PIN  82
#define	GPIO_FDD_BAND_SUPPORT_DETECT_2ND_PIN  81
#define	GPIO_FDD_BAND_SUPPORT_DETECT_3RD_PIN  80

#define MAX_GPIO_MODE_PER_REG 10
#define MAX_GPIO_DIR_PER_REG 32

#define GPIO_MODE_BASE_ADDR 0x10005300
#define GPIO_DIR_BASE_ADDR  0x10005000
#define GPIO_DIN_BASE_ADDR  0x10005200
#define GPIO_PULL_ENABLE_ADDR  0x10002460

#define ADC_BASE_ADDR 0x11001000

#define MD_3M_4M_A 0 //c221
#define MD_3M_4M_B 2 //c228
#define MD_5M_WP   4
#define MD_3M_TDD  6
#define MD_6M_WP   7


#define MOD_ADC_6200K_100K_RANGE    .min = 0 , .max = 96110 
#define MOD_ADC_1000K_100K_RANGE    .min = 96111 , .max = 239700 
#define MOD_ADC_470K_100K_RANGE     .min = 239701, .max = 382900 
#define MOD_ADC_300K_100K_RANGE     .min = 382901, .max = 546400  
#define MOD_ADC_180K_100K_RANGE     .min = 546401, .max = 771400
#define MOD_ADC_100K_100K_RANGE     .min = 771401, .max = 1062200 
#define MOD_ADC_47K_100K_RANGE      .min = 1062201, .max = 1320900
#define MOD_ADC_27K_100K_RANGE      .min = 1320901, .max = 1500000 

RF_CHECK_STRUCT rf_detect = {
	.tag = "AGOLD#ND#DETECT",
	.pin = {
			{//gpio80
				.gpio_pull_addr = GPIO_PULL_ENABLE_ADDR,
				.gpio_mode_addr = GPIO_MODE_BASE_ADDR + GPIO_FDD_BAND_SUPPORT_DETECT_1ST_PIN / MAX_GPIO_MODE_PER_REG*16,
				.gpio_mode_value=0xffffffe00,	
				.gpio_dir_addr = GPIO_DIR_BASE_ADDR + GPIO_FDD_BAND_SUPPORT_DETECT_1ST_PIN / MAX_GPIO_DIR_PER_REG*16,
				.gpio_dir_value=0xfff8ffff,
				.gpio_data_addr = GPIO_DIN_BASE_ADDR + GPIO_FDD_BAND_SUPPORT_DETECT_1ST_PIN / MAX_GPIO_DIR_PER_REG*16,
				.gpio_offset = GPIO_FDD_BAND_SUPPORT_DETECT_1ST_PIN % MAX_GPIO_DIR_PER_REG,
			},
			{//gpio81
				.gpio_pull_addr = GPIO_PULL_ENABLE_ADDR,
				.gpio_mode_addr = GPIO_MODE_BASE_ADDR + GPIO_FDD_BAND_SUPPORT_DETECT_2ND_PIN / MAX_GPIO_MODE_PER_REG*16,	
				.gpio_mode_value=0xffffffe00,
				.gpio_dir_addr = GPIO_DIR_BASE_ADDR + GPIO_FDD_BAND_SUPPORT_DETECT_2ND_PIN / MAX_GPIO_DIR_PER_REG*16,
				.gpio_dir_value=0xfff8ffff,
				.gpio_data_addr = GPIO_DIN_BASE_ADDR + GPIO_FDD_BAND_SUPPORT_DETECT_2ND_PIN / MAX_GPIO_DIR_PER_REG*16,
				.gpio_offset = GPIO_FDD_BAND_SUPPORT_DETECT_2ND_PIN % MAX_GPIO_DIR_PER_REG,
			},
			{//gpio82
				.gpio_pull_addr = GPIO_PULL_ENABLE_ADDR,
				.gpio_mode_addr = GPIO_MODE_BASE_ADDR + GPIO_FDD_BAND_SUPPORT_DETECT_3RD_PIN / MAX_GPIO_MODE_PER_REG*16,	
				.gpio_mode_value=0xffffffe00,
				.gpio_dir_addr = GPIO_DIR_BASE_ADDR + GPIO_FDD_BAND_SUPPORT_DETECT_3RD_PIN / MAX_GPIO_DIR_PER_REG*16,
				.gpio_dir_value=0xfff8ffff,
				.gpio_data_addr = GPIO_DIN_BASE_ADDR + GPIO_FDD_BAND_SUPPORT_DETECT_3RD_PIN / MAX_GPIO_DIR_PER_REG*16,
				.gpio_offset = GPIO_FDD_BAND_SUPPORT_DETECT_3RD_PIN % MAX_GPIO_DIR_PER_REG,
			},
	},
	.adc = {
			.base_addr = ADC_BASE_ADDR,
			.channel = 14,
			MOD_ADC_470K_100K_RANGE,
	},
	.flag = MD_3M_4M_A,
	.msg ={
		/*no_drdi_mode1*/{"none"},
		/*no_drdi_mode2*/{"none"},
		/*no_drdi_mode3*/{"none"},
		/*no_drdi_mode4*/{"none"},
		/*no_drdi_mode5*/{"none"},
		/*no_drdi_mode6*/{"none"},
		/*no_drdi_mode7*/{"none"},
		/*no_drdi_mode8*/{"none"},
		/*no_drdi_mode9*/{"none"},
		/*no_drdi_mode10*/{"none"},
		/*no_drdi_mode11*/{"none"},
		/*no_drdi_mode12*/{"none"},
		/*no_drdi_mode13*/{"none"},
		/*no_drdi_mode14*/{"none"},
		/*no_drdi_mode15*/{"none"},
		/*no_drdi_mode16*/{"none"}
	}
};
#endif
#endif
