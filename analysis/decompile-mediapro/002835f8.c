// Ghidra: 002835f8; ELF VMA = Ghidra - 0x100000

undefined1 catalog_002835f8(long *param_1)

{
  undefined1 uVar1;
  int iVar2;
  void *pvVar3;
  undefined1 auStack_4e0 [624];
  undefined1 auStack_270 [108];
  int iStack_204;
  char cStack_1fc;
  
  memset(auStack_270,0,0x26c);
  iVar2 = (**(code **)(*(long *)param_1[1] + 0x30))((long *)param_1[1],auStack_270);
  if (iVar2 == 0) {
    pvVar3 = memcpy(auStack_4e0,auStack_270,0x26c);
    uVar1 = (**(code **)(*param_1 + 1000))(param_1,pvVar3);
    *(bool *)((long)param_1 + 0xafc75) = iStack_204 != 1 || cStack_1fc != '\0';
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

