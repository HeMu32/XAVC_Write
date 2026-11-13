// Ghidra: 0028bac4; ELF VMA = Ghidra - 0x100000

int FUN_0028bac4(long param_1,undefined8 param_2,undefined4 param_3,void *param_4,undefined4 param_5
                )

{
  int iVar1;
  void *pvVar2;
  void *pvVar3;
  long *plVar4;
  void *pvVar5;
  undefined1 auStack_5f0 [1520];
  
  pvVar2 = operator_new(0x20);
  FUN_00291d00(pvVar2,*(undefined8 *)(param_1 + 8),param_3);
  pvVar3 = operator_new(0x18);
  FUN_002920f8(pvVar3,param_3);
  plVar4 = *(long **)(param_1 + (long)*(int *)(param_1 + 0x70) * 8 + 0x78);
  (**(code **)(*plVar4 + 0x88))(plVar4,param_2,param_3,pvVar2,pvVar3);
  plVar4 = *(long **)(param_1 + (long)*(int *)(param_1 + 0x70) * 8 + 0x78);
  pvVar5 = memcpy(auStack_5f0,param_4,0x5e8);
  iVar1 = (**(code **)(*plVar4 + 0x90))(plVar4,pvVar5,param_5,pvVar2);
  if (iVar1 != 0) {
    FUN_00290aa4(1,"xavcIfo_CommonMediaProfileParserImpl.cpp",0x17c,iVar1);
  }
  FUN_00291d34(pvVar2);
  operator_delete(pvVar2,0x20);
  FUN_0029212c(pvVar3);
  operator_delete(pvVar3,0x18);
  return iVar1;
}

