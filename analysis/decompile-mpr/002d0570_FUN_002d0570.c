// FUN_002d0570
// Ghidra address: 002d0570

int FUN_002d0570(undefined8 *param_1,int param_2,int param_3,long *param_4)

{
  int iVar1;
  long lVar2;
  undefined4 local_78;
  undefined8 local_70;
  
  if ((param_1 == (undefined8 *)0x0 || param_2 == 0) || (param_3 == 0 || param_4 == (long *)0x0)) {
    iVar1 = 1;
  }
  else {
    lVar2 = 0;
    iVar1 = FUN_002cedb8();
    if (iVar1 != 0) goto LAB_002d0608;
    iVar1 = 0x100;
    lVar2 = FUN_002dd104(*param_1,1,0x20);
    if ((lVar2 == 0) ||
       (iVar1 = FUN_002f594c(*param_1,param_1[1],local_70,local_78,lVar2), iVar1 != 0))
    goto LAB_002d0608;
    *param_4 = lVar2;
  }
  lVar2 = 0;
LAB_002d0608:
  FUN_002d0548(param_1,lVar2);
  return iVar1;
}

