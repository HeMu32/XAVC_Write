// FUN_8078f160
// Ghidra address: 8078f160

uint FUN_8078f160(uint param_1)

{
  if (2 < param_1) {
    param_1 = 0;
    DAT_807c0368 = DAT_807c0368 | 0x200;
  }
  return param_1;
}

