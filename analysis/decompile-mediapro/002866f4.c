// Ghidra: 002866f4; ELF VMA = Ghidra - 0x100000

undefined8 catalog_002866f4(long param_1,uint param_2)

{
  undefined8 uVar1;
  
  if ((param_2 != 0) && (param_2 <= *(uint *)(param_1 + 0xafc60))) {
    uVar1 = FUN_0028662c();
    return uVar1;
  }
  return 0x67;
}

