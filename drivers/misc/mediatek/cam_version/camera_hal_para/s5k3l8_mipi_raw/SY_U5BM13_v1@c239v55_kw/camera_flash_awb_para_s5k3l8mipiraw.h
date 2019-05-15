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
            512,  // FlashPreferenceGain.i4R
            512,  // FlashPreferenceGain.i4G
            512     // FlashPreferenceGain.i4B
         },
},

// Flash AWB calibration
{{
   { 512, 512, 512},  //duty=-1, dutyLt=-1  
   {1097, 512, 785},  //duty=0, dutyLt=-1  
   {1090, 512, 792},  //duty=1, dutyLt=-1  
   {1091, 512, 798},  //duty=2, dutyLt=-1  
   {1092, 512, 801},  //duty=3, dutyLt=-1  
   {1090, 512, 803},  //duty=4, dutyLt=-1  
   {1089, 512, 805},  //duty=5, dutyLt=-1  
   {1088, 512, 808},  //duty=6, dutyLt=-1  
   {1088, 512, 808},  //duty=7, dutyLt=-1  
   {1087, 512, 812},  //duty=8, dutyLt=-1  
   {1086, 512, 810},  //duty=9, dutyLt=-1  
   {1086, 512, 815},  //duty=10, dutyLt=-1  
   {1086, 512, 813},  //duty=11, dutyLt=-1  
   {1079, 512, 810},  //duty=12, dutyLt=-1  
   {1064, 512, 793},  //duty=13, dutyLt=-1  
   {1059, 512, 784},  //duty=14, dutyLt=-1  
   {1053, 512, 786},  //duty=15, dutyLt=-1  
   {1063, 512, 782},  //duty=16, dutyLt=-1  
   {1055, 512, 785},  //duty=17, dutyLt=-1  
   {1062, 512, 783},  //duty=18, dutyLt=-1  
   {1056, 512, 785},  //duty=19, dutyLt=-1  
   {1061, 512, 783},  //duty=20, dutyLt=-1  
   {1063, 512, 782},  //duty=21, dutyLt=-1  
   {1055, 512, 785},  //duty=22, dutyLt=-1  
   {1063, 512, 783},  //duty=23, dutyLt=-1  
   {1063, 512, 782},  //duty=24, dutyLt=-1  
   {1062, 512, 783},  //duty=25, dutyLt=-1  
   { 623, 512,1658},  //duty=-1, dutyLt=0  
   { 832, 512,1005},  //duty=0, dutyLt=0  
   { 914, 512, 918},  //duty=1, dutyLt=0  
   { 955, 512, 883},  //duty=2, dutyLt=0  
   { 978, 512, 866},  //duty=3, dutyLt=0  
   { 993, 512, 857},  //duty=4, dutyLt=0  
   {1003, 512, 850},  //duty=5, dutyLt=0  
   {1012, 512, 846},  //duty=6, dutyLt=0  
   {1020, 512, 845},  //duty=7, dutyLt=0  
   {1029, 512, 839},  //duty=8, dutyLt=0  
   {1036, 512, 834},  //duty=9, dutyLt=0  
   {1041, 512, 832},  //duty=10, dutyLt=0  
   {1043, 512, 826},  //duty=11, dutyLt=0  
   {1038, 512, 816},  //duty=12, dutyLt=0  
   {1018, 512, 801},  //duty=13, dutyLt=0  
   {1010, 512, 791},  //duty=14, dutyLt=0  
   {1025, 512, 789},  //duty=15, dutyLt=0  
   {1010, 512, 791},  //duty=16, dutyLt=0  
   {1012, 512, 790},  //duty=17, dutyLt=0  
   {1017, 512, 790},  //duty=18, dutyLt=0  
   {1018, 512, 790},  //duty=19, dutyLt=0  
   {1017, 512, 790},  //duty=20, dutyLt=0  
   {1012, 512, 791},  //duty=21, dutyLt=0  
   {1010, 512, 791},  //duty=22, dutyLt=0  
   {1011, 512, 791},  //duty=23, dutyLt=0  
   {1010, 512, 791},  //duty=24, dutyLt=0  
   { 512, 512, 512},  //duty=25, dutyLt=0  
   { 626, 512,1693},  //duty=-1, dutyLt=1  
   { 756, 512,1152},  //duty=0, dutyLt=1  
   { 828, 512,1014},  //duty=1, dutyLt=1  
   { 876, 512, 959},  //duty=2, dutyLt=1  
   { 906, 512, 928},  //duty=3, dutyLt=1  
   { 926, 512, 909},  //duty=4, dutyLt=1  
   { 943, 512, 896},  //duty=5, dutyLt=1  
   { 955, 512, 887},  //duty=6, dutyLt=1  
   { 970, 512, 877},  //duty=7, dutyLt=1  
   { 984, 512, 868},  //duty=8, dutyLt=1  
   { 997, 512, 859},  //duty=9, dutyLt=1  
   {1005, 512, 856},  //duty=10, dutyLt=1  
   {1004, 512, 846},  //duty=11, dutyLt=1  
   {1003, 512, 828},  //duty=12, dutyLt=1  
   { 976, 512, 805},  //duty=13, dutyLt=1  
   { 966, 512, 794},  //duty=14, dutyLt=1  
   { 970, 512, 794},  //duty=15, dutyLt=1  
   { 976, 512, 795},  //duty=16, dutyLt=1  
   { 969, 512, 795},  //duty=17, dutyLt=1  
   { 971, 512, 794},  //duty=18, dutyLt=1  
   { 968, 512, 794},  //duty=19, dutyLt=1  
   { 976, 512, 795},  //duty=20, dutyLt=1  
   { 976, 512, 795},  //duty=21, dutyLt=1  
   { 975, 512, 795},  //duty=22, dutyLt=1  
   { 968, 512, 795},  //duty=23, dutyLt=1  
   { 976, 512, 795},  //duty=24, dutyLt=1  
   { 512, 512, 512},  //duty=25, dutyLt=1  
   { 627, 512,1699},  //duty=-1, dutyLt=2  
   { 723, 512,1244},  //duty=0, dutyLt=2  
   { 787, 512,1090},  //duty=1, dutyLt=2  
   { 830, 512,1019},  //duty=2, dutyLt=2  
   { 861, 512, 980},  //duty=3, dutyLt=2  
   { 883, 512, 956},  //duty=4, dutyLt=2  
   { 901, 512, 938},  //duty=5, dutyLt=2  
   { 916, 512, 924},  //duty=6, dutyLt=2  
   { 933, 512, 908},  //duty=7, dutyLt=2  
   { 950, 512, 895},  //duty=8, dutyLt=2  
   { 966, 512, 882},  //duty=9, dutyLt=2  
   { 974, 512, 872},  //duty=10, dutyLt=2  
   { 972, 512, 856},  //duty=11, dutyLt=2  
   { 962, 512, 836},  //duty=12, dutyLt=2  
   { 943, 512, 809},  //duty=13, dutyLt=2  
   { 936, 512, 797},  //duty=14, dutyLt=2  
   { 931, 512, 795},  //duty=15, dutyLt=2  
   { 934, 512, 797},  //duty=16, dutyLt=2  
   { 935, 512, 797},  //duty=17, dutyLt=2  
   { 971, 512, 796},  //duty=18, dutyLt=2  
   { 943, 512, 798},  //duty=19, dutyLt=2  
   { 936, 512, 797},  //duty=20, dutyLt=2  
   { 940, 512, 798},  //duty=21, dutyLt=2  
   { 947, 512, 796},  //duty=22, dutyLt=2  
   { 936, 512, 797},  //duty=23, dutyLt=2  
   { 512, 512, 512},  //duty=24, dutyLt=2  
   { 512, 512, 512},  //duty=25, dutyLt=2  
   { 628, 512,1710},  //duty=-1, dutyLt=3  
   { 704, 512,1304},  //duty=0, dutyLt=3  
   { 760, 512,1148},  //duty=1, dutyLt=3  
   { 800, 512,1070},  //duty=2, dutyLt=3  
   { 830, 512,1025},  //duty=3, dutyLt=3  
   { 852, 512, 995},  //duty=4, dutyLt=3  
   { 871, 512, 973},  //duty=5, dutyLt=3  
   { 886, 512, 956},  //duty=6, dutyLt=3  
   { 905, 512, 937},  //duty=7, dutyLt=3  
   { 924, 512, 918},  //duty=8, dutyLt=3  
   { 941, 512, 902},  //duty=9, dutyLt=3  
   { 948, 512, 888},  //duty=10, dutyLt=3  
   { 940, 512, 867},  //duty=11, dutyLt=3  
   { 929, 512, 842},  //duty=12, dutyLt=3  
   { 913, 512, 811},  //duty=13, dutyLt=3  
   { 900, 512, 797},  //duty=14, dutyLt=3  
   { 905, 512, 798},  //duty=15, dutyLt=3  
   { 900, 512, 797},  //duty=16, dutyLt=3  
   { 910, 512, 800},  //duty=17, dutyLt=3  
   { 903, 512, 795},  //duty=18, dutyLt=3  
   { 904, 512, 798},  //duty=19, dutyLt=3  
   { 904, 512, 798},  //duty=20, dutyLt=3  
   { 907, 512, 799},  //duty=21, dutyLt=3  
   { 902, 512, 797},  //duty=22, dutyLt=3  
   { 909, 512, 800},  //duty=23, dutyLt=3  
   { 512, 512, 512},  //duty=24, dutyLt=3  
   { 512, 512, 512},  //duty=25, dutyLt=3  
   { 626, 512,1709},  //duty=-1, dutyLt=4  
   { 694, 512,1350},  //duty=0, dutyLt=4  
   { 743, 512,1193},  //duty=1, dutyLt=4  
   { 780, 512,1110},  //duty=2, dutyLt=4  
   { 808, 512,1060},  //duty=3, dutyLt=4  
   { 830, 512,1027},  //duty=4, dutyLt=4  
   { 849, 512,1002},  //duty=5, dutyLt=4  
   { 864, 512, 981},  //duty=6, dutyLt=4  
   { 883, 512, 962},  //duty=7, dutyLt=4  
   { 902, 512, 940},  //duty=8, dutyLt=4  
   { 918, 512, 918},  //duty=9, dutyLt=4  
   { 919, 512, 900},  //duty=10, dutyLt=4  
   { 912, 512, 873},  //duty=11, dutyLt=4  
   { 897, 512, 844},  //duty=12, dutyLt=4  
   { 879, 512, 810},  //duty=13, dutyLt=4  
   { 875, 512, 798},  //duty=14, dutyLt=4  
   { 871, 512, 796},  //duty=15, dutyLt=4  
   { 875, 512, 798},  //duty=16, dutyLt=4  
   { 870, 512, 796},  //duty=17, dutyLt=4  
   { 867, 512, 795},  //duty=18, dutyLt=4  
   { 868, 512, 795},  //duty=19, dutyLt=4  
   { 877, 512, 799},  //duty=20, dutyLt=4  
   { 879, 512, 794},  //duty=21, dutyLt=4  
   { 869, 512, 795},  //duty=22, dutyLt=4  
   { 512, 512, 512},  //duty=23, dutyLt=4  
   { 512, 512, 512},  //duty=24, dutyLt=4  
   { 512, 512, 512},  //duty=25, dutyLt=4  
   { 630, 512,1710},  //duty=-1, dutyLt=5  
   { 685, 512,1387},  //duty=0, dutyLt=5  
   { 730, 512,1232},  //duty=1, dutyLt=5  
   { 764, 512,1146},  //duty=2, dutyLt=5  
   { 791, 512,1093},  //duty=3, dutyLt=5  
   { 812, 512,1057},  //duty=4, dutyLt=5  
   { 830, 512,1030},  //duty=5, dutyLt=5  
   { 846, 512,1007},  //duty=6, dutyLt=5  
   { 865, 512, 985},  //duty=7, dutyLt=5  
   { 884, 512, 959},  //duty=8, dutyLt=5  
   { 898, 512, 932},  //duty=9, dutyLt=5  
   { 897, 512, 906},  //duty=10, dutyLt=5  
   { 887, 512, 877},  //duty=11, dutyLt=5  
   { 872, 512, 846},  //duty=12, dutyLt=5  
   { 846, 512, 806},  //duty=13, dutyLt=5  
   { 840, 512, 793},  //duty=14, dutyLt=5  
   { 835, 512, 790},  //duty=15, dutyLt=5  
   { 839, 512, 789},  //duty=16, dutyLt=5  
   { 843, 512, 794},  //duty=17, dutyLt=5  
   { 843, 512, 794},  //duty=18, dutyLt=5  
   { 846, 512, 796},  //duty=19, dutyLt=5  
   { 843, 512, 794},  //duty=20, dutyLt=5  
   { 841, 512, 793},  //duty=21, dutyLt=5  
   { 853, 512, 791},  //duty=22, dutyLt=5  
   { 512, 512, 512},  //duty=23, dutyLt=5  
   { 512, 512, 512},  //duty=24, dutyLt=5  
   { 512, 512, 512},  //duty=25, dutyLt=5  
   { 630, 512,1717},  //duty=-1, dutyLt=6  
   { 679, 512,1418},  //duty=0, dutyLt=6  
   { 720, 512,1264},  //duty=1, dutyLt=6  
   { 752, 512,1178},  //duty=2, dutyLt=6  
   { 778, 512,1119},  //duty=3, dutyLt=6  
   { 797, 512,1085},  //duty=4, dutyLt=6  
   { 815, 512,1056},  //duty=5, dutyLt=6  
   { 831, 512,1032},  //duty=6, dutyLt=6  
   { 849, 512,1005},  //duty=7, dutyLt=6  
   { 869, 512, 980},  //duty=8, dutyLt=6  
   { 877, 512, 945},  //duty=9, dutyLt=6  
   { 873, 512, 913},  //duty=10, dutyLt=6  
   { 861, 512, 878},  //duty=11, dutyLt=6  
   { 842, 512, 844},  //duty=12, dutyLt=6  
   { 821, 512, 804},  //duty=13, dutyLt=6  
   { 811, 512, 788},  //duty=14, dutyLt=6  
   { 813, 512, 789},  //duty=15, dutyLt=6  
   { 812, 512, 787},  //duty=16, dutyLt=6  
   { 821, 512, 793},  //duty=17, dutyLt=6  
   { 812, 512, 788},  //duty=18, dutyLt=6  
   { 817, 512, 791},  //duty=19, dutyLt=6  
   { 813, 512, 789},  //duty=20, dutyLt=6  
   { 813, 512, 789},  //duty=21, dutyLt=6  
   { 512, 512, 512},  //duty=22, dutyLt=6  
   { 512, 512, 512},  //duty=23, dutyLt=6  
   { 512, 512, 512},  //duty=24, dutyLt=6  
   { 512, 512, 512},  //duty=25, dutyLt=6  
   { 631, 512,1718},  //duty=-1, dutyLt=7  
   { 675, 512,1444},  //duty=0, dutyLt=7  
   { 710, 512,1301},  //duty=1, dutyLt=7  
   { 738, 512,1214},  //duty=2, dutyLt=7  
   { 761, 512,1160},  //duty=3, dutyLt=7  
   { 781, 512,1117},  //duty=4, dutyLt=7  
   { 797, 512,1088},  //duty=5, dutyLt=7  
   { 812, 512,1063},  //duty=6, dutyLt=7  
   { 831, 512,1031},  //duty=7, dutyLt=7  
   { 847, 512,1000},  //duty=8, dutyLt=7  
   { 850, 512, 955},  //duty=9, dutyLt=7  
   { 843, 512, 917},  //duty=10, dutyLt=7  
   { 825, 512, 877},  //duty=11, dutyLt=7  
   { 809, 512, 841},  //duty=12, dutyLt=7  
   { 790, 512, 801},  //duty=13, dutyLt=7  
   { 781, 512, 784},  //duty=14, dutyLt=7  
   { 771, 512, 778},  //duty=15, dutyLt=7  
   { 785, 512, 787},  //duty=16, dutyLt=7  
   { 776, 512, 781},  //duty=17, dutyLt=7  
   { 788, 512, 789},  //duty=18, dutyLt=7  
   { 779, 512, 782},  //duty=19, dutyLt=7  
   { 787, 512, 788},  //duty=20, dutyLt=7  
   { 775, 512, 781},  //duty=21, dutyLt=7  
   { 512, 512, 512},  //duty=22, dutyLt=7  
   { 512, 512, 512},  //duty=23, dutyLt=7  
   { 512, 512, 512},  //duty=24, dutyLt=7  
   { 512, 512, 512},  //duty=25, dutyLt=7  
   { 632, 512,1720},  //duty=-1, dutyLt=8  
   { 669, 512,1480},  //duty=0, dutyLt=8  
   { 700, 512,1347},  //duty=1, dutyLt=8  
   { 725, 512,1256},  //duty=2, dutyLt=8  
   { 747, 512,1198},  //duty=3, dutyLt=8  
   { 764, 512,1156},  //duty=4, dutyLt=8  
   { 780, 512,1123},  //duty=5, dutyLt=8  
   { 794, 512,1097},  //duty=6, dutyLt=8  
   { 811, 512,1062},  //duty=7, dutyLt=8  
   { 820, 512,1018},  //duty=8, dutyLt=8  
   { 814, 512, 962},  //duty=9, dutyLt=8  
   { 802, 512, 916},  //duty=10, dutyLt=8  
   { 783, 512, 872},  //duty=11, dutyLt=8  
   { 768, 512, 833},  //duty=12, dutyLt=8  
   { 746, 512, 790},  //duty=13, dutyLt=8  
   { 746, 512, 781},  //duty=14, dutyLt=8  
   { 739, 512, 775},  //duty=15, dutyLt=8  
   { 740, 512, 771},  //duty=16, dutyLt=8  
   { 738, 512, 774},  //duty=17, dutyLt=8  
   { 741, 512, 776},  //duty=18, dutyLt=8  
   { 737, 512, 773},  //duty=19, dutyLt=8  
   { 745, 512, 778},  //duty=20, dutyLt=8  
   { 512, 512, 512},  //duty=21, dutyLt=8  
   { 512, 512, 512},  //duty=22, dutyLt=8  
   { 512, 512, 512},  //duty=23, dutyLt=8  
   { 512, 512, 512},  //duty=24, dutyLt=8  
   { 512, 512, 512},  //duty=25, dutyLt=8  
   { 633, 512,1723},  //duty=-1, dutyLt=9  
   { 665, 512,1512},  //duty=0, dutyLt=9  
   { 691, 512,1383},  //duty=1, dutyLt=9  
   { 714, 512,1296},  //duty=2, dutyLt=9  
   { 733, 512,1240},  //duty=3, dutyLt=9  
   { 750, 512,1193},  //duty=4, dutyLt=9  
   { 765, 512,1157},  //duty=5, dutyLt=9  
   { 776, 512,1127},  //duty=6, dutyLt=9  
   { 785, 512,1085},  //duty=7, dutyLt=9  
   { 787, 512,1028},  //duty=8, dutyLt=9  
   { 776, 512, 960},  //duty=9, dutyLt=9  
   { 756, 512, 907},  //duty=10, dutyLt=9  
   { 742, 512, 862},  //duty=11, dutyLt=9  
   { 723, 512, 821},  //duty=12, dutyLt=9  
   { 700, 512, 775},  //duty=13, dutyLt=9  
   { 692, 512, 758},  //duty=14, dutyLt=9  
   { 695, 512, 760},  //duty=15, dutyLt=9  
   { 700, 512, 764},  //duty=16, dutyLt=9  
   { 696, 512, 762},  //duty=17, dutyLt=9  
   { 697, 512, 761},  //duty=18, dutyLt=9  
   { 701, 512, 765},  //duty=19, dutyLt=9  
   { 512, 512, 512},  //duty=20, dutyLt=9  
   { 512, 512, 512},  //duty=21, dutyLt=9  
   { 512, 512, 512},  //duty=22, dutyLt=9  
   { 512, 512, 512},  //duty=23, dutyLt=9  
   { 512, 512, 512},  //duty=24, dutyLt=9  
   { 512, 512, 512},  //duty=25, dutyLt=9  
   { 634, 512,1721},  //duty=-1, dutyLt=10  
   { 662, 512,1523},  //duty=0, dutyLt=10  
   { 687, 512,1402},  //duty=1, dutyLt=10  
   { 708, 512,1324},  //duty=2, dutyLt=10  
   { 725, 512,1267},  //duty=3, dutyLt=10  
   { 741, 512,1220},  //duty=4, dutyLt=10  
   { 754, 512,1179},  //duty=5, dutyLt=10  
   { 762, 512,1142},  //duty=6, dutyLt=10  
   { 764, 512,1095},  //duty=7, dutyLt=10  
   { 765, 512,1028},  //duty=8, dutyLt=10  
   { 743, 512, 953},  //duty=9, dutyLt=10  
   { 727, 512, 899},  //duty=10, dutyLt=10  
   { 711, 512, 853},  //duty=11, dutyLt=10  
   { 697, 512, 813},  //duty=12, dutyLt=10  
   { 680, 512, 770},  //duty=13, dutyLt=10  
   { 672, 512, 754},  //duty=14, dutyLt=10  
   { 672, 512, 749},  //duty=15, dutyLt=10  
   { 669, 512, 748},  //duty=16, dutyLt=10  
   { 666, 512, 749},  //duty=17, dutyLt=10  
   { 670, 512, 752},  //duty=18, dutyLt=10  
   { 512, 512, 512},  //duty=19, dutyLt=10  
   { 512, 512, 512},  //duty=20, dutyLt=10  
   { 512, 512, 512},  //duty=21, dutyLt=10  
   { 512, 512, 512},  //duty=22, dutyLt=10  
   { 512, 512, 512},  //duty=23, dutyLt=10  
   { 512, 512, 512},  //duty=24, dutyLt=10  
   { 512, 512, 512},  //duty=25, dutyLt=10  
   { 634, 512,1716},  //duty=-1, dutyLt=11  
   { 661, 512,1532},  //duty=0, dutyLt=11  
   { 684, 512,1416},  //duty=1, dutyLt=11  
   { 702, 512,1346},  //duty=2, dutyLt=11  
   { 720, 512,1282},  //duty=3, dutyLt=11  
   { 732, 512,1237},  //duty=4, dutyLt=11  
   { 742, 512,1192},  //duty=5, dutyLt=11  
   { 748, 512,1150},  //duty=6, dutyLt=11  
   { 745, 512,1097},  //duty=7, dutyLt=11  
   { 740, 512,1024},  //duty=8, dutyLt=11  
   { 719, 512, 945},  //duty=9, dutyLt=11  
   { 699, 512, 889},  //duty=10, dutyLt=11  
   { 679, 512, 840},  //duty=11, dutyLt=11  
   { 670, 512, 801},  //duty=12, dutyLt=11  
   { 652, 512, 755},  //duty=13, dutyLt=11  
   { 645, 512, 739},  //duty=14, dutyLt=11  
   { 650, 512, 743},  //duty=15, dutyLt=11  
   { 653, 512, 745},  //duty=16, dutyLt=11  
   { 646, 512, 739},  //duty=17, dutyLt=11  
   { 512, 512, 512},  //duty=18, dutyLt=11  
   { 512, 512, 512},  //duty=19, dutyLt=11  
   { 512, 512, 512},  //duty=20, dutyLt=11  
   { 512, 512, 512},  //duty=21, dutyLt=11  
   { 512, 512, 512},  //duty=22, dutyLt=11  
   { 512, 512, 512},  //duty=23, dutyLt=11  
   { 512, 512, 512},  //duty=24, dutyLt=11  
   { 512, 512, 512},  //duty=25, dutyLt=11  
   { 635, 512,1720},  //duty=-1, dutyLt=12  
   { 659, 512,1549},  //duty=0, dutyLt=12  
   { 681, 512,1429},  //duty=1, dutyLt=12  
   { 700, 512,1346},  //duty=2, dutyLt=12  
   { 715, 512,1292},  //duty=3, dutyLt=12  
   { 726, 512,1240},  //duty=4, dutyLt=12  
   { 731, 512,1195},  //duty=5, dutyLt=12  
   { 729, 512,1156},  //duty=6, dutyLt=12  
   { 723, 512,1093},  //duty=7, dutyLt=12  
   { 719, 512,1017},  //duty=8, dutyLt=12  
   { 695, 512, 936},  //duty=9, dutyLt=12  
   { 679, 512, 880},  //duty=10, dutyLt=12  
   { 663, 512, 832},  //duty=11, dutyLt=12  
   { 648, 512, 789},  //duty=12, dutyLt=12  
   { 651, 512, 755},  //duty=13, dutyLt=12  
   { 635, 512, 736},  //duty=14, dutyLt=12  
   { 639, 512, 738},  //duty=15, dutyLt=12  
   { 626, 512, 728},  //duty=16, dutyLt=12  
   { 512, 512, 512},  //duty=17, dutyLt=12  
   { 512, 512, 512},  //duty=18, dutyLt=12  
   { 512, 512, 512},  //duty=19, dutyLt=12  
   { 512, 512, 512},  //duty=20, dutyLt=12  
   { 512, 512, 512},  //duty=21, dutyLt=12  
   { 512, 512, 512},  //duty=22, dutyLt=12  
   { 512, 512, 512},  //duty=23, dutyLt=12  
   { 512, 512, 512},  //duty=24, dutyLt=12  
   { 512, 512, 512},  //duty=25, dutyLt=12  
   { 636, 512,1716},  //duty=-1, dutyLt=13  
   { 659, 512,1548},  //duty=0, dutyLt=13  
   { 679, 512,1441},  //duty=1, dutyLt=13  
   { 693, 512,1379},  //duty=2, dutyLt=13  
   { 708, 512,1301},  //duty=3, dutyLt=13  
   { 715, 512,1247},  //duty=4, dutyLt=13  
   { 718, 512,1197},  //duty=5, dutyLt=13  
   { 709, 512,1153},  //duty=6, dutyLt=13  
   { 709, 512,1086},  //duty=7, dutyLt=13  
   { 695, 512,1008},  //duty=8, dutyLt=13  
   { 680, 512, 927},  //duty=9, dutyLt=13  
   { 654, 512, 868},  //duty=10, dutyLt=13  
   { 642, 512, 821},  //duty=11, dutyLt=13  
   { 641, 512, 787},  //duty=12, dutyLt=13  
   { 622, 512, 740},  //duty=13, dutyLt=13  
   { 613, 512, 720},  //duty=14, dutyLt=13  
   { 617, 512, 724},  //duty=15, dutyLt=13  
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
   { 636, 512,1706},  //duty=-1, dutyLt=14  
   { 658, 512,1566},  //duty=0, dutyLt=14  
   { 678, 512,1447},  //duty=1, dutyLt=14  
   { 694, 512,1368},  //duty=2, dutyLt=14  
   { 703, 512,1307},  //duty=3, dutyLt=14  
   { 707, 512,1250},  //duty=4, dutyLt=14  
   { 706, 512,1200},  //duty=5, dutyLt=14  
   { 713, 512,1148},  //duty=6, dutyLt=14  
   { 705, 512,1083},  //duty=7, dutyLt=14  
   { 678, 512,1001},  //duty=8, dutyLt=14  
   { 668, 512, 922},  //duty=9, dutyLt=14  
   { 645, 512, 862},  //duty=10, dutyLt=14  
   { 641, 512, 819},  //duty=11, dutyLt=14  
   { 625, 512, 774},  //duty=12, dutyLt=14  
   { 619, 512, 738},  //duty=13, dutyLt=14  
   { 616, 512, 725},  //duty=14, dutyLt=14  
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
   { 636, 512,1706},  //duty=-1, dutyLt=15  
   { 658, 512,1547},  //duty=0, dutyLt=15  
   { 678, 512,1447},  //duty=1, dutyLt=15  
   { 691, 512,1378},  //duty=2, dutyLt=15  
   { 699, 512,1313},  //duty=3, dutyLt=15  
   { 706, 512,1251},  //duty=4, dutyLt=15  
   { 705, 512,1203},  //duty=5, dutyLt=15  
   { 714, 512,1147},  //duty=6, dutyLt=15  
   { 696, 512,1083},  //duty=7, dutyLt=15  
   { 681, 512,1003},  //duty=8, dutyLt=15  
   { 660, 512, 919},  //duty=9, dutyLt=15  
   { 647, 512, 863},  //duty=10, dutyLt=15  
   { 634, 512, 815},  //duty=11, dutyLt=15  
   { 626, 512, 776},  //duty=12, dutyLt=15  
   { 629, 512, 740},  //duty=13, dutyLt=15  
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
   { 636, 512,1711},  //duty=-1, dutyLt=16  
   { 658, 512,1555},  //duty=0, dutyLt=16  
   { 678, 512,1447},  //duty=1, dutyLt=16  
   { 690, 512,1383},  //duty=2, dutyLt=16  
   { 698, 512,1316},  //duty=3, dutyLt=16  
   { 708, 512,1250},  //duty=4, dutyLt=16  
   { 703, 512,1202},  //duty=5, dutyLt=16  
   { 704, 512,1151},  //duty=6, dutyLt=16  
   { 707, 512,1083},  //duty=7, dutyLt=16  
   { 678, 512,1002},  //duty=8, dutyLt=16  
   { 665, 512, 920},  //duty=9, dutyLt=16  
   { 657, 512, 868},  //duty=10, dutyLt=16  
   { 630, 512, 812},  //duty=11, dutyLt=16  
   { 629, 512, 779},  //duty=12, dutyLt=16  
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
   { 636, 512,1709},  //duty=-1, dutyLt=17  
   { 658, 512,1551},  //duty=0, dutyLt=17  
   { 677, 512,1450},  //duty=1, dutyLt=17  
   { 694, 512,1366},  //duty=2, dutyLt=17  
   { 702, 512,1307},  //duty=3, dutyLt=17  
   { 709, 512,1248},  //duty=4, dutyLt=17  
   { 710, 512,1197},  //duty=5, dutyLt=17  
   { 701, 512,1151},  //duty=6, dutyLt=17  
   { 693, 512,1082},  //duty=7, dutyLt=17  
   { 684, 512,1003},  //duty=8, dutyLt=17  
   { 673, 512, 924},  //duty=9, dutyLt=17  
   { 650, 512, 864},  //duty=10, dutyLt=17  
   { 634, 512, 816},  //duty=11, dutyLt=17  
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
   { 636, 512,1704},  //duty=-1, dutyLt=18  
   { 659, 512,1542},  //duty=0, dutyLt=18  
   { 678, 512,1445},  //duty=1, dutyLt=18  
   { 692, 512,1375},  //duty=2, dutyLt=18  
   { 705, 512,1303},  //duty=3, dutyLt=18  
   { 712, 512,1246},  //duty=4, dutyLt=18  
   { 709, 512,1198},  //duty=5, dutyLt=18  
   { 702, 512,1151},  //duty=6, dutyLt=18  
   { 696, 512,1082},  //duty=7, dutyLt=18  
   { 678, 512,1002},  //duty=8, dutyLt=18  
   { 666, 512, 921},  //duty=9, dutyLt=18  
   { 645, 512, 862},  //duty=10, dutyLt=18  
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
   { 636, 512,1707},  //duty=-1, dutyLt=19  
   { 658, 512,1556},  //duty=0, dutyLt=19  
   { 677, 512,1450},  //duty=1, dutyLt=19  
   { 691, 512,1377},  //duty=2, dutyLt=19  
   { 700, 512,1311},  //duty=3, dutyLt=19  
   { 708, 512,1249},  //duty=4, dutyLt=19  
   { 713, 512,1196},  //duty=5, dutyLt=19  
   { 704, 512,1150},  //duty=6, dutyLt=19  
   { 693, 512,1082},  //duty=7, dutyLt=19  
   { 688, 512,1004},  //duty=8, dutyLt=19  
   { 662, 512, 920},  //duty=9, dutyLt=19  
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
   { 636, 512,1707},  //duty=-1, dutyLt=20  
   { 658, 512,1565},  //duty=0, dutyLt=20  
   { 678, 512,1443},  //duty=1, dutyLt=20  
   { 692, 512,1374},  //duty=2, dutyLt=20  
   { 697, 512,1317},  //duty=3, dutyLt=20  
   { 708, 512,1250},  //duty=4, dutyLt=20  
   { 702, 512,1202},  //duty=5, dutyLt=20  
   { 708, 512,1149},  //duty=6, dutyLt=20  
   { 699, 512,1082},  //duty=7, dutyLt=20  
   { 693, 512,1005},  //duty=8, dutyLt=20  
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
   { 636, 512,1725},  //duty=-1, dutyLt=21  
   { 658, 512,1558},  //duty=0, dutyLt=21  
   { 677, 512,1453},  //duty=1, dutyLt=21  
   { 691, 512,1377},  //duty=2, dutyLt=21  
   { 701, 512,1309},  //duty=3, dutyLt=21  
   { 705, 512,1253},  //duty=4, dutyLt=21  
   { 711, 512,1197},  //duty=5, dutyLt=21  
   { 709, 512,1149},  //duty=6, dutyLt=21  
   { 705, 512,1083},  //duty=7, dutyLt=21  
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
   { 636, 512,1708},  //duty=-1, dutyLt=22  
   { 658, 512,1554},  //duty=0, dutyLt=22  
   { 676, 512,1460},  //duty=1, dutyLt=22  
   { 691, 512,1380},  //duty=2, dutyLt=22  
   { 702, 512,1310},  //duty=3, dutyLt=22  
   { 713, 512,1245},  //duty=4, dutyLt=22  
   { 710, 512,1198},  //duty=5, dutyLt=22  
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
   { 636, 512,1711},  //duty=-1, dutyLt=23  
   { 659, 512,1546},  //duty=0, dutyLt=23  
   { 677, 512,1456},  //duty=1, dutyLt=23  
   { 694, 512,1367},  //duty=2, dutyLt=23  
   { 705, 512,1303},  //duty=3, dutyLt=23  
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
   { 636, 512,1725},  //duty=-1, dutyLt=24  
   { 660, 512,1533},  //duty=0, dutyLt=24  
   { 677, 512,1452},  //duty=1, dutyLt=24  
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
   { 636, 512,1706},  //duty=-1, dutyLt=25  
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



