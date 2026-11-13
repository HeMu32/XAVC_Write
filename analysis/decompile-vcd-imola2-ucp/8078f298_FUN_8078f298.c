// FUN_8078f298
// Ghidra address: 8078f298

uint FUN_8078f298(uint param_1)

{
  uint uVar1;
  
  param_1 = param_1 & 0x1f;
  uVar1 = 0x1f;
  if (((0xb < param_1) || (uVar1 = 1, param_1 < 5)) && (param_1 != uVar1)) {
    param_1 = 0x1f;
    DAT_807c0368 = DAT_807c0368 | 1;
  }
  return param_1;
}

