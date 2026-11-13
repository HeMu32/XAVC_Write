// FUN_8078ee7c
// Ghidra address: 8078ee7c

uint FUN_8078ee7c(uint param_1)

{
  if (0xff < param_1) {
    param_1 = 0;
    DAT_807c0368 = DAT_807c0368 | 0x4000;
  }
  return param_1;
}

