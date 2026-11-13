// FUN_0028e160
// Ghidra address: 0028e160

undefined4 FUN_0028e160(long param_1,undefined8 param_2,char param_3)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  undefined4 uVar4;
  undefined *local_18;
  undefined8 uStack_10;
  undefined8 local_8;
  
  FUN_0028e0d0();
  uVar3 = 1;
  *(char *)(*(long *)(param_1 + 0x60) + 0xecf0) = param_3;
  if (param_3 == '\0') {
    uVar3 = 3;
  }
  iVar1 = FUN_00280c20(*(undefined8 *)(param_1 + 0x10),*(undefined8 *)(param_1 + 0x20),uVar3,0);
  if (iVar1 == 0) {
    local_18 = (undefined *)0x0;
    iVar1 = FUN_00280fd8(*(undefined8 *)(param_1 + 0x10),&local_18);
    if (iVar1 == 0) {
      lVar2 = *(long *)(param_1 + 0x60);
      *(int *)(lVar2 + 0xea80) = (int)local_18;
      local_8 = *(undefined8 *)(param_1 + 0x58);
      local_18 = PTR_DAT_00402230 + 0x10;
      uStack_10 = param_2;
      iVar1 = FUN_00292bc8(*(undefined8 *)(param_1 + 0x38),lVar2,&local_18);
      if (iVar1 != 0xe) {
        FUN_0028bc28(*(undefined8 *)(param_1 + 8),1);
        return 0;
      }
      FUN_00290aa4(2,"xavcIfo_CommonMediaProfileParserImplState.cpp",0x91,0xe);
      uVar4 = 0xe;
    }
    else {
      uVar4 = 10;
      FUN_00290aa4(2,"xavcIfo_CommonMediaProfileParserImplState.cpp",0x83,iVar1);
    }
  }
  else {
    uVar4 = 3;
    FUN_00290aa4(2,"xavcIfo_CommonMediaProfileParserImplState.cpp",0x76,iVar1);
  }
  iVar1 = FUN_00280cc4(*(undefined8 *)(param_1 + 0x10));
  if (iVar1 != 0) {
    FUN_00290aa4(2,"xavcIfo_CommonMediaProfileParserImplState.cpp",0x9d,iVar1);
  }
  FUN_0028bc28(*(undefined8 *)(param_1 + 8),2);
  return uVar4;
}

