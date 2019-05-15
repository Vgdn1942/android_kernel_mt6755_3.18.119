// Flash AWB tuning parameter
{
    9, //foreground percentage
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
    512, //FlashPreferenceGain R
    512, //FlashPreferenceGain G
    512, //FlashPreferenceGain B
},

// Flash AWB calibration
{{
   { 512, 512, 512},  //duty=-1, dutyLt=-1  
   {1060, 512, 911},  //duty=0, dutyLt=-1  
   {1063, 512, 907},  //duty=1, dutyLt=-1  
   {1069, 512, 908},  //duty=2, dutyLt=-1  
   {1070, 512, 915},  //duty=3, dutyLt=-1  
   {1076, 512, 907},  //duty=4, dutyLt=-1  
   {1077, 512, 908},  //duty=5, dutyLt=-1  
   {1067, 512, 903},  //duty=6, dutyLt=-1  
   {1069, 512, 902},  //duty=7, dutyLt=-1  
   {1067, 512, 895},  //duty=8, dutyLt=-1  
   {1065, 512, 891},  //duty=9, dutyLt=-1  
   {1063, 512, 886},  //duty=10, dutyLt=-1  
   {1061, 512, 884},  //duty=11, dutyLt=-1  
   {1060, 512, 877},  //duty=12, dutyLt=-1  
   {1059, 512, 875},  //duty=13, dutyLt=-1  
   {1058, 512, 869},  //duty=14, dutyLt=-1  
   {1057, 512, 866},  //duty=15, dutyLt=-1  
   {1058, 512, 860},  //duty=16, dutyLt=-1  
   {1060, 512, 849},  //duty=17, dutyLt=-1  
   {1056, 512, 854},  //duty=18, dutyLt=-1  
   {1056, 512, 849},  //duty=19, dutyLt=-1  
   {1062, 512, 833},  //duty=20, dutyLt=-1  
   {1050, 512, 834},  //duty=21, dutyLt=-1  
   {1044, 512, 826},  //duty=22, dutyLt=-1  
   {1044, 512, 816},  //duty=23, dutyLt=-1  
   {1020, 512, 804},  //duty=24, dutyLt=-1  
   {1017, 512, 793},  //duty=25, dutyLt=-1  
   { 576, 512,2071},  //duty=-1, dutyLt=0  
   { 747, 512,1281},  //duty=0, dutyLt=0  
   { 851, 512,1105},  //duty=1, dutyLt=0  
   { 905, 512,1043},  //duty=2, dutyLt=0  
   { 934, 512,1015},  //duty=3, dutyLt=0  
   { 955, 512, 994},  //duty=4, dutyLt=0  
   { 975, 512, 972},  //duty=5, dutyLt=0  
   { 982, 512, 937},  //duty=6, dutyLt=0  
   { 995, 512, 953},  //duty=7, dutyLt=0  
   {1005, 512, 937},  //duty=8, dutyLt=0  
   {1014, 512, 924},  //duty=9, dutyLt=0  
   {1019, 512, 915},  //duty=10, dutyLt=0  
   {1022, 512, 911},  //duty=11, dutyLt=0  
   {1030, 512, 898},  //duty=12, dutyLt=0  
   {1026, 512, 889},  //duty=13, dutyLt=0  
   {1027, 512, 887},  //duty=14, dutyLt=0  
   {1028, 512, 882},  //duty=15, dutyLt=0  
   {1034, 512, 864},  //duty=16, dutyLt=0  
   {1031, 512, 871},  //duty=17, dutyLt=0  
   {1033, 512, 865},  //duty=18, dutyLt=0  
   {1037, 512, 853},  //duty=19, dutyLt=0  
   {1031, 512, 851},  //duty=20, dutyLt=0  
   {1031, 512, 840},  //duty=21, dutyLt=0  
   {1020, 512, 834},  //duty=22, dutyLt=0  
   {1035, 512, 818},  //duty=23, dutyLt=0  
   {1003, 512, 810},  //duty=24, dutyLt=0  
   { 512, 512, 512},  //duty=25, dutyLt=0  
   { 578, 512,2084},  //duty=-1, dutyLt=1  
   { 676, 512,1475},  //duty=0, dutyLt=1  
   { 764, 512,1257},  //duty=1, dutyLt=1  
   { 819, 512,1160},  //duty=2, dutyLt=1  
   { 857, 512,1103},  //duty=3, dutyLt=1  
   { 882, 512,1066},  //duty=4, dutyLt=1  
   { 892, 512,1024},  //duty=5, dutyLt=1  
   { 920, 512,1021},  //duty=6, dutyLt=1  
   { 937, 512, 999},  //duty=7, dutyLt=1  
   { 954, 512, 978},  //duty=8, dutyLt=1  
   { 970, 512, 959},  //duty=9, dutyLt=1  
   { 978, 512, 946},  //duty=10, dutyLt=1  
   { 986, 512, 932},  //duty=11, dutyLt=1  
   { 988, 512, 922},  //duty=12, dutyLt=1  
   { 994, 512, 911},  //duty=13, dutyLt=1  
   { 998, 512, 903},  //duty=14, dutyLt=1  
   {1001, 512, 900},  //duty=15, dutyLt=1  
   {1005, 512, 889},  //duty=16, dutyLt=1  
   {1008, 512, 882},  //duty=17, dutyLt=1  
   {1019, 512, 875},  //duty=18, dutyLt=1  
   {1014, 512, 870},  //duty=19, dutyLt=1  
   {1008, 512, 860},  //duty=20, dutyLt=1  
   {1005, 512, 849},  //duty=21, dutyLt=1  
   {1000, 512, 844},  //duty=22, dutyLt=1  
   {1005, 512, 828},  //duty=23, dutyLt=1  
   { 987, 512, 815},  //duty=24, dutyLt=1  
   { 512, 512, 512},  //duty=25, dutyLt=1  
   { 576, 512,2074},  //duty=-1, dutyLt=2  
   { 648, 512,1601},  //duty=0, dutyLt=2  
   { 720, 512,1366},  //duty=1, dutyLt=2  
   { 764, 512,1251},  //duty=2, dutyLt=2  
   { 800, 512,1177},  //duty=3, dutyLt=2  
   { 828, 512,1117},  //duty=4, dutyLt=2  
   { 854, 512,1096},  //duty=5, dutyLt=2  
   { 873, 512,1067},  //duty=6, dutyLt=2  
   { 894, 512,1042},  //duty=7, dutyLt=2  
   { 915, 512,1012},  //duty=8, dutyLt=2  
   { 934, 512, 986},  //duty=9, dutyLt=2  
   { 945, 512, 973},  //duty=10, dutyLt=2  
   { 954, 512, 959},  //duty=11, dutyLt=2  
   { 962, 512, 943},  //duty=12, dutyLt=2  
   { 971, 512, 926},  //duty=13, dutyLt=2  
   { 975, 512, 926},  //duty=14, dutyLt=2  
   { 978, 512, 910},  //duty=15, dutyLt=2  
   { 982, 512, 907},  //duty=16, dutyLt=2  
   { 988, 512, 888},  //duty=17, dutyLt=2  
   { 990, 512, 893},  //duty=18, dutyLt=2  
   { 991, 512, 878},  //duty=19, dutyLt=2  
   { 983, 512, 870},  //duty=20, dutyLt=2  
   { 985, 512, 857},  //duty=21, dutyLt=2  
   { 983, 512, 845},  //duty=22, dutyLt=2  
   { 982, 512, 834},  //duty=23, dutyLt=2  
   { 512, 512, 512},  //duty=24, dutyLt=2  
   { 512, 512, 512},  //duty=25, dutyLt=2  
   { 577, 512,2112},  //duty=-1, dutyLt=3  
   { 633, 512,1687},  //duty=0, dutyLt=3  
   { 693, 512,1449},  //duty=1, dutyLt=3  
   { 732, 512,1321},  //duty=2, dutyLt=3  
   { 762, 512,1231},  //duty=3, dutyLt=3  
   { 797, 512,1183},  //duty=4, dutyLt=3  
   { 820, 512,1143},  //duty=5, dutyLt=3  
   { 839, 512,1111},  //duty=6, dutyLt=3  
   { 864, 512,1068},  //duty=7, dutyLt=3  
   { 885, 512,1043},  //duty=8, dutyLt=3  
   { 905, 512,1013},  //duty=9, dutyLt=3  
   { 918, 512, 995},  //duty=10, dutyLt=3  
   { 930, 512, 978},  //duty=11, dutyLt=3  
   { 939, 512, 964},  //duty=12, dutyLt=3  
   { 948, 512, 949},  //duty=13, dutyLt=3  
   { 954, 512, 944},  //duty=14, dutyLt=3  
   { 957, 512, 929},  //duty=15, dutyLt=3  
   { 969, 512, 921},  //duty=16, dutyLt=3  
   { 968, 512, 915},  //duty=17, dutyLt=3  
   { 969, 512, 905},  //duty=18, dutyLt=3  
   { 973, 512, 892},  //duty=19, dutyLt=3  
   { 968, 512, 881},  //duty=20, dutyLt=3  
   { 964, 512, 868},  //duty=21, dutyLt=3  
   { 964, 512, 852},  //duty=22, dutyLt=3  
   { 952, 512, 842},  //duty=23, dutyLt=3  
   { 512, 512, 512},  //duty=24, dutyLt=3  
   { 512, 512, 512},  //duty=25, dutyLt=3  
   { 577, 512,2131},  //duty=-1, dutyLt=4  
   { 623, 512,1743},  //duty=0, dutyLt=4  
   { 674, 512,1504},  //duty=1, dutyLt=4  
   { 711, 512,1364},  //duty=2, dutyLt=4  
   { 748, 512,1284},  //duty=3, dutyLt=4  
   { 772, 512,1229},  //duty=4, dutyLt=4  
   { 794, 512,1182},  //duty=5, dutyLt=4  
   { 813, 512,1148},  //duty=6, dutyLt=4  
   { 835, 512,1111},  //duty=7, dutyLt=4  
   { 859, 512,1072},  //duty=8, dutyLt=4  
   { 882, 512,1035},  //duty=9, dutyLt=4  
   { 896, 512,1017},  //duty=10, dutyLt=4  
   { 907, 512, 999},  //duty=11, dutyLt=4  
   { 918, 512, 981},  //duty=12, dutyLt=4  
   { 927, 512, 963},  //duty=13, dutyLt=4  
   { 935, 512, 955},  //duty=14, dutyLt=4  
   { 942, 512, 941},  //duty=15, dutyLt=4  
   { 944, 512, 933},  //duty=16, dutyLt=4  
   { 951, 512, 924},  //duty=17, dutyLt=4  
   { 953, 512, 911},  //duty=18, dutyLt=4  
   { 951, 512, 899},  //duty=19, dutyLt=4  
   { 951, 512, 883},  //duty=20, dutyLt=4  
   { 953, 512, 868},  //duty=21, dutyLt=4  
   { 939, 512, 856},  //duty=22, dutyLt=4  
   { 512, 512, 512},  //duty=23, dutyLt=4  
   { 512, 512, 512},  //duty=24, dutyLt=4  
   { 512, 512, 512},  //duty=25, dutyLt=4  
   { 579, 512,2126},  //duty=-1, dutyLt=5  
   { 620, 512,1785},  //duty=0, dutyLt=5  
   { 662, 512,1559},  //duty=1, dutyLt=5  
   { 693, 512,1402},  //duty=2, dutyLt=5  
   { 729, 512,1328},  //duty=3, dutyLt=5  
   { 753, 512,1269},  //duty=4, dutyLt=5  
   { 773, 512,1221},  //duty=5, dutyLt=5  
   { 791, 512,1182},  //duty=6, dutyLt=5  
   { 814, 512,1138},  //duty=7, dutyLt=5  
   { 838, 512,1098},  //duty=8, dutyLt=5  
   { 861, 512,1058},  //duty=9, dutyLt=5  
   { 876, 512,1036},  //duty=10, dutyLt=5  
   { 888, 512,1017},  //duty=11, dutyLt=5  
   { 899, 512, 998},  //duty=12, dutyLt=5  
   { 910, 512, 984},  //duty=13, dutyLt=5  
   { 918, 512, 972},  //duty=14, dutyLt=5  
   { 925, 512, 954},  //duty=15, dutyLt=5  
   { 931, 512, 945},  //duty=16, dutyLt=5  
   { 935, 512, 931},  //duty=17, dutyLt=5  
   { 937, 512, 919},  //duty=18, dutyLt=5  
   { 934, 512, 911},  //duty=19, dutyLt=5  
   { 964, 512, 884},  //duty=20, dutyLt=5  
   { 929, 512, 878},  //duty=21, dutyLt=5  
   { 918, 512, 860},  //duty=22, dutyLt=5  
   { 512, 512, 512},  //duty=23, dutyLt=5  
   { 512, 512, 512},  //duty=24, dutyLt=5  
   { 512, 512, 512},  //duty=25, dutyLt=5  
   { 577, 512,2138},  //duty=-1, dutyLt=6  
   { 615, 512,1816},  //duty=0, dutyLt=6  
   { 644, 512,1589},  //duty=1, dutyLt=6  
   { 682, 512,1462},  //duty=2, dutyLt=6  
   { 714, 512,1366},  //duty=3, dutyLt=6  
   { 736, 512,1305},  //duty=4, dutyLt=6  
   { 757, 512,1253},  //duty=5, dutyLt=6  
   { 774, 512,1213},  //duty=6, dutyLt=6  
   { 797, 512,1168},  //duty=7, dutyLt=6  
   { 820, 512,1122},  //duty=8, dutyLt=6  
   { 844, 512,1079},  //duty=9, dutyLt=6  
   { 859, 512,1056},  //duty=10, dutyLt=6  
   { 872, 512,1032},  //duty=11, dutyLt=6  
   { 883, 512,1015},  //duty=12, dutyLt=6  
   { 895, 512, 998},  //duty=13, dutyLt=6  
   { 903, 512, 982},  //duty=14, dutyLt=6  
   { 910, 512, 973},  //duty=15, dutyLt=6  
   { 916, 512, 955},  //duty=16, dutyLt=6  
   { 921, 512, 937},  //duty=17, dutyLt=6  
   { 919, 512, 929},  //duty=18, dutyLt=6  
   { 917, 512, 917},  //duty=19, dutyLt=6  
   { 918, 512, 897},  //duty=20, dutyLt=6  
   { 904, 512, 880},  //duty=21, dutyLt=6  
   { 512, 512, 512},  //duty=22, dutyLt=6  
   { 512, 512, 512},  //duty=23, dutyLt=6  
   { 512, 512, 512},  //duty=24, dutyLt=6  
   { 512, 512, 512},  //duty=25, dutyLt=6  
   { 578, 512,2129},  //duty=-1, dutyLt=7  
   { 607, 512,1831},  //duty=0, dutyLt=7  
   { 640, 512,1644},  //duty=1, dutyLt=7  
   { 667, 512,1514},  //duty=2, dutyLt=7  
   { 692, 512,1425},  //duty=3, dutyLt=7  
   { 713, 512,1353},  //duty=4, dutyLt=7  
   { 733, 512,1298},  //duty=5, dutyLt=7  
   { 754, 512,1255},  //duty=6, dutyLt=7  
   { 775, 512,1203},  //duty=7, dutyLt=7  
   { 798, 512,1154},  //duty=8, dutyLt=7  
   { 822, 512,1109},  //duty=9, dutyLt=7  
   { 838, 512,1080},  //duty=10, dutyLt=7  
   { 851, 512,1055},  //duty=11, dutyLt=7  
   { 863, 512,1034},  //duty=12, dutyLt=7  
   { 875, 512,1018},  //duty=13, dutyLt=7  
   { 883, 512,1003},  //duty=14, dutyLt=7  
   { 890, 512, 990},  //duty=15, dutyLt=7  
   { 896, 512, 969},  //duty=16, dutyLt=7  
   { 896, 512, 955},  //duty=17, dutyLt=7  
   { 897, 512, 938},  //duty=18, dutyLt=7  
   { 900, 512, 925},  //duty=19, dutyLt=7  
   { 889, 512, 904},  //duty=20, dutyLt=7  
   { 885, 512, 886},  //duty=21, dutyLt=7  
   { 512, 512, 512},  //duty=22, dutyLt=7  
   { 512, 512, 512},  //duty=23, dutyLt=7  
   { 512, 512, 512},  //duty=24, dutyLt=7  
   { 512, 512, 512},  //duty=25, dutyLt=7  
   { 575, 512,2084},  //duty=-1, dutyLt=8  
   { 605, 512,1867},  //duty=0, dutyLt=8  
   { 631, 512,1693},  //duty=1, dutyLt=8  
   { 654, 512,1569},  //duty=2, dutyLt=8  
   { 678, 512,1473},  //duty=3, dutyLt=8  
   { 696, 512,1404},  //duty=4, dutyLt=8  
   { 712, 512,1348},  //duty=5, dutyLt=8  
   { 733, 512,1300},  //duty=6, dutyLt=8  
   { 753, 512,1246},  //duty=7, dutyLt=8  
   { 776, 512,1191},  //duty=8, dutyLt=8  
   { 800, 512,1140},  //duty=9, dutyLt=8  
   { 815, 512,1110},  //duty=10, dutyLt=8  
   { 829, 512,1087},  //duty=11, dutyLt=8  
   { 840, 512,1065},  //duty=12, dutyLt=8  
   { 852, 512,1042},  //duty=13, dutyLt=8  
   { 860, 512,1026},  //duty=14, dutyLt=8  
   { 865, 512,1009},  //duty=15, dutyLt=8  
   { 868, 512, 986},  //duty=16, dutyLt=8  
   { 870, 512, 967},  //duty=17, dutyLt=8  
   { 866, 512, 948},  //duty=18, dutyLt=8  
   { 863, 512, 933},  //duty=19, dutyLt=8  
   { 858, 512, 908},  //duty=20, dutyLt=8  
   { 512, 512, 512},  //duty=21, dutyLt=8  
   { 512, 512, 512},  //duty=22, dutyLt=8  
   { 512, 512, 512},  //duty=23, dutyLt=8  
   { 512, 512, 512},  //duty=24, dutyLt=8  
   { 512, 512, 512},  //duty=25, dutyLt=8  
   { 586, 512,2080},  //duty=-1, dutyLt=9  
   { 601, 512,1905},  //duty=0, dutyLt=9  
   { 624, 512,1739},  //duty=1, dutyLt=9  
   { 644, 512,1618},  //duty=2, dutyLt=9  
   { 662, 512,1528},  //duty=3, dutyLt=9  
   { 680, 512,1456},  //duty=4, dutyLt=9  
   { 695, 512,1398},  //duty=5, dutyLt=9  
   { 709, 512,1350},  //duty=6, dutyLt=9  
   { 733, 512,1290},  //duty=7, dutyLt=9  
   { 755, 512,1232},  //duty=8, dutyLt=9  
   { 778, 512,1180},  //duty=9, dutyLt=9  
   { 793, 512,1145},  //duty=10, dutyLt=9  
   { 806, 512,1114},  //duty=11, dutyLt=9  
   { 819, 512,1091},  //duty=12, dutyLt=9  
   { 829, 512,1069},  //duty=13, dutyLt=9  
   { 835, 512,1047},  //duty=14, dutyLt=9  
   { 840, 512,1024},  //duty=15, dutyLt=9  
   { 843, 512, 998},  //duty=16, dutyLt=9  
   { 841, 512, 977},  //duty=17, dutyLt=9  
   { 844, 512, 957},  //duty=18, dutyLt=9  
   { 842, 512, 941},  //duty=19, dutyLt=9  
   { 512, 512, 512},  //duty=20, dutyLt=9  
   { 512, 512, 512},  //duty=21, dutyLt=9  
   { 512, 512, 512},  //duty=22, dutyLt=9  
   { 512, 512, 512},  //duty=23, dutyLt=9  
   { 512, 512, 512},  //duty=24, dutyLt=9  
   { 512, 512, 512},  //duty=25, dutyLt=9  
   { 588, 512,2088},  //duty=-1, dutyLt=10  
   { 601, 512,1924},  //duty=0, dutyLt=10  
   { 619, 512,1772},  //duty=1, dutyLt=10  
   { 638, 512,1649},  //duty=2, dutyLt=10  
   { 655, 512,1560},  //duty=3, dutyLt=10  
   { 672, 512,1485},  //duty=4, dutyLt=10  
   { 692, 512,1423},  //duty=5, dutyLt=10  
   { 698, 512,1383},  //duty=6, dutyLt=10  
   { 717, 512,1320},  //duty=7, dutyLt=10  
   { 741, 512,1264},  //duty=8, dutyLt=10  
   { 763, 512,1207},  //duty=9, dutyLt=10  
   { 778, 512,1172},  //duty=10, dutyLt=10  
   { 792, 512,1142},  //duty=11, dutyLt=10  
   { 803, 512,1113},  //duty=12, dutyLt=10  
   { 813, 512,1083},  //duty=13, dutyLt=10  
   { 816, 512,1060},  //duty=14, dutyLt=10  
   { 823, 512,1035},  //duty=15, dutyLt=10  
   { 820, 512,1006},  //duty=16, dutyLt=10  
   { 814, 512, 982},  //duty=17, dutyLt=10  
   { 808, 512, 957},  //duty=18, dutyLt=10  
   { 512, 512, 512},  //duty=19, dutyLt=10  
   { 512, 512, 512},  //duty=20, dutyLt=10  
   { 512, 512, 512},  //duty=21, dutyLt=10  
   { 512, 512, 512},  //duty=22, dutyLt=10  
   { 512, 512, 512},  //duty=23, dutyLt=10  
   { 512, 512, 512},  //duty=24, dutyLt=10  
   { 512, 512, 512},  //duty=25, dutyLt=10  
   { 587, 512,2099},  //duty=-1, dutyLt=11  
   { 598, 512,1945},  //duty=0, dutyLt=11  
   { 616, 512,1793},  //duty=1, dutyLt=11  
   { 633, 512,1675},  //duty=2, dutyLt=11  
   { 648, 512,1590},  //duty=3, dutyLt=11  
   { 664, 512,1516},  //duty=4, dutyLt=11  
   { 677, 512,1457},  //duty=5, dutyLt=11  
   { 696, 512,1402},  //duty=6, dutyLt=11  
   { 710, 512,1351},  //duty=7, dutyLt=11  
   { 730, 512,1290},  //duty=8, dutyLt=11  
   { 751, 512,1231},  //duty=9, dutyLt=11  
   { 768, 512,1188},  //duty=10, dutyLt=11  
   { 779, 512,1161},  //duty=11, dutyLt=11  
   { 790, 512,1130},  //duty=12, dutyLt=11  
   { 797, 512,1098},  //duty=13, dutyLt=11  
   { 801, 512,1069},  //duty=14, dutyLt=11  
   { 799, 512,1044},  //duty=15, dutyLt=11  
   { 806, 512,1012},  //duty=16, dutyLt=11  
   { 793, 512, 983},  //duty=17, dutyLt=11  
   { 512, 512, 512},  //duty=18, dutyLt=11  
   { 512, 512, 512},  //duty=19, dutyLt=11  
   { 512, 512, 512},  //duty=20, dutyLt=11  
   { 512, 512, 512},  //duty=21, dutyLt=11  
   { 512, 512, 512},  //duty=22, dutyLt=11  
   { 512, 512, 512},  //duty=23, dutyLt=11  
   { 512, 512, 512},  //duty=24, dutyLt=11  
   { 512, 512, 512},  //duty=25, dutyLt=11  
   { 587, 512,2104},  //duty=-1, dutyLt=12  
   { 595, 512,1965},  //duty=0, dutyLt=12  
   { 612, 512,1812},  //duty=1, dutyLt=12  
   { 629, 512,1697},  //duty=2, dutyLt=12  
   { 643, 512,1612},  //duty=3, dutyLt=12  
   { 658, 512,1540},  //duty=4, dutyLt=12  
   { 669, 512,1487},  //duty=5, dutyLt=12  
   { 681, 512,1435},  //duty=6, dutyLt=12  
   { 698, 512,1374},  //duty=7, dutyLt=12  
   { 723, 512,1307},  //duty=8, dutyLt=12  
   { 742, 512,1252},  //duty=9, dutyLt=12  
   { 757, 512,1210},  //duty=10, dutyLt=12  
   { 768, 512,1176},  //duty=11, dutyLt=12  
   { 776, 512,1146},  //duty=12, dutyLt=12  
   { 782, 512,1107},  //duty=13, dutyLt=12  
   { 786, 512,1077},  //duty=14, dutyLt=12  
   { 790, 512,1049},  //duty=15, dutyLt=12  
   { 791, 512,1016},  //duty=16, dutyLt=12  
   { 512, 512, 512},  //duty=17, dutyLt=12  
   { 512, 512, 512},  //duty=18, dutyLt=12  
   { 512, 512, 512},  //duty=19, dutyLt=12  
   { 512, 512, 512},  //duty=20, dutyLt=12  
   { 512, 512, 512},  //duty=21, dutyLt=12  
   { 512, 512, 512},  //duty=22, dutyLt=12  
   { 512, 512, 512},  //duty=23, dutyLt=12  
   { 512, 512, 512},  //duty=24, dutyLt=12  
   { 512, 512, 512},  //duty=25, dutyLt=12  
   { 587, 512,2109},  //duty=-1, dutyLt=13  
   { 596, 512,1968},  //duty=0, dutyLt=13  
   { 610, 512,1830},  //duty=1, dutyLt=13  
   { 626, 512,1718},  //duty=2, dutyLt=13  
   { 638, 512,1635},  //duty=3, dutyLt=13  
   { 650, 512,1570},  //duty=4, dutyLt=13  
   { 664, 512,1506},  //duty=5, dutyLt=13  
   { 673, 512,1462},  //duty=6, dutyLt=13  
   { 698, 512,1389},  //duty=7, dutyLt=13  
   { 713, 512,1332},  //duty=8, dutyLt=13  
   { 733, 512,1273},  //duty=9, dutyLt=13  
   { 738, 512,1238},  //duty=10, dutyLt=13  
   { 756, 512,1192},  //duty=11, dutyLt=13  
   { 756, 512,1161},  //duty=12, dutyLt=13  
   { 767, 512,1115},  //duty=13, dutyLt=13  
   { 762, 512,1082},  //duty=14, dutyLt=13  
   { 765, 512,1052},  //duty=15, dutyLt=13  
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
   { 587, 512,2110},  //duty=-1, dutyLt=14  
   { 594, 512,1978},  //duty=0, dutyLt=14  
   { 608, 512,1843},  //duty=1, dutyLt=14  
   { 624, 512,1732},  //duty=2, dutyLt=14  
   { 635, 512,1651},  //duty=3, dutyLt=14  
   { 647, 512,1586},  //duty=4, dutyLt=14  
   { 660, 512,1525},  //duty=5, dutyLt=14  
   { 668, 512,1484},  //duty=6, dutyLt=14  
   { 684, 512,1418},  //duty=7, dutyLt=14  
   { 706, 512,1353},  //duty=8, dutyLt=14  
   { 726, 512,1287},  //duty=9, dutyLt=14  
   { 734, 512,1248},  //duty=10, dutyLt=14  
   { 742, 512,1206},  //duty=11, dutyLt=14  
   { 746, 512,1168},  //duty=12, dutyLt=14  
   { 753, 512,1122},  //duty=13, dutyLt=14  
   { 749, 512,1087},  //duty=14, dutyLt=14  
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
   { 588, 512,2103},  //duty=-1, dutyLt=15  
   { 595, 512,1979},  //duty=0, dutyLt=15  
   { 609, 512,1845},  //duty=1, dutyLt=15  
   { 623, 512,1739},  //duty=2, dutyLt=15  
   { 632, 512,1666},  //duty=3, dutyLt=15  
   { 644, 512,1600},  //duty=4, dutyLt=15  
   { 654, 512,1547},  //duty=5, dutyLt=15  
   { 667, 512,1491},  //duty=6, dutyLt=15  
   { 678, 512,1438},  //duty=7, dutyLt=15  
   { 701, 512,1358},  //duty=8, dutyLt=15  
   { 718, 512,1294},  //duty=9, dutyLt=15  
   { 726, 512,1258},  //duty=10, dutyLt=15  
   { 736, 512,1211},  //duty=11, dutyLt=15  
   { 736, 512,1171},  //duty=12, dutyLt=15  
   { 746, 512,1122},  //duty=13, dutyLt=15  
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
   { 588, 512,2101},  //duty=-1, dutyLt=16  
   { 595, 512,1980},  //duty=0, dutyLt=16  
   { 607, 512,1856},  //duty=1, dutyLt=16  
   { 622, 512,1750},  //duty=2, dutyLt=16  
   { 630, 512,1683},  //duty=3, dutyLt=16  
   { 645, 512,1605},  //duty=4, dutyLt=16  
   { 652, 512,1558},  //duty=5, dutyLt=16  
   { 663, 512,1508},  //duty=6, dutyLt=16  
   { 674, 512,1452},  //duty=7, dutyLt=16  
   { 695, 512,1383},  //duty=8, dutyLt=16  
   { 713, 512,1311},  //duty=9, dutyLt=16  
   { 719, 512,1269},  //duty=10, dutyLt=16  
   { 723, 512,1219},  //duty=11, dutyLt=16  
   { 724, 512,1174},  //duty=12, dutyLt=16  
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
   { 589, 512,2091},  //duty=-1, dutyLt=17  
   { 597, 512,1974},  //duty=0, dutyLt=17  
   { 609, 512,1854},  //duty=1, dutyLt=17  
   { 619, 512,1764},  //duty=2, dutyLt=17  
   { 629, 512,1690},  //duty=3, dutyLt=17  
   { 640, 512,1623},  //duty=4, dutyLt=17  
   { 648, 512,1573},  //duty=5, dutyLt=17  
   { 658, 512,1525},  //duty=6, dutyLt=17  
   { 674, 512,1458},  //duty=7, dutyLt=17  
   { 688, 512,1399},  //duty=8, dutyLt=17  
   { 698, 512,1326},  //duty=9, dutyLt=17  
   { 714, 512,1268},  //duty=10, dutyLt=17  
   { 716, 512,1221},  //duty=11, dutyLt=17  
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
   { 589, 512,2087},  //duty=-1, dutyLt=18  
   { 594, 512,1982},  //duty=0, dutyLt=18  
   { 606, 512,1864},  //duty=1, dutyLt=18  
   { 616, 512,1776},  //duty=2, dutyLt=18  
   { 626, 512,1704},  //duty=3, dutyLt=18  
   { 641, 512,1628},  //duty=4, dutyLt=18  
   { 647, 512,1582},  //duty=5, dutyLt=18  
   { 658, 512,1530},  //duty=6, dutyLt=18  
   { 667, 512,1477},  //duty=7, dutyLt=18  
   { 682, 512,1405},  //duty=8, dutyLt=18  
   { 702, 512,1325},  //duty=9, dutyLt=18  
   { 703, 512,1273},  //duty=10, dutyLt=18  
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
   { 591, 512,2079},  //duty=-1, dutyLt=19  
   { 595, 512,1977},  //duty=0, dutyLt=19  
   { 604, 512,1870},  //duty=1, dutyLt=19  
   { 615, 512,1781},  //duty=2, dutyLt=19  
   { 630, 512,1696},  //duty=3, dutyLt=19  
   { 637, 512,1641},  //duty=4, dutyLt=19  
   { 646, 512,1588},  //duty=5, dutyLt=19  
   { 658, 512,1533},  //duty=6, dutyLt=19  
   { 670, 512,1473},  //duty=7, dutyLt=19  
   { 683, 512,1405},  //duty=8, dutyLt=19  
   { 694, 512,1331},  //duty=9, dutyLt=19  
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
   { 590, 512,2072},  //duty=-1, dutyLt=20  
   { 596, 512,1972},  //duty=0, dutyLt=20  
   { 610, 512,1859},  //duty=1, dutyLt=20  
   { 618, 512,1777},  //duty=2, dutyLt=20  
   { 626, 512,1714},  //duty=3, dutyLt=20  
   { 635, 512,1651},  //duty=4, dutyLt=20  
   { 646, 512,1593},  //duty=5, dutyLt=20  
   { 651, 512,1554},  //duty=6, dutyLt=20  
   { 666, 512,1485},  //duty=7, dutyLt=20  
   { 676, 512,1415},  //duty=8, dutyLt=20  
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
   { 590, 512,2066},  //duty=-1, dutyLt=21  
   { 598, 512,1967},  //duty=0, dutyLt=21  
   { 607, 512,1868},  //duty=1, dutyLt=21  
   { 614, 512,1792},  //duty=2, dutyLt=21  
   { 631, 512,1700},  //duty=3, dutyLt=21  
   { 635, 512,1658},  //duty=4, dutyLt=21  
   { 644, 512,1603},  //duty=5, dutyLt=21  
   { 647, 512,1565},  //duty=6, dutyLt=21  
   { 664, 512,1490},  //duty=7, dutyLt=21  
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
   { 588, 512,2064},  //duty=-1, dutyLt=22  
   { 596, 512,1968},  //duty=0, dutyLt=22  
   { 608, 512,1867},  //duty=1, dutyLt=22  
   { 619, 512,1781},  //duty=2, dutyLt=22  
   { 624, 512,1725},  //duty=3, dutyLt=22  
   { 639, 512,1647},  //duty=4, dutyLt=22  
   { 640, 512,1615},  //duty=5, dutyLt=22  
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
   { 589, 512,2053},  //duty=-1, dutyLt=23  
   { 599, 512,1961},  //duty=0, dutyLt=23  
   { 608, 512,1866},  //duty=1, dutyLt=23  
   { 616, 512,1793},  //duty=2, dutyLt=23  
   { 625, 512,1725},  //duty=3, dutyLt=23  
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
   { 591, 512,2045},  //duty=-1, dutyLt=24  
   { 598, 512,1961},  //duty=0, dutyLt=24  
   { 609, 512,1866},  //duty=1, dutyLt=24  
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
   { 589, 512,2044},  //duty=-1, dutyLt=25  
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

