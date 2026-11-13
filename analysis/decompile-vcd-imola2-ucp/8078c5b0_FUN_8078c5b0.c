// FUN_8078c5b0
// Ghidra address: 8078c5b0

/* WARNING: Control flow encountered bad instruction data */

void FUN_8078c5b0(void)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = 0;
  do {
    uVar2 = sony_ucp_read7(0x350);
    iVar1 = iVar1 + 1;
    if ((uVar2 & 1) != 0) goto LAB_8078c5f0;
  } while (iVar1 != 0x30571);
  FUN_80747a30(0x350);
LAB_8078c5f0:
  sony_ucp_write7(0x350,1);
  iVar1 = 0;
  do {
    uVar2 = sony_ucp_read7(0x360);
    iVar1 = iVar1 + 1;
    if ((uVar2 & 1) != 0) goto LAB_8078c624;
  } while (iVar1 != 0x30571);
  FUN_80747a30(0x360);
LAB_8078c624:
  FUN_8079408c(4);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

