//  Enemy AI - Draygon & Spore Spawn

#include "ida_types.h"
#include "variables.h"
#include "funcs.h"
#include "enemy_types.h"
#include "sm_a5.h"





void Enemy_GrappleReact_NoInteract_A5(void) {  // 0xA58000
  SwitchEnemyAiToMainAi();
}

void Enemy_GrappleReact_CancelBeam_A5(void) {  // 0xA5800F
  Enemy_SwitchToFrozenAi();
}

void Enemy_NormalTouchAI_A5(void) {  // 0xA58023
  NormalEnemyTouchAi();
}

void Enemy_NormalShotAI_A5(void) {  // 0xA5802D
  NormalEnemyShotAi();
}

void Enemy_NormalFrozenAI_A5(void) {  // 0xA58041
  NormalEnemyFrozenAI();
}

void Draygon_Init(void) {  // 0xA58687
  uint16 j;

  for (int i = 48; i >= 0; i -= 2)
    target_palettes[(i >> 1) + 144] = kDraygon_Palette1[i >> 1];
  for (j = 4094; (j & 0x8000) == 0; j -= 2)
    tilemap_stuff[j >> 1] = 824;
  Get_Draygon(cur_enemy_index)->base.palette_index = 0xe00;
  *(uint16 *)&enemy_gfx_drawn_hook.bank = 165;
  enemy_gfx_drawn_hook.addr = FUNC16(Draygon_Func_36);
  flag_process_all_enemies = -1;
  Get_Draygon(0)->base.current_instruction = addr_kDraygon_Ilist_9889;
  Get_Draygon(0x40)->base.current_instruction = addr_kDraygon_Ilist_9944;
  Get_Draygon(0x80)->base.current_instruction = addr_kDraygon_Ilist_99FC;
  Get_Draygon(0xC0)->base.current_instruction = addr_kDraygon_Ilist_9813;
  enemy_bg2_tilemap_size = 1024;
  Get_Draygon(cur_enemy_index)->draygon_var_A = FUNC16(Draygon_Func_1);
  SpawnDraygonMainScreenLayerHdmaObject();
  room_loading_irq_handler = 12;
  SpawnBG3ScrollHdmaObject();
  Get_Draygon(0)->draygon_var_45 = 1;
  DisableMinimapAndMarkBossRoomAsExplored();
}

void CallDraygonFunc(uint32 ea, uint16 k) {
  switch (ea) {
  case fnnullsub_169_A5: return;
  case fnDraygon_Func_1: Draygon_Func_1(); return;
  case fnDraygon_Func_2: Draygon_Func_2(); return;
  case fnDraygon_Func_4: Draygon_Func_4(); return;
  case fnDraygon_Func_6: Draygon_Func_6(); return;
  case fnDraygon_Func_8: Draygon_Func_8(); return;
  case fnDraygon_Func_9: Draygon_Func_9(); return;
  case fnDraygon_Func_10: Draygon_Func_10(); return;
  case fnDraygon_Func_11: Draygon_Func_11(); return;
  case fnDraygon_Func_12: Draygon_Func_12(); return;
  case fnDraygon_Func_13: Draygon_Func_13(); return;
  case fnDraygon_Func_14: Draygon_Func_14(); return;
  case fnDraygon_Func_15: Draygon_Func_15(); return;
  case fnDraygon_Func_16: Draygon_Func_16(); return;
  case fnDraygon_Func_17: Draygon_Func_17(k); return;
  case fnDraygon_Func_18: Draygon_Func_18(); return;
  case fnDraygon_Func_19: Draygon_Func_19(); return;
  case fnDraygon_Func_20: Draygon_Func_20(); return;
  case fnDraygon_Func_21: Draygon_Func_21(k); return;
  case fnDraygon_Func_22: Draygon_Func_22(); return;
  case fnDraygon_Func_23: Draygon_Func_23(); return;
  case fnDraygon_Func_24: Draygon_Func_24(k); return;
  case fnDraygon_Func_25: Draygon_Func_25(k); return;
  case fnDraygon_Func_26: Draygon_Func_26(k); return;
  case fnDraygon_Func_27: Draygon_Func_27(k); return;
  case fnDraygon_Func_28: Draygon_Func_28(k); return;
  case fnDraygon_Func_29: Draygon_Func_29(); return;
  case fnDraygon_Func_30: Draygon_Func_30(); return;
  case fnDraygon_Func_31: Draygon_Func_31(); return;
  case fnDraygon_Func_32: Draygon_Func_32(); return;
  case fnDraygon_Func_33: Draygon_Func_33(); return;
  case fnDraygon_Func_48: Draygon_Func_48(k); return;
  case fnDraygon_Func_49: Draygon_Func_49(k); return;
  case fnnullsub_223: return;
  case fnSporeSpawn_Func_1: SporeSpawn_Func_1(); return;
  case fnSporeSpawn_Func_2: SporeSpawn_Func_2(k); return;
  case fnSporeSpawn_Func_3: SporeSpawn_Func_3(); return;
  case fnSporeSpawn_Func_4: SporeSpawn_Func_4(); return;
  default: Unreachable();
  }
}

void Draygon_Main(void) {  // 0xA586FC
  Enemy_Draygon *EK = Get_Draygon(cur_enemy_index);
  CallDraygonFunc(EK->draygon_var_A | 0xA50000, cur_enemy_index);

  Enemy_Draygon *E0 = Get_Draygon(0);
  uint16 x_pos = E0->base.x_pos;
  Enemy_Draygon *E1 = Get_Draygon(0x40);
  E1->base.x_pos = x_pos;
  Enemy_Draygon *E2 = Get_Draygon(0x80);
  E2->base.x_pos = x_pos;
  Enemy_Draygon *E3 = Get_Draygon(0xC0);
  E3->base.x_pos = x_pos;
  uint16 y_pos = E0->base.y_pos;
  E1->base.y_pos = y_pos;
  E2->base.y_pos = y_pos;
  E3->base.y_pos = y_pos;
}

void Draygon_Func_1(void) {  // 0xA5871B
  VramWriteEntry *v2;

  Draygon_Func_3();
  Enemy_Draygon *E = Get_Draygon(0);
  if (sign16(E->draygon_var_B - 256)) {
    if (!E->draygon_var_B) {
      v2 = gVramWriteEntry(vram_write_queue_tail);
      v2->size = 1536;
      v2->src.addr = -27648;
      *(uint16 *)&v2->src.bank = 177;
      v2->vram_dst = 27904;
      vram_write_queue_tail += 7;
      Draygon_Func_45();
    }
    ++E->draygon_var_B;
  } else {
    E->draygon_var_A = FUNC16(Draygon_Func_2);
    E->draygon_var_B = 0;
    uint16 x_pos = E->base.x_pos;
    E->draygon_var_00 = x_pos;
    E->draygon_var_02 = x_pos + 672;
    E->draygon_var_01 = E->base.y_pos;
    E->base.x_pos = E->draygon_var_00;
    E->base.y_pos = E->draygon_var_01;
    E->draygon_var_0F = 24;
  }
}

void Draygon_Func_2(void) {  // 0xA5878B
  Draygon_Func_3();
  Enemy_Draygon *E = Get_Draygon(0);
  if (sign16(E->draygon_var_B - 1232)) {
    Draygon_Func_46();
    ++E->draygon_var_B;
  } else {
    E->draygon_var_A = FUNC16(Draygon_Func_4);
    E->draygon_var_B = 0;
  }
}

void Draygon_Func_3(void) {  // 0xA587AA
  int8 Random;

  if ((nmi_frame_counter_word & 0x3F) == 0) {
    Random = NextRandom();
    uint16 result = 2 * ((Random & 3) + 2);
    if (!Get_Draygon(result)->draygon_var_40) {
      int v2 = (uint16)(4 * ((Random & 3) + 2)) >> 1;
      eproj_spawn_pt = (Point16U){ kDraygonTurret_XYSpawnPositions[v2], kDraygonTurret_XYSpawnPositions[v2 + 1] };
      SpawnEprojWithGfx(3, result, addr_kEproj_DraygonWallTurretProjectile);
    }
  }
}

void Draygon_Func_4(void) {  // 0xA587F4
  Draygon_Func_3();
  Draygon_Func_5();
  Enemy_Draygon *E = Get_Draygon(0);
  E->draygon_var_A = FUNC16(Draygon_Func_6);
  E->base.current_instruction = addr_kDraygon_Ilist_97D1;
  E->base.instruction_timer = 1;
  E->draygon_var_20 = 1;
}

void Draygon_Func_5(void) {  // 0xA58817
  Enemy_Draygon *E = Get_Draygon(0);
  //varE28 = 384;
  uint16 varE24 = 384;
  uint16 varE22 = 0;
  uint16 varE26 = 0;
  while (1) {
    varE22 += E->draygon_var_0F;
    uint16 v1 = varE24 - HIBYTE(varE22);
    if ((int16)(v1 - E->draygon_var_01) < 0)
      break;
    varE24 -= HIBYTE(varE22);
    *(uint16 *)((uint8 *)&g_word_7E9002 + varE26++) = v1;
    varE26 += 2;
    if (!sign16(++varE26 - 2048)) {
      Unreachable();
    }
  }
  uint32 t = EnemyFunc_Divide(varE26 >> 2, Abs16(E->draygon_var_00 - samus_x_pos) << 16);
  SetHiLo(&E->draygon_var_D, &E->draygon_var_E, t);
  uint16 v6 = varE26;
  *(uint16 *)((uint8 *)&g_word_7E9002 + varE26) = E->base.y_pos;
  E->draygon_var_B = v6;
  E->draygon_var_C = v6;
}

void Draygon_Func_6(void) {  // 0xA588B1
  Draygon_Func_3();
  Draygon_Func_35();
  Enemy_Draygon *E = Get_Draygon(0);
  uint16 draygon_var_B = E->draygon_var_B;
  if (draygon_var_B == 104) {
    Enemy_Draygon *E3 = Get_Draygon(0xC0);
    E3->base.current_instruction = addr_kDraygon_Ilist_9C06;
    E3->base.instruction_timer = 1;
  }
  Get_Draygon(cur_enemy_index)->base.y_pos = *(uint16 *)((uint8 *)&g_word_7E9002 + draygon_var_B);
  E->draygon_var_B -= 4;
  if (E->draygon_var_B) {
    AddToHiLo(&E->base.x_pos, &E->base.x_subpos, __PAIR32__(E->draygon_var_D, E->draygon_var_E));
  } else {
    E->draygon_var_A = FUNC16(Draygon_Func_8);
  }
}

void Draygon_Func_7(void) {  // 0xA58901
  Enemy_Draygon *E = Get_Draygon(0);
  if ((nmi_frame_counter_word & 0xF) == 0) {
    E->base.current_instruction = addr_kDraygon_Ilist_98FE;
    if (E->draygon_var_20)
      E->base.current_instruction = addr_kDraygon_Ilist_9C90;
    E->base.instruction_timer = 1;
  }
}

void Draygon_Func_8(void) {  // 0xA58922
  Draygon_Func_3();
  Enemy_Draygon *E = Get_Draygon(0);
  uint32 t = EnemyFunc_Divide(E->draygon_var_C >> 2, (672 - E->base.x_pos) << 16);
  SetHiLo(&E->draygon_var_D, &E->draygon_var_E, t);
  E->draygon_var_A = FUNC16(Draygon_Func_9);
}

void Draygon_Func_9(void) {  // 0xA58951
  Draygon_Func_3();
  Enemy_Draygon *E = Get_Draygon(0);
  uint16 draygon_var_B = E->draygon_var_B;
  if (draygon_var_B == 104) {
    Enemy_Draygon *E3 = Get_Draygon(0xC0);
    E3->base.current_instruction = addr_kDraygon_Ilist_9BDA;
    E3->base.instruction_timer = 1;
  }
  Get_Draygon(cur_enemy_index)->base.y_pos = *(uint16 *)((uint8 *)&g_word_7E9002 + draygon_var_B);
  E->draygon_var_B += 4;
  if (E->draygon_var_B == E->draygon_var_C) {
    E->draygon_var_B = 0;
    if ((random_number & 1) != 0)
      E->draygon_var_A = FUNC16(Draygon_Func_10);
    else
      E->draygon_var_A = FUNC16(Draygon_Func_18);
  } else {
    AddToHiLo(&E->base.x_pos, &E->base.x_subpos, __PAIR32__(E->draygon_var_D, E->draygon_var_E));
  }
}

void Draygon_Func_10(void) {  // 0xA589B3
  Draygon_Func_3();
  Enemy_Draygon *E = Get_Draygon(0);
  printf("Wtf is varE26?\n");
  uint16 varE26 = 0; // Wtf is varE26
  uint32 t = EnemyFunc_Divide(varE26 >> 2, Abs16(E->draygon_var_02 - samus_x_pos) << 16);
  SetHiLo(&E->draygon_var_D, &E->draygon_var_E, t);
  E->draygon_var_A = FUNC16(Draygon_Func_11);
  E->base.current_instruction = addr_kDraygon_Ilist_97BB;
  E->base.instruction_timer = 1;
  E->draygon_var_20 = 0;
  E->draygon_var_B = E->draygon_var_C;
}

void Draygon_Func_11(void) {  // 0xA58A00
  Draygon_Func_3();
  Draygon_Func_35();
  Enemy_Draygon *E = Get_Draygon(0);
  uint16 draygon_var_B = E->draygon_var_B;
  if (draygon_var_B == 104) {
    Enemy_Draygon *E3 = Get_Draygon(0xC0);
    E3->base.current_instruction = addr_kDraygon_Ilist_9813;
    E3->base.instruction_timer = 1;
  }
  Get_Draygon(cur_enemy_index)->base.y_pos = *(uint16 *)((uint8 *)&g_word_7E9002 + draygon_var_B);
  E->draygon_var_B -= 4;
  if (E->draygon_var_B) {
    AddToHiLo(&E->base.x_pos, &E->base.x_subpos, -IPAIR32(E->draygon_var_D, E->draygon_var_E));
  } else {
    E->draygon_var_A = FUNC16(Draygon_Func_12);
  }
}

void Draygon_Func_12(void) {  // 0xA58A50
  Draygon_Func_3();
  Enemy_Draygon *E = Get_Draygon(0);
  uint32 t = EnemyFunc_Divide(E->draygon_var_C >> 2, (E->base.x_pos - E->draygon_var_00) << 16);
  E->draygon_var_D = t >> 16;
  E->draygon_var_E = t;
  E->draygon_var_A = FUNC16(Draygon_Func_13);
}

void Draygon_Func_13(void) {  // 0xA58A90
  Draygon_Func_3();
  Draygon_Func_35();
  Enemy_Draygon *E = Get_Draygon(0);
  uint16 draygon_var_B = E->draygon_var_B;
  if (draygon_var_B == 104) {
    Enemy_Draygon *E3 = Get_Draygon(0xC0);
    E3->base.current_instruction = addr_kDraygon_Ilist_97E7;
    E3->base.instruction_timer = 1;
  }
  Get_Draygon(cur_enemy_index)->base.y_pos = *(uint16 *)((uint8 *)&g_word_7E9002 + draygon_var_B);
  E->draygon_var_B += 4;
  if (E->draygon_var_B == E->draygon_var_C) {
    if ((random_number & 1) != 0) {
      E->draygon_var_A = FUNC16(Draygon_Func_4);
      E->draygon_var_B = 0;
      E->base.x_pos = E->draygon_var_00;
      E->base.y_pos = E->draygon_var_01;
    } else {
      E->draygon_var_A = FUNC16(Draygon_Func_14);
      E->base.x_pos = E->draygon_var_00;
    }
  } else {
    AddToHiLo(&E->base.x_pos, &E->base.x_subpos, -IPAIR32(E->draygon_var_D, E->draygon_var_E));
  }
}

void Draygon_Func_14(void) {  // 0xA58B0A
  Draygon_Func_3();
  Enemy_Draygon *E = Get_Draygon(0);
  E->base.x_pos = -80;
  E->base.y_pos = 384;
  E->draygon_var_E = 0;
  E->draygon_var_D = 1;
  E->draygon_var_0D = 0;
  Enemy_Draygon *E3 = Get_Draygon(0xC0);
  E3->base.current_instruction = addr_kDraygon_Ilist_9C06;
  E3->base.instruction_timer = 1;
  E->draygon_var_A = FUNC16(Draygon_Func_15);
  E->base.current_instruction = addr_kDraygon_Ilist_97D1;
  E->base.instruction_timer = 1;
  E->draygon_var_20 = 1;
}

void Draygon_Func_15(void) {  // 0xA58B52
  Draygon_Func_3();
  Draygon_Func_35();
  Enemy_Draygon *E = Get_Draygon(0);
  uint16 v2 = Abs16(E->base.x_pos - samus_x_pos);
  if (sign16(v2 - 208)) {
    E->draygon_var_A = FUNC16(Draygon_Func_16);
    E->draygon_var_03 = 16;
  } else {
    E->base.y_pos = CosineMult8bit(E->draygon_var_0D, 32) + 384;
    E->draygon_var_0D = (uint8)(E->draygon_var_0D + 1);
    AddToHiLo(&E->base.x_pos, &E->base.x_subpos, __PAIR32__(E->draygon_var_D, E->draygon_var_E));
  }
}

void Draygon_Func_16(void) {  // 0xA58BAE
  Enemy_Draygon *E = Get_Draygon(0);

  Draygon_Func_3();
  if (samus_x_speed_divisor)
    goto LABEL_9;
  if ((random_number & 0xF) == 0) {
    uint16 v1 = E->draygon_var_03 - 1;
    E->draygon_var_03 = v1;
    if (!v1)
      goto LABEL_8;
    E->base.current_instruction = addr_kDraygon_Ilist_9C90;
    E->base.instruction_timer = 1;
  }
  E->base.y_pos = CosineMult8bit(E->draygon_var_0D, 32) + 384;
  E->draygon_var_0D = (uint8)(E->draygon_var_0D + 1);
  AddToHiLo(&E->base.x_pos, &E->base.x_subpos, __PAIR32__(E->draygon_var_D, E->draygon_var_E));
  if ((int16)E->base.x_pos >= 0 && !sign16(E->base.x_pos - 672)) {
LABEL_8:
    if (!samus_x_speed_divisor) {
      Enemy_Draygon *E3 = Get_Draygon(0xC0);
      E3->base.current_instruction = addr_kDraygon_Ilist_9BDA;
      E3->base.instruction_timer = 1;
      E->draygon_var_A = FUNC16(Draygon_Func_17);
      return;
    }
LABEL_9:
    E->draygon_var_A = FUNC16(Draygon_Func_22);
  }
}

void Draygon_Func_17(uint16 k) {  // 0xA58C33
  Draygon_Func_35();
  Enemy_Draygon *E = Get_Draygon(0);
  E->base.y_pos = CosineMult8bit(E->draygon_var_0D, 32) + 384;
  E->draygon_var_0D = (uint8)(E->draygon_var_0D + 1);
  AddToHiLo(&E->base.x_pos, &E->base.x_subpos, __PAIR32__(E->draygon_var_D, E->draygon_var_E));
  if ((int16)E->base.x_pos >= 0 && !sign16(E->base.x_pos - 672)) {
    E->draygon_var_A = FUNC16(Draygon_Func_10);
    E->base.x_pos = 592;
    E->base.y_pos = -80;
    E->draygon_var_B = E->draygon_var_C;
  }
}

void Draygon_Func_18(void) {  // 0xA58C8E
  Enemy_Draygon *E = Get_Draygon(0);
  E->base.x_pos = E->draygon_var_02;
  E->base.y_pos = 384;
  E->draygon_var_E = 0;
  E->draygon_var_D = 1;
  E->draygon_var_0D = 0;
  Enemy_Draygon *E3 = Get_Draygon(0xC0);
  E3->base.current_instruction = addr_kDraygon_Ilist_9C06;
  E3->base.instruction_timer = 1;
  E->draygon_var_A = FUNC16(Draygon_Func_19);
  E->base.current_instruction = addr_kDraygon_Ilist_97BB;
  E->base.instruction_timer = 1;
  E->draygon_var_20 = 0;
}

void Draygon_Func_19(void) {  // 0xA58CD4
  Draygon_Func_3();
  Draygon_Func_35();
  Enemy_Draygon *E = Get_Draygon(0);
  uint16 v2 = Abs16(E->base.x_pos - samus_x_pos);
  if (sign16(v2 - 208)) {
    E->draygon_var_A = FUNC16(Draygon_Func_20);
    E->draygon_var_03 = 16;
  } else {
    E->base.y_pos = CosineMult8bit(E->draygon_var_0D, 32) + 384;
    E->draygon_var_0D = (uint8)(E->draygon_var_0D + 1);
    AddToHiLo(&E->base.x_pos, &E->base.x_subpos, -IPAIR32(E->draygon_var_D, E->draygon_var_E));
  }
}

void Draygon_Func_20(void) {  // 0xA58D30
  Enemy_Draygon *E = Get_Draygon(0);
  if (samus_x_speed_divisor)
    goto LABEL_9;
  if ((random_number & 0xF) == 0) {
    uint16 v1 = E->draygon_var_03 - 1;
    E->draygon_var_03 = v1;
    if (!v1)
      goto LABEL_8;
    E->base.current_instruction = addr_kDraygon_Ilist_98FE;
    E->base.instruction_timer = 1;
  }
  E->base.y_pos = CosineMult8bit(E->draygon_var_0D, 32) + 384;
  E->draygon_var_0D = (uint8)(E->draygon_var_0D + 1);
  AddToHiLo(&E->base.x_pos, &E->base.x_subpos, -IPAIR32(E->draygon_var_D, E->draygon_var_E));
  if ((int32)E->base.x_pos < 0 && sign16(E->base.x_pos + 80)) {
LABEL_8:
    if (!samus_x_speed_divisor) {
      Enemy_Draygon *E3 = Get_Draygon(0xC0);
      E3->base.current_instruction = addr_kDraygon_Ilist_97E7;
      E3->base.instruction_timer = 1;
      Get_Draygon(0)->draygon_var_A = FUNC16(Draygon_Func_21);
      return;
    }
LABEL_9:
    Get_Draygon(0)->draygon_var_A = FUNC16(Draygon_Func_22);
  }
}

void Draygon_Func_21(uint16 k) {  // 0xA58DB2
  Enemy_Draygon *E = Get_Draygon(0);
  Draygon_Func_35();
  if (samus_x_speed_divisor) {
    E->draygon_var_A = FUNC16(Draygon_Func_22);
  } else {
    E->base.y_pos = CosineMult8bit(E->draygon_var_0D, 32) + 384;
    E->draygon_var_0D = (uint8)(E->draygon_var_0D + 1);
    AddToHiLo(&E->base.x_pos, &E->base.x_subpos, -IPAIR32(E->draygon_var_D, E->draygon_var_E));
    if ((int16)E->base.x_pos < 0 && sign16(E->base.x_pos + 80)) {
      E->draygon_var_A = FUNC16(Draygon_Func_4);
      E->base.x_pos = -80;
      E->base.y_pos = -80;
      E->draygon_var_B = E->draygon_var_C;
    }
  }
}

void Draygon_Func_22(void) {  // 0xA58E19
  Enemy_Draygon *E = Get_Draygon(0);
  int16 v2;
  uint16 v4;

  Draygon_Func_3();
  if (samus_x_speed_divisor) {
    E->base.properties |= kEnemyProps_Tangible;
    v2 = 8;
    if (!E->draygon_var_20)
      v2 = -8;
    uint16 v3 = Abs16(E->base.x_pos + v2 - samus_x_pos);
    if (sign16(v3 - 8) && (v4 = Abs16(E->base.y_pos - samus_y_pos), sign16(v4 - 8))) {
      uint16 v5 = addr_kDraygon_Ilist_9845;
      if (E->draygon_var_20)
        v5 = addr_kDraygon_Ilist_9C38;
      Enemy_Draygon *E3 = Get_Draygon(0xC0);
      E3->base.current_instruction = v5;
      E3->base.instruction_timer = 1;
      if (RunSamusCode(kSamusCode_13_IsGrappleActive)) {
        E->draygon_var_A = FUNC16(Draygon_Func_23);
      } else {
        Samus_SetGrabbedByDraygonPose(E->draygon_var_20 != 0);
        E->draygon_var_06 = 256;
        E->draygon_var_07 = 384;
        E->draygon_var_05 = 0;
        E->draygon_var_09 = 0;
        E->draygon_var_08 = 192;
        E->draygon_var_0B = 2048;
        E->draygon_var_A = FUNC16(Draygon_Func_24);
      }
    } else {
      uint16 varE20 = (uint8)(64 - CalculateAngleFromXY(samus_x_pos - E->base.x_pos, samus_y_pos - E->base.y_pos));
      Point32 pt = ConvertAngleToXy(varE20, 2);
      MoveEnemyByAngleAndXYSpeed(varE20, pt);
    }
  } else {
    E->draygon_var_A = FUNC16(Draygon_Func_30);
  }
}

void Draygon_Func_23(void) {  // 0xA58F10
  grapple_beam_function = FUNC16(GrappleBeam_Func2);
  Get_Draygon(0)->draygon_var_A = FUNC16(Draygon_Func_29);
}

void Draygon_Func_24(uint16 k) {  // 0xA58F1E
  Enemy_Draygon *E = Get_Draygon(0);
  uint16 v5;

  if ((samus_grapple_flags & 1) != 0) {
    E->base.flash_timer = get_EnemyDef_A2(E->base.enemy_ptr)->hurt_ai_time + 8;
    E->base.ai_handler_bits |= 2;
  } else {
    uint16 v4 = Abs16(E->base.x_pos - 256);
    if (sign16(v4 - 2) && (v5 = Abs16(E->base.y_pos - 384), sign16(v5 - 2))) {
      E->draygon_var_A = FUNC16(Draygon_Func_25);
      uint16 v6 = addr_kDraygon_Ilist_9922;
      if (E->draygon_var_20)
        v6 = addr_kDraygon_Ilist_9CB4;
      Enemy_Draygon *EK = Get_Draygon(k);
      EK->base.current_instruction = v6;
      EK->base.instruction_timer = 1;
      E->base.properties |= kEnemyProps_Tangible;
    } else {
      uint16 varE20 = (uint8)(64 - CalculateAngleFromXY(256 - E->base.x_pos, 384 - E->base.y_pos));
      Point32 pt = ConvertAngleToXy(varE20, 2);
      MoveEnemyByAngleAndXYSpeed(varE20, pt);
      Draygon_Func_40(k);
    }
  }
}

void Draygon_Func_25(uint16 k) {  // 0xA58FD6
  Enemy_Draygon *E = Get_Draygon(0);
  uint16 v6;

  if ((samus_grapple_flags & 1) != 0) {
    E->base.flash_timer = get_EnemyDef_A2(E->base.enemy_ptr)->hurt_ai_time + 8;
    E->base.ai_handler_bits |= 2;
  } else if ((uint8)random_number) {
    E->base.x_pos = E->draygon_var_06 + CosineMult8bit(E->draygon_var_08, E->draygon_var_05);
    E->base.y_pos = E->draygon_var_07 + SineMult8bit(E->draygon_var_08, E->draygon_var_05 >> 2);
    if ((Get_Draygon(k)->base.frame_counter & 7) == 0) {
      uint16 x = E->draygon_var_20 ? E->base.x_pos + 32 : E->base.x_pos - 32;
      uint16 y = E->base.y_pos - 16;
      CreateSpriteAtPos(x, y, 61, 0);
    }
    AddToHiLo(&E->draygon_var_05, &E->draygon_var_09, 0x2000);
    uint16 draygon_var_0A, v8;
    if (!sign16(E->draygon_var_05 - 160)
        || (v6 = E->draygon_var_0B - 1,
            E->draygon_var_0B = v6,
            E->draygon_var_08 = (uint8)(LOBYTE(E->draygon_var_08) + HIBYTE(v6)),
            draygon_var_0A = E->draygon_var_0A,
            E->draygon_var_0A = draygon_var_0A - 0x4000,
            v8 = (__PAIR32__(E->draygon_var_07, draygon_var_0A) - 0x4000) >> 16,
            E->draygon_var_07 = v8,
            sign16(v8 - 64))) {
      E->draygon_var_A = FUNC16(Draygon_Func_27);
    } else {
      Draygon_Func_40(k);
    }
  } else {
    E->draygon_var_0C = 64;
    E->draygon_var_A = FUNC16(Draygon_Func_26);
  }
}

void Draygon_Func_26(uint16 k) {  // 0xA590D4
  uint16 v0 = k;
  uint16 v3;

  Draygon_Func_40(v0);
  Enemy_Draygon *E = Get_Draygon(0);
  uint16 v2 = E->draygon_var_0C - 1;
  E->draygon_var_0C = v2;
  if (v2) {
    if (v2 == 63) {
      v3 = addr_kDraygon_Ilist_9AE8;
      if (E->draygon_var_20)
        v3 = addr_kDraygon_Ilist_9EA1;
      Enemy_Draygon *E2 = Get_Draygon(0x80);
      E2->base.current_instruction = v3;
      E2->base.instruction_timer = 1;
    }
  } else {
    E->draygon_var_A = FUNC16(Draygon_Func_25);
  }
}

void Draygon_Func_27(uint16 k) {  // 0xA59105
  Draygon_Func_40(k);
  uint16 v1 = addr_kDraygon_Ilist_9A68;
  if (Get_Draygon(k)->draygon_var_20)
    v1 = addr_kDraygon_Ilist_9E21;
  Enemy_Draygon *E = Get_Draygon(0x80);
  E->base.current_instruction = v1;
  E->base.instruction_timer = 1;
  Get_Draygon(0)->draygon_var_A = FUNC16(Draygon_Func_28);
}

void Draygon_Func_28(uint16 k) {  // 0xA59124
  Draygon_Func_40(k);
}

void Draygon_Func_29(void) {  // 0xA59128
  Samus_ReleaseFromDraygon_();
  samus_grapple_flags = 0;
  Enemy_Draygon *E = Get_Draygon(0);
  E->draygon_var_A = FUNC16(Draygon_Func_30);
  E->base.properties &= ~kEnemyProps_Tangible;
  uint16 v1 = addr_kDraygon_Ilist_9B5A;
  if (E->draygon_var_20)
    v1 = addr_kDraygon_Ilist_9F15;
  Enemy_Draygon *E2 = Get_Draygon(0x80);
  E2->base.current_instruction = v1;
  E2->base.instruction_timer = 1;
}

void Draygon_Func_30(void) {  // 0xA59154
  int16 v1;

  Draygon_Func_3();
  Enemy_Draygon *E = Get_Draygon(0);
  v1 = E->base.y_pos - 4;
  E->base.y_pos = v1;
  if (v1 < 0) {
    E->base.properties &= ~kEnemyProps_Tangible;
    E->draygon_var_A = FUNC16(Draygon_Func_4);
    E->draygon_var_B = 0;
    E->base.x_pos = E->draygon_var_00;
    E->base.y_pos = E->draygon_var_01;
  }
}

void Draygon_Func_31(void) {  // 0xA59185
  Enemy_Draygon *E = Get_Draygon(0);
  if ((Get_Draygon(cur_enemy_index)->base.frame_counter & 0xF) == 0) {
    uint16 x = E->draygon_var_20 ? E->base.x_pos + 32 : E->base.x_pos - 32;
    uint16 y = E->base.y_pos - 16;
    CreateSpriteAtPos(x, y, 61, 0);
  }
  E->draygon_var_43 = (uint8)(64 - CalculateAngleFromXY(64 - (E->base.x_pos >> 2), 120 - (E->base.y_pos >> 2)));
  Point32 pt = ConvertAngleToXy(LOBYTE(E->draygon_var_43), 1);
  MoveEnemyByAngleAndXYSpeed(LOBYTE(E->draygon_var_43), pt);
  uint16 v3 = Abs16(E->base.x_pos - 256);
  if (sign16(v3 - 4)) {
    uint16 v4 = Abs16(E->base.y_pos - 480);
    if (sign16(v4 - 4)) {
      Draygon_Func_43();
      E->draygon_var_A = FUNC16(Draygon_Func_32);
      QueueMusic_Delayed8(kMusic_Elevator);
      E->draygon_var_B = 416;
      E->base.current_instruction = addr_kDraygon_Ilist_97B9;
      E->base.instruction_timer = 1;
      uint16 v5 = E->base.properties | kEnemyProps_Deleted;
      Get_Draygon(0x80)->base.properties = v5;
      Get_Draygon(0xC0)->base.properties = v5;
      uint16 v6 = addr_kDraygon_Ilist_999C;
      if (E->draygon_var_20)
        v6 = addr_kDraygon_Ilist_9D3E;
      Enemy_Draygon *E1 = Get_Draygon(0x40);
      E1->base.current_instruction = v6;
      E1->base.instruction_timer = 1;
      E1->draygon_var_A = FUNC16(nullsub_169_A5);
    }
  }
}

void Draygon_Func_32(void) {  // 0xA59294
  Draygon_Func_34();
  Enemy_Draygon *E = Get_Draygon(0);
  if (--E->draygon_var_B)
    Draygon_Func_42(0);
  else
    E->draygon_var_A = FUNC16(Draygon_Func_33);
}

void Draygon_Func_33(void) {  // 0xA592AB
  Draygon_Func_34();
  Draygon_Func_42(0); // What is varE24 ?
  Enemy_Draygon *E = Get_Draygon(0);
  if (!sign16(++E->base.y_pos - 576)) {
    E->base.current_instruction = addr_kDraygon_Ilist_98ED;
    E->base.instruction_timer = 1;
    uint16 v1 = E->base.properties | kEnemyProps_Deleted;
    E->base.properties = v1;
    Get_Draygon(0x40)->base.properties = v1;
    uint16 v2 = area_index;
    *(uint16 *)&boss_bits_for_area[area_index] |= kBossBit_AreaBoss;
    Enemy_ItemDrop_Draygon(v2);
    Draygon_Func_44();
  }
}

void Draygon_Func_34(void) {  // 0xA592EA
  if ((nmi_frame_counter_word & 7) == 0) {
    uint16 x = (NextRandom() & 0x7F) + 192;
    uint16 y = ((uint16)(random_number & 0x3F00) >> 8) + 400;
    CreateSpriteAtPos(x, y, 21, 0);
  }
}

void Draygon_Func_35(void) {  // 0xA5931C
  Enemy_Draygon *Draygon = Get_Draygon(cur_enemy_index);
  if ((Draygon->base.frame_counter & 0x7F) == 0) {
    Draygon = Get_Draygon(0);
    CreateSpriteAtPos(Draygon->base.x_pos - 16, Draygon->base.y_pos - 16, 24, 0);
  }
}

void Draygon_Func_36(void) {  // 0xA59342
  Enemy_Draygon *E = Get_Draygon(0);
  reg_BG2HOFS = E->draygon_var_5E + layer1_x_pos - E->base.x_pos - 450;
  reg_BG2VOFS = E->draygon_var_5F + layer1_y_pos - E->base.y_pos - 192;
}

void Draygon_Func_37(void) {  // 0xA59367
  Enemy_Draygon *E = Get_Draygon(0);
  if ((joypad2_last & 0x40) != 0)
    Draygon_Func_39();
  else
    Draygon_Func_38();
  if ((joypad2_new_keys & 0x4000) != 0) {
    uint16 v0 = addr_kDraygon_Ilist_98FE;
    if (E->draygon_var_20)
      v0 = addr_kDraygon_Ilist_9C90;
    E->base.current_instruction = v0;
    E->base.instruction_timer = 1;
  } else if ((joypad2_new_keys & 0x8000) == 0) {
    if ((joypad2_new_keys & 0x80) != 0) {
      uint16 v4 = addr_kDraygon_Ilist_9825;
      if (E->draygon_var_20)
        v4 = addr_kDraygon_Ilist_9C18;
      Enemy_Draygon *E3 = Get_Draygon(0xC0);
      E3->base.current_instruction = v4;
      E3->base.instruction_timer = 1;
    }
  } else {
    uint16 v2 = addr_kDraygon_Ilist_99FC;
    if (E->draygon_var_20)
      v2 = addr_kDraygon_Ilist_9D9E;
    Enemy_Draygon *E2 = Get_Draygon(0x80);
    E2->base.current_instruction = v2;
    E2->base.instruction_timer = 1;
  }
}

void Draygon_Func_38(void) {  // 0xA593DA
  Enemy_Draygon *E = Get_Draygon(0);
  uint16 v0 = joypad2_last, v2;
  if ((joypad2_last & 0x200) == 0 || (--E->base.x_pos, v0 == debug_enemy_population_pointer)) {
    if ((v0 & 0x100) == 0)
      goto LABEL_8;
    ++E->base.x_pos;
    if (v0 == debug_enemy_population_pointer)
      goto LABEL_8;
    debug_enemy_population_pointer = v0;
    v2 = addr_kDraygon_Ilist_97D1;
    E->draygon_var_20 = 1;
  } else {
    debug_enemy_population_pointer = v0;
    v2 = addr_kDraygon_Ilist_97BB;
    E->draygon_var_20 = 0;
  }
  E->base.current_instruction = v2;
  E->base.instruction_timer = 1;
LABEL_8:
  if ((joypad2_last & 0x800) != 0) {
    --E->base.y_pos;
  } else if ((joypad2_last & 0x400) != 0) {
    ++E->base.y_pos;
  }
}

void Draygon_Func_39(void) {  // 0xA59430
  Enemy_Draygon *E = Get_Draygon(0);
  uint16 v0 = joypad2_last, v2;
  if ((joypad2_last & 0x200) == 0
      || (E->base.x_pos -= 4, v0 = joypad2_last, joypad2_last == debug_enemy_population_pointer)) {
    if ((v0 & 0x100) == 0)
      goto LABEL_8;
    E->base.x_pos += 4;
    if (joypad2_last == debug_enemy_population_pointer)
      goto LABEL_8;
    debug_enemy_population_pointer = joypad2_last;
    v2 = addr_kDraygon_Ilist_97D1;
    E->draygon_var_20 = 1;
  } else {
    debug_enemy_population_pointer = joypad2_last;
    v2 = addr_kDraygon_Ilist_97BB;
    E->draygon_var_20 = 0;
  }
  E->base.current_instruction = v2;
  E->base.instruction_timer = 1;
LABEL_8:
  if ((joypad2_last & 0x800) != 0) {
    E->base.y_pos -= 4;
  } else if ((joypad2_last & 0x400) != 0) {
    ++E->base.y_pos;
    E->base.y_pos += 4;
  }
}

void Draygon_Func_40(uint16 k) {  // 0xA594A9
  int16 v1;

  v1 = 8;
  if (!Get_Draygon(k)->draygon_var_20)
    v1 = -8;
  Enemy_Draygon *E = Get_Draygon(0);
  samus_x_pos = E->base.x_pos + v1;
  samus_y_pos = E->base.y_pos + 40;
  EnemyFunc_B7A1();
  if ((samus_grapple_flags & 2) != 0) {
    samus_grapple_flags = 0;
    E->draygon_var_A = FUNC16(Draygon_Func_30);
  }
}

const uint16 *Draygon_Instr_1(uint16 k, const uint16 *jp) {  // 0xA594DD
  Get_Draygon(0)->base.current_instruction = jp[0];
  Get_Draygon(0x40)->base.current_instruction = jp[1];
  Get_Draygon(0x80)->base.current_instruction = jp[2];
  Get_Draygon(0xC0)->base.current_instruction = jp[3];
  Get_Draygon(0)->base.instruction_timer = 1;
  Get_Draygon(0x40)->base.instruction_timer = 1;
  Get_Draygon(0x80)->base.instruction_timer = 1;
  Get_Draygon(0xC0)->base.instruction_timer = 1;
  return jp + 4;
}

void Draygon_Hurt(void) {  // 0xA5954D
  uint16 v0 = addr_kDraygon_MorePalettes2;
  if ((Get_Draygon(cur_enemy_index)->base.flash_timer & 2) != 0)
    v0 = addr_word_A5A297;
  memcpy(g_ram + addr_kDraygon_BigSprmap_C08F + 17, RomPtr_A5(v0), 32);

  if ((Get_Draygon(cur_enemy_index)->base.flash_timer & 2) == 0) {
    uint16 v3 = 4 * Get_Draygon(0)->draygon_var_0E;
    for (int i = 0; i != 8; i += 2) {
      palette_buffer[(i >> 1) + 89] = kDraygon_HealthPaletteTable[v3 >> 1];
      v3 += 2;
    }
  }
  uint16 v5 = addr_kDraygon_Palette;
  if ((Get_Draygon(cur_enemy_index)->base.flash_timer & 2) != 0)
    v5 = addr_word_A5A297;
  memcpy(g_ram + addr_kDraygon_BigSprmap_C11B + 197, RomPtr_A5(v5), 32);

  if ((samus_grapple_flags & 1) != 0) {
    Enemy_Draygon *E = Get_Draygon(0);
    if ((E->base.frame_counter & 7) == 0) {
      int16 v9 = E->base.health - 256;
      if (v9 < 0)
        v9 = 0;
      E->base.health = v9;
      sub_A5960D();
    }
  }
}

void Draygon_Touch(void) {  // 0xA595EA
  NormalEnemyTouchAiSkipDeathAnim_CurEnemy();
  sub_A5960D();
}

void Draygon_Shot(void) {  // 0xA595F0
  Enemy_Draygon *E = Get_Draygon(0);
  if (sign16(E->draygon_var_0F - 152))
    E->draygon_var_0F += 8;
  NormalEnemyShotAiSkipDeathAnim_CurEnemy();
  sub_A5960D();
}

void Draygon_Powerbomb(void) {  // 0xA59607
  NormalEnemyPowerBombAiSkipDeathAnim_CurEnemy();
  sub_A5960D();
}

void sub_A5960D(void) {  // 0xA5960D
  if (Get_Draygon(cur_enemy_index)->base.health) {
    Draygon_Func_41();
  } else {
    grapple_beam_function = FUNC16(GrappleBeam_Func2);
    uint16 v0 = addr_kDraygon_Ilist_9867;
    Enemy_Draygon *E = Get_Draygon(0);
    if (E->draygon_var_20)
      v0 = addr_kDraygon_Ilist_9C5A;
    E->base.current_instruction = v0;
    E->base.instruction_timer = 1;
    uint16 v3 = addr_kDraygon_Ilist_997A;
    if (E->draygon_var_20)
      v3 = addr_kDraygon_Ilist_9D1C;
    Enemy_Draygon *E1 = Get_Draygon(0x40);
    E1->base.current_instruction = v3;
    E1->base.instruction_timer = 1;
    E1->draygon_var_A = FUNC16(nullsub_169_A5);
    E->draygon_var_A = FUNC16(Draygon_Func_31);
    Samus_ReleaseFromDraygon_();
    samus_grapple_flags = 0;
    E->draygon_var_43 = (uint8)(64 - CalculateAngleFromXY(256 - E->base.x_pos, 480 - E->base.y_pos));
    Point32 pt = ConvertAngleToXy(LOBYTE(E->draygon_var_43), 1);
    E->draygon_var_28 = pt.x >> 16;
    E->draygon_var_29 = pt.x;
    E->draygon_var_2A = pt.y >> 16;
    E->draygon_var_2B = pt.y;
  }
}

void Draygon_Func_41(void) {  // 0xA59701
  int i;
  uint16 j;
  Enemy_Draygon *E = Get_Draygon(0);
  for (i = 0; ; i += 2) {
    if ((int16)(E->base.health - kDraygon_HealthPaletteThreshold[i >> 1]) >= 0)
      break;
  }
  if (i != E->draygon_var_0E) {
    E->draygon_var_0E = i;
    uint16 v2 = 4 * E->draygon_var_0E;
    for (j = 0; j != 8; j += 2) {
      palette_buffer[(j >> 1) + 89] = kDraygon_HealthPaletteTable[v2 >> 1];
      v2 += 2;
    }
  }
}

const uint16 *Draygon_Instr_13(uint16 k, const uint16 *jp) {  // 0xA59736
  Get_Draygon(k)->draygon_var_A = jp[0];
  return jp + 1;
}

static Point16U Draygon_Func_47(void) {  // 0xA5978B
  NextRandom();
  Enemy_Draygon *E = Get_Draygon(0);
  uint16 r18 = (random_number & 0x7F) - 64;
  uint16 r20 = ((random_number & 0x7F00) >> 8) - 64;
  return (Point16U) {r18 + E->base.x_pos, r20 + E->base.y_pos};
}

const uint16 *Draygon_Instr_8(uint16 k, const uint16 *jp) {  // 0xA5973F
  Point16U pt = Draygon_Func_47();
  CreateSpriteAtPos(pt.x, pt.y, 21, 0);
  return jp;
}

const uint16 *Draygon_Instr_7(uint16 k, const uint16 *jp) {  // 0xA59752
  Point16U pt = Draygon_Func_47();
  CreateSpriteAtPos(pt.x, pt.y, 3, 0);
  return jp;
}

const uint16 *Draygon_Instr_6(uint16 k, const uint16 *jp) {  // 0xA59765
  Point16U pt = Draygon_Func_47();
  CreateSpriteAtPos(pt.x, pt.y, 29, 0);
  return jp;
}

const uint16 *Draygon_Instr_9(uint16 k, const uint16 *jp) {  // 0xA59778
  Point16U pt = Draygon_Func_47();
  CreateSpriteAtPos(pt.x, pt.y, 24, 0);
  return jp;
}

const uint16 *Draygon_Instr_2(uint16 k, const uint16 *jp) {  // 0xA59895
  room_loading_irq_handler = 12;
  return jp;
}

const uint16 *Draygon_Instr_11(uint16 k, const uint16 *jp) {  // 0xA598D3
  Enemy_Draygon *E2 = Get_Draygon(0x80);
  E2->base.instruction_timer = 1;
  E2->base.current_instruction = addr_kDraygon_Ilist_97B9;

  Enemy_Draygon *E3 = Get_Draygon(0xC0);
  E3->base.instruction_timer = 1;
  E3->base.current_instruction = addr_kDraygon_Ilist_97B9;
  return jp;
}

const uint16 *Draygon_Instr_5(uint16 k, const uint16 *jp) {  // 0xA598EF
  Enemy_Draygon *E = Get_Draygon(0);
  E->base.properties |= kEnemyProps_Tangible;
  return jp;
}

const uint16 *Draygon_Instr_15(uint16 k, const uint16 *jp) {  // 0xA59B9A
  Enemy_Draygon *E = Get_Draygon(0);
  E->draygon_var_0F = 24;
  const uint8 *v3 = RomPtr_A0(E->base.enemy_ptr);
  Samus_DealDamage(SuitDamageDivision(GET_WORD(v3 + 6)));
  earthquake_timer = 32;
  earthquake_type = 7;
  CreateSpriteAtPos(samus_x_pos, samus_y_pos + 16, 21, 0);
  return jp;
}

const uint16 *Draygon_Instr_17(uint16 k, const uint16 *jp) {  // 0xA59C8A
  room_loading_irq_handler = 12;
  return jp;
}

const uint16 *Draygon_Instr_14(uint16 k, const uint16 *jp) {  // 0xA59E0A
  Enemy_Draygon *E = Get_Draygon(0);
  E->draygon_var_5E = jp[0];
  E->draygon_var_5F = jp[1];
  return jp + 2;
}

const uint16 *Draygon_Instr_16(uint16 k, const uint16 *jp) {  // 0xA59F57
  Get_Draygon(0)->draygon_var_A = jp[0];
  return jp + 1;
}

const uint16 *Draygon_Instr_10(uint16 k, const uint16 *jp) {  // 0xA59F60
  QueueSfx2_Max6(jp[0]);
  return jp + 1;
}

const uint16 *Draygon_Instr_4(uint16 k, const uint16 *jp) {  // 0xA59F6E
  QueueSfx3_Max6(jp[0]);
  return jp + 1;
}

const uint16 *Draygon_Instr_12(uint16 k, const uint16 *jp) {  // 0xA59F7C
  Enemy_Draygon *E = Get_Draygon(0);
  eproj_spawn_pt = (Point16U){ E->base.x_pos - 28, E->base.y_pos - 16 };
  eproj_init_param_1 = (NextRandom() & 0x3F) + 128;
  SpawnEprojWithGfx(2, cur_enemy_index, addr_kEproj_DraygonGoop);
  return jp;
}

const uint16 *Draygon_Instr_18(uint16 k, const uint16 *jp) {  // 0xA59FAE
  Enemy_Draygon *E = Get_Draygon(0);
  eproj_spawn_pt = (Point16U){ E->base.x_pos + 24, E->base.y_pos - 16 };
  eproj_init_param_1 = (NextRandom() & 0x3F) + 192;
  SpawnEprojWithGfx(2, cur_enemy_index, addr_kEproj_DraygonGoop);
  return jp;
}

void Draygon_Func_42(uint16 varE24) {  // 0xA59FE0
  uint16 v0 = 62;
  for (int i = 20; i >= 0; i -= 4) {
    int v2 = i >> 1;
    int v3 = v0 >> 1;
    if (((kMiniDraygon_DeathSequenceAngles[v2] + 64) & 0x80) != 0)
      AddToHiLo(&sprite_x_pos[v3], &sprite_x_subpos[v3], kMiniDraygon_DeathSequenceSubspeeds[v2]);
    else
      AddToHiLo(&sprite_x_pos[v3], &sprite_x_subpos[v3], -kMiniDraygon_DeathSequenceSubspeeds[v2] - (varE24 << 16));
    uint16 v8 = sprite_y_subpos[v3];
    if (((kMiniDraygon_DeathSequenceAngles[v2] + 128) & 0x80) != 0)
      AddToHiLo(&sprite_y_pos[v3], &sprite_y_subpos[v3], kMiniDraygon_DeathSequenceSubspeeds[v2 + 1]);
    else
      AddToHiLo(&sprite_y_pos[v3], &sprite_y_subpos[v3], -kMiniDraygon_DeathSequenceSubspeeds[v2 + 1]);
    v0 -= 2;
  }
}

void Draygon_Func_43(void) {  // 0xA5A06C
  int16 v1;
  int16 j;

  for (int i = 62; i >= 0; i -= 2)
    sprite_instr_list_ptrs[i >> 1] = 0;
  v1 = 2;
  uint16 v2 = 20;
  do {
    int v3 = v2 >> 1;
    CreateSpriteAtPos(kMiniDraygon_DeathSequenceSpawnPositions[v3], kMiniDraygon_DeathSequenceSpawnPositions[v3 + 1], 59, 0xe00);
    v2 -= 4;
  } while (--v1 >= 0);
  for (j = 2; j >= 0; --j) {
    int v5 = v2 >> 1;
    CreateSpriteAtPos(kMiniDraygon_DeathSequenceSpawnPositions[v5], kMiniDraygon_DeathSequenceSpawnPositions[v5 + 1], 60, 0xe00);
    v2 -= 4;
  }
}

void Draygon_Func_44(void) {  // 0xA5A0C6
  for (int i = 62; i >= 0; i -= 2)
    sprite_instr_list_ptrs[i >> 1] = 0;
}

void Draygon_Func_45(void) {  // 0xA5A0D9
  CreateSpriteAtPos(16, 384, 59, 0xe00);
  CreateSpriteAtPos(16, 384, 59, 0xe00);
  CreateSpriteAtPos(16, 384, 59, 0xe00);
  CreateSpriteAtPos(16, 384, 59, 0xe00);
}

void Draygon_Func_46(void) {  // 0xA5A13E
  uint16 v0 = 62;
  do {
    uint16 v1 = Get_Draygon(0)->draygon_var_46 + kMiniDraygon_MovementLatency[(uint16)(v0 - 56) >> 1];
    if ((v1 & 0x8000) == 0) {
      uint16 v2 = v1;
      if (*(uint16 *)&kMiniDraygonIntroDanceTable[v1] == 0x8080) {
        sprite_instr_list_ptrs[v0 >> 1] = 0;
      } else {
        int v3 = v0 >> 1;
        sprite_x_pos[v3] += SignExtend8(kMiniDraygonIntroDanceTable[v1]);
        sprite_y_pos[v3] += SignExtend8(kMiniDraygonIntroDanceTable[v2 + 1]);
      }
    }
    v0 -= 2;
  } while ((int16)(v0 - 56) >= 0);
  Enemy_Draygon *E = Get_Draygon(0);
  E->draygon_var_46 += 4;
}

void DraygonsEye_Init(void) {  // 0xA5C46B
  Enemy_Draygon *E = Get_Draygon(cur_enemy_index);
  E->base.current_instruction = addr_kDraygon_Ilist_9944;
  E->draygon_var_A = FUNC16(nullsub_169_A5);
}

const uint16 *Draygon_Instr_3(uint16 k, const uint16 *jp) {  // 0xA5C47B
  Get_Draygon(0x40)->draygon_var_A = jp[0];
  return jp + 1;
}

void DraygonsEye_Main(void) {  // 0xA5C486
  Enemy_Draygon *E = Get_Draygon(cur_enemy_index);
  CallDraygonFunc(E->draygon_var_A | 0xA50000, cur_enemy_index);
}

void Draygon_Func_48(uint16 k) {  // 0xA5C48D
  if ((Get_Draygon(k)->base.frame_counter & 0x7F) == 0) {
    Enemy_Draygon *E1 = Get_Draygon(0x40);
    eproj_spawn_pt = (Point16U){ E1->base.x_pos - 24, E1->base.y_pos - 32 };
    SpawnEprojWithRoomGfx(addr_kEproj_DustCloudExplosion, 0x18);
  }
  Enemy_Draygon *E0 = Get_Draygon(0);
  uint16 v4 = CalculateAngleFromXY(samus_x_pos - (E0->base.x_pos - 24), samus_y_pos - (E0->base.y_pos - 32));
  Enemy_Draygon *E = Get_Draygon(cur_enemy_index);
  if (v4 != E->draygon_var_F) {
    uint16 v6 = addr_kDraygon_Ilist_99BA;
    if (!sign16(v4 - 32)) {
      v6 = addr_kDraygon_Ilist_99B4;
      if (!sign16(v4 - 96)) {
        v6 = addr_kDraygon_Ilist_99C0;
        if (!sign16(v4 - 160)) {
          v6 = addr_kDraygon_Ilist_99AE;
          if (!sign16(v4 - 224))
            v6 = addr_kDraygon_Ilist_99BA;
        }
      }
    }
    E->draygon_var_F = v4;
    E->base.current_instruction = v6;
    E->base.instruction_timer = 1;
    E->base.timer = 0;
  }
}

void Draygon_Func_49(uint16 k) {  // 0xA5C513
  Enemy_Draygon *E0 = Get_Draygon(0);

  if ((Get_Draygon(k)->base.frame_counter & 0x7F) == 0) {
    eproj_spawn_pt = (Point16U){ E0->base.x_pos + 24, E0->base.y_pos - 32 };
    SpawnEprojWithRoomGfx(addr_kEproj_DustCloudExplosion, 0x18);
  }

  uint16 v4 = CalculateAngleFromXY(samus_x_pos - (E0->base.x_pos + 24), samus_y_pos - (E0->base.y_pos - 32));
  Enemy_Draygon *E = Get_Draygon(cur_enemy_index);
  if (v4 != E->draygon_var_F) {
    uint16 v6 = addr_kDraygon_Ilist_9D5C;
    if (!sign16(v4 - 32)) {
      v6 = addr_kDraygon_Ilist_9D50;
      if (!sign16(v4 - 96)) {
        v6 = addr_kDraygon_Ilist_9D62;
        if (!sign16(v4 - 160)) {
          v6 = addr_kDraygon_Ilist_9D56;
          if (!sign16(v4 - 224))
            v6 = addr_kDraygon_Ilist_9D5C;
        }
      }
    }
    E->draygon_var_F = v4;
    E->base.current_instruction = v6;
    E->base.instruction_timer = 1;
    E->base.timer = 0;
  }
}

void DraygonsTail_Init(void) {  // 0xA5C599
  EnemyData *v0 = gEnemyData(cur_enemy_index);
  v0->current_instruction = addr_kDraygon_Ilist_99FC;
  v0->palette_index = 0xe00;
}

void DraygonsArms_Init(void) {  // 0xA5C5AD
  EnemyData *v0 = gEnemyData(cur_enemy_index);
  v0->current_instruction = addr_kDraygon_Ilist_97E7;
  v0->palette_index = 0xe00;
  v0->layer = 2;
}

const uint16 *Draygon_Instr_25(uint16 k, const uint16 *jp) {  // 0xA5E75F
  Enemy_Draygon *E = Get_Draygon(0);
  if (sign16(E->draygon_var_0B - 40))
    E->draygon_var_0B += 8;
  return jp;
}

const uint16 *Draygon_Instr_24(uint16 k, const uint16 *jp) {  // 0xA5E771
  Get_Draygon(0)->draygon_var_2F = 0;
  return jp;
}

void Draygon_Func_50(uint16 j) {  // 0xA5E811
  const uint8 *v1 = RomPtr_A5(j);
  Enemy_Draygon *E = Get_Draygon(0);
  E->draygon_var_0B = GET_WORD(v1);
  E->draygon_var_0C = GET_WORD(v1 + 2);
  E->draygon_var_0A = GET_WORD(v1 + 4);
}

const uint16 *Draygon_Instr_21(uint16 k, const uint16 *jp) {  // 0xA5E82D
  Enemy_Draygon *E = Get_Draygon(0);
  E->draygon_var_0B = jp[0];
  E->draygon_var_0C = jp[1];
  return jp + 2;
}

void Draygon_Func_51(uint16 j) {  // 0xA5E840
  uint16 v1 = *(uint16 *)RomPtr_A5(j);
  Get_Draygon(0)->draygon_var_0B = v1;
}

void Draygon_Func_52(uint16 j) {  // 0xA5E84A
  uint16 v1 = *(uint16 *)RomPtr_A5(j);
  Get_Draygon(0)->draygon_var_0C = v1;
}

uint16 Draygon_Instr_53(uint16 k, uint16 j) {  // 0xA5E854
  Enemy_Draygon *E = Get_Draygon(0);
  E->draygon_var_0B += *(uint16 *)RomPtr_A5(j);
  return j + 2;
}

const uint16 *Draygon_Instr_22(uint16 k, const uint16 *jp) {  // 0xA5E872
  kraid_unk9000 = jp[0];
  return jp + 1;
}

const uint16 *Draygon_Instr_27(uint16 k, const uint16 *jp) {  // 0xA5E87C
  Enemy_Draygon *E = Get_Draygon(0);
  E->base.x_pos = 128;
  E->base.y_pos = 624;
  E->base.properties = E->base.properties & 0x5BFF | 0xA000;
  return jp;
}

const uint16 *Draygon_Instr_23(uint16 k, const uint16 *jp) {  // 0xA5E895
  QueueSfx2_Max6(jp[0]);
  return jp + 1;
}

const uint16 *Draygon_Instr_30(uint16 k, const uint16 *jp) {  // 0xA5E8B1
  Enemy_ItemDrop_SporeSpawn(k);
  return jp;
}

const uint16 *Draygon_Instr_20(uint16 k, const uint16 *jp) {  // 0xA5E8BA
  Get_Draygon(cur_enemy_index)->draygon_var_A = jp[0];
  return jp + 1;
}

const uint16 *Draygon_Instr_29(uint16 k, const uint16 *jp) {  // 0xA5E8CA
  uint16 v2 = jp[0];
  for (int i = 0; i != 32; i += 2)
    palette_buffer[(i >> 1) + 144] = kSporeSpawn_DeathSequencePalette1[(v2 + i) >> 1];
  for (int i = 0; i != 32; i += 2)
    palette_buffer[(i >> 1) + 64] = kSporeSpawn_DeathSequnceBg1AndBg2Palette4[(v2 + i) >> 1];
  for (int i = 0; i != 32; i += 2)
    palette_buffer[(i >> 1) + 112] = kSporeSpawn_DeathSequenceBg1AndBg2Palette7[(v2 + i) >> 1];
  return jp + 1;
}

const uint16 *Draygon_Instr_19(uint16 k, const uint16 *jp) {  // 0xA5E91C
  uint16 v2 = jp[0];
  for (int i = 0; i != 32; i += 2)
    target_palettes[(i >> 1) + 144] = kSporeSpawn_DeathSequencePalette1[(v2 + i) >> 1];
  for (int i = 0; i != 32; i += 2)
    target_palettes[(i >> 1) + 64] = kSporeSpawn_DeathSequnceBg1AndBg2Palette4[(v2 + i) >> 1];
  for (int i = 0; i != 32; i += 2)
    target_palettes[(i >> 1) + 112] = kSporeSpawn_DeathSequenceBg1AndBg2Palette7[(v2 + i) >> 1];
  return jp + 1;
}

const uint16 *Draygon_Instr_28(uint16 k, const uint16 *jp) {  // 0xA5E96E
  NextRandom();
  uint16 r18 = (random_number & 0x7F) - 64;
  Enemy_Draygon *E = Get_Draygon(0);
  r18 += E->base.x_pos;
  uint16 r20 = ((uint16)(random_number & 0x7F00) >> 8) - 64;
  r20 += E->base.y_pos;
  eproj_spawn_pt = (Point16U){ r18, r20 };
  SpawnEprojWithRoomGfx(0xE509, 0x15);
  QueueSfx2_Max6(kSfx2_MotherBrainRisingIntoPhase2_CrocomiresWallExplodes_SporeSpawnGetsHard);
  return jp;
}

const uint16 *Draygon_Instr_26(uint16 k, const uint16 *jp) {  // 0xA5E9B1
  NextRandom();
  Enemy_Draygon *E = Get_Draygon(0);
  uint16 x = E->base.x_pos + (random_number & 0x7F) - 64;
  uint16 y = E->base.y_pos + ((uint16)(random_number & 0x3F00) >> 8) - 32;
  CreateSpriteAtPos(x, y, 3, 0);
  QueueSfx2_Max6(kSfx2_BigExplosion);
  return jp;
}

void sub_A5E9F5(void) {  // 0xA5E9F5
  if ((nmi_frame_counter_word & 0xF) == 0) {
    NextRandom();
    uint16 x = (random_number & 0x3F) + 96;
    uint16 y = ((uint16)(random_number & 0xF00) >> 8) + 480;
    CreateSpriteAtPos(x, y, 21, 0);
  }
}

void SporeSpawn_Init(void) {  // 0xA5EA2A
  uint16 v0 = 0;
  for (int i = 0; i != 32; i += 2) {
    target_palettes[(i >> 1) + 240] = kSporeSpawn_Palette7[v0 >> 1];
    v0 += 2;
  }
  SpawnEprojWithGfx(0, cur_enemy_index, addr_kEproj_SporeSpawnsStalk);
  SpawnEprojWithGfx(1, cur_enemy_index, addr_kEproj_SporeSpawnsStalk);
  SpawnEprojWithGfx(2, cur_enemy_index, addr_kEproj_SporeSpawnsStalk);
  SpawnEprojWithGfx(3, cur_enemy_index, addr_kEproj_SporeSpawnsStalk);
  Enemy_SporeSpawn *E = Get_SporeSpawn(cur_enemy_index);
  Enemy_SporeSpawn *E0 = Get_SporeSpawn(0);
  E->ssn_var_04 = E->base.x_pos;
  E->ssn_var_05 = E->base.y_pos - 72;
  E->ssn_var_C = E->base.x_pos;
  E->ssn_var_D = E->base.y_pos;
  E->ssn_var_F = 0;
  if ((boss_bits_for_area[area_index] & kBossBit_AreaMiniBoss) != 0) {
    E0->base.current_instruction = addr_kDraygon_Ilist_E6B9;
    E0->ssn_var_A = FUNC16(nullsub_223);
    E0->base.properties |= 0x8000;
    SporeSpawn_Func_5();
    SpawnHardcodedPlm((SpawnHardcodedPlmArgs) { 0x07, 0x1e, 0xb793 });
    scrolling_finished_hook = 0;
  } else {
    E0->base.current_instruction = addr_kDraygon_Ilist_E6C7;
    flag_process_all_enemies = -1;
    uint16 v5 = cur_enemy_index;
    E->ssn_var_A = FUNC16(nullsub_223);
    scrolling_finished_hook = FUNC16(Samus_ScrollFinishedHook_SporeSpawnFight);
    E->base.y_pos -= 128;
    SpawnEprojWithGfx(0, v5, addr_kEproj_SporeSpawners);
    SpawnEprojWithGfx(1, v5, addr_kEproj_SporeSpawners);
    SpawnEprojWithGfx(2, v5, addr_kEproj_SporeSpawners);
    SpawnEprojWithGfx(3, v5, addr_kEproj_SporeSpawners);
    SporeSpawn_Func_5();
  }
}

void CallSporeSpawnFunc(uint32 ea) {
  switch (ea) {
  case fnnullsub_223: return;
  case fnSporeSpawn_Func_1: SporeSpawn_Func_1(); return;
  case fnSporeSpawn_Func_2: SporeSpawn_Func_2(cur_enemy_index); return;
  case fnSporeSpawn_Func_3: SporeSpawn_Func_3(); return;
  case fnSporeSpawn_Func_4: SporeSpawn_Func_4(); return;
  default: Unreachable();
  }
}

void SporeSpawn_Main(void) {  // 0xA5EB13
  Enemy_SporeSpawn *E = Get_SporeSpawn(cur_enemy_index);
  CallSporeSpawnFunc(E->ssn_var_A | 0xA50000);
}

void SporeSpawn_Func_1(void) {  // 0xA5EB1B
  SporeSpawn_Func_5();
  Enemy_SporeSpawn *E = Get_SporeSpawn(cur_enemy_index);
  uint16 v1 = E->base.y_pos + 1;
  E->base.y_pos = v1;
  if (!sign16(v1 - 624)) {
    E->base.current_instruction = addr_kDraygon_Ilist_E6D5;
    E->base.instruction_timer = 1;
  }
  Enemy_SporeSpawn *E0 = Get_SporeSpawn(0);
  E0->ssn_var_0B = 48;
  E0->ssn_var_0C = 1;
  E0->ssn_var_0A = 192;
}

void SporeSpawn_Func_2(uint16 k) {  // 0xA5EB52
  SporeSpawn_Func_5();
  Enemy_SporeSpawn *E0 = Get_SporeSpawn(0);
  Enemy_SporeSpawn *E = Get_SporeSpawn(k);
  E->base.x_pos = E->ssn_var_C + CosineMult8bit(E0->ssn_var_0A, E0->ssn_var_0B);
  E->base.y_pos = E->ssn_var_D + SineMult8bit(2 * (E0->ssn_var_0A - 64), E0->ssn_var_0B - 16);
  E0->ssn_var_0A = (uint8)(LOBYTE(E0->ssn_var_0C) + E0->ssn_var_0A);
}

void SporeSpawn_Func_3(void) {  // 0xA5EB9B
  Enemy_SporeSpawn *E0 = Get_SporeSpawn(0);
  E0->ssn_var_43 = (uint8)(64 - CalculateAngleFromXY(128 - E0->base.x_pos, 624 - E0->base.y_pos));
  Enemy_SporeSpawn *E = Get_SporeSpawn(cur_enemy_index);
  Point32 pt = ConvertAngleToXy(LOBYTE(E0->ssn_var_43), 1);
  E->ssn_var_28 = pt.x >> 16;
  E->ssn_var_29 = pt.x;
  E->ssn_var_2A = pt.y >> 16;
  E->ssn_var_2B = pt.y;
}

void SporeSpawn_Func_4(void) {  // 0xA5EBEE
  Enemy_SporeSpawn *E = Get_SporeSpawn(cur_enemy_index);
  Enemy_SporeSpawn *E0 = Get_SporeSpawn(0);
  uint16 varE20 = LOBYTE(E0->ssn_var_43);
  MoveEnemyByAngleAndXYSpeed(varE20, (Point32) { __PAIR32__(E->ssn_var_28, E->ssn_var_29), __PAIR32__(E->ssn_var_2A, E->ssn_var_2B) });
  uint16 v2 = Abs16(E0->base.x_pos - 128);
  if (sign16(v2 - 8)) {
    uint16 v3 = Abs16(E0->base.y_pos - 624);
    if (sign16(v3 - 8))
      E0->ssn_var_A = FUNC16(nullsub_223);
  }
  SporeSpawn_Func_5();
  sub_A5E9F5();
}

void SporeSpawn_Func_5(void) {  // 0xA5EC49
  Enemy_SporeSpawn *E = Get_SporeSpawn(0);
  uint16 v1 = E->base.x_pos - E->ssn_var_04, v2;
  uint16 r18, r20, r22;
  if ((v1 & 0x8000) == 0) {
    r18 = v1 >> 1, r20 = v1 >> 2;
    r22 = (v1 >> 1) + (v1 >> 2);
    eproj_x_pos[14] = 128;
    eproj_x_pos[15] = E->ssn_var_04 + (v1 >> 2);
    E->ssn_var_20 = eproj_x_pos[15];
    eproj_x_pos[16] = E->ssn_var_04 + r18;
    E->ssn_var_21 = eproj_x_pos[16];
    v2 = E->ssn_var_04 + r22;
  } else {
    r18 = (uint16)(E->ssn_var_04 - E->base.x_pos) >> 1;
    r20 = (uint16)-v1 >> 2;
    r22 = r18 + r20;
    eproj_x_pos[14] = 128;
    eproj_x_pos[15] = E->ssn_var_04 - r20;
    E->ssn_var_20 = eproj_x_pos[15];
    eproj_x_pos[16] = E->ssn_var_04 - r18;
    E->ssn_var_21 = eproj_x_pos[16];
    v2 = E->ssn_var_04 - r22;
  }
  eproj_x_pos[17] = v2;
  E->ssn_var_22 = v2;
  uint16 v3 = E->base.y_pos - 40 - E->ssn_var_05, v4;
  if ((v3 & 0x8000) == 0) {
    r18 = v3 >> 1, r20 = v3 >> 2;
    r22 = (v3 >> 1) + (v3 >> 2);
    eproj_y_pos[14] = 560;
    eproj_y_pos[15] = E->ssn_var_05 + (v3 >> 2);
    E->ssn_var_23 = eproj_y_pos[15];
    eproj_y_pos[16] = E->ssn_var_05 + r18;
    E->ssn_var_24 = eproj_y_pos[16];
    v4 = E->ssn_var_05 + r22;
  } else {
    r18 = (uint16)(E->ssn_var_05 - (E->base.y_pos - 40)) >> 1;
    r20 = (uint16)-v3 >> 2;
    r22 = r18 + r20;
    eproj_y_pos[14] = 560;
    eproj_y_pos[15] = E->ssn_var_05 - r20;
    E->ssn_var_23 = eproj_y_pos[15];
    eproj_y_pos[16] = E->ssn_var_05 - r18;
    E->ssn_var_24 = eproj_y_pos[16];
    v4 = E->ssn_var_05 - r22;
  }
  eproj_y_pos[17] = v4;
  E->ssn_var_25 = v4;
}

void SporeSpawn_Shot(void) {  // 0xA5ED5A
  int16 v4;

  uint16 v0 = 2 * collision_detection_index;
  uint16 v1 = projectile_type[collision_detection_index];
  if ((v1 & 0x700) != 0 || (v1 & 0x10) != 0) {
    EnemyFunc_A6B4_UsedBySporeSpawn();
    v0 = cur_enemy_index;
    Enemy_SporeSpawn *EK = Get_SporeSpawn(v0);
    if (EK->base.flash_timer) {
      Enemy_SporeSpawn *E = Get_SporeSpawn(0);
      EK->ssn_var_A = FUNC16(SporeSpawn_Func_2);
      v4 = 2;
      if (sign16(EK->base.health - 400)) {
        if ((E->ssn_var_0C & 0x8000) != 0)
          v4 = -2;
        E->ssn_var_0C = v4;
      }
      if (!E->ssn_var_2F) {
        E->ssn_var_0C = -E->ssn_var_0C;
        E->ssn_var_2F = 1;
        EK->base.current_instruction = addr_stru_A5E729;
        EK->base.instruction_timer = 1;
        uint16 v7 = 96;
        uint16 health = EK->base.health;
        if (!sign16(health - 70)) {
          v7 = 64;
          if (!sign16(health - 410)) {
            v7 = 32;
            if (!sign16(health - 770))
              v7 = 0;
          }
        }
        if (health != E->ssn_var_40) {
          E->ssn_var_40 = health;
          SporeSpawn_Func_7(v7);
        }
      }
    }
    SporeSpawn_Func_6();
  }
}

void SporeSpawn_Touch(void) {  // 0xA5EDEC
  NormalEnemyTouchAiSkipDeathAnim_CurEnemy();
  SporeSpawn_Func_6();
}

void SporeSpawn_Func_6(void) {  // 0xA5EDF3
  if (!Get_SporeSpawn(cur_enemy_index)->base.health) {
    Enemy_SporeSpawn *E = Get_SporeSpawn(cur_enemy_index);
    Enemy_SporeSpawn *E0 = Get_SporeSpawn(0);
    E0->ssn_var_0E = 0;
    E->base.invincibility_timer = 0;
    E->base.flash_timer = 0;
    E->base.ai_handler_bits = 0;
    E->base.properties |= kEnemyProps_Tangible;
    for (int i = 26; i >= 0; i -= 2)
      *(uint16 *)((uint8 *)eproj_id + (uint16)i) = 0;
    E0->base.current_instruction = addr_kDraygon_Ilist_E77D;
    E0->base.instruction_timer = 1;
    *(uint16 *)&boss_bits_for_area[area_index] |= kBossBit_AreaMiniBoss;
    scrolling_finished_hook = 0;
    SpawnHardcodedPlm((SpawnHardcodedPlmArgs) { 0x07, 0x1e, 0xb78f });
  }
}

void SporeSpawn_Func_7(uint16 a) {  // 0xA5EE4A
  uint16 v1 = a;
  for (int i = 0; i != 32; i += 2) {
    palette_buffer[(i >> 1) + 144] = kSporeSpawn_HealthPaletteTable[v1 >> 1];
    v1 += 2;
  }
}
