// FUN_80790ecc
// Ghidra address: 80790ecc

void FUN_80790ecc(void)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  
  iVar2 = FUN_80791424();
  if ((iVar2 != 0) || (iVar2 = FUN_80791400(), iVar2 != 0)) {
    iVar3 = FUN_80791424();
    iVar2 = DAT_807c0a98;
    if (iVar3 != 0) {
      uVar5 = FUN_8079408c(1);
      *(uint *)(iVar2 + 0x1c) = *(uint *)(iVar2 + 0x1c) & 0xfffffbff | (uVar5 & 1) << 10;
    }
    iVar2 = DAT_807c0a98;
    uVar1 = FUN_807941d8();
    *(undefined1 *)(iVar2 + 0x22) = uVar1;
  }
  iVar2 = FUN_807929e8(*(undefined1 *)(DAT_807c0a98 + 3));
  if (iVar2 != 0) {
    uVar4 = FUN_80794188();
    iVar2 = DAT_807c0a98;
    uVar5 = FUN_8078ee08(uVar4);
    *(uint *)(iVar2 + 0x20) = *(uint *)(iVar2 + 0x20) & 0xffffff1f | (uVar5 & 7) << 5;
    if ((*(uint *)(DAT_807c0a98 + 0x20) & 0xff) >> 5 != 1) {
      uVar4 = FUN_807941d8();
      iVar2 = DAT_807c0a98;
      uVar5 = FUN_8078ee2c(uVar4);
      *(uint *)(iVar2 + 0x20) = *(uint *)(iVar2 + 0x20) & 0xf0ffffff | (uVar5 & 0xf) << 0x18;
      uVar4 = FUN_807941d8();
      iVar2 = DAT_807c0a98;
      iVar3 = FUN_8078ee54(uVar4);
      *(uint *)(iVar2 + 0x20) = *(uint *)(iVar2 + 0x20) & 0xfffffff | iVar3 << 0x1c;
    }
  }
  sony_ucp_write7(0x360,0);
  return;
}

