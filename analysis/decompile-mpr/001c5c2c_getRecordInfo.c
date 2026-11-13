// mpr::stillplay::getRecordInfo
// Ghidra address: 001c5c2c

/* mpr::stillplay::getRecordInfo(unsigned int, char const*, sidb::recordInfo*, bool) */

undefined4
mpr::stillplay::getRecordInfo(uint param_1,char *param_2,recordInfo *param_3,bool param_4)

{
  undefined1 uVar1;
  undefined2 uVar2;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  long lVar8;
  undefined8 *puVar9;
  undefined8 uVar10;
  undefined4 uVar11;
  libstill *plVar12;
  undefined8 local_910;
  ulong uStack_908;
  undefined2 local_900 [4];
  undefined8 local_8f8;
  ulong local_8f0;
  undefined8 local_8e8;
  undefined8 uStack_8e0;
  undefined8 local_8d8;
  undefined8 uStack_8d0;
  undefined8 local_8c8;
  ulong uStack_8c0;
  undefined8 local_8b8;
  undefined8 uStack_8b0;
  undefined8 local_8a8;
  undefined8 uStack_8a0;
  undefined1 auStack_898 [12];
  int local_88c;
  undefined2 local_7f0;
  undefined2 local_7ee;
  undefined4 local_7ec;
  int local_7e8;
  int local_7e4;
  get_if_t agStack_400 [8];
  undefined2 *local_3f8;
  undefined2 local_350;
  area_list_t aaStack_160 [228];
  undefined8 local_7c;
  undefined8 uStack_74;
  undefined8 local_6c;
  undefined8 uStack_64;
  undefined8 local_5c;
  undefined8 uStack_54;
  undefined2 uVar3;
  
  memset(auStack_898,0,0xa8);
  local_8f8 = 0;
  local_8f0 = 0;
  local_8e8 = 0;
  uStack_8e0 = 0;
  local_8d8 = 0;
  uStack_8d0 = 0;
  memset(agStack_400,0,0x400);
  _init_get_if_t(agStack_400);
  puVar7 = operator_new(4);
  *puVar7 = 0;
  iVar4 = FUN_001c4cd8(param_2);
  iVar5 = Fsys_Open(param_2,&local_910,1);
  if (iVar5 != 0) {
    uVar10 = 0xc;
    local_7ec = 3;
    local_7ee = 0x2100;
    local_7e8 = iVar5;
LAB_001c5d04:
    local_7f0 = 0x2140;
    plVar12 = (libstill *)0x0;
    FUN_001c495c(&local_7f0,uVar10);
LAB_001c5d10:
    uVar11 = 0xb;
    goto LAB_001c5d70;
  }
  uVar10 = FUN_003b7184(0x40000,0);
  lVar8 = FUN_003b769c(uVar10,auStack_898,1,puVar7);
  if (lVar8 == 0) {
    plVar12 = (libstill *)0x0;
    uVar11 = 2;
    local_7f0 = 0x2140;
    local_7ee = 0x2200;
    local_7ec = 4;
    FUN_001c495c(&local_7f0,8);
    goto LAB_001c5d70;
  }
  FUN_001c4d88(auStack_898,&local_8f8);
  iVar5 = Fsys_Read(local_910,local_8e8,local_8f0 & 0xffffffff);
  iVar6 = Fsys_Close(local_910);
  if (iVar6 != 0 || iVar5 < 1) {
    local_7ec = 2;
    local_7ee = 0x2300;
    uVar10 = 0x10;
    local_7e8 = iVar6;
    local_7e4 = iVar5;
    goto LAB_001c5d04;
  }
  plVar12 = (libstill *)stillutil::creater(iVar4);
  if (plVar12 == (libstill *)0x0) {
    uVar10 = 8;
    local_7ec = 4;
    local_7ee = 0x2310;
LAB_001c5e64:
    local_7f0 = 0x2140;
    FUN_001c495c(&local_7f0,uVar10);
    goto LAB_001c5d10;
  }
  local_8c8 = local_8f8;
  uStack_8c0 = local_8f0;
  local_8b8 = local_8e8;
  uStack_8b0 = uStack_8e0;
  local_8a8 = local_8d8;
  uStack_8a0 = uStack_8d0;
  iVar5 = libstill::ana_if(plVar12,&local_8c8,0);
  if (iVar5 != 0) {
    local_7ec = 3;
    local_7ee = 0x2400;
    uVar10 = 0xc;
    local_7e8 = iVar5;
    goto LAB_001c5e64;
  }
  local_3f8 = &local_7f0;
  FUN_0037589c(plVar12,agStack_400);
  uVar11 = 0;
  if (param_4) goto LAB_001c5d70;
  if (*(char *)((long)local_3f8 + 0x1d) != '\0') {
    param_3[0x25] = *(undefined1 *)(local_3f8 + 0xf);
  }
  if (*(char *)(local_3f8 + 0x1a) != '\0') {
    *(undefined8 *)(param_3 + 0xc) = *(undefined8 *)(local_3f8 + 0x1b);
    *(undefined4 *)(param_3 + 0x14) = *(undefined4 *)(local_3f8 + 0x1f);
  }
  uVar1 = *(undefined1 *)((long)local_3f8 + 0x25);
  param_3[0x5f0] = *(undefined1 *)(local_3f8 + 0x12);
  param_3[0x5f1] = uVar1;
  switch(iVar4) {
  case 1:
    puVar9 = (undefined8 *)(param_3 + 0x504);
    break;
  case 2:
    puVar9 = (undefined8 *)(param_3 + 0x524);
    break;
  default:
    uVar11 = 3;
    goto LAB_001c5f64;
  case 4:
    puVar9 = (undefined8 *)(param_3 + 0x544);
    break;
  case 8:
    puVar9 = (undefined8 *)(param_3 + 0x564);
  }
  *puVar9 = local_7c;
  puVar9[1] = uStack_74;
  puVar9[2] = local_6c;
  puVar9[3] = uStack_64;
LAB_001c5f64:
  *(undefined8 *)(param_3 + 0x5f3) = local_5c;
  *(undefined8 *)(param_3 + 0x5fb) = uStack_54;
  uVar2 = (undefined2)local_7ec;
  uVar3 = (undefined2)local_7e8;
  if (iVar4 == 2) {
    if ((char)local_7f0 == '\0') {
      *(undefined2 *)(param_3 + 0x4e2) = 0;
      *(undefined2 *)(param_3 + 0x4e0) = 0;
    }
    else {
      *(undefined2 *)(param_3 + 0x4e0) = uVar2;
      *(undefined2 *)(param_3 + 0x4e2) = uVar3;
    }
    *(undefined2 *)(param_3 + 0x4f4) = local_350;
  }
  else if (iVar4 == 4) {
    if ((char)local_7f0 == '\0') {
      *(undefined2 *)(param_3 + 0x4e6) = 0;
      *(undefined2 *)(param_3 + 0x4e4) = 0;
    }
    else {
      *(undefined2 *)(param_3 + 0x4e4) = uVar2;
      *(undefined2 *)(param_3 + 0x4e6) = uVar3;
    }
    _calc_image_area(aaStack_160,&uStack_908,(ulong *)local_900);
    *(undefined2 *)(param_3 + 0x4fc) = local_900[0];
  }
  else if (iVar4 == 1) {
    if ((char)local_7f0 == '\0') {
      *(undefined2 *)(param_3 + 0x4de) = 0;
      *(undefined2 *)(param_3 + 0x4dc) = 0;
    }
    else {
      *(undefined2 *)(param_3 + 0x4dc) = uVar2;
      *(undefined2 *)(param_3 + 0x4de) = uVar3;
    }
    *(undefined2 *)(param_3 + 0x4ec) = local_350;
  }
LAB_001c5d70:
  if (local_88c != 0) {
    FUN_003b7968();
  }
  if (plVar12 != (libstill *)0x0) {
    (**(code **)(*(long *)plVar12 + 8))(plVar12);
  }
  operator_delete(puVar7,4);
  return uVar11;
}

