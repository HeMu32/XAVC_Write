// FUN_8078ee2c
// Ghidra address: 8078ee2c

int FUN_8078ee2c(int param_1)

{
  if (0xc < param_1 + 6U) {
    param_1 = 0;
    DAT_807c0368 = DAT_807c0368 | 0x20;
  }
  return param_1;
}

