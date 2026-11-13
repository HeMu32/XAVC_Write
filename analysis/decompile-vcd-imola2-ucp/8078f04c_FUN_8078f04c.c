// FUN_8078f04c
// Ghidra address: 8078f04c

uint FUN_8078f04c(uint param_1)

{
  if ((6 < param_1 / 10) || (3 < param_1 % 10)) {
    param_1 = 0x34;
    DAT_807c0368 = DAT_807c0368 | 8;
  }
  return param_1;
}

