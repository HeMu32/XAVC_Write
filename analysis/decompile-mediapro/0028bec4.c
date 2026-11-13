// Ghidra: 0028bec4; ELF VMA = Ghidra - 0x100000

bool FUN_0028bec4(long param_1,undefined1 param_2)

{
  size_t sVar1;
  undefined1 *puVar2;
  
  sVar1 = strlen(*(char **)(param_1 + 0x18));
  puVar2 = *(undefined1 **)(param_1 + 0x20);
  if (puVar2 != (undefined1 *)0x0) {
    *puVar2 = param_2;
    *(undefined1 *)(*(long *)(param_1 + 0x20) + 1) = 0x3a;
    memcpy((void *)(*(long *)(param_1 + 0x20) + 2),*(void **)(param_1 + 0x18),
           (ulong)((int)sVar1 + 1));
  }
  else {
    FUN_0028bc28(param_1,2);
    FUN_00290aa4(1,"xavcIfo_CommonMediaProfileParserImpl.cpp",0x14b);
  }
  return puVar2 == (undefined1 *)0x0;
}

