// FUN_807ab508
// Ghidra address: 807ab508

void FUN_807ab508(int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 8);
  uVar1 = FUN_8079408c(10);
  *(uint *)(iVar4 + 0xac) = *(uint *)(iVar4 + 0xac) & 0xfffffc00 | uVar1 & 0x3ff;
  uVar1 = FUN_8079408c(3);
  *(uint *)(iVar4 + 0xac) = *(uint *)(iVar4 + 0xac) & 0xffffe3ff | (uVar1 & 7) << 10;
  uVar1 = FUN_8079408c(0x10);
  uVar3 = *(uint *)(iVar4 + 0xac);
  *(uint *)(iVar4 + 0xac) = uVar3 & 0xe0001fff | (uVar1 & 0xffff) << 0xd;
  if (((uVar3 & 0x1fff) >> 10) - 2 < 2) {
    uVar1 = FUN_8079408c(1);
    *(uint *)(iVar4 + 0xac) = *(uint *)(iVar4 + 0xac) & 0xdfffffff | (uVar1 & 1) << 0x1d;
    uVar1 = FUN_8079408c(3);
    *(uint *)(iVar4 + 0xb0) = *(uint *)(iVar4 + 0xb0) & 0xfffffff8 | uVar1 & 7;
  }
  if ((*(uint *)(iVar4 + 0xac) & 0x1fff) >> 10 != 3) {
    while (iVar2 = FUN_8079408c(1), iVar2 != 0) {
      uVar1 = FUN_8079408c(8);
      uVar1 = *(uint *)(iVar4 + 0xb0) & 0xffff807f | (uVar1 & 0xff) << 7;
LAB_807ab598:
      *(uint *)(iVar4 + 0xb0) = uVar1;
    }
    FUN_80787cd8(iVar4 + 0xac);
    return;
  }
  uVar1 = FUN_8079408c(1);
  *(uint *)(iVar4 + 0xb0) = *(uint *)(iVar4 + 0xb0) & 0xfffffff7 | (uVar1 & 1) << 3;
  uVar1 = FUN_8079408c(3);
  uVar1 = *(uint *)(iVar4 + 0xb0) & 0xffffff8f | (uVar1 & 7) << 4;
  goto LAB_807ab598;
}

