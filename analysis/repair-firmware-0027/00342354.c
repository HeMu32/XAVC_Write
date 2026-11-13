// FUN_00342354
// Ghidra address 00342354; ELF VMA = Ghidra - 0x100000

int FUN_00342354(long param_1,undefined4 *param_2)

{
  int iVar1;
  undefined8 local_10;
  undefined1 local_8;
  undefined4 local_4;
  
  local_8 = 0;
  local_10 = 0;
  local_4 = 8;
  if (param_2 != (undefined4 *)0x0) {
    iVar1 = FUN_00341e8c(param_1,param_1 + 0x10);
    if (iVar1 != 0) {
      return iVar1;
    }
    iVar1 = Fsys_Seek(*(undefined8 *)(param_1 + 8),
                      *(long *)(param_1 + 0x28) + *(long *)(param_1 + 0x30),0,0);
    if (iVar1 != 0) {
      return 3;
    }
    iVar1 = FUN_00341c44(param_1,&local_10);
    if (iVar1 != 0) {
      *param_2 = (int)*(undefined8 *)(param_1 + 0x40);
      return 0;
    }
  }
  return 1;
}

