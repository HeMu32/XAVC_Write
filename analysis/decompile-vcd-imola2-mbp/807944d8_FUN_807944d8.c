// FUN_807944d8
// Ghidra address: 807944d8

int FUN_807944d8(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_8079408c(1);
  iVar2 = FUN_8079408c(param_1 - 1U);
  if (iVar1 != 0) {
    iVar2 = iVar2 - (1 << (param_1 - 1U & 0x1f));
  }
  return iVar2;
}

