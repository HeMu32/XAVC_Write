// FUN_807a5130
// Ghidra address: 807a5130

undefined4 FUN_807a5130(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  uVar3 = 0x807a514c;
  FUN_807a5454();
  uVar2 = uVar3;
  if (param_1 != 0) {
    uVar2 = 0x807a52a8;
    FUN_80745808(&DAT_807c0524,s_________________________src_ipsx_807b0914,0x74,uVar3);
  }
  if (((&DAT_807c0518)[param_1] == 2) && ((param_1 == 0 || (DAT_807c0518 != 2)))) {
    uVar2 = 0x807a5270;
    iVar1 = FUN_8079c854(3,0x504,0xffffffff);
    if (iVar1 == 0) goto LAB_807a518c;
    uVar3 = 0x1b0;
  }
  else {
    if (param_1 != 0) {
      uVar3 = 0x807a5244;
      FUN_80745808(&DAT_807c0524,s_________________________src_ipsx_807b0914,0x74,uVar2);
      uVar2 = uVar3;
    }
    if ((&DAT_807c0518)[param_1] != 1) goto LAB_807a518c;
    uVar2 = 0x807a5200;
    iVar1 = FUN_8079c854(3,0x509,0xffffffff);
    if (iVar1 == 0) goto LAB_807a518c;
    uVar3 = 0x1a8;
  }
  uVar4 = 0x807a5224;
  FUN_80745808(&DAT_807c0524,s_________________________src_ipsx_807b0914,uVar3,uVar2);
  uVar2 = uVar4;
LAB_807a518c:
  if (param_1 != 0) {
    FUN_80745808(&DAT_807c0524,s_________________________src_ipsx_807b0914,0x56,uVar2);
  }
  (&DAT_807c0518)[param_1] = 0;
  uVar2 = 2;
  if (DAT_807c0518 == 0) {
    FUN_807a5678();
    uVar2 = 3;
  }
  return uVar2;
}

