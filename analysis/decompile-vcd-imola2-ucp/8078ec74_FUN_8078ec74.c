// FUN_8078ec74
// Ghidra address: 8078ec74

int FUN_8078ec74(int param_1,char param_2)

{
  int iVar1;
  
  if ((param_2 == '\0') && (iVar1 = FUN_80791590(), param_1 != iVar1)) {
    DAT_807c0368 = DAT_807c0368 | 0x10000000;
    param_1 = iVar1;
  }
  return param_1;
}

