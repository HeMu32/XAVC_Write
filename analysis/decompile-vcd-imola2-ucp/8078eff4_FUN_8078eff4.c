// FUN_8078eff4
// Ghidra address: 8078eff4

uint FUN_8078eff4(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_1 & 0xff;
  if (uVar2 != 100) {
    if (uVar2 < 0x65) {
      uVar1 = 0x4d;
      if (uVar2 == 0x42) {
        return param_1;
      }
    }
    else {
      if (uVar2 == 0x6e) {
        return param_1;
      }
      uVar1 = 0x7a;
    }
    if (uVar2 != uVar1) {
      param_1 = 100;
      DAT_807c0368 = DAT_807c0368 | 4;
    }
  }
  return param_1;
}

