// FUN_8078ec18
// Ghidra address: 8078ec18

uint FUN_8078ec18(uint param_1,char param_2)

{
  uint uVar1;
  
  if (param_2 == '\0') {
    uVar1 = FUN_80791584();
    if (param_1 != (uVar1 & 0xffff)) {
      DAT_807c0368 = DAT_807c0368 | 0x8000000;
      param_1 = uVar1 & 0xffff;
    }
  }
  return param_1;
}

