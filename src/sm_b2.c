// $B2 - Enemy AI - space pirates
#include "ida_types.h"
#include "variables.h"
#include "funcs.h"
#include "enemy_types.h"
#include "sm_b2.h"





void Enemy_GrappleReact_CancelBeam_B2(void) {  // 0xB2800F
  Enemy_SwitchToFrozenAi();
}

void Enemy_NormalFrozenAI_B2(void) {  // 0xB28041
  NormalEnemyFrozenAI();
}

void WalkingSpacePirates_Powerbomb(void) {  // 0xB28767
  NormalEnemyPowerBombAi();
}

void WalkingSpacePirates_Touch(void) {  // 0xB2876C
  if (!Get_SpacePirates(cur_enemy_index)->base.frozen_timer)
    NormalEnemyTouchAi();
}

void WalkingSpacePirates_Shot(void) {  // 0xB28779
  if (Get_SpacePirates(cur_enemy_index)->base.enemy_ptr == addr_kEnemyDef_ItemDrop_GoldNinjaSpacePirateDropChances)
    WalkingSpacePirates_8789();
  else
    NormalEnemyShotAi();
}

void WalkingSpacePirates_8789(void) {  // 0xB28789
  Enemy_SpacePirates *E = Get_SpacePirates(cur_enemy_index);
  special_death_item_drop_x_origin_pos = E->base.x_pos;
  special_death_item_drop_y_origin_pos = E->base.y_pos;
  NormalEnemyShotAiSkipDeathAnim_CurEnemy();
  if (!E->base.health) {
    uint16 v1 = cur_enemy_index;
    if (E->base.enemy_ptr == addr_kEnemyDef_ItemDrop_GoldNinjaSpacePirateDropChances) {
      E->sps_var_B = 0;
      EnemyDeathAnimation(v1, 4);
      Enemy_ItemDrop_LowerNorfairSpacePirate(v1);
    } else {
      E->sps_var_B = 0;
      EnemyDeathAnimation(v1, 4);
    }
  }
}

void WalkingSpacePirates_87C8(void) {  // 0xB287C8
  Vulnerability *v2;
  int16 v3;
  Vulnerability *v;

  if (Get_SpacePirates(cur_enemy_index)->base.enemy_ptr != addr_kEnemyDef_ItemDrop_GoldNinjaSpacePirateDropChances)
    goto LABEL_2;
  uint16 r18 = projectile_type[collision_detection_index];
  if (sign16((r18 & kProjectileType_TypeMask) - kProjectileType_PowerBomb)) {
    uint16 enemy_ptr;
    uint16 vulnerability_ptr;
    enemy_ptr = Get_SpacePirates(cur_enemy_index)->base.enemy_ptr;
    vulnerability_ptr = get_EnemyDef_A2(enemy_ptr)->vulnerability_ptr;
    if (!vulnerability_ptr)
      vulnerability_ptr = addr_kEnemyVulnerability;
    uint16 r20 = vulnerability_ptr;
    if ((r18 & kProjectileType_TypeMask) != 0) {
      if ((r18 & kProjectileType_TypeMask) != kProjectileType_Missile && (r18 & kProjectileType_TypeMask) != kProjectileType_SuperMissile)
        goto LABEL_2;
      v3 = (uint16)(r18 & kProjectileType_TypeMask) >> 8;
      v = get_Vulnerability(r20 + v3);
      if ((v->plasma_ice_wave & 0xF) != 0 && (v->plasma_ice_wave & 0xF) != 15)
        goto LABEL_2;
    } else {
      v2 = get_Vulnerability(r20 + (r18 & 0xF));
      if ((v2->power & 0xF) != 0 && (v2->power & 0xF) != 15) {
LABEL_2:
        WalkingSpacePirates_8789();
        return;
      }
    }
    WalkingSpacePirates_883E();
  }
}

void WalkingSpacePirates_883E(void) {  // 0xB2883E
  if (Get_SpacePirates(cur_enemy_index)->base.enemy_ptr != addr_kEnemyDef_ItemDrop_GoldNinjaSpacePirateDropChances) {
    WalkingSpacePirates_8789();
    return;
  }
  uint16 v0 = 2 * collision_detection_index;
  int v1 = collision_detection_index;
  uint16 r18 = projectile_type[v1];
  if ((r18 & kProjectileType_TypeMask) == kProjectileType_SuperMissile) {
    if (!projectile_variables[v1])
      return;
  } else if (!sign16((r18 & kProjectileType_TypeMask) - kProjectileType_PowerBomb)) {
    return;
  }
  Get_SpacePirates(cur_enemy_index)->base.invincibility_timer = 10;
  uint16 v2;
  if ((projectile_dir[v1] & 0xF) == 7) {
    v2 = 1;
  } else if ((projectile_dir[v1] & 0xF) == 2) {
    v2 = 8;
  } else {
    v2 = 5;
  }
  projectile_dir[v1] = v2;
  ProjectileReflection(v0);
  QueueSfx2_Max6(kSfx2_ShotKiHunter_WalkingSpacePirate);
}

const uint16 *SpacePirates_Instr_MovePixelsDownAndChangeDirFaceRight(uint16 k, const uint16 *jp) {  // 0xB2EE40
  if (!(Enemy_MoveDown(cur_enemy_index, INT16_SHL16(jp[0]))))
    return jp + 1;
  Enemy_SpacePirates *E = Get_SpacePirates(cur_enemy_index);
  E->sps_var_C ^= 1;
  if (E->sps_var_C)
    return INSTR_RETURN_ADDR(addr_off_B2ECEC);
  return INSTR_RETURN_ADDR(addr_kSpacePirates_Ilist_ED36);
}

const uint16 *SpacePirates_Instr_MovePixelsDownAndChangeDirFaceLeft(uint16 k, const uint16 *jp) {  // 0xB2EE72
  if (!(Enemy_MoveDown(cur_enemy_index, INT16_SHL16(jp[0]))))
    return jp + 1;
  Enemy_SpacePirates *E = Get_SpacePirates(cur_enemy_index);
  E->sps_var_C ^= 1;
  if (E->sps_var_C)
    return INSTR_RETURN_ADDR(addr_kSpacePirates_Ilist_EDF6);
  return INSTR_RETURN_ADDR(addr_off_B2EDAC);
}

const uint16 *SpacePirates_Instr_RandomNewDirFaceR(uint16 k, const uint16 *jp) {  // 0xB2EEA4
  uint16 result = addr_kSpacePirates_Ilist_ED36;
  uint16 v4 = NextRandom() & 1;
  Get_SpacePirates(cur_enemy_index)->sps_var_C = v4;
  if (v4)
    return INSTR_RETURN_ADDR(addr_off_B2ECEC);
  return INSTR_RETURN_ADDR(result);
}

const uint16 *SpacePirates_Instr_RandomNewDirFaceL(uint16 k, const uint16 *jp) {  // 0xB2EEBC
  uint16 result = addr_off_B2EDAC;
  uint16 v4 = NextRandom() & 1;
  Get_SpacePirates(cur_enemy_index)->sps_var_C = v4;
  if (v4)
    return INSTR_RETURN_ADDR(addr_kSpacePirates_Ilist_EDF6);
  return INSTR_RETURN_ADDR(result);
}

const uint16 *SpacePirates_Instr_PrepareWallJumpR(uint16 k, const uint16 *jp) {  // 0xB2EED4
  Enemy_SpacePirates *E = Get_SpacePirates(cur_enemy_index);
  E->sps_var_B = E->base.x_pos + E->sps_parameter_2;
  E->sps_var_D = E->base.x_pos + (E->sps_parameter_2 >> 1);
  E->sps_var_E = E->base.y_pos;
  E->sps_var_F = 64;
  return jp;
}

const uint16 *SpacePirates_Instr_PrepareWallJumpL(uint16 k, const uint16 *jp) {  // 0xB2EEFD
  Enemy_SpacePirates *E = Get_SpacePirates(cur_enemy_index);
  E->sps_var_B = E->base.x_pos - E->sps_parameter_2;
  E->sps_var_D = E->base.x_pos - (E->sps_parameter_2 >> 1);
  E->sps_var_E = E->base.y_pos;
  E->sps_var_F = 192;
  return jp;
}

const uint16 *SpacePirates_Instr_FireLaserL(uint16 k, const uint16 *jp) {  // 0xB2EF2A
  Enemy_SpacePirates *E = Get_SpacePirates(cur_enemy_index);
  eproj_init_param_0 = *((uint16 *)RomPtr_A0(E->base.enemy_ptr) + 3);
  eproj_spawn_pt = (Point16U){ E->base.x_pos - 24, E->base.y_pos - 16 };
  eproj_spawn_r22 = 0;
  SpawnEprojWithRoomGfx(addr_stru_86A17B, 0);
  return jp;
}

const uint16 *SpacePirates_Instr_FireLaserR(uint16 k, const uint16 *jp) {  // 0xB2EF5D
  Enemy_SpacePirates *E = Get_SpacePirates(cur_enemy_index);
  eproj_spawn_pt = (Point16U){ E->base.x_pos + 24, E->base.y_pos - 16 };
  eproj_spawn_r22 = 1;
  SpawnEprojWithRoomGfx(addr_stru_86A17B, 1);
  return jp;
}

const uint16 *SpacePirates_Instr_SetEnemyFunc(uint16 k, const uint16 *jp) {  // 0xB2EF83
  Get_SpacePirates(cur_enemy_index)->sps_var_A = jp[0];
  return jp + 1;
}

const uint16 *SpacePirates_Instr_PlaySfx(uint16 k, const uint16 *jp) {  // 0xB2EF93
  QueueSfx2_Max6(kSfx2_ShotKiHunter_WalkingSpacePirate);
  return jp;
}

void WallSpacePirates_Init(void) {  // 0xB2EF9F
  uint16 v0 = addr_kSpacePirates_Ilist_ED36;
  Enemy_SpacePirates *E = Get_SpacePirates(cur_enemy_index);
  if ((E->sps_parameter_1 & 1) != 0)
    v0 = addr_off_B2EDAC;
  E->base.current_instruction = v0;
  E->sps_var_20 = 190;
  E->sps_var_21 = 66;
  E->sps_var_22 = 2;
  if ((E->sps_parameter_1 & 0x8000) == 0) {
    E->sps_var_20 += 2;
    E->sps_var_21 -= 2;
    E->sps_var_22 += 2;
  }
  uint16 v2 = FUNC16(SpacePirates_Func_1);
  if ((E->sps_parameter_1 & 1) != 0)
    v2 = FUNC16(SpacePirates_Func_3);
  E->sps_var_A = v2;
  uint16 v3;
  if (sign16((E->base.x_pos & 0xF) - 11))
    v3 = E->base.x_pos & 0xFFF8;
  else
    v3 = (E->base.x_pos & 0xFFF0) + 16;
  E->base.x_pos = v3;
}

void CallSpacePiratesEnemyFunc(uint32 ea, uint16 k) {
  switch (ea) {
  case fnnullsub_169_B2: return;  // 0xb2804b
  case fnSpacePirates_Func_1: SpacePirates_Func_1(k); return;  // 0xb2f034
  case fnnullsub_279: return;  // 0xb2f04f
  case fnSpacePirates_Func_2: SpacePirates_Func_2(k); return;  // 0xb2f050
  case fnSpacePirates_Func_3: SpacePirates_Func_3(k); return;  // 0xb2f0c8
  case fnnullsub_281: return;  // 0xb2f0e3
  case fnnullsub_282: return;
  case fnSpacePirates_Func_4: SpacePirates_Func_4(k); return;  // 0xb2f0e4
  case fnSpacePirates_Func_5: SpacePirates_Func_5(k); return;  // 0xb2f6a9
  case fnSpacePirates_Func_6: SpacePirates_Func_6(k); return;  // 0xb2f6e4
  case fnSpacePirates_Func_11: SpacePirates_Func_11(k); return;  // 0xb2f817
  case fnSpacePirates_Func_12: SpacePirates_Func_12(k); return;
  case fnSpacePirates_Func_13: SpacePirates_Func_13(k); return;  // 0xb2f890
  case fnSpacePirates_Func_14: SpacePirates_Func_14(k); return;
  case fnSpacePirates_Func_15: SpacePirates_Func_15(k); return;  // 0xb2f909
  case fnSpacePirates_F985: SpacePirates_F985(k); return;  // 0xb2f985
  case fnSpacePirates_F9C1: SpacePirates_F9C1(k); return;  // 0xb2f9c1
  case fnSpacePirates_FA15: SpacePirates_FA15(k); return;  // 0xb2fa15
  case fnSpacePirates_FA59: SpacePirates_FA59(k); return;  // 0xb2fa59
  case fnSpacePirates_FA95: SpacePirates_FA95(k); return;  // 0xb2fa95
  case fnSpacePirates_FAE9: SpacePirates_FAE9(k); return;  // 0xb2fae9
  case fnWalkingSpacePirates_FD44: WalkingSpacePirates_FD44(); return;
  case fnWalkingSpacePirates_FDCE: WalkingSpacePirates_FDCE(); return;
  default: Unreachable();
  }
}

void WallSpacePirates_Main(void) {  // 0xB2F02D
  EnemyData *v0 = gEnemyData(cur_enemy_index);
  CallSpacePiratesEnemyFunc(v0->ai_var_A | 0xB20000, cur_enemy_index);
}

void SpacePirates_Func_1(uint16 k) {  // 0xB2F034
  if (IsSamusWithinEnemy_Y(cur_enemy_index, 0x20)) {
    Enemy_SpacePirates *E = Get_SpacePirates(cur_enemy_index);
    E->base.current_instruction = addr_kSpacePirates_Ilist_ED80;
    E->base.instruction_timer = 1;
  }
}

void SpacePirates_Func_2(uint16 k) {  // 0xB2F050
  Enemy_SpacePirates *E = Get_SpacePirates(cur_enemy_index);
  E->base.x_pos = E->sps_var_D + SineMult8bit(E->sps_var_F, E->sps_parameter_2 >> 1);
  E->base.y_pos = E->sps_var_E - CosineMult8bit(E->sps_var_F, E->sps_parameter_2 >> 2);
  uint16 v1 = (uint8)(LOBYTE(E->sps_var_F) - LOBYTE(E->sps_var_22));
  E->sps_var_F = v1;
  if (v1 == E->sps_var_20) {
    E->base.current_instruction = addr_kSpacePirates_Ilist_EDA4;
    E->base.instruction_timer = 1;
    uint16 v2;
    if (sign16((E->base.x_pos & 0xF) - 11))
      v2 = E->base.x_pos & 0xFFF8;
    else
      v2 = (E->base.x_pos & 0xFFF0) + 16;
    E->base.x_pos = v2;
  }
}

void SpacePirates_Func_3(uint16 k) {  // 0xB2F0C8
  if (IsSamusWithinEnemy_Y(cur_enemy_index, 0x20)) {
    Enemy_SpacePirates *E = Get_SpacePirates(cur_enemy_index);
    E->base.current_instruction = addr_kSpacePirates_Ilist_ECC0;
    E->base.instruction_timer = 1;
  }
}

void SpacePirates_Func_4(uint16 k) {  // 0xB2F0E4
  Enemy_SpacePirates *E = Get_SpacePirates(cur_enemy_index);
  E->base.x_pos = E->sps_var_D + SineMult8bit(E->sps_var_F, E->sps_parameter_2 >> 1);
  E->base.y_pos = E->sps_var_E - CosineMult8bit(E->sps_var_F, E->sps_parameter_2 >> 2);
  uint16 v1 = (uint8)(LOBYTE(E->sps_var_22) + LOBYTE(E->sps_var_F));
  E->sps_var_F = v1;
  if (v1 == E->sps_var_21) {
    E->base.current_instruction = addr_kSpacePirates_Ilist_ECE4;
    E->base.instruction_timer = 1;
    uint16 v2;
    if (sign16((E->base.x_pos & 0xF) - 11))
      v2 = E->base.x_pos & 0xFFF8;
    else
      v2 = (E->base.x_pos & 0xFFF0) + 16;
    E->base.x_pos = v2;
  }
}

const uint16 *SpacePirates_Instr_20(uint16 k, const uint16 *jp) {  // 0xB2F536
  Get_SpacePirates(cur_enemy_index)->base.palette_index = jp[0];
  return jp + 1;
}

const uint16 *SpacePirates_Instr_16(uint16 k, const uint16 *jp) {  // 0xB2F546
  QueueSfx2_Max6(jp[0]);
  return jp + 1;
}

void sub_B2F554(void) {  // 0xB2F554
  gEnemyData(cur_enemy_index)->instruction_timer = 1;
}

const uint16 *SpacePirates_Instr_15(uint16 k, const uint16 *jp) {  // 0xB2F564
  Enemy_SpacePirates *E = Get_SpacePirates(cur_enemy_index);
  eproj_spawn_rect = (Rect16U){ E->base.x_pos, E->base.y_pos, jp[1], jp[2] };
  SpawnEprojWithGfx(jp[0], cur_enemy_index, addr_kEproj_PirateClaw);
  return jp + 3;
}

const uint16 *SpacePirates_Instr_18(uint16 k, const uint16 *jp) {  // 0xB2F590
  Enemy_SpacePirates *E = Get_SpacePirates(cur_enemy_index);
  E->base.instruction_timer = 1;
  E->sps_var_C = (((E->base.x_pos - samus_x_pos) & 0x8000) != 0) ? addr_kSpacePirates_Ilist_F420 : addr_kSpacePirates_Ilist_F22E;
  return INSTR_RETURN_ADDR(E->sps_var_C);
}

void sub_B2F5B3(void) {  // 0xB2F5B3
  EnemyData *v0 = gEnemyData(cur_enemy_index);
  v0->instruction_timer = 1;
  v0->ai_var_C = (((v0->x_pos - samus_x_pos) & 0x8000) != 0) ? addr_kSpacePirates_Ilist_F51A : addr_kSpacePirates_Ilist_F32E;
}

const uint16 *SpacePirates_Instr_17(uint16 k, const uint16 *jp) {  // 0xB2F5D6
  Get_SpacePirates(k)->sps_var_00 = 0;
  return jp;
}

void NinjaSpacePirates_Init(void) {  // 0xB2F5DE
  Enemy_SpacePirates *E = Get_SpacePirates(cur_enemy_index);
  E->base.current_instruction = (E->sps_parameter_1 & 1) != 0 ? addr_kSpacePirates_Ilist_F4CC : addr_kSpacePirates_Ilist_F2DA;
  E->sps_var_C = E->base.current_instruction;
  uint16 x_pos = E->base.x_pos;
  if ((E->sps_parameter_1 & 1) != 0) {
    E->sps_var_E = x_pos;
    E->sps_var_F = E->sps_parameter_2 + x_pos;
  } else {
    E->sps_var_F = x_pos;
    E->sps_var_E = x_pos - E->sps_parameter_2;
  }
  uint16 r20 = (uint16)(E->sps_var_F - E->sps_var_E) >> 1;
  E->sps_var_D = E->sps_var_E + r20;
  uint16 r18 = 0;
  uint16 R22 = 0;
  r20 = (uint8)r20 << 8;
  do {
    r18 += 32;
    R22 += r18;
  } while (sign16(R22 - r20));
  E->sps_var_B = r18;
  uint16 R24 = (R22 & 0xFF00) >> 8;
  E->sps_var_F = E->sps_var_D + R24;
  E->sps_var_E = E->sps_var_D - R24;
  uint16 sps_var_E = E->sps_var_E;
  if ((E->sps_parameter_1 & 1) == 0)
    sps_var_E = E->sps_var_F;
  E->base.x_pos = sps_var_E;
  E->sps_var_A = FUNC16(nullsub_169_B2);
  E->sps_var_08 = E->base.y_pos;
  uint16 v6 = 0;
  uint16 v7 = 0;
  int n = 15;
  do {
    target_palettes[(v7 >> 1) + 240] = kWallSpacePirates_Palette_3[v6 >> 1];
    v6 += 2;
    v7 += 2;
  } while (--n >= 0);
}

void NinjaSpacePirates_Main(void) {  // 0xB2F6A2
  Enemy_SpacePirates *E = Get_SpacePirates(cur_enemy_index);
  CallSpacePiratesEnemyFunc(E->sps_var_A | 0xB20000, cur_enemy_index);
}

void SpacePirates_Func_5(uint16 k) {  // 0xB2F6A9
  Enemy_SpacePirates *E = Get_SpacePirates(cur_enemy_index);
  if ((int16)(abs16(E->base.x_pos - samus_x_pos) - 128) >= 0) {
    SpacePirates_Func_8();
  } else {
    E->base.current_instruction = ((E->base.x_pos - samus_x_pos) & 0x8000) ? addr_kSpacePirates_Ilist_F420 : addr_kSpacePirates_Ilist_F22E;
    E->sps_var_C = E->base.current_instruction;
    E->base.instruction_timer = 1;
  }
}

void SpacePirates_Func_6(uint16 k) {  // 0xB2F6E4
  if (!SpacePirates_Func_8() && !SpacePirates_Func_10() && !SpacePirates_Func_9())
    SpacePirates_Func_7(k);
}

void SpacePirates_Func_7(uint16 k) {  // 0xB2F6F7
  Enemy_SpacePirates *E = Get_SpacePirates(k);
  if ((E->base.frame_counter & 0x3F) == 0) {
    if (E->base.x_pos == E->sps_var_E) {
      if ((int16)(E->base.x_pos - samus_x_pos) < 0)
        return;
      E->base.current_instruction = addr_kSpacePirates_Ilist_F15C;
    } else {
      if ((int16)(E->base.x_pos - samus_x_pos) >= 0)
        return;
      E->base.current_instruction = addr_kSpacePirates_Ilist_F34A;
    }
    E->base.instruction_timer = 1;
  }
}

uint16 SpacePirates_Func_8(void) {  // 0xB2F72E
  uint16 v0 = 8;
  while (!projectile_type[v0 >> 1]) {
    v0 -= 2;
    if ((v0 & 0x8000) != 0)
      return 0;
  }
  int v1 = v0 >> 1;
  Enemy_SpacePirates *E = Get_SpacePirates(cur_enemy_index);
  if ((int16)(abs16(projectile_x_pos[v1] - E->base.x_pos) - 32) >= 0
      || (int16)(abs16(projectile_y_pos[v1] - E->base.y_pos) - 32) >= 0) {
    return 0;
  }
  E->base.current_instruction = (E->base.x_pos - samus_x_pos & 0x8000) ? addr_kSpacePirates_Ilist_F462 : addr_kSpacePirates_Ilist_F270;
  E->base.instruction_timer = 1;
  return 1;
}

uint16 SpacePirates_Func_9(void) {  // 0xB2F78D
  Enemy_SpacePirates *E = Get_SpacePirates(cur_enemy_index);
  if ((int16)(abs16(E->sps_var_D - samus_x_pos) - 32) >= 0)
    return 0;
  uint16 v1 = addr_kSpacePirates_Ilist_F1C4;
  if (E->base.x_pos == E->sps_var_E)
    v1 = addr_kSpacePirates_Ilist_F3B2;
  E->base.current_instruction = v1;
  E->base.instruction_timer = 1;
  return 1;
}

uint16 SpacePirates_Func_10(void) {  // 0xB2F7C6
  Enemy_SpacePirates *E = Get_SpacePirates(cur_enemy_index);
  if ((int16)(abs16(samus_x_pos - E->base.x_pos) - 40) >= 0
      || (int16)(abs16(samus_y_pos - E->base.y_pos) - 40) >= 0) {
    return 0;
  }
  E->base.current_instruction = ((E->base.x_pos - samus_x_pos) & 0x8000) != 0 ? addr_kSpacePirates_Ilist_F51A : addr_kSpacePirates_Ilist_F32E;
  E->base.instruction_timer = 1;
  return 1;
}

void SpacePirates_Func_11(uint16 k) {  // 0xB2F817
  Enemy_SpacePirates *E = Get_SpacePirates(k);
  E->base.x_pos -= HIBYTE(E->sps_var_00);
  --E->base.y_pos;
  --E->base.y_pos;
  E->sps_var_00 += 32;
  if ((int16)(E->base.x_pos - E->sps_var_D) < 0)
    E->sps_var_A = FUNC16(SpacePirates_Func_12);
}

void SpacePirates_Func_12(uint16 k) {  // 0xB2F84C
  Enemy_SpacePirates *E = Get_SpacePirates(k);
  E->base.x_pos -= HIBYTE(E->sps_var_00);
  ++E->base.y_pos;
  ++E->base.y_pos;
  uint16 v2 = E->sps_var_00 - 32;
  E->sps_var_00 = v2;
  if (!v2) {
    E->sps_var_A = FUNC16(nullsub_169_B2);
    E->base.current_instruction = addr_kSpacePirates_Ilist_F2F8;
    E->base.instruction_timer = 1;
    E->base.x_pos = E->sps_var_E;
    SpacePirates_FB11(k);
  }
}

void SpacePirates_Func_13(uint16 k) {  // 0xB2F890
  Enemy_SpacePirates *E = Get_SpacePirates(k);
  E->base.x_pos += HIBYTE(E->sps_var_00);
  --E->base.y_pos;
  --E->base.y_pos;
  E->sps_var_00 += 32;
  if ((int16)(E->base.x_pos - E->sps_var_D) >= 0)
    E->sps_var_A = FUNC16(SpacePirates_Func_14);
}

void SpacePirates_Func_14(uint16 k) {  // 0xB2F8C5
  Enemy_SpacePirates *E = Get_SpacePirates(k);
  E->base.x_pos += HIBYTE(E->sps_var_00);
  ++E->base.y_pos;
  ++E->base.y_pos;
  uint16 v2 = E->sps_var_00 - 32;
  E->sps_var_00 = v2;
  if (!v2) {
    E->sps_var_A = FUNC16(nullsub_169_B2);
    E->base.current_instruction = addr_kSpacePirates_Ilist_F4EA;
    E->base.instruction_timer = 1;
    E->base.x_pos = E->sps_var_F;
    SpacePirates_FB11(k);
  }
}

void SpacePirates_Func_15(uint16 k) {  // 0xB2F909
  if (!SpacePirates_Func_8() && !SpacePirates_Func_10())
    SpacePirates_Func_16();
}

void SpacePirates_Func_16(void) {  // 0xB2F917
  int16 v3;

  Enemy_SpacePirates *E = Get_SpacePirates(cur_enemy_index);
  if ((int16)(abs16(E->sps_var_D - samus_x_pos) - 32) < 0) {
    uint16 v2;
    do
      v2 = NextRandom() & 3;
    while (!v2);
    v3 = 0;
    if (E->base.x_pos == E->sps_var_E)
      v3 = 4;
    E->base.current_instruction = kSpacePirate_InstrListPtrs[v2 + v3];
    E->base.instruction_timer = 1;
  }
}

const uint16 *SpacePirates_Instr_19(uint16 k, const uint16 *jp) {  // 0xB2F969
  Enemy_SpacePirates *E = Get_SpacePirates(k);
  E->sps_var_00 = 1536;
  E->sps_var_03 = E->sps_var_D
    + ((uint16)(E->sps_var_F - E->sps_var_D) >> 1);
  return jp;
}

void SpacePirates_F985(uint16 k) {  // 0xB2F985
  int16 v2;

  Enemy_SpacePirates *E = Get_SpacePirates(k);
  E->base.y_pos -= HIBYTE(E->sps_var_00);
  v2 = E->sps_var_00 - 64;
  E->sps_var_00 = v2;
  if (v2 < 0) {
    E->sps_var_A = FUNC16(SpacePirates_F9C1);
    E->base.current_instruction = addr_kSpacePirates_Ilist_F2A0;
    E->base.instruction_timer = 1;
    E->sps_var_00 = 1536;
  }
}

void SpacePirates_F9C1(uint16 k) {  // 0xB2F9C1
  int16 v2;

  Enemy_SpacePirates *E = Get_SpacePirates(k);
  E->base.x_pos -= 5;
  if (Enemy_MoveDown(k, __PAIR32__(HIBYTE(E->sps_var_00), LOBYTE(E->sps_var_00)))
      || (v2 = E->sps_var_00 - 64, E->sps_var_00 = v2, v2 < 0)
      || (v2 & 0xFF00) == 0) {
    E->sps_var_A = FUNC16(SpacePirates_FA15);
    E->base.current_instruction = addr_kSpacePirates_Ilist_F2B2;
    E->base.instruction_timer = 1;
    E->base.y_pos = E->sps_var_08;
    SpacePirates_FB11(k);
  }
}

void SpacePirates_FA15(uint16 k) {  // 0xB2FA15
  Enemy_SpacePirates *E = Get_SpacePirates(k);
  uint16 v2 = E->base.x_pos - 2;
  E->base.x_pos = v2;
  if ((int16)(v2 - E->sps_var_E) < 0) {
    E->base.x_pos = E->sps_var_E;
    E->base.current_instruction = addr_kSpacePirates_Ilist_F2F8;
    E->base.instruction_timer = 1;
    E->sps_var_A = FUNC16(nullsub_169_B2);
  }
}

const uint16 *SpacePirates_Instr_21(uint16 k, const uint16 *jp) {  // 0xB2FA3D
  Enemy_SpacePirates *E = Get_SpacePirates(k);
  E->sps_var_00 = 1536;
  E->sps_var_03 = E->sps_var_E
    + ((uint16)(E->sps_var_D - E->sps_var_E) >> 1);
  return jp;
}

void SpacePirates_FA59(uint16 k) {  // 0xB2FA59
  int16 v2;

  Enemy_SpacePirates *E = Get_SpacePirates(k);
  E->base.y_pos -= HIBYTE(E->sps_var_00);
  v2 = E->sps_var_00 - 64;
  E->sps_var_00 = v2;
  if (v2 < 0) {
    E->sps_var_A = FUNC16(SpacePirates_FA95);
    E->base.current_instruction = addr_kSpacePirates_Ilist_F492;
    E->base.instruction_timer = 1;
    E->sps_var_00 = 1536;
  }
}

void SpacePirates_FA95(uint16 k) {  // 0xB2FA95
  int16 v2;

  Enemy_SpacePirates *E = Get_SpacePirates(k);
  E->base.x_pos += 5;
  if (Enemy_MoveDown(k, __PAIR32__(HIBYTE(E->sps_var_00), LOBYTE(E->sps_var_00)))
      || (v2 = E->sps_var_00 - 64, E->sps_var_00 = v2, v2 < 0)
      || (v2 & 0xFF00) == 0) {
    E->sps_var_A = FUNC16(SpacePirates_FAE9);
    E->base.current_instruction = addr_kSpacePirates_Ilist_F4A4;
    E->base.instruction_timer = 1;
    E->base.y_pos = E->sps_var_08;
    SpacePirates_FB11(k);
  }
}

void SpacePirates_FAE9(uint16 k) {  // 0xB2FAE9
  Enemy_SpacePirates *E = Get_SpacePirates(k);
  uint16 v2 = E->base.x_pos + 2;
  E->base.x_pos = v2;
  if ((int16)(v2 - E->sps_var_F) >= 0) {
    E->base.x_pos = E->sps_var_F;
    E->base.current_instruction = addr_kSpacePirates_Ilist_F4EA;
    E->base.instruction_timer = 1;
    E->sps_var_A = FUNC16(nullsub_169_B2);
  }
}

void SpacePirates_FB11(uint16 k) {  // 0xB2FB11
  Enemy_SpacePirates *E = Get_SpacePirates(k);
  CreateSpriteAtPos(E->base.x_pos - 8, E->base.y_pos + 28, 10, 0);
  CreateSpriteAtPos(E->base.x_pos + 8, E->base.y_pos + 28, 10, 0);
}

const uint16 *SpacePirates_Instr_12(uint16 k, const uint16 *jp) {  // 0xB2FC68
  Enemy_SpacePirates *E = Get_SpacePirates(cur_enemy_index);
  eproj_spawn_pt = (Point16U){ E->base.x_pos - 24, E->base.y_pos - jp[0] };
  eproj_spawn_r22 = 0;
  SpawnEprojWithRoomGfx(addr_stru_86A17B, 0);
  return jp + 1;
}

const uint16 *SpacePirates_Instr_14(uint16 k, const uint16 *jp) {  // 0xB2FC90
  Enemy_SpacePirates *E = Get_SpacePirates(cur_enemy_index);
  eproj_spawn_pt = (Point16U){ E->base.x_pos + 24, E->base.y_pos - jp[0] };
  eproj_spawn_r22 = 1;
  SpawnEprojWithRoomGfx(addr_stru_86A17B, 1);
  return jp + 1;
}

const uint16 *SpacePirates_Instr_11(uint16 k, const uint16 *jp) {  // 0xB2FCB8
  Get_SpacePirates(cur_enemy_index)->sps_var_A = jp[0];
  return jp + 1;
}

const uint16 *SpacePirates_Instr_13(uint16 k, const uint16 *jp) {  // 0xB2FCC8
  if (IsSamusWithinEnemy_Y(cur_enemy_index, 0x10)) {
    if ((int16)(samus_x_pos - Get_SpacePirates(cur_enemy_index)->base.x_pos) >= 0)
      return INSTR_RETURN_ADDR(addr_kSpacePirates_Ilist_FC0E);
    return INSTR_RETURN_ADDR(addr_kSpacePirates_Ilist_FB8C);
  } else {
    if ((int16)(samus_x_pos - Get_SpacePirates(cur_enemy_index)->base.x_pos) >= 0)
      return INSTR_RETURN_ADDR(addr_kSpacePirates_Ilist_FB64);
    return INSTR_RETURN_ADDR(addr_kSpacePirates_Ilist_FBE6);
  }
}

void WalkingSpacePirates_Init(void) {  // 0xB2FD02
  uint16 v0 = addr_kSpacePirates_Ilist_FB64;
  Enemy_SpacePirates *E = Get_SpacePirates(cur_enemy_index);
  if ((E->sps_parameter_1 & 1) != 0)
    v0 = addr_kSpacePirates_Ilist_FBE6;
  E->base.current_instruction = v0;
  E->sps_var_A = FUNC16(nullsub_169_B2);
  E->sps_var_F = E->sps_parameter_2 + E->base.x_pos;
  E->sps_var_E = E->base.x_pos - E->sps_parameter_2;
}

void WalkingSpacePirates_Main(void) {  // 0xB2FD32
  Enemy_SpacePirates *E = Get_SpacePirates(cur_enemy_index);
  CallSpacePiratesEnemyFunc(E->sps_var_A | 0xB20000, cur_enemy_index);
  if ((E->sps_parameter_1 & 0x8000) != 0)
    WalkingSpacePirates_FE4B();
}

void WalkingSpacePirates_FD44(void) {  // 0xB2FD44
  Enemy_SpacePirates *E = Get_SpacePirates(cur_enemy_index);

  if (IsSamusWithinEnemy_Y(cur_enemy_index, 0x10)) {
    uint16 v1 = addr_kSpacePirates_Ilist_FB8C;
    if ((int16)(samus_x_pos - E->base.x_pos) >= 0)
      v1 = addr_kSpacePirates_Ilist_FC0E;
    E->base.current_instruction = v1;
    E->base.instruction_timer = 1;
  } else {
    if (Enemy_MoveDown(cur_enemy_index, INT16_SHL16(1))) {
      uint16 x_pos = E->base.x_pos;
      E->sps_var_00 = x_pos;
      E->base.x_pos = x_pos - 17;
      uint8 result = Enemy_MoveDown(cur_enemy_index, INT16_SHL16(1));
      E->base.x_pos = E->sps_var_00;

      if (result) {
        EnemyFunc_BBBF(cur_enemy_index, INT16_SHL16(-9));
        if (!Enemy_MoveRight_IgnoreSlopes(cur_enemy_index, -14337)) {
          if ((int16)(E->base.x_pos - E->sps_var_E) >= 0)
            return;
        }
      }
      E->base.current_instruction = addr_kSpacePirates_Ilist_FBC6;
      E->base.instruction_timer = 1;
    }
  }
}

void WalkingSpacePirates_FDCE(void) {  // 0xB2FDCE
  Enemy_SpacePirates *E = Get_SpacePirates(cur_enemy_index);

  if (IsSamusWithinEnemy_Y(cur_enemy_index, 0x10)) {
    uint16 v1 = addr_kSpacePirates_Ilist_FB8C;
    if ((int16)(samus_x_pos - E->base.x_pos) >= 0)
      v1 = addr_kSpacePirates_Ilist_FC0E;
    E->base.current_instruction = v1;
    E->base.instruction_timer = 1;
  } else {
    if (Enemy_MoveDown(cur_enemy_index, INT16_SHL16(1))) {
      uint16 x_pos = E->base.x_pos;
      E->sps_var_00 = x_pos;
      E->base.x_pos = x_pos + 16;
      uint8 result = Enemy_MoveDown(cur_enemy_index, INT16_SHL16(1));
      E->base.x_pos = E->sps_var_00;
      if (!result ||
          (Enemy_MoveRight_IgnoreSlopes(cur_enemy_index, 14336)) ||
          (int16)(E->base.x_pos - E->sps_var_F) >= 0) {
        E->base.current_instruction = addr_kSpacePirates_Ilist_FC48;
        E->base.instruction_timer = 1;
      }
    }
  }
}

void WalkingSpacePirates_FE4B(void) {  // 0xB2FE4B
  uint16 v0 = 8;
  while (!projectile_type[v0 >> 1]) {
    v0 -= 2;
    if ((v0 & 0x8000) != 0)
      return;
  }
  int v1 = v0 >> 1;
  Enemy_SpacePirates *E = Get_SpacePirates(cur_enemy_index);
  if ((int16)(abs16(projectile_x_pos[v1] - E->base.x_pos) - 32) < 0
      && (int16)(abs16(projectile_y_pos[v1] - E->base.y_pos) - 32) < 0) {
    E->base.current_instruction = ((E->base.x_pos - samus_x_pos) & 0x8000) ? addr_kSpacePirates_Ilist_FB58 : addr_kSpacePirates_Ilist_FB4C;
    E->base.instruction_timer = 1;
  }
}
