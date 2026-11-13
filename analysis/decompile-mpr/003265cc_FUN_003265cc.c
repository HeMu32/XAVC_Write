// FUN_003265cc
// Ghidra address: 003265cc

void FUN_003265cc(undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 *param_5)

{
  int iVar1;
  undefined4 uVar2;
  ulong local_8;
  
  FUN_002c78a0(param_2,param_3,param_4,&local_8);
  iVar1 = FUN_00322428();
  if (iVar1 == 0) {
    uVar2 = (undefined4)local_8;
    if (0xffffffff < local_8) {
      uVar2 = 0xffffffff;
    }
    *param_5 = uVar2;
  }
  return;
}

