// FUN_80785c78
// Ghidra address: 80785c78

undefined4 FUN_80785c78(void)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0x80785c90;
  iVar1 = FUN_8079c854(3,0x50b,0xffffffff);
  if (iVar1 != 0) {
    FUN_80745808(&DAT_807c020c,s_________________________src_ipsx_807af9a8,0x41e,uVar2);
  }
  if (DAT_807c01dc != 0) {
    iVar1 = FUN_80786788();
    uVar2 = 0x80785d08;
    iVar1 = FUN_8079c854(3,(*(uint *)(iVar1 + 4) & 7) << 0xc | 0x585,0xffffffff);
    if (iVar1 != 0) {
      FUN_80745808(&DAT_807c020c,s_________________________src_ipsx_807af9a8,0x2b7,uVar2);
    }
    FUN_807867a8();
  }
  FUN_80788848((undefined2)DAT_807c01c8);
  FUN_80786db4(2);
  FUN_80786510();
  return 4;
}

