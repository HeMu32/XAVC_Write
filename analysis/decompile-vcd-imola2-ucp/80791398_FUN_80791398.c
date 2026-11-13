// FUN_80791398
// Ghidra address: 80791398

bool FUN_80791398(void)

{
  ushort uVar1;
  
  uVar1 = *(ushort *)(DAT_807c0a98 + 2) & 0xf;
  return uVar1 == 2 || uVar1 == 7;
}

