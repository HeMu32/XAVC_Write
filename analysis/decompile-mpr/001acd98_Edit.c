// mpr::Edit
// Ghidra address: 001acd98

/* mpr::Edit(void*) */

void mpr::Edit(void *param_1)

{
  pthread_mutex_t *__mutex;
  pthread_mutex_t *__mutex_00;
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  byte bVar6;
  undefined *puVar7;
  undefined *puVar8;
  undefined8 ***pppuVar9;
  bool bVar10;
  bool bVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  ContentsList *this;
  char *pcVar19;
  ulong uVar20;
  _List_node_base *p_Var21;
  DirectEditRequestCounter *this_00;
  undefined8 uVar22;
  ulong uVar23;
  uint uVar24;
  int iVar25;
  undefined8 ****ppppuVar26;
  undefined8 ****ppppuVar27;
  uint local_1d30;
  undefined4 local_1d10;
  uint local_1d00;
  uint local_1cfc;
  undefined8 local_1cf8;
  undefined8 local_1cf0;
  undefined4 local_1ce8;
  ulong local_1ce0;
  undefined8 uStack_1cd8;
  undefined4 local_1cd0;
  undefined8 ***local_1cc8;
  undefined8 ***local_1cc0;
  long local_1cb8;
  set asStack_1cb0 [32];
  set asStack_1c90 [8];
  undefined8 local_1c88;
  undefined1 local_1c80;
  undefined4 local_1c7c;
  undefined4 local_1c78;
  undefined8 *local_1c70;
  undefined8 *puStack_1c68;
  undefined *local_1c60;
  code *local_1c58;
  undefined8 local_1c50;
  undefined1 auStack_1c48 [32];
  undefined8 local_1c28;
  undefined4 local_1c20;
  uint uStack_1c1c;
  undefined *local_1c18;
  undefined *local_1c10;
  undefined2 local_1c00;
  undefined2 uStack_1bfe;
  undefined1 uStack_1bfc;
  undefined1 uStack_1bfb;
  undefined1 uStack_1bfa;
  undefined1 uStack_1bf9;
  uint local_1bf8;
  uint local_1bf4;
  undefined8 local_1bf0;
  undefined8 local_1be8;
  int local_1be0;
  char local_1bdc;
  undefined4 local_1bb4;
  undefined4 local_15e0;
  undefined1 local_15dc;
  undefined1 local_15db;
  undefined1 local_15da;
  undefined1 local_15d9;
  undefined4 local_15d8;
  int local_15c8;
  int local_15c4;
  char *local_15c0;
  byte local_15b8;
  recordInfo *local_15b0;
  uint local_15a8;
  uint local_15a4;
  undefined4 local_15a0;
  undefined4 local_10;
  undefined *local_8;
  
  iVar25 = 6;
  local_15dc = 3;
  local_15e0 = 0x80021b0;
  local_15d8 = SUB84(param_1,0);
  local_15db = 0;
  local_15da = 0;
  local_15d9 = 0;
  FUN_001aa3f8(&local_15e0,0xc);
  uVar1 = *(undefined4 *)param_1;
  this = *(ContentsList **)((long)param_1 + 8);
  iVar2 = *(int *)((long)param_1 + 0x10);
  iVar3 = *(int *)((long)param_1 + 0x14);
  uVar22 = *(undefined8 *)((long)param_1 + 0x10);
  pcVar19 = *(char **)((long)param_1 + 0x18);
  local_1cb8 = 0;
  bVar6 = *(byte *)((long)param_1 + 0x20);
  uVar4 = *(undefined4 *)((long)param_1 + 0x38);
  local_1d00 = 0xffffffff;
  local_1cf8 = DAT_003d3458;
  local_1cf0 = DAT_003d3460;
  local_1ce8 = DAT_003d3468;
  local_1cd0 = DAT_003d3468;
  local_1ce0 = DAT_003d3458;
  uStack_1cd8 = DAT_003d3460;
  local_1cc8 = &local_1cc8;
  local_1cc0 = &local_1cc8;
  FUN_001aaaac(&local_15e0,0);
  local_1c00 = 0x21b0;
  uStack_1bfb = 0;
  uStack_1bfc = 1;
  uStack_1bfa = 0;
  uStack_1bfe = 0x801;
  uStack_1bf9 = 0;
  local_1d10 = SUB84(this,0);
  local_1bf4 = local_1d10;
  local_1bf8 = uVar1;
  local_1bf0 = (undefined *)uVar22;
  FUN_001aa3f8((recordInfo *)&local_1c00,0x18);
  local_1c00 = 0x21b0;
  uStack_1bfb = 0;
  uStack_1bfc = 2;
  uStack_1bfa = 0;
  uStack_1bfe = 0x802;
  local_1d30 = (uint)pcVar19;
  uStack_1bf9 = 0;
  local_1bf8 = local_1d30;
  local_1bf4 = (uint)bVar6;
  FUN_001aa3f8((recordInfo *)&local_1c00,0x10);
  ContentsList::Size(this,&local_1cfc);
  iVar12 = GetContensSize(this);
  bVar10 = iVar2 == 0;
  local_1c00 = 0x21b0;
  uStack_1bfb = 0;
  uVar23 = 0;
  uStack_1bfa = 0;
  uStack_1bf9 = 0;
  uStack_1bfc = 4;
  uStack_1bfe = 0x810;
  FUN_001aa3f8((recordInfo *)&local_1c00,8);
  while( true ) {
    uVar18 = (uint)uVar23;
    iVar25 = iVar25 + -1;
    uVar24 = 0;
    if (iVar25 == 0) break;
    for (; uVar24 < local_1cfc; uVar24 = uVar24 + 1) {
      iVar13 = ContentsList::Get(this,uVar24,(set **)&local_1c28,(uint *)&local_1c50);
      if (iVar13 == 0) {
        iVar13 = 1;
        if ((uint)local_1c50 == 0xffffffff) {
          iVar13 = sidb::set::size((set *)CONCAT17(local_1c28._7_1_,
                                                   CONCAT16(local_1c28._6_1_,
                                                            CONCAT15(local_1c28._5_1_,
                                                                     CONCAT14(local_1c28._4_1_,
                                                                              CONCAT22(local_1c28.
                                                                                       _2_2_,(
                                                  undefined2)local_1c28))))));
          local_1c50._0_4_ = 0;
        }
        for (; uVar18 = (uint)uVar23, iVar13 != 0; iVar13 = iVar13 + -1) {
          uVar14 = sidb::set::at((set *)CONCAT17(local_1c28._7_1_,
                                                 CONCAT16(local_1c28._6_1_,
                                                          CONCAT15(local_1c28._5_1_,
                                                                   CONCAT14(local_1c28._4_1_,
                                                                            CONCAT22(local_1c28.
                                                                                     _2_2_,(
                                                  undefined2)local_1c28))))),(uint)local_1c50);
          iVar15 = sidb::GetMediaIdFromUniqueId(uVar14,&local_1d00);
          if (iVar15 != 0) {
LAB_001ad080:
            uVar24 = 2;
            goto LAB_001ad084;
          }
          uVar20 = 0;
          while (*(uint *)((long)&local_1cf8 + uVar20 * 4) != local_1d00) {
            if (uVar23 == uVar20) {
              *(uint *)((long)&local_1cf8 + (uVar20 & 0xffffffff) * 4) = local_1d00;
              uStack_1bfc = 1;
              uStack_1bfe = 0x811;
              uVar23 = (ulong)(uVar18 + 1);
              uStack_1bfb = 0;
              uStack_1bfa = 0;
              uStack_1bf9 = 0;
              local_1c00 = 0x21b0;
              local_1bf4 = local_1d00;
              local_1bf0 = (undefined *)CONCAT44(uVar18 + 1,local_1d00);
              local_1bf8 = uVar18;
              FUN_001aa3f8((recordInfo *)&local_1c00,0x18);
              break;
            }
            uVar20 = uVar20 + 1;
            if (uVar20 == 5) goto LAB_001ad080;
          }
          local_1c50._0_4_ = (uint)local_1c50 + 1;
        }
      }
    }
  }
LAB_001ad084:
  uStack_1bfb = 0;
  uVar23 = 0;
  uStack_1bfc = 1;
  uStack_1bfa = 0;
  local_1c00 = 0x21b0;
  uStack_1bf9 = 0;
  uStack_1bfe = 0x81f;
  local_1bf4 = (uint)local_1cf8;
  local_1bf0 = (undefined *)CONCAT44((undefined4)local_1cf0,local_1cf8._4_4_);
  local_1bf8 = uVar18;
  FUN_001aa3f8((recordInfo *)&local_1c00,0x18);
  puVar8 = PTR_s_editQueueLock_00401bf0;
  uVar14 = 0;
  iVar25 = 1;
  __mutex = (pthread_mutex_t *)(PTR_s_editQueueLock_00401bf0 + 8);
  do {
    if (uVar18 == uVar23) break;
    uStack_1bfb = 0;
    uStack_1bfc = 4;
    uStack_1bfa = 0;
    local_1c00 = 0x21b0;
    uStack_1bf9 = 0;
    uStack_1bfe = 0x820;
    FUN_001aa3f8((recordInfo *)&local_1c00,8);
    for (uVar17 = 0; uVar17 < local_1cfc; uVar17 = uVar17 + 1) {
      iVar13 = ContentsList::Get(this,uVar17,(set **)&local_1c50,(uint *)&local_1c70);
      if (iVar13 == 0) {
        iVar13 = 1;
        if ((uint)local_1c70 == -1) {
          iVar13 = sidb::set::size((set *)CONCAT44(local_1c50._4_4_,(uint)local_1c50));
          local_1c70 = (undefined8 *)((ulong)local_1c70 & 0xffffffff00000000);
        }
        while (iVar13 = iVar13 + -1, iVar13 != -1) {
          if ((pcVar19 != (char *)0x0) && (*pcVar19 != '\0')) {
            uVar24 = 1;
            goto LAB_001ad1d0;
          }
          uVar16 = sidb::set::at((set *)CONCAT44(local_1c50._4_4_,(uint)local_1c50),(uint)local_1c70
                                );
          sidb::recordInfo::clear((recordInfo *)&local_1c00);
          iVar15 = sidb::GetMediaIdFromUniqueId(uVar16,&local_1d00);
          if (iVar15 != 0) {
LAB_001ad1cc:
            uVar24 = 2;
            goto LAB_001ad1d0;
          }
          uVar5 = *(uint *)((long)&local_1cf8 + uVar23 * 4);
          if (uVar5 == local_1d00) {
            iVar15 = sidb::Select(0xffffffff,uVar16,(recordInfo *)&local_1c00,false);
            if ((bVar6 & bVar10 & iVar15 == 0x402) != 0) {
              uVar24 = 4;
              goto LAB_001ad1d0;
            }
            if (iVar15 != 0) goto LAB_001ad1cc;
            bVar11 = false;
            if (iVar2 == 0) {
              if (local_1bdc == '\0') {
                bVar11 = false;
                if ((iVar3 == 0) && (local_1be0 - 1U < 2)) {
                  bVar11 = true;
                  p_Var21 = operator_new(0x18);
                  *(uint *)(p_Var21 + 0x10) = local_1bf8;
                  std::__detail::_List_node_base::_M_hook(p_Var21);
                  local_1cb8 = local_1cb8 + 1;
                }
                goto LAB_001ad71c;
              }
            }
            else {
LAB_001ad71c:
              local_15e0 = msidconv::GetSlotID((msidconv *)PTR_g_msidconv_00401cd8,(uint)local_1cf8)
              ;
              local_15a4 = local_1d00;
              local_15c8 = iVar2;
              local_15c4 = iVar3;
              local_15c0 = pcVar19;
              local_15b8 = bVar6;
              local_15b0 = (recordInfo *)&local_1c00;
              local_15a8 = uVar16;
              local_15a0 = uVar4;
              local_10 = uVar1;
              pthread_mutex_lock(__mutex);
              if (CONCAT22(uStack_1bfe,local_1c00) == 1) {
                local_8 = PTR_EditStill_00402270;
                FUN_00194008(&local_15e0);
                pthread_cond_wait((pthread_cond_t *)(puVar8 + 0x38),__mutex);
                pppuVar9 = local_1cc0;
                uVar24 = DAT_0047a474;
                if ((((iVar3 == 0) && (bVar10 && DAT_0047a474 == 0)) && (uVar24 = 0, bVar11)) &&
                   (uVar24 = 0, DAT_0040cd28 == '\0')) {
                  local_1cb8 = local_1cb8 + -1;
                  std::__detail::_List_node_base::_M_unhook();
                  operator_delete(pppuVar9);
                }
              }
              else if (CONCAT22(uStack_1bfe,local_1c00) == 4) {
                local_8 = PTR_EditMovie_00401540;
                FUN_00194008(&local_15e0);
                pthread_cond_wait((pthread_cond_t *)(puVar8 + 0x38),__mutex);
                uVar24 = DAT_0047a474;
              }
              else {
                uVar24 = 2;
              }
              pthread_mutex_unlock((pthread_mutex_t *)(PTR_s_editQueueLock_00401bf0 + 8));
            }
            SendEvtEditProgress(iVar2,local_1d00,iVar25,iVar12);
            local_1c70 = (undefined8 *)CONCAT44(local_1c70._4_4_,(uint)local_1c70 + 1);
            iVar25 = iVar25 + 1;
          }
          else {
            local_1c28._5_1_ = 0;
            local_1c28._6_1_ = 0;
            local_1c28._4_1_ = 1;
            local_1c28._7_1_ = 0;
            local_1c28._0_2_ = 0x21b0;
            local_1c28._2_2_ = 0x821;
            local_1c18 = (undefined *)(ulong)local_1d00;
            local_1c20 = (int)uVar23;
            uStack_1c1c = uVar5;
            FUN_001aa3f8(&local_1c28,0x18);
            local_1c70 = (undefined8 *)CONCAT44(local_1c70._4_4_,(uint)local_1c70 + 1);
          }
        }
        if (uVar24 != 0) break;
      }
    }
LAB_001ad1d0:
    uStack_1bfe = 0x82f;
    uStack_1bfc = 4;
    uStack_1bfb = 0;
    uStack_1bfa = 0;
    uStack_1bf9 = 0;
    local_1c00 = 0x21b0;
    FUN_001aa3f8((recordInfo *)&local_1c00,8);
    uStack_1bfc = 4;
    uStack_1bfb = 0;
    uStack_1bfa = 0;
    uStack_1bf9 = 0;
    local_1ce0 = CONCAT44(local_1ce0._4_4_,*(undefined4 *)((long)&local_1cf8 + uVar23 * 4));
    local_1c00 = 0x21b0;
    uStack_1bfe = 0x830;
    FUN_001aa3f8((recordInfo *)&local_1c00,8);
    if (uVar24 != 4 && (bVar10 && iVar3 == 0)) {
      sidb::recordInfo::clear((recordInfo *)&local_1c00);
      sidb::set::set(asStack_1cb0);
      iVar13 = sidb::GetRootSet(1,&local_1ce0,5,0,1,0,asStack_1cb0);
      if (iVar13 == 0) {
        local_1c80 = 1;
        local_1c88 = 0;
        local_1c28._0_2_ = 4;
        local_1c28._2_2_ = 0;
        local_1c50._0_4_ = 0xf;
        local_1c7c = 0;
        local_1c78 = 0;
        local_1c10 = PTR__M_invoke_00401530;
        local_1c50._4_4_ = 0;
        local_1c18 = PTR__M_manager_00402f30;
        FUN_001ac104(auStack_1c48,&local_1c28);
        FUN_001aa68c(&local_1c28);
        local_1c28._0_2_ = 0xf;
        local_1c28._2_2_ = 0;
        local_1c70 = (undefined8 *)((ulong)local_1c70 & 0xffffffff00000000);
        local_1c58 = (code *)PTR__M_invoke_00402658;
        local_1c60 = PTR__M_manager_00401c78;
        local_1c28._4_1_ = 1;
        local_1c28._5_1_ = 0;
        local_1c28._6_1_ = 0;
        local_1c28._7_1_ = 0;
        FUN_001ac104(&local_1c20,&local_1c70);
        FUN_001aa68c(&local_1c70);
        local_1c58 = FUN_001aa318;
        local_1c60 = &LAB_001aa250;
        local_1c70 = &local_1c50;
        puStack_1c68 = &local_1c28;
        iVar13 = sidb::ComplexRefine(0xffffffff,asStack_1cb0,&local_1c70,asStack_1c90);
        FUN_001aa68c(&local_1c70);
        if ((iVar13 == 0) && (iVar13 = sidb::set::size(asStack_1c90), iVar13 == 1)) {
          uVar14 = sidb::set::at(asStack_1c90,0);
          sidb::Select(0xffffffff,uVar14,(recordInfo *)&local_1c00,true);
          sidb::SetHeaderParam<unsigned_int>(local_1ce0 & 0xffffffff,0,local_1bb4);
        }
        FUN_001aa68c(&local_1c20);
        FUN_001aa68c(auStack_1c48);
        sidb::set::~set(asStack_1c90);
      }
      sidb::set::clear(asStack_1cb0);
      iVar13 = sidb::GetRootSet(1,&local_1ce0,1,0,1,0,asStack_1cb0);
      if (iVar13 == 0) {
        iVar13 = sidb::set::size(asStack_1cb0);
        uVar22 = 0;
        if (iVar13 != 0) {
          uVar17 = sidb::set::at(asStack_1cb0,iVar13 - 1);
          sidb::Select(0xffffffff,uVar17,(recordInfo *)&local_1c00,true);
          uVar22 = sidb::ConvDefStructLocalTime2SiDBUInt64((LocalTime *)&local_1bf4);
        }
        sidb::SetHeaderParam<unsigned_long>(local_1ce0 & 0xffffffff,3,uVar22);
      }
      sidb::set::~set(asStack_1cb0);
    }
    uStack_1bfb = 0;
    uStack_1bfc = 3;
    uStack_1bfa = 0;
    uStack_1bfe = 0x83f;
    uStack_1bf9 = 0;
    local_1c00 = 0x21b0;
    local_1bf8 = uVar14;
    FUN_001aa3f8((recordInfo *)&local_1c00,0xc);
    uStack_1bfb = 0;
    uStack_1bfa = 0;
    uStack_1bfc = 4;
    uStack_1bf9 = 0;
    uStack_1bfe = 0x840;
    local_1c00 = 0x21b0;
    FUN_001aa3f8((recordInfo *)&local_1c00,8);
    if ((undefined8 ****)local_1cc8 != &local_1cc8) {
      sidb::set::set((set *)&local_1c70);
      iVar13 = sidb::GetRootSet(1,&local_1ce0,6,0,1,0,(set *)&local_1c70);
      ppppuVar26 = (undefined8 ****)local_1cc8;
      if ((undefined8 ****)local_1cc8 != &local_1cc8) {
        while (ppppuVar27 = ppppuVar26, ppppuVar26 = (undefined8 ****)*ppppuVar27,
              ppppuVar26 != &local_1cc8) {
          if (*(int *)(ppppuVar27 + 2) == *(int *)(ppppuVar26 + 2)) {
            local_1cb8 = local_1cb8 + -1;
            std::__detail::_List_node_base::_M_unhook();
            operator_delete(ppppuVar26);
            ppppuVar26 = ppppuVar27;
          }
        }
      }
      puVar7 = PTR__M_invoke_00401530;
      if (iVar13 == 0) {
        for (ppppuVar26 = (undefined8 ****)local_1cc8; ppppuVar26 != &local_1cc8;
            ppppuVar26 = (undefined8 ****)*ppppuVar26) {
          sidb::set::set((set *)&local_1c50);
          local_1c00 = (undefined2)*(undefined4 *)(ppppuVar26 + 2);
          uStack_1bfe = (undefined2)((uint)*(undefined4 *)(ppppuVar26 + 2) >> 0x10);
          local_1be8 = puVar7;
          local_1bf0 = PTR__M_manager_00402f30;
          sidb::Refine<unsigned_int>
                    (0xffffffff,(set *)&local_1c70,2,(recordInfo *)&local_1c00,(set *)&local_1c50);
          FUN_001aa68c((recordInfo *)&local_1c00);
          iVar13 = sidb::set::size((set *)&local_1c50);
          if (iVar13 != 0) {
            local_1bf0 = (undefined *)0x0;
            local_1c10 = PTR_LAB_004026d8;
            local_1c18 = PTR_FUN_00402048;
            FUN_001aa290((recordInfo *)&local_1c00,&local_1c28,2);
            local_1be8 = local_1c10;
            local_1bf0 = local_1c18;
            sidb::set::sort_i<unsigned_int>((set *)&local_1c50,7,(recordInfo *)&local_1c00);
            FUN_001aa68c((recordInfo *)&local_1c00);
            FUN_001aa68c(&local_1c28);
            sidb::recordInfo::clear((recordInfo *)&local_1c00);
            uVar17 = sidb::set::at((set *)&local_1c50,0);
            sidb::Select(0xffffffff,uVar17,(recordInfo *)&local_1c00,true);
            if (local_1be8._4_1_ == '\0') {
              sidb::PartialUpdate<bool>(0xffffffff,uVar17,8,1,0,0);
            }
            iVar13 = sidb::set::size((set *)&local_1c50);
            if (iVar13 == 1) {
              sidb::PartialUpdate<unsigned_int>(0xffffffff,uVar17,9,0,0,0);
              sidb::PartialUpdate<unsigned_int>(0xffffffff,uVar17,2,0,0,0);
            }
          }
          sidb::set::~set((set *)&local_1c50);
        }
      }
      sidb::set::~set((set *)&local_1c70);
    }
    FUN_001acd60(&local_1cc8);
    uStack_1bfb = 0;
    uStack_1bfa = 0;
    uStack_1bfc = 4;
    uStack_1bf9 = 0;
    local_1c00 = 0x21b0;
    uStack_1bfe = 0x84f;
    local_1cb8 = 0;
    local_1cc8 = &local_1cc8;
    local_1cc0 = &local_1cc8;
    FUN_001aa3f8((recordInfo *)&local_1c00,8);
    bVar11 = bVar10;
    if ((bVar6 & bVar10) == 0) {
LAB_001ad954:
      uStack_1bfb = 0;
      uStack_1bfc = 4;
      uStack_1bfa = 0;
      uStack_1bfe = 0x850;
      uStack_1bf9 = 0;
      local_1c00 = 0x21b0;
      FUN_001aa3f8((recordInfo *)&local_1c00,8);
      local_8 = PTR_SidbFlush_004024e8;
      local_15e0 = msidconv::GetSlotID((msidconv *)PTR_g_msidconv_00401cd8,(uint)local_1ce0);
      puVar7 = PTR_s_editQueueLock_00401bf0;
      local_15a4 = (uint)local_1ce0;
      __mutex_00 = (pthread_mutex_t *)(PTR_s_editQueueLock_00401bf0 + 8);
      pthread_mutex_lock(__mutex_00);
      FUN_00194008(&local_15e0);
      pthread_cond_wait((pthread_cond_t *)(puVar7 + 0x38),__mutex_00);
      if (DAT_0047a474 != 0) {
        uStack_1bfb = 0;
        uVar24 = 2;
        uStack_1bfc = 3;
        uStack_1bfa = 0;
        uStack_1bfe = 0x851;
        uStack_1bf9 = 0;
        local_1bf8 = (uint)local_1ce0;
        local_1c00 = 0x21b0;
        FUN_001aa3f8((recordInfo *)&local_1c00,0xc);
      }
      pthread_mutex_unlock((pthread_mutex_t *)(PTR_s_editQueueLock_00401bf0 + 8));
      uStack_1bfb = 0;
      uStack_1bfa = 0;
      uStack_1bfc = 4;
      uStack_1bf9 = 0;
      local_1c00 = 0x21b0;
      uStack_1bfe = 0x85f;
      FUN_001aa3f8((recordInfo *)&local_1c00,8);
      if (bVar11) {
        SetRecStatus(iVar2,local_1ce0 & 0xffffffff);
      }
      if (iVar2 == 0) goto LAB_001ada68;
    }
    else {
      uVar17 = msidconv::GetSlotID((msidconv *)PTR_g_msidconv_00401cd8,(uint)local_1ce0);
      iVar13 = FUN_002366f4();
      if (iVar13 == 0) {
        iVar13 = FUN_002366f4(uVar17 ^ 1);
        bVar11 = iVar13 == 0;
        goto LAB_001ad954;
      }
LAB_001ada68:
      capidtbl::AddCapIdTbl((LocalTime *)0x0);
    }
    uVar23 = uVar23 + 1;
  } while (uVar24 == 0);
  if (iVar12 == 1) {
    ContentsList::Get(this,0,(set **)&local_1c00,(uint *)&local_1c28);
    uVar18 = sidb::set::at((set *)CONCAT17(uStack_1bf9,
                                           CONCAT16(uStack_1bfa,
                                                    CONCAT15(uStack_1bfb,
                                                             CONCAT14(uStack_1bfc,
                                                                      CONCAT22(uStack_1bfe,
                                                                               local_1c00))))),
                           CONCAT22(local_1c28._2_2_,(undefined2)local_1c28));
    this_00 = (DirectEditRequestCounter *)PTR_s_directProtectReqCnt_00401f18;
    if ((iVar2 == 1) ||
       (this_00 = (DirectEditRequestCounter *)PTR_s_directRatingReqCnt_00401f88, iVar2 == 3)) {
      DirectEditRequestCounter::Complete(this_00,uVar18);
    }
  }
  SendEvtEditFinished(iVar2,local_1cf8 & 0xffffffff,uVar1,uVar24);
  uStack_1bfb = 0;
  uStack_1bfa = 0;
  uStack_1bfc = 4;
  uStack_1bf9 = 0;
  local_1c00 = 0x21b0;
  uStack_1bfe = 0x8ff;
  FUN_001aa3f8((recordInfo *)&local_1c00,8);
  FUN_001acd60(&local_1cc8);
  return;
}

