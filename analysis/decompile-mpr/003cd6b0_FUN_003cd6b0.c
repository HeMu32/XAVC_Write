// FUN_003cd6b0
// Ghidra address: 003cd6b0

undefined8 FUN_003cd6b0(long param_1,undefined2 *param_2)

{
  *param_2 = *(undefined2 *)(param_1 + 0xd);
  *(undefined1 *)(param_2 + 1) = *(undefined1 *)(param_1 + 0xf);
  return 0;
}

