// FUN_8078ea68
// Ghidra address: 8078ea68

uint FUN_8078ea68(uint param_1,char param_2)

{
  uint uVar1;
  
  if (param_2 == '\0') {
    uVar1 = FUN_8079155c();
    if (param_1 != uVar1) {
      DAT_807c0368 = DAT_807c0368 | 0x800000;
      param_1 = uVar1;
    }
  }
  else {
    uVar1 = param_1;
    if (0xff < param_1) {
      DAT_807c0368 = DAT_807c0368 | 0x4000;
      uVar1 = 0;
    }
    if ((DAT_807c0368 & 0x4000) != 0) {
      DAT_807c0368 = DAT_807c0368 | 0x800000;
      param_1 = uVar1;
    }
  }
  return param_1;
}

