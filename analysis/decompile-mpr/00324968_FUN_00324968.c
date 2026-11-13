// FUN_00324968
// Ghidra address: 00324968

uint FUN_00324968(undefined8 param_1,uint param_2,long param_3,byte param_4)

{
  uint uVar1;
  long lVar2;
  uint uVar3;
  long lVar4;
  undefined8 uVar5;
  long lVar6;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 local_c;
  undefined1 local_b;
  undefined1 local_a;
  undefined1 local_9;
  uint local_8;
  uint local_4;
  
  local_c = 2;
  local_e = 0x310;
  local_b = 0;
  local_a = 0;
  local_9 = 0;
  local_10 = 0x2301;
  local_4 = (uint)param_4;
  local_8 = param_2;
  FUN_00322494(&local_10,0x10);
  if (param_4 == 0) {
    uVar3 = (uint)*(undefined8 *)(param_3 + 0x28);
    if (uVar3 == 0) {
      uVar5 = 0xc;
      local_c = 3;
      local_e = 0x313;
      local_8 = 0;
    }
    else {
      uVar1 = 0;
      if (uVar3 != 0) {
        uVar1 = param_2 / uVar3;
      }
      uVar3 = param_2 - uVar1 * uVar3;
      lVar2 = *(long *)(param_3 + 0x10);
      lVar6 = param_3 + 8;
      while (lVar4 = lVar2, lVar4 != 0) {
        if (*(uint *)(lVar4 + 0x20) < uVar3) {
          lVar2 = *(long *)(lVar4 + 0x18);
        }
        else {
          lVar2 = *(long *)(lVar4 + 0x10);
          lVar6 = lVar4;
        }
      }
      if ((param_3 + 8 != lVar6) && (*(uint *)(lVar6 + 0x20) <= uVar3)) {
        param_2 = param_2 + *(int *)(lVar6 + 0x24);
        goto LAB_00324a88;
      }
      uVar5 = 0x10;
      local_c = 2;
      local_e = 0x312;
      local_8 = param_2;
      local_4 = uVar3;
    }
    local_9 = 0;
    local_a = 0;
    local_b = 0;
    local_10 = 0x2301;
    FUN_00322494(&local_10,uVar5);
  }
LAB_00324a88:
  local_c = 3;
  local_b = 0;
  local_10 = 0x2301;
  local_a = 0;
  local_e = 799;
  local_9 = 0;
  local_8 = param_2;
  FUN_00322494(&local_10,0xc);
  return param_2;
}

