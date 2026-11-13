// FUN_807817e8
// Ghidra address: 807817e8

undefined4 FUN_807817e8(void)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = 0x80781800;
  iVar2 = FUN_8079c854(3,0x50b,0xffffffff);
  if (iVar2 != 0) {
    FUN_80745808(&DAT_807c0160,s_________________________src_ipsx_807af878,0x703,uVar3);
  }
  if (DAT_807c0140 != 0) {
    iVar2 = FUN_80786788();
    uVar3 = 0x80781880;
    iVar2 = FUN_8079c854(3,(*(uint *)(iVar2 + 4) & 7) << 0xc | 0x585,0xffffffff);
    if (iVar2 != 0) {
      FUN_80745808(&DAT_807c0160,s_________________________src_ipsx_807af878,0x482,uVar3);
    }
    FUN_807867a8();
  }
  uVar1 = FUN_80785394();
  FUN_80788848(uVar1);
  FUN_80786db4(2);
  FUN_807829d0();
  return 4;
}

