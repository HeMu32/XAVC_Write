// FUN_00326618
// Ghidra address: 00326618

undefined4
FUN_00326618(long param_1,undefined8 param_2,undefined4 param_3,undefined1 *param_4,
            undefined4 *param_5,undefined8 param_6)

{
  undefined4 uVar1;
  undefined8 local_18;
  ulong local_10;
  undefined8 local_8;
  
  *param_4 = 1;
  *param_5 = 0;
  FUN_002cb93c(param_2,param_3);
  FUN_002cba30(param_2,0);
  local_8 = 0;
  local_18 = 0;
  local_10 = 0;
  FUN_002cba80(param_2,0,1,&local_18);
  uVar1 = FUN_00322428();
  FUN_003265cc(param_1,local_10 & 0xffffffff,*(undefined4 *)(param_1 + 0x1cc),90000,param_6);
  FUN_002cb914(param_2,0);
  return uVar1;
}

