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
   {1061, 512, 987},  //duty=0, dutyLt=-1  
   {1046, 512, 973},  //duty=1, dutyLt=-1  
   {1066, 512, 980},  //duty=2, dutyLt=-1  
   {1063, 512, 973},  //duty=3, dutyLt=-1  
   {1061, 512, 967},  //duty=4, dutyLt=-1  
   {1060, 512, 962},  //duty=5, dutyLt=-1  
   {1054, 512, 956},  //duty=6, dutyLt=-1  
   {1058, 512, 947},  //duty=7, dutyLt=-1  
   {1048, 512, 941},  //duty=8, dutyLt=-1  
   {1051, 512, 936},  //duty=9, dutyLt=-1  
   {1045, 512, 931},  //duty=10, dutyLt=-1  
   {1045, 512, 926},  //duty=11, dutyLt=-1  
   {1043, 512, 922},  //duty=12, dutyLt=-1  
   {1044, 512, 917},  //duty=13, dutyLt=-1  
   {1043, 512, 914},  //duty=14, dutyLt=-1  
   {1043, 512, 910},  //duty=15, dutyLt=-1  
   {1042, 512, 907},  //duty=16, dutyLt=-1  
   {1041, 512, 904},  //duty=17, dutyLt=-1  
   {1041, 512, 901},  //duty=18, dutyLt=-1  
   {1041, 512, 898},  //duty=19, dutyLt=-1  
   {1040, 512, 895},  //duty=20, dutyLt=-1  
   {1039, 512, 892},  //duty=21, dutyLt=-1  
   {1039, 512, 889},  //duty=22, dutyLt=-1  
   {1038, 512, 886},  //duty=23, dutyLt=-1  
   {1035, 512, 881},  //duty=24, dutyLt=-1  
   {1030, 512, 875},  //duty=25, dutyLt=-1  
   { 456, 512,1912},  //duty=-1, dutyLt=0  
   { 747, 512,1151},  //duty=0, dutyLt=0  
   { 867, 512,1077},  //duty=1, dutyLt=0  
   { 916, 512,1039},  //duty=2, dutyLt=0  
   { 945, 512,1019},  //duty=3, dutyLt=0  
   { 957, 512,1004},  //duty=4, dutyLt=0  
   { 974, 512, 993},  //duty=5, dutyLt=0  
   { 979, 512, 982},  //duty=6, dutyLt=0  
   { 984, 512, 971},  //duty=7, dutyLt=0  
   { 997, 512, 962},  //duty=8, dutyLt=0  
   {1000, 512, 952},  //duty=9, dutyLt=0  
   {1005, 512, 946},  //duty=10, dutyLt=0  
   {1009, 512, 940},  //duty=11, dutyLt=0  
   {1011, 512, 935},  //duty=12, dutyLt=0  
   {1013, 512, 929},  //duty=13, dutyLt=0  
   {1015, 512, 926},  //duty=14, dutyLt=0  
   {1016, 512, 921},  //duty=15, dutyLt=0  
   {1018, 512, 917},  //duty=16, dutyLt=0  
   {1019, 512, 913},  //duty=17, dutyLt=0  
   {1019, 512, 910},  //duty=18, dutyLt=0  
   {1020, 512, 906},  //duty=19, dutyLt=0  
   {1021, 512, 902},  //duty=20, dutyLt=0  
   {1022, 512, 901},  //duty=21, dutyLt=0  
   {1021, 512, 897},  //duty=22, dutyLt=0  
   {1021, 512, 894},  //duty=23, dutyLt=0  
   {1018, 512, 888},  //duty=24, dutyLt=0  
   { 512, 512, 512},  //duty=25, dutyLt=0  
   { 458, 512,1864},  //duty=-1, dutyLt=1  
   { 647, 512,1269},  //duty=0, dutyLt=1  
   { 755, 512,1151},  //duty=1, dutyLt=1  
   { 824, 512,1095},  //duty=2, dutyLt=1  
   { 863, 512,1062},  //duty=3, dutyLt=1  
   { 889, 512,1041},  //duty=4, dutyLt=1  
   { 908, 512,1023},  //duty=5, dutyLt=1  
   { 925, 512,1007},  //duty=6, dutyLt=1  
   { 933, 512, 995},  //duty=7, dutyLt=1  
   { 949, 512, 981},  //duty=8, dutyLt=1  
   { 963, 512, 968},  //duty=9, dutyLt=1  
   { 971, 512, 960},  //duty=10, dutyLt=1  
   { 977, 512, 954},  //duty=11, dutyLt=1  
   { 982, 512, 948},  //duty=12, dutyLt=1  
   { 988, 512, 941},  //duty=13, dutyLt=1  
   { 991, 512, 935},  //duty=14, dutyLt=1  
   { 993, 512, 931},  //duty=15, dutyLt=1  
   { 996, 512, 926},  //duty=16, dutyLt=1  
   { 999, 512, 922},  //duty=17, dutyLt=1  
   {1000, 512, 918},  //duty=18, dutyLt=1  
   {1001, 512, 915},  //duty=19, dutyLt=1  
   {1003, 512, 910},  //duty=20, dutyLt=1  
   {1005, 512, 908},  //duty=21, dutyLt=1  
   {1005, 512, 904},  //duty=22, dutyLt=1  
   {1005, 512, 900},  //duty=23, dutyLt=1  
   {1003, 512, 894},  //duty=24, dutyLt=1  
   { 512, 512, 512},  //duty=25, dutyLt=1  
   { 459, 512,1866},  //duty=-1, dutyLt=2  
   { 603, 512,1375},  //duty=0, dutyLt=2  
   { 698, 512,1212},  //duty=1, dutyLt=2  
   { 759, 512,1140},  //duty=2, dutyLt=2  
   { 809, 512,1100},  //duty=3, dutyLt=2  
   { 838, 512,1072},  //duty=4, dutyLt=2  
   { 858, 512,1049},  //duty=5, dutyLt=2  
   { 876, 512,1032},  //duty=6, dutyLt=2  
   { 893, 512,1016},  //duty=7, dutyLt=2  
   { 913, 512, 999},  //duty=8, dutyLt=2  
   { 931, 512, 984},  //duty=9, dutyLt=2  
   { 943, 512, 974},  //duty=10, dutyLt=2  
   { 951, 512, 966},  //duty=11, dutyLt=2  
   { 958, 512, 959},  //duty=12, dutyLt=2  
   { 965, 512, 951},  //duty=13, dutyLt=2  
   { 970, 512, 945},  //duty=14, dutyLt=2  
   { 973, 512, 940},  //duty=15, dutyLt=2  
   { 977, 512, 934},  //duty=16, dutyLt=2  
   { 981, 512, 930},  //duty=17, dutyLt=2  
   { 983, 512, 926},  //duty=18, dutyLt=2  
   { 985, 512, 922},  //duty=19, dutyLt=2  
   { 988, 512, 918},  //duty=20, dutyLt=2  
   { 989, 512, 914},  //duty=21, dutyLt=2  
   { 990, 512, 910},  //duty=22, dutyLt=2  
   { 991, 512, 906},  //duty=23, dutyLt=2  
   { 512, 512, 512},  //duty=24, dutyLt=2  
   { 512, 512, 512},  //duty=25, dutyLt=2  
   { 461, 512,1863},  //duty=-1, dutyLt=3  
   { 576, 512,1436},  //duty=0, dutyLt=3  
   { 662, 512,1259},  //duty=1, dutyLt=3  
   { 719, 512,1180},  //duty=2, dutyLt=3  
   { 769, 512,1131},  //duty=3, dutyLt=3  
   { 800, 512,1099},  //duty=4, dutyLt=3  
   { 824, 512,1072},  //duty=5, dutyLt=3  
   { 838, 512,1054},  //duty=6, dutyLt=3  
   { 862, 512,1035},  //duty=7, dutyLt=3  
   { 885, 512,1016},  //duty=8, dutyLt=3  
   { 910, 512, 997},  //duty=9, dutyLt=3  
   { 918, 512, 987},  //duty=10, dutyLt=3  
   { 929, 512, 977},  //duty=11, dutyLt=3  
   { 937, 512, 969},  //duty=12, dutyLt=3  
   { 945, 512, 960},  //duty=13, dutyLt=3  
   { 951, 512, 955},  //duty=14, dutyLt=3  
   { 959, 512, 949},  //duty=15, dutyLt=3  
   { 961, 512, 942},  //duty=16, dutyLt=3  
   { 965, 512, 937},  //duty=17, dutyLt=3  
   { 968, 512, 933},  //duty=18, dutyLt=3  
   { 970, 512, 929},  //duty=19, dutyLt=3  
   { 974, 512, 925},  //duty=20, dutyLt=3  
   { 976, 512, 920},  //duty=21, dutyLt=3  
   { 977, 512, 916},  //duty=22, dutyLt=3  
   { 977, 512, 912},  //duty=23, dutyLt=3  
   { 512, 512, 512},  //duty=24, dutyLt=3  
   { 512, 512, 512},  //duty=25, dutyLt=3  
   { 460, 512,1934},  //duty=-1, dutyLt=4  
   { 559, 512,1478},  //duty=0, dutyLt=4  
   { 638, 512,1299},  //duty=1, dutyLt=4  
   { 692, 512,1212},  //duty=2, dutyLt=4  
   { 733, 512,1158},  //duty=3, dutyLt=4  
   { 772, 512,1121},  //duty=4, dutyLt=4  
   { 797, 512,1089},  //duty=5, dutyLt=4  
   { 812, 512,1074},  //duty=6, dutyLt=4  
   { 835, 512,1052},  //duty=7, dutyLt=4  
   { 860, 512,1031},  //duty=8, dutyLt=4  
   { 883, 512,1010},  //duty=9, dutyLt=4  
   { 898, 512, 998},  //duty=10, dutyLt=4  
   { 909, 512, 988},  //duty=11, dutyLt=4  
   { 920, 512, 979},  //duty=12, dutyLt=4  
   { 928, 512, 969},  //duty=13, dutyLt=4  
   { 934, 512, 962},  //duty=14, dutyLt=4  
   { 940, 512, 957},  //duty=15, dutyLt=4  
   { 946, 512, 949},  //duty=16, dutyLt=4  
   { 950, 512, 945},  //duty=17, dutyLt=4  
   { 954, 512, 939},  //duty=18, dutyLt=4  
   { 957, 512, 936},  //duty=19, dutyLt=4  
   { 961, 512, 931},  //duty=20, dutyLt=4  
   { 963, 512, 926},  //duty=21, dutyLt=4  
   { 965, 512, 922},  //duty=22, dutyLt=4  
   { 512, 512, 512},  //duty=23, dutyLt=4  
   { 512, 512, 512},  //duty=24, dutyLt=4  
   { 512, 512, 512},  //duty=25, dutyLt=4  
   { 461, 512,1918},  //duty=-1, dutyLt=5  
   { 547, 512,1511},  //duty=0, dutyLt=5  
   { 618, 512,1334},  //duty=1, dutyLt=5  
   { 673, 512,1241},  //duty=2, dutyLt=5  
   { 710, 512,1182},  //duty=3, dutyLt=5  
   { 740, 512,1141},  //duty=4, dutyLt=5  
   { 767, 512,1115},  //duty=5, dutyLt=5  
   { 789, 512,1093},  //duty=6, dutyLt=5  
   { 818, 512,1069},  //duty=7, dutyLt=5  
   { 840, 512,1046},  //duty=8, dutyLt=5  
   { 864, 512,1023},  //duty=9, dutyLt=5  
   { 879, 512,1010},  //duty=10, dutyLt=5  
   { 892, 512, 998},  //duty=11, dutyLt=5  
   { 902, 512, 988},  //duty=12, dutyLt=5  
   { 912, 512, 979},  //duty=13, dutyLt=5  
   { 920, 512, 971},  //duty=14, dutyLt=5  
   { 926, 512, 964},  //duty=15, dutyLt=5  
   { 933, 512, 957},  //duty=16, dutyLt=5  
   { 938, 512, 952},  //duty=17, dutyLt=5  
   { 942, 512, 946},  //duty=18, dutyLt=5  
   { 945, 512, 942},  //duty=19, dutyLt=5  
   { 949, 512, 936},  //duty=20, dutyLt=5  
   { 952, 512, 932},  //duty=21, dutyLt=5  
   { 954, 512, 928},  //duty=22, dutyLt=5  
   { 512, 512, 512},  //duty=23, dutyLt=5  
   { 512, 512, 512},  //duty=24, dutyLt=5  
   { 512, 512, 512},  //duty=25, dutyLt=5  
   { 461, 512,1911},  //duty=-1, dutyLt=6  
   { 538, 512,1539},  //duty=0, dutyLt=6  
   { 604, 512,1361},  //duty=1, dutyLt=6  
   { 653, 512,1266},  //duty=2, dutyLt=6  
   { 692, 512,1204},  //duty=3, dutyLt=6  
   { 722, 512,1159},  //duty=4, dutyLt=6  
   { 748, 512,1133},  //duty=5, dutyLt=6  
   { 769, 512,1110},  //duty=6, dutyLt=6  
   { 795, 512,1085},  //duty=7, dutyLt=6  
   { 822, 512,1058},  //duty=8, dutyLt=6  
   { 848, 512,1034},  //duty=9, dutyLt=6  
   { 863, 512,1019},  //duty=10, dutyLt=6  
   { 876, 512,1007},  //duty=11, dutyLt=6  
   { 887, 512, 997},  //duty=12, dutyLt=6  
   { 899, 512, 986},  //duty=13, dutyLt=6  
   { 906, 512, 976},  //duty=14, dutyLt=6  
   { 913, 512, 972},  //duty=15, dutyLt=6  
   { 921, 512, 963},  //duty=16, dutyLt=6  
   { 926, 512, 958},  //duty=17, dutyLt=6  
   { 930, 512, 952},  //duty=18, dutyLt=6  
   { 934, 512, 948},  //duty=19, dutyLt=6  
   { 938, 512, 941},  //duty=20, dutyLt=6  
   { 941, 512, 937},  //duty=21, dutyLt=6  
   { 512, 512, 512},  //duty=22, dutyLt=6  
   { 512, 512, 512},  //duty=23, dutyLt=6  
   { 512, 512, 512},  //duty=24, dutyLt=6  
   { 512, 512, 512},  //duty=25, dutyLt=6  
   { 464, 512,1914},  //duty=-1, dutyLt=7  
   { 531, 512,1565},  //duty=0, dutyLt=7  
   { 587, 512,1399},  //duty=1, dutyLt=7  
   { 632, 512,1300},  //duty=2, dutyLt=7  
   { 674, 512,1237},  //duty=3, dutyLt=7  
   { 700, 512,1182},  //duty=4, dutyLt=7  
   { 724, 512,1159},  //duty=5, dutyLt=7  
   { 746, 512,1135},  //duty=6, dutyLt=7  
   { 772, 512,1105},  //duty=7, dutyLt=7  
   { 799, 512,1076},  //duty=8, dutyLt=7  
   { 826, 512,1050},  //duty=9, dutyLt=7  
   { 842, 512,1033},  //duty=10, dutyLt=7  
   { 856, 512,1020},  //duty=11, dutyLt=7  
   { 872, 512,1009},  //duty=12, dutyLt=7  
   { 880, 512, 997},  //duty=13, dutyLt=7  
   { 889, 512, 989},  //duty=14, dutyLt=7  
   { 900, 512, 980},  //duty=15, dutyLt=7  
   { 904, 512, 973},  //duty=16, dutyLt=7  
   { 910, 512, 966},  //duty=17, dutyLt=7  
   { 915, 512, 960},  //duty=18, dutyLt=7  
   { 919, 512, 956},  //duty=19, dutyLt=7  
   { 926, 512, 949},  //duty=20, dutyLt=7  
   { 927, 512, 944},  //duty=21, dutyLt=7  
   { 512, 512, 512},  //duty=22, dutyLt=7  
   { 512, 512, 512},  //duty=23, dutyLt=7  
   { 512, 512, 512},  //duty=24, dutyLt=7  
   { 512, 512, 512},  //duty=25, dutyLt=7  
   { 465, 512,1906},  //duty=-1, dutyLt=8  
   { 524, 512,1599},  //duty=0, dutyLt=8  
   { 575, 512,1433},  //duty=1, dutyLt=8  
   { 615, 512,1338},  //duty=2, dutyLt=8  
   { 651, 512,1264},  //duty=3, dutyLt=8  
   { 674, 512,1221},  //duty=4, dutyLt=8  
   { 697, 512,1186},  //duty=5, dutyLt=8  
   { 718, 512,1159},  //duty=6, dutyLt=8  
   { 747, 512,1127},  //duty=7, dutyLt=8  
   { 774, 512,1097},  //duty=8, dutyLt=8  
   { 802, 512,1069},  //duty=9, dutyLt=8  
   { 819, 512,1050},  //duty=10, dutyLt=8  
   { 834, 512,1036},  //duty=11, dutyLt=8  
   { 846, 512,1023},  //duty=12, dutyLt=8  
   { 859, 512,1010},  //duty=13, dutyLt=8  
   { 868, 512,1001},  //duty=14, dutyLt=8  
   { 876, 512, 992},  //duty=15, dutyLt=8  
   { 885, 512, 983},  //duty=16, dutyLt=8  
   { 895, 512, 976},  //duty=17, dutyLt=8  
   { 897, 512, 970},  //duty=18, dutyLt=8  
   { 902, 512, 965},  //duty=19, dutyLt=8  
   { 907, 512, 958},  //duty=20, dutyLt=8  
   { 512, 512, 512},  //duty=21, dutyLt=8  
   { 512, 512, 512},  //duty=22, dutyLt=8  
   { 512, 512, 512},  //duty=23, dutyLt=8  
   { 512, 512, 512},  //duty=24, dutyLt=8  
   { 512, 512, 512},  //duty=25, dutyLt=8  
   { 466, 512,1898},  //duty=-1, dutyLt=9  
   { 516, 512,1631},  //duty=0, dutyLt=9  
   { 559, 512,1470},  //duty=1, dutyLt=9  
   { 598, 512,1371},  //duty=2, dutyLt=9  
   { 626, 512,1301},  //duty=3, dutyLt=9  
   { 655, 512,1254},  //duty=4, dutyLt=9  
   { 681, 512,1218},  //duty=5, dutyLt=9  
   { 697, 512,1191},  //duty=6, dutyLt=9  
   { 722, 512,1155},  //duty=7, dutyLt=9  
   { 750, 512,1120},  //duty=8, dutyLt=9  
   { 777, 512,1089},  //duty=9, dutyLt=9  
   { 795, 512,1069},  //duty=10, dutyLt=9  
   { 811, 512,1051},  //duty=11, dutyLt=9  
   { 824, 512,1039},  //duty=12, dutyLt=9  
   { 838, 512,1025},  //duty=13, dutyLt=9  
   { 848, 512,1014},  //duty=14, dutyLt=9  
   { 856, 512,1006},  //duty=15, dutyLt=9  
   { 865, 512, 996},  //duty=16, dutyLt=9  
   { 880, 512, 984},  //duty=17, dutyLt=9  
   { 878, 512, 981},  //duty=18, dutyLt=9  
   { 882, 512, 976},  //duty=19, dutyLt=9  
   { 512, 512, 512},  //duty=20, dutyLt=9  
   { 512, 512, 512},  //duty=21, dutyLt=9  
   { 512, 512, 512},  //duty=22, dutyLt=9  
   { 512, 512, 512},  //duty=23, dutyLt=9  
   { 512, 512, 512},  //duty=24, dutyLt=9  
   { 512, 512, 512},  //duty=25, dutyLt=9  
   { 467, 512,1898},  //duty=-1, dutyLt=10  
   { 512, 512,1652},  //duty=0, dutyLt=10  
   { 550, 512,1495},  //duty=1, dutyLt=10  
   { 586, 512,1386},  //duty=2, dutyLt=10  
   { 614, 512,1323},  //duty=3, dutyLt=10  
   { 641, 512,1278},  //duty=4, dutyLt=10  
   { 663, 512,1240},  //duty=5, dutyLt=10  
   { 682, 512,1209},  //duty=6, dutyLt=10  
   { 707, 512,1172},  //duty=7, dutyLt=10  
   { 734, 512,1136},  //duty=8, dutyLt=10  
   { 763, 512,1100},  //duty=9, dutyLt=10  
   { 780, 512,1081},  //duty=10, dutyLt=10  
   { 795, 512,1065},  //duty=11, dutyLt=10  
   { 809, 512,1051},  //duty=12, dutyLt=10  
   { 823, 512,1035},  //duty=13, dutyLt=10  
   { 833, 512,1024},  //duty=14, dutyLt=10  
   { 842, 512,1014},  //duty=15, dutyLt=10  
   { 852, 512,1004},  //duty=16, dutyLt=10  
   { 859, 512, 996},  //duty=17, dutyLt=10  
   { 865, 512, 989},  //duty=18, dutyLt=10  
   { 512, 512, 512},  //duty=19, dutyLt=10  
   { 512, 512, 512},  //duty=20, dutyLt=10  
   { 512, 512, 512},  //duty=21, dutyLt=10  
   { 512, 512, 512},  //duty=22, dutyLt=10  
   { 512, 512, 512},  //duty=23, dutyLt=10  
   { 512, 512, 512},  //duty=24, dutyLt=10  
   { 512, 512, 512},  //duty=25, dutyLt=10  
   { 468, 512,1894},  //duty=-1, dutyLt=11  
   { 509, 512,1661},  //duty=0, dutyLt=11  
   { 547, 512,1512},  //duty=1, dutyLt=11  
   { 578, 512,1415},  //duty=2, dutyLt=11  
   { 606, 512,1349},  //duty=3, dutyLt=11  
   { 630, 512,1297},  //duty=4, dutyLt=11  
   { 651, 512,1257},  //duty=5, dutyLt=11  
   { 670, 512,1227},  //duty=6, dutyLt=11  
   { 695, 512,1189},  //duty=7, dutyLt=11  
   { 722, 512,1151},  //duty=8, dutyLt=11  
   { 748, 512,1117},  //duty=9, dutyLt=11  
   { 767, 512,1095},  //duty=10, dutyLt=11  
   { 782, 512,1077},  //duty=11, dutyLt=11  
   { 796, 512,1061},  //duty=12, dutyLt=11  
   { 815, 512,1043},  //duty=13, dutyLt=11  
   { 821, 512,1033},  //duty=14, dutyLt=11  
   { 830, 512,1023},  //duty=15, dutyLt=11  
   { 840, 512,1012},  //duty=16, dutyLt=11  
   { 847, 512,1004},  //duty=17, dutyLt=11  
   { 512, 512, 512},  //duty=18, dutyLt=11  
   { 512, 512, 512},  //duty=19, dutyLt=11  
   { 512, 512, 512},  //duty=20, dutyLt=11  
   { 512, 512, 512},  //duty=21, dutyLt=11  
   { 512, 512, 512},  //duty=22, dutyLt=11  
   { 512, 512, 512},  //duty=23, dutyLt=11  
   { 512, 512, 512},  //duty=24, dutyLt=11  
   { 512, 512, 512},  //duty=25, dutyLt=11  
   { 468, 512,1890},  //duty=-1, dutyLt=12  
   { 506, 512,1677},  //duty=0, dutyLt=12  
   { 540, 512,1519},  //duty=1, dutyLt=12  
   { 572, 512,1432},  //duty=2, dutyLt=12  
   { 598, 512,1366},  //duty=3, dutyLt=12  
   { 621, 512,1314},  //duty=4, dutyLt=12  
   { 641, 512,1273},  //duty=5, dutyLt=12  
   { 665, 512,1238},  //duty=6, dutyLt=12  
   { 684, 512,1203},  //duty=7, dutyLt=12  
   { 710, 512,1164},  //duty=8, dutyLt=12  
   { 737, 512,1128},  //duty=9, dutyLt=12  
   { 755, 512,1105},  //duty=10, dutyLt=12  
   { 772, 512,1082},  //duty=11, dutyLt=12  
   { 791, 512,1065},  //duty=12, dutyLt=12  
   { 799, 512,1054},  //duty=13, dutyLt=12  
   { 810, 512,1041},  //duty=14, dutyLt=12  
   { 819, 512,1031},  //duty=15, dutyLt=12  
   { 829, 512,1020},  //duty=16, dutyLt=12  
   { 512, 512, 512},  //duty=17, dutyLt=12  
   { 512, 512, 512},  //duty=18, dutyLt=12  
   { 512, 512, 512},  //duty=19, dutyLt=12  
   { 512, 512, 512},  //duty=20, dutyLt=12  
   { 512, 512, 512},  //duty=21, dutyLt=12  
   { 512, 512, 512},  //duty=22, dutyLt=12  
   { 512, 512, 512},  //duty=23, dutyLt=12  
   { 512, 512, 512},  //duty=24, dutyLt=12  
   { 512, 512, 512},  //duty=25, dutyLt=12  
   { 469, 512,1885},  //duty=-1, dutyLt=13  
   { 504, 512,1685},  //duty=0, dutyLt=13  
   { 537, 512,1545},  //duty=1, dutyLt=13  
   { 566, 512,1450},  //duty=2, dutyLt=13  
   { 590, 512,1385},  //duty=3, dutyLt=13  
   { 613, 512,1332},  //duty=4, dutyLt=13  
   { 632, 512,1291},  //duty=5, dutyLt=13  
   { 654, 512,1240},  //duty=6, dutyLt=13  
   { 671, 512,1214},  //duty=7, dutyLt=13  
   { 698, 512,1178},  //duty=8, dutyLt=13  
   { 725, 512,1140},  //duty=9, dutyLt=13  
   { 746, 512,1110},  //duty=10, dutyLt=13  
   { 758, 512,1098},  //duty=11, dutyLt=13  
   { 778, 512,1077},  //duty=12, dutyLt=13  
   { 787, 512,1063},  //duty=13, dutyLt=13  
   { 798, 512,1050},  //duty=14, dutyLt=13  
   { 807, 512,1039},  //duty=15, dutyLt=13  
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
   { 470, 512,1885},  //duty=-1, dutyLt=14  
   { 503, 512,1683},  //duty=0, dutyLt=14  
   { 533, 512,1558},  //duty=1, dutyLt=14  
   { 561, 512,1467},  //duty=2, dutyLt=14  
   { 587, 512,1388},  //duty=3, dutyLt=14  
   { 606, 512,1346},  //duty=4, dutyLt=14  
   { 625, 512,1303},  //duty=5, dutyLt=14  
   { 642, 512,1269},  //duty=6, dutyLt=14  
   { 664, 512,1230},  //duty=7, dutyLt=14  
   { 690, 512,1189},  //duty=8, dutyLt=14  
   { 716, 512,1150},  //duty=9, dutyLt=14  
   { 734, 512,1127},  //duty=10, dutyLt=14  
   { 753, 512,1099},  //duty=11, dutyLt=14  
   { 769, 512,1085},  //duty=12, dutyLt=14  
   { 780, 512,1069},  //duty=13, dutyLt=14  
   { 789, 512,1057},  //duty=14, dutyLt=14  
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
   { 471, 512,1877},  //duty=-1, dutyLt=15  
   { 502, 512,1690},  //duty=0, dutyLt=15  
   { 533, 512,1541},  //duty=1, dutyLt=15  
   { 558, 512,1472},  //duty=2, dutyLt=15  
   { 580, 512,1409},  //duty=3, dutyLt=15  
   { 601, 512,1352},  //duty=4, dutyLt=15  
   { 620, 512,1307},  //duty=5, dutyLt=15  
   { 637, 512,1279},  //duty=6, dutyLt=15  
   { 664, 512,1227},  //duty=7, dutyLt=15  
   { 684, 512,1196},  //duty=8, dutyLt=15  
   { 710, 512,1157},  //duty=9, dutyLt=15  
   { 727, 512,1133},  //duty=10, dutyLt=15  
   { 743, 512,1112},  //duty=11, dutyLt=15  
   { 756, 512,1095},  //duty=12, dutyLt=15  
   { 771, 512,1077},  //duty=13, dutyLt=15  
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
   { 470, 512,1857},  //duty=-1, dutyLt=16  
   { 500, 512,1693},  //duty=0, dutyLt=16  
   { 530, 512,1564},  //duty=1, dutyLt=16  
   { 556, 512,1472},  //duty=2, dutyLt=16  
   { 575, 512,1419},  //duty=3, dutyLt=16  
   { 599, 512,1357},  //duty=4, dutyLt=16  
   { 614, 512,1322},  //duty=5, dutyLt=16  
   { 632, 512,1284},  //duty=6, dutyLt=16  
   { 651, 512,1250},  //duty=7, dutyLt=16  
   { 676, 512,1208},  //duty=8, dutyLt=16  
   { 703, 512,1165},  //duty=9, dutyLt=16  
   { 719, 512,1142},  //duty=10, dutyLt=16  
   { 734, 512,1122},  //duty=11, dutyLt=16  
   { 747, 512,1103},  //duty=12, dutyLt=16  
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
   { 477, 512,1862},  //duty=-1, dutyLt=17  
   { 499, 512,1700},  //duty=0, dutyLt=17  
   { 527, 512,1577},  //duty=1, dutyLt=17  
   { 550, 512,1495},  //duty=2, dutyLt=17  
   { 572, 512,1428},  //duty=3, dutyLt=17  
   { 592, 512,1366},  //duty=4, dutyLt=17  
   { 608, 512,1337},  //duty=5, dutyLt=17  
   { 625, 512,1300},  //duty=6, dutyLt=17  
   { 646, 512,1258},  //duty=7, dutyLt=17  
   { 672, 512,1213},  //duty=8, dutyLt=17  
   { 703, 512,1168},  //duty=9, dutyLt=17  
   { 712, 512,1150},  //duty=10, dutyLt=17  
   { 736, 512,1121},  //duty=11, dutyLt=17  
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
   { 472, 512,1859},  //duty=-1, dutyLt=18  
   { 500, 512,1690},  //duty=0, dutyLt=18  
   { 527, 512,1574},  //duty=1, dutyLt=18  
   { 548, 512,1499},  //duty=2, dutyLt=18  
   { 570, 512,1434},  //duty=3, dutyLt=18  
   { 588, 512,1385},  //duty=4, dutyLt=18  
   { 609, 512,1330},  //duty=5, dutyLt=18  
   { 627, 512,1293},  //duty=6, dutyLt=18  
   { 642, 512,1264},  //duty=7, dutyLt=18  
   { 667, 512,1218},  //duty=8, dutyLt=18  
   { 690, 512,1181},  //duty=9, dutyLt=18  
   { 708, 512,1154},  //duty=10, dutyLt=18  
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
   { 472, 512,1859},  //duty=-1, dutyLt=19  
   { 501, 512,1685},  //duty=0, dutyLt=19  
   { 524, 512,1590},  //duty=1, dutyLt=19  
   { 546, 512,1505},  //duty=2, dutyLt=19  
   { 567, 512,1440},  //duty=3, dutyLt=19  
   { 590, 512,1376},  //duty=4, dutyLt=19  
   { 606, 512,1338},  //duty=5, dutyLt=19  
   { 624, 512,1299},  //duty=6, dutyLt=19  
   { 643, 512,1258},  //duty=7, dutyLt=19  
   { 664, 512,1224},  //duty=8, dutyLt=19  
   { 688, 512,1184},  //duty=9, dutyLt=19  
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
   { 472, 512,1844},  //duty=-1, dutyLt=20  
   { 498, 512,1689},  //duty=0, dutyLt=20  
   { 522, 512,1598},  //duty=1, dutyLt=20  
   { 546, 512,1505},  //duty=2, dutyLt=20  
   { 564, 512,1447},  //duty=3, dutyLt=20  
   { 583, 512,1395},  //duty=4, dutyLt=20  
   { 599, 512,1356},  //duty=5, dutyLt=20  
   { 620, 512,1297},  //duty=6, dutyLt=20  
   { 636, 512,1274},  //duty=7, dutyLt=20  
   { 657, 512,1235},  //duty=8, dutyLt=20  
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
   { 472, 512,1847},  //duty=-1, dutyLt=21  
   { 497, 512,1709},  //duty=0, dutyLt=21  
   { 525, 512,1580},  //duty=1, dutyLt=21  
   { 543, 512,1515},  //duty=2, dutyLt=21  
   { 563, 512,1453},  //duty=3, dutyLt=21  
   { 582, 512,1397},  //duty=4, dutyLt=21  
   { 599, 512,1351},  //duty=5, dutyLt=21  
   { 618, 512,1308},  //duty=6, dutyLt=21  
   { 638, 512,1267},  //duty=7, dutyLt=21  
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
   { 474, 512,1836},  //duty=-1, dutyLt=22  
   { 497, 512,1702},  //duty=0, dutyLt=22  
   { 521, 512,1596},  //duty=1, dutyLt=22  
   { 543, 512,1512},  //duty=2, dutyLt=22  
   { 561, 512,1455},  //duty=3, dutyLt=22  
   { 580, 512,1399},  //duty=4, dutyLt=22  
   { 594, 512,1364},  //duty=5, dutyLt=22  
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
   { 474, 512,1831},  //duty=-1, dutyLt=23  
   { 497, 512,1706},  //duty=0, dutyLt=23  
   { 524, 512,1579},  //duty=1, dutyLt=23  
   { 541, 512,1517},  //duty=2, dutyLt=23  
   { 559, 512,1460},  //duty=3, dutyLt=23  
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
   { 474, 512,1829},  //duty=-1, dutyLt=24  
   { 502, 512,1665},  //duty=0, dutyLt=24  
   { 521, 512,1589},  //duty=1, dutyLt=24  
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
   { 475, 512,1825},  //duty=-1, dutyLt=25  
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



