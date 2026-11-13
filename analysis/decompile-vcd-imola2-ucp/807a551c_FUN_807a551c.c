// FUN_807a551c
// Ghidra address: 807a551c

void FUN_807a551c(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 unaff_retaddr;
  undefined4 uVar3;
  
  if (param_1 != 0) {
    unaff_retaddr = 0x807a5670;
    FUN_80745808(&DAT_807c0524,s_________________________src_ipsx_807b0914,0x74);
  }
  if (((&DAT_807c0518)[param_1] == 2) && ((param_1 == 0 || (DAT_807c0518 != 2)))) {
    unaff_retaddr = 0x807a5634;
    iVar1 = FUN_8079c854(3,0x504,0xffffffff);
    if (iVar1 == 0) goto LAB_807a5570;
    uVar2 = 0x1b0;
  }
  else {
    if (param_1 != 0) {
      uVar2 = 0x807a5608;
      FUN_80745808(&DAT_807c0524,s_________________________src_ipsx_807b0914,0x74,unaff_retaddr);
      unaff_retaddr = uVar2;
    }
    if ((&DAT_807c0518)[param_1] != 1) goto LAB_807a5570;
    unaff_retaddr = 0x807a55c4;
    iVar1 = FUN_8079c854(3,0x509,0xffffffff);
    if (iVar1 == 0) goto LAB_807a5570;
    uVar2 = 0x1a8;
  }
  uVar3 = 0x807a55e8;
  FUN_80745808(&DAT_807c0524,s_________________________src_ipsx_807b0914,uVar2,unaff_retaddr);
  unaff_retaddr = uVar3;
LAB_807a5570:
  if (param_1 != 0) {
    FUN_80745808(&DAT_807c0524,s_________________________src_ipsx_807b0914,0x56,unaff_retaddr);
  }
  (&DAT_807c0518)[param_1] = 0;
  return;
}

