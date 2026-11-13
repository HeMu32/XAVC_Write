// FUN_8078eebc
// Ghidra address: 8078eebc

uint FUN_8078eebc(uint param_1)

{
  if (0x1f < param_1) {
    param_1 = 0;
    DAT_807c0368 = DAT_807c0368 | 0x10000;
  }
  return param_1;
}

