// FUN_807941d8
// Ghidra address: 807941d8

undefined4 FUN_807941d8(void)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  sony_ucp_write7(0x360,0x3f);
  iVar2 = 0;
  do {
    uVar3 = sony_ucp_read7(0x361);
    iVar2 = iVar2 + 1;
    if ((uVar3 & 1) != 0) goto LAB_80794214;
  } while (iVar2 != 0x30571);
  FUN_80747a30(0x361);
LAB_80794214:
  uVar1 = sony_ucp_read7(0x362);
  sony_ucp_write7(0x361,0);
  return uVar1;
}

