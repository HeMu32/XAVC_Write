// FUN_8079a368
// Ghidra address: 8079a368

void FUN_8079a368(int param_1,uint *param_2,undefined1 param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  bool bVar3;
  
  uVar1 = FUN_807868c0(param_4);
  if (uVar1 < 6) {
    iVar2 = 0;
    do {
      uVar1 = sony_ucp_read7(0x350);
      iVar2 = iVar2 + 1;
      if ((uVar1 & 1) != 0) goto LAB_8079a3d0;
    } while (iVar2 != 0x30571);
    FUN_80747a30(0x350);
LAB_8079a3d0:
    sony_ucp_write7(0x350,0xb);
    uVar1 = *param_2;
  }
  else {
    uVar1 = *param_2;
  }
  bVar3 = false;
  if ((uVar1 & 0xf) == 1 || (uVar1 & 0xf) == 3) {
    uVar1 = FUN_8079168c(0);
    bVar3 = uVar1 == *param_2 >> 0xc;
  }
  FUN_8079acc8(bVar3,param_4,*(undefined4 *)(param_1 + 8));
  FUN_8079a550(param_1,param_3,param_4);
  return;
}

