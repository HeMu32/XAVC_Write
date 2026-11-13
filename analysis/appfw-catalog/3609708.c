// ELF VMA 0x3609708; Ghidra bias 0x100000

undefined4 appfw_3609708(long param_1)

{
  if (*(char *)(param_1 + 0x10) != '\0') {
    return *(undefined4 *)(param_1 + 0x18);
  }
  return *(undefined4 *)(*(long *)(param_1 + 8) + 0xc);
}

