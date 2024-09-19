#pragma once

#include "types.h"

//#define kEnemyInit_Torizo_InstrListPtrs ((uint16*)RomFixedPtr(0xaac967))
//#define kTourianEntranceStatue_InstrListPtrs ((uint16*)RomFixedPtr(0xaad810))
//#define kTourianEntranceStatue_SpritePalette2 ((uint16*)RomFixedPtr(0xaad765))
//#define kTourianEntranceStatue_SpritePalette7 ((uint16*)RomFixedPtr(0xaad785))
//#define kShaktool_InstrListPtrs0 ((uint16*)RomFixedPtr(0xaadf13))
//#define kShaktool_InstrListPtrs1 ((uint16*)RomFixedPtr(0xaadf21))
//#define kSine ((uint16*)RomFixedPtr(0xaae0bd))
//#define kCosine ((uint16*)RomFixedPtr(0xaae13d))
//#define kNegativeSine ((uint16*)RomFixedPtr(0xaae1bd))
//#define kNegativeCosine_0 ((uint16*)RomFixedPtr(0xaae23d))
//#define kNegativeCosine ((uint16*)RomFixedPtr(0xaae03d))
//#define kShaktool_InstrListPtrs2 ((uint16*)RomFixedPtr(0xaadd15))
//#define kEnemyInit_Shaktool_PropertiesIndices ((uint16*)RomFixedPtr(0xaade95))
//#define kEnemyInit_Shaktool_RamOffsetIndices ((uint16*)RomFixedPtr(0xaadea3))
//#define kEnemyInit_Shaktool_InitialAnglesIndices ((uint16*)RomFixedPtr(0xaadeb1))
//#define kEnemyInit_Shaktool_FuncPtrs ((uint16*)RomFixedPtr(0xaadedb))
//#define kEnemyInit_Shaktool_ZeroIndices ((uint16*)RomFixedPtr(0xaadef7))
//#define kEnemyInit_Shaktool_LayerControlIndices ((uint16*)RomFixedPtr(0xaadecd))
//#define kShaktool_XDirectionIndices ((uint16*)RomFixedPtr(0xaae630))
//#define kShaktool_SamusXPositionIndices ((uint16*)RomFixedPtr(0xaae670))
//#define kShaktool_SamusYPositionIndices ((uint16*)RomFixedPtr(0xaae6b0))
//#define kN00bTubeCracks_Palette2 ((uint16*)RomFixedPtr(0xaae2dd))
//#define kEnemyInit_ChozoStatue_InstrListPtrs ((uint16*)RomFixedPtr(0xaae7a2))

uint16 kEnemyInit_Torizo_InstrListPtrs[] = {
  0xb879, 0xc9cb,
};

static const uint16 kTourianEntranceStatue_InstrListPtrs[3] = {
  addr_kTourianEntranceStatue_Ilist_BaseDecoration,
  addr_kTourianEntranceStatue_Ilist_Ridley,
  addr_kTourianEntranceStatue_Ilist_Phantoon,
};

static const uint16 kTourianEntranceStatue_SpritePalette2[] = {
  0x3800, 0x57ff, 0x2bff, 0x1f3c,  0x278,  0x1b0,  0x10b,   0x87,   0x44, 0x7fff, 0x7fff, 0x7fff,  0x3ff,  0x252,  0x129,    0x0,
};

static const uint16 kTourianEntranceStatue_SpritePalette7[] = {
  0x3800, 0x27f9, 0x2375, 0x1ad2, 0x164e, 0x11ab,  0xd27,  0x484,    0x0, 0x7f5f, 0x7c1f, 0x5816, 0x300c, 0x5294, 0x39ce, 0x2108,
};

uint16 kShaktool_InstrListPtrs0[] = {
  0xd9fc, 0xda56, 0xda62, 0xda90, 0xda62, 0xda56, 0xda04,
};

uint16 kShaktool_InstrListPtrs1[] = {
  0xd9ea, 0xda2e, 0xda42, 0xda7a, 0xda42, 0xda2e, 0xd9f2,
};

uint16 kSine[] = {
     0x0,   0x4b,   0x96,   0xe1,  0x12d,  0x178,  0x1c2,  0x20d,  0x257,  0x2a1,  0x2ea,  0x333,  0x37b,  0x3c3,  0x40a,  0x451, 
   0x497,  0x4dc,  0x521,  0x565,  0x5a8,  0x5ea,  0x62b,  0x66b,  0x6aa,  0x6e8,  0x725,  0x761,  0x79c,  0x7d6,  0x80f,  0x846, 
   0x87c,  0x8b0,  0x8e4,  0x916,  0x946,  0x975,  0x9a3,  0x9cf,  0x9fa,  0xa23,  0xa4a,  0xa70,  0xa95,  0xab7,  0xad9,  0xaf8, 
   0xb16,  0xb32,  0xb4c,  0xb64,  0xb7b,  0xb90,  0xba3,  0xbb5,  0xbc4,  0xbd2,  0xbde,  0xbe8,  0xbf1,  0xbf7,  0xbfc,  0xbff,
};

uint16 kCosine[] = {
   0xbff,  0xbff,  0xbfc,  0xbf7,  0xbf1,  0xbe8,  0xbde,  0xbd2,  0xbc4,  0xbb5,  0xba3,  0xb90,  0xb7b,  0xb64,  0xb4c,  0xb32, 
   0xb16,  0xaf8,  0xad9,  0xab7,  0xa95,  0xa70,  0xa4a,  0xa23,  0x9fa,  0x9cf,  0x9a3,  0x975,  0x946,  0x916,  0x8e4,  0x8b0, 
   0x87c,  0x846,  0x80f,  0x7d6,  0x79c,  0x761,  0x725,  0x6e8,  0x6aa,  0x66b,  0x62b,  0x5ea,  0x5a8,  0x565,  0x521,  0x4dc, 
   0x497,  0x451,  0x40a,  0x3c3,  0x37b,  0x333,  0x2ea,  0x2a1,  0x257,  0x20d,  0x1c2,  0x178,  0x12d,   0xe1,   0x96,   0x4b,
};

uint16 kNegativeSine[] = {
     0x0, 0xffb5, 0xff6a, 0xff1f, 0xfed3, 0xfe88, 0xfe3e, 0xfdf3, 0xfda9, 0xfd5f, 0xfd16, 0xfccd, 0xfc85, 0xfc3d, 0xfbf6, 0xfbaf, 
  0xfb69, 0xfb24, 0xfadf, 0xfa9b, 0xfa58, 0xfa16, 0xf9d5, 0xf995, 0xf956, 0xf918, 0xf8db, 0xf89f, 0xf864, 0xf82a, 0xf7f1, 0xf7ba, 
  0xf784, 0xf750, 0xf71c, 0xf6ea, 0xf6ba, 0xf68b, 0xf65d, 0xf631, 0xf606, 0xf5dd, 0xf5b6, 0xf590, 0xf56b, 0xf549, 0xf527, 0xf508, 
  0xf4ea, 0xf4ce, 0xf4b4, 0xf49c, 0xf485, 0xf470, 0xf45d, 0xf44b, 0xf43c, 0xf42e, 0xf422, 0xf418, 0xf40f, 0xf409, 0xf404, 0xf401,
};

uint16 kNegativeCosine_0[] = {
  0xf401, 0xf401, 0xf404, 0xf409, 0xf40f, 0xf418, 0xf422, 0xf42e, 0xf43c, 0xf44b, 0xf45d, 0xf470, 0xf485, 0xf49c, 0xf4b4, 0xf4ce, 
  0xf4ea, 0xf508, 0xf527, 0xf549, 0xf56b, 0xf590, 0xf5b6, 0xf5dd, 0xf606, 0xf631, 0xf65d, 0xf68b, 0xf6ba, 0xf6ea, 0xf71c, 0xf750, 
  0xf784, 0xf7ba, 0xf7f1, 0xf82a, 0xf864, 0xf89e, 0xf8da, 0xf918, 0xf956, 0xf995, 0xf9d5, 0xfa16, 0xfa58, 0xfa9b, 0xfadf, 0xfb24, 
  0xfb69, 0xfbaf, 0xfbf6, 0xfc3d, 0xfc85, 0xfccd, 0xfd16, 0xfd5f, 0xfda9, 0xfdf3, 0xfe3e, 0xfe88, 0xfed3, 0xff1e, 0xff6a, 0xffb5,
};

uint16 kNegativeCosine[] = {
  0xf401, 0xf401, 0xf404, 0xf409, 0xf40f, 0xf418, 0xf422, 0xf42e, 0xf43c, 0xf44b, 0xf45d, 0xf470, 0xf485, 0xf49c, 0xf4b4, 0xf4ce, 
  0xf4ea, 0xf508, 0xf527, 0xf549, 0xf56b, 0xf590, 0xf5b6, 0xf5dd, 0xf606, 0xf631, 0xf65d, 0xf68b, 0xf6ba, 0xf6ea, 0xf71c, 0xf750, 
  0xf784, 0xf7ba, 0xf7f1, 0xf82a, 0xf864, 0xf89e, 0xf8da, 0xf918, 0xf956, 0xf995, 0xf9d5, 0xfa16, 0xfa58, 0xfa9b, 0xfadf, 0xfb24, 
  0xfb69, 0xfbaf, 0xfbf6, 0xfc3d, 0xfc85, 0xfccd, 0xfd16, 0xfd5f, 0xfda9, 0xfdf3, 0xfe3e, 0xfe88, 0xfed3, 0xff1e, 0xff6a, 0xffb5,
};

uint16 kShaktool_InstrListPtrs2[] = {
  0xdab4, 0xdabc, 0xdac4, 0xdacc, 0xdad4, 0xdadc, 0xdaa4, 0xdaac,
};

uint16 kEnemyInit_Shaktool_PropertiesIndices[] = {
  (kEnemyProps_ProcessInstructions | kEnemyProps_ProcessedOffscreen),
  (kEnemyProps_ProcessInstructions | kEnemyProps_ProcessedOffscreen | kEnemyProps_Intangible),
  (kEnemyProps_ProcessInstructions | kEnemyProps_ProcessedOffscreen | kEnemyProps_Intangible),
  (kEnemyProps_ProcessInstructions | kEnemyProps_ProcessedOffscreen | kEnemyProps_Intangible),
  (kEnemyProps_ProcessInstructions | kEnemyProps_ProcessedOffscreen | kEnemyProps_Intangible),
  (kEnemyProps_ProcessInstructions | kEnemyProps_ProcessedOffscreen | kEnemyProps_Intangible),
  (kEnemyProps_ProcessInstructions | kEnemyProps_ProcessedOffscreen),
};

uint16 kEnemyInit_Shaktool_RamOffsetIndices[] = {
     0x0,   0x40,   0x80,   0xc0,  0x100,  0x140,  0x180,
};

uint16 kEnemyInit_Shaktool_InitialAnglesIndices[] = {
     0x0, 0xf800, 0xe800, 0xd000, 0xb000, 0x9800, 0x8800,
};

uint16 kEnemyInit_Shaktool_FuncPtrs[] = {
  0xdcab, 0xdcac, 0xdcac, 0xdcd7, 0xdcac, 0xdcac, 0xdd25,
};

uint16 kEnemyInit_Shaktool_ZeroIndices[] = {
      0,     0,     0,     0,     0,     0,     0,
};

uint16 kEnemyInit_Shaktool_LayerControlIndices[] = {
      2,     4,     4,     2,     4,     4,     2,
};

uint16 kShaktool_XDirectionIndices[] = {
     0x0,    0x0,    0x0,    0x0, 0xfe00, 0xfd00, 0xf200, 0xf800, 0xfe00, 0xfd00, 0xf200, 0xf800,    0x0,    0x0,    0x0,    0x0, 
     0x0,    0x0,    0x0,    0x0,  0x200,  0x300,  0xe00,  0x800,  0x200,  0x300,  0xe00,  0x800,    0x0,    0x0,    0x0,    0x0,
};

uint16 kShaktool_SamusXPositionIndices[] = {
  0xffe4, 0xffe2, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 
    0x1c,   0x1e,   0x20,   0x20,   0x20,   0x20,   0x20,   0x20,   0x20,   0x20,   0x20,   0x20,   0x20,   0x20,   0x20,   0x20,
};

uint16 kShaktool_SamusYPositionIndices[] = {
  0xffe0, 0xffe7, 0xffe9, 0xffe9, 0xffe9, 0xffe8, 0xffe7, 0xffe8, 0xffe9, 0xffe8, 0xffe7, 0xffe8, 0xffe9, 0xffe9, 0xffe9, 0xffe9, 
  0xffe0, 0xffe7, 0xffe9, 0xffe9, 0xffe9, 0xffe8, 0xffe7, 0xffe8, 0xffe9, 0xffe8, 0xffe7, 0xffe8, 0xffe9, 0xffe9, 0xffe9, 0xffe9,
};

uint16 kN00bTubeCracks_Palette2[] = {
  0x3800, 0x7f9c, 0x7f17, 0x6e72, 0x59ee, 0x456a, 0x3528, 0x28e6, 0x777f, 0x66fb, 0x5676, 0x45f2, 0x358d, 0x2509, 0x1484,  0x400,
  0x3800, 0x7f9c, 0x7f17, 0x6e72, 0x59ee, 0x456a, 0x3528, 0x28e6, 0x777f, 0x66fb, 0x5676, 0x45f2, 0x358d, 0x2509, 0x1484,  0x400,
};

uint16 kEnemyInit_ChozoStatue_InstrListPtrs[] = {
  0xe457, 0xe39d,
};


