// FUN_80790564
// Ghidra address: 80790564

void FUN_80790564(uint param_1,uint param_2,undefined4 param_3,int param_4,int param_5)

{
  uint *puVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  
  if (param_4 != 0) {
    iVar3 = 0;
    do {
      uVar4 = sony_ucp_read7(0x350);
      iVar3 = iVar3 + 1;
      if ((uVar4 & 1) != 0) goto LAB_807905ac;
    } while (iVar3 != 0x30571);
    FUN_80747a30(0x350);
LAB_807905ac:
    sony_ucp_write7(0x350,1);
    iVar3 = 0;
    do {
      uVar4 = sony_ucp_read7(0x360);
      iVar3 = iVar3 + 1;
      if ((uVar4 & 1) != 0) goto LAB_807905e0;
    } while (iVar3 != 0x30571);
    FUN_80747a30(0x360);
  }
LAB_807905e0:
  FUN_807924b8(DAT_807c0a98,0x24);
  *DAT_807c0a98 = *DAT_807c0a98 & 0xffffff80 | (param_1 & 0x1f) << 2 | param_2 & 3;
  uVar2 = FUN_80794188();
  puVar1 = DAT_807c0a98;
  uVar4 = FUN_8078ea38(uVar2);
  puVar1[1] = uVar4;
  if (param_5 != 0) {
    sony_ucp_write7(0x360,0);
  }
  return;
}

