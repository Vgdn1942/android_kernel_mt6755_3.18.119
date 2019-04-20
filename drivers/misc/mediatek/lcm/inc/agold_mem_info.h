/*****************************************************************************
 *
 * Filename:
 * ---------
 *   agold_bin_info.h
 *
 * Project:
 * --------
 *   lk
 *
 * Author:
 * -------
 * agold zam 2012-03-13
 *
 ****************************************************************************/

typedef struct AG_MEM_INFO
{
	unsigned int idx; // 保留位，先不管
	unsigned char chip_name[60]; // 字串，由厂商+型号+容量3部分串一起，如 HYNIX_H9TP32A8JDMCPR_KGM_8G1G
	unsigned int id_len; // 需要比对的chip ID的长度
	unsigned char nand_id[24];  // NAND_EMMC_ID 
	unsigned int fw_len; // 需要比对的firmware ID的长度
	unsigned char fw_id[20];  // firmware ID
} T_MEM_INFO;

typedef struct AG_BIN_INF
{
	unsigned char image_char[20]; //固定为 ”OFNI  NIB  MMOCDLOGA“
	unsigned char bin_ver[8]; // bin info 数据结构的版本，目前为 "V2.0"
	unsigned char tool_ver[16]; // 需要的multidownload tool 版本号
	T_MEM_INFO mem_list[20];			 // 支持的memory ID 列表  
	unsigned char mmd_type[8]; // mmd1 or mmd2 
	unsigned char project[64]; // project name
	unsigned int efuse_enable;
	unsigned int reserved[111];
} T_AG_BIN_INFO;

struct AG_BIN_INF agold_bin_info=
{
	.image_char	="OFNI$NIB$MMOCDLOGA",
	.bin_ver	="v2.0",
	.tool_ver	="v3.1504",
	.mmd_type	="",
	.mem_list	={

		{
			.chip_name="Samsung_KMR21000BM-B809_12288+12288",
			.id_len=24,
			.nand_id="0x150100523231424D42",
			.fw_len=20,
			.fw_id="",
		},
		{
			.chip_name="Hynix_H9TQ26ADFTACUR_KUM_16384+8192",
			.id_len=24,
			.nand_id="0x90014A484247346132",
			.fw_len=20,
			.fw_id="",
		},
		{
			.chip_name="Samsung_KMRX1000BM_B614_12288+12288",
			.id_len=24,
			.nand_id="0x150100525831424D42",
			.fw_len=20,
			.fw_id="",
		},
		{
			.chip_name="Micron_MT29TZZZ7D7EKKBT_107W_97V_12288+12288",
			.id_len=24,
			.nand_id="0x13014E51334A393756",
			.fw_len=20,
			.fw_id="",
		},
		{
			.chip_name="Samsung_KMRC10014M_B809_16384+16384",
			.id_len=24,
			.nand_id="0x150100524331344D42",
			.fw_len=20,
			.fw_id="",
		},
		{
			.chip_name="Hynix_H9TQ52ACLTMCUR_KUM_16384+16384",
			.id_len=24,
			.nand_id="0x90014A484347386134",
			.fw_len=20,
			.fw_id="0xA1",
		},
		{
			.chip_name="Samsung_KMRH60014A_B614_16384+16384",
			.id_len=24,
			.nand_id="0x150100524836344142",
			.fw_len=20,
			.fw_id="",
		},
		{
			.chip_name="Leahkinn_LTLQ66BBSS-7EKK-7B_12288+12288",
			.id_len=24,
			.nand_id="0x13014E51324A393756",
			.fw_len=20,
			.fw_id="",
		},
			},	
	.efuse_enable=0
	
};
