// FUN_80786510
// Ghidra address: 80786510

void FUN_80786510(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 uVar7;
  short local_30 [8];
  
  do {
    iVar1 = FUN_8079ec78(DAT_807c0a40);
    if (iVar1 != 0) {
      return;
    }
    piVar2 = (int *)FUN_8079ec5c(DAT_807c0a40);
    iVar1 = *piVar2;
    uVar6 = (*(uint *)(iVar1 + 4) & 0x7ff) >> 8;
    if (((uVar6 == 1) && (DAT_807c01cc == 0)) || ((uVar6 == 2 && (DAT_807c01cc == 1)))) {
      iVar4 = FUN_80786788();
      uVar7 = 0x80786664;
      iVar4 = FUN_8079c854(3,(*(uint *)(iVar4 + 4) & 7) << 0xc | 0x585,0xffffffff);
      if (iVar4 != 0) {
        FUN_80745808(&DAT_807c020c,s_________________________src_ipsx_807af9a8,0x2b7,uVar7);
      }
      FUN_807867a8();
    }
    iVar4 = DAT_807c01cc;
    uVar7 = 0x80786590;
    iVar3 = FUN_8079ec40((&DAT_807c0a3c)[DAT_807c01cc]);
    if (iVar3 == 0) {
      uVar5 = 0x1cd;
LAB_807865fc:
      FUN_80745808(&DAT_807c020c,s_________________________src_ipsx_807af9a8,uVar5,uVar7);
      uVar6 = *(uint *)(iVar1 + 4);
    }
    else {
      local_30[0] = 5;
      if (iVar4 != 0) {
        FUN_80745808(&DAT_807c020c,s_________________________src_ipsx_807af9a8,0x1be,uVar7);
      }
      uVar7 = 0x807865b8;
      iVar4 = FUN_8079c854((int)local_30[iVar4],0x850c,0xffffffff);
      if (iVar4 != 0) {
        uVar5 = 0x1c2;
        goto LAB_807865fc;
      }
      uVar6 = *(uint *)(iVar1 + 4);
    }
    if (((uVar6 & 0x7ff) >> 8) - 1 < 2) {
      DAT_807c0a40 = DAT_807c0a3c;
      DAT_807c01cc = 0;
      DAT_807c01d0 = 0;
    }
  } while( true );
}

