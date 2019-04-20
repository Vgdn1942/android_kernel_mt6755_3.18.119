
#ifdef AGOLD_BOARD_DETECT
#ifdef BUILD_LK
#include <lcm_drv.h>

typedef struct board_gpio_info
{
	int gpio_pull_addr;
	int gpio_mode_addr;
	int gpio_dir_addr;
	int gpio_data_addr;
	int gpio_offset; 
}GPIO_INFO_STRUCT_R;
 
typedef  struct board_adc_info
{
	int base_addr;
	int channel;
	int max;
	int min;
}GPIO_ADC_INFO_STRUCT;

typedef  struct BOARD_DETECT
{
	char tag[16];//"AGOLD#BOARD#DETECT"必须是这个标志
	GPIO_INFO_STRUCT_R pin;
	GPIO_ADC_INFO_STRUCT adc;
	int flag;
	char msg[32];
}BOARD_DETECT_STRUCT;



#define	GPIO_BOARD_DETECT_PIN1  74


#define MAX_GPIO_MODE_PER_REG 8
#define MAX_GPIO_DIR_PER_REG 32
#define GPIO_MODE_BASE_ADDR 0x10005300
#define GPIO_DIR_BASE_ADDR 0x10005000
#define GPIO_DIN_BASE_ADDR 0x10005200
#define ADC_BASE_ADDR 0x11001000
#define GPIO_MODE_PULL_ADDR 0x10002450

#define BOARD_V0  0
#define BOARD_V1  1
#define BOARD_V2  2
#define BOARD_V3  3
#define BOARD_V4  4

#define MOD_ADC_6200K_100K_RANGE    .min = 0 , .max = 96110 
#define MOD_ADC_1000K_100K_RANGE    .min = 96111 , .max = 239700 
#define MOD_ADC_470K_100K_RANGE     .min = 239701, .max = 382900 
#define MOD_ADC_300K_100K_RANGE     .min = 382901, .max = 546400  
#define MOD_ADC_180K_100K_RANGE     .min = 546401, .max = 771400
#define MOD_ADC_100K_100K_RANGE     .min = 771401, .max = 1062200 
#define MOD_ADC_47K_100K_RANGE      .min = 1062201, .max = 1320900
#define MOD_ADC_27K_100K_RANGE      .min = 1320901, .max = 1500000 

static BOARD_DETECT_STRUCT board_detect = {
	.tag = "AGOLD#BD#DETECT",
	.pin = {
		
                        .gpio_pull_addr = GPIO_MODE_PULL_ADDR, 
			.gpio_mode_addr = GPIO_MODE_BASE_ADDR + GPIO_BOARD_DETECT_PIN1 / MAX_GPIO_MODE_PER_REG * 0x10,	
			.gpio_dir_addr = GPIO_DIR_BASE_ADDR + GPIO_BOARD_DETECT_PIN1 / MAX_GPIO_DIR_PER_REG * 0x10,
			.gpio_data_addr = GPIO_DIN_BASE_ADDR + GPIO_BOARD_DETECT_PIN1 / MAX_GPIO_DIR_PER_REG * 0x10,
			.gpio_offset = GPIO_BOARD_DETECT_PIN1 % MAX_GPIO_DIR_PER_REG,
		
	},
	.adc = {
			.base_addr = 0,
			.channel = 0,
			.min = 0 , 
                        .max = 0 ,
	},
	.flag = AGOLD_BOARD_VERSION,
	.msg = "EXTAMP",
};
#endif
#endif
