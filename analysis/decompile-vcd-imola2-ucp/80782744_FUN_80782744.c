// FUN_80782744
// Ghidra address: 80782744

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_80782744(void)

{
  uint3 uVar1;
  undefined2 uVar2;
  int iVar3;
  undefined4 uVar4;
  int local_20 [4];
  
  uVar1 = CONCAT12((undefined1)DAT_807c012c,(undefined2)DAT_807c0134);
  FUN_807468c0();
  FUN_80786aa0(2,local_20);
  uVar4 = 0;
  if (local_20[0] != 2) {
    DAT_807c0138 = DAT_807c0138 + 1;
    DAT_807c0140 = 0;
    if (_DAT_807c013c == 2) {
      FUN_80747230(0x850b,(uint)uVar1);
    }
    FUN_80788928(0x124,0,0);
    uVar4 = 0x807827d0;
    iVar3 = FUN_8079c854(3,(*(uint *)(DAT_807c0114 + 4) & 7) << 0xc | 0x505,0xffffffff);
    if (iVar3 != 0) {
      FUN_80745808(&DAT_807c0160,s_________________________src_ipsx_807af878,0x482,uVar4);
    }
    (*(code *)(&PTR_LAB_807c0154)[DAT_807c0144])();
    uVar2 = FUN_80785394();
    FUN_8078895c(uVar2,(uint)uVar1);
    uVar4 = 1;
  }
  return uVar4;
}

