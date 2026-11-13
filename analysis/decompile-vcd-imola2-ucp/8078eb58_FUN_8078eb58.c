// FUN_8078eb58
// Ghidra address: 8078eb58

int FUN_8078eb58(int param_1,char param_2)

{
  int iVar1;
  
  if ((param_2 == '\0') && (iVar1 = FUN_80791568(), param_1 != iVar1)) {
    DAT_807c0368 = DAT_807c0368 | 0x2000000;
    param_1 = iVar1;
  }
  return param_1;
}

