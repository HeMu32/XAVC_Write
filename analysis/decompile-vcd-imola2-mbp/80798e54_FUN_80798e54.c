// FUN_80798e54
// Ghidra address: 80798e54

undefined4 FUN_80798e54(void)

{
  uint *puVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  *DAT_807c0b40 = *DAT_807c0b40 | 1;
  uVar2 = FUN_80799324();
  puVar1 = DAT_807c0b20;
  uVar3 = FUN_8078f0a0(uVar2);
  *puVar1 = *puVar1 & 0xffffffe0 | uVar3 & 0x1f;
  uVar3 = *DAT_807c0b20 & 0x1f;
  iVar4 = FUN_807927e0(uVar3);
  if (iVar4 != 0) {
    iVar4 = FUN_80792700(uVar3);
    iVar4 = iVar4 + 1;
    uVar6 = 0;
    while( true ) {
      uVar5 = FUN_807927a0(uVar3);
      puVar1 = DAT_807c0b20;
      if (uVar5 < uVar6) break;
      DAT_807c0430 = DAT_807c0430 + iVar4;
      uVar5 = FUN_8079408c(iVar4);
      puVar1[uVar6 * 2 + 1] = uVar5;
      puVar1 = DAT_807c0b20;
      DAT_807c0430 = DAT_807c0430 + iVar4;
      uVar5 = FUN_8079408c(iVar4);
      puVar1[uVar6 * 2 + 2] = uVar5;
      uVar6 = uVar6 + 1;
    }
  }
  iVar4 = FUN_807927c0(uVar3);
  if (iVar4 != 0) {
    iVar4 = FUN_80792700(uVar3);
    iVar4 = iVar4 + 1;
    uVar6 = 0;
    while( true ) {
      uVar5 = FUN_807927a0(uVar3);
      puVar1 = DAT_807c0b20;
      if (uVar5 < uVar6) break;
      DAT_807c0430 = DAT_807c0430 + iVar4;
      uVar5 = FUN_8079408c(iVar4);
      puVar1[uVar6 * 2 + 0x41] = uVar5;
      puVar1 = DAT_807c0b20;
      DAT_807c0430 = DAT_807c0430 + iVar4;
      uVar5 = FUN_8079408c(iVar4);
      puVar1[uVar6 * 2 + 0x42] = uVar5;
      uVar6 = uVar6 + 1;
    }
  }
  return 1;
}

