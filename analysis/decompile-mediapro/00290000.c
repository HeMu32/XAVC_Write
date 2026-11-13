// Ghidra: 00290000; ELF VMA = Ghidra - 0x100000

undefined8 FUN_00290000(long param_1)

{
  void *pvVar1;
  undefined8 uVar2;
  
  pvVar1 = operator_new(0x68);
  FUN_0029019c(pvVar1,param_1);
  *(void **)(param_1 + 0x78) = pvVar1;
  pvVar1 = operator_new(0x68);
  FUN_002901cc(pvVar1,param_1);
  *(void **)(param_1 + 0x80) = pvVar1;
  pvVar1 = operator_new(0x68);
  FUN_002901fc(pvVar1,param_1);
  *(void **)(param_1 + 0x88) = pvVar1;
  if (*(long *)(param_1 + 0x78) == 0) {
    FUN_0028bc28(param_1,2);
    uVar2 = 0x32;
  }
  else {
    if (*(long *)(param_1 + 0x80) != 0) {
      return 0;
    }
    FUN_0028bc28(param_1,2);
    uVar2 = 0x38;
  }
  FUN_00290aa4(1,"xavcIfo_M4MediaProfileParserImpl.cpp",uVar2);
  return 1;
}

