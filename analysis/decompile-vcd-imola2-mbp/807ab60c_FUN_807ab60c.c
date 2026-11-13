// FUN_807ab60c
// Ghidra address: 807ab60c

void FUN_807ab60c(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  iVar5 = *(int *)(param_1 + 8);
  if (((*(uint *)(iVar5 + 0xac) & 0x1fff) >> 10) - 2 < 2) {
    iVar1 = FUN_8079408c(4);
    *(uint *)(iVar5 + 0xb4) = *(uint *)(iVar5 + 0xb4) & 0xfffffff0 | iVar1 + 10U & 0xf;
    iVar1 = FUN_8079408c(4);
    *(uint *)(iVar5 + 0xb4) = *(uint *)(iVar5 + 0xb4) & 0xffffff0f | (iVar1 + 10U & 0xf) << 4;
    iVar1 = FUN_8079408c(4);
    *(uint *)(iVar5 + 0xb4) = *(uint *)(iVar5 + 0xb4) & 0xfffff0ff | (iVar1 + 10U & 0xf) << 8;
    iVar1 = FUN_8079408c(4);
    *(uint *)(iVar5 + 0xb4) = *(uint *)(iVar5 + 0xb4) & 0xffff0fff | (iVar1 + 10U & 0xf) << 0xc;
  }
  else {
    uVar2 = FUN_8079408c(4);
    *(uint *)(iVar5 + 0xb4) = *(uint *)(iVar5 + 0xb4) & 0xfffffff0 | uVar2 & 0xf;
    uVar2 = FUN_8079408c(4);
    *(uint *)(iVar5 + 0xb4) = *(uint *)(iVar5 + 0xb4) & 0xffffff0f | (uVar2 & 0xf) << 4;
    uVar2 = FUN_8079408c(4);
    *(uint *)(iVar5 + 0xb4) = *(uint *)(iVar5 + 0xb4) & 0xfffff0ff | (uVar2 & 0xf) << 8;
    uVar2 = FUN_8079408c(4);
    *(uint *)(iVar5 + 0xb4) = *(uint *)(iVar5 + 0xb4) & 0xffff0fff | (uVar2 & 0xf) << 0xc;
  }
  uVar2 = FUN_8079408c(2);
  *(uint *)(iVar5 + 0xb4) = *(uint *)(iVar5 + 0xb4) & 0xfffcffff | (uVar2 & 3) << 0x10;
  uVar2 = FUN_8079408c(2);
  *(uint *)(iVar5 + 0xb4) = *(uint *)(iVar5 + 0xb4) & 0xfff3ffff | (uVar2 & 3) << 0x12;
  uVar2 = FUN_8079408c(1);
  *(uint *)(iVar5 + 0xb4) = *(uint *)(iVar5 + 0xb4) & 0xffefffff | (uVar2 & 1) << 0x14;
  uVar2 = FUN_8079408c(1);
  *(uint *)(iVar5 + 0xb4) = *(uint *)(iVar5 + 0xb4) & 0xffdfffff | (uVar2 & 1) << 0x15;
  uVar2 = FUN_8079408c(1);
  *(uint *)(iVar5 + 0xb4) = *(uint *)(iVar5 + 0xb4) & 0xffbfffff | (uVar2 & 1) << 0x16;
  uVar2 = FUN_8079408c(1);
  *(uint *)(iVar5 + 0xb4) = *(uint *)(iVar5 + 0xb4) & 0xff7fffff | (uVar2 & 1) << 0x17;
  uVar2 = FUN_8079408c(1);
  *(uint *)(iVar5 + 0xb4) = *(uint *)(iVar5 + 0xb4) & 0xfeffffff | (uVar2 & 1) << 0x18;
  uVar2 = FUN_8079408c(1);
  *(uint *)(iVar5 + 0xb4) = *(uint *)(iVar5 + 0xb4) & 0xfdffffff | (uVar2 & 1) << 0x19;
  uVar2 = FUN_8079408c(1);
  *(uint *)(iVar5 + 0xb4) = *(uint *)(iVar5 + 0xb4) & 0xfbffffff | (uVar2 & 1) << 0x1a;
  uVar2 = FUN_8079408c(1);
  *(uint *)(iVar5 + 0xb4) = *(uint *)(iVar5 + 0xb4) & 0xf7ffffff | (uVar2 & 1) << 0x1b;
  uVar2 = FUN_8079408c(1);
  *(uint *)(iVar5 + 0xb4) = *(uint *)(iVar5 + 0xb4) & 0xefffffff | (uVar2 & 1) << 0x1c;
  uVar2 = FUN_8079408c(1);
  uVar3 = *(uint *)(iVar5 + 0xb4);
  uVar2 = (uVar2 & 1) << 0x1d;
  uVar4 = uVar3 & 0xdfffffff | uVar2;
  *(uint *)(iVar5 + 0xb4) = uVar4;
  uVar2 = uVar3 & 0xdbffffff | uVar2;
  if ((int)(uVar3 << 3) < 0) {
    *(uint *)(iVar5 + 0xb4) = uVar4 | 0xc0000;
    if (-1 < *(int *)(iVar5 + 0x8c) << 0x17) goto LAB_807ab7d4;
    uVar2 = uVar4 | 0x2c0000;
  }
  *(uint *)(iVar5 + 0xb4) = uVar2;
LAB_807ab7d4:
  if (*(int *)(iVar5 + 0xb4) << 2 < 0) {
    uVar2 = FUN_8079408c(1);
    *(uint *)(iVar5 + 0xb4) = *(uint *)(iVar5 + 0xb4) & 0xbfffffff | (uVar2 & 1) << 0x1e;
    uVar2 = FUN_8079408c(3);
    *(uint *)(iVar5 + 0xb8) = *(uint *)(iVar5 + 0xb8) & 0xfffffff8 | uVar2 & 7;
    uVar2 = FUN_8079408c(1);
    *(uint *)(iVar5 + 0xb8) = *(uint *)(iVar5 + 0xb8) & 0xfffffff7 | (uVar2 & 1) << 3;
    uVar2 = FUN_8079408c(7);
    *(uint *)(iVar5 + 0xb8) = *(uint *)(iVar5 + 0xb8) & 0xfffff80f | (uVar2 & 0x7f) << 4;
    uVar2 = FUN_8079408c(8);
    *(uint *)(iVar5 + 0xb8) = *(uint *)(iVar5 + 0xb8) & 0xfff807ff | (uVar2 & 0xff) << 0xb;
  }
  return;
}

