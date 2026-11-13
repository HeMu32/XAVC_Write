// Ghidra: 0028aec0; ELF VMA = Ghidra - 0x100000

int FUN_0028aec0(long param_1)

{
  int iVar1;
  int iVar2;
  
  if (*(long **)(param_1 + 8) == (long *)0x0) {
    FUN_00290aa4(0,"xavcIfo_CommonMediaProfileParser.cpp",0x98,0xb);
    iVar1 = 0xb;
  }
  else {
    iVar2 = (**(code **)(**(long **)(param_1 + 8) + 0x50))();
    iVar1 = 0;
    if (iVar2 != 0) {
      FUN_00290aa4(0,"xavcIfo_CommonMediaProfileParser.cpp",0x9e,iVar2);
      iVar1 = iVar2;
    }
  }
  return iVar1;
}

