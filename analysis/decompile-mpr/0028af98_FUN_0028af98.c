// FUN_0028af98
// Ghidra address: 0028af98

int FUN_0028af98(long param_1)

{
  int iVar1;
  int iVar2;
  
  if (*(long **)(param_1 + 8) == (long *)0x0) {
    FUN_00290aa4(0,"xavcIfo_CommonMediaProfileParser.cpp",0xb7,0xb);
    iVar1 = 0xb;
  }
  else {
    iVar2 = (**(code **)(**(long **)(param_1 + 8) + 0x60))();
    iVar1 = 0;
    if (iVar2 != 0) {
      FUN_00290aa4(0,"xavcIfo_CommonMediaProfileParser.cpp",0xbd,iVar2);
      iVar1 = iVar2;
    }
  }
  return iVar1;
}

