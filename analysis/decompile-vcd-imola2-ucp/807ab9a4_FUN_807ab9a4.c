// FUN_807ab9a4
// Ghidra address: 807ab9a4

void FUN_807ab9a4(int param_1)

{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  iVar5 = *(int *)(param_1 + 8);
  cVar1 = FUN_8079408c(1);
  if (cVar1 == '\x01') {
    uVar4 = 0;
    *(uint *)(iVar5 + 0xbc) = *(uint *)(iVar5 + 0xbc) | 1;
    do {
      iVar3 = iVar5 + uVar4;
      uVar2 = FUN_8079408c(8);
      uVar4 = uVar4 + 1 & 0xff;
      *(undefined1 *)(iVar3 + 0xbd) = uVar2;
    } while (uVar4 < 0x40);
    FUN_807ad084(iVar5 + 0xbd);
  }
  cVar1 = FUN_8079408c(1);
  if (cVar1 == '\x01') {
    uVar4 = 0;
    *(uint *)(iVar5 + 0xbc) = *(uint *)(iVar5 + 0xbc) | 2;
    do {
      iVar3 = iVar5 + uVar4;
      uVar2 = FUN_8079408c(8);
      uVar4 = uVar4 + 1 & 0xff;
      *(undefined1 *)(iVar3 + 0xfd) = uVar2;
    } while (uVar4 < 0x40);
    FUN_807ad084(iVar5 + 0xfd);
  }
  cVar1 = FUN_8079408c(1);
  if (cVar1 == '\x01') {
    uVar4 = 0;
    *(uint *)(iVar5 + 0xbc) = *(uint *)(iVar5 + 0xbc) | 4;
    do {
      iVar3 = iVar5 + uVar4;
      uVar2 = FUN_8079408c(8);
      uVar4 = uVar4 + 1 & 0xff;
      *(undefined1 *)(iVar3 + 0x13d) = uVar2;
    } while (uVar4 < 0x40);
    FUN_807ad084(iVar5 + 0x13d);
  }
  cVar1 = FUN_8079408c(1);
  if (cVar1 == '\x01') {
    uVar4 = 0;
    *(uint *)(iVar5 + 0xbc) = *(uint *)(iVar5 + 0xbc) | 8;
    do {
      iVar3 = iVar5 + uVar4;
      uVar2 = FUN_8079408c(8);
      uVar4 = uVar4 + 1 & 0xff;
      *(undefined1 *)(iVar3 + 0x17d) = uVar2;
    } while (uVar4 < 0x40);
    FUN_807ad084(iVar5 + 0x17d);
  }
  return;
}

