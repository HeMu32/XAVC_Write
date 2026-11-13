// FUN_00351108
// Ghidra address: 00351108

undefined4 * FUN_00351108(undefined4 *param_1,undefined8 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  locale alStack_68 [8];
  long local_60;
  long lStack_58;
  undefined4 local_40 [2];
  locale alStack_38 [8];
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_20 [2];
  locale alStack_18 [8];
  undefined8 local_10;
  undefined8 local_8;
  
  FUN_00345568(&local_60);
  std::locale::locale(alStack_68,(locale *)(param_1 + 2));
  local_40[0] = param_3;
  std::locale::locale(alStack_38,alStack_68);
  FUN_00351090(&local_30,local_60,local_60 + lStack_58,alStack_38,local_40[0]);
  local_20[0] = local_40[0];
  std::locale::locale(alStack_18,alStack_38);
  local_10 = local_30;
  local_30 = 0;
  local_8 = local_28;
  uVar1 = *param_1;
  *param_1 = local_20[0];
  local_28 = 0;
  local_20[0] = uVar1;
  FUN_00350aa4((locale *)(param_1 + 2),alStack_18);
  uVar2 = *(undefined8 *)(param_1 + 4);
  *(undefined8 *)(param_1 + 4) = local_10;
  uVar3 = *(undefined8 *)(param_1 + 6);
  *(undefined8 *)(param_1 + 6) = local_8;
  local_10 = uVar2;
  local_8 = uVar3;
  FUN_0034de2c(local_20);
  FUN_0034de2c(local_40);
  std::locale::~locale(alStack_68);
  std::__cxx11::string::_M_dispose();
  return param_1;
}

