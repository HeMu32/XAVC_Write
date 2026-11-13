// FUN_00287158
// Ghidra address: 00287158

int FUN_00287158(long *param_1,undefined8 param_2)

{
  long *plVar1;
  int iVar2;
  int iVar3;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  undefined8 uStack_18;
  undefined8 local_10;
  undefined4 local_8;
  undefined2 local_4;
  undefined1 local_2;
  
  iVar2 = 0x68;
  if ((int)param_1[0x15f8c] != 9999) {
    plVar1 = param_1 + 89999;
    FUN_0028643c(plVar1);
    iVar2 = (**(code **)(*param_1 + 0x460))(param_1,param_2,plVar1);
    if (iVar2 == 0) {
      iVar2 = (**(code **)(*(long *)param_1[1] + 0x40))
                        ((long *)param_1[1],plVar1,(int)param_1[0x15f8c],1);
      if (iVar2 == 0) {
        (**(code **)(*param_1 + 0xa8))(param_1);
        FUN_00286fc0(param_1,(int)param_1[0x15f8c]);
        (**(code **)(*param_1 + 0x1f0))(param_1,plVar1,1);
        (**(code **)(*param_1 + 0x2e8))(param_1);
        (**(code **)(*param_1 + 0x2f8))(param_1);
        if (*(char *)((long)param_1 + 0xafc74) == '\0') {
          local_40 = 0;
          uStack_38 = 0;
          local_30 = 0;
          uStack_28 = 0;
          local_20 = 0;
          uStack_18 = 0;
          local_4 = 0;
          local_2 = 0;
          local_10 = 0;
          local_8 = 0;
          (**(code **)(*param_1 + 0x118))(param_1,&local_40);
          iVar3 = (**(code **)(*(long *)param_1[1] + 0x50))((long *)param_1[1],&local_40);
          if (iVar3 == 0) {
            *(undefined1 *)((long)param_1 + 0xafc74) = 1;
          }
        }
      }
    }
  }
  return iVar2;
}

