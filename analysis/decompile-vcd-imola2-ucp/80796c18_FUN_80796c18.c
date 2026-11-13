// FUN_80796c18
// Ghidra address: 80796c18

undefined4 FUN_80796c18(uint param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  uint uVar2;
  
  if (param_3 != 1) {
    if (param_3 == 0) {
      if (param_1 == 1) {
        *DAT_807c0afc = *DAT_807c0afc | 0x40000;
LAB_80796d08:
        FUN_80796334(param_2);
        return 1;
      }
    }
    else if (param_3 == 2) {
      if (param_1 != 1) goto LAB_80796d08;
    }
    else {
      FUN_80745808(&DAT_807c03f8,s_________________________src_ipsx_807aff38,0x2b3);
    }
  }
  uVar2 = param_1;
  if (0x2c < param_1) {
    uVar2 = param_1 - 0x23;
  }
  if (0x7f < param_1) {
    uVar2 = param_1 - 0x68;
  }
  if (uVar2 < 0x1f) {
    uVar1 = (*(code *)(&PTR_FUN_807b56d0)[uVar2])(param_2);
    if ((DAT_807c03e8 & 7) != 0) {
      DAT_807c03e8 = DAT_807c03e8 + (8 - (DAT_807c03e8 & 7));
      FUN_8079408c();
    }
  }
  else {
    FUN_80796334(param_2);
    uVar1 = 1;
  }
  return uVar1;
}

