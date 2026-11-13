// FUN_807913bc
// Ghidra address: 807913bc

bool FUN_807913bc(void)

{
  return (*(ushort *)(DAT_807c0a98 + 2) & 0xf) == 0 || (*(ushort *)(DAT_807c0a98 + 2) & 0xf) == 5;
}

