// FUN_003cd59c
// Ghidra address: 003cd59c

undefined8 FUN_003cd59c(long param_1,uint param_2,long param_3,uint param_4)

{
  ulong uVar1;
  
  if (param_4 * 2 + 1 <= param_2) {
    for (uVar1 = 0; uVar1 != param_4; uVar1 = uVar1 + 1) {
      snprintf((char *)(param_1 + (uVar1 & 0x7fffffff) * 2),3,"%02X",
               (ulong)*(byte *)(param_3 + uVar1));
    }
    return 0;
  }
  return 3;
}

