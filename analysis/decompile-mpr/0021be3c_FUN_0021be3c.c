// FUN_0021be3c
// Ghidra address: 0021be3c

char FUN_0021be3c(undefined8 param_1,long param_2,uint param_3,uint param_4,uint param_5,
                 uint param_6,undefined8 param_7,char *param_8)

{
  uint uVar1;
  int iVar2;
  ulong uVar3;
  uint uVar4;
  ulong uVar5;
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
  
  if (*param_8 != '\0') goto LAB_0021bedc;
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
    uVar1 = (int)*(ulong *)(param_2 + 0x468) - uVar4;
    if (*(ulong *)(param_2 + 0x468) <= (ulong)uVar4) {
      uVar1 = 0;
    }
    if (param_3 <= uVar1) {
      std::
      _Vector_base<mpr::VideoEncodeTable::VideoInfo,std::allocator<mpr::VideoEncodeTable::VideoInfo>>
      ::~_Vector_base((_Vector_base<mpr::VideoEncodeTable::VideoInfo,std::allocator<mpr::VideoEncodeTable::VideoInfo>>
                       *)&local_18);
      local_18 = 0;
      lStack_10 = 0;
      local_8 = 0;
      iVar2 = mpr::Codec::GetMetaInfoReadList
                        (*(uint *)(param_2 + 0x14),*(uint *)(param_2 + 4),(vector *)&local_18);
      if (iVar2 == 0) {
        iVar2 = (int)((ulong)(lStack_10 - local_18) >> 8);
        if ((uint)(iVar2 * -0x33333333) < *(uint *)(param_2 + 0x4c8)) {
          uVar4 = *(uint *)(param_2 + 0x4c8) + iVar2 * 0x33333333;
          if (param_6 < uVar4) {
            FUN_0021b940((_Vector_base<mpr::VideoEncodeTable::VideoInfo,std::allocator<mpr::VideoEncodeTable::VideoInfo>>
                          *)&local_18);
            local_18 = 0;
            lStack_10 = 0;
            local_8 = 0;
            iVar2 = mpr::Codec::GetAudioInfoReadList
                              (*(uint *)(param_2 + 0x14),*(uint *)(param_2 + 4),(vector *)&local_18,
                               true);
            if (iVar2 == 0) {
              uVar3 = (lStack_10 - local_18 >> 3) * -0x71c71c71c71c71c7;
              if ((uint)uVar3 < *(uint *)(param_2 + 0x4b0)) {
                uVar4 = *(uint *)(param_2 + 0x4b0) - (uint)uVar3;
                if (uVar4 <= param_5) goto LAB_0021c160;
                uVar4 = 0;
                for (uVar5 = 0; uVar5 <= uVar3 && uVar3 - uVar5 != 0;
                    uVar5 = (ulong)((int)uVar5 + 1)) {
                  uVar4 = uVar4 + *(int *)(local_18 + uVar5 * 0x48 + 0x18);
                }
                uVar1 = (int)*(ulong *)(param_2 + 0x480) - uVar4;
                if (*(ulong *)(param_2 + 0x480) <= (ulong)uVar4) {
                  uVar1 = 0;
                }
                if (param_4 <= uVar1) goto LAB_0021c0f0;
                local_26 = 0xeb14;
                local_20 = uVar1;
                uStack_1c = param_4;
              }
              else {
                uVar4 = 0;
LAB_0021c160:
                local_26 = 0xeb10;
                local_20 = uVar4;
                uStack_1c = param_5;
              }
              local_21 = 0;
              local_22 = 0;
              local_23 = 0;
              local_24 = 2;
              local_28 = 0x2310;
              FUN_0021777c(&local_28,0x10);
              FUN_001fe0e8(param_7,0xb);
              *param_8 = '\x01';
            }
            else {
              local_23 = 0;
              local_24 = 4;
              local_22 = 0;
              local_28 = 0x2310;
              local_21 = 0;
              local_26 = 0xeb0e;
              FUN_0021777c(&local_28,8);
              FUN_001fe0e8(param_7,2);
            }
LAB_0021c0f0:
            std::
            _Vector_base<mpr::AudioEncodeTable::AudioInfo,std::allocator<mpr::AudioEncodeTable::AudioInfo>>
            ::~_Vector_base((_Vector_base<mpr::AudioEncodeTable::AudioInfo,std::allocator<mpr::AudioEncodeTable::AudioInfo>>
                             *)&local_18);
            goto LAB_0021bedc;
          }
        }
        else {
          uVar4 = 0;
        }
        local_23 = 0;
        local_24 = 2;
        local_22 = 0;
        local_28 = 0x2310;
        local_21 = 0;
        local_26 = 0xeb0a;
        local_20 = uVar4;
        uStack_1c = param_6;
        FUN_0021777c(&local_28,0x10);
        FUN_001fe0e8(param_7,0xb);
        *param_8 = '\x01';
      }
      else {
        local_23 = 0;
        local_24 = 4;
        local_22 = 0;
        local_28 = 0x2310;
        local_21 = 0;
        local_26 = 0xeb08;
        FUN_0021777c(&local_28,8);
        FUN_001fe0e8(param_7,2);
      }
      FUN_0021b940((_Vector_base<mpr::VideoEncodeTable::VideoInfo,std::allocator<mpr::VideoEncodeTable::VideoInfo>>
                    *)&local_18);
      goto LAB_0021bedc;
    }
    local_23 = 0;
    local_24 = 2;
    local_22 = 0;
    local_28 = 0x2310;
    local_21 = 0;
    local_26 = 0xeb04;
    local_20 = uVar1;
    uStack_1c = param_3;
    FUN_0021777c(&local_28,0x10);
    FUN_001fe0e8(param_7,0xb);
    *param_8 = '\x01';
  }
  else {
    local_23 = 0;
    local_24 = 4;
    local_22 = 0;
    local_28 = 0x2310;
    local_21 = 0;
    local_26 = 0xeb02;
    FUN_0021777c(&local_28,8);
    FUN_001fe0e8(param_7,2);
  }
  std::
  _Vector_base<mpr::VideoEncodeTable::VideoInfo,std::allocator<mpr::VideoEncodeTable::VideoInfo>>::
  ~_Vector_base((_Vector_base<mpr::VideoEncodeTable::VideoInfo,std::allocator<mpr::VideoEncodeTable::VideoInfo>>
                 *)&local_18);
LAB_0021bedc:
  return *param_8;
}

