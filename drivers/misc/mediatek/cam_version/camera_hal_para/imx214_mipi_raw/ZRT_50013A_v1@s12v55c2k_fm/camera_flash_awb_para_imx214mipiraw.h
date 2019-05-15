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
   {1067, 512, 846},  //duty=0, dutyLt=-1  
   {1075, 512, 844},  //duty=1, dutyLt=-1  
   {1070, 512, 837},  //duty=2, dutyLt=-1  
   {1067, 512, 831},  //duty=3, dutyLt=-1  
   {1066, 512, 826},  //duty=4, dutyLt=-1  
   {1065, 512, 821},  //duty=5, dutyLt=-1  
   {1063, 512, 810},  //duty=6, dutyLt=-1  
   {1061, 512, 817},  //duty=7, dutyLt=-1  
   {1059, 512, 812},  //duty=8, dutyLt=-1  
   {1059, 512, 807},  //duty=9, dutyLt=-1  
   {1058, 512, 803},  //duty=10, dutyLt=-1  
   {1057, 512, 797},  //duty=11, dutyLt=-1  
   {1056, 512, 796},  //duty=12, dutyLt=-1  
   {1055, 512, 791},  //duty=13, dutyLt=-1  
   {1054, 512, 787},  //duty=14, dutyLt=-1  
   {1054, 512, 785},  //duty=15, dutyLt=-1  
   {1053, 512, 779},  //duty=16, dutyLt=-1  
   {1053, 512, 774},  //duty=17, dutyLt=-1  
   {1052, 512, 772},  //duty=18, dutyLt=-1  
   {1052, 512, 769},  //duty=19, dutyLt=-1  
   {1051, 512, 760},  //duty=20, dutyLt=-1  
   {1045, 512, 757},  //duty=21, dutyLt=-1  
   {1038, 512, 750},  //duty=22, dutyLt=-1  
   {1030, 512, 742},  //duty=23, dutyLt=-1  
   {1015, 512, 729},  //duty=24, dutyLt=-1  
   {1007, 512, 718},  //duty=25, dutyLt=-1  
   { 574, 512,2054},  //duty=-1, dutyLt=0  
   { 783, 512,1126},  //duty=0, dutyLt=0  
   { 880, 512,1000},  //duty=1, dutyLt=0  
   { 919, 512, 941},  //duty=2, dutyLt=0  
   { 945, 512, 910},  //duty=3, dutyLt=0  
   { 963, 512, 892},  //duty=4, dutyLt=0  
   { 975, 512, 873},  //duty=5, dutyLt=0  
   { 983, 512, 867},  //duty=6, dutyLt=0  
   { 990, 512, 858},  //duty=7, dutyLt=0  
   {1001, 512, 847},  //duty=8, dutyLt=0  
   {1008, 512, 833},  //duty=9, dutyLt=0  
   {1013, 512, 827},  //duty=10, dutyLt=0  
   {1017, 512, 821},  //duty=11, dutyLt=0  
   {1019, 512, 812},  //duty=12, dutyLt=0  
   {1022, 512, 808},  //duty=13, dutyLt=0  
   {1024, 512, 804},  //duty=14, dutyLt=0  
   {1025, 512, 798},  //duty=15, dutyLt=0  
   {1027, 512, 787},  //duty=16, dutyLt=0  
   {1027, 512, 789},  //duty=17, dutyLt=0  
   {1028, 512, 786},  //duty=18, dutyLt=0  
   {1028, 512, 781},  //duty=19, dutyLt=0  
   {1025, 512, 774},  //duty=20, dutyLt=0  
   {1020, 512, 767},  //duty=21, dutyLt=0  
   {1017, 512, 757},  //duty=22, dutyLt=0  
   {1011, 512, 747},  //duty=23, dutyLt=0  
   { 995, 512, 733},  //duty=24, dutyLt=0  
   { 512, 512, 512},  //duty=25, dutyLt=0  
   { 575, 512,2026},  //duty=-1, dutyLt=1  
   { 703, 512,1319},  //duty=0, dutyLt=1  
   { 789, 512,1123},  //duty=1, dutyLt=1  
   { 839, 512,1038},  //duty=2, dutyLt=1  
   { 873, 512, 988},  //duty=3, dutyLt=1  
   { 891, 512, 950},  //duty=4, dutyLt=1  
   { 909, 512, 931},  //duty=5, dutyLt=1  
   { 922, 512, 914},  //duty=6, dutyLt=1  
   { 937, 512, 898},  //duty=7, dutyLt=1  
   { 953, 512, 878},  //duty=8, dutyLt=1  
   { 968, 512, 861},  //duty=9, dutyLt=1  
   { 976, 512, 852},  //duty=10, dutyLt=1  
   { 983, 512, 841},  //duty=11, dutyLt=1  
   { 987, 512, 832},  //duty=12, dutyLt=1  
   { 993, 512, 823},  //duty=13, dutyLt=1  
   { 997, 512, 820},  //duty=14, dutyLt=1  
   { 999, 512, 811},  //duty=15, dutyLt=1  
   {1004, 512, 807},  //duty=16, dutyLt=1  
   {1005, 512, 800},  //duty=17, dutyLt=1  
   {1005, 512, 798},  //duty=18, dutyLt=1  
   {1006, 512, 790},  //duty=19, dutyLt=1  
   {1005, 512, 781},  //duty=20, dutyLt=1  
   {1001, 512, 771},  //duty=21, dutyLt=1  
   { 996, 512, 763},  //duty=22, dutyLt=1  
   { 988, 512, 753},  //duty=23, dutyLt=1  
   { 980, 512, 739},  //duty=24, dutyLt=1  
   { 512, 512, 512},  //duty=25, dutyLt=1  
   { 575, 512,2070},  //duty=-1, dutyLt=2  
   { 669, 512,1434},  //duty=0, dutyLt=2  
   { 737, 512,1212},  //duty=1, dutyLt=2  
   { 790, 512,1112},  //duty=2, dutyLt=2  
   { 824, 512,1049},  //duty=3, dutyLt=2  
   { 846, 512, 991},  //duty=4, dutyLt=2  
   { 868, 512, 980},  //duty=5, dutyLt=2  
   { 885, 512, 958},  //duty=6, dutyLt=2  
   { 899, 512, 933},  //duty=7, dutyLt=2  
   { 918, 512, 909},  //duty=8, dutyLt=2  
   { 935, 512, 887},  //duty=9, dutyLt=2  
   { 946, 512, 873},  //duty=10, dutyLt=2  
   { 954, 512, 863},  //duty=11, dutyLt=2  
   { 961, 512, 851},  //duty=12, dutyLt=2  
   { 968, 512, 841},  //duty=13, dutyLt=2  
   { 973, 512, 832},  //duty=14, dutyLt=2  
   { 977, 512, 826},  //duty=15, dutyLt=2  
   { 981, 512, 821},  //duty=16, dutyLt=2  
   { 984, 512, 811},  //duty=17, dutyLt=2  
   { 986, 512, 807},  //duty=18, dutyLt=2  
   { 987, 512, 799},  //duty=19, dutyLt=2  
   { 984, 512, 788},  //duty=20, dutyLt=2  
   { 980, 512, 779},  //duty=21, dutyLt=2  
   { 973, 512, 769},  //duty=22, dutyLt=2  
   { 968, 512, 757},  //duty=23, dutyLt=2  
   { 512, 512, 512},  //duty=24, dutyLt=2  
   { 512, 512, 512},  //duty=25, dutyLt=2  
   { 575, 512,2050},  //duty=-1, dutyLt=3  
   { 650, 512,1509},  //duty=0, dutyLt=3  
   { 708, 512,1285},  //duty=1, dutyLt=3  
   { 757, 512,1172},  //duty=2, dutyLt=3  
   { 785, 512,1084},  //duty=3, dutyLt=3  
   { 814, 512,1056},  //duty=4, dutyLt=3  
   { 835, 512,1021},  //duty=5, dutyLt=3  
   { 852, 512, 995},  //duty=6, dutyLt=3  
   { 873, 512, 968},  //duty=7, dutyLt=3  
   { 893, 512, 938},  //duty=8, dutyLt=3  
   { 908, 512, 908},  //duty=9, dutyLt=3  
   { 921, 512, 894},  //duty=10, dutyLt=3  
   { 931, 512, 879},  //duty=11, dutyLt=3  
   { 939, 512, 868},  //duty=12, dutyLt=3  
   { 947, 512, 856},  //duty=13, dutyLt=3  
   { 953, 512, 846},  //duty=14, dutyLt=3  
   { 958, 512, 840},  //duty=15, dutyLt=3  
   { 963, 512, 830},  //duty=16, dutyLt=3  
   { 966, 512, 820},  //duty=17, dutyLt=3  
   { 974, 512, 816},  //duty=18, dutyLt=3  
   { 967, 512, 811},  //duty=19, dutyLt=3  
   { 981, 512, 793},  //duty=20, dutyLt=3  
   { 960, 512, 786},  //duty=21, dutyLt=3  
   { 953, 512, 775},  //duty=22, dutyLt=3  
   { 944, 512, 762},  //duty=23, dutyLt=3  
   { 512, 512, 512},  //duty=24, dutyLt=3  
   { 512, 512, 512},  //duty=25, dutyLt=3  
   { 576, 512,2031},  //duty=-1, dutyLt=4  
   { 638, 512,1562},  //duty=0, dutyLt=4  
   { 690, 512,1339},  //duty=1, dutyLt=4  
   { 729, 512,1212},  //duty=2, dutyLt=4  
   { 767, 512,1143},  //duty=3, dutyLt=4  
   { 790, 512,1095},  //duty=4, dutyLt=4  
   { 806, 512,1054},  //duty=5, dutyLt=4  
   { 828, 512,1027},  //duty=6, dutyLt=4  
   { 847, 512, 998},  //duty=7, dutyLt=4  
   { 865, 512, 962},  //duty=8, dutyLt=4  
   { 886, 512, 931},  //duty=9, dutyLt=4  
   { 899, 512, 913},  //duty=10, dutyLt=4  
   { 910, 512, 896},  //duty=11, dutyLt=4  
   { 919, 512, 885},  //duty=12, dutyLt=4  
   { 928, 512, 871},  //duty=13, dutyLt=4  
   { 935, 512, 861},  //duty=14, dutyLt=4  
   { 940, 512, 855},  //duty=15, dutyLt=4  
   { 946, 512, 840},  //duty=16, dutyLt=4  
   { 950, 512, 835},  //duty=17, dutyLt=4  
   { 951, 512, 826},  //duty=18, dutyLt=4  
   { 951, 512, 817},  //duty=19, dutyLt=4  
   { 946, 512, 804},  //duty=20, dutyLt=4  
   { 940, 512, 791},  //duty=21, dutyLt=4  
   { 933, 512, 779},  //duty=22, dutyLt=4  
   { 512, 512, 512},  //duty=23, dutyLt=4  
   { 512, 512, 512},  //duty=24, dutyLt=4  
   { 512, 512, 512},  //duty=25, dutyLt=4  
   { 576, 512,2027},  //duty=-1, dutyLt=5  
   { 629, 512,1608},  //duty=0, dutyLt=5  
   { 676, 512,1384},  //duty=1, dutyLt=5  
   { 713, 512,1257},  //duty=2, dutyLt=5  
   { 747, 512,1184},  //duty=3, dutyLt=5  
   { 766, 512,1128},  //duty=4, dutyLt=5  
   { 790, 512,1089},  //duty=5, dutyLt=5  
   { 807, 512,1060},  //duty=6, dutyLt=5  
   { 828, 512,1023},  //duty=7, dutyLt=5  
   { 850, 512, 988},  //duty=8, dutyLt=5  
   { 871, 512, 954},  //duty=9, dutyLt=5  
   { 881, 512, 933},  //duty=10, dutyLt=5  
   { 892, 512, 915},  //duty=11, dutyLt=5  
   { 902, 512, 901},  //duty=12, dutyLt=5  
   { 912, 512, 886},  //duty=13, dutyLt=5  
   { 919, 512, 875},  //duty=14, dutyLt=5  
   { 925, 512, 867},  //duty=15, dutyLt=5  
   { 931, 512, 855},  //duty=16, dutyLt=5  
   { 935, 512, 841},  //duty=17, dutyLt=5  
   { 935, 512, 835},  //duty=18, dutyLt=5  
   { 938, 512, 820},  //duty=19, dutyLt=5  
   { 933, 512, 807},  //duty=20, dutyLt=5  
   { 928, 512, 795},  //duty=21, dutyLt=5  
   { 917, 512, 781},  //duty=22, dutyLt=5  
   { 512, 512, 512},  //duty=23, dutyLt=5  
   { 512, 512, 512},  //duty=24, dutyLt=5  
   { 512, 512, 512},  //duty=25, dutyLt=5  
   { 576, 512,2017},  //duty=-1, dutyLt=6  
   { 623, 512,1638},  //duty=0, dutyLt=6  
   { 664, 512,1412},  //duty=1, dutyLt=6  
   { 699, 512,1293},  //duty=2, dutyLt=6  
   { 728, 512,1214},  //duty=3, dutyLt=6  
   { 754, 512,1164},  //duty=4, dutyLt=6  
   { 774, 512,1119},  //duty=5, dutyLt=6  
   { 786, 512,1081},  //duty=6, dutyLt=6  
   { 811, 512,1047},  //duty=7, dutyLt=6  
   { 829, 512,1006},  //duty=8, dutyLt=6  
   { 851, 512, 969},  //duty=9, dutyLt=6  
   { 865, 512, 947},  //duty=10, dutyLt=6  
   { 876, 512, 929},  //duty=11, dutyLt=6  
   { 887, 512, 914},  //duty=12, dutyLt=6  
   { 898, 512, 898},  //duty=13, dutyLt=6  
   { 905, 512, 886},  //duty=14, dutyLt=6  
   { 911, 512, 874},  //duty=15, dutyLt=6  
   { 918, 512, 862},  //duty=16, dutyLt=6  
   { 920, 512, 854},  //duty=17, dutyLt=6  
   { 920, 512, 842},  //duty=18, dutyLt=6  
   { 918, 512, 831},  //duty=19, dutyLt=6  
   { 914, 512, 813},  //duty=20, dutyLt=6  
   { 913, 512, 798},  //duty=21, dutyLt=6  
   { 512, 512, 512},  //duty=22, dutyLt=6  
   { 512, 512, 512},  //duty=23, dutyLt=6  
   { 512, 512, 512},  //duty=24, dutyLt=6  
   { 512, 512, 512},  //duty=25, dutyLt=6  
   { 576, 512,2010},  //duty=-1, dutyLt=7  
   { 617, 512,1663},  //duty=0, dutyLt=7  
   { 654, 512,1463},  //duty=1, dutyLt=7  
   { 688, 512,1352},  //duty=2, dutyLt=7  
   { 708, 512,1263},  //duty=3, dutyLt=7  
   { 729, 512,1204},  //duty=4, dutyLt=7  
   { 753, 512,1160},  //duty=5, dutyLt=7  
   { 765, 512,1122},  //duty=6, dutyLt=7  
   { 785, 512,1079},  //duty=7, dutyLt=7  
   { 807, 512,1035},  //duty=8, dutyLt=7  
   { 830, 512, 997},  //duty=9, dutyLt=7  
   { 844, 512, 968},  //duty=10, dutyLt=7  
   { 857, 512, 951},  //duty=11, dutyLt=7  
   { 867, 512, 932},  //duty=12, dutyLt=7  
   { 879, 512, 913},  //duty=13, dutyLt=7  
   { 887, 512, 903},  //duty=14, dutyLt=7  
   { 893, 512, 891},  //duty=15, dutyLt=7  
   { 899, 512, 877},  //duty=16, dutyLt=7  
   { 902, 512, 862},  //duty=17, dutyLt=7  
   { 899, 512, 851},  //duty=18, dutyLt=7  
   { 899, 512, 838},  //duty=19, dutyLt=7  
   { 894, 512, 819},  //duty=20, dutyLt=7  
   { 885, 512, 803},  //duty=21, dutyLt=7  
   { 512, 512, 512},  //duty=22, dutyLt=7  
   { 512, 512, 512},  //duty=23, dutyLt=7  
   { 512, 512, 512},  //duty=24, dutyLt=7  
   { 512, 512, 512},  //duty=25, dutyLt=7  
   { 577, 512,1985},  //duty=-1, dutyLt=8  
   { 614, 512,1691},  //duty=0, dutyLt=8  
   { 644, 512,1516},  //duty=1, dutyLt=8  
   { 671, 512,1394},  //duty=2, dutyLt=8  
   { 692, 512,1314},  //duty=3, dutyLt=8  
   { 711, 512,1252},  //duty=4, dutyLt=8  
   { 728, 512,1204},  //duty=5, dutyLt=8  
   { 744, 512,1164},  //duty=6, dutyLt=8  
   { 768, 512,1120},  //duty=7, dutyLt=8  
   { 790, 512,1074},  //duty=8, dutyLt=8  
   { 807, 512,1029},  //duty=9, dutyLt=8  
   { 822, 512,1003},  //duty=10, dutyLt=8  
   { 835, 512, 979},  //duty=11, dutyLt=8  
   { 846, 512, 960},  //duty=12, dutyLt=8  
   { 857, 512, 940},  //duty=13, dutyLt=8  
   { 866, 512, 925},  //duty=14, dutyLt=8  
   { 872, 512, 909},  //duty=15, dutyLt=8  
   { 874, 512, 894},  //duty=16, dutyLt=8  
   { 877, 512, 876},  //duty=17, dutyLt=8  
   { 873, 512, 862},  //duty=18, dutyLt=8  
   { 869, 512, 847},  //duty=19, dutyLt=8  
   { 861, 512, 824},  //duty=20, dutyLt=8  
   { 512, 512, 512},  //duty=21, dutyLt=8  
   { 512, 512, 512},  //duty=22, dutyLt=8  
   { 512, 512, 512},  //duty=23, dutyLt=8  
   { 512, 512, 512},  //duty=24, dutyLt=8  
   { 512, 512, 512},  //duty=25, dutyLt=8  
   { 581, 512,1975},  //duty=-1, dutyLt=9  
   { 609, 512,1730},  //duty=0, dutyLt=9  
   { 635, 512,1563},  //duty=1, dutyLt=9  
   { 658, 512,1446},  //duty=2, dutyLt=9  
   { 677, 512,1365},  //duty=3, dutyLt=9  
   { 696, 512,1299},  //duty=4, dutyLt=9  
   { 711, 512,1249},  //duty=5, dutyLt=9  
   { 724, 512,1211},  //duty=6, dutyLt=9  
   { 742, 512,1158},  //duty=7, dutyLt=9  
   { 764, 512,1109},  //duty=8, dutyLt=9  
   { 786, 512,1061},  //duty=9, dutyLt=9  
   { 805, 512,1035},  //duty=10, dutyLt=9  
   { 813, 512,1007},  //duty=11, dutyLt=9  
   { 825, 512, 983},  //duty=12, dutyLt=9  
   { 836, 512, 965},  //duty=13, dutyLt=9  
   { 843, 512, 946},  //duty=14, dutyLt=9  
   { 847, 512, 929},  //duty=15, dutyLt=9  
   { 849, 512, 907},  //duty=16, dutyLt=9  
   { 847, 512, 889},  //duty=17, dutyLt=9  
   { 844, 512, 870},  //duty=18, dutyLt=9  
   { 841, 512, 853},  //duty=19, dutyLt=9  
   { 512, 512, 512},  //duty=20, dutyLt=9  
   { 512, 512, 512},  //duty=21, dutyLt=9  
   { 512, 512, 512},  //duty=22, dutyLt=9  
   { 512, 512, 512},  //duty=23, dutyLt=9  
   { 512, 512, 512},  //duty=24, dutyLt=9  
   { 512, 512, 512},  //duty=25, dutyLt=9  
   { 581, 512,1967},  //duty=-1, dutyLt=10  
   { 606, 512,1745},  //duty=0, dutyLt=10  
   { 630, 512,1589},  //duty=1, dutyLt=10  
   { 651, 512,1478},  //duty=2, dutyLt=10  
   { 668, 512,1396},  //duty=3, dutyLt=10  
   { 685, 512,1331},  //duty=4, dutyLt=10  
   { 700, 512,1279},  //duty=5, dutyLt=10  
   { 713, 512,1237},  //duty=6, dutyLt=10  
   { 731, 512,1186},  //duty=7, dutyLt=10  
   { 751, 512,1134},  //duty=8, dutyLt=10  
   { 772, 512,1085},  //duty=9, dutyLt=10  
   { 786, 512,1053},  //duty=10, dutyLt=10  
   { 799, 512,1024},  //duty=11, dutyLt=10  
   { 810, 512,1005},  //duty=12, dutyLt=10  
   { 821, 512, 981},  //duty=13, dutyLt=10  
   { 826, 512, 961},  //duty=14, dutyLt=10  
   { 830, 512, 939},  //duty=15, dutyLt=10  
   { 829, 512, 916},  //duty=16, dutyLt=10  
   { 826, 512, 895},  //duty=17, dutyLt=10  
   { 821, 512, 875},  //duty=18, dutyLt=10  
   { 512, 512, 512},  //duty=19, dutyLt=10  
   { 512, 512, 512},  //duty=20, dutyLt=10  
   { 512, 512, 512},  //duty=21, dutyLt=10  
   { 512, 512, 512},  //duty=22, dutyLt=10  
   { 512, 512, 512},  //duty=23, dutyLt=10  
   { 512, 512, 512},  //duty=24, dutyLt=10  
   { 512, 512, 512},  //duty=25, dutyLt=10  
   { 581, 512,1963},  //duty=-1, dutyLt=11  
   { 604, 512,1759},  //duty=0, dutyLt=11  
   { 625, 512,1614},  //duty=1, dutyLt=11  
   { 644, 512,1507},  //duty=2, dutyLt=11  
   { 661, 512,1426},  //duty=3, dutyLt=11  
   { 677, 512,1359},  //duty=4, dutyLt=11  
   { 691, 512,1308},  //duty=5, dutyLt=11  
   { 703, 512,1266},  //duty=6, dutyLt=11  
   { 721, 512,1211},  //duty=7, dutyLt=11  
   { 739, 512,1160},  //duty=8, dutyLt=11  
   { 761, 512,1105},  //duty=9, dutyLt=11  
   { 775, 512,1070},  //duty=10, dutyLt=11  
   { 787, 512,1045},  //duty=11, dutyLt=11  
   { 798, 512,1021},  //duty=12, dutyLt=11  
   { 807, 512, 994},  //duty=13, dutyLt=11  
   { 811, 512, 971},  //duty=14, dutyLt=11  
   { 813, 512, 949},  //duty=15, dutyLt=11  
   { 810, 512, 922},  //duty=16, dutyLt=11  
   { 806, 512, 900},  //duty=17, dutyLt=11  
   { 512, 512, 512},  //duty=18, dutyLt=11  
   { 512, 512, 512},  //duty=19, dutyLt=11  
   { 512, 512, 512},  //duty=20, dutyLt=11  
   { 512, 512, 512},  //duty=21, dutyLt=11  
   { 512, 512, 512},  //duty=22, dutyLt=11  
   { 512, 512, 512},  //duty=23, dutyLt=11  
   { 512, 512, 512},  //duty=24, dutyLt=11  
   { 512, 512, 512},  //duty=25, dutyLt=11  
   { 582, 512,1956},  //duty=-1, dutyLt=12  
   { 602, 512,1769},  //duty=0, dutyLt=12  
   { 622, 512,1629},  //duty=1, dutyLt=12  
   { 640, 512,1524},  //duty=2, dutyLt=12  
   { 656, 512,1444},  //duty=3, dutyLt=12  
   { 670, 512,1382},  //duty=4, dutyLt=12  
   { 684, 512,1330},  //duty=5, dutyLt=12  
   { 695, 512,1285},  //duty=6, dutyLt=12  
   { 712, 512,1231},  //duty=7, dutyLt=12  
   { 731, 512,1177},  //duty=8, dutyLt=12  
   { 751, 512,1126},  //duty=9, dutyLt=12  
   { 764, 512,1093},  //duty=10, dutyLt=12  
   { 778, 512,1056},  //duty=11, dutyLt=12  
   { 785, 512,1039},  //duty=12, dutyLt=12  
   { 794, 512,1004},  //duty=13, dutyLt=12  
   { 796, 512, 981},  //duty=14, dutyLt=12  
   { 796, 512, 956},  //duty=15, dutyLt=12  
   { 793, 512, 926},  //duty=16, dutyLt=12  
   { 512, 512, 512},  //duty=17, dutyLt=12  
   { 512, 512, 512},  //duty=18, dutyLt=12  
   { 512, 512, 512},  //duty=19, dutyLt=12  
   { 512, 512, 512},  //duty=20, dutyLt=12  
   { 512, 512, 512},  //duty=21, dutyLt=12  
   { 512, 512, 512},  //duty=22, dutyLt=12  
   { 512, 512, 512},  //duty=23, dutyLt=12  
   { 512, 512, 512},  //duty=24, dutyLt=12  
   { 512, 512, 512},  //duty=25, dutyLt=12  
   { 582, 512,1948},  //duty=-1, dutyLt=13  
   { 600, 512,1779},  //duty=0, dutyLt=13  
   { 620, 512,1641},  //duty=1, dutyLt=13  
   { 636, 512,1542},  //duty=2, dutyLt=13  
   { 651, 512,1465},  //duty=3, dutyLt=13  
   { 664, 512,1405},  //duty=4, dutyLt=13  
   { 676, 512,1354},  //duty=5, dutyLt=13  
   { 688, 512,1310},  //duty=6, dutyLt=13  
   { 703, 512,1257},  //duty=7, dutyLt=13  
   { 722, 512,1195},  //duty=8, dutyLt=13  
   { 741, 512,1144},  //duty=9, dutyLt=13  
   { 754, 512,1110},  //duty=10, dutyLt=13  
   { 765, 512,1079},  //duty=11, dutyLt=13  
   { 774, 512,1049},  //duty=12, dutyLt=13  
   { 780, 512,1013},  //duty=13, dutyLt=13  
   { 778, 512, 989},  //duty=14, dutyLt=13  
   { 777, 512, 962},  //duty=15, dutyLt=13  
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
   { 582, 512,1949},  //duty=-1, dutyLt=14  
   { 599, 512,1791},  //duty=0, dutyLt=14  
   { 616, 512,1665},  //duty=1, dutyLt=14  
   { 632, 512,1565},  //duty=2, dutyLt=14  
   { 646, 512,1488},  //duty=3, dutyLt=14  
   { 659, 512,1424},  //duty=4, dutyLt=14  
   { 671, 512,1373},  //duty=5, dutyLt=14  
   { 681, 512,1332},  //duty=6, dutyLt=14  
   { 697, 512,1272},  //duty=7, dutyLt=14  
   { 715, 512,1215},  //duty=8, dutyLt=14  
   { 734, 512,1158},  //duty=9, dutyLt=14  
   { 746, 512,1124},  //duty=10, dutyLt=14  
   { 758, 512,1087},  //duty=11, dutyLt=14  
   { 762, 512,1060},  //duty=12, dutyLt=14  
   { 772, 512,1015},  //duty=13, dutyLt=14  
   { 770, 512, 990},  //duty=14, dutyLt=14  
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
   { 583, 512,1939},  //duty=-1, dutyLt=15  
   { 599, 512,1790},  //duty=0, dutyLt=15  
   { 615, 512,1673},  //duty=1, dutyLt=15  
   { 630, 512,1573},  //duty=2, dutyLt=15  
   { 644, 512,1498},  //duty=3, dutyLt=15  
   { 657, 512,1432},  //duty=4, dutyLt=15  
   { 667, 512,1387},  //duty=5, dutyLt=15  
   { 678, 512,1343},  //duty=6, dutyLt=15  
   { 691, 512,1292},  //duty=7, dutyLt=15  
   { 709, 512,1231},  //duty=8, dutyLt=15  
   { 729, 512,1169},  //duty=9, dutyLt=15  
   { 738, 512,1140},  //duty=10, dutyLt=15  
   { 750, 512,1094},  //duty=11, dutyLt=15  
   { 751, 512,1067},  //duty=12, dutyLt=15  
   { 755, 512,1026},  //duty=13, dutyLt=15  
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
   { 583, 512,1932},  //duty=-1, dutyLt=16  
   { 599, 512,1793},  //duty=0, dutyLt=16  
   { 613, 512,1681},  //duty=1, dutyLt=16  
   { 629, 512,1582},  //duty=2, dutyLt=16  
   { 643, 512,1502},  //duty=3, dutyLt=16  
   { 657, 512,1436},  //duty=4, dutyLt=16  
   { 663, 512,1404},  //duty=5, dutyLt=16  
   { 676, 512,1350},  //duty=6, dutyLt=16  
   { 690, 512,1290},  //duty=7, dutyLt=16  
   { 703, 512,1245},  //duty=8, dutyLt=16  
   { 721, 512,1186},  //duty=9, dutyLt=16  
   { 738, 512,1132},  //duty=10, dutyLt=16  
   { 735, 512,1110},  //duty=11, dutyLt=16  
   { 737, 512,1075},  //duty=12, dutyLt=16  
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
   { 582, 512,1942},  //duty=-1, dutyLt=17  
   { 598, 512,1799},  //duty=0, dutyLt=17  
   { 612, 512,1688},  //duty=1, dutyLt=17  
   { 626, 512,1597},  //duty=2, dutyLt=17  
   { 637, 512,1530},  //duty=3, dutyLt=17  
   { 651, 512,1456},  //duty=4, dutyLt=17  
   { 658, 512,1420},  //duty=5, dutyLt=17  
   { 671, 512,1366},  //duty=6, dutyLt=17  
   { 682, 512,1320},  //duty=7, dutyLt=17  
   { 702, 512,1248},  //duty=8, dutyLt=17  
   { 715, 512,1197},  //duty=9, dutyLt=17  
   { 721, 512,1157},  //duty=10, dutyLt=17  
   { 728, 512,1115},  //duty=11, dutyLt=17  
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
   { 583, 512,1937},  //duty=-1, dutyLt=18  
   { 598, 512,1794},  //duty=0, dutyLt=18  
   { 612, 512,1688},  //duty=1, dutyLt=18  
   { 625, 512,1600},  //duty=2, dutyLt=18  
   { 639, 512,1523},  //duty=3, dutyLt=18  
   { 648, 512,1471},  //duty=4, dutyLt=18  
   { 656, 512,1427},  //duty=5, dutyLt=18  
   { 667, 512,1381},  //duty=6, dutyLt=18  
   { 678, 512,1331},  //duty=7, dutyLt=18  
   { 695, 512,1267},  //duty=8, dutyLt=18  
   { 707, 512,1209},  //duty=9, dutyLt=18  
   { 715, 512,1161},  //duty=10, dutyLt=18  
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
   { 584, 512,1925},  //duty=-1, dutyLt=19  
   { 596, 512,1808},  //duty=0, dutyLt=19  
   { 613, 512,1686},  //duty=1, dutyLt=19  
   { 624, 512,1601},  //duty=2, dutyLt=19  
   { 635, 512,1539},  //duty=3, dutyLt=19  
   { 645, 512,1484},  //duty=4, dutyLt=19  
   { 660, 512,1435},  //duty=5, dutyLt=19  
   { 664, 512,1392},  //duty=6, dutyLt=19  
   { 675, 512,1342},  //duty=7, dutyLt=19  
   { 692, 512,1273},  //duty=8, dutyLt=19  
   { 703, 512,1211},  //duty=9, dutyLt=19  
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
   { 585, 512,1918},  //duty=-1, dutyLt=20  
   { 596, 512,1811},  //duty=0, dutyLt=20  
   { 609, 512,1703},  //duty=1, dutyLt=20  
   { 624, 512,1604},  //duty=2, dutyLt=20  
   { 633, 512,1550},  //duty=3, dutyLt=20  
   { 641, 512,1499},  //duty=4, dutyLt=20  
   { 651, 512,1449},  //duty=5, dutyLt=20  
   { 661, 512,1403},  //duty=6, dutyLt=20  
   { 676, 512,1338},  //duty=7, dutyLt=20  
   { 685, 512,1287},  //duty=8, dutyLt=20  
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
   { 584, 512,1919},  //duty=-1, dutyLt=21  
   { 598, 512,1799},  //duty=0, dutyLt=21  
   { 610, 512,1701},  //duty=1, dutyLt=21  
   { 621, 512,1623},  //duty=2, dutyLt=21  
   { 634, 512,1546},  //duty=3, dutyLt=21  
   { 642, 512,1498},  //duty=4, dutyLt=21  
   { 648, 512,1463},  //duty=5, dutyLt=21  
   { 658, 512,1412},  //duty=6, dutyLt=21  
   { 670, 512,1355},  //duty=7, dutyLt=21  
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
   { 586, 512,1907},  //duty=-1, dutyLt=22  
   { 597, 512,1797},  //duty=0, dutyLt=22  
   { 608, 512,1712},  //duty=1, dutyLt=22  
   { 622, 512,1621},  //duty=2, dutyLt=22  
   { 628, 512,1572},  //duty=3, dutyLt=22  
   { 639, 512,1509},  //duty=4, dutyLt=22  
   { 652, 512,1466},  //duty=5, dutyLt=22  
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
   { 586, 512,1903},  //duty=-1, dutyLt=23  
   { 598, 512,1797},  //duty=0, dutyLt=23  
   { 609, 512,1705},  //duty=1, dutyLt=23  
   { 620, 512,1630},  //duty=2, dutyLt=23  
   { 633, 512,1550},  //duty=3, dutyLt=23  
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
   { 586, 512,1903},  //duty=-1, dutyLt=24  
   { 598, 512,1797},  //duty=0, dutyLt=24  
   { 607, 512,1720},  //duty=1, dutyLt=24  
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
   { 587, 512,1893},  //duty=-1, dutyLt=25  
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



