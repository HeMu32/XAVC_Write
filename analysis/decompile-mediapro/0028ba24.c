// Ghidra: 0028ba24; ELF VMA = Ghidra - 0x100000

int FUN_0028ba24(long param_1,undefined8 param_2,undefined4 param_3)

{
  int iVar1;
  void *pvVar2;
  long *plVar3;
  
  pvVar2 = operator_new(0x28);
  FUN_002911c4(pvVar2,*(undefined8 *)(param_1 + 8),param_3);
  plVar3 = *(long **)(param_1 + (long)*(int *)(param_1 + 0x70) * 8 + 0x78);
  iVar1 = (**(code **)(*plVar3 + 0x80))(plVar3,param_2,param_3,pvVar2);
  if (iVar1 != 0) {
    FUN_00290aa4(1,"xavcIfo_CommonMediaProfileParserImpl.cpp",0x16a,iVar1);
  }
  FUN_00291200(pvVar2);
  operator_delete(pvVar2,0x28);
  return iVar1;
}

