
#ifndef CUST_AGOLD_FACTORY_TEST_CONFIG_H
#define CUST_AGOLD_FACTORY_TEST_CONFIG_H

#ifdef AGOLD_FACTORY_TEST_CONFIG

#define AGOLD_FACTORY_TEST_ALSPS                 1
#define AGOLD_FACTORY_TEST_MSENSOR               2
#define AGOLD_FACTORY_TEST_NLED                  3
#define AGOLD_FACTORY_TEST_HALL                  4
#define AGOLD_FACTORY_TEST_NFC                   5
#define AGOLD_FACTORY_TEST_FINGERPRINT           6
#define AGOLD_FACTORY_TEST_HALL_CAM              7
#define AGOLD_FACTORY_TEST_BTP                   8
#define AGOLD_FACTORY_TEST_MATV                  9
#define AGOLD_FACTORY_TEST_GYROSCOPE             10
#define AGOLD_FACTORY_TEST_UV                    11
#define AGOLD_FACTORY_TEST_TEMP                  12
#define AGOLD_FACTORY_TEST_BAROMETER             13
#define AGOLD_FACTORY_TEST_DEFAULT1              14
#define AGOLD_FACTORY_TEST_DEFAULT2              15
#define AGOLD_FACTORY_TEST_DEFAULT3              16
#define AGOLD_FACTORY_TEST_DEFAULT4              17
#define AGOLD_FACTORY_TEST_DEFAULT5              18
#define AGOLD_FACTORY_TEST_DEFAULT6              19
#define AGOLD_FACTORY_TEST_DEFAULT7              20
#define AGOLD_FACTORY_TEST_DEFAULT8              21
#define AGOLD_FACTORY_TEST_DEFAULT9              22
#define AGOLD_FACTORY_TEST_DEFAULT10             23
#define AGOLD_FACTORY_TEST_DEFAULT11             24
#define AGOLD_FACTORY_TEST_DEFAULT12             25
#define AGOLD_FACTORY_TEST_DEFAULT13             26
#define AGOLD_FACTORY_TEST_DEFAULT14             27
#define AGOLD_FACTORY_TEST_DEFAULT15             28
#define AGOLD_FACTORY_TEST_DEFAULT16             29
#define AGOLD_FACTORY_TEST_DEFAULT17             30
#define AGOLD_FACTORY_TEST_DEFAULT18             31
#define AGOLD_FACTORY_TEST_DEFAULT19             32


typedef struct 
{
	char factory_test_magic_name1[16];
	char item_list[32];
	char factory_test_magic_name2[16];
}AGOLD_FACTORY_TEST_ITEM_LIST;

const AGOLD_FACTORY_TEST_ITEM_LIST agold_factory_test_config =
{
	"AGOLD$FACTORY",
	"0000000000000000000000000000000",
	"AGOLD$FACTORY"
};

#endif
#endif
