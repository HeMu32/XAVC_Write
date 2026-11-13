// Normalized static image, not an observed export trace.
// Preferred VA 1801b89a0
// Disassembly returned true; body bytes 374

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void loaded_1801b89a0(undefined8 param_1,undefined *param_2)

{
  code *pcVar1;
  int iVar2;
  undefined1 auStack_a8 [32];
  undefined8 uStack_88;
  undefined4 uStack_78;
  longlong *plStack_70;
  undefined2 *puStack_68;
  longlong *plStack_60;
  undefined *puStack_50;
  undefined8 uStack_48;
  undefined2 uStack_40;
  undefined6 uStack_3e;
  longlong *plStack_30;
  ulonglong uStack_28;
  ulonglong uStack_20;
  
  uStack_20 = _DAT_18092d280 ^ (ulonglong)auStack_a8;
  uStack_48 = 0;
  uStack_78 = 0;
  plStack_70 = (longlong *)0x0;
  if (param_2 == (undefined *)0x0) {
    param_2 = &UNK_1806f41e8;
  }
  else {
    uStack_48 = func_0x000180591eea(param_2);
  }
  puStack_50 = param_2;
  FUN_180432640(&uStack_40,&puStack_50);
  uStack_78 = 1;
  puStack_68 = &uStack_40;
  if (7 < uStack_28) {
    puStack_68 = (undefined2 *)CONCAT62(uStack_3e,uStack_40);
  }
  plStack_60 = plStack_30;
  iVar2 = FUN_180440750(&puStack_68,0x1021,&plStack_70);
  uStack_78 = 0;
  if (7 < uStack_28) {
    if (0xfff < uStack_28 * 2 + 2) {
      if (0x1f < (CONCAT62(uStack_3e,uStack_40) - *(longlong *)(CONCAT62(uStack_3e,uStack_40) + -8))
                 - 8U) {
        uStack_88 = 0;
        _invoke_watson(0,0,0,0);
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
    }
    func_0x00018058eb90();
  }
  plStack_30 = (longlong *)_DAT_1806f4460;
  uStack_28 = _UNK_1806f4468;
  uStack_40 = 0;
  if (-1 < iVar2) {
    puStack_68 = (undefined2 *)CONCAT62(puStack_68._2_6_,0xd);
    plStack_60 = plStack_70;
    if (plStack_70 != (longlong *)0x0) {
      (**(code **)(*plStack_70 + 8))();
    }
    FUN_1801b8f50(param_1,&puStack_68);
    VariantClear(&puStack_68);
  }
  if (plStack_70 != (longlong *)0x0) {
    (**(code **)(*plStack_70 + 0x10))();
  }
  FUN_18058f0f0(uStack_20 ^ (ulonglong)auStack_a8);
  return;
}

