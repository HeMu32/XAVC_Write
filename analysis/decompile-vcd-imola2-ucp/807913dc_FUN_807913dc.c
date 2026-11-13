// FUN_807913dc
// Ghidra address: 807913dc

bool FUN_807913dc(void)

{
  ushort uVar1;
  
  uVar1 = *(ushort *)(DAT_807c0a98 + 2) & 0xf;
  return uVar1 == 1 || uVar1 == 6;
}

