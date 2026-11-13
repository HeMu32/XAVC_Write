// FUN_80786418
// Ghidra address: 80786418

void FUN_80786418(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  short local_30 [8];
  
  iVar3 = 0;
LAB_80786440:
  do {
    while (iVar1 = FUN_8079ec78(DAT_807c0a3c), iVar1 != 0) {
      iVar3 = iVar3 + 1;
      if (iVar3 != 0) {
        return;
      }
    }
    uVar4 = 0x80786480;
    iVar1 = FUN_8079ec40(DAT_807c0a3c);
    uVar2 = 0x1cd;
    if (iVar1 != 0) {
      local_30[0] = 5;
      if (iVar3 != 0) {
        FUN_80745808(&DAT_807c020c,s_________________________src_ipsx_807af9a8,0x1be,uVar4);
      }
      uVar4 = 0x807864d4;
      iVar1 = FUN_8079c854((int)local_30[iVar3],0x850c,0xffffffff);
      uVar2 = 0x1c2;
      if (iVar1 == 0) goto LAB_80786440;
    }
    FUN_80745808(&DAT_807c020c,s_________________________src_ipsx_807af9a8,uVar2,uVar4);
  } while( true );
}

