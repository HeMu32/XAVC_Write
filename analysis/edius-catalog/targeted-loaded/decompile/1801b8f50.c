// Normalized static image, not an observed export trace.
// Preferred VA 1801b8f50
// Disassembly returned true; body bytes 642

ulonglong loaded_1801b8f50(longlong *param_1,undefined4 *param_2)

{
  longlong ****pppplVar1;
  code *pcVar2;
  longlong ***ppplVar3;
  int iVar4;
  uint uVar5;
  longlong *plVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  ulonglong uVar9;
  longlong ****pppplVar10;
  longlong ***ppplStackX_18;
  longlong *plStackX_20;
  longlong ***ppplStack_58;
  longlong ***ppplStack_50;
  longlong ***appplStack_48 [2];
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined8 uStack_28;
  
  pppplVar10 = (longlong ****)0x0;
  if (param_1[3] == 0) {
    plVar6 = (longlong *)FUN_180187ab0(appplStack_48,&UNK_1806f8320,0,0x17);
    pppplVar1 = (longlong ****)*plVar6;
    if (pppplVar1 != (longlong ****)0x0) {
      *plVar6 = 0;
      pppplVar10 = pppplVar1;
    }
    if ((longlong ****)appplStack_48[0] != (longlong ****)0x0) {
      (*(code *)(*appplStack_48[0])[2])();
    }
    if (pppplVar10 == (longlong ****)0x0) {
      func_0x000180591c10(0x80004003);
      goto LAB_1801b91cb;
    }
    iVar4 = (*(code *)(*pppplVar10)[0x48])(pppplVar10,0xffffffff);
    if (iVar4 < 0) {
      FUN_180591c20(iVar4,pppplVar10,&UNK_1806f7268);
    }
    iVar4 = (*(code *)(*pppplVar10)[0x3f])(pppplVar10,0xffffffff);
    if (iVar4 < 0) {
      FUN_180591c20(iVar4,pppplVar10,&UNK_1806f7268);
    }
    ppplStack_50 = (longlong ***)&ppplStackX_18;
    uVar7 = (**(code **)(*param_1 + 0x20))(param_1);
    uVar7 = FUN_180189f90(&ppplStackX_18,uVar7);
    ppplStack_58 = (longlong ***)appplStack_48;
    uVar8 = FUN_180189f90(appplStack_48,&UNK_1806f8330);
    FUN_18019cc40(pppplVar10,&plStackX_20,uVar8,uVar7);
    if ((plStackX_20 != (longlong *)0x0) &&
       (FUN_180193490(pppplVar10,&ppplStackX_18), (longlong ****)ppplStackX_18 != (longlong ****)0x0
       )) {
      (*(code *)(*ppplStackX_18)[2])();
    }
    pcVar2 = *(code **)(*param_1 + 0x10);
    appplStack_48[0] = (longlong ***)&ppplStackX_18;
    ppplStackX_18 = (longlong ***)pppplVar10;
    (*(code *)(*pppplVar10)[1])(pppplVar10);
    uVar5 = (*pcVar2)(param_1,&ppplStackX_18);
    uVar9 = (ulonglong)uVar5;
    if (plStackX_20 != (longlong *)0x0) {
      (**(code **)(*plStackX_20 + 0x10))();
    }
  }
  else {
    FUN_1801b8340(&ppplStack_58);
    ppplVar3 = ppplStack_58;
    if ((longlong ****)ppplStack_58 != (longlong ****)0x0) {
      ppplStack_58 = (longlong ***)0x0;
      pppplVar10 = (longlong ****)ppplVar3;
    }
    if ((longlong ****)ppplStack_58 != (longlong ****)0x0) {
      (*(code *)(*ppplStack_58)[2])();
    }
    pcVar2 = *(code **)(*param_1 + 0x18);
    ppplStackX_18 = (longlong ***)&ppplStack_50;
    ppplStack_50 = (longlong ***)pppplVar10;
    if (pppplVar10 != (longlong ****)0x0) {
      (*(code *)(*pppplVar10)[1])(pppplVar10);
    }
    uVar5 = (*pcVar2)(param_1,&ppplStack_50);
    uVar9 = (ulonglong)uVar5;
  }
  if (-1 < (int)uVar9) {
    if (pppplVar10 == (longlong ****)0x0) {
LAB_1801b91cb:
      func_0x000180591c10(0x80004003);
      pcVar2 = (code *)swi(3);
      uVar9 = (*pcVar2)();
      return uVar9;
    }
    uStack_38 = *param_2;
    uStack_34 = param_2[1];
    uStack_30 = param_2[2];
    uStack_2c = param_2[3];
    uStack_28 = *(undefined8 *)(param_2 + 4);
    uVar5 = (*(code *)(*pppplVar10)[0x42])(pppplVar10,&uStack_38);
    uVar9 = (ulonglong)uVar5;
    if ((int)uVar5 < 0) {
      FUN_180591c20(uVar5,pppplVar10,&UNK_1806f7268);
    }
  }
  if (pppplVar10 != (longlong ****)0x0) {
    (*(code *)(*pppplVar10)[2])(pppplVar10);
  }
  return uVar9;
}

