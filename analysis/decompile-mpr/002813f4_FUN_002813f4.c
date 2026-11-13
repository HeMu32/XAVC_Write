// FUN_002813f4
// Ghidra address: 002813f4

void FUN_002813f4(uint param_1,long param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  void *pvVar4;
  long *plVar5;
  long *plVar6;
  code *pcVar7;
  ulong uVar8;
  long lVar9;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 local_c;
  undefined1 local_b;
  undefined1 local_a;
  undefined1 local_9;
  uint local_8;
  
  uVar8 = (ulong)param_1;
  local_c = 4;
  local_b = 0;
  local_a = 0;
  local_9 = 0;
  local_10 = 0x2300;
  local_e = 0;
  FUN_00281260(&local_10,8);
  local_b = 0;
  local_c = 3;
  local_a = 0;
  local_e = 1;
  local_9 = 0;
  local_10 = 0x2300;
  local_8 = param_1;
  FUN_00281260(&local_10,0xc);
  if (param_2 != 0) {
    FUN_00194dd8(0x2300,2,param_2);
  }
  puVar2 = PTR_DAT_004028b8;
  lVar9 = uVar8 * 0x10;
  if (PTR_DAT_004028b8[lVar9] == '\0') {
    pvVar4 = operator_new(0xc0690);
    FUN_0028eb3c();
    puVar3 = PTR_DAT_00402c38;
    *(void **)(PTR_DAT_00402c38 + uVar8 * 8) = pvVar4;
    plVar5 = operator_new(0x20);
    puVar1 = PTR_DAT_00401b68;
    *(undefined4 *)(plVar5 + 2) = 0;
    plVar5[3] = 0;
    *plVar5 = (long)(puVar1 + 0x10);
    plVar5[1] = 0;
    *(long **)(PTR_DAT_00401ab8 + uVar8 * 8) = plVar5;
    puVar2[lVar9] = 1;
    plVar6 = *(long **)(puVar3 + uVar8 * 8);
    pcVar7 = *(code **)(*plVar6 + 0x10);
    *(long **)(puVar2 + lVar9 + 8) = plVar6;
    (*pcVar7)(plVar6,plVar5,0,param_2);
  }
  else {
    FUN_00194dd8(0x2300,3,"Init() has already been called");
  }
  local_b = 0;
  local_c = 4;
  local_a = 0;
  local_10 = 0x2300;
  local_9 = 0;
  local_e = 0xf;
  FUN_00281260(&local_10,8);
  return;
}

