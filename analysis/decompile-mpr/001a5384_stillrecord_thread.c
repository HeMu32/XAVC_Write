// mpr::aging::stillrecord_thread
// Ghidra address: 001a5384

/* mpr::aging::stillrecord_thread(void*) */

void mpr::aging::stillrecord_thread(void *param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  char cVar4;
  int iVar5;
  ContentsList *pCVar6;
  undefined8 uVar7;
  _Vector_base<std::pair<sidb::set*,unsigned_int>,std::allocator<std::pair<sidb::set*,unsigned_int>>>
  *p_Var8;
  long lVar9;
  int iVar10;
  undefined2 local_108;
  undefined2 local_106;
  undefined1 local_104;
  undefined1 local_103;
  undefined1 local_102;
  undefined1 local_101;
  int local_100;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined4 local_e8;
  undefined2 local_e0;
  undefined2 local_de;
  undefined1 local_dc;
  undefined1 local_db;
  undefined1 local_da;
  undefined1 local_d9;
  int local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined1 local_84;
  int local_18;
  int local_14;
  int local_8;
  int local_4;
  
  iVar10 = 0;
  local_e8 = DAT_003d2b90;
  local_f8 = DAT_003d2b80;
  uStack_f0 = DAT_003d2b88;
  *PTR_g_cancel_00401d58 = 0;
  push_test_callback_func();
  puVar3 = PTR_test_list_stillRecord_00402b50;
  do {
    lVar9 = 0;
    while ((uint)lVar9 < *(uint *)((long)param_1 + 0x80)) {
      local_db = 0;
      local_dc = 3;
      local_da = 0;
      local_e0 = 0x2490;
      local_d9 = 0;
      local_de = 0x700;
      local_d8 = iVar10;
      FUN_001a23b0((test_data_stillReocrd_t *)&local_e0,0xc);
      memcpy((test_data_stillReocrd_t *)&local_e0,
             puVar3 + (ulong)*(uint *)((long)param_1 + lVar9 * 4) * 0xe0,0xe0);
      if (*(char *)((long)param_1 + 0x8e) != '\0') {
        local_d0 = local_d4;
        local_84 = *(char *)((long)param_1 + 0x8f) != '\0';
      }
      if (*(int *)((long)param_1 + 0x88) != 0) {
        local_18 = *(int *)((long)param_1 + 0x88);
      }
      if (*(int *)((long)param_1 + 0x84) != 0) {
        local_14 = *(int *)((long)param_1 + 0x84);
      }
      if (*(int *)((long)param_1 + 0x90) != 0) {
        local_8 = *(int *)((long)param_1 + 0x90);
      }
      if (*(int *)((long)param_1 + 0x94) != 0) {
        local_4 = *(int *)((long)param_1 + 0x94);
      }
      iVar5 = testsequence_stillRecord
                        ((test_data_stillReocrd_t *)&local_e0,(bool *)PTR_g_cancel_00401d58);
      if (iVar5 == -1) {
        local_106 = 0x300;
LAB_001a54d4:
        local_104 = 3;
        uVar7 = 0xc;
        local_100 = iVar5;
        goto LAB_001a54e0;
      }
      if (iVar5 != 0) {
        local_106 = 0x400;
        goto LAB_001a54d4;
      }
      do {
        usleep(200000);
        cVar4 = FUN_001943b0(0);
      } while (cVar4 == '\0');
      do {
        usleep(200000);
        cVar4 = FUN_001943b0(1);
        puVar1 = PTR_root_set0_00401860;
      } while (cVar4 == '\0');
      if ((*(char *)((long)param_1 + 0x8c) != '\0') &&
         (((uint)lVar9 < *(int *)((long)param_1 + 0x80) - 1U ||
          (*(char *)((long)param_1 + 0x8d) != '\0')))) {
        *PTR_g_edit_fnished0_00402a78 = 0;
        *PTR_g_edit_fnished1_00402d88 = 0;
        local_f8 = CONCAT44(local_f8._4_4_,*(undefined4 *)(PTR_g_msidconv_00401cd8 + 0x7c));
        sidb::GetRootSet(1,&local_f8,0,0,1,0,puVar1);
        puVar1 = PTR_p_contetentsList0_00402570;
        p_Var8 = *(_Vector_base<std::pair<sidb::set*,unsigned_int>,std::allocator<std::pair<sidb::set*,unsigned_int>>>
                   **)PTR_p_contetentsList0_00402570;
        if (p_Var8 != (_Vector_base<std::pair<sidb::set*,unsigned_int>,std::allocator<std::pair<sidb::set*,unsigned_int>>>
                       *)0x0) {
          std::
          _Vector_base<std::pair<sidb::set*,unsigned_int>,std::allocator<std::pair<sidb::set*,unsigned_int>>>
          ::~_Vector_base(p_Var8);
          operator_delete(p_Var8,0x18);
          *(undefined8 *)puVar1 = 0;
        }
        pCVar6 = operator_new(0x18);
        puVar2 = PTR_p_contetentsList0_00402570;
        puVar1 = PTR_root_set0_00401860;
        *(undefined8 *)pCVar6 = 0;
        *(undefined8 *)(pCVar6 + 8) = 0;
        *(undefined8 *)(pCVar6 + 0x10) = 0;
        *(ContentsList **)puVar2 = pCVar6;
        ContentsList::Add(pCVar6,(set *)puVar1,0xffffffff);
        Delete(0,0xffffffff,*(undefined8 *)puVar2,PTR_g_cancel_00401d58,0);
        local_f8 = CONCAT44(local_f8._4_4_,*(undefined4 *)(PTR_g_msidconv_00401cd8 + 0xfc));
        sidb::GetRootSet(1,&local_f8,0,0,1,0,PTR_root_set1_00401600);
        puVar1 = PTR_p_contetentsList1_00401440;
        p_Var8 = *(_Vector_base<std::pair<sidb::set*,unsigned_int>,std::allocator<std::pair<sidb::set*,unsigned_int>>>
                   **)PTR_p_contetentsList1_00401440;
        if (p_Var8 != (_Vector_base<std::pair<sidb::set*,unsigned_int>,std::allocator<std::pair<sidb::set*,unsigned_int>>>
                       *)0x0) {
          std::
          _Vector_base<std::pair<sidb::set*,unsigned_int>,std::allocator<std::pair<sidb::set*,unsigned_int>>>
          ::~_Vector_base(p_Var8);
          operator_delete(p_Var8,0x18);
          *(undefined8 *)puVar1 = 0;
        }
        pCVar6 = operator_new(0x18);
        puVar2 = PTR_root_set1_00401600;
        puVar1 = PTR_p_contetentsList1_00401440;
        *(undefined8 *)pCVar6 = 0;
        *(undefined8 *)(pCVar6 + 8) = 0;
        *(undefined8 *)(pCVar6 + 0x10) = 0;
        *(ContentsList **)puVar1 = pCVar6;
        ContentsList::Add(pCVar6,(set *)puVar2,0xffffffff);
        Delete(0,0xffffffff,*(undefined8 *)puVar1,PTR_g_cancel_00401d58,0);
        puVar1 = PTR_g_edit_fnished0_00402a78;
        do {
          usleep(200000);
          puVar2 = PTR_g_edit_fnished1_00402d88;
        } while (*puVar1 == '\0');
        do {
          usleep(200000);
        } while (*puVar2 == '\0');
      }
      lVar9 = lVar9 + 1;
      if (*PTR_g_cancel_00401d58 != '\0') {
        uVar7 = 8;
        local_104 = 4;
        local_106 = 0x500;
LAB_001a54e0:
        local_101 = 0;
        local_102 = 0;
        local_103 = 0;
        local_108 = 0x2490;
        FUN_001a23b0(&local_108,uVar7);
        goto LAB_001a54e8;
      }
    }
    iVar10 = iVar10 + 1;
    if (*(char *)((long)param_1 + 0x8d) == '\0') {
LAB_001a54e8:
      pop_test_callback_func();
      local_db = 0;
      local_dc = 3;
      local_da = 0;
      local_e0 = 0x2490;
      local_d9 = 0;
      local_de = 0x600;
      local_d8 = iVar10;
      FUN_001a23b0(&local_e0,0xc);
      return;
    }
  } while( true );
}

