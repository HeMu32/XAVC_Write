// FUN_00327690
// Ghidra address: 00327690

undefined4
FUN_00327690(long param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4,long *param_5)

{
  undefined4 uVar1;
  undefined4 local_14;
  undefined8 local_10;
  long local_8;
  
  local_14 = 0;
  local_10 = 0;
  FUN_002cf9d0(param_2,param_3,param_4,&local_10,&local_14);
  uVar1 = FUN_00322428();
  local_8 = 0;
  FUN_00326cfc(param_1,local_10,*(undefined4 *)(param_1 + 0x1cc),90000);
  *param_5 = local_8 + 90000;
  return uVar1;
}

