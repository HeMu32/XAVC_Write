// Normalized static image, not an observed export trace.
// Preferred VA 180440750
// Disassembly returned true; body bytes 279

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void loaded_180440750(ulonglong *param_1,undefined4 param_2,undefined8 param_3)

{
  code *pcVar1;
  ulonglong uVar2;
  undefined8 ****ppppuVar3;
  undefined1 auStack_78 [32];
  undefined8 uStack_58;
  undefined8 ***pppuStack_48;
  ulonglong uStack_40;
  undefined8 uStack_38;
  ulonglong uStack_30;
  ulonglong uStack_28;
  
  uStack_28 = _DAT_18092d280 ^ (ulonglong)auStack_78;
  pppuStack_48 = (undefined8 ***)*param_1;
  uStack_40 = param_1[1];
  uVar2 = FUN_180434d30(&pppuStack_48);
  if ((uVar2 & 5) == 0) {
    FUN_18043aaa0(param_1,param_2,param_3);
  }
  else {
    pppuStack_48 = (undefined8 ****)0x0;
    uStack_40 = 0;
    uStack_38 = 0;
    uStack_30 = 0;
    FUN_18017d6c0(&pppuStack_48,*param_1,param_1[1]);
    ppppuVar3 = &pppuStack_48;
    if (7 < uStack_30) {
      ppppuVar3 = (undefined8 ****)pppuStack_48;
    }
    SHCreateStreamOnFileW(ppppuVar3,param_2,param_3);
    if (7 < uStack_30) {
      ppppuVar3 = (undefined8 ****)pppuStack_48;
      if (0xfff < uStack_30 * 2 + 2) {
        ppppuVar3 = (undefined8 ****)pppuStack_48[-1];
        if (0x1f < (ulonglong)((longlong)pppuStack_48 + (-8 - (longlong)ppppuVar3))) {
          uStack_58 = 0;
          _invoke_watson(0,0,0,0);
          pcVar1 = (code *)swi(3);
          (*pcVar1)();
          return;
        }
      }
      func_0x00018058eb90(ppppuVar3);
    }
    uStack_38 = _DAT_1806f4460;
    uStack_30 = _UNK_1806f4468;
    pppuStack_48 = (undefined8 ***)((ulonglong)pppuStack_48 & 0xffffffffffff0000);
  }
  FUN_18058f0f0(uStack_28 ^ (ulonglong)auStack_78);
  return;
}

