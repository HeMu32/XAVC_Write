// FUN_80794ad8
// Ghidra address: 80794ad8

void FUN_80794ad8(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  
  sony_ucp_write7(0x350,6);
  sony_ucp_write7(0x350,4);
  sony_ucp_write7(0x350,5);
  FUN_8079486c(0,param_1,param_2,1,param_3,0);
  (&DAT_807c03c8)[param_3] = 0;
  iVar1 = 0;
  do {
    uVar2 = sony_ucp_read7(0x350);
    iVar1 = iVar1 + 1;
    if ((uVar2 & 1) != 0) goto LAB_80794b58;
  } while (iVar1 != 0x30571);
  FUN_80747a30(0x350);
LAB_80794b58:
  sony_ucp_write7(0x350,1);
  FUN_8079408c(0x20);
  sony_ucp_write7(0x360,0);
  sony_ucp_write7(0x350,7);
  return;
}

