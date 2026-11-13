// FUN_0028b290
// Ghidra address: 0028b290

int FUN_0028b290(long param_1)

{
  int iVar1;
  int iVar2;
  
  if (*(long **)(param_1 + 8) == (long *)0x0) {
    FUN_00290aa4(0,"xavcIfo_CommonMediaProfileParser.cpp",0x12d,0xb);
    iVar1 = 0xb;
  }
  else {
    iVar2 = (**(code **)(**(long **)(param_1 + 8) + 0x98))();
    iVar1 = 0;
    if (iVar2 != 0) {
      FUN_00290aa4(0,"xavcIfo_CommonMediaProfileParser.cpp",0x133,iVar2);
      iVar1 = iVar2;
    }
  }
  return iVar1;
}

