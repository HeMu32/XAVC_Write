// mpr::RepairDcfInconsistencies
// Ghidra address: 001baba4

/* mpr::RepairDcfInconsistencies(unsigned int, bool*, unsigned int&) */

undefined4 mpr::RepairDcfInconsistencies(uint param_1,bool *param_2,uint *param_3)

{
  bool bVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  uint uVar9;
  uint uVar10;
  uint *puVar11;
  uint local_72c;
  uint local_728;
  uint local_724;
  int iStack_720;
  uint local_718 [6];
  char local_700 [4];
  int local_6fc;
  uint local_6f8;
  undefined1 local_6f4;
  int local_6f0;
  int local_6ec;
  set asStack_6e8 [32];
  undefined1 auStack_6c8 [8];
  undefined4 local_6c0 [2];
  undefined4 *local_6b8;
  undefined4 *puStack_6b0;
  undefined4 *local_6a8;
  undefined8 uStack_6a0;
  char local_698;
  uint local_690 [8];
  char local_670;
  undefined1 auStack_668 [32];
  char local_648;
  undefined1 auStack_640 [32];
  recordInfo arStack_620 [8];
  uint local_618 [4];
  undefined2 local_608;
  undefined2 local_606;
  undefined1 local_604;
  int local_600;
  char local_560;
  undefined1 auStack_55f [262];
  char local_459;
  undefined1 auStack_458 [262];
  char local_352;
  undefined1 auStack_351 [262];
  char local_24b;
  int local_9c;
  int local_98;
  int local_94;
  int local_90;
  int local_8c;
  int local_88;
  undefined4 local_84;
  undefined1 local_7;
  char local_6;
  
  uVar10 = 0xffffffff;
  if (param_1 < 4) {
    uVar10 = *(uint *)(PTR_g_msidconv_00401cd8 + (ulong)param_1 * 0x80 + 0x7c);
  }
  puStack_6b0 = local_6c0;
  local_6c0[0] = 0;
  local_6b8 = (undefined4 *)0x0;
  uStack_6a0 = 0;
  local_6a8 = puStack_6b0;
  sidb::set::set(asStack_6e8);
  local_718[1] = 0xffff;
  local_718[2] = 0xffff;
  local_718[3] = 0xffff;
  local_718[4] = 0xffff;
  local_718[0] = uVar10;
  iVar3 = sidb::GetRootSet(1,local_718,6,0,1,0,asStack_6e8);
  if (iVar3 == 0) {
    uVar8 = 0;
    for (uVar9 = 0; uVar4 = sidb::set::size(asStack_6e8), uVar9 < uVar4; uVar9 = uVar9 + 1) {
      sidb::recordInfo::clear(arStack_620);
      if ((param_2 != (bool *)0x0) && (*param_2 != false)) {
        uVar8 = 1;
        break;
      }
      uVar4 = sidb::set::at(asStack_6e8,uVar9);
      iVar3 = sidb::Select(0xffffffff,uVar4,arStack_620,false);
      if (iVar3 != 0) goto LAB_001baf4c;
      uVar8 = 0;
      if (local_6 != '\0') {
        puVar11 = local_690;
        local_698 = local_560;
        FUN_001b7cd4(puVar11,auStack_55f);
        local_670 = local_459;
        FUN_001b7cd4(auStack_668,auStack_458);
        local_648 = local_352;
        FUN_001b7cd4(auStack_640,auStack_351);
        iVar3 = 0;
        do {
          if (((char)puVar11[-2] != '\0') &&
             (iVar5 = stillplay::getRecordInfo(param_1,*(char **)puVar11,arStack_620,false),
             iVar5 != 0)) {
            iVar3 = iVar5;
          }
          puVar11 = puVar11 + 10;
        } while (local_618 != puVar11);
        if (iVar3 == 0) {
          local_7 = 1;
          local_6 = '\0';
          iVar3 = FUN_0023afb8(uVar10,local_608,local_606,local_700);
          if (iVar3 != 0) goto LAB_001baf60;
          if (local_700[0] == '\0') {
LAB_001bafb8:
            iVar3 = sidb::Update(0xffffffff,arStack_620,false,true);
            goto LAB_001bafcc;
          }
          local_604 = local_6f4;
          local_600 = local_6fc;
          if (local_560 != '\0') {
            if (local_9c == 0) {
              local_9c = local_6f0;
            }
            if (local_98 == 0) {
              local_98 = local_6f0;
            }
          }
          if (local_459 != '\0') {
            if (local_8c == 0) {
              local_8c = local_6ec;
            }
            if (local_88 == 0) {
              local_88 = local_6ec;
            }
          }
          if (local_352 != '\0') {
            if (local_94 == 0) {
              local_94 = local_6f0;
            }
            if (local_90 == 0) {
              local_90 = local_6f0;
            }
          }
          if (local_24b != '\0') {
            local_84 = 0;
          }
          if (1 < local_6fc - 1U) {
            local_618[0] = 0;
LAB_001bafb0:
            local_604 = 1;
            goto LAB_001bafb8;
          }
          puVar2 = local_6b8;
          puVar7 = local_6c0;
          while (puVar6 = puVar2, puVar6 != (undefined4 *)0x0) {
            if ((uint)puVar6[8] < local_6f8) {
              puVar2 = *(undefined4 **)(puVar6 + 6);
            }
            else {
              puVar2 = *(undefined4 **)(puVar6 + 4);
              puVar7 = puVar6;
            }
          }
          if ((puVar7 != local_6c0) &&
             (puVar2 = local_6b8, puVar6 = local_6c0, (uint)puVar7[8] <= local_6f8)) {
            while (puVar7 = puVar2, puVar7 != (undefined4 *)0x0) {
              if ((uint)puVar7[8] < local_6f8) {
                puVar2 = *(undefined4 **)(puVar7 + 6);
              }
              else {
                puVar2 = *(undefined4 **)(puVar7 + 4);
                puVar6 = puVar7;
              }
            }
            if ((puVar6 == local_6c0) || (local_6f8 < (uint)puVar6[8])) {
              std::__throw_out_of_range("map::at");
              goto LAB_001baf60;
            }
            local_618[0] = puVar6[9];
            local_604 = 0;
            goto LAB_001bafb8;
          }
          iVar3 = sidb::IssueGroupId(uVar10,&local_72c);
          if (iVar3 == 0) {
            local_618[0] = local_72c;
            local_728 = local_6f8;
            local_724 = local_72c;
            FUN_001baa90(auStack_6c8,(evtRepairProgressParam *)&local_728);
            goto LAB_001bafb0;
          }
LAB_001bafd4:
          bVar1 = false;
          uVar8 = 2;
        }
        else {
LAB_001baf60:
          uVar4 = sidb::set::at(asStack_6e8,uVar9);
          iVar3 = sidb::Delete(0xffffffff,uVar4,false,false);
LAB_001bafcc:
          if (iVar3 != 0) goto LAB_001bafd4;
          uVar4 = *param_3;
          bVar1 = true;
          *param_3 = uVar4 + 1;
          if ((uVar4 + 1) % 100 == 0) {
            evtRepairProgressParam::evtRepairProgressParam((evtRepairProgressParam *)&local_728);
            iStack_720 = (int)((double)*param_3 * DAT_003d39f0);
            local_724 = uVar10;
            SetIssueEvent(0x1027,(evtRepairProgressParam *)&local_728,0xc);
          }
        }
        std::__cxx11::string::_M_dispose();
        std::__cxx11::string::_M_dispose();
        std::__cxx11::string::_M_dispose();
        if (!bVar1) break;
      }
    }
  }
  else {
LAB_001baf4c:
    uVar8 = 2;
  }
  sidb::set::~set(asStack_6e8);
  FUN_001baa44(auStack_6c8,local_6b8);
  return uVar8;
}

