// FUN_80791424
// Ghidra address: 80791424

bool FUN_80791424(void)

{
  ushort uVar1;
  
  uVar1 = *(ushort *)(DAT_807c0a98 + 2) & 0xf;
  return uVar1 == 3 || uVar1 == 8;
}

