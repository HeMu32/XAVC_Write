// FUN_003cda58
// Ghidra address: 003cda58

void FUN_003cda58(undefined2 *param_1,long param_2)

{
  byte bVar1;
  
  FUN_003cd954();
  *(undefined1 *)(param_2 + 7) = 0x80;
  bVar1 = FUN_003cd2ec(*param_1);
  *(byte *)(param_2 + 7) = bVar1 | *(byte *)(param_2 + 7);
  return;
}

