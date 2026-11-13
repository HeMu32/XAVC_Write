// FUN_807ac5b4
// Ghidra address: 807ac5b4

void FUN_807ac5b4(int param_1)

{
  undefined1 uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  
  iVar6 = *(int *)(param_1 + 8);
  uVar2 = FUN_8079408c(0xc);
  uVar3 = FUN_8079408c(0xc);
  *(uint *)(iVar6 + 4) = *(uint *)(iVar6 + 4) & 0xff000000 | uVar2 & 0xfff | (uVar3 & 0xfff) << 0xc;
  uVar2 = FUN_8079408c(4);
  *(uint *)(iVar6 + 4) = *(uint *)(iVar6 + 4) & 0xf0ffffff | (uVar2 & 0xf) << 0x18;
  uVar4 = FUN_8079408c(4);
  iVar5 = FUN_807ad08c(uVar4);
  *(uint *)(iVar6 + 4) = *(uint *)(iVar6 + 4) & 0xfffffff | iVar5 << 0x1c;
  uVar2 = FUN_8079408c(0x12);
  *(uint *)(iVar6 + 8) = *(uint *)(iVar6 + 8) & 0xfffc0000 | uVar2 & 0x3ffff;
  FUN_8079408c(1);
  uVar2 = FUN_8079408c(10);
  *(uint *)(iVar6 + 8) = *(uint *)(iVar6 + 8) & 0xf003ffff | (uVar2 & 0x3ff) << 0x12;
  uVar2 = FUN_8079408c(1);
  *(uint *)(iVar6 + 8) = *(uint *)(iVar6 + 8) & 0xefffffff | (uVar2 & 1) << 0x1c;
  uVar2 = FUN_8079408c(1);
  uVar2 = *(uint *)(iVar6 + 8) & 0xdfffffff | (uVar2 & 1) << 0x1d;
  *(uint *)(iVar6 + 8) = uVar2;
  if ((int)(uVar2 << 2) < 0) {
    uVar2 = 0;
    do {
      uVar1 = FUN_8079408c(8);
      iVar5 = uVar2 + iVar6;
      uVar2 = uVar2 + 1 & 0xff;
      *(undefined1 *)(iVar5 + 0xc) = uVar1;
    } while (uVar2 < 0x40);
    FUN_807ad084(iVar6 + 0xc);
  }
  uVar2 = FUN_8079408c(1);
  uVar2 = *(uint *)(iVar6 + 8) & 0xbfffffff | (uVar2 & 1) << 0x1e;
  *(uint *)(iVar6 + 8) = uVar2;
  if ((int)(uVar2 << 1) < 0) {
    uVar2 = 0;
    do {
      iVar5 = iVar6 + uVar2;
      uVar1 = FUN_8079408c(8);
      uVar2 = uVar2 + 1 & 0xff;
      *(undefined1 *)(iVar5 + 0x4c) = uVar1;
    } while (uVar2 < 0x40);
    FUN_807ad084(iVar6 + 0x4c);
  }
  FUN_80787e30(iVar6 + 4);
  return;
}

