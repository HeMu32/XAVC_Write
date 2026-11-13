// FUN_80794188
// Ghidra address: 80794188

undefined4 FUN_80794188(void)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  sony_ucp_write7(0x360,0x3e);
  iVar2 = 0;
  do {
    uVar3 = sony_ucp_read7(0x361);
    iVar2 = iVar2 + 1;
    if ((uVar3 & 1) != 0) goto LAB_807941c4;
  } while (iVar2 != 0x30571);
  FUN_80747a30(0x361);
LAB_807941c4:
  uVar1 = sony_ucp_read7(0x362);
  sony_ucp_write7(0x361,0);
  return uVar1;
}

