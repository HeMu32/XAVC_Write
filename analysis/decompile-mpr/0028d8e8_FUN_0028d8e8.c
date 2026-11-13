// FUN_0028d8e8
// Ghidra address: 0028d8e8

undefined8 FUN_0028d8e8(long param_1)

{
  int iVar1;
  undefined8 uVar2;
  
  iVar1 = FUN_00280cc4(*(undefined8 *)(param_1 + 0x10));
  if (iVar1 == 0) {
    FUN_0028bc28(*(undefined8 *)(param_1 + 8),0);
    uVar2 = 0;
  }
  else {
    FUN_0028bc28(*(undefined8 *)(param_1 + 8),2);
    FUN_00290aa4(2,"xavcIfo_CommonMediaProfileParserImplState.cpp",0x19f,iVar1);
    uVar2 = 4;
  }
  return uVar2;
}

