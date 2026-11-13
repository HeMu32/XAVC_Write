// FUN_003cd0b4
// Ghidra address: 003cd0b4

void FUN_003cd0b4(long param_1,uint param_2)

{
  long lVar1;
  ulong uVar2;
  
  for (uVar2 = 0; uVar2 != param_2; uVar2 = uVar2 + 1) {
    lVar1 = random();
    *(char *)(param_1 + uVar2) = (char)((int)lVar1 >> 4);
  }
  return;
}

