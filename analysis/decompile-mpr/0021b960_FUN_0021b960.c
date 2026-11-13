// FUN_0021b960
// Ghidra address: 0021b960

undefined8 FUN_0021b960(undefined8 param_1,long param_2,uint param_3,undefined8 param_4)

{
  uint uVar1;
  int iVar2;
  ulong uVar3;
  uint uVar4;
  ulong uVar5;
  undefined8 uVar6;
  undefined2 local_28;
  undefined2 local_26;
  undefined1 local_24;
  undefined1 local_23;
  undefined1 local_22;
  undefined1 local_21;
  uint local_20;
  uint uStack_1c;
  long local_18;
  long lStack_10;
  undefined8 local_8;
  
  local_18 = 0;
  lStack_10 = 0;
  local_8 = 0;
  iVar2 = mpr::Codec::GetVideoInfoReadList
                    (*(uint *)(param_2 + 0x14),*(uint *)(param_2 + 4),(vector *)&local_18);
  if (iVar2 == 0) {
    uVar3 = (lStack_10 - local_18 >> 5) * -0x5555555555555555;
    uVar4 = 0;
    for (uVar5 = 0; uVar5 <= uVar3 && uVar3 - uVar5 != 0; uVar5 = (ulong)((int)uVar5 + 1)) {
      uVar4 = uVar4 + *(int *)(local_18 + uVar5 * 0x60 + 0x10);
    }
    uVar6 = 0;
    uVar1 = (int)*(ulong *)(param_2 + 0x468) - uVar4;
    if (*(ulong *)(param_2 + 0x468) <= (ulong)uVar4) {
      uVar1 = 0;
    }
    if (uVar1 < param_3) {
      local_23 = 0;
      local_24 = 2;
      local_22 = 0;
      uVar6 = 1;
      local_28 = 0x2310;
      local_21 = 0;
      local_26 = 0xec04;
      local_20 = uVar1;
      uStack_1c = param_3;
      FUN_0021777c(&local_28,0x10);
      FUN_001fe0e8(param_4,0xb);
    }
  }
  else {
    local_23 = 0;
    uVar6 = 0;
    local_24 = 4;
    local_22 = 0;
    local_28 = 0x2310;
    local_21 = 0;
    local_26 = 0xec02;
    FUN_0021777c(&local_28,8);
    FUN_001fe0e8(param_4,2);
  }
  std::
  _Vector_base<mpr::VideoEncodeTable::VideoInfo,std::allocator<mpr::VideoEncodeTable::VideoInfo>>::
  ~_Vector_base((_Vector_base<mpr::VideoEncodeTable::VideoInfo,std::allocator<mpr::VideoEncodeTable::VideoInfo>>
                 *)&local_18);
  return uVar6;
}

