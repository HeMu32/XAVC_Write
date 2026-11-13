// FUN_003285d0
// Ghidra address: 003285d0

void FUN_003285d0(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined4 uVar1;
  
  uVar1 = FUN_003285bc(param_1,*(undefined4 *)(param_1 + 8));
  FUN_002d95d8(*(undefined8 *)(param_1 + 0xb0),uVar1,*(undefined8 *)(param_1 + 0xa0),param_2,
               0x6d646174,param_3,param_4);
  FUN_00322428();
  return;
}

