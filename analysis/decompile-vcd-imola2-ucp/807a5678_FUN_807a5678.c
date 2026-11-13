// FUN_807a5678
// Ghidra address: 807a5678

void FUN_807a5678(void)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  while( true ) {
    iVar1 = FUN_8079ec78(DAT_807c0b74);
    if (iVar1 != 0) break;
    piVar2 = (int *)FUN_8079ec5c(DAT_807c0b74);
    if (*piVar2 == 0) {
      FUN_807874d8(piVar2[1]);
      uVar4 = 0x807a56d4;
      iVar1 = FUN_8079c854(3,0x509,0xffffffff);
      uVar3 = 0x1a8;
    }
    else {
      FUN_807874ec(piVar2[1]);
      uVar4 = 0x807a5744;
      iVar1 = FUN_8079c854(3,0x504,0xffffffff);
      uVar3 = 0x1b0;
    }
    if (iVar1 != 0) {
      FUN_80745808(&DAT_807c0524,s_________________________src_ipsx_807b0914,uVar3,uVar4);
    }
    uVar3 = 0x807a56f8;
    iVar1 = FUN_8079ec40(DAT_807c0b74);
    if (iVar1 == 0) {
      FUN_80745808(&DAT_807c0524,s_________________________src_ipsx_807b0914,0xa2,uVar3);
    }
  }
  return;
}

