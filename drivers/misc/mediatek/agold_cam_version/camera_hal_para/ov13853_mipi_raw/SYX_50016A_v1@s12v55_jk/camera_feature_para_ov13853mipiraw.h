#ifndef __FEATURE_TUNING_PARA_H__
#define __FEATURE_TUNING_PARA_H__

{
    2664,1500,0,
    0.015740,     0.000000,     0.000000,     0.000000,     1969.723191,     0.005298, 
    0.015740,     0.000000,     0.000000,     0.000000,     1969.723191,     0.005298, 
    0.015740,     0.000000,     0.000000,     0.000000,     1969.723191,     0.005298,     // pre, cap, normal_video
    0.015740,     0.031489,     0.031489,     0.000000,     0.000000,     0.000000,     0.000000,     0.000000,     0.000000,     0.000000,     0.000000,     0.000000,     0.000000,     0.000000,     0.000000,     0.000000,     0.000000,     0.000000,     0.000000,     0.000000, 
    //Rerserved1
    0.000000,     0.000000,     0.000000,     0.000000,     0.000000,     0.000000,     0.000000,     0.000000,     0.000000,     0.000000,     0.000000,     0.000000,     0.000000,     0.000000,     0.000000,     0.000000,     0.000000,     0.000000,     0.000000,     0.000000, 
    //Rerserved2
    0.000000,     0.000000,     0.000000,     0.000000,     0.000000,     0.000000,     0.000000,     0.000000,     0.000000,     0.000000,     0.000000,     0.000000,     0.000000,     0.000000,     0.000000,     0.000000,     0.000000,     0.000000,     0.000000,     0.000000, 


},
{
    max_frame_number            :   4,
    bss_clip_th                 :   8,
    memc_bad_mv_range           :   32,
    memc_bad_mv_rate_th         :   48,
    //
    mfll_iso_th                 :   400,
    //
    ais_exp_th                  :   33000,
    ais_advanced_tuning_en      :   1,
    ais_advanced_max_iso        :   1600,
    ais_advanced_max_exposure   :   66000,
    //
    reserved                    :   {
                                    16667,  //ais_exp_th0, default=16667 us, must < ais_exp_th
                                    1200,   //ais_iso_th0, default=1200, must < ais_advanced_max_iso
                                    },
},
{
    { // iso 100, single
        50 , 8     , 32    , 28    , 24  , 20  , 55552 , 64  , 128 , 192 ,
        0  , 0     , 16    , 7     , 300 , 0   , 0    , 0   , 0   , 0   ,
        0  , 55552 , 56905 , 46189 , 0   , 0   , 0    , 0   , 0   , 0   ,
        0  , 0     , 0     , 1     , 0   , 0   , 0    , 0   , 0   , -4  ,
        -4 , -4    , -4    , 0     , 0   , 0   , 0    , 0   , 0   , 0   ,
        1  , 0     , 0     , 39    , 103 , 14  , 21   , 5   , 35  , 255 ,
        64 , 0     , 68    , 0     , 224 , 0   , 56   , 11  , 25  , 1   ,
        0  , 0     , 0     , 16    , 270 , 286 , -128 , 127 , 64  , 0   ,
    },
    { // iso 200, single
        50 , 8     , 32    , 28    , 24  , 20  , 55552 , 64  , 128 , 192 ,
        0  , 0     , 16    , 7     , 300 , 0   , 0    , 0   , 0   , 0   ,
        0  , 55552 , 56905 , 46189 , 0   , 0   , 0    , 0   , 0   , 0   ,
        0  , 0     , 0     , 1     , 0   , 0   , 0    , 0   , 0   , -4  ,
        -4 , -4    , -4    , 0     , 0   , 0   , 0    , 0   , 0   , 0   ,
        1  , 0     , 0     , 39    , 103 , 14  , 21   , 5   , 35  , 255 ,
        64 , 0     , 68    , 0     , 224 , 0   , 56   , 11  , 25  , 1   ,
        0  , 0     , 0     , 16    , 270 , 286 , -128 , 127 , 64  , 0   ,
    },
    { // iso 400, single
        50 , 8     , 32    , 28    , 24  , 20  , 55552 , 64  , 128 , 192 ,
        0  , 0     , 16    , 7     , 300 , 0   , 0    , 0   , 0   , 0   ,
        0  , 55552 , 56905 , 46189 , 0   , 0   , 0    , 0   , 0   , 0   ,
        0  , 0     , 0     , 1     , 0   , 0   , 0    , 0   , 0   , -4  ,
        -4 , -4    , -4    , 0     , 0   , 0   , 0    , 0   , 0   , 0   ,
        1  , 0     , 0     , 39    , 103 , 14  , 21   , 5   , 35  , 255 ,
        64 , 0     , 68    , 0     , 224 , 0   , 56   , 11  , 25  , 1   ,
        0  , 0     , 0     , 16    , 270 , 286 , -128 , 127 , 64  , 0   ,
    },
    { // iso 800, single
        50 , 8     , 32    , 28    , 24  , 20  , 55552 , 64  , 128 , 192 ,
        0  , 0     , 16    , 7     , 300 , 0   , 0    , 0   , 0   , 0   ,
        0  , 55552 , 56905 , 46189 , 0   , 0   , 0    , 0   , 0   , 0   ,
        0  , 0     , 0     , 1     , 0   , 0   , 0    , 0   , 0   , -4  ,
        -4 , -4    , -4    , 0     , 0   , 0   , 0    , 0   , 0   , 0   ,
        1  , 0     , 0     , 39    , 103 , 14  , 21   , 5   , 35  , 255 ,
        64 , 0     , 68    , 0     , 224 , 0   , 56   , 11  , 25  , 1   ,
        0  , 0     , 0     , 16    , 270 , 286 , -128 , 127 , 64  , 0   ,
    },
    { // iso 1200, single
        50 , 8     , 32    , 28    , 24  , 20  , 55552 , 64  , 128 , 192 ,
        0  , 0     , 16    , 7     , 300 , 0   , 0    , 0   , 0   , 0   ,
        0  , 55552 , 56905 , 46189 , 0   , 0   , 0    , 0   , 0   , 0   ,
        0  , 0     , 0     , 1     , 0   , 0   , 0    , 0   , 0   , -4  ,
        -4 , -4    , -4    , 0     , 0   , 0   , 0    , 0   , 0   , 0   ,
        1  , 0     , 0     , 39    , 103 , 14  , 21   , 5   , 35  , 255 ,
        64 , 0     , 68    , 0     , 224 , 0   , 56   , 11  , 25  , 1   ,
        0  , 0     , 0     , 16    , 270 , 286 , -128 , 127 , 64  , 0   ,
    },
    { // iso 1600, single
        50 , 8     , 32    , 28    , 24  , 20  , 55552 , 64  , 128 , 192 ,
        0  , 0     , 16    , 7     , 300 , 0   , 0    , 0   , 0   , 0   ,
        0  , 55552 , 56905 , 46189 , 0   , 0   , 0    , 0   , 0   , 0   ,
        0  , 0     , 0     , 1     , 0   , 0   , 0    , 0   , 0   , -4  ,
        -4 , -4    , -4    , 0     , 0   , 0   , 0    , 0   , 0   , 0   ,
        1  , 0     , 0     , 39    , 103 , 14  , 21   , 5   , 35  , 255 ,
        64 , 0     , 68    , 0     , 224 , 0   , 56   , 11  , 25  , 1   ,
        0  , 0     , 0     , 16    , 270 , 286 , -128 , 127 , 64  , 0   ,
    },
    { // iso 2000, single
        50 , 8     , 32    , 28    , 24  , 20  , 55552 , 64  , 128 , 192 ,
        0  , 0     , 16    , 7     , 300 , 0   , 0    , 0   , 0   , 0   ,
        0  , 55552 , 56905 , 46189 , 0   , 0   , 0    , 0   , 0   , 0   ,
        0  , 0     , 0     , 1     , 0   , 0   , 0    , 0   , 0   , -4  ,
        -4 , -4    , -4    , 0     , 0   , 0   , 0    , 0   , 0   , 0   ,
        1  , 0     , 0     , 39    , 103 , 14  , 21   , 5   , 35  , 255 ,
        64 , 0     , 68    , 0     , 224 , 0   , 56   , 11  , 25  , 1   ,
        0  , 0     , 0     , 16    , 270 , 286 , -128 , 127 , 64  , 0   ,
    },
    { // iso 2400, single
        50 , 8     , 32    , 28    , 24  , 20  , 55552 , 64  , 128 , 192 ,
        0  , 0     , 16    , 7     , 300 , 0   , 0    , 0   , 0   , 0   ,
        0  , 55552 , 56905 , 46189 , 0   , 0   , 0    , 0   , 0   , 0   ,
        0  , 0     , 0     , 1     , 0   , 0   , 0    , 0   , 0   , -4  ,
        -4 , -4    , -4    , 0     , 0   , 0   , 0    , 0   , 0   , 0   ,
        1  , 0     , 0     , 39    , 103 , 14  , 21   , 5   , 35  , 255 ,
        64 , 0     , 68    , 0     , 224 , 0   , 56   , 11  , 25  , 1   ,
        0  , 0     , 0     , 16    , 270 , 286 , -128 , 127 , 64  , 0   ,
    },
    { // iso 2800, single
        50 , 8     , 32    , 28    , 24  , 20  , 55552 , 64  , 128 , 192 ,
        0  , 0     , 16    , 7     , 300 , 0   , 0    , 0   , 0   , 0   ,
        0  , 55552 , 56905 , 46189 , 0   , 0   , 0    , 0   , 0   , 0   ,
        0  , 0     , 0     , 1     , 0   , 0   , 0    , 0   , 0   , -4  ,
        -4 , -4    , -4    , 0     , 0   , 0   , 0    , 0   , 0   , 0   ,
        1  , 0     , 0     , 39    , 103 , 14  , 21   , 5   , 35  , 255 ,
        64 , 0     , 68    , 0     , 224 , 0   , 56   , 11  , 25  , 1   ,
        0  , 0     , 0     , 16    , 270 , 286 , -128 , 127 , 64  , 0   ,
    },
    { // iso 3200, single
        50 , 8     , 32    , 28    , 24  , 20  , 55552 , 64  , 128 , 192 ,
        0  , 0     , 16    , 7     , 300 , 0   , 0    , 0   , 0   , 0   ,
        0  , 55552 , 56905 , 46189 , 0   , 0   , 0    , 0   , 0   , 0   ,
        0  , 0     , 0     , 1     , 0   , 0   , 0    , 0   , 0   , -4  ,
        -4 , -4    , -4    , 0     , 0   , 0   , 0    , 0   , 0   , 0   ,
        1  , 0     , 0     , 39    , 103 , 14  , 21   , 5   , 35  , 255 ,
        64 , 0     , 68    , 0     , 224 , 0   , 56   , 11  , 25  , 1   ,
        0  , 0     , 0     , 16    , 270 , 286 , -128 , 127 , 64  , 0   ,
    },
    { // preserved, ANR off, single
        50 , 8     , 32    , 28    , 24  , 20  , 55552 , 64  , 128 , 192 ,
        0  , 0     , 16    , 7     , 300 , 0   , 0    , 0   , 0   , 0   ,
        0  , 55552 , 56905 , 46189 , 0   , 0   , 0    , 0   , 0   , 0   ,
        0  , 0     , 0     , 1     , 0   , 0   , 0    , 0   , 0   , -4  ,
        -4 , -4    , -4    , 0     , 0   , 0   , 0    , 0   , 0   , 0   ,
        1  , 0     , 0     , 39    , 103 , 14  , 21   , 5   , 35  , 255 ,
        64 , 0     , 68    , 0     , 224 , 0   , 56   , 11  , 25  , 1   ,
        0  , 0     , 0     , 16    , 270 , 286 , -128 , 127 , 64  , 0   ,
    },
    { // preserved, ANR on, single
        50 , 8     , 32    , 28    , 24  , 20  , 55552 , 64  , 128 , 192 ,
        0  , 0     , 16    , 7     , 300 , 0   , 0    , 0   , 0   , 0   ,
        0  , 55552 , 56905 , 46189 , 0   , 0   , 0    , 0   , 0   , 0   ,
        0  , 0     , 0     , 1     , 0   , 0   , 0    , 0   , 0   , -4  ,
        -4 , -4    , -4    , 0     , 0   , 0   , 0    , 0   , 0   , 0   ,
        1  , 0     , 0     , 39    , 103 , 14  , 21   , 5   , 35  , 255 ,
        64 , 0     , 68    , 0     , 224 , 0   , 56   , 11  , 25  , 1   ,
        0  , 0     , 0     , 16    , 270 , 286 , -128 , 127 , 64  , 0   ,
    },
    { // iso 100, mfll
        50 , 8     , 32    , 28    , 24  , 20  , 55552 , 64  , 128 , 192 ,
        0  , 0     , 16    , 7     , 300 , 0   , 0    , 0   , 0   , 0   ,
        0  , 55552 , 56905 , 46189 , 0   , 0   , 0    , 0   , 0   , 0   ,
        0  , 0     , 0     , 1     , 0   , 0   , 0    , 0   , 0   , -4  ,
        -4 , -4    , -4    , 0     , 0   , 0   , 0    , 0   , 0   , 0   ,
        1  , 0     , 0     , 39    , 103 , 14  , 21   , 5   , 35  , 255 ,
        64 , 0     , 68    , 0     , 224 , 0   , 56   , 11  , 25  , 1   ,
        0  , 0     , 0     , 16    , 270 , 286 , -128 , 127 , 64  , 0   ,
    },
    { // iso 200, mfll
        50 , 8     , 32    , 28    , 24  , 20  , 55552 , 64  , 128 , 192 ,
        0  , 0     , 16    , 7     , 300 , 0   , 0    , 0   , 0   , 0   ,
        0  , 55552 , 56905 , 46189 , 0   , 0   , 0    , 0   , 0   , 0   ,
        0  , 0     , 0     , 1     , 0   , 0   , 0    , 0   , 0   , -4  ,
        -4 , -4    , -4    , 0     , 0   , 0   , 0    , 0   , 0   , 0   ,
        1  , 0     , 0     , 39    , 103 , 14  , 21   , 5   , 35  , 255 ,
        64 , 0     , 68    , 0     , 224 , 0   , 56   , 11  , 25  , 1   ,
        0  , 0     , 0     , 16    , 270 , 286 , -128 , 127 , 64  , 0   ,
    },
    { // iso 400, mfll
        50 , 8     , 32    , 28    , 24  , 20  , 55552 , 64  , 128 , 192 ,
        0  , 0     , 16    , 7     , 300 , 0   , 0    , 0   , 0   , 0   ,
        0  , 55552 , 56905 , 46189 , 0   , 0   , 0    , 0   , 0   , 0   ,
        0  , 0     , 0     , 1     , 0   , 0   , 0    , 0   , 0   , -4  ,
        -4 , -4    , -4    , 0     , 0   , 0   , 0    , 0   , 0   , 0   ,
        1  , 0     , 0     , 39    , 103 , 14  , 21   , 5   , 35  , 255 ,
        64 , 0     , 68    , 0     , 224 , 0   , 56   , 11  , 25  , 1   ,
        0  , 0     , 0     , 16    , 270 , 286 , -128 , 127 , 64  , 0   ,
    },
    { // iso 800, mfll
        50 , 8     , 32    , 28    , 24  , 20  , 55552 , 64  , 128 , 192 ,
        0  , 0     , 16    , 7     , 300 , 0   , 0    , 0   , 0   , 0   ,
        0  , 55552 , 56905 , 46189 , 0   , 0   , 0    , 0   , 0   , 0   ,
        0  , 0     , 0     , 1     , 0   , 0   , 0    , 0   , 0   , -4  ,
        -4 , -4    , -4    , 0     , 0   , 0   , 0    , 0   , 0   , 0   ,
        1  , 0     , 0     , 39    , 103 , 14  , 21   , 5   , 35  , 255 ,
        64 , 0     , 68    , 0     , 224 , 0   , 56   , 11  , 25  , 1   ,
        0  , 0     , 0     , 16    , 270 , 286 , -128 , 127 , 64  , 0   ,
    },
    { // iso 1200, mfll
        50 , 8     , 32    , 28    , 24  , 20  , 55552 , 64  , 128 , 192 ,
        0  , 0     , 16    , 7     , 300 , 0   , 0    , 0   , 0   , 0   ,
        0  , 55552 , 56905 , 46189 , 0   , 0   , 0    , 0   , 0   , 0   ,
        0  , 0     , 0     , 1     , 0   , 0   , 0    , 0   , 0   , -4  ,
        -4 , -4    , -4    , 0     , 0   , 0   , 0    , 0   , 0   , 0   ,
        1  , 0     , 0     , 39    , 103 , 14  , 21   , 5   , 35  , 255 ,
        64 , 0     , 68    , 0     , 224 , 0   , 56   , 11  , 25  , 1   ,
        0  , 0     , 0     , 16    , 270 , 286 , -128 , 127 , 64  , 0   ,
    },
    { // iso 1600, mfll
        50 , 8     , 32    , 28    , 24  , 20  , 55552 , 64  , 128 , 192 ,
        0  , 0     , 16    , 7     , 300 , 0   , 0    , 0   , 0   , 0   ,
        0  , 55552 , 56905 , 46189 , 0   , 0   , 0    , 0   , 0   , 0   ,
        0  , 0     , 0     , 1     , 0   , 0   , 0    , 0   , 0   , -4  ,
        -4 , -4    , -4    , 0     , 0   , 0   , 0    , 0   , 0   , 0   ,
        1  , 0     , 0     , 39    , 103 , 14  , 21   , 5   , 35  , 255 ,
        64 , 0     , 68    , 0     , 224 , 0   , 56   , 11  , 25  , 1   ,
        0  , 0     , 0     , 16    , 270 , 286 , -128 , 127 , 64  , 0   ,
    },
    { // iso 2000, mfll
        50 , 8     , 32    , 28    , 24  , 20  , 55552 , 64  , 128 , 192 ,
        0  , 0     , 16    , 7     , 300 , 0   , 0    , 0   , 0   , 0   ,
        0  , 55552 , 56905 , 46189 , 0   , 0   , 0    , 0   , 0   , 0   ,
        0  , 0     , 0     , 1     , 0   , 0   , 0    , 0   , 0   , -4  ,
        -4 , -4    , -4    , 0     , 0   , 0   , 0    , 0   , 0   , 0   ,
        1  , 0     , 0     , 39    , 103 , 14  , 21   , 5   , 35  , 255 ,
        64 , 0     , 68    , 0     , 224 , 0   , 56   , 11  , 25  , 1   ,
        0  , 0     , 0     , 16    , 270 , 286 , -128 , 127 , 64  , 0   ,
    },
    { // iso 2400, mfll
        50 , 8     , 32    , 28    , 24  , 20  , 55552 , 64  , 128 , 192 ,
        0  , 0     , 16    , 7     , 300 , 0   , 0    , 0   , 0   , 0   ,
        0  , 55552 , 56905 , 46189 , 0   , 0   , 0    , 0   , 0   , 0   ,
        0  , 0     , 0     , 1     , 0   , 0   , 0    , 0   , 0   , -4  ,
        -4 , -4    , -4    , 0     , 0   , 0   , 0    , 0   , 0   , 0   ,
        1  , 0     , 0     , 39    , 103 , 14  , 21   , 5   , 35  , 255 ,
        64 , 0     , 68    , 0     , 224 , 0   , 56   , 11  , 25  , 1   ,
        0  , 0     , 0     , 16    , 270 , 286 , -128 , 127 , 64  , 0   ,
    },
    { // iso 2800, mfll
        50 , 8     , 32    , 28    , 24  , 20  , 55552 , 64  , 128 , 192 ,
        0  , 0     , 16    , 7     , 300 , 0   , 0    , 0   , 0   , 0   ,
        0  , 55552 , 56905 , 46189 , 0   , 0   , 0    , 0   , 0   , 0   ,
        0  , 0     , 0     , 1     , 0   , 0   , 0    , 0   , 0   , -4  ,
        -4 , -4    , -4    , 0     , 0   , 0   , 0    , 0   , 0   , 0   ,
        1  , 0     , 0     , 39    , 103 , 14  , 21   , 5   , 35  , 255 ,
        64 , 0     , 68    , 0     , 224 , 0   , 56   , 11  , 25  , 1   ,
        0  , 0     , 0     , 16    , 270 , 286 , -128 , 127 , 64  , 0   ,
    },
    { // iso 3200, mfll
        50 , 8     , 32    , 28    , 24  , 20  , 55552 , 64  , 128 , 192 ,
        0  , 0     , 16    , 7     , 300 , 0   , 0    , 0   , 0   , 0   ,
        0  , 55552 , 56905 , 46189 , 0   , 0   , 0    , 0   , 0   , 0   ,
        0  , 0     , 0     , 1     , 0   , 0   , 0    , 0   , 0   , -4  ,
        -4 , -4    , -4    , 0     , 0   , 0   , 0    , 0   , 0   , 0   ,
        1  , 0     , 0     , 39    , 103 , 14  , 21   , 5   , 35  , 255 ,
        64 , 0     , 68    , 0     , 224 , 0   , 56   , 11  , 25  , 1   ,
        0  , 0     , 0     , 16    , 270 , 286 , -128 , 127 , 64  , 0   ,
    },
    { // preserved, ANR off, mfll
    50   , 8    , 32   , 28   , 24   ,20   , 55552, 64   , 128  , 192  ,
    0    , 0    , 16   , 7    , 300  ,0    , 0     ,0    , 0    , 0    ,
    0    , 0    , 0    , 0    , 0    ,0    , 0    , 0    , 0    , 0    ,
    0    , 0    , 0    , 0    , 0    ,0    , 0    , 0    , 0    , 0    ,
    0    , 0    , 0    , 0    , 0    ,0    , 0    , 0    , 0    , 0    ,
    0    , 0    , 0    , 0    , 0    ,0    , 0    , 0    , 0    , 0    ,
    0    , 0    , 0    , 0    , 0    ,0    , 0    , 0    , 0    , 0    ,
    0    , 0    , 0    , 0    , 0    ,0    , 0    , 0    , 0    , 0    ,
    },
    { // preserved, ANR on, mfll
    0    , 0    , 0    , 0    , 0    ,0    , 0    , 0    , 0    , 0    ,
    0    , 0    , 0    , 0    , 0    ,0    , 0     ,0    , 0    , 0    ,
    0    , 0    , 0    , 0    , 0    ,0    , 0    , 0    , 0    , 0    ,
    0    , 0    , 0    , 0    , 0    ,0    , 0    , 0    , 0    , 0    ,
    0    , 0    , 0    , 0    , 0    ,0    , 0    , 0    , 0    , 0    ,
    0    , 0    , 0    , 0    , 0    ,0    , 0    , 0    , 0    , 0    ,
    0    , 0    , 0    , 0    , 0    ,0    , 0    , 0    , 0    , 0    ,
    0    , 0    , 0    , 0    , 0    ,0    , 0    , 0    , 0    , 0    ,
    },
},
#endif // __FEATURE_TUNING_PARA_H__
