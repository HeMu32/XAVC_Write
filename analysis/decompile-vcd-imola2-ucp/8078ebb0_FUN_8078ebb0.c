// FUN_8078ebb0
// Ghidra address: 8078ebb0

uint FUN_8078ebb0(uint param_1,char param_2)

{
  uint uVar1;
  
  if (param_2 == '\0') {
    uVar1 = FUN_80791578();
    if (param_1 == uVar1) {
      return param_1;
    }
  }
  else {
    if (param_1 < 0x10000) {
      return param_1;
    }
    uVar1 = 0;
  }
  DAT_807c0368 = DAT_807c0368 | 0x4000000;
  return uVar1;
}

