// FUN_8079a450
// Ghidra address: 8079a450

void FUN_8079a450(int param_1,uint param_2,undefined1 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = 0;
  do {
    uVar3 = sony_ucp_read7(0x300);
    iVar2 = iVar2 + 1;
    if ((uVar3 & 1) != 0) goto LAB_8079a4a4;
  } while (iVar2 != 0x30571);
  FUN_80747a30(0x300);
LAB_8079a4a4:
  iVar2 = FUN_8078fd80();
  if (iVar2 + 1U == 0) {
    trap(7);
  }
  sony_ucp_write7(0x30b,param_2 / (iVar2 + 1U));
  sony_ucp_write7(0x30c,1);
  iVar2 = 0;
  do {
    uVar3 = sony_ucp_read7(0x350);
    iVar2 = iVar2 + 1;
    if ((uVar3 & 1) != 0) goto LAB_8079a4f8;
  } while (iVar2 != 0x30571);
  FUN_80747a30(0x350);
LAB_8079a4f8:
  sony_ucp_write7(0x350,3);
  FUN_8079d7d8();
  uVar1 = FUN_8079af08(param_4);
  FUN_8079af10(uVar1,*(undefined4 *)(param_1 + 8));
  sony_ucp_write7(0x30f,0);
  FUN_8079d844();
  FUN_8079a550(param_1,param_3,param_4);
  return;
}

