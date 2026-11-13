// FUN_8079408c
// Ghidra address: 8079408c

undefined4 FUN_8079408c(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = 0;
  if (param_1 != 0) {
    iVar2 = 0;
    do {
      uVar3 = sony_ucp_read7(0x360);
      iVar2 = iVar2 + 1;
      if ((uVar3 & 1) != 0) goto LAB_807940d0;
    } while (iVar2 != 0x30571);
    FUN_80747a30(0x360);
LAB_807940d0:
    sony_ucp_write7(0x360,param_1);
    iVar2 = 0;
    do {
      uVar3 = sony_ucp_read7(0x361);
      iVar2 = iVar2 + 1;
      if ((uVar3 & 1) != 0) goto LAB_80794100;
    } while (iVar2 != 0x30571);
    FUN_80747a30(0x361);
LAB_80794100:
    uVar1 = sony_ucp_read7(0x362);
    DAT_807c03c0 = sony_ucp_read7(0x364);
    sony_ucp_write7(0x361,0);
  }
  return uVar1;
}

