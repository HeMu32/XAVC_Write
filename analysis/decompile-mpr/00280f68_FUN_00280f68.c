// FUN_00280f68
// Ghidra address: 00280f68

ulong FUN_00280f68(long param_1,undefined4 param_2,undefined8 param_3)

{
  ulong uVar1;
  ulong uVar2;
  
  if (*(long *)(param_1 + 8) == 0) {
    FUN_001aaa3c(0x2300,0xffffe600,0x28,*(undefined8 *)(param_1 + 0x18));
    uVar2 = 0xb;
  }
  else {
    uVar1 = Fsys_Seek(*(long *)(param_1 + 8),param_3,param_2);
    uVar2 = uVar1 & 0xffffffff;
    if ((int)uVar1 != 0) {
      uVar1 = FUN_00280ae8(uVar1,*(undefined8 *)(param_1 + 0x18),*(undefined8 *)(param_1 + 8),0x18d)
      ;
      return uVar1;
    }
  }
  return uVar2;
}

