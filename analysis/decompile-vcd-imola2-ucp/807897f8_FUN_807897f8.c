// FUN_807897f8
// Ghidra address: 807897f8

void FUN_807897f8(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_807873f0((*(uint *)(param_2 + 4) & 0xff) >> 4);
  if (iVar1 == 4) {
    *(ushort *)(param_1 + 0x136) = (ushort)((uint)(*(int *)(param_2 + 0xc) << 5) >> 0x1f);
  }
  return;
}

