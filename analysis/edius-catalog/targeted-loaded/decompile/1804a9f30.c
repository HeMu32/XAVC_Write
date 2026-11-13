// Normalized static image, not an observed export trace.
// Preferred VA 1804a9f30
// Disassembly returned true; body bytes 373

uint loaded_1804a9f30(longlong param_1)

{
  int *piVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong lVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  longlong lStackX_8;
  longlong lStack_38;
  undefined8 uStack_30;
  longlong lStack_28;
  longlong *plStack_20;
  undefined8 uStack_18;
  longlong *plStack_10;
  
  if (param_1 != 0) {
    uStack_18 = 0;
    plStack_10 = (longlong *)0x0;
    uStack_30 = func_0x000180591eea();
    lStack_38 = param_1;
    FUN_1804a90c0(&lStack_28,&lStack_38,&uStack_18);
    if (lStack_28 == 0) {
      iVar5 = DeleteFileW(param_1);
      uVar6 = 0;
      if (iVar5 == 0) {
        uVar6 = GetLastError();
        if (0 < (int)uVar6) {
          uVar6 = uVar6 & 0xffff | 0x80070000;
        }
        if (-1 < (int)uVar6) {
          uVar6 = 0x80004005;
        }
      }
    }
    else {
      plVar3 = *(longlong **)(lStack_28 + 0x5f8);
      if (plVar3 == (longlong *)0x0) {
        SetLastError(0x32);
        uVar6 = 0x80070032;
      }
      else {
        lStackX_8 = param_1;
        uVar6 = (**(code **)(*plVar3 + 0x10))(plVar3,&lStackX_8);
        if (((int)uVar6 < 0) && (iVar5 = GetLastError(), iVar5 == 0)) {
          uVar7 = uVar6 & 0xffff;
          if ((uVar6 & 0xffff0000) != 0x80070000) {
            uVar7 = 1;
          }
          SetLastError(uVar7);
        }
      }
    }
    if (plStack_20 != (longlong *)0x0) {
      LOCK();
      plVar3 = plStack_20 + 1;
      lVar4 = *plVar3;
      *(int *)plVar3 = (int)*plVar3 + -1;
      UNLOCK();
      if ((int)lVar4 == 1) {
        (**(code **)*plStack_20)(plStack_20);
        LOCK();
        piVar1 = (int *)((longlong)plStack_20 + 0xc);
        iVar5 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
        if (iVar5 == 1) {
          (**(code **)(*plStack_20 + 8))(plStack_20);
        }
      }
    }
    plVar3 = plStack_10;
    if (plStack_10 != (longlong *)0x0) {
      LOCK();
      plVar2 = plStack_10 + 1;
      lVar4 = *plVar2;
      *(int *)plVar2 = (int)*plVar2 + -1;
      UNLOCK();
      if ((int)lVar4 == 1) {
        (**(code **)*plStack_10)(plStack_10);
        LOCK();
        piVar1 = (int *)((longlong)plVar3 + 0xc);
        iVar5 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
        if (iVar5 == 1) {
          (**(code **)(*plVar3 + 8))(plVar3);
        }
      }
    }
    return uVar6;
  }
  SetLastError(0x57);
  return 0x80070057;
}

