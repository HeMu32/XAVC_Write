// FUN_00351090
// Ghidra address: 00351090

undefined8 *
FUN_00351090(undefined8 *param_1,long param_2,long param_3,undefined8 param_4,undefined4 param_5)

{
  undefined8 uVar1;
  undefined1 auStack_190 [256];
  undefined8 local_90;
  undefined8 local_88 [5];
  undefined1 auStack_60 [96];
  
  param_3 = param_3 - param_2;
  if (param_3 == 0) {
    param_2 = 0;
  }
  FUN_002c6a84(auStack_190,param_2,param_2 + param_3,param_4,param_5);
  uVar1 = local_88[0];
  *param_1 = local_90;
  local_90 = 0;
  local_88[0] = 0;
  param_1[1] = uVar1;
  FUN_002bec70(auStack_60);
  std::__cxx11::string::_M_dispose();
  FUN_002bead4(local_88);
  std::__cxx11::string::_M_dispose();
  return param_1;
}

