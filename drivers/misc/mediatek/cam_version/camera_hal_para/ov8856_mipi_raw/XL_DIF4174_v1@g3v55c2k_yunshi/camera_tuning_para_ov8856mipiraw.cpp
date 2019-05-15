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
#include "camera_AE_PLineTable_ov8856mipiraw.h"
#include "camera_info_ov8856mipiraw.h"
#include "camera_custom_AEPlinetable.h"
#include "camera_custom_tsf_tbl.h"


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
      0x00000000, // MIX3_CTRL_0
      0x00000000, // MIX3_CTRL_1
      0x00000000  // MIX3_SPARE
    }},
    ISPMulitCCM:{
      Poly22:{
        0,      // i4R_AVG
        0,      // i4R_STD
        0,      // i4B_AVG
        0,      // i4B_STD
        0,      // i4R_MAX
        0,      // i4R_MIN
        0,      // i4G_MAX
        0,      // i4G_MIN
        0,      // i4B_MAX
        0,      // i4B_MIN
                { // i4P00[9]
            0, 0, 0, 0, 0, 0, 0, 0, 0
                },
                { // i4P10[9]
            0, 0, 0, 0, 0, 0, 0, 0, 0
                },
                { // i4P01[9]
            0, 0, 0, 0, 0, 0, 0, 0, 0
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
        // Strobe
        {
          0,    // i4R
          0,    // i4G
          0    // i4B
        },
        // A
        {
          0,    // i4R
          0,    // i4G
          0    // i4B
        },
        // TL84
        {
          0,    // i4R
          0,    // i4G
          0    // i4B
        },
        // CWF
        {
          0,    // i4R
          0,    // i4G
          0    // i4B
        },
        // D65
        {
          0,    // i4R
          0,    // i4G
          0    // i4B
        },
        // Reserved 1
        {
          0,    // i4R
          0,    // i4G
          0    // i4B
        },
        // Reserved 2
        {
          0,    // i4R
          0,    // i4G
          0    // i4B
        },
        // Reserved 3
        {
          0,    // i4R
          0,    // i4G
          0    // i4B
        }
      },
      Weight:{
        0, // Strobe
        0, // A
        0, // TL84
        0, // CWF
        0, // D65
        0, // Reserved 1
        0, // Reserved 2
        0  // Reserved 3
      }
    },

          MDPMulitCCM:{
                Poly22:{
        0,      // i4R_AVG
        0,      // i4R_STD
        0,      // i4B_AVG
        0,      // i4B_STD
        0,      // i4R_MAX
        0,      // i4R_MIN
        0,      // i4G_MAX
        0,      // i4G_MIN
        0,      // i4B_MAX
        0,      // i4B_MIN
                  {  // i4P00[9]
            0, 0, 0, 0, 0, 0, 0, 0, 0
                  },
                  {  // i4P10[9]
            0, 0, 0, 0, 0, 0, 0, 0, 0
                  },
                  {  // i4P01[9]
            0, 0, 0, 0, 0, 0, 0, 0, 0
                  },
                  {  // i4P20[9]
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
                  // Strobe
                  {
          0,    // i4R
          0,    // i4G
          0    // i4B
                  },
                  // A
                  {
          0,    // i4R
          0,    // i4G
          0    // i4B
                  },
                  // TL84
                  {
          0,    // i4R
          0,    // i4G
          0    // i4B
                  },
                  // CWF
                  {
          0,    // i4R
          0,    // i4G
          0    // i4B
                  },
                  // D65
                  {
          0,    // i4R
          0,    // i4G
          0    // i4B
                  },
                  // Reserved 1
                  {
          0,    // i4R
          0,    // i4G
          0    // i4B
        },
        // Reserved 2
        {
          0,    // i4R
          0,    // i4G
          0    // i4B
        },
        // Reserved 3
        {
          0,    // i4R
          0,    // i4G
          0    // i4B
        }
      },
      Weight:{
        0, // Strobe
        0, // A
        0, // TL84
        0, // CWF
        0, // D65
        0, // Reserved 1
        0, // Reserved 2
        0  // Reserved 3
      }
    },
    isp_ccm_ratio: 0.000000,
    //bInvokeSmoothCCM
    bInvokeSmoothCCM: MFALSE,
    DngMetadata:
    {
        0,  //i4RefereceIlluminant1
        3,  //i4RefereceIlluminant2
        {
            // rNoiseProfile[4]
            {
                {3.530980e-6, 3.357493e-4},
                {8.098436e-8, -2.336529e-4},
            },
            {
                {3.530980e-6, 3.357493e-4},
                {8.098436e-8, -2.336529e-4},
            },
            {
                {3.530980e-6, 3.357493e-4},
                {8.098436e-8, -2.336529e-4},
            },
            {
                {3.530980e-6, 3.357493e-4},
                {8.098436e-8, -2.336529e-4},
            },
        },
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
            1280,    // u4MinGain, 1024 base = 1x                                                        
            10512,    // u4MaxGain, 16x                                                                   
            39,    // u4MiniISOGain, ISOxx                                                              
            128,    // u4GainStepUnit, 1x/8
            26,    // u4PreExpUnit                                                                       
            30,    // u4PreMaxFrameRate                                                                  
            14,    // u4VideoExpUnit                                                                     
            30,    // u4VideoMaxFrameRate                                                                
            1024,    // u4Video2PreRatio, 1024 base = 1x                                                 
            13,    // u4CapExpUnit                                                                       
            30,    // u4CapMaxFrameRate                                                                  
            1024,    // u4Cap2PreRatio, 1024 base = 1x                                                   
            15,     // u4Video1ExpUnit
            120,     // u4Video1MaxFrameRate
            1024,   // u4Video12PreRatio, 1024 base = 1x
            26,     // u4Video2ExpUnit
            30,     // u4Video2MaxFrameRate
            1024,   // u4Video22PreRatio, 1024 base = 1x
            20,     // u4Custom1ExpUnit
            30,     // u4Custom1MaxFrameRate
            1024,   // u4Custom12PreRatio, 1024 base = 1x
            20,     // u4Custom2ExpUnit
            30,     // u4Custom2MaxFrameRate
            1024,   // u4Custom22PreRatio, 1024 base = 1x
            20,     // u4Custom3ExpUnit
            30,     // u4Custom3MaxFrameRate
            1024,   // u4Custom32PreRatio, 1024 base = 1x
            20,     // u4Custom4ExpUnit
            30,     // u4Custom4MaxFrameRate
            1024,   // u4Custom42PreRatio, 1024 base = 1x
            20,     // u4Custom5ExpUnit
            30,     // u4Custom5MaxFrameRate
            1024,   // u4Custom52PreRatio, 1024 base = 1x
            24,    // u4LensFno, Fno = 2.8                                                               
            350    // u4FocusLength_100x                                                                 
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
            FALSE,            // bEnableCaptureThres
            FALSE,            // bEnableVideoThres
            FALSE,            // bEnableVideo1Thres
            FALSE,            // bEnableVideo2Thres
            TRUE,            // bEnableCustom1Thres
            TRUE,            // bEnableCustom2Thres
            TRUE,            // bEnableCustom3Thres
            TRUE,            // bEnableCustom4Thres
            TRUE,            // bEnableCustom5Thres
            TRUE,            // bEnableStrobeThres
            55,    // u4AETarget
            47,                // u4StrobeAETarget

            50,                // u4InitIndex
            4,                 // u4BackLightWeight
            32,                // u4HistStretchWeight
            4,                 // u4AntiOverExpWeight
            2,                 // u4BlackLightStrengthIndex
            2, // 2,                 // u4HistStretchStrengthIndex
            2,                 // u4AntiOverExpStrengthIndex
            2,                 // u4TimeLPFStrengthIndex
            {1, 3, 5, 7, 8}, // u4LPFConvergeTable[AE_CCT_STRENGTH_NUM]
            90,                // u4InDoorEV = 9.0, 10 base
            -6,               // i4BVOffset delta BV = -2.3
            64,                 // u4PreviewFlareOffset
            64,                 // u4CaptureFlareOffset
            3,                 // u4CaptureFlareThres
            64,                 // u4VideoFlareOffset
            3,                 // u4VideoFlareThres
            64,                 // u4CustomFlareOffset
            3,                 // u4CustomFlareThres
            64,                 // u4StrobeFlareOffset
            3,                 // u4StrobeFlareThres
            160,                 // u4PrvMaxFlareThres
            0,                 // u4PrvMinFlareThres
            160,                 // u4VideoMaxFlareThres
            0,                 // u4VideoMinFlareThres
            18,                // u4FlatnessThres              // 10 base for flatness condition.
            75,                // u4FlatnessStrength
                        //rMeteringSpec
                        {
                                //rHS_Spec
                                {
                                        TRUE,//bEnableHistStretch           // enable histogram stretch
                                        1024,//u4HistStretchWeight          // Histogram weighting value
                                        40,//u4Pcent                      // 1%=10, 0~1000
                                        160,//u4Thd                        // 0~255
                                        75,//u4FlatThd                    // 0~255

                                        120,//u4FlatBrightPcent
                                        120,//u4FlatDarkPcent
                                        //sFlatRatio
                                        {
                                            1000, //i4X1
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
                                        TRUE,//bEnableAntiOverExposure
                                        1024,//u4AntiOverExpWeight
                                        10,//u4Pcent
                                        200,//u4Thd    //gy 
                                        TRUE,//bEnableCOEP
                                        1,//u4COEPcent
                                        106,//u4COEThd
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
                                        TRUE,//bEnableBlackLight
                                        1024,//u4BackLightWeight
                                        400,//u4Pcent
                                        22,//u4Thd,
                                        255, // center luminance
                                        256, // final target limitation, 256/128 = 2x
                                        //sFgBgEVRatio
                                        {
                                                2200, //i4X1
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
                                        5,    //u4Pcent
                                        174,  //u4Thd
                                        72,   //u4FlatThd
                                        200,  //u4BrightTonePcent
                                        90,   //u4BrightToneThdMul;      // bright tone THD 1x=1024, m_u4AETarget*u4BrightToneThdMul/1024
                                        500,  //u4LowBndPcent
                                        5,    //u4LowBndThdMul, <1024, u4AETarget*u4LowBndThdMul/1024
                                        20,    //u4LowBndThdLimitMul, <1024, u4AETarget*u4LowBndThdLimitMul/1024

                                        50,  //u4FlatBrightPcent;
                                        300,   //u4FlatDarkPcent;
                                        //sFlatRatio
                                        {
                                                1200, //i4X1
                                                1024, //i4Y1
                                                2400,//i4X2
                                                0    //i4Y2
                                        },
                                        //sBVRatio
                                        {
                                                -500, //i4X1
                                                1024,  //i4Y1
                                                2000, //i4X2
                                                0     //i4Y2
                                        },
                                        TRUE, // bEnableNightSkySuppresion
                                        //sSkyBVRatio
                                        {
                                                -4000, //i4X1
                                                1024,  //i4Y1
                                                -2000,  //i4X2
                                                0     //i4Y2
                                        }
                            },
                            // rTOUCHFD_Spec
                            {
                                40,
                                50,
                                40,
                                50,
                                3,
                                120,
                                80,
                            }
                        }, //End rMeteringSpec
                        // rFlareSpec
                        {
                {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, //uPrvFlareWeightArr[16];
                {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, //uVideoFlareWeightArr[16];
                96,                                               //u4FlareStdThrHigh;
                48,                                               //u4FlareStdThrLow;
                0,                                               //u4PrvCapFlareDiff;
                4,                                               //u4FlareMaxStepGap_Fast;
                0,                                               //u4FlareMaxStepGap_Slow;
                1800,                                               //u4FlarMaxStepGapLimitBV;
                0,                                               //u4FlareAEStableCount;
                        },
                        //rAEMoveRatio =
                        {
                            100, //u4SpeedUpRatio
                            100, //u4GlobalRatio
                            190, //u4Bright2TargetEnd
                            20,   //u4Dark2TargetStart
                            90, //u4B2TEnd
                            70,  //u4B2TStart
                            60,  //u4D2TEnd
                            90,  //u4D2TStart
                        },

                        //rAEVideoMoveRatio =
                        {
                            100, //u4SpeedUpRatio
                            100, //u4GlobalRatio
                            150,  //u4Bright2TargetEnd
                            20,    //u4Dark2TargetStart
                            90, //u4B2TEnd
                            40,  //u4B2TStart
                            40,  //u4D2TEnd
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
                            40,  //u4D2TEnd
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
                            40,  //u4D2TEnd
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
                            40,  //u4D2TEnd
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
                            40,  //u4D2TEnd
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
                            40,  //u4D2TEnd
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
                            40,  //u4D2TEnd
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
                            40,  //u4D2TEnd
                            90,  //u4D2TStart
                        },

                        //rAEFaceMoveRatio =
                        {
                            100, //u4SpeedUpRatio
                            100, //u4GlobalRatio
                            190,  //u4Bright2TargetEnd
                            10,    //u4Dark2TargetStart
                            80, //u4B2TEnd
                            40,  //u4B2TStart
                            30,  //u4D2TEnd
                            60,  //u4D2TStart
                        },

                        //rAETrackingMoveRatio =
                        {
                            100, //u4SpeedUpRatio
                            100, //u4GlobalRatio
                            190,  //u4Bright2TargetEnd
                            10,    //u4Dark2TargetStart
                            80, //u4B2TEnd
                            40,  //u4B2TStart
                            30,  //u4D2TEnd
                            60,  //u4D2TStart
                        },
            //rAEAOENVRAMParam =
            {
                1,      // i4AOEStrengthIdx: 0 / 1 / 2
                130,    // u4BVCompRatio
                {//rAEAOEAlgParam
                    {//rAEAOEAlgParam[0]
                     47,  //u4Y_Target
                     10,  //u4AOE_OE_percent
                     160,  //u4AOE_OEBound
                     10,    //u4AOE_DarkBound
                     950,    //u4AOE_LowlightPrecent
                     1,    //u4AOE_LowlightBound
                     135,    //u4AOESceneLV_L
                     170,    //u4AOESceneLV_H
                     40,    //u4AOE_SWHdrLE_Bound
                },
                    {//rAEAOEAlgParam[1]
                     47,  //u4Y_Target
                     10,  //u4AOE_OE_percent
                     180,  //u4AOE_OEBound
                     15,    //u4AOE_DarkBound
                     950,    //u4AOE_LowlightPrecent
                     3,    //u4AOE_LowlightBound
                     135,    //u4AOESceneLV_L
                     170,    //u4AOESceneLV_H
                     40,    //u4AOE_SWHdrLE_Bound
                },
                    {//rAEAOEAlgParam[2]
                     47,  //u4Y_Target
                     10,  //u4AOE_OE_percent
                     200,  //u4AOE_OEBound
                     25,    //u4AOE_DarkBound
                     950,    //u4AOE_LowlightPrecent
                     8,    //u4AOE_LowlightBound
                     135,    //u4AOESceneLV_L
                     170,    //u4AOESceneLV_H
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
                    932,    // D65Gain_R
                    512,    // D65Gain_G
                    666    // D65Gain_B
                    }
                },
                // Original XY coordinate of AWB light source
                {
                    // Strobe
                        {
                    124,    // i4X
                    -318    // i4Y
                },
                // Horizon
                {
                    -300,    // OriX_Hor
                    -325    // OriY_Hor
                },
                // A
                {
                    -204,    // OriX_A
                    -351    // OriY_A
                },
                // TL84
                {
                    -119,    // OriX_TL84
                    -331    // OriY_TL84
                },
                // CWF
                {
                    -76,    // OriX_CWF
                    -374    // OriY_CWF
                },
                // DNP
                {
                    6,    // OriX_DNP
                    -345    // OriY_DNP
                },
                // D65
                {
                    124,    // OriX_D65
                    -318    // OriY_D65
                },
                // DF
                {
                    -21,    // OriX_DF
                    -371    // OriY_DF
		}
	},
	// Rotated XY coordinate of AWB light source
	{
		// Strobe
		{
                    108,    // i4X
                    -324    // i4Y
                },
                // Horizon
                {
                    -317,    // RotX_Hor
                    -310    // RotY_Hor
                },
                // A
                {
                    -222,    // RotX_A
                    -341    // RotY_A
                },
                // TL84
                {
                    -136,    // RotX_TL84
                    -325    // RotY_TL84
                },
                // CWF
                {
                    -95,    // RotX_CWF
                    -370    // RotY_CWF
                },
                // DNP
                {
                    -12,    // RotX_DNP
                    -345    // RotY_DNP
                },
                // D65
                {
                    108,    // RotX_D65
                    -324    // RotY_D65
                },
                // DF
                {
                    -40,    // RotX_DF
                    -370    // RotY_DF
                }
            },
            // AWB gain of AWB light source
            {
                // Strobe 
                {
                    932,    // i4R
                    512,    // i4G
                    666    // i4B
                },
                // Horizon 
                {
                    530,    // AWBGAIN_HOR_R
                    512,    // AWBGAIN_HOR_G
                    1193    // AWBGAIN_HOR_B
		},
		// A
		{
                    625,    // AWBGAIN_A_R
                    512,    // AWBGAIN_A_G
                    1086    // AWBGAIN_A_B
                },
                // TL84 
                {
                    682,    // AWBGAIN_TL84_R
                    512,    // AWBGAIN_TL84_G
                    943    // AWBGAIN_TL84_B
                },
                // CWF 
                {
                    767,    // AWBGAIN_CWF_R
                    512,    // AWBGAIN_CWF_G
                    942    // AWBGAIN_CWF_B
                },
                // DNP 
                {
                    823,    // AWBGAIN_DNP_R
                    512,    // AWBGAIN_DNP_G
                    810    // AWBGAIN_DNP_B
                },
                // D65 
                {
                    932,    // AWBGAIN_D65_R
                    512,    // AWBGAIN_D65_G
                    666    // AWBGAIN_D65_B
                },
                // DF 
                {
                    823,    // AWBGAIN_DF_R
                    512,    // AWBGAIN_DF_G
                    870    // AWBGAIN_DF_B
		}
                },
                // Rotation matrix parameter
                {
                3,    // RotationAngle
                256,    // Cos
                13    // Sin
            },
            // Daylight locus parameter
            {
                -141,    // i4SlopeNumerator
                128    // i4SlopeDenominator
            },
            // Predictor gain
            {
                101, // i4PrefRatio100
                // DaylightLocus_L
                {
                    902,    // i4R
                    530,    // i4G
                    686    // i4B
                        },
                        // DaylightLocus_H
                        {
                    748,    // i4R
                    512,    // i4G
                    845    // i4B
                },
                // Temporal General
                {
                    932,    // i4R
                    512,    // i4G
                    666    // i4B
                },
                // AWB LSC Gain
                {
                    781,        // i4R
                    512,        // i4G
                    808        // i4B
                    }
                },
                // AWB light area
                {
                    // Strobe
                        {
                    158,    // i4RightBound
                    58,    // i4LeftBound
                    -274,    // i4UpperBound
                    -374    // i4LowerBound
		},
		// Tungsten
		{
                    -170,    // TungRightBound
                    -717,    // TungLeftBound
                    -255,    // TungUpperBound
                    -333    // TungLowerBound
		},						                              
		// Warm fluorescent						              
		{						                                
                    -170,    // WFluoRightBound
                    -717,    // WFluoLeftBound
                    -333,    // WFluoUpperBound
                    -460    // WFluoLowerBound
		},						                              
		// Fluorescent						                  
		{						                                
                    -52,    // FluoRightBound
                    -170,    // FluoLeftBound
                    -264,    // FluoUpperBound
                    -348    // FluoLowerBound
                },
                // CWF
                {
                -71,    // CWFRightBound
                -170,    // CWFLeftBound
                -348,    // CWFUpperBound
                -425    // CWFLowerBound
                },
                // Daylight
                {
                    138,    // DayRightBound
                    -52,    // DayLeftBound
                    -264,    // DayUpperBound
                    -348    // DayLowerBound
                },
                // Shade
                {
                    468,    // ShadeRightBound
                    138,    // ShadeLeftBound
                    -264,    // ShadeUpperBound
                    -342    // ShadeLowerBound
                },
                // Daylight Fluorescent
                {
                    138,    // DFRightBound
                    -71,    // DFLeftBound
                    -348,    // DFUpperBound
                    -425    // DFLowerBound
		}
	},
	// PWB light area
	{
		// Reference area
		{
                    468,    // PRefRightBound
                    -717,    // PRefLeftBound
                    -230,    // PRefUpperBound
                    -460    // PRefLowerBound
                },
                // Daylight
                {
                    163,    // PDayRightBound
                    -52,    // PDayLeftBound
                    -264,    // PDayUpperBound
                    -348    // PDayLowerBound
                },
                // Cloudy daylight
                {
                    263,    // PCloudyRightBound
                    88,    // PCloudyLeftBound
                    -264,    // PCloudyUpperBound
                    -348    // PCloudyLowerBound
                },
                // Shade
                {
                    363,    // PShadeRightBound
                    88,    // PShadeLeftBound
                    -264,    // PShadeUpperBound
                    -348    // PShadeLowerBound
                },
                // Twilight
                {
                    -52,    // PTwiRightBound
                    -212,    // PTwiLeftBound
                    -264,    // PTwiUpperBound
                    -348    // PTwiLowerBound
                },
                // Fluorescent
                {
                    158,    // PFluoRightBound
                    -236,    // PFluoLeftBound
                    -274,    // PFluoUpperBound
                    -420    // PFluoLowerBound
                },
                // Warm fluorescent
                {
                    -122,    // PWFluoRightBound
                    -322,    // PWFluoLeftBound
                    -274,    // PWFluoUpperBound
                    -420    // PWFluoLowerBound
                },
                // Incandescent
                {
                    -122,    // PIncaRightBound
                    -322,    // PIncaLeftBound
                    -264,    // PIncaUpperBound
                    -348    // PIncaLowerBound
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
                    849,    // PWB_Day_R
                    512,    // PWB_Day_G
                    700    // PWB_Day_B
                },
                // Cloudy daylight
                {
                    990,    // PWB_Cloudy_R
                    512,    // PWB_Cloudy_G
                    591    // PWB_Cloudy_B
                },
                // Shade
                {
                    1055,    // PWB_Shade_R
                    512,    // PWB_Shade_G
                    550    // PWB_Shade_B
                },
                // Twilight
                {
                    667,    // PWB_Twi_R
                    512,    // PWB_Twi_G
                    914    // PWB_Twi_B
                },
                // Fluorescent
                {
                    797,    // PWB_Fluo_R
                    512,    // PWB_Fluo_G
                    844    // PWB_Fluo_B
                },
                // Warm fluorescent
                {
                    630,    // PWB_WFluo_R
                    512,    // PWB_WFluo_G
                    1095    // PWB_WFluo_B
                },
                // Incandescent
                {
                    595,    // PWB_Inca_R
                    512,    // PWB_Inca_G
                    1039    // PWB_Inca_B
                },
                // Gray World
                {
                    512,    // PWB_GW_R
                    512,    // PWB_GW_G
                    512    // PWB_GW_B
                }
            },
            // AWB preference color	
            {
                // Tungsten
                {
                    40,    // TUNG_SLIDER
                    3992    // TUNG_OFFS
                },
                // Warm fluorescent	
                {
                    40,    // WFluo_SLIDER
                    3992    // WFluo_OFFS
                },
                // Shade
                {
                    50,    // Shade_SLIDER
                    909    // Shade_OFFS
                },
                // Sunset Area
                {
                    19,   // i4Sunset_BoundXr_Thr
                    -345    // i4Sunset_BoundYr_Thr
                },
                // Shade F Area
                {
                    -170,   // i4BoundXrThr
                    -329    // i4BoundYrThr
                    },
                    // Shade F Vertex
                    {
                    -111,   // i4BoundXrThr
                    -339    // i4BoundYrThr
                },
                // Shade CWF Area
                {
                    -170,   // i4BoundXrThr
                    -374    // i4BoundYrThr
                },
                // Shade CWF Vertex
                {
                    -121,   // i4BoundXrThr
                    -400    // i4BoundYrThr
                }
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
                -425,    // i4RotatedXCoordinate[0]
                -330,    // i4RotatedXCoordinate[1]
                -244,    // i4RotatedXCoordinate[2]
                -120,    // i4RotatedXCoordinate[3]
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
                    {0, 350,  700,  850, 1200, 1667, 1889, 2111, 2333, 2556, 2778, 3000, 3222, 3444, 3667, 3889, 4111, 4333, 4556, 4778,  5000} // i4LUTOut
                },

                // Daylight locus offset LUTs for shade
                {
                    21, // i4Size: LUT dimension
                    {0, 500, 1000, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5000, 5500, 6000, 6500, 7000, 7500, 8000, 8500, 9000, 9500, 10000}, // i4LUTIn
                    {0, 500, 1000, 1500, 2500, 3500, 4000, 4500, 5000, 5500, 6000, 6500, 7000, 7500, 8000, 8000, 8000, 8500, 9000, 9500, 10000}  // i4LUTOut
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
          	            {530, 530, 480}, {530, 530, 480}, {530, 530, 480}, {530, 530, 480}, {530, 530, 480}, {520, 520, 496}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512},
           	            {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}
        	        }, // TUNGSTEN
        	        {
                        {512, 512, 508}, {512, 512, 508}, {512, 512, 508}, {512, 512, 508}, {512, 512, 508}, {512, 512, 508}, {512, 512, 508}, {512, 512, 508}, {512, 512, 508}, {512, 512, 508},
           	            {512, 512, 508}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}
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
                        {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512},
                        {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}
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
                        //LV0  1    2    3    4    5    6    7    8    9    10   11   12   13   14   15   16   17   18
                { 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,  50,  25,   2,   2,   2,   2,   2,   2,   2}  // (%) i4CWFDF_LUTThr
                    },
                    // AWB light neutral noise reduction for outdoor
                    {
                        //LV0  1    2    3    4    5    6    7    8    9    10   11   12   13   14   15   16   17   18
                        // Non neutral
		                { 3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  5,  10,  10,  10,  10,  10,  10,  10,  10},  // (%)
		                // Flurescent
                    {   0,   0,   0,   0,   0,   3,   5,   5,   5,   5,   5,  10,  10,  10,  10,  10,  10,  10,  10},  // (%)
		                // CWF
                    {   0,   0,   0,   0,   0,   3,   5,   5,   5,   5,   5,  10,  10,  10,  10,  10,  10,  10,  10},  // (%)
		                // Daylight
		                { 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  2,  2,  2,  2,  2,  2,  2,  2},  // (%)
		                // DF
		                { 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  5,  10,  10,  10,  10,  10,  10,  10,  10},  // (%)
                    },
                    // AWB feature detection
                    {
                        // Sunset Prop
                        {
                            1,      // i4Enable
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
                    }
                },
                // AWB non-neutral probability for spatial and temporal weighting look-up table (Max: 100; Min: 0)
                {
                    //LV0   1    2    3    4    5    6    7    8    9    10   11   12   13   14   15   16   17   18
                    {   0,  33,  66, 100, 100, 100, 100, 100, 100, 100, 100,  70,  30,  20,  10,   0,   0,   0,   0}
                },

                // AWB daylight locus probability look-up table (Max: 100; Min: 0)
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
                // AWB tuning information
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
			1071,	// i4R				
                                512,    // i4G
			696	// i4B				
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
		-360,	// i4X
		-371	// i4Y	
                        },
                        // A
                        {
			-250,	// i4X	
			-394	    // i4Y	
                        },
                        // TL84
                        {
			-77,	// i4X		
			-429	// i4Y		
		},		
		// CWF				
		{					
			-54,	// i4X	
			-480	// i4Y	
		},			
		// DNP						
		{		
			27,	// i4X		
			-416	// i4Y		
		},			
		// D65	
		{						
			159,	// i4X			
			-386	// i4Y			
		},		
		// DF		
		{		
			122,    // i4X
			-465	// i4Y	
                        }
                },
                // Rotated XY coordinate of AWB light source
                {
                    // Strobe
                        {
                                0,    // i4X
                                0    // i4Y
                        },
                        // Horizon
                        {
			-366,	// i4X				                  
			-365	// i4Y				                  
		},						                              
		// A						                            
		{						                                
			-256,	// i4X				                    
			-390	// i4Y				                    
		},						                              
		// TL84						                          
		{						                                
			-84,	// i4X				                
			-428	// i4Y				                
		},						                              
		// CWF						                          
		{						                                
			-61,	// i4X				                  
			-479	// i4Y				                  
		},						                              
		// DNP						                          
		{						                                
			21,	// i4X				                  
			-416	// i4Y				                  
		},						                              
		// D65						                          
		{						                                
			153,	// i4X				                    
			-388	// i4Y				                  
		},						                              
		// DF						                            
		{						                                
			115,	// i4X				                    
			-467	// i4Y				                      
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
			512,	// i4R
			540,	// i4G
			1387	// i4B
		},
		// A
		{
			575,	// i4R
			512,	// i4G
			1159	// i4B
		},
		// TL84
		{
			702,	// i4R
			512,	// i4G
			935	// i4B
		},
		// CWF
		{
			810,	// i4R
			512,	// i4G
			997	// i4B
		},
		// DNP
		{
			843,	// i4R
			512,	// i4G
			800	// i4B
		},
		// D65
		{
			971,	// i4R
			512,	// i4G
			649	// i4B
		},
		// DF
		{
			512,	// i4R
			512,	// i4G
			512	// i4B
                        }
                },
                // Rotation matrix parameter
                {
                    2,	// i4RotationAngle
                        256,    // i4Cos
		9	// i4Sin
                },
                // Daylight locus parameter
                {
		-135,	// i4SlopeNumerator
                        128    // i4SlopeDenominator
                },
	            // Predictor gain
                {
                    // i4PrefRatio100
                        151,

                        // DaylightLocus_L
                        {
                            971,    // i4R
                            512,    // i4G
                            649     // i4B
                        },
                        // DaylightLocus_H
                        {
                    765,    // i4R
                    512,    // i4G
                    987    // i4B
                        },
                        // Temporal General
                        {
                            971,    // i4R
                            512,    // i4G
                            649     // i4B
                        },
                        // AWB LSC Gain
                    {
                        718,    // i4R
                            512,    // i4G
                            896     // i4B
                    }
 },
                // AWB light area
                {
                    // Strobe
                        {
			0,	// StrobeRightBound
			0,	// StrobeLeftBound
			0,	// StrobeUpperBound
			0	// StrobeLowerBound
                        },
                        // Tungsten
                        {
			-179,	// TungRightBound
			-780,	// TungLeftBound
			-280,	// TungUpperBound
			-336	// TungLowerBound
		},
		// Warm fluorescent
		{
			-179,	// WFluoRightBound
			-780,	// WFluoLeftBound
			-336,	// WFluoUpperBound
			-443	// WFluoLowerBound
		},
		// Fluorescent
		{
			-24,	// FluoRightBound
			-179,	// FluoLeftBound
			-289,	// FluoUpperBound
			-384	// FluoLowerBound
		},
		// CWF
		{
			-6,	// CWFRightBound
			-179,	// CWFLeftBound
			-384,	// CWFUpperBound
			-458	// CWFLowerBound
		},
		// Daylight
		{
			168,	// DayRightBound
			-24,	// DayLeftBound
			-289,	// DayUpperBound
			-384	// DayLowerBound
		},
		// Shade
		{
			498,	// ShadeRightBound
			168,	// ShadeLeftBound
			-289,	// ShadeUpperBound
			-363	// ShadeLowerBound
		},
		// Daylight Fluorescent
		{
			168,	// DFRightBound
			-6,	// DFLeftBound
			-384,	// DFUpperBound
			-458	// DFLowerBound
		}
	},
                // PWB light area
                {
                    // Reference area
                        {
			498,	// PRefRightBound
			-780,	// PRefLeftBound
			-255,	// PRefUpperBound
			-458	// PRefLowerBound
		},
		// Daylight
		{
			193,	// PDayRightBound
			-24,	// PDayLeftBound
			-289,	// PDayUpperBound
			-384	// PDayLowerBound
		},
		// Cloudy daylight
		{
			293,	// PCloudyRightBound
			118,	// PCloudyLeftBound
			-289,	// PCloudyUpperBound
			-384	// PCloudyLowerBound
		},
		// Shade
		{
			393,	// PShadeRightBound
			118,	// PShadeLeftBound
			-289,	// PShadeUpperBound
			-384	// PShadeLowerBound
		},
		// Twilight
		{
			-24,	// PTwiRightBound
			-184,	// PTwiLeftBound
			-289,	// PTwiUpperBound
			-384	// PTwiLowerBound
		},
		// Fluorescent
		{
			188,	// PFluoRightBound
			-218,	// PFluoLeftBound
			-279,	// PFluoUpperBound
			-463	// PFluoLowerBound
		},
		// Warm fluorescent
		{
			-171,	// PWFluoRightBound
			-371,	// PWFluoLeftBound
			-279,	// PWFluoUpperBound
			-463	// PWFluoLowerBound
		},
		// Incandescent
		{
			-171,	// PIncaRightBound
			-371,	// PIncaLeftBound
			-289,	// PIncaUpperBound
			-384	// PIncaLowerBound
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
			916,	// PWB_Day_R
			512,	// PWB_Day_G
			706	// PWB_Day_B
		},
		// Cloudy daylight
		{
			1072,	// PWB_Cloudy_R
			512,	// PWB_Cloudy_G
			596	// PWB_Cloudy_B
		},
		// Shade
		{
			1144,	// PWB_Shade_R
			512,	// PWB_Shade_G
			555	// PWB_Shade_B
		},
		// Twilight
		{
			716,	// PWB_Twi_R
			512,	// PWB_Twi_G
			919	// PWB_Twi_B
		},
		// Fluorescent
		{
			844,	// PWB_Fluo_R
			512,	// PWB_Fluo_G
			848	// PWB_Fluo_B
		},
		// Warm fluorescent
		{
			604,	// PWB_WFluo_R
			512,	// PWB_WFluo_G
			1214	// PWB_WFluo_B
		},
		// Incandescent
		{
			576,	// PWB_Inca_R
			512,	// PWB_Inca_G
			1161	// PWB_Inca_B
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
			60,	// TUNG_SLIDER
			4120	// TUNG_OFFS
                        },
                        // Warm fluorescent
                        {
			50,	// WFluo_SLIDER
			4320	// WFluo_OFFS
                        },
                        // Shade
                        {
			50,	// Shade_SLIDER
			909	// Shade_OFFS
                        },
                    // Sunset Area
                    {
                        38, //64,   // i4Sunset_BoundXr_Thr
                        -350 //-463     // i4Sunset_BoundYr_Thr
                    },
                    // Shade F Area
                    {

                        -87, //-135, //-82,   // i4BoundXrThr
                        -329 //-412 //-415    // i4BoundYrThr
                    },
                    // Shade F Vertex
                    {

                        -87, //-135, //-82,   // i4BoundXrThr
                        -329 //-412 //-415    // i4BoundYrThr
                    },
                    // Shade CWF Area
                    {
                        -92,//-109, //-89,   // i4BoundXrThr
                        -413//-475 //-509    // i4BoundYrThr
                    },
                    // Shade CWF Vertex
                    {
                        -56,//-109, //-89,   // i4BoundXrThr
                        -529//-475 //-509    // i4BoundYrThr
                    }
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
			-518,	// RotatedXCoordinate0
			-409,	// RotatedXCoordinate1
			-256,	// RotatedXCoordinate2
			-131,	// RotatedXCoordinate3
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
                    //{0, 500, 1000, 1333, 1667, 2000, 2333, 2667, 3000, 3333, 3667, 4000, 4333, 4667, 5000, 5333, 5667, 6000, 6333, 6667,  7000} // i4LUTOut
                    //{0, 500, 1000, 1500, 2000, 2313, 2625, 2938, 3250, 3563, 3875, 4188, 4500, 4813, 5125, 5438, 5750, 6063, 6375, 6688,  7000} // i4LUTOut
                },

                // Daylight locus offset LUTs for WF
                {
                    21, // i4Size: LUT dimension
                    {0, 500, 1000, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5000, 5500, 6000, 6500, 7000, 7500, 8000, 8500, 9000, 9500, 10000}, // i4LUTIn
                    {0, 350,  700,  850, 1200, 1667, 1889, 2111, 2333, 2556, 2778, 3000, 3222, 3444, 3667, 3889, 4111, 4333, 4556, 4778,  5000} // i4LUTOut
                },

                // Daylight locus offset LUTs for shade
                {
                    21, // i4Size: LUT dimension
                    {0, 500, 1000, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5000, 5500, 6000, 6500, 7000, 7500, 8000, 8500, 9000, 9500, 10000}, // i4LUTIn
                    {0, 500, 1000, 1500, 2500, 3500, 4000, 4500, 5000, 5500, 6000, 6500, 7000, 7500, 8000, 8000, 8000, 8500, 9000, 9500, 10000}  // i4LUTOut
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
          	            {530, 530, 480}, {530, 530, 480}, {530, 530, 480}, {530, 530, 480}, {530, 530, 480}, {520, 520, 496}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512},
           	            {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}
        	        }, // TUNGSTEN
        	        {
                        {512, 512, 508}, {512, 512, 508}, {512, 512, 508}, {512, 512, 508}, {512, 512, 508}, {512, 512, 508}, {512, 512, 508}, {512, 512, 508}, {512, 512, 508}, {512, 512, 508},
           	            {512, 512, 508}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}
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
                        {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512},
                        {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}
                    } // DAYLIGHT F
                },
                // Parent block weight parameter
                {
                    1,      // bEnable
                    6           // i4ScalingFactor: [6] 1~12, [7] 1~6, [8] 1~3, [9] 1~2, [>=10]: 1
                },
                // AWB LV threshold for predictor
                {
                    115, //100,    // i4InitLVThr_L
                    155, //140,    // i4InitLVThr_H
                    100 //80      // i4EnqueueLVThr
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
	                { 0,   0,   0,   0,   0,   0,   0,   0,    0,   0,   5,  10,  10,  10,  10,  10,  10,  10,  10},  // (%)
	                // CWF
	                { 0,   0,   0,   0,   0,   0,   0,   0,    0,   0,   5,  10,  10,  10,  10,  10,  10,  10,  10},  // (%)
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
                        90,        // i4LVThr
                        105,        // i4LVThr
                        96 //10         // i4DaylightProb
                    },

                    // Shade CWF Detection
                    {
                        1,          // i4Enable
                        90,        // i4LVThr
                        105,        // i4LVThr
                        208 //224 //128 //35         // i4DaylightProb
                    }

                },

                    // AWB non-neutral probability for spatial and temporal weighting look-up table (Max: 100; Min: 0)
                    {
                        //LV0   1    2    3    4    5    6    7    8    9    10   11   12   13   14   15   16   17   18
                    {  90,  90,  90,  90,  90,  90,  90,  90,  90,  90,  90,  50,  30,  20,  10,   0,   0,   0,   0}
                    },

                    // AWB daylight locus probability look-up table (Max: 100; Min: 0)
                    {   
						//LV0    1     2     3      4     5     6     7     8      9      10     11    12   13     14    15   16    17    18
		                { 100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  50,  25,  0,  0,  0,  0}, // Strobe
                    { 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,  75,  50,  25,  25,  25,   0,   0,   0}, // Tungsten
                    { 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,  75,  50,  25,  25,  25,   0,   0,   0}, // Warm fluorescent
                    { 100, 100, 100, 100, 100, 100, 100, 100, 100,  95,  95,  70,  50,  25,  25,  25,   0,   0,   0}, // Fluorescent
                    {  90,  90,  90,  90,  90,  90,  90,  90,  90,  90,  80,  55,  30,  30,  30,  30,   0,   0,   0}, // CWF
                    { 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,  75,  50,  40,  30,  20}, // Daylight
                    { 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,  75,  50,  25,   0,   0,   0,   0}, // Shade
                    {  90,  90,  90,  90,  90,  90,  90,  90,  90,  90,  80,  55,  30,  30,  30,  30,   0,   0,   0} // Daylight fluorescent
                },

                // AWB tuning information
                {
                    6735,       // project code
                    5588,       // model   
                    20150624,   // date
                    0,          // reserved 0 
                    1,          // reserved 1  
                    2,          // reserved 2  
                    3,          // reserved 3 
                    4,          // reserved 4
                }
            }			                                
}							                                
},
        // Flash AWB NVRAM
        {
            #include INCLUDE_FILENAME_FLASH_AWB_PARA
        },
                                               
	{0}  //FIXED                                  
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
	"XL_DIF4174_v1",
	(NVRAM_CAMERA_ISP_PARAM_STRUCT*)&CAMERA_ISP_DEFAULT_VALUE,
	(NVRAM_CAMERA_3A_STRUCT*)&CAMERA_3A_NVRAM_DEFAULT_VALUE,
	(NVRAM_CAMERA_SHADING_STRUCT*)&CAMERA_SHADING_DEFAULT_VALUE,
	&g_PlineTableMapping,
	(CAMERA_TSF_TBL_STRUCT*)&CAMERA_TSF_DEFAULT_VALUE,
	&CAMERA_FEATURE_DEFAULT_VALUE,
	
};

