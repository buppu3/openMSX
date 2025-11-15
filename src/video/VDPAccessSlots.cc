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
static constexpr int16_t CPU_EN = 0x8000u;
static constexpr int16_t SLOT_MASK = 0x7FFFu;
static constexpr int16_t c_timming_a = 1;
static constexpr int16_t c_timming_b = 9;

static constexpr std::array<int16_t, 700> slotsV9968ScreenOff = {
	0000 * 16 + c_timming_a,	CPU_EN | (0000 * 16 + c_timming_b),	// -40
	0001 * 16 + c_timming_a,	CPU_EN | (0001 * 16 + c_timming_b),	// -39
	0002 * 16 + c_timming_a,	CPU_EN | (0002 * 16 + c_timming_b),	// -38
	0003 * 16 + c_timming_a,	CPU_EN | (0003 * 16 + c_timming_b),	// -37
	0004 * 16 + c_timming_a,	CPU_EN | (0004 * 16 + c_timming_b),	// -36
	0005 * 16 + c_timming_a,	CPU_EN | (0005 * 16 + c_timming_b),	// -35
	0006 * 16 + c_timming_a,	CPU_EN | (0006 * 16 + c_timming_b),	// -34
	0007 * 16 + c_timming_a,	CPU_EN | (0007 * 16 + c_timming_b),	// -33

	/* REFRESH */													// -32
	0011 * 16 + c_timming_a,	CPU_EN | (0011 * 16 + c_timming_b),	// -31
	0012 * 16 + c_timming_a,	CPU_EN | (0012 * 16 + c_timming_b),	// -30
	0013 * 16 + c_timming_a,	CPU_EN | (0013 * 16 + c_timming_b),	// -29
	0014 * 16 + c_timming_a,	CPU_EN | (0014 * 16 + c_timming_b),	// -28
	0015 * 16 + c_timming_a,	CPU_EN | (0015 * 16 + c_timming_b),	// -27
	0016 * 16 + c_timming_a,	CPU_EN | (0016 * 16 + c_timming_b),	// -26
	0017 * 16 + c_timming_a,	CPU_EN | (0017 * 16 + c_timming_b),	// -25

	0020 * 16 + c_timming_a,	CPU_EN | (0020 * 16 + c_timming_b),	// -24
	0021 * 16 + c_timming_a,	CPU_EN | (0021 * 16 + c_timming_b),	// -23
	0022 * 16 + c_timming_a,	CPU_EN | (0022 * 16 + c_timming_b),	// -22
	0023 * 16 + c_timming_a,	CPU_EN | (0023 * 16 + c_timming_b),	// -21
	0024 * 16 + c_timming_a,	CPU_EN | (0024 * 16 + c_timming_b),	// -20
	0025 * 16 + c_timming_a,	CPU_EN | (0025 * 16 + c_timming_b),	// -19
	0026 * 16 + c_timming_a,	CPU_EN | (0026 * 16 + c_timming_b),	// -18
	0027 * 16 + c_timming_a,	CPU_EN | (0027 * 16 + c_timming_b),	// -17

	0030 * 16 + c_timming_a,	CPU_EN | (0030 * 16 + c_timming_b),	// -16
	0031 * 16 + c_timming_a,	CPU_EN | (0031 * 16 + c_timming_b),	// -15
	0032 * 16 + c_timming_a,	CPU_EN | (0032 * 16 + c_timming_b),	// -14
	0033 * 16 + c_timming_a,	CPU_EN | (0033 * 16 + c_timming_b),	// -13
	0034 * 16 + c_timming_a,	CPU_EN | (0034 * 16 + c_timming_b),	// -12
	0035 * 16 + c_timming_a,	CPU_EN | (0035 * 16 + c_timming_b),	// -11
	0036 * 16 + c_timming_a,	CPU_EN | (0036 * 16 + c_timming_b),	// -10
	0037 * 16 + c_timming_a,	CPU_EN | (0037 * 16 + c_timming_b),	// -9

	0040 * 16 + c_timming_a,	CPU_EN | (0040 * 16 + c_timming_b),	// -8
	0041 * 16 + c_timming_a,	CPU_EN | (0041 * 16 + c_timming_b),	// -7
	0042 * 16 + c_timming_a,	CPU_EN | (0042 * 16 + c_timming_b),	// -6
	0043 * 16 + c_timming_a,	CPU_EN | (0043 * 16 + c_timming_b),	// -5
	0044 * 16 + c_timming_a,	CPU_EN | (0044 * 16 + c_timming_b),	// -4
	0045 * 16 + c_timming_a,	CPU_EN | (0045 * 16 + c_timming_b),	// -3
	0046 * 16 + c_timming_a,	CPU_EN | (0046 * 16 + c_timming_b),	// -2
	0047 * 16 + c_timming_a,	CPU_EN | (0047 * 16 + c_timming_b),	// -1

	0050 * 16 + c_timming_a,	CPU_EN | (0050 * 16 + c_timming_b),	// 0
	0051 * 16 + c_timming_a,	CPU_EN | (0051 * 16 + c_timming_b),	// 1
	0052 * 16 + c_timming_a,	CPU_EN | (0052 * 16 + c_timming_b),	// 2
	0053 * 16 + c_timming_a,	CPU_EN | (0053 * 16 + c_timming_b),	// 3
	0054 * 16 + c_timming_a,	CPU_EN | (0054 * 16 + c_timming_b),	// 4
	0055 * 16 + c_timming_a,	CPU_EN | (0055 * 16 + c_timming_b),	// 5
	0056 * 16 + c_timming_a,	CPU_EN | (0056 * 16 + c_timming_b),	// 6
	0057 * 16 + c_timming_a,	CPU_EN | (0057 * 16 + c_timming_b),	// 7

	0060 * 16 + c_timming_a,	CPU_EN | (0060 * 16 + c_timming_b),	// 8
	0061 * 16 + c_timming_a,	CPU_EN | (0061 * 16 + c_timming_b),	// 9
	0062 * 16 + c_timming_a,	CPU_EN | (0062 * 16 + c_timming_b),	// 10
	0063 * 16 + c_timming_a,	CPU_EN | (0063 * 16 + c_timming_b),	// 11
	0064 * 16 + c_timming_a,	CPU_EN | (0064 * 16 + c_timming_b),	// 12
	0065 * 16 + c_timming_a,	CPU_EN | (0065 * 16 + c_timming_b),	// 13
	0066 * 16 + c_timming_a,	CPU_EN | (0066 * 16 + c_timming_b),	// 14
	0067 * 16 + c_timming_a,	CPU_EN | (0067 * 16 + c_timming_b),	// 15

	0070 * 16 + c_timming_a,	CPU_EN | (0070 * 16 + c_timming_b),	// 16
	0071 * 16 + c_timming_a,	CPU_EN | (0071 * 16 + c_timming_b),	// 17
	0072 * 16 + c_timming_a,	CPU_EN | (0072 * 16 + c_timming_b),	// 18
	0073 * 16 + c_timming_a,	CPU_EN | (0073 * 16 + c_timming_b),	// 19
	0074 * 16 + c_timming_a,	CPU_EN | (0074 * 16 + c_timming_b),	// 20
	0075 * 16 + c_timming_a,	CPU_EN | (0075 * 16 + c_timming_b),	// 21
	0076 * 16 + c_timming_a,	CPU_EN | (0076 * 16 + c_timming_b),	// 22
	0077 * 16 + c_timming_a,	CPU_EN | (0077 * 16 + c_timming_b),	// 23

	0100 * 16 + c_timming_a,	CPU_EN | (0100 * 16 + c_timming_b),	// 24
	0101 * 16 + c_timming_a,	CPU_EN | (0101 * 16 + c_timming_b),	// 25
	0102 * 16 + c_timming_a,	CPU_EN | (0102 * 16 + c_timming_b),	// 26
	0103 * 16 + c_timming_a,	CPU_EN | (0103 * 16 + c_timming_b),	// 27
	0104 * 16 + c_timming_a,	CPU_EN | (0104 * 16 + c_timming_b),	// 28
	0105 * 16 + c_timming_a,	CPU_EN | (0105 * 16 + c_timming_b),	// 29
	0106 * 16 + c_timming_a,	CPU_EN | (0106 * 16 + c_timming_b),	// 30
	0107 * 16 + c_timming_a,	CPU_EN | (0107 * 16 + c_timming_b),	// 31

	0110 * 16 + c_timming_a,	CPU_EN | (0110 * 16 + c_timming_b),	// 32
	0111 * 16 + c_timming_a,	CPU_EN | (0111 * 16 + c_timming_b),	// 33
	0112 * 16 + c_timming_a,	CPU_EN | (0112 * 16 + c_timming_b),	// 34
	0113 * 16 + c_timming_a,	CPU_EN | (0113 * 16 + c_timming_b),	// 35
	0114 * 16 + c_timming_a,	CPU_EN | (0114 * 16 + c_timming_b),	// 36
	0115 * 16 + c_timming_a,	CPU_EN | (0115 * 16 + c_timming_b),	// 37
	0116 * 16 + c_timming_a,	CPU_EN | (0116 * 16 + c_timming_b),	// 38
	0117 * 16 + c_timming_a,	CPU_EN | (0117 * 16 + c_timming_b),	// 39

	0120 * 16 + c_timming_a,	CPU_EN | (0120 * 16 + c_timming_b),	// 40
	0121 * 16 + c_timming_a,	CPU_EN | (0121 * 16 + c_timming_b),	// 41
	0122 * 16 + c_timming_a,	CPU_EN | (0122 * 16 + c_timming_b),	// 42
	0123 * 16 + c_timming_a,	CPU_EN | (0123 * 16 + c_timming_b),	// 43
	0124 * 16 + c_timming_a,	CPU_EN | (0124 * 16 + c_timming_b),	// 44
	0125 * 16 + c_timming_a,	CPU_EN | (0125 * 16 + c_timming_b),	// 45
	0126 * 16 + c_timming_a,	CPU_EN | (0126 * 16 + c_timming_b),	// 46
	0127 * 16 + c_timming_a,	CPU_EN | (0127 * 16 + c_timming_b),	// 47

	0130 * 16 + c_timming_a,	CPU_EN | (0130 * 16 + c_timming_b),	// 48
	0131 * 16 + c_timming_a,	CPU_EN | (0131 * 16 + c_timming_b),	// 49
	0132 * 16 + c_timming_a,	CPU_EN | (0132 * 16 + c_timming_b),	// 50
	0133 * 16 + c_timming_a,	CPU_EN | (0133 * 16 + c_timming_b),	// 51
	0134 * 16 + c_timming_a,	CPU_EN | (0134 * 16 + c_timming_b),	// 52
	0135 * 16 + c_timming_a,	CPU_EN | (0135 * 16 + c_timming_b),	// 53
	0136 * 16 + c_timming_a,	CPU_EN | (0136 * 16 + c_timming_b),	// 54
	0137 * 16 + c_timming_a,	CPU_EN | (0137 * 16 + c_timming_b),	// 55

	0140 * 16 + c_timming_a,	CPU_EN | (0140 * 16 + c_timming_b),	// 56
	0141 * 16 + c_timming_a,	CPU_EN | (0141 * 16 + c_timming_b),	// 57
	0142 * 16 + c_timming_a,	CPU_EN | (0142 * 16 + c_timming_b),	// 58
	0143 * 16 + c_timming_a,	CPU_EN | (0143 * 16 + c_timming_b),	// 59
	0144 * 16 + c_timming_a,	CPU_EN | (0144 * 16 + c_timming_b),	// 60
	0145 * 16 + c_timming_a,	CPU_EN | (0145 * 16 + c_timming_b),	// 61
	0146 * 16 + c_timming_a,	CPU_EN | (0146 * 16 + c_timming_b),	// 62
	0147 * 16 + c_timming_a,	CPU_EN | (0147 * 16 + c_timming_b),	// 63

	0150 * 16 + c_timming_a,	CPU_EN | (0150 * 16 + c_timming_b),	// 64
	0151 * 16 + c_timming_a,	CPU_EN | (0151 * 16 + c_timming_b),	// 65
	0152 * 16 + c_timming_a,	CPU_EN | (0152 * 16 + c_timming_b),	// 66
	0153 * 16 + c_timming_a,	CPU_EN | (0153 * 16 + c_timming_b),	// 67
	0154 * 16 + c_timming_a,	CPU_EN | (0154 * 16 + c_timming_b),	// 68
	0155 * 16 + c_timming_a,	CPU_EN | (0155 * 16 + c_timming_b),	// 69
	0156 * 16 + c_timming_a,	CPU_EN | (0156 * 16 + c_timming_b),	// 70
	0157 * 16 + c_timming_a,	CPU_EN | (0157 * 16 + c_timming_b),	// 71

	0160 * 16 + c_timming_a,	CPU_EN | (0160 * 16 + c_timming_b),	// 72
	0161 * 16 + c_timming_a,	CPU_EN | (0161 * 16 + c_timming_b),	// 73
	0162 * 16 + c_timming_a,	CPU_EN | (0162 * 16 + c_timming_b),	// 74
	0163 * 16 + c_timming_a,	CPU_EN | (0163 * 16 + c_timming_b),	// 75
	0164 * 16 + c_timming_a,	CPU_EN | (0164 * 16 + c_timming_b),	// 76
	0165 * 16 + c_timming_a,	CPU_EN | (0165 * 16 + c_timming_b),	// 77
	0166 * 16 + c_timming_a,	CPU_EN | (0166 * 16 + c_timming_b),	// 78
	0167 * 16 + c_timming_a,	CPU_EN | (0167 * 16 + c_timming_b),	// 79

	0170 * 16 + c_timming_a,	CPU_EN | (0170 * 16 + c_timming_b),	// 80
	0171 * 16 + c_timming_a,	CPU_EN | (0171 * 16 + c_timming_b),	// 81
	0172 * 16 + c_timming_a,	CPU_EN | (0172 * 16 + c_timming_b),	// 82
	0173 * 16 + c_timming_a,	CPU_EN | (0173 * 16 + c_timming_b),	// 83
	0174 * 16 + c_timming_a,	CPU_EN | (0174 * 16 + c_timming_b),	// 84
	0175 * 16 + c_timming_a,	CPU_EN | (0175 * 16 + c_timming_b),	// 85
	0176 * 16 + c_timming_a,	CPU_EN | (0176 * 16 + c_timming_b),	// 86
	0177 * 16 + c_timming_a,	CPU_EN | (0177 * 16 + c_timming_b),	// 87

	0200 * 16 + c_timming_a,	CPU_EN | (0200 * 16 + c_timming_b),	// 88
	0201 * 16 + c_timming_a,	CPU_EN | (0201 * 16 + c_timming_b),	// 89
	0202 * 16 + c_timming_a,	CPU_EN | (0202 * 16 + c_timming_b),	// 90
	0203 * 16 + c_timming_a,	CPU_EN | (0203 * 16 + c_timming_b),	// 91
	0204 * 16 + c_timming_a,	CPU_EN | (0204 * 16 + c_timming_b),	// 92
	0205 * 16 + c_timming_a,	CPU_EN | (0205 * 16 + c_timming_b),	// 93
	0206 * 16 + c_timming_a,	CPU_EN | (0206 * 16 + c_timming_b),	// 94
	0207 * 16 + c_timming_a,	CPU_EN | (0207 * 16 + c_timming_b),	// 95

	0210 * 16 + c_timming_a,	CPU_EN | (0210 * 16 + c_timming_b),	// 96
	0211 * 16 + c_timming_a,	CPU_EN | (0211 * 16 + c_timming_b),	// 97
	0212 * 16 + c_timming_a,	CPU_EN | (0212 * 16 + c_timming_b),	// 98
	0213 * 16 + c_timming_a,	CPU_EN | (0213 * 16 + c_timming_b),	// 99
	0214 * 16 + c_timming_a,	CPU_EN | (0214 * 16 + c_timming_b),	// 100
	0215 * 16 + c_timming_a,	CPU_EN | (0215 * 16 + c_timming_b),	// 101
	0216 * 16 + c_timming_a,	CPU_EN | (0216 * 16 + c_timming_b),	// 102
	0217 * 16 + c_timming_a,	CPU_EN | (0217 * 16 + c_timming_b),	// 103

	0220 * 16 + c_timming_a,	CPU_EN | (0220 * 16 + c_timming_b),	// 104
	0221 * 16 + c_timming_a,	CPU_EN | (0221 * 16 + c_timming_b),	// 105
	0222 * 16 + c_timming_a,	CPU_EN | (0222 * 16 + c_timming_b),	// 106
	0223 * 16 + c_timming_a,	CPU_EN | (0223 * 16 + c_timming_b),	// 107
	0224 * 16 + c_timming_a,	CPU_EN | (0224 * 16 + c_timming_b),	// 108
	0225 * 16 + c_timming_a,	CPU_EN | (0225 * 16 + c_timming_b),	// 109
	0226 * 16 + c_timming_a,	CPU_EN | (0226 * 16 + c_timming_b),	// 110
	0227 * 16 + c_timming_a,	CPU_EN | (0227 * 16 + c_timming_b),	// 111

	0230 * 16 + c_timming_a,	CPU_EN | (0230 * 16 + c_timming_b),	// 112
	0231 * 16 + c_timming_a,	CPU_EN | (0231 * 16 + c_timming_b),	// 113
	0232 * 16 + c_timming_a,	CPU_EN | (0232 * 16 + c_timming_b),	// 114
	0233 * 16 + c_timming_a,	CPU_EN | (0233 * 16 + c_timming_b),	// 115
	0234 * 16 + c_timming_a,	CPU_EN | (0234 * 16 + c_timming_b),	// 116
	0235 * 16 + c_timming_a,	CPU_EN | (0235 * 16 + c_timming_b),	// 117
	0236 * 16 + c_timming_a,	CPU_EN | (0236 * 16 + c_timming_b),	// 118
	0237 * 16 + c_timming_a,	CPU_EN | (0237 * 16 + c_timming_b),	// 119

	0240 * 16 + c_timming_a,	CPU_EN | (0240 * 16 + c_timming_b),	// 120
	0241 * 16 + c_timming_a,	CPU_EN | (0241 * 16 + c_timming_b),	// 121
	0242 * 16 + c_timming_a,	CPU_EN | (0242 * 16 + c_timming_b),	// 122
	0243 * 16 + c_timming_a,	CPU_EN | (0243 * 16 + c_timming_b),	// 123
	0244 * 16 + c_timming_a,	CPU_EN | (0244 * 16 + c_timming_b),	// 124
	0245 * 16 + c_timming_a,	CPU_EN | (0245 * 16 + c_timming_b),	// 125
	0246 * 16 + c_timming_a,	CPU_EN | (0246 * 16 + c_timming_b),	// 126
	0247 * 16 + c_timming_a,	CPU_EN | (0247 * 16 + c_timming_b),	// 127

	0250 * 16 + c_timming_a,	CPU_EN | (0250 * 16 + c_timming_b),	// 128
	0251 * 16 + c_timming_a,	CPU_EN | (0251 * 16 + c_timming_b),	// 129
	0252 * 16 + c_timming_a,	CPU_EN | (0252 * 16 + c_timming_b),	// 130
	0253 * 16 + c_timming_a,	CPU_EN | (0253 * 16 + c_timming_b),	// 131
	0254 * 16 + c_timming_a,	CPU_EN | (0254 * 16 + c_timming_b),	// 132
	0255 * 16 + c_timming_a,	CPU_EN | (0255 * 16 + c_timming_b),	// 133
	0256 * 16 + c_timming_a,	CPU_EN | (0256 * 16 + c_timming_b),	// 134
	0257 * 16 + c_timming_a,	CPU_EN | (0257 * 16 + c_timming_b),	// 135

	0260 * 16 + c_timming_a,	CPU_EN | (0260 * 16 + c_timming_b),	// 136
	0261 * 16 + c_timming_a,	CPU_EN | (0261 * 16 + c_timming_b),	// 137
	0262 * 16 + c_timming_a,	CPU_EN | (0262 * 16 + c_timming_b),	// 138
	0263 * 16 + c_timming_a,	CPU_EN | (0263 * 16 + c_timming_b),	// 139
	0264 * 16 + c_timming_a,	CPU_EN | (0264 * 16 + c_timming_b),	// 140
	0265 * 16 + c_timming_a,	CPU_EN | (0265 * 16 + c_timming_b),	// 141
	0266 * 16 + c_timming_a,	CPU_EN | (0266 * 16 + c_timming_b),	// 142
	0267 * 16 + c_timming_a,	CPU_EN | (0267 * 16 + c_timming_b),	// 143

	0270 * 16 + c_timming_a,	CPU_EN | (0270 * 16 + c_timming_b),	// 144
	0271 * 16 + c_timming_a,	CPU_EN | (0271 * 16 + c_timming_b),	// 145
	0272 * 16 + c_timming_a,	CPU_EN | (0272 * 16 + c_timming_b),	// 146
	0273 * 16 + c_timming_a,	CPU_EN | (0273 * 16 + c_timming_b),	// 147
	0274 * 16 + c_timming_a,	CPU_EN | (0274 * 16 + c_timming_b),	// 148
	0275 * 16 + c_timming_a,	CPU_EN | (0275 * 16 + c_timming_b),	// 149
	0276 * 16 + c_timming_a,	CPU_EN | (0276 * 16 + c_timming_b),	// 150
	0277 * 16 + c_timming_a,	CPU_EN | (0277 * 16 + c_timming_b),	// 151

	0300 * 16 + c_timming_a,	CPU_EN | (0300 * 16 + c_timming_b),	// 152
	0301 * 16 + c_timming_a,	CPU_EN | (0301 * 16 + c_timming_b),	// 153
	0302 * 16 + c_timming_a,	CPU_EN | (0302 * 16 + c_timming_b),	// 154
	0303 * 16 + c_timming_a,	CPU_EN | (0303 * 16 + c_timming_b),	// 155
	0304 * 16 + c_timming_a,	CPU_EN | (0304 * 16 + c_timming_b),	// 156
	0305 * 16 + c_timming_a,	CPU_EN | (0305 * 16 + c_timming_b),	// 157
	0306 * 16 + c_timming_a,	CPU_EN | (0306 * 16 + c_timming_b),	// 158
	0307 * 16 + c_timming_a,	CPU_EN | (0307 * 16 + c_timming_b),	// 159

	0310 * 16 + c_timming_a,	CPU_EN | (0310 * 16 + c_timming_b),	// 160
	0311 * 16 + c_timming_a,	CPU_EN | (0311 * 16 + c_timming_b),	// 161
	0312 * 16 + c_timming_a,	CPU_EN | (0312 * 16 + c_timming_b),	// 162
	0313 * 16 + c_timming_a,	CPU_EN | (0313 * 16 + c_timming_b),	// 163
	0314 * 16 + c_timming_a,	CPU_EN | (0314 * 16 + c_timming_b),	// 164
	0315 * 16 + c_timming_a,	CPU_EN | (0315 * 16 + c_timming_b),	// 165
	0316 * 16 + c_timming_a,	CPU_EN | (0316 * 16 + c_timming_b),	// 166
	0317 * 16 + c_timming_a,	CPU_EN | (0317 * 16 + c_timming_b),	// 167

	0320 * 16 + c_timming_a,	CPU_EN | (0320 * 16 + c_timming_b),	// 168
	0321 * 16 + c_timming_a,	CPU_EN | (0321 * 16 + c_timming_b),	// 169
	0322 * 16 + c_timming_a,	CPU_EN | (0322 * 16 + c_timming_b),	// 170
	0323 * 16 + c_timming_a,	CPU_EN | (0323 * 16 + c_timming_b),	// 171
	0324 * 16 + c_timming_a,	CPU_EN | (0324 * 16 + c_timming_b),	// 172
	0325 * 16 + c_timming_a,	CPU_EN | (0325 * 16 + c_timming_b),	// 173
	0326 * 16 + c_timming_a,	CPU_EN | (0326 * 16 + c_timming_b),	// 174
	0327 * 16 + c_timming_a,	CPU_EN | (0327 * 16 + c_timming_b),	// 175

	0330 * 16 + c_timming_a,	CPU_EN | (0330 * 16 + c_timming_b),	// 176
	0331 * 16 + c_timming_a,	CPU_EN | (0331 * 16 + c_timming_b),	// 177
	0332 * 16 + c_timming_a,	CPU_EN | (0332 * 16 + c_timming_b),	// 178
	0333 * 16 + c_timming_a,	CPU_EN | (0333 * 16 + c_timming_b),	// 179
	0334 * 16 + c_timming_a,	CPU_EN | (0334 * 16 + c_timming_b),	// 180
	0335 * 16 + c_timming_a,	CPU_EN | (0335 * 16 + c_timming_b),	// 181
	0336 * 16 + c_timming_a,	CPU_EN | (0336 * 16 + c_timming_b),	// 182
	0337 * 16 + c_timming_a,	CPU_EN | (0337 * 16 + c_timming_b),	// 183

	0340 * 16 + c_timming_a,	CPU_EN | (0340 * 16 + c_timming_b),	// 184
	0341 * 16 + c_timming_a,	CPU_EN | (0341 * 16 + c_timming_b),	// 185
	0342 * 16 + c_timming_a,	CPU_EN | (0342 * 16 + c_timming_b),	// 186
	0343 * 16 + c_timming_a,	CPU_EN | (0343 * 16 + c_timming_b),	// 187
	0344 * 16 + c_timming_a,	CPU_EN | (0344 * 16 + c_timming_b),	// 188
	0345 * 16 + c_timming_a,	CPU_EN | (0345 * 16 + c_timming_b),	// 189
	0346 * 16 + c_timming_a,	CPU_EN | (0346 * 16 + c_timming_b),	// 190
	0347 * 16 + c_timming_a,	CPU_EN | (0347 * 16 + c_timming_b),	// 191

	0350 * 16 + c_timming_a,	CPU_EN | (0350 * 16 + c_timming_b),	// 192
	0351 * 16 + c_timming_a,	CPU_EN | (0351 * 16 + c_timming_b),	// 193
	0352 * 16 + c_timming_a,	CPU_EN | (0352 * 16 + c_timming_b),	// 194
	0353 * 16 + c_timming_a,	CPU_EN | (0353 * 16 + c_timming_b),	// 195
	0354 * 16 + c_timming_a,	CPU_EN | (0354 * 16 + c_timming_b),	// 196
	0355 * 16 + c_timming_a,	CPU_EN | (0355 * 16 + c_timming_b),	// 197
	0356 * 16 + c_timming_a,	CPU_EN | (0356 * 16 + c_timming_b),	// 198
	0357 * 16 + c_timming_a,	CPU_EN | (0357 * 16 + c_timming_b),	// 199

	0360 * 16 + c_timming_a,	CPU_EN | (0360 * 16 + c_timming_b),	// 200
	0361 * 16 + c_timming_a,	CPU_EN | (0361 * 16 + c_timming_b),	// 201
	0362 * 16 + c_timming_a,	CPU_EN | (0362 * 16 + c_timming_b),	// 202
	0363 * 16 + c_timming_a,	CPU_EN | (0363 * 16 + c_timming_b),	// 203
	0364 * 16 + c_timming_a,	CPU_EN | (0364 * 16 + c_timming_b),	// 204
	0365 * 16 + c_timming_a,	CPU_EN | (0365 * 16 + c_timming_b),	// 205
	0366 * 16 + c_timming_a,	CPU_EN | (0366 * 16 + c_timming_b),	// 206
	0367 * 16 + c_timming_a,	CPU_EN | (0367 * 16 + c_timming_b),	// 207

	0370 * 16 + c_timming_a,	CPU_EN | (0370 * 16 + c_timming_b),	// 208
	0371 * 16 + c_timming_a,	CPU_EN | (0371 * 16 + c_timming_b),	// 209
	0372 * 16 + c_timming_a,	CPU_EN | (0372 * 16 + c_timming_b),	// 210
	0373 * 16 + c_timming_a,	CPU_EN | (0373 * 16 + c_timming_b),	// 211
	0374 * 16 + c_timming_a,	CPU_EN | (0374 * 16 + c_timming_b),	// 212
	0375 * 16 + c_timming_a,	CPU_EN | (0375 * 16 + c_timming_b),	// 213
	0376 * 16 + c_timming_a,	CPU_EN | (0376 * 16 + c_timming_b),	// 214
	0377 * 16 + c_timming_a,	CPU_EN | (0377 * 16 + c_timming_b),	// 215

	0400 * 16 + c_timming_a,	CPU_EN | (0400 * 16 + c_timming_b),	// 216
	0401 * 16 + c_timming_a,	CPU_EN | (0401 * 16 + c_timming_b),	// 217
	0402 * 16 + c_timming_a,	CPU_EN | (0402 * 16 + c_timming_b),	// 218
	0403 * 16 + c_timming_a,	CPU_EN | (0403 * 16 + c_timming_b),	// 219
	0404 * 16 + c_timming_a,	CPU_EN | (0404 * 16 + c_timming_b),	// 220
	0405 * 16 + c_timming_a,	CPU_EN | (0405 * 16 + c_timming_b),	// 221
	0406 * 16 + c_timming_a,	CPU_EN | (0406 * 16 + c_timming_b),	// 222
	0407 * 16 + c_timming_a,	CPU_EN | (0407 * 16 + c_timming_b),	// 223

	0410 * 16 + c_timming_a,	CPU_EN | (0410 * 16 + c_timming_b),	// 224
	0411 * 16 + c_timming_a,	CPU_EN | (0411 * 16 + c_timming_b),	// 225
	0412 * 16 + c_timming_a,	CPU_EN | (0412 * 16 + c_timming_b),	// 226
	0413 * 16 + c_timming_a,	CPU_EN | (0413 * 16 + c_timming_b),	// 227
	0414 * 16 + c_timming_a,	CPU_EN | (0414 * 16 + c_timming_b),	// 228
	0415 * 16 + c_timming_a,	CPU_EN | (0415 * 16 + c_timming_b),	// 229
	0416 * 16 + c_timming_a,	CPU_EN | (0416 * 16 + c_timming_b),	// 230
	0417 * 16 + c_timming_a,	CPU_EN | (0417 * 16 + c_timming_b),	// 231

	0420 * 16 + c_timming_a,	CPU_EN | (0420 * 16 + c_timming_b),	// 232
	0421 * 16 + c_timming_a,	CPU_EN | (0421 * 16 + c_timming_b),	// 233
	0422 * 16 + c_timming_a,	CPU_EN | (0422 * 16 + c_timming_b),	// 234
	0423 * 16 + c_timming_a,	CPU_EN | (0423 * 16 + c_timming_b),	// 235
	0424 * 16 + c_timming_a,	CPU_EN | (0424 * 16 + c_timming_b),	// 236
	0425 * 16 + c_timming_a,	CPU_EN | (0425 * 16 + c_timming_b),	// 237
	0426 * 16 + c_timming_a,	CPU_EN | (0426 * 16 + c_timming_b),	// 238
	0427 * 16 + c_timming_a,	CPU_EN | (0427 * 16 + c_timming_b),	// 239

	0430 * 16 + c_timming_a,	CPU_EN | (0430 * 16 + c_timming_b),	// 240
	0431 * 16 + c_timming_a,	CPU_EN | (0431 * 16 + c_timming_b),	// 241
	0432 * 16 + c_timming_a,	CPU_EN | (0432 * 16 + c_timming_b),	// 242
	0433 * 16 + c_timming_a,	CPU_EN | (0433 * 16 + c_timming_b),	// 243
	0434 * 16 + c_timming_a,	CPU_EN | (0434 * 16 + c_timming_b),	// 244
	0435 * 16 + c_timming_a,	CPU_EN | (0435 * 16 + c_timming_b),	// 245
	0436 * 16 + c_timming_a,	CPU_EN | (0436 * 16 + c_timming_b),	// 246
	0437 * 16 + c_timming_a,	CPU_EN | (0437 * 16 + c_timming_b),	// 247

	0440 * 16 + c_timming_a,	CPU_EN | (0440 * 16 + c_timming_b),	// 248
	0441 * 16 + c_timming_a,	CPU_EN | (0441 * 16 + c_timming_b),	// 249
	0442 * 16 + c_timming_a,	CPU_EN | (0442 * 16 + c_timming_b),	// 250
	0443 * 16 + c_timming_a,	CPU_EN | (0443 * 16 + c_timming_b),	// 251
	0444 * 16 + c_timming_a,	CPU_EN | (0444 * 16 + c_timming_b),	// 252
	0445 * 16 + c_timming_a,	CPU_EN | (0445 * 16 + c_timming_b),	// 253
	0446 * 16 + c_timming_a,	CPU_EN | (0446 * 16 + c_timming_b),	// 254
	0447 * 16 + c_timming_a,	CPU_EN | (0447 * 16 + c_timming_b),	// 255

	0450 * 16 + c_timming_a,	CPU_EN | (0450 * 16 + c_timming_b),	// 256
	0451 * 16 + c_timming_a,	CPU_EN | (0451 * 16 + c_timming_b),	// 257
	0452 * 16 + c_timming_a,	CPU_EN | (0452 * 16 + c_timming_b),	// 258
	0453 * 16 + c_timming_a,	CPU_EN | (0453 * 16 + c_timming_b),	// 259
	0454 * 16 + c_timming_a,	CPU_EN | (0454 * 16 + c_timming_b),	// 260
	0455 * 16 + c_timming_a,	CPU_EN | (0455 * 16 + c_timming_b),	// 261
	0456 * 16 + c_timming_a,	CPU_EN | (0456 * 16 + c_timming_b),	// 262
	0457 * 16 + c_timming_a,	CPU_EN | (0457 * 16 + c_timming_b),	// 263

	0460 * 16 + c_timming_a,	CPU_EN | (0460 * 16 + c_timming_b),	// 264
	0461 * 16 + c_timming_a,	CPU_EN | (0461 * 16 + c_timming_b),	// 265
	0462 * 16 + c_timming_a,	CPU_EN | (0462 * 16 + c_timming_b),	// 266
	0463 * 16 + c_timming_a,	CPU_EN | (0463 * 16 + c_timming_b),	// 267
	0464 * 16 + c_timming_a,	CPU_EN | (0464 * 16 + c_timming_b),	// 268
	0465 * 16 + c_timming_a,	CPU_EN | (0465 * 16 + c_timming_b),	// 269
	0466 * 16 + c_timming_a,	CPU_EN | (0466 * 16 + c_timming_b),	// 270
	0467 * 16 + c_timming_a,	CPU_EN | (0467 * 16 + c_timming_b),	// 271

	0470 * 16 + c_timming_a,	CPU_EN | (0470 * 16 + c_timming_b),	// 272
	0471 * 16 + c_timming_a,	CPU_EN | (0471 * 16 + c_timming_b),	// 273
	0472 * 16 + c_timming_a,	CPU_EN | (0472 * 16 + c_timming_b),	// 274
	0473 * 16 + c_timming_a,	CPU_EN | (0473 * 16 + c_timming_b),	// 275
	0474 * 16 + c_timming_a,	CPU_EN | (0474 * 16 + c_timming_b),	// 276
	0475 * 16 + c_timming_a,	CPU_EN | (0475 * 16 + c_timming_b),	// 277
	0476 * 16 + c_timming_a,	CPU_EN | (0476 * 16 + c_timming_b),	// 278
	0477 * 16 + c_timming_a,	CPU_EN | (0477 * 16 + c_timming_b),	// 279

	0500 * 16 + c_timming_a,	CPU_EN | (0500 * 16 + c_timming_b),	// 280
	0501 * 16 + c_timming_a,	CPU_EN | (0501 * 16 + c_timming_b),	// 281
	0502 * 16 + c_timming_a,	CPU_EN | (0502 * 16 + c_timming_b),	// 282
	0503 * 16 + c_timming_a,	CPU_EN | (0503 * 16 + c_timming_b),	// 283
	0504 * 16 + c_timming_a,	CPU_EN | (0504 * 16 + c_timming_b),	// 284
	0505 * 16 + c_timming_a,	CPU_EN | (0505 * 16 + c_timming_b),	// 285
	0506 * 16 + c_timming_a,	CPU_EN | (0506 * 16 + c_timming_b),	// 286
	0507 * 16 + c_timming_a,	CPU_EN | (0507 * 16 + c_timming_b),	// 287

	0510 * 16 + c_timming_a,	CPU_EN | (0510 * 16 + c_timming_b),	// 288
	0511 * 16 + c_timming_a,	CPU_EN | (0511 * 16 + c_timming_b),	// 289
	0512 * 16 + c_timming_a,	CPU_EN | (0512 * 16 + c_timming_b),	// 290
	0513 * 16 + c_timming_a,	CPU_EN | (0513 * 16 + c_timming_b),	// 291
	0514 * 16 + c_timming_a,	CPU_EN | (0514 * 16 + c_timming_b),	// 292
	0515 * 16 + c_timming_a,	CPU_EN | (0515 * 16 + c_timming_b),	// 293
	0516 * 16 + c_timming_a,	CPU_EN | (0516 * 16 + c_timming_b),	// 294
	0517 * 16 + c_timming_a,	CPU_EN | (0517 * 16 + c_timming_b),	// 295

	0520 * 16 + c_timming_a,	CPU_EN | (0520 * 16 + c_timming_b),	// 296
	0521 * 16 + c_timming_a,	CPU_EN | (0521 * 16 + c_timming_b),	// 297
	0522 * 16 + c_timming_a,	CPU_EN | (0522 * 16 + c_timming_b),	// 298
	0523 * 16 + c_timming_a,	CPU_EN | (0523 * 16 + c_timming_b),	// 299
	0524 * 16 + c_timming_a,	CPU_EN | (0524 * 16 + c_timming_b),	// 300
	0525 * 16 + c_timming_a,	CPU_EN | (0525 * 16 + c_timming_b),	// 301

	0526 * 16 + c_timming_a,	CPU_EN | (0526 * 16 + c_timming_b),	// -40
	0527 * 16 + c_timming_a,	CPU_EN | (0527 * 16 + c_timming_b),	// -39
	0530 * 16 + c_timming_a,	CPU_EN | (0530 * 16 + c_timming_b),	// -38
	0531 * 16 + c_timming_a,	CPU_EN | (0531 * 16 + c_timming_b),	// -37
	0532 * 16 + c_timming_a,	CPU_EN | (0532 * 16 + c_timming_b),	// -36
	0533 * 16 + c_timming_a,	CPU_EN | (0533 * 16 + c_timming_b),	// -35
	0534 * 16 + c_timming_a,	CPU_EN | (0534 * 16 + c_timming_b),	// -34
	0535 * 16 + c_timming_a,	CPU_EN | (0535 * 16 + c_timming_b),	// -33

	/* REFRESH */													// -32
	0537 * 16 + c_timming_a,	CPU_EN | (0537 * 16 + c_timming_b),	// -31
};

// screen0:width40
static constexpr std::array<int16_t, 580> slotsV9968TextLow = {
	0000 * 16 + c_timming_a,	CPU_EN | (0000 * 16 + c_timming_b),	// -42
	0001 * 16 + c_timming_a,	CPU_EN | (0001 * 16 + c_timming_b),	// -41
	0002 * 16 + c_timming_a,	CPU_EN | (0002 * 16 + c_timming_b),	// -40
	0003 * 16 + c_timming_a,	CPU_EN | (0003 * 16 + c_timming_b),	// -39
	0004 * 16 + c_timming_a,	CPU_EN | (0004 * 16 + c_timming_b),	// -38
	0005 * 16 + c_timming_a,	CPU_EN | (0005 * 16 + c_timming_b),	// -37

	0006 * 16 + c_timming_a,	CPU_EN | (0006 * 16 + c_timming_b),	// -36
	0007 * 16 + c_timming_a,	CPU_EN | (0007 * 16 + c_timming_b),	// -35
	/* REFRESH */													// -34
	0011 * 16 + c_timming_a,	CPU_EN | (0011 * 16 + c_timming_b),	// -33
	0012 * 16 + c_timming_a,	CPU_EN | (0012 * 16 + c_timming_b),	// -32
	0013 * 16 + c_timming_a,	CPU_EN | (0013 * 16 + c_timming_b),	// -31

	0014 * 16 + c_timming_a,	CPU_EN | (0014 * 16 + c_timming_b),	// -30
	0015 * 16 + c_timming_a,	CPU_EN | (0015 * 16 + c_timming_b),	// -29
	0016 * 16 + c_timming_a,	CPU_EN | (0016 * 16 + c_timming_b),	// -28
	0017 * 16 + c_timming_a,	CPU_EN | (0017 * 16 + c_timming_b),	// -27
	0020 * 16 + c_timming_a,	CPU_EN | (0020 * 16 + c_timming_b),	// -26
	0021 * 16 + c_timming_a,	CPU_EN | (0021 * 16 + c_timming_b),	// -25

	0022 * 16 + c_timming_a,	CPU_EN | (0022 * 16 + c_timming_b),	// -24
	0023 * 16 + c_timming_a,	CPU_EN | (0023 * 16 + c_timming_b),	// -23
	0024 * 16 + c_timming_a,	CPU_EN | (0024 * 16 + c_timming_b),	// -22
	0025 * 16 + c_timming_a,	CPU_EN | (0025 * 16 + c_timming_b),	// -21
	0026 * 16 + c_timming_a,	CPU_EN | (0026 * 16 + c_timming_b),	// -20
	0027 * 16 + c_timming_a,	CPU_EN | (0027 * 16 + c_timming_b),	// -19

	0030 * 16 + c_timming_a,	CPU_EN | (0030 * 16 + c_timming_b),	// -18
	0031 * 16 + c_timming_a,	CPU_EN | (0031 * 16 + c_timming_b),	// -17
	0032 * 16 + c_timming_a,	CPU_EN | (0032 * 16 + c_timming_b),	// -16
	0033 * 16 + c_timming_a,	CPU_EN | (0033 * 16 + c_timming_b),	// -15
	0034 * 16 + c_timming_a,	CPU_EN | (0034 * 16 + c_timming_b),	// -14
	0035 * 16 + c_timming_a,	CPU_EN | (0035 * 16 + c_timming_b),	// -13

	0036 * 16 + c_timming_a,	CPU_EN | (0036 * 16 + c_timming_b),	// -12
	0037 * 16 + c_timming_a,	CPU_EN | (0037 * 16 + c_timming_b),	// -11
	0040 * 16 + c_timming_a,	CPU_EN | (0040 * 16 + c_timming_b),	// -10
	0041 * 16 + c_timming_a,	CPU_EN | (0041 * 16 + c_timming_b),	// -9
	0042 * 16 + c_timming_a,	CPU_EN | (0042 * 16 + c_timming_b),	// -8
	0043 * 16 + c_timming_a,	CPU_EN | (0043 * 16 + c_timming_b),	// -7

	/* NAME */					CPU_EN | (0044 * 16 + c_timming_b),	// -6
	/* PATTERN */				CPU_EN | (0045 * 16 + c_timming_b),	// -5
	0046 * 16 + c_timming_a,	CPU_EN | (0046 * 16 + c_timming_b),	// -4
	/* COLOR */					CPU_EN | (0047 * 16 + c_timming_b),	// -3
	0050 * 16 + c_timming_a,	CPU_EN | (0050 * 16 + c_timming_b),	// -2
	0051 * 16 + c_timming_a,	CPU_EN | (0051 * 16 + c_timming_b),	// -1

	/* NAME */					CPU_EN | (0052 * 16 + c_timming_b),	// 0
	/* PATTERN */				CPU_EN | (0053 * 16 + c_timming_b),	// 1
	0054 * 16 + c_timming_a,	CPU_EN | (0054 * 16 + c_timming_b),	// 2
	/* COLOR */					CPU_EN | (0055 * 16 + c_timming_b),	// 3
	0056 * 16 + c_timming_a,	CPU_EN | (0056 * 16 + c_timming_b),	// 4
	0057 * 16 + c_timming_a,	CPU_EN | (0057 * 16 + c_timming_b),	// 5

	/* NAME */					CPU_EN | (0060 * 16 + c_timming_b),	// 6
	/* PATTERN */				CPU_EN | (0061 * 16 + c_timming_b),	// 7
	0062 * 16 + c_timming_a,	CPU_EN | (0062 * 16 + c_timming_b),	// 8
	/* COLOR */					CPU_EN | (0063 * 16 + c_timming_b),	// 9
	0064 * 16 + c_timming_a,	CPU_EN | (0064 * 16 + c_timming_b),	// 10
	0065 * 16 + c_timming_a,	CPU_EN | (0065 * 16 + c_timming_b),	// 11

	/* NAME */					CPU_EN | (0066 * 16 + c_timming_b),	// 12
	/* PATTERN */				CPU_EN | (0067 * 16 + c_timming_b),	// 13
	0070 * 16 + c_timming_a,	CPU_EN | (0070 * 16 + c_timming_b),	// 14
	/* COLOR */					CPU_EN | (0071 * 16 + c_timming_b),	// 15
	0072 * 16 + c_timming_a,	CPU_EN | (0072 * 16 + c_timming_b),	// 16
	0073 * 16 + c_timming_a,	CPU_EN | (0073 * 16 + c_timming_b),	// 17

	/* NAME */					CPU_EN | (0074 * 16 + c_timming_b),	// 18
	/* PATTERN */				CPU_EN | (0075 * 16 + c_timming_b),	// 19
	0076 * 16 + c_timming_a,	CPU_EN | (0076 * 16 + c_timming_b),	// 20
	/* COLOR */					CPU_EN | (0077 * 16 + c_timming_b),	// 21
	0100 * 16 + c_timming_a,	CPU_EN | (0100 * 16 + c_timming_b),	// 22
	0101 * 16 + c_timming_a,	CPU_EN | (0101 * 16 + c_timming_b),	// 23

	/* NAME */					CPU_EN | (0102 * 16 + c_timming_b),	// 24
	/* PATTERN */				CPU_EN | (0103 * 16 + c_timming_b),	// 25
	0104 * 16 + c_timming_a,	CPU_EN | (0104 * 16 + c_timming_b),	// 26
	/* COLOR */					CPU_EN | (0105 * 16 + c_timming_b),	// 27
	0106 * 16 + c_timming_a,	CPU_EN | (0106 * 16 + c_timming_b),	// 28
	0107 * 16 + c_timming_a,	CPU_EN | (0107 * 16 + c_timming_b),	// 29

	/* NAME */					CPU_EN | (0110 * 16 + c_timming_b),	// 30
	/* PATTERN */				CPU_EN | (0111 * 16 + c_timming_b),	// 31
	0112 * 16 + c_timming_a,	CPU_EN | (0112 * 16 + c_timming_b),	// 32
	/* COLOR */					CPU_EN | (0113 * 16 + c_timming_b),	// 33
	0114 * 16 + c_timming_a,	CPU_EN | (0114 * 16 + c_timming_b),	// 34
	0115 * 16 + c_timming_a,	CPU_EN | (0115 * 16 + c_timming_b),	// 35

	/* NAME */					CPU_EN | (0116 * 16 + c_timming_b),	// 36
	/* PATTERN */				CPU_EN | (0117 * 16 + c_timming_b),	// 37
	0120 * 16 + c_timming_a,	CPU_EN | (0120 * 16 + c_timming_b),	// 38
	/* COLOR */					CPU_EN | (0121 * 16 + c_timming_b),	// 39
	0122 * 16 + c_timming_a,	CPU_EN | (0122 * 16 + c_timming_b),	// 40
	0123 * 16 + c_timming_a,	CPU_EN | (0123 * 16 + c_timming_b),	// 41

	/* NAME */					CPU_EN | (0124 * 16 + c_timming_b),	// 42
	/* PATTERN */				CPU_EN | (0125 * 16 + c_timming_b),	// 43
	0126 * 16 + c_timming_a,	CPU_EN | (0126 * 16 + c_timming_b),	// 44
	/* COLOR */					CPU_EN | (0127 * 16 + c_timming_b),	// 45
	0130 * 16 + c_timming_a,	CPU_EN | (0130 * 16 + c_timming_b),	// 46
	0131 * 16 + c_timming_a,	CPU_EN | (0131 * 16 + c_timming_b),	// 47

	/* NAME */					CPU_EN | (0132 * 16 + c_timming_b),	// 48
	/* PATTERN */				CPU_EN | (0133 * 16 + c_timming_b),	// 49
	0134 * 16 + c_timming_a,	CPU_EN | (0134 * 16 + c_timming_b),	// 50
	/* COLOR */					CPU_EN | (0135 * 16 + c_timming_b),	// 51
	0136 * 16 + c_timming_a,	CPU_EN | (0136 * 16 + c_timming_b),	// 52
	0137 * 16 + c_timming_a,	CPU_EN | (0137 * 16 + c_timming_b),	// 53

	/* NAME */					CPU_EN | (0140 * 16 + c_timming_b),	// 54
	/* PATTERN */				CPU_EN | (0141 * 16 + c_timming_b),	// 55
	0142 * 16 + c_timming_a,	CPU_EN | (0142 * 16 + c_timming_b),	// 56
	/* COLOR */					CPU_EN | (0143 * 16 + c_timming_b),	// 57
	0144 * 16 + c_timming_a,	CPU_EN | (0144 * 16 + c_timming_b),	// 58
	0145 * 16 + c_timming_a,	CPU_EN | (0145 * 16 + c_timming_b),	// 59

	/* NAME */					CPU_EN | (0146 * 16 + c_timming_b),	// 60
	/* PATTERN */				CPU_EN | (0147 * 16 + c_timming_b),	// 61
	0150 * 16 + c_timming_a,	CPU_EN | (0150 * 16 + c_timming_b),	// 62
	/* COLOR */					CPU_EN | (0151 * 16 + c_timming_b),	// 63
	0152 * 16 + c_timming_a,	CPU_EN | (0152 * 16 + c_timming_b),	// 64
	0153 * 16 + c_timming_a,	CPU_EN | (0153 * 16 + c_timming_b),	// 65

	/* NAME */					CPU_EN | (0154 * 16 + c_timming_b),	// 66
	/* PATTERN */				CPU_EN | (0155 * 16 + c_timming_b),	// 67
	0156 * 16 + c_timming_a,	CPU_EN | (0156 * 16 + c_timming_b),	// 68
	/* COLOR */					CPU_EN | (0157 * 16 + c_timming_b),	// 69
	0160 * 16 + c_timming_a,	CPU_EN | (0160 * 16 + c_timming_b),	// 70
	0161 * 16 + c_timming_a,	CPU_EN | (0161 * 16 + c_timming_b),	// 71

	/* NAME */					CPU_EN | (0162 * 16 + c_timming_b),	// 72
	/* PATTERN */				CPU_EN | (0163 * 16 + c_timming_b),	// 73
	0164 * 16 + c_timming_a,	CPU_EN | (0164 * 16 + c_timming_b),	// 74
	/* COLOR */					CPU_EN | (0165 * 16 + c_timming_b),	// 75
	0166 * 16 + c_timming_a,	CPU_EN | (0166 * 16 + c_timming_b),	// 76
	0167 * 16 + c_timming_a,	CPU_EN | (0167 * 16 + c_timming_b),	// 77

	/* NAME */					CPU_EN | (0170 * 16 + c_timming_b),	// 78
	/* PATTERN */				CPU_EN | (0171 * 16 + c_timming_b),	// 79
	0172 * 16 + c_timming_a,	CPU_EN | (0172 * 16 + c_timming_b),	// 80
	/* COLOR */					CPU_EN | (0173 * 16 + c_timming_b),	// 81
	0174 * 16 + c_timming_a,	CPU_EN | (0174 * 16 + c_timming_b),	// 82
	0175 * 16 + c_timming_a,	CPU_EN | (0175 * 16 + c_timming_b),	// 83

	/* NAME */					CPU_EN | (0176 * 16 + c_timming_b),	// 84
	/* PATTERN */				CPU_EN | (0177 * 16 + c_timming_b),	// 85
	0200 * 16 + c_timming_a,	CPU_EN | (0200 * 16 + c_timming_b),	// 86
	/* COLOR */					CPU_EN | (0201 * 16 + c_timming_b),	// 87
	0202 * 16 + c_timming_a,	CPU_EN | (0202 * 16 + c_timming_b),	// 88
	0203 * 16 + c_timming_a,	CPU_EN | (0203 * 16 + c_timming_b),	// 89

	/* NAME */					CPU_EN | (0204 * 16 + c_timming_b),	// 90
	/* PATTERN */				CPU_EN | (0205 * 16 + c_timming_b),	// 91
	0206 * 16 + c_timming_a,	CPU_EN | (0206 * 16 + c_timming_b),	// 92
	/* COLOR */					CPU_EN | (0207 * 16 + c_timming_b),	// 93
	0210 * 16 + c_timming_a,	CPU_EN | (0210 * 16 + c_timming_b),	// 94
	0211 * 16 + c_timming_a,	CPU_EN | (0211 * 16 + c_timming_b),	// 95

	/* NAME */					CPU_EN | (0212 * 16 + c_timming_b),	// 96
	/* PATTERN */				CPU_EN | (0213 * 16 + c_timming_b),	// 97
	0214 * 16 + c_timming_a,	CPU_EN | (0214 * 16 + c_timming_b),	// 98
	/* COLOR */					CPU_EN | (0215 * 16 + c_timming_b),	// 99
	0216 * 16 + c_timming_a,	CPU_EN | (0216 * 16 + c_timming_b),	// 100
	0217 * 16 + c_timming_a,	CPU_EN | (0217 * 16 + c_timming_b),	// 101

	/* NAME */					CPU_EN | (0220 * 16 + c_timming_b),	// 102
	/* PATTERN */				CPU_EN | (0221 * 16 + c_timming_b),	// 103
	0222 * 16 + c_timming_a,	CPU_EN | (0222 * 16 + c_timming_b),	// 104
	/* COLOR */					CPU_EN | (0223 * 16 + c_timming_b),	// 105
	0224 * 16 + c_timming_a,	CPU_EN | (0224 * 16 + c_timming_b),	// 106
	0225 * 16 + c_timming_a,	CPU_EN | (0225 * 16 + c_timming_b),	// 107

	/* NAME */					CPU_EN | (0226 * 16 + c_timming_b),	// 108
	/* PATTERN */				CPU_EN | (0227 * 16 + c_timming_b),	// 109
	0230 * 16 + c_timming_a,	CPU_EN | (0230 * 16 + c_timming_b),	// 110
	/* COLOR */					CPU_EN | (0231 * 16 + c_timming_b),	// 111
	0232 * 16 + c_timming_a,	CPU_EN | (0232 * 16 + c_timming_b),	// 112
	0233 * 16 + c_timming_a,	CPU_EN | (0233 * 16 + c_timming_b),	// 113

	/* NAME */					CPU_EN | (0234 * 16 + c_timming_b),	// 114
	/* PATTERN */				CPU_EN | (0235 * 16 + c_timming_b),	// 115
	0236 * 16 + c_timming_a,	CPU_EN | (0236 * 16 + c_timming_b),	// 116
	/* COLOR */					CPU_EN | (0237 * 16 + c_timming_b),	// 117
	0240 * 16 + c_timming_a,	CPU_EN | (0240 * 16 + c_timming_b),	// 118
	0241 * 16 + c_timming_a,	CPU_EN | (0241 * 16 + c_timming_b),	// 119

	/* NAME */					CPU_EN | (0242 * 16 + c_timming_b),	// 120
	/* PATTERN */				CPU_EN | (0243 * 16 + c_timming_b),	// 121
	0244 * 16 + c_timming_a,	CPU_EN | (0244 * 16 + c_timming_b),	// 122
	/* COLOR */					CPU_EN | (0245 * 16 + c_timming_b),	// 123
	0246 * 16 + c_timming_a,	CPU_EN | (0246 * 16 + c_timming_b),	// 124
	0247 * 16 + c_timming_a,	CPU_EN | (0247 * 16 + c_timming_b),	// 125

	/* NAME */					CPU_EN | (0250 * 16 + c_timming_b),	// 126
	/* PATTERN */				CPU_EN | (0251 * 16 + c_timming_b),	// 127
	0252 * 16 + c_timming_a,	CPU_EN | (0252 * 16 + c_timming_b),	// 128
	/* COLOR */					CPU_EN | (0253 * 16 + c_timming_b),	// 129
	0254 * 16 + c_timming_a,	CPU_EN | (0254 * 16 + c_timming_b),	// 130
	0255 * 16 + c_timming_a,	CPU_EN | (0255 * 16 + c_timming_b),	// 131

	/* NAME */					CPU_EN | (0256 * 16 + c_timming_b),	// 132
	/* PATTERN */				CPU_EN | (0257 * 16 + c_timming_b),	// 133
	0260 * 16 + c_timming_a,	CPU_EN | (0260 * 16 + c_timming_b),	// 134
	/* COLOR */					CPU_EN | (0261 * 16 + c_timming_b),	// 135
	0262 * 16 + c_timming_a,	CPU_EN | (0262 * 16 + c_timming_b),	// 136
	0263 * 16 + c_timming_a,	CPU_EN | (0263 * 16 + c_timming_b),	// 137

	/* NAME */					CPU_EN | (0264 * 16 + c_timming_b),	// 138
	/* PATTERN */				CPU_EN | (0265 * 16 + c_timming_b),	// 139
	0266 * 16 + c_timming_a,	CPU_EN | (0266 * 16 + c_timming_b),	// 140
	/* COLOR */					CPU_EN | (0267 * 16 + c_timming_b),	// 141
	0270 * 16 + c_timming_a,	CPU_EN | (0270 * 16 + c_timming_b),	// 142
	0271 * 16 + c_timming_a,	CPU_EN | (0271 * 16 + c_timming_b),	// 143

	/* NAME */					CPU_EN | (0272 * 16 + c_timming_b),	// 144
	/* PATTERN */				CPU_EN | (0273 * 16 + c_timming_b),	// 145
	0274 * 16 + c_timming_a,	CPU_EN | (0274 * 16 + c_timming_b),	// 146
	/* COLOR */					CPU_EN | (0275 * 16 + c_timming_b),	// 147
	0276 * 16 + c_timming_a,	CPU_EN | (0276 * 16 + c_timming_b),	// 148
	0277 * 16 + c_timming_a,	CPU_EN | (0277 * 16 + c_timming_b),	// 149

	/* NAME */					CPU_EN | (0300 * 16 + c_timming_b),	// 150
	/* PATTERN */				CPU_EN | (0301 * 16 + c_timming_b),	// 151
	0302 * 16 + c_timming_a,	CPU_EN | (0302 * 16 + c_timming_b),	// 152
	/* COLOR */					CPU_EN | (0303 * 16 + c_timming_b),	// 153
	0304 * 16 + c_timming_a,	CPU_EN | (0304 * 16 + c_timming_b),	// 154
	0305 * 16 + c_timming_a,	CPU_EN | (0305 * 16 + c_timming_b),	// 155

	/* NAME */					CPU_EN | (0306 * 16 + c_timming_b),	// 156
	/* PATTERN */				CPU_EN | (0307 * 16 + c_timming_b),	// 157
	0310 * 16 + c_timming_a,	CPU_EN | (0310 * 16 + c_timming_b),	// 158
	/* COLOR */					CPU_EN | (0311 * 16 + c_timming_b),	// 159
	0312 * 16 + c_timming_a,	CPU_EN | (0312 * 16 + c_timming_b),	// 160
	0313 * 16 + c_timming_a,	CPU_EN | (0313 * 16 + c_timming_b),	// 161

	/* NAME */					CPU_EN | (0314 * 16 + c_timming_b),	// 162
	/* PATTERN */				CPU_EN | (0315 * 16 + c_timming_b),	// 163
	0316 * 16 + c_timming_a,	CPU_EN | (0316 * 16 + c_timming_b),	// 164
	/* COLOR */					CPU_EN | (0317 * 16 + c_timming_b),	// 165
	0320 * 16 + c_timming_a,	CPU_EN | (0320 * 16 + c_timming_b),	// 166
	0321 * 16 + c_timming_a,	CPU_EN | (0321 * 16 + c_timming_b),	// 167

	/* NAME */					CPU_EN | (0322 * 16 + c_timming_b),	// 168
	/* PATTERN */				CPU_EN | (0323 * 16 + c_timming_b),	// 169
	0324 * 16 + c_timming_a,	CPU_EN | (0324 * 16 + c_timming_b),	// 170
	/* COLOR */					CPU_EN | (0325 * 16 + c_timming_b),	// 171
	0326 * 16 + c_timming_a,	CPU_EN | (0326 * 16 + c_timming_b),	// 172
	0327 * 16 + c_timming_a,	CPU_EN | (0327 * 16 + c_timming_b),	// 173

	/* NAME */					CPU_EN | (0330 * 16 + c_timming_b),	// 174
	/* PATTERN */				CPU_EN | (0331 * 16 + c_timming_b),	// 175
	0332 * 16 + c_timming_a,	CPU_EN | (0332 * 16 + c_timming_b),	// 176
	/* COLOR */					CPU_EN | (0333 * 16 + c_timming_b),	// 177
	0334 * 16 + c_timming_a,	CPU_EN | (0334 * 16 + c_timming_b),	// 178
	0335 * 16 + c_timming_a,	CPU_EN | (0335 * 16 + c_timming_b),	// 179

	/* NAME */					CPU_EN | (0336 * 16 + c_timming_b),	// 180
	/* PATTERN */				CPU_EN | (0337 * 16 + c_timming_b),	// 181
	0340 * 16 + c_timming_a,	CPU_EN | (0340 * 16 + c_timming_b),	// 182
	/* COLOR */					CPU_EN | (0341 * 16 + c_timming_b),	// 183
	0342 * 16 + c_timming_a,	CPU_EN | (0342 * 16 + c_timming_b),	// 184
	0343 * 16 + c_timming_a,	CPU_EN | (0343 * 16 + c_timming_b),	// 185

	/* NAME */					CPU_EN | (0344 * 16 + c_timming_b),	// 186
	/* PATTERN */				CPU_EN | (0345 * 16 + c_timming_b),	// 187
	0346 * 16 + c_timming_a,	CPU_EN | (0346 * 16 + c_timming_b),	// 188
	/* COLOR */					CPU_EN | (0347 * 16 + c_timming_b),	// 189
	0350 * 16 + c_timming_a,	CPU_EN | (0350 * 16 + c_timming_b),	// 190
	0351 * 16 + c_timming_a,	CPU_EN | (0351 * 16 + c_timming_b),	// 191

	/* NAME */					CPU_EN | (0352 * 16 + c_timming_b),	// 192
	/* PATTERN */				CPU_EN | (0353 * 16 + c_timming_b),	// 193
	0354 * 16 + c_timming_a,	CPU_EN | (0354 * 16 + c_timming_b),	// 194
	/* COLOR */					CPU_EN | (0355 * 16 + c_timming_b),	// 195
	0356 * 16 + c_timming_a,	CPU_EN | (0356 * 16 + c_timming_b),	// 196
	0357 * 16 + c_timming_a,	CPU_EN | (0357 * 16 + c_timming_b),	// 197

	/* NAME */					CPU_EN | (0360 * 16 + c_timming_b),	// 198
	/* PATTERN */				CPU_EN | (0361 * 16 + c_timming_b),	// 199
	0362 * 16 + c_timming_a,	CPU_EN | (0362 * 16 + c_timming_b),	// 200
	/* COLOR */					CPU_EN | (0363 * 16 + c_timming_b),	// 201
	0364 * 16 + c_timming_a,	CPU_EN | (0364 * 16 + c_timming_b),	// 202
	0365 * 16 + c_timming_a,	CPU_EN | (0365 * 16 + c_timming_b),	// 203

	/* NAME */					CPU_EN | (0366 * 16 + c_timming_b),	// 204
	/* PATTERN */				CPU_EN | (0367 * 16 + c_timming_b),	// 205
	0370 * 16 + c_timming_a,	CPU_EN | (0370 * 16 + c_timming_b),	// 206
	/* COLOR */					CPU_EN | (0371 * 16 + c_timming_b),	// 205
	0372 * 16 + c_timming_a,	CPU_EN | (0372 * 16 + c_timming_b),	// 208
	0373 * 16 + c_timming_a,	CPU_EN | (0373 * 16 + c_timming_b),	// 209

	/* NAME */					CPU_EN | (0374 * 16 + c_timming_b),	// 210
	/* PATTERN */				CPU_EN | (0375 * 16 + c_timming_b),	// 211
	0376 * 16 + c_timming_a,	CPU_EN | (0376 * 16 + c_timming_b),	// 212
	/* COLOR */					CPU_EN | (0377 * 16 + c_timming_b),	// 213
	0400 * 16 + c_timming_a,	CPU_EN | (0400 * 16 + c_timming_b),	// 214
	0401 * 16 + c_timming_a,	CPU_EN | (0401 * 16 + c_timming_b),	// 215

	/* NAME */					CPU_EN | (0402 * 16 + c_timming_b),	// 216
	/* PATTERN */				CPU_EN | (0403 * 16 + c_timming_b),	// 217
	0404 * 16 + c_timming_a,	CPU_EN | (0404 * 16 + c_timming_b),	// 218
	/* COLOR */					CPU_EN | (0405 * 16 + c_timming_b),	// 219
	0406 * 16 + c_timming_a,	CPU_EN | (0406 * 16 + c_timming_b),	// 220
	0407 * 16 + c_timming_a,	CPU_EN | (0407 * 16 + c_timming_b),	// 221

	/* NAME */					CPU_EN | (0410 * 16 + c_timming_b),	// 222
	/* PATTERN */				CPU_EN | (0411 * 16 + c_timming_b),	// 223
	0412 * 16 + c_timming_a,	CPU_EN | (0412 * 16 + c_timming_b),	// 224
	/* COLOR */					CPU_EN | (0413 * 16 + c_timming_b),	// 225
	0414 * 16 + c_timming_a,	CPU_EN | (0414 * 16 + c_timming_b),	// 226
	0415 * 16 + c_timming_a,	CPU_EN | (0415 * 16 + c_timming_b),	// 227

	/* NAME */					CPU_EN | (0416 * 16 + c_timming_b),	// 228
	/* PATTERN */				CPU_EN | (0417 * 16 + c_timming_b),	// 229
	0420 * 16 + c_timming_a,	CPU_EN | (0420 * 16 + c_timming_b),	// 230
	/* COLOR */					CPU_EN | (0421 * 16 + c_timming_b),	// 231
	0422 * 16 + c_timming_a,	CPU_EN | (0422 * 16 + c_timming_b),	// 232
	0423 * 16 + c_timming_a,	CPU_EN | (0423 * 16 + c_timming_b),	// 233

	0424 * 16 + c_timming_a,	CPU_EN | (0424 * 16 + c_timming_b),	// 234
	0425 * 16 + c_timming_a,	CPU_EN | (0425 * 16 + c_timming_b),	// 235
	0426 * 16 + c_timming_a,	CPU_EN | (0426 * 16 + c_timming_b),	// 236
	0427 * 16 + c_timming_a,	CPU_EN | (0427 * 16 + c_timming_b),	// 237
	0430 * 16 + c_timming_a,	CPU_EN | (0430 * 16 + c_timming_b),	// 238
	0431 * 16 + c_timming_a,	CPU_EN | (0431 * 16 + c_timming_b),	// 239

	0432 * 16 + c_timming_a,	CPU_EN | (0432 * 16 + c_timming_b),	// 240
	0433 * 16 + c_timming_a,	CPU_EN | (0433 * 16 + c_timming_b),	// 241
	0434 * 16 + c_timming_a,	CPU_EN | (0434 * 16 + c_timming_b),	// 242
	0435 * 16 + c_timming_a,	CPU_EN | (0435 * 16 + c_timming_b),	// 243
	0436 * 16 + c_timming_a,	CPU_EN | (0436 * 16 + c_timming_b),	// 244
	0437 * 16 + c_timming_a,	CPU_EN | (0437 * 16 + c_timming_b),	// 245

	0440 * 16 + c_timming_a,	CPU_EN | (0440 * 16 + c_timming_b),	// 246
	0441 * 16 + c_timming_a,	CPU_EN | (0441 * 16 + c_timming_b),	// 247
	0442 * 16 + c_timming_a,	CPU_EN | (0442 * 16 + c_timming_b),	// 248
	0443 * 16 + c_timming_a,	CPU_EN | (0443 * 16 + c_timming_b),	// 249
	0444 * 16 + c_timming_a,	CPU_EN | (0444 * 16 + c_timming_b),	// 250
	0445 * 16 + c_timming_a,	CPU_EN | (0445 * 16 + c_timming_b),	// 251

	0446 * 16 + c_timming_a,	CPU_EN | (0446 * 16 + c_timming_b),	// 252
	0447 * 16 + c_timming_a,	CPU_EN | (0447 * 16 + c_timming_b),	// 253
	0450 * 16 + c_timming_a,	CPU_EN | (0450 * 16 + c_timming_b),	// 254
	0451 * 16 + c_timming_a,	CPU_EN | (0451 * 16 + c_timming_b),	// 255
	0452 * 16 + c_timming_a,	CPU_EN | (0452 * 16 + c_timming_b),	// 256
	0453 * 16 + c_timming_a,	CPU_EN | (0453 * 16 + c_timming_b),	// 257

	0454 * 16 + c_timming_a,	CPU_EN | (0454 * 16 + c_timming_b),	// 258
	0455 * 16 + c_timming_a,	CPU_EN | (0455 * 16 + c_timming_b),	// 259
	0456 * 16 + c_timming_a,	CPU_EN | (0456 * 16 + c_timming_b),	// 260
	0457 * 16 + c_timming_a,	CPU_EN | (0457 * 16 + c_timming_b),	// 261
	0460 * 16 + c_timming_a,	CPU_EN | (0460 * 16 + c_timming_b),	// 262
	0461 * 16 + c_timming_a,	CPU_EN | (0461 * 16 + c_timming_b),	// 263

	0462 * 16 + c_timming_a,	CPU_EN | (0462 * 16 + c_timming_b),	// 264
	0463 * 16 + c_timming_a,	CPU_EN | (0463 * 16 + c_timming_b),	// 265
	0464 * 16 + c_timming_a,	CPU_EN | (0464 * 16 + c_timming_b),	// 266
	0465 * 16 + c_timming_a,	CPU_EN | (0465 * 16 + c_timming_b),	// 267
	0466 * 16 + c_timming_a,	CPU_EN | (0466 * 16 + c_timming_b),	// 268
	0467 * 16 + c_timming_a,	CPU_EN | (0467 * 16 + c_timming_b),	// 269

	0470 * 16 + c_timming_a,	CPU_EN | (0470 * 16 + c_timming_b),	// 270
	0471 * 16 + c_timming_a,	CPU_EN | (0471 * 16 + c_timming_b),	// 271
	0472 * 16 + c_timming_a,	CPU_EN | (0472 * 16 + c_timming_b),	// 272
	0473 * 16 + c_timming_a,	CPU_EN | (0473 * 16 + c_timming_b),	// 273
	0474 * 16 + c_timming_a,	CPU_EN | (0474 * 16 + c_timming_b),	// 274
	0475 * 16 + c_timming_a,	CPU_EN | (0475 * 16 + c_timming_b),	// 275

	0476 * 16 + c_timming_a,	CPU_EN | (0476 * 16 + c_timming_b),	// 276
	0477 * 16 + c_timming_a,	CPU_EN | (0477 * 16 + c_timming_b),	// 277
	0500 * 16 + c_timming_a,	CPU_EN | (0500 * 16 + c_timming_b),	// 278
	0501 * 16 + c_timming_a,	CPU_EN | (0501 * 16 + c_timming_b),	// 279
	0502 * 16 + c_timming_a,	CPU_EN | (0502 * 16 + c_timming_b),	// 280
	0503 * 16 + c_timming_a,	CPU_EN | (0503 * 16 + c_timming_b),	// 281

	0504 * 16 + c_timming_a,	CPU_EN | (0504 * 16 + c_timming_b),	// 282
	0505 * 16 + c_timming_a,	CPU_EN | (0505 * 16 + c_timming_b),	// 283
	0506 * 16 + c_timming_a,	CPU_EN | (0506 * 16 + c_timming_b),	// 284
	0507 * 16 + c_timming_a,	CPU_EN | (0507 * 16 + c_timming_b),	// 285
	0510 * 16 + c_timming_a,	CPU_EN | (0510 * 16 + c_timming_b),	// 286
	0511 * 16 + c_timming_a,	CPU_EN | (0511 * 16 + c_timming_b),	// 287

	0512 * 16 + c_timming_a,	CPU_EN | (0512 * 16 + c_timming_b),	// 288
	0513 * 16 + c_timming_a,	CPU_EN | (0513 * 16 + c_timming_b),	// 289
	0514 * 16 + c_timming_a,	CPU_EN | (0514 * 16 + c_timming_b),	// 290
	0515 * 16 + c_timming_a,	CPU_EN | (0515 * 16 + c_timming_b),	// 291
	0516 * 16 + c_timming_a,	CPU_EN | (0516 * 16 + c_timming_b),	// 292
	0517 * 16 + c_timming_a,	CPU_EN | (0517 * 16 + c_timming_b),	// 293

	0520 * 16 + c_timming_a,	CPU_EN | (0520 * 16 + c_timming_b),	// 294
	0521 * 16 + c_timming_a,	CPU_EN | (0521 * 16 + c_timming_b),	// 295
	0522 * 16 + c_timming_a,	CPU_EN | (0522 * 16 + c_timming_b),	// 296
	0523 * 16 + c_timming_a,	CPU_EN | (0523 * 16 + c_timming_b),	// 297
	0524 * 16 + c_timming_a,	CPU_EN | (0524 * 16 + c_timming_b),	// 298
	0525 * 16 + c_timming_a,	CPU_EN | (0525 * 16 + c_timming_b),	// 299

	0526 * 16 + c_timming_a,	CPU_EN | (0526 * 16 + c_timming_b),	// -42
	0527 * 16 + c_timming_a,	CPU_EN | (0527 * 16 + c_timming_b),	// -41
	0530 * 16 + c_timming_a,	CPU_EN | (0530 * 16 + c_timming_b),	// -40
	0531 * 16 + c_timming_a,	CPU_EN | (0531 * 16 + c_timming_b),	// -39
	0532 * 16 + c_timming_a,	CPU_EN | (0532 * 16 + c_timming_b),	// -38
	0533 * 16 + c_timming_a,	CPU_EN | (0533 * 16 + c_timming_b),	// -37

	0534 * 16 + c_timming_a,	CPU_EN | (0534 * 16 + c_timming_b),	// -36
	0535 * 16 + c_timming_a,	CPU_EN | (0535 * 16 + c_timming_b),	// -35
	/* REFRESH */													// -34
	0537 * 16 + c_timming_a,	CPU_EN | (0537 * 16 + c_timming_b)	// -33
};

// screen0:width80
static constexpr std::array<int16_t, 540> slotsV9968TextHigh = {
	0000 * 16 + c_timming_a,	CPU_EN | (0000 * 16 + c_timming_b),	// -42
	0001 * 16 + c_timming_a,	CPU_EN | (0001 * 16 + c_timming_b),	// -41
	0002 * 16 + c_timming_a,	CPU_EN | (0002 * 16 + c_timming_b),	// -40
	0003 * 16 + c_timming_a,	CPU_EN | (0003 * 16 + c_timming_b),	// -39
	0004 * 16 + c_timming_a,	CPU_EN | (0004 * 16 + c_timming_b),	// -38
	0005 * 16 + c_timming_a,	CPU_EN | (0005 * 16 + c_timming_b),	// -37

	0006 * 16 + c_timming_a,	CPU_EN | (0006 * 16 + c_timming_b),	// -36
	0007 * 16 + c_timming_a,	CPU_EN | (0007 * 16 + c_timming_b),	// -35
	/* REFRESH */													// -34
	0011 * 16 + c_timming_a,	CPU_EN | (0011 * 16 + c_timming_b),	// -33
	0012 * 16 + c_timming_a,	CPU_EN | (0012 * 16 + c_timming_b),	// -32
	0013 * 16 + c_timming_a,	CPU_EN | (0013 * 16 + c_timming_b),	// -31

	0014 * 16 + c_timming_a,	CPU_EN | (0014 * 16 + c_timming_b),	// -30
	0015 * 16 + c_timming_a,	CPU_EN | (0015 * 16 + c_timming_b),	// -29
	0016 * 16 + c_timming_a,	CPU_EN | (0016 * 16 + c_timming_b),	// -28
	0017 * 16 + c_timming_a,	CPU_EN | (0017 * 16 + c_timming_b),	// -27
	0020 * 16 + c_timming_a,	CPU_EN | (0020 * 16 + c_timming_b),	// -26
	0021 * 16 + c_timming_a,	CPU_EN | (0021 * 16 + c_timming_b),	// -25

	0022 * 16 + c_timming_a,	CPU_EN | (0022 * 16 + c_timming_b),	// -24
	0023 * 16 + c_timming_a,	CPU_EN | (0023 * 16 + c_timming_b),	// -23
	0024 * 16 + c_timming_a,	CPU_EN | (0024 * 16 + c_timming_b),	// -22
	0025 * 16 + c_timming_a,	CPU_EN | (0025 * 16 + c_timming_b),	// -21
	0026 * 16 + c_timming_a,	CPU_EN | (0026 * 16 + c_timming_b),	// -20
	0027 * 16 + c_timming_a,	CPU_EN | (0027 * 16 + c_timming_b),	// -19

	0030 * 16 + c_timming_a,	CPU_EN | (0030 * 16 + c_timming_b),	// -18
	0031 * 16 + c_timming_a,	CPU_EN | (0031 * 16 + c_timming_b),	// -17
	0032 * 16 + c_timming_a,	CPU_EN | (0032 * 16 + c_timming_b),	// -16
	0033 * 16 + c_timming_a,	CPU_EN | (0033 * 16 + c_timming_b),	// -15
	0034 * 16 + c_timming_a,	CPU_EN | (0034 * 16 + c_timming_b),	// -14
	0035 * 16 + c_timming_a,	CPU_EN | (0035 * 16 + c_timming_b),	// -13

	0036 * 16 + c_timming_a,	CPU_EN | (0036 * 16 + c_timming_b),	// -12
	0037 * 16 + c_timming_a,	CPU_EN | (0037 * 16 + c_timming_b),	// -11
	0040 * 16 + c_timming_a,	CPU_EN | (0040 * 16 + c_timming_b),	// -10
	0041 * 16 + c_timming_a,	CPU_EN | (0041 * 16 + c_timming_b),	// -9
	0042 * 16 + c_timming_a,	CPU_EN | (0042 * 16 + c_timming_b),	// -8
	0043 * 16 + c_timming_a,	CPU_EN | (0043 * 16 + c_timming_b),	// -7

	/* NAME */					CPU_EN | (0044 * 16 + c_timming_b),	// -6
	/* PATTERN */				CPU_EN | (0045 * 16 + c_timming_b),	// -5
	/* PATTERN */				CPU_EN | (0046 * 16 + c_timming_b),	// -4
	/* COLOR */					CPU_EN | (0047 * 16 + c_timming_b),	// -3
	0050 * 16 + c_timming_a,	CPU_EN | (0050 * 16 + c_timming_b),	// -2
	0051 * 16 + c_timming_a,	CPU_EN | (0051 * 16 + c_timming_b),	// -1

	/* NAME */					CPU_EN | (0052 * 16 + c_timming_b),	// 0
	/* PATTERN */				CPU_EN | (0053 * 16 + c_timming_b),	// 1
	/* PATTERN */				CPU_EN | (0054 * 16 + c_timming_b),	// 2
	/* COLOR */					CPU_EN | (0055 * 16 + c_timming_b),	// 3
	0056 * 16 + c_timming_a,	CPU_EN | (0056 * 16 + c_timming_b),	// 4
	0057 * 16 + c_timming_a,	CPU_EN | (0057 * 16 + c_timming_b),	// 5

	/* NAME */					CPU_EN | (0060 * 16 + c_timming_b),	// 6
	/* PATTERN */				CPU_EN | (0061 * 16 + c_timming_b),	// 7
	/* PATTERN */				CPU_EN | (0062 * 16 + c_timming_b),	// 8
	/* COLOR */					CPU_EN | (0063 * 16 + c_timming_b),	// 9
	0064 * 16 + c_timming_a,	CPU_EN | (0064 * 16 + c_timming_b),	// 10
	0065 * 16 + c_timming_a,	CPU_EN | (0065 * 16 + c_timming_b),	// 11

	/* NAME */					CPU_EN | (0066 * 16 + c_timming_b),	// 12
	/* PATTERN */				CPU_EN | (0067 * 16 + c_timming_b),	// 13
	/* PATTERN */				CPU_EN | (0070 * 16 + c_timming_b),	// 14
	/* COLOR */					CPU_EN | (0071 * 16 + c_timming_b),	// 15
	0072 * 16 + c_timming_a,	CPU_EN | (0072 * 16 + c_timming_b),	// 16
	0073 * 16 + c_timming_a,	CPU_EN | (0073 * 16 + c_timming_b),	// 17

	/* NAME */					CPU_EN | (0074 * 16 + c_timming_b),	// 18
	/* PATTERN */				CPU_EN | (0075 * 16 + c_timming_b),	// 19
	/* PATTERN */				CPU_EN | (0076 * 16 + c_timming_b),	// 20
	/* COLOR */					CPU_EN | (0077 * 16 + c_timming_b),	// 21
	0100 * 16 + c_timming_a,	CPU_EN | (0100 * 16 + c_timming_b),	// 22
	0101 * 16 + c_timming_a,	CPU_EN | (0101 * 16 + c_timming_b),	// 23

	/* NAME */					CPU_EN | (0102 * 16 + c_timming_b),	// 24
	/* PATTERN */				CPU_EN | (0103 * 16 + c_timming_b),	// 25
	/* PATTERN */				CPU_EN | (0104 * 16 + c_timming_b),	// 26
	/* COLOR */					CPU_EN | (0105 * 16 + c_timming_b),	// 27
	0106 * 16 + c_timming_a,	CPU_EN | (0106 * 16 + c_timming_b),	// 28
	0107 * 16 + c_timming_a,	CPU_EN | (0107 * 16 + c_timming_b),	// 29

	/* NAME */					CPU_EN | (0110 * 16 + c_timming_b),	// 30
	/* PATTERN */				CPU_EN | (0111 * 16 + c_timming_b),	// 31
	/* PATTERN */				CPU_EN | (0112 * 16 + c_timming_b),	// 32
	/* COLOR */					CPU_EN | (0113 * 16 + c_timming_b),	// 33
	0114 * 16 + c_timming_a,	CPU_EN | (0114 * 16 + c_timming_b),	// 34
	0115 * 16 + c_timming_a,	CPU_EN | (0115 * 16 + c_timming_b),	// 35

	/* NAME */					CPU_EN | (0116 * 16 + c_timming_b),	// 36
	/* PATTERN */				CPU_EN | (0117 * 16 + c_timming_b),	// 37
	/* PATTERN */				CPU_EN | (0120 * 16 + c_timming_b),	// 38
	/* COLOR */					CPU_EN | (0121 * 16 + c_timming_b),	// 39
	0122 * 16 + c_timming_a,	CPU_EN | (0122 * 16 + c_timming_b),	// 40
	0123 * 16 + c_timming_a,	CPU_EN | (0123 * 16 + c_timming_b),	// 41

	/* NAME */					CPU_EN | (0124 * 16 + c_timming_b),	// 42
	/* PATTERN */				CPU_EN | (0125 * 16 + c_timming_b),	// 43
	/* PATTERN */				CPU_EN | (0126 * 16 + c_timming_b),	// 44
	/* COLOR */					CPU_EN | (0127 * 16 + c_timming_b),	// 45
	0130 * 16 + c_timming_a,	CPU_EN | (0130 * 16 + c_timming_b),	// 46
	0131 * 16 + c_timming_a,	CPU_EN | (0131 * 16 + c_timming_b),	// 47

	/* NAME */					CPU_EN | (0132 * 16 + c_timming_b),	// 48
	/* PATTERN */				CPU_EN | (0133 * 16 + c_timming_b),	// 49
	/* PATTERN */				CPU_EN | (0134 * 16 + c_timming_b),	// 50
	/* COLOR */					CPU_EN | (0135 * 16 + c_timming_b),	// 51
	0136 * 16 + c_timming_a,	CPU_EN | (0136 * 16 + c_timming_b),	// 52
	0137 * 16 + c_timming_a,	CPU_EN | (0137 * 16 + c_timming_b),	// 53

	/* NAME */					CPU_EN | (0140 * 16 + c_timming_b),	// 54
	/* PATTERN */				CPU_EN | (0141 * 16 + c_timming_b),	// 55
	/* PATTERN */				CPU_EN | (0142 * 16 + c_timming_b),	// 56
	/* COLOR */					CPU_EN | (0143 * 16 + c_timming_b),	// 57
	0144 * 16 + c_timming_a,	CPU_EN | (0144 * 16 + c_timming_b),	// 58
	0145 * 16 + c_timming_a,	CPU_EN | (0145 * 16 + c_timming_b),	// 59

	/* NAME */					CPU_EN | (0146 * 16 + c_timming_b),	// 60
	/* PATTERN */				CPU_EN | (0147 * 16 + c_timming_b),	// 61
	/* PATTERN */				CPU_EN | (0150 * 16 + c_timming_b),	// 62
	/* COLOR */					CPU_EN | (0151 * 16 + c_timming_b),	// 63
	0152 * 16 + c_timming_a,	CPU_EN | (0152 * 16 + c_timming_b),	// 64
	0153 * 16 + c_timming_a,	CPU_EN | (0153 * 16 + c_timming_b),	// 65

	/* NAME */					CPU_EN | (0154 * 16 + c_timming_b),	// 66
	/* PATTERN */				CPU_EN | (0155 * 16 + c_timming_b),	// 67
	/* PATTERN */				CPU_EN | (0156 * 16 + c_timming_b),	// 68
	/* COLOR */					CPU_EN | (0157 * 16 + c_timming_b),	// 69
	0160 * 16 + c_timming_a,	CPU_EN | (0160 * 16 + c_timming_b),	// 70
	0161 * 16 + c_timming_a,	CPU_EN | (0161 * 16 + c_timming_b),	// 71

	/* NAME */					CPU_EN | (0162 * 16 + c_timming_b),	// 72
	/* PATTERN */				CPU_EN | (0163 * 16 + c_timming_b),	// 73
	/* PATTERN */				CPU_EN | (0164 * 16 + c_timming_b),	// 74
	/* COLOR */					CPU_EN | (0165 * 16 + c_timming_b),	// 75
	0166 * 16 + c_timming_a,	CPU_EN | (0166 * 16 + c_timming_b),	// 76
	0167 * 16 + c_timming_a,	CPU_EN | (0167 * 16 + c_timming_b),	// 77

	/* NAME */					CPU_EN | (0170 * 16 + c_timming_b),	// 78
	/* PATTERN */				CPU_EN | (0171 * 16 + c_timming_b),	// 79
	/* PATTERN */				CPU_EN | (0172 * 16 + c_timming_b),	// 80
	/* COLOR */					CPU_EN | (0173 * 16 + c_timming_b),	// 81
	0174 * 16 + c_timming_a,	CPU_EN | (0174 * 16 + c_timming_b),	// 82
	0175 * 16 + c_timming_a,	CPU_EN | (0175 * 16 + c_timming_b),	// 83

	/* NAME */					CPU_EN | (0176 * 16 + c_timming_b),	// 84
	/* PATTERN */				CPU_EN | (0177 * 16 + c_timming_b),	// 85
	/* PATTERN */				CPU_EN | (0200 * 16 + c_timming_b),	// 86
	/* COLOR */					CPU_EN | (0201 * 16 + c_timming_b),	// 87
	0202 * 16 + c_timming_a,	CPU_EN | (0202 * 16 + c_timming_b),	// 88
	0203 * 16 + c_timming_a,	CPU_EN | (0203 * 16 + c_timming_b),	// 89

	/* NAME */					CPU_EN | (0204 * 16 + c_timming_b),	// 90
	/* PATTERN */				CPU_EN | (0205 * 16 + c_timming_b),	// 91
	/* PATTERN */				CPU_EN | (0206 * 16 + c_timming_b),	// 92
	/* COLOR */					CPU_EN | (0207 * 16 + c_timming_b),	// 93
	0210 * 16 + c_timming_a,	CPU_EN | (0210 * 16 + c_timming_b),	// 94
	0211 * 16 + c_timming_a,	CPU_EN | (0211 * 16 + c_timming_b),	// 95

	/* NAME */					CPU_EN | (0212 * 16 + c_timming_b),	// 96
	/* PATTERN */				CPU_EN | (0213 * 16 + c_timming_b),	// 97
	/* PATTERN */				CPU_EN | (0214 * 16 + c_timming_b),	// 98
	/* COLOR */					CPU_EN | (0215 * 16 + c_timming_b),	// 99
	0216 * 16 + c_timming_a,	CPU_EN | (0216 * 16 + c_timming_b),	// 100
	0217 * 16 + c_timming_a,	CPU_EN | (0217 * 16 + c_timming_b),	// 101

	/* NAME */					CPU_EN | (0220 * 16 + c_timming_b),	// 102
	/* PATTERN */				CPU_EN | (0221 * 16 + c_timming_b),	// 103
	/* PATTERN */				CPU_EN | (0222 * 16 + c_timming_b),	// 104
	/* COLOR */					CPU_EN | (0223 * 16 + c_timming_b),	// 105
	0224 * 16 + c_timming_a,	CPU_EN | (0224 * 16 + c_timming_b),	// 106
	0225 * 16 + c_timming_a,	CPU_EN | (0225 * 16 + c_timming_b),	// 107

	/* NAME */					CPU_EN | (0226 * 16 + c_timming_b),	// 108
	/* PATTERN */				CPU_EN | (0227 * 16 + c_timming_b),	// 109
	/* PATTERN */				CPU_EN | (0230 * 16 + c_timming_b),	// 110
	/* COLOR */					CPU_EN | (0231 * 16 + c_timming_b),	// 111
	0232 * 16 + c_timming_a,	CPU_EN | (0232 * 16 + c_timming_b),	// 112
	0233 * 16 + c_timming_a,	CPU_EN | (0233 * 16 + c_timming_b),	// 113

	/* NAME */					CPU_EN | (0234 * 16 + c_timming_b),	// 114
	/* PATTERN */				CPU_EN | (0235 * 16 + c_timming_b),	// 115
	/* PATTERN */				CPU_EN | (0236 * 16 + c_timming_b),	// 116
	/* COLOR */					CPU_EN | (0237 * 16 + c_timming_b),	// 117
	0240 * 16 + c_timming_a,	CPU_EN | (0240 * 16 + c_timming_b),	// 118
	0241 * 16 + c_timming_a,	CPU_EN | (0241 * 16 + c_timming_b),	// 119

	/* NAME */					CPU_EN | (0242 * 16 + c_timming_b),	// 120
	/* PATTERN */				CPU_EN | (0243 * 16 + c_timming_b),	// 121
	/* PATTERN */				CPU_EN | (0244 * 16 + c_timming_b),	// 122
	/* COLOR */					CPU_EN | (0245 * 16 + c_timming_b),	// 123
	0246 * 16 + c_timming_a,	CPU_EN | (0246 * 16 + c_timming_b),	// 124
	0247 * 16 + c_timming_a,	CPU_EN | (0247 * 16 + c_timming_b),	// 125

	/* NAME */					CPU_EN | (0250 * 16 + c_timming_b),	// 126
	/* PATTERN */				CPU_EN | (0251 * 16 + c_timming_b),	// 127
	/* PATTERN */				CPU_EN | (0252 * 16 + c_timming_b),	// 128
	/* COLOR */					CPU_EN | (0253 * 16 + c_timming_b),	// 129
	0254 * 16 + c_timming_a,	CPU_EN | (0254 * 16 + c_timming_b),	// 130
	0255 * 16 + c_timming_a,	CPU_EN | (0255 * 16 + c_timming_b),	// 131

	/* NAME */					CPU_EN | (0256 * 16 + c_timming_b),	// 132
	/* PATTERN */				CPU_EN | (0257 * 16 + c_timming_b),	// 133
	/* PATTERN */				CPU_EN | (0260 * 16 + c_timming_b),	// 134
	/* COLOR */					CPU_EN | (0261 * 16 + c_timming_b),	// 135
	0262 * 16 + c_timming_a,	CPU_EN | (0262 * 16 + c_timming_b),	// 136
	0263 * 16 + c_timming_a,	CPU_EN | (0263 * 16 + c_timming_b),	// 137

	/* NAME */					CPU_EN | (0264 * 16 + c_timming_b),	// 138
	/* PATTERN */				CPU_EN | (0265 * 16 + c_timming_b),	// 139
	/* PATTERN */				CPU_EN | (0266 * 16 + c_timming_b),	// 140
	/* COLOR */					CPU_EN | (0267 * 16 + c_timming_b),	// 141
	0270 * 16 + c_timming_a,	CPU_EN | (0270 * 16 + c_timming_b),	// 142
	0271 * 16 + c_timming_a,	CPU_EN | (0271 * 16 + c_timming_b),	// 143

	/* NAME */					CPU_EN | (0272 * 16 + c_timming_b),	// 144
	/* PATTERN */				CPU_EN | (0273 * 16 + c_timming_b),	// 145
	/* PATTERN */				CPU_EN | (0274 * 16 + c_timming_b),	// 146
	/* COLOR */					CPU_EN | (0275 * 16 + c_timming_b),	// 147
	0276 * 16 + c_timming_a,	CPU_EN | (0276 * 16 + c_timming_b),	// 148
	0277 * 16 + c_timming_a,	CPU_EN | (0277 * 16 + c_timming_b),	// 149

	/* NAME */					CPU_EN | (0300 * 16 + c_timming_b),	// 150
	/* PATTERN */				CPU_EN | (0301 * 16 + c_timming_b),	// 151
	/* PATTERN */				CPU_EN | (0302 * 16 + c_timming_b),	// 152
	/* COLOR */					CPU_EN | (0303 * 16 + c_timming_b),	// 153
	0304 * 16 + c_timming_a,	CPU_EN | (0304 * 16 + c_timming_b),	// 154
	0305 * 16 + c_timming_a,	CPU_EN | (0305 * 16 + c_timming_b),	// 155

	/* NAME */					CPU_EN | (0306 * 16 + c_timming_b),	// 156
	/* PATTERN */				CPU_EN | (0307 * 16 + c_timming_b),	// 157
	/* PATTERN */				CPU_EN | (0310 * 16 + c_timming_b),	// 158
	/* COLOR */					CPU_EN | (0311 * 16 + c_timming_b),	// 159
	0312 * 16 + c_timming_a,	CPU_EN | (0312 * 16 + c_timming_b),	// 160
	0313 * 16 + c_timming_a,	CPU_EN | (0313 * 16 + c_timming_b),	// 161

	/* NAME */					CPU_EN | (0314 * 16 + c_timming_b),	// 162
	/* PATTERN */				CPU_EN | (0315 * 16 + c_timming_b),	// 163
	/* PATTERN */				CPU_EN | (0316 * 16 + c_timming_b),	// 164
	/* COLOR */					CPU_EN | (0317 * 16 + c_timming_b),	// 165
	0320 * 16 + c_timming_a,	CPU_EN | (0320 * 16 + c_timming_b),	// 166
	0321 * 16 + c_timming_a,	CPU_EN | (0321 * 16 + c_timming_b),	// 167

	/* NAME */					CPU_EN | (0322 * 16 + c_timming_b),	// 168
	/* PATTERN */				CPU_EN | (0323 * 16 + c_timming_b),	// 169
	/* PATTERN */				CPU_EN | (0324 * 16 + c_timming_b),	// 170
	/* COLOR */					CPU_EN | (0325 * 16 + c_timming_b),	// 171
	0326 * 16 + c_timming_a,	CPU_EN | (0326 * 16 + c_timming_b),	// 172
	0327 * 16 + c_timming_a,	CPU_EN | (0327 * 16 + c_timming_b),	// 173

	/* NAME */					CPU_EN | (0330 * 16 + c_timming_b),	// 174
	/* PATTERN */				CPU_EN | (0331 * 16 + c_timming_b),	// 175
	/* PATTERN */				CPU_EN | (0332 * 16 + c_timming_b),	// 176
	/* COLOR */					CPU_EN | (0333 * 16 + c_timming_b),	// 177
	0334 * 16 + c_timming_a,	CPU_EN | (0334 * 16 + c_timming_b),	// 178
	0335 * 16 + c_timming_a,	CPU_EN | (0335 * 16 + c_timming_b),	// 179

	/* NAME */					CPU_EN | (0336 * 16 + c_timming_b),	// 180
	/* PATTERN */				CPU_EN | (0337 * 16 + c_timming_b),	// 181
	/* PATTERN */				CPU_EN | (0340 * 16 + c_timming_b),	// 182
	/* COLOR */					CPU_EN | (0341 * 16 + c_timming_b),	// 183
	0342 * 16 + c_timming_a,	CPU_EN | (0342 * 16 + c_timming_b),	// 184
	0343 * 16 + c_timming_a,	CPU_EN | (0343 * 16 + c_timming_b),	// 185

	/* NAME */					CPU_EN | (0344 * 16 + c_timming_b),	// 186
	/* PATTERN */				CPU_EN | (0345 * 16 + c_timming_b),	// 187
	/* PATTERN */				CPU_EN | (0346 * 16 + c_timming_b),	// 188
	/* COLOR */					CPU_EN | (0347 * 16 + c_timming_b),	// 189
	0350 * 16 + c_timming_a,	CPU_EN | (0350 * 16 + c_timming_b),	// 190
	0351 * 16 + c_timming_a,	CPU_EN | (0351 * 16 + c_timming_b),	// 191

	/* NAME */					CPU_EN | (0352 * 16 + c_timming_b),	// 192
	/* PATTERN */				CPU_EN | (0353 * 16 + c_timming_b),	// 193
	/* PATTERN */				CPU_EN | (0354 * 16 + c_timming_b),	// 194
	/* COLOR */					CPU_EN | (0355 * 16 + c_timming_b),	// 195
	0356 * 16 + c_timming_a,	CPU_EN | (0356 * 16 + c_timming_b),	// 196
	0357 * 16 + c_timming_a,	CPU_EN | (0357 * 16 + c_timming_b),	// 197

	/* NAME */					CPU_EN | (0360 * 16 + c_timming_b),	// 198
	/* PATTERN */				CPU_EN | (0361 * 16 + c_timming_b),	// 199
	/* PATTERN */				CPU_EN | (0362 * 16 + c_timming_b),	// 200
	/* COLOR */					CPU_EN | (0363 * 16 + c_timming_b),	// 201
	0364 * 16 + c_timming_a,	CPU_EN | (0364 * 16 + c_timming_b),	// 202
	0365 * 16 + c_timming_a,	CPU_EN | (0365 * 16 + c_timming_b),	// 203

	/* NAME */					CPU_EN | (0366 * 16 + c_timming_b),	// 204
	/* PATTERN */				CPU_EN | (0367 * 16 + c_timming_b),	// 205
	/* PATTERN */				CPU_EN | (0370 * 16 + c_timming_b),	// 206
	/* COLOR */					CPU_EN | (0371 * 16 + c_timming_b),	// 205
	0372 * 16 + c_timming_a,	CPU_EN | (0372 * 16 + c_timming_b),	// 208
	0373 * 16 + c_timming_a,	CPU_EN | (0373 * 16 + c_timming_b),	// 209

	/* NAME */					CPU_EN | (0374 * 16 + c_timming_b),	// 210
	/* PATTERN */				CPU_EN | (0375 * 16 + c_timming_b),	// 211
	/* PATTERN */				CPU_EN | (0376 * 16 + c_timming_b),	// 212
	/* COLOR */					CPU_EN | (0377 * 16 + c_timming_b),	// 213
	0400 * 16 + c_timming_a,	CPU_EN | (0400 * 16 + c_timming_b),	// 214
	0401 * 16 + c_timming_a,	CPU_EN | (0401 * 16 + c_timming_b),	// 215

	/* NAME */					CPU_EN | (0402 * 16 + c_timming_b),	// 216
	/* PATTERN */				CPU_EN | (0403 * 16 + c_timming_b),	// 217
	/* PATTERN */				CPU_EN | (0404 * 16 + c_timming_b),	// 218
	/* COLOR */					CPU_EN | (0405 * 16 + c_timming_b),	// 219
	0406 * 16 + c_timming_a,	CPU_EN | (0406 * 16 + c_timming_b),	// 220
	0407 * 16 + c_timming_a,	CPU_EN | (0407 * 16 + c_timming_b),	// 221

	/* NAME */					CPU_EN | (0410 * 16 + c_timming_b),	// 222
	/* PATTERN */				CPU_EN | (0411 * 16 + c_timming_b),	// 223
	/* PATTERN */				CPU_EN | (0412 * 16 + c_timming_b),	// 224
	/* COLOR */					CPU_EN | (0413 * 16 + c_timming_b),	// 225
	0414 * 16 + c_timming_a,	CPU_EN | (0414 * 16 + c_timming_b),	// 226
	0415 * 16 + c_timming_a,	CPU_EN | (0415 * 16 + c_timming_b),	// 227

	/* NAME */					CPU_EN | (0416 * 16 + c_timming_b),	// 228
	/* PATTERN */				CPU_EN | (0417 * 16 + c_timming_b),	// 229
	/* PATTERN */				CPU_EN | (0420 * 16 + c_timming_b),	// 230
	/* COLOR */					CPU_EN | (0421 * 16 + c_timming_b),	// 231
	0422 * 16 + c_timming_a,	CPU_EN | (0422 * 16 + c_timming_b),	// 232
	0423 * 16 + c_timming_a,	CPU_EN | (0423 * 16 + c_timming_b),	// 233

	0424 * 16 + c_timming_a,	CPU_EN | (0424 * 16 + c_timming_b),	// 234
	0425 * 16 + c_timming_a,	CPU_EN | (0425 * 16 + c_timming_b),	// 235
	0426 * 16 + c_timming_a,	CPU_EN | (0426 * 16 + c_timming_b),	// 236
	0427 * 16 + c_timming_a,	CPU_EN | (0427 * 16 + c_timming_b),	// 237
	0430 * 16 + c_timming_a,	CPU_EN | (0430 * 16 + c_timming_b),	// 238
	0431 * 16 + c_timming_a,	CPU_EN | (0431 * 16 + c_timming_b),	// 239

	0432 * 16 + c_timming_a,	CPU_EN | (0432 * 16 + c_timming_b),	// 240
	0433 * 16 + c_timming_a,	CPU_EN | (0433 * 16 + c_timming_b),	// 241
	0434 * 16 + c_timming_a,	CPU_EN | (0434 * 16 + c_timming_b),	// 242
	0435 * 16 + c_timming_a,	CPU_EN | (0435 * 16 + c_timming_b),	// 243
	0436 * 16 + c_timming_a,	CPU_EN | (0436 * 16 + c_timming_b),	// 244
	0437 * 16 + c_timming_a,	CPU_EN | (0437 * 16 + c_timming_b),	// 245

	0440 * 16 + c_timming_a,	CPU_EN | (0440 * 16 + c_timming_b),	// 246
	0441 * 16 + c_timming_a,	CPU_EN | (0441 * 16 + c_timming_b),	// 247
	0442 * 16 + c_timming_a,	CPU_EN | (0442 * 16 + c_timming_b),	// 248
	0443 * 16 + c_timming_a,	CPU_EN | (0443 * 16 + c_timming_b),	// 249
	0444 * 16 + c_timming_a,	CPU_EN | (0444 * 16 + c_timming_b),	// 250
	0445 * 16 + c_timming_a,	CPU_EN | (0445 * 16 + c_timming_b),	// 251

	0446 * 16 + c_timming_a,	CPU_EN | (0446 * 16 + c_timming_b),	// 252
	0447 * 16 + c_timming_a,	CPU_EN | (0447 * 16 + c_timming_b),	// 253
	0450 * 16 + c_timming_a,	CPU_EN | (0450 * 16 + c_timming_b),	// 254
	0451 * 16 + c_timming_a,	CPU_EN | (0451 * 16 + c_timming_b),	// 255
	0452 * 16 + c_timming_a,	CPU_EN | (0452 * 16 + c_timming_b),	// 256
	0453 * 16 + c_timming_a,	CPU_EN | (0453 * 16 + c_timming_b),	// 257

	0454 * 16 + c_timming_a,	CPU_EN | (0454 * 16 + c_timming_b),	// 258
	0455 * 16 + c_timming_a,	CPU_EN | (0455 * 16 + c_timming_b),	// 259
	0456 * 16 + c_timming_a,	CPU_EN | (0456 * 16 + c_timming_b),	// 260
	0457 * 16 + c_timming_a,	CPU_EN | (0457 * 16 + c_timming_b),	// 261
	0460 * 16 + c_timming_a,	CPU_EN | (0460 * 16 + c_timming_b),	// 262
	0461 * 16 + c_timming_a,	CPU_EN | (0461 * 16 + c_timming_b),	// 263

	0462 * 16 + c_timming_a,	CPU_EN | (0462 * 16 + c_timming_b),	// 264
	0463 * 16 + c_timming_a,	CPU_EN | (0463 * 16 + c_timming_b),	// 265
	0464 * 16 + c_timming_a,	CPU_EN | (0464 * 16 + c_timming_b),	// 266
	0465 * 16 + c_timming_a,	CPU_EN | (0465 * 16 + c_timming_b),	// 267
	0466 * 16 + c_timming_a,	CPU_EN | (0466 * 16 + c_timming_b),	// 268
	0467 * 16 + c_timming_a,	CPU_EN | (0467 * 16 + c_timming_b),	// 269

	0470 * 16 + c_timming_a,	CPU_EN | (0470 * 16 + c_timming_b),	// 270
	0471 * 16 + c_timming_a,	CPU_EN | (0471 * 16 + c_timming_b),	// 271
	0472 * 16 + c_timming_a,	CPU_EN | (0472 * 16 + c_timming_b),	// 272
	0473 * 16 + c_timming_a,	CPU_EN | (0473 * 16 + c_timming_b),	// 273
	0474 * 16 + c_timming_a,	CPU_EN | (0474 * 16 + c_timming_b),	// 274
	0475 * 16 + c_timming_a,	CPU_EN | (0475 * 16 + c_timming_b),	// 275

	0476 * 16 + c_timming_a,	CPU_EN | (0476 * 16 + c_timming_b),	// 276
	0477 * 16 + c_timming_a,	CPU_EN | (0477 * 16 + c_timming_b),	// 277
	0500 * 16 + c_timming_a,	CPU_EN | (0500 * 16 + c_timming_b),	// 278
	0501 * 16 + c_timming_a,	CPU_EN | (0501 * 16 + c_timming_b),	// 279
	0502 * 16 + c_timming_a,	CPU_EN | (0502 * 16 + c_timming_b),	// 280
	0503 * 16 + c_timming_a,	CPU_EN | (0503 * 16 + c_timming_b),	// 281

	0504 * 16 + c_timming_a,	CPU_EN | (0504 * 16 + c_timming_b),	// 282
	0505 * 16 + c_timming_a,	CPU_EN | (0505 * 16 + c_timming_b),	// 283
	0506 * 16 + c_timming_a,	CPU_EN | (0506 * 16 + c_timming_b),	// 284
	0507 * 16 + c_timming_a,	CPU_EN | (0507 * 16 + c_timming_b),	// 285
	0510 * 16 + c_timming_a,	CPU_EN | (0510 * 16 + c_timming_b),	// 286
	0511 * 16 + c_timming_a,	CPU_EN | (0511 * 16 + c_timming_b),	// 287

	0512 * 16 + c_timming_a,	CPU_EN | (0512 * 16 + c_timming_b),	// 288
	0513 * 16 + c_timming_a,	CPU_EN | (0513 * 16 + c_timming_b),	// 289
	0514 * 16 + c_timming_a,	CPU_EN | (0514 * 16 + c_timming_b),	// 290
	0515 * 16 + c_timming_a,	CPU_EN | (0515 * 16 + c_timming_b),	// 291
	0516 * 16 + c_timming_a,	CPU_EN | (0516 * 16 + c_timming_b),	// 292
	0517 * 16 + c_timming_a,	CPU_EN | (0517 * 16 + c_timming_b),	// 293

	0520 * 16 + c_timming_a,	CPU_EN | (0520 * 16 + c_timming_b),	// 294
	0521 * 16 + c_timming_a,	CPU_EN | (0521 * 16 + c_timming_b),	// 295
	0522 * 16 + c_timming_a,	CPU_EN | (0522 * 16 + c_timming_b),	// 296
	0523 * 16 + c_timming_a,	CPU_EN | (0523 * 16 + c_timming_b),	// 297
	0524 * 16 + c_timming_a,	CPU_EN | (0524 * 16 + c_timming_b),	// 298
	0525 * 16 + c_timming_a,	CPU_EN | (0525 * 16 + c_timming_b),	// 299

	0526 * 16 + c_timming_a,	CPU_EN | (0526 * 16 + c_timming_b),	// -42
	0527 * 16 + c_timming_a,	CPU_EN | (0527 * 16 + c_timming_b),	// -41
	0530 * 16 + c_timming_a,	CPU_EN | (0530 * 16 + c_timming_b),	// -40
	0531 * 16 + c_timming_a,	CPU_EN | (0531 * 16 + c_timming_b),	// -39
	0532 * 16 + c_timming_a,	CPU_EN | (0532 * 16 + c_timming_b),	// -38
	0533 * 16 + c_timming_a,	CPU_EN | (0533 * 16 + c_timming_b),	// -37

	0534 * 16 + c_timming_a,	CPU_EN | (0534 * 16 + c_timming_b),	// -36
	0535 * 16 + c_timming_a,	CPU_EN | (0535 * 16 + c_timming_b),	// -35
	/* REFRESH */													// -34
	0537 * 16 + c_timming_a,	CPU_EN | (0537 * 16 + c_timming_b)	// -33
};

// screen 5,6
static constexpr std::array<int16_t, 700-32> slotsV9968BitmapLowSpritesOff = {
	0000 * 16 + c_timming_a,	CPU_EN | (0000 * 16 + c_timming_b),	// -40
	0001 * 16 + c_timming_a,	CPU_EN | (0001 * 16 + c_timming_b),	// -39
	0002 * 16 + c_timming_a,	CPU_EN | (0002 * 16 + c_timming_b),	// -38
	0003 * 16 + c_timming_a,	CPU_EN | (0003 * 16 + c_timming_b),	// -37
	0004 * 16 + c_timming_a,	CPU_EN | (0004 * 16 + c_timming_b),	// -36
	0005 * 16 + c_timming_a,	CPU_EN | (0005 * 16 + c_timming_b),	// -35
	0006 * 16 + c_timming_a,	CPU_EN | (0006 * 16 + c_timming_b),	// -34
	0007 * 16 + c_timming_a,	CPU_EN | (0007 * 16 + c_timming_b),	// -33

	/* REFRESH */													// -32
	0011 * 16 + c_timming_a,	CPU_EN | (0011 * 16 + c_timming_b),	// -31
	0012 * 16 + c_timming_a,	CPU_EN | (0012 * 16 + c_timming_b),	// -30
	0013 * 16 + c_timming_a,	CPU_EN | (0013 * 16 + c_timming_b),	// -29
	0014 * 16 + c_timming_a,	CPU_EN | (0014 * 16 + c_timming_b),	// -28
	0015 * 16 + c_timming_a,	CPU_EN | (0015 * 16 + c_timming_b),	// -27
	0016 * 16 + c_timming_a,	CPU_EN | (0016 * 16 + c_timming_b),	// -26
	0017 * 16 + c_timming_a,	CPU_EN | (0017 * 16 + c_timming_b),	// -25

	0020 * 16 + c_timming_a,	CPU_EN | (0020 * 16 + c_timming_b),	// -24
	0021 * 16 + c_timming_a,	CPU_EN | (0021 * 16 + c_timming_b),	// -23
	0022 * 16 + c_timming_a,	CPU_EN | (0022 * 16 + c_timming_b),	// -22
	0023 * 16 + c_timming_a,	CPU_EN | (0023 * 16 + c_timming_b),	// -21
	0024 * 16 + c_timming_a,	CPU_EN | (0024 * 16 + c_timming_b),	// -20
	0025 * 16 + c_timming_a,	CPU_EN | (0025 * 16 + c_timming_b),	// -19
	0026 * 16 + c_timming_a,	CPU_EN | (0026 * 16 + c_timming_b),	// -18
	0027 * 16 + c_timming_a,	CPU_EN | (0027 * 16 + c_timming_b),	// -17

	0030 * 16 + c_timming_a,	CPU_EN | (0030 * 16 + c_timming_b),	// -16
	0031 * 16 + c_timming_a,	CPU_EN | (0031 * 16 + c_timming_b),	// -15
	0032 * 16 + c_timming_a,	CPU_EN | (0032 * 16 + c_timming_b),	// -14
	0033 * 16 + c_timming_a,	CPU_EN | (0033 * 16 + c_timming_b),	// -13
	0034 * 16 + c_timming_a,	CPU_EN | (0034 * 16 + c_timming_b),	// -12
	0035 * 16 + c_timming_a,	CPU_EN | (0035 * 16 + c_timming_b),	// -11
	0036 * 16 + c_timming_a,	CPU_EN | (0036 * 16 + c_timming_b),	// -10
	0037 * 16 + c_timming_a,	CPU_EN | (0037 * 16 + c_timming_b),	// -9

	/* BITMAP */				CPU_EN | (0040 * 16 + c_timming_b),	// -8
	0041 * 16 + c_timming_a,	CPU_EN | (0041 * 16 + c_timming_b),	// -7
	0042 * 16 + c_timming_a,	CPU_EN | (0042 * 16 + c_timming_b),	// -6
	0043 * 16 + c_timming_a,	CPU_EN | (0043 * 16 + c_timming_b),	// -5
	0044 * 16 + c_timming_a,	CPU_EN | (0044 * 16 + c_timming_b),	// -4
	0045 * 16 + c_timming_a,	CPU_EN | (0045 * 16 + c_timming_b),	// -3
	0046 * 16 + c_timming_a,	CPU_EN | (0046 * 16 + c_timming_b),	// -2
	0047 * 16 + c_timming_a,	CPU_EN | (0047 * 16 + c_timming_b),	// -1

	/* BITMAP */				CPU_EN | (0050 * 16 + c_timming_b),	// 0
	0051 * 16 + c_timming_a,	CPU_EN | (0051 * 16 + c_timming_b),	// 1
	0052 * 16 + c_timming_a,	CPU_EN | (0052 * 16 + c_timming_b),	// 2
	0053 * 16 + c_timming_a,	CPU_EN | (0053 * 16 + c_timming_b),	// 3
	0054 * 16 + c_timming_a,	CPU_EN | (0054 * 16 + c_timming_b),	// 4
	0055 * 16 + c_timming_a,	CPU_EN | (0055 * 16 + c_timming_b),	// 5
	0056 * 16 + c_timming_a,	CPU_EN | (0056 * 16 + c_timming_b),	// 6
	0057 * 16 + c_timming_a,	CPU_EN | (0057 * 16 + c_timming_b),	// 7

	/* BITMAP */				CPU_EN | (0060 * 16 + c_timming_b),	// 8
	0061 * 16 + c_timming_a,	CPU_EN | (0061 * 16 + c_timming_b),	// 9
	0062 * 16 + c_timming_a,	CPU_EN | (0062 * 16 + c_timming_b),	// 10
	0063 * 16 + c_timming_a,	CPU_EN | (0063 * 16 + c_timming_b),	// 11
	0064 * 16 + c_timming_a,	CPU_EN | (0064 * 16 + c_timming_b),	// 12
	0065 * 16 + c_timming_a,	CPU_EN | (0065 * 16 + c_timming_b),	// 13
	0066 * 16 + c_timming_a,	CPU_EN | (0066 * 16 + c_timming_b),	// 14
	0067 * 16 + c_timming_a,	CPU_EN | (0067 * 16 + c_timming_b),	// 15

	/* BITMAP */				CPU_EN | (0070 * 16 + c_timming_b),	// 16
	0071 * 16 + c_timming_a,	CPU_EN | (0071 * 16 + c_timming_b),	// 17
	0072 * 16 + c_timming_a,	CPU_EN | (0072 * 16 + c_timming_b),	// 18
	0073 * 16 + c_timming_a,	CPU_EN | (0073 * 16 + c_timming_b),	// 19
	0074 * 16 + c_timming_a,	CPU_EN | (0074 * 16 + c_timming_b),	// 20
	0075 * 16 + c_timming_a,	CPU_EN | (0075 * 16 + c_timming_b),	// 21
	0076 * 16 + c_timming_a,	CPU_EN | (0076 * 16 + c_timming_b),	// 22
	0077 * 16 + c_timming_a,	CPU_EN | (0077 * 16 + c_timming_b),	// 23

	/* BITMAP */				CPU_EN | (0100 * 16 + c_timming_b),	// 24
	0101 * 16 + c_timming_a,	CPU_EN | (0101 * 16 + c_timming_b),	// 25
	0102 * 16 + c_timming_a,	CPU_EN | (0102 * 16 + c_timming_b),	// 26
	0103 * 16 + c_timming_a,	CPU_EN | (0103 * 16 + c_timming_b),	// 27
	0104 * 16 + c_timming_a,	CPU_EN | (0104 * 16 + c_timming_b),	// 28
	0105 * 16 + c_timming_a,	CPU_EN | (0105 * 16 + c_timming_b),	// 29
	0106 * 16 + c_timming_a,	CPU_EN | (0106 * 16 + c_timming_b),	// 30
	0107 * 16 + c_timming_a,	CPU_EN | (0107 * 16 + c_timming_b),	// 31

	/* BITMAP */				CPU_EN | (0110 * 16 + c_timming_b),	// 32
	0111 * 16 + c_timming_a,	CPU_EN | (0111 * 16 + c_timming_b),	// 33
	0112 * 16 + c_timming_a,	CPU_EN | (0112 * 16 + c_timming_b),	// 34
	0113 * 16 + c_timming_a,	CPU_EN | (0113 * 16 + c_timming_b),	// 35
	0114 * 16 + c_timming_a,	CPU_EN | (0114 * 16 + c_timming_b),	// 36
	0115 * 16 + c_timming_a,	CPU_EN | (0115 * 16 + c_timming_b),	// 37
	0116 * 16 + c_timming_a,	CPU_EN | (0116 * 16 + c_timming_b),	// 38
	0117 * 16 + c_timming_a,	CPU_EN | (0117 * 16 + c_timming_b),	// 39

	/* BITMAP */				CPU_EN | (0120 * 16 + c_timming_b),	// 40
	0121 * 16 + c_timming_a,	CPU_EN | (0121 * 16 + c_timming_b),	// 41
	0122 * 16 + c_timming_a,	CPU_EN | (0122 * 16 + c_timming_b),	// 42
	0123 * 16 + c_timming_a,	CPU_EN | (0123 * 16 + c_timming_b),	// 43
	0124 * 16 + c_timming_a,	CPU_EN | (0124 * 16 + c_timming_b),	// 44
	0125 * 16 + c_timming_a,	CPU_EN | (0125 * 16 + c_timming_b),	// 45
	0126 * 16 + c_timming_a,	CPU_EN | (0126 * 16 + c_timming_b),	// 46
	0127 * 16 + c_timming_a,	CPU_EN | (0127 * 16 + c_timming_b),	// 47

	/* BITMAP */				CPU_EN | (0130 * 16 + c_timming_b),	// 48
	0131 * 16 + c_timming_a,	CPU_EN | (0131 * 16 + c_timming_b),	// 49
	0132 * 16 + c_timming_a,	CPU_EN | (0132 * 16 + c_timming_b),	// 50
	0133 * 16 + c_timming_a,	CPU_EN | (0133 * 16 + c_timming_b),	// 51
	0134 * 16 + c_timming_a,	CPU_EN | (0134 * 16 + c_timming_b),	// 52
	0135 * 16 + c_timming_a,	CPU_EN | (0135 * 16 + c_timming_b),	// 53
	0136 * 16 + c_timming_a,	CPU_EN | (0136 * 16 + c_timming_b),	// 54
	0137 * 16 + c_timming_a,	CPU_EN | (0137 * 16 + c_timming_b),	// 55

	/* BITMAP */				CPU_EN | (0140 * 16 + c_timming_b),	// 56
	0141 * 16 + c_timming_a,	CPU_EN | (0141 * 16 + c_timming_b),	// 57
	0142 * 16 + c_timming_a,	CPU_EN | (0142 * 16 + c_timming_b),	// 58
	0143 * 16 + c_timming_a,	CPU_EN | (0143 * 16 + c_timming_b),	// 59
	0144 * 16 + c_timming_a,	CPU_EN | (0144 * 16 + c_timming_b),	// 60
	0145 * 16 + c_timming_a,	CPU_EN | (0145 * 16 + c_timming_b),	// 61
	0146 * 16 + c_timming_a,	CPU_EN | (0146 * 16 + c_timming_b),	// 62
	0147 * 16 + c_timming_a,	CPU_EN | (0147 * 16 + c_timming_b),	// 63

	/* BITMAP */				CPU_EN | (0150 * 16 + c_timming_b),	// 64
	0151 * 16 + c_timming_a,	CPU_EN | (0151 * 16 + c_timming_b),	// 65
	0152 * 16 + c_timming_a,	CPU_EN | (0152 * 16 + c_timming_b),	// 66
	0153 * 16 + c_timming_a,	CPU_EN | (0153 * 16 + c_timming_b),	// 67
	0154 * 16 + c_timming_a,	CPU_EN | (0154 * 16 + c_timming_b),	// 68
	0155 * 16 + c_timming_a,	CPU_EN | (0155 * 16 + c_timming_b),	// 69
	0156 * 16 + c_timming_a,	CPU_EN | (0156 * 16 + c_timming_b),	// 70
	0157 * 16 + c_timming_a,	CPU_EN | (0157 * 16 + c_timming_b),	// 71

	/* BITMAP */				CPU_EN | (0160 * 16 + c_timming_b),	// 72
	0161 * 16 + c_timming_a,	CPU_EN | (0161 * 16 + c_timming_b),	// 73
	0162 * 16 + c_timming_a,	CPU_EN | (0162 * 16 + c_timming_b),	// 74
	0163 * 16 + c_timming_a,	CPU_EN | (0163 * 16 + c_timming_b),	// 75
	0164 * 16 + c_timming_a,	CPU_EN | (0164 * 16 + c_timming_b),	// 76
	0165 * 16 + c_timming_a,	CPU_EN | (0165 * 16 + c_timming_b),	// 77
	0166 * 16 + c_timming_a,	CPU_EN | (0166 * 16 + c_timming_b),	// 78
	0167 * 16 + c_timming_a,	CPU_EN | (0167 * 16 + c_timming_b),	// 79

	/* BITMAP */				CPU_EN | (0170 * 16 + c_timming_b),	// 80
	0171 * 16 + c_timming_a,	CPU_EN | (0171 * 16 + c_timming_b),	// 81
	0172 * 16 + c_timming_a,	CPU_EN | (0172 * 16 + c_timming_b),	// 82
	0173 * 16 + c_timming_a,	CPU_EN | (0173 * 16 + c_timming_b),	// 83
	0174 * 16 + c_timming_a,	CPU_EN | (0174 * 16 + c_timming_b),	// 84
	0175 * 16 + c_timming_a,	CPU_EN | (0175 * 16 + c_timming_b),	// 85
	0176 * 16 + c_timming_a,	CPU_EN | (0176 * 16 + c_timming_b),	// 86
	0177 * 16 + c_timming_a,	CPU_EN | (0177 * 16 + c_timming_b),	// 87

	/* BITMAP */				CPU_EN | (0200 * 16 + c_timming_b),	// 88
	0201 * 16 + c_timming_a,	CPU_EN | (0201 * 16 + c_timming_b),	// 89
	0202 * 16 + c_timming_a,	CPU_EN | (0202 * 16 + c_timming_b),	// 90
	0203 * 16 + c_timming_a,	CPU_EN | (0203 * 16 + c_timming_b),	// 91
	0204 * 16 + c_timming_a,	CPU_EN | (0204 * 16 + c_timming_b),	// 92
	0205 * 16 + c_timming_a,	CPU_EN | (0205 * 16 + c_timming_b),	// 93
	0206 * 16 + c_timming_a,	CPU_EN | (0206 * 16 + c_timming_b),	// 94
	0207 * 16 + c_timming_a,	CPU_EN | (0207 * 16 + c_timming_b),	// 95

	/* BITMAP */				CPU_EN | (0210 * 16 + c_timming_b),	// 96
	0211 * 16 + c_timming_a,	CPU_EN | (0211 * 16 + c_timming_b),	// 97
	0212 * 16 + c_timming_a,	CPU_EN | (0212 * 16 + c_timming_b),	// 98
	0213 * 16 + c_timming_a,	CPU_EN | (0213 * 16 + c_timming_b),	// 99
	0214 * 16 + c_timming_a,	CPU_EN | (0214 * 16 + c_timming_b),	// 100
	0215 * 16 + c_timming_a,	CPU_EN | (0215 * 16 + c_timming_b),	// 101
	0216 * 16 + c_timming_a,	CPU_EN | (0216 * 16 + c_timming_b),	// 102
	0217 * 16 + c_timming_a,	CPU_EN | (0217 * 16 + c_timming_b),	// 103

	/* BITMAP */				CPU_EN | (0220 * 16 + c_timming_b),	// 104
	0221 * 16 + c_timming_a,	CPU_EN | (0221 * 16 + c_timming_b),	// 105
	0222 * 16 + c_timming_a,	CPU_EN | (0222 * 16 + c_timming_b),	// 106
	0223 * 16 + c_timming_a,	CPU_EN | (0223 * 16 + c_timming_b),	// 107
	0224 * 16 + c_timming_a,	CPU_EN | (0224 * 16 + c_timming_b),	// 108
	0225 * 16 + c_timming_a,	CPU_EN | (0225 * 16 + c_timming_b),	// 109
	0226 * 16 + c_timming_a,	CPU_EN | (0226 * 16 + c_timming_b),	// 110
	0227 * 16 + c_timming_a,	CPU_EN | (0227 * 16 + c_timming_b),	// 111

	/* BITMAP */				CPU_EN | (0230 * 16 + c_timming_b),	// 112
	0231 * 16 + c_timming_a,	CPU_EN | (0231 * 16 + c_timming_b),	// 113
	0232 * 16 + c_timming_a,	CPU_EN | (0232 * 16 + c_timming_b),	// 114
	0233 * 16 + c_timming_a,	CPU_EN | (0233 * 16 + c_timming_b),	// 115
	0234 * 16 + c_timming_a,	CPU_EN | (0234 * 16 + c_timming_b),	// 116
	0235 * 16 + c_timming_a,	CPU_EN | (0235 * 16 + c_timming_b),	// 117
	0236 * 16 + c_timming_a,	CPU_EN | (0236 * 16 + c_timming_b),	// 118
	0237 * 16 + c_timming_a,	CPU_EN | (0237 * 16 + c_timming_b),	// 119

	/* BITMAP */				CPU_EN | (0240 * 16 + c_timming_b),	// 120
	0241 * 16 + c_timming_a,	CPU_EN | (0241 * 16 + c_timming_b),	// 121
	0242 * 16 + c_timming_a,	CPU_EN | (0242 * 16 + c_timming_b),	// 122
	0243 * 16 + c_timming_a,	CPU_EN | (0243 * 16 + c_timming_b),	// 123
	0244 * 16 + c_timming_a,	CPU_EN | (0244 * 16 + c_timming_b),	// 124
	0245 * 16 + c_timming_a,	CPU_EN | (0245 * 16 + c_timming_b),	// 125
	0246 * 16 + c_timming_a,	CPU_EN | (0246 * 16 + c_timming_b),	// 126
	0247 * 16 + c_timming_a,	CPU_EN | (0247 * 16 + c_timming_b),	// 127

	/* BITMAP */				CPU_EN | (0250 * 16 + c_timming_b),	// 128
	0251 * 16 + c_timming_a,	CPU_EN | (0251 * 16 + c_timming_b),	// 129
	0252 * 16 + c_timming_a,	CPU_EN | (0252 * 16 + c_timming_b),	// 130
	0253 * 16 + c_timming_a,	CPU_EN | (0253 * 16 + c_timming_b),	// 131
	0254 * 16 + c_timming_a,	CPU_EN | (0254 * 16 + c_timming_b),	// 132
	0255 * 16 + c_timming_a,	CPU_EN | (0255 * 16 + c_timming_b),	// 133
	0256 * 16 + c_timming_a,	CPU_EN | (0256 * 16 + c_timming_b),	// 134
	0257 * 16 + c_timming_a,	CPU_EN | (0257 * 16 + c_timming_b),	// 135

	/* BITMAP */				CPU_EN | (0260 * 16 + c_timming_b),	// 136
	0261 * 16 + c_timming_a,	CPU_EN | (0261 * 16 + c_timming_b),	// 137
	0262 * 16 + c_timming_a,	CPU_EN | (0262 * 16 + c_timming_b),	// 138
	0263 * 16 + c_timming_a,	CPU_EN | (0263 * 16 + c_timming_b),	// 139
	0264 * 16 + c_timming_a,	CPU_EN | (0264 * 16 + c_timming_b),	// 140
	0265 * 16 + c_timming_a,	CPU_EN | (0265 * 16 + c_timming_b),	// 141
	0266 * 16 + c_timming_a,	CPU_EN | (0266 * 16 + c_timming_b),	// 142
	0267 * 16 + c_timming_a,	CPU_EN | (0267 * 16 + c_timming_b),	// 143

	/* BITMAP */				CPU_EN | (0270 * 16 + c_timming_b),	// 144
	0271 * 16 + c_timming_a,	CPU_EN | (0271 * 16 + c_timming_b),	// 145
	0272 * 16 + c_timming_a,	CPU_EN | (0272 * 16 + c_timming_b),	// 146
	0273 * 16 + c_timming_a,	CPU_EN | (0273 * 16 + c_timming_b),	// 147
	0274 * 16 + c_timming_a,	CPU_EN | (0274 * 16 + c_timming_b),	// 148
	0275 * 16 + c_timming_a,	CPU_EN | (0275 * 16 + c_timming_b),	// 149
	0276 * 16 + c_timming_a,	CPU_EN | (0276 * 16 + c_timming_b),	// 150
	0277 * 16 + c_timming_a,	CPU_EN | (0277 * 16 + c_timming_b),	// 151

	/* BITMAP */				CPU_EN | (0300 * 16 + c_timming_b),	// 152
	0301 * 16 + c_timming_a,	CPU_EN | (0301 * 16 + c_timming_b),	// 153
	0302 * 16 + c_timming_a,	CPU_EN | (0302 * 16 + c_timming_b),	// 154
	0303 * 16 + c_timming_a,	CPU_EN | (0303 * 16 + c_timming_b),	// 155
	0304 * 16 + c_timming_a,	CPU_EN | (0304 * 16 + c_timming_b),	// 156
	0305 * 16 + c_timming_a,	CPU_EN | (0305 * 16 + c_timming_b),	// 157
	0306 * 16 + c_timming_a,	CPU_EN | (0306 * 16 + c_timming_b),	// 158
	0307 * 16 + c_timming_a,	CPU_EN | (0307 * 16 + c_timming_b),	// 159

	/* BITMAP */				CPU_EN | (0310 * 16 + c_timming_b),	// 160
	0311 * 16 + c_timming_a,	CPU_EN | (0311 * 16 + c_timming_b),	// 161
	0312 * 16 + c_timming_a,	CPU_EN | (0312 * 16 + c_timming_b),	// 162
	0313 * 16 + c_timming_a,	CPU_EN | (0313 * 16 + c_timming_b),	// 163
	0314 * 16 + c_timming_a,	CPU_EN | (0314 * 16 + c_timming_b),	// 164
	0315 * 16 + c_timming_a,	CPU_EN | (0315 * 16 + c_timming_b),	// 165
	0316 * 16 + c_timming_a,	CPU_EN | (0316 * 16 + c_timming_b),	// 166
	0317 * 16 + c_timming_a,	CPU_EN | (0317 * 16 + c_timming_b),	// 167

	/* BITMAP */				CPU_EN | (0320 * 16 + c_timming_b),	// 168
	0321 * 16 + c_timming_a,	CPU_EN | (0321 * 16 + c_timming_b),	// 169
	0322 * 16 + c_timming_a,	CPU_EN | (0322 * 16 + c_timming_b),	// 170
	0323 * 16 + c_timming_a,	CPU_EN | (0323 * 16 + c_timming_b),	// 171
	0324 * 16 + c_timming_a,	CPU_EN | (0324 * 16 + c_timming_b),	// 172
	0325 * 16 + c_timming_a,	CPU_EN | (0325 * 16 + c_timming_b),	// 173
	0326 * 16 + c_timming_a,	CPU_EN | (0326 * 16 + c_timming_b),	// 174
	0327 * 16 + c_timming_a,	CPU_EN | (0327 * 16 + c_timming_b),	// 175

	/* BITMAP */				CPU_EN | (0330 * 16 + c_timming_b),	// 176
	0331 * 16 + c_timming_a,	CPU_EN | (0331 * 16 + c_timming_b),	// 177
	0332 * 16 + c_timming_a,	CPU_EN | (0332 * 16 + c_timming_b),	// 178
	0333 * 16 + c_timming_a,	CPU_EN | (0333 * 16 + c_timming_b),	// 179
	0334 * 16 + c_timming_a,	CPU_EN | (0334 * 16 + c_timming_b),	// 180
	0335 * 16 + c_timming_a,	CPU_EN | (0335 * 16 + c_timming_b),	// 181
	0336 * 16 + c_timming_a,	CPU_EN | (0336 * 16 + c_timming_b),	// 182
	0337 * 16 + c_timming_a,	CPU_EN | (0337 * 16 + c_timming_b),	// 183

	/* BITMAP */				CPU_EN | (0340 * 16 + c_timming_b),	// 184
	0341 * 16 + c_timming_a,	CPU_EN | (0341 * 16 + c_timming_b),	// 185
	0342 * 16 + c_timming_a,	CPU_EN | (0342 * 16 + c_timming_b),	// 186
	0343 * 16 + c_timming_a,	CPU_EN | (0343 * 16 + c_timming_b),	// 187
	0344 * 16 + c_timming_a,	CPU_EN | (0344 * 16 + c_timming_b),	// 188
	0345 * 16 + c_timming_a,	CPU_EN | (0345 * 16 + c_timming_b),	// 189
	0346 * 16 + c_timming_a,	CPU_EN | (0346 * 16 + c_timming_b),	// 190
	0347 * 16 + c_timming_a,	CPU_EN | (0347 * 16 + c_timming_b),	// 191

	/* BITMAP */				CPU_EN | (0350 * 16 + c_timming_b),	// 192
	0351 * 16 + c_timming_a,	CPU_EN | (0351 * 16 + c_timming_b),	// 193
	0352 * 16 + c_timming_a,	CPU_EN | (0352 * 16 + c_timming_b),	// 194
	0353 * 16 + c_timming_a,	CPU_EN | (0353 * 16 + c_timming_b),	// 195
	0354 * 16 + c_timming_a,	CPU_EN | (0354 * 16 + c_timming_b),	// 196
	0355 * 16 + c_timming_a,	CPU_EN | (0355 * 16 + c_timming_b),	// 197
	0356 * 16 + c_timming_a,	CPU_EN | (0356 * 16 + c_timming_b),	// 198
	0357 * 16 + c_timming_a,	CPU_EN | (0357 * 16 + c_timming_b),	// 199

	/* BITMAP */				CPU_EN | (0360 * 16 + c_timming_b),	// 200
	0361 * 16 + c_timming_a,	CPU_EN | (0361 * 16 + c_timming_b),	// 201
	0362 * 16 + c_timming_a,	CPU_EN | (0362 * 16 + c_timming_b),	// 202
	0363 * 16 + c_timming_a,	CPU_EN | (0363 * 16 + c_timming_b),	// 203
	0364 * 16 + c_timming_a,	CPU_EN | (0364 * 16 + c_timming_b),	// 204
	0365 * 16 + c_timming_a,	CPU_EN | (0365 * 16 + c_timming_b),	// 205
	0366 * 16 + c_timming_a,	CPU_EN | (0366 * 16 + c_timming_b),	// 206
	0367 * 16 + c_timming_a,	CPU_EN | (0367 * 16 + c_timming_b),	// 207

	/* BITMAP */				CPU_EN | (0370 * 16 + c_timming_b),	// 208
	0371 * 16 + c_timming_a,	CPU_EN | (0371 * 16 + c_timming_b),	// 209
	0372 * 16 + c_timming_a,	CPU_EN | (0372 * 16 + c_timming_b),	// 210
	0373 * 16 + c_timming_a,	CPU_EN | (0373 * 16 + c_timming_b),	// 211
	0374 * 16 + c_timming_a,	CPU_EN | (0374 * 16 + c_timming_b),	// 212
	0375 * 16 + c_timming_a,	CPU_EN | (0375 * 16 + c_timming_b),	// 213
	0376 * 16 + c_timming_a,	CPU_EN | (0376 * 16 + c_timming_b),	// 214
	0377 * 16 + c_timming_a,	CPU_EN | (0377 * 16 + c_timming_b),	// 215

	/* BITMAP */				CPU_EN | (0400 * 16 + c_timming_b),	// 216
	0401 * 16 + c_timming_a,	CPU_EN | (0401 * 16 + c_timming_b),	// 217
	0402 * 16 + c_timming_a,	CPU_EN | (0402 * 16 + c_timming_b),	// 218
	0403 * 16 + c_timming_a,	CPU_EN | (0403 * 16 + c_timming_b),	// 219
	0404 * 16 + c_timming_a,	CPU_EN | (0404 * 16 + c_timming_b),	// 220
	0405 * 16 + c_timming_a,	CPU_EN | (0405 * 16 + c_timming_b),	// 221
	0406 * 16 + c_timming_a,	CPU_EN | (0406 * 16 + c_timming_b),	// 222
	0407 * 16 + c_timming_a,	CPU_EN | (0407 * 16 + c_timming_b),	// 223

	/* BITMAP */				CPU_EN | (0410 * 16 + c_timming_b),	// 224
	0411 * 16 + c_timming_a,	CPU_EN | (0411 * 16 + c_timming_b),	// 225
	0412 * 16 + c_timming_a,	CPU_EN | (0412 * 16 + c_timming_b),	// 226
	0413 * 16 + c_timming_a,	CPU_EN | (0413 * 16 + c_timming_b),	// 227
	0414 * 16 + c_timming_a,	CPU_EN | (0414 * 16 + c_timming_b),	// 228
	0415 * 16 + c_timming_a,	CPU_EN | (0415 * 16 + c_timming_b),	// 229
	0416 * 16 + c_timming_a,	CPU_EN | (0416 * 16 + c_timming_b),	// 230
	0417 * 16 + c_timming_a,	CPU_EN | (0417 * 16 + c_timming_b),	// 231

	/* BITMAP */				CPU_EN | (0420 * 16 + c_timming_b),	// 232
	0421 * 16 + c_timming_a,	CPU_EN | (0421 * 16 + c_timming_b),	// 233
	0422 * 16 + c_timming_a,	CPU_EN | (0422 * 16 + c_timming_b),	// 234
	0423 * 16 + c_timming_a,	CPU_EN | (0423 * 16 + c_timming_b),	// 235
	0424 * 16 + c_timming_a,	CPU_EN | (0424 * 16 + c_timming_b),	// 236
	0425 * 16 + c_timming_a,	CPU_EN | (0425 * 16 + c_timming_b),	// 237
	0426 * 16 + c_timming_a,	CPU_EN | (0426 * 16 + c_timming_b),	// 238
	0427 * 16 + c_timming_a,	CPU_EN | (0427 * 16 + c_timming_b),	// 239

	/* BITMAP */				CPU_EN | (0430 * 16 + c_timming_b),	// 240
	0431 * 16 + c_timming_a,	CPU_EN | (0431 * 16 + c_timming_b),	// 241
	0432 * 16 + c_timming_a,	CPU_EN | (0432 * 16 + c_timming_b),	// 242
	0433 * 16 + c_timming_a,	CPU_EN | (0433 * 16 + c_timming_b),	// 243
	0434 * 16 + c_timming_a,	CPU_EN | (0434 * 16 + c_timming_b),	// 244
	0435 * 16 + c_timming_a,	CPU_EN | (0435 * 16 + c_timming_b),	// 245
	0436 * 16 + c_timming_a,	CPU_EN | (0436 * 16 + c_timming_b),	// 246
	0437 * 16 + c_timming_a,	CPU_EN | (0437 * 16 + c_timming_b),	// 247

	0440 * 16 + c_timming_a,	CPU_EN | (0440 * 16 + c_timming_b),	// 248
	0441 * 16 + c_timming_a,	CPU_EN | (0441 * 16 + c_timming_b),	// 249
	0442 * 16 + c_timming_a,	CPU_EN | (0442 * 16 + c_timming_b),	// 250
	0443 * 16 + c_timming_a,	CPU_EN | (0443 * 16 + c_timming_b),	// 251
	0444 * 16 + c_timming_a,	CPU_EN | (0444 * 16 + c_timming_b),	// 252
	0445 * 16 + c_timming_a,	CPU_EN | (0445 * 16 + c_timming_b),	// 253
	0446 * 16 + c_timming_a,	CPU_EN | (0446 * 16 + c_timming_b),	// 254
	0447 * 16 + c_timming_a,	CPU_EN | (0447 * 16 + c_timming_b),	// 255

	0450 * 16 + c_timming_a,	CPU_EN | (0450 * 16 + c_timming_b),	// 256
	0451 * 16 + c_timming_a,	CPU_EN | (0451 * 16 + c_timming_b),	// 257
	0452 * 16 + c_timming_a,	CPU_EN | (0452 * 16 + c_timming_b),	// 258
	0453 * 16 + c_timming_a,	CPU_EN | (0453 * 16 + c_timming_b),	// 259
	0454 * 16 + c_timming_a,	CPU_EN | (0454 * 16 + c_timming_b),	// 260
	0455 * 16 + c_timming_a,	CPU_EN | (0455 * 16 + c_timming_b),	// 261
	0456 * 16 + c_timming_a,	CPU_EN | (0456 * 16 + c_timming_b),	// 262
	0457 * 16 + c_timming_a,	CPU_EN | (0457 * 16 + c_timming_b),	// 263

	0460 * 16 + c_timming_a,	CPU_EN | (0460 * 16 + c_timming_b),	// 264
	0461 * 16 + c_timming_a,	CPU_EN | (0461 * 16 + c_timming_b),	// 265
	0462 * 16 + c_timming_a,	CPU_EN | (0462 * 16 + c_timming_b),	// 266
	0463 * 16 + c_timming_a,	CPU_EN | (0463 * 16 + c_timming_b),	// 267
	0464 * 16 + c_timming_a,	CPU_EN | (0464 * 16 + c_timming_b),	// 268
	0465 * 16 + c_timming_a,	CPU_EN | (0465 * 16 + c_timming_b),	// 269
	0466 * 16 + c_timming_a,	CPU_EN | (0466 * 16 + c_timming_b),	// 270
	0467 * 16 + c_timming_a,	CPU_EN | (0467 * 16 + c_timming_b),	// 271

	0470 * 16 + c_timming_a,	CPU_EN | (0470 * 16 + c_timming_b),	// 272
	0471 * 16 + c_timming_a,	CPU_EN | (0471 * 16 + c_timming_b),	// 273
	0472 * 16 + c_timming_a,	CPU_EN | (0472 * 16 + c_timming_b),	// 274
	0473 * 16 + c_timming_a,	CPU_EN | (0473 * 16 + c_timming_b),	// 275
	0474 * 16 + c_timming_a,	CPU_EN | (0474 * 16 + c_timming_b),	// 276
	0475 * 16 + c_timming_a,	CPU_EN | (0475 * 16 + c_timming_b),	// 277
	0476 * 16 + c_timming_a,	CPU_EN | (0476 * 16 + c_timming_b),	// 278
	0477 * 16 + c_timming_a,	CPU_EN | (0477 * 16 + c_timming_b),	// 279

	0500 * 16 + c_timming_a,	CPU_EN | (0500 * 16 + c_timming_b),	// 280
	0501 * 16 + c_timming_a,	CPU_EN | (0501 * 16 + c_timming_b),	// 281
	0502 * 16 + c_timming_a,	CPU_EN | (0502 * 16 + c_timming_b),	// 282
	0503 * 16 + c_timming_a,	CPU_EN | (0503 * 16 + c_timming_b),	// 283
	0504 * 16 + c_timming_a,	CPU_EN | (0504 * 16 + c_timming_b),	// 284
	0505 * 16 + c_timming_a,	CPU_EN | (0505 * 16 + c_timming_b),	// 285
	0506 * 16 + c_timming_a,	CPU_EN | (0506 * 16 + c_timming_b),	// 286
	0507 * 16 + c_timming_a,	CPU_EN | (0507 * 16 + c_timming_b),	// 287

	0510 * 16 + c_timming_a,	CPU_EN | (0510 * 16 + c_timming_b),	// 288
	0511 * 16 + c_timming_a,	CPU_EN | (0511 * 16 + c_timming_b),	// 289
	0512 * 16 + c_timming_a,	CPU_EN | (0512 * 16 + c_timming_b),	// 290
	0513 * 16 + c_timming_a,	CPU_EN | (0513 * 16 + c_timming_b),	// 291
	0514 * 16 + c_timming_a,	CPU_EN | (0514 * 16 + c_timming_b),	// 292
	0515 * 16 + c_timming_a,	CPU_EN | (0515 * 16 + c_timming_b),	// 293
	0516 * 16 + c_timming_a,	CPU_EN | (0516 * 16 + c_timming_b),	// 294
	0517 * 16 + c_timming_a,	CPU_EN | (0517 * 16 + c_timming_b),	// 295

	0520 * 16 + c_timming_a,	CPU_EN | (0520 * 16 + c_timming_b),	// 296
	0521 * 16 + c_timming_a,	CPU_EN | (0521 * 16 + c_timming_b),	// 297
	0522 * 16 + c_timming_a,	CPU_EN | (0522 * 16 + c_timming_b),	// 298
	0523 * 16 + c_timming_a,	CPU_EN | (0523 * 16 + c_timming_b),	// 299
	0524 * 16 + c_timming_a,	CPU_EN | (0524 * 16 + c_timming_b),	// 300
	0525 * 16 + c_timming_a,	CPU_EN | (0525 * 16 + c_timming_b),	// 301

	0526 * 16 + c_timming_a,	CPU_EN | (0526 * 16 + c_timming_b),	// -40
	0527 * 16 + c_timming_a,	CPU_EN | (0527 * 16 + c_timming_b),	// -39
	0530 * 16 + c_timming_a,	CPU_EN | (0530 * 16 + c_timming_b),	// -38
	0531 * 16 + c_timming_a,	CPU_EN | (0531 * 16 + c_timming_b),	// -37
	0532 * 16 + c_timming_a,	CPU_EN | (0532 * 16 + c_timming_b),	// -36
	0533 * 16 + c_timming_a,	CPU_EN | (0533 * 16 + c_timming_b),	// -35
	0534 * 16 + c_timming_a,	CPU_EN | (0534 * 16 + c_timming_b),	// -34
	0535 * 16 + c_timming_a,	CPU_EN | (0535 * 16 + c_timming_b),	// -33

	/* REFRESH */													// -32
	0537 * 16 + c_timming_a,	CPU_EN | (0537 * 16 + c_timming_b)	// -31
};

// screen 5,6
static constexpr std::array<int16_t, 700-32-44> slotsV9968BitmapLowSpritesOn = {
	0000 * 16 + c_timming_a,	CPU_EN | (0000 * 16 + c_timming_b),	// -40
	0001 * 16 + c_timming_a,	CPU_EN | (0001 * 16 + c_timming_b),	// -39
	/* SPRITE */				CPU_EN | (0002 * 16 + c_timming_b),	// -38
	0003 * 16 + c_timming_a,	CPU_EN | (0003 * 16 + c_timming_b),	// -37
	0004 * 16 + c_timming_a,	CPU_EN | (0004 * 16 + c_timming_b),	// -36
	0005 * 16 + c_timming_a,	CPU_EN | (0005 * 16 + c_timming_b),	// -35
	0006 * 16 + c_timming_a,	CPU_EN | (0006 * 16 + c_timming_b),	// -34
	0007 * 16 + c_timming_a,	CPU_EN | (0007 * 16 + c_timming_b),	// -33

	/* REFRESH */											// -32
	0011 * 16 + c_timming_a,	CPU_EN | (0011 * 16 + c_timming_b),	// -31
	/* SPRITE */				CPU_EN | (0012 * 16 + c_timming_b),	// -30
	0013 * 16 + c_timming_a,	CPU_EN | (0013 * 16 + c_timming_b),	// -29
	0014 * 16 + c_timming_a,	CPU_EN | (0014 * 16 + c_timming_b),	// -28
	0015 * 16 + c_timming_a,	CPU_EN | (0015 * 16 + c_timming_b),	// -27
	0016 * 16 + c_timming_a,	CPU_EN | (0016 * 16 + c_timming_b),	// -26
	0017 * 16 + c_timming_a,	CPU_EN | (0017 * 16 + c_timming_b),	// -25

	0020 * 16 + c_timming_a,	CPU_EN | (0020 * 16 + c_timming_b),	// -24
	0021 * 16 + c_timming_a,	CPU_EN | (0021 * 16 + c_timming_b),	// -23
	/* SPRITE */				CPU_EN | (0022 * 16 + c_timming_b),	// -22
	0023 * 16 + c_timming_a,	CPU_EN | (0023 * 16 + c_timming_b),	// -21
	0024 * 16 + c_timming_a,	CPU_EN | (0024 * 16 + c_timming_b),	// -20
	0025 * 16 + c_timming_a,	CPU_EN | (0025 * 16 + c_timming_b),	// -19
	0026 * 16 + c_timming_a,	CPU_EN | (0026 * 16 + c_timming_b),	// -18
	0027 * 16 + c_timming_a,	CPU_EN | (0027 * 16 + c_timming_b),	// -17

	0030 * 16 + c_timming_a,	CPU_EN | (0030 * 16 + c_timming_b),	// -16
	0031 * 16 + c_timming_a,	CPU_EN | (0031 * 16 + c_timming_b),	// -15
	/* SPRITE */				CPU_EN | (0032 * 16 + c_timming_b),	// -14
	0033 * 16 + c_timming_a,	CPU_EN | (0033 * 16 + c_timming_b),	// -13
	0034 * 16 + c_timming_a,	CPU_EN | (0034 * 16 + c_timming_b),	// -12
	0035 * 16 + c_timming_a,	CPU_EN | (0035 * 16 + c_timming_b),	// -11
	0036 * 16 + c_timming_a,	CPU_EN | (0036 * 16 + c_timming_b),	// -10
	0037 * 16 + c_timming_a,	CPU_EN | (0037 * 16 + c_timming_b),	// -9

	/* BITMAP */				CPU_EN | (0040 * 16 + c_timming_b),	// -8
	0041 * 16 + c_timming_a,	CPU_EN | (0041 * 16 + c_timming_b),	// -7
	/* SPRITE */				CPU_EN | (0042 * 16 + c_timming_b),	// -6
	0043 * 16 + c_timming_a,	CPU_EN | (0043 * 16 + c_timming_b),	// -5
	0044 * 16 + c_timming_a,	CPU_EN | (0044 * 16 + c_timming_b),	// -4
	0045 * 16 + c_timming_a,	CPU_EN | (0045 * 16 + c_timming_b),	// -3
	0046 * 16 + c_timming_a,	CPU_EN | (0046 * 16 + c_timming_b),	// -2
	0047 * 16 + c_timming_a,	CPU_EN | (0047 * 16 + c_timming_b),	// -1

	/* BITMAP */				CPU_EN | (0050 * 16 + c_timming_b),	// 0
	0051 * 16 + c_timming_a,	CPU_EN | (0051 * 16 + c_timming_b),	// 1
	/* SPRITE */				CPU_EN | (0052 * 16 + c_timming_b),	// 2
	0053 * 16 + c_timming_a,	CPU_EN | (0053 * 16 + c_timming_b),	// 3
	0054 * 16 + c_timming_a,	CPU_EN | (0054 * 16 + c_timming_b),	// 4
	0055 * 16 + c_timming_a,	CPU_EN | (0055 * 16 + c_timming_b),	// 5
	0056 * 16 + c_timming_a,	CPU_EN | (0056 * 16 + c_timming_b),	// 6
	0057 * 16 + c_timming_a,	CPU_EN | (0057 * 16 + c_timming_b),	// 7

	/* BITMAP */				CPU_EN | (0060 * 16 + c_timming_b),	// 8
	0061 * 16 + c_timming_a,	CPU_EN | (0061 * 16 + c_timming_b),	// 9
	/* SPRITE */				CPU_EN | (0062 * 16 + c_timming_b),	// 10
	0063 * 16 + c_timming_a,	CPU_EN | (0063 * 16 + c_timming_b),	// 11
	0064 * 16 + c_timming_a,	CPU_EN | (0064 * 16 + c_timming_b),	// 12
	0065 * 16 + c_timming_a,	CPU_EN | (0065 * 16 + c_timming_b),	// 13
	0066 * 16 + c_timming_a,	CPU_EN | (0066 * 16 + c_timming_b),	// 14
	0067 * 16 + c_timming_a,	CPU_EN | (0067 * 16 + c_timming_b),	// 15

	/* BITMAP */				CPU_EN | (0070 * 16 + c_timming_b),	// 16
	0071 * 16 + c_timming_a,	CPU_EN | (0071 * 16 + c_timming_b),	// 17
	/* SPRITE */				CPU_EN | (0072 * 16 + c_timming_b),	// 18
	0073 * 16 + c_timming_a,	CPU_EN | (0073 * 16 + c_timming_b),	// 19
	0074 * 16 + c_timming_a,	CPU_EN | (0074 * 16 + c_timming_b),	// 20
	0075 * 16 + c_timming_a,	CPU_EN | (0075 * 16 + c_timming_b),	// 21
	0076 * 16 + c_timming_a,	CPU_EN | (0076 * 16 + c_timming_b),	// 22
	0077 * 16 + c_timming_a,	CPU_EN | (0077 * 16 + c_timming_b),	// 23

	/* BITMAP */				CPU_EN | (0100 * 16 + c_timming_b),	// 24
	0101 * 16 + c_timming_a,	CPU_EN | (0101 * 16 + c_timming_b),	// 25
	/* SPRITE */				CPU_EN | (0102 * 16 + c_timming_b),	// 26
	0103 * 16 + c_timming_a,	CPU_EN | (0103 * 16 + c_timming_b),	// 27
	0104 * 16 + c_timming_a,	CPU_EN | (0104 * 16 + c_timming_b),	// 28
	0105 * 16 + c_timming_a,	CPU_EN | (0105 * 16 + c_timming_b),	// 29
	0106 * 16 + c_timming_a,	CPU_EN | (0106 * 16 + c_timming_b),	// 30
	0107 * 16 + c_timming_a,	CPU_EN | (0107 * 16 + c_timming_b),	// 31

	/* BITMAP */				CPU_EN | (0110 * 16 + c_timming_b),	// 32
	0111 * 16 + c_timming_a,	CPU_EN | (0111 * 16 + c_timming_b),	// 33
	/* SPRITE */				CPU_EN | (0112 * 16 + c_timming_b),	// 34
	0113 * 16 + c_timming_a,	CPU_EN | (0113 * 16 + c_timming_b),	// 35
	0114 * 16 + c_timming_a,	CPU_EN | (0114 * 16 + c_timming_b),	// 36
	0115 * 16 + c_timming_a,	CPU_EN | (0115 * 16 + c_timming_b),	// 37
	0116 * 16 + c_timming_a,	CPU_EN | (0116 * 16 + c_timming_b),	// 38
	0117 * 16 + c_timming_a,	CPU_EN | (0117 * 16 + c_timming_b),	// 39

	/* BITMAP */				CPU_EN | (0120 * 16 + c_timming_b),	// 40
	0121 * 16 + c_timming_a,	CPU_EN | (0121 * 16 + c_timming_b),	// 41
	/* SPRITE */				CPU_EN | (0122 * 16 + c_timming_b),	// 42
	0123 * 16 + c_timming_a,	CPU_EN | (0123 * 16 + c_timming_b),	// 43
	0124 * 16 + c_timming_a,	CPU_EN | (0124 * 16 + c_timming_b),	// 44
	0125 * 16 + c_timming_a,	CPU_EN | (0125 * 16 + c_timming_b),	// 45
	0126 * 16 + c_timming_a,	CPU_EN | (0126 * 16 + c_timming_b),	// 46
	0127 * 16 + c_timming_a,	CPU_EN | (0127 * 16 + c_timming_b),	// 47

	/* BITMAP */				CPU_EN | (0130 * 16 + c_timming_b),	// 48
	0131 * 16 + c_timming_a,	CPU_EN | (0131 * 16 + c_timming_b),	// 49
	/* SPRITE */				CPU_EN | (0132 * 16 + c_timming_b),	// 50
	0133 * 16 + c_timming_a,	CPU_EN | (0133 * 16 + c_timming_b),	// 51
	0134 * 16 + c_timming_a,	CPU_EN | (0134 * 16 + c_timming_b),	// 52
	0135 * 16 + c_timming_a,	CPU_EN | (0135 * 16 + c_timming_b),	// 53
	0136 * 16 + c_timming_a,	CPU_EN | (0136 * 16 + c_timming_b),	// 54
	0137 * 16 + c_timming_a,	CPU_EN | (0137 * 16 + c_timming_b),	// 55

	/* BITMAP */				CPU_EN | (0140 * 16 + c_timming_b),	// 56
	0141 * 16 + c_timming_a,	CPU_EN | (0141 * 16 + c_timming_b),	// 57
	/* SPRITE */				CPU_EN | (0142 * 16 + c_timming_b),	// 58
	0143 * 16 + c_timming_a,	CPU_EN | (0143 * 16 + c_timming_b),	// 59
	0144 * 16 + c_timming_a,	CPU_EN | (0144 * 16 + c_timming_b),	// 60
	0145 * 16 + c_timming_a,	CPU_EN | (0145 * 16 + c_timming_b),	// 61
	0146 * 16 + c_timming_a,	CPU_EN | (0146 * 16 + c_timming_b),	// 62
	0147 * 16 + c_timming_a,	CPU_EN | (0147 * 16 + c_timming_b),	// 63

	/* BITMAP */				CPU_EN | (0150 * 16 + c_timming_b),	// 64
	0151 * 16 + c_timming_a,	CPU_EN | (0151 * 16 + c_timming_b),	// 65
	/* SPRITE */				CPU_EN | (0152 * 16 + c_timming_b),	// 66
	0153 * 16 + c_timming_a,	CPU_EN | (0153 * 16 + c_timming_b),	// 67
	0154 * 16 + c_timming_a,	CPU_EN | (0154 * 16 + c_timming_b),	// 68
	0155 * 16 + c_timming_a,	CPU_EN | (0155 * 16 + c_timming_b),	// 69
	0156 * 16 + c_timming_a,	CPU_EN | (0156 * 16 + c_timming_b),	// 70
	0157 * 16 + c_timming_a,	CPU_EN | (0157 * 16 + c_timming_b),	// 71

	/* BITMAP */				CPU_EN | (0160 * 16 + c_timming_b),	// 72
	0161 * 16 + c_timming_a,	CPU_EN | (0161 * 16 + c_timming_b),	// 73
	/* SPRITE */				CPU_EN | (0162 * 16 + c_timming_b),	// 74
	0163 * 16 + c_timming_a,	CPU_EN | (0163 * 16 + c_timming_b),	// 75
	0164 * 16 + c_timming_a,	CPU_EN | (0164 * 16 + c_timming_b),	// 76
	0165 * 16 + c_timming_a,	CPU_EN | (0165 * 16 + c_timming_b),	// 77
	0166 * 16 + c_timming_a,	CPU_EN | (0166 * 16 + c_timming_b),	// 78
	0167 * 16 + c_timming_a,	CPU_EN | (0167 * 16 + c_timming_b),	// 79

	/* BITMAP */				CPU_EN | (0170 * 16 + c_timming_b),	// 80
	0171 * 16 + c_timming_a,	CPU_EN | (0171 * 16 + c_timming_b),	// 81
	/* SPRITE */				CPU_EN | (0172 * 16 + c_timming_b),	// 82
	0173 * 16 + c_timming_a,	CPU_EN | (0173 * 16 + c_timming_b),	// 83
	0174 * 16 + c_timming_a,	CPU_EN | (0174 * 16 + c_timming_b),	// 84
	0175 * 16 + c_timming_a,	CPU_EN | (0175 * 16 + c_timming_b),	// 85
	0176 * 16 + c_timming_a,	CPU_EN | (0176 * 16 + c_timming_b),	// 86
	0177 * 16 + c_timming_a,	CPU_EN | (0177 * 16 + c_timming_b),	// 87

	/* BITMAP */				CPU_EN | (0200 * 16 + c_timming_b),	// 88
	0201 * 16 + c_timming_a,	CPU_EN | (0201 * 16 + c_timming_b),	// 89
	/* SPRITE */				CPU_EN | (0202 * 16 + c_timming_b),	// 90
	0203 * 16 + c_timming_a,	CPU_EN | (0203 * 16 + c_timming_b),	// 91
	0204 * 16 + c_timming_a,	CPU_EN | (0204 * 16 + c_timming_b),	// 92
	0205 * 16 + c_timming_a,	CPU_EN | (0205 * 16 + c_timming_b),	// 93
	0206 * 16 + c_timming_a,	CPU_EN | (0206 * 16 + c_timming_b),	// 94
	0207 * 16 + c_timming_a,	CPU_EN | (0207 * 16 + c_timming_b),	// 95

	/* BITMAP */				CPU_EN | (0210 * 16 + c_timming_b),	// 96
	0211 * 16 + c_timming_a,	CPU_EN | (0211 * 16 + c_timming_b),	// 97
	/* SPRITE */				CPU_EN | (0212 * 16 + c_timming_b),	// 98
	0213 * 16 + c_timming_a,	CPU_EN | (0213 * 16 + c_timming_b),	// 99
	0214 * 16 + c_timming_a,	CPU_EN | (0214 * 16 + c_timming_b),	// 100
	0215 * 16 + c_timming_a,	CPU_EN | (0215 * 16 + c_timming_b),	// 101
	0216 * 16 + c_timming_a,	CPU_EN | (0216 * 16 + c_timming_b),	// 102
	0217 * 16 + c_timming_a,	CPU_EN | (0217 * 16 + c_timming_b),	// 103

	/* BITMAP */				CPU_EN | (0220 * 16 + c_timming_b),	// 104
	0221 * 16 + c_timming_a,	CPU_EN | (0221 * 16 + c_timming_b),	// 105
	/* SPRITE */				CPU_EN | (0222 * 16 + c_timming_b),	// 106
	0223 * 16 + c_timming_a,	CPU_EN | (0223 * 16 + c_timming_b),	// 107
	0224 * 16 + c_timming_a,	CPU_EN | (0224 * 16 + c_timming_b),	// 108
	0225 * 16 + c_timming_a,	CPU_EN | (0225 * 16 + c_timming_b),	// 109
	0226 * 16 + c_timming_a,	CPU_EN | (0226 * 16 + c_timming_b),	// 110
	0227 * 16 + c_timming_a,	CPU_EN | (0227 * 16 + c_timming_b),	// 111

	/* BITMAP */				CPU_EN | (0230 * 16 + c_timming_b),	// 112
	0231 * 16 + c_timming_a,	CPU_EN | (0231 * 16 + c_timming_b),	// 113
	/* SPRITE */				CPU_EN | (0232 * 16 + c_timming_b),	// 114
	0233 * 16 + c_timming_a,	CPU_EN | (0233 * 16 + c_timming_b),	// 115
	0234 * 16 + c_timming_a,	CPU_EN | (0234 * 16 + c_timming_b),	// 116
	0235 * 16 + c_timming_a,	CPU_EN | (0235 * 16 + c_timming_b),	// 117
	0236 * 16 + c_timming_a,	CPU_EN | (0236 * 16 + c_timming_b),	// 118
	0237 * 16 + c_timming_a,	CPU_EN | (0237 * 16 + c_timming_b),	// 119

	/* BITMAP */				CPU_EN | (0240 * 16 + c_timming_b),	// 120
	0241 * 16 + c_timming_a,	CPU_EN | (0241 * 16 + c_timming_b),	// 121
	/* SPRITE */				CPU_EN | (0242 * 16 + c_timming_b),	// 122
	0243 * 16 + c_timming_a,	CPU_EN | (0243 * 16 + c_timming_b),	// 123
	0244 * 16 + c_timming_a,	CPU_EN | (0244 * 16 + c_timming_b),	// 124
	0245 * 16 + c_timming_a,	CPU_EN | (0245 * 16 + c_timming_b),	// 125
	0246 * 16 + c_timming_a,	CPU_EN | (0246 * 16 + c_timming_b),	// 126
	0247 * 16 + c_timming_a,	CPU_EN | (0247 * 16 + c_timming_b),	// 127

	/* BITMAP */				CPU_EN | (0250 * 16 + c_timming_b),	// 128
	0251 * 16 + c_timming_a,	CPU_EN | (0251 * 16 + c_timming_b),	// 129
	/* SPRITE */				CPU_EN | (0252 * 16 + c_timming_b),	// 130
	0253 * 16 + c_timming_a,	CPU_EN | (0253 * 16 + c_timming_b),	// 131
	0254 * 16 + c_timming_a,	CPU_EN | (0254 * 16 + c_timming_b),	// 132
	0255 * 16 + c_timming_a,	CPU_EN | (0255 * 16 + c_timming_b),	// 133
	0256 * 16 + c_timming_a,	CPU_EN | (0256 * 16 + c_timming_b),	// 134
	0257 * 16 + c_timming_a,	CPU_EN | (0257 * 16 + c_timming_b),	// 135

	/* BITMAP */				CPU_EN | (0260 * 16 + c_timming_b),	// 136
	0261 * 16 + c_timming_a,	CPU_EN | (0261 * 16 + c_timming_b),	// 137
	/* SPRITE */				CPU_EN | (0262 * 16 + c_timming_b),	// 138
	0263 * 16 + c_timming_a,	CPU_EN | (0263 * 16 + c_timming_b),	// 139
	0264 * 16 + c_timming_a,	CPU_EN | (0264 * 16 + c_timming_b),	// 140
	0265 * 16 + c_timming_a,	CPU_EN | (0265 * 16 + c_timming_b),	// 141
	0266 * 16 + c_timming_a,	CPU_EN | (0266 * 16 + c_timming_b),	// 142
	0267 * 16 + c_timming_a,	CPU_EN | (0267 * 16 + c_timming_b),	// 143

	/* BITMAP */				CPU_EN | (0270 * 16 + c_timming_b),	// 144
	0271 * 16 + c_timming_a,	CPU_EN | (0271 * 16 + c_timming_b),	// 145
	/* SPRITE */				CPU_EN | (0272 * 16 + c_timming_b),	// 146
	0273 * 16 + c_timming_a,	CPU_EN | (0273 * 16 + c_timming_b),	// 147
	0274 * 16 + c_timming_a,	CPU_EN | (0274 * 16 + c_timming_b),	// 148
	0275 * 16 + c_timming_a,	CPU_EN | (0275 * 16 + c_timming_b),	// 149
	0276 * 16 + c_timming_a,	CPU_EN | (0276 * 16 + c_timming_b),	// 150
	0277 * 16 + c_timming_a,	CPU_EN | (0277 * 16 + c_timming_b),	// 151

	/* BITMAP */				CPU_EN | (0300 * 16 + c_timming_b),	// 152
	0301 * 16 + c_timming_a,	CPU_EN | (0301 * 16 + c_timming_b),	// 153
	/* SPRITE */				CPU_EN | (0302 * 16 + c_timming_b),	// 154
	0303 * 16 + c_timming_a,	CPU_EN | (0303 * 16 + c_timming_b),	// 155
	0304 * 16 + c_timming_a,	CPU_EN | (0304 * 16 + c_timming_b),	// 156
	0305 * 16 + c_timming_a,	CPU_EN | (0305 * 16 + c_timming_b),	// 157
	0306 * 16 + c_timming_a,	CPU_EN | (0306 * 16 + c_timming_b),	// 158
	0307 * 16 + c_timming_a,	CPU_EN | (0307 * 16 + c_timming_b),	// 159

	/* BITMAP */				CPU_EN | (0310 * 16 + c_timming_b),	// 160
	0311 * 16 + c_timming_a,	CPU_EN | (0311 * 16 + c_timming_b),	// 161
	/* SPRITE */				CPU_EN | (0312 * 16 + c_timming_b),	// 162
	0313 * 16 + c_timming_a,	CPU_EN | (0313 * 16 + c_timming_b),	// 163
	0314 * 16 + c_timming_a,	CPU_EN | (0314 * 16 + c_timming_b),	// 164
	0315 * 16 + c_timming_a,	CPU_EN | (0315 * 16 + c_timming_b),	// 165
	0316 * 16 + c_timming_a,	CPU_EN | (0316 * 16 + c_timming_b),	// 166
	0317 * 16 + c_timming_a,	CPU_EN | (0317 * 16 + c_timming_b),	// 167

	/* BITMAP */				CPU_EN | (0320 * 16 + c_timming_b),	// 168
	0321 * 16 + c_timming_a,	CPU_EN | (0321 * 16 + c_timming_b),	// 169
	/* SPRITE */				CPU_EN | (0322 * 16 + c_timming_b),	// 170
	0323 * 16 + c_timming_a,	CPU_EN | (0323 * 16 + c_timming_b),	// 171
	0324 * 16 + c_timming_a,	CPU_EN | (0324 * 16 + c_timming_b),	// 172
	0325 * 16 + c_timming_a,	CPU_EN | (0325 * 16 + c_timming_b),	// 173
	0326 * 16 + c_timming_a,	CPU_EN | (0326 * 16 + c_timming_b),	// 174
	0327 * 16 + c_timming_a,	CPU_EN | (0327 * 16 + c_timming_b),	// 175

	/* BITMAP */				CPU_EN | (0330 * 16 + c_timming_b),	// 176
	0331 * 16 + c_timming_a,	CPU_EN | (0331 * 16 + c_timming_b),	// 177
	/* SPRITE */				CPU_EN | (0332 * 16 + c_timming_b),	// 178
	0333 * 16 + c_timming_a,	CPU_EN | (0333 * 16 + c_timming_b),	// 179
	0334 * 16 + c_timming_a,	CPU_EN | (0334 * 16 + c_timming_b),	// 180
	0335 * 16 + c_timming_a,	CPU_EN | (0335 * 16 + c_timming_b),	// 181
	0336 * 16 + c_timming_a,	CPU_EN | (0336 * 16 + c_timming_b),	// 182
	0337 * 16 + c_timming_a,	CPU_EN | (0337 * 16 + c_timming_b),	// 183

	/* BITMAP */				CPU_EN | (0340 * 16 + c_timming_b),	// 184
	0341 * 16 + c_timming_a,	CPU_EN | (0341 * 16 + c_timming_b),	// 185
	/* SPRITE */				CPU_EN | (0342 * 16 + c_timming_b),	// 186
	0343 * 16 + c_timming_a,	CPU_EN | (0343 * 16 + c_timming_b),	// 187
	0344 * 16 + c_timming_a,	CPU_EN | (0344 * 16 + c_timming_b),	// 188
	0345 * 16 + c_timming_a,	CPU_EN | (0345 * 16 + c_timming_b),	// 189
	0346 * 16 + c_timming_a,	CPU_EN | (0346 * 16 + c_timming_b),	// 190
	0347 * 16 + c_timming_a,	CPU_EN | (0347 * 16 + c_timming_b),	// 191

	/* BITMAP */				CPU_EN | (0350 * 16 + c_timming_b),	// 192
	0351 * 16 + c_timming_a,	CPU_EN | (0351 * 16 + c_timming_b),	// 193
	/* SPRITE */				CPU_EN | (0352 * 16 + c_timming_b),	// 194
	0353 * 16 + c_timming_a,	CPU_EN | (0353 * 16 + c_timming_b),	// 195
	0354 * 16 + c_timming_a,	CPU_EN | (0354 * 16 + c_timming_b),	// 196
	0355 * 16 + c_timming_a,	CPU_EN | (0355 * 16 + c_timming_b),	// 197
	0356 * 16 + c_timming_a,	CPU_EN | (0356 * 16 + c_timming_b),	// 198
	0357 * 16 + c_timming_a,	CPU_EN | (0357 * 16 + c_timming_b),	// 199

	/* BITMAP */				CPU_EN | (0360 * 16 + c_timming_b),	// 200
	0361 * 16 + c_timming_a,	CPU_EN | (0361 * 16 + c_timming_b),	// 201
	/* SPRITE */				CPU_EN | (0362 * 16 + c_timming_b),	// 202
	0363 * 16 + c_timming_a,	CPU_EN | (0363 * 16 + c_timming_b),	// 203
	0364 * 16 + c_timming_a,	CPU_EN | (0364 * 16 + c_timming_b),	// 204
	0365 * 16 + c_timming_a,	CPU_EN | (0365 * 16 + c_timming_b),	// 205
	0366 * 16 + c_timming_a,	CPU_EN | (0366 * 16 + c_timming_b),	// 206
	0367 * 16 + c_timming_a,	CPU_EN | (0367 * 16 + c_timming_b),	// 207

	/* BITMAP */				CPU_EN | (0370 * 16 + c_timming_b),	// 208
	0371 * 16 + c_timming_a,	CPU_EN | (0371 * 16 + c_timming_b),	// 209
	/* SPRITE */				CPU_EN | (0372 * 16 + c_timming_b),	// 210
	0373 * 16 + c_timming_a,	CPU_EN | (0373 * 16 + c_timming_b),	// 211
	0374 * 16 + c_timming_a,	CPU_EN | (0374 * 16 + c_timming_b),	// 212
	0375 * 16 + c_timming_a,	CPU_EN | (0375 * 16 + c_timming_b),	// 213
	0376 * 16 + c_timming_a,	CPU_EN | (0376 * 16 + c_timming_b),	// 214
	0377 * 16 + c_timming_a,	CPU_EN | (0377 * 16 + c_timming_b),	// 215

	/* BITMAP */				CPU_EN | (0400 * 16 + c_timming_b),	// 216
	0401 * 16 + c_timming_a,	CPU_EN | (0401 * 16 + c_timming_b),	// 217
	/* SPRITE */				CPU_EN | (0402 * 16 + c_timming_b),	// 218
	0403 * 16 + c_timming_a,	CPU_EN | (0403 * 16 + c_timming_b),	// 219
	0404 * 16 + c_timming_a,	CPU_EN | (0404 * 16 + c_timming_b),	// 220
	0405 * 16 + c_timming_a,	CPU_EN | (0405 * 16 + c_timming_b),	// 221
	0406 * 16 + c_timming_a,	CPU_EN | (0406 * 16 + c_timming_b),	// 222
	0407 * 16 + c_timming_a,	CPU_EN | (0407 * 16 + c_timming_b),	// 223

	/* BITMAP */				CPU_EN | (0410 * 16 + c_timming_b),	// 224
	0411 * 16 + c_timming_a,	CPU_EN | (0411 * 16 + c_timming_b),	// 225
	/* SPRITE */				CPU_EN | (0412 * 16 + c_timming_b),	// 226
	0413 * 16 + c_timming_a,	CPU_EN | (0413 * 16 + c_timming_b),	// 227
	0414 * 16 + c_timming_a,	CPU_EN | (0414 * 16 + c_timming_b),	// 228
	0415 * 16 + c_timming_a,	CPU_EN | (0415 * 16 + c_timming_b),	// 229
	0416 * 16 + c_timming_a,	CPU_EN | (0416 * 16 + c_timming_b),	// 230
	0417 * 16 + c_timming_a,	CPU_EN | (0417 * 16 + c_timming_b),	// 231

	/* BITMAP */				CPU_EN | (0420 * 16 + c_timming_b),	// 232
	0421 * 16 + c_timming_a,	CPU_EN | (0421 * 16 + c_timming_b),	// 233
	/* SPRITE */				CPU_EN | (0422 * 16 + c_timming_b),	// 234
	0423 * 16 + c_timming_a,	CPU_EN | (0423 * 16 + c_timming_b),	// 235
	0424 * 16 + c_timming_a,	CPU_EN | (0424 * 16 + c_timming_b),	// 236
	0425 * 16 + c_timming_a,	CPU_EN | (0425 * 16 + c_timming_b),	// 237
	0426 * 16 + c_timming_a,	CPU_EN | (0426 * 16 + c_timming_b),	// 238
	0427 * 16 + c_timming_a,	CPU_EN | (0427 * 16 + c_timming_b),	// 239

	/* BITMAP */				CPU_EN | (0430 * 16 + c_timming_b),	// 240
	0431 * 16 + c_timming_a,	CPU_EN | (0431 * 16 + c_timming_b),	// 241
	/* SPRITE */				CPU_EN | (0432 * 16 + c_timming_b),	// 218
	0433 * 16 + c_timming_a,	CPU_EN | (0433 * 16 + c_timming_b),	// 243
	0434 * 16 + c_timming_a,	CPU_EN | (0434 * 16 + c_timming_b),	// 244
	0435 * 16 + c_timming_a,	CPU_EN | (0435 * 16 + c_timming_b),	// 245
	0436 * 16 + c_timming_a,	CPU_EN | (0436 * 16 + c_timming_b),	// 246
	0437 * 16 + c_timming_a,	CPU_EN | (0437 * 16 + c_timming_b),	// 247

	0440 * 16 + c_timming_a,	CPU_EN | (0440 * 16 + c_timming_b),	// 248
	0441 * 16 + c_timming_a,	CPU_EN | (0441 * 16 + c_timming_b),	// 249
	/* SPRITE */				CPU_EN | (0442 * 16 + c_timming_b),	// 250
	0443 * 16 + c_timming_a,	CPU_EN | (0443 * 16 + c_timming_b),	// 251
	0444 * 16 + c_timming_a,	CPU_EN | (0444 * 16 + c_timming_b),	// 252
	0445 * 16 + c_timming_a,	CPU_EN | (0445 * 16 + c_timming_b),	// 253
	0446 * 16 + c_timming_a,	CPU_EN | (0446 * 16 + c_timming_b),	// 254
	0447 * 16 + c_timming_a,	CPU_EN | (0447 * 16 + c_timming_b),	// 255

	0450 * 16 + c_timming_a,	CPU_EN | (0450 * 16 + c_timming_b),	// 256
	0451 * 16 + c_timming_a,	CPU_EN | (0451 * 16 + c_timming_b),	// 257
	/* SPRITE */				CPU_EN | (0452 * 16 + c_timming_b),	// 258
	0453 * 16 + c_timming_a,	CPU_EN | (0453 * 16 + c_timming_b),	// 259
	0454 * 16 + c_timming_a,	CPU_EN | (0454 * 16 + c_timming_b),	// 260
	0455 * 16 + c_timming_a,	CPU_EN | (0455 * 16 + c_timming_b),	// 261
	0456 * 16 + c_timming_a,	CPU_EN | (0456 * 16 + c_timming_b),	// 262
	0457 * 16 + c_timming_a,	CPU_EN | (0457 * 16 + c_timming_b),	// 263

	0460 * 16 + c_timming_a,	CPU_EN | (0460 * 16 + c_timming_b),	// 264
	0461 * 16 + c_timming_a,	CPU_EN | (0461 * 16 + c_timming_b),	// 265
	/* SPRITE */				CPU_EN | (0462 * 16 + c_timming_b),	// 266
	0463 * 16 + c_timming_a,	CPU_EN | (0463 * 16 + c_timming_b),	// 267
	0464 * 16 + c_timming_a,	CPU_EN | (0464 * 16 + c_timming_b),	// 268
	0465 * 16 + c_timming_a,	CPU_EN | (0465 * 16 + c_timming_b),	// 269
	0466 * 16 + c_timming_a,	CPU_EN | (0466 * 16 + c_timming_b),	// 270
	0467 * 16 + c_timming_a,	CPU_EN | (0467 * 16 + c_timming_b),	// 271

	0470 * 16 + c_timming_a,	CPU_EN | (0470 * 16 + c_timming_b),	// 272
	0471 * 16 + c_timming_a,	CPU_EN | (0471 * 16 + c_timming_b),	// 273
	/* SPRITE */				CPU_EN | (0472 * 16 + c_timming_b),	// 274
	0473 * 16 + c_timming_a,	CPU_EN | (0473 * 16 + c_timming_b),	// 275
	0474 * 16 + c_timming_a,	CPU_EN | (0474 * 16 + c_timming_b),	// 276
	0475 * 16 + c_timming_a,	CPU_EN | (0475 * 16 + c_timming_b),	// 277
	0476 * 16 + c_timming_a,	CPU_EN | (0476 * 16 + c_timming_b),	// 278
	0477 * 16 + c_timming_a,	CPU_EN | (0477 * 16 + c_timming_b),	// 279

	0500 * 16 + c_timming_a,	CPU_EN | (0500 * 16 + c_timming_b),	// 280
	0501 * 16 + c_timming_a,	CPU_EN | (0501 * 16 + c_timming_b),	// 281
	/* SPRITE */				CPU_EN | (0502 * 16 + c_timming_b),	// 282
	0503 * 16 + c_timming_a,	CPU_EN | (0503 * 16 + c_timming_b),	// 283
	0504 * 16 + c_timming_a,	CPU_EN | (0504 * 16 + c_timming_b),	// 284
	0505 * 16 + c_timming_a,	CPU_EN | (0505 * 16 + c_timming_b),	// 285
	0506 * 16 + c_timming_a,	CPU_EN | (0506 * 16 + c_timming_b),	// 286
	0507 * 16 + c_timming_a,	CPU_EN | (0507 * 16 + c_timming_b),	// 287

	0510 * 16 + c_timming_a,	CPU_EN | (0510 * 16 + c_timming_b),	// 288
	0511 * 16 + c_timming_a,	CPU_EN | (0511 * 16 + c_timming_b),	// 289
	/* SPRITE */				CPU_EN | (0512 * 16 + c_timming_b),	// 290
	0513 * 16 + c_timming_a,	CPU_EN | (0513 * 16 + c_timming_b),	// 291
	0514 * 16 + c_timming_a,	CPU_EN | (0514 * 16 + c_timming_b),	// 292
	0515 * 16 + c_timming_a,	CPU_EN | (0515 * 16 + c_timming_b),	// 293
	0516 * 16 + c_timming_a,	CPU_EN | (0516 * 16 + c_timming_b),	// 294
	0517 * 16 + c_timming_a,	CPU_EN | (0517 * 16 + c_timming_b),	// 295

	0520 * 16 + c_timming_a,	CPU_EN | (0520 * 16 + c_timming_b),	// 296
	0521 * 16 + c_timming_a,	CPU_EN | (0521 * 16 + c_timming_b),	// 297
	/* SPRITE */				CPU_EN | (0522 * 16 + c_timming_b),	// 298
	0523 * 16 + c_timming_a,	CPU_EN | (0523 * 16 + c_timming_b),	// 299
	0524 * 16 + c_timming_a,	CPU_EN | (0524 * 16 + c_timming_b),	// 300
	0525 * 16 + c_timming_a,	CPU_EN | (0525 * 16 + c_timming_b),	// 301

	0526 * 16 + c_timming_a,	CPU_EN | (0526 * 16 + c_timming_b),	// -40
	0527 * 16 + c_timming_a,	CPU_EN | (0527 * 16 + c_timming_b),	// -39
	/* SPRITE */				CPU_EN | (0530 * 16 + c_timming_b),	// -38
	0531 * 16 + c_timming_a,	CPU_EN | (0531 * 16 + c_timming_b),	// -37
	0532 * 16 + c_timming_a,	CPU_EN | (0532 * 16 + c_timming_b),	// -36
	0533 * 16 + c_timming_a,	CPU_EN | (0533 * 16 + c_timming_b),	// -35
	0534 * 16 + c_timming_a,	CPU_EN | (0534 * 16 + c_timming_b),	// -34
	0535 * 16 + c_timming_a,	CPU_EN | (0535 * 16 + c_timming_b),	// -33

	/* REFRESH */													// -32
	0537 * 16 + c_timming_a,	CPU_EN | (0537 * 16 + c_timming_b)	// -31
};

// screen 7,8,10,11,12
static constexpr std::array<int16_t, 700-64> slotsV9968BitmapHighSpritesOff = {
	0000 * 16 + c_timming_a,	CPU_EN | (0000 * 16 + c_timming_b),	// -40
	0001 * 16 + c_timming_a,	CPU_EN | (0001 * 16 + c_timming_b),	// -39
	0002 * 16 + c_timming_a,	CPU_EN | (0002 * 16 + c_timming_b),	// -38
	0003 * 16 + c_timming_a,	CPU_EN | (0003 * 16 + c_timming_b),	// -37
	0004 * 16 + c_timming_a,	CPU_EN | (0004 * 16 + c_timming_b),	// -36
	0005 * 16 + c_timming_a,	CPU_EN | (0005 * 16 + c_timming_b),	// -35
	0006 * 16 + c_timming_a,	CPU_EN | (0006 * 16 + c_timming_b),	// -34
	0007 * 16 + c_timming_a,	CPU_EN | (0007 * 16 + c_timming_b),	// -33

	/* REFRESH */													// -32
	0011 * 16 + c_timming_a,	CPU_EN | (0011 * 16 + c_timming_b),	// -31
	0012 * 16 + c_timming_a,	CPU_EN | (0012 * 16 + c_timming_b),	// -30
	0013 * 16 + c_timming_a,	CPU_EN | (0013 * 16 + c_timming_b),	// -29
	0014 * 16 + c_timming_a,	CPU_EN | (0014 * 16 + c_timming_b),	// -28
	0015 * 16 + c_timming_a,	CPU_EN | (0015 * 16 + c_timming_b),	// -27
	0016 * 16 + c_timming_a,	CPU_EN | (0016 * 16 + c_timming_b),	// -26
	0017 * 16 + c_timming_a,	CPU_EN | (0017 * 16 + c_timming_b),	// -25

	0020 * 16 + c_timming_a,	CPU_EN | (0020 * 16 + c_timming_b),	// -24
	0021 * 16 + c_timming_a,	CPU_EN | (0021 * 16 + c_timming_b),	// -23
	0022 * 16 + c_timming_a,	CPU_EN | (0022 * 16 + c_timming_b),	// -22
	0023 * 16 + c_timming_a,	CPU_EN | (0023 * 16 + c_timming_b),	// -21
	0024 * 16 + c_timming_a,	CPU_EN | (0024 * 16 + c_timming_b),	// -20
	0025 * 16 + c_timming_a,	CPU_EN | (0025 * 16 + c_timming_b),	// -19
	0026 * 16 + c_timming_a,	CPU_EN | (0026 * 16 + c_timming_b),	// -18
	0027 * 16 + c_timming_a,	CPU_EN | (0027 * 16 + c_timming_b),	// -17

	0030 * 16 + c_timming_a,	CPU_EN | (0030 * 16 + c_timming_b),	// -16
	0031 * 16 + c_timming_a,	CPU_EN | (0031 * 16 + c_timming_b),	// -15
	0032 * 16 + c_timming_a,	CPU_EN | (0032 * 16 + c_timming_b),	// -14
	0033 * 16 + c_timming_a,	CPU_EN | (0033 * 16 + c_timming_b),	// -13
	0034 * 16 + c_timming_a,	CPU_EN | (0034 * 16 + c_timming_b),	// -12
	0035 * 16 + c_timming_a,	CPU_EN | (0035 * 16 + c_timming_b),	// -11
	0036 * 16 + c_timming_a,	CPU_EN | (0036 * 16 + c_timming_b),	// -10
	0037 * 16 + c_timming_a,	CPU_EN | (0037 * 16 + c_timming_b),	// -9

	/* BITMAP */				CPU_EN | (0040 * 16 + c_timming_b),	// -8
	/* BITMAP */				CPU_EN | (0041 * 16 + c_timming_b),	// -7
	0042 * 16 + c_timming_a,	CPU_EN | (0042 * 16 + c_timming_b),	// -6
	0043 * 16 + c_timming_a,	CPU_EN | (0043 * 16 + c_timming_b),	// -5
	0044 * 16 + c_timming_a,	CPU_EN | (0044 * 16 + c_timming_b),	// -4
	0045 * 16 + c_timming_a,	CPU_EN | (0045 * 16 + c_timming_b),	// -3
	0046 * 16 + c_timming_a,	CPU_EN | (0046 * 16 + c_timming_b),	// -2
	0047 * 16 + c_timming_a,	CPU_EN | (0047 * 16 + c_timming_b),	// -1

	/* BITMAP */				CPU_EN | (0050 * 16 + c_timming_b),	// 0
	/* BITMAP */				CPU_EN | (0051 * 16 + c_timming_b),	// 1
	0052 * 16 + c_timming_a,	CPU_EN | (0052 * 16 + c_timming_b),	// 2
	0053 * 16 + c_timming_a,	CPU_EN | (0053 * 16 + c_timming_b),	// 3
	0054 * 16 + c_timming_a,	CPU_EN | (0054 * 16 + c_timming_b),	// 4
	0055 * 16 + c_timming_a,	CPU_EN | (0055 * 16 + c_timming_b),	// 5
	0056 * 16 + c_timming_a,	CPU_EN | (0056 * 16 + c_timming_b),	// 6
	0057 * 16 + c_timming_a,	CPU_EN | (0057 * 16 + c_timming_b),	// 7

	/* BITMAP */				CPU_EN | (0060 * 16 + c_timming_b),	// 8
	/* BITMAP */				CPU_EN | (0061 * 16 + c_timming_b),	// 9
	0062 * 16 + c_timming_a,	CPU_EN | (0062 * 16 + c_timming_b),	// 10
	0063 * 16 + c_timming_a,	CPU_EN | (0063 * 16 + c_timming_b),	// 11
	0064 * 16 + c_timming_a,	CPU_EN | (0064 * 16 + c_timming_b),	// 12
	0065 * 16 + c_timming_a,	CPU_EN | (0065 * 16 + c_timming_b),	// 13
	0066 * 16 + c_timming_a,	CPU_EN | (0066 * 16 + c_timming_b),	// 14
	0067 * 16 + c_timming_a,	CPU_EN | (0067 * 16 + c_timming_b),	// 15

	/* BITMAP */				CPU_EN | (0070 * 16 + c_timming_b),	// 16
	/* BITMAP */				CPU_EN | (0071 * 16 + c_timming_b),	// 17
	0072 * 16 + c_timming_a,	CPU_EN | (0072 * 16 + c_timming_b),	// 18
	0073 * 16 + c_timming_a,	CPU_EN | (0073 * 16 + c_timming_b),	// 19
	0074 * 16 + c_timming_a,	CPU_EN | (0074 * 16 + c_timming_b),	// 20
	0075 * 16 + c_timming_a,	CPU_EN | (0075 * 16 + c_timming_b),	// 21
	0076 * 16 + c_timming_a,	CPU_EN | (0076 * 16 + c_timming_b),	// 22
	0077 * 16 + c_timming_a,	CPU_EN | (0077 * 16 + c_timming_b),	// 23

	/* BITMAP */				CPU_EN | (0100 * 16 + c_timming_b),	// 24
	/* BITMAP */				CPU_EN | (0101 * 16 + c_timming_b),	// 25
	0102 * 16 + c_timming_a,	CPU_EN | (0102 * 16 + c_timming_b),	// 26
	0103 * 16 + c_timming_a,	CPU_EN | (0103 * 16 + c_timming_b),	// 27
	0104 * 16 + c_timming_a,	CPU_EN | (0104 * 16 + c_timming_b),	// 28
	0105 * 16 + c_timming_a,	CPU_EN | (0105 * 16 + c_timming_b),	// 29
	0106 * 16 + c_timming_a,	CPU_EN | (0106 * 16 + c_timming_b),	// 30
	0107 * 16 + c_timming_a,	CPU_EN | (0107 * 16 + c_timming_b),	// 31

	/* BITMAP */				CPU_EN | (0110 * 16 + c_timming_b),	// 32
	/* BITMAP */				CPU_EN | (0111 * 16 + c_timming_b),	// 33
	0112 * 16 + c_timming_a,	CPU_EN | (0112 * 16 + c_timming_b),	// 34
	0113 * 16 + c_timming_a,	CPU_EN | (0113 * 16 + c_timming_b),	// 35
	0114 * 16 + c_timming_a,	CPU_EN | (0114 * 16 + c_timming_b),	// 36
	0115 * 16 + c_timming_a,	CPU_EN | (0115 * 16 + c_timming_b),	// 37
	0116 * 16 + c_timming_a,	CPU_EN | (0116 * 16 + c_timming_b),	// 38
	0117 * 16 + c_timming_a,	CPU_EN | (0117 * 16 + c_timming_b),	// 39

	/* BITMAP */				CPU_EN | (0120 * 16 + c_timming_b),	// 40
	/* BITMAP */				CPU_EN | (0121 * 16 + c_timming_b),	// 41
	0122 * 16 + c_timming_a,	CPU_EN | (0122 * 16 + c_timming_b),	// 42
	0123 * 16 + c_timming_a,	CPU_EN | (0123 * 16 + c_timming_b),	// 43
	0124 * 16 + c_timming_a,	CPU_EN | (0124 * 16 + c_timming_b),	// 44
	0125 * 16 + c_timming_a,	CPU_EN | (0125 * 16 + c_timming_b),	// 45
	0126 * 16 + c_timming_a,	CPU_EN | (0126 * 16 + c_timming_b),	// 46
	0127 * 16 + c_timming_a,	CPU_EN | (0127 * 16 + c_timming_b),	// 47

	/* BITMAP */				CPU_EN | (0130 * 16 + c_timming_b),	// 48
	/* BITMAP */				CPU_EN | (0131 * 16 + c_timming_b),	// 49
	0132 * 16 + c_timming_a,	CPU_EN | (0132 * 16 + c_timming_b),	// 50
	0133 * 16 + c_timming_a,	CPU_EN | (0133 * 16 + c_timming_b),	// 51
	0134 * 16 + c_timming_a,	CPU_EN | (0134 * 16 + c_timming_b),	// 52
	0135 * 16 + c_timming_a,	CPU_EN | (0135 * 16 + c_timming_b),	// 53
	0136 * 16 + c_timming_a,	CPU_EN | (0136 * 16 + c_timming_b),	// 54
	0137 * 16 + c_timming_a,	CPU_EN | (0137 * 16 + c_timming_b),	// 55

	/* BITMAP */				CPU_EN | (0140 * 16 + c_timming_b),	// 56
	/* BITMAP */				CPU_EN | (0141 * 16 + c_timming_b),	// 57
	0142 * 16 + c_timming_a,	CPU_EN | (0142 * 16 + c_timming_b),	// 58
	0143 * 16 + c_timming_a,	CPU_EN | (0143 * 16 + c_timming_b),	// 59
	0144 * 16 + c_timming_a,	CPU_EN | (0144 * 16 + c_timming_b),	// 60
	0145 * 16 + c_timming_a,	CPU_EN | (0145 * 16 + c_timming_b),	// 61
	0146 * 16 + c_timming_a,	CPU_EN | (0146 * 16 + c_timming_b),	// 62
	0147 * 16 + c_timming_a,	CPU_EN | (0147 * 16 + c_timming_b),	// 63

	/* BITMAP */				CPU_EN | (0150 * 16 + c_timming_b),	// 64
	/* BITMAP */				CPU_EN | (0151 * 16 + c_timming_b),	// 65
	0152 * 16 + c_timming_a,	CPU_EN | (0152 * 16 + c_timming_b),	// 66
	0153 * 16 + c_timming_a,	CPU_EN | (0153 * 16 + c_timming_b),	// 67
	0154 * 16 + c_timming_a,	CPU_EN | (0154 * 16 + c_timming_b),	// 68
	0155 * 16 + c_timming_a,	CPU_EN | (0155 * 16 + c_timming_b),	// 69
	0156 * 16 + c_timming_a,	CPU_EN | (0156 * 16 + c_timming_b),	// 70
	0157 * 16 + c_timming_a,	CPU_EN | (0157 * 16 + c_timming_b),	// 71

	/* BITMAP */				CPU_EN | (0160 * 16 + c_timming_b),	// 72
	/* BITMAP */				CPU_EN | (0161 * 16 + c_timming_b),	// 73
	0162 * 16 + c_timming_a,	CPU_EN | (0162 * 16 + c_timming_b),	// 74
	0163 * 16 + c_timming_a,	CPU_EN | (0163 * 16 + c_timming_b),	// 75
	0164 * 16 + c_timming_a,	CPU_EN | (0164 * 16 + c_timming_b),	// 76
	0165 * 16 + c_timming_a,	CPU_EN | (0165 * 16 + c_timming_b),	// 77
	0166 * 16 + c_timming_a,	CPU_EN | (0166 * 16 + c_timming_b),	// 78
	0167 * 16 + c_timming_a,	CPU_EN | (0167 * 16 + c_timming_b),	// 79

	/* BITMAP */				CPU_EN | (0170 * 16 + c_timming_b),	// 80
	/* BITMAP */				CPU_EN | (0171 * 16 + c_timming_b),	// 81
	0172 * 16 + c_timming_a,	CPU_EN | (0172 * 16 + c_timming_b),	// 82
	0173 * 16 + c_timming_a,	CPU_EN | (0173 * 16 + c_timming_b),	// 83
	0174 * 16 + c_timming_a,	CPU_EN | (0174 * 16 + c_timming_b),	// 84
	0175 * 16 + c_timming_a,	CPU_EN | (0175 * 16 + c_timming_b),	// 85
	0176 * 16 + c_timming_a,	CPU_EN | (0176 * 16 + c_timming_b),	// 86
	0177 * 16 + c_timming_a,	CPU_EN | (0177 * 16 + c_timming_b),	// 87

	/* BITMAP */				CPU_EN | (0200 * 16 + c_timming_b),	// 88
	/* BITMAP */				CPU_EN | (0201 * 16 + c_timming_b),	// 89
	0202 * 16 + c_timming_a,	CPU_EN | (0202 * 16 + c_timming_b),	// 90
	0203 * 16 + c_timming_a,	CPU_EN | (0203 * 16 + c_timming_b),	// 91
	0204 * 16 + c_timming_a,	CPU_EN | (0204 * 16 + c_timming_b),	// 92
	0205 * 16 + c_timming_a,	CPU_EN | (0205 * 16 + c_timming_b),	// 93
	0206 * 16 + c_timming_a,	CPU_EN | (0206 * 16 + c_timming_b),	// 94
	0207 * 16 + c_timming_a,	CPU_EN | (0207 * 16 + c_timming_b),	// 95

	/* BITMAP */				CPU_EN | (0210 * 16 + c_timming_b),	// 96
	/* BITMAP */				CPU_EN | (0211 * 16 + c_timming_b),	// 97
	0212 * 16 + c_timming_a,	CPU_EN | (0212 * 16 + c_timming_b),	// 98
	0213 * 16 + c_timming_a,	CPU_EN | (0213 * 16 + c_timming_b),	// 99
	0214 * 16 + c_timming_a,	CPU_EN | (0214 * 16 + c_timming_b),	// 100
	0215 * 16 + c_timming_a,	CPU_EN | (0215 * 16 + c_timming_b),	// 101
	0216 * 16 + c_timming_a,	CPU_EN | (0216 * 16 + c_timming_b),	// 102
	0217 * 16 + c_timming_a,	CPU_EN | (0217 * 16 + c_timming_b),	// 103

	/* BITMAP */				CPU_EN | (0220 * 16 + c_timming_b),	// 104
	/* BITMAP */				CPU_EN | (0221 * 16 + c_timming_b),	// 105
	0222 * 16 + c_timming_a,	CPU_EN | (0222 * 16 + c_timming_b),	// 106
	0223 * 16 + c_timming_a,	CPU_EN | (0223 * 16 + c_timming_b),	// 107
	0224 * 16 + c_timming_a,	CPU_EN | (0224 * 16 + c_timming_b),	// 108
	0225 * 16 + c_timming_a,	CPU_EN | (0225 * 16 + c_timming_b),	// 109
	0226 * 16 + c_timming_a,	CPU_EN | (0226 * 16 + c_timming_b),	// 110
	0227 * 16 + c_timming_a,	CPU_EN | (0227 * 16 + c_timming_b),	// 111

	/* BITMAP */				CPU_EN | (0230 * 16 + c_timming_b),	// 112
	/* BITMAP */				CPU_EN | (0231 * 16 + c_timming_b),	// 113
	0232 * 16 + c_timming_a,	CPU_EN | (0232 * 16 + c_timming_b),	// 114
	0233 * 16 + c_timming_a,	CPU_EN | (0233 * 16 + c_timming_b),	// 115
	0234 * 16 + c_timming_a,	CPU_EN | (0234 * 16 + c_timming_b),	// 116
	0235 * 16 + c_timming_a,	CPU_EN | (0235 * 16 + c_timming_b),	// 117
	0236 * 16 + c_timming_a,	CPU_EN | (0236 * 16 + c_timming_b),	// 118
	0237 * 16 + c_timming_a,	CPU_EN | (0237 * 16 + c_timming_b),	// 119

	/* BITMAP */				CPU_EN | (0240 * 16 + c_timming_b),	// 120
	/* BITMAP */				CPU_EN | (0241 * 16 + c_timming_b),	// 121
	0242 * 16 + c_timming_a,	CPU_EN | (0242 * 16 + c_timming_b),	// 122
	0243 * 16 + c_timming_a,	CPU_EN | (0243 * 16 + c_timming_b),	// 123
	0244 * 16 + c_timming_a,	CPU_EN | (0244 * 16 + c_timming_b),	// 124
	0245 * 16 + c_timming_a,	CPU_EN | (0245 * 16 + c_timming_b),	// 125
	0246 * 16 + c_timming_a,	CPU_EN | (0246 * 16 + c_timming_b),	// 126
	0247 * 16 + c_timming_a,	CPU_EN | (0247 * 16 + c_timming_b),	// 127

	/* BITMAP */				CPU_EN | (0250 * 16 + c_timming_b),	// 128
	/* BITMAP */				CPU_EN | (0251 * 16 + c_timming_b),	// 129
	0252 * 16 + c_timming_a,	CPU_EN | (0252 * 16 + c_timming_b),	// 130
	0253 * 16 + c_timming_a,	CPU_EN | (0253 * 16 + c_timming_b),	// 131
	0254 * 16 + c_timming_a,	CPU_EN | (0254 * 16 + c_timming_b),	// 132
	0255 * 16 + c_timming_a,	CPU_EN | (0255 * 16 + c_timming_b),	// 133
	0256 * 16 + c_timming_a,	CPU_EN | (0256 * 16 + c_timming_b),	// 134
	0257 * 16 + c_timming_a,	CPU_EN | (0257 * 16 + c_timming_b),	// 135

	/* BITMAP */				CPU_EN | (0260 * 16 + c_timming_b),	// 136
	/* BITMAP */				CPU_EN | (0261 * 16 + c_timming_b),	// 137
	0262 * 16 + c_timming_a,	CPU_EN | (0262 * 16 + c_timming_b),	// 138
	0263 * 16 + c_timming_a,	CPU_EN | (0263 * 16 + c_timming_b),	// 139
	0264 * 16 + c_timming_a,	CPU_EN | (0264 * 16 + c_timming_b),	// 140
	0265 * 16 + c_timming_a,	CPU_EN | (0265 * 16 + c_timming_b),	// 141
	0266 * 16 + c_timming_a,	CPU_EN | (0266 * 16 + c_timming_b),	// 142
	0267 * 16 + c_timming_a,	CPU_EN | (0267 * 16 + c_timming_b),	// 143

	/* BITMAP */				CPU_EN | (0270 * 16 + c_timming_b),	// 144
	/* BITMAP */				CPU_EN | (0271 * 16 + c_timming_b),	// 145
	0272 * 16 + c_timming_a,	CPU_EN | (0272 * 16 + c_timming_b),	// 146
	0273 * 16 + c_timming_a,	CPU_EN | (0273 * 16 + c_timming_b),	// 147
	0274 * 16 + c_timming_a,	CPU_EN | (0274 * 16 + c_timming_b),	// 148
	0275 * 16 + c_timming_a,	CPU_EN | (0275 * 16 + c_timming_b),	// 149
	0276 * 16 + c_timming_a,	CPU_EN | (0276 * 16 + c_timming_b),	// 150
	0277 * 16 + c_timming_a,	CPU_EN | (0277 * 16 + c_timming_b),	// 151

	/* BITMAP */				CPU_EN | (0300 * 16 + c_timming_b),	// 152
	/* BITMAP */				CPU_EN | (0301 * 16 + c_timming_b),	// 153
	0302 * 16 + c_timming_a,	CPU_EN | (0302 * 16 + c_timming_b),	// 154
	0303 * 16 + c_timming_a,	CPU_EN | (0303 * 16 + c_timming_b),	// 155
	0304 * 16 + c_timming_a,	CPU_EN | (0304 * 16 + c_timming_b),	// 156
	0305 * 16 + c_timming_a,	CPU_EN | (0305 * 16 + c_timming_b),	// 157
	0306 * 16 + c_timming_a,	CPU_EN | (0306 * 16 + c_timming_b),	// 158
	0307 * 16 + c_timming_a,	CPU_EN | (0307 * 16 + c_timming_b),	// 159

	/* BITMAP */				CPU_EN | (0310 * 16 + c_timming_b),	// 160
	/* BITMAP */				CPU_EN | (0311 * 16 + c_timming_b),	// 161
	0312 * 16 + c_timming_a,	CPU_EN | (0312 * 16 + c_timming_b),	// 162
	0313 * 16 + c_timming_a,	CPU_EN | (0313 * 16 + c_timming_b),	// 163
	0314 * 16 + c_timming_a,	CPU_EN | (0314 * 16 + c_timming_b),	// 164
	0315 * 16 + c_timming_a,	CPU_EN | (0315 * 16 + c_timming_b),	// 165
	0316 * 16 + c_timming_a,	CPU_EN | (0316 * 16 + c_timming_b),	// 166
	0317 * 16 + c_timming_a,	CPU_EN | (0317 * 16 + c_timming_b),	// 167

	/* BITMAP */				CPU_EN | (0320 * 16 + c_timming_b),	// 168
	/* BITMAP */				CPU_EN | (0321 * 16 + c_timming_b),	// 169
	0322 * 16 + c_timming_a,	CPU_EN | (0322 * 16 + c_timming_b),	// 170
	0323 * 16 + c_timming_a,	CPU_EN | (0323 * 16 + c_timming_b),	// 171
	0324 * 16 + c_timming_a,	CPU_EN | (0324 * 16 + c_timming_b),	// 172
	0325 * 16 + c_timming_a,	CPU_EN | (0325 * 16 + c_timming_b),	// 173
	0326 * 16 + c_timming_a,	CPU_EN | (0326 * 16 + c_timming_b),	// 174
	0327 * 16 + c_timming_a,	CPU_EN | (0327 * 16 + c_timming_b),	// 175

	/* BITMAP */				CPU_EN | (0330 * 16 + c_timming_b),	// 176
	/* BITMAP */				CPU_EN | (0331 * 16 + c_timming_b),	// 177
	0332 * 16 + c_timming_a,	CPU_EN | (0332 * 16 + c_timming_b),	// 178
	0333 * 16 + c_timming_a,	CPU_EN | (0333 * 16 + c_timming_b),	// 179
	0334 * 16 + c_timming_a,	CPU_EN | (0334 * 16 + c_timming_b),	// 180
	0335 * 16 + c_timming_a,	CPU_EN | (0335 * 16 + c_timming_b),	// 181
	0336 * 16 + c_timming_a,	CPU_EN | (0336 * 16 + c_timming_b),	// 182
	0337 * 16 + c_timming_a,	CPU_EN | (0337 * 16 + c_timming_b),	// 183

	/* BITMAP */				CPU_EN | (0340 * 16 + c_timming_b),	// 184
	/* BITMAP */				CPU_EN | (0341 * 16 + c_timming_b),	// 185
	0342 * 16 + c_timming_a,	CPU_EN | (0342 * 16 + c_timming_b),	// 186
	0343 * 16 + c_timming_a,	CPU_EN | (0343 * 16 + c_timming_b),	// 187
	0344 * 16 + c_timming_a,	CPU_EN | (0344 * 16 + c_timming_b),	// 188
	0345 * 16 + c_timming_a,	CPU_EN | (0345 * 16 + c_timming_b),	// 189
	0346 * 16 + c_timming_a,	CPU_EN | (0346 * 16 + c_timming_b),	// 190
	0347 * 16 + c_timming_a,	CPU_EN | (0347 * 16 + c_timming_b),	// 191

	/* BITMAP */				CPU_EN | (0350 * 16 + c_timming_b),	// 192
	/* BITMAP */				CPU_EN | (0351 * 16 + c_timming_b),	// 193
	0352 * 16 + c_timming_a,	CPU_EN | (0352 * 16 + c_timming_b),	// 194
	0353 * 16 + c_timming_a,	CPU_EN | (0353 * 16 + c_timming_b),	// 195
	0354 * 16 + c_timming_a,	CPU_EN | (0354 * 16 + c_timming_b),	// 196
	0355 * 16 + c_timming_a,	CPU_EN | (0355 * 16 + c_timming_b),	// 197
	0356 * 16 + c_timming_a,	CPU_EN | (0356 * 16 + c_timming_b),	// 198
	0357 * 16 + c_timming_a,	CPU_EN | (0357 * 16 + c_timming_b),	// 199

	/* BITMAP */				CPU_EN | (0360 * 16 + c_timming_b),	// 200
	/* BITMAP */				CPU_EN | (0361 * 16 + c_timming_b),	// 201
	0362 * 16 + c_timming_a,	CPU_EN | (0362 * 16 + c_timming_b),	// 202
	0363 * 16 + c_timming_a,	CPU_EN | (0363 * 16 + c_timming_b),	// 203
	0364 * 16 + c_timming_a,	CPU_EN | (0364 * 16 + c_timming_b),	// 204
	0365 * 16 + c_timming_a,	CPU_EN | (0365 * 16 + c_timming_b),	// 205
	0366 * 16 + c_timming_a,	CPU_EN | (0366 * 16 + c_timming_b),	// 206
	0367 * 16 + c_timming_a,	CPU_EN | (0367 * 16 + c_timming_b),	// 207

	/* BITMAP */				CPU_EN | (0370 * 16 + c_timming_b),	// 208
	/* BITMAP */				CPU_EN | (0371 * 16 + c_timming_b),	// 209
	0372 * 16 + c_timming_a,	CPU_EN | (0372 * 16 + c_timming_b),	// 210
	0373 * 16 + c_timming_a,	CPU_EN | (0373 * 16 + c_timming_b),	// 211
	0374 * 16 + c_timming_a,	CPU_EN | (0374 * 16 + c_timming_b),	// 212
	0375 * 16 + c_timming_a,	CPU_EN | (0375 * 16 + c_timming_b),	// 213
	0376 * 16 + c_timming_a,	CPU_EN | (0376 * 16 + c_timming_b),	// 214
	0377 * 16 + c_timming_a,	CPU_EN | (0377 * 16 + c_timming_b),	// 215

	/* BITMAP */				CPU_EN | (0400 * 16 + c_timming_b),	// 216
	/* BITMAP */				CPU_EN | (0401 * 16 + c_timming_b),	// 217
	0402 * 16 + c_timming_a,	CPU_EN | (0402 * 16 + c_timming_b),	// 218
	0403 * 16 + c_timming_a,	CPU_EN | (0403 * 16 + c_timming_b),	// 219
	0404 * 16 + c_timming_a,	CPU_EN | (0404 * 16 + c_timming_b),	// 220
	0405 * 16 + c_timming_a,	CPU_EN | (0405 * 16 + c_timming_b),	// 221
	0406 * 16 + c_timming_a,	CPU_EN | (0406 * 16 + c_timming_b),	// 222
	0407 * 16 + c_timming_a,	CPU_EN | (0407 * 16 + c_timming_b),	// 223

	/* BITMAP */				CPU_EN | (0410 * 16 + c_timming_b),	// 224
	/* BITMAP */				CPU_EN | (0411 * 16 + c_timming_b),	// 225
	0412 * 16 + c_timming_a,	CPU_EN | (0412 * 16 + c_timming_b),	// 226
	0413 * 16 + c_timming_a,	CPU_EN | (0413 * 16 + c_timming_b),	// 227
	0414 * 16 + c_timming_a,	CPU_EN | (0414 * 16 + c_timming_b),	// 228
	0415 * 16 + c_timming_a,	CPU_EN | (0415 * 16 + c_timming_b),	// 229
	0416 * 16 + c_timming_a,	CPU_EN | (0416 * 16 + c_timming_b),	// 230
	0417 * 16 + c_timming_a,	CPU_EN | (0417 * 16 + c_timming_b),	// 231

	/* BITMAP */				CPU_EN | (0420 * 16 + c_timming_b),	// 232
	/* BITMAP */				CPU_EN | (0421 * 16 + c_timming_b),	// 233
	0422 * 16 + c_timming_a,	CPU_EN | (0422 * 16 + c_timming_b),	// 234
	0423 * 16 + c_timming_a,	CPU_EN | (0423 * 16 + c_timming_b),	// 235
	0424 * 16 + c_timming_a,	CPU_EN | (0424 * 16 + c_timming_b),	// 236
	0425 * 16 + c_timming_a,	CPU_EN | (0425 * 16 + c_timming_b),	// 237
	0426 * 16 + c_timming_a,	CPU_EN | (0426 * 16 + c_timming_b),	// 238
	0427 * 16 + c_timming_a,	CPU_EN | (0427 * 16 + c_timming_b),	// 239

	/* BITMAP */				CPU_EN | (0430 * 16 + c_timming_b),	// 240
	/* BITMAP */				CPU_EN | (0431 * 16 + c_timming_b),	// 241
	0432 * 16 + c_timming_a,	CPU_EN | (0432 * 16 + c_timming_b),	// 242
	0433 * 16 + c_timming_a,	CPU_EN | (0433 * 16 + c_timming_b),	// 243
	0434 * 16 + c_timming_a,	CPU_EN | (0434 * 16 + c_timming_b),	// 244
	0435 * 16 + c_timming_a,	CPU_EN | (0435 * 16 + c_timming_b),	// 245
	0436 * 16 + c_timming_a,	CPU_EN | (0436 * 16 + c_timming_b),	// 246
	0437 * 16 + c_timming_a,	CPU_EN | (0437 * 16 + c_timming_b),	// 247

	0440 * 16 + c_timming_a,	CPU_EN | (0440 * 16 + c_timming_b),	// 248
	0441 * 16 + c_timming_a,	CPU_EN | (0441 * 16 + c_timming_b),	// 249
	0442 * 16 + c_timming_a,	CPU_EN | (0442 * 16 + c_timming_b),	// 250
	0443 * 16 + c_timming_a,	CPU_EN | (0443 * 16 + c_timming_b),	// 251
	0444 * 16 + c_timming_a,	CPU_EN | (0444 * 16 + c_timming_b),	// 252
	0445 * 16 + c_timming_a,	CPU_EN | (0445 * 16 + c_timming_b),	// 253
	0446 * 16 + c_timming_a,	CPU_EN | (0446 * 16 + c_timming_b),	// 254
	0447 * 16 + c_timming_a,	CPU_EN | (0447 * 16 + c_timming_b),	// 255

	0450 * 16 + c_timming_a,	CPU_EN | (0450 * 16 + c_timming_b),	// 256
	0451 * 16 + c_timming_a,	CPU_EN | (0451 * 16 + c_timming_b),	// 257
	0452 * 16 + c_timming_a,	CPU_EN | (0452 * 16 + c_timming_b),	// 258
	0453 * 16 + c_timming_a,	CPU_EN | (0453 * 16 + c_timming_b),	// 259
	0454 * 16 + c_timming_a,	CPU_EN | (0454 * 16 + c_timming_b),	// 260
	0455 * 16 + c_timming_a,	CPU_EN | (0455 * 16 + c_timming_b),	// 261
	0456 * 16 + c_timming_a,	CPU_EN | (0456 * 16 + c_timming_b),	// 262
	0457 * 16 + c_timming_a,	CPU_EN | (0457 * 16 + c_timming_b),	// 263

	0460 * 16 + c_timming_a,	CPU_EN | (0460 * 16 + c_timming_b),	// 264
	0461 * 16 + c_timming_a,	CPU_EN | (0461 * 16 + c_timming_b),	// 265
	0462 * 16 + c_timming_a,	CPU_EN | (0462 * 16 + c_timming_b),	// 266
	0463 * 16 + c_timming_a,	CPU_EN | (0463 * 16 + c_timming_b),	// 267
	0464 * 16 + c_timming_a,	CPU_EN | (0464 * 16 + c_timming_b),	// 268
	0465 * 16 + c_timming_a,	CPU_EN | (0465 * 16 + c_timming_b),	// 269
	0466 * 16 + c_timming_a,	CPU_EN | (0466 * 16 + c_timming_b),	// 270
	0467 * 16 + c_timming_a,	CPU_EN | (0467 * 16 + c_timming_b),	// 271

	0470 * 16 + c_timming_a,	CPU_EN | (0470 * 16 + c_timming_b),	// 272
	0471 * 16 + c_timming_a,	CPU_EN | (0471 * 16 + c_timming_b),	// 273
	0472 * 16 + c_timming_a,	CPU_EN | (0472 * 16 + c_timming_b),	// 274
	0473 * 16 + c_timming_a,	CPU_EN | (0473 * 16 + c_timming_b),	// 275
	0474 * 16 + c_timming_a,	CPU_EN | (0474 * 16 + c_timming_b),	// 276
	0475 * 16 + c_timming_a,	CPU_EN | (0475 * 16 + c_timming_b),	// 277
	0476 * 16 + c_timming_a,	CPU_EN | (0476 * 16 + c_timming_b),	// 278
	0477 * 16 + c_timming_a,	CPU_EN | (0477 * 16 + c_timming_b),	// 279

	0500 * 16 + c_timming_a,	CPU_EN | (0500 * 16 + c_timming_b),	// 280
	0501 * 16 + c_timming_a,	CPU_EN | (0501 * 16 + c_timming_b),	// 281
	0502 * 16 + c_timming_a,	CPU_EN | (0502 * 16 + c_timming_b),	// 282
	0503 * 16 + c_timming_a,	CPU_EN | (0503 * 16 + c_timming_b),	// 283
	0504 * 16 + c_timming_a,	CPU_EN | (0504 * 16 + c_timming_b),	// 284
	0505 * 16 + c_timming_a,	CPU_EN | (0505 * 16 + c_timming_b),	// 285
	0506 * 16 + c_timming_a,	CPU_EN | (0506 * 16 + c_timming_b),	// 286
	0507 * 16 + c_timming_a,	CPU_EN | (0507 * 16 + c_timming_b),	// 287

	0510 * 16 + c_timming_a,	CPU_EN | (0510 * 16 + c_timming_b),	// 288
	0511 * 16 + c_timming_a,	CPU_EN | (0511 * 16 + c_timming_b),	// 289
	0512 * 16 + c_timming_a,	CPU_EN | (0512 * 16 + c_timming_b),	// 290
	0513 * 16 + c_timming_a,	CPU_EN | (0513 * 16 + c_timming_b),	// 291
	0514 * 16 + c_timming_a,	CPU_EN | (0514 * 16 + c_timming_b),	// 292
	0515 * 16 + c_timming_a,	CPU_EN | (0515 * 16 + c_timming_b),	// 293
	0516 * 16 + c_timming_a,	CPU_EN | (0516 * 16 + c_timming_b),	// 294
	0517 * 16 + c_timming_a,	CPU_EN | (0517 * 16 + c_timming_b),	// 295

	0520 * 16 + c_timming_a,	CPU_EN | (0520 * 16 + c_timming_b),	// 296
	0521 * 16 + c_timming_a,	CPU_EN | (0521 * 16 + c_timming_b),	// 297
	0522 * 16 + c_timming_a,	CPU_EN | (0522 * 16 + c_timming_b),	// 298
	0523 * 16 + c_timming_a,	CPU_EN | (0523 * 16 + c_timming_b),	// 299
	0524 * 16 + c_timming_a,	CPU_EN | (0524 * 16 + c_timming_b),	// 300
	0525 * 16 + c_timming_a,	CPU_EN | (0525 * 16 + c_timming_b),	// 301

	0526 * 16 + c_timming_a,	CPU_EN | (0526 * 16 + c_timming_b),	// -40
	0527 * 16 + c_timming_a,	CPU_EN | (0527 * 16 + c_timming_b),	// -39
	0530 * 16 + c_timming_a,	CPU_EN | (0530 * 16 + c_timming_b),	// -38
	0531 * 16 + c_timming_a,	CPU_EN | (0531 * 16 + c_timming_b),	// -37
	0532 * 16 + c_timming_a,	CPU_EN | (0532 * 16 + c_timming_b),	// -36
	0533 * 16 + c_timming_a,	CPU_EN | (0533 * 16 + c_timming_b),	// -35
	0534 * 16 + c_timming_a,	CPU_EN | (0534 * 16 + c_timming_b),	// -34
	0535 * 16 + c_timming_a,	CPU_EN | (0535 * 16 + c_timming_b),	// -33

	/* REFRESH */													// -32
	0537 * 16 + c_timming_a,	CPU_EN | (0537 * 16 + c_timming_b)	// -31
};

// screen 7,8,10,11,12
static constexpr std::array<int16_t, 700-64-44> slotsV9968BitmapHighSpritesOn = {
	0000 * 16 + c_timming_a,	CPU_EN | (0000 * 16 + c_timming_b),	// -40
	0001 * 16 + c_timming_a,	CPU_EN | (0001 * 16 + c_timming_b),	// -39
	/* SPRITE */				CPU_EN | (0002 * 16 + c_timming_b),	// -38
	0003 * 16 + c_timming_a,	CPU_EN | (0003 * 16 + c_timming_b),	// -37
	0004 * 16 + c_timming_a,	CPU_EN | (0004 * 16 + c_timming_b),	// -36
	0005 * 16 + c_timming_a,	CPU_EN | (0005 * 16 + c_timming_b),	// -35
	0006 * 16 + c_timming_a,	CPU_EN | (0006 * 16 + c_timming_b),	// -34
	0007 * 16 + c_timming_a,	CPU_EN | (0007 * 16 + c_timming_b),	// -33

	/* REFRESH */													// -32
	0011 * 16 + c_timming_a,	CPU_EN | (0011 * 16 + c_timming_b),	// -31
	/* SPRITE */				CPU_EN | (0012 * 16 + c_timming_b),	// -30
	0013 * 16 + c_timming_a,	CPU_EN | (0013 * 16 + c_timming_b),	// -29
	0014 * 16 + c_timming_a,	CPU_EN | (0014 * 16 + c_timming_b),	// -28
	0015 * 16 + c_timming_a,	CPU_EN | (0015 * 16 + c_timming_b),	// -27
	0016 * 16 + c_timming_a,	CPU_EN | (0016 * 16 + c_timming_b),	// -26
	0017 * 16 + c_timming_a,	CPU_EN | (0017 * 16 + c_timming_b),	// -25

	0020 * 16 + c_timming_a,	CPU_EN | (0020 * 16 + c_timming_b),	// -24
	0021 * 16 + c_timming_a,	CPU_EN | (0021 * 16 + c_timming_b),	// -23
	/* SPRITE */				CPU_EN | (0022 * 16 + c_timming_b),	// -22
	0023 * 16 + c_timming_a,	CPU_EN | (0023 * 16 + c_timming_b),	// -21
	0024 * 16 + c_timming_a,	CPU_EN | (0024 * 16 + c_timming_b),	// -20
	0025 * 16 + c_timming_a,	CPU_EN | (0025 * 16 + c_timming_b),	// -19
	0026 * 16 + c_timming_a,	CPU_EN | (0026 * 16 + c_timming_b),	// -18
	0027 * 16 + c_timming_a,	CPU_EN | (0027 * 16 + c_timming_b),	// -17

	0030 * 16 + c_timming_a,	CPU_EN | (0030 * 16 + c_timming_b),	// -16
	0031 * 16 + c_timming_a,	CPU_EN | (0031 * 16 + c_timming_b),	// -15
	/* SPRITE */				CPU_EN | (0032 * 16 + c_timming_b),	// -14
	0033 * 16 + c_timming_a,	CPU_EN | (0033 * 16 + c_timming_b),	// -13
	0034 * 16 + c_timming_a,	CPU_EN | (0034 * 16 + c_timming_b),	// -12
	0035 * 16 + c_timming_a,	CPU_EN | (0035 * 16 + c_timming_b),	// -11
	0036 * 16 + c_timming_a,	CPU_EN | (0036 * 16 + c_timming_b),	// -10
	0037 * 16 + c_timming_a,	CPU_EN | (0037 * 16 + c_timming_b),	// -9

	/* BITMAP */				CPU_EN | (0040 * 16 + c_timming_b),	// -8
	/* BITMAP */				CPU_EN | (0041 * 16 + c_timming_b),	// -7
	/* SPRITE */				CPU_EN | (0042 * 16 + c_timming_b),	// -6
	0043 * 16 + c_timming_a,	CPU_EN | (0043 * 16 + c_timming_b),	// -5
	0044 * 16 + c_timming_a,	CPU_EN | (0044 * 16 + c_timming_b),	// -4
	0045 * 16 + c_timming_a,	CPU_EN | (0045 * 16 + c_timming_b),	// -3
	0046 * 16 + c_timming_a,	CPU_EN | (0046 * 16 + c_timming_b),	// -2
	0047 * 16 + c_timming_a,	CPU_EN | (0047 * 16 + c_timming_b),	// -1

	/* BITMAP */				CPU_EN | (0050 * 16 + c_timming_b),	// 0
	/* BITMAP */				CPU_EN | (0051 * 16 + c_timming_b),	// 1
	/* SPRITE */				CPU_EN | (0052 * 16 + c_timming_b),	// 2
	0053 * 16 + c_timming_a,	CPU_EN | (0053 * 16 + c_timming_b),	// 3
	0054 * 16 + c_timming_a,	CPU_EN | (0054 * 16 + c_timming_b),	// 4
	0055 * 16 + c_timming_a,	CPU_EN | (0055 * 16 + c_timming_b),	// 5
	0056 * 16 + c_timming_a,	CPU_EN | (0056 * 16 + c_timming_b),	// 6
	0057 * 16 + c_timming_a,	CPU_EN | (0057 * 16 + c_timming_b),	// 7

	/* BITMAP */				CPU_EN | (0060 * 16 + c_timming_b),	// 8
	/* BITMAP */				CPU_EN | (0061 * 16 + c_timming_b),	// 9
	/* SPRITE */				CPU_EN | (0062 * 16 + c_timming_b),	// 10
	0063 * 16 + c_timming_a,	CPU_EN | (0063 * 16 + c_timming_b),	// 11
	0064 * 16 + c_timming_a,	CPU_EN | (0064 * 16 + c_timming_b),	// 12
	0065 * 16 + c_timming_a,	CPU_EN | (0065 * 16 + c_timming_b),	// 13
	0066 * 16 + c_timming_a,	CPU_EN | (0066 * 16 + c_timming_b),	// 14
	0067 * 16 + c_timming_a,	CPU_EN | (0067 * 16 + c_timming_b),	// 15

	/* BITMAP */				CPU_EN | (0070 * 16 + c_timming_b),	// 16
	/* BITMAP */				CPU_EN | (0071 * 16 + c_timming_b),	// 17
	/* SPRITE */				CPU_EN | (0072 * 16 + c_timming_b),	// 18
	0073 * 16 + c_timming_a,	CPU_EN | (0073 * 16 + c_timming_b),	// 19
	0074 * 16 + c_timming_a,	CPU_EN | (0074 * 16 + c_timming_b),	// 20
	0075 * 16 + c_timming_a,	CPU_EN | (0075 * 16 + c_timming_b),	// 21
	0076 * 16 + c_timming_a,	CPU_EN | (0076 * 16 + c_timming_b),	// 22
	0077 * 16 + c_timming_a,	CPU_EN | (0077 * 16 + c_timming_b),	// 23

	/* BITMAP */				CPU_EN | (0100 * 16 + c_timming_b),	// 24
	/* BITMAP */				CPU_EN | (0101 * 16 + c_timming_b),	// 25
	/* SPRITE */				CPU_EN | (0102 * 16 + c_timming_b),	// 26
	0103 * 16 + c_timming_a,	CPU_EN | (0103 * 16 + c_timming_b),	// 27
	0104 * 16 + c_timming_a,	CPU_EN | (0104 * 16 + c_timming_b),	// 28
	0105 * 16 + c_timming_a,	CPU_EN | (0105 * 16 + c_timming_b),	// 29
	0106 * 16 + c_timming_a,	CPU_EN | (0106 * 16 + c_timming_b),	// 30
	0107 * 16 + c_timming_a,	CPU_EN | (0107 * 16 + c_timming_b),	// 31

	/* BITMAP */				CPU_EN | (0110 * 16 + c_timming_b),	// 32
	/* BITMAP */				CPU_EN | (0111 * 16 + c_timming_b),	// 33
	/* SPRITE */				CPU_EN | (0112 * 16 + c_timming_b),	// 34
	0113 * 16 + c_timming_a,	CPU_EN | (0113 * 16 + c_timming_b),	// 35
	0114 * 16 + c_timming_a,	CPU_EN | (0114 * 16 + c_timming_b),	// 36
	0115 * 16 + c_timming_a,	CPU_EN | (0115 * 16 + c_timming_b),	// 37
	0116 * 16 + c_timming_a,	CPU_EN | (0116 * 16 + c_timming_b),	// 38
	0117 * 16 + c_timming_a,	CPU_EN | (0117 * 16 + c_timming_b),	// 39

	/* BITMAP */				CPU_EN | (0120 * 16 + c_timming_b),	// 40
	/* BITMAP */				CPU_EN | (0121 * 16 + c_timming_b),	// 41
	/* SPRITE */				CPU_EN | (0122 * 16 + c_timming_b),	// 42
	0123 * 16 + c_timming_a,	CPU_EN | (0123 * 16 + c_timming_b),	// 43
	0124 * 16 + c_timming_a,	CPU_EN | (0124 * 16 + c_timming_b),	// 44
	0125 * 16 + c_timming_a,	CPU_EN | (0125 * 16 + c_timming_b),	// 45
	0126 * 16 + c_timming_a,	CPU_EN | (0126 * 16 + c_timming_b),	// 46
	0127 * 16 + c_timming_a,	CPU_EN | (0127 * 16 + c_timming_b),	// 47

	/* BITMAP */				CPU_EN | (0130 * 16 + c_timming_b),	// 48
	/* BITMAP */				CPU_EN | (0131 * 16 + c_timming_b),	// 49
	/* SPRITE */				CPU_EN | (0132 * 16 + c_timming_b),	// 50
	0133 * 16 + c_timming_a,	CPU_EN | (0133 * 16 + c_timming_b),	// 51
	0134 * 16 + c_timming_a,	CPU_EN | (0134 * 16 + c_timming_b),	// 52
	0135 * 16 + c_timming_a,	CPU_EN | (0135 * 16 + c_timming_b),	// 53
	0136 * 16 + c_timming_a,	CPU_EN | (0136 * 16 + c_timming_b),	// 54
	0137 * 16 + c_timming_a,	CPU_EN | (0137 * 16 + c_timming_b),	// 55

	/* BITMAP */				CPU_EN | (0140 * 16 + c_timming_b),	// 56
	/* BITMAP */				CPU_EN | (0141 * 16 + c_timming_b),	// 57
	/* SPRITE */				CPU_EN | (0142 * 16 + c_timming_b),	// 58
	0143 * 16 + c_timming_a,	CPU_EN | (0143 * 16 + c_timming_b),	// 59
	0144 * 16 + c_timming_a,	CPU_EN | (0144 * 16 + c_timming_b),	// 60
	0145 * 16 + c_timming_a,	CPU_EN | (0145 * 16 + c_timming_b),	// 61
	0146 * 16 + c_timming_a,	CPU_EN | (0146 * 16 + c_timming_b),	// 62
	0147 * 16 + c_timming_a,	CPU_EN | (0147 * 16 + c_timming_b),	// 63

	/* BITMAP */				CPU_EN | (0150 * 16 + c_timming_b),	// 64
	/* BITMAP */				CPU_EN | (0151 * 16 + c_timming_b),	// 65
	/* SPRITE */				CPU_EN | (0152 * 16 + c_timming_b),	// 66
	0153 * 16 + c_timming_a,	CPU_EN | (0153 * 16 + c_timming_b),	// 67
	0154 * 16 + c_timming_a,	CPU_EN | (0154 * 16 + c_timming_b),	// 68
	0155 * 16 + c_timming_a,	CPU_EN | (0155 * 16 + c_timming_b),	// 69
	0156 * 16 + c_timming_a,	CPU_EN | (0156 * 16 + c_timming_b),	// 70
	0157 * 16 + c_timming_a,	CPU_EN | (0157 * 16 + c_timming_b),	// 71

	/* BITMAP */				CPU_EN | (0160 * 16 + c_timming_b),	// 72
	/* BITMAP */				CPU_EN | (0161 * 16 + c_timming_b),	// 73
	/* SPRITE */				CPU_EN | (0162 * 16 + c_timming_b),	// 74
	0163 * 16 + c_timming_a,	CPU_EN | (0163 * 16 + c_timming_b),	// 75
	0164 * 16 + c_timming_a,	CPU_EN | (0164 * 16 + c_timming_b),	// 76
	0165 * 16 + c_timming_a,	CPU_EN | (0165 * 16 + c_timming_b),	// 77
	0166 * 16 + c_timming_a,	CPU_EN | (0166 * 16 + c_timming_b),	// 78
	0167 * 16 + c_timming_a,	CPU_EN | (0167 * 16 + c_timming_b),	// 79

	/* BITMAP */				CPU_EN | (0170 * 16 + c_timming_b),	// 80
	/* BITMAP */				CPU_EN | (0171 * 16 + c_timming_b),	// 81
	/* SPRITE */				CPU_EN | (0172 * 16 + c_timming_b),	// 82
	0173 * 16 + c_timming_a,	CPU_EN | (0173 * 16 + c_timming_b),	// 83
	0174 * 16 + c_timming_a,	CPU_EN | (0174 * 16 + c_timming_b),	// 84
	0175 * 16 + c_timming_a,	CPU_EN | (0175 * 16 + c_timming_b),	// 85
	0176 * 16 + c_timming_a,	CPU_EN | (0176 * 16 + c_timming_b),	// 86
	0177 * 16 + c_timming_a,	CPU_EN | (0177 * 16 + c_timming_b),	// 87

	/* BITMAP */				CPU_EN | (0200 * 16 + c_timming_b),	// 88
	/* BITMAP */				CPU_EN | (0201 * 16 + c_timming_b),	// 89
	/* SPRITE */				CPU_EN | (0202 * 16 + c_timming_b),	// 90
	0203 * 16 + c_timming_a,	CPU_EN | (0203 * 16 + c_timming_b),	// 91
	0204 * 16 + c_timming_a,	CPU_EN | (0204 * 16 + c_timming_b),	// 92
	0205 * 16 + c_timming_a,	CPU_EN | (0205 * 16 + c_timming_b),	// 93
	0206 * 16 + c_timming_a,	CPU_EN | (0206 * 16 + c_timming_b),	// 94
	0207 * 16 + c_timming_a,	CPU_EN | (0207 * 16 + c_timming_b),	// 95

	/* BITMAP */				CPU_EN | (0210 * 16 + c_timming_b),	// 96
	/* BITMAP */				CPU_EN | (0211 * 16 + c_timming_b),	// 97
	/* SPRITE */				CPU_EN | (0212 * 16 + c_timming_b),	// 98
	0213 * 16 + c_timming_a,	CPU_EN | (0213 * 16 + c_timming_b),	// 99
	0214 * 16 + c_timming_a,	CPU_EN | (0214 * 16 + c_timming_b),	// 100
	0215 * 16 + c_timming_a,	CPU_EN | (0215 * 16 + c_timming_b),	// 101
	0216 * 16 + c_timming_a,	CPU_EN | (0216 * 16 + c_timming_b),	// 102
	0217 * 16 + c_timming_a,	CPU_EN | (0217 * 16 + c_timming_b),	// 103

	/* BITMAP */				CPU_EN | (0220 * 16 + c_timming_b),	// 104
	/* BITMAP */				CPU_EN | (0221 * 16 + c_timming_b),	// 105
	/* SPRITE */				CPU_EN | (0222 * 16 + c_timming_b),	// 106
	0223 * 16 + c_timming_a,	CPU_EN | (0223 * 16 + c_timming_b),	// 107
	0224 * 16 + c_timming_a,	CPU_EN | (0224 * 16 + c_timming_b),	// 108
	0225 * 16 + c_timming_a,	CPU_EN | (0225 * 16 + c_timming_b),	// 109
	0226 * 16 + c_timming_a,	CPU_EN | (0226 * 16 + c_timming_b),	// 110
	0227 * 16 + c_timming_a,	CPU_EN | (0227 * 16 + c_timming_b),	// 111

	/* BITMAP */				CPU_EN | (0230 * 16 + c_timming_b),	// 112
	/* BITMAP */				CPU_EN | (0231 * 16 + c_timming_b),	// 113
	/* SPRITE */				CPU_EN | (0232 * 16 + c_timming_b),	// 114
	0233 * 16 + c_timming_a,	CPU_EN | (0233 * 16 + c_timming_b),	// 115
	0234 * 16 + c_timming_a,	CPU_EN | (0234 * 16 + c_timming_b),	// 116
	0235 * 16 + c_timming_a,	CPU_EN | (0235 * 16 + c_timming_b),	// 117
	0236 * 16 + c_timming_a,	CPU_EN | (0236 * 16 + c_timming_b),	// 118
	0237 * 16 + c_timming_a,	CPU_EN | (0237 * 16 + c_timming_b),	// 119

	/* BITMAP */				CPU_EN | (0240 * 16 + c_timming_b),	// 120
	/* BITMAP */				CPU_EN | (0241 * 16 + c_timming_b),	// 121
	/* SPRITE */				CPU_EN | (0242 * 16 + c_timming_b),	// 122
	0243 * 16 + c_timming_a,	CPU_EN | (0243 * 16 + c_timming_b),	// 123
	0244 * 16 + c_timming_a,	CPU_EN | (0244 * 16 + c_timming_b),	// 124
	0245 * 16 + c_timming_a,	CPU_EN | (0245 * 16 + c_timming_b),	// 125
	0246 * 16 + c_timming_a,	CPU_EN | (0246 * 16 + c_timming_b),	// 126
	0247 * 16 + c_timming_a,	CPU_EN | (0247 * 16 + c_timming_b),	// 127

	/* BITMAP */				CPU_EN | (0250 * 16 + c_timming_b),	// 128
	/* BITMAP */				CPU_EN | (0251 * 16 + c_timming_b),	// 129
	/* SPRITE */				CPU_EN | (0252 * 16 + c_timming_b),	// 130
	0253 * 16 + c_timming_a,	CPU_EN | (0253 * 16 + c_timming_b),	// 131
	0254 * 16 + c_timming_a,	CPU_EN | (0254 * 16 + c_timming_b),	// 132
	0255 * 16 + c_timming_a,	CPU_EN | (0255 * 16 + c_timming_b),	// 133
	0256 * 16 + c_timming_a,	CPU_EN | (0256 * 16 + c_timming_b),	// 134
	0257 * 16 + c_timming_a,	CPU_EN | (0257 * 16 + c_timming_b),	// 135

	/* BITMAP */				CPU_EN | (0260 * 16 + c_timming_b),	// 136
	/* BITMAP */				CPU_EN | (0261 * 16 + c_timming_b),	// 137
	/* SPRITE */				CPU_EN | (0262 * 16 + c_timming_b),	// 138
	0263 * 16 + c_timming_a,	CPU_EN | (0263 * 16 + c_timming_b),	// 139
	0264 * 16 + c_timming_a,	CPU_EN | (0264 * 16 + c_timming_b),	// 140
	0265 * 16 + c_timming_a,	CPU_EN | (0265 * 16 + c_timming_b),	// 141
	0266 * 16 + c_timming_a,	CPU_EN | (0266 * 16 + c_timming_b),	// 142
	0267 * 16 + c_timming_a,	CPU_EN | (0267 * 16 + c_timming_b),	// 143

	/* BITMAP */				CPU_EN | (0270 * 16 + c_timming_b),	// 144
	/* BITMAP */				CPU_EN | (0271 * 16 + c_timming_b),	// 145
	/* SPRITE */				CPU_EN | (0272 * 16 + c_timming_b),	// 146
	0273 * 16 + c_timming_a,	CPU_EN | (0273 * 16 + c_timming_b),	// 147
	0274 * 16 + c_timming_a,	CPU_EN | (0274 * 16 + c_timming_b),	// 148
	0275 * 16 + c_timming_a,	CPU_EN | (0275 * 16 + c_timming_b),	// 149
	0276 * 16 + c_timming_a,	CPU_EN | (0276 * 16 + c_timming_b),	// 150
	0277 * 16 + c_timming_a,	CPU_EN | (0277 * 16 + c_timming_b),	// 151

	/* BITMAP */				CPU_EN | (0300 * 16 + c_timming_b),	// 152
	/* BITMAP */				CPU_EN | (0301 * 16 + c_timming_b),	// 153
	/* SPRITE */				CPU_EN | (0302 * 16 + c_timming_b),	// 154
	0303 * 16 + c_timming_a,	CPU_EN | (0303 * 16 + c_timming_b),	// 155
	0304 * 16 + c_timming_a,	CPU_EN | (0304 * 16 + c_timming_b),	// 156
	0305 * 16 + c_timming_a,	CPU_EN | (0305 * 16 + c_timming_b),	// 157
	0306 * 16 + c_timming_a,	CPU_EN | (0306 * 16 + c_timming_b),	// 158
	0307 * 16 + c_timming_a,	CPU_EN | (0307 * 16 + c_timming_b),	// 159

	/* BITMAP */				CPU_EN | (0310 * 16 + c_timming_b),	// 160
	/* BITMAP */				CPU_EN | (0311 * 16 + c_timming_b),	// 161
	/* SPRITE */				CPU_EN | (0312 * 16 + c_timming_b),	// 162
	0313 * 16 + c_timming_a,	CPU_EN | (0313 * 16 + c_timming_b),	// 163
	0314 * 16 + c_timming_a,	CPU_EN | (0314 * 16 + c_timming_b),	// 164
	0315 * 16 + c_timming_a,	CPU_EN | (0315 * 16 + c_timming_b),	// 165
	0316 * 16 + c_timming_a,	CPU_EN | (0316 * 16 + c_timming_b),	// 166
	0317 * 16 + c_timming_a,	CPU_EN | (0317 * 16 + c_timming_b),	// 167

	/* BITMAP */				CPU_EN | (0320 * 16 + c_timming_b),	// 168
	/* BITMAP */				CPU_EN | (0321 * 16 + c_timming_b),	// 169
	/* SPRITE */				CPU_EN | (0322 * 16 + c_timming_b),	// 170
	0323 * 16 + c_timming_a,	CPU_EN | (0323 * 16 + c_timming_b),	// 171
	0324 * 16 + c_timming_a,	CPU_EN | (0324 * 16 + c_timming_b),	// 172
	0325 * 16 + c_timming_a,	CPU_EN | (0325 * 16 + c_timming_b),	// 173
	0326 * 16 + c_timming_a,	CPU_EN | (0326 * 16 + c_timming_b),	// 174
	0327 * 16 + c_timming_a,	CPU_EN | (0327 * 16 + c_timming_b),	// 175

	/* BITMAP */				CPU_EN | (0330 * 16 + c_timming_b),	// 176
	/* BITMAP */				CPU_EN | (0331 * 16 + c_timming_b),	// 177
	/* SPRITE */				CPU_EN | (0332 * 16 + c_timming_b),	// 178
	0333 * 16 + c_timming_a,	CPU_EN | (0333 * 16 + c_timming_b),	// 179
	0334 * 16 + c_timming_a,	CPU_EN | (0334 * 16 + c_timming_b),	// 180
	0335 * 16 + c_timming_a,	CPU_EN | (0335 * 16 + c_timming_b),	// 181
	0336 * 16 + c_timming_a,	CPU_EN | (0336 * 16 + c_timming_b),	// 182
	0337 * 16 + c_timming_a,	CPU_EN | (0337 * 16 + c_timming_b),	// 183

	/* BITMAP */				CPU_EN | (0340 * 16 + c_timming_b),	// 184
	/* BITMAP */				CPU_EN | (0341 * 16 + c_timming_b),	// 185
	/* SPRITE */				CPU_EN | (0342 * 16 + c_timming_b),	// 186
	0343 * 16 + c_timming_a,	CPU_EN | (0343 * 16 + c_timming_b),	// 187
	0344 * 16 + c_timming_a,	CPU_EN | (0344 * 16 + c_timming_b),	// 188
	0345 * 16 + c_timming_a,	CPU_EN | (0345 * 16 + c_timming_b),	// 189
	0346 * 16 + c_timming_a,	CPU_EN | (0346 * 16 + c_timming_b),	// 190
	0347 * 16 + c_timming_a,	CPU_EN | (0347 * 16 + c_timming_b),	// 191

	/* BITMAP */				CPU_EN | (0350 * 16 + c_timming_b),	// 192
	/* BITMAP */				CPU_EN | (0351 * 16 + c_timming_b),	// 193
	/* SPRITE */				CPU_EN | (0352 * 16 + c_timming_b),	// 194
	0353 * 16 + c_timming_a,	CPU_EN | (0353 * 16 + c_timming_b),	// 195
	0354 * 16 + c_timming_a,	CPU_EN | (0354 * 16 + c_timming_b),	// 196
	0355 * 16 + c_timming_a,	CPU_EN | (0355 * 16 + c_timming_b),	// 197
	0356 * 16 + c_timming_a,	CPU_EN | (0356 * 16 + c_timming_b),	// 198
	0357 * 16 + c_timming_a,	CPU_EN | (0357 * 16 + c_timming_b),	// 199

	/* BITMAP */				CPU_EN | (0360 * 16 + c_timming_b),	// 200
	/* BITMAP */				CPU_EN | (0361 * 16 + c_timming_b),	// 201
	/* SPRITE */				CPU_EN | (0362 * 16 + c_timming_b),	// 202
	0363 * 16 + c_timming_a,	CPU_EN | (0363 * 16 + c_timming_b),	// 203
	0364 * 16 + c_timming_a,	CPU_EN | (0364 * 16 + c_timming_b),	// 204
	0365 * 16 + c_timming_a,	CPU_EN | (0365 * 16 + c_timming_b),	// 205
	0366 * 16 + c_timming_a,	CPU_EN | (0366 * 16 + c_timming_b),	// 206
	0367 * 16 + c_timming_a,	CPU_EN | (0367 * 16 + c_timming_b),	// 207

	/* BITMAP */				CPU_EN | (0370 * 16 + c_timming_b),	// 208
	/* BITMAP */				CPU_EN | (0371 * 16 + c_timming_b),	// 209
	/* SPRITE */				CPU_EN | (0372 * 16 + c_timming_b),	// 210
	0373 * 16 + c_timming_a,	CPU_EN | (0373 * 16 + c_timming_b),	// 211
	0374 * 16 + c_timming_a,	CPU_EN | (0374 * 16 + c_timming_b),	// 212
	0375 * 16 + c_timming_a,	CPU_EN | (0375 * 16 + c_timming_b),	// 213
	0376 * 16 + c_timming_a,	CPU_EN | (0376 * 16 + c_timming_b),	// 214
	0377 * 16 + c_timming_a,	CPU_EN | (0377 * 16 + c_timming_b),	// 215

	/* BITMAP */				CPU_EN | (0400 * 16 + c_timming_b),	// 216
	/* BITMAP */				CPU_EN | (0401 * 16 + c_timming_b),	// 217
	/* SPRITE */				CPU_EN | (0402 * 16 + c_timming_b),	// 218
	0403 * 16 + c_timming_a,	CPU_EN | (0403 * 16 + c_timming_b),	// 219
	0404 * 16 + c_timming_a,	CPU_EN | (0404 * 16 + c_timming_b),	// 220
	0405 * 16 + c_timming_a,	CPU_EN | (0405 * 16 + c_timming_b),	// 221
	0406 * 16 + c_timming_a,	CPU_EN | (0406 * 16 + c_timming_b),	// 222
	0407 * 16 + c_timming_a,	CPU_EN | (0407 * 16 + c_timming_b),	// 223

	/* BITMAP */				CPU_EN | (0410 * 16 + c_timming_b),	// 224
	/* BITMAP */				CPU_EN | (0411 * 16 + c_timming_b),	// 225
	/* SPRITE */				CPU_EN | (0412 * 16 + c_timming_b),	// 226
	0413 * 16 + c_timming_a,	CPU_EN | (0413 * 16 + c_timming_b),	// 227
	0414 * 16 + c_timming_a,	CPU_EN | (0414 * 16 + c_timming_b),	// 228
	0415 * 16 + c_timming_a,	CPU_EN | (0415 * 16 + c_timming_b),	// 229
	0416 * 16 + c_timming_a,	CPU_EN | (0416 * 16 + c_timming_b),	// 230
	0417 * 16 + c_timming_a,	CPU_EN | (0417 * 16 + c_timming_b),	// 231

	/* BITMAP */				CPU_EN | (0420 * 16 + c_timming_b),	// 232
	/* BITMAP */				CPU_EN | (0421 * 16 + c_timming_b),	// 233
	/* SPRITE */				CPU_EN | (0422 * 16 + c_timming_b),	// 234
	0423 * 16 + c_timming_a,	CPU_EN | (0423 * 16 + c_timming_b),	// 235
	0424 * 16 + c_timming_a,	CPU_EN | (0424 * 16 + c_timming_b),	// 236
	0425 * 16 + c_timming_a,	CPU_EN | (0425 * 16 + c_timming_b),	// 237
	0426 * 16 + c_timming_a,	CPU_EN | (0426 * 16 + c_timming_b),	// 238
	0427 * 16 + c_timming_a,	CPU_EN | (0427 * 16 + c_timming_b),	// 239

	/* BITMAP */				CPU_EN | (0430 * 16 + c_timming_b),	// 240
	/* BITMAP */				CPU_EN | (0431 * 16 + c_timming_b),	// 241
	/* SPRITE */				CPU_EN | (0432 * 16 + c_timming_b),	// 242
	0433 * 16 + c_timming_a,	CPU_EN | (0433 * 16 + c_timming_b),	// 243
	0434 * 16 + c_timming_a,	CPU_EN | (0434 * 16 + c_timming_b),	// 244
	0435 * 16 + c_timming_a,	CPU_EN | (0435 * 16 + c_timming_b),	// 245
	0436 * 16 + c_timming_a,	CPU_EN | (0436 * 16 + c_timming_b),	// 246
	0437 * 16 + c_timming_a,	CPU_EN | (0437 * 16 + c_timming_b),	// 247

	0440 * 16 + c_timming_a,	CPU_EN | (0440 * 16 + c_timming_b),	// 248
	0441 * 16 + c_timming_a,	CPU_EN | (0441 * 16 + c_timming_b),	// 249
	/* SPRITE */				CPU_EN | (0442 * 16 + c_timming_b),	// 250
	0443 * 16 + c_timming_a,	CPU_EN | (0443 * 16 + c_timming_b),	// 251
	0444 * 16 + c_timming_a,	CPU_EN | (0444 * 16 + c_timming_b),	// 252
	0445 * 16 + c_timming_a,	CPU_EN | (0445 * 16 + c_timming_b),	// 253
	0446 * 16 + c_timming_a,	CPU_EN | (0446 * 16 + c_timming_b),	// 254
	0447 * 16 + c_timming_a,	CPU_EN | (0447 * 16 + c_timming_b),	// 255

	0450 * 16 + c_timming_a,	CPU_EN | (0450 * 16 + c_timming_b),	// 256
	0451 * 16 + c_timming_a,	CPU_EN | (0451 * 16 + c_timming_b),	// 257
	/* SPRITE */				CPU_EN | (0452 * 16 + c_timming_b),	// 258
	0453 * 16 + c_timming_a,	CPU_EN | (0453 * 16 + c_timming_b),	// 259
	0454 * 16 + c_timming_a,	CPU_EN | (0454 * 16 + c_timming_b),	// 260
	0455 * 16 + c_timming_a,	CPU_EN | (0455 * 16 + c_timming_b),	// 261
	0456 * 16 + c_timming_a,	CPU_EN | (0456 * 16 + c_timming_b),	// 262
	0457 * 16 + c_timming_a,	CPU_EN | (0457 * 16 + c_timming_b),	// 263

	0460 * 16 + c_timming_a,	CPU_EN | (0460 * 16 + c_timming_b),	// 264
	0461 * 16 + c_timming_a,	CPU_EN | (0461 * 16 + c_timming_b),	// 265
	/* SPRITE */				CPU_EN | (0462 * 16 + c_timming_b),	// 266
	0463 * 16 + c_timming_a,	CPU_EN | (0463 * 16 + c_timming_b),	// 267
	0464 * 16 + c_timming_a,	CPU_EN | (0464 * 16 + c_timming_b),	// 268
	0465 * 16 + c_timming_a,	CPU_EN | (0465 * 16 + c_timming_b),	// 269
	0466 * 16 + c_timming_a,	CPU_EN | (0466 * 16 + c_timming_b),	// 270
	0467 * 16 + c_timming_a,	CPU_EN | (0467 * 16 + c_timming_b),	// 271

	0470 * 16 + c_timming_a,	CPU_EN | (0470 * 16 + c_timming_b),	// 272
	0471 * 16 + c_timming_a,	CPU_EN | (0471 * 16 + c_timming_b),	// 273
	/* SPRITE */				CPU_EN | (0472 * 16 + c_timming_b),	// 274
	0473 * 16 + c_timming_a,	CPU_EN | (0473 * 16 + c_timming_b),	// 275
	0474 * 16 + c_timming_a,	CPU_EN | (0474 * 16 + c_timming_b),	// 276
	0475 * 16 + c_timming_a,	CPU_EN | (0475 * 16 + c_timming_b),	// 277
	0476 * 16 + c_timming_a,	CPU_EN | (0476 * 16 + c_timming_b),	// 278
	0477 * 16 + c_timming_a,	CPU_EN | (0477 * 16 + c_timming_b),	// 279

	0500 * 16 + c_timming_a,	CPU_EN | (0500 * 16 + c_timming_b),	// 280
	0501 * 16 + c_timming_a,	CPU_EN | (0501 * 16 + c_timming_b),	// 281
	/* SPRITE */				CPU_EN | (0502 * 16 + c_timming_b),	// 282
	0503 * 16 + c_timming_a,	CPU_EN | (0503 * 16 + c_timming_b),	// 283
	0504 * 16 + c_timming_a,	CPU_EN | (0504 * 16 + c_timming_b),	// 284
	0505 * 16 + c_timming_a,	CPU_EN | (0505 * 16 + c_timming_b),	// 285
	0506 * 16 + c_timming_a,	CPU_EN | (0506 * 16 + c_timming_b),	// 286
	0507 * 16 + c_timming_a,	CPU_EN | (0507 * 16 + c_timming_b),	// 287

	0510 * 16 + c_timming_a,	CPU_EN | (0510 * 16 + c_timming_b),	// 288
	0511 * 16 + c_timming_a,	CPU_EN | (0511 * 16 + c_timming_b),	// 289
	/* SPRITE */				CPU_EN | (0512 * 16 + c_timming_b),	// 290
	0513 * 16 + c_timming_a,	CPU_EN | (0513 * 16 + c_timming_b),	// 291
	0514 * 16 + c_timming_a,	CPU_EN | (0514 * 16 + c_timming_b),	// 292
	0515 * 16 + c_timming_a,	CPU_EN | (0515 * 16 + c_timming_b),	// 293
	0516 * 16 + c_timming_a,	CPU_EN | (0516 * 16 + c_timming_b),	// 294
	0517 * 16 + c_timming_a,	CPU_EN | (0517 * 16 + c_timming_b),	// 295

	0520 * 16 + c_timming_a,	CPU_EN | (0520 * 16 + c_timming_b),	// 296
	0521 * 16 + c_timming_a,	CPU_EN | (0521 * 16 + c_timming_b),	// 297
	/* SPRITE */				CPU_EN | (0522 * 16 + c_timming_b),	// 298
	0523 * 16 + c_timming_a,	CPU_EN | (0523 * 16 + c_timming_b),	// 299
	0524 * 16 + c_timming_a,	CPU_EN | (0524 * 16 + c_timming_b),	// 300
	0525 * 16 + c_timming_a,	CPU_EN | (0525 * 16 + c_timming_b),	// 301

	0526 * 16 + c_timming_a,	CPU_EN | (0526 * 16 + c_timming_b),	// -40
	0527 * 16 + c_timming_a,	CPU_EN | (0527 * 16 + c_timming_b),	// -39
	/* SPRITE */				CPU_EN | (0530 * 16 + c_timming_b),	// -38
	0531 * 16 + c_timming_a,	CPU_EN | (0531 * 16 + c_timming_b),	// -37
	0532 * 16 + c_timming_a,	CPU_EN | (0532 * 16 + c_timming_b),	// -36
	0533 * 16 + c_timming_a,	CPU_EN | (0533 * 16 + c_timming_b),	// -35
	0534 * 16 + c_timming_a,	CPU_EN | (0534 * 16 + c_timming_b),	// -34
	0535 * 16 + c_timming_a,	CPU_EN | (0535 * 16 + c_timming_b),	// -33

	/* REFRESH */													// -32
	0537 * 16 + c_timming_a,	CPU_EN | (0537 * 16 + c_timming_b)	// -31
};

// screen 1,2,4
static constexpr std::array<int16_t, 700-96> slotsV9968PcgSpritesOff = {
	0000 * 16 + c_timming_a,	CPU_EN | (0000 * 16 + c_timming_b),	// -40
	0001 * 16 + c_timming_a,	CPU_EN | (0001 * 16 + c_timming_b),	// -39
	0002 * 16 + c_timming_a,	CPU_EN | (0002 * 16 + c_timming_b),	// -38
	0003 * 16 + c_timming_a,	CPU_EN | (0003 * 16 + c_timming_b),	// -37
	0004 * 16 + c_timming_a,	CPU_EN | (0004 * 16 + c_timming_b),	// -36
	0005 * 16 + c_timming_a,	CPU_EN | (0005 * 16 + c_timming_b),	// -35
	0006 * 16 + c_timming_a,	CPU_EN | (0006 * 16 + c_timming_b),	// -34
	0007 * 16 + c_timming_a,	CPU_EN | (0007 * 16 + c_timming_b),	// -33

	/* REFRESH */													// -32
	0011 * 16 + c_timming_a,	CPU_EN | (0011 * 16 + c_timming_b),	// -31
	0012 * 16 + c_timming_a,	CPU_EN | (0012 * 16 + c_timming_b),	// -30
	0013 * 16 + c_timming_a,	CPU_EN | (0013 * 16 + c_timming_b),	// -29
	0014 * 16 + c_timming_a,	CPU_EN | (0014 * 16 + c_timming_b),	// -28
	0015 * 16 + c_timming_a,	CPU_EN | (0015 * 16 + c_timming_b),	// -27
	0016 * 16 + c_timming_a,	CPU_EN | (0016 * 16 + c_timming_b),	// -26
	0017 * 16 + c_timming_a,	CPU_EN | (0017 * 16 + c_timming_b),	// -25

	0020 * 16 + c_timming_a,	CPU_EN | (0020 * 16 + c_timming_b),	// -24
	0021 * 16 + c_timming_a,	CPU_EN | (0021 * 16 + c_timming_b),	// -23
	0022 * 16 + c_timming_a,	CPU_EN | (0022 * 16 + c_timming_b),	// -22
	0023 * 16 + c_timming_a,	CPU_EN | (0023 * 16 + c_timming_b),	// -21
	0024 * 16 + c_timming_a,	CPU_EN | (0024 * 16 + c_timming_b),	// -20
	0025 * 16 + c_timming_a,	CPU_EN | (0025 * 16 + c_timming_b),	// -19
	0026 * 16 + c_timming_a,	CPU_EN | (0026 * 16 + c_timming_b),	// -18
	0027 * 16 + c_timming_a,	CPU_EN | (0027 * 16 + c_timming_b),	// -17

	0030 * 16 + c_timming_a,	CPU_EN | (0030 * 16 + c_timming_b),	// -16
	0031 * 16 + c_timming_a,	CPU_EN | (0031 * 16 + c_timming_b),	// -15
	0032 * 16 + c_timming_a,	CPU_EN | (0032 * 16 + c_timming_b),	// -14
	0033 * 16 + c_timming_a,	CPU_EN | (0033 * 16 + c_timming_b),	// -13
	0034 * 16 + c_timming_a,	CPU_EN | (0034 * 16 + c_timming_b),	// -12
	0035 * 16 + c_timming_a,	CPU_EN | (0035 * 16 + c_timming_b),	// -11
	0036 * 16 + c_timming_a,	CPU_EN | (0036 * 16 + c_timming_b),	// -10
	0037 * 16 + c_timming_a,	CPU_EN | (0037 * 16 + c_timming_b),	// -9

	/* NAME */					CPU_EN | (0040 * 16 + c_timming_b),	// -8
	/* PATTERN */				CPU_EN | (0041 * 16 + c_timming_b),	// -7
	0042 * 16 + c_timming_a,	CPU_EN | (0042 * 16 + c_timming_b),	// -6
	/* COLOR */					CPU_EN | (0043 * 16 + c_timming_b),	// -5
	0044 * 16 + c_timming_a,	CPU_EN | (0044 * 16 + c_timming_b),	// -4
	0045 * 16 + c_timming_a,	CPU_EN | (0045 * 16 + c_timming_b),	// -3
	0046 * 16 + c_timming_a,	CPU_EN | (0046 * 16 + c_timming_b),	// -2
	0047 * 16 + c_timming_a,	CPU_EN | (0047 * 16 + c_timming_b),	// -1

	/* NAME */					CPU_EN | (0050 * 16 + c_timming_b),	// 0
	/* PATTERN */				CPU_EN | (0051 * 16 + c_timming_b),	// 1
	0052 * 16 + c_timming_a,	CPU_EN | (0052 * 16 + c_timming_b),	// 2
	/* COLOR */					CPU_EN | (0053 * 16 + c_timming_b),	// 3
	0054 * 16 + c_timming_a,	CPU_EN | (0054 * 16 + c_timming_b),	// 4
	0055 * 16 + c_timming_a,	CPU_EN | (0055 * 16 + c_timming_b),	// 5
	0056 * 16 + c_timming_a,	CPU_EN | (0056 * 16 + c_timming_b),	// 6
	0057 * 16 + c_timming_a,	CPU_EN | (0057 * 16 + c_timming_b),	// 7

	/* NAME */					CPU_EN | (0060 * 16 + c_timming_b),	// 8
	/* PATTERN */				CPU_EN | (0061 * 16 + c_timming_b),	// 9
	0062 * 16 + c_timming_a,	CPU_EN | (0062 * 16 + c_timming_b),	// 10
	/* COLOR */					CPU_EN | (0063 * 16 + c_timming_b),	// 11
	0064 * 16 + c_timming_a,	CPU_EN | (0064 * 16 + c_timming_b),	// 12
	0065 * 16 + c_timming_a,	CPU_EN | (0065 * 16 + c_timming_b),	// 13
	0066 * 16 + c_timming_a,	CPU_EN | (0066 * 16 + c_timming_b),	// 14
	0067 * 16 + c_timming_a,	CPU_EN | (0067 * 16 + c_timming_b),	// 15

	/* NAME */					CPU_EN | (0070 * 16 + c_timming_b),	// 16
	/* PATTERN */				CPU_EN | (0071 * 16 + c_timming_b),	// 17
	0072 * 16 + c_timming_a,	CPU_EN | (0072 * 16 + c_timming_b),	// 18
	/* COLOR */					CPU_EN | (0073 * 16 + c_timming_b),	// 19
	0074 * 16 + c_timming_a,	CPU_EN | (0074 * 16 + c_timming_b),	// 20
	0075 * 16 + c_timming_a,	CPU_EN | (0075 * 16 + c_timming_b),	// 21
	0076 * 16 + c_timming_a,	CPU_EN | (0076 * 16 + c_timming_b),	// 22
	0077 * 16 + c_timming_a,	CPU_EN | (0077 * 16 + c_timming_b),	// 23

	/* NAME */					CPU_EN | (0100 * 16 + c_timming_b),	// 24
	/* PATTERN */				CPU_EN | (0101 * 16 + c_timming_b),	// 25
	0102 * 16 + c_timming_a,	CPU_EN | (0102 * 16 + c_timming_b),	// 26
	/* COLOR */					CPU_EN | (0103 * 16 + c_timming_b),	// 27
	0104 * 16 + c_timming_a,	CPU_EN | (0104 * 16 + c_timming_b),	// 28
	0105 * 16 + c_timming_a,	CPU_EN | (0105 * 16 + c_timming_b),	// 29
	0106 * 16 + c_timming_a,	CPU_EN | (0106 * 16 + c_timming_b),	// 30
	0107 * 16 + c_timming_a,	CPU_EN | (0107 * 16 + c_timming_b),	// 31

	/* NAME */					CPU_EN | (0110 * 16 + c_timming_b),	// 32
	/* PATTERN */				CPU_EN | (0111 * 16 + c_timming_b),	// 33
	0112 * 16 + c_timming_a,	CPU_EN | (0112 * 16 + c_timming_b),	// 34
	/* COLOR */					CPU_EN | (0113 * 16 + c_timming_b),	// 35
	0114 * 16 + c_timming_a,	CPU_EN | (0114 * 16 + c_timming_b),	// 36
	0115 * 16 + c_timming_a,	CPU_EN | (0115 * 16 + c_timming_b),	// 37
	0116 * 16 + c_timming_a,	CPU_EN | (0116 * 16 + c_timming_b),	// 38
	0117 * 16 + c_timming_a,	CPU_EN | (0117 * 16 + c_timming_b),	// 39

	/* NAME */					CPU_EN | (0120 * 16 + c_timming_b),	// 40
	/* PATTERN */				CPU_EN | (0121 * 16 + c_timming_b),	// 41
	0122 * 16 + c_timming_a,	CPU_EN | (0122 * 16 + c_timming_b),	// 42
	/* COLOR */					CPU_EN | (0123 * 16 + c_timming_b),	// 43
	0124 * 16 + c_timming_a,	CPU_EN | (0124 * 16 + c_timming_b),	// 44
	0125 * 16 + c_timming_a,	CPU_EN | (0125 * 16 + c_timming_b),	// 45
	0126 * 16 + c_timming_a,	CPU_EN | (0126 * 16 + c_timming_b),	// 46
	0127 * 16 + c_timming_a,	CPU_EN | (0127 * 16 + c_timming_b),	// 47

	/* NAME */					CPU_EN | (0130 * 16 + c_timming_b),	// 48
	/* PATTERN */				CPU_EN | (0131 * 16 + c_timming_b),	// 49
	0132 * 16 + c_timming_a,	CPU_EN | (0132 * 16 + c_timming_b),	// 50
	/* COLOR */					CPU_EN | (0133 * 16 + c_timming_b),	// 51
	0134 * 16 + c_timming_a,	CPU_EN | (0134 * 16 + c_timming_b),	// 52
	0135 * 16 + c_timming_a,	CPU_EN | (0135 * 16 + c_timming_b),	// 53
	0136 * 16 + c_timming_a,	CPU_EN | (0136 * 16 + c_timming_b),	// 54
	0137 * 16 + c_timming_a,	CPU_EN | (0137 * 16 + c_timming_b),	// 55

	/* NAME */					CPU_EN | (0140 * 16 + c_timming_b),	// 56
	/* PATTERN */				CPU_EN | (0141 * 16 + c_timming_b),	// 57
	0142 * 16 + c_timming_a,	CPU_EN | (0142 * 16 + c_timming_b),	// 58
	/* COLOR */					CPU_EN | (0143 * 16 + c_timming_b),	// 59
	0144 * 16 + c_timming_a,	CPU_EN | (0144 * 16 + c_timming_b),	// 60
	0145 * 16 + c_timming_a,	CPU_EN | (0145 * 16 + c_timming_b),	// 61
	0146 * 16 + c_timming_a,	CPU_EN | (0146 * 16 + c_timming_b),	// 62
	0147 * 16 + c_timming_a,	CPU_EN | (0147 * 16 + c_timming_b),	// 63

	/* NAME */					CPU_EN | (0150 * 16 + c_timming_b),	// 64
	/* PATTERN */				CPU_EN | (0151 * 16 + c_timming_b),	// 65
	0152 * 16 + c_timming_a,	CPU_EN | (0152 * 16 + c_timming_b),	// 66
	/* COLOR */					CPU_EN | (0153 * 16 + c_timming_b),	// 67
	0154 * 16 + c_timming_a,	CPU_EN | (0154 * 16 + c_timming_b),	// 68
	0155 * 16 + c_timming_a,	CPU_EN | (0155 * 16 + c_timming_b),	// 69
	0156 * 16 + c_timming_a,	CPU_EN | (0156 * 16 + c_timming_b),	// 70
	0157 * 16 + c_timming_a,	CPU_EN | (0157 * 16 + c_timming_b),	// 71

	/* NAME */					CPU_EN | (0160 * 16 + c_timming_b),	// 72
	/* PATTERN */				CPU_EN | (0161 * 16 + c_timming_b),	// 73
	0162 * 16 + c_timming_a,	CPU_EN | (0162 * 16 + c_timming_b),	// 74
	/* COLOR */					CPU_EN | (0163 * 16 + c_timming_b),	// 75
	0164 * 16 + c_timming_a,	CPU_EN | (0164 * 16 + c_timming_b),	// 76
	0165 * 16 + c_timming_a,	CPU_EN | (0165 * 16 + c_timming_b),	// 77
	0166 * 16 + c_timming_a,	CPU_EN | (0166 * 16 + c_timming_b),	// 78
	0167 * 16 + c_timming_a,	CPU_EN | (0167 * 16 + c_timming_b),	// 79

	/* PATTERN */				CPU_EN | (0170 * 16 + c_timming_b),	// 80
	/* PATTERN */				CPU_EN | (0171 * 16 + c_timming_b),	// 81
	0172 * 16 + c_timming_a,	CPU_EN | (0172 * 16 + c_timming_b),	// 82
	/* COLOR */					CPU_EN | (0173 * 16 + c_timming_b),	// 83
	0174 * 16 + c_timming_a,	CPU_EN | (0174 * 16 + c_timming_b),	// 84
	0175 * 16 + c_timming_a,	CPU_EN | (0175 * 16 + c_timming_b),	// 85
	0176 * 16 + c_timming_a,	CPU_EN | (0176 * 16 + c_timming_b),	// 86
	0177 * 16 + c_timming_a,	CPU_EN | (0177 * 16 + c_timming_b),	// 87

	/* NAME */					CPU_EN | (0200 * 16 + c_timming_b),	// 88
	/* PATTERN */				CPU_EN | (0201 * 16 + c_timming_b),	// 89
	0202 * 16 + c_timming_a,	CPU_EN | (0202 * 16 + c_timming_b),	// 90
	/* COLOR */					CPU_EN | (0203 * 16 + c_timming_b),	// 91
	0204 * 16 + c_timming_a,	CPU_EN | (0204 * 16 + c_timming_b),	// 92
	0205 * 16 + c_timming_a,	CPU_EN | (0205 * 16 + c_timming_b),	// 93
	0206 * 16 + c_timming_a,	CPU_EN | (0206 * 16 + c_timming_b),	// 94
	0207 * 16 + c_timming_a,	CPU_EN | (0207 * 16 + c_timming_b),	// 95

	/* NAME */					CPU_EN | (0210 * 16 + c_timming_b),	// 96
	/* PATTERN */				CPU_EN | (0211 * 16 + c_timming_b),	// 97
	0212 * 16 + c_timming_a,	CPU_EN | (0212 * 16 + c_timming_b),	// 98
	/* COLOR */					CPU_EN | (0213 * 16 + c_timming_b),	// 99
	0214 * 16 + c_timming_a,	CPU_EN | (0214 * 16 + c_timming_b),	// 100
	0215 * 16 + c_timming_a,	CPU_EN | (0215 * 16 + c_timming_b),	// 101
	0216 * 16 + c_timming_a,	CPU_EN | (0216 * 16 + c_timming_b),	// 102
	0217 * 16 + c_timming_a,	CPU_EN | (0217 * 16 + c_timming_b),	// 103

	/* NAME */					CPU_EN | (0220 * 16 + c_timming_b),	// 104
	/* PATTERN */				CPU_EN | (0221 * 16 + c_timming_b),	// 105
	0222 * 16 + c_timming_a,	CPU_EN | (0222 * 16 + c_timming_b),	// 106
	/* COLOR */					CPU_EN | (0223 * 16 + c_timming_b),	// 107
	0224 * 16 + c_timming_a,	CPU_EN | (0224 * 16 + c_timming_b),	// 108
	0225 * 16 + c_timming_a,	CPU_EN | (0225 * 16 + c_timming_b),	// 109
	0226 * 16 + c_timming_a,	CPU_EN | (0226 * 16 + c_timming_b),	// 110
	0227 * 16 + c_timming_a,	CPU_EN | (0227 * 16 + c_timming_b),	// 111

	/* NAME */					CPU_EN | (0230 * 16 + c_timming_b),	// 112
	/* PATTERN */				CPU_EN | (0231 * 16 + c_timming_b),	// 113
	0232 * 16 + c_timming_a,	CPU_EN | (0232 * 16 + c_timming_b),	// 114
	/* COLOR */					CPU_EN | (0233 * 16 + c_timming_b),	// 115
	0234 * 16 + c_timming_a,	CPU_EN | (0234 * 16 + c_timming_b),	// 116
	0235 * 16 + c_timming_a,	CPU_EN | (0235 * 16 + c_timming_b),	// 117
	0236 * 16 + c_timming_a,	CPU_EN | (0236 * 16 + c_timming_b),	// 118
	0237 * 16 + c_timming_a,	CPU_EN | (0237 * 16 + c_timming_b),	// 119

	/* NAME */					CPU_EN | (0240 * 16 + c_timming_b),	// 120
	/* PATTERN */				CPU_EN | (0241 * 16 + c_timming_b),	// 121
	0242 * 16 + c_timming_a,	CPU_EN | (0242 * 16 + c_timming_b),	// 122
	/* COLOR */					CPU_EN | (0243 * 16 + c_timming_b),	// 123
	0244 * 16 + c_timming_a,	CPU_EN | (0244 * 16 + c_timming_b),	// 124
	0245 * 16 + c_timming_a,	CPU_EN | (0245 * 16 + c_timming_b),	// 125
	0246 * 16 + c_timming_a,	CPU_EN | (0246 * 16 + c_timming_b),	// 126
	0247 * 16 + c_timming_a,	CPU_EN | (0247 * 16 + c_timming_b),	// 127

	/* NAME */					CPU_EN | (0250 * 16 + c_timming_b),	// 128
	/* PATTERN */				CPU_EN | (0251 * 16 + c_timming_b),	// 129
	0252 * 16 + c_timming_a,	CPU_EN | (0252 * 16 + c_timming_b),	// 130
	/* COLOR */					CPU_EN | (0253 * 16 + c_timming_b),	// 131
	0254 * 16 + c_timming_a,	CPU_EN | (0254 * 16 + c_timming_b),	// 132
	0255 * 16 + c_timming_a,	CPU_EN | (0255 * 16 + c_timming_b),	// 133
	0256 * 16 + c_timming_a,	CPU_EN | (0256 * 16 + c_timming_b),	// 134
	0257 * 16 + c_timming_a,	CPU_EN | (0257 * 16 + c_timming_b),	// 135

	/* NAME */					CPU_EN | (0260 * 16 + c_timming_b),	// 136
	/* PATTERN */				CPU_EN | (0261 * 16 + c_timming_b),	// 137
	0262 * 16 + c_timming_a,	CPU_EN | (0262 * 16 + c_timming_b),	// 138
	/* COLOR */					CPU_EN | (0263 * 16 + c_timming_b),	// 139
	0264 * 16 + c_timming_a,	CPU_EN | (0264 * 16 + c_timming_b),	// 140
	0265 * 16 + c_timming_a,	CPU_EN | (0265 * 16 + c_timming_b),	// 141
	0266 * 16 + c_timming_a,	CPU_EN | (0266 * 16 + c_timming_b),	// 142
	0267 * 16 + c_timming_a,	CPU_EN | (0267 * 16 + c_timming_b),	// 143

	/* NAME */					CPU_EN | (0270 * 16 + c_timming_b),	// 144
	/* PATTERN */				CPU_EN | (0271 * 16 + c_timming_b),	// 145
	0272 * 16 + c_timming_a,	CPU_EN | (0272 * 16 + c_timming_b),	// 146
	/* COLOR */					CPU_EN | (0273 * 16 + c_timming_b),	// 147
	0274 * 16 + c_timming_a,	CPU_EN | (0274 * 16 + c_timming_b),	// 148
	0275 * 16 + c_timming_a,	CPU_EN | (0275 * 16 + c_timming_b),	// 149
	0276 * 16 + c_timming_a,	CPU_EN | (0276 * 16 + c_timming_b),	// 150
	0277 * 16 + c_timming_a,	CPU_EN | (0277 * 16 + c_timming_b),	// 151

	/* NAME */					CPU_EN | (0300 * 16 + c_timming_b),	// 152
	/* PATTERN */				CPU_EN | (0301 * 16 + c_timming_b),	// 153
	0302 * 16 + c_timming_a,	CPU_EN | (0302 * 16 + c_timming_b),	// 154
	/* COLOR */					CPU_EN | (0303 * 16 + c_timming_b),	// 155
	0304 * 16 + c_timming_a,	CPU_EN | (0304 * 16 + c_timming_b),	// 156
	0305 * 16 + c_timming_a,	CPU_EN | (0305 * 16 + c_timming_b),	// 157
	0306 * 16 + c_timming_a,	CPU_EN | (0306 * 16 + c_timming_b),	// 158
	0307 * 16 + c_timming_a,	CPU_EN | (0307 * 16 + c_timming_b),	// 159

	/* NAME */					CPU_EN | (0310 * 16 + c_timming_b),	// 160
	/* PATTERN */				CPU_EN | (0311 * 16 + c_timming_b),	// 161
	0312 * 16 + c_timming_a,	CPU_EN | (0312 * 16 + c_timming_b),	// 162
	/* COLOR */					CPU_EN | (0313 * 16 + c_timming_b),	// 163
	0314 * 16 + c_timming_a,	CPU_EN | (0314 * 16 + c_timming_b),	// 164
	0315 * 16 + c_timming_a,	CPU_EN | (0315 * 16 + c_timming_b),	// 165
	0316 * 16 + c_timming_a,	CPU_EN | (0316 * 16 + c_timming_b),	// 166
	0317 * 16 + c_timming_a,	CPU_EN | (0317 * 16 + c_timming_b),	// 167

	/* NAME */					CPU_EN | (0320 * 16 + c_timming_b),	// 168
	/* PATTERN */				CPU_EN | (0321 * 16 + c_timming_b),	// 169
	0322 * 16 + c_timming_a,	CPU_EN | (0322 * 16 + c_timming_b),	// 170
	/* COLOR */					CPU_EN | (0323 * 16 + c_timming_b),	// 171
	0324 * 16 + c_timming_a,	CPU_EN | (0324 * 16 + c_timming_b),	// 172
	0325 * 16 + c_timming_a,	CPU_EN | (0325 * 16 + c_timming_b),	// 173
	0326 * 16 + c_timming_a,	CPU_EN | (0326 * 16 + c_timming_b),	// 174
	0327 * 16 + c_timming_a,	CPU_EN | (0327 * 16 + c_timming_b),	// 175

	/* NAME */					CPU_EN | (0330 * 16 + c_timming_b),	// 176
	/* PATTERN */				CPU_EN | (0331 * 16 + c_timming_b),	// 177
	0332 * 16 + c_timming_a,	CPU_EN | (0332 * 16 + c_timming_b),	// 178
	/* COLOR */					CPU_EN | (0333 * 16 + c_timming_b),	// 179
	0334 * 16 + c_timming_a,	CPU_EN | (0334 * 16 + c_timming_b),	// 180
	0335 * 16 + c_timming_a,	CPU_EN | (0335 * 16 + c_timming_b),	// 181
	0336 * 16 + c_timming_a,	CPU_EN | (0336 * 16 + c_timming_b),	// 182
	0337 * 16 + c_timming_a,	CPU_EN | (0337 * 16 + c_timming_b),	// 183

	/* NAME */					CPU_EN | (0340 * 16 + c_timming_b),	// 184
	/* PATTERN */				CPU_EN | (0341 * 16 + c_timming_b),	// 185
	0342 * 16 + c_timming_a,	CPU_EN | (0342 * 16 + c_timming_b),	// 186
	/* COLOR */					CPU_EN | (0343 * 16 + c_timming_b),	// 187
	0344 * 16 + c_timming_a,	CPU_EN | (0344 * 16 + c_timming_b),	// 188
	0345 * 16 + c_timming_a,	CPU_EN | (0345 * 16 + c_timming_b),	// 189
	0346 * 16 + c_timming_a,	CPU_EN | (0346 * 16 + c_timming_b),	// 190
	0347 * 16 + c_timming_a,	CPU_EN | (0347 * 16 + c_timming_b),	// 191

	/* NAME */					CPU_EN | (0350 * 16 + c_timming_b),	// 192
	/* PATTERN */				CPU_EN | (0351 * 16 + c_timming_b),	// 193
	0352 * 16 + c_timming_a,	CPU_EN | (0352 * 16 + c_timming_b),	// 194
	/* COLOR */					CPU_EN | (0353 * 16 + c_timming_b),	// 195
	0354 * 16 + c_timming_a,	CPU_EN | (0354 * 16 + c_timming_b),	// 196
	0355 * 16 + c_timming_a,	CPU_EN | (0355 * 16 + c_timming_b),	// 197
	0356 * 16 + c_timming_a,	CPU_EN | (0356 * 16 + c_timming_b),	// 198
	0357 * 16 + c_timming_a,	CPU_EN | (0357 * 16 + c_timming_b),	// 199

	/* NAME */					CPU_EN | (0360 * 16 + c_timming_b),	// 200
	/* PATTERN */				CPU_EN | (0361 * 16 + c_timming_b),	// 201
	0362 * 16 + c_timming_a,	CPU_EN | (0362 * 16 + c_timming_b),	// 202
	/* COLOR */					CPU_EN | (0363 * 16 + c_timming_b),	// 203
	0364 * 16 + c_timming_a,	CPU_EN | (0364 * 16 + c_timming_b),	// 204
	0365 * 16 + c_timming_a,	CPU_EN | (0365 * 16 + c_timming_b),	// 205
	0366 * 16 + c_timming_a,	CPU_EN | (0366 * 16 + c_timming_b),	// 206
	0367 * 16 + c_timming_a,	CPU_EN | (0367 * 16 + c_timming_b),	// 207

	/* NAME */					CPU_EN | (0370 * 16 + c_timming_b),	// 208
	/* PATTERN */				CPU_EN | (0371 * 16 + c_timming_b),	// 209
	0372 * 16 + c_timming_a,	CPU_EN | (0372 * 16 + c_timming_b),	// 210
	/* COLOR */					CPU_EN | (0373 * 16 + c_timming_b),	// 211
	0374 * 16 + c_timming_a,	CPU_EN | (0374 * 16 + c_timming_b),	// 212
	0375 * 16 + c_timming_a,	CPU_EN | (0375 * 16 + c_timming_b),	// 213
	0376 * 16 + c_timming_a,	CPU_EN | (0376 * 16 + c_timming_b),	// 214
	0377 * 16 + c_timming_a,	CPU_EN | (0377 * 16 + c_timming_b),	// 215

	/* NAME */					CPU_EN | (0400 * 16 + c_timming_b),	// 216
	/* PATTERN */				CPU_EN | (0401 * 16 + c_timming_b),	// 217
	0402 * 16 + c_timming_a,	CPU_EN | (0402 * 16 + c_timming_b),	// 218
	/* COLOR */					CPU_EN | (0403 * 16 + c_timming_b),	// 219
	0404 * 16 + c_timming_a,	CPU_EN | (0404 * 16 + c_timming_b),	// 220
	0405 * 16 + c_timming_a,	CPU_EN | (0405 * 16 + c_timming_b),	// 221
	0406 * 16 + c_timming_a,	CPU_EN | (0406 * 16 + c_timming_b),	// 222
	0407 * 16 + c_timming_a,	CPU_EN | (0407 * 16 + c_timming_b),	// 223

	/* NAME */					CPU_EN | (0410 * 16 + c_timming_b),	// 224
	/* PATTERN */				CPU_EN | (0411 * 16 + c_timming_b),	// 225
	0412 * 16 + c_timming_a,	CPU_EN | (0412 * 16 + c_timming_b),	// 226
	/* COLOR */					CPU_EN | (0413 * 16 + c_timming_b),	// 227
	0414 * 16 + c_timming_a,	CPU_EN | (0414 * 16 + c_timming_b),	// 228
	0415 * 16 + c_timming_a,	CPU_EN | (0415 * 16 + c_timming_b),	// 229
	0416 * 16 + c_timming_a,	CPU_EN | (0416 * 16 + c_timming_b),	// 230
	0417 * 16 + c_timming_a,	CPU_EN | (0417 * 16 + c_timming_b),	// 231

	/* NAME */					CPU_EN | (0420 * 16 + c_timming_b),	// 232
	/* PATTERN */				CPU_EN | (0421 * 16 + c_timming_b),	// 233
	0422 * 16 + c_timming_a,	CPU_EN | (0422 * 16 + c_timming_b),	// 234
	/* COLOR */					CPU_EN | (0423 * 16 + c_timming_b),	// 235
	0424 * 16 + c_timming_a,	CPU_EN | (0424 * 16 + c_timming_b),	// 236
	0425 * 16 + c_timming_a,	CPU_EN | (0425 * 16 + c_timming_b),	// 237
	0426 * 16 + c_timming_a,	CPU_EN | (0426 * 16 + c_timming_b),	// 238
	0427 * 16 + c_timming_a,	CPU_EN | (0427 * 16 + c_timming_b),	// 239

	/* NAME */					CPU_EN | (0430 * 16 + c_timming_b),	// 240
	/* PATTERN */				CPU_EN | (0431 * 16 + c_timming_b),	// 241
	0432 * 16 + c_timming_a,	CPU_EN | (0432 * 16 + c_timming_b),	// 242
	/* COLOR */					CPU_EN | (0433 * 16 + c_timming_b),	// 243
	0434 * 16 + c_timming_a,	CPU_EN | (0434 * 16 + c_timming_b),	// 244
	0435 * 16 + c_timming_a,	CPU_EN | (0435 * 16 + c_timming_b),	// 245
	0436 * 16 + c_timming_a,	CPU_EN | (0436 * 16 + c_timming_b),	// 246
	0437 * 16 + c_timming_a,	CPU_EN | (0437 * 16 + c_timming_b),	// 247

	0440 * 16 + c_timming_a,	CPU_EN | (0440 * 16 + c_timming_b),	// 248
	0441 * 16 + c_timming_a,	CPU_EN | (0441 * 16 + c_timming_b),	// 249
	0442 * 16 + c_timming_a,	CPU_EN | (0442 * 16 + c_timming_b),	// 250
	0443 * 16 + c_timming_a,	CPU_EN | (0443 * 16 + c_timming_b),	// 251
	0444 * 16 + c_timming_a,	CPU_EN | (0444 * 16 + c_timming_b),	// 252
	0445 * 16 + c_timming_a,	CPU_EN | (0445 * 16 + c_timming_b),	// 253
	0446 * 16 + c_timming_a,	CPU_EN | (0446 * 16 + c_timming_b),	// 254
	0447 * 16 + c_timming_a,	CPU_EN | (0447 * 16 + c_timming_b),	// 255

	0450 * 16 + c_timming_a,	CPU_EN | (0450 * 16 + c_timming_b),	// 256
	0451 * 16 + c_timming_a,	CPU_EN | (0451 * 16 + c_timming_b),	// 257
	0452 * 16 + c_timming_a,	CPU_EN | (0452 * 16 + c_timming_b),	// 258
	0453 * 16 + c_timming_a,	CPU_EN | (0453 * 16 + c_timming_b),	// 259
	0454 * 16 + c_timming_a,	CPU_EN | (0454 * 16 + c_timming_b),	// 260
	0455 * 16 + c_timming_a,	CPU_EN | (0455 * 16 + c_timming_b),	// 261
	0456 * 16 + c_timming_a,	CPU_EN | (0456 * 16 + c_timming_b),	// 262
	0457 * 16 + c_timming_a,	CPU_EN | (0457 * 16 + c_timming_b),	// 263

	0460 * 16 + c_timming_a,	CPU_EN | (0460 * 16 + c_timming_b),	// 264
	0461 * 16 + c_timming_a,	CPU_EN | (0461 * 16 + c_timming_b),	// 265
	0462 * 16 + c_timming_a,	CPU_EN | (0462 * 16 + c_timming_b),	// 266
	0463 * 16 + c_timming_a,	CPU_EN | (0463 * 16 + c_timming_b),	// 267
	0464 * 16 + c_timming_a,	CPU_EN | (0464 * 16 + c_timming_b),	// 268
	0465 * 16 + c_timming_a,	CPU_EN | (0465 * 16 + c_timming_b),	// 269
	0466 * 16 + c_timming_a,	CPU_EN | (0466 * 16 + c_timming_b),	// 270
	0467 * 16 + c_timming_a,	CPU_EN | (0467 * 16 + c_timming_b),	// 271

	0470 * 16 + c_timming_a,	CPU_EN | (0470 * 16 + c_timming_b),	// 272
	0471 * 16 + c_timming_a,	CPU_EN | (0471 * 16 + c_timming_b),	// 273
	0472 * 16 + c_timming_a,	CPU_EN | (0472 * 16 + c_timming_b),	// 274
	0473 * 16 + c_timming_a,	CPU_EN | (0473 * 16 + c_timming_b),	// 275
	0474 * 16 + c_timming_a,	CPU_EN | (0474 * 16 + c_timming_b),	// 276
	0475 * 16 + c_timming_a,	CPU_EN | (0475 * 16 + c_timming_b),	// 277
	0476 * 16 + c_timming_a,	CPU_EN | (0476 * 16 + c_timming_b),	// 278
	0477 * 16 + c_timming_a,	CPU_EN | (0477 * 16 + c_timming_b),	// 279

	0500 * 16 + c_timming_a,	CPU_EN | (0500 * 16 + c_timming_b),	// 280
	0501 * 16 + c_timming_a,	CPU_EN | (0501 * 16 + c_timming_b),	// 281
	0502 * 16 + c_timming_a,	CPU_EN | (0502 * 16 + c_timming_b),	// 282
	0503 * 16 + c_timming_a,	CPU_EN | (0503 * 16 + c_timming_b),	// 283
	0504 * 16 + c_timming_a,	CPU_EN | (0504 * 16 + c_timming_b),	// 284
	0505 * 16 + c_timming_a,	CPU_EN | (0505 * 16 + c_timming_b),	// 285
	0506 * 16 + c_timming_a,	CPU_EN | (0506 * 16 + c_timming_b),	// 286
	0507 * 16 + c_timming_a,	CPU_EN | (0507 * 16 + c_timming_b),	// 287

	0510 * 16 + c_timming_a,	CPU_EN | (0510 * 16 + c_timming_b),	// 288
	0511 * 16 + c_timming_a,	CPU_EN | (0511 * 16 + c_timming_b),	// 289
	0512 * 16 + c_timming_a,	CPU_EN | (0512 * 16 + c_timming_b),	// 290
	0513 * 16 + c_timming_a,	CPU_EN | (0513 * 16 + c_timming_b),	// 291
	0514 * 16 + c_timming_a,	CPU_EN | (0514 * 16 + c_timming_b),	// 292
	0515 * 16 + c_timming_a,	CPU_EN | (0515 * 16 + c_timming_b),	// 293
	0516 * 16 + c_timming_a,	CPU_EN | (0516 * 16 + c_timming_b),	// 294
	0517 * 16 + c_timming_a,	CPU_EN | (0517 * 16 + c_timming_b),	// 295

	0520 * 16 + c_timming_a,	CPU_EN | (0520 * 16 + c_timming_b),	// 296
	0521 * 16 + c_timming_a,	CPU_EN | (0521 * 16 + c_timming_b),	// 297
	0522 * 16 + c_timming_a,	CPU_EN | (0522 * 16 + c_timming_b),	// 298
	0523 * 16 + c_timming_a,	CPU_EN | (0523 * 16 + c_timming_b),	// 299
	0524 * 16 + c_timming_a,	CPU_EN | (0524 * 16 + c_timming_b),	// 300
	0525 * 16 + c_timming_a,	CPU_EN | (0525 * 16 + c_timming_b),	// 301

	0526 * 16 + c_timming_a,	CPU_EN | (0526 * 16 + c_timming_b),	// -40
	0527 * 16 + c_timming_a,	CPU_EN | (0527 * 16 + c_timming_b),	// -39
	0530 * 16 + c_timming_a,	CPU_EN | (0530 * 16 + c_timming_b),	// -38
	0531 * 16 + c_timming_a,	CPU_EN | (0531 * 16 + c_timming_b),	// -37
	0532 * 16 + c_timming_a,	CPU_EN | (0532 * 16 + c_timming_b),	// -36
	0533 * 16 + c_timming_a,	CPU_EN | (0533 * 16 + c_timming_b),	// -35
	0534 * 16 + c_timming_a,	CPU_EN | (0534 * 16 + c_timming_b),	// -34
	0535 * 16 + c_timming_a,	CPU_EN | (0535 * 16 + c_timming_b),	// -33

	/* REFRESH */													// -32
	0537 * 16 + c_timming_a,	CPU_EN | (0537 * 16 + c_timming_b)	// -31
};

// screen 1,2,4
static constexpr std::array<int16_t, 700-96-44> slotsV9968PcgSpritesOn = {
	0000 * 16 + c_timming_a,	CPU_EN | (0000 * 16 + c_timming_b),	// -40
	0001 * 16 + c_timming_a,	CPU_EN | (0001 * 16 + c_timming_b),	// -39
	/* SPRITE */				CPU_EN | (0002 * 16 + c_timming_b),	// -38
	0003 * 16 + c_timming_a,	CPU_EN | (0003 * 16 + c_timming_b),	// -37
	0004 * 16 + c_timming_a,	CPU_EN | (0004 * 16 + c_timming_b),	// -36
	0005 * 16 + c_timming_a,	CPU_EN | (0005 * 16 + c_timming_b),	// -35
	0006 * 16 + c_timming_a,	CPU_EN | (0006 * 16 + c_timming_b),	// -34
	0007 * 16 + c_timming_a,	CPU_EN | (0007 * 16 + c_timming_b),	// -33

	/* REFRESH */													// -32
	0011 * 16 + c_timming_a,	CPU_EN | (0011 * 16 + c_timming_b),	// -31
	/* SPRITE */				CPU_EN | (0012 * 16 + c_timming_b),	// -30
	0013 * 16 + c_timming_a,	CPU_EN | (0013 * 16 + c_timming_b),	// -29
	0014 * 16 + c_timming_a,	CPU_EN | (0014 * 16 + c_timming_b),	// -28
	0015 * 16 + c_timming_a,	CPU_EN | (0015 * 16 + c_timming_b),	// -27
	0016 * 16 + c_timming_a,	CPU_EN | (0016 * 16 + c_timming_b),	// -26
	0017 * 16 + c_timming_a,	CPU_EN | (0017 * 16 + c_timming_b),	// -25

	0020 * 16 + c_timming_a,	CPU_EN | (0020 * 16 + c_timming_b),	// -24
	0021 * 16 + c_timming_a,	CPU_EN | (0021 * 16 + c_timming_b),	// -23
	/* SPRITE */				CPU_EN | (0022 * 16 + c_timming_b),	// -22
	0023 * 16 + c_timming_a,	CPU_EN | (0023 * 16 + c_timming_b),	// -21
	0024 * 16 + c_timming_a,	CPU_EN | (0024 * 16 + c_timming_b),	// -20
	0025 * 16 + c_timming_a,	CPU_EN | (0025 * 16 + c_timming_b),	// -19
	0026 * 16 + c_timming_a,	CPU_EN | (0026 * 16 + c_timming_b),	// -18
	0027 * 16 + c_timming_a,	CPU_EN | (0027 * 16 + c_timming_b),	// -17

	0030 * 16 + c_timming_a,	CPU_EN | (0030 * 16 + c_timming_b),	// -16
	0031 * 16 + c_timming_a,	CPU_EN | (0031 * 16 + c_timming_b),	// -15
	/* SPRITE */				CPU_EN | (0032 * 16 + c_timming_b),	// -14
	0033 * 16 + c_timming_a,	CPU_EN | (0033 * 16 + c_timming_b),	// -13
	0034 * 16 + c_timming_a,	CPU_EN | (0034 * 16 + c_timming_b),	// -12
	0035 * 16 + c_timming_a,	CPU_EN | (0035 * 16 + c_timming_b),	// -11
	0036 * 16 + c_timming_a,	CPU_EN | (0036 * 16 + c_timming_b),	// -10
	0037 * 16 + c_timming_a,	CPU_EN | (0037 * 16 + c_timming_b),	// -9

	/* NAME */					CPU_EN | (0040 * 16 + c_timming_b),	// -8
	/* PATTERN */				CPU_EN | (0041 * 16 + c_timming_b),	// -7
	/* SPRITE */				CPU_EN | (0042 * 16 + c_timming_b),	// -6
	/* COLOR */					CPU_EN | (0043 * 16 + c_timming_b),	// -5
	0044 * 16 + c_timming_a,	CPU_EN | (0044 * 16 + c_timming_b),	// -4
	0045 * 16 + c_timming_a,	CPU_EN | (0045 * 16 + c_timming_b),	// -3
	0046 * 16 + c_timming_a,	CPU_EN | (0046 * 16 + c_timming_b),	// -2
	0047 * 16 + c_timming_a,	CPU_EN | (0047 * 16 + c_timming_b),	// -1

	/* NAME */					CPU_EN | (0050 * 16 + c_timming_b),	// 0
	/* PATTERN */				CPU_EN | (0051 * 16 + c_timming_b),	// 1
	/* SPRITE */				CPU_EN | (0052 * 16 + c_timming_b),	// 2
	/* COLOR */					CPU_EN | (0053 * 16 + c_timming_b),	// 3
	0054 * 16 + c_timming_a,	CPU_EN | (0054 * 16 + c_timming_b),	// 4
	0055 * 16 + c_timming_a,	CPU_EN | (0055 * 16 + c_timming_b),	// 5
	0056 * 16 + c_timming_a,	CPU_EN | (0056 * 16 + c_timming_b),	// 6
	0057 * 16 + c_timming_a,	CPU_EN | (0057 * 16 + c_timming_b),	// 7

	/* NAME */					CPU_EN | (0060 * 16 + c_timming_b),	// 8
	/* PATTERN */				CPU_EN | (0061 * 16 + c_timming_b),	// 9
	/* SPRITE */				CPU_EN | (0062 * 16 + c_timming_b),	// 10
	/* COLOR */					CPU_EN | (0063 * 16 + c_timming_b),	// 11
	0064 * 16 + c_timming_a,	CPU_EN | (0064 * 16 + c_timming_b),	// 12
	0065 * 16 + c_timming_a,	CPU_EN | (0065 * 16 + c_timming_b),	// 13
	0066 * 16 + c_timming_a,	CPU_EN | (0066 * 16 + c_timming_b),	// 14
	0067 * 16 + c_timming_a,	CPU_EN | (0067 * 16 + c_timming_b),	// 15

	/* NAME */					CPU_EN | (0070 * 16 + c_timming_b),	// 16
	/* PATTERN */				CPU_EN | (0071 * 16 + c_timming_b),	// 17
	/* SPRITE */				CPU_EN | (0072 * 16 + c_timming_b),	// 18
	/* COLOR */					CPU_EN | (0073 * 16 + c_timming_b),	// 19
	0074 * 16 + c_timming_a,	CPU_EN | (0074 * 16 + c_timming_b),	// 20
	0075 * 16 + c_timming_a,	CPU_EN | (0075 * 16 + c_timming_b),	// 21
	0076 * 16 + c_timming_a,	CPU_EN | (0076 * 16 + c_timming_b),	// 22
	0077 * 16 + c_timming_a,	CPU_EN | (0077 * 16 + c_timming_b),	// 23

	/* NAME */					CPU_EN | (0100 * 16 + c_timming_b),	// 24
	/* PATTERN */				CPU_EN | (0101 * 16 + c_timming_b),	// 25
	/* SPRITE */				CPU_EN | (0102 * 16 + c_timming_b),	// 26
	/* COLOR */					CPU_EN | (0103 * 16 + c_timming_b),	// 27
	0104 * 16 + c_timming_a,	CPU_EN | (0104 * 16 + c_timming_b),	// 28
	0105 * 16 + c_timming_a,	CPU_EN | (0105 * 16 + c_timming_b),	// 29
	0106 * 16 + c_timming_a,	CPU_EN | (0106 * 16 + c_timming_b),	// 30
	0107 * 16 + c_timming_a,	CPU_EN | (0107 * 16 + c_timming_b),	// 31

	/* NAME */					CPU_EN | (0110 * 16 + c_timming_b),	// 32
	/* PATTERN */				CPU_EN | (0111 * 16 + c_timming_b),	// 33
	/* SPRITE */				CPU_EN | (0112 * 16 + c_timming_b),	// 34
	/* COLOR */					CPU_EN | (0113 * 16 + c_timming_b),	// 35
	0114 * 16 + c_timming_a,	CPU_EN | (0114 * 16 + c_timming_b),	// 36
	0115 * 16 + c_timming_a,	CPU_EN | (0115 * 16 + c_timming_b),	// 37
	0116 * 16 + c_timming_a,	CPU_EN | (0116 * 16 + c_timming_b),	// 38
	0117 * 16 + c_timming_a,	CPU_EN | (0117 * 16 + c_timming_b),	// 39

	/* NAME */					CPU_EN | (0120 * 16 + c_timming_b),	// 40
	/* PATTERN */				CPU_EN | (0121 * 16 + c_timming_b),	// 41
	/* SPRITE */				CPU_EN | (0122 * 16 + c_timming_b),	// 42
	/* COLOR */					CPU_EN | (0123 * 16 + c_timming_b),	// 43
	0124 * 16 + c_timming_a,	CPU_EN | (0124 * 16 + c_timming_b),	// 44
	0125 * 16 + c_timming_a,	CPU_EN | (0125 * 16 + c_timming_b),	// 45
	0126 * 16 + c_timming_a,	CPU_EN | (0126 * 16 + c_timming_b),	// 46
	0127 * 16 + c_timming_a,	CPU_EN | (0127 * 16 + c_timming_b),	// 47

	/* NAME */					CPU_EN | (0130 * 16 + c_timming_b),	// 48
	/* PATTERN */				CPU_EN | (0131 * 16 + c_timming_b),	// 49
	/* SPRITE */				CPU_EN | (0132 * 16 + c_timming_b),	// 50
	/* COLOR */					CPU_EN | (0133 * 16 + c_timming_b),	// 51
	0134 * 16 + c_timming_a,	CPU_EN | (0134 * 16 + c_timming_b),	// 52
	0135 * 16 + c_timming_a,	CPU_EN | (0135 * 16 + c_timming_b),	// 53
	0136 * 16 + c_timming_a,	CPU_EN | (0136 * 16 + c_timming_b),	// 54
	0137 * 16 + c_timming_a,	CPU_EN | (0137 * 16 + c_timming_b),	// 55

	/* NAME */					CPU_EN | (0140 * 16 + c_timming_b),	// 56
	/* PATTERN */				CPU_EN | (0141 * 16 + c_timming_b),	// 57
	/* SPRITE */				CPU_EN | (0142 * 16 + c_timming_b),	// 58
	/* COLOR */					CPU_EN | (0143 * 16 + c_timming_b),	// 59
	0144 * 16 + c_timming_a,	CPU_EN | (0144 * 16 + c_timming_b),	// 60
	0145 * 16 + c_timming_a,	CPU_EN | (0145 * 16 + c_timming_b),	// 61
	0146 * 16 + c_timming_a,	CPU_EN | (0146 * 16 + c_timming_b),	// 62
	0147 * 16 + c_timming_a,	CPU_EN | (0147 * 16 + c_timming_b),	// 63

	/* NAME */					CPU_EN | (0150 * 16 + c_timming_b),	// 64
	/* PATTERN */				CPU_EN | (0151 * 16 + c_timming_b),	// 65
	/* SPRITE */				CPU_EN | (0152 * 16 + c_timming_b),	// 66
	/* COLOR */					CPU_EN | (0153 * 16 + c_timming_b),	// 67
	0154 * 16 + c_timming_a,	CPU_EN | (0154 * 16 + c_timming_b),	// 68
	0155 * 16 + c_timming_a,	CPU_EN | (0155 * 16 + c_timming_b),	// 69
	0156 * 16 + c_timming_a,	CPU_EN | (0156 * 16 + c_timming_b),	// 70
	0157 * 16 + c_timming_a,	CPU_EN | (0157 * 16 + c_timming_b),	// 71

	/* NAME */					CPU_EN | (0160 * 16 + c_timming_b),	// 72
	/* PATTERN */				CPU_EN | (0161 * 16 + c_timming_b),	// 73
	/* SPRITE */				CPU_EN | (0162 * 16 + c_timming_b),	// 74
	/* COLOR */					CPU_EN | (0163 * 16 + c_timming_b),	// 75
	0164 * 16 + c_timming_a,	CPU_EN | (0164 * 16 + c_timming_b),	// 76
	0165 * 16 + c_timming_a,	CPU_EN | (0165 * 16 + c_timming_b),	// 77
	0166 * 16 + c_timming_a,	CPU_EN | (0166 * 16 + c_timming_b),	// 78
	0167 * 16 + c_timming_a,	CPU_EN | (0167 * 16 + c_timming_b),	// 79

	/* PATTERN */				CPU_EN | (0170 * 16 + c_timming_b),	// 80
	/* PATTERN */				CPU_EN | (0171 * 16 + c_timming_b),	// 81
	/* SPRITE */				CPU_EN | (0172 * 16 + c_timming_b),	// 82
	/* COLOR */					CPU_EN | (0173 * 16 + c_timming_b),	// 83
	0174 * 16 + c_timming_a,	CPU_EN | (0174 * 16 + c_timming_b),	// 84
	0175 * 16 + c_timming_a,	CPU_EN | (0175 * 16 + c_timming_b),	// 85
	0176 * 16 + c_timming_a,	CPU_EN | (0176 * 16 + c_timming_b),	// 86
	0177 * 16 + c_timming_a,	CPU_EN | (0177 * 16 + c_timming_b),	// 87

	/* NAME */					CPU_EN | (0200 * 16 + c_timming_b),	// 88
	/* PATTERN */				CPU_EN | (0201 * 16 + c_timming_b),	// 89
	/* SPRITE */				CPU_EN | (0202 * 16 + c_timming_b),	// 90
	/* COLOR */					CPU_EN | (0203 * 16 + c_timming_b),	// 91
	0204 * 16 + c_timming_a,	CPU_EN | (0204 * 16 + c_timming_b),	// 92
	0205 * 16 + c_timming_a,	CPU_EN | (0205 * 16 + c_timming_b),	// 93
	0206 * 16 + c_timming_a,	CPU_EN | (0206 * 16 + c_timming_b),	// 94
	0207 * 16 + c_timming_a,	CPU_EN | (0207 * 16 + c_timming_b),	// 95

	/* NAME */					CPU_EN | (0210 * 16 + c_timming_b),	// 96
	/* PATTERN */				CPU_EN | (0211 * 16 + c_timming_b),	// 97
	/* SPRITE */				CPU_EN | (0212 * 16 + c_timming_b),	// 98
	/* COLOR */					CPU_EN | (0213 * 16 + c_timming_b),	// 99
	0214 * 16 + c_timming_a,	CPU_EN | (0214 * 16 + c_timming_b),	// 100
	0215 * 16 + c_timming_a,	CPU_EN | (0215 * 16 + c_timming_b),	// 101
	0216 * 16 + c_timming_a,	CPU_EN | (0216 * 16 + c_timming_b),	// 102
	0217 * 16 + c_timming_a,	CPU_EN | (0217 * 16 + c_timming_b),	// 103

	/* NAME */					CPU_EN | (0220 * 16 + c_timming_b),	// 104
	/* PATTERN */				CPU_EN | (0221 * 16 + c_timming_b),	// 105
	/* SPRITE */				CPU_EN | (0222 * 16 + c_timming_b),	// 106
	/* COLOR */					CPU_EN | (0223 * 16 + c_timming_b),	// 107
	0224 * 16 + c_timming_a,	CPU_EN | (0224 * 16 + c_timming_b),	// 108
	0225 * 16 + c_timming_a,	CPU_EN | (0225 * 16 + c_timming_b),	// 109
	0226 * 16 + c_timming_a,	CPU_EN | (0226 * 16 + c_timming_b),	// 110
	0227 * 16 + c_timming_a,	CPU_EN | (0227 * 16 + c_timming_b),	// 111

	/* NAME */					CPU_EN | (0230 * 16 + c_timming_b),	// 112
	/* PATTERN */				CPU_EN | (0231 * 16 + c_timming_b),	// 113
	/* SPRITE */				CPU_EN | (0232 * 16 + c_timming_b),	// 114
	/* COLOR */					CPU_EN | (0233 * 16 + c_timming_b),	// 115
	0234 * 16 + c_timming_a,	CPU_EN | (0234 * 16 + c_timming_b),	// 116
	0235 * 16 + c_timming_a,	CPU_EN | (0235 * 16 + c_timming_b),	// 117
	0236 * 16 + c_timming_a,	CPU_EN | (0236 * 16 + c_timming_b),	// 118
	0237 * 16 + c_timming_a,	CPU_EN | (0237 * 16 + c_timming_b),	// 119

	/* NAME */					CPU_EN | (0240 * 16 + c_timming_b),	// 120
	/* PATTERN */				CPU_EN | (0241 * 16 + c_timming_b),	// 121
	/* SPRITE */				CPU_EN | (0242 * 16 + c_timming_b),	// 122
	/* COLOR */					CPU_EN | (0243 * 16 + c_timming_b),	// 123
	0244 * 16 + c_timming_a,	CPU_EN | (0244 * 16 + c_timming_b),	// 124
	0245 * 16 + c_timming_a,	CPU_EN | (0245 * 16 + c_timming_b),	// 125
	0246 * 16 + c_timming_a,	CPU_EN | (0246 * 16 + c_timming_b),	// 126
	0247 * 16 + c_timming_a,	CPU_EN | (0247 * 16 + c_timming_b),	// 127

	/* NAME */					CPU_EN | (0250 * 16 + c_timming_b),	// 128
	/* PATTERN */				CPU_EN | (0251 * 16 + c_timming_b),	// 129
	/* SPRITE */				CPU_EN | (0252 * 16 + c_timming_b),	// 130
	/* COLOR */					CPU_EN | (0253 * 16 + c_timming_b),	// 131
	0254 * 16 + c_timming_a,	CPU_EN | (0254 * 16 + c_timming_b),	// 132
	0255 * 16 + c_timming_a,	CPU_EN | (0255 * 16 + c_timming_b),	// 133
	0256 * 16 + c_timming_a,	CPU_EN | (0256 * 16 + c_timming_b),	// 134
	0257 * 16 + c_timming_a,	CPU_EN | (0257 * 16 + c_timming_b),	// 135

	/* NAME */					CPU_EN | (0260 * 16 + c_timming_b),	// 136
	/* PATTERN */				CPU_EN | (0261 * 16 + c_timming_b),	// 137
	/* SPRITE */				CPU_EN | (0262 * 16 + c_timming_b),	// 138
	/* COLOR */					CPU_EN | (0263 * 16 + c_timming_b),	// 139
	0264 * 16 + c_timming_a,	CPU_EN | (0264 * 16 + c_timming_b),	// 140
	0265 * 16 + c_timming_a,	CPU_EN | (0265 * 16 + c_timming_b),	// 141
	0266 * 16 + c_timming_a,	CPU_EN | (0266 * 16 + c_timming_b),	// 142
	0267 * 16 + c_timming_a,	CPU_EN | (0267 * 16 + c_timming_b),	// 143

	/* NAME */					CPU_EN | (0270 * 16 + c_timming_b),	// 144
	/* PATTERN */				CPU_EN | (0271 * 16 + c_timming_b),	// 145
	/* SPRITE */				CPU_EN | (0272 * 16 + c_timming_b),	// 146
	/* COLOR */					CPU_EN | (0273 * 16 + c_timming_b),	// 147
	0274 * 16 + c_timming_a,	CPU_EN | (0274 * 16 + c_timming_b),	// 148
	0275 * 16 + c_timming_a,	CPU_EN | (0275 * 16 + c_timming_b),	// 149
	0276 * 16 + c_timming_a,	CPU_EN | (0276 * 16 + c_timming_b),	// 150
	0277 * 16 + c_timming_a,	CPU_EN | (0277 * 16 + c_timming_b),	// 151

	/* NAME */					CPU_EN | (0300 * 16 + c_timming_b),	// 152
	/* PATTERN */				CPU_EN | (0301 * 16 + c_timming_b),	// 153
	/* SPRITE */				CPU_EN | (0302 * 16 + c_timming_b),	// 154
	/* COLOR */					CPU_EN | (0303 * 16 + c_timming_b),	// 155
	0304 * 16 + c_timming_a,	CPU_EN | (0304 * 16 + c_timming_b),	// 156
	0305 * 16 + c_timming_a,	CPU_EN | (0305 * 16 + c_timming_b),	// 157
	0306 * 16 + c_timming_a,	CPU_EN | (0306 * 16 + c_timming_b),	// 158
	0307 * 16 + c_timming_a,	CPU_EN | (0307 * 16 + c_timming_b),	// 159

	/* NAME */					CPU_EN | (0310 * 16 + c_timming_b),	// 160
	/* PATTERN */				CPU_EN | (0311 * 16 + c_timming_b),	// 161
	/* SPRITE */				CPU_EN | (0312 * 16 + c_timming_b),	// 162
	/* COLOR */					CPU_EN | (0313 * 16 + c_timming_b),	// 163
	0314 * 16 + c_timming_a,	CPU_EN | (0314 * 16 + c_timming_b),	// 164
	0315 * 16 + c_timming_a,	CPU_EN | (0315 * 16 + c_timming_b),	// 165
	0316 * 16 + c_timming_a,	CPU_EN | (0316 * 16 + c_timming_b),	// 166
	0317 * 16 + c_timming_a,	CPU_EN | (0317 * 16 + c_timming_b),	// 167

	/* NAME */					CPU_EN | (0320 * 16 + c_timming_b),	// 168
	/* PATTERN */				CPU_EN | (0321 * 16 + c_timming_b),	// 169
	/* SPRITE */				CPU_EN | (0322 * 16 + c_timming_b),	// 170
	/* COLOR */					CPU_EN | (0323 * 16 + c_timming_b),	// 171
	0324 * 16 + c_timming_a,	CPU_EN | (0324 * 16 + c_timming_b),	// 172
	0325 * 16 + c_timming_a,	CPU_EN | (0325 * 16 + c_timming_b),	// 173
	0326 * 16 + c_timming_a,	CPU_EN | (0326 * 16 + c_timming_b),	// 174
	0327 * 16 + c_timming_a,	CPU_EN | (0327 * 16 + c_timming_b),	// 175

	/* NAME */					CPU_EN | (0330 * 16 + c_timming_b),	// 176
	/* PATTERN */				CPU_EN | (0331 * 16 + c_timming_b),	// 177
	/* SPRITE */				CPU_EN | (0332 * 16 + c_timming_b),	// 178
	/* COLOR */					CPU_EN | (0333 * 16 + c_timming_b),	// 179
	0334 * 16 + c_timming_a,	CPU_EN | (0334 * 16 + c_timming_b),	// 180
	0335 * 16 + c_timming_a,	CPU_EN | (0335 * 16 + c_timming_b),	// 181
	0336 * 16 + c_timming_a,	CPU_EN | (0336 * 16 + c_timming_b),	// 182
	0337 * 16 + c_timming_a,	CPU_EN | (0337 * 16 + c_timming_b),	// 183

	/* NAME */					CPU_EN | (0340 * 16 + c_timming_b),	// 184
	/* PATTERN */				CPU_EN | (0341 * 16 + c_timming_b),	// 185
	/* SPRITE */				CPU_EN | (0342 * 16 + c_timming_b),	// 186
	/* COLOR */					CPU_EN | (0343 * 16 + c_timming_b),	// 187
	0344 * 16 + c_timming_a,	CPU_EN | (0344 * 16 + c_timming_b),	// 188
	0345 * 16 + c_timming_a,	CPU_EN | (0345 * 16 + c_timming_b),	// 189
	0346 * 16 + c_timming_a,	CPU_EN | (0346 * 16 + c_timming_b),	// 190
	0347 * 16 + c_timming_a,	CPU_EN | (0347 * 16 + c_timming_b),	// 191

	/* NAME */					CPU_EN | (0350 * 16 + c_timming_b),	// 192
	/* PATTERN */				CPU_EN | (0351 * 16 + c_timming_b),	// 193
	/* SPRITE */				CPU_EN | (0352 * 16 + c_timming_b),	// 194
	/* COLOR */					CPU_EN | (0353 * 16 + c_timming_b),	// 195
	0354 * 16 + c_timming_a,	CPU_EN | (0354 * 16 + c_timming_b),	// 196
	0355 * 16 + c_timming_a,	CPU_EN | (0355 * 16 + c_timming_b),	// 197
	0356 * 16 + c_timming_a,	CPU_EN | (0356 * 16 + c_timming_b),	// 198
	0357 * 16 + c_timming_a,	CPU_EN | (0357 * 16 + c_timming_b),	// 199

	/* NAME */					CPU_EN | (0360 * 16 + c_timming_b),	// 200
	/* PATTERN */				CPU_EN | (0361 * 16 + c_timming_b),	// 201
	/* SPRITE */				CPU_EN | (0362 * 16 + c_timming_b),	// 202
	/* COLOR */					CPU_EN | (0363 * 16 + c_timming_b),	// 203
	0364 * 16 + c_timming_a,	CPU_EN | (0364 * 16 + c_timming_b),	// 204
	0365 * 16 + c_timming_a,	CPU_EN | (0365 * 16 + c_timming_b),	// 205
	0366 * 16 + c_timming_a,	CPU_EN | (0366 * 16 + c_timming_b),	// 206
	0367 * 16 + c_timming_a,	CPU_EN | (0367 * 16 + c_timming_b),	// 207

	/* NAME */					CPU_EN | (0370 * 16 + c_timming_b),	// 208
	/* PATTERN */				CPU_EN | (0371 * 16 + c_timming_b),	// 209
	/* SPRITE */				CPU_EN | (0372 * 16 + c_timming_b),	// 210
	/* COLOR */					CPU_EN | (0373 * 16 + c_timming_b),	// 211
	0374 * 16 + c_timming_a,	CPU_EN | (0374 * 16 + c_timming_b),	// 212
	0375 * 16 + c_timming_a,	CPU_EN | (0375 * 16 + c_timming_b),	// 213
	0376 * 16 + c_timming_a,	CPU_EN | (0376 * 16 + c_timming_b),	// 214
	0377 * 16 + c_timming_a,	CPU_EN | (0377 * 16 + c_timming_b),	// 215

	/* NAME */					CPU_EN | (0400 * 16 + c_timming_b),	// 216
	/* PATTERN */				CPU_EN | (0401 * 16 + c_timming_b),	// 217
	/* SPRITE */				CPU_EN | (0402 * 16 + c_timming_b),	// 218
	/* COLOR */					CPU_EN | (0403 * 16 + c_timming_b),	// 219
	0404 * 16 + c_timming_a,	CPU_EN | (0404 * 16 + c_timming_b),	// 220
	0405 * 16 + c_timming_a,	CPU_EN | (0405 * 16 + c_timming_b),	// 221
	0406 * 16 + c_timming_a,	CPU_EN | (0406 * 16 + c_timming_b),	// 222
	0407 * 16 + c_timming_a,	CPU_EN | (0407 * 16 + c_timming_b),	// 223

	/* NAME */					CPU_EN | (0410 * 16 + c_timming_b),	// 224
	/* PATTERN */				CPU_EN | (0411 * 16 + c_timming_b),	// 225
	/* SPRITE */				CPU_EN | (0412 * 16 + c_timming_b),	// 226
	/* COLOR */					CPU_EN | (0413 * 16 + c_timming_b),	// 227
	0414 * 16 + c_timming_a,	CPU_EN | (0414 * 16 + c_timming_b),	// 228
	0415 * 16 + c_timming_a,	CPU_EN | (0415 * 16 + c_timming_b),	// 229
	0416 * 16 + c_timming_a,	CPU_EN | (0416 * 16 + c_timming_b),	// 230
	0417 * 16 + c_timming_a,	CPU_EN | (0417 * 16 + c_timming_b),	// 231

	/* NAME */					CPU_EN | (0420 * 16 + c_timming_b),	// 232
	/* PATTERN */				CPU_EN | (0421 * 16 + c_timming_b),	// 233
	/* SPRITE */				CPU_EN | (0422 * 16 + c_timming_b),	// 234
	/* COLOR */					CPU_EN | (0423 * 16 + c_timming_b),	// 235
	0424 * 16 + c_timming_a,	CPU_EN | (0424 * 16 + c_timming_b),	// 236
	0425 * 16 + c_timming_a,	CPU_EN | (0425 * 16 + c_timming_b),	// 237
	0426 * 16 + c_timming_a,	CPU_EN | (0426 * 16 + c_timming_b),	// 238
	0427 * 16 + c_timming_a,	CPU_EN | (0427 * 16 + c_timming_b),	// 239

	/* NAME */					CPU_EN | (0430 * 16 + c_timming_b),	// 240
	/* PATTERN */				CPU_EN | (0431 * 16 + c_timming_b),	// 241
	/* SPRITE */				CPU_EN | (0432 * 16 + c_timming_b),	// 242
	/* COLOR */					CPU_EN | (0433 * 16 + c_timming_b),	// 243
	0434 * 16 + c_timming_a,	CPU_EN | (0434 * 16 + c_timming_b),	// 244
	0435 * 16 + c_timming_a,	CPU_EN | (0435 * 16 + c_timming_b),	// 245
	0436 * 16 + c_timming_a,	CPU_EN | (0436 * 16 + c_timming_b),	// 246
	0437 * 16 + c_timming_a,	CPU_EN | (0437 * 16 + c_timming_b),	// 247

	0440 * 16 + c_timming_a,	CPU_EN | (0440 * 16 + c_timming_b),	// 248
	0441 * 16 + c_timming_a,	CPU_EN | (0441 * 16 + c_timming_b),	// 249
	/* SPRITE */				CPU_EN | (0442 * 16 + c_timming_b),	// 250
	0443 * 16 + c_timming_a,	CPU_EN | (0443 * 16 + c_timming_b),	// 251
	0444 * 16 + c_timming_a,	CPU_EN | (0444 * 16 + c_timming_b),	// 252
	0445 * 16 + c_timming_a,	CPU_EN | (0445 * 16 + c_timming_b),	// 253
	0446 * 16 + c_timming_a,	CPU_EN | (0446 * 16 + c_timming_b),	// 254
	0447 * 16 + c_timming_a,	CPU_EN | (0447 * 16 + c_timming_b),	// 255

	0450 * 16 + c_timming_a,	CPU_EN | (0450 * 16 + c_timming_b),	// 256
	0451 * 16 + c_timming_a,	CPU_EN | (0451 * 16 + c_timming_b),	// 257
	/* SPRITE */				CPU_EN | (0452 * 16 + c_timming_b),	// 258
	0453 * 16 + c_timming_a,	CPU_EN | (0453 * 16 + c_timming_b),	// 259
	0454 * 16 + c_timming_a,	CPU_EN | (0454 * 16 + c_timming_b),	// 260
	0455 * 16 + c_timming_a,	CPU_EN | (0455 * 16 + c_timming_b),	// 261
	0456 * 16 + c_timming_a,	CPU_EN | (0456 * 16 + c_timming_b),	// 262
	0457 * 16 + c_timming_a,	CPU_EN | (0457 * 16 + c_timming_b),	// 263

	0460 * 16 + c_timming_a,	CPU_EN | (0460 * 16 + c_timming_b),	// 264
	0461 * 16 + c_timming_a,	CPU_EN | (0461 * 16 + c_timming_b),	// 265
	/* SPRITE */				CPU_EN | (0462 * 16 + c_timming_b),	// 266
	0463 * 16 + c_timming_a,	CPU_EN | (0463 * 16 + c_timming_b),	// 267
	0464 * 16 + c_timming_a,	CPU_EN | (0464 * 16 + c_timming_b),	// 268
	0465 * 16 + c_timming_a,	CPU_EN | (0465 * 16 + c_timming_b),	// 269
	0466 * 16 + c_timming_a,	CPU_EN | (0466 * 16 + c_timming_b),	// 270
	0467 * 16 + c_timming_a,	CPU_EN | (0467 * 16 + c_timming_b),	// 271

	0470 * 16 + c_timming_a,	CPU_EN | (0470 * 16 + c_timming_b),	// 272
	0471 * 16 + c_timming_a,	CPU_EN | (0471 * 16 + c_timming_b),	// 273
	/* SPRITE */				CPU_EN | (0472 * 16 + c_timming_b),	// 274
	0473 * 16 + c_timming_a,	CPU_EN | (0473 * 16 + c_timming_b),	// 275
	0474 * 16 + c_timming_a,	CPU_EN | (0474 * 16 + c_timming_b),	// 276
	0475 * 16 + c_timming_a,	CPU_EN | (0475 * 16 + c_timming_b),	// 277
	0476 * 16 + c_timming_a,	CPU_EN | (0476 * 16 + c_timming_b),	// 278
	0477 * 16 + c_timming_a,	CPU_EN | (0477 * 16 + c_timming_b),	// 279

	0500 * 16 + c_timming_a,	CPU_EN | (0500 * 16 + c_timming_b),	// 280
	0501 * 16 + c_timming_a,	CPU_EN | (0501 * 16 + c_timming_b),	// 281
	/* SPRITE */				CPU_EN | (0502 * 16 + c_timming_b),	// 282
	0503 * 16 + c_timming_a,	CPU_EN | (0503 * 16 + c_timming_b),	// 283
	0504 * 16 + c_timming_a,	CPU_EN | (0504 * 16 + c_timming_b),	// 284
	0505 * 16 + c_timming_a,	CPU_EN | (0505 * 16 + c_timming_b),	// 285
	0506 * 16 + c_timming_a,	CPU_EN | (0506 * 16 + c_timming_b),	// 286
	0507 * 16 + c_timming_a,	CPU_EN | (0507 * 16 + c_timming_b),	// 287

	0510 * 16 + c_timming_a,	CPU_EN | (0510 * 16 + c_timming_b),	// 288
	0511 * 16 + c_timming_a,	CPU_EN | (0511 * 16 + c_timming_b),	// 289
	/* SPRITE */				CPU_EN | (0512 * 16 + c_timming_b),	// 290
	0513 * 16 + c_timming_a,	CPU_EN | (0513 * 16 + c_timming_b),	// 291
	0514 * 16 + c_timming_a,	CPU_EN | (0514 * 16 + c_timming_b),	// 292
	0515 * 16 + c_timming_a,	CPU_EN | (0515 * 16 + c_timming_b),	// 293
	0516 * 16 + c_timming_a,	CPU_EN | (0516 * 16 + c_timming_b),	// 294
	0517 * 16 + c_timming_a,	CPU_EN | (0517 * 16 + c_timming_b),	// 295

	0520 * 16 + c_timming_a,	CPU_EN | (0520 * 16 + c_timming_b),	// 296
	0521 * 16 + c_timming_a,	CPU_EN | (0521 * 16 + c_timming_b),	// 297
	/* SPRITE */				CPU_EN | (0522 * 16 + c_timming_b),	// 298
	0523 * 16 + c_timming_a,	CPU_EN | (0523 * 16 + c_timming_b),	// 299
	0524 * 16 + c_timming_a,	CPU_EN | (0524 * 16 + c_timming_b),	// 300
	0525 * 16 + c_timming_a,	CPU_EN | (0525 * 16 + c_timming_b),	// 301

	0526 * 16 + c_timming_a,	CPU_EN | (0526 * 16 + c_timming_b),	// -40
	0527 * 16 + c_timming_a,	CPU_EN | (0527 * 16 + c_timming_b),	// -39
	/* SPRITE */				CPU_EN | (0530 * 16 + c_timming_b),	// -38
	0531 * 16 + c_timming_a,	CPU_EN | (0531 * 16 + c_timming_b),	// -37
	0532 * 16 + c_timming_a,	CPU_EN | (0532 * 16 + c_timming_b),	// -36
	0533 * 16 + c_timming_a,	CPU_EN | (0533 * 16 + c_timming_b),	// -35
	0534 * 16 + c_timming_a,	CPU_EN | (0534 * 16 + c_timming_b),	// -34
	0535 * 16 + c_timming_a,	CPU_EN | (0535 * 16 + c_timming_b),	// -33

	/* REFRESH */													// -32
	0537 * 16 + c_timming_a,	CPU_EN | (0537 * 16 + c_timming_b)	// -31
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
	constexpr CycleTable(const bool msx1, const bool v9968, const bool cpu, std::span<const int16_t> slots)
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
			if (cpu) {
				while ((slots[p] & SLOT_MASK) * mul < step || (0 == (slots[p] & CPU_EN))) ++p;
			} else {
				while ((slots[p] & SLOT_MASK) * mul < step) ++p;
			}
			for (auto i : xrange(TICKS)) {
				if (cpu) {
					while (((slots[p] & SLOT_MASK) * mul - i) < step || (0 == (slots[p] & CPU_EN))) ++p;
				} else {
					while (((slots[p] & SLOT_MASK) * mul - i) < step) ++p;
				}
				const int16_t slot_val = (slots[p] & SLOT_MASK) * mul;
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
static constexpr CycleTable tabSpritesOn     (false, false, false, slotsSpritesOn);
static constexpr CycleTable tabSpritesOff    (false, false, false, slotsSpritesOff);
static constexpr CycleTable tabChar          (false, false, false, slotsChar);
static constexpr CycleTable tabText          (false, false, false, slotsText);
static constexpr CycleTable tabScreenOff     (false, false, false, slotsScreenOff);
static constexpr CycleTable tabMsx1Gfx12     (true,  false, false, slotsMsx1Gfx12);
static constexpr CycleTable tabMsx1Gfx3      (true,  false, false, slotsMsx1Gfx3);
static constexpr CycleTable tabMsx1Text      (true,  false, false, slotsMsx1Text);
static constexpr CycleTable tabMsx1ScreenOff (true,  false, false, slotsMsx1ScreenOff);
static constexpr ZeroTable  tabBroken;
static constexpr CycleTable tabV9968ScreenOff			(false,  true, false, slotsV9968ScreenOff);
static constexpr CycleTable tabV9968TextLow				(false,  true, false, slotsV9968TextLow);
static constexpr CycleTable tabV9968TextHigh			(false,  true, false, slotsV9968TextHigh);
static constexpr CycleTable tabV9968BmpLowSpritesOff	(false,  true, false, slotsV9968BitmapLowSpritesOff);
static constexpr CycleTable tabV9968BmpLowSpritesOn		(false,  true, false, slotsV9968BitmapLowSpritesOn);
static constexpr CycleTable tabV9968BmpHighSpritesOff	(false,  true, false, slotsV9968BitmapHighSpritesOff);
static constexpr CycleTable tabV9968BmpHighSpritesOn	(false,  true, false, slotsV9968BitmapHighSpritesOn);
static constexpr CycleTable tabV9968PcgSpritesOff		(false,  true, false, slotsV9968PcgSpritesOff);
static constexpr CycleTable tabV9968PcgSpritesOn		(false,  true, false, slotsV9968PcgSpritesOn);
static constexpr CycleTable tabV9968CpuScreenOff			(false,  true, true, slotsV9968ScreenOff);
static constexpr CycleTable tabV9968CpuTextLow				(false,  true, true, slotsV9968TextLow);
static constexpr CycleTable tabV9968CpuTextHigh				(false,  true, true, slotsV9968TextHigh);
static constexpr CycleTable tabV9968CpuBmpLowSpritesOff		(false,  true, true, slotsV9968BitmapLowSpritesOff);
static constexpr CycleTable tabV9968CpuBmpLowSpritesOn		(false,  true, true, slotsV9968BitmapLowSpritesOn);
static constexpr CycleTable tabV9968CpuBmpHighSpritesOff	(false,  true, true, slotsV9968BitmapHighSpritesOff);
static constexpr CycleTable tabV9968CpuBmpHighSpritesOn		(false,  true, true, slotsV9968BitmapHighSpritesOn);
static constexpr CycleTable tabV9968CpuPcgSpritesOff		(false,  true, true, slotsV9968PcgSpritesOff);
static constexpr CycleTable tabV9968CpuPcgSpritesOn			(false,  true, true, slotsV9968PcgSpritesOn);
#else
static  CycleTable tabSpritesOn     (false, false, false, slotsSpritesOn);
static  CycleTable tabSpritesOff    (false, false, false, slotsSpritesOff);
static  CycleTable tabChar          (false, false, false, slotsChar);
static  CycleTable tabText          (false, false, false, slotsText);
static  CycleTable tabScreenOff     (false, false, false, slotsScreenOff);
static  CycleTable tabMsx1Gfx12     (true,  false, false, slotsMsx1Gfx12);
static  CycleTable tabMsx1Gfx3      (true,  false, false, slotsMsx1Gfx3);
static  CycleTable tabMsx1Text      (true,  false, false, slotsMsx1Text);
static  CycleTable tabMsx1ScreenOff (true,  false, false, slotsMsx1ScreenOff);
static  ZeroTable  tabBroken;
static  CycleTable tabV9968ScreenOff			(false,  true, false, slotsV9968ScreenOff);
static  CycleTable tabV9968TextLow				(false,  true, false, slotsV9968TextLow);
static  CycleTable tabV9968TextHigh				(false,  true, false, slotsV9968TextHigh);
static  CycleTable tabV9968BmpLowSpritesOff		(false,  true, false, slotsV9968BitmapLowSpritesOff);
static  CycleTable tabV9968BmpLowSpritesOn		(false,  true, false, slotsV9968BitmapLowSpritesOn);
static  CycleTable tabV9968BmpHighSpritesOff	(false,  true, false, slotsV9968BitmapHighSpritesOff);
static  CycleTable tabV9968BmpHighSpritesOn		(false,  true, false, slotsV9968BitmapHighSpritesOn);
static  CycleTable tabV9968PcgSpritesOff		(false,  true, false, slotsV9968PcgSpritesOff);
static  CycleTable tabV9968PcgSpritesOn			(false,  true, false, slotsV9968PcgSpritesOn);
static  CycleTable tabV9968CpuScreenOff			(false,  true, true, slotsV9968ScreenOff);
static  CycleTable tabV9968CpuTextLow			(false,  true, true, slotsV9968TextLow);
static  CycleTable tabV9968CpuTextHigh			(false,  true, true, slotsV9968TextHigh);
static  CycleTable tabV9968CpuBmpLowSpritesOff	(false,  true, true, slotsV9968BitmapLowSpritesOff);
static  CycleTable tabV9968CpuBmpLowSpritesOn	(false,  true, true, slotsV9968BitmapLowSpritesOn);
static  CycleTable tabV9968CpuBmpHighSpritesOff	(false,  true, true, slotsV9968BitmapHighSpritesOff);
static  CycleTable tabV9968CpuBmpHighSpritesOn	(false,  true, true, slotsV9968BitmapHighSpritesOn);
static  CycleTable tabV9968CpuPcgSpritesOff		(false,  true, true, slotsV9968PcgSpritesOff);
static  CycleTable tabV9968CpuPcgSpritesOn		(false,  true, true, slotsV9968PcgSpritesOn);
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

[[nodiscard]] static inline std::span<const tab_value, NUM_DELTAS * TICKS> getCpuTab(const VDP& vdp)
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
				return tabV9968CpuTextLow;
			case DisplayMode::TEXT2:
				return tabV9968CpuTextHigh;
			case DisplayMode::GRAPHIC1:
			case DisplayMode::GRAPHIC2:
			case DisplayMode::GRAPHIC3:
			case DisplayMode::MULTICOLOR:
				return sprites ? tabV9968CpuPcgSpritesOn : tabV9968CpuPcgSpritesOff;
			case DisplayMode::GRAPHIC6:
			case DisplayMode::GRAPHIC7:
				return sprites ? tabV9968CpuBmpHighSpritesOn : tabV9968CpuBmpHighSpritesOff;
			default:
				return sprites ? tabV9968CpuBmpLowSpritesOn : tabV9968CpuBmpLowSpritesOff;
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

EmuTime getCpuAccessSlot(EmuTime frame_, EmuTime time, const VDP& vdp)
{
	VDP::VDPClock frame(frame_);
	unsigned ticks = frame.getTicksTill_fast(time) % TICKS;
	auto tab = getCpuTab(vdp);
	return time + VDP::VDPClock::duration(tab[ticks]);
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
