// FUN_8078eccc
// Ghidra address: 8078eccc

int FUN_8078eccc(int param_1,char param_2)

{
  int iVar1;
  
  if ((param_2 == '\0') && (iVar1 = FUN_8079159c(), param_1 != iVar1)) {
    DAT_807c0368 = DAT_807c0368 | 0x20000000;
    param_1 = iVar1;
  }
  return param_1;
}

