// FUN_8078a0c4
// Ghidra address: 8078a0c4

int FUN_8078a0c4(undefined4 param_1)

{
  int local_20 [4];
  
  local_20[0] = 0;
  DAT_807c0a58 = FUN_80786714(local_20);
  if (local_20[0] == 0) {
    DAT_807c0a5c = DAT_807c0a58 + 0x1c;
    FUN_8078a234(param_1);
  }
  return local_20[0];
}

