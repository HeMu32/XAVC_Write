// FUN_00354f88
// Ghidra address: 00354f88

void FUN_00354f88(long param_1,int *param_2)

{
  int iVar1;
  
  if (param_2 == (int *)0x0) {
    iVar1 = 2;
  }
  else {
    iVar1 = FUN_0033abec(*(undefined8 *)(param_1 + 8));
    if ((iVar1 == 4) || (iVar1 = FUN_0033abec(*(undefined8 *)(param_1 + 8)), iVar1 == 5)) {
      FUN_00354e3c(param_1);
      *param_2 = (int)(*(long *)(param_1 + 0x20) - *(long *)(param_1 + 0x18) >> 2) * -0x55555555;
      iVar1 = 0;
    }
    else {
      iVar1 = 3;
    }
  }
  NRTERRCNV::ConvToMPR2(iVar1);
  return;
}

