// FUN_80796334
// Ghidra address: 80796334

undefined4 FUN_80796334(uint param_1)

{
  uint uVar1;
  
  DAT_807c03e8 = DAT_807c03e8 + param_1 * 8;
  uVar1 = 0;
  if (param_1 >> 2 != 0) {
    do {
      uVar1 = uVar1 + 1;
      FUN_8079408c(0x20);
    } while (uVar1 < param_1 >> 2);
  }
  FUN_8079408c((param_1 & 3) << 3);
  return 1;
}

