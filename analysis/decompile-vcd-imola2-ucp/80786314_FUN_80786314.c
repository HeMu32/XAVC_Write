// FUN_80786314
// Ghidra address: 80786314

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_80786314(void)

{
  uint3 uVar1;
  int iVar2;
  undefined4 uVar3;
  int local_20 [4];
  
  FUN_807468c0();
  FUN_80786aa0(2,local_20);
  uVar3 = 0;
  if (local_20[0] != 2) {
    DAT_807c01d4 = DAT_807c01d4 + 1;
    uVar1 = CONCAT12((undefined1)DAT_807c01e0,(undefined2)DAT_807c01e8);
    DAT_807c01dc = 0;
    if (_DAT_807c01d8 == 2) {
      FUN_80747230(0x850b,(uint)uVar1);
    }
    (*(code *)(&PTR_LAB_807c0200)[DAT_807c01f0])();
    iVar2 = FUN_80786788();
    uVar3 = 0x807863b0;
    iVar2 = FUN_8079c854(3,(*(uint *)(iVar2 + 4) & 7) << 0xc | 0x505,0xffffffff);
    if (iVar2 != 0) {
      FUN_80745808(&DAT_807c020c,s_________________________src_ipsx_807af9a8,0x2b7,uVar3);
    }
    FUN_8078895c((undefined2)DAT_807c01c8,(uint)uVar1);
    FUN_807867a8();
    uVar3 = 1;
  }
  return uVar3;
}

