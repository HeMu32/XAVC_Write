// FUN_8078eee4
// Ghidra address: 8078eee4

uint FUN_8078eee4(uint param_1)

{
  if (0x1f < param_1) {
    param_1 = 0;
    DAT_807c0368 = DAT_807c0368 | 0x20000;
  }
  return param_1;
}

