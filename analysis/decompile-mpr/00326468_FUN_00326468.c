// FUN_00326468
// Ghidra address: 00326468

void FUN_00326468(undefined8 param_1,undefined8 param_2,undefined4 *param_3,long param_4,
                 undefined4 *param_5)

{
  undefined2 uVar1;
  uint uVar2;
  bool bVar3;
  undefined4 uVar4;
  int iVar5;
  undefined8 uVar6;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  undefined8 uStack_18;
  undefined8 local_10;
  undefined4 local_8;
  
  uVar1 = *(undefined2 *)(param_4 + 0x18);
  *param_5 = param_3[4];
  param_5[1] = *(undefined4 *)(param_4 + 0x10);
  uVar2 = CONCAT22(uVar1,*(undefined2 *)(param_4 + 0x1a));
  param_5[3] = uVar2;
  if (uVar2 != 0x320000) {
    if (uVar2 < 0x320001) {
      bVar3 = uVar2 == 0x190000;
    }
    else {
      if (uVar2 == 0x640000) goto LAB_003264c4;
      bVar3 = uVar2 == 0xc80000;
    }
    uVar4 = 0;
    if (!bVar3) goto LAB_003264c8;
  }
LAB_003264c4:
  uVar4 = 1;
LAB_003264c8:
  param_5[2] = uVar4;
  uVar4 = FUN_0032637c(param_1);
  local_40 = 0;
  uStack_38 = 0;
  uVar6 = *(undefined8 *)(param_3 + 0x26);
  param_5[6] = uVar4;
  local_30 = 0;
  uStack_28 = 0;
  local_20 = 0;
  uStack_18 = 0;
  local_10 = 0;
  local_8 = 0;
  iVar5 = FUN_002cc004(param_2,uVar6,1,&local_40);
  if (iVar5 == 0) {
    *(undefined2 *)(param_5 + 7) = uStack_38._4_2_;
    *(undefined2 *)((long)param_5 + 0x1e) = uStack_38._6_2_;
    FUN_00324ea4(param_1,&local_40,param_5 + 8,(long)param_5 + 0x2e);
    param_5[9] = 0;
    param_5[10] = 1;
    *(undefined1 *)(param_5 + 0xb) = 3;
    *(undefined1 *)((long)param_5 + 0x2d) = 3;
    iVar5 = FUN_00325020(param_1,param_2,*param_3,param_5 + 0xc);
    if (iVar5 == 0) {
      param_5[0xd] = (uint)(*(char *)((long)param_3 + 0xad) != '\0');
    }
  }
  return;
}

