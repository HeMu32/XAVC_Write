// FUN_1800204b0
// VA 1800204b0

undefined8 FUN_1800204b0(longlong param_1,int param_2,int *param_3)

{
  int *piVar1;
  int iVar2;
  longlong *plVar3;
  undefined8 uVar4;
  longlong lVar5;
  
  piVar1 = (int *)(param_1 + 600);
  *piVar1 = 0;
  *(undefined4 *)(param_1 + 0x2c0) = 0;
  *(undefined4 *)(param_1 + 0x2d8) = 0;
  if (param_2 == 0) {
    if (*(int *)(param_1 + 0x5c) == 4) {
      FUN_180020790(param_1);
    }
    for (; param_3 != (int *)0x0; param_3 = *(int **)(param_3 + 2)) {
      iVar2 = *param_3;
      if (iVar2 == 3) {
        FUN_18002b5f0(param_1,(longlong)param_3);
        *piVar1 = 1;
      }
      else if (iVar2 == 4) {
        FUN_18002af30(param_1,(longlong)param_3);
        *piVar1 = 1;
      }
      else if (iVar2 == 7) {
        FUN_18002aba0(param_1,(longlong)param_3);
        *piVar1 = 1;
      }
      else if (iVar2 == 9) {
        FUN_18002ad40(param_1,(longlong)param_3);
        *piVar1 = 1;
      }
      else if (iVar2 == 5) {
        FUN_18002a7b0(param_1,(longlong)param_3);
        *piVar1 = 1;
      }
      else if (iVar2 == 6) {
        FUN_18002a550(param_1,(longlong)param_3);
        *piVar1 = 1;
      }
      else if (iVar2 == 8) {
        FUN_18002b090(param_1,(longlong)param_3);
        *piVar1 = 1;
      }
      else if (iVar2 == 10) {
        FUN_18002a9d0(param_1,(longlong)param_3);
        *(undefined4 *)(param_1 + 0x2c0) = 1;
      }
      else if ((iVar2 == 0xb) && (uVar4 = FUN_18002b1c0(param_1,(longlong)param_3), (int)uVar4 == 0)
              ) {
        *(undefined4 *)(param_1 + 0x2d8) = 1;
      }
    }
    FUN_18002f650(param_1);
    if ((*piVar1 != 0) || (*(int *)(param_1 + 0x260) != 0)) {
      *(uint *)(param_1 + 0x68) = *(uint *)(param_1 + 0x68) | 1;
    }
  }
  for (lVar5 = *(longlong *)(param_1 + 0x1e8); lVar5 != *(longlong *)(param_1 + 0x1f0);
      lVar5 = lVar5 + 0x10) {
    (**(code **)(**(longlong **)(lVar5 + 8) + 0x10))(*(longlong **)(lVar5 + 8),param_2);
  }
  plVar3 = *(longlong **)(param_1 + 0x270);
  if ((plVar3 != (longlong *)0x0) && ((longlong)plVar3 / 0x68 != 0)) {
    (**(code **)(*plVar3 + 0x18))
              (plVar3,CONCAT71((int7)((ulonglong)((longlong)plVar3 / 0x68) >> 8),param_2 == 0));
    (**(code **)(*(longlong *)(param_1 + 0x268) + 0x18))((longlong *)(param_1 + 0x268),0);
  }
  for (lVar5 = *(longlong *)(param_1 + 0x1e8); lVar5 != *(longlong *)(param_1 + 0x1f0);
      lVar5 = lVar5 + 0x10) {
    (**(code **)(**(longlong **)(lVar5 + 8) + 0x18))(*(longlong **)(lVar5 + 8),param_2);
  }
  return 0;
}

