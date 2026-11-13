// FUN_807ab8c8
// Ghidra address: 807ab8c8

void FUN_807ab8c8(int param_1)

{
  undefined2 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  iVar4 = *(int *)(param_1 + 8);
  uVar2 = *(uint *)(iVar4 + 0xb4);
  if (*(int *)(iVar4 + 0x8c) << 0x17 < 0) {
    uVar5 = 1;
    if (-1 < (int)(uVar2 << 5)) goto LAB_807ab910;
    uVar2 = (uVar2 & 0x1fffff) >> 0x14;
  }
  else {
    uVar5 = 1;
    if ((uVar2 & 0xfffff) >> 0x12 != 3) goto LAB_807ab910;
    uVar2 = (uVar2 & 0x7ffffff) >> 0x1a;
  }
  uVar5 = 3;
  if (uVar2 == 0) {
    uVar5 = 2;
  }
LAB_807ab910:
  uVar2 = 0;
  if (uVar5 != 0) {
    iVar3 = 0;
    do {
      uVar1 = FUN_8079408c(0x10);
      *(undefined2 *)(iVar3 + iVar4 + 0x1c0) = uVar1;
      FUN_8079408c(1);
      uVar1 = FUN_8079408c(0x10);
      *(undefined2 *)(iVar3 + iVar4 + 0x1c6) = uVar1;
      FUN_8079408c(1);
      uVar2 = uVar2 + 1 & 0xff;
      iVar3 = uVar2 << 1;
    } while (uVar2 < uVar5);
  }
  return;
}

