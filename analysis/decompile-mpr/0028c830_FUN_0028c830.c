// FUN_0028c830
// Ghidra address: 0028c830

int FUN_0028c830(long param_1,undefined8 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  
  iVar1 = FUN_00280c20(*(undefined8 *)(param_1 + 0x10),*(undefined8 *)(param_1 + 0x20),6,0);
  if (iVar1 == 0) {
    FUN_0029213c(*(undefined8 *)(param_1 + 0x48));
    iVar1 = FUN_00295858(*(undefined8 *)(param_1 + 0x40),*(undefined8 *)(param_1 + 0x48),param_2);
    if (iVar1 == 0) {
      FUN_00291d44(*(undefined8 *)(param_1 + 0x30),0);
      uVar5 = *(undefined8 *)(param_1 + 0x30);
      uVar4 = FUN_002921b0(*(undefined8 *)(param_1 + 0x48));
      uVar3 = FUN_002921b8(*(undefined8 *)(param_1 + 0x48));
      iVar1 = FUN_00291dfc(uVar5,uVar4,uVar3);
      if (iVar1 == 0) {
        iVar2 = FUN_00291d4c(*(undefined8 *)(param_1 + 0x30));
        iVar1 = 0;
        if (iVar2 != 0) {
          FUN_00290aa4(2,"xavcIfo_CommonMediaProfileParserImplState.cpp",0xda,iVar2);
          iVar1 = iVar2;
        }
        goto LAB_0028c87c;
      }
      uVar4 = 0xd1;
    }
    else {
      uVar4 = 0xc4;
    }
    FUN_00290aa4(2,"xavcIfo_CommonMediaProfileParserImplState.cpp",uVar4,iVar1);
  }
  else {
    FUN_00290aa4(2,"xavcIfo_CommonMediaProfileParserImplState.cpp",0xb7,iVar1);
    iVar1 = 9;
  }
LAB_0028c87c:
  iVar2 = FUN_00280cc4(*(undefined8 *)(param_1 + 0x10));
  if (iVar2 == 0) {
    uVar4 = 0;
    if (iVar1 == 0) goto LAB_0028c970;
  }
  else {
    FUN_00290aa4(2,"xavcIfo_CommonMediaProfileParserImplState.cpp",0xe8,iVar2);
    if (iVar1 == 0) {
      iVar1 = 4;
    }
  }
  uVar4 = 2;
LAB_0028c970:
  FUN_0028bc28(*(undefined8 *)(param_1 + 8),uVar4);
  return iVar1;
}

