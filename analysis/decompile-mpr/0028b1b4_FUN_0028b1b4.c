// FUN_0028b1b4
// Ghidra address: 0028b1b4

int FUN_0028b1b4(long param_1,undefined1 param_2)

{
  int iVar1;
  int iVar2;
  long *plVar3;
  
  plVar3 = *(long **)(param_1 + 8);
  if (plVar3 == (long *)0x0) {
    FUN_00290aa4(0,"xavcIfo_CommonMediaProfileParser.cpp",0x106,0xb);
    iVar1 = 0xb;
  }
  else {
    iVar2 = (**(code **)(*plVar3 + 0x88))(plVar3,param_2);
    iVar1 = 0;
    if (iVar2 != 0) {
      FUN_00290aa4(0,"xavcIfo_CommonMediaProfileParser.cpp",0x10c,iVar2);
      iVar1 = iVar2;
    }
  }
  return iVar1;
}

