// FUN_80799028
// Ghidra address: 80799028

void FUN_80799028(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = 0;
  do {
    uVar3 = sony_ucp_read7(0x350);
    iVar2 = iVar2 + 1;
    if ((uVar3 & 1) != 0) goto LAB_80799074;
  } while (iVar2 != 0x30571);
  FUN_80747a30(0x350);
LAB_80799074:
  sony_ucp_write7(0x350,1);
  iVar2 = 0;
  do {
    uVar3 = sony_ucp_read7(0x360);
    iVar2 = iVar2 + 1;
    if ((uVar3 & 1) != 0) goto LAB_807990a8;
  } while (iVar2 != 0x30571);
  FUN_80747a30(0x360);
LAB_807990a8:
  FUN_807991e8();
  iVar2 = 0;
  while( true ) {
    while (iVar1 = FUN_8079408c(8), iVar1 == 0xff) {
      iVar2 = iVar2 + 0xff;
    }
    iVar2 = iVar2 + iVar1;
    iVar1 = 0;
    if ((iVar2 == 0x80) || (0xf < DAT_807c0434)) break;
    while( true ) {
      uVar3 = FUN_8079408c(8);
      if ((uVar3 & 0xff) != 0xff) break;
      iVar1 = iVar1 + 0xff;
    }
    iVar1 = iVar1 + (uVar3 & 0xff);
    if (0x400 < iVar1) break;
    if (iVar1 < 0x241) {
      if (iVar2 < 0x16) {
        iVar2 = (*(code *)(&PTR_FUN_807b59cc)[iVar2])(iVar1);
LAB_80799190:
        if ((DAT_807c0430 & 7) != 0) {
          DAT_807c0430 = DAT_807c0430 + (8 - (DAT_807c0430 & 7));
          FUN_8079408c();
        }
      }
      else {
        if (iVar2 == 0x2d) {
          iVar2 = FUN_80799abc(iVar1);
          goto LAB_80799190;
        }
        FUN_80798fc4(iVar1);
        iVar2 = 1;
      }
      if (iVar2 == 0) break;
    }
    else {
      FUN_80798fc4(iVar1);
    }
    DAT_807c0434 = DAT_807c0434 + 1;
    iVar2 = 0;
  }
  sony_ucp_write7(0x360,0);
  return;
}

