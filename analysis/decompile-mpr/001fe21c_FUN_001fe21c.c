// FUN_001fe21c
// Ghidra address: 001fe21c

void FUN_001fe21c(long param_1,undefined4 param_2)

{
  long lVar1;
  long lVar2;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 local_c;
  undefined1 local_b;
  undefined1 local_a;
  undefined1 local_9;
  undefined4 local_8;
  
  if (param_1 == 0) {
    local_b = 0;
    local_c = 3;
    local_a = 0;
    local_10 = 0x2312;
    local_9 = 0;
    local_e = 0x60;
    local_8 = 0xff;
    FUN_001fdddc(&local_10,0xc);
  }
  else {
    lVar2 = param_1;
    do {
      lVar1 = lVar2 + 0x60;
      FUN_001fe0e8(lVar2,param_2);
      lVar2 = lVar1;
    } while (lVar1 != param_1 + 0x180);
  }
  return;
}

