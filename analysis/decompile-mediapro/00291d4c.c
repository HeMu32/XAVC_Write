// Ghidra: 00291d4c; ELF VMA = Ghidra - 0x100000

undefined8 FUN_00291d4c(undefined8 *param_1)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 auStack_8 [8];
  
  if (*(int *)(param_1 + 3) != 0) {
    iVar1 = FUN_00280f68(*param_1,0,*(undefined4 *)((long)param_1 + 0x1c),auStack_8);
    if (iVar1 == 0) {
      iVar1 = FUN_00280e90(*param_1,param_1[2],*(undefined4 *)(param_1 + 3));
      if (iVar1 == 0) {
        iVar1 = *(int *)(param_1 + 3);
        *(undefined4 *)(param_1 + 3) = 0;
        *(int *)((long)param_1 + 0x1c) = *(int *)((long)param_1 + 0x1c) + iVar1;
        uVar2 = 0;
      }
      else {
        FUN_00290aa4(6,"xavcIfo_MediaProfileParserImplOutputFile.cpp",0x73,iVar1);
        uVar2 = 8;
      }
    }
    else {
      FUN_00290aa4(6,"xavcIfo_MediaProfileParserImplOutputFile.cpp",0x6b,iVar1);
      uVar2 = 5;
    }
    return uVar2;
  }
  return 0;
}

