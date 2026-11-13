// mpr::IntegPlayGetRecordInfo
// Ghidra address: 001c3228

/* mpr::IntegPlayGetRecordInfo(sidb::recordInfo&) */

int mpr::IntegPlayGetRecordInfo(recordInfo *param_1)

{
  int iVar1;
  undefined2 local_68;
  undefined2 local_66;
  undefined1 local_64;
  undefined1 local_63;
  undefined1 local_62;
  undefined1 local_61;
  int local_60;
  undefined2 local_48;
  undefined2 local_46;
  undefined1 local_44;
  undefined1 local_43;
  undefined1 local_42;
  undefined1 local_41;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined2 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 uStack_4;
  
  local_43 = 0;
  local_44 = 4;
  local_42 = 0;
  local_48 = 0x2160;
  local_41 = 0;
  local_46 = 0x1f0;
  FUN_001bf858(&local_48,8);
  local_30 = 1;
  local_2c = 0;
  local_28 = 0;
  local_3c = 0;
  local_38 = 0xff;
  local_18 = 0;
  local_14 = 0;
  local_34 = 3;
  local_24 = 3;
  local_10 = 0;
  local_c = 0;
  local_8 = 1;
  uStack_4 = 1;
  local_20 = 0x14d4015;
  local_1c = 100;
  FUN_001bf7c4(&local_68,param_1 + 0xc1);
  iVar1 = IntegPlayGetRecordInfoFromMp4(&local_68,&local_48);
  std::__cxx11::string::_M_dispose();
  if (iVar1 == 0) {
    param_1[0x26] = 1;
    *(undefined4 *)(param_1 + 0x28) = local_3c;
    param_1[0x94] = 1;
    *(undefined4 *)(param_1 + 0x2c) = local_38;
    *(undefined4 *)(param_1 + 0x30) = local_34;
    *(undefined4 *)(param_1 + 0x40) = local_24;
    *(undefined4 *)(param_1 + 0x38) = local_2c;
    *(undefined4 *)(param_1 + 0x3c) = local_28;
    *(undefined4 *)(param_1 + 0x98) = local_14;
    *(undefined4 *)(param_1 + 0x9c) = local_10;
    *(undefined4 *)(param_1 + 0xa0) = local_c;
    *(undefined4 *)(param_1 + 0xa4) = local_8;
  }
  local_64 = 3;
  local_63 = 0;
  local_68 = 0x2160;
  local_62 = 0;
  local_66 = 0x1f8;
  local_61 = 0;
  local_60 = iVar1;
  FUN_001bf858(&local_68,0xc);
  return iVar1;
}

