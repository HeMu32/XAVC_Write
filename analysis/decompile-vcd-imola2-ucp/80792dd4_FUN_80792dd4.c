// FUN_80792dd4
// Ghidra address: 80792dd4

void FUN_80792dd4(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  
  iVar2 = 0;
  do {
    uVar4 = sony_ucp_read7(0x350);
    iVar2 = iVar2 + 1;
    if ((uVar4 & 1) != 0) goto LAB_80792e0c;
  } while (iVar2 != 0x30571);
  FUN_80747a30(0x350);
LAB_80792e0c:
  sony_ucp_write7(0x350,1);
  iVar2 = 0;
  do {
    uVar4 = sony_ucp_read7(0x360);
    iVar2 = iVar2 + 1;
    if ((uVar4 & 1) != 0) goto LAB_80792e40;
  } while (iVar2 != 0x30571);
  FUN_80747a30(0x360);
LAB_80792e40:
  puVar3 = DAT_807c0ac8;
  uVar1 = FUN_8079408c(3);
  *puVar3 = uVar1;
  sony_ucp_write7(0x360,0);
  for (puVar3 = (undefined4 *)((uint)DAT_807c0ac8 & 0xffffffc0); puVar3 < DAT_807c0ac8 + 1;
      puVar3 = puVar3 + 0x10) {
    cacheOp(0x1a,puVar3);
  }
  return;
}

