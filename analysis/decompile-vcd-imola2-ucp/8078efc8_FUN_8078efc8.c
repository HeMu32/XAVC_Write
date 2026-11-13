// FUN_8078efc8
// Ghidra address: 8078efc8

int FUN_8078efc8(int param_1)

{
  if (0x18 < param_1 + 0xcU) {
    param_1 = 0;
    DAT_807c0368 = DAT_807c0368 | 0x200000;
  }
  return param_1;
}

