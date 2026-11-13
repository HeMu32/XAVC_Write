// FUN_18001e1f0
// VA 18001e1f0

undefined8 FUN_18001e1f0(longlong param_1,int param_2,int *param_3)

{
  undefined8 uVar1;
  
  if (*(int *)(param_1 + 0x2dc) != 0) {
    uVar1 = FUN_1800204b0(param_1,param_2,param_3);
    *(int *)(param_1 + 0x2dc) = 0;
    return uVar1;
  }
  return 0;
}

