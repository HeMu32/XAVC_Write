// FUN_00341e8c
// Ghidra address 00341e8c; ELF VMA = Ghidra - 0x100000

uint FUN_00341e8c(long param_1,undefined8 *param_2)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  void *pvVar4;
  undefined8 uVar5;
  long lVar6;
  char local_11;
  long local_10;
  undefined1 local_8;
  uint local_4;
  
  pvVar4 = operator_new__(0x40);
  local_8 = 0;
  local_10 = 0;
  local_4 = 8;
  do {
    uVar5 = FUN_00341e60(param_1);
    *param_2 = uVar5;
    uVar2 = FUN_00341c44(param_1,&local_10);
    if (uVar2 != 0) break;
    cVar1 = FUN_00341ba8(param_1,&local_10,&DAT_003dc0a8);
    if (cVar1 != '\0') {
      param_2[1] = local_10;
      uVar2 = Fsys_Seek(*(undefined8 *)(param_1 + 8),4,1,0);
      if (uVar2 == 0) goto LAB_00341f38;
      break;
    }
    uVar2 = Fsys_Seek(*(undefined8 *)(param_1 + 8),local_10 - (ulong)local_4,1,0);
  } while (uVar2 == 0);
  goto LAB_00341f84;
  while( true ) {
    cVar1 = FUN_00341ba8(param_1,&local_10,&DAT_003dc0ad);
    if (cVar1 != '\0') {
      if (((0x40 < local_10 - 8U) ||
          (iVar3 = Fsys_Read(*(undefined8 *)(param_1 + 8),pvVar4,(int)local_10 + -8),
          local_10 + -8 != (long)iVar3)) || (cVar1 = FUN_00341bd4(param_1,pvVar4), cVar1 == '\0'))
      goto LAB_00341f80;
      goto LAB_00341fe4;
    }
    uVar2 = Fsys_Seek(*(undefined8 *)(param_1 + 8),local_10 - (ulong)local_4,1,0);
    if (uVar2 != 0) break;
LAB_00341f38:
    uVar5 = FUN_00341e60(param_1);
    param_2[2] = uVar5;
    uVar2 = FUN_00341c44(param_1,&local_10);
    if (uVar2 != 0) break;
  }
  goto LAB_00341f84;
LAB_00341fe4:
  uVar5 = FUN_00341e60(param_1);
  param_2[3] = uVar5;
  uVar2 = FUN_00341c44(param_1,&local_10);
  if (uVar2 != 0) goto LAB_00341f84;
  cVar1 = FUN_00341ba8(param_1,&local_10,&DAT_003dc0b2);
  if (cVar1 != '\0') {
    cVar1 = FUN_00341ba8(param_1,&local_10,&DAT_003dc0b2);
    if (cVar1 == '\0') goto LAB_00341f80;
    param_2[4] = local_10;
    uVar2 = Fsys_Seek(*(undefined8 *)(param_1 + 8),4,1,0);
    if (uVar2 == 0) {
      lVar6 = local_10 + -0xc;
      if (lVar6 == 0) goto LAB_00342178;
      uVar2 = Fsys_Seek(*(undefined8 *)(param_1 + 8),local_10 + -0xd,1,0);
      if (uVar2 == 0) {
        goto LAB_00342120;
      }
    }
    goto LAB_00341f84;
  }
  uVar2 = Fsys_Seek(*(undefined8 *)(param_1 + 8),local_10 - (ulong)local_4,1,0);
  if (uVar2 != 0) goto LAB_00341f84;
  goto LAB_00341fe4;
LAB_00341f80:
  uVar2 = 1;
  goto LAB_00341f84;
  while( true ) {
    if (local_11 != '\0') {
      uVar2 = Fsys_Seek(*(undefined8 *)(param_1 + 8),-lVar6,1,0);
      if (uVar2 != 0) {
        lVar6 = 0;
      }
      break;
    }
    uVar5 = *(undefined8 *)(param_1 + 8);
    param_2[7] = 1;
    lVar6 = lVar6 + -1;
    uVar2 = Fsys_Seek(uVar5,0xfffffffffffffffe,1,0);
    if (uVar2 != 0) goto LAB_00342194;
    if (lVar6 == 0) break;
LAB_00342120:
    local_11 = '\0';
    iVar3 = Fsys_Read(*(undefined8 *)(param_1 + 8),&local_11,1);
    if (iVar3 != 1) {
      uVar2 = 1;
LAB_00342194:
      lVar6 = 0;
      break;
    }
  }
  if (uVar2 == 0 && lVar6 != 0) {
LAB_00342178:
    uVar5 = FUN_00341e60(param_1);
    param_2[5] = uVar5;
    param_2[6] = lVar6;
  }
  else if (uVar2 != 0) goto LAB_00341f84;
  uVar2 = (uint)(lVar6 == 0);
LAB_00341f84:
  operator_delete__(pvVar4);
  return uVar2;
}

