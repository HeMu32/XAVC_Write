// FUN_80799724
// Ghidra address: 80799724

undefined4 FUN_80799724(void)

{
  uint *puVar1;
  undefined2 uVar2;
  uint uVar3;
  
  puVar1 = DAT_807c0b2c;
  *DAT_807c0b40 = *DAT_807c0b40 | 0x40;
  uVar2 = FUN_80799324();
  *(undefined2 *)puVar1 = uVar2;
  puVar1 = DAT_807c0b2c;
  DAT_807c0430 = DAT_807c0430 + 1;
  uVar3 = FUN_8079408c(1);
  *puVar1 = *puVar1 & 0xfffeffff | (uVar3 & 1) << 0x10;
  puVar1 = DAT_807c0b2c;
  DAT_807c0430 = DAT_807c0430 + 1;
  uVar3 = FUN_8079408c(1);
  *puVar1 = *puVar1 & 0xfffdffff | (uVar3 & 1) << 0x11;
  puVar1 = DAT_807c0b2c;
  DAT_807c0430 = DAT_807c0430 + 2;
  uVar3 = FUN_8079408c(2);
  *puVar1 = *puVar1 & 0xfff3ffff | (uVar3 & 3) << 0x12;
  return 1;
}

