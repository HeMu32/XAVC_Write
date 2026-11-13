// FUN_8078f184
// Ghidra address: 8078f184

uint FUN_8078f184(uint param_1)

{
  if (0xc < param_1) {
    param_1 = 0;
    DAT_807c0368 = DAT_807c0368 | 0x200;
  }
  return param_1;
}

