// FUN_807abc68
// Ghidra address: 807abc68

void FUN_807abc68(int param_1)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 8);
  uVar1 = FUN_8079408c(10);
  *(uint *)(iVar2 + 0x1d8) = *(uint *)(iVar2 + 0x1d8) & 0xfffffc00 | uVar1 & 0x3ff;
  FUN_8079408c(1);
  uVar1 = FUN_8079408c(0xf);
  *(uint *)(iVar2 + 0x1d8) = *(uint *)(iVar2 + 0x1d8) & 0xfe0003ff | (uVar1 & 0x7fff) << 10;
  FUN_8079408c(1);
  uVar1 = FUN_8079408c(0xf);
  *(uint *)(iVar2 + 0x1dc) = *(uint *)(iVar2 + 0x1dc) & 0xffff8000 | uVar1 & 0x7fff;
  uVar1 = FUN_8079408c(2);
  *(uint *)(iVar2 + 0x1dc) = *(uint *)(iVar2 + 0x1dc) & 0xfffe7fff | (uVar1 & 3) << 0xf;
  uVar1 = FUN_8079408c(1);
  *(uint *)(iVar2 + 0x1dc) = *(uint *)(iVar2 + 0x1dc) & 0xfffdffff | (uVar1 & 1) << 0x11;
  uVar1 = FUN_8079408c(1);
  *(uint *)(iVar2 + 0x1dc) = *(uint *)(iVar2 + 0x1dc) & 0xfffbffff | (uVar1 & 1) << 0x12;
  return;
}

