// FUN_00341af0
// Ghidra address 00341af0; ELF VMA = Ghidra - 0x100000

undefined8 FUN_00341af0(long param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  iVar1 = Fsys_Open(param_2,param_1 + 8);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = 3;
    *(undefined8 *)(param_1 + 8) = 0;
  }
  return uVar2;
}

