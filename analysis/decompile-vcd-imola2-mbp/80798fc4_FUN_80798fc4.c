// FUN_80798fc4
// Ghidra address: 80798fc4

undefined4 FUN_80798fc4(uint param_1)

{
  int iVar1;
  
  DAT_807c0430 = DAT_807c0430 + param_1 * 8;
  iVar1 = (int)param_1 >> 2;
  if (0 < iVar1) {
    do {
      iVar1 = iVar1 + -1;
      FUN_8079408c(0x20);
    } while (iVar1 != 0);
  }
  FUN_8079408c((param_1 & 3) << 3);
  return 1;
}

