// FUN_00280d8c
// Ghidra address: 00280d8c

ulong FUN_00280d8c(long param_1,undefined8 param_2,int param_3,int *param_4)

{
  int iVar1;
  uint uVar2;
  long lVar3;
  ulong uVar4;
  undefined8 uVar5;
  
  lVar3 = *(long *)(param_1 + 8);
  *param_4 = 0;
  if (lVar3 == 0) {
    FUN_001aaa3c(0x2300,0xffffe200,0x28,*(undefined8 *)(param_1 + 0x18));
    uVar4 = 0xb;
  }
  else {
    uVar5 = Fsys_Read();
    iVar1 = (int)uVar5;
    if (iVar1 < 0) {
      uVar4 = FUN_00280ae8(uVar5,*(undefined8 *)(param_1 + 0x18),*(undefined8 *)(param_1 + 8),0xf9);
      return uVar4;
    }
    uVar2 = 0;
    if (iVar1 == 0 && param_3 != iVar1) {
      uVar2 = 0x6f;
    }
    uVar4 = (ulong)uVar2;
    *param_4 = iVar1;
  }
  return uVar4;
}

