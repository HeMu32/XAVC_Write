// Ghidra: 00280cc4; ELF VMA = Ghidra - 0x100000

undefined8 FUN_00280cc4(long param_1)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  if (*(long *)(param_1 + 8) == 0) {
    FUN_001aaa3c(0x2300,0xffffe100,0x28,*(undefined8 *)(param_1 + 0x18));
    uVar2 = 0xb;
    goto LAB_00280cf4;
  }
  if ((*(uint *)(param_1 + 0x10) & 1) == 0) {
    if ((*(uint *)(param_1 + 0x10) >> 1 & 1) == 0) {
      uVar2 = Fsys_Close();
      if ((int)uVar2 != 0) {
        uVar3 = 0x95;
LAB_00280d34:
        uVar2 = FUN_00280ae8(uVar2,*(undefined8 *)(param_1 + 0x18),*(undefined8 *)(param_1 + 8),
                             uVar3);
        goto LAB_00280cf4;
      }
    }
    else {
      uVar2 = Fsys_Flush();
      if (((int)uVar2 != 0) &&
         (uVar2 = FUN_00280ae8(uVar2,*(undefined8 *)(param_1 + 0x18),*(undefined8 *)(param_1 + 8),
                               0x7f), (int)uVar2 != 0)) goto LAB_00280cf4;
      uVar2 = Fsys_Close(*(undefined8 *)(param_1 + 8));
      if ((int)uVar2 != 0) {
        uVar3 = 0x89;
        goto LAB_00280d34;
      }
    }
  }
  else {
    iVar1 = Fsys_Close();
    if (iVar1 != 0) {
      uVar2 = Fsys_Close(*(undefined8 *)(param_1 + 8));
      uVar3 = 0x73;
      if ((int)uVar2 != 0) goto LAB_00280d34;
    }
  }
  uVar2 = 0;
LAB_00280cf4:
  *(undefined8 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined8 *)(param_1 + 0x18) = 0;
  return uVar2;
}

