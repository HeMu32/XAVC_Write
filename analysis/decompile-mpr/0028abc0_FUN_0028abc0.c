// FUN_0028abc0
// Ghidra address: 0028abc0

int FUN_0028abc0(long param_1,undefined8 param_2,undefined1 param_3)

{
  int iVar1;
  int iVar2;
  long *plVar3;
  
  plVar3 = *(long **)(param_1 + 8);
  if (plVar3 == (long *)0x0) {
    FUN_00290aa4(0,"xavcIfo_CommonMediaProfileParser.cpp",0x2f,0xb);
    iVar1 = 0xb;
  }
  else {
    iVar2 = (**(code **)(*plVar3 + 0x18))(plVar3,param_2,param_3);
    iVar1 = 0;
    if (iVar2 != 0) {
      FUN_00290aa4(0,"xavcIfo_CommonMediaProfileParser.cpp",0x35,iVar2);
      iVar1 = iVar2;
    }
  }
  return iVar1;
}

