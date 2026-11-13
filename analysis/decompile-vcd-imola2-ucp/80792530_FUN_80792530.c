// FUN_80792530
// Ghidra address: 80792530

int FUN_80792530(uint param_1,undefined4 *param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 local_30 [16];
  
  FUN_8078e980();
  FUN_807992fc();
  FUN_807992ec();
  iVar2 = 1 << (param_1 & 0x1f);
  if (0x1f < param_1) {
    iVar2 = 0x40000000;
  }
  uVar1 = FUN_8078e974();
  local_30[0] = 0;
  *param_2 = uVar1;
  FUN_80792cf4(local_30,param_3);
  FUN_80787a24(param_1,iVar2,*param_2);
  return iVar2;
}

