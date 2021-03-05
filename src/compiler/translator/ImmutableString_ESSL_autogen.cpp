// GENERATED FILE - DO NOT EDIT.
// Generated by gen_builtin_symbols.py using data from builtin_variables.json and
// builtin_function_declarations.txt.
//
// Copyright 2020 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//
// ImmutableString_ESSL_autogen.cpp: Wrapper for static or pool allocated char arrays, that are
// guaranteed to be valid and unchanged for the duration of the compilation. Implements
// mangledNameHash using perfect hash function from gen_builtin_symbols.py

#include "compiler/translator/ImmutableString.h"

std::ostream &operator<<(std::ostream &os, const sh::ImmutableString &str)
{
    return os.write(str.data(), str.length());
}

#if defined(_MSC_VER)
#    pragma warning(disable : 4309)  // truncation of constant value
#endif

namespace
{

constexpr int mangledkT1[] = {1865, 3158, 2853, 1682, 964,  2924, 357,  2994, 1417, 2512,
                              1311, 1311, 2139, 1976, 1760, 582,  284,  1231, 2967, 2550,
                              557,  2450, 1390, 2263, 1589, 1298, 3121, 2215, 2366, 708,
                              1827, 1707, 2405, 2487, 3075, 2597, 90,   1010, 2784, 2606};
constexpr int mangledkT2[] = {1020, 2468, 786,  2255, 1879, 342,  431,  224,  687,  2281,
                              2252, 3080, 1892, 2914, 2719, 1134, 2940, 1802, 617,  2244,
                              2471, 2754, 1169, 2072, 1955, 1834, 3185, 3182, 1842, 443,
                              1668, 2555, 569,  804,  2640, 839,  583,  2781, 2276, 3104};
constexpr int mangledkG[]  = {
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    1850, 0,    0,    0,    1329, 2858,
    0,    0,    0,    1862, 0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    823,  0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    2177, 0,    0,    2651,
    0,    0,    422,  0,    0,    0,    0,    560,  0,    0,    0,    0,    0,    0,    0,    0,
    1600, 0,    3068, 799,  0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    1882, 746,  0,    0,    0,    2264, 0,    2364, 0,    0,    0,    0,    0,    2816,
    2133, 0,    0,    0,    564,  0,    0,    0,    0,    0,    0,    0,    0,    0,    2861, 1758,
    0,    549,  700,  0,    0,    0,    0,    621,  0,    0,    953,  0,    0,    236,  0,    0,
    1605, 0,    0,    0,    3018, 0,    0,    0,    0,    177,  0,    907,  2690, 0,    431,  1482,
    1284, 0,    0,    709,  0,    0,    0,    223,  0,    0,    905,  0,    0,    0,    0,    0,
    670,  0,    0,    2949, 0,    3163, 0,    1372, 3123, 0,    0,    0,    0,    0,    724,  0,
    0,    0,    0,    1173, 0,    1126, 617,  1050, 2666, 0,    0,    3191, 359,  0,    0,    0,
    2813, 0,    0,    0,    242,  0,    0,    0,    43,   0,    0,    0,    0,    0,    0,    0,
    0,    757,  333,  0,    0,    0,    0,    0,    0,    0,    0,    2220, 0,    1472, 0,    0,
    587,  0,    0,    0,    0,    0,    0,    0,    0,    1430, 0,    0,    0,    0,    0,    2181,
    0,    0,    354,  0,    0,    0,    0,    0,    0,    0,    2087, 0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    2999, 0,    0,    0,    0,    0,    0,    357,  791,  0,    0,
    1551, 0,    771,  0,    0,    0,    0,    0,    0,    939,  0,    0,    1168, 713,  727,  0,
    2891, 0,    1179, 0,    0,    488,  0,    0,    0,    0,    2055, 2141, 0,    427,  0,    0,
    0,    0,    2322, 0,    494,  110,  0,    0,    0,    3014, 0,    0,    0,    0,    0,    0,
    1180, 0,    0,    0,    274,  205,  0,    0,    2602, 2475, 2363, 0,    321,  0,    0,    0,
    326,  0,    0,    1524, 1388, 147,  1398, 0,    0,    1440, 0,    0,    0,    0,    846,  1008,
    0,    2242, 0,    0,    0,    193,  762,  0,    1474, 910,  0,    0,    0,    882,  316,  0,
    651,  2287, 625,  2816, 414,  513,  0,    0,    0,    360,  0,    0,    0,    2544, 0,    0,
    0,    0,    0,    0,    0,    334,  1159, 2744, 0,    697,  0,    0,    3093, 3075, 0,    2294,
    309,  3124, 0,    0,    1766, 2773, 0,    0,    0,    0,    0,    2615, 0,    0,    0,    0,
    0,    412,  3090, 0,    1460, 0,    0,    0,    0,    0,    0,    0,    0,    203,  0,    0,
    1978, 954,  2940, 1415, 0,    2782, 0,    0,    3142, 454,  0,    0,    433,  0,    0,    0,
    0,    0,    0,    0,    0,    0,    2246, 2200, 0,    0,    1978, 0,    0,    0,    0,    0,
    402,  1098, 690,  0,    0,    0,    0,    0,    0,    0,    1593, 2920, 1333, 129,  0,    0,
    3171, 525,  0,    934,  0,    2163, 175,  2369, 0,    0,    0,    0,    0,    0,    1919, 0,
    0,    0,    0,    149,  304,  0,    0,    538,  96,   0,    1428, 2439, 2615, 252,  584,  0,
    1274, 0,    0,    0,    0,    919,  0,    0,    0,    0,    0,    0,    0,    584,  0,    0,
    1369, 2771, 2902, 0,    0,    352,  0,    0,    0,    0,    0,    424,  0,    0,    818,  0,
    351,  0,    0,    0,    0,    0,    0,    0,    1861, 0,    0,    0,    0,    2037, 884,  0,
    940,  1403, 899,  1550, 0,    0,    3130, 0,    0,    728,  0,    0,    121,  672,  820,  0,
    1932, 3074, 0,    0,    0,    0,    2168, 923,  0,    0,    690,  0,    0,    1109, 838,  91,
    1813, 0,    805,  3028, 0,    194,  1589, 0,    0,    1774, 0,    0,    0,    0,    131,  0,
    0,    0,    0,    0,    612,  0,    0,    0,    1494, 0,    0,    555,  2769, 0,    2365, 3155,
    0,    0,    2909, 0,    0,    0,    0,    2813, 0,    640,  0,    2879, 0,    0,    0,    466,
    213,  0,    1802, 0,    2281, 20,   0,    0,    1105, 2588, 985,  3119, 0,    0,    0,    0,
    0,    1140, 404,  435,  602,  0,    2753, 848,  0,    0,    1986, 0,    3004, 0,    643,  0,
    0,    1300, 0,    0,    0,    0,    0,    2533, 1445, 480,  1335, 362,  0,    1233, 529,  0,
    0,    0,    184,  0,    0,    828,  0,    13,   2768, 0,    0,    0,    254,  334,  2904, 0,
    0,    0,    0,    0,    0,    0,    1205, 0,    0,    1363, 0,    1992, 3083, 0,    2480, 0,
    0,    3169, 0,    0,    2452, 0,    311,  0,    0,    0,    0,    0,    0,    0,    800,  2823,
    0,    717,  1950, 0,    0,    0,    2713, 1659, 1022, 0,    0,    892,  0,    347,  0,    2889,
    85,   536,  0,    2011, 0,    1234, 0,    0,    0,    246,  0,    128,  0,    0,    586,  828,
    1942, 33,   0,    407,  2011, 1026, 0,    0,    608,  2261, 0,    0,    0,    0,    621,  2127,
    0,    0,    1030, 0,    631,  761,  1032, 1965, 2006, 1457, 0,    0,    0,    0,    0,    1213,
    0,    311,  3073, 1105, 0,    390,  0,    0,    1938, 1763, 2095, 0,    0,    1065, 0,    1818,
    0,    0,    0,    1434, 0,    188,  0,    0,    0,    1617, 0,    0,    0,    998,  0,    717,
    695,  0,    426,  0,    21,   1485, 1309, 0,    2592, 2962, 908,  0,    784,  0,    1073, 1205,
    0,    0,    0,    207,  503,  230,  1422, 0,    0,    0,    1355, 0,    0,    1437, 2853, 0,
    0,    0,    0,    36,   2489, 0,    2874, 1042, 416,  651,  0,    0,    2161, 2759, 610,  0,
    0,    0,    0,    0,    0,    0,    0,    0,    1356, 0,    0,    1512, 1333, 0,    0,    649,
    0,    0,    0,    0,    0,    500,  0,    0,    3044, 1747, 0,    0,    2457, 0,    0,    0,
    643,  519,  0,    0,    0,    0,    0,    0,    275,  0,    0,    870,  1531, 0,    1453, 1055,
    0,    0,    0,    0,    3062, 0,    3074, 0,    953,  0,    0,    0,    1156, 0,    840,  550,
    0,    1060, 2907, 2024, 0,    606,  0,    0,    2819, 2156, 309,  1841, 774,  0,    315,  3193,
    0,    0,    0,    0,    411,  0,    0,    0,    0,    783,  3089, 995,  2675, 1405, 0,    0,
    0,    2172, 459,  3082, 1018, 0,    1082, 0,    0,    1040, 968,  0,    0,    1234, 39,   0,
    0,    0,    558,  769,  469,  0,    1385, 0,    1020, 1853, 0,    1206, 0,    387,  0,    0,
    0,    3031, 702,  412,  0,    1480, 671,  1605, 1280, 877,  183,  0,    0,    0,    0,    0,
    0,    249,  137,  0,    0,    0,    1033, 3024, 115,  0,    412,  0,    0,    835,  0,    0,
    0,    1409, 417,  710,  0,    2945, 0,    0,    0,    0,    0,    0,    2735, 0,    1179, 0,
    692,  1583, 1391, 2889, 0,    1161, 0,    958,  0,    3006, 0,    0,    0,    832,  0,    0,
    1869, 579,  0,    931,  1442, 1563, 675,  0,    642,  399,  0,    0,    0,    1474, 0,    0,
    521,  2053, 0,    1359, 0,    0,    0,    290,  0,    1347, 53,   0,    0,    1538, 3004, 0,
    1927, 1715, 0,    3133, 0,    0,    3040, 0,    0,    0,    0,    2997, 0,    1066, 0,    0,
    1580, 54,   0,    0,    541,  2649, 0,    0,    0,    2052, 0,    271,  0,    0,    0,    0,
    1245, 2525, 0,    1347, 2719, 1301, 1731, 0,    0,    0,    3163, 0,    0,    1234, 1171, 1507,
    0,    0,    1342, 873,  107,  0,    425,  1132, 0,    0,    0,    653,  0,    914,  0,    0,
    0,    0,    0,    1426, 593,  1099, 963,  1141, 0,    0,    0,    1475, 2824, 0,    0,    0,
    0,    0,    0,    0,    0,    723,  0,    2213, 2918, 0,    353,  2702, 2303, 647,  1467, 1092,
    793,  227,  0,    1128, 0,    0,    2314, 0,    0,    977,  848,  383,  0,    2071, 1518, 0,
    3001, 928,  0,    0,    0,    110,  0,    0,    0,    931,  0,    1975, 0,    972,  131,  534,
    1739, 0,    370,  0,    0,    0,    1800, 27,   0,    844,  129,  0,    0,    0,    2981, 155,
    0,    0,    0,    0,    0,    800,  0,    0,    315,  0,    1891, 0,    0,    548,  2963, 0,
    0,    489,  0,    0,    0,    269,  3117, 0,    886,  889,  0,    1021, 439,  574,  1241, 2946,
    1317, 0,    895,  698,  0,    0,    0,    1213, 593,  1624, 761,  1405, 0,    0,    0,    0,
    744,  0,    0,    2848, 0,    2670, 0,    54,   0,    1125, 0,    0,    0,    0,    457,  0,
    0,    0,    504,  0,    928,  540,  1491, 0,    0,    0,    1145, 0,    0,    0,    92,   2864,
    1036, 0,    148,  0,    1449, 2899, 2437, 0,    344,  540,  0,    19,   2306, 1062, 2138, 0,
    1255, 1066, 0,    0,    1900, 729,  0,    334,  667,  0,    92,   0,    981,  182,  747,  0,
    398,  53,   761,  849,  0,    1401, 0,    0,    280,  2398, 0,    0,    0,    0,    1451, 2570,
    0,    841,  0,    0,    0,    1463, 1127, 2842, 0,    1304, 573,  1741, 1532, 0,    65,   0,
    2492, 0,    0,    0,    1755, 756,  1400, 2830, 1363, 1412, 0,    0,    0,    0,    0,    3160,
    94,   0,    1274, 0,    100,  598,  0,    0,    0,    155,  674,  0,    0,    0,    154,  780,
    929,  0,    1597, 2997, 0,    2106, 165,  0,    0,    1495, 444,  0,    1139, 1404, 2574, 1648,
    0,    0,    0,    2660, 1557, 1462, 0,    0,    0,    0,    0,    0,    0,    0,    1565, 0,
    955,  427,  1525, 2986, 1728, 0,    0,    559,  377,  0,    1529, 0,    0,    872,  954,  0,
    0,    0,    49,   20,   0,    1430, 531,  0,    0,    0,    2355, 0,    524,  0,    3079, 31,
    0,    2709, 0,    1307, 0,    2781, 0,    2797, 0,    986,  442,  112,  2436, 2868, 826,  0,
    1277, 0,    3022, 0,    2130, 0,    0,    0,    446,  0,    2153, 1656, 0,    0,    1234, 0,
    0,    95,   885,  0,    2608, 0,    0,    1948, 2947, 1170, 15,   0,    0,    332,  0,    6,
    0,    0,    0,    1365, 0,    3000, 0,    0,    80,   0,    893,  0,    731,  1585, 1162, 1436,
    0,    936,  1564, 1362, 1007, 1278, 2177, 219,  0,    1949, 2732, 0,    0,    3175, 1096, 316,
    0,    0,    0,    1214, 853,  0,    0,    216,  2692, 0,    524,  135,  0,    0,    594,  0,
    0,    0,    822,  2791, 0,    1323, 0,    0,    1089, 2420, 534,  0,    0,    967,  968,  0,
    654,  0,    1050, 0,    1260, 0,    0,    0,    677,  0,    419,  1028, 502,  0,    0,    909,
    299,  79,   0,    0,    2494, 0,    0,    1485, 0,    3119, 1164, 3107, 976,  2359, 0,    0,
    1183, 2778, 0,    2048, 455,  2015, 0,    0,    887,  811,  0,    1544, 390,  0,    0,    0,
    0,    810,  485,  460,  0,    720,  2589, 600,  0,    0,    2576, 0,    3130, 0,    1144, 1111,
    0,    1500, 1349, 836,  254,  0,    509,  1711, 0,    2970, 0,    2799, 866,  0,    0,    1393,
    0,    2682, 0,    2401, 0,    0,    705,  0,    0,    0,    1042, 1419, 0,    0,    1045, 0,
    2933, 0,    0,    117,  0,    1472, 2464, 1268, 0,    46,   0,    0,    0,    0,    450,  0,
    0,    560,  0,    0,    0,    693,  406,  709,  744,  0,    0,    60,   1420, 1083, 857,  0,
    168,  1248, 1241, 799,  0,    0,    2154, 37,   0,    0,    603,  0,    1100, 0,    0,    0,
    831,  367,  1489, 0,    0,    2248, 2984, 0,    0,    0,    0,    265,  123,  0,    2369, 0,
    0,    2201, 0,    1094, 3200, 201,  841,  1898, 0,    0,    0,    0,    3018, 632,  0,    868,
    2832, 0,    2591, 0,    0,    1197, 0,    0,    1028, 0,    0,    0,    770,  30,   2527, 799,
    80,   255,  0,    0,    1315, 0,    0,    0,    1008, 0,    0,    0,    0,    0,    0,    0,
    0,    544,  0,    1593, 311,  1114, 150,  2863, 3079, 407,  0,    0,    0,    2960, 1838, 425,
    0,    970,  1860, 653,  0,    163,  0,    0,    2968, 0,    0,    1515, 1019, 224,  0,    0,
    0,    707,  0,    0,    878,  0,    12,   1150, 0,    0,    664,  2961, 483,  0,    850,  1505,
    643,  2948, 657,  0,    0,    447,  0,    0,    2159, 754,  324,  0,    0,    3206, 167,  1189,
    3045, 1233, 642,  0,    1608, 0,    898,  0,    2375, 145,  1446, 0,    2687, 0,    0,    1600,
    2197, 824,  0,    211,  0,    582,  1164, 1695, 818,  2658, 249,  922,  0,    0,    199,  266,
    931,  289,  545,  0,    0,    0,    572,  0,    1600, 2231, 164,  2762, 0,    639,  703,  383,
    0,    775,  2262, 0,    1109, 3159, 0,    0,    0,    0,    554,  0,    0,    0,    0,    0,
    321,  294,  0,    192,  0,    321,  3108, 291,  765,  0,    725,  2588, 0,    3028, 2490, 0,
    1556, 0,    2366, 0,    0,    409,  221,  3156, 1225, 1408, 2705, 535,  2628, 705,  833,  0,
    1493, 1030, 0,    0,    0,    3056, 1803, 479,  164,  1224, 0,    1488, 0,    2977, 797,  1223,
    1198, 2277, 920,  506,  1383, 558,  946,  0,    2423, 0,    562,  1979, 1709, 592,  127,  754,
    1363, 595,  122,  173,  0,    0,    2701, 1418, 1536, 517,  0,    2204, 0,    0,    325,  0,
    0,    1777, 0,    0,    0,    1360, 0,    0,    642,  131,  1337, 0,    1171, 908,  0,    0,
    1999, 0,    1202, 0,    0,    2558, 496,  377,  610,  139,  896,  0,    298,  0,    1185, 0,
    0,    668,  297,  1773, 0,    0,    0,    0,    3197, 0,    803,  3157, 0,    0,    901,  3035,
    3147, 1211, 0,    0,    1486, 0,    0,    1113, 0,    267,  0,    0,    0,    1921, 0,    0,
    1293, 0,    121,  1346, 2100, 0,    0,    0,    0,    3086, 3002, 1318, 0,    545,  0,    0,
    0,    104,  3048, 2323, 186,  0,    0,    0,    2822, 0,    619,  0,    0,    418,  0,    391,
    964,  2059, 796,  0,    0,    903,  1274, 2016, 1174, 65,   0,    718,  0,    568,  1080, 0,
    2813, 0,    0,    0,    2482, 0,    237,  0,    2786, 3029, 0,    2206, 1258, 1211, 1153, 0,
    94,   0,    0,    0,    2373, 2980, 0,    0,    1146, 0,    2907, 0,    0,    1527, 0,    250,
    0,    0,    0,    1058, 0,    2818, 0,    826,  0,    0,    1507, 369,  807,  0,    0,    0,
    989,  276,  2059, 1084, 288,  345,  1483, 244,  1138, 2383, 1837, 2474, 0,    0,    0,    548,
    0,    0,    295,  1406, 2462, 2250, 1260, 268,  1387, 0,    192,  2254, 0,    0,    1371, 0,
    91,   1428, 1077, 710,  0,    575,  0,    0,    1039, 806,  428,  1450, 1054, 838,  1118, 475,
    0,    0,    0,    1298, 1029, 528,  0,    0,    479,  2412, 1195, 630,  2349, 280,  0,    2878,
    2840, 943,  2001, 2729, 624,  999,  117,  901,  483,  2563, 0,    805,  152,  1489, 1230, 0,
    0,    994,  826,  0,    1129, 1034, 0,    1502, 2314, 0,    397,  1894, 515,  0,    1080, 888,
    752,  0,    2409, 0,    0,    0,    0,    439,  1102, 516,  2678, 1869, 0,    327,  890,  161,
    0,    0,    0,    1524, 702,  1548, 944,  2834, 73,   0,    0,    2010, 0,    150,  0,    0,
    519,  868,  0,    1348, 739,  895,  2340, 929,  387,  0,    398,  396,  0,    0,    1683, 201,
    0,    0,    0,    1283, 279,  837,  0,    1111, 1407, 0,    0,    0,    1198, 859,  2059, 700,
    0,    0,    1744, 2010, 2351, 128,  438,  1010, 894,  0,    0,    1252, 2415, 1212, 1066, 0,
    586,  797,  910,  2784, 3011, 2435, 58,   1053, 2021, 54,   0,    274,  0,    176,  0,    253,
    0,    0,    0,    560,  1530, 0,    0,    3106, 1330, 1405, 1114, 2217, 0,    1008, 3133, 802,
    2858, 0,    1541, 1434, 947,  0,    0,    547,  630,  0,    0,    2943, 0,    0,    0,    569,
    236,  864,  0,    0,    0,    0,    309,  1308, 2879, 0,    0,    0,    620,  0,    1093, 0,
    125,  683,  0,    1026, 2743, 0,    781,  94,   1493, 1089, 1469, 0,    1622, 1940, 0,    447,
    128,  641,  0,    746,  0,    0,    1356, 335,  336,  0,    0,    0,    0,    499,  308,  1114,
    0,    0,    757,  0,    0,    1358, 3198, 2122, 123,  915,  2951, 1088, 0,    0,    474,  1311,
    229,  0,    1244, 740,  3016, 2603, 1362, 952,  1856, 0,    0,    597,  0,    0,    0,    0,
    514,  2622, 0,    715,  916,  0,    0,    0,    1452, 17,   2435, 0,    687,  2183, 1335, 0,
    661,  682,  228,  0,    0,    0,    941,  0,    0,    1455, 2370, 2193, 483,  1432, 1058, 1954,
    940,  672,  0,    0,    772,  0,    90,   0,    234,  0,    1229, 0,    731,  1136, 0,    512,
    480,  0,    317,  0,    0,    12,   0,    1432, 0,    1157, 291,  1002, 58,   0,    0,    3088,
    0,    293,  364,  0,    765,  0,    2422, 0,    0,    343,  487,  0,    0,    2178, 0,    0,
    120,  1417, 690,  725,  2661, 851,  0,    1090, 461,  1897, 0,    2918, 2692, 0,    0,    0,
    2782, 0,    0,    84,   1579, 3081, 0,    0,    0,    2505, 0,    0,    395,  478,  0,    0,
    3136, 0,    0,    993,  1304, 1099, 0,    0,    408,  0,    1496, 0,    1325, 1091, 285,  626,
    1459, 0,    1180, 1456, 550,  456,  0,    0,    1182, 0,    0,    0,    321,  1423, 1381, 82,
    126,  1462, 0,    0,    0,    0,    0,    1253, 269,  2819, 0,    971,  852,  231,  3088, 3169,
    1310, 1275, 0,    2446, 2797, 9,    0,    0,    1074, 785,  3207, 386,  0,    1310, 0,    473,
    0,    1963, 0,    0,    1060, 283,  0,    0,    521,  814,  2817, 2769, 409,  0,    742,  506,
    0,    0,    3074, 0,    2333, 719,  530,  0,    0,    1565, 0,    0,    459,  0,    367,  3135,
    1601, 1046, 2334, 3185, 142,  601,  260,  233,  0,    0,    439,  214,  714,  1102, 0,    582,
    0,    0,    1182, 125,  130,  777,  1161, 776,  0,    1665, 673,  2209, 3088, 2395, 902,  2312,
    0,    1433, 0,    198,  41,   116,  2806, 1231, 1122, 1545, 0,    2837, 632,  0,    1707, 0,
    0,    0,    2100, 0,    0,    763,  0,    0,    0,    491,  154,  1161, 2678, 1299, 2738, 0,
    2135, 0,    0,    0,    0,    0,    0,    0,    468,  33,   0,    0,    0,    0,    0,    0,
    894,  305,  490,  0,    978,  747,  374,  2062, 2364, 730,  0,    0,    0,    0,    151,  1520,
    1665, 0,    825,  0,    446,  1598, 2155, 505,  2116, 3111, 0,    0,    0,    0,    1177, 0,
    861,  2000, 840,  2769, 1374, 320,  997,  932,  1555, 1193, 13,   0,    325,  1991, 323,  0,
    0,    2974, 1281, 0,    0,    1239, 109,  770,  3180, 0,    535,  0,    0,    2743, 1699, 762,
    0,    0,    0,    1264, 0,    404,  1262, 1024, 306,  0,    197,  412,  2275, 1291, 0,    2523,
    45,   0,    1428, 0,    1540, 335,  257,  1841, 0,    828,  653,  1110, 289,  2528, 892,  0,
    0,    939,  1345, 190,  1891, 0,    0,    472,  0,    0,    0,    2161, 0,    0,    0,    1283,
    880,  627,  279,  601,  1163, 506,  81,   129,  20,   0,    600,  2876, 846,  779,  0,    236,
    224,  0,    0,    1411, 1708, 0,    498,  251,  2594, 2123, 262,  3052, 358,  0,    1276, 284,
    2924, 952,  707,  1416, 442,  0,    0,    0,    0,    0,    517,  0,    2839, 1035, 513,  2324,
    0,    3092, 1199, 1105, 1101, 1373, 215,  1348, 1090, 0,    2831, 886,  631,  0,    0,    0,
    1308, 2,    258,  579,  78,   0,    0,    2934, 0,    0,    1992, 0,    1075, 0,    0,    0,
    0,    3120, 1055, 2680, 0,    0,    0,    0,    1811, 0,    2396, 1196, 0,    1043, 0,    2836,
    373,  3173, 0,    2750, 269,  2658, 1526, 2918, 1559, 1426, 0,    2025, 990,  726,  0,    0,
    226,  0,    364,  0,    0,    3201, 363,  0,    0,    0,    0,    0,    149,  1038, 0,    0,
    295,  430,  507,  1232, 2367, 336,  911,  561,  0,    1027, 3046, 45,   0,    454,  1767, 0,
    903,  748,  887,  949,  0,    0,    0,    1015, 0,    1632, 984,  2941, 489,  173,  1549, 0,
    0,    602,  622,  2971, 2371, 549,  0,    2256, 509,  55,   45,   217,  1648, 0,    0,    405,
    2840, 324,  35,   0,    0,    0,    0,    2751, 185,  0,    2848, 0,    0,    0,    0,    2118,
    273,  1398, 0,    0,    697,  0,    1151, 199,  330,  1983, 294,  2845, 0,    262,  1584, 2080,
    0,    0,    0,    0,    1425, 0,    324,  1161, 0,    371,  327,  1214, 428,  1314, 2901, 805,
    0,    180,  331,  160,  101,  0,    0,    132,  2721, 176,  0,    881,  0,    0,    1986, 621,
    0,    144,  3011, 0,    34,   0,    979,  61,   1322, 0,    0,    0,    44,   1197, 192,  772,
    1490, 0,    2397, 0,    2559, 0,    675,  2070, 1072, 829,  0,    0,    0,    2587, 0,    2004,
    1149, 411,  2956, 1118, 1052, 646,  0,    0};

int MangledHashG(const char *key, const int *T)
{
    int sum = 0;

    for (int i = 0; key[i] != '\0'; i++)
    {
        sum += T[i] * key[i];
        sum %= 3208;
    }
    return mangledkG[sum];
}

int MangledPerfectHash(const char *key)
{
    if (strlen(key) > 40)
        return 0;

    return (MangledHashG(key, mangledkT1) + MangledHashG(key, mangledkT2)) % 3208;
}

constexpr int unmangledkT1[] = {249, 268, 237, 143, 100, 53,  77,  99,  153, 196, 268, 119, 234,
                                218, 139, 142, 2,   98,  160, 173, 114, 214, 22,  46,  268, 9};
constexpr int unmangledkT2[] = {44,  159, 153, 267, 220, 238, 250, 184, 272, 262, 61,  213, 258,
                                149, 267, 118, 156, 254, 128, 97,  89,  159, 113, 184, 215, 101};
constexpr int unmangledkG[]  = {
    0,   0,   0,   0,   0,   0,   0,   234, 0,   0,   0,   0,   230, 0,   0,   0,   0,   193, 273,
    0,   76,  202, 0,   0,   0,   0,   0,   161, 0,   0,   0,   78,  0,   0,   0,   0,   161, 193,
    0,   0,   231, 227, 0,   0,   0,   0,   0,   41,  0,   153, 42,  0,   86,  32,  0,   123, 90,
    0,   192, 0,   0,   94,  0,   93,  0,   0,   0,   0,   0,   0,   0,   63,  0,   156, 70,  184,
    64,  0,   189, 203, 274, 0,   184, 250, 0,   128, 0,   252, 180, 224, 0,   134, 116, 262, 0,
    75,  0,   0,   208, 155, 46,  0,   99,  100, 264, 38,  0,   193, 166, 31,  21,  129, 243, 140,
    206, 0,   18,  148, 214, 193, 114, 155, 0,   146, 0,   75,  128, 0,   244, 135, 0,   173, 105,
    0,   255, 0,   251, 86,  125, 73,  0,   132, 160, 159, 0,   225, 137, 109, 20,  96,  0,   0,
    102, 0,   0,   165, 0,   0,   47,  0,   0,   199, 101, 143, 108, 0,   144, 0,   0,   42,  0,
    118, 266, 0,   104, 222, 0,   0,   0,   131, 176, 138, 0,   0,   274, 95,  251, 182, 0,   129,
    0,   5,   105, 249, 0,   0,   69,  0,   0,   62,  152, 0,   0,   201, 167, 15,  0,   238, 0,
    0,   201, 100, 202, 0,   272, 275, 163, 87,  163, 142, 64,  63,  250, 0,   273, 107, 163, 157,
    198, 113, 8,   0,   0,   110, 233, 0,   0,   34,  104, 191, 262, 178, 123, 49,  13,  19,  91,
    41,  45,  278, 52,  154, 0,   0,   0,   0,   178, 27,  0,   110, 0,   31,  23,  196, 212, 0,
    0,   68,  0,   142, 267, 153, 79,  52,  179, 114, 94,  0,   0};

int UnmangledHashG(const char *key, const int *T)
{
    int sum = 0;

    for (int i = 0; key[i] != '\0'; i++)
    {
        sum += T[i] * key[i];
        sum %= 279;
    }
    return unmangledkG[sum];
}

int UnmangledPerfectHash(const char *key)
{
    if (strlen(key) > 26)
        return 0;

    return (UnmangledHashG(key, unmangledkT1) + UnmangledHashG(key, unmangledkT2)) % 279;
}

}  // namespace

namespace sh
{

template <>
const size_t ImmutableString::FowlerNollVoHash<4>::kFnvPrime = 16777619u;

template <>
const size_t ImmutableString::FowlerNollVoHash<4>::kFnvOffsetBasis = 0x811c9dc5u;

template <>
const size_t ImmutableString::FowlerNollVoHash<8>::kFnvPrime =
    static_cast<size_t>(1099511628211ull);

template <>
const size_t ImmutableString::FowlerNollVoHash<8>::kFnvOffsetBasis =
    static_cast<size_t>(0xcbf29ce484222325ull);

uint32_t ImmutableString::mangledNameHash() const
{
    return MangledPerfectHash(data());
}

uint32_t ImmutableString::unmangledNameHash() const
{
    return UnmangledPerfectHash(data());
}

}  // namespace sh
