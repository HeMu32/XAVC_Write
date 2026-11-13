// mpr::ProvisionalRepairM4
// Ghidra address: 001bded4

/* mpr::ProvisionalRepairM4(unsigned int, bool, bool, unsigned int&, bool&, unsigned long&) */

int mpr::ProvisionalRepairM4
              (uint param_1,bool param_2,bool param_3,uint *param_4,bool *param_5,ulong *param_6)

{
  char cVar1;
  undefined1 uVar2;
  undefined *puVar3;
  undefined4 *puVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  undefined1 uVar8;
  undefined1 uVar9;
  undefined1 uVar10;
  undefined1 uVar11;
  undefined1 uVar12;
  char cVar13;
  int iVar14;
  uint uVar15;
  ulong uVar16;
  undefined8 *puVar17;
  char *pcVar18;
  string *psVar19;
  char *pcVar20;
  undefined8 uVar21;
  long lVar22;
  char *__s;
  uint uVar23;
  recordInfo *prVar24;
  string *psVar25;
  char cVar26;
  undefined4 local_1084;
  signed sStack_107d;
  int local_107c;
  undefined4 *local_1078;
  undefined4 *local_1070;
  undefined4 local_1068;
  undefined4 local_1064;
  undefined4 uStack_1060;
  undefined4 local_105c;
  undefined4 uStack_1058;
  set asStack_1050 [32];
  map amStack_1030 [8];
  undefined4 local_1028 [2];
  undefined8 local_1020;
  undefined4 *local_1018;
  undefined4 *puStack_1010;
  undefined8 local_1008;
  char local_1000 [104];
  ulong local_f98 [17];
  recordInfo arStack_f10 [32];
  string asStack_ef0 [32];
  undefined1 local_ed0 [32];
  undefined1 auStack_eb0 [32];
  undefined1 auStack_e90 [32];
  undefined1 auStack_e70 [32];
  undefined1 auStack_e50 [32];
  undefined1 auStack_e30 [32];
  undefined1 auStack_e10 [32];
  undefined1 auStack_df0 [32];
  undefined1 auStack_dd0 [32];
  undefined1 auStack_db0 [32];
  undefined1 auStack_d90 [32];
  undefined1 auStack_d70 [32];
  undefined1 auStack_d50 [32];
  undefined1 auStack_d30 [32];
  recordInfo arStack_d10 [12];
  undefined8 local_d04;
  undefined4 local_cfc;
  ushort local_cf6;
  string asStack_cf0 [4];
  char local_cec;
  char local_c50 [1056];
  undefined8 local_830;
  undefined8 uStack_828;
  undefined8 auStack_820 [37];
  undefined1 local_6f7;
  undefined1 local_6f6;
  undefined2 local_6f0;
  undefined2 uStack_6ee;
  undefined1 uStack_6ec;
  undefined1 uStack_6eb;
  undefined1 uStack_6ea;
  undefined1 uStack_6e9;
  int local_6e8;
  undefined *local_6e0;
  undefined *local_6d8;
  
  if (param_1 < 4) {
    uVar2 = PTR_g_msidconv_00401cd8[(ulong)param_1 * 0x80];
    local_1084 = *(undefined4 *)(PTR_g_msidconv_00401cd8 + (ulong)param_1 * 0x80 + 0x7c);
  }
  else {
    uVar2 = 0;
    local_1084 = 0xffffffff;
  }
  local_1064 = 0xffff;
  uStack_1060 = 0xffff;
  local_105c = 0xffff;
  uStack_1058 = 0xffff;
  local_1068 = local_1084;
  sidb::set::set(asStack_1050);
  local_1078 = (undefined4 *)0x0;
  local_1018 = local_1028;
  local_1028[0] = 0;
  local_1020 = 0;
  local_1008 = 0;
  puStack_1010 = local_1018;
  msidconv::GetLoadPathFromSlotID((msidconv *)PTR_g_msidconv_00401cd8,param_1,local_1000);
  *param_5 = false;
  FUN_001b7cd4(arStack_f10,"MAIN");
  FUN_001b7cd4(asStack_ef0,"CLIP/");
  FUN_001b7cd4(local_ed0,&DAT_003d7eaf);
  FUN_001b7cd4(auStack_eb0,&DAT_003d8132);
  FUN_001b7cd4(auStack_e90,"NRT");
  FUN_001b7cd4(auStack_e70,"CLIP/");
  FUN_001b7cd4(auStack_e50,&DAT_003d3aaf);
  FUN_001b7cd4(auStack_e30,&DAT_003d3527);
  FUN_001b7cd4(auStack_e10,&DAT_003d2e02);
  FUN_001b7cd4(auStack_df0,"THMBNL/");
  FUN_001b7cd4(auStack_dd0,&DAT_003d3ab3);
  FUN_001b7cd4(auStack_db0,&DAT_003d1f47);
  FUN_001b7cd4(auStack_d90,&DAT_003d3a9f);
  FUN_001b7cd4(auStack_d70,&DAT_003d34ab);
  FUN_001b7cd4(auStack_d50,&DAT_003d3ab7);
  FUN_001b7cd4(auStack_d30,&DAT_003d8132);
  iVar14 = MakeM4RootSubFolder(param_1);
  if (iVar14 == 0) {
    iVar14 = sidb::GetRootSet(1,&local_1068,5,0,1,0,asStack_1050);
    if (iVar14 == 0) {
      iVar14 = FindM4Object(param_1,(bool *)0x0,amStack_1030);
      if (iVar14 == 0) {
        local_6d8 = PTR_LAB_004015f8;
        local_6e0 = PTR_LAB_00401a00;
        iVar14 = sidb::set::sort<unsigned_short>(asStack_1050,6,(string *)&local_6f0);
        FUN_001aa68c((string *)&local_6f0);
        if (iVar14 != 0) goto LAB_001be0e0;
        uVar23 = 0;
        local_1078 = local_1018;
LAB_001be17c:
        uVar15 = sidb::set::size(asStack_1050);
        uVar11 = uStack_6e9;
        uVar9 = uStack_6ea;
        uVar7 = uStack_6eb;
        uVar5 = uStack_6ec;
        uStack_6ec = (undefined1)local_1084;
        uVar6 = uStack_6ec;
        uStack_6eb = (undefined1)((uint)local_1084 >> 8);
        uVar8 = uStack_6eb;
        uStack_6ea = (undefined1)((uint)local_1084 >> 0x10);
        uVar10 = uStack_6ea;
        uStack_6e9 = (undefined1)((uint)local_1084 >> 0x18);
        uVar12 = uStack_6e9;
        uStack_6ec = uVar5;
        uStack_6eb = uVar7;
        uStack_6ea = uVar9;
        uStack_6e9 = uVar11;
        if (uVar23 < uVar15) {
          sidb::recordInfo::clear(arStack_d10);
          if (local_1078 == local_1028) goto LAB_001be6f0;
          uVar15 = sidb::set::at(asStack_1050,uVar23);
          iVar14 = sidb::Select(0xffffffff,uVar15,arStack_d10,false);
          if (iVar14 == 0) {
LAB_001be1d0:
            puVar4 = local_1078;
            if (local_1078 != local_1028) {
              uVar16 = sidb::ConvDefStructLocalTime2SiDBUInt64((LocalTime *)(local_1078 + 0x14));
              if ((*param_6 & 0x7ffffffffff) < (uVar16 & 0x7ffffffffff)) {
                *param_6 = uVar16;
              }
              puVar3 = PTR_gp_paramBoard_00402470;
              if (*(ushort *)(puVar4 + 8) == local_cf6) {
                psVar25 = asStack_ef0;
                cVar26 = '\0';
                do {
                  psVar19 = psVar25 + -0x20;
                  cVar13 = FUN_001ba878(psVar19,"MAIN");
                  if (cVar13 == '\0') {
                    cVar13 = FUN_001ba878(psVar19,"NRT");
                    if (cVar13 == '\0') {
                      cVar13 = FUN_001ba878(psVar19,&DAT_003d2e02);
                      if (cVar13 == '\0') {
                        pcVar20 = (char *)(local_1078 + 0x24);
                        lVar22 = (long)local_1078 + 0x91;
                        uVar21 = *(undefined8 *)(local_1078 + 0x26);
                        __s = local_c50 + 0x316;
                        pcVar18 = local_c50 + 0x315;
                        puVar17 = &uStack_828;
                      }
                      else {
                        pcVar20 = (char *)(local_1078 + 0x20);
                        lVar22 = (long)local_1078 + 0x81;
                        uVar21 = *(undefined8 *)(local_1078 + 0x22);
                        __s = local_c50 + 0x20f;
                        pcVar18 = local_c50 + 0x20e;
                        puVar17 = auStack_820;
                      }
                    }
                    else {
                      puVar17 = (undefined8 *)0x0;
                      uVar21 = 0;
                      __s = local_c50 + 0x108;
                      pcVar20 = (char *)(local_1078 + 0x1c);
                      pcVar18 = local_c50 + 0x107;
                      lVar22 = (long)local_1078 + 0x71;
                    }
                  }
                  else {
                    __s = local_c50 + 1;
                    pcVar18 = local_c50;
                    pcVar20 = (char *)(local_1078 + 0x18);
                    lVar22 = (long)local_1078 + 0x61;
                    uVar21 = *(undefined8 *)(local_1078 + 0x1a);
                    puVar17 = &local_830;
                  }
                  cVar13 = *pcVar20;
                  cVar1 = *pcVar18;
                  if (cVar13 == '\0') {
                    if (cVar1 != '\0') {
                      *pcVar18 = '\0';
                      *__s = '\0';
                      cVar26 = cVar1;
                      if (puVar17 != (undefined8 *)0x0) {
                        *puVar17 = 0;
                      }
                    }
                  }
                  else if (cVar1 == '\0') {
                    *pcVar18 = '\x01';
                    if (puVar17 != (undefined8 *)0x0) {
                      *puVar17 = uVar21;
                    }
                    FUN_001b7eb8((string *)&local_6f0,uVar2);
                    std::__cxx11::string::operator+=((string *)&local_6f0,":");
                    std::__cxx11::string::operator+=((string *)&local_6f0,local_1000);
                    if (*(int *)(*(long *)puVar3 + (ulong)param_1 * 0x2c + 0x50) == 3) {
                      std::__cxx11::string::operator+=((string *)&local_6f0,"/PRIVATE");
                    }
                    std::__cxx11::string::operator+=((string *)&local_6f0,"/M4ROOT");
                    std::__cxx11::string::operator+=
                              ((string *)&local_6f0,(char *)((long)&DAT_003d7f63 + 1));
                    std::__cxx11::string::operator+=((string *)&local_6f0,psVar25);
                    std::__cxx11::string::operator+=
                              ((string *)&local_6f0,(string *)(local_1078 + 0xc));
                    if (local_1078[0x28] == 2) {
                      snprintf(__s,0x105,"%s%03d%s%s.%s",
                               CONCAT17(uStack_6e9,
                                        CONCAT16(uStack_6ea,
                                                 CONCAT15(uStack_6eb,
                                                          CONCAT14(uStack_6ec,
                                                                   CONCAT22(uStack_6ee,local_6f0))))
                                       ),(ulong)(*(ushort *)(local_1078 + 10) % 1000),
                               local_1078 + 0x29,*(undefined8 *)(psVar25 + 0x20),lVar22);
                    }
                    else {
                      snprintf(__s,0x105,"%s%04d%s.%s",
                               CONCAT17(uStack_6e9,
                                        CONCAT16(uStack_6ea,
                                                 CONCAT15(uStack_6eb,
                                                          CONCAT14(uStack_6ec,
                                                                   CONCAT22(uStack_6ee,local_6f0))))
                                       ),(ulong)*(ushort *)(local_1078 + 10),
                               *(undefined8 *)(psVar25 + 0x20));
                    }
                    std::__cxx11::string::_M_dispose();
                    cVar26 = cVar13;
                  }
                  puVar4 = local_1078;
                  psVar25 = psVar25 + 0x80;
                } while (psVar25 != asStack_cf0);
                if (local_cec != *(char *)(local_1078 + 0x17)) {
                  cVar26 = '\x01';
                  if (param_3) goto LAB_001be3d0;
LAB_001be538:
                  *param_5 = true;
                  local_d04 = *(undefined8 *)(local_1078 + 0x14);
                  local_cfc = local_1078[0x16];
                  local_cec = *(char *)(local_1078 + 0x17);
                  local_6f6 = 1;
                  local_6f7 = 0;
                  iVar14 = sidb::GetRemain(local_1084,0x80000000,&local_107c,0);
                  if (iVar14 != 0) goto LAB_001be6e8;
                  if (local_107c != 0) {
                    iVar14 = sidb::Update(0xffffffff,arStack_d10,false,false);
                    goto LAB_001be43c;
                  }
                  uStack_6eb = 0;
                  uStack_6ec = 4;
                  uStack_6ea = 0;
                  local_6f0 = 0x2300;
                  uStack_6e9 = 0;
                  uStack_6ee = 0x1902;
                  FUN_001b7d90((string *)&local_6f0,8);
                  iVar14 = 0;
                  goto LAB_001be5c4;
                }
                if (param_3) {
LAB_001be3d0:
                  memset((string *)&local_6f0,0,0x6f0);
                  ExistedFileInfo::ExistedFileInfo
                            ((ExistedFileInfo *)local_f98,(ExistedFileInfo *)(puVar4 + 10));
                  iVar14 = GetClipInfo(param_1,(ExistedFileInfo *)local_f98,(string *)&local_6f0);
                  std::__cxx11::string::_M_dispose();
                  if ((iVar14 == 0) &&
                     (iVar14 = FUN_002819f8(param_1,(string *)&local_6f0), iVar14 == 0))
                  goto LAB_001be534;
                  uVar15 = sidb::set::at(asStack_1050,uVar23);
                  iVar14 = sidb::Delete(0xffffffff,uVar15,false,false);
LAB_001be43c:
                  if (iVar14 != 0) goto LAB_001be6e8;
                }
                else {
LAB_001be534:
                  if (cVar26 != '\0') goto LAB_001be538;
                }
                if ((param_2) && (uVar15 = *param_4, *param_4 = uVar15 + 1, (uVar15 + 1) % 100 == 0)
                   ) {
                  evtRepairProgressParam::evtRepairProgressParam
                            ((evtRepairProgressParam *)&local_6f0);
                  local_6e8 = (int)((double)*param_4 * DAT_003d39f8);
                  uStack_6ec = uVar6;
                  uStack_6eb = uVar8;
                  uStack_6ea = uVar10;
                  uStack_6e9 = uVar12;
                  SetIssueEvent(0x1027,(string *)&local_6f0,0xc);
                }
                uVar23 = uVar23 + 1 & 0xffff;
                local_1078 = (undefined4 *)
                             std::
                             _Rb_tree<unsigned_short,std::pair<unsigned_short_const,mpr::ExistedFileInfo>,std::_Select1st<std::pair<unsigned_short_const,mpr::ExistedFileInfo>>,std::less<unsigned_short>,std::allocator<std::pair<unsigned_short_const,mpr::ExistedFileInfo>>>
                             ::erase_abi_cxx11_((_Rb_tree<unsigned_short,std::pair<unsigned_short_const,mpr::ExistedFileInfo>,std::_Select1st<std::pair<unsigned_short_const,mpr::ExistedFileInfo>>,std::less<unsigned_short>,std::allocator<std::pair<unsigned_short_const,mpr::ExistedFileInfo>>>
                                                 *)amStack_1030,local_1078);
              }
              else {
                if (*(ushort *)(puVar4 + 8) <= local_cf6) goto LAB_001be6dc;
                uVar15 = sidb::set::at(asStack_1050,uVar23);
                iVar14 = sidb::Delete(0xffffffff,uVar15,false,false);
                if (iVar14 != 0) goto LAB_001be6e8;
                uVar23 = uVar23 + 1 & 0xffff;
              }
            }
            goto LAB_001be17c;
          }
LAB_001be6e8:
          iVar14 = 2;
          goto LAB_001be5c4;
        }
LAB_001be730:
        local_1070 = local_1018;
        while( true ) {
          iVar14 = 0;
          if (local_1070 == local_1028) goto LAB_001be5c8;
          local_f98[0] = 0;
          *param_5 = true;
          iVar14 = sidb::GetRemain(local_1084,0x80000000,&local_107c,0);
          if (iVar14 != 0) break;
          if (local_107c == 0) {
            uStack_6eb = 0;
            uStack_6ec = 4;
            uStack_6ea = 0;
            local_6f0 = 0x2300;
            uStack_6e9 = 0;
            uStack_6ee = 0x1901;
            FUN_001b7d90((string *)&local_6f0,8);
            iVar14 = 0;
            goto LAB_001be5c4;
          }
          ExistedFileInfo::ExistedFileInfo
                    ((ExistedFileInfo *)&local_6f0,(ExistedFileInfo *)(local_1070 + 10));
          iVar14 = RegisterM4RecordInfoOnSidb(param_1,(string *)&local_6f0);
          std::__cxx11::string::_M_dispose();
          if (iVar14 != 0) goto LAB_001be5c4;
          sidb::ConvDefStructLocalTime2SiDBUInt64
                    ((LocalTime *)(local_1070 + 0x14),local_f98,&sStack_107d);
          if (*param_6 < local_f98[0]) {
            *param_6 = local_f98[0];
          }
          if (param_3) {
            memset((string *)&local_6f0,0,0x6f0);
            ExistedFileInfo::ExistedFileInfo
                      ((ExistedFileInfo *)arStack_d10,(ExistedFileInfo *)(local_1070 + 10));
            GetClipInfo(param_1,(ExistedFileInfo *)arStack_d10,(string *)&local_6f0);
            std::__cxx11::string::_M_dispose();
            FUN_002819f8(param_1,(string *)&local_6f0);
          }
          if ((param_2) && (uVar23 = *param_4, *param_4 = uVar23 + 1, (uVar23 + 1) % 100 == 0)) {
            evtRepairProgressParam::evtRepairProgressParam((evtRepairProgressParam *)&local_6f0);
            local_6e8 = (int)((double)*param_4 * DAT_003d39f8);
            uStack_6ec = uVar6;
            uStack_6eb = uVar8;
            uStack_6ea = uVar10;
            uStack_6e9 = uVar12;
            SetIssueEvent(0x1027,(string *)&local_6f0,0xc);
          }
          std::_Rb_tree_iterator<std::pair<unsigned_short_const,mpr::ExistedFileInfo>>::operator++
                    ((_Rb_tree_iterator<std::pair<unsigned_short_const,mpr::ExistedFileInfo>> *)
                     &local_1070);
        }
        iVar14 = 2;
LAB_001be5c4:
        if (iVar14 == 0) goto LAB_001be5c8;
      }
    }
    else {
LAB_001be0e0:
      iVar14 = 2;
    }
  }
  *param_5 = true;
LAB_001be5c8:
  prVar24 = arStack_d10;
  do {
    prVar24 = prVar24 + -0x80;
    std::__cxx11::string::_M_dispose();
    std::__cxx11::string::_M_dispose();
    std::__cxx11::string::_M_dispose();
    std::__cxx11::string::_M_dispose();
  } while (prVar24 != arStack_f10);
  std::
  _Rb_tree<unsigned_short,std::pair<unsigned_short_const,mpr::ExistedFileInfo>,std::_Select1st<std::pair<unsigned_short_const,mpr::ExistedFileInfo>>,std::less<unsigned_short>,std::allocator<std::pair<unsigned_short_const,mpr::ExistedFileInfo>>>
  ::~_Rb_tree((_Rb_tree<unsigned_short,std::pair<unsigned_short_const,mpr::ExistedFileInfo>,std::_Select1st<std::pair<unsigned_short_const,mpr::ExistedFileInfo>>,std::less<unsigned_short>,std::allocator<std::pair<unsigned_short_const,mpr::ExistedFileInfo>>>
               *)amStack_1030);
  sidb::set::~set(asStack_1050);
  return iVar14;
LAB_001be6f0:
  uVar15 = sidb::set::size(asStack_1050);
  if (uVar15 <= uVar23) goto LAB_001be730;
  uVar15 = sidb::set::at(asStack_1050,uVar23);
  iVar14 = sidb::Delete(0xffffffff,uVar15,false,false);
  if (iVar14 != 0) goto LAB_001be0e0;
  uVar23 = uVar23 + 1 & 0xffff;
  goto LAB_001be6f0;
LAB_001be6dc:
  std::_Rb_tree_iterator<std::pair<unsigned_short_const,mpr::ExistedFileInfo>>::operator++
            ((_Rb_tree_iterator<std::pair<unsigned_short_const,mpr::ExistedFileInfo>> *)&local_1078)
  ;
  goto LAB_001be1d0;
}

