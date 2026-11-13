// Normalized static image, not an observed export trace.
// Preferred VA 18043f520
// Disassembly returned true; body bytes 484

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void loaded_18043f520(undefined8 *param_1)

{
  code *pcVar1;
  int iVar2;
  undefined1 auStack_a8 [32];
  undefined8 uStack_88;
  undefined4 uStack_78;
  undefined2 *puStack_70;
  undefined8 uStack_68;
  undefined8 uStack_60;
  longlong lStack_58;
  undefined2 uStack_50;
  undefined6 uStack_4e;
  undefined8 uStack_40;
  ulonglong uStack_38;
  undefined2 uStack_30;
  undefined6 uStack_2e;
  undefined8 uStack_20;
  ulonglong uStack_18;
  ulonglong uStack_10;
  
  uStack_10 = _DAT_18092d280 ^ (ulonglong)auStack_a8;
  uStack_78 = 0;
  if (param_1[1] != 0) {
    uStack_60 = *param_1;
    lStack_58 = param_1[1];
    FUN_180439a70(&uStack_50,&uStack_60);
    puStack_70 = &uStack_50;
    if (7 < uStack_38) {
      puStack_70 = (undefined2 *)CONCAT62(uStack_4e,uStack_50);
    }
    uStack_68 = uStack_40;
    FUN_1804362a0(&uStack_30,&puStack_70);
    uStack_78 = 2;
    FUN_18017e240(&uStack_50,&uStack_30);
    uStack_78 = 0;
    if (7 < uStack_18) {
      if ((0xfff < uStack_18 * 2 + 2) &&
         (0x1f < (CONCAT62(uStack_2e,uStack_30) - *(longlong *)(CONCAT62(uStack_2e,uStack_30) + -8))
                 - 8U)) {
        uStack_88 = 0;
        _invoke_watson(0,0,0,0);
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      func_0x00018058eb90();
    }
    uStack_20 = _DAT_1806f4460;
    uStack_18 = _UNK_1806f4468;
    uStack_30 = 0;
    puStack_70 = &uStack_50;
    if (7 < uStack_38) {
      puStack_70 = (undefined2 *)CONCAT62(uStack_4e,uStack_50);
    }
    uStack_68 = uStack_40;
    iVar2 = FUN_1804ab350(&puStack_70);
    if (iVar2 == -0x7fffbfff) {
      puStack_70 = &uStack_50;
      if (7 < uStack_38) {
        puStack_70 = (undefined2 *)CONCAT62(uStack_4e,uStack_50);
      }
      uStack_68 = uStack_40;
      FUN_18043dcc0(&puStack_70);
    }
    if (7 < uStack_38) {
      if ((0xfff < uStack_38 * 2 + 2) &&
         (0x1f < (CONCAT62(uStack_4e,uStack_50) - *(longlong *)(CONCAT62(uStack_4e,uStack_50) + -8))
                 - 8U)) {
        uStack_88 = 0;
        _invoke_watson(0,0,0,0);
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      func_0x00018058eb90();
    }
    uStack_40 = 0;
    uStack_38 = 7;
    uStack_50 = 0;
  }
  FUN_18058f0f0(uStack_10 ^ (ulonglong)auStack_a8);
  return;
}

