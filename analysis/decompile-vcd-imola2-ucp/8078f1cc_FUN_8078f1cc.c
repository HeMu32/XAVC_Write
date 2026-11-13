// FUN_8078f1cc
// Ghidra address: 8078f1cc

uint FUN_8078f1cc(uint param_1)

{
  uint uVar1;
  
  uVar1 = 5;
  if (4 < param_1) {
    if (param_1 < 0x200) {
      return param_1;
    }
    uVar1 = 0x1ff;
  }
  DAT_807c0368 = DAT_807c0368 | 0x1000;
  return uVar1;
}

