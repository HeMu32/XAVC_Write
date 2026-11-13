// Ghidra: 002875c0; ELF VMA = Ghidra - 0x100000

undefined8 catalog_002875c0(long param_1,undefined8 param_2,uint param_3)

{
  undefined8 uVar1;
  
  if ((param_3 <= *(uint *)(param_1 + 0xafc60)) && (param_3 - 1 < 100)) {
    uVar1 = FUN_002872f0();
    return uVar1;
  }
  return 0x67;
}

