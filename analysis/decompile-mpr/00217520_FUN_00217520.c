// FUN_00217520
// Ghidra address: 00217520

void FUN_00217520(long param_1)

{
  int iVar1;
  
  iVar1 = FUN_00322e58(*(undefined8 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x18),1,
                       *(undefined4 *)(param_1 + 0x1c),*(undefined8 *)(param_1 + 0x20));
  if (iVar1 != 0) {
    FUN_001fe0e8(*(undefined8 *)(param_1 + 0x28),iVar1);
  }
  if (*(void **)(param_1 + 0x20) != (void *)0x0) {
    operator_delete__(*(void **)(param_1 + 0x20));
  }
  *(undefined8 *)(param_1 + 0x20) = 0;
  return;
}

