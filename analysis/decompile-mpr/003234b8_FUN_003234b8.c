// FUN_003234b8
// Ghidra address: 003234b8

undefined8 FUN_003234b8(long param_1,undefined8 param_2,ulong param_3,undefined8 param_4)

{
  undefined8 uVar1;
  
  if (8 < param_3) {
    FUN_002d4340(*(undefined8 *)(param_1 + 0xb0),*(undefined8 *)(param_1 + 0xa0),param_2,
                 (int)param_3 + -8,param_4);
    uVar1 = FUN_00322428();
    return uVar1;
  }
  return 3;
}

