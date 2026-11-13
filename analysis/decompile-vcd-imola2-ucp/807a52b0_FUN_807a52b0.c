// FUN_807a52b0
// Ghidra address: 807a52b0

undefined4 FUN_807a52b0(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = 0x807a52d0;
  iVar2 = FUN_8079c854(3,0x50a,0xffffffff);
  if (iVar2 != 0) {
    uVar1 = 0x807a5370;
    FUN_80745808(&DAT_807c0524,s_________________________src_ipsx_807b0914,0x1e5,uVar3);
    uVar3 = uVar1;
  }
  if (param_1 != 0) {
    FUN_80745808(&DAT_807c0524,s_________________________src_ipsx_807b0914,0xcd,uVar3);
  }
  FUN_807874ec((&DAT_807c0520)[param_1 * 2]);
  FUN_807a551c(param_1);
  FUN_807a5768(param_1);
  uVar3 = 2;
  if (DAT_807c0518 == 0) {
    FUN_807a5678();
    uVar3 = 3;
  }
  return uVar3;
}

