// FUN_0028d7e4
// Ghidra address: 0028d7e4

int FUN_0028d7e4(long param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4,
                undefined8 param_5)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined8 uVar4;
  
  iVar1 = FUN_00280c20(*(undefined8 *)(param_1 + 0x10),*(undefined8 *)(param_1 + 0x18),6,0);
  if (iVar1 == 0) {
    FUN_0029213c(param_5);
    FUN_00292148(param_5,param_2,param_3);
    FUN_00291d44(param_4,0);
    uVar4 = FUN_002921b0(param_5);
    uVar2 = FUN_002921b8(param_5);
    iVar3 = FUN_00291dfc(param_4,uVar4,uVar2);
    iVar1 = 0;
    if (iVar3 != 0) {
      FUN_0028bc28(*(undefined8 *)(param_1 + 8),2);
      FUN_00290aa4(2,"xavcIfo_CommonMediaProfileParserImplState.cpp",0x56c,iVar3);
      iVar1 = iVar3;
    }
  }
  else {
    FUN_00290aa4(2,"xavcIfo_CommonMediaProfileParserImplState.cpp",0x556,iVar1);
    FUN_00280cc4(*(undefined8 *)(param_1 + 0x10));
    FUN_0028bc28(*(undefined8 *)(param_1 + 8),2);
    iVar1 = 9;
  }
  return iVar1;
}

