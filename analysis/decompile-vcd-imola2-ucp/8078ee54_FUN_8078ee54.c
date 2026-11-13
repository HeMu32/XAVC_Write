// FUN_8078ee54
// Ghidra address: 8078ee54

int FUN_8078ee54(int param_1)

{
  if (0xc < param_1 + 6U) {
    param_1 = 0;
    DAT_807c0368 = DAT_807c0368 | 0x40;
  }
  return param_1;
}

