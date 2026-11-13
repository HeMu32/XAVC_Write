// FUN_8079a238
// Ghidra address: 8079a238

void FUN_8079a238(void)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  uVar1 = FUN_80791388();
  uVar2 = FUN_80792614(uVar1);
  uVar3 = FUN_807915dc();
  iVar5 = 0;
  do {
    uVar6 = sony_ucp_read7(0x300);
    iVar5 = iVar5 + 1;
    if ((uVar6 & 1) != 0) goto LAB_8079a294;
  } while (iVar5 != 0x30571);
  FUN_80747a30(0x300);
LAB_8079a294:
  DAT_807c0b4c = FUN_807915fc();
  if (4 < (int)DAT_807c0b4c) {
    DAT_807c0b4c = DAT_807c0b4c - 5;
  }
  uVar1 = FUN_80791698();
  iVar5 = FUN_8079291c(uVar1);
  iVar4 = FUN_8079160c();
  DAT_807c0b50 = FUN_8078eda0(iVar5 + iVar4);
  uVar7 = DAT_807c0b50 & 0x7f;
  uVar8 = DAT_807c0b4c & 7;
  uVar6 = FUN_80791650();
  sony_ucp_write7(0x304,uVar8 | (uVar2 & ~uVar3 & 1) << 4 | uVar7 << 8 | (uVar6 & 3) << 0x10);
  uVar1 = FUN_80791698();
  iVar5 = FUN_80792a2c(uVar1);
  if (iVar5 == 1) {
    iVar5 = 0;
    do {
      uVar2 = sony_ucp_read7(0x301);
      iVar5 = iVar5 + 1;
      if ((uVar2 & 1) != 0) goto LAB_8079a35c;
    } while (iVar5 != 0x30571);
    FUN_80747a30(0x301);
LAB_8079a35c:
    sony_ucp_write7(0x30e,0);
  }
  return;
}

