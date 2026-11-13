// FUN_002c0044
// Ghidra address: 002c0044

long FUN_002c0044(long param_1,int param_2)

{
  int iVar1;
  long lVar2;
  ulong uVar3;
  
  lVar2 = 0;
  for (uVar3 = 0; uVar3 < *(ulong *)(param_1 + 0x118); uVar3 = uVar3 + 1) {
    iVar1 = FUN_002bdde4(*(undefined1 *)(*(long *)(param_1 + 0x110) + uVar3),param_2);
    lVar2 = param_2 * lVar2 + (long)iVar1;
  }
  return lVar2;
}

