// FUN_003430e0
// Ghidra address: 003430e0

void FUN_003430e0(long *param_1)

{
  void *pvVar1;
  long *plVar2;
  
  param_1[2] = 0;
  *param_1 = (long)(PTR_DAT_004025c8 + 0x10);
  param_1[1] = 0;
  pvVar1 = operator_new(0x20);
  FUN_003376d0();
  param_1[1] = (long)pvVar1;
  pvVar1 = operator_new(0x20);
  FUN_0033a134(pvVar1,param_1,param_1[1]);
  param_1[3] = (long)pvVar1;
  pvVar1 = operator_new(0x18);
  FUN_0033a050(pvVar1,param_1,param_1[1]);
  param_1[4] = (long)pvVar1;
  pvVar1 = operator_new(0x18);
  FUN_00343b18(pvVar1,param_1,param_1[1]);
  param_1[5] = (long)pvVar1;
  pvVar1 = operator_new(0x18);
  FUN_0032c2b8(pvVar1,param_1,param_1[1]);
  param_1[6] = (long)pvVar1;
  pvVar1 = operator_new(0x18);
  FUN_0033b290(pvVar1,param_1,param_1[1]);
  param_1[7] = (long)pvVar1;
  pvVar1 = operator_new(0x18);
  FUN_00343dc0(pvVar1,param_1,param_1[1]);
  param_1[8] = (long)pvVar1;
  plVar2 = param_1 + 3;
  do {
    if (*plVar2 == 0) {
      return;
    }
    plVar2 = plVar2 + 1;
  } while (plVar2 != param_1 + 9);
  param_1[2] = param_1[3];
  return;
}

