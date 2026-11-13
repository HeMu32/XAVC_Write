// FUN_00353e8c
// Ghidra address: 00353e8c

void FUN_00353e8c(long param_1,long param_2,int param_3)

{
  int iVar1;
  
  if (param_2 == 0 || param_3 == 0) {
    iVar1 = 2;
  }
  else {
    iVar1 = FUN_0033abf4(*(undefined8 *)(param_1 + 8));
  }
  NRTERRCNV::ConvToMPR2(iVar1);
  return;
}

