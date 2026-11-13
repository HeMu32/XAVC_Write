// FUN_80791400
// Ghidra address: 80791400

bool FUN_80791400(void)

{
  ushort uVar1;
  
  uVar1 = *(ushort *)(DAT_807c0a98 + 2) & 0xf;
  return uVar1 == 4 || uVar1 == 9;
}

