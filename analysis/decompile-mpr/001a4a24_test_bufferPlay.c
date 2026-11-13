// mpr::aging::test_bufferPlay
// Ghidra address: 001a4a24

/* mpr::aging::test_bufferPlay(mpr::aging::test_data_stillReocrd_t&, mpr::captureOutParam&, unsigned
   int) */

void mpr::aging::test_bufferPlay
               (test_data_stillReocrd_t *param_1,captureOutParam *param_2,uint param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  ContentsList *pCVar8;
  long lVar9;
  _Vector_base<std::pair<sidb::set*,unsigned_int>,std::allocator<std::pair<sidb::set*,unsigned_int>>>
  *p_Var10;
  undefined1 *puVar11;
  undefined1 *puVar12;
  undefined1 *puVar13;
  undefined1 *puVar14;
  captureOutParam *pcVar15;
  uint local_d2c;
  uint local_d28;
  uint local_d24;
  undefined8 local_d18;
  undefined1 *local_d10;
  ulong local_d08;
  undefined8 uStack_d00;
  undefined8 local_cf8;
  undefined8 uStack_cf0;
  ulong local_ce8;
  long lStack_ce0;
  undefined8 local_cd8;
  uint local_cd0 [4];
  ulong local_cc0;
  undefined8 uStack_cb8;
  undefined8 local_cb0;
  undefined8 uStack_ca8;
  ulong local_ca0;
  long lStack_c98;
  undefined8 local_c90;
  int local_c40 [48];
  char local_b80;
  undefined1 auStack_b7f [262];
  char local_a79;
  undefined1 auStack_a78 [262];
  char local_972;
  undefined1 auStack_971 [849];
  int local_620 [48];
  char local_560;
  undefined1 auStack_55f [262];
  char local_459;
  undefined1 auStack_458 [262];
  char local_352;
  undefined1 auStack_351 [849];
  
  sidb::recordInfo::clear((recordInfo *)local_c40);
  sidb::recordInfo::clear((recordInfo *)local_620);
  puVar2 = PTR_p_test_contentsList0_00402bc0;
  p_Var10 = *(_Vector_base<std::pair<sidb::set*,unsigned_int>,std::allocator<std::pair<sidb::set*,unsigned_int>>>
              **)PTR_p_test_contentsList0_00402bc0;
  if (p_Var10 !=
      (_Vector_base<std::pair<sidb::set*,unsigned_int>,std::allocator<std::pair<sidb::set*,unsigned_int>>>
       *)0x0) {
    std::
    _Vector_base<std::pair<sidb::set*,unsigned_int>,std::allocator<std::pair<sidb::set*,unsigned_int>>>
    ::~_Vector_base(p_Var10);
    operator_delete(p_Var10,0x18);
    *(undefined8 *)puVar2 = 0;
  }
  puVar2 = PTR_p_test_contentsList1_00402780;
  p_Var10 = *(_Vector_base<std::pair<sidb::set*,unsigned_int>,std::allocator<std::pair<sidb::set*,unsigned_int>>>
              **)PTR_p_test_contentsList1_00402780;
  if (p_Var10 !=
      (_Vector_base<std::pair<sidb::set*,unsigned_int>,std::allocator<std::pair<sidb::set*,unsigned_int>>>
       *)0x0) {
    std::
    _Vector_base<std::pair<sidb::set*,unsigned_int>,std::allocator<std::pair<sidb::set*,unsigned_int>>>
    ::~_Vector_base(p_Var10);
    operator_delete(p_Var10,0x18);
    *(undefined8 *)puVar2 = 0;
  }
  puVar4 = PTR_s_test_root_set1_00402cc8;
  puVar2 = PTR_g_msidconv_00401cd8;
  pcVar15 = param_2 + 0xc;
  local_d28 = 0;
  local_d24 = 0;
  puVar11 = (undefined1 *)0x0;
  puVar13 = (undefined1 *)0x0;
  for (local_d2c = 0; puVar1 = PTR_s_test_root_set0_004017a8, local_d2c < *(uint *)(param_2 + 4);
      local_d2c = local_d2c + 1) {
    local_cd0[0] = *(uint *)(pcVar15 + -4);
    local_cd0[2] = 0xffff;
    local_cd0[3] = 0xffff;
    local_cd0[1] = 0xffff;
    local_cc0 = CONCAT44(local_cc0._4_4_,0xffff);
    puVar12 = puVar11;
    puVar14 = puVar13;
    if (local_cd0[0] == *(uint *)(puVar2 + 0x7c)) {
      local_d24 = *(uint *)pcVar15;
      sidb::GetRootSet(1,local_cd0,0,0,1,0,PTR_s_test_root_set0_004017a8);
      pCVar8 = operator_new(0x18);
      *(undefined8 *)pCVar8 = 0;
      *(undefined8 *)(pCVar8 + 8) = 0;
      puVar3 = PTR_p_test_contentsList0_00402bc0;
      *(undefined8 *)(pCVar8 + 0x10) = 0;
      *(ContentsList **)puVar3 = pCVar8;
      if (puVar1[0x10] == '\0') {
        iVar5 = *(int *)(*(long *)(puVar1 + 8) + 0xc);
      }
      else {
        iVar5 = *(int *)(puVar1 + 0x18);
      }
      ContentsList::Add(pCVar8,(set *)PTR_s_test_root_set0_004017a8,iVar5 - 1);
      iVar5 = sidb::Select(0xffffffff,local_d24,(recordInfo *)local_c40,true);
      if ((iVar5 != 0) && (local_c40[0] == 1)) {
        if (local_a79 == '\0') {
          if (local_b80 == '\0') {
            puVar14 = auStack_971;
            if (local_972 == '\0') {
              puVar14 = puVar13;
            }
          }
          else {
            puVar14 = auStack_b7f;
          }
        }
        else {
          puVar14 = auStack_a78;
        }
      }
    }
    else if (local_cd0[0] == *(uint *)(puVar2 + 0xfc)) {
      local_d28 = *(uint *)pcVar15;
      sidb::GetRootSet(1,local_cd0,0,0,1,0,puVar4);
      pCVar8 = operator_new(0x18);
      *(undefined8 *)pCVar8 = 0;
      *(undefined8 *)(pCVar8 + 8) = 0;
      puVar1 = PTR_p_test_contentsList1_00402780;
      *(undefined8 *)(pCVar8 + 0x10) = 0;
      *(ContentsList **)puVar1 = pCVar8;
      if (puVar4[0x10] == '\0') {
        iVar5 = *(int *)(*(long *)(puVar4 + 8) + 0xc);
      }
      else {
        iVar5 = *(int *)(puVar4 + 0x18);
      }
      ContentsList::Add(pCVar8,(set *)PTR_s_test_root_set1_00402cc8,iVar5 - 1);
      iVar5 = sidb::Select(0xffffffff,local_d28,(recordInfo *)local_620,true);
      if ((iVar5 != 0) && (local_620[0] == 1)) {
        if (local_459 == '\0') {
          if (local_560 == '\0') {
            puVar12 = auStack_351;
            if (local_352 == '\0') {
              puVar12 = puVar11;
            }
          }
          else {
            puVar12 = auStack_55f;
          }
        }
        else {
          puVar12 = auStack_458;
        }
      }
    }
    pcVar15 = pcVar15 + 8;
    puVar11 = puVar12;
    puVar13 = puVar14;
  }
  if (param_3 == 1) {
    pCVar8 = *(ContentsList **)PTR_p_test_contentsList0_00402bc0;
    if (pCVar8 != (ContentsList *)0x0) {
      *PTR_g_edit_fnished0_00402a78 = 0;
      Rating(0,3,0xffffffff,pCVar8,(bool *)0x0);
    }
    pCVar8 = *(ContentsList **)PTR_p_test_contentsList1_00402780;
    if (pCVar8 != (ContentsList *)0x0) {
      *PTR_g_edit_fnished1_00402d88 = 0;
      Rating(0,3,0xffffffff,pCVar8,(bool *)0x0);
    }
  }
  else if (param_3 == 2) {
    lVar9 = *(long *)PTR_p_test_contentsList0_00402bc0;
    if (lVar9 != 0) {
      *PTR_g_edit_fnished0_00402a78 = 0;
      Protect(0,0,0xffffffff,lVar9,0);
    }
    lVar9 = *(long *)PTR_p_test_contentsList1_00402780;
    if (lVar9 != 0) {
      *PTR_g_edit_fnished1_00402d88 = 0;
      Protect(0,0,0xffffffff,lVar9,0);
    }
  }
  else if (param_3 - 3 < 3) {
    local_cd0[2] = 0;
    local_cd0[3] = 0;
    uStack_cb8 = 0;
    local_d10 = (undefined1 *)0x0;
    local_cb0 = 0;
    uStack_ca8 = 0;
    uStack_d00 = 0;
    local_ca0 = 0;
    local_cf8 = 0;
    uStack_cf0 = 0;
    local_cd0[0] = 0x2a;
    local_cd0[1] = 0;
    local_ce8 = 0;
    local_d18 = 0x2a;
    local_cd8 = 1;
    local_c90 = 1;
    if (param_3 != 3) {
      uVar6 = 2;
      if (param_3 != 4) {
        uVar6 = 3;
      }
      local_ce8 = (ulong)uVar6;
      local_ca0 = (ulong)uVar6;
    }
    local_d08 = (ulong)*(uint *)(PTR_g_msidconv_00401cd8 + 0x7c);
    local_cc0 = (ulong)*(uint *)(PTR_g_msidconv_00401cd8 + 0xfc);
    lStack_c98 = (ulong)local_d28 << 0x20;
    lStack_ce0 = (ulong)local_d24 << 0x20;
    if (*(long *)PTR_p_test_contentsList0_00402bc0 != 0) {
      *PTR_g_edit_fnished0_00402a78 = 0;
      ReadStillImage((readStillImageInParam *)&local_d18);
    }
    if (*(long *)PTR_p_test_contentsList1_00402780 != 0) {
      *PTR_g_edit_fnished1_00402d88 = 0;
      ReadStillImage((readStillImageInParam *)local_cd0);
    }
  }
  else if (param_3 - 6 < 2) {
    local_d10 = (undefined1 *)0x0;
    local_d08 = 0;
    local_d18 = 0x5e;
    memset((transferStillFileOutParam *)local_cd0,0,0x90);
    local_cd0[0] = 0x5f;
    uVar7 = 2;
    if (param_3 != 6) {
      uVar7 = 3;
    }
    local_d08 = CONCAT44(local_d08._4_4_,uVar7);
    if (puVar13 != (undefined1 *)0x0) {
      lVar9 = 0;
      *PTR_g_edit_fnished0_00402a78 = 0;
      local_d10 = puVar13;
      file::TransferStillFile
                ((transferStillFileInParam *)&local_d18,(transferStillFileOutParam *)local_cd0);
      while( true ) {
        uVar6 = (uint)lVar9;
        lVar9 = lVar9 + 1;
        if (local_cd0[3] <= uVar6) break;
        FUN_003b795c(*(undefined4 *)((transferStillFileOutParam *)local_cd0 + lVar9 * 0x10));
      }
    }
    if (puVar11 != (undefined1 *)0x0) {
      lVar9 = 0;
      *PTR_g_edit_fnished1_00402d88 = 0;
      local_d10 = puVar11;
      file::TransferStillFile
                ((transferStillFileInParam *)&local_d18,(transferStillFileOutParam *)local_cd0);
      while( true ) {
        uVar6 = (uint)lVar9;
        lVar9 = lVar9 + 1;
        if (local_cd0[3] <= uVar6) break;
        FUN_003b795c(*(undefined4 *)((transferStillFileOutParam *)local_cd0 + lVar9 * 0x10));
      }
    }
  }
  return;
}

