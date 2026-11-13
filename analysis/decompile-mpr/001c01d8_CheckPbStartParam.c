// mpr::CheckPbStartParam
// Ghidra address: 001c01d8

/* mpr::CheckPbStartParam(mpr::pbStartInParam const&) */

undefined8 mpr::CheckPbStartParam(pbStartInParam *param_1)

{
  uint uVar1;
  int iVar2;
  uint local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 local_c;
  undefined1 local_b;
  undefined1 local_a;
  undefined1 local_9;
  uint local_8;
  uint uStack_4;
  
  local_c = 4;
  local_b = 0;
  local_10 = 0x2160;
  local_a = 0;
  local_e = 0x1c0;
  local_9 = 0;
  FUN_001bf858(&local_10,8);
  uVar1 = *(uint *)PTR_s_uniqueId_00402950;
  if (*(set **)(param_1 + 0x10) == (set *)0x0) {
    local_8 = *(uint *)(param_1 + 0x1c);
  }
  else {
    local_8 = sidb::set::at(*(set **)(param_1 + 0x10),*(uint *)(param_1 + 0x18));
  }
  uStack_4 = local_8;
  if (local_8 == uVar1) {
    uVar1 = *(uint *)(PTR_s_pbStartParam_00402b70 + 8);
    local_14 = 0xffffffff;
    iVar2 = sidb::GetMediaIdFromUniqueId(local_8,&local_14);
    if (iVar2 != 0) {
      local_b = 0;
      local_c = 3;
      local_a = 0;
      local_10 = 0x2160;
      local_9 = 0;
      local_e = 0x1c3;
      FUN_001bf858(&local_10,0xc);
      return 3;
    }
    local_b = 0;
    local_c = 2;
    local_a = 0;
    local_9 = 0;
    local_10 = 0x2160;
    if (uVar1 == local_14) {
      local_e = 0x1cf;
      FUN_001bf858(&local_10,0x10);
      return 1;
    }
    uStack_4 = local_14;
    local_e = 0x1c2;
  }
  else {
    local_e = 0x1c1;
  }
  local_8 = uVar1;
  local_9 = 0;
  local_a = 0;
  local_b = 0;
  local_c = 2;
  local_10 = 0x2160;
  FUN_001bf858(&local_10,0x10);
  return 2;
}

