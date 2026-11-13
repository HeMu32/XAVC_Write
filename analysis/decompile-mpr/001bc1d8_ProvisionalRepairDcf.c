// mpr::ProvisionalRepairDcf
// Ghidra address: 001bc1d8

/* mpr::ProvisionalRepairDcf(unsigned int, bool, unsigned int&, bool&, mpr::InhBit&, unsigned long&)
    */

int mpr::ProvisionalRepairDcf
              (uint param_1,bool param_2,uint *param_3,bool *param_4,InhBit *param_5,ulong *param_6)

{
  string *psVar1;
  char cVar2;
  undefined1 uVar3;
  undefined2 uVar4;
  undefined *puVar5;
  undefined *puVar6;
  _Rb_tree_node *p_Var7;
  char cVar8;
  int iVar9;
  uint uVar10;
  _List_node_base *p_Var11;
  _Rb_tree_node *p_Var12;
  ulong uVar13;
  char *pcVar14;
  _Rb_tree_node_base *p_Var15;
  set *this;
  _Rb_tree_node *p_Var16;
  undefined4 *puVar17;
  undefined4 uVar18;
  char *pcVar19;
  char *__s;
  uint uVar20;
  undefined8 ****ppppuVar21;
  undefined8 ****ppppuVar22;
  undefined8 ****ppppuVar23;
  char cVar24;
  undefined8 ****ppppuVar25;
  long local_8d0;
  int local_8a0;
  uint local_89c;
  int local_890;
  int local_88c;
  undefined4 *local_888;
  uint local_880 [6];
  undefined8 ***local_868;
  undefined8 ***pppuStack_860;
  long local_858;
  undefined8 ***local_850;
  undefined8 ***pppuStack_848;
  long local_840;
  set asStack_838 [32];
  set asStack_818 [32];
  set asStack_7f8 [32];
  undefined4 *local_7d8;
  undefined8 uStack_7d0;
  undefined1 local_7c8 [16];
  ulong local_7b8 [4];
  map amStack_798 [8];
  undefined4 local_790 [2];
  _Rb_tree_node *local_788;
  _Rb_tree_node_base *local_780;
  _Rb_tree_node_base *local_778;
  undefined8 local_770;
  _Rb_tree<unsigned_short,std::pair<unsigned_short_const,mpr::ExistedFileInfo>,std::_Select1st<std::pair<unsigned_short_const,mpr::ExistedFileInfo>>,std::less<unsigned_short>,std::allocator<std::pair<unsigned_short_const,mpr::ExistedFileInfo>>>
  local_768 [8];
  undefined4 local_760 [2];
  undefined8 local_758;
  undefined4 *local_750;
  undefined4 *local_748;
  undefined8 local_740;
  undefined2 local_738;
  undefined2 uStack_736;
  undefined1 uStack_734;
  undefined1 uStack_733;
  undefined1 uStack_732;
  undefined1 uStack_731;
  int local_730 [2];
  undefined *local_728;
  undefined *local_720;
  _Rb_tree_node_base local_710;
  char local_708 [104];
  string asStack_6a0 [32];
  undefined1 auStack_680 [32];
  undefined1 auStack_660 [32];
  undefined1 auStack_640 [32];
  uint local_620;
  uint local_61c;
  int local_618;
  undefined4 uStack_614;
  undefined4 local_610;
  undefined4 uStack_60c;
  undefined8 local_608;
  int local_600;
  char local_5fc;
  char local_560 [1064];
  undefined4 local_138 [2];
  undefined4 auStack_130 [2];
  undefined4 auStack_128 [2];
  undefined4 auStack_120 [70];
  undefined1 local_7;
  undefined1 local_6;
  byte local_4;
  
  if (param_1 < 4) {
    uVar3 = PTR_g_msidconv_00401cd8[(ulong)param_1 * 0x80];
    local_89c = *(uint *)(PTR_g_msidconv_00401cd8 + (ulong)param_1 * 0x80 + 0x7c);
  }
  else {
    uVar3 = 0;
    local_89c = 0xffffffff;
  }
  local_880[1] = 0xffff;
  local_880[2] = 0xffff;
  local_880[3] = 0xffff;
  local_880[4] = 0xffff;
  local_880[0] = local_89c;
  sidb::set::set(asStack_838);
  sidb::set::set(asStack_818);
  FUN_001b7cd4(asStack_6a0,&DAT_003d1f47);
  FUN_001b7cd4(auStack_680,&DAT_003d3bff);
  FUN_001b7cd4(auStack_660,&DAT_003d1c61);
  FUN_001b7cd4(auStack_640,&DAT_003d3c04);
  local_780 = (_Rb_tree_node_base *)local_790;
  local_858 = 0;
  local_840 = 0;
  local_790[0] = 0;
  local_788 = (_Rb_tree_node *)0x0;
  local_770 = 0;
  local_868 = &local_868;
  pppuStack_860 = &local_868;
  local_850 = &local_850;
  pppuStack_848 = &local_850;
  local_778 = local_780;
  msidconv::GetLoadPathFromSlotID((msidconv *)PTR_g_msidconv_00401cd8,param_1,local_708);
  *param_4 = false;
  iVar9 = sidb::GetRootSet(1,local_880,6,0,1,0,asStack_838);
  if (iVar9 == 0) {
    local_608 = PTR__M_invoke_00401638;
    local_620 = (local_620 >> 8 & 0xff) << 8;
    local_61c = local_61c & 0xffffff00;
    local_610 = SUB84(PTR__M_manager_004015a0,0);
    uStack_60c = (undefined4)((ulong)PTR__M_manager_004015a0 >> 0x20);
    iVar9 = sidb::Refine<sidb::DirNumberChangeCheckInfo>
                      (0xffffffff,asStack_838,5,(recordInfo *)&local_620,asStack_818);
    FUN_001aa68c((recordInfo *)&local_620);
    uVar20 = 0;
    if (iVar9 != 0) goto LAB_001bc334;
    for (; uVar10 = sidb::set::size(asStack_818), uVar20 < uVar10; uVar20 = uVar20 + 1 & 0xffff) {
      sidb::recordInfo::clear((recordInfo *)&local_620);
      uVar10 = sidb::set::at(asStack_818,uVar20);
      iVar9 = sidb::Select(0xffffffff,uVar10,(recordInfo *)&local_620,false);
      if (iVar9 != 0) goto LAB_001bc334;
      p_Var11 = operator_new(0x18);
      *(undefined2 *)(p_Var11 + 0x10) = (undefined2)local_608;
      std::__detail::_List_node_base::_M_hook(p_Var11);
      local_840 = local_840 + 1;
    }
    iVar9 = sidb::GetRemain(local_89c,1,&local_890,1);
    if (iVar9 != 0) goto LAB_001bc334;
    local_8a0 = FindDcfFolder(param_1,(bool *)0x0,true,amStack_798);
    iVar9 = local_8a0;
    if (local_8a0 == 0) {
      p_Var7 = local_788;
      p_Var16 = (_Rb_tree_node *)local_790;
      while (p_Var12 = p_Var7, p_Var12 != (_Rb_tree_node *)0x0) {
        if (*(ushort *)(p_Var12 + 0x20) < 999) {
          p_Var7 = *(_Rb_tree_node **)(p_Var12 + 0x18);
        }
        else {
          p_Var7 = *(_Rb_tree_node **)(p_Var12 + 0x10);
          p_Var16 = p_Var12;
        }
      }
      if ((p_Var16 != (_Rb_tree_node *)local_790) && (*(ushort *)(p_Var16 + 0x20) < 1000)) {
        *(undefined4 *)param_5 = 4;
      }
      for (p_Var15 = local_780; puVar6 = PTR__M_manager_00402178, puVar5 = PTR__M_invoke_00401ce8,
          p_Var15 != (_Rb_tree_node_base *)local_790;
          p_Var15 = (_Rb_tree_node_base *)std::_Rb_tree_increment(p_Var15)) {
        sidb::set::set(asStack_7f8);
        uVar4 = *(undefined2 *)(p_Var15 + 0x20);
        local_750 = local_760;
        local_888 = (undefined4 *)0x0;
        local_760[0] = 0;
        local_758 = 0;
        local_740 = 0;
        psVar1 = (string *)(p_Var15 + 0x30);
        local_748 = local_750;
        std::__cxx11::string::string((string *)&local_620,psVar1);
        iVar9 = FindDcfObject(param_1,0,1,(string *)&local_620,local_768);
        std::__cxx11::string::_M_dispose();
        if (iVar9 != 0) {
LAB_001bc564:
          std::
          _Rb_tree<unsigned_short,std::pair<unsigned_short_const,mpr::ExistedFileInfo>,std::_Select1st<std::pair<unsigned_short_const,mpr::ExistedFileInfo>>,std::less<unsigned_short>,std::allocator<std::pair<unsigned_short_const,mpr::ExistedFileInfo>>>
          ::~_Rb_tree(local_768);
          sidb::set::~set(asStack_7f8);
          ppppuVar22 = (undefined8 ****)local_850;
          if (iVar9 != 0) goto LAB_001bc578;
          goto LAB_001bd05c;
        }
        local_620 = CONCAT22(local_620._2_2_,uVar4);
        local_608 = PTR__M_invoke_00401ce8;
        local_610 = SUB84(PTR__M_manager_00402178,0);
        uStack_60c = (undefined4)((ulong)PTR__M_manager_00402178 >> 0x20);
        iVar9 = sidb::Refine<unsigned_short>
                          (0xffffffff,asStack_838,5,(string *)&local_620,asStack_7f8);
        FUN_001aa68c((string *)&local_620);
        ppppuVar22 = (undefined8 ****)local_850;
        ppppuVar21 = &local_850;
        if (iVar9 != 0) {
LAB_001bc560:
          iVar9 = 2;
          goto LAB_001bc564;
        }
        while (ppppuVar25 = ppppuVar21, ppppuVar23 = ppppuVar22, ppppuVar23 != &local_850) {
          ppppuVar22 = (undefined8 ****)*ppppuVar23;
          ppppuVar21 = ppppuVar25;
          if ((*(short *)(ppppuVar23 + 2) == *(short *)(p_Var15 + 0x20)) &&
             (ppppuVar21 = ppppuVar23, p_Var15 + 0x20 != (_Rb_tree_node_base *)(ppppuVar23 + 2))) {
            local_840 = local_840 + -1;
            std::__detail::_List_node_base::_M_unhook();
            operator_delete(ppppuVar23);
            ppppuVar21 = ppppuVar25;
          }
        }
        if (ppppuVar25 != &local_850) {
          local_840 = local_840 + -1;
          std::__detail::_List_node_base::_M_unhook();
          operator_delete(ppppuVar25);
        }
        local_608 = PTR_LAB_004015f8;
        local_610 = SUB84(PTR_LAB_00401a00,0);
        uStack_60c = (undefined4)((ulong)PTR_LAB_00401a00 >> 0x20);
        iVar9 = sidb::set::sort<unsigned_short>(asStack_7f8,6,(string *)&local_620);
        FUN_001aa68c((string *)&local_620);
        if (iVar9 != 0) goto LAB_001bc560;
        uVar20 = 0;
        local_888 = local_750;
        while( true ) {
          uVar10 = sidb::set::size(asStack_7f8);
          if (uVar10 <= uVar20) break;
          sidb::recordInfo::clear((recordInfo *)&local_620);
          local_7c8[0] = 0;
          uStack_7d0 = 0;
          local_7d8 = (undefined4 *)local_7c8;
          uVar10 = sidb::set::at(asStack_7f8,uVar20);
          if (local_888 == local_760) {
            std::__cxx11::string::_M_dispose();
            goto LAB_001bccb0;
          }
          iVar9 = sidb::Select(0xffffffff,uVar10,(string *)&local_620,false);
          if (iVar9 != 0) {
LAB_001bcb88:
            std::__cxx11::string::_M_dispose();
            goto LAB_001bc560;
          }
LAB_001bc6d0:
          puVar17 = local_888;
          if (local_888 != local_760) {
            uVar13 = sidb::ConvDefStructLocalTime2SiDBUInt64((LocalTime *)(local_888 + 0x14));
            if ((*param_6 & 0x7ffffffffff) < (uVar13 & 0x7ffffffffff)) {
              *param_6 = uVar13;
            }
            if (*(ushort *)(puVar17 + 8) == local_608._2_2_) {
              cVar24 = '\0';
              local_8d0 = 0;
              do {
                std::__cxx11::string::string((string *)local_7b8,asStack_6a0 + local_8d0);
                cVar8 = FUN_001ba878((string *)local_7b8,&DAT_003d1f47);
                if (cVar8 == '\0') {
                  cVar8 = FUN_001ba878((string *)local_7b8,&DAT_003d3bff);
                  if (cVar8 == '\0') {
                    cVar8 = FUN_001ba878((string *)local_7b8,&DAT_003d1c61);
                    if (cVar8 == '\0') {
                      pcVar19 = (char *)(local_888 + 0x24);
                      uVar18 = 0;
                      __s = local_560 + 0x316;
                      pcVar14 = local_560 + 0x315;
                      puVar17 = auStack_120;
                    }
                    else {
                      pcVar19 = (char *)(local_888 + 0x20);
                      uVar18 = (undefined4)*(undefined8 *)(local_888 + 0x22);
                      __s = local_560 + 0x20f;
                      pcVar14 = local_560 + 0x20e;
                      puVar17 = auStack_128;
                    }
                  }
                  else {
                    __s = local_560 + 0x108;
                    pcVar19 = (char *)(local_888 + 0x1c);
                    uVar18 = (undefined4)*(undefined8 *)(local_888 + 0x1e);
                    pcVar14 = local_560 + 0x107;
                    puVar17 = auStack_130;
                  }
                }
                else {
                  __s = local_560 + 1;
                  pcVar19 = (char *)(local_888 + 0x18);
                  uVar18 = (undefined4)*(undefined8 *)(local_888 + 0x1a);
                  pcVar14 = local_560;
                  puVar17 = local_138;
                }
                cVar8 = *pcVar19;
                cVar2 = *pcVar14;
                if (cVar8 == '\0') {
                  if (cVar2 != '\0') {
                    *pcVar14 = '\0';
                    *__s = '\0';
                    *puVar17 = 0;
                    cVar24 = cVar2;
                  }
                }
                else if (cVar2 == '\0') {
                  *pcVar14 = '\x01';
                  *puVar17 = uVar18;
                  FUN_001b7eb8((string *)&local_738,uVar3);
                  std::__cxx11::string::operator+=((string *)&local_738,":");
                  std::__cxx11::string::operator+=((string *)&local_738,local_708);
                  std::__cxx11::string::operator+=((string *)&local_738,"/DCIM");
                  std::__cxx11::string::operator+=
                            ((string *)&local_738,(char *)((long)&DAT_003d7f63 + 1));
                  std::__cxx11::string::operator+=((string *)&local_738,psVar1);
                  std::__cxx11::string::operator+=
                            ((string *)&local_738,(char *)((long)&DAT_003d7f63 + 1));
                  std::__cxx11::string::operator+=((string *)&local_738,(string *)(local_888 + 0xc))
                  ;
                  snprintf(__s,0x105,"%s%04d.%s",
                           CONCAT17(uStack_731,
                                    CONCAT16(uStack_732,
                                             CONCAT15(uStack_733,
                                                      CONCAT14(uStack_734,
                                                               CONCAT22(uStack_736,local_738))))),
                           (ulong)*(ushort *)(local_888 + 10),local_7b8[0]);
                  std::__cxx11::string::_M_dispose();
                  cVar24 = cVar8;
                }
                std::__cxx11::string::_M_dispose();
                local_8d0 = local_8d0 + 0x20;
              } while (local_8d0 != 0x80);
              if (local_5fc != *(char *)(local_888 + 0x17)) {
                cVar24 = '\x01';
              }
              if (((p_Var15[0x50] != (_Rb_tree_node_base)0x0) ||
                  (*(char *)((long)local_888 + 0x5d) != '\0')) || (cVar24 != '\0')) {
                *param_4 = true;
                uStack_60c = local_888[0x16];
                local_5fc = *(char *)(local_888 + 0x17);
                local_6 = 1;
                uStack_614 = (undefined4)*(undefined8 *)(local_888 + 0x14);
                local_610 = (undefined4)((ulong)*(undefined8 *)(local_888 + 0x14) >> 0x20);
                local_7 = 0;
                local_4 = local_4 & 0xf0 |
                          local_4 & 3 |
                          (((byte)p_Var15[0x50] | *(byte *)((long)local_888 + 0x5d)) & 1) << 2 |
                          (*(byte *)((long)local_888 + 0x5e) & 1) << 3;
                iVar9 = sidb::GetRemain(local_89c,0x80000000,&local_88c,0);
                if (iVar9 != 0) goto LAB_001bcb88;
                if (local_88c != 0) {
                  iVar9 = sidb::Update(0xffffffff,(string *)&local_620,false,false);
                  if (iVar9 == 0) goto LAB_001bcbb4;
                  goto LAB_001bcb88;
                }
                uStack_733 = 0;
                uStack_734 = 4;
                uStack_732 = 0;
                local_738 = 0x2300;
                uStack_731 = 0;
                uStack_736 = 0x1803;
                FUN_001b7d90(&local_738,8);
                std::__cxx11::string::_M_dispose();
                goto LAB_001bc938;
              }
              if (*(char *)((long)local_888 + 0x5e) != '\0') {
                sidb::PartialUpdate<bool>(0xffffffff,uVar10,0x69,1,0,1);
              }
LAB_001bcbb4:
              if ((param_2) && (uVar10 = *param_3, *param_3 = uVar10 + 1, (uVar10 + 1) % 100 == 0))
              {
                evtRepairProgressParam::evtRepairProgressParam((evtRepairProgressParam *)&local_738)
                ;
                uStack_734 = (undefined1)local_89c;
                uStack_733 = (undefined1)(local_89c >> 8);
                uStack_732 = (undefined1)(local_89c >> 0x10);
                uStack_731 = (undefined1)(local_89c >> 0x18);
                local_730[0] = (int)((double)*param_3 * DAT_003d39f0);
                SetIssueEvent(0x1027,(evtRepairProgressParam *)&local_738,0xc);
              }
              uVar20 = uVar20 + 1 & 0xffff;
              local_888 = (undefined4 *)
                          std::
                          _Rb_tree<unsigned_short,std::pair<unsigned_short_const,mpr::ExistedFileInfo>,std::_Select1st<std::pair<unsigned_short_const,mpr::ExistedFileInfo>>,std::less<unsigned_short>,std::allocator<std::pair<unsigned_short_const,mpr::ExistedFileInfo>>>
                          ::erase_abi_cxx11_(local_768,local_888);
            }
            else {
              if (*(ushort *)(puVar17 + 8) <= local_608._2_2_) goto LAB_001bcc98;
              if (local_600 - 1U < 2) {
                FUN_001ba90c(&local_868,&local_618);
              }
              uVar10 = sidb::set::at(asStack_7f8,uVar20);
              iVar9 = sidb::Delete(0xffffffff,uVar10,false,false);
              if (iVar9 != 0) goto LAB_001bcb88;
              local_890 = local_890 + 1;
              uVar20 = uVar20 + 1 & 0xffff;
            }
          }
          std::__cxx11::string::_M_dispose();
        }
LAB_001bcd44:
        local_7d8 = local_750;
LAB_001bcd64:
        if (local_7d8 != local_760) {
          local_7b8[0] = 0;
          *param_4 = true;
          if (local_890 == 0) {
            local_61c = 4;
            local_620 = 0x18022300;
            FUN_001b7d90(&local_620,8);
LAB_001bc938:
            std::
            _Rb_tree<unsigned_short,std::pair<unsigned_short_const,mpr::ExistedFileInfo>,std::_Select1st<std::pair<unsigned_short_const,mpr::ExistedFileInfo>>,std::less<unsigned_short>,std::allocator<std::pair<unsigned_short_const,mpr::ExistedFileInfo>>>
            ::~_Rb_tree(local_768);
            sidb::set::~set(asStack_7f8);
            goto LAB_001bc948;
          }
          iVar9 = sidb::GetRemain(local_89c,0x80000000,&local_88c,0);
          if (iVar9 == 0) {
            if (local_88c == 0) {
              local_61c = 4;
              local_620 = 0x18042300;
              FUN_001b7d90((string *)&local_620,8);
              iVar9 = 0;
            }
            else {
              local_738 = *(undefined2 *)(p_Var15 + 0x28);
              std::__cxx11::string::string((string *)local_730,psVar1);
              local_710 = p_Var15[0x50];
              ExistedFileInfo::ExistedFileInfo
                        ((ExistedFileInfo *)&local_620,(ExistedFileInfo *)(local_7d8 + 10));
              iVar9 = RegisterDcfRecordInfoOnSidb(param_1,(signed *)&local_738,(string *)&local_620)
              ;
              std::__cxx11::string::_M_dispose();
              std::__cxx11::string::_M_dispose();
              if (iVar9 == 0) goto code_r0x001bce70;
            }
            goto LAB_001bc564;
          }
          goto LAB_001bc560;
        }
        std::
        _Rb_tree<unsigned_short,std::pair<unsigned_short_const,mpr::ExistedFileInfo>,std::_Select1st<std::pair<unsigned_short_const,mpr::ExistedFileInfo>>,std::less<unsigned_short>,std::allocator<std::pair<unsigned_short_const,mpr::ExistedFileInfo>>>
        ::~_Rb_tree(local_768);
        sidb::set::~set(asStack_7f8);
      }
      this = (set *)&local_738;
      for (ppppuVar22 = (undefined8 ****)local_850; ppppuVar22 != &local_850;
          ppppuVar22 = (undefined8 ****)*ppppuVar22) {
        sidb::set::set(this);
        local_620 = CONCAT22(local_620._2_2_,*(undefined2 *)(ppppuVar22 + 2));
        local_610 = SUB84(puVar6,0);
        uStack_60c = (undefined4)((ulong)puVar6 >> 0x20);
        local_608 = puVar5;
        iVar9 = sidb::Refine<unsigned_short>(0xffffffff,asStack_838,5,&local_620,this);
        FUN_001aa68c(&local_620);
        if (iVar9 != 0) goto LAB_001bcff8;
        for (uVar20 = 0; uVar10 = sidb::set::size(this), uVar20 < uVar10;
            uVar20 = uVar20 + 1 & 0xffff) {
          uVar10 = sidb::set::at(this,uVar20);
          iVar9 = sidb::Delete(0xffffffff,uVar10,false,false);
          if (iVar9 != 0) goto LAB_001bcff8;
        }
        sidb::set::~set(this);
      }
LAB_001bc948:
      ppppuVar22 = (undefined8 ****)local_850;
      if ((undefined8 ****)local_868 == &local_868) goto LAB_001bd05c;
      this = (set *)local_7b8;
      sidb::set::set(this);
      iVar9 = sidb::GetRootSet(1,local_880,6,0,1,0,this);
      if (iVar9 == 0) {
        ppppuVar22 = (undefined8 ****)local_868;
        if ((undefined8 ****)local_868 != &local_868) {
          while (ppppuVar21 = ppppuVar22, ppppuVar22 = (undefined8 ****)*ppppuVar21,
                ppppuVar22 != &local_868) {
            if (*(int *)(ppppuVar21 + 2) == *(int *)(ppppuVar22 + 2)) {
              local_858 = local_858 + -1;
              std::__detail::_List_node_base::_M_unhook();
              operator_delete(ppppuVar22);
              ppppuVar22 = ppppuVar21;
            }
          }
        }
        puVar6 = PTR__M_manager_00402f30;
        puVar5 = PTR__M_invoke_00401530;
        for (ppppuVar22 = (undefined8 ****)local_868; ppppuVar22 != &local_868;
            ppppuVar22 = (undefined8 ****)*ppppuVar22) {
          sidb::set::set((set *)local_768);
          local_620 = *(uint *)(ppppuVar22 + 2);
          local_610 = SUB84(puVar6,0);
          uStack_60c = (undefined4)((ulong)puVar6 >> 0x20);
          local_608 = puVar5;
          iVar9 = sidb::Refine<unsigned_int>
                            (0xffffffff,this,2,(recordInfo *)&local_620,(set *)local_768);
          FUN_001aa68c((recordInfo *)&local_620);
          if (iVar9 != 0) {
LAB_001bd040:
            sidb::set::~set((set *)local_768);
            goto LAB_001bcff8;
          }
          iVar9 = sidb::set::size((set *)local_768);
          if (iVar9 != 0) {
            local_610 = 0;
            uStack_60c = 0;
            local_720 = PTR_LAB_004026d8;
            local_728 = PTR_FUN_00402048;
            FUN_001aa290((recordInfo *)&local_620,&local_738,2);
            local_608 = local_720;
            local_610 = SUB84(local_728,0);
            uStack_60c = (undefined4)((ulong)local_728 >> 0x20);
            sidb::set::sort_i<unsigned_int>((set *)local_768,7,(recordInfo *)&local_620);
            FUN_001aa68c((recordInfo *)&local_620);
            FUN_001aa68c(&local_738);
            sidb::recordInfo::clear((recordInfo *)&local_620);
            uVar20 = sidb::set::at((set *)local_768,0);
            iVar9 = sidb::Select(0xffffffff,uVar20,(recordInfo *)&local_620,false);
            if (iVar9 == 0) {
              local_608._0_5_ = CONCAT14(1,(undefined4)local_608);
              iVar9 = sidb::set::size((set *)local_768);
              if (iVar9 == 1) {
                local_600 = 0;
              }
              iVar9 = sidb::Update(0xffffffff,(recordInfo *)&local_620,false,false);
              if (iVar9 == 0) goto LAB_001bcac8;
            }
            goto LAB_001bd040;
          }
LAB_001bcac8:
          sidb::set::~set((set *)local_768);
        }
        sidb::set::~set(this);
        local_8a0 = 0;
        ppppuVar22 = (undefined8 ****)local_850;
        goto LAB_001bd05c;
      }
LAB_001bcff8:
      sidb::set::~set(this);
      goto LAB_001bc334;
    }
  }
  else {
LAB_001bc334:
    iVar9 = 2;
  }
LAB_001bc578:
  *param_4 = true;
  ppppuVar22 = (undefined8 ****)local_850;
  local_8a0 = iVar9;
LAB_001bd05c:
  while (ppppuVar21 = (undefined8 ****)local_868, ppppuVar22 != &local_850) {
    ppppuVar21 = (undefined8 ****)*ppppuVar22;
    operator_delete(ppppuVar22);
    ppppuVar22 = ppppuVar21;
  }
  while (ppppuVar21 != &local_868) {
    ppppuVar22 = (undefined8 ****)*ppppuVar21;
    operator_delete(ppppuVar21);
    ppppuVar21 = ppppuVar22;
  }
  std::
  _Rb_tree<unsigned_short,std::pair<unsigned_short_const,mpr::ExistedFolderInfo>,std::_Select1st<std::pair<unsigned_short_const,mpr::ExistedFolderInfo>>,std::less<unsigned_short>,std::allocator<std::pair<unsigned_short_const,mpr::ExistedFolderInfo>>>
  ::_M_erase((_Rb_tree<unsigned_short,std::pair<unsigned_short_const,mpr::ExistedFolderInfo>,std::_Select1st<std::pair<unsigned_short_const,mpr::ExistedFolderInfo>>,std::less<unsigned_short>,std::allocator<std::pair<unsigned_short_const,mpr::ExistedFolderInfo>>>
              *)amStack_798,local_788);
  std::__cxx11::string::_M_dispose();
  std::__cxx11::string::_M_dispose();
  std::__cxx11::string::_M_dispose();
  std::__cxx11::string::_M_dispose();
  sidb::set::~set(asStack_818);
  sidb::set::~set(asStack_838);
  return local_8a0;
LAB_001bccb0:
  uVar10 = sidb::set::size(asStack_7f8);
  if (uVar10 <= uVar20) goto LAB_001bcd44;
  sidb::recordInfo::clear((recordInfo *)&local_620);
  uVar10 = sidb::set::at(asStack_7f8,uVar20);
  iVar9 = sidb::Select(0xffffffff,uVar10,(string *)&local_620,false);
  if (iVar9 != 0) goto LAB_001bc560;
  if (local_600 - 1U < 2) {
    FUN_001ba90c(&local_868,&local_618);
  }
  uVar10 = sidb::set::at(asStack_7f8,uVar20);
  iVar9 = sidb::Delete(0xffffffff,uVar10,false,false);
  if (iVar9 != 0) goto LAB_001bc560;
  local_890 = local_890 + 1;
  uVar20 = uVar20 + 1 & 0xffff;
  goto LAB_001bccb0;
code_r0x001bce70:
  local_890 = local_890 + -1;
  sidb::ConvDefStructLocalTime2SiDBUInt64
            ((LocalTime *)(local_7d8 + 0x14),local_7b8,(signed *)&local_738);
  if (*param_6 < local_7b8[0]) {
    *param_6 = local_7b8[0];
  }
  if ((param_2) && (uVar20 = *param_3, *param_3 = uVar20 + 1, (uVar20 + 1) % 100 == 0)) {
    evtRepairProgressParam::evtRepairProgressParam((evtRepairProgressParam *)&local_620);
    local_61c = local_89c;
    local_618 = (int)((double)*param_3 * DAT_003d39f0);
    SetIssueEvent(0x1027,(string *)&local_620,0xc);
  }
  std::_Rb_tree_iterator<std::pair<unsigned_short_const,mpr::ExistedFileInfo>>::operator++
            ((_Rb_tree_iterator<std::pair<unsigned_short_const,mpr::ExistedFileInfo>> *)&local_7d8);
  goto LAB_001bcd64;
LAB_001bcc98:
  std::_Rb_tree_iterator<std::pair<unsigned_short_const,mpr::ExistedFileInfo>>::operator++
            ((_Rb_tree_iterator<std::pair<unsigned_short_const,mpr::ExistedFileInfo>> *)&local_888);
  goto LAB_001bc6d0;
}

