// Ghidra: 00286954; ELF VMA = Ghidra - 0x100000

void catalog_00286954(long param_1,undefined1 param_2,undefined1 param_3)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0xc0670);
  *(undefined1 *)(lVar1 + 8) = param_2;
  *(undefined1 *)(lVar1 + 9) = param_3;
  FUN_00286874();
  return;
}

