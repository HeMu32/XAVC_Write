// FUN_8078f13c
// Ghidra address: 8078f13c

uint FUN_8078f13c(uint param_1)

{
  if (0xc < param_1) {
    param_1 = 0;
    DAT_807c0368 = DAT_807c0368 | 0x100;
  }
  return param_1;
}

