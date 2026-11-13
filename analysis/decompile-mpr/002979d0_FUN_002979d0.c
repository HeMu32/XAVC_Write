// FUN_002979d0
// Ghidra address: 002979d0

int FUN_002979d0(long param_1,undefined8 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  
  iVar1 = FUN_00280c20(*(undefined8 *)(param_1 + 0x10),*(undefined8 *)(param_1 + 0x18),6,0);
  if (iVar1 == 0) {
    FUN_0029213c(*(undefined8 *)(param_1 + 0x48));
    iVar1 = FUN_00295858(*(undefined8 *)(param_1 + 0x40),*(undefined8 *)(param_1 + 0x48),param_2);
    if (iVar1 == 0) {
      FUN_00291d44(*(undefined8 *)(param_1 + 0x30),0);
      uVar5 = *(undefined8 *)(param_1 + 0x30);
      uVar4 = FUN_002921b0(*(undefined8 *)(param_1 + 0x48));
      uVar3 = FUN_002921b8(*(undefined8 *)(param_1 + 0x48));
      iVar1 = FUN_00291f58(uVar5,uVar4,uVar3);
      if (iVar1 == 0) {
        uVar4 = *(undefined8 *)(param_1 + 0x30);
        iVar1 = FUN_002921b8(*(undefined8 *)(param_1 + 0x48));
        iVar1 = FUN_00292080(uVar4,0x20,0x200000 - iVar1);
        if (iVar1 == 0) {
          *(undefined4 *)(*(long *)(param_1 + 0x60) + 0xea80) = 0x200000;
          iVar2 = FUN_00291d4c(*(undefined8 *)(param_1 + 0x30));
          iVar1 = 0;
          if (iVar2 != 0) {
            FUN_00290aa4(2,"xavcIfo_PxMediaProfileParserImplState.cpp",0x61,iVar2);
            iVar1 = iVar2;
          }
          goto LAB_00297a1c;
        }
        uVar4 = 0x57;
      }
      else {
        uVar4 = 0x4e;
      }
    }
    else {
      uVar4 = 0x41;
    }
    FUN_00290aa4(2,"xavcIfo_PxMediaProfileParserImplState.cpp",uVar4,iVar1);
  }
  else {
    FUN_00290aa4(2,"xavcIfo_PxMediaProfileParserImplState.cpp",0x34,iVar1);
    iVar1 = 9;
  }
LAB_00297a1c:
  iVar2 = FUN_00280cc4(*(undefined8 *)(param_1 + 0x10));
  if (iVar2 == 0) {
    uVar4 = 0;
    if (iVar1 == 0) goto LAB_00297b50;
  }
  else {
    FUN_00290aa4(2,"xavcIfo_PxMediaProfileParserImplState.cpp",0x6f,iVar2);
    if (iVar1 == 0) {
      iVar1 = 4;
    }
  }
  uVar4 = 2;
LAB_00297b50:
  FUN_0028bc28(*(undefined8 *)(param_1 + 8),uVar4);
  return iVar1;
}

