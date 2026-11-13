// Normalized static image, not an observed export trace.
// Preferred VA 1801b8ca0
// Disassembly returned true; body bytes 205

int loaded_1801b8ca0(longlong *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  code *pcVar1;
  int iVar2;
  undefined8 uVar3;
  longlong *plVar4;
  longlong *plStackX_18;
  longlong *plStackX_20;
  
  plStackX_18 = (longlong *)0x0;
  iVar2 = FUN_1801b8d90(param_2,&plStackX_18);
  plVar4 = plStackX_18;
  if (-1 < iVar2) {
    pcVar1 = *(code **)(*param_1 + 8);
    uVar3 = FUN_1801b8340(&plStackX_20,&plStackX_18,param_3,param_4,iVar2,&plStackX_20);
    iVar2 = (*pcVar1)(param_1,uVar3);
    plVar4 = plStackX_18;
    if (((-1 < iVar2) && ((int)param_1[2] != 0)) && ((longlong *)param_1[3] != plStackX_18)) {
      plStackX_20 = plStackX_18;
      if (plStackX_18 != (longlong *)0x0) {
        (**(code **)(*plStackX_18 + 8))(plStackX_18);
      }
      plStackX_20 = (longlong *)param_1[3];
      param_1[3] = (longlong)plVar4;
      if (plStackX_20 != (longlong *)0x0) {
        (**(code **)(*plStackX_20 + 0x10))();
      }
    }
  }
  if (plVar4 != (longlong *)0x0) {
    (**(code **)(*plVar4 + 0x10))(plVar4);
  }
  return iVar2;
}

