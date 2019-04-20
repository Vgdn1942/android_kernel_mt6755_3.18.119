#ifndef BOARD_VERSION_H
#define	BOARD_VERSION_H

#define BOARD_VERSION_TOTAL       8
#define UL1CUSTOM_ADC_LEVEL_TOTAL 8
#define LCM_ID_TOTAL              8

#define MOD_ADC_6200K_100K_RANGE        0 ,   96110  
#define MOD_ADC_1000K_100K_RANGE    96111 ,   239700 
#define MOD_ADC_470K_100K_RANGE    239701 ,   382900 
#define MOD_ADC_300K_100K_RANGE    382901 ,   546400  
#define MOD_ADC_180K_100K_RANGE    546401 ,   771400  
#define MOD_ADC_100K_100K_RANGE    771401 ,   1062200  
#define MOD_ADC_47K_100K_RANGE    1062201 ,   1320900
#define MOD_ADC_27K_100K_RANGE    1320901 ,   1500000  
  

#define BOARD_VERSION_V1	MOD_ADC_6200K_100K_RANGE
#define BOARD_VERSION_V2	MOD_ADC_1000K_100K_RANGE
#define BOARD_VERSION_V3	MOD_ADC_470K_100K_RANGE
#define BOARD_VERSION_V4	MOD_ADC_300K_100K_RANGE
#define BOARD_VERSION_V5	MOD_ADC_180K_100K_RANGE
#define BOARD_VERSION_V6	MOD_ADC_100K_100K_RANGE
#define BOARD_VERSION_V7	MOD_ADC_47K_100K_RANGE
#define BOARD_VERSION_V8	MOD_ADC_27K_100K_RANGE

#define ADC_LVL0_RANGE 		MOD_ADC_6200K_100K_RANGE
#define ADC_LVL1_RANGE		MOD_ADC_1000K_100K_RANGE
#define ADC_LVL2_RANGE		MOD_ADC_470K_100K_RANGE
#define ADC_LVL3_RANGE		MOD_ADC_300K_100K_RANGE
#define ADC_LVL4_RANGE		MOD_ADC_180K_100K_RANGE
#define ADC_LVL5_RANGE		MOD_ADC_100K_100K_RANGE 
#define ADC_LVL6_RANGE		MOD_ADC_47K_100K_RANGE
#define ADC_LVL7_RANGE		MOD_ADC_27K_100K_RANGE

#define LCM_ID_V1			MOD_ADC_6200K_100K_RANGE
#define LCM_ID_V2			MOD_ADC_1000K_100K_RANGE
#define LCM_ID_V3			MOD_ADC_470K_100K_RANGE
#define LCM_ID_V4			MOD_ADC_300K_100K_RANGE
#define LCM_ID_V5			MOD_ADC_180K_100K_RANGE
#define LCM_ID_V6			MOD_ADC_100K_100K_RANGE
#define LCM_ID_V7			MOD_ADC_47K_100K_RANGE
#define LCM_ID_V8			MOD_ADC_27K_100K_RANGE

//3M_FDD & 4M
//modem A
#define BAND_A_3M_FDD_V1          "null-V1 (3M_A)"
#define BAND_A_3M_FDD_V2          "Band 1+2+3+4+5+7+8+17+19+20+38+39+40+41 (4M)"
#define BAND_A_3M_FDD_V3          "Band 1+3+7+8+20 (3M_A)"
#define BAND_A_3M_FDD_V4          "Band 1+2+4+5+7+17+19 (3M_A)"
#define BAND_A_3M_FDD_V5          "Band 1+3+38+39+40+41 (4M)"
#define BAND_A_3M_FDD_V6          "null-V6 (3M_A)"
#define BAND_A_3M_FDD_V7          "null-V7 (3M_A)"
#define BAND_A_3M_FDD_V8          "null-V8 (3M_A)"
#define BAND_A_3M_FDD_V9          "null-V9 (3M_A)"
#define BAND_A_3M_FDD_V10         "null-V10 (3M_A)"
#define BAND_A_3M_FDD_V11         "null-V11 (3M_A)"
#define BAND_A_3M_FDD_V12         "null-V12 (3M_A)"
#define BAND_A_3M_FDD_V13         "null-V13 (3M_A)"
#define BAND_A_3M_FDD_V14         "null-V14 (3M_A)"
#define BAND_A_3M_FDD_V15         "null-V15 (3M_A)"
#define BAND_A_3M_FDD_V16         "null-V16 (3M_A)"
//modem B
#define BAND_B_3M_FDD_V1          "null-V1 (3M_B)"
#define BAND_B_3M_FDD_V2          "Band 1+2+3+4+5+7+8+17+19+20+38+39+40+41 (4M)"
#define BAND_B_3M_FDD_V3          "Band 1+3+7+8+20 (3M_B)"
#define BAND_B_3M_FDD_V4          "Band 1+2+4+5+7+17+19 (3M_B)"
#define BAND_B_3M_FDD_V5          "Band 1+3+38+39+40+41 (4M)"
#define BAND_B_3M_FDD_V6          "Band 1+3+7+8+20+38+40V1.0 (4M)"
#define BAND_B_3M_FDD_V7          "Band 1+3+7+8+20+38+40V1.1 (4M)"
#define BAND_B_3M_FDD_V8          "null-V8 (3M_B)"
#define BAND_B_3M_FDD_V9          "null-V9 (3M_B)"
#define BAND_B_3M_FDD_V10         "null-V10 (3M_B)"
#define BAND_B_3M_FDD_V11         "Band 2+3+4+5+8+28 (3M_B)"
#define BAND_B_3M_FDD_V12         "null-V12 (3M_B)"
#define BAND_B_3M_FDD_V13         "null-V13 (3M_B)"
#define BAND_B_3M_FDD_V14         "null-V14 (3M_B)"
#define BAND_B_3M_FDD_V15         "null-V15 (3M_B)"
#define BAND_B_3M_FDD_V16         "null-V16 (3M_B)"

//5M
#define BAND_5M_V1         		  "null (5M)"
#define BAND_5M_V2                "Band 1+3+7+8+20+38+39+40+41 (5M)"
#define BAND_5M_V3                "Band 1+3+38+39+40+41 (5M)"
#define BAND_5M_V4                "null (5M)"
#define BAND_5M_V5                "null (5M)"
#define BAND_5M_V6                "null (5M)"
#define BAND_5M_V7                "null (5M)"
#define BAND_5M_V8                "null (5M)"

//3M_TDD
#define BAND_3M_TDD_V1            "null (3M_TDD)"
#define BAND_3M_TDD_V2            "null (3M_TDD)"
#define BAND_3M_TDD_V3            "null (3M_TDD)"
#define BAND_3M_TDD_V4            "null (3M_TDD)"
#define BAND_3M_TDD_V5            "null (3M_TDD)"
#define BAND_3M_TDD_V6            "null (3M_TDD)"
#define BAND_3M_TDD_V7            "null (3M_TDD)"
#define BAND_3M_TDD_V8            "null (3M_TDD)"
//6M
#define BAND_6M_V1                "null (6M)"
#define BAND_6M_V2             	  "Band 1+3+7+8+20+38+39+40+41+BC0 (6M)"
#define BAND_6M_V3             	  "Band 1+3+7+38+39+40+41+BC0 (6M)"
#define BAND_6M_V4                "Band 1+3+38+39+40+41+BC0 (6M)"
#define BAND_6M_V5                "Band 1+3+38+39+40+41+BC0(GSM/WCDMA四频) (6M)"
#define BAND_6M_V6                "Band 1+3+7+20+38+39+40+41+BC0 (6M)"
#define BAND_6M_V7                "null (6M)"
#define BAND_6M_V8                "null (6M)"

#define BAND_NONE                  "none"

#define MD_3M_4M_A_0_8  0 //c221
#define MD_3M_4M_A_9_16 1 //c221
#define MD_3M_4M_B_0_8  2 //c228
#define MD_3M_4M_B_9_16 3 //c228
#define MD_5M		    4
#define MD_3M_TDD  		6
#define MD_6M   		7

struct adc_range
{
	int min;
	int max;
};

typedef struct 
{
	struct adc_range range;
	char name[64];
}agold_version;



#define Board_V1		"Board_V1"
#define Board_V2		"Board_V2"
#define Board_V3		"Board_V3"
#define Board_V4		"Board_V4"
#define Board_V5		"Board_V5"
#define Board_V6		"Board_V6"
#define Board_V7		"Board_V7"
#define Board_V8		"Board_V8"

#define LCM_V1		"LCM_V1"
#define LCM_V2		"LCM_V2"
#define LCM_V3		"LCM_V3"
#define LCM_V4		"LCM_V4"
#define LCM_V5		"LCM_V5"
#define LCM_V6		"LCM_V6"
#define LCM_V7		"LCM_V7"
#define LCM_V8		"LCM_V8"

#endif

