// Normalized static image, not an observed export trace.
// Preferred VA 1801b86f0
// Disassembly returned true; body bytes 166

int loaded_1801b86f0(undefined8 param_1,undefined *param_2)

{
  int iVar1;
  longlong *aplStackX_10 [3];
  undefined *puStack_28;
  longlong *plStack_20;
  
  plStack_20 = (longlong *)0x0;
  aplStackX_10[0] = (longlong *)0x0;
  if (param_2 == (undefined *)0x0) {
    param_2 = &UNK_1806f41e8;
  }
  else {
    plStack_20 = (longlong *)func_0x000180591eea(param_2);
  }
  puStack_28 = param_2;
  iVar1 = FUN_180440750(&puStack_28,0,aplStackX_10);
  if (-1 < iVar1) {
    puStack_28 = (undefined *)CONCAT62(puStack_28._2_6_,0xd);
    plStack_20 = aplStackX_10[0];
    if (aplStackX_10[0] != (longlong *)0x0) {
      (**(code **)(*aplStackX_10[0] + 8))();
    }
    iVar1 = FUN_1801b8ca0(param_1,&puStack_28);
    VariantClear(&puStack_28);
  }
  if (aplStackX_10[0] != (longlong *)0x0) {
    (**(code **)(*aplStackX_10[0] + 0x10))();
  }
  return iVar1;
}

