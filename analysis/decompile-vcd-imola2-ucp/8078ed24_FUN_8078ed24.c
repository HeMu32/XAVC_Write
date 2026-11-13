// FUN_8078ed24
// Ghidra address: 8078ed24

int FUN_8078ed24(int param_1,char param_2)

{
  int iVar1;
  
  if ((param_2 == '\0') && (iVar1 = FUN_807915a8(), param_1 != iVar1)) {
    DAT_807c0368 = DAT_807c0368 | 0x40000000;
    param_1 = iVar1;
  }
  return param_1;
}

