// FUN_00354094
// Ghidra address: 00354094

void FUN_00354094(long param_1,undefined1 *param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  uVar2 = *(undefined8 *)(param_1 + 8);
  *param_2 = 0;
  param_2[8] = 0;
  param_2[0x10] = 0;
  iVar1 = FUN_0033ada8(uVar2);
  NRTERRCNV::ConvToMPR2(iVar1);
  return;
}

