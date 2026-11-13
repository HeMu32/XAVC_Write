// Ghidra: 00280c20; ELF VMA = Ghidra - 0x100000

ulong FUN_00280c20(long param_1,undefined8 param_2,undefined4 param_3,long *param_4)

{
  ulong uVar1;
  
  *(undefined8 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined8 *)(param_1 + 0x18) = 0;
  uVar1 = Fsys_Open(param_2,param_1 + 8);
  if ((int)uVar1 != 0) {
    uVar1 = FUN_00280ae8(uVar1,param_2,0,0x3d);
    return uVar1;
  }
  uVar1 = uVar1 & 0xffffffff;
  if (*(long *)(param_1 + 8) == 0) {
    FUN_001aaa3c(0x2300,0xffffe000,0x28,param_2);
    uVar1 = 3;
  }
  else {
    *(undefined4 *)(param_1 + 0x10) = param_3;
    *(undefined8 *)(param_1 + 0x18) = param_2;
    if (param_4 != (long *)0x0) {
      *param_4 = *(long *)(param_1 + 8);
    }
  }
  return uVar1;
}

