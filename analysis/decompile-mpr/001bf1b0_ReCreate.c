// mpr::ReCreate
// Ghidra address: 001bf1b0

/* mpr::ReCreate(unsigned int, bool*, bool&) */

int mpr::ReCreate(uint param_1,bool *param_2,bool *param_3)

{
  int iVar1;
  int iVar2;
  ulong uVar3;
  bool bVar4;
  undefined1 uVar5;
  undefined4 uVar6;
  bool local_d06;
  bool local_d05;
  uint local_d04;
  uint local_d00;
  undefined4 uStack_cfc;
  ulong local_ce0 [4];
  ulong local_cc0;
  undefined4 local_cb8 [2];
  undefined8 local_cb0;
  undefined4 *puStack_ca8;
  undefined4 *local_ca0;
  undefined8 uStack_c98;
  char acStack_c90 [104];
  undefined2 local_c28;
  undefined2 local_c26;
  undefined1 local_c24;
  undefined1 local_c23;
  undefined1 local_c22;
  undefined1 local_c21;
  uint local_c20;
  byte local_c02;
  uint auStack_af4 [701];
  
  uVar3 = (ulong)param_1;
  local_c24 = 3;
  local_c28 = 0x2300;
  local_c26 = 0xd00;
  local_c23 = 0;
  local_c22 = 0;
  local_c21 = 0;
  local_c20 = param_1;
  FUN_001b7d90((getStillRecStatusOutParam *)&local_c28,0xc);
  if (param_1 < 4) {
    uVar5 = PTR_g_msidconv_00401cd8[uVar3 * 0x80];
    uVar6 = *(undefined4 *)(PTR_g_msidconv_00401cd8 + uVar3 * 0x80 + 0x7c);
  }
  else {
    uVar6 = 0xffffffff;
    uVar5 = 0;
  }
  msidconv::GetLoadPathFromSlotID((msidconv *)PTR_g_msidconv_00401cd8,param_1,acStack_c90);
  *param_3 = false;
  if (PTR_sb_sidbLoaded_00401990[param_1] != '\0') {
LAB_001bf318:
    bVar4 = false;
    if (PTR_sb_mediaProLoaded_00401400[uVar3] != '\0') {
LAB_001bf438:
      if ((PTR_sb_sidbLoaded_00401990[param_1] != '\0') &&
         (PTR_sb_mediaProLoaded_00401400[param_1] != '\0')) {
        local_d04 = 0;
        local_d00 = 0;
        local_ce0[0] = 0;
        local_cc0 = 0;
        ProvisionalRepairDcf(param_1,true,&local_d04,&local_d06,(InhBit *)&local_d00,local_ce0);
        ProvisionalRepairM4(param_1,true,bVar4,&local_d04,&local_d05,&local_cc0);
        *param_3 = (bool)(local_d06 | local_d05);
        if ((bool)(local_d06 | local_d05) != false) {
          uVar3 = local_ce0[0];
          if (local_ce0[0] < local_cc0) {
            uVar3 = local_cc0;
          }
          sidb::SetHeaderParam<unsigned_long>(uVar6,3,uVar3);
        }
        if (local_d00 != 0) {
          getStillRecStatusOutParam::getStillRecStatusOutParam
                    ((getStillRecStatusOutParam *)&local_c28);
          GetStillRecStatusForUpdate((getStillRecStatusOutParam *)&local_c28);
          auStack_af4[(ulong)param_1 * 6] = auStack_af4[(ulong)param_1 * 6] | local_d00;
          SetStillRecStatus((getStillRecStatusOutParam *)&local_c28);
        }
      }
      FUN_0022bc00(param_1,1);
      iVar2 = capidtbl::RemakeCapIdTbl((LocalTime *)0x0);
      FUN_00231b90(0);
      FUN_0022d23c(0);
      goto LAB_001bf564;
    }
    puStack_ca8 = local_cb8;
    local_cb0 = 0;
    uStack_c98 = 0;
    local_cb8[0] = 0;
    local_ca0 = puStack_ca8;
    FUN_001b7eb8((string *)&local_d00,uVar5);
    std::__cxx11::string::push_back('\0');
    std::__cxx11::string::operator+=((string *)&local_d00,acStack_c90);
    if (*(int *)(*(long *)PTR_gp_paramBoard_00402470 + uVar3 * 0x2c + 0x50) == 3) {
      std::__cxx11::string::operator+=((string *)&local_d00,"/PRIVATE");
    }
    std::__cxx11::string::operator+=((string *)&local_d00,"/M4ROOT/MEDIAPRO.XML");
    iVar1 = Fsys_FindFirst(CONCAT44(uStack_cfc,local_d00),0xffffff80,
                           (getStillRecStatusOutParam *)&local_c28);
    if (iVar1 == 0) {
      if (((local_c02 >> 4 & 1) == 0) &&
         (iVar1 = Fsys_Remove(CONCAT44(uStack_cfc,local_d00)), iVar1 != 0)) goto LAB_001bf5d8;
LAB_001bf3cc:
      iVar2 = fs::MkMultiDir((char *)CONCAT44(uStack_cfc,local_d00),0,true,true);
      if (iVar2 == 0) {
        std::__cxx11::string::string((string *)local_ce0,(string *)&local_d00);
        iVar2 = MakeMediaPro(param_1,(string *)local_ce0);
        std::__cxx11::string::_M_dispose();
        if (iVar2 == 0) {
          PTR_sb_mediaProLoaded_00401400[param_1] = 1;
          bVar4 = true;
          std::__cxx11::string::_M_dispose();
          std::
          _Rb_tree<unsigned_short,std::pair<unsigned_short_const,mpr::ExistedFileInfo>,std::_Select1st<std::pair<unsigned_short_const,mpr::ExistedFileInfo>>,std::less<unsigned_short>,std::allocator<std::pair<unsigned_short_const,mpr::ExistedFileInfo>>>
          ::~_Rb_tree((_Rb_tree<unsigned_short,std::pair<unsigned_short_const,mpr::ExistedFileInfo>,std::_Select1st<std::pair<unsigned_short_const,mpr::ExistedFileInfo>>,std::less<unsigned_short>,std::allocator<std::pair<unsigned_short_const,mpr::ExistedFileInfo>>>
                       *)&local_cc0);
          goto LAB_001bf438;
        }
      }
    }
    else {
      if (iVar1 == 2) goto LAB_001bf3cc;
LAB_001bf5d8:
      iVar2 = 0xb;
    }
    std::__cxx11::string::_M_dispose();
    std::
    _Rb_tree<unsigned_short,std::pair<unsigned_short_const,mpr::ExistedFileInfo>,std::_Select1st<std::pair<unsigned_short_const,mpr::ExistedFileInfo>>,std::less<unsigned_short>,std::allocator<std::pair<unsigned_short_const,mpr::ExistedFileInfo>>>
    ::~_Rb_tree((_Rb_tree<unsigned_short,std::pair<unsigned_short_const,mpr::ExistedFileInfo>,std::_Select1st<std::pair<unsigned_short_const,mpr::ExistedFileInfo>>,std::less<unsigned_short>,std::allocator<std::pair<unsigned_short_const,mpr::ExistedFileInfo>>>
                 *)&local_cc0);
    goto LAB_001bf564;
  }
  FUN_001b7eb8((string *)&local_d00,uVar5);
  std::__cxx11::string::push_back('\0');
  std::__cxx11::string::operator+=((string *)&local_d00,acStack_c90);
  std::__cxx11::string::operator+=((string *)&local_d00,"/PRIVATE/DATABASE/DATABASE.BIN");
  iVar1 = Fsys_FindFirst(CONCAT44(uStack_cfc,local_d00),0xffffff80,
                         (getStillRecStatusOutParam *)&local_c28);
  if (iVar1 == 0) {
    if (((local_c02 >> 4 & 1) == 0) &&
       (iVar1 = Fsys_Remove(CONCAT44(uStack_cfc,local_d00)), iVar1 != 0)) goto LAB_001bf558;
LAB_001bf2ac:
    FUN_001b7cd4(local_ce0,acStack_c90);
    FUN_001b7cd4(&local_cc0,"/PRIVATE/DATABASE/DATABASE.BIN");
    iVar1 = sidb::CreateDBFile(uVar6,uVar5,local_ce0,&local_cc0);
    std::__cxx11::string::_M_dispose();
    iVar2 = 2;
    std::__cxx11::string::_M_dispose();
    if (iVar1 == 0) {
      PTR_sb_sidbLoaded_00401990[param_1] = 1;
      std::__cxx11::string::_M_dispose();
      goto LAB_001bf318;
    }
  }
  else {
    if (iVar1 == 2) goto LAB_001bf2ac;
LAB_001bf558:
    iVar2 = 0xb;
  }
  std::__cxx11::string::_M_dispose();
LAB_001bf564:
  local_c23 = 0;
  local_c24 = 3;
  local_c22 = 0;
  local_c28 = 0x2300;
  local_c21 = 0;
  local_c26 = 0xd0f;
  local_c20 = (uint)*param_3;
  FUN_001b7d90((getStillRecStatusOutParam *)&local_c28,0xc);
  return iVar2;
}

