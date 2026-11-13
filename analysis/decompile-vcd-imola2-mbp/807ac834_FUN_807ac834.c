// FUN_807ac834
// Ghidra address: 807ac834

void FUN_807ac834(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 8);
  uVar1 = FUN_8079408c(2);
  *(uint *)(iVar3 + 0x9c) = *(uint *)(iVar3 + 0x9c) & 0xfffffffc | uVar1 & 3;
  uVar1 = FUN_8079408c(4);
  uVar2 = *(uint *)(iVar3 + 0x9c);
  *(uint *)(iVar3 + 0x9c) = uVar2 & 0xffffffc3 | (uVar1 & 0xf) << 2;
  if ((uVar2 & 3) == 1) {
    uVar1 = FUN_8079408c(0xe);
    *(uint *)(iVar3 + 0x9c) = *(uint *)(iVar3 + 0x9c) & 0xfff0003f | (uVar1 & 0x3fff) << 6;
    FUN_8079408c(1);
    uVar1 = FUN_8079408c(0xe);
    *(uint *)(iVar3 + 0xa0) = *(uint *)(iVar3 + 0xa0) & 0xffffc000 | uVar1 & 0x3fff;
    uVar1 = FUN_8079408c(5);
    *(uint *)(iVar3 + 0xa0) = *(uint *)(iVar3 + 0xa0) & 0xfff83fff | (uVar1 & 0x1f) << 0xe;
    uVar1 = FUN_8079408c(5);
    *(uint *)(iVar3 + 0xa0) = *(uint *)(iVar3 + 0xa0) & 0xff07ffff | (uVar1 & 0x1f) << 0x13;
    uVar1 = FUN_8079408c(5);
    *(uint *)(iVar3 + 0xa0) = *(uint *)(iVar3 + 0xa0) & 0xe0ffffff | (uVar1 & 0x1f) << 0x18;
    uVar1 = FUN_8079408c(5);
    *(uint *)(iVar3 + 0xa4) = *(uint *)(iVar3 + 0xa4) & 0xffffffe0 | uVar1 & 0x1f;
  }
  if ((*(uint *)(iVar3 + 0x9c) & 3) == 3) {
    uVar1 = FUN_8079408c(1);
    uVar1 = *(uint *)(iVar3 + 0xa4) & 0xffffffdf | (uVar1 & 1) << 5;
    *(uint *)(iVar3 + 0xa4) = uVar1;
    if ((int)(uVar1 << 0x1a) < 0) {
      uVar1 = FUN_8079408c(1);
      *(uint *)(iVar3 + 0xa4) = *(uint *)(iVar3 + 0xa4) & 0xffffffbf | (uVar1 & 1) << 6;
    }
    uVar1 = FUN_8079408c(3);
    *(uint *)(iVar3 + 0xa4) = *(uint *)(iVar3 + 0xa4) & 0xfffffc7f | (uVar1 & 7) << 7;
    uVar1 = FUN_8079408c(3);
    *(uint *)(iVar3 + 0xa4) = *(uint *)(iVar3 + 0xa4) & 0xffffe3ff | (uVar1 & 7) << 10;
  }
  return;
}

