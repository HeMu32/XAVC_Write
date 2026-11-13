// FUN_0033abf4
// Ghidra address: 0033abf4

undefined4 FUN_0033abf4(long param_1,undefined8 param_2,undefined8 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = FUN_00343584(*(undefined8 *)(param_1 + 8));
  uVar2 = FUN_00343200(*(undefined8 *)(param_1 + 8));
  *param_4 = uVar2;
  return uVar1;
}

