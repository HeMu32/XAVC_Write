// FUN_8078f264
// Ghidra address: 8078f264

uint FUN_8078f264(uint param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = (param_1 & 0xff) >> 5;
  if (uVar1 == 0 && param_2 == 5) {
    uVar1 = 1;
    DAT_807c0368 = DAT_807c0368 | 2;
  }
  return uVar1;
}

