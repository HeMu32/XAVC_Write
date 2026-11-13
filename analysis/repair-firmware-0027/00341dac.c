// FUN_00341dac
// Ghidra address 00341dac; ELF VMA = Ghidra - 0x100000

undefined1 FUN_00341dac(long param_1,long param_2,ulong param_3)

{
  undefined1 uVar1;
  int iVar2;
  ulong uVar3;
  undefined8 local_10;
  undefined1 local_8;
  undefined4 local_4;
  
  local_8 = 0;
  local_4 = 8;
  uVar1 = 1;
  local_10 = 0;
  if ((param_2 != 0) && (uVar1 = 2, *(ulong *)(param_1 + 0x40) <= (param_3 & 0xffffffff))) {
    iVar2 = Fsys_Seek(*(undefined8 *)(param_1 + 8),*(undefined8 *)(param_1 + 0x38),0,0);
    if ((iVar2 == 0) &&
       ((uVar3 = Fsys_Read(*(undefined8 *)(param_1 + 8),param_2,*(undefined4 *)(param_1 + 0x40)),
        *(ulong *)(param_1 + 0x40) == (uVar3 & 0xffffffff) &&
        (iVar2 = Fsys_Seek(*(undefined8 *)(param_1 + 8),
                           *(long *)(param_1 + 0x28) + *(long *)(param_1 + 0x30),0,0), iVar2 == 0)))
       ) {
      iVar2 = FUN_00341c44(param_1,&local_10);
      uVar1 = iVar2 == 0;
    }
    else {
      uVar1 = 3;
    }
  }
  return uVar1;
}

