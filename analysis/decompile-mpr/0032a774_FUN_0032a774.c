// FUN_0032a774
// Ghidra address: 0032a774

undefined8 FUN_0032a774(long param_1,uint param_2)

{
  void *pvVar1;
  undefined8 uVar2;
  
  if (*(long *)(param_1 + 0x38) == 0) {
    *(uint *)(param_1 + 0x30) = param_2;
    pvVar1 = calloc((ulong)param_2,1);
    *(void **)(param_1 + 0x38) = pvVar1;
    uVar2 = 2;
    if (pvVar1 != (void *)0x0) {
      uVar2 = 0;
    }
    return uVar2;
  }
  return 0;
}

