// FUN_8078f0a0
// Ghidra address: 8078f0a0

uint FUN_8078f0a0(uint param_1)

{
  if (0x1f < param_1) {
    param_1 = 0;
    DAT_807c0368 = DAT_807c0368 | 0x10;
  }
  return param_1;
}

