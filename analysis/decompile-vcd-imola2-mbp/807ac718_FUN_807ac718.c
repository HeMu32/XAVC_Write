// FUN_807ac718
// Ghidra address: 807ac718

void FUN_807ac718(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 8);
  uVar1 = FUN_8079408c(3);
  *(uint *)(iVar3 + 0x94) = *(uint *)(iVar3 + 0x94) & 0xfffffff8 | uVar1 & 7;
  uVar1 = FUN_8079408c(1);
  uVar1 = *(uint *)(iVar3 + 0x94) & 0xfffffff7 | (uVar1 & 1) << 3;
  *(uint *)(iVar3 + 0x94) = uVar1;
  if ((int)(uVar1 << 0x1c) < 0) {
    uVar1 = FUN_8079408c(8);
    *(uint *)(iVar3 + 0x94) = *(uint *)(iVar3 + 0x94) & 0xfffff00f | (uVar1 & 0xff) << 4;
    uVar1 = FUN_8079408c(8);
    *(uint *)(iVar3 + 0x94) = *(uint *)(iVar3 + 0x94) & 0xfff00fff | (uVar1 & 0xff) << 0xc;
    uVar1 = FUN_8079408c(8);
    *(uint *)(iVar3 + 0x94) = *(uint *)(iVar3 + 0x94) & 0xf00fffff | (uVar1 & 0xff) << 0x14;
  }
  uVar1 = FUN_8079408c(0xe);
  *(uint *)(iVar3 + 0x98) = *(uint *)(iVar3 + 0x98) & 0xffffc000 | uVar1 & 0x3fff;
  FUN_8079408c(1);
  uVar1 = FUN_8079408c(0xe);
  uVar2 = *(uint *)(iVar3 + 0x98);
  uVar1 = uVar1 & 0x3fff;
  *(uint *)(iVar3 + 0x98) = uVar2 & 0xf0003fff | uVar1 << 0xe;
  if ((uVar2 & 0x3fff) != 0) {
    if (uVar1 == 0) {
      *(uint *)(iVar3 + 0x98) = uVar2 & 0xf0000000;
      return;
    }
    if ((int)((*(uint *)(iVar3 + 4) & 0xfff) - 4) <= (int)(uVar2 & 0x3fff)) {
      return;
    }
    if ((*(uint *)(iVar3 + 4) & 0xffffff) >> 0xc <= uVar1) {
      return;
    }
  }
  *(uint *)(iVar3 + 0x98) = uVar2 & 0xf0000000;
  return;
}

