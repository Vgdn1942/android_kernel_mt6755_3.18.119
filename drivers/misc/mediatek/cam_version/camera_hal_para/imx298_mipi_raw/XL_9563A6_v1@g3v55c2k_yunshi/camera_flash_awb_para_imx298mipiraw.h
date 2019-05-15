/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 */
/* MediaTek Inc. (C) 2010. All rights reserved.
 *
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 * RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER ON
 * AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
 * NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
 * SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
 * SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES TO LOOK ONLY TO SUCH
 * THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES
 * THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES
 * CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK
 * SOFTWARE RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND
 * CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
 * AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
 * OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
 * MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 * The following software/firmware and/or related documentation ("MediaTek Software")
 * have been modified by MediaTek Inc. All revisions are subject to any receiver's
 * applicable license agreements with MediaTek Inc.
 */

/********************************************************************************************
 *     LEGAL DISCLAIMER
 *
 *     (Header of MediaTek Software/Firmware Release or Documentation)
 *
 *     BY OPENING OR USING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 *     THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE") RECEIVED
 *     FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON AN "AS-IS" BASIS
 *     ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES, EXPRESS OR IMPLIED,
 *     INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR
 *     A PARTICULAR PURPOSE OR NONINFRINGEMENT. NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY
 *     WHATSOEVER WITH RESPECT TO THE SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY,
 *     INCORPORATED IN, OR SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK
 *     ONLY TO SUCH THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
 *     NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S SPECIFICATION
 *     OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
 *
 *     BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE LIABILITY WITH
 *     RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE, AT MEDIATEK'S OPTION,
TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE, OR REFUND ANY SOFTWARE LICENSE
 *     FEES OR SERVICE CHARGE PAID BY BUYER TO MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 *     THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE WITH THE LAWS
 *     OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF LAWS PRINCIPLES.
 ************************************************************************************************/

// Flash AWB tuning parameter
{
    9,  //foreground percentage
    95, //background percentage
     2, //FgPercentage_Th1 
     5, //FgPercentage_Th2
    10, //FgPercentage_Th3 
    15, //FgPercentage_Th4 
   250, //FgPercentage_Th1_Val 
   250, //FgPercentage_Th2_Val 
   250, //FgPercentage_Th3_Val 
   250, //FgPercentage_Th4_Val 
    10, //location_map_th1 
    20, //location_map_th2
    40, //location_map_th3 
    50, //location_map_th4 
   100, //location_map_val1 
   100, //location_map_val2 
   100, //location_map_val3
   100, //location_map_val4
     0, //SelfTuningFbBgWeightTbl
    100, //FgBgTbl_Y0
    100, //FgBgTbl_Y1
    100, //FgBgTbl_Y2
    100, //FgBgTbl_Y3
    100, //FgBgTbl_Y4
    100, //FgBgTbl_Y5
      5, //YPrimeWeightTh[0]
      9, //YPrimeWeightTh[1]
		 11, //YPrimeWeightTh[2]
		 13, //YPrimeWeightTh[3]
		 15, //YPrimeWeightTh[4]
			1, //YPrimeWeight[0]
			3, //YPrimeWeight[1]
			5, //YPrimeWeight[2]
			7, //YPrimeWeight[3]
	// FlashPreferenceGain
	{
		512,	// FlashPreferenceGain.i4R
		512,	// FlashPreferenceGain.i4G
		512	  // FlashPreferenceGain.i4B
	},
},

// Flash AWB calibration
{{
   { 512, 512, 512},  //duty=-1, dutyLt=-1  
   {1110, 512, 998},  //duty=0, dutyLt=-1  
   {1107, 512, 997},  //duty=1, dutyLt=-1  
   {1111, 512, 998},  //duty=2, dutyLt=-1  
   {1113, 512,1000},  //duty=3, dutyLt=-1  
   {1115, 512, 999},  //duty=4, dutyLt=-1  
   {1115, 512, 997},  //duty=5, dutyLt=-1  
   {1115, 512, 995},  //duty=6, dutyLt=-1  
   {1113, 512, 993},  //duty=7, dutyLt=-1  
   {1114, 512, 990},  //duty=8, dutyLt=-1  
   {1115, 512, 987},  //duty=9, dutyLt=-1  
   {1114, 512, 983},  //duty=10, dutyLt=-1  
   {1113, 512, 980},  //duty=11, dutyLt=-1  
   {1114, 512, 977},  //duty=12, dutyLt=-1  
   {1113, 512, 973},  //duty=13, dutyLt=-1  
   {1113, 512, 970},  //duty=14, dutyLt=-1  
   {1113, 512, 968},  //duty=15, dutyLt=-1  
   {1112, 512, 964},  //duty=16, dutyLt=-1  
   {1112, 512, 961},  //duty=17, dutyLt=-1  
   {1112, 512, 962},  //duty=18, dutyLt=-1  
   {1112, 512, 955},  //duty=19, dutyLt=-1  
   {1112, 512, 951},  //duty=20, dutyLt=-1  
   {1111, 512, 947},  //duty=21, dutyLt=-1  
   {1108, 512, 943},  //duty=22, dutyLt=-1  
   {1105, 512, 936},  //duty=23, dutyLt=-1  
   {1101, 512, 921},  //duty=24, dutyLt=-1  
   {1088, 512, 914},  //duty=25, dutyLt=-1  
   { 584, 512,2754},  //duty=-1, dutyLt=0  
   { 862, 512,1273},  //duty=0, dutyLt=0  
   { 956, 512,1131},  //duty=1, dutyLt=0  
   {1001, 512,1089},  //duty=2, dutyLt=0  
   {1027, 512,1066},  //duty=3, dutyLt=0  
   {1037, 512,1056},  //duty=4, dutyLt=0  
   {1049, 512,1045},  //duty=5, dutyLt=0  
   {1057, 512,1032},  //duty=6, dutyLt=0  
   {1060, 512,1029},  //duty=7, dutyLt=0  
   {1069, 512,1020},  //duty=8, dutyLt=0  
   {1076, 512,1012},  //duty=9, dutyLt=0  
   {1081, 512,1003},  //duty=10, dutyLt=0  
   {1084, 512, 999},  //duty=11, dutyLt=0  
   {1086, 512, 994},  //duty=12, dutyLt=0  
   {1089, 512, 990},  //duty=13, dutyLt=0  
   {1090, 512, 986},  //duty=14, dutyLt=0  
   {1091, 512, 981},  //duty=15, dutyLt=0  
   {1093, 512, 976},  //duty=16, dutyLt=0  
   {1094, 512, 976},  //duty=17, dutyLt=0  
   {1094, 512, 969},  //duty=18, dutyLt=0  
   {1095, 512, 968},  //duty=19, dutyLt=0  
   {1095, 512, 962},  //duty=20, dutyLt=0  
   {1094, 512, 961},  //duty=21, dutyLt=0  
   {1092, 512, 952},  //duty=22, dutyLt=0  
   {1086, 512, 945},  //duty=23, dutyLt=0  
   {1075, 512, 933},  //duty=24, dutyLt=0  
   { 512, 512, 512},  //duty=25, dutyLt=0  
   { 585, 512,2825},  //duty=-1, dutyLt=1  
   { 752, 512,1514},  //duty=0, dutyLt=1  
   { 850, 512,1286},  //duty=1, dutyLt=1  
   { 907, 512,1199},  //duty=2, dutyLt=1  
   { 943, 512,1152},  //duty=3, dutyLt=1  
   { 967, 512,1124},  //duty=4, dutyLt=1  
   { 986, 512,1100},  //duty=5, dutyLt=1  
   { 996, 512,1086},  //duty=6, dutyLt=1  
   {1012, 512,1069},  //duty=7, dutyLt=1  
   {1023, 512,1056},  //duty=8, dutyLt=1  
   {1036, 512,1042},  //duty=9, dutyLt=1  
   {1045, 512,1032},  //duty=10, dutyLt=1  
   {1051, 512,1022},  //duty=11, dutyLt=1  
   {1057, 512,1016},  //duty=12, dutyLt=1  
   {1061, 512,1009},  //duty=13, dutyLt=1  
   {1065, 512,1003},  //duty=14, dutyLt=1  
   {1068, 512, 999},  //duty=15, dutyLt=1  
   {1070, 512, 992},  //duty=16, dutyLt=1  
   {1072, 512, 988},  //duty=17, dutyLt=1  
   {1074, 512, 985},  //duty=18, dutyLt=1  
   {1075, 512, 979},  //duty=19, dutyLt=1  
   {1077, 512, 974},  //duty=20, dutyLt=1  
   {1076, 512, 968},  //duty=21, dutyLt=1  
   {1073, 512, 960},  //duty=22, dutyLt=1  
   {1067, 512, 951},  //duty=23, dutyLt=1  
   {1059, 512, 937},  //duty=24, dutyLt=1  
   { 512, 512, 512},  //duty=25, dutyLt=1  
   { 585, 512,2847},  //duty=-1, dutyLt=2  
   { 705, 512,1702},  //duty=0, dutyLt=2  
   { 791, 512,1416},  //duty=1, dutyLt=2  
   { 847, 512,1298},  //duty=2, dutyLt=2  
   { 886, 512,1231},  //duty=3, dutyLt=2  
   { 913, 512,1189},  //duty=4, dutyLt=2  
   { 936, 512,1147},  //duty=5, dutyLt=2  
   { 949, 512,1136},  //duty=6, dutyLt=2  
   { 970, 512,1111},  //duty=7, dutyLt=2  
   { 990, 512,1088},  //duty=8, dutyLt=2  
   {1008, 512,1066},  //duty=9, dutyLt=2  
   {1013, 512,1057},  //duty=10, dutyLt=2  
   {1023, 512,1046},  //duty=11, dutyLt=2  
   {1029, 512,1037},  //duty=12, dutyLt=2  
   {1036, 512,1029},  //duty=13, dutyLt=2  
   {1041, 512,1021},  //duty=14, dutyLt=2  
   {1045, 512,1014},  //duty=15, dutyLt=2  
   {1050, 512,1007},  //duty=16, dutyLt=2  
   {1052, 512,1002},  //duty=17, dutyLt=2  
   {1055, 512, 996},  //duty=18, dutyLt=2  
   {1057, 512, 992},  //duty=19, dutyLt=2  
   {1059, 512, 987},  //duty=20, dutyLt=2  
   {1057, 512, 978},  //duty=21, dutyLt=2  
   {1054, 512, 968},  //duty=22, dutyLt=2  
   {1049, 512, 959},  //duty=23, dutyLt=2  
   { 512, 512, 512},  //duty=24, dutyLt=2  
   { 512, 512, 512},  //duty=25, dutyLt=2  
   { 584, 512,2811},  //duty=-1, dutyLt=3  
   { 679, 512,1844},  //duty=0, dutyLt=3  
   { 754, 512,1527},  //duty=1, dutyLt=3  
   { 806, 512,1384},  //duty=2, dutyLt=3  
   { 845, 512,1301},  //duty=3, dutyLt=3  
   { 872, 512,1248},  //duty=4, dutyLt=3  
   { 894, 512,1209},  //duty=5, dutyLt=3  
   { 913, 512,1182},  //duty=6, dutyLt=3  
   { 935, 512,1150},  //duty=7, dutyLt=3  
   { 958, 512,1119},  //duty=8, dutyLt=3  
   { 979, 512,1094},  //duty=9, dutyLt=3  
   { 987, 512,1082},  //duty=10, dutyLt=3  
   {1002, 512,1064},  //duty=11, dutyLt=3  
   {1006, 512,1058},  //duty=12, dutyLt=3  
   {1014, 512,1046},  //duty=13, dutyLt=3  
   {1020, 512,1039},  //duty=14, dutyLt=3  
   {1025, 512,1031},  //duty=15, dutyLt=3  
   {1030, 512,1019},  //duty=16, dutyLt=3  
   {1034, 512,1016},  //duty=17, dutyLt=3  
   {1037, 512,1009},  //duty=18, dutyLt=3  
   {1040, 512,1004},  //duty=19, dutyLt=3  
   {1041, 512, 995},  //duty=20, dutyLt=3  
   {1039, 512, 988},  //duty=21, dutyLt=3  
   {1035, 512, 978},  //duty=22, dutyLt=3  
   {1030, 512, 965},  //duty=23, dutyLt=3  
   { 512, 512, 512},  //duty=24, dutyLt=3  
   { 512, 512, 512},  //duty=25, dutyLt=3  
   { 585, 512,2812},  //duty=-1, dutyLt=4  
   { 664, 512,1949},  //duty=0, dutyLt=4  
   { 729, 512,1614},  //duty=1, dutyLt=4  
   { 778, 512,1455},  //duty=2, dutyLt=4  
   { 816, 512,1360},  //duty=3, dutyLt=4  
   { 840, 512,1302},  //duty=4, dutyLt=4  
   { 864, 512,1256},  //duty=5, dutyLt=4  
   { 884, 512,1222},  //duty=6, dutyLt=4  
   { 907, 512,1187},  //duty=7, dutyLt=4  
   { 931, 512,1153},  //duty=8, dutyLt=4  
   { 954, 512,1121},  //duty=9, dutyLt=4  
   { 968, 512,1102},  //duty=10, dutyLt=4  
   { 979, 512,1087},  //duty=11, dutyLt=4  
   { 985, 512,1079},  //duty=12, dutyLt=4  
   { 995, 512,1064},  //duty=13, dutyLt=4  
   {1001, 512,1055},  //duty=14, dutyLt=4  
   {1007, 512,1046},  //duty=15, dutyLt=4  
   {1013, 512,1037},  //duty=16, dutyLt=4  
   {1018, 512,1030},  //duty=17, dutyLt=4  
   {1021, 512,1024},  //duty=18, dutyLt=4  
   {1024, 512,1020},  //duty=19, dutyLt=4  
   {1024, 512,1007},  //duty=20, dutyLt=4  
   {1022, 512, 996},  //duty=21, dutyLt=4  
   {1018, 512, 984},  //duty=22, dutyLt=4  
   { 512, 512, 512},  //duty=23, dutyLt=4  
   { 512, 512, 512},  //duty=24, dutyLt=4  
   { 512, 512, 512},  //duty=25, dutyLt=4  
   { 585, 512,2818},  //duty=-1, dutyLt=5  
   { 652, 512,2038},  //duty=0, dutyLt=5  
   { 710, 512,1696},  //duty=1, dutyLt=5  
   { 755, 512,1524},  //duty=2, dutyLt=5  
   { 790, 512,1414},  //duty=3, dutyLt=5  
   { 816, 512,1351},  //duty=4, dutyLt=5  
   { 840, 512,1300},  //duty=5, dutyLt=5  
   { 859, 512,1263},  //duty=6, dutyLt=5  
   { 883, 512,1222},  //duty=7, dutyLt=5  
   { 908, 512,1182},  //duty=8, dutyLt=5  
   { 932, 512,1146},  //duty=9, dutyLt=5  
   { 947, 512,1124},  //duty=10, dutyLt=5  
   { 960, 512,1106},  //duty=11, dutyLt=5  
   { 966, 512,1097},  //duty=12, dutyLt=5  
   { 977, 512,1081},  //duty=13, dutyLt=5  
   { 984, 512,1071},  //duty=14, dutyLt=5  
   { 990, 512,1061},  //duty=15, dutyLt=5  
   { 997, 512,1050},  //duty=16, dutyLt=5  
   {1002, 512,1042},  //duty=17, dutyLt=5  
   {1007, 512,1035},  //duty=18, dutyLt=5  
   {1009, 512,1027},  //duty=19, dutyLt=5  
   {1009, 512,1016},  //duty=20, dutyLt=5  
   {1006, 512,1005},  //duty=21, dutyLt=5  
   {1001, 512, 991},  //duty=22, dutyLt=5  
   { 512, 512, 512},  //duty=23, dutyLt=5  
   { 512, 512, 512},  //duty=24, dutyLt=5  
   { 512, 512, 512},  //duty=25, dutyLt=5  
   { 582, 512,2830},  //duty=-1, dutyLt=6  
   { 643, 512,2112},  //duty=0, dutyLt=6  
   { 696, 512,1766},  //duty=1, dutyLt=6  
   { 738, 512,1584},  //duty=2, dutyLt=6  
   { 770, 512,1468},  //duty=3, dutyLt=6  
   { 796, 512,1397},  //duty=4, dutyLt=6  
   { 820, 512,1342},  //duty=5, dutyLt=6  
   { 838, 512,1301},  //duty=6, dutyLt=6  
   { 863, 512,1256},  //duty=7, dutyLt=6  
   { 889, 512,1211},  //duty=8, dutyLt=6  
   { 914, 512,1170},  //duty=9, dutyLt=6  
   { 929, 512,1146},  //duty=10, dutyLt=6  
   { 942, 512,1127},  //duty=11, dutyLt=6  
   { 954, 512,1113},  //duty=12, dutyLt=6  
   { 961, 512,1097},  //duty=13, dutyLt=6  
   { 969, 512,1085},  //duty=14, dutyLt=6  
   { 975, 512,1075},  //duty=15, dutyLt=6  
   { 983, 512,1065},  //duty=16, dutyLt=6  
   { 988, 512,1055},  //duty=17, dutyLt=6  
   { 992, 512,1047},  //duty=18, dutyLt=6  
   { 994, 512,1039},  //duty=19, dutyLt=6  
   { 994, 512,1025},  //duty=20, dutyLt=6  
   { 990, 512,1011},  //duty=21, dutyLt=6  
   { 512, 512, 512},  //duty=22, dutyLt=6  
   { 512, 512, 512},  //duty=23, dutyLt=6  
   { 512, 512, 512},  //duty=24, dutyLt=6  
   { 512, 512, 512},  //duty=25, dutyLt=6  
   { 583, 512,2836},  //duty=-1, dutyLt=7  
   { 636, 512,2177},  //duty=0, dutyLt=7  
   { 681, 512,1850},  //duty=1, dutyLt=7  
   { 717, 512,1654},  //duty=2, dutyLt=7  
   { 746, 512,1540},  //duty=3, dutyLt=7  
   { 773, 512,1460},  //duty=4, dutyLt=7  
   { 794, 512,1400},  //duty=5, dutyLt=7  
   { 814, 512,1354},  //duty=6, dutyLt=7  
   { 838, 512,1301},  //duty=7, dutyLt=7  
   { 864, 512,1250},  //duty=8, dutyLt=7  
   { 889, 512,1205},  //duty=9, dutyLt=7  
   { 906, 512,1177},  //duty=10, dutyLt=7  
   { 919, 512,1154},  //duty=11, dutyLt=7  
   { 927, 512,1142},  //duty=12, dutyLt=7  
   { 939, 512,1122},  //duty=13, dutyLt=7  
   { 948, 512,1108},  //duty=14, dutyLt=7  
   { 955, 512,1096},  //duty=15, dutyLt=7  
   { 964, 512,1084},  //duty=16, dutyLt=7  
   { 969, 512,1074},  //duty=17, dutyLt=7  
   { 973, 512,1063},  //duty=18, dutyLt=7  
   { 974, 512,1053},  //duty=19, dutyLt=7  
   { 972, 512,1035},  //duty=20, dutyLt=7  
   { 967, 512,1020},  //duty=21, dutyLt=7  
   { 512, 512, 512},  //duty=22, dutyLt=7  
   { 512, 512, 512},  //duty=23, dutyLt=7  
   { 512, 512, 512},  //duty=24, dutyLt=7  
   { 512, 512, 512},  //duty=25, dutyLt=7  
   { 582, 512,2841},  //duty=-1, dutyLt=8  
   { 628, 512,2262},  //duty=0, dutyLt=8  
   { 665, 512,1929},  //duty=1, dutyLt=8  
   { 698, 512,1740},  //duty=2, dutyLt=8  
   { 725, 512,1620},  //duty=3, dutyLt=8  
   { 749, 512,1531},  //duty=4, dutyLt=8  
   { 770, 512,1468},  //duty=5, dutyLt=8  
   { 783, 512,1421},  //duty=6, dutyLt=8  
   { 811, 512,1357},  //duty=7, dutyLt=8  
   { 837, 512,1299},  //duty=8, dutyLt=8  
   { 863, 512,1246},  //duty=9, dutyLt=8  
   { 880, 512,1215},  //duty=10, dutyLt=8  
   { 894, 512,1189},  //duty=11, dutyLt=8  
   { 902, 512,1173},  //duty=12, dutyLt=8  
   { 915, 512,1151},  //duty=13, dutyLt=8  
   { 924, 512,1136},  //duty=14, dutyLt=8  
   { 932, 512,1123},  //duty=15, dutyLt=8  
   { 940, 512,1109},  //duty=16, dutyLt=8  
   { 946, 512,1098},  //duty=17, dutyLt=8  
   { 948, 512,1083},  //duty=18, dutyLt=8  
   { 948, 512,1069},  //duty=19, dutyLt=8  
   { 945, 512,1048},  //duty=20, dutyLt=8  
   { 512, 512, 512},  //duty=21, dutyLt=8  
   { 512, 512, 512},  //duty=22, dutyLt=8  
   { 512, 512, 512},  //duty=23, dutyLt=8  
   { 512, 512, 512},  //duty=24, dutyLt=8  
   { 512, 512, 512},  //duty=25, dutyLt=8  
   { 583, 512,2840},  //duty=-1, dutyLt=9  
   { 617, 512,2326},  //duty=0, dutyLt=9  
   { 650, 512,2029},  //duty=1, dutyLt=9  
   { 678, 512,1839},  //duty=2, dutyLt=9  
   { 706, 512,1704},  //duty=3, dutyLt=9  
   { 728, 512,1612},  //duty=4, dutyLt=9  
   { 747, 512,1540},  //duty=5, dutyLt=9  
   { 764, 512,1483},  //duty=6, dutyLt=9  
   { 786, 512,1418},  //duty=7, dutyLt=9  
   { 811, 512,1352},  //duty=8, dutyLt=9  
   { 837, 512,1291},  //duty=9, dutyLt=9  
   { 854, 512,1258},  //duty=10, dutyLt=9  
   { 868, 512,1229},  //duty=11, dutyLt=9  
   { 876, 512,1212},  //duty=12, dutyLt=9  
   { 890, 512,1185},  //duty=13, dutyLt=9  
   { 899, 512,1168},  //duty=14, dutyLt=9  
   { 907, 512,1154},  //duty=15, dutyLt=9  
   { 916, 512,1134},  //duty=16, dutyLt=9  
   { 920, 512,1119},  //duty=17, dutyLt=9  
   { 920, 512,1102},  //duty=18, dutyLt=9  
   { 919, 512,1085},  //duty=19, dutyLt=9  
   { 512, 512, 512},  //duty=20, dutyLt=9  
   { 512, 512, 512},  //duty=21, dutyLt=9  
   { 512, 512, 512},  //duty=22, dutyLt=9  
   { 512, 512, 512},  //duty=23, dutyLt=9  
   { 512, 512, 512},  //duty=24, dutyLt=9  
   { 512, 512, 512},  //duty=25, dutyLt=9  
   { 583, 512,2815},  //duty=-1, dutyLt=10  
   { 614, 512,2367},  //duty=0, dutyLt=10  
   { 643, 512,2085},  //duty=1, dutyLt=10  
   { 668, 512,1898},  //duty=2, dutyLt=10  
   { 690, 512,1770},  //duty=3, dutyLt=10  
   { 715, 512,1664},  //duty=4, dutyLt=10  
   { 733, 512,1589},  //duty=5, dutyLt=10  
   { 749, 512,1531},  //duty=6, dutyLt=10  
   { 771, 512,1461},  //duty=7, dutyLt=10  
   { 795, 512,1392},  //duty=8, dutyLt=10  
   { 820, 512,1328},  //duty=9, dutyLt=10  
   { 832, 512,1296},  //duty=10, dutyLt=10  
   { 845, 512,1266},  //duty=11, dutyLt=10  
   { 859, 512,1237},  //duty=12, dutyLt=10  
   { 873, 512,1210},  //duty=13, dutyLt=10  
   { 882, 512,1192},  //duty=14, dutyLt=10  
   { 891, 512,1174},  //duty=15, dutyLt=10  
   { 897, 512,1154},  //duty=16, dutyLt=10  
   { 899, 512,1135},  //duty=17, dutyLt=10  
   { 898, 512,1114},  //duty=18, dutyLt=10  
   { 512, 512, 512},  //duty=19, dutyLt=10  
   { 512, 512, 512},  //duty=20, dutyLt=10  
   { 512, 512, 512},  //duty=21, dutyLt=10  
   { 512, 512, 512},  //duty=22, dutyLt=10  
   { 512, 512, 512},  //duty=23, dutyLt=10  
   { 512, 512, 512},  //duty=24, dutyLt=10  
   { 512, 512, 512},  //duty=25, dutyLt=10  
   { 584, 512,2819},  //duty=-1, dutyLt=11  
   { 611, 512,2410},  //duty=0, dutyLt=11  
   { 638, 512,2131},  //duty=1, dutyLt=11  
   { 661, 512,1950},  //duty=2, dutyLt=11  
   { 681, 512,1822},  //duty=3, dutyLt=11  
   { 700, 512,1720},  //duty=4, dutyLt=11  
   { 717, 512,1643},  //duty=5, dutyLt=11  
   { 732, 512,1582},  //duty=6, dutyLt=11  
   { 753, 512,1507},  //duty=7, dutyLt=11  
   { 781, 512,1426},  //duty=8, dutyLt=11  
   { 801, 512,1366},  //duty=9, dutyLt=11  
   { 817, 512,1325},  //duty=10, dutyLt=11  
   { 831, 512,1294},  //duty=11, dutyLt=11  
   { 844, 512,1263},  //duty=12, dutyLt=11  
   { 858, 512,1236},  //duty=13, dutyLt=11  
   { 868, 512,1215},  //duty=14, dutyLt=11  
   { 875, 512,1195},  //duty=15, dutyLt=11  
   { 880, 512,1169},  //duty=16, dutyLt=11  
   { 881, 512,1147},  //duty=17, dutyLt=11  
   { 512, 512, 512},  //duty=18, dutyLt=11  
   { 512, 512, 512},  //duty=19, dutyLt=11  
   { 512, 512, 512},  //duty=20, dutyLt=11  
   { 512, 512, 512},  //duty=21, dutyLt=11  
   { 512, 512, 512},  //duty=22, dutyLt=11  
   { 512, 512, 512},  //duty=23, dutyLt=11  
   { 512, 512, 512},  //duty=24, dutyLt=11  
   { 512, 512, 512},  //duty=25, dutyLt=11  
   { 585, 512,2806},  //duty=-1, dutyLt=12  
   { 609, 512,2438},  //duty=0, dutyLt=12  
   { 633, 512,2175},  //duty=1, dutyLt=12  
   { 655, 512,1993},  //duty=2, dutyLt=12  
   { 674, 512,1865},  //duty=3, dutyLt=12  
   { 692, 512,1762},  //duty=4, dutyLt=12  
   { 708, 512,1686},  //duty=5, dutyLt=12  
   { 723, 512,1620},  //duty=6, dutyLt=12  
   { 742, 512,1545},  //duty=7, dutyLt=12  
   { 764, 512,1470},  //duty=8, dutyLt=12  
   { 788, 512,1397},  //duty=9, dutyLt=12  
   { 805, 512,1353},  //duty=10, dutyLt=12  
   { 819, 512,1317},  //duty=11, dutyLt=12  
   { 832, 512,1287},  //duty=12, dutyLt=12  
   { 847, 512,1248},  //duty=13, dutyLt=12  
   { 854, 512,1232},  //duty=14, dutyLt=12  
   { 860, 512,1211},  //duty=15, dutyLt=12  
   { 864, 512,1182},  //duty=16, dutyLt=12  
   { 512, 512, 512},  //duty=17, dutyLt=12  
   { 512, 512, 512},  //duty=18, dutyLt=12  
   { 512, 512, 512},  //duty=19, dutyLt=12  
   { 512, 512, 512},  //duty=20, dutyLt=12  
   { 512, 512, 512},  //duty=21, dutyLt=12  
   { 512, 512, 512},  //duty=22, dutyLt=12  
   { 512, 512, 512},  //duty=23, dutyLt=12  
   { 512, 512, 512},  //duty=24, dutyLt=12  
   { 512, 512, 512},  //duty=25, dutyLt=12  
   { 585, 512,2803},  //duty=-1, dutyLt=13  
   { 611, 512,2456},  //duty=0, dutyLt=13  
   { 629, 512,2218},  //duty=1, dutyLt=13  
   { 649, 512,2041},  //duty=2, dutyLt=13  
   { 667, 512,1909},  //duty=3, dutyLt=13  
   { 684, 512,1808},  //duty=4, dutyLt=13  
   { 699, 512,1729},  //duty=5, dutyLt=13  
   { 712, 512,1665},  //duty=6, dutyLt=13  
   { 730, 512,1585},  //duty=7, dutyLt=13  
   { 753, 512,1505},  //duty=8, dutyLt=13  
   { 775, 512,1433},  //duty=9, dutyLt=13  
   { 791, 512,1385},  //duty=10, dutyLt=13  
   { 805, 512,1346},  //duty=11, dutyLt=13  
   { 817, 512,1315},  //duty=12, dutyLt=13  
   { 831, 512,1281},  //duty=13, dutyLt=13  
   { 837, 512,1258},  //duty=14, dutyLt=13  
   { 842, 512,1229},  //duty=15, dutyLt=13  
   { 512, 512, 512},  //duty=16, dutyLt=13  
   { 512, 512, 512},  //duty=17, dutyLt=13  
   { 512, 512, 512},  //duty=18, dutyLt=13  
   { 512, 512, 512},  //duty=19, dutyLt=13  
   { 512, 512, 512},  //duty=20, dutyLt=13  
   { 512, 512, 512},  //duty=21, dutyLt=13  
   { 512, 512, 512},  //duty=22, dutyLt=13  
   { 512, 512, 512},  //duty=23, dutyLt=13  
   { 512, 512, 512},  //duty=24, dutyLt=13  
   { 512, 512, 512},  //duty=25, dutyLt=13  
   { 586, 512,2808},  //duty=-1, dutyLt=14  
   { 606, 512,2487},  //duty=0, dutyLt=14  
   { 626, 512,2254},  //duty=1, dutyLt=14  
   { 646, 512,2073},  //duty=2, dutyLt=14  
   { 662, 512,1947},  //duty=3, dutyLt=14  
   { 678, 512,1841},  //duty=4, dutyLt=14  
   { 693, 512,1762},  //duty=5, dutyLt=14  
   { 704, 512,1699},  //duty=6, dutyLt=14  
   { 724, 512,1613},  //duty=7, dutyLt=14  
   { 744, 512,1532},  //duty=8, dutyLt=14  
   { 767, 512,1455},  //duty=9, dutyLt=14  
   { 782, 512,1407},  //duty=10, dutyLt=14  
   { 795, 512,1371},  //duty=11, dutyLt=14  
   { 808, 512,1335},  //duty=12, dutyLt=14  
   { 820, 512,1299},  //duty=13, dutyLt=14  
   { 826, 512,1269},  //duty=14, dutyLt=14  
   { 512, 512, 512},  //duty=15, dutyLt=14  
   { 512, 512, 512},  //duty=16, dutyLt=14  
   { 512, 512, 512},  //duty=17, dutyLt=14  
   { 512, 512, 512},  //duty=18, dutyLt=14  
   { 512, 512, 512},  //duty=19, dutyLt=14  
   { 512, 512, 512},  //duty=20, dutyLt=14  
   { 512, 512, 512},  //duty=21, dutyLt=14  
   { 512, 512, 512},  //duty=22, dutyLt=14  
   { 512, 512, 512},  //duty=23, dutyLt=14  
   { 512, 512, 512},  //duty=24, dutyLt=14  
   { 512, 512, 512},  //duty=25, dutyLt=14  
   { 586, 512,2802},  //duty=-1, dutyLt=15  
   { 609, 512,2493},  //duty=0, dutyLt=15  
   { 624, 512,2274},  //duty=1, dutyLt=15  
   { 642, 512,2101},  //duty=2, dutyLt=15  
   { 659, 512,1972},  //duty=3, dutyLt=15  
   { 673, 512,1873},  //duty=4, dutyLt=15  
   { 686, 512,1792},  //duty=5, dutyLt=15  
   { 700, 512,1723},  //duty=6, dutyLt=15  
   { 717, 512,1641},  //duty=7, dutyLt=15  
   { 737, 512,1556},  //duty=8, dutyLt=15  
   { 759, 512,1478},  //duty=9, dutyLt=15  
   { 773, 512,1432},  //duty=10, dutyLt=15  
   { 786, 512,1392},  //duty=11, dutyLt=15  
   { 799, 512,1354},  //duty=12, dutyLt=15  
   { 809, 512,1316},  //duty=13, dutyLt=15  
   { 512, 512, 512},  //duty=14, dutyLt=15  
   { 512, 512, 512},  //duty=15, dutyLt=15  
   { 512, 512, 512},  //duty=16, dutyLt=15  
   { 512, 512, 512},  //duty=17, dutyLt=15  
   { 512, 512, 512},  //duty=18, dutyLt=15  
   { 512, 512, 512},  //duty=19, dutyLt=15  
   { 512, 512, 512},  //duty=20, dutyLt=15  
   { 512, 512, 512},  //duty=21, dutyLt=15  
   { 512, 512, 512},  //duty=22, dutyLt=15  
   { 512, 512, 512},  //duty=23, dutyLt=15  
   { 512, 512, 512},  //duty=24, dutyLt=15  
   { 512, 512, 512},  //duty=25, dutyLt=15  
   { 587, 512,2799},  //duty=-1, dutyLt=16  
   { 605, 512,2517},  //duty=0, dutyLt=16  
   { 623, 512,2296},  //duty=1, dutyLt=16  
   { 638, 512,2138},  //duty=2, dutyLt=16  
   { 654, 512,2005},  //duty=3, dutyLt=16  
   { 668, 512,1904},  //duty=4, dutyLt=16  
   { 681, 512,1822},  //duty=5, dutyLt=16  
   { 694, 512,1755},  //duty=6, dutyLt=16  
   { 710, 512,1672},  //duty=7, dutyLt=16  
   { 729, 512,1586},  //duty=8, dutyLt=16  
   { 750, 512,1506},  //duty=9, dutyLt=16  
   { 765, 512,1455},  //duty=10, dutyLt=16  
   { 778, 512,1413},  //duty=11, dutyLt=16  
   { 789, 512,1375},  //duty=12, dutyLt=16  
   { 512, 512, 512},  //duty=13, dutyLt=16  
   { 512, 512, 512},  //duty=14, dutyLt=16  
   { 512, 512, 512},  //duty=15, dutyLt=16  
   { 512, 512, 512},  //duty=16, dutyLt=16  
   { 512, 512, 512},  //duty=17, dutyLt=16  
   { 512, 512, 512},  //duty=18, dutyLt=16  
   { 512, 512, 512},  //duty=19, dutyLt=16  
   { 512, 512, 512},  //duty=20, dutyLt=16  
   { 512, 512, 512},  //duty=21, dutyLt=16  
   { 512, 512, 512},  //duty=22, dutyLt=16  
   { 512, 512, 512},  //duty=23, dutyLt=16  
   { 512, 512, 512},  //duty=24, dutyLt=16  
   { 512, 512, 512},  //duty=25, dutyLt=16  
   { 588, 512,2792},  //duty=-1, dutyLt=17  
   { 604, 512,2527},  //duty=0, dutyLt=17  
   { 621, 512,2314},  //duty=1, dutyLt=17  
   { 636, 512,2158},  //duty=2, dutyLt=17  
   { 651, 512,2032},  //duty=3, dutyLt=17  
   { 665, 512,1930},  //duty=4, dutyLt=17  
   { 677, 512,1847},  //duty=5, dutyLt=17  
   { 689, 512,1777},  //duty=6, dutyLt=17  
   { 705, 512,1693},  //duty=7, dutyLt=17  
   { 724, 512,1608},  //duty=8, dutyLt=17  
   { 744, 512,1529},  //duty=9, dutyLt=17  
   { 758, 512,1476},  //duty=10, dutyLt=17  
   { 771, 512,1432},  //duty=11, dutyLt=17  
   { 512, 512, 512},  //duty=12, dutyLt=17  
   { 512, 512, 512},  //duty=13, dutyLt=17  
   { 512, 512, 512},  //duty=14, dutyLt=17  
   { 512, 512, 512},  //duty=15, dutyLt=17  
   { 512, 512, 512},  //duty=16, dutyLt=17  
   { 512, 512, 512},  //duty=17, dutyLt=17  
   { 512, 512, 512},  //duty=18, dutyLt=17  
   { 512, 512, 512},  //duty=19, dutyLt=17  
   { 512, 512, 512},  //duty=20, dutyLt=17  
   { 512, 512, 512},  //duty=21, dutyLt=17  
   { 512, 512, 512},  //duty=22, dutyLt=17  
   { 512, 512, 512},  //duty=23, dutyLt=17  
   { 512, 512, 512},  //duty=24, dutyLt=17  
   { 512, 512, 512},  //duty=25, dutyLt=17  
   { 588, 512,2792},  //duty=-1, dutyLt=18  
   { 604, 512,2534},  //duty=0, dutyLt=18  
   { 620, 512,2331},  //duty=1, dutyLt=18  
   { 635, 512,2173},  //duty=2, dutyLt=18  
   { 649, 512,2054},  //duty=3, dutyLt=18  
   { 662, 512,1951},  //duty=4, dutyLt=18  
   { 674, 512,1867},  //duty=5, dutyLt=18  
   { 686, 512,1799},  //duty=6, dutyLt=18  
   { 701, 512,1715},  //duty=7, dutyLt=18  
   { 718, 512,1631},  //duty=8, dutyLt=18  
   { 739, 512,1542},  //duty=9, dutyLt=18  
   { 754, 512,1488},  //duty=10, dutyLt=18  
   { 512, 512, 512},  //duty=11, dutyLt=18  
   { 512, 512, 512},  //duty=12, dutyLt=18  
   { 512, 512, 512},  //duty=13, dutyLt=18  
   { 512, 512, 512},  //duty=14, dutyLt=18  
   { 512, 512, 512},  //duty=15, dutyLt=18  
   { 512, 512, 512},  //duty=16, dutyLt=18  
   { 512, 512, 512},  //duty=17, dutyLt=18  
   { 512, 512, 512},  //duty=18, dutyLt=18  
   { 512, 512, 512},  //duty=19, dutyLt=18  
   { 512, 512, 512},  //duty=20, dutyLt=18  
   { 512, 512, 512},  //duty=21, dutyLt=18  
   { 512, 512, 512},  //duty=22, dutyLt=18  
   { 512, 512, 512},  //duty=23, dutyLt=18  
   { 512, 512, 512},  //duty=24, dutyLt=18  
   { 512, 512, 512},  //duty=25, dutyLt=18  
   { 588, 512,2785},  //duty=-1, dutyLt=19  
   { 604, 512,2543},  //duty=0, dutyLt=19  
   { 619, 512,2343},  //duty=1, dutyLt=19  
   { 634, 512,2185},  //duty=2, dutyLt=19  
   { 647, 512,2069},  //duty=3, dutyLt=19  
   { 660, 512,1964},  //duty=4, dutyLt=19  
   { 672, 512,1884},  //duty=5, dutyLt=19  
   { 683, 512,1817},  //duty=6, dutyLt=19  
   { 697, 512,1732},  //duty=7, dutyLt=19  
   { 715, 512,1647},  //duty=8, dutyLt=19  
   { 736, 512,1558},  //duty=9, dutyLt=19  
   { 512, 512, 512},  //duty=10, dutyLt=19  
   { 512, 512, 512},  //duty=11, dutyLt=19  
   { 512, 512, 512},  //duty=12, dutyLt=19  
   { 512, 512, 512},  //duty=13, dutyLt=19  
   { 512, 512, 512},  //duty=14, dutyLt=19  
   { 512, 512, 512},  //duty=15, dutyLt=19  
   { 512, 512, 512},  //duty=16, dutyLt=19  
   { 512, 512, 512},  //duty=17, dutyLt=19  
   { 512, 512, 512},  //duty=18, dutyLt=19  
   { 512, 512, 512},  //duty=19, dutyLt=19  
   { 512, 512, 512},  //duty=20, dutyLt=19  
   { 512, 512, 512},  //duty=21, dutyLt=19  
   { 512, 512, 512},  //duty=22, dutyLt=19  
   { 512, 512, 512},  //duty=23, dutyLt=19  
   { 512, 512, 512},  //duty=24, dutyLt=19  
   { 512, 512, 512},  //duty=25, dutyLt=19  
   { 589, 512,2782},  //duty=-1, dutyLt=20  
   { 603, 512,2552},  //duty=0, dutyLt=20  
   { 618, 512,2361},  //duty=1, dutyLt=20  
   { 632, 512,2205},  //duty=2, dutyLt=20  
   { 643, 512,2096},  //duty=3, dutyLt=20  
   { 657, 512,1991},  //duty=4, dutyLt=20  
   { 668, 512,1910},  //duty=5, dutyLt=20  
   { 677, 512,1849},  //duty=6, dutyLt=20  
   { 693, 512,1755},  //duty=7, dutyLt=20  
   { 710, 512,1667},  //duty=8, dutyLt=20  
   { 512, 512, 512},  //duty=9, dutyLt=20  
   { 512, 512, 512},  //duty=10, dutyLt=20  
   { 512, 512, 512},  //duty=11, dutyLt=20  
   { 512, 512, 512},  //duty=12, dutyLt=20  
   { 512, 512, 512},  //duty=13, dutyLt=20  
   { 512, 512, 512},  //duty=14, dutyLt=20  
   { 512, 512, 512},  //duty=15, dutyLt=20  
   { 512, 512, 512},  //duty=16, dutyLt=20  
   { 512, 512, 512},  //duty=17, dutyLt=20  
   { 512, 512, 512},  //duty=18, dutyLt=20  
   { 512, 512, 512},  //duty=19, dutyLt=20  
   { 512, 512, 512},  //duty=20, dutyLt=20  
   { 512, 512, 512},  //duty=21, dutyLt=20  
   { 512, 512, 512},  //duty=22, dutyLt=20  
   { 512, 512, 512},  //duty=23, dutyLt=20  
   { 512, 512, 512},  //duty=24, dutyLt=20  
   { 512, 512, 512},  //duty=25, dutyLt=20  
   { 590, 512,2776},  //duty=-1, dutyLt=21  
   { 603, 512,2559},  //duty=0, dutyLt=21  
   { 617, 512,2366},  //duty=1, dutyLt=21  
   { 631, 512,2218},  //duty=2, dutyLt=21  
   { 643, 512,2101},  //duty=3, dutyLt=21  
   { 654, 512,2010},  //duty=4, dutyLt=21  
   { 666, 512,1929},  //duty=5, dutyLt=21  
   { 676, 512,1855},  //duty=6, dutyLt=21  
   { 690, 512,1774},  //duty=7, dutyLt=21  
   { 512, 512, 512},  //duty=8, dutyLt=21  
   { 512, 512, 512},  //duty=9, dutyLt=21  
   { 512, 512, 512},  //duty=10, dutyLt=21  
   { 512, 512, 512},  //duty=11, dutyLt=21  
   { 512, 512, 512},  //duty=12, dutyLt=21  
   { 512, 512, 512},  //duty=13, dutyLt=21  
   { 512, 512, 512},  //duty=14, dutyLt=21  
   { 512, 512, 512},  //duty=15, dutyLt=21  
   { 512, 512, 512},  //duty=16, dutyLt=21  
   { 512, 512, 512},  //duty=17, dutyLt=21  
   { 512, 512, 512},  //duty=18, dutyLt=21  
   { 512, 512, 512},  //duty=19, dutyLt=21  
   { 512, 512, 512},  //duty=20, dutyLt=21  
   { 512, 512, 512},  //duty=21, dutyLt=21  
   { 512, 512, 512},  //duty=22, dutyLt=21  
   { 512, 512, 512},  //duty=23, dutyLt=21  
   { 512, 512, 512},  //duty=24, dutyLt=21  
   { 512, 512, 512},  //duty=25, dutyLt=21  
   { 590, 512,2774},  //duty=-1, dutyLt=22  
   { 603, 512,2562},  //duty=0, dutyLt=22  
   { 617, 512,2375},  //duty=1, dutyLt=22  
   { 630, 512,2233},  //duty=2, dutyLt=22  
   { 642, 512,2111},  //duty=3, dutyLt=22  
   { 653, 512,2022},  //duty=4, dutyLt=22  
   { 664, 512,1939},  //duty=5, dutyLt=22  
   { 512, 512, 512},  //duty=6, dutyLt=22  
   { 512, 512, 512},  //duty=7, dutyLt=22  
   { 512, 512, 512},  //duty=8, dutyLt=22  
   { 512, 512, 512},  //duty=9, dutyLt=22  
   { 512, 512, 512},  //duty=10, dutyLt=22  
   { 512, 512, 512},  //duty=11, dutyLt=22  
   { 512, 512, 512},  //duty=12, dutyLt=22  
   { 512, 512, 512},  //duty=13, dutyLt=22  
   { 512, 512, 512},  //duty=14, dutyLt=22  
   { 512, 512, 512},  //duty=15, dutyLt=22  
   { 512, 512, 512},  //duty=16, dutyLt=22  
   { 512, 512, 512},  //duty=17, dutyLt=22  
   { 512, 512, 512},  //duty=18, dutyLt=22  
   { 512, 512, 512},  //duty=19, dutyLt=22  
   { 512, 512, 512},  //duty=20, dutyLt=22  
   { 512, 512, 512},  //duty=21, dutyLt=22  
   { 512, 512, 512},  //duty=22, dutyLt=22  
   { 512, 512, 512},  //duty=23, dutyLt=22  
   { 512, 512, 512},  //duty=24, dutyLt=22  
   { 512, 512, 512},  //duty=25, dutyLt=22  
   { 590, 512,2773},  //duty=-1, dutyLt=23  
   { 603, 512,2563},  //duty=0, dutyLt=23  
   { 616, 512,2387},  //duty=1, dutyLt=23  
   { 629, 512,2243},  //duty=2, dutyLt=23  
   { 641, 512,2128},  //duty=3, dutyLt=23  
   { 512, 512, 512},  //duty=4, dutyLt=23  
   { 512, 512, 512},  //duty=5, dutyLt=23  
   { 512, 512, 512},  //duty=6, dutyLt=23  
   { 512, 512, 512},  //duty=7, dutyLt=23  
   { 512, 512, 512},  //duty=8, dutyLt=23  
   { 512, 512, 512},  //duty=9, dutyLt=23  
   { 512, 512, 512},  //duty=10, dutyLt=23  
   { 512, 512, 512},  //duty=11, dutyLt=23  
   { 512, 512, 512},  //duty=12, dutyLt=23  
   { 512, 512, 512},  //duty=13, dutyLt=23  
   { 512, 512, 512},  //duty=14, dutyLt=23  
   { 512, 512, 512},  //duty=15, dutyLt=23  
   { 512, 512, 512},  //duty=16, dutyLt=23  
   { 512, 512, 512},  //duty=17, dutyLt=23  
   { 512, 512, 512},  //duty=18, dutyLt=23  
   { 512, 512, 512},  //duty=19, dutyLt=23  
   { 512, 512, 512},  //duty=20, dutyLt=23  
   { 512, 512, 512},  //duty=21, dutyLt=23  
   { 512, 512, 512},  //duty=22, dutyLt=23  
   { 512, 512, 512},  //duty=23, dutyLt=23  
   { 512, 512, 512},  //duty=24, dutyLt=23  
   { 512, 512, 512},  //duty=25, dutyLt=23  
   { 591, 512,2763},  //duty=-1, dutyLt=24  
   { 603, 512,2565},  //duty=0, dutyLt=24  
   { 616, 512,2397},  //duty=1, dutyLt=24  
   { 512, 512, 512},  //duty=2, dutyLt=24  
   { 512, 512, 512},  //duty=3, dutyLt=24  
   { 512, 512, 512},  //duty=4, dutyLt=24  
   { 512, 512, 512},  //duty=5, dutyLt=24  
   { 512, 512, 512},  //duty=6, dutyLt=24  
   { 512, 512, 512},  //duty=7, dutyLt=24  
   { 512, 512, 512},  //duty=8, dutyLt=24  
   { 512, 512, 512},  //duty=9, dutyLt=24  
   { 512, 512, 512},  //duty=10, dutyLt=24  
   { 512, 512, 512},  //duty=11, dutyLt=24  
   { 512, 512, 512},  //duty=12, dutyLt=24  
   { 512, 512, 512},  //duty=13, dutyLt=24  
   { 512, 512, 512},  //duty=14, dutyLt=24  
   { 512, 512, 512},  //duty=15, dutyLt=24  
   { 512, 512, 512},  //duty=16, dutyLt=24  
   { 512, 512, 512},  //duty=17, dutyLt=24  
   { 512, 512, 512},  //duty=18, dutyLt=24  
   { 512, 512, 512},  //duty=19, dutyLt=24  
   { 512, 512, 512},  //duty=20, dutyLt=24  
   { 512, 512, 512},  //duty=21, dutyLt=24  
   { 512, 512, 512},  //duty=22, dutyLt=24  
   { 512, 512, 512},  //duty=23, dutyLt=24  
   { 512, 512, 512},  //duty=24, dutyLt=24  
   { 512, 512, 512},  //duty=25, dutyLt=24  
   { 592, 512,2755},  //duty=-1, dutyLt=25  
   { 512, 512, 512},  //duty=0, dutyLt=25  
   { 512, 512, 512},  //duty=1, dutyLt=25  
   { 512, 512, 512},  //duty=2, dutyLt=25  
   { 512, 512, 512},  //duty=3, dutyLt=25  
   { 512, 512, 512},  //duty=4, dutyLt=25  
   { 512, 512, 512},  //duty=5, dutyLt=25  
   { 512, 512, 512},  //duty=6, dutyLt=25  
   { 512, 512, 512},  //duty=7, dutyLt=25  
   { 512, 512, 512},  //duty=8, dutyLt=25  
   { 512, 512, 512},  //duty=9, dutyLt=25  
   { 512, 512, 512},  //duty=10, dutyLt=25  
   { 512, 512, 512},  //duty=11, dutyLt=25  
   { 512, 512, 512},  //duty=12, dutyLt=25  
   { 512, 512, 512},  //duty=13, dutyLt=25  
   { 512, 512, 512},  //duty=14, dutyLt=25  
   { 512, 512, 512},  //duty=15, dutyLt=25  
   { 512, 512, 512},  //duty=16, dutyLt=25  
   { 512, 512, 512},  //duty=17, dutyLt=25  
   { 512, 512, 512},  //duty=18, dutyLt=25  
   { 512, 512, 512},  //duty=19, dutyLt=25  
   { 512, 512, 512},  //duty=20, dutyLt=25  
   { 512, 512, 512},  //duty=21, dutyLt=25  
   { 512, 512, 512},  //duty=22, dutyLt=25  
   { 512, 512, 512},  //duty=23, dutyLt=25  
   { 512, 512, 512},  //duty=24, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512},  //duty=25, dutyLt=25  
   { 512, 512, 512}
}}



