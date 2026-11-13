// FUN_80798bd8
// Ghidra address: 80798bd8

void FUN_80798bd8(void)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = 0;
  do {
    uVar2 = sony_ucp_read7(0x350);
    iVar1 = iVar1 + 1;
    if ((uVar2 & 1) != 0) goto LAB_80798c0c;
  } while (iVar1 != 0x30571);
  FUN_80747a30(0x350);
LAB_80798c0c:
  sony_ucp_write7(0x350,1);
  iVar1 = 0;
  do {
    uVar2 = sony_ucp_read7(0x360);
    iVar1 = iVar1 + 1;
    if ((uVar2 & 1) != 0) goto LAB_80798c40;
  } while (iVar1 != 0x30571);
  FUN_80747a30(0x360);
LAB_80798c40:
  FUN_80794188();
  sony_ucp_write7(0x360,0);
  return;
}

