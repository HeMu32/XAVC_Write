// Ghidra: 00286874; ELF VMA = Ghidra - 0x100000

int FUN_00286874(long *param_1,byte param_2,byte param_3)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  long *plVar4;
  long lVar5;
  code *pcVar6;
  
  (**(code **)(*(long *)*param_1 + 0x1e8))();
  lVar5 = *param_1;
  plVar4 = *(long **)(lVar5 + 8);
  if (plVar4 == (long *)0x0) {
    return 0x6c;
  }
  pcVar6 = *(code **)(*plVar4 + 0x18);
  *(undefined4 *)(lVar5 + 0x28) = 0;
  uVar2 = (*pcVar6)(plVar4,*(undefined8 *)(lVar5 + 0x10),param_2 | param_3);
  iVar3 = (**(code **)(*(long *)*param_1 + 0x390))((long *)*param_1,uVar2);
  if (iVar3 != 0) {
    return iVar3;
  }
  plVar4 = (long *)*param_1;
  uVar2 = 3;
  if (param_2 == 0) {
    cVar1 = (**(code **)(*plVar4 + 0x3a0))();
    if (param_3 == 0 && cVar1 == '\x01') goto LAB_0028690c;
    plVar4 = (long *)*param_1;
    uVar2 = 2;
  }
  *(undefined4 *)(plVar4 + 5) = uVar2;
LAB_0028690c:
  lVar5 = *param_1;
  if (*(int *)(lVar5 + 0xafc70) != *(int *)(lVar5 + 0xafc68) + *(int *)(lVar5 + 0xafc6c)) {
    return 0x6c;
  }
  return 0;
}

