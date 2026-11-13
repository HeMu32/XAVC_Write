// FUN_00284aa8
// Ghidra address: 00284aa8

undefined8 FUN_00284aa8(long *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  long *plVar2;
  undefined8 uVar3;
  code *pcVar4;
  
  (**(code **)(*param_1 + 0x490))();
  plVar2 = (long *)param_1[1];
  if (plVar2 == (long *)0x0) {
    return 100;
  }
  iVar1 = (**(code **)(*plVar2 + 0x10))(plVar2,param_2,param_4,(int)param_1[0x180cf]);
  if (iVar1 == 0) {
    plVar2 = operator_new(0x10);
    param_1[2] = (long)plVar2;
    *plVar2 = (long)(PTR_DAT_004029b8 + 0x10);
    plVar2[1] = (long)param_1;
    iVar1 = (**(code **)(*param_1 + 0x3d0))(param_1);
    if (iVar1 != 0) {
      pcVar4 = *(code **)(*param_1 + 0x1c0);
      goto LAB_00284b3c;
    }
    uVar3 = (**(code **)(*param_1 + 0x400))(param_1);
    if ((int)uVar3 == 0) {
      return uVar3;
    }
  }
  pcVar4 = *(code **)(*param_1 + 0x1c0);
LAB_00284b3c:
  (*pcVar4)(param_1);
  return 100;
}

