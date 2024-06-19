#pragma once

#include "ida_types.h"
#include "types.h"

//#define kWaver_InstrListPtrs ((uint16*)RomFixedPtr(0xa386db))
//#define kMetalee_InstrListPtrs ((uint16*)RomFixedPtr(0xa3894e))
//#define kFireFlea_Tab0 ((uint16*)RomFixedPtr(0xa38d1d))
//#define kElevator_ControllerInputs ((uint16*)RomFixedPtr(0xa394e2))
//#define kEnemyInit_Crab_InstrListPtrs ((uint16*)RomFixedPtr(0xa396db))
//#define kEnemyInit_Slug_InstrListPtrs ((uint16*)RomFixedPtr(0xa3992b))
//#define kRoach_InstrListPtrs ((uint16*)RomFixedPtr(0xa3a111))
//#define kRoach_FuncPtrs ((uint16*)RomFixedPtr(0xa3a121))
//#define kSidehopper_InstrListPtrs0 ((uint16*)RomFixedPtr(0xa3aac2))
//#define kSidehopper_InstrListPtrs1 ((uint16*)RomFixedPtr(0xa3aaca))
//#define kSidehopper_InstrListPtrs2 ((uint16*)RomFixedPtr(0xa3aad2))
//#define kSidehopper_InstrListPtrs3 ((uint16*)RomFixedPtr(0xa3aada))
//#define kSidehopper_FuncPtrs ((uint16*)RomFixedPtr(0xa3aae2))
//#define kSidehopper_Tab0 ((uint16*)RomFixedPtr(0xa3aae6))
//#define kSidehopper_Tab1 ((uint16*)RomFixedPtr(0xa3aaea))
//#define kSidehopper_Tab2 ((uint16*)RomFixedPtr(0xa3aaee))
//#define kSidehopper_Tab3 ((uint16*)RomFixedPtr(0xa3aaf2))
//#define kSidehopper_Tab4 ((uint16*)RomFixedPtr(0xa3aaf6))
//#define kSidehopper_Tab5 ((uint16*)RomFixedPtr(0xa3aafa))
//#define kMaridiaRefillCandy_XPositionIndices ((uint16*)RomFixedPtr(0xa3b415))
//#define kMaridiaRefillCandy_InstrListPtrs ((uint16*)RomFixedPtr(0xa3b40d))
//#define kEnemyInit_NorfairSlowFireball_InstrListPtrs ((uint16*)RomFixedPtr(0xa3b667))
//#define kEnemyInit_Bang_Tab0 ((uint16*)RomFixedPtr(0xa3ba84))
//#define kBang_ShotDirectionIndices ((uint16*)RomFixedPtr(0xa3ba94))
//#define kBang_ShotSoundIndices ((uint16*)RomFixedPtr(0xa3bc4a))
//#define kEnemyInit_Bang_Tab1 ((uint16*)RomFixedPtr(0xa3bc6a))
//#define kBang_InstrListPtrs ((uint16*)RomFixedPtr(0xa3b722))
//#define kSkree_InstrListPtrs ((uint16*)RomFixedPtr(0xa3c69c))
//#define kMaridiaSnail_Tab0 ((MaridiaSnailData2*)RomFixedPtr(0xa3cd42))
//#define kMaridiaSnail_Tab1 ((uint16*)RomFixedPtr(0xa3cd82))
//#define kMaridiaSnail_Tab2 ((uint16*)RomFixedPtr(0xa3cdc2))
//#define kMaridiaSnail_Tab3 ((uint16*)RomFixedPtr(0xa3cca2))
//#define kMaridiaSnail_FuncPtrs ((uint16*)RomFixedPtr(0xa3cdd2))
//#define kMaridiaSnail_InstrListPtrs0 ((uint16*)RomFixedPtr(0xa3d1ab))
//#define kMaridiaSnail_InstrListPtrs1 ((uint16*)RomFixedPtr(0xa3d30d))
//#define kMaridiaSnail_InstrListPtrs2 ((uint16*)RomFixedPtr(0xa3d50f))
//#define kMaridiaSnail_Tab4 ((uint16*)RomFixedPtr(0xa3d517))
//#define kMaridiaSnail_InstrListPtrs3 ((uint16*)RomFixedPtr(0xa3d5a4))
//#define kReflec_GlowColorsIndices ((uint16*)RomFixedPtr(0xa3dabc))
//#define kReflec_InstrListPtrs0 ((uint16*)RomFixedPtr(0xa3dc0b))
//#define kReflec_ShootDirectionsIndices ((uint16*)RomFixedPtr(0xa3dcae))
//#define kReflec_InstrListPtrs1 ((uint16*)RomFixedPtr(0xa3dca6))
//#define kEnemyInit_WreckedShipOrangeZoomer_InstrListPtrs ((uint16*)RomFixedPtr(0xa3e03b))
//#define kCommonZoomer_SpeedIndices ((uint16*)RomFixedPtr(0xa3e5f0))
//#define kCommonZoomer_InstrListPtrs0 ((uint16*)RomFixedPtr(0xa3e2cc))
//#define kCommonZoomer_InstrListPtrs1 ((uint16*)RomFixedPtr(0xa3e630))
//#define kCommonZoomer_InstrListPtrs2 ((uint16*)RomFixedPtr(0xa3e63c))
//#define kCommonZoomer_InstrListPtrs3 ((uint16*)RomFixedPtr(0xa3e648))
//#define kCommonZoomer_InstrListPtrs4 ((uint16*)RomFixedPtr(0xa3e654))
//#define kCommonZoomer_Tab0 ((uint16*)RomFixedPtr(0xa3e931))
//#define kMetroid_CrySoundsIndices ((uint16*)RomFixedPtr(0xa3ead6))
//#define kMetroid_SpeedIndices ((uint16*)RomFixedPtr(0xa3ea3f))

uint16 kWaver_InstrListPtrs[] = {
  0x86a7, 0x86ad, 0x86b3, 0x86c7,
};

uint16 kMetalee_InstrListPtrs[] = {
  0x8910, 0x8924, 0x8930, 0x8946,
};

uint16 kFireFlea_Tab0[] = {
      8,    16,    24,    32,    40,    48,    56,    64,
};

uint16 kElevator_ControllerInputs[] = {
   kButton_Down,  kButton_Up,
};

uint16 kEnemyInit_Crab_InstrListPtrs[] = {
  0x967b, 0x9693, 0x96ab, 0x96c3,
};

uint16 kEnemyInit_Slug_InstrListPtrs[] = {
  0x984b, 0x988b, 0x98ab, 0x990b, 0x982b, 0x986b, 0x98cb, 0x98eb,
};

uint16 kRoach_InstrListPtrs[] = {
  0xa071, 0xa085, 0xa099, 0xa0ad, 0xa0c1, 0xa0d5, 0xa0e9, 0xa0fd,
};

uint16 kRoach_FuncPtrs[] = {
  0xa301, 0xa30b, 0xa34b, 0xa315, 0xa325, 0xa33b, 0xa380,
};

uint16 kSidehopper_InstrListPtrs0[] = {
  0xaa82, 0xb0d1, 0xb23f, 0xafad,
};

uint16 kSidehopper_InstrListPtrs1[] = {
  0xaaa8, 0xb0f7, 0xb25d, 0xafcb,
};

uint16 kSidehopper_InstrListPtrs2[] = {
  0xaa76, 0xb0c5, 0xb237, 0xafa5,
};

uint16 kSidehopper_InstrListPtrs3[] = {
  0xaa9c, 0xb0eb, 0xb255, 0xafc3,
};

uint16 kSidehopper_FuncPtrs[] = {
  0xabe6, 0xac13,
};

uint16 kSidehopper_Tab0[] = {
      3,     3,
};

uint16 kSidehopper_Tab1[] = {
      3,     3,
};

uint16 kSidehopper_Tab2[] = {
  0x1000, 0x1000,
};

uint16 kSidehopper_Tab3[] = {
      4,     4,
};

uint16 kSidehopper_Tab4[] = {
      3,     3,
};

uint16 kSidehopper_Tab5[] = {
  0x3000, 0x3000,
};

uint16 kMaridiaRefillCandy_XPositionIndices[] = {
     0x0,   0x0,    0x0,0x8000,    0x0,0xa000,    0x2,   0x0,    0x0,   0x0,
};

uint16 kMaridiaRefillCandy_InstrListPtrs[] = {
  0xb3c1, 0xb3d7, 0xb3e7, 0xb3fd,
};

uint16 kEnemyInit_NorfairSlowFireball_InstrListPtrs[] = {
  0xb5e3, 0xb5eb, 0xb5d3, 0xb5db,
};

uint16 kEnemyInit_Bang_Tab0[] = {
   0x2ff,  0x3ff,  0x4ff,  0x5ff,  0x6ff,  0x7ff,  0x8ff,  0x9ff,
};

uint16 kBang_ShotDirectionIndices[] = {
    0xc0,   0xe0,    0x0,   0x20,   0x40,   0x40,   0x60,   0x80,   0xa0,   0xc0,
};

uint16 kBang_ShotSoundIndices[] = {
  kSfx1_ChargedPowerBeam, kSfx1_ChargedWaveBeam, kSfx1_ChargedIceBeam, kSfx1_ChargedIceWaveBeam, kSfx1_ChargedSpazerWaveBeam, kSfx1_ChargedSpazerIceBeam, kSfx1_ChargedSpazerIceWaveBeam, kSfx1_ChargedPlasmaBeamHyperBeam, kSfx1_ChargedPlasmaWaveBeam, kSfx1_ChargedPlasmaIceBeam, kSfx1_ChargedPlasmaIceWaveBeam,
  0, 0, 0, 0, 0,
};

uint16 kEnemyInit_Bang_Tab1[] = {
      3,     1,     4,     1,     5,     2,     6,     2,     7,     2,     8,     3,     9, 
      3,    10,     4,    11,     4,    12,     5,    13,     5,    14,     6,    15,     6,
};

uint16 kBang_InstrListPtrs[] = {
  0xb75e, 0xb772, 0xb790, 0xb7a4, 0xb7c2, 
  0xb7d6, 0xb7f4, 0xb838, 0xb85a, 0xb88a, 
  0xb9fa, 0xb9fa, 0xb9fa, 0xb9fa, 0xb9fa, 
  0xb9fa, 0xb9fa, 0xba00, 0xb9fa, 0xba00, 
  0xb8ac, 0xb8c0, 0xb8de, 0xb8f2, 0xb910, 
  0xb924, 0xb942, 0xb986, 0xb9a8, 0xb9d8,
};

uint16 kSkree_InstrListPtrs[] = {
  0xc65e, 0xc672, 0xc67e, 0xc694,
};

MaridiaSnailData2 kMaridiaSnail_Tab0[] = {
  0xc982,     2, 0xcb9e,     0, 
  0xc9ee,     3, 0xcbec,     1, 
  0xca5a,     2, 0xcbb8,     1, 
  0xc916,     3, 0xcbd2,     0, 
  0xca24,     0, 0xcb50,     1, 
  0xc94c,     1, 0xcb6a,     0, 
  0xc8e0,     0, 0xcb36,     0, 
  0xc9b8,     1, 0xcb84,     1,
};

uint16 kMaridiaSnail_Tab1[] = {
  0xffff,    0x1, 0xffff,    0x1, 
  0xffff,    0x1,    0x0,    0x0, 
     0x0,    0x0, 0xffff,    0x1, 
     0x0,    0x0,    0x0,    0x0, 
  0xffff,    0x1, 0xffff,    0x1, 
     0x0,    0x0, 0xffff,    0x1, 
  0xffff,    0x1,    0x0,    0x0, 
     0x0,    0x0,    0x0,    0x0,
};

uint16 kMaridiaSnail_Tab2[] = {
      1,     0,     3,     2,     5,     4,     7,     6,
};

uint16 kMaridiaSnail_Tab3[] = {
    0x40,   0x80,   0xc0,  0x100,  0x140,  0x180,  0x1c0,  0x200,  0x240,  0x280,  0x2c0,  0x300,  0x340,  0x380,  0x400,  0x440, 
   0x540,  0x580,  0x5c0,  0x600,  0x640,  0x680,  0x6c0,  0x700,  0x740,  0x780,  0x7c0,  0x800,  0x840,  0x880,  0x800,    0x0,
};

uint16 kMaridiaSnail_FuncPtrs[] = {
  0xcfeb, 0xcfe5, 0xcffc, 0xcfb7, 0xcfce, 0xcfbd, 0xcfa6, 0xcfd4,
};

uint16 kMaridiaSnail_InstrListPtrs0[] = {
  0xcc06,0xcb44, 0xcc1e,0xcb92,
};

uint16 kMaridiaSnail_InstrListPtrs1[] = {
  0xcc06,0xcb44, 0xcc1e,0xcb92,
};

uint16 kMaridiaSnail_InstrListPtrs2[] = {
  0xcc06,0xcb44, 0xcc1e,0xcb92,
};

uint16 kMaridiaSnail_Tab4[] = {
     0x0,0xfffd, 0xa000,0xfffd, 0x4000,0xfffd, 
     0x0,0xfffc, 0xa000,0xfffc, 0x4000,0xfffc, 
     0x0,0xfffb, 0xa000,0xfffb, 0x4000,0xfffb, 
     0x0,0xfffa, 0xa000,0xfffa, 0x4000,0xfffa, 
     0x0,0xfff9, 0xa000,0xfff9, 0x4000,0xfff9, 
     0x0,0xfff8,
};

uint16 kMaridiaSnail_InstrListPtrs3[] = {
  0xcc06,0xcb44, 0xcc1e,0xcb92,
};

uint16 kReflec_GlowColorsIndices[] = {
  0x241f, 0x1c17, 0x142f,  0xc47, 
  0x211f, 0x18d8, 0x10b1,  0x86a, 
  0x221f, 0x1999, 0x1113,  0x8ad, 
  0x1eff, 0x163a,  0xd95,  0x4d0, 
  0x1bff, 0x12fb,  0x9f7,   0xf3, 
  0x1bff, 0x12fb,  0x9f7,   0xf3, 
  0x1eff, 0x163a,  0xd95,  0x4d0, 
  0x221f, 0x1999, 0x1113,  0x8ad, 
  0x211f, 0x18d8, 0x10b1,  0x86a, 
  0x241f, 0x1c17, 0x142f,  0xc47,
};

uint16 kReflec_InstrListPtrs0[] = {
  0xdb4c, 0xdb58, 0xdb64, 0xdb6e, 0xdb78, 0xdb82, 0xdb8c, 0xdb96,
};

uint16 kReflec_ShootDirectionsIndices[] = {
  0x8000, 0xfff8,    0x7, 0xfffa, 0x8000, 0x8000, 0xfffd,    0x2, 0xffff, 0x8000,    0x0,    0x0,    0x0,    0x0,    0x0,    0x0, 
  0xfffe, 0x8000, 0xfff7,    0x8, 0xfff9, 0xfff9, 0x8000, 0xfffb,    0x3, 0xfffe,    0x0,    0x0,    0x0,    0x0,    0x0,    0x0, 
     0x4, 0xfffd, 0x8000, 0xffff,    0x0,    0x9, 0xfff8, 0x8000, 0xfffa,    0x5,    0x0,    0x0,    0x0,    0x0,    0x0,    0x0, 
  0xfff9,    0x6, 0xfffc, 0x8000, 0xfffe, 0xfffe,    0x1, 0xfff7, 0x8000, 0xfff9,    0x0,    0x0,    0x0,    0x0,    0x0,    0x0,
};

uint16 kReflec_InstrListPtrs1[] = {
  0xdba0, 0xdbaa, 0xdbb4, 0xdbbe,
};

uint16 kEnemyInit_WreckedShipOrangeZoomer_InstrListPtrs[] = {
  0xdfcb, 0xdfe7, 0xe003, 0xe01f,
};

uint16 kCommonZoomer_SpeedIndices[] = {
    0x40,   0x80,   0xc0,  0x100,  0x140,  0x180,  0x1c0,  0x200,  0x240,  0x280,  0x2c0,  0x300,  0x340,  0x380,  0x400,  0x440, 
   0x540,  0x580,  0x5c0,  0x600,  0x640,  0x680,  0x6c0,  0x700,  0x740,  0x780,  0x7c0,  0x800,  0x840,  0x880,  0x800,    0x0,
};

uint16 kCommonZoomer_InstrListPtrs0[] = {
  0xe25c, 0xe278, 0xe294, 0xe2b0,
};

uint16 kCommonZoomer_InstrListPtrs1[] = {
  0xe294, 0xe294, 0xe294, 0xb5d3, 0x96ab, 0x98ab,
};

uint16 kCommonZoomer_InstrListPtrs2[] = {
  0xe2b0, 0xe2b0, 0xe2b0, 0xb5db, 0x96c3, 0x990b,
};

uint16 kCommonZoomer_InstrListPtrs3[] = {
  0xe25c, 0xe25c, 0xe25c, 0xb5e3, 0x967b, 0x984b,
};

uint16 kCommonZoomer_InstrListPtrs4[] = {
  0xe278, 0xe278, 0xe278, 0xb5eb, 0x9693, 0x988b,
};

uint16 kCommonZoomer_Tab0[] = {
   0x100,    0x0,  0x100,    0x0,  0x100,    0x0,  0x100,    0x0,  0x100,    0x0,  0x100,    0x0,  0x100,    0x0,  0x100,    0x0, 
   0x100,    0x0,  0x100,    0x0,  0x100,    0x0,  0x100,    0x0,  0x100,    0x0,  0x100, 0x1000,   0xb0, 0x1000,   0xb0,    0x0, 
   0x100,    0x0,  0x100, 0x1000,   0xc0,    0x0,  0x100, 0x1000,   0xc0, 0x1000,   0xc0,  0x800,   0xd8,  0x800,   0xd8,  0x600, 
    0xf0,  0x600,   0xf0,  0x600,   0xf0, 0x4000,   0x80, 0x4000,   0x80, 0x6000,   0x50, 0x6000,   0x50, 0x6000,   0x50,
};

uint16 kMetroid_CrySoundsIndices[] = {
  kSfx2_MetroidDrainingSamus_RandomMetroidCry_HighPriority, kSfx2_ShotMochtroid_RandomMetroidCry, kSfx2_ShotMetroid_RandomMetroidCry,
  kSfx2_MetroidDrainingSamus_RandomMetroidCry_HighPriority, kSfx2_ShotMochtroid_RandomMetroidCry, kSfx2_ShotMetroid_RandomMetroidCry,
  kSfx2_ShotMochtroid_RandomMetroidCry, kSfx2_ShotMetroid_RandomMetroidCry,
};

uint16 kMetroid_SpeedIndices[] = {
     0x2,    0x0, 0xfffe,    0x0,
     0x0, 0xfffe,    0x0,    0x2,
};


