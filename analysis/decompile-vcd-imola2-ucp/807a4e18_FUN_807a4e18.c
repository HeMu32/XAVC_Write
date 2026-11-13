// FUN_807a4e18
// Ghidra address: 807a4e18

void FUN_807a4e18(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  FUN_807882b0(param_1,0);
  uVar2 = 0x807a4e48;
  iVar1 = FUN_8079c854(5,0x8501,0xffffffff);
  if (iVar1 != 0) {
    FUN_80745808(&DAT_807c0524,s_________________________src_ipsx_807b0914,0x114,uVar2);
  }
  uVar2 = 0x807a4e74;
  iVar1 = FUN_8079c854(5,param_1,0xffffffff);
  if (iVar1 != 0) {
    FUN_80745808(&DAT_807c0524,s_________________________src_ipsx_807b0914,0x117,uVar2);
  }
  DAT_807c0518 = 1;
  DAT_807c051c = 0;
  DAT_807c0520 = param_1;
  return;
}

