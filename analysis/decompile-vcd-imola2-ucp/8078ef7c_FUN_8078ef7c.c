// FUN_8078ef7c
// Ghidra address: 8078ef7c

int FUN_8078ef7c(int param_1)

{
  if (0x18 < param_1 + 0xcU) {
    param_1 = 0;
    DAT_807c0368 = DAT_807c0368 | 0x80000;
  }
  return param_1;
}

