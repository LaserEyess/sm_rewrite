#pragma once

//#define kDemoRoomData ((uint16*)RomFixedPtr(0x82876c))

//uint16 kDemoRoomData[] = { 0x8774, 0x87e2, 0x8850, 0x88be, };

//#define kPauseScreenSpriteAnimationData_Timer (*(PauseScreenSpriteAnimationData*)RomFixedPtr(0x82c0b2))
//#define kPauseScreenSpriteAnimationData_Frame (*(PauseScreenSpriteAnimationData*)RomFixedPtr(0x82c0c4))
//#define kPauseScreenSpriteAnimationData_Mode (*(PauseScreenSpriteAnimationData*)RomFixedPtr(0x82c0d6))
//#define kPauseScreenSpriteAnimationData_Data (*(PauseScreenSpriteAnimationData*)RomFixedPtr(0x82c0e8))

PauseScreenSpriteAnimationData kPauseScreenSpriteAnimationData_Timer = {  0x729,  0x72b,  0x72d,  0x72f,  0x731,  0x733,  0x735,  0x737,  0x739, };
PauseScreenSpriteAnimationData kPauseScreenSpriteAnimationData_Frame = {  0x73d,  0x73f,  0x741,  0x743,  0x745,  0x747,  0x749,  0x74b,  0x74d, };
PauseScreenSpriteAnimationData kPauseScreenSpriteAnimationData_Mode = {  0x751,  0x753,  0x755,  0x757,  0x759,  0x75b,  0x75d,  0x75f,  0x761, };
PauseScreenSpriteAnimationData kPauseScreenSpriteAnimationData_Data = { 0xc10a, 0xc10c, 0xc137, 0xc162, 0xc137, 0xc137, 0xc137, 0xc137, 0xc137, };

//#define kPauseSpritePaletteIndexValues ((uint16*)RomFixedPtr(0x82c0fa))

uint16 kPauseSpritePaletteIndexValues[] = { 0x0, 0x200, 0x400, 0x600, 0x800, 0xa00, 0xc00, 0xe00, };

//#define kPausePtsToAnimationSpritemapBaseIds ((uint16*)RomFixedPtr(0x82c1e4))

uint16 kPausePtsToAnimationSpritemapBaseIds[] = { 0xc1f6, 0xc1fc, 0xc202, 0xc20a, 0xc20c, 0xc20e, 0xc210, 0xc212, 0xc214, };

//#define kInitialPalette ((uint16*)RomFixedPtr(0x9a8000))

uint16 kInitialPalette[] = { 0x14e0, 0x7fff, 0x6b5a, 0x6b5a, 0x6b5a, 0x6b5a, 0x6b5a, 0x6b5a, 0x6b5a, 0x6b5a, 0x6b5a, 0x6b5a, 0x6b5a, 0x6b5a, 0x6b5a, 0x6b5a, 
							 0x2003, 0x6f7b, 0x4e12, 0x2884,    0x0, 0x6f7b, 0x209f, 0x2884,    0x0, 0x4e31, 0x354c, 0x2884,    0x0,  0x23f,  0x198,   0x6f, 
							 0x2003, 0x7fff,    0x0, 0x2fef,  0x30d,  0x209,  0x145, 0x5ebb, 0x3db3, 0x292e, 0x1486,  0x3bf,  0x25d,  0x179,   0x99, 0x6b5a, 
							    0x0, 0x7fff,    0x0,  0x31f,  0x1da,   0xf5,   0x67,    0x0,    0x0,    0x0,    0x0,    0x0,    0x0,    0x0,    0x0, 0x6b5a, 
							    0x0, 0x7fff,    0x0, 0x5c17, 0x380e, 0x1c07,  0xc03, 0x26fa,  0xe1a, 0x6b5a, 0x6b5a, 0x6b5a, 0x6b5a, 0x6b5a, 0x6b5a, 0x6b5a, 
							    0x0, 0x7fff,    0x0, 0x7290, 0x4d8b, 0x38e6, 0x1c62, 0x3f33, 0x2e6d, 0x1d8a,  0xd06,  0xed7,  0x1dd, 0x141f, 0x201f, 0x6b5a, 
							    0x0, 0x7fff,    0x0,  0x2a0,  0x940,  0x8e0,  0x860,  0x213,  0x150,   0xa9,   0x22,    0x0,    0x0,    0x0,    0x0, 0x6b5a, 
							    0x0, 0x7fff,    0x0, 0x6b5a, 0x6b5a, 0x6b5a, 0x6b5a, 0x6b5a, 0x6b5a, 0x6b5a, 0x6b5a, 0x6b5a, 0x6b5a, 0x6b5a, 0x6b5a, 0x6b5a, 
							 0x3800,   0xce,   0xbb,  0xc21, 0x3be0, 0x318c, 0x263e, 0x5ad6, 0x4a52, 0x3be0,   0x74,    0xd,  0x173, 0x2108, 0x7e94, 0x7d08, 
							 0x3800,    0x0,    0x0,    0x0,    0x0,    0x0,    0x0,    0x0,    0x0,    0x0,    0x0,    0x0,    0x0,    0x0,    0x0,    0x0, 
							 0x3800,   0xce, 0x421f, 0x1405, 0x3be0, 0x21a8, 0x579f, 0x4ad2, 0x3a4e,   0xbb, 0x5914, 0x30aa,  0x216, 0x1104,   0x74,    0xd, 
							 0x3800,    0x0,    0x0,    0x0,    0x0,    0x0,    0x0,    0x0,    0x0,    0x0,    0x0,    0x0,    0x0,    0x0,    0x0,    0x0, 
							 0x3800,   0xce,  0x33f, 0x1405, 0x3be0, 0x21a8, 0x579f, 0x4ad2, 0x3a4e,   0xbb,  0x21b,  0x10e,  0x216, 0x1104,   0x74,    0xd, 
							 0x3800, 0x7f5a,  0x33b,  0x216,  0x113, 0x7c1d, 0x5814, 0x300a, 0x3be0, 0x2680, 0x1580, 0x5294, 0x39ce, 0x2108, 0x2484, 0x7d08, 
							 0x3800, 0x7f5a, 0x7ec0, 0x6de0, 0x54e0, 0x7f6e, 0x730a, 0x6665, 0x5e22, 0x7fa0, 0x7b60, 0x7720, 0x72a0, 0x6e60, 0x7f91,    0x0, 
							 0x3800,    0x0,    0x0,    0x0,    0x0,    0x0,    0x0,    0x0,    0x0,    0x0,    0x0,    0x0,    0x0,    0x0,    0x0,    0x0, };

//#define kPauseScreenPalettes ((uint16*)RomFixedPtr(0xb6f000))

uint16 kPauseScreenPalettes[] = {    0x0,  0x2df,  0x1d7,   0xac, 0x5ebb, 0x3db3, 0x292e, 0x1486, 0x6318, 0x48fb, 0x7fff,    0x0, 0x6318, 0x44e5, 0x7fff,    0x0, 
								  0x2003,  0xbb1, 0x1ea9,  0x145,    0x0, 0x3db3, 0x292e, 0x1486, 0x6318, 0x5ef7,    0x0,    0x0, 0x6318,  0x2df, 0x7fff,    0x0, 
								  0x2003, 0x48fb, 0x7ff4,   0x1f,    0x0, 0x7fff,  0x156,   0x1f, 0x2413, 0x559d,    0x0,  0x2df, 0x4408, 0x7fff, 0x5ef7, 0x318c, 
								     0x0, 0x44e5, 0x7ff4,   0x1f,    0x0, 0x4a52, 0x318c, 0x5ef7, 0x1ce7, 0x2870, 0x1ce7, 0x4a52, 0x4408, 0x7fff, 0x5ef7, 0x318c, 
								     0x0, 0x272a, 0x559d, 0x1816,    0x0, 0x7fff, 0x4a52, 0x6318, 0x6318, 0x6318, 0x48fb, 0x6318, 0x6318,    0x0, 0x7fff, 0x6318, 
								     0x0, 0x72b2, 0x71c7, 0x4463, 0x6318, 0x6318, 0x6318, 0x6318, 0x6318, 0x6318, 0x2884, 0x6318, 0x7000,    0x0, 0x7fff, 0x6318, 
								     0x0, 0x6318, 0x6318, 0x6318,    0x0, 0x739c,  0x156, 0x6e7a,    0x0,    0x0,    0x0,  0x39e, 0x4408, 0x7fff, 0x5ef7, 0x318c, 
								     0x0, 0x7fff, 0x4a52, 0x318c,    0x0, 0x739c, 0x318c, 0x739c, 0x739c, 0x739c,    0x0, 0x4a52, 0x4408, 0x7fff, 0x6318, 0x6318, 
								  0x3800, 0x7fff, 0x4bff, 0x13ff, 0x129f, 0x111f,  0xcb5,  0x46a,    0x0, 0x3db3, 0x292e, 0x48fb, 0x1849, 0x44e5, 0x7fff,    0x0, 
								  0x3800, 0x7fff, 0x4bff, 0x13ff, 0x129f, 0x111f,  0xcb5,  0x46a,    0x0, 0x1085,  0xc64, 0x1447,  0x823, 0x1442, 0x2108,    0x0, 
								  0x3800, 0x200d,    0xa, 0x2c02, 0x4e73, 0x7fff,  0x39f,   0x1f,    0x0, 0x559d,   0x1d,  0x39f, 0x7fff,    0x0,    0x0,  0x23f, 
								  0x3800, 0x200d,    0xa, 0x2c02, 0x4e73, 0x7fff,  0x39f,   0x1f,    0x0, 0x559d,   0x1d,  0x39f, 0x7fff,    0x0,    0x0,  0x23f, 
								  0x3800,    0x0,    0x0,    0x0,    0x0,    0x0,    0x0,    0x0,    0x0,    0x0,    0x0,    0x0,    0x0,    0x0,    0x0,    0x0, 
								  0x3800,    0x0,    0x0,    0x0,    0x0,    0x0,    0x0,    0x0,    0x0,    0x0,    0x0,    0x0,    0x0,    0x0,    0x0,    0x0, 
								  0x3800,  0xce0,  0x8a0,   0x40, 0x18c5, 0x1062,  0xc41,  0x421,  0xce7,  0x887,   0x27,   0x25,   0x23,    0x1, 0x1ce7,    0x0, 
								  0x3800, 0x2fe0, 0x1a80,  0x120, 0x6b37, 0x4588, 0x2d05, 0x1062, 0x37ff, 0x1e3f,  0x47f,  0x456,   0x4c,   0x23, 0x7fff,    0x0, };

//#define kPauseLrHighlightAnimData ((uint8*)RomFixedPtr(0x82c10c))

uint8 kPauseLrHighlightAnimData[] = { 15,0,0, 3,1,0, 3,2,0, 3,3,0, 3,4,0, 3,5,0, 3,6,0, 3,7,0, 3,6,0, 3,5,0, 3,4,0, 3,3,0, 3,2,0, 3,1,0, 255,};

//#define kPauseAreaLabelTilemap ((uint16*)RomFixedPtr(0x82965f))

uint16 kPauseAreaLabelTilemap[] = { 0x966f, 0x9687, 0x969f, 0x96b7, 0x96cf, 0x96e7, 0x96ff, 0x96e7, };

//#define kPauseMenuMapTilemaps ((LongPtr*)RomFixedPtr(0x82964a))

LongPtr kPauseMenuMapTilemaps[] = { 0x9000, 0xb5, 0x8000, 0xb5, 0xa000, 0xb5, 0xb000, 0xb5, 0xc000, 0xb5, 0xd000, 0xb5, 0xe000, 0xb5, };

//#define kPauseMenuMapData ((uint16*)RomFixedPtr(0x829717))

uint16 kPauseMenuMapData[] = { 0x9727, 0x9827, 0x9927, 0x9a27, 0x9b27, 0x9c27, 0x9d27, 0x9c27, };

//#define kEquipmentTilemaps_Tanks ((uint16*)RomFixedPtr(0x82c088))
//#define kEquipmentTilemaps_Weapons ((uint16*)RomFixedPtr(0x82c08c))
//#define kEquipmentTilemaps_Suits ((uint16*)RomFixedPtr(0x82c096))
//#define kEquipmentTilemaps_Boots ((uint16*)RomFixedPtr(0x82c0a2))
//#define kHyperBeamWeaponsTilemaps ((uint16*)RomFixedPtr(0x82c0a8))

uint16 kEquipmentTilemaps_Tanks[] = { 0xbf06, 0xbf14, };
uint16 kEquipmentTilemaps_Weapons[] = { 0xbf32, 0xbf3c, 0xbf46, 0xbf50, 0xbf5a, 0xbf64 };
uint16 kEquipmentTilemaps_Suits[] = { 0xbf64, 0xbf76, 0xbf88, 0xbf9a, 0xbfac, 0xbfc0, };
uint16 kEquipmentTilemaps_Boots[] = { 0xbfd2, 0xbfe4, 0xbff6, };
uint16 kHyperBeamWeaponsTilemaps[] = { 0xc01a, 0xc01a, 0xc008, 0xc01a, 0xc01a, };

//#define kEquipmentBitmasks_Weapons ((uint16*)RomFixedPtr(0x82c04c))
//#define kEquipmentBitmasks_Suits ((uint16*)RomFixedPtr(0x82c056))
//#define kEquipmentBitmasks_Boots ((uint16*)RomFixedPtr(0x82c062))

uint16 kEquipmentBitmasks_Weapons[] = { 0x1000, 0x2, 0x1, 0x4, 0x8, 0x1 };
uint16 kEquipmentBitmasks_Suits[] = { 0x1, 0x20, 0x4, 0x1000, 0x2, 0x8, };
uint16 kEquipmentBitmasks_Boots[] = { 0x100, 0x200, 0x2000, };

//#define kPauseAnimatedPalette ((uint16*)RomFixedPtr(0x82a987))

uint16 kPauseAnimatedPalette[] = {    0x0, 0x7e7f,  0x15f, 0x7c14, 0x7fff, 0x4e73,    0x0, 0x318c,   0x70, 0x2870, 0x318c,    0x0,    0x0, 0x318c,    0x0, 0x318c, 
								      0x0, 0x6e1c,  0x11b, 0x7412, 0x739c, 0x5294,   0xa6, 0x294d,   0x4e, 0x3092, 0x294b,   0xa6, 0x1084, 0x294a,    0x0, 0x298e, 
								      0x0, 0x61ba,   0xf9, 0x6810, 0x6b5a, 0x56b5,  0x12a, 0x2530,   0x4c, 0x34b4, 0x294b,  0x12a, 0x18c6, 0x2108,    0x0, 0x25b0, 
								      0x0, 0x5577,   0xb6, 0x580c, 0x6318, 0x5ad6,  0x18e, 0x2111,   0x4b, 0x3cf5, 0x252b,  0x18e, 0x294a, 0x1ce7,    0x0, 0x21b1, 
								      0x0, 0x5156,   0x93, 0x500a, 0x6318, 0x6318,  0x212, 0x1cf2,   0x28, 0x3cf6, 0x210b,  0x212, 0x39ce, 0x14a5,    0x0, 0x1dd3, 
								      0x0, 0x44f4,   0x12, 0x4407, 0x5ad6, 0x6739,  0x296, 0x18d5,    0x4, 0x4518, 0x18cb,  0x296, 0x4a52,  0xc63,    0x0, 0x15d6, 
								      0x0, 0x3cd2,   0x70, 0x3805, 0x5294, 0x739c,  0x2fa,  0xc7a,    0x2, 0x495a,  0xc6f,  0x2fa, 0x6318,  0x421,    0x0,  0xdfa, 
								      0x0, 0x200d,    0xa, 0x2c02, 0x4e73, 0x7fff,  0x39f,   0x1f,    0x0, 0x559d,   0x1d,  0x39f, 0x7fff,    0x0,    0x0,  0x23f, 
								      0x0, 0x3cd2,   0x70, 0x3805, 0x5294, 0x739c,  0x2fa,  0xc7a,    0x2, 0x495a,  0xc6f,  0x2fa, 0x6318,  0x421,    0x0,  0xdfa, 
								      0x0, 0x44f4,   0x12, 0x4407, 0x5ad6, 0x6739,  0x296, 0x18d5,    0x4, 0x4518, 0x18cb,  0x296, 0x4a52,  0xc63,    0x0, 0x15d6, 
								      0x0, 0x5156,   0x93, 0x500a, 0x6318, 0x6318,  0x212, 0x1cf2,   0x28, 0x3cf6, 0x210b,  0x212, 0x39ce, 0x14a5,    0x0, 0x1dd3, 
								      0x0, 0x5577,   0xb6, 0x580c, 0x6318, 0x5ad6,  0x18e, 0x2111,   0x4b, 0x3cf5, 0x252b,  0x18e, 0x294a, 0x1ce7,    0x0, 0x21b1, 
								      0x0, 0x61ba,   0xf9, 0x6810, 0x6b5a, 0x56b5,  0x12a, 0x2530,   0x4c, 0x34b4, 0x294b,  0x12a, 0x18c6, 0x2108,    0x0, 0x25b0, 
								      0x0, 0x6e1c,  0x11b, 0x7412, 0x739c, 0x5294,   0xa6, 0x294d,   0x4e, 0x3092, 0x294b,   0xa6, 0x1084, 0x294a,    0x0, 0x298e, };

//#define kPauseReserveTankAnimationData ((uint8*)RomFixedPtr(0x82c165))

uint8 kPauseReserveTankAnimationData[] = { 15,0, 2,1, 2,2, 2,3, 2,4, 2,5, 2,6, 2,7, 2,6, 2,5, 2,4, 2,3, 2,2, 2,1, 255,};

//#define kEquipmentTilemapOffs_Tanks ((uint16*)RomFixedPtr(0x82c068))
//#define kEquipmentTilemapOffs_Weapons ((uint16*)RomFixedPtr(0x82c06c))
//#define kEquipmentTilemapOffs_Suits ((uint16*)RomFixedPtr(0x82c076))
//#define kEquipmentTilemapOffs_Boots ((uint16*)RomFixedPtr(0x82c082))

uint16 kEquipmentTilemapOffs_Tanks[] = { 0x3a88, 0x3ac8, };
uint16 kEquipmentTilemapOffs_Weapons[] = { 0x3c08, 0x3c48, 0x3c88, 0x3cc8, 0x3d08, };
uint16 kEquipmentTilemapOffs_Suits[] = { 0x3a6a, 0x3aaa, 0x3b6a, 0x3baa, 0x3bea, 0x3c2a, };
uint16 kEquipmentTilemapOffs_Boots[] = { 0x3cea, 0x3d2a, 0x3d6a, };

//#define kEquipmentScreenWireframeCmp ((uint16*)RomFixedPtr(0x82b257))
//#define kEquipmentScreenWireframePtrs ((uint16*)RomFixedPtr(0x82b25f))

uint16 kEquipmentScreenWireframeCmp[] = { 0x0, 0x100, 0x1, 0x101, };
uint16 kEquipmentScreenWireframePtrs[] = { 0xd521, 0xd631, 0xd741, 0xd851, };

//#define kEquipmentScreenPtrsToItemXYpos ((uint16*)RomFixedPtr(0x82c18e))

uint16 kEquipmentScreenPtrsToItemXYpos[] = { 0xc196, 0xc19e, 0xc1b2, 0xc1ca, };

//#define kEquipmentPtrsToRamTilemapOffsets ((uint16*)RomFixedPtr(0x82c02c))
//#define kEquipmentPtrsToBitmasks ((uint16*)RomFixedPtr(0x82c034))
//#define kEquipmentPtrsToBitsets ((uint16*)RomFixedPtr(0x82c03c))
//#define kEquipmentPtrsToEquipmentTilemaps ((uint16*)RomFixedPtr(0x82c044))

uint16 kEquipmentPtrsToRamTilemapOffsets[] = { 0xc068, 0xc06c, 0xc076, 0xc082, };
uint16 kEquipmentPtrsToBitmasks[] = { 0x0, 0xc04c, 0xc056, 0xc062, };
uint16 kEquipmentPtrsToBitsets[] = { 0x0, 0x9a6, 0x9a2, 0x9a2, };
uint16 kEquipmentPtrsToEquipmentTilemaps[] = { 0x0, 0xc08c, 0xc096, 0xc0a2, };

//#define kMapIconDataPointers ((MapIconDataPointers*)RomFixedPtr(0x82c7cb))

MapIconDataPointers kMapIconDataPointers_82[] = { 0xc83b, 0xc89d, 0xc90b, 0xc981, 0xc9db,    0x0, 0xca9b,    0x0, 
											      0x0, 0xc8a3,    0x0,    0x0, 0xc9e1,    0x0,    0x0,    0x0, 
											      0x0, 0xc8a9, 0xc913,    0x0, 0xc9e7, 0xca49,    0x0,    0x0, 
											   0xc84d, 0xc8b7, 0xc91d, 0xc98b, 0xc9ed, 0xca4f,    0x0,    0x0, 
											   0xc853, 0xc8bd, 0xc923, 0xc991, 0xc9f3, 0xca51,    0x0,    0x0, 
											   0xc873, 0xc8dd, 0xc943, 0xc9b1, 0xca13, 0xca71,    0x0,    0x0, 
											   0xc893, 0xc8fd, 0xc963, 0xc9d1, 0xca33, 0xca91,    0x0,    0x0, };

//#define kLeftMapScrollArrowData ((MapScrollArrowData*)RomFixedPtr(0x82b9a0))
//#define kRightMapScrollArrowData ((MapScrollArrowData*)RomFixedPtr(0x82b9aa))
//#define kUpMapScrollArrowData ((MapScrollArrowData*)RomFixedPtr(0x82b9b4))
//#define kDownMapScrollArrowData (*(MapScrollArrowData*)RomFixedPtr(0x82b9be))

MapScrollArrowData kLeftMapScrollArrowData = { 16, 120, 9, 512, 1, };
MapScrollArrowData kRightMapScrollArrowData = { 240, 120, 8, 256, 2, };
MapScrollArrowData kUpMapScrollArrowData = { 128, 56, 6, 2048, 3, };
MapScrollArrowData kDownMapScrollArrowData = { 128, 184, 7, 1024, 4, };

//#define file_copy_arrow_stuff ((FileCopyArrowStuff*)RomFixedPtr(0x82bb0c))

FileCopyArrowStuff kFileCopyArrow_Tab0[] = {
  [0] = { .spritemap_idx = 66, .x_pos = 20, .y_pos = 104, },
  [1] = { .spritemap_idx = 64, .x_pos = 20, .y_pos = 88,  },
  [2] = { .spritemap_idx = 64, .x_pos = 20, .y_pos = 120, },
  [3] = { .spritemap_idx = 67, .x_pos = 20, .y_pos = 104, },
  [4] = { .spritemap_idx = 65, .x_pos = 20, .y_pos = 88,  },
  [5] = { .spritemap_idx = 65, .x_pos = 20, .y_pos = 120, },
};

//#define kMapElevatorDests ((uint16*)RomFixedPtr(0x82c74d))

uint16 kMapElevatorDests[] = {
  [kArea_0_Crateria] = 0xc759,
  [kArea_1_Brinstar] = 0xc779,
  [kArea_2_Norfair] = 0xc799,
  [kArea_3_WreckedShip] = 0xc7a1,
  [kArea_4_Maridia] = 0xc7af,
  [kArea_5_Tourian] = 0xc7c3,
};

//#define kStateHeaderTileSets ((uint16*)RomFixedPtr(0x8fe7a7))

//uint16 kStateHeaderTileSets[] = { 0xe6a2, 0xe6ab, 0xe6b4, 0xe6bd, 0xe6c6, 0xe6cf, 0xe6d8, 0xe6e1, 0xe6ea, 
//								  0xe6f3, 0xe6fc, 0xe705, 0xe70e, 0xe717, 0xe720, 0xe729, 0xe732, 0xe73b, 
//								  0xe744, 0xe74d, 0xe756, 0xe75f, 0xe768, 0xe771, 0xe77a, 0xe783, 0xe78c, 
//								  0xe795, 0xe79e, };

TileSet kTileSetTable[] = {
  [kTileSet_0_UpperCrateria]              = { .tile_table_ptr = { .addr = 0xb6f6, .bank = 0xc1 }, .tiles_ptr = { .addr = 0xc629, .bank = 0xba }, .palette_ptr = { .addr = 0xad7c, .bank = 0xc2 }, },
  [kTileSet_1_RedCrateria]                = { .tile_table_ptr = { .addr = 0xb6f6, .bank = 0xc1 }, .tiles_ptr = { .addr = 0xc629, .bank = 0xba }, .palette_ptr = { .addr = 0xae5d, .bank = 0xc2 }, },
  [kTileSet_2_LowerCrateria]              = { .tile_table_ptr = { .addr = 0xbeee, .bank = 0xc1 }, .tiles_ptr = { .addr = 0xf911, .bank = 0xba }, .palette_ptr = { .addr = 0xaf43, .bank = 0xc2 }, },
  [kTileSet_3_OldTourian]                 = { .tile_table_ptr = { .addr = 0xbeee, .bank = 0xc1 }, .tiles_ptr = { .addr = 0xf911, .bank = 0xba }, .palette_ptr = { .addr = 0xb015, .bank = 0xc2 }, },
  [kTileSet_4_WreckedShip_On]             = { .tile_table_ptr = { .addr = 0xc5cf, .bank = 0xc1 }, .tiles_ptr = { .addr = 0xae9e, .bank = 0xbb }, .palette_ptr = { .addr = 0xb0e7, .bank = 0xc2 }, },
  [kTileSet_5_WreckedShip_Off]            = { .tile_table_ptr = { .addr = 0xc5cf, .bank = 0xc1 }, .tiles_ptr = { .addr = 0xae9e, .bank = 0xbb }, .palette_ptr = { .addr = 0xb1a6, .bank = 0xc2 }, },
  [kTileSet_6_GreenBrinstar_BlueBrinstar] = { .tile_table_ptr = { .addr = 0xcfa6, .bank = 0xc1 }, .tiles_ptr = { .addr = 0xe6b0, .bank = 0xbb }, .palette_ptr = { .addr = 0xb264, .bank = 0xc2 }, },
  [kTileSet_7_RedBrinstar_KraidsLair]     = { .tile_table_ptr = { .addr = 0xd8dc, .bank = 0xc1 }, .tiles_ptr = { .addr = 0xa5aa, .bank = 0xbc }, .palette_ptr = { .addr = 0xb35f, .bank = 0xc2 }, },
  [kTileSet_8_PreTourianEntranceCorrdior] = { .tile_table_ptr = { .addr = 0xd8dc, .bank = 0xc1 }, .tiles_ptr = { .addr = 0xa5aa, .bank = 0xbc }, .palette_ptr = { .addr = 0xb447, .bank = 0xc2 }, },
  [kTileSet_9_HeatedNorfair]              = { .tile_table_ptr = { .addr = 0xe361, .bank = 0xc1 }, .tiles_ptr = { .addr = 0xc3f9, .bank = 0xbd }, .palette_ptr = { .addr = 0xb5e4, .bank = 0xc2 }, },
  [kTileSet_10_UnheatedNorfair]           = { .tile_table_ptr = { .addr = 0xe361, .bank = 0xc1 }, .tiles_ptr = { .addr = 0xc3f9, .bank = 0xbd }, .palette_ptr = { .addr = 0xb6bb, .bank = 0xc2 }, },
  [kTileSet_11_SandlessMaridia]           = { .tile_table_ptr = { .addr = 0xf4b1, .bank = 0xc1 }, .tiles_ptr = { .addr = 0xb130, .bank = 0xbe }, .palette_ptr = { .addr = 0xb83c, .bank = 0xc2 }, },
  [kTileSet_12_SandyMaridia]              = { .tile_table_ptr = { .addr = 0x855f, .bank = 0xc2 }, .tiles_ptr = { .addr = 0xe78d, .bank = 0xbe }, .palette_ptr = { .addr = 0xb92e, .bank = 0xc2 }, },
  [kTileSet_13_Tourian]                   = { .tile_table_ptr = { .addr = 0x9b01, .bank = 0xc2 }, .tiles_ptr = { .addr = 0xd414, .bank = 0xbf }, .palette_ptr = { .addr = 0xbaed, .bank = 0xc2 }, },
  [kTileSet_14_MotherBrainsRoom]          = { .tile_table_ptr = { .addr = 0x9b01, .bank = 0xc2 }, .tiles_ptr = { .addr = 0xd414, .bank = 0xbf }, .palette_ptr = { .addr = 0xbbc1, .bank = 0xc2 }, },
  [kTileSet_15_BlueCeres]                 = { .tile_table_ptr = { .addr = 0xa75e, .bank = 0xc2 }, .tiles_ptr = { .addr = 0xb004, .bank = 0xc0 }, .palette_ptr = { .addr = 0xc104, .bank = 0xc2 }, },
  [kTileSet_16_WhiteCeres]                = { .tile_table_ptr = { .addr = 0xa75e, .bank = 0xc2 }, .tiles_ptr = { .addr = 0xb004, .bank = 0xc0 }, .palette_ptr = { .addr = 0xc1e3, .bank = 0xc2 }, },
  [kTileSet_17_BlueCeresElevator]         = { .tile_table_ptr = { .addr = 0xa75e, .bank = 0xc2 }, .tiles_ptr = { .addr = 0xe22a, .bank = 0xc0 }, .palette_ptr = { .addr = 0xc104, .bank = 0xc2 }, },
  [kTileSet_18_WhiteCeresElevator]        = { .tile_table_ptr = { .addr = 0xa75e, .bank = 0xc2 }, .tiles_ptr = { .addr = 0xe22a, .bank = 0xc0 }, .palette_ptr = { .addr = 0xc1e3, .bank = 0xc2 }, },
  [kTileSet_19_BlueCeresRidleysRoom]      = { .tile_table_ptr = { .addr = 0xa75e, .bank = 0xc2 }, .tiles_ptr = { .addr = 0x8da9, .bank = 0xc1 }, .palette_ptr = { .addr = 0xc104, .bank = 0xc2 }, },
  [kTileSet_20_WhiteCeresRidleysRoom]     = { .tile_table_ptr = { .addr = 0xa75e, .bank = 0xc2 }, .tiles_ptr = { .addr = 0x8da9, .bank = 0xc1 }, .palette_ptr = { .addr = 0xc1e3, .bank = 0xc2 }, },
  [kTileSet_21_MapRoom_TourianEntrance]   = { .tile_table_ptr = { .addr = 0xa27b, .bank = 0xc2 }, .tiles_ptr = { .addr = 0x860b, .bank = 0xc0 }, .palette_ptr = { .addr = 0xbc9c, .bank = 0xc2 }, },
  [kTileSet_22_WreckedShipMapRoom_Off]    = { .tile_table_ptr = { .addr = 0xa27b, .bank = 0xc2 }, .tiles_ptr = { .addr = 0x860b, .bank = 0xc0 }, .palette_ptr = { .addr = 0xbd7b, .bank = 0xc2 }, },
  [kTileSet_23_BlueRefillRoom]            = { .tile_table_ptr = { .addr = 0xa27b, .bank = 0xc2 }, .tiles_ptr = { .addr = 0x860b, .bank = 0xc0 }, .palette_ptr = { .addr = 0xbe58, .bank = 0xc2 }, },
  [kTileSet_24_YellowRefillRoom]          = { .tile_table_ptr = { .addr = 0xa27b, .bank = 0xc2 }, .tiles_ptr = { .addr = 0x860b, .bank = 0xc0 }, .palette_ptr = { .addr = 0xbf3d, .bank = 0xc2 }, },
  [kTileSet_25_SaveRoom]                  = { .tile_table_ptr = { .addr = 0xa27b, .bank = 0xc2 }, .tiles_ptr = { .addr = 0x860b, .bank = 0xc0 }, .palette_ptr = { .addr = 0xc021, .bank = 0xc2 }, },
  [kTileSet_26_KraidsRoom]                = { .tile_table_ptr = { .addr = 0xe189, .bank = 0xc1 }, .tiles_ptr = { .addr = 0xdff0, .bank = 0xbc }, .palette_ptr = { .addr = 0xb510, .bank = 0xc2 }, },
  [kTileSet_27_CrocomiresRoom]            = { .tile_table_ptr = { .addr = 0xf3af, .bank = 0xc1 }, .tiles_ptr = { .addr = 0xfe2a, .bank = 0xbd }, .palette_ptr = { .addr = 0xb798, .bank = 0xc2 }, },
  [kTileSet_28_DraygonsRoom]              = { .tile_table_ptr = { .addr = 0x960d, .bank = 0xc2 }, .tiles_ptr = { .addr = 0x9dea, .bank = 0xbf }, .palette_ptr = { .addr = 0xba2c, .bank = 0xc2 }, },
};

//#define kCommonSpritesPalette1 ((uint16*)RomFixedPtr(0x9afc00))

uint16 kCommonSpritesPalette1[] = {    0x0, 0x7fff, 0x77bd, 0x6b5a, 
									0x6318, 0x7fff, 0x77bd, 0x6b5a, 
									0x6318, 0x7fff, 0x77bd, 0x6b5a, 
									0x6318, 0x7fff, 0x77bd, 0x6b5a, };

//#define kMenuPalettes ((uint16*)RomFixedPtr(0x8ee400))

uint16 kMenuPalettes_82[] = {    0x0, 0x7fff, 0x4bff, 0x13ff, 0x129f, 0x111f,  0xcb5,  0x46a,    0x0, 0x3db3, 0x292e, 0x48fb, 0x1849, 0x44e5, 0x7fff,    0x0, 
						      0x0, 0x7fff, 0x4bff, 0x13ff, 0x129f, 0x111f,  0xcb5,  0x46a,    0x0, 0x1085,  0xc64, 0x1447,  0x823, 0x1442, 0x2108,    0x0, 
						      0x0, 0x48fb, 0x7ff4,   0x1f,    0x0, 0x7fff,  0x156,   0x1f, 0x2413, 0x559d,    0x0,  0x2df, 0x4408, 0x7fff, 0x5ef7, 0x318c, 
						      0x0, 0x44e5, 0x7ff4,   0x1f,    0x0, 0x4a52, 0x318c, 0x5ef7, 0x1ce7, 0x2870, 0x1ce7, 0x4a52, 0x4408, 0x7fff, 0x5ef7, 0x318c, 
						      0x0, 0x373f, 0x2e9e, 0x2e3b, 0x25d8, 0x1d33, 0x14ae, 0x144a,  0x803, 0x7dff, 0x6819, 0x5413, 0x340a, 0x2004, 0x1403,    0x0, 
						      0x0, 0x7fe0, 0x7ea0, 0x7d40, 0x7c00, 0x4000,  0x1db,  0x196,  0x150,   0xeb,   0xa5,  0x33b,  0x296,  0x1f0,  0x14b,   0xa5, 
						    0x400, 0x6400, 0x4c00, 0x3400, 0x1c00,  0x400,   0x13,    0xf,    0xa,    0x6,    0x1,  0xbb1,  0xb0d,  0x669,  0x5a4,  0x100, 
						      0x0, 0x7fe0, 0x7ea0, 0x7d40, 0x7c00, 0x4000, 0x6417, 0x4c12, 0x380d, 0x2007,  0x802, 0x5280, 0x4620, 0x39c0, 0x2940, 0x14a5, 
						   0x7fff, 0x7fff, 0x4bff, 0x13ff, 0x129f, 0x111f,  0xcb5,  0x46a,    0x0, 0x3db3, 0x292e, 0x48fb, 0x1849, 0x44e5, 0x7fff,    0x0, 
						   0x3800, 0x7fff, 0x4bff, 0x13ff, 0x129f, 0x111f,  0xcb5,  0x46a,    0x0, 0x1085,  0xc64, 0x1447,  0x823, 0x1442, 0x2108,    0x0, 
						   0x3800, 0x200d,    0xa, 0x2c02, 0x4e73, 0x7fff,  0x39f,   0x1f,    0x0, 0x559d,   0x1d,  0x39f, 0x7fff,    0x0,    0x0,  0x23f, 
						      0x0, 0x200d,    0xa, 0x2c02, 0x4e73, 0x7fff,  0x39f,   0x1f,    0x0, 0x559d,   0x1d,  0x39f, 0x7fff,    0x0,    0x0,  0x23f, 
						   0x3800, 0x6bf5,  0x6e1,  0x641,  0x5a1, 0x5e5f, 0x183f, 0x1014,  0x80a,  0x404, 0x4f9f, 0x3ed8, 0x2e12, 0x6f70, 0x7fff, 0x5ee0, 
						   0x3800, 0x7e20, 0x6560, 0x2060, 0x1000, 0x7940, 0x5d00, 0x4ca0, 0x3ca0, 0x43ff,  0x113,    0xf, 0x175c,  0x299,  0x1d6, 0x57e0, 
						   0x3800,  0xce0,  0x8a0,   0x40, 0x18c5, 0x1062,  0xc41,  0x421,  0xce7,  0x887,   0x27,   0x25,   0x23,    0x1, 0x1ce7,    0x0, 
						   0x3800, 0x2fe0, 0x1a80,  0x120, 0x6b37, 0x4588, 0x2d05, 0x1062, 0x37ff, 0x1e3f,  0x47f,  0x456,   0x4c,   0x23, 0x7fff,    0x0, };

//#define kOptionsMenuSpecialPtrs ((uint16*)RomFixedPtr(0x82f0ae))

uint16 kOptionsMenuSpecialPtrs[] = { 0x9ea, 0x9e4, };

//#define kMenuMissilePtrsToStartPos ((uint16*)RomFixedPtr(0x82f2ed))

uint16 kMenuMissilePtrsToStartPos[] = { 0x0, 0x0, 0xf307, 0xf307, 0x0, 0x0, 0x0, 0xf31b, 0xf33f, 0x0, 0x0, 0xf307, 0x0, };

//#define kControllerBindingRAMAddresses ((uint16*)RomFixedPtr(0x82f54a))

uint16 kControllerBindingRAMAddresses[] = { 0x9b2, 0x9b4, 0x9b6, 0x9ba, 0x9b8, 0x9be, 0x9bc, };

//#define kOptionsMenuPtrsToTilemapOffsets ((uint16*)RomFixedPtr(0x82f639))
//#define kOptionsMenuPtrsToButtonTilemaps ((uint16*)RomFixedPtr(0x82f647))

uint16 kOptionsMenuPtrsToTilemapOffsets[] = { 0x16e, 0x22e, 0x2ee, 0x3ae, 0x46e, 0x52e, 0x5ee, };
uint16 kOptionsMenuPtrsToButtonTilemaps[] = { 0xf659, 0xf665, 0xf671, 0xf67d, 0xf689, 0xf695, 0xf6a1, 0xf6ad, 0xf6ad, };

DemoRoomData kDemoRoomData[4][7] = {
  [0] = {
    [0] = { .room_ptr_ = 0x91f8, .door_ptr = 0x896a, .door_slot = 1, .screen_x_pos =  0x400, .screen_y_pos =  0x400, .samus_y_offs =   0x40, .samus_x_offs =    0x1, .demo_length = 1235, .demo_code_ptr = 0x8925 },
    [1] = { .room_ptr_ = 0x9f11, .door_ptr = 0x8eaa, .door_slot = 1, .screen_x_pos =    0x0, .screen_y_pos =    0x0, .samus_y_offs =   0x6b, .samus_x_offs = 0xffd2, .demo_length =  337, .demo_code_ptr = 0x8924 },
    [2] = { .room_ptr_ = 0x9d9c, .door_ptr = 0x8dc6, .door_slot = 0, .screen_x_pos =  0x100, .screen_y_pos =    0x0, .samus_y_offs =   0xbb, .samus_x_offs = 0xffe0, .demo_length =  378, .demo_code_ptr = 0x8924 },
    [3] = { .room_ptr_ = 0xb106, .door_ptr = 0x970e, .door_slot = 0, .screen_x_pos =  0x700, .screen_y_pos =    0x0, .samus_y_offs =   0x8b, .samus_x_offs =   0x48, .demo_length =  420, .demo_code_ptr = 0x8924 },
    [4] = { .room_ptr_ = 0xaffb, .door_ptr = 0x9792, .door_slot = 1, .screen_x_pos =    0x0, .screen_y_pos =    0x0, .samus_y_offs =   0x8b, .samus_x_offs = 0xffc2, .demo_length =  444, .demo_code_ptr = 0x8924 },
    [5] = { .room_ptr_ = 0x9d19, .door_ptr = 0x8e7a, .door_slot = 0, .screen_x_pos =  0x200, .screen_y_pos =  0x600, .samus_y_offs =   0x99, .samus_x_offs =   0x27, .demo_length =  613, .demo_code_ptr = 0x891a },
    [6] = { 0xffff },
  },
  [1] = {
    [0] = { .room_ptr_ = 0xa408, .door_ptr = 0xa36c, .door_slot = 0, .screen_x_pos =  0x100, .screen_y_pos =  0x100, .samus_y_offs =   0x8b, .samus_x_offs =   0x56, .demo_length =  509, .demo_code_ptr = 0x8924 },
    [1] = { .room_ptr_ = 0x9c5e, .door_ptr = 0x8cca, .door_slot = 3, .screen_x_pos =  0x200, .screen_y_pos =    0x0, .samus_y_offs =   0x8b, .samus_x_offs =   0x49, .demo_length =  410, .demo_code_ptr = 0x8924 },
    [2] = { .room_ptr_ = 0x9e52, .door_ptr = 0x8dea, .door_slot = 3, .screen_x_pos =  0x500, .screen_y_pos =  0x300, .samus_y_offs =   0xab, .samus_x_offs = 0xffe2, .demo_length =  279, .demo_code_ptr = 0x8924 },
    [3] = { .room_ptr_ = 0xaf14, .door_ptr = 0x967e, .door_slot = 2, .screen_x_pos =  0x300, .screen_y_pos =    0x0, .samus_y_offs =   0x8b, .samus_x_offs =   0x4b, .demo_length =  970, .demo_code_ptr = 0x8924 },
    [4] = { .room_ptr_ = 0x9879, .door_ptr = 0x8982, .door_slot = 3, .screen_x_pos =    0x0, .screen_y_pos =    0x0, .samus_y_offs =   0xbb, .samus_x_offs = 0xfff1, .demo_length =  213, .demo_code_ptr = 0x8924 },
    [5] = { .room_ptr_ = 0x9cb3, .door_ptr = 0x8dd2, .door_slot = 1, .screen_x_pos =  0x400, .screen_y_pos =  0x200, .samus_y_offs =   0x80, .samus_x_offs =    0x5, .demo_length =  791, .demo_code_ptr = 0x8924 },
    [6] = { 0xffff },
  },
  [2] = {
    [0] = { .room_ptr_ = 0xcc6f, .door_ptr = 0xa21c, .door_slot = 3, .screen_x_pos =  0x200, .screen_y_pos =    0x0, .samus_y_offs =   0x60, .samus_x_offs =    0x4, .demo_length =  751, .demo_code_ptr = 0x8924 },
    [1] = { .room_ptr_ = 0x91f8, .door_ptr = 0x896a, .door_slot = 1, .screen_x_pos =  0x300, .screen_y_pos =  0x400, .samus_y_offs =   0xb0, .samus_x_offs =    0x0, .demo_length =  199, .demo_code_ptr = 0x8925 },
    [2] = { .room_ptr_ = 0xa56b, .door_ptr = 0x919e, .door_slot = 1, .screen_x_pos =    0x0, .screen_y_pos =  0x100, .samus_y_offs =   0x8b, .samus_x_offs = 0xffd2, .demo_length =  723, .demo_code_ptr = 0x8924 },
    [3] = { .room_ptr_ = 0xa322, .door_ptr = 0x90ea, .door_slot = 0, .screen_x_pos =    0x0, .screen_y_pos =  0x700, .samus_y_offs =   0x8b, .samus_x_offs = 0xffaa, .demo_length =  356, .demo_code_ptr = 0x8924 },
    [4] = { .room_ptr_ = 0xa59f, .door_ptr = 0x91b6, .door_slot = 1, .screen_x_pos =    0x0, .screen_y_pos =  0x100, .samus_y_offs =   0x8b, .samus_x_offs = 0xffbf, .demo_length =  319, .demo_code_ptr = 0x892b },
    [5] = { .room_ptr_ = 0xa66a, .door_ptr = 0x91f2, .door_slot = 1, .screen_x_pos =    0x0, .screen_y_pos =    0x0, .samus_y_offs =   0x8b, .samus_x_offs = 0xffb1, .demo_length =  407, .demo_code_ptr = 0x8932 },
    [6] = { 0xffff },
  },
  [3] = {
    [0] = { .room_ptr_ = 0x91f8, .door_ptr = 0x890a, .door_slot = 0, .screen_x_pos =  0x600, .screen_y_pos =  0x200, .samus_y_offs =   0x80, .samus_x_offs =   0x30, .demo_length =  256, .demo_code_ptr = 0x8925 },
    [1] = { .room_ptr_ = 0xd0b9, .door_ptr = 0xa474, .door_slot = 0, .screen_x_pos =  0x200, .screen_y_pos =    0x0, .samus_y_offs =   0xab, .samus_x_offs =    0x0, .demo_length =  818, .demo_code_ptr = 0x8924 },
    [2] = { .room_ptr_ = 0x91f8, .door_ptr = 0x890a, .door_slot = 0, .screen_x_pos =  0x600, .screen_y_pos =  0x200, .samus_y_offs =   0x7b, .samus_x_offs =   0x20, .demo_length =  389, .demo_code_ptr = 0x8925 },
    [3] = { .room_ptr_ = 0x9ad9, .door_ptr = 0x8d42, .door_slot = 1, .screen_x_pos =    0x0, .screen_y_pos =  0x400, .samus_y_offs =   0x8b, .samus_x_offs = 0xffb7, .demo_length =  394, .demo_code_ptr = 0x8924 },
    [4] = { .room_ptr_ = 0x91f8, .door_ptr = 0x890a, .door_slot = 0, .screen_x_pos =  0x600, .screen_y_pos =  0x200, .samus_y_offs =   0x8b, .samus_x_offs =    0x4, .demo_length =  512, .demo_code_ptr = 0x8925 },
    [5] = { 0xffff },
  },
};
