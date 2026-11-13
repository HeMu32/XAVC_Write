// Ghidra: 0028e8e0; ELF VMA = Ghidra - 0x100000

undefined4 FUN_0028e8e0(long param_1)

{
  int iVar1;
  undefined4 uVar2;
  void *pvVar3;
  
  pvVar3 = operator_new(0x18);
  FUN_00290268();
  *(void **)(param_1 + 0x18) = pvVar3;
  iVar1 = FUN_00290274(pvVar3,35999);
  uVar2 = 100;
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  return uVar2;
}

