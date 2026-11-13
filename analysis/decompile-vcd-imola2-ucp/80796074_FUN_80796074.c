// FUN_80796074
// Ghidra address: 80796074

int FUN_80796074(void)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  
  *DAT_807c0afc = *DAT_807c0afc | 0x20000000;
  DAT_807c03e8 = DAT_807c03e8 + 1;
  iVar5 = 1;
  FUN_8079408c(1);
  DAT_807c03e8 = DAT_807c03e8 + 1;
  iVar1 = FUN_8079408c(1);
  if (iVar1 == 0) {
    DAT_807c03e8 = DAT_807c03e8 + 1;
    iVar1 = FUN_8079408c(1);
    if (iVar1 == 0) {
      DAT_807c03e8 = DAT_807c03e8 + 3;
      uVar4 = 0;
      FUN_8079408c(3);
      uVar3 = FUN_807965bc();
      uVar2 = FUN_8079604c(uVar3);
      do {
        DAT_807c03e8 = DAT_807c03e8 + 6;
        uVar4 = uVar4 + 1;
        FUN_8079408c(6);
      } while (uVar4 <= uVar2);
    }
  }
  else {
    DAT_807c03e8 = DAT_807c03e8 + 1;
    uVar2 = FUN_8079408c(1);
    uVar3 = FUN_807965bc();
    uVar4 = FUN_80796024(uVar3);
    for (; uVar2 <= uVar4; uVar2 = uVar2 + 1) {
      DAT_807c03e8 = DAT_807c03e8 + 3;
      FUN_8079408c(3);
      FUN_807965bc();
    }
  }
  if ((DAT_807c03e8 & 7) != 0) {
    DAT_807c03e8 = DAT_807c03e8 + (8 - (DAT_807c03e8 & 7));
    FUN_8079408c();
  }
  do {
    if (0xf < DAT_807c03ec) {
      return iVar5;
    }
    iVar1 = FUN_807962a0();
    uVar2 = FUN_807962e8();
    if (iVar1 == 0x80 && uVar2 == 0) {
      return iVar5;
    }
    if (0x400 < uVar2) {
      return iVar5;
    }
    if (uVar2 < 0x241) {
      if (iVar1 == 4) {
        uVar3 = 4;
LAB_807961b8:
        iVar5 = FUN_80796d3c(uVar2,uVar3);
      }
      else {
        uVar3 = 5;
        if (iVar1 == 5) goto LAB_807961b8;
        FUN_80796334(uVar2);
      }
      if (iVar5 == 0) {
        return 0;
      }
    }
    else {
      FUN_80796334(uVar2);
    }
    DAT_807c03ec = DAT_807c03ec + 1;
  } while( true );
}

