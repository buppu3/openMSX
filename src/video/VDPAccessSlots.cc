#include "VDPAccessSlots.hh"

#include <array>
#include <utility>

namespace openmsx::VDPAccessSlots {

// These tables must contain at least one value that is bigger or equal
// to 1368+136. So we extend the data with some cyclic duplicates.

// Screen rendering disabled (or vertical border).
// This is correct (measured on real V9938) for bitmap and character mode.
// TODO also correct for text mode? See 'vdp-timing-2.html for more details.
static constexpr std::array<int16_t, 154 + 17> slotsScreenOff = {
	   0,    8,   16,   24,   32,   40,   48,   56,   64,   72,
	  80,   88,   96,  104,  112,  120,  164,  172,  180,  188,
	 196,  204,  212,  220,  228,  236,  244,  252,  260,  268,
	 276,  292,  300,  308,  316,  324,  332,  340,  348,  356,
	 364,  372,  380,  388,  396,  404,  420,  428,  436,  444,
	 452,  460,  468,  476,  484,  492,  500,  508,  516,  524,
	 532,  548,  556,  564,  572,  580,  588,  596,  604,  612,
	 620,  628,  636,  644,  652,  660,  676,  684,  692,  700,
	 708,  716,  724,  732,  740,  748,  756,  764,  772,  780,
	 788,  804,  812,  820,  828,  836,  844,  852,  860,  868,
	 876,  884,  892,  900,  908,  916,  932,  940,  948,  956,
	 964,  972,  980,  988,  996, 1004, 1012, 1020, 1028, 1036,
	1044, 1060, 1068, 1076, 1084, 1092, 1100, 1108, 1116, 1124,
	1132, 1140, 1148, 1156, 1164, 1172, 1188, 1196, 1204, 1212,
	1220, 1228, 1268, 1276, 1284, 1292, 1300, 1308, 1316, 1324,
	1334, 1344, 1352, 1360,
	1368+  0, 1368+  8, 1368+16, 1368+ 24, 1368+ 32,
	1368+ 40, 1368+ 48, 1368+56, 1368+ 64, 1368+ 72,
	1368+ 80, 1368+ 88, 1368+96, 1368+104, 1368+112,
	1368+120, 1368+164
};

// Bitmap mode, sprites disabled.
static constexpr std::array<int16_t, 88 + 16> slotsSpritesOff = {
	   6,   14,   22,   30,   38,   46,   54,   62,   70,   78,
	  86,   94,  102,  110,  118,  162,  170,  182,  188,  214,
	 220,  246,  252,  278,  310,  316,  342,  348,  374,  380,
	 406,  438,  444,  470,  476,  502,  508,  534,  566,  572,
	 598,  604,  630,  636,  662,  694,  700,  726,  732,  758,
	 764,  790,  822,  828,  854,  860,  886,  892,  918,  950,
	 956,  982,  988, 1014, 1020, 1046, 1078, 1084, 1110, 1116,
	1142, 1148, 1174, 1206, 1212, 1266, 1274, 1282, 1290, 1298,
	1306, 1314, 1322, 1332, 1342, 1350, 1358, 1366,
	1368+  6, 1368+14, 1368+ 22, 1368+ 30, 1368+ 38,
	1368+ 46, 1368+54, 1368+ 62, 1368+ 70, 1368+ 78,
	1368+ 86, 1368+94, 1368+102, 1368+110, 1368+118,
	1368+162,
};

// Bitmap mode, sprites enabled.
static constexpr std::array<int16_t, 31 + 3> slotsSpritesOn = {
	  28,   92,  162,  170,  188,  220,  252,  316,  348,  380,
	 444,  476,  508,  572,  604,  636,  700,  732,  764,  828,
	 860,  892,  956,  988, 1020, 1084, 1116, 1148, 1212, 1264,
	1330,
	1368+28, 1368+92, 1368+162,
};

// Character mode, sprites enabled.
static constexpr std::array<int16_t, 31 + 3> slotsChar = {
	  32,   96,  166,  174,  188,  220,  252,  316,  348,  380,
	 444,  476,  508,  572,  604,  636,  700,  732,  764,  828,
	 860,  892,  956,  988, 1020, 1084, 1116, 1148, 1212, 1268,
	1334,
	1368+32, 1368+96, 1368+166,
};

// Text mode.
static constexpr std::array<int16_t, 47 + 10> slotsText = {
	   2,   10,   18,   26,   34,   42,   50,   58,   66,  166,
	 174,  182,  190,  198,  206,  214,  222,  312,  408,  504,
	 600,  696,  792,  888,  984, 1080, 1176, 1206, 1214, 1222,
	1230, 1238, 1246, 1254, 1262, 1270, 1278, 1286, 1294, 1302,
	1310, 1318, 1326, 1336, 1346, 1354, 1362,
	1368+ 2, 1368+10, 1368+18, 1368+26, 1368+ 34,
	1368+42, 1368+50, 1368+58, 1368+66, 1368+166,
};


// TMS9918 (MSX1) cycle numbers translated to V99x8 cycles (multiplied by 4).
// MSX1 screen off.
static constexpr std::array<int16_t, 107 + 18> slotsMsx1ScreenOff = {
	   4,   12,   20,   28,   36,   44,   52,   60,   68,   76,
	  84,   92,  100,  108,  116,  124,  132,  140,  148,  156,
	 164,  172,  180,  188,  196,  204,  220,  236,  252,  268,
	 284,  300,  316,  332,  348,  364,  380,  396,  412,  428,
	 444,  460,  476,  492,  508,  524,  540,  556,  572,  588,
	 604,  620,  636,  652,  668,  684,  700,  716,  732,  748,
	 764,  780,  796,  812,  828,  844,  860,  876,  892,  908,
	 924,  940,  956,  972,  988, 1004, 1020, 1036, 1052, 1068,
	1084, 1100, 1116, 1132, 1148, 1164, 1180, 1196, 1212, 1228,
	1236, 1244, 1252, 1260, 1268, 1276, 1284, 1292, 1300, 1308,
	1316, 1324, 1332, 1340, 1348, 1356, 1364,
	1368+  4, 1368+ 12, 1368+ 20, 1368+ 28, 1368+ 36,
	1368+ 44, 1368+ 52, 1368+ 60, 1368+ 68, 1368+ 76,
	1368+ 84, 1368+ 92, 1368+100, 1368+108, 1368+116,
	1368+124, 1368+132, 1368+140,
};

// MSX1 graphic mode 1 and 2 (aka screen 1 and 2).
static constexpr std::array<int16_t, 19 + 8> slotsMsx1Gfx12 = {
	   4,   12,   20,   28,  116,  124,  132,  140,  220,  348,
	 476,  604,  732,  860,  988, 1116, 1236, 1244, 1364,
	1368+  4, 1368+ 12, 1368+ 20, 1368+ 28, 1368+116,
	1368+124, 1368+132, 1368+140,
};

// MSX1 graphic mode 3 (aka screen 3).
static constexpr std::array<int16_t, 51 + 8> slotsMsx1Gfx3 = {
	   4,   12,   20,   28,  116,  124,  132,  140,  220,  228,
	 260,  292,  324,  348,  356,  388,  420,  452,  476,  484,
	 516,  548,  580,  604,  612,  644,  676,  708,  732,  740,
	 772,  804,  836,  860,  868,  900,  932,  964,  988,  996,
	1028, 1060, 1092, 1116, 1124, 1156, 1188, 1220, 1236, 1244,
	1364,
	1368+  4, 1368+ 12, 1368+ 20, 1368+ 28, 1368+116,
	1368+124, 1368+132, 1368+140,
};


// MSX1 text mode 1 (aka screen 0 width 40).
static constexpr std::array<int16_t, 91 + 18> slotsMsx1Text = {
	   4,   12,   20,   28,   36,   44,   52,   60,   68,   76,
	  84,   92,  100,  108,  116,  124,  132,  140,  148,  156,
	 164,  172,  180,  188,  196,  204,  212,  220,  228,  244,
	 268,  292,  316,  340,  364,  388,  412,  436,  460,  484,
	 508,  532,  556,  580,  604,  628,  652,  676,  700,  724,
	 748,  772,  796,  820,  844,  868,  892,  916,  940,  964,
	 988, 1012, 1036, 1060, 1084, 1108, 1132, 1156, 1180, 1196,
	1204, 1212, 1220, 1228, 1236, 1244, 1252, 1260, 1268, 1276,
	1284, 1292, 1300, 1308, 1316, 1324, 1332, 1340, 1348, 1356,
	1364,
	1368+  4, 1368+ 12, 1368+ 20, 1368+ 28, 1368+ 36,
	1368+ 44, 1368+ 52, 1368+ 60, 1368+ 68, 1368+ 76,
	1368+ 84, 1368+ 92, 1368+100, 1368+108, 1368+116,
	1368+124, 1368+132, 1368+140,
};

// 0:bitmap			0:name		0:name
// 1:bitmap(g6~)	1:par		1:pat
// 2:sprite			2:sprite	2:pat(t2)
// 3:cmd			3:color		3:blink
// 4:cmd			4:cmd		4:cmd
// 5:cmd			5:cmd		5:cmd
// 6:cmd			6:cmd
// 7:cmd			7:cmd
static constexpr std::array<int16_t, 352> slotsV9968ScreenOff = {
//	bmp   bmp   spr   cmd   cmd   cmd   cmd   cmd
	   0,   16,   32,   48,   64,   80,   96,  112,	// -40
	       144,  160,  176,  192,  208,  224,  240,	// -32 128=REFRESH
	 256,  272,  288,  304,  320,  336,  352,  368,	// -24
	 384,  400,  416,  432,  448,  464,  480,  496,	// -16
	 512,  528,  544,  560,  576,  592,  608,  624,	// -8
	 640,  656,  672,  688,  704,  720,  736,  752,	// 0
	 768,  784,  800,  816,  832,  848,  864,  880,
	 896,  912,  928,  944,  960,  976,  992, 1008,
	1024, 1040, 1056, 1072, 1088, 1104, 1120, 1136,
	1152, 1168, 1184, 1200, 1216, 1232, 1248, 1264,
	1280, 1296, 1312, 1328, 1344, 1360, 1376, 1392,
	1408, 1424, 1440, 1456, 1472, 1488, 1504, 1520,
	1536, 1552, 1568, 1584, 1600, 1616, 1632, 1648,
	1664, 1680, 1696, 1712, 1728, 1744, 1760, 1776,
	1792, 1808, 1824, 1840, 1856, 1872, 1888, 1904,
	1920, 1936, 1952, 1968, 1984, 2000, 2016, 2032,
	2048, 2064, 2080, 2096, 2112, 2128, 2144, 2160,
	2176, 2192, 2208, 2224, 2240, 2256, 2272, 2288,
	2304, 2320, 2336, 2352, 2368, 2384, 2400, 2416,
	2432, 2448, 2464, 2480, 2496, 2512, 2528, 2544,
	2560, 2576, 2592, 2608, 2624, 2640, 2656, 2672,
	2688, 2704, 2720, 2736, 2752, 2768, 2784, 2800,
	2816, 2832, 2848, 2864, 2880, 2896, 2912, 2928,
	2944, 2960, 2976, 2992, 3008, 3024, 3040, 3056,
	3072, 3088, 3104, 3120, 3136, 3152, 3168, 3184,
	3200, 3216, 3232, 3248, 3264, 3280, 3296, 3312,
	3328, 3344, 3360, 3376, 3392, 3408, 3424, 3440,
	3456, 3472, 3488, 3504, 3520, 3536, 3552, 3568,
	3584, 3600, 3616, 3632, 3648, 3664, 3680, 3696,
	3712, 3728, 3744, 3760, 3776, 3792, 3808, 3824,
	3840, 3856, 3872, 3888, 3904, 3920, 3936, 3952,
	3968, 3984, 4000, 4016, 4032, 4048, 4064, 4080,
	4096, 4112, 4128, 4144, 4160, 4176, 4192, 4208,
	4224, 4240, 4256, 4272, 4288, 4304, 4320, 4336,
	4352, 4368, 4384, 4400, 4416, 4432, 4448, 4464,
	4480, 4496, 4512, 4528, 4544, 4560, 4576, 4592,
	4608, 4624, 4640, 4656, 4672, 4688, 4704, 4720,
	4736, 4752, 4768, 4784, 4800, 4816, 4832, 4848,	// 256
	4864, 4880, 4896, 4912, 4928, 4944, 4960, 4976,	// 264
	4992, 5008, 5024, 5040, 5056, 5072, 5088, 5104,
	5120, 5136, 5152, 5168, 5184, 5200, 5216, 5232,
	5248, 5264, 5280, 5296, 5312, 5328, 5344, 5360,
	5376, 5392, 5408, 5424, 5440, 5456,
	5472, 5488, 5504, 5520, 5536, 5552, 5568, 5584,	// -40
	      5616										// -32 5600 = REFRESH
};

// screen0:width40
static constexpr std::array<int16_t, 232> slotsV9968TextLow = {
//	name  pat   pat   clr   cmd   cmd
	   0,   16,   32,   48,   64,   80, // -42
	  96,  112,        144,  160,  176,	// -36 128=REFRESH
	 192,  208,  224,  240,  256,  272, // -30
	 288,  304,  320,  336,  352,  368,	// -24
	 384,  400,  416,  432,  448,  464,	// -18
	 480,  496,  512,  528,  544,  560, // -12
	             608,      	 640,  656, // -6
	             704,        736,  752,	// 0
	             800,        832,  848,	// 6
	           	 896,        928,  944,	// 12
	             992,      	1024, 1040,	// 18
	            1088,       1120, 1136,
	            1184,       1216, 1232,
	            1280,       1312, 1328,
	            1376,       1408, 1424,
	            1472,       1504, 1520,
	            1568,       1600, 1616,
	           	1664,       1696, 1712,
	            1760,      	1792, 1808,
	            1856,       1888, 1904,
	            1952,       1984, 2000,
	           	2048,       2080, 2096,
	            2144,      	2176, 2192,
	            2240,       2272, 2288,
	            2336,       2368, 2384,
	           	2432,       2464, 2480,
	            2528,      	2560, 2576,
	            2624,       2656, 2672,
	            2720,       2752, 2768,
	           	2816,       2848, 2864,
	            2912,      	2944, 2960,
	            3008,       3040, 3056,
	            3104,       3136, 3152,
	           	3200,       3232, 3248,
	            3296,      	3328, 3344,
	            3392,       3424, 3440,
	            3488,       3520, 3536,
	           	3584,       3616, 3632,
	            3680,      	3712, 3728,
	            3776,       3808, 3824,
	            3872,       3904, 3920,
	           	3968,       4000, 4016,
	            4064,      	4096, 4112,
	            4160,       4192, 4208,
	            4256,       4288, 4304,
	           	4352,       4384, 4400,
	4416, 4432, 4448, 4464,	4480, 4496,
	4512, 4528, 4544, 4560, 4576, 4592,	// 240
	4608, 4624, 4640, 4656, 4672, 4688,
	4704, 4720,	4736, 4752, 4768, 4784,
	4800, 4816, 4832, 4848,	4864, 4880,
	4896, 4912, 4928, 4944, 4960, 4976,
	4992, 5008, 5024, 5040, 5056, 5072,
	5088, 5104,	5120, 5136, 5152, 5168,
	5184, 5200, 5216, 5232,	5248, 5264,
	5280, 5296, 5312, 5328, 5344, 5360,
	5376, 5392, 5408, 5424, 5440, 5456,
	5472, 5488, 5504, 5520, 5536, 5552,	// -42
	5568, 5584,	      5616				// -36 5600=REFRESH
};

// screen0:width80
static constexpr std::array<int16_t, 192> slotsV9968TextHigh = {
//	name  pat   pat   clr   cmd   cmd
	   0,   16,   32,   48,   64,   80, // -42
	  96,  112,        144,  160,  176,	// -36 128=REFRESH
	 192,  208,  224,  240,  256,  272, // -30
	 288,  304,  320,  336,  352,  368,	// -24
	 384,  400,  416,  432,  448,  464,	// -18
	 480,  496,  512,  528,  544,  560, // -12
	                       	 640,  656, // -6
	                         736,  752,	// 0
	                         832,  848,	// 6
	           	             928,  944,	// 12
	                       	1024, 1040,	// 18
	                        1120, 1136,
	                        1216, 1232,
	                        1312, 1328,
	                        1408, 1424,
	                        1504, 1520,
	                        1600, 1616,
	           	            1696, 1712,
	                       	1792, 1808,
	                        1888, 1904,
	                        1984, 2000,
	           	            2080, 2096,
	                       	2176, 2192,
	                        2272, 2288,
	                        2368, 2384,
	           	            2464, 2480,
	                       	2560, 2576,
	                        2656, 2672,
	                        2752, 2768,
	           	            2848, 2864,
	                       	2944, 2960,
	                        3040, 3056,
	                        3136, 3152,
	           	            3232, 3248,
	                       	3328, 3344,
	                        3424, 3440,
	                        3520, 3536,
	           	            3616, 3632,
	                       	3712, 3728,
	                        3808, 3824,
	                        3904, 3920,
	           	            4000, 4016,
	                       	4096, 4112,
	                        4192, 4208,
	                        4288, 4304,
	           	            4384, 4400,
	4416, 4432, 4448, 4464,	4480, 4496,
	4512, 4528, 4544, 4560, 4576, 4592,	// 240
	4608, 4624, 4640, 4656, 4672, 4688,
	4704, 4720,	4736, 4752, 4768, 4784,
	4800, 4816, 4832, 4848,	4864, 4880,
	4896, 4912, 4928, 4944, 4960, 4976,
	4992, 5008, 5024, 5040, 5056, 5072,
	5088, 5104,	5120, 5136, 5152, 5168,
	5184, 5200, 5216, 5232,	5248, 5264,
	5280, 5296, 5312, 5328, 5344, 5360,
	5376, 5392, 5408, 5424, 5440, 5456,
	5472, 5488, 5504, 5520, 5536, 5552,	// -42
	5568, 5584,	      5616				// -36 5600=REFRESH
};

// screen 5,6
static constexpr std::array<int16_t, 320> slotsV9968BitmapLowSpritesOff = {
//	bmp   bmp   spr   cmd   cmd   cmd   cmd   cmd
	   0,   16,   32,   48,   64,   80,   96,  112,	// -40
	       144,  160,  176,  192,  208,  224,  240,	// -32 128=REFRESH
	 256,  272,  288,  304,  320,  336,  352,  368,	// -24
	 384,  400,  416,  432,  448,  464,  480,  496,	// -16
	       528,  544,  560,  576,  592,  608,  624,	// -8
	       656,  672,  688,  704,  720,  736,  752,	// 0
	       784,  800,  816,  832,  848,  864,  880,
	       912,  928,  944,  960,  976,  992, 1008,
	      1040, 1056, 1072, 1088, 1104, 1120, 1136,
	      1168, 1184, 1200, 1216, 1232, 1248, 1264,
	      1296, 1312, 1328, 1344, 1360, 1376, 1392,
	      1424, 1440, 1456, 1472, 1488, 1504, 1520,
	      1552, 1568, 1584, 1600, 1616, 1632, 1648,
	      1680, 1696, 1712, 1728, 1744, 1760, 1776,
	      1808, 1824, 1840, 1856, 1872, 1888, 1904,
	      1936, 1952, 1968, 1984, 2000, 2016, 2032,
	      2064, 2080, 2096, 2112, 2128, 2144, 2160,
	      2192, 2208, 2224, 2240, 2256, 2272, 2288,
	      2320, 2336, 2352, 2368, 2384, 2400, 2416,
	      2448, 2464, 2480, 2496, 2512, 2528, 2544,
	      2576, 2592, 2608, 2624, 2640, 2656, 2672,
	      2704, 2720, 2736, 2752, 2768, 2784, 2800,
	      2832, 2848, 2864, 2880, 2896, 2912, 2928,
	      2960, 2976, 2992, 3008, 3024, 3040, 3056,
	      3088, 3104, 3120, 3136, 3152, 3168, 3184,
	      3216, 3232, 3248, 3264, 3280, 3296, 3312,
	      3344, 3360, 3376, 3392, 3408, 3424, 3440,
	      3472, 3488, 3504, 3520, 3536, 3552, 3568,
	      3600, 3616, 3632, 3648, 3664, 3680, 3696,
	      3728, 3744, 3760, 3776, 3792, 3808, 3824,
	      3856, 3872, 3888, 3904, 3920, 3936, 3952,
	      3984, 4000, 4016, 4032, 4048, 4064, 4080,
	      4112, 4128, 4144, 4160, 4176, 4192, 4208,
	      4240, 4256, 4272, 4288, 4304, 4320, 4336,
	      4368, 4384, 4400, 4416, 4432, 4448, 4464,
	      4496, 4512, 4528, 4544, 4560, 4576, 4592,
	4608, 4624, 4640, 4656, 4672, 4688, 4704, 4720,
	4736, 4752, 4768, 4784, 4800, 4816, 4832, 4848,	// 256
	4864, 4880, 4896, 4912, 4928, 4944, 4960, 4976,	// 264
	4992, 5008, 5024, 5040, 5056, 5072, 5088, 5104,
	5120, 5136, 5152, 5168, 5184, 5200, 5216, 5232,
	5248, 5264, 5280, 5296, 5312, 5328, 5344, 5360,
	5376, 5392, 5408, 5424, 5440, 5456,
	5472, 5488, 5504, 5520, 5536, 5552, 5568, 5584,	// -40
	      5616										// -32 5600=REFRESH
};

// screen 5,6
static constexpr std::array<int16_t, 276> slotsV9968BitmapLowSpritesOn = {
//	bmp   bmp   spr   cmd   cmd   cmd   cmd   cmd
	   0,   16,         48,   64,   80,   96,  112,	// -40
	       144,        176,  192,  208,  224,  240,	// -32 128=REFRESH
	 256,  272,        304,  320,  336,  352,  368,	// -24
	 384,  400,        432,  448,  464,  480,  496,	// -16
	       528,        560,  576,  592,  608,  624,	// -8
	       656,        688,  704,  720,  736,  752,	// 0
	       784,        816,  832,  848,  864,  880,
	       912,        944,  960,  976,  992, 1008,
	      1040,       1072, 1088, 1104, 1120, 1136,
	      1168,       1200, 1216, 1232, 1248, 1264,
	      1296,       1328, 1344, 1360, 1376, 1392,
	      1424,       1456, 1472, 1488, 1504, 1520,
	      1552,       1584, 1600, 1616, 1632, 1648,
	      1680,       1712, 1728, 1744, 1760, 1776,
	      1808,       1840, 1856, 1872, 1888, 1904,
	      1936,       1968, 1984, 2000, 2016, 2032,
	      2064,       2096, 2112, 2128, 2144, 2160,
	      2192,       2224, 2240, 2256, 2272, 2288,
	      2320,       2352, 2368, 2384, 2400, 2416,
	      2448,       2480, 2496, 2512, 2528, 2544,
	      2576,       2608, 2624, 2640, 2656, 2672,
	      2704,       2736, 2752, 2768, 2784, 2800,
	      2832,       2864, 2880, 2896, 2912, 2928,
	      2960,       2992, 3008, 3024, 3040, 3056,
	      3088,       3120, 3136, 3152, 3168, 3184,
	      3216,       3248, 3264, 3280, 3296, 3312,
	      3344,       3376, 3392, 3408, 3424, 3440,
	      3472,       3504, 3520, 3536, 3552, 3568,
	      3600,       3632, 3648, 3664, 3680, 3696,
	      3728,       3760, 3776, 3792, 3808, 3824,
	      3856,       3888, 3904, 3920, 3936, 3952,
	      3984,       4016, 4032, 4048, 4064, 4080,
	      4112,       4144, 4160, 4176, 4192, 4208,
	      4240,       4272, 4288, 4304, 4320, 4336,
	      4368,       4400, 4416, 4432, 4448, 4464,
	      4496,       4528, 4544, 4560, 4576, 4592,
	4608, 4624,       4656, 4672, 4688, 4704, 4720,
	4736, 4752,       4784, 4800, 4816, 4832, 4848,	// 256
	4864, 4880,       4912, 4928, 4944, 4960, 4976,	// 264
	4992, 5008,       5040, 5056, 5072, 5088, 5104,
	5120, 5136,       5168, 5184, 5200, 5216, 5232,
	5248, 5264,       5296, 5312, 5328, 5344, 5360,
	5376, 5392,       5424, 5440, 5456,
	5472, 5488,       5520, 5536, 5552, 5568, 5584,	// -40
	      5616										// -32 5600=REFRESH
};

// screen 7,8,10,11,12
static constexpr std::array<int16_t, 288> slotsV9968BitmapHighSpritesOff = {
//	bmp   bmp   spr   cmd   cmd   cmd   cmd   cmd
	   0,   16,   32,   48,   64,   80,   96,  112,	// -40
	       144,  160,  176,  192,  208,  224,  240,	// -32 128=REFRESH
	 256,  272,  288,  304,  320,  336,  352,  368,	// -24
	 384,  400,  416,  432,  448,  464,  480,  496,	// -16
	             544,  560,  576,  592,  608,  624,	// -8
	             672,  688,  704,  720,  736,  752,	// 0
	             800,  816,  832,  848,  864,  880,
	             928,  944,  960,  976,  992, 1008,
	            1056, 1072, 1088, 1104, 1120, 1136,
	            1184, 1200, 1216, 1232, 1248, 1264,
	            1312, 1328, 1344, 1360, 1376, 1392,
	            1440, 1456, 1472, 1488, 1504, 1520,
	            1568, 1584, 1600, 1616, 1632, 1648,
	            1696, 1712, 1728, 1744, 1760, 1776,
	            1824, 1840, 1856, 1872, 1888, 1904,
	            1952, 1968, 1984, 2000, 2016, 2032,
	            2080, 2096, 2112, 2128, 2144, 2160,
	            2208, 2224, 2240, 2256, 2272, 2288,
	            2336, 2352, 2368, 2384, 2400, 2416,
	            2464, 2480, 2496, 2512, 2528, 2544,
	            2592, 2608, 2624, 2640, 2656, 2672,
	            2720, 2736, 2752, 2768, 2784, 2800,
	            2848, 2864, 2880, 2896, 2912, 2928,
	            2976, 2992, 3008, 3024, 3040, 3056,
	            3104, 3120, 3136, 3152, 3168, 3184,
	            3232, 3248, 3264, 3280, 3296, 3312,
	            3360, 3376, 3392, 3408, 3424, 3440,
	            3488, 3504, 3520, 3536, 3552, 3568,
	            3616, 3632, 3648, 3664, 3680, 3696,
	            3744, 3760, 3776, 3792, 3808, 3824,
	            3872, 3888, 3904, 3920, 3936, 3952,
	            4000, 4016, 4032, 4048, 4064, 4080,
	            4128, 4144, 4160, 4176, 4192, 4208,
	            4256, 4272, 4288, 4304, 4320, 4336,
	            4384, 4400, 4416, 4432, 4448, 4464,
	            4512, 4528, 4544, 4560, 4576, 4592,
	4608, 4624, 4640, 4656, 4672, 4688, 4704, 4720,
	4736, 4752, 4768, 4784, 4800, 4816, 4832, 4848,	// 256
	4864, 4880, 4896, 4912, 4928, 4944, 4960, 4976,	// 264
	4992, 5008, 5024, 5040, 5056, 5072, 5088, 5104,
	5120, 5136, 5152, 5168, 5184, 5200, 5216, 5232,
	5248, 5264, 5280, 5296, 5312, 5328, 5344, 5360,
	5376, 5392, 5408, 5424, 5440, 5456,
	5472, 5488, 5504, 5520, 5536, 5552, 5568, 5584,	// -40
	      5616										// -32 5600=REFRESH
};

// screen 7,8,10,11,12
static constexpr std::array<int16_t, 244> slotsV9968BitmapHighSpritesOn = {
//	bmp   bmp   spr   cmd   cmd   cmd   cmd   cmd
	   0,   16,         48,   64,   80,   96,  112,	// -40
	       144,        176,  192,  208,  224,  240,	// -32 128=REFRESH
	 256,  272,        304,  320,  336,  352,  368,	// -24
	 384,  400,        432,  448,  464,  480,  496,	// -16
	                   560,  576,  592,  608,  624,	// -8
	                   688,  704,  720,  736,  752,	// 0
	                   816,  832,  848,  864,  880,
	                   944,  960,  976,  992, 1008,
	                  1072, 1088, 1104, 1120, 1136,
	                  1200, 1216, 1232, 1248, 1264,
	                  1328, 1344, 1360, 1376, 1392,
	                  1456, 1472, 1488, 1504, 1520,
	                  1584, 1600, 1616, 1632, 1648,
	                  1712, 1728, 1744, 1760, 1776,
	                  1840, 1856, 1872, 1888, 1904,
	                  1968, 1984, 2000, 2016, 2032,
	                  2096, 2112, 2128, 2144, 2160,
	                  2224, 2240, 2256, 2272, 2288,
	                  2352, 2368, 2384, 2400, 2416,
	                  2480, 2496, 2512, 2528, 2544,
	                  2608, 2624, 2640, 2656, 2672,
	                  2736, 2752, 2768, 2784, 2800,
	                  2864, 2880, 2896, 2912, 2928,
	                  2992, 3008, 3024, 3040, 3056,
	                  3120, 3136, 3152, 3168, 3184,
	                  3248, 3264, 3280, 3296, 3312,
	                  3376, 3392, 3408, 3424, 3440,
	                  3504, 3520, 3536, 3552, 3568,
	                  3632, 3648, 3664, 3680, 3696,
	                  3760, 3776, 3792, 3808, 3824,
	                  3888, 3904, 3920, 3936, 3952,
	                  4016, 4032, 4048, 4064, 4080,
	                  4144, 4160, 4176, 4192, 4208,
	                  4272, 4288, 4304, 4320, 4336,
	                  4400, 4416, 4432, 4448, 4464,
	                  4528, 4544, 4560, 4576, 4592,
	4608, 4624,       4656, 4672, 4688, 4704, 4720,
	4736, 4752,       4784, 4800, 4816, 4832, 4848,	// 256
	4864, 4880,       4912, 4928, 4944, 4960, 4976,	// 264
	4992, 5008,       5040, 5056, 5072, 5088, 5104,
	5120, 5136,       5168, 5184, 5200, 5216, 5232,
	5248, 5264,       5296, 5312, 5328, 5344, 5360,
	5376, 5392,       5424, 5440, 5456,
	5472, 5488,       5520, 5536, 5552, 5568, 5584,	// -40
	      5616										// -32 5600=REFRESH
};

// screen 1,2,4
static constexpr std::array<int16_t, 256> slotsV9968PcgSpritesOff = {
//	name  pat   spr   clr   cmd   cmd   cmd   cmd
	   0,   16,   32,   48,   64,   80,   96,  112,	// -40
	       144,  160,  176,  192,  208,  224,  240,	// -32 128=REFRESH
	 256,  272,  288,  304,  320,  336,  352,  368,	// -24
	 384,  400,  416,  432,  448,  464,  480,  496,	// -16
	             544,        576,  592,  608,  624,	// -8
	             672,        704,  720,  736,  752,	// 0
	             800,        832,  848,  864,  880,
	             928,        960,  976,  992, 1008,
	            1056,       1088, 1104, 1120, 1136,
	            1184,       1216, 1232, 1248, 1264,
	            1312,       1344, 1360, 1376, 1392,
	            1440,       1472, 1488, 1504, 1520,
	            1568,       1600, 1616, 1632, 1648,
	            1696,       1728, 1744, 1760, 1776,
	            1824,       1856, 1872, 1888, 1904,
	            1952,       1984, 2000, 2016, 2032,
	            2080,       2112, 2128, 2144, 2160,
	            2208,       2240, 2256, 2272, 2288,
	            2336,       2368, 2384, 2400, 2416,
	            2464,       2496, 2512, 2528, 2544,
	            2592,       2624, 2640, 2656, 2672,
	            2720,       2752, 2768, 2784, 2800,
	            2848,       2880, 2896, 2912, 2928,
	            2976,       3008, 3024, 3040, 3056,
	            3104,       3136, 3152, 3168, 3184,
	            3232,       3264, 3280, 3296, 3312,
	            3360,       3392, 3408, 3424, 3440,
	            3488,       3520, 3536, 3552, 3568,
	            3616,       3648, 3664, 3680, 3696,
	            3744,       3776, 3792, 3808, 3824,
	            3872,       3904, 3920, 3936, 3952,
	            4000,       4032, 4048, 4064, 4080,
	            4128,       4160, 4176, 4192, 4208,
	            4256,       4288, 4304, 4320, 4336,
	            4384,       4416, 4432, 4448, 4464,
	            4512,       4544, 4560, 4576, 4592,
	4608, 4624, 4640, 4656, 4672, 4688, 4704, 4720,
	4736, 4752, 4768, 4784, 4800, 4816, 4832, 4848,	// 256
	4864, 4880, 4896, 4912, 4928, 4944, 4960, 4976,	// 264
	4992, 5008, 5024, 5040, 5056, 5072, 5088, 5104,
	5120, 5136, 5152, 5168, 5184, 5200, 5216, 5232,
	5248, 5264, 5280, 5296, 5312, 5328, 5344, 5360,
	5376, 5392, 5408, 5424, 5440, 5456,
	5472, 5488, 5504, 5520, 5536, 5552, 5568, 5584,	// -40
	      5616										// -32 5600=REFRESH
};

// screen 1,2,4
static constexpr std::array<int16_t, 212> slotsV9968PcgSpritesOn = {
//	name  pat   spr   clr   cmd   cmd   cmd   cmd
	   0,   16,         48,   64,   80,   96,  112,	// -40
	       144,        176,  192,  208,  224,  240,	// -32 128=REFRESH
	 256,  272,        304,  320,  336,  352,  368,	// -24
	 384,  400,        432,  448,  464,  480,  496,	// -16
	                         576,  592,  608,  624,	// -8
	                         704,  720,  736,  752,	// 0
	                         832,  848,  864,  880,
	                         960,  976,  992, 1008,
	                        1088, 1104, 1120, 1136,
	                        1216, 1232, 1248, 1264,
	                        1344, 1360, 1376, 1392,
	                        1472, 1488, 1504, 1520,
	                        1600, 1616, 1632, 1648,
	                        1728, 1744, 1760, 1776,
	                        1856, 1872, 1888, 1904,
	                        1984, 2000, 2016, 2032,
	                        2112, 2128, 2144, 2160,
	                        2240, 2256, 2272, 2288,
	                        2368, 2384, 2400, 2416,
	                        2496, 2512, 2528, 2544,
	                        2624, 2640, 2656, 2672,
	                        2752, 2768, 2784, 2800,
	                        2880, 2896, 2912, 2928,
	                        3008, 3024, 3040, 3056,
	                        3136, 3152, 3168, 3184,
	                        3264, 3280, 3296, 3312,
	                        3392, 3408, 3424, 3440,
	                        3520, 3536, 3552, 3568,
	                        3648, 3664, 3680, 3696,
	                        3776, 3792, 3808, 3824,
	                        3904, 3920, 3936, 3952,
	                        4032, 4048, 4064, 4080,
	                        4160, 4176, 4192, 4208,
	                        4288, 4304, 4320, 4336,
	                        4416, 4432, 4448, 4464,
	                        4544, 4560, 4576, 4592,
	4608, 4624,       4656, 4672, 4688, 4704, 4720,
	4736, 4752,       4784, 4800, 4816, 4832, 4848,	// 256
	4864, 4880,       4912, 4928, 4944, 4960, 4976,	// 264
	4992, 5008,       5040, 5056, 5072, 5088, 5104,
	5120, 5136,       5168, 5184, 5200, 5216, 5232,
	5248, 5264,       5296, 5312, 5328, 5344, 5360,
	5376, 5392,       5424, 5440, 5456,
	5472, 5488,       5520, 5536, 5552, 5568, 5584,	// -40
	      5616										// -32 5600=REFRESH
};

// Helper functions to transform the above tables into a format that is easier
// (=faster) to work with.

struct AccessTable
{
	operator std::span<const tab_value, NUM_DELTAS * TICKS>() const { return values; }

protected:
	std::array<tab_value, NUM_DELTAS * TICKS> values = {};
};

struct CycleTable : AccessTable
{
	constexpr CycleTable(const bool msx1, const bool v9968, std::span<const int16_t> slots)
	{
		// !!! Keep this in sync with the 'Delta' enum !!!
		constexpr std::array<int, NUM_DELTAS> delta = {
			0, 1, 16, 24, 28, 32, 40, 48, 64, 72, 88, 104, 120, 128, 136
		};

		constexpr size_t max_val = 65536;//1 << sizeof(tab_value);
		int mul = v9968 ? 1 : VDP::CLK_MUL;

		size_t out = 0;
		for (auto step_raw : delta) {
			const int step = step_raw * mul;
			int p = 0;
			while (slots[p] * mul < step) ++p;
			for (auto i : xrange(TICKS)) {
				if ((slots[p] * mul - i) < step /*&& p < slots.size()-1*/) ++p;
				const int16_t slot_val = slots[p] * mul;
				assert((slot_val - i) >= step);
				unsigned t = slot_val - i;
				if (msx1) {
					if (step <= 40 * mul) assert(t < max_val);
				} else {
					assert(t < max_val);
				}
				values[out++] = narrow_cast<tab_value>(t);
			}
		}
	}
};

struct ZeroTable : AccessTable
{
};

#ifdef NDEBUG
static constexpr CycleTable tabSpritesOn     (false, false, slotsSpritesOn);
static constexpr CycleTable tabSpritesOff    (false, false, slotsSpritesOff);
static constexpr CycleTable tabChar          (false, false, slotsChar);
static constexpr CycleTable tabText          (false, false, slotsText);
static constexpr CycleTable tabScreenOff     (false, false, slotsScreenOff);
static constexpr CycleTable tabMsx1Gfx12     (true,  false, slotsMsx1Gfx12);
static constexpr CycleTable tabMsx1Gfx3      (true,  false, slotsMsx1Gfx3);
static constexpr CycleTable tabMsx1Text      (true,  false, slotsMsx1Text);
static constexpr CycleTable tabMsx1ScreenOff (true,  false, slotsMsx1ScreenOff);
static constexpr ZeroTable  tabBroken;
static constexpr CycleTable tabV9968ScreenOff			(false,  true, slotsV9968ScreenOff);
static constexpr CycleTable tabV9968TextLow				(false,  true, slotsV9968TextLow);
static constexpr CycleTable tabV9968TextHigh			(false,  true, slotsV9968TextHigh);
static constexpr CycleTable tabV9968BmpLowSpritesOff	(false,  true, slotsV9968BitmapLowSpritesOff);
static constexpr CycleTable tabV9968BmpLowSpritesOn		(false,  true, slotsV9968BitmapLowSpritesOn);
static constexpr CycleTable tabV9968BmpHighSpritesOff	(false,  true, slotsV9968BitmapHighSpritesOff);
static constexpr CycleTable tabV9968BmpHighSpritesOn	(false,  true, slotsV9968BitmapHighSpritesOn);
static constexpr CycleTable tabV9968PcgSpritesOff		(false,  true, slotsV9968PcgSpritesOff);
static constexpr CycleTable tabV9968PcgSpritesOn		(false,  true, slotsV9968PcgSpritesOn);
#else
static  CycleTable tabSpritesOn     (false, false, slotsSpritesOn);
static  CycleTable tabSpritesOff    (false, false, slotsSpritesOff);
static  CycleTable tabChar          (false, false, slotsChar);
static  CycleTable tabText          (false, false, slotsText);
static  CycleTable tabScreenOff     (false, false, slotsScreenOff);
static  CycleTable tabMsx1Gfx12     (true,  false, slotsMsx1Gfx12);
static  CycleTable tabMsx1Gfx3      (true,  false, slotsMsx1Gfx3);
static  CycleTable tabMsx1Text      (true,  false, slotsMsx1Text);
static  CycleTable tabMsx1ScreenOff (true,  false, slotsMsx1ScreenOff);
static  ZeroTable  tabBroken;
static  CycleTable tabV9968ScreenOff			(false,  true, slotsV9968ScreenOff);
static  CycleTable tabV9968TextLow				(false,  true, slotsV9968TextLow);
static  CycleTable tabV9968TextHigh				(false,  true, slotsV9968TextHigh);
static  CycleTable tabV9968BmpLowSpritesOff		(false,  true, slotsV9968BitmapLowSpritesOff);
static  CycleTable tabV9968BmpLowSpritesOn		(false,  true, slotsV9968BitmapLowSpritesOn);
static  CycleTable tabV9968BmpHighSpritesOff	(false,  true, slotsV9968BitmapHighSpritesOff);
static  CycleTable tabV9968BmpHighSpritesOn		(false,  true, slotsV9968BitmapHighSpritesOn);
static  CycleTable tabV9968PcgSpritesOff		(false,  true, slotsV9968PcgSpritesOff);
static  CycleTable tabV9968PcgSpritesOn			(false,  true, slotsV9968PcgSpritesOn);
#endif

[[nodiscard]] static inline std::span<const tab_value, NUM_DELTAS * TICKS> getTab(const VDP& vdp)
{
	if (vdp.getBrokenCmdTiming()) return tabBroken;
	bool enabled = vdp.isDisplayEnabled();
	bool sprites = vdp.spritesEnabledRegister();
	auto mode    = vdp.getDisplayMode();
	bool bitmap  = mode.isBitmapMode();
	bool text    = mode.isTextMode();
	bool gfx3    = mode.getBase() == DisplayMode::GRAPHIC3;

	if (vdp.useHS()) {
		if (!enabled) return tabV9968ScreenOff;
		switch (mode.getByte()) {
			case DisplayMode::TEXT1:
				return tabV9968TextLow;
			case DisplayMode::TEXT2:
				return tabV9968TextHigh;
			case DisplayMode::GRAPHIC1:
			case DisplayMode::GRAPHIC2:
			case DisplayMode::GRAPHIC3:
			case DisplayMode::MULTICOLOR:
				return sprites ? tabV9968PcgSpritesOn : tabV9968PcgSpritesOff;
			case DisplayMode::GRAPHIC6:
			case DisplayMode::GRAPHIC7:
				return sprites ? tabV9968BmpHighSpritesOn : tabV9968BmpHighSpritesOff;
			default:
				return sprites ? tabV9968BmpLowSpritesOn : tabV9968BmpLowSpritesOff;
		}
	} else if (vdp.isMSX1VDP()) {
		if (!enabled) return tabMsx1ScreenOff;
		return text ? tabMsx1Text
		            : (gfx3 ? tabMsx1Gfx3
		                    : tabMsx1Gfx12);
		// TODO undocumented modes
	} else {
		if (bitmap) {
			return !enabled ? tabScreenOff
			      : sprites ? tabSpritesOn
			                : tabSpritesOff;
		} else {
			// 'enabled' or 'sprites' doesn't matter in V99x8 non-bitmap mode
			// See: https://github.com/openMSX/openMSX/issues/1754
			return text ? tabText
			            : tabChar;
		}
	}
}

EmuTime getAccessSlot(
	EmuTime frame_, EmuTime time, Delta delta,
	const VDP& vdp)
{
	VDP::VDPClock frame(frame_);
	unsigned ticks = frame.getTicksTill_fast(time) % TICKS;
	auto tab = getTab(vdp);
	return time + VDP::VDPClock::duration(tab[std::to_underlying(delta) + ticks]);
}

EmuTime getAccessSlot(EmuTime frame_, EmuTime time, int delay, int wait, VDPCmdCache::CachePenalty penalty, const VDP& vdp)
{
	VDP::VDPClock frame(frame_);
	auto tab = getTab(vdp);
	unsigned start_ticks = frame.getTicksTill_fast(time);
	unsigned end_ticks = getAccessSlotTick(start_ticks, delay, wait, penalty, tab);
	return time + VDP::VDPClock::duration(end_ticks - start_ticks);
}

unsigned getAccessSlotTick(unsigned ticks, int delay, int wait, VDPCmdCache::CachePenalty penalty, std::span<const tab_value, NUM_DELTAS * TICKS> tab)
{
	ticks += delay;
	if(penalty == VDPCmdCache::CachePenalty::CACHE_READ_HIT) {
		ticks += 1;													// check
	} else if(penalty == VDPCmdCache::CachePenalty::CACHE_READ_MISS) {
		ticks += 1;													// check
		ticks += tab[ticks % TICKS] + V9968_MEMORY_ACCESS_TIME + 1;	// read
	} else if(penalty == VDPCmdCache::CachePenalty::CACHE_READ_FLUSH) {
		ticks += 1;													// check
		ticks += tab[ticks % TICKS] + V9968_MEMORY_ACCESS_TIME + 1;	// write
		ticks += tab[ticks % TICKS] + V9968_MEMORY_ACCESS_TIME + 1;	// read
	} else if(penalty == VDPCmdCache::CachePenalty::CACHE_WRITE_HIT) {
		ticks += 1;													// check
	} else if(penalty == VDPCmdCache::CachePenalty::CACHE_WRITE_MISS) {
		ticks += 1;													// check
	} else if(penalty == VDPCmdCache::CachePenalty::CACHE_WRITE_FLUSH) {
		ticks += 1;													// check
		ticks += tab[ticks % TICKS] + V9968_MEMORY_ACCESS_TIME;		// write
	} else if(penalty == VDPCmdCache::CachePenalty::CACHE_FLUSH_1) {
		ticks += 1;													// check
		ticks += tab[ticks % TICKS] + V9968_MEMORY_ACCESS_TIME;		// write
	} else if(penalty == VDPCmdCache::CachePenalty::CACHE_FLUSH_2) {
		ticks += 1;													// check
		ticks += tab[ticks % TICKS] + V9968_MEMORY_ACCESS_TIME;		// write
		ticks += 1;													// check
		ticks += tab[ticks % TICKS] + V9968_MEMORY_ACCESS_TIME;		// write
	} else if(penalty == VDPCmdCache::CachePenalty::CACHE_FLUSH_3) {
		ticks += 1;													// check
		ticks += tab[ticks % TICKS] + V9968_MEMORY_ACCESS_TIME;		// write
		ticks += 1;													// check
		ticks += tab[ticks % TICKS] + V9968_MEMORY_ACCESS_TIME;		// write
		ticks += 1;													// check
		ticks += tab[ticks % TICKS] + V9968_MEMORY_ACCESS_TIME;		// write
	} else if(penalty == VDPCmdCache::CachePenalty::CACHE_FLUSH_4) {
		ticks += 1;													// check
		ticks += tab[ticks % TICKS] + V9968_MEMORY_ACCESS_TIME;		// write
		ticks += 1;													// check
		ticks += tab[ticks % TICKS] + V9968_MEMORY_ACCESS_TIME;		// write
		ticks += 1;													// check
		ticks += tab[ticks % TICKS] + V9968_MEMORY_ACCESS_TIME;		// write
		ticks += 1;													// check
		ticks += tab[ticks % TICKS] + V9968_MEMORY_ACCESS_TIME;		// write
	}

	ticks += wait;

	return ticks;
}

Calculator getCalculator(
	EmuTime frame, EmuTime time, EmuTime limit,
	const VDP& vdp)
{
	auto tab = getTab(vdp);
	return {frame, time, limit, tab};
}

} // namespace openmsx::VDPAccessSlots
