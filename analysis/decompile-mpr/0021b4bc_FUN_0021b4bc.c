// FUN_0021b4bc
// Ghidra address: 0021b4bc

void FUN_0021b4bc(long param_1)

{
  void *pvVar1;
  undefined2 local_18;
  undefined2 local_16;
  undefined1 local_14;
  undefined1 local_13;
  undefined1 local_12;
  undefined1 local_11;
  undefined4 local_10;
  undefined1 local_c;
  undefined1 local_b;
  undefined1 local_a;
  undefined1 local_9;
  undefined8 local_8;
  
  local_c = 4;
  local_10 = 0x2802310;
  local_b = 0;
  local_a = 0;
  local_9 = 0;
  FUN_0021777c(&local_10,8);
  mpr::BaseList::Clear(*(BaseList **)(param_1 + 0x110));
  mpr::BaseList::Clear(*(BaseList **)(param_1 + 0x118));
  mpr::BaseList::Clear(*(BaseList **)(param_1 + 0x120));
  *(undefined8 *)(param_1 + 0x988) = 0;
  *(undefined8 *)(param_1 + 0x990) = 0;
  local_10 = 0x58415643;
  local_8 = 0xa00000;
  pvVar1 = operator_new(800);
  FUN_00322994(pvVar1,&local_10);
  *(void **)(param_1 + 0x108) = pvVar1;
  memset((void *)(param_1 + 0x9d0),0,0x106);
  memset((void *)(param_1 + 0xad6),0,0x106);
  memset((void *)(param_1 + 0x130),0xff,0x100);
  memset((void *)(param_1 + 0x230),0xff,0x100);
  memset((void *)(param_1 + 0x330),0xff,0x100);
  *(undefined8 *)(param_1 + 0xbdc) = 0;
  *(undefined8 *)(param_1 + 0xbe4) = 0;
  *(undefined8 *)(param_1 + 0xbec) = 0;
  *(undefined8 *)(param_1 + 0xbf4) = 0;
  *(undefined8 *)(param_1 + 0xbfc) = 0;
  FUN_0021b474(param_1 + 0xc08);
  *(undefined1 *)(param_1 + 0xcd8) = 0;
  *(undefined4 *)(param_1 + 0xc04) = 0;
  memset((void *)(param_1 + 0xcd9),0,8000);
  *(undefined4 *)(param_1 + 0x2c1c) = 0;
  local_14 = 4;
  local_16 = 0x288;
  local_18 = 0x2310;
  local_13 = 0;
  local_12 = 0;
  local_11 = 0;
  FUN_0021777c(&local_18,8);
  return;
}

