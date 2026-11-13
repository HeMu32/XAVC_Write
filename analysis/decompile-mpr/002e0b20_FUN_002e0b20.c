// FUN_002e0b20
// Ghidra address: 002e0b20

int FUN_002e0b20(long param_1,long param_2,long param_3,int param_4,uint param_5,long param_6,
                long *param_7)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  long lVar4;
  uint *local_8;
  
  iVar1 = 1;
  local_8 = (uint *)0x0;
  if ((((param_1 != 0 && param_2 != 0) && (iVar1 = 1, param_3 != 0 && param_4 != 0)) &&
      ((param_5 != 0 && param_6 != 0) && param_7 != (long *)0x0)) &&
     (iVar1 = 0x1000, *(long *)(param_3 + 0x100) != 0)) {
    iVar1 = 0x200;
    if ((*(uint *)(param_3 + 0x118) != 0) &&
       (iVar1 = 0x1000, (param_5 - 1) + param_4 <= *(uint *)(param_3 + 0x118))) {
      lVar4 = (ulong)*(uint *)(param_3 + 0x110) * (ulong)param_5;
      if (*(uint *)(param_3 + 0x110) == 0) {
        if (*(int *)(param_3 + 0xf8) == 0x7374737a) {
          iVar1 = FUN_002e093c();
        }
        else {
          iVar1 = FUN_002e1b9c();
        }
        if (iVar1 == 0) {
          lVar4 = 0;
          uVar3 = 0;
          do {
            iVar1 = FUN_002dea1c(param_6 + 0x140,uVar3 + param_4,&local_8);
            if (iVar1 != 0) {
              return iVar1;
            }
            puVar2 = local_8;
            if (local_8 == (uint *)0x0) {
              return 0x10000000;
            }
            while( true ) {
              if (param_5 <= uVar3) goto LAB_002e0ca0;
              if (*(uint *)(param_6 + 0x16c) <= uVar3 + param_4) break;
              uVar3 = uVar3 + 1;
              lVar4 = lVar4 + (ulong)*puVar2;
              puVar2 = puVar2 + 1;
            }
            if (*(int *)(param_3 + 0xf8) == 0x7374737a) {
              iVar1 = FUN_002e080c();
            }
            else {
              iVar1 = FUN_002e1994(param_1,param_2,param_3,uVar3 + param_4,5,param_6 + 0x140);
            }
          } while (iVar1 == 0);
        }
      }
      else {
LAB_002e0ca0:
        iVar1 = 0;
        *param_7 = lVar4;
      }
    }
  }
  return iVar1;
}

