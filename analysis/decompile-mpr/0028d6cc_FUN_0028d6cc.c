// FUN_0028d6cc
// Ghidra address: 0028d6cc

int FUN_0028d6cc(long param_1,void *param_2,uint param_3)

{
  char cVar1;
  int iVar2;
  void *local_8;
  
  if (param_3 < **(uint **)(param_1 + 0x60)) {
    local_8 = (void *)FUN_00291428(*(undefined8 *)(param_1 + 0x58),param_3);
    if (local_8 == (void *)0x0) {
      iVar2 = *(int *)(*(long *)(param_1 + 0x60) + (ulong)param_3 * 4 + 0x20);
      iVar2 = FUN_00292c68(*(undefined8 *)(param_1 + 0x38),&local_8,iVar2,
                           *(int *)(*(long *)(param_1 + 0x60) + ((ulong)(param_3 + 1) + 8) * 4) -
                           iVar2);
      if (iVar2 != 0) {
        if (iVar2 == 0xe) {
          FUN_0028bc28(*(undefined8 *)(param_1 + 8),2);
        }
        FUN_00290aa4(2,"xavcIfo_CommonMediaProfileParserImplState.cpp",0x1d3,iVar2);
        return iVar2;
      }
      cVar1 = FUN_00291914(*(undefined8 *)(param_1 + 0x58),param_3,local_8);
      if (cVar1 == '\0') {
        FUN_00290aa4(2,"xavcIfo_CommonMediaProfileParserImplState.cpp",0x1db,0);
      }
    }
    memcpy(param_2,local_8,0x5e8);
    iVar2 = 0;
  }
  else {
    FUN_00290aa4(2,"xavcIfo_CommonMediaProfileParserImplState.cpp",0x1c0,0x67);
    iVar2 = 0x67;
  }
  return iVar2;
}

