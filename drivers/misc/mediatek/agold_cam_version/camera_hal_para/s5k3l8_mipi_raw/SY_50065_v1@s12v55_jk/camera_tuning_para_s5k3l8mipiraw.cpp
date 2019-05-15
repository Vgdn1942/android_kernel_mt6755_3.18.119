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
#include <utils/Log.h>
#include <fcntl.h>
#include <math.h>
#include <string.h>

#include "camera_custom_nvram.h"
#include "camera_custom_sensor.h"
#include "image_sensor.h"
#include "kd_imgsensor_define.h"
#include "camera_AE_PLineTable_s5k3l8mipiraw.h"
#include "camera_info_s5k3l8mipiraw.h"
#include "camera_custom_AEPlinetable.h"
#include "camera_custom_tsf_tbl.h"

#define NVRAM_TUNING_PARAM_NUM	5341001

const NVRAM_CAMERA_ISP_PARAM_STRUCT CAMERA_ISP_DEFAULT_VALUE =
{{
    //Version
    Version: NVRAM_CAMERA_PARA_FILE_VERSION,

    //SensorId
    SensorId: SENSOR_ID,
    ISPComm:{
      {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      }
    },
    ISPPca: {
#include INCLUDE_FILENAME_ISP_PCA_PARAM
    },
    ISPRegs:{
#include INCLUDE_FILENAME_ISP_REGS_PARAM
    },
    ISPMfbMixer:{{
      0x01FF0001, // MIX3_CTRL_0
      0x00FF0000, // MIX3_CTRL_1
      0xFFFF0000  // MIX3_SPARE
    }},
    ISPMulitCCM:{
      Poly22:{
        79925,      // i4R_AVG
        17040,      // i4R_STD
        104050,      // i4B_AVG
        28534,      // i4B_STD
				  0, // i4R_MAX 
				   0, // i4R_MIN 
				  0, // i4G_MAX 
				   0, // i4G_MIN 
				  0, // i4B_MAX 
				   0, // i4B_MIN 
                { // i4P00[9]
            9672500, -4207500, -340000, -1632500, 7307500, -545000, -20000, -3597500, 8737500
                },
                { // i4P10[9]
            1929809, -2442164, 546714, 229831, -481611, 254632, 158277, -940574, 810630
                },
                { // i4P01[9]
            1349654, -1869674, 551861, -15606, -604285, 619213, 138273, -2050025, 1946685
                },
                { // i4P20[9]
                0, 0, 0, 0, 0, 0, 0, 0, 0
                },
                { // i4P11[9]
                0, 0, 0, 0, 0, 0, 0, 0, 0
                },
                { // i4P02[9]
                0, 0, 0, 0, 0, 0, 0, 0, 0
                }
      },

      AWBGain:{
        {
          512,    // i4R
          512,    // i4G
          512    // i4B
        },
        {
          644,    // i4R
          512,    // i4G
          1353    // i4B
        },
        {
          701,    // i4R
          512,    // i4G
          1087    // i4B
        },
        {
          823,    // i4R
          512,    // i4G
          1061    // i4B
        },
        {
          1029,    // i4R
          512,    // i4G
          661    // i4B
        },
        {
          512,    // i4R
          512,    // i4G
          512    // i4B
        },
        {
          512,    // i4R
          512,    // i4G
          512    // i4B
        },
        {
          512,    // i4R
          512,    // i4G
          512    // i4B
        }
      },
      Weight:{
        1, // Strobe
        1, // A
        1, // TL84
        1, // CWF
        1, // D65
        1, // Reserved 1
        1, // Reserved 2
        1  // Reserved 3
      }
    },
    MDPMulitCCM:{
      Poly22:{
        125225,      // i4R_AVG
        32141,      // i4R_STD
        165675,      // i4B_AVG
        30249,      // i4B_STD
        646,      // i4R_MAX
        527,      // i4R_MIN
        789,      // i4G_MAX
        670,      // i4G_MIN
        856,      // i4B_MAX
        721,      // i4B_MIN
        {  // i4P00[9]
            5995000, -505000, -370000, -1387500, 7165000, -657500, -532500, -2045000, 7697500
        },
        {  // i4P10[9]
            725905, -1081879, 355974, 627096, -389018, -238079, 626246, -86040, -540207
        },
        {  // i4P01[9]
            257857, -576218, 318361, -96902, -138571, 235473, 24959, 193148, -218107
        },
        {  // i4P20[9]
            0, 0, 0, 0, 0, 0, 0, 0, 0
        },
        {  // i4P11[9]
            0, 0, 0, 0, 0, 0, 0, 0, 0
        },
        {  // i4P02[9]
            0, 0, 0, 0, 0, 0, 0, 0, 0
        }
      },
      AWBGain:{
        // Strobe
        {
          512,    // i4R
          512,    // i4G
          512    // i4B
        },
        // A
        {
          667,    // i4R
            512,    // i4G
          1524    // i4B
        },
        // TL84
        {
          797,    // i4R
            512,    // i4G
          1259    // i4B
        },
        // CWF
        {
          905,    // i4R
            512,    // i4G
          1254    // i4B
        },
        // D65
        {
          1053,    // i4R
            512,    // i4G
          791    // i4B
        },
        // Reserved 1
        {
            512,    // i4R
            512,    // i4G
            512    // i4B
        },
        // Reserved 2
        {
            512,    // i4R
            512,    // i4G
            512    // i4B
        },
        // Reserved 3
        {
            512,    // i4R
            512,    // i4G
            512    // i4B
        }
      },
      Weight:{
        1, // Strobe
        1, // A
        1, // TL84
        1, // CWF
        1, // D65
        1, // Reserved 1
        1, // Reserved 2
        1  // Reserved 3
      }
    },
    isp_ccm_ratio: 1.000000,
    bInvokeSmoothCCM: MTRUE,

    DngMetadata:{
      0, // i4RefereceIlluminant1
      3, // i4RefereceIlluminant2
      rNoiseProfile:{
                  {  // i4P00[9]
          S:{
            0.000004,      // a
            0.000336       // b
                  },
          O:{
            0.000000,      // a
            -0.000234       // b
          }
                          },
                          { // i4P11[9]
          S:{
            0.000004,      // a
            0.000336       // b
                          },
          O:{
            0.000000,      // a
            -0.000234       // b
                          }
          
                },
                  // Strobe
                  {
                  // A
          S:{
            0.000004,      // a
                  // TL84
            0.000336       // b
                  },
                  // CWF
          O:{
            0.000000,      // a
            -0.000234       // b
          }
                  // D65
                  },
                  // Reserved 1
                  {
                  // Reserved 2
          S:{
            0.000004,      // a
            0.000336       // b
                  },
                  // Reserved 3
          O:{
            0.000000,      // a
            -0.000234       // b
                  }
        }
                }
    //bInvokeSmoothCCM
            // rNoiseProfile[4]
    },
    ANR_TBL:
    {0}
}};

const NVRAM_CAMERA_3A_STRUCT CAMERA_3A_NVRAM_DEFAULT_VALUE =
{
    NVRAM_CAMERA_3A_FILE_VERSION, // u4Version
    SENSOR_ID, // SensorId

    // AE NVRAM
    {
        // rDevicesInfo
        {
            1144,    // u4MinGain, 1024 base = 1x
            16384,    // u4MaxGain, 16x
            100,    // u4MiniISOGain, ISOxx  
            128,    // u4GainStepUnit, 1x/8
            10372,    // u4PreExpUnit 
            30,     // u4PreMaxFrameRate
            10372,    // u4VideoExpUnit  
            30,     // u4VideoMaxFrameRate
            1024,   // u4Video2PreRatio, 1024 base = 1x
            10372,    // u4CapExpUnit 
            30,    // u4CapMaxFrameRate
            1024,    // u4Cap2PreRatio, 1024 base = 1x
            10372,    // u4Video1ExpUnit
            120,    // u4Video1MaxFrameRate
            1024,   // u4Cap2PreRatio, 1024 base = 1x
            10372,    // u4Video2ExpUnit
            120,    // u4Video2MaxFrameRate
            1024,   // u4Video12PreRatio, 1024 base = 1x
            19770,     // u4Video2ExpUnit
            30,     // u4Video2MaxFrameRate
            1024,   // u4Video22PreRatio, 1024 base = 1x
            19770,     // u4Custom1ExpUnit
            30,     // u4Custom1MaxFrameRate
            1024,   // u4Custom12PreRatio, 1024 base = 1x
            19770,     // u4Custom2ExpUnit
            30,     // u4Custom2MaxFrameRate
            1024,   // u4Custom22PreRatio, 1024 base = 1x
            19770,     // u4Custom3ExpUnit
            30,     // u4Custom3MaxFrameRate
            1024,   // u4Custom32PreRatio, 1024 base = 1x
            19770,     // u4Custom4ExpUnit
            30,     // u4Custom4MaxFrameRate
            1024,   // u4Custom42PreRatio, 1024 base = 1x
            22,    // u4LensFno, Fno = 2.8
            350     // u4FocusLength_100x
        },
        // rHistConfig
        {
            4, // 2,   // u4HistHighThres
            40,  // u4HistLowThres
            2,   // u4MostBrightRatio
            1,   // u4MostDarkRatio
            160, // u4CentralHighBound
            20,  // u4CentralLowBound
            {240, 230, 220, 210, 200}, // u4OverExpThres[AE_CCT_STRENGTH_NUM]
            {62, 70, 82, 108, 141},  // u4HistStretchThres[AE_CCT_STRENGTH_NUM]
            {18, 22, 26, 30, 34}       // u4BlackLightThres[AE_CCT_STRENGTH_NUM]
        },
        // rCCTConfig
        {
            TRUE,            // bEnableBlackLight
            TRUE,            // bEnableHistStretch
            TRUE,           // bEnableAntiOverExposure
            TRUE,            // bEnableTimeLPF
            TRUE,            // bEnableCaptureThres
            TRUE,            // bEnableVideoThres
            TRUE,            // bEnableVideo1Thres
            TRUE,            // bEnableVideo2Thres
            TRUE,            // bEnableCustom1Thres
            TRUE,            // bEnableCustom2Thres
            TRUE,            // bEnableCustom3Thres
            TRUE,            // bEnableCustom4Thres
            TRUE,            // bEnableCustom5Thres
            TRUE,            // bEnableStrobeThres
            57,    // u4AETarget
            47,                // u4StrobeAETarget

            60,    // u4InitIndex
            4,                 // u4BackLightWeight
            32,                // u4HistStretchWeight
            4,                 // u4AntiOverExpWeight
            2,                 // u4BlackLightStrengthIndex
            2,                 // u4HistStretchStrengthIndex
            2,                 // u4AntiOverExpStrengthIndex
            2,                 // u4TimeLPFStrengthIndex
            {1, 3, 5, 7, 8}, // u4LPFConvergeTable[AE_CCT_STRENGTH_NUM]
            90,                // u4InDoorEV = 9.0, 10 base
            3,    // i4BVOffset delta BV = value/10 
            0,    // u4PreviewFlareOffset
            0,    // u4CaptureFlareOffset
            3,                 // u4CaptureFlareThres
            0,    // u4VideoFlareOffset
            3,                 // u4VideoFlareThres
            0,    // u4CustomFlareOffset
            3,                 //  u4CustomFlareThres
            0,    // u4StrobeFlareOffset
            3,                 // u4StrobeFlareThres // 0.5%
            160,                 // u4PrvMaxFlareThres //12 bit
            0,                 // u4PrvMinFlareThres
            160,                 // u4VideoMaxFlareThres // 12 bit
            0,                 // u4VideoMinFlareThres
            18,                // u4FlatnessThres              // 10 base for flatness condition.
            75,    // u4FlatnessStrength
            //rMeteringSpec
            {
                //rHS_Spec
                {
                    TRUE,//bEnableHistStretch           // enable histogram stretch
                    1024,//u4HistStretchWeight          // Histogram weighting value
                    40, //50, //20,//u4Pcent                      // 1%=10, 0~1000
                    160,//u4Thd                        // 0~255
                    75, //54, //74,//u4FlatThd                    // 0~255

                    120,//u4FlatBrightPcent
                    120,//u4FlatDarkPcent
                    //sFlatRatio
                    {
                        1000,  //i4X1
                        1024,  //i4Y1
                        2400, //i4X2
                        0     //i4Y2
                    },
                    TRUE, //bEnableGreyTextEnhance
                    1800, //u4GreyTextFlatStart, > sFlatRatio.i4X1, < sFlatRatio.i4X2
                    {
                        10,     //i4X1
                        1024,   //i4Y1
                        80,     //i4X2
                        0       //i4Y2
                    }
                },
                //rAOE_Spec
                {
                    TRUE, //bEnableAntiOverExposure
                    1024, //u4AntiOverExpWeight
                    10,    //u4Pcent
                    220, //u4Thd

                    TRUE, //bEnableCOEP
                    1,    //u4COEPcent
                    106,  //u4COEThd
                    0,  // u4BVCompRatio
                    //sCOEYRatio;     // the outer y ratio
                    {
                        23,   //i4X1
                        1024,  //i4Y1
                        47,   //i4X2
                        0     //i4Y2
                    },
                    //sCOEDiffRatio;  // inner/outer y difference ratio
                    {
                        1500, //i4X1
                        0,    //i4Y1
                        2100, //i4X2
                        1024   //i4Y2
                    }
                },
                //rABL_Spec
                {
                    TRUE,//bEnableBlackLigh
                    1024,//u4BackLightWeigh
                    400,//u4Pcent
                    22,//u4Thd
                    255, // center luminance
                    246, //256, // final target limitation, 256/128 = 2x
                    //sFgBgEVRatio
                    {
                        2100,//2200, //i4X1
                        0,    //i4Y1
                        4000, //i4X2
                        1024   //i4Y2
                    },
                    //sBVRatio
                    {
                        3800,//i4X1
                        0,   //i4Y1
                        5000,//i4X2
                        1024  //i4Y2
                    }
                },
                //rNS_Spec
                {
                    TRUE, // bEnableNightScene
                    10, //5,    //u4Pcent
                    150,//u4Thd
                    72, //52,   //u4FlatThd

					          180, //  200,  //u4BrightTonePcent
				            80, //85,//	82, //  95, //u4BrightToneThd

                    500,  //u4LowBndPcent
                    5,    //u4LowBndThd
                    26,    //u4LowBndThdLimit

                    50,  //u4FlatBrightPcent;
                    300,   //u4FlatDarkPcent;
                    //sFlatRatio
                    {
                        1200, //i4X1
                        1024, //i4Y1
                      2800,//  2400, //i4X2
                        0    //i4Y2
                    },
                    //sBVRatio
                    {
                        -500, //i4X1
                        1024,  //i4Y1
                        3000, //i4X2
                        0     //i4Y2
                    },
                    TRUE, // bEnableNightSkySuppresion
                    //sSkyBVRatio
                    {
                        -4000, //i4X1
                        1024, //i4X2
                        -2000,  //i4Y1
                        0     //i4Y2
                    }
                },
                // rTOUCHFD_Spec
                {
                    55, //uMeteringYLowBound;
                    65, //uMeteringYHighBound;
                    55, //uFaceYLowBound;
                    65, //uFaceYHighBound;
                    3,  //uFaceCentralWeight;
                    120,//u4MeteringStableMax;
                    80, //u4MeteringStableMin;
                }
            }, //End rMeteringSpec
            // rFlareSpec
            {
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //uPrvFlareWeightArr[16];
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //uVideoFlareWeightArr[16];
                0,                                               //u4FlareStdThrHigh;
                0,                                               //u4FlareStdThrLow;
                0,                                                //u4PrvCapFlareDiff;
                2,                                                //u4FlareMaxStepGap_Fast;
                0,//0,                                                //u4FlareMaxStepGap_Slow;
                1800,                                             //u4FlarMaxStepGapLimitBV;
                2,//0,                                                //u4FlareAEStableCount;
            },
            //rAEMoveRatio =
            {
                100,//100, //u4SpeedUpRatio 500
                100, //100, //u4GlobalRatio
                190, //u4Bright2TargetEnd  190 150
                10,//20,   //u4Dark2TargetStart
                90, //u4B2TEnd
                85,//70,  //u4B2TStart 70
                70,//60,  //u4D2TEnd 60
                85,  //u4D2TStart
            },

            //rAEVideoMoveRatio =
            {
                100, //u4SpeedUpRatio
                100, //u4GlobalRatio
                150,  //u4Bright2TargetEnd
                20,    //u4Dark2TargetStart
                90, //u4B2TEnd
                40,  //u4B2TStart
                30,  //u4D2TEnd
                90,  //u4D2TStart
            },

            //rAEVideo1MoveRatio =
            {
                100, //u4SpeedUpRatio
                100, //u4GlobalRatio
                150,  //u4Bright2TargetEnd
                20,    //u4Dark2TargetStart
                90, //u4B2TEnd
                40,  //u4B2TStart
                30,  //u4D2TEnd
                90,  //u4D2TStart
            },

            //rAEVideo2MoveRatio =
            {
                100, //u4SpeedUpRatio
                100, //u4GlobalRatio
                150,  //u4Bright2TargetEnd
                20,    //u4Dark2TargetStart
                90, //u4B2TEnd
                40,  //u4B2TStart
                30,  //u4D2TEnd
                90,  //u4D2TStart
            },

            //rAECustom1MoveRatio =
            {
                100, //u4SpeedUpRatio
                100, //u4GlobalRatio
                150,  //u4Bright2TargetEnd
                20,    //u4Dark2TargetStart
                90, //u4B2TEnd
                40,  //u4B2TStart
                30,  //u4D2TEnd
                90,  //u4D2TStart
            },

            //rAECustom2MoveRatio =
            {
                100, //u4SpeedUpRatio
                100, //u4GlobalRatio
                150,  //u4Bright2TargetEnd
                20,    //u4Dark2TargetStart
                90, //u4B2TEnd
                40,  //u4B2TStart
                30,  //u4D2TEnd
                90,  //u4D2TStart
            },

            //rAECustom3MoveRatio =
            {
                100, //u4SpeedUpRatio
                100, //u4GlobalRatio
                150,  //u4Bright2TargetEnd
                20,    //u4Dark2TargetStart
                90, //u4B2TEnd
                40,  //u4B2TStart
                30,  //u4D2TEnd
                90,  //u4D2TStart
            },

            //rAECustom4MoveRatio =
            {
                100, //u4SpeedUpRatio
                100, //u4GlobalRatio
                150,  //u4Bright2TargetEnd
                20,    //u4Dark2TargetStart
                90, //u4B2TEnd
                40,  //u4B2TStart
                30,  //u4D2TEnd
                90,  //u4D2TStart
            },

            //rAECustom5MoveRatio =
            {
                100, //u4SpeedUpRatio
                100, //u4GlobalRatio
                150,  //u4Bright2TargetEnd
                20,    //u4Dark2TargetStart
                90, //u4B2TEnd
                40,  //u4B2TStart
                30,  //u4D2TEnd
                90,  //u4D2TStart
            },

            //rAEFaceMoveRatio =
            {
                100, //u4SpeedUpRatio
                100, //u4GlobalRatio
                190,  //u4Bright2TargetEnd
                10,    //u4Dark2TargetStart
                80, //u4B2TEnd
                30,  //u4B2TStart
                20,  //u4D2TEnd
                60,  //u4D2TStart
            },

            //rAETrackingMoveRatio =
            {
                100, //u4SpeedUpRatio
                100, //u4GlobalRatio
                190,  //u4Bright2TargetEnd
                10,    //u4Dark2TargetStart
                80, //u4B2TEnd
                30,  //u4B2TStart
                20,  //u4D2TEnd
                60,  //u4D2TStart
            },
            //rAEAOENVRAMParam =
            {
                1,      // i4AOEStrengthIdx: 0 / 1 / 2
                130,    // u4BVCompRatio
                {
                    {
                        47,  //u4Y_Target
                        25,  //u4AOE_OE_percent
                        210,  //u4AOE_OEBound
                        10,    //u4AOE_DarkBound
                        950,    //u4AOE_LowlightPrecent
                        1,    //u4AOE_LowlightBound
                        145,    //u4AOESceneLV_L
                        180,    //u4AOESceneLV_H
                        40,    //u4AOE_SWHdrLE_Bound
                    },
                    {
                        47,  //u4Y_Target
                        25,  //u4AOE_OE_percent
                        210,  //u4AOE_OEBound
                        15, //20,    //u4AOE_DarkBound
                        950,    //u4AOE_LowlightPrecent
                        3, //10,    //u4AOE_LowlightBound
                        145,    //u4AOESceneLV_L
                        180,    //u4AOESceneLV_H
                        40,    //u4AOE_SWHdrLE_Bound
                    },
                    {
                        47,  //u4Y_Target
                        25,  //u4AOE_OE_percent
                        210,  //u4AOE_OEBound
                        25,    //u4AOE_DarkBound
                        950,    //u4AOE_LowlightPrecent
                        8,    //u4AOE_LowlightBound
                        145,    //u4AOESceneLV_L
                        180,    //u4AOESceneLV_H
                        40,    //u4AOE_SWHdrLE_Bound
                    }
                }
            }
        }
    },

        // AWB NVRAM
    AWB_NVRAM_START
    {
        {
            {
                // AWB calibration data
                {
                    // rUnitGain (unit gain: 1.0 = 512)
                    {
                            0,    // i4R
                            0,    // i4G
                            0    // i4B
                    },
                    // rGoldenGain (golden sample gain: 1.0 = 512)
                    {
                            0,    // i4R
                            0,    // i4G
                            0    // i4B
                    },
                    // rUnitGain TL84 (unit gain: 1.0 = 512)
                    {
                        0,    // i4R
                        0,    // i4G
                        0     // i4B
                    },
                    // rGoldenGain TL84 (golden sample gain: 1.0 = 512)
                    {
                        0,    // i4R
                        0,    // i4G
                        0     // i4B
                    },
                     // rUnitGain Alight (unit gain: 1.0 = 512)
                    {
                        0,    // i4R
                        0,    // i4G
                        0     // i4B
                    },
                    // rGoldenGain Alight (golden sample gain: 1.0 = 512)
                    {
                        0,    // i4R
                        0,    // i4G
                        0     // i4B
                    },
                    // rTuningUnitGain (Tuning sample unit gain: 1.0 = 512)
                    {
                            0,    // i4R
                            0,    // i4G
                            0    // i4B
                    },
                    // rD65Gain (D65 WB gain: 1.0 = 512)
                    {
                    1013,    // D65Gain_R
                    512,    // D65Gain_G
                    807    // D65Gain_B
                    }
                },
                // Original XY coordinate of AWB light source
                {
                    // Strobe
                        {
                    0,    // i4X
                    0    // i4Y
                        },
                        // Horizon
                        {
                    -427,    // OriX_Hor
                    -497    // OriY_Hor
                        },
                        // A
                        {
                    -310,    // OriX_A
                    -501    // OriY_A
                },
                {
                    -210,    // OriX_TL84
                    -469    // OriY_TL84
                        },
                        // TL84
                        {
                    -186,    // OriX_CWF
                    -487    // OriY_CWF
                },
                {
                    -61,    // OriX_DNP
                    -452    // OriY_DNP
                },
                {
                    84,    // OriX_D65
                    -420    // OriY_D65
                        },
                        // CWF
                        {
                    0,    // OriX_DF
                    0    // OriY_DF
                }
            },
            {
                {
                    0,    // i4X
                    0    // i4Y
                },
                {
                    -506,    // RotX_Hor
                    -416    // RotY_Hor
                },
                {
                    -391,    // RotX_A
                    -440    // RotY_A
                },
                {
                    -287,    // RotX_TL84
                    -426    // RotY_TL84
                },
                {
                    -267,    // RotX_CWF
                    -447    // RotY_CWF
                },
                {
                    -138,    // RotX_DNP
                    -434    // RotY_DNP
                        },
                        // DNP
                        {
                    11,    // RotX_D65
                    -428    // RotY_D65
                },
                {
                    -22,    // RotX_DF
                    -445    // RotY_DF
                }
                        },
            {
                {
                    512,    // i4R
                    512,    // i4G
                    512    // i4B
                },
                {
                    563,    // AWBGAIN_HOR_R
                    512,    // AWBGAIN_HOR_G
                    1790    // AWBGAIN_HOR_B
                },
                        // D65
                        {
                    663,    // AWBGAIN_A_R
                    512,    // AWBGAIN_A_G
                    1536    // AWBGAIN_A_B
                },
                {
                    727,    // AWBGAIN_TL84_R
                    512,    // AWBGAIN_TL84_G
                    1282    // AWBGAIN_TL84_B
                },
                {
                    770,    // AWBGAIN_CWF_R
                    512,    // AWBGAIN_CWF_G
                    1273    // AWBGAIN_CWF_B
                },
                {
                    868,    // AWBGAIN_DNP_R
                    512,    // AWBGAIN_DNP_G
                    1025    // AWBGAIN_DNP_B
                },
                {
                    1013,    // AWBGAIN_D65_R
                    512,    // AWBGAIN_D65_G
                    807    // AWBGAIN_D65_B
                        },
                        // DF
                        {
                    512,    // AWBGAIN_DF_R
                    512,    // AWBGAIN_DF_G
                    512    // AWBGAIN_DF_B
                }
            },
            {
                10,    // RotationAngle
                252,    // Cos
                44    // Sin
            },
            {
                -180,    // i4SlopeNumerator
                128    // i4SlopeDenominator
            },
            {
                101, // i4PrefRatio100
                {
                    983,    // i4R
                    530,    // i4G
                    827    // i4B
                },
                {
                    703,    // i4R
                    512,    // i4G
                    1353    // i4B
                },
                {
                    1013,    // i4R
                    512,    // i4G
                    807    // i4B
                },
                {
                    840,        // i4R
                    512,        // i4G
                    1053        // i4B
                }
            },
            {
                {
                    0,    // OriX_DF
                    0,    // i4LeftBound
                    0,    // i4UpperBound
                    0    // OriY_DF
                },
                {
                    -329,    // TungRightBound
                    -906,    // TungLeftBound
                    -361,    // TungUpperBound
                    -433    // TungLowerBound
                },
                {
                    -329,    // WFluoRightBound
                    -906,    // WFluoLeftBound
                    -433,    // WFluoUpperBound
                    -537    // WFluoLowerBound
                },
                {
                    -186,    // FluoRightBound
                    -329,    // FluoLeftBound
                    -368,    // FluoUpperBound
                    -437    // FluoLowerBound
                },
                {
                -159,    // CWFRightBound
                -329,    // CWFLeftBound
                -437,    // CWFUpperBound
                -502    // CWFLowerBound
                },
                {
                    70,    // DayRightBound
                    -186,    // DayLeftBound
                    -368,    // DayUpperBound
                    -437    // DayLowerBound
                },
                {
                    371,    // ShadeRightBound
                    70,    // ShadeLeftBound
                    -368,    // ShadeUpperBound
                    -436    // ShadeLowerBound
                },
                {
                    41,    // DFRightBound
                    -159,    // DFLeftBound
                    -437,    // DFUpperBound
                    -502    // DFLowerBound
                        }
                },
            {
                // Rotated XY coordinate of AWB light source
                {
                    371,    // PRefRightBound
                    -906,    // PRefLeftBound
                    0,    // PRefUpperBound
                    -537    // PRefLowerBound
                },
                    // Strobe
                        {
                    95,    // PDayRightBound
                    -186,    // PDayLeftBound
                    -368,    // PDayUpperBound
                    -437    // PDayLowerBound
                        },
                        // Horizon
                        {
                    195,    // PCloudyRightBound
                    20,    // PCloudyLeftBound
                    -368,    // PCloudyUpperBound
                    -437    // PCloudyLowerBound
                        },
                        // A
                        {
                    295,    // PShadeRightBound
                    20,    // PShadeLeftBound
                    -368,    // PShadeUpperBound
                    -437    // PShadeLowerBound
                        },
                        // TL84
                        {
                    -186,    // PTwiRightBound
                    -346,    // PTwiLeftBound
                    -368,    // PTwiUpperBound
                    -437    // PTwiLowerBound
                        },
                        // CWF
                        {
                    61,    // PFluoRightBound
                    -387,    // PFluoLeftBound
                    -376,    // PFluoLeftBound
                    -497    // PFluoLowerBound
                },
                {
                    -291,    // PWFluoRightBound
                    -491,    // PWFluoLeftBound
                    -376,    // PWFluoUpperBound
                    -497    // PWFluoLowerBound
                },
                {
                    -291,    // PIncaRightBound
                    -491,    // PIncaLeftBound
                    -368,    // PIncaUpperBound
                    -437    // PIncaLowerBound
                        },
                {
                    5000,    // PGWRightBound
                    -5000,    // PGWLeftBound
                    5000,    // PGWUpperBound
                    -5000    // PGWLowerBound
                }
            },
            {
                {
                    915,    // PWB_Day_R
                    512,    // PWB_Day_G
                    857    // PWB_Day_B
                },
                {
                    1083,    // PWB_Cloudy_R
                    512,    // PWB_Cloudy_G
                    674    // PWB_Cloudy_B
                },
                {
                    1145,    // PWB_Shade_R
                    512,    // PWB_Shade_G
                    623    // PWB_Shade_B
                },
                {
                    718,    // PWB_Twi_R
                    512,    // PWB_Twi_G
                    1210    // PWB_Twi_B
                },
                {
                    848,    // PWB_Fluo_R
                    512,    // PWB_Fluo_G
                    1069    // PWB_Fluo_B
                },
                {
                    660,    // PWB_WFluo_R
                    512,    // PWB_WFluo_G
                    1529    // PWB_WFluo_B
                },
                {
                    626,    // PWB_Inca_R
                    512,    // PWB_Inca_G
                    1472    // PWB_Inca_B
                },
                {
                    512,    // PWB_GW_R
                    512,    // PWB_GW_G
                    512    // PWB_GW_B
                }
            },
            {
                {
                    40,    // TUNG_SLIDER
                    4984    // TUNG_OFFS
                },
                {
                    40,    // WFluo_SLIDER
                    4899    // WFluo_OFFS
                },
                {
                    50,    // Shade_SLIDER
                    815    // Shade_OFFS
                },
                {
                    -101,   // i4Sunset_BoundXr_Thr
                    -434    // i4Sunset_BoundYr_Thr
                },
                {
                    -329,   // i4BoundXrThr
                    -430    // i4BoundYrThr
                },
                {
                    -258,   // i4BoundXrThr
                    -434    // i4BoundYrThr
                },
                {
                    -329,   // i4BoundXrThr
                    -451    // i4BoundYrThr
                },
                {
                    -244,   // i4BoundXrThr
                    -477    // i4BoundYrThr
                },
            },
            {
                {
                    2300,    // i4CCT[0]
                    2850,    // i4CCT[1]
                    3750,    // i4CCT[2]
                    5100,    // i4CCT[3]
                    6500     // i4CCT[4]
                },
                {
                -517,    // i4RotatedXCoordinate[0]
                -402,    // i4RotatedXCoordinate[1]
                -298,    // i4RotatedXCoordinate[2]
                -149,    // i4RotatedXCoordinate[3]
                0    // i4RotatedXCoordinate[4]
                }
            }
        },
        {
            0,
            {
                21, // i4Size: LUT dimension
                {0, 500, 1000, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5000, 5500, 6000, 6500, 7000, 7500, 8000, 8500, 9000, 9500, 10000}, // i4LUTIn
                {0, 350, 800, 1222, 1444, 1667, 1889, 2111, 2333, 2556, 2778, 3000, 3222, 3444, 3667, 3889, 4111, 4333, 4556, 4778, 5000} // i4LUTOut
            },
            {
                21, // i4Size: LUT dimension
                {0, 500, 1000, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5000, 5500, 6000, 6500, 7000, 7500, 8000, 8500, 9000, 9500, 10000}, // i4LUTIn
                {0, 350, 700, 1000, 1444, 1667, 1889, 2111, 2333, 2556, 2778, 3000, 3222, 3444, 3667, 3889, 4111, 4333, 4556, 4778, 5000} // i4LUTOut
            },
            {
                21, // i4Size: LUT dimension
                {0, 500, 1000, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5000, 5500, 6000, 6500, 7000, 7500, 8000, 8500, 9000, 9500, 10000}, // i4LUTIn
                {0, 500, 1000, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5000, 5500, 6000, 6500, 7000, 7500, 8000, 8500, 9000, 9500, 10000} // i4LUTOut
            },
            {
                {
                    {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, 
                    {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}
                }, // STROBE
                {
                    {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, 
                    {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}
                }, // TUNGSTEN
                {
                    {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, 
                    {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}
                }, // WARM F
                {
                    {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, 
                    {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {502, 512, 512}, {502, 512, 512}, {502, 512, 512}, {502, 512, 512}, {502, 512, 512}
                }, // F
                {
                    {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, 
                    {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}
                }, // CWF
                {
                    {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, 
                    {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {502, 512, 512}, {502, 512, 512}, {502, 512, 512}, {502, 512, 512}, {502, 512, 512}
                }, // DAYLIGHT
                {
                    {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, 
                    {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}
                }, // SHADE
                {
                    {512, 504, 512}, {512, 504, 512}, {512, 504, 512}, {512, 504, 512}, {512, 504, 512}, {512, 504, 512}, {512, 504, 512}, {512, 504, 512}, {512, 504, 512}, {512, 504, 512}, 
                    {512, 504, 512}, {512, 504, 512}, {512, 504, 512}, {512, 504, 512}, {512, 504, 512}, {512, 504, 512}, {512, 504, 512}, {512, 504, 512}, {512, 504, 512}
                } // DAYLIGHT F
            },
            {
                1,      // bEnable
                6           // i4ScalingFactor: [6] 1~12, [7] 1~6, [8] 1~3, [9] 1~2, [>=10]: 1
            },
            {
                115,    // i4InitLVThr_L
                155,    // i4InitLVThr_H
                100      // i4EnqueueLVThr
            },
            {
                65,     // i4Neutral_ParentBlk_Thr
                { 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,  50,  25,   2,   2,   2,   2,   2,   2,   2}  // (%) i4CWFDF_LUTThr
                },
                {
                    {   3,   3,   3,   3,   3,   3,   3,   3,   3,   3,   5,  10,  10,  10,  10,  10,  10,  10,  10},  // (%)
                    {   0,   0,   0,   0,   0,   3,   5,   5,   5,   5,   5,  10,  10,  10,  10,  10,  10,  10,  10},  // (%)
                    {   0,   0,   0,   0,   0,   3,   5,   5,   5,   5,   5,  10,  10,  10,  10,  10,  10,  10,  10},  // (%)
                    {   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   2,   2,   2,   2,   2,   2,   2,   2},  // (%)
                        // DNP
                    {   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   5,  10,  10,  10,  10,  10,  10,  10,  10},  // (%)
                },
                        {
                    {
                        1,          // i4Enable
                        120,        // i4LVThr_L
                        130,        // i4LVThr_H
                        10,         // i4SunsetCountThr
                        0,          // i4SunsetCountRatio_L
                        171         // i4SunsetCountRatio_H
                    },
                    {
                        1,          // i4Enable
                        50,        // i4LVThr_L
                        90,        // i4LVThr_H
                        128         // i4DaylightProb
                    },
                    {
                        1,          // i4Enable
                        50,        // i4LVThr_L
                        90,        // i4LVThr_H
                        192         // i4DaylightProb
                    },
                },
                {
                    {   0,  33,  66, 100, 100, 100, 100, 100, 100, 100, 100,  70,  30,  20,  10,   0,   0,   0,   0}
                },
                {   //LV0    1     2     3      4     5     6     7     8      9      10     11    12   13     14    15   16    17    18
                    { 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,  50,  25,   0,   0,   0,   0}, // Strobe
                    { 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,  75,  50,  25,   0,   0,   0}, // Tungsten
                    { 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,  75,  50,  25,  25,  25,   0,   0,   0}, // Warm fluorescent
                    { 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,  95,  75,  50,  25,  25,  25,   0,   0,   0}, // Fluorescent
                    {  90,  90,  90,  90,  90,  90,  90,  90,  90,  90,  80,  55,  30,  30,  30,  30,   0,   0,   0}, // CWF
                    { 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,  75,  50,  40,  30,  20}, // Daylight
                    { 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,  75,  50,  25,   0,   0,   0,   0}, // Shade
                    {  90,  90,  90,  90,  90,  90,  90,  90,  90,  90,  80,  55,  30,  30,  30,  30,   0,   0,   0} // Daylight fluorescent
                },
                {
                    0,		// project code
                    0,		// model
                    0,		// date
                    0,		// reserved 0
                    0,		// reserved 1
                    0,		// reserved 2
                    0,		// reserved 3
                    0,		// reserved 4
                }
            }
        },
        {
          {
            {
                {
                    0,    // i4R
                    0,    // i4G
                    0    // i4B
                },
                {
                    0,    // i4R
                    0,    // i4G
                    0    // i4B
                },
                {
                    0,    // i4R
                    0,    // i4G
                    0    // i4B
                },
                {
                    0,    // i4R
                    0,    // i4G
                    0    // i4B
                },
                {
                    0,    // i4R
                    0,    // i4G
                    0    // i4B
                },
                {
                    0,    // i4R
                    0,    // i4G
                    0    // i4B
                },
                {
                    0,    // i4R
                    0,    // i4G
                    0    // i4B
                },
                {
                    1013,    // D65Gain_R
                    512,    // D65Gain_G
                    807    // D65Gain_B
                }
            },
            {
                {
                    0,    // i4X
                    0    // i4Y
                },
                {
                    -427,    // OriX_Hor
                    -497    // OriY_Hor
                },
                {
                    -310,    // OriX_A
                    -501    // OriY_A
                },
                {
                    -210,    // OriX_TL84
                    -469    // OriY_TL84
                        },
                {
                    -186,    // OriX_CWF
                    -487    // OriY_CWF
                },
                {
                    -61,    // OriX_DNP
                    -452    // OriY_DNP
                },
                        // D65
                        {
                    84,    // OriX_D65
                    -420    // OriY_D65
                },
                {
                    0,    // OriX_DF
                    0    // OriY_DF
                }
            },
            {
                {
                    0,    // i4X
                    0    // i4Y
                },
                {
                    -506,    // RotX_Hor
                    -416    // RotY_Hor
                },
                {
                    -391,    // RotX_A
                    -440    // RotY_A
                },
                {
                    -287,    // RotX_TL84
                    -426    // RotY_TL84
                },
                {
                    -267,    // RotX_CWF
                    -447    // RotY_CWF
                },
                {
                    -138,    // RotX_DNP
                    -434    // RotY_DNP
                },
                {
                    11,    // RotX_D65
                    -428    // RotY_D65
                        },
                        // DF
                        {
                    -22,    // RotX_DF
                    -445    // RotY_DF
                        }
                },
                // AWB gain of AWB light source
                {
                    // Strobe
                        {
                    512,    // i4R
                                512,    // i4G
                    512    // i4B
                        },
                        // Horizon
                        {
                    563,    // AWBGAIN_HOR_R
                    512,    // AWBGAIN_HOR_R
                    1790    // AWBGAIN_HOR_B
                        },
                        // A
                        {
                    663,    // AWBGAIN_A_R
                    512,    // AWBGAIN_A_G
                    1536    // AWBGAIN_A_B
                        },
                        // TL84
                        {
                    727,    // AWBGAIN_TL84_R
                    512,    // AWBGAIN_TL84_G
                    1282    // AWBGAIN_TL84_B
                        },
                        // CWF
                        {
                    770,    // AWBGAIN_CWF_R
                    512,    // AWBGAIN_CWF_G
                    1273    // AWBGAIN_CWF_B
                        },
                        // DNP
                        {
                    868,    // AWBGAIN_DNP_R
                    512,    // AWBGAIN_DNP_G
                    1025    // AWBGAIN_DNP_B
                        },
                        // D65
                        {
                    1013,    // AWBGAIN_D65_R
                    512,    // AWBGAIN_D65_G
                    807    // AWBGAIN_D65_B
                        },
                        // DF
                        {
                    512,    // AWBGAIN_DF_R
                    512,    // AWBGAIN_DF_G
                    512    // AWBGAIN_DF_B
                        }
                },
                // Rotation matrix parameter
                {
                10,    // RotationAngle
                252,    // Cos
                44    // Sin
                },
                // Daylight locus parameter
                {
                -180,    // i4SlopeNumerator
                        128    // i4SlopeDenominator
                },
	            // Predictor gain
                {
                101, // i4PrefRatio100
                        // DaylightLocus_L
                        {
                    983,    // i4R
                    530,    // i4G
                    827    // i4B
                        },
                        // DaylightLocus_H
                        {
                    703,    // i4R
                            512, // i4G
                    1353    // i4B
                        },
                        // Temporal General
                        {
                    1013,    // i4R
                            512, // i4G
                    807    // i4B
                        },
                    // AWB LSC Gain
                    {
                    840,        // i4R
                            512, // i4G
                    1053        // i4B
                    }
                },
                // AWB light area
                {
                    // Strobe
                        {
                    0,    // i4RightBound
                    0,    // i4LeftBound
                    0,    // i4UpperBound
                    0    // i4LowerBound
                        },
                        // Tungsten
                        {
                    -329,    // TungRightBound
                    -906,    // TungLeftBound
                    -361,    // TungUpperBound
                    -433    // TungLowerBound
                        },
                        // Warm fluorescent
                        {
                    -329,    // WFluoRightBound
                    -906,    // WFluoLeftBound
                    -433,    // WFluoUpperBound
                    -537    // WFluoLowerBound
                        },
                        // Fluorescent
                        {
                    -186,    // FluoRightBound
                    -329,    // FluoLeftBound
                    -368,    // FluoUpperBound
                    -437    // FluoLowerBound
                        },
                        // CWF
                        {
                -159,    // CWFRightBound
                -329,    // CWFLeftBound
                -437,    // CWFUpperBound
                -502    // CWFLowerBound
                        },
                        // Daylight
                        {
                    70,    // DayRightBound
                    -186,    // DayLeftBound
                    -368,    // DayUpperBound
                    -437    // DayLowerBound
                        },
                        // Shade
                        {
                    371,    // ShadeRightBound
                    70,    // ShadeLeftBound
                    -368,    // ShadeUpperBound
                    -436    // ShadeLowerBound
                        },
                        // Daylight Fluorescent
                        {
                    41,    // DFRightBound
                    -159,    // DFLeftBound
                    -437,    // DFUpperBound
                    -502    // DFLowerBound
                        }
                },
                // PWB light area
                {
                    // Reference area
                        {
                    371,    // PRefRightBound
                    -906,    // PRefLeftBound
                    0,    // PRefUpperBound
                    -537    // PRefLowerBound
                        },
                        // Daylight
                        {
                    95,    // PDayRightBound
                    -186,    // PDayLeftBound
                    -368,    // PDayUpperBound
                    -437    // PDayLowerBound
                        },
                        // Cloudy daylight
                        {
                    195,    // PCloudyRightBound
                    20,    // PCloudyLeftBound
                    -368,    // PCloudyUpperBound
                    -437    // PCloudyLowerBound
                        },
                        // Shade
                        {
                    295,    // PShadeRightBound
                    20,    // PShadeLeftBound
                    -368,    // PShadeUpperBound
                    -437    // PShadeLowerBound
                        },
                        // Twilight
                        {
                    -186,    // PTwiRightBound
                    -346,    // PTwiLeftBound
                    -368,    // PTwiUpperBound
                    -437    // PTwiLowerBound
                        },
                        // Fluorescent
                        {
                    61,    // PFluoRightBound
                    -387,    // PFluoLeftBound
                    -376,    // PFluoLeftBound
                    -497    // PFluoLowerBound
                        },
                        // Warm fluorescent
                        {
                    -291,    // PWFluoRightBound
                    -491,    // PWFluoLeftBound
                    -376,    // PWFluoUpperBound
                    -497    // PWFluoLowerBound
                        },
                        // Incandescent
                        {
                    -291,    // PIncaRightBound
                    -491,    // PIncaLeftBound
                    -368,    // PIncaUpperBound
                    -437    // PIncaLowerBound
                        },
                        // Gray World
                        {
			5000,	// PGWRightBound
			-5000,	// PGWLeftBound
			5000,	// PGWUpperBound
			-5000	// PGWLowerBound
                        }
                },
                // PWB default gain
                {
                    // Daylight
                        {
                    915,    // PWB_Day_R
			512,	// PWB_Day_G
                    857    // PWB_Day_B
                        },
                        // Cloudy daylight
                        {
                    1083,    // PWB_Cloudy_R
			512,	// PWB_Cloudy_G
                    674    // PWB_Cloudy_B
                        },
                        // Shade
                        {
                    1145,    // PWB_Shade_R
			512,	// PWB_Shade_G
                    623    // PWB_Shade_B
                        },
                        // Twilight
                        {
                    718,    // PWB_Twi_R
			512,	// PWB_Twi_G
                    1210    // PWB_Twi_B
                        },
                        // Fluorescent
                        {
                    848,    // PWB_Fluo_R
			512,	// PWB_Fluo_G
                    1069    // PWB_Fluo_B
                        },
                        // Warm fluorescent
                        {
                    660,    // PWB_WFluo_R
			512,	// PWB_WFluo_G
                    1529    // PWB_WFluo_B
                        },
                        // Incandescent
                        {
                    626,    // PWB_Inca_R
			512,	// PWB_Inca_G
                    1472    // PWB_Inca_B
                        },
                        // Gray World
                        {
			512,	// PWB_GW_R
			512,	// PWB_GW_G
			512	// PWB_GW_B
                        }
                },
                // AWB preference color
                {
                    // Tungsten
                        {
                    40,    // TUNG_SLIDER
                    4984    // TUNG_OFFS
                        },
                        // Warm fluorescent
                        {
                    40,    // WFluo_SLIDER
                    4899    // WFluo_OFFS
                        },
                        // Shade
                        {
			50,	// Shade_SLIDER
                    815    // Shade_OFFS
                        },
                    // Sunset Area
                    {
                    -101,   // i4Sunset_BoundXr_Thr
                    -434    // i4Sunset_BoundYr_Thr
                    },                    
                    // Shade F Area
                    {

                    -329,   // i4BoundXrThr
                    -430    // i4BoundYrThr
                    },
                    // Shade F Vertex
                    {
                    -258,   // i4BoundXrThr
                    -434    // i4BoundYrThr
                    },
                    // Shade CWF Area
                    {
                    -329,   // i4BoundXrThr
                    -451    // i4BoundYrThr
                    },
                    // Shade CWF Vertex
                    {
                    -244,   // i4BoundXrThr
                    -477    // i4BoundYrThr
                },
                },
                // CCT estimation
                {
	                // CCT
	                {
		                2300,	// i4CCT[0]
		                2850,	// i4CCT[1]
		                3750,	// i4CCT[2]
		                5100,	// i4CCT[3]
		                6500 	// i4CCT[4]
	                },
	                // Rotated X coordinate
	                {
                -517,    // i4RotatedXCoordinate[0]
                -402,    // i4RotatedXCoordinate[1]
                -298,    // i4RotatedXCoordinate[2]
                -149,    // i4RotatedXCoordinate[3]
			                0 	    // i4RotatedXCoordinate[4]
	                }
                }
            },

            // Algorithm Tuning Paramter
            {
                // AWB Backup Enable
                0,

                // Daylight locus offset LUTs for tungsten
                {
                    21, // i4Size: LUT dimension
                    {0, 500, 1000, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5000, 5500, 6000, 6500, 7000, 7500, 8000, 8500, 9000, 9500, 10000}, // i4LUTIn
                    {0, 350,  800, 1222, 1444, 1667, 1889, 2111, 2333, 2556, 2778, 3000, 3222, 3444, 3667, 3889, 4111, 4333, 4556, 4778,  5000} // i4LUTOut
                },

                // Daylight locus offset LUTs for WF
                {
                    21, // i4Size: LUT dimension
                    {0, 500, 1000, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5000, 5500, 6000, 6500, 7000, 7500, 8000, 8500, 9000, 9500, 10000}, // i4LUTIn
                {0, 350, 700, 1000, 1444, 1667, 1889, 2111, 2333, 2556, 2778, 3000, 3222, 3444, 3667, 3889, 4111, 4333, 4556, 4778, 5000} // i4LUTOut
                },

                // Daylight locus offset LUTs for shade
                {
                    21, // i4Size: LUT dimension
                    {0, 500, 1000, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5000, 5500, 6000, 6500, 7000, 7500, 8000, 8500, 9000, 9500, 10000}, // i4LUTIn
                {0, 500, 1000, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5000, 5500, 6000, 6500, 7000, 7500, 8000, 8500, 9000, 9500, 10000} // i4LUTOut
                },
                // Preference gain for each light source
                {
                    //        LV0              LV1              LV2              LV3              LV4              LV5              LV6              LV7              LV8              LV9
                    {
                        {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512},
                    //        LV10             LV11             LV12             LV13             LV14             LV15             LV16             LV17             LV18
          	            {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}
        	        }, // STROBE
        	        {
                    {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, 
           	            {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}
        	        }, // TUNGSTEN
        	        {
                    {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, 
                    {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}
        	        }, // WARM F
        	        {
                        {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512},
                        {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {502, 512, 512}, {502, 512, 512}, {502, 512, 512}, {502, 512, 512}, {502, 512, 512}
                    }, // F
                    {
                        {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512},
                        {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}
                    }, // CWF
                    {
                        {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512},
                        {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {502, 512, 512}, {502, 512, 512}, {502, 512, 512}, {502, 512, 512}, {502, 512, 512}
                    }, // DAYLIGHT
                    {
                        {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512},
                        {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}
                    }, // SHADE
                    {
                    {512, 504, 512}, {512, 504, 512}, {512, 504, 512}, {512, 504, 512}, {512, 504, 512}, {512, 504, 512}, {512, 504, 512}, {512, 504, 512}, {512, 504, 512}, {512, 504, 512}, 
                    {512, 504, 512}, {512, 504, 512}, {512, 504, 512}, {512, 504, 512}, {512, 504, 512}, {512, 504, 512}, {512, 504, 512}, {512, 504, 512}, {512, 504, 512}
                    } // DAYLIGHT F
                },
                // Parent block weight parameter
                {
                    1,      // bEnable
                    6           // i4ScalingFactor: [6] 1~12, [7] 1~6, [8] 1~3, [9] 1~2, [>=10]: 1
                },
                // AWB LV threshold for predictor
                {
                115,    // i4InitLVThr_L
                155,    // i4InitLVThr_H
                100      // i4EnqueueLVThr
                },
                // AWB number threshold for temporal predictor
                {
                        65,     // i4Neutral_ParentBlk_Thr
                    //LV0   1    2    3    4    5    6    7    8    9    10   11   12   13   14   15   16   17   18
                    { 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,  50,  25,   2,   2,   2,   2,   2,   2,   2}  // (%) i4CWFDF_LUTThr
                },
                // AWB light neutral noise reduction for outdoor
                {
                    //LV0  1    2    3    4    5    6    7    8    9    10   11   12   13   14   15   16   17   18
                    // Non neutral
	                { 3,   3,   3,   3,   3,   3,   3,   3,    3,   3,   5,  10,  10,  10,  10,  10,  10,  10,  10},  // (%)
	                // Flurescent
                    {   0,   0,   0,   0,   0,   3,   5,   5,   5,   5,   5,  10,  10,  10,  10,  10,  10,  10,  10},  // (%)
	                // CWF
                    {   0,   0,   0,   0,   0,   3,   5,   5,   5,   5,   5,  10,  10,  10,  10,  10,  10,  10,  10},  // (%)
	                // Daylight
	                { 0,   0,   0,   0,   0,   0,   0,   0,    0,   0,   0,   2,   2,   2,   2,   2,   2,   2,   2},  // (%)
	                // DF
	                { 0,   0,   0,   0,   0,   0,   0,   0,    0,   0,   5,  10,  10,  10,  10,  10,  10,  10,  10},  // (%)
                },
                // AWB feature detection
                {
                    // Sunset Prop
                    {
                        1,          // i4Enable
                        120,        // i4LVThr_L
                        130,        // i4LVThr_H
                        10,         // i4SunsetCountThr
                        0,          // i4SunsetCountRatio_L
                        171         // i4SunsetCountRatio_H
                    },

                    // Shade F Detection
                    {
                        1,          // i4Enable
                        50,        // i4LVThr_L
                        90,        // i4LVThr_H
                        128         // i4DaylightProb
                    },

                    // Shade CWF Detection
                    {
                        1,          // i4Enable
                        50,        // i4LVThr_L
                        90,        // i4LVThr_H
                        192         // i4DaylightProb
                    },

                },

                // AWB non-neutral probability for spatial and temporal weighting look-up table (Max: 100; Min: 0)
                {
                    //LV0   1    2    3    4    5    6    7    8    9    10   11   12   13   14   15   16   17   18
                    {   0,  33,  66, 100, 100, 100, 100, 100, 100, 100, 100,  70,  30,  20,  10,   0,   0,   0,   0}
                },

                // AWB daylight locus probability look-up table (Max: 100; Min: 0)
                {
                    //LV0  1    2    3    4    5    6    7    8    9     10    11   12   13   14   15  16   17   18
                    {100, 100, 100, 100, 100, 100, 100, 100, 100, 100,  100,  100, 100,  50,  25,   0,  0,   0,   0}, // Strobe
                    { 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,  75,  50,  25,   0,   0,   0}, // Tungsten
                    {100, 100, 100, 100, 100, 100, 100, 100, 100, 100,  100,   75,  50,  25,  25,  25,  0,   0,   0}, // Warm fluorescent
                    { 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,  95,  75,  50,  25,  25,  25,   0,   0,   0}, // Fluorescent
                    { 90,  90,  90,  90,  90,  90,  90,  90,  90,  90,   80,   55,  30,  30,  30,  30,  0,   0,   0}, // CWF
                    {100, 100, 100, 100, 100, 100, 100, 100, 100, 100,  100,  100, 100, 100,  75,  50, 40,  30,  20}, // Daylight
                    {100, 100, 100, 100, 100, 100, 100, 100, 100, 100,  100,  100,  75,  50,  25,   0,  0,   0,   0}, // Shade
                    { 90,  90,  90,  90,  90,  90,  90,  90,  90,  90,   80,   55,  30,  30,  30,  30,  0,   0,   0}  // Daylight fluorescent
                },

                // AWB tuning information
                // AWB calibration data
                    // rUnitGain (unit gain: 1.0 = 512)
                    // rGoldenGain (golden sample gain: 1.0 = 512)
                    // rUnitGain TL84 (unit gain: 1.0 = 512)
                    // rGoldenGain TL84 (golden sample gain: 1.0 = 512)
                     // rUnitGain Alight (unit gain: 1.0 = 512)
                    // rGoldenGain Alight (golden sample gain: 1.0 = 512)
                    // rTuningUnitGain (Tuning sample unit gain: 1.0 = 512)
                    // rD65Gain (D65 WB gain: 1.0 = 512)
                // Original XY coordinate of AWB light source
                    // Strobe
                        // Horizon
                        // A
                        // TL84
                        // CWF
                        // DNP
                        // D65
                        // DF
                // Rotated XY coordinate of AWB light source
                    // Strobe
                        // Horizon
                        // A
                        // TL84
                        // CWF
                        // DNP
                        // D65
                        // DF
                // AWB gain of AWB light source
                    // Strobe
                        // Horizon
                        // A
                        // TL84
                        // CWF
                        // DNP
                        // D65
                        // DF
                // Rotation matrix parameter
                // Daylight locus parameter
	            // Predictor gain
                    // i4PrefRatio100

                        // DaylightLocus_L
                        // DaylightLocus_H
                        // Temporal General
                    // AWB LSC Gain
                // AWB light area
                    // Strobe
                        // Tungsten
                        // Warm fluorescent
                        // Fluorescent
                        // CWF
                        // Daylight
                        // Shade
                        // Daylight Fluorescent
                // PWB light area
                    // Reference area
                        // Daylight
                        // Cloudy daylight
                        // Shade
                        // Twilight
                        // Fluorescent
                        // Warm fluorescent
                        // Incandescent
                        // Gray World
                // PWB default gain
                    // Daylight
                        // Cloudy daylight
                        // Shade
                        // Twilight
                        // Fluorescent
                        // Warm fluorescent
                        // Incandescent
                        // Gray World
                // AWB preference color
                    // Tungsten
                        // Warm fluorescent
                        // Shade
                    // Sunset Area
                    // Shade F Area

                    // Shade F Vertex

                    // Shade CWF Area
                    // Shade CWF Vertex
                // CCT estimation
	                // CCT
	                // Rotated X coordinate

            // Algorithm Tuning Paramter
                // AWB Backup Enable

                // Daylight locus offset LUTs for tungsten
                    //{0, 500, 1000, 1333, 1667, 2000, 2333, 2667, 3000, 3333, 3667, 4000, 4333, 4667, 5000, 5333, 5667, 6000, 6333, 6667,  7000} // i4LUTOut
                    //{0, 500, 1000, 1500, 2000, 2313, 2625, 2938, 3250, 3563, 3875, 4188, 4500, 4813, 5125, 5438, 5750, 6063, 6375, 6688,  7000} // i4LUTOut

                // Daylight locus offset LUTs for WF

                // Daylight locus offset LUTs for shade
                // Preference gain for each light source
                    //        LV0              LV1              LV2              LV3              LV4              LV5              LV6              LV7              LV8              LV9
                    //        LV10             LV11             LV12             LV13             LV14             LV15             LV16             LV17             LV18
                // Parent block weight parameter
                // AWB LV threshold for predictor
                // AWB number threshold for temporal predictor
                    //LV0   1    2    3    4    5    6    7    8    9    10   11   12   13   14   15   16   17   18
                // AWB light neutral noise reduction for outdoor
                    //LV0  1    2    3    4    5    6    7    8    9    10   11   12   13   14   15   16   17   18
                    // Non neutral
	                // Flurescent
	                // CWF
	                // Daylight
	                // DF
                // AWB feature detection
                    // Sunset Prop

                    // Shade F Detection

                    // Shade CWF Detection


                // AWB non-neutral probability for spatial and temporal weighting look-up table (Max: 100; Min: 0)
                    //LV0   1    2    3    4    5    6    7    8    9    10   11   12   13   14   15   16   17   18

                // AWB daylight locus probability look-up table (Max: 100; Min: 0)
                    //LV0  1    2    3    4    5    6    7    8    9     10    11   12   13   14   15  16   17   18

                // AWB tuning information
                {
                    0,		// project code
                    0,		// model
                    0,		// date
                    0,          // reserved 0 
                    0,		// reserved 1
                    0,		// reserved 2
                    0,		// reserved 3
                    0,		// reserved 4
                }
            }
        }
    },

    // Flash AWB NVRAM
    {
#include INCLUDE_FILENAME_FLASH_AWB_PARA
    },

    {0}
};

#include INCLUDE_FILENAME_ISP_LSC_PARAM
//};  //  namespace

const CAMERA_TSF_TBL_STRUCT CAMERA_TSF_DEFAULT_VALUE =
{
    {
        1,  // isTsfEn
        2,  // tsfCtIdx
        {20, 2000, -110, -110, 512, 512, 512, 0}    // rAWBInput[8]
    },

#include INCLUDE_FILENAME_TSF_PARA
#include INCLUDE_FILENAME_TSF_DATA
};

const NVRAM_CAMERA_FEATURE_STRUCT CAMERA_FEATURE_DEFAULT_VALUE =
{
#include INCLUDE_FILENAME_FEATURE_PARA
};

#if defined(AGOLD_CAMERA_VERSION)
#include "agold_camera_version.h"
#endif 

agold_camera_version agold_camera_para = {
	"SY_50065_v1",
	(NVRAM_CAMERA_ISP_PARAM_STRUCT*)&CAMERA_ISP_DEFAULT_VALUE,
	(NVRAM_CAMERA_3A_STRUCT*)&CAMERA_3A_NVRAM_DEFAULT_VALUE,
	(NVRAM_CAMERA_SHADING_STRUCT*)&CAMERA_SHADING_DEFAULT_VALUE,
	&g_PlineTableMapping,
	(CAMERA_TSF_TBL_STRUCT*)&CAMERA_TSF_DEFAULT_VALUE,
	&CAMERA_FEATURE_DEFAULT_VALUE,	
};
