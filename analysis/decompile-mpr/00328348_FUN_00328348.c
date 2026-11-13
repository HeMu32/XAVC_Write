// FUN_00328348
// Ghidra address: 00328348

undefined4
FUN_00328348(long param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
            undefined4 *param_5)

{
  undefined4 uVar1;
  undefined8 local_88;
  long local_80;
  undefined4 local_78 [2];
  undefined8 local_70;
  undefined4 local_68;
  
  memset(local_78,0,0x78);
  FUN_002cedb8(*(undefined8 *)(param_1 + 0x108),*(undefined4 *)(param_1 + 0x2b0),param_4,0,local_78,
               0);
  local_88 = 0;
  FUN_002cf9d0(*(undefined8 *)(param_1 + 0x108),*(undefined4 *)(param_1 + 0x2b0),param_4,&local_88);
  uVar1 = FUN_00322428();
  local_80 = 0;
  FUN_00326cfc(param_1,local_88,*(undefined4 *)(param_1 + 0x2b4),90000);
  local_80 = local_80 + 90000;
  FUN_003265cc(param_1,local_68,*(undefined4 *)(param_1 + 0x2b4));
  *param_5 = local_78[0];
  *(undefined8 *)(param_5 + 2) = local_70;
  param_5[4] = (int)local_80;
  param_5[5] = 0;
  return uVar1;
}

