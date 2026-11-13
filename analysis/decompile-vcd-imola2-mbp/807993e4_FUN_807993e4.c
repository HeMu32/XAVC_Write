// FUN_807993e4
// Ghidra address: 807993e4

undefined4 FUN_807993e4(void)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar6 = *DAT_807c0b40;
  *DAT_807c0b40 = uVar6 | 2;
  if ((uVar6 & 1) == 0) {
    uVar6 = FUN_80791388();
  }
  else {
    uVar6 = *DAT_807c0b20 & 0x1f;
  }
  DAT_807c0b24[1] = 1;
  iVar2 = FUN_807927c0(uVar6);
  if ((iVar2 != 0) || (iVar2 = FUN_807927e0(uVar6), iVar2 != 0)) {
    iVar2 = FUN_80792720(uVar6);
    iVar3 = FUN_80792740(uVar6);
    puVar1 = DAT_807c0b24;
    DAT_807c0430 = DAT_807c0430 + iVar2 + 1;
    uVar4 = FUN_8079408c(iVar2 + 1);
    *puVar1 = uVar4;
    DAT_807c0430 = DAT_807c0430 + iVar3 + 1;
    uVar5 = FUN_8079408c(iVar3 + 1);
    uVar7 = 1;
    if (uVar5 < 0xb) {
      uVar7 = uVar5;
    }
    DAT_807c0b24[1] = uVar7;
  }
  iVar2 = FUN_80792760(uVar6);
  if (iVar2 == 0) {
    DAT_807c0b24[2] = DAT_807c0b24[2] | 0xf;
  }
  else {
    FUN_80799e78(uVar6);
  }
  return 1;
}

