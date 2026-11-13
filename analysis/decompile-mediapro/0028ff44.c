// Ghidra: 0028ff44; ELF VMA = Ghidra - 0x100000

undefined8 FUN_0028ff44(long param_1,undefined8 param_2,undefined4 param_3)

{
  void *pvVar1;
  
  pvVar1 = operator_new(0x90);
  FUN_002900b8(pvVar1,param_2,param_3);
  *(void **)(param_1 + 8) = pvVar1;
  return 0;
}

