// FUN_807997d0
// Ghidra address: 807997d0

undefined4 FUN_807997d0(void)

{
  uint *puVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  
  uVar2 = FUN_80791770();
  puVar1 = DAT_807c0b30;
  *DAT_807c0b40 = *DAT_807c0b40 | 0x80;
  DAT_807c0430 = DAT_807c0430 + 1;
  uVar3 = FUN_8079408c(1);
  *puVar1 = *puVar1 & 0xfffffffe | uVar3 & 1;
  puVar1 = DAT_807c0b30;
  uVar3 = FUN_80799324();
  *puVar1 = *puVar1 & 0xfffe0001 | (uVar3 & 0xffff) << 1;
  iVar4 = FUN_807925f4(uVar2);
  puVar1 = DAT_807c0b30;
  if (iVar4 == 0) {
    DAT_807c0430 = DAT_807c0430 + 1;
    uVar3 = FUN_8079408c(1);
    *puVar1 = *puVar1 & 0xfffdffff | (uVar3 & 1) << 0x11;
    puVar1 = DAT_807c0b30;
    if ((int)(*DAT_807c0b30 << 0xe) < 0) {
      DAT_807c0430 = DAT_807c0430 + 1;
      uVar3 = FUN_8079408c(1);
      *puVar1 = *puVar1 & 0xfffbffff | (uVar3 & 1) << 0x12;
    }
  }
  return 1;
}

