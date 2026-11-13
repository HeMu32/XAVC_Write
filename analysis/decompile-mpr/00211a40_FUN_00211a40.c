// FUN_00211a40
// Ghidra address: 00211a40

undefined8 FUN_00211a40(XavcsMovieReader *param_1,undefined4 *param_2)

{
  uint uVar1;
  long lVar2;
  XavcsMovieReader XVar3;
  char cVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int *piVar8;
  ulong uVar9;
  undefined4 *puVar10;
  int *piVar11;
  uint *puVar12;
  ulong uVar13;
  undefined1 uVar14;
  uint uVar15;
  uint uVar16;
  undefined1 *puVar17;
  XavcsMovieReader XVar18;
  XavcsMovieReader XVar19;
  XavcsMovieReader local_745;
  int local_744;
  uint local_740;
  uint local_73c;
  uint local_738;
  undefined4 local_734;
  void *local_730;
  void *local_728;
  void *local_720;
  void *local_718;
  int local_710;
  uint local_70c;
  uint local_708;
  undefined1 *local_700;
  undefined8 uStack_6f8;
  undefined1 local_6f0 [16];
  undefined2 local_6e0;
  undefined2 local_6de;
  uint local_6dc;
  uint local_6d8;
  uint local_6c8;
  uint local_6c4;
  ushort local_6a8 [68];
  undefined2 local_620;
  undefined2 local_61e;
  undefined1 local_61c;
  undefined1 local_61b;
  undefined1 local_61a;
  undefined1 local_619;
  undefined4 local_618;
  undefined4 local_614;
  undefined4 local_610;
  undefined4 local_60c;
  char local_5fa;
  uint local_5e0;
  
  local_620 = 0x2311;
  local_61c = 1;
  local_61e = 0xe10;
  local_618 = *param_2;
  local_61b = 0;
  local_614 = param_2[1];
  local_61a = 0;
  local_610 = param_2[2];
  local_619 = 0;
  local_60c = param_2[3];
  FUN_0020aff4((recordInfo *)&local_620,0x18);
  local_745 = (XavcsMovieReader)0x0;
  local_744 = 0;
  FUN_002119a4(param_2[2],&local_744,&local_745);
  mpr::thread::normalLock::lock((normalLock *)(param_1 + 0x1e28));
  sidb::recordInfo::clear((recordInfo *)&local_620);
  uVar14 = 0;
  sidb::Select(0xffffffff,*(uint *)(param_1 + 0x1e1c),(recordInfo *)&local_620,true);
  if ((uint)param_2[1] < 4) {
    uVar14 = PTR_g_msidconv_00401cd8[(ulong)(uint)param_2[1] * 0x80];
  }
  iVar5 = Fsys_GetDriveInfo(uVar14,local_6a8);
  if (iVar5 == 0) {
    piVar8 = (int *)&local_6e0;
    if ((local_6a8[0] & 3) == 0) {
      XVar19 = param_1[0x1e18];
      if (XVar19 == (XavcsMovieReader)0x0) {
        iVar5 = 2;
        local_6dc = 4;
        local_6e0 = 0x2311;
        local_6de = 0xe1e;
        FUN_0020aff4(piVar8,8);
        goto LAB_00211bac;
      }
      iVar5 = Fsys_GetFreeSpace(uVar14,piVar8);
      if (iVar5 != 0) goto LAB_00211b30;
      uVar9 = (ulong)local_6c8 * (ulong)local_6c4 * (ulong)local_6dc;
      if (0x3bfffff < uVar9) {
        uVar15 = 0;
        if (local_5fa != '\0') {
          puVar12 = (uint *)(PTR_DAT_004027a8 + 4);
          uVar15 = 0;
          do {
            if (local_5e0 == puVar12[-1]) {
              uVar15 = *puVar12;
            }
            puVar12 = puVar12 + 2;
          } while ((uint *)(PTR_DAT_004027a8 + 100) != puVar12);
        }
        local_740 = 0;
        FUN_00354f88(*(undefined8 *)(param_1 + 0x1e10),&local_740);
        local_73c = 0;
        FUN_00354714(*(undefined8 *)(param_1 + 0x1e10),&local_73c);
        XVar3 = local_745;
        uVar9 = (ulong)local_740;
        if (local_745 == (XavcsMovieReader)0x0) {
          uVar16 = param_2[3];
          lVar2 = -(uVar9 * 0x30 + 0x16 & 0x7ffffffff0);
          puVar10 = (undefined4 *)(&stack0xfffffffffffff820 + lVar2);
          for (uVar13 = 0; uVar9 != uVar13; uVar13 = uVar13 + 1) {
            *(undefined1 *)(puVar10 + 8) = 0;
            *puVar10 = 0;
            puVar10[1] = 0;
            puVar10[2] = 0;
            *(undefined4 **)(puVar10 + 4) = puVar10 + 8;
            *(undefined8 *)(puVar10 + 6) = 0;
            puVar10 = puVar10 + 0xc;
          }
          FUN_00355004(*(undefined8 *)(param_1 + 0x1e10),0,uVar9,&stack0xfffffffffffff820 + lVar2,
                       &local_738);
          uVar6 = 0;
          piVar8 = (int *)(&stack0xfffffffffffff820 + lVar2);
          while (piVar8 != (int *)(&stack0xfffffffffffff820 + (ulong)local_738 * 0x30 + lVar2)) {
            piVar11 = piVar8 + 0xc;
            iVar5 = *piVar8;
            piVar8 = piVar11;
            if (iVar5 == local_744) {
              uVar6 = uVar6 + 1;
            }
          }
          iVar5 = 0;
          if (0x7f < (int)uVar6) {
            local_70c = 3;
            iVar5 = 5;
            local_710 = 0xe192311;
            local_708 = uVar6;
            FUN_0020aff4(&local_710,0xc);
          }
          local_734 = 0;
          if ((iVar5 == 0) &&
             (cVar4 = FUN_0020bd80(0,0,uVar16,&local_734,&stack0xfffffffffffff820 + lVar2,local_738)
             , cVar4 != '\0')) {
            local_70c = 3;
            local_710 = 0xe1a2311;
            local_708 = local_734;
            FUN_0020aff4(&local_710,0xc);
            for (uVar6 = 1; uVar6 < uVar15; uVar6 = uVar6 + 1) {
              uVar1 = uVar6 + uVar16;
              local_710 = 0;
              if ((uVar1 < local_73c) &&
                 (cVar4 = FUN_0020bd80(local_734,0,uVar1,&local_710,&stack0xfffffffffffff820 + lVar2
                                       ,local_738), cVar4 == '\0')) goto LAB_00211f94;
              if (uVar6 < uVar16) {
                cVar4 = FUN_0020bd80(local_734,1,uVar16 - uVar6,&local_710,
                                     &stack0xfffffffffffff820 + lVar2,local_738);
                uVar1 = uVar16 - uVar6;
                if (cVar4 == '\0') goto LAB_00211f94;
              }
            }
            iVar5 = 6;
            uVar1 = uVar16;
LAB_00211f94:
            uVar16 = uVar1;
            local_70c = 3;
            local_710 = 0xe1b2311;
            local_708 = uVar16;
            FUN_0020aff4(&local_710,0xc);
          }
          if (local_73c <= uVar16) {
            local_708 = local_73c;
            local_70c = 3;
            iVar5 = 6;
            local_710 = 0xe1c2311;
            FUN_0020aff4(&local_710,0xc);
          }
          local_730 = (void *)0x0;
          local_728 = (void *)0x0;
          local_720 = (void *)0x0;
          XVar18 = (XavcsMovieReader)0x0;
          if (iVar5 == 0) {
            iVar5 = XavcsMovieReader::OpenAndLockNrtFiles
                              (param_1,(recordInfo *)&local_620,&local_730,&local_728,&local_720);
            if (iVar5 == 0) {
              local_700 = local_6f0;
              uStack_6f8 = 0;
              local_6f0[0] = 0;
              local_710 = local_744;
              local_708 = 0;
              local_70c = uVar16;
              iVar7 = FUN_00355c8c(*(undefined8 *)(param_1 + 0x1e10),&local_710);
              iVar5 = 0;
              if (iVar7 != 0) {
                XVar19 = (XavcsMovieReader)0x0;
                iVar5 = 2;
                local_718 = (void *)0x40e1d2311;
                FUN_0020aff4(&local_718,8);
              }
              std::__cxx11::string::_M_dispose();
              XVar18 = XVar19;
            }
            else {
              iVar5 = 2;
              local_70c = 4;
              local_710 = 0x1e1b2311;
              FUN_0020aff4(&local_710,8);
            }
          }
          FUN_0020c050(param_1,&local_730,&local_728,&local_720);
          for (puVar17 = &stack0xfffffffffffff820 + uVar9 * 0x30 + lVar2;
              puVar17 != &stack0xfffffffffffff820 + lVar2; puVar17 = puVar17 + -0x30) {
            std::__cxx11::string::_M_dispose();
          }
        }
        else {
          lVar2 = -(uVar9 * 0x30 + 0x16 & 0x7ffffffff0);
          puVar10 = (undefined4 *)(&stack0xfffffffffffff820 + lVar2);
          for (uVar13 = 0; uVar9 != uVar13; uVar13 = uVar13 + 1) {
            *(undefined1 *)(puVar10 + 8) = 0;
            *puVar10 = 0;
            puVar10[1] = 0;
            puVar10[2] = 0;
            *(undefined4 **)(puVar10 + 4) = puVar10 + 8;
            *(undefined8 *)(puVar10 + 6) = 0;
            puVar10 = puVar10 + 0xc;
          }
          FUN_00355004(*(undefined8 *)(param_1 + 0x1e10),0,uVar9,&stack0xfffffffffffff820 + lVar2,
                       &local_730);
          local_728 = (void *)0x0;
          local_720 = (void *)0x0;
          local_718 = (void *)0x0;
          iVar5 = XavcsMovieReader::OpenAndLockNrtFiles
                            (param_1,(recordInfo *)&local_620,&local_728,&local_720,&local_718);
          if (iVar5 == 0) {
            XVar18 = (XavcsMovieReader)0x0;
            iVar5 = 4;
            for (uVar15 = 0; uVar15 < (uint)local_730; uVar15 = uVar15 + 1) {
              if (*(int *)(&stack0xfffffffffffff824 + (ulong)uVar15 * 0x30 + lVar2) == param_2[3]) {
                local_70c = 4;
                if (*(int *)(&stack0xfffffffffffff820 + (ulong)uVar15 * 0x30 + lVar2) - 10U < 2) {
                  iVar5 = 2;
                  local_710 = 0xe172311;
                  FUN_0020aff4(&local_710,8);
                }
                else {
                  iVar5 = 0;
                  local_710 = 0xe182311;
                  FUN_0020aff4(&local_710,8);
                  FUN_003552ec(*(undefined8 *)(param_1 + 0x1e10),uVar15);
                  XVar18 = XVar3;
                }
              }
            }
          }
          else {
            XVar18 = (XavcsMovieReader)0x0;
            iVar5 = 2;
            local_710 = 0x1e1a2311;
            local_70c = 4;
            FUN_0020aff4(&local_710,8);
          }
          FUN_0020c050(param_1,&local_728,&local_720,&local_718);
          for (puVar17 = &stack0xfffffffffffff820 + uVar9 * 0x30 + lVar2;
              puVar17 != &stack0xfffffffffffff820 + lVar2; puVar17 = puVar17 + -0x30) {
            std::__cxx11::string::_M_dispose();
          }
        }
        if (XVar18 != (XavcsMovieReader)0x0) {
          param_1[0x1e19] = (XavcsMovieReader)0x1;
          param_1[0x1e68] = (XavcsMovieReader)0x1;
        }
        goto LAB_00211bac;
      }
      local_708 = (uint)uVar9;
      piVar8 = &local_710;
      local_70c = 3;
      local_710 = 0xe162311;
    }
    else {
      local_6d8 = (uint)local_6a8[0];
      local_6dc = 3;
      local_6e0 = 0x2311;
      local_6de = 0xe14;
    }
    FUN_0020aff4(piVar8,0xc);
  }
LAB_00211b30:
  iVar5 = 0xb;
LAB_00211bac:
  if (*(long *)(param_1 + 0x18) != 0) {
    local_70c = 4;
    local_710 = 0x52311;
    FUN_0020aff4(&local_710,8);
    (**(code **)(param_1 + 0x18))(0x20000007,iVar5,param_2 + 1,4,*(undefined8 *)(param_1 + 0x20));
  }
  local_710 = 0xe1f2311;
  local_70c = 3;
  local_708 = iVar5;
  FUN_0020aff4(&local_710,0xc);
  mpr::thread::normalLock::unlock((normalLock *)(param_1 + 0x1e28));
  return 0;
}

