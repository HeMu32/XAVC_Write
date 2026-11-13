// Normalized static image, not an observed export trace.
// Preferred VA 18043c630
// Disassembly returned true; body bytes 405

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void loaded_18043c630(longlong *param_1,char param_2)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  undefined2 *puVar4;
  undefined1 auStack_78 [32];
  undefined8 uStack_58;
  undefined2 *puStack_48;
  longlong lStack_40;
  undefined2 uStack_30;
  undefined6 uStack_2e;
  undefined8 uStack_20;
  ulonglong uStack_18;
  ulonglong uStack_10;
  
  uStack_10 = _DAT_18092d280 ^ (ulonglong)auStack_78;
  puStack_48 = (undefined2 *)*param_1;
  lStack_40 = param_1[1];
  FUN_180439a70(&uStack_30,&puStack_48);
  puVar4 = &uStack_30;
  if (7 < uStack_18) {
    puVar4 = (undefined2 *)CONCAT62(uStack_2e,uStack_30);
  }
  iVar2 = FUN_1804a9f30(puVar4);
  if (iVar2 < 0) {
    uVar3 = GetLastError();
    if (0 < (int)uVar3) {
      uVar3 = uVar3 & 0xffff | 0x80070000;
    }
    if (((((iVar2 == -0x7ff8fffb) || (uVar3 == 0x80070005)) || (iVar2 == -0x7ff8e887)) ||
        (uVar3 == 0x80071779)) && (param_2 != '\0')) {
      puStack_48 = &uStack_30;
      if (7 < uStack_18) {
        puStack_48 = (undefined2 *)CONCAT62(uStack_2e,uStack_30);
      }
      lStack_40 = func_0x000180591eea();
      uVar3 = FUN_18043dcc0(&puStack_48);
      if ((uVar3 != 0xffffffff) && ((uVar3 & 1) != 0)) {
        puStack_48 = &uStack_30;
        if (7 < uStack_18) {
          puStack_48 = (undefined2 *)CONCAT62(uStack_2e,uStack_30);
        }
        lStack_40 = func_0x000180591eea();
        iVar2 = FUN_180440870(&puStack_48,uVar3 & 0xfffffffe);
        if (-1 < iVar2) {
          puVar4 = &uStack_30;
          if (7 < uStack_18) {
            puVar4 = (undefined2 *)CONCAT62(uStack_2e,uStack_30);
          }
          FUN_1804a9f30(puVar4);
        }
      }
    }
  }
  if (7 < uStack_18) {
    if (0xfff < uStack_18 * 2 + 2) {
      if (0x1f < (CONCAT62(uStack_2e,uStack_30) - *(longlong *)(CONCAT62(uStack_2e,uStack_30) + -8))
                 - 8U) {
        uStack_58 = 0;
        _invoke_watson(0,0,0,0);
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
    }
    func_0x00018058eb90();
  }
  uStack_20 = _DAT_1806f4460;
  uStack_18 = _UNK_1806f4468;
  uStack_30 = 0;
  FUN_18058f0f0(uStack_10 ^ (ulonglong)auStack_78);
  return;
}

