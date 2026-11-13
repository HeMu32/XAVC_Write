// Normalized static image, not an observed export trace.
// Preferred VA 18023bf00
// Disassembly returned true; body bytes 544

void loaded_18023bf00(longlong param_1)

{
  ulonglong uVar1;
  code *pcVar2;
  int iVar3;
  undefined1 *puVar4;
  ulonglong uVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  ulonglong uVar8;
  longlong lVar9;
  undefined1 *puStack_68;
  undefined1 *puStack_60;
  undefined1 *puStack_58;
  undefined1 **ppuStack_50;
  undefined1 *puStack_48;
  ulonglong uStack_40;
  undefined1 *puStack_38;
  undefined1 *puStack_30;
  
  if (*(longlong *)(param_1 + 0x158) != 0) {
    puStack_68 = (undefined1 *)0x0;
    puStack_60 = (undefined1 *)0x0;
    puStack_58 = (undefined1 *)0x0;
    iVar3 = FUN_180237b80(0,&puStack_68);
    puVar7 = puStack_60;
    if (-1 < iVar3) {
      if (puStack_68 != puStack_60) {
        if (puStack_60 == puStack_58) {
          lVar9 = (longlong)puStack_60 - (longlong)puStack_68;
          if (lVar9 == 0x7fffffffffffffff) {
            FUN_18017e520();
            pcVar2 = (code *)swi(3);
            (*pcVar2)();
            return;
          }
          uVar1 = lVar9 + 1;
          uVar5 = (longlong)puStack_58 - (longlong)puStack_68;
          uVar8 = 0x7fffffffffffffff;
          if ((uVar5 <= 0x7fffffffffffffff - (uVar5 >> 1)) &&
             (uVar8 = (uVar5 >> 1) + uVar5, uVar8 < uVar1)) {
            uVar8 = uVar1;
          }
          puVar4 = (undefined1 *)FUN_18017cf80(uVar8);
          puStack_38 = puVar4 + lVar9;
          puVar6 = puStack_38 + 1;
          ppuStack_50 = &puStack_68;
          *puStack_38 = 0;
          uStack_40 = uVar8;
          puStack_30 = puVar6;
          if (puVar7 == puStack_60) {
            lVar9 = (longlong)puStack_60 - (longlong)puStack_68;
            puVar6 = puVar4;
            puVar7 = puStack_68;
            puStack_48 = puVar4;
          }
          else {
            puStack_48 = puVar4;
            func_0x000180591e90(puVar4,puStack_68,(longlong)puVar7 - (longlong)puStack_68);
            lVar9 = (longlong)puStack_60 - (longlong)puVar7;
            puStack_38 = puVar4;
          }
          func_0x000180591e90(puVar6,puVar7,lVar9);
          puStack_48 = (undefined1 *)0x0;
          if (puStack_68 != (undefined1 *)0x0) {
            if (0xfff < (ulonglong)((longlong)puStack_58 - (longlong)puStack_68)) {
              if ((undefined1 *)0x1f < puStack_68 + (-8 - *(longlong *)(puStack_68 + -8))) {
                _invoke_watson(0,0,0,0,0);
                pcVar2 = (code *)swi(3);
                (*pcVar2)();
                return;
              }
            }
            func_0x00018058eb90();
          }
          puStack_60 = puVar4 + uVar1;
          puStack_58 = puVar4 + uVar8;
          puStack_68 = puVar4;
        }
        else {
          *puStack_60 = 0;
          puStack_60 = puStack_60 + 1;
        }
        iVar3 = func_0x0001803dc570(*(undefined8 *)(param_1 + 0x158),puStack_68,
                                    (longlong)puStack_60 - (longlong)puStack_68);
      }
    }
    *(int *)(param_1 + 0x248) = iVar3;
    if (puStack_68 != (undefined1 *)0x0) {
      if (0xfff < (ulonglong)((longlong)puStack_58 - (longlong)puStack_68)) {
        if ((undefined1 *)0x1f < puStack_68 + (-8 - *(longlong *)(puStack_68 + -8))) {
          _invoke_watson(0,0,0,0,0);
          pcVar2 = (code *)swi(3);
          (*pcVar2)();
          return;
        }
      }
      func_0x00018058eb90();
    }
  }
  return;
}

