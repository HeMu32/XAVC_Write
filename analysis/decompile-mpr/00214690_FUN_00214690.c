// FUN_00214690
// Ghidra address: 00214690

void FUN_00214690(long param_1,undefined8 param_2,uint *param_3,uint *param_4,undefined8 param_5,
                 undefined8 param_6,undefined1 param_7,byte param_8,undefined8 param_9,
                 undefined8 param_10,byte *param_11,undefined8 param_12)

{
  int iVar1;
  ulong uVar2;
  byte bVar3;
  undefined1 local_19;
  long local_18;
  long local_10;
  undefined8 local_8;
  
  *param_11 = 1;
  local_19 = param_7;
  if ((((*param_3 & 1) != 0) && ((*param_4 & 1) != 0)) || ((*param_3 >> 4 & 1) != 0)) {
    local_18 = 0;
    local_10 = 0;
    uVar2 = 1;
    local_8 = 0;
    bVar3 = *(byte *)(param_1 + 0x4a8);
    if (((param_8 != 0) && (uVar2 = 1, *(char *)(param_1 + 0x4a9) == '\0')) &&
       (uVar2 = 2, bVar3 != 0)) {
      bVar3 = 2;
      uVar2 = 2;
    }
    mpr::Codec::GetVideoPiWriteList((vector *)&local_18);
    if ((ulong)((local_10 - local_18 >> 3) * -0x5555555555555555) < uVar2) {
      *param_11 = 0;
    }
    local_10 = local_18;
    mpr::Codec::GetAudioPiWriteList((vector *)&local_18);
    if ((ulong)((local_10 - local_18 >> 3) * -0x5555555555555555) < (ulong)bVar3) {
      *param_11 = 0;
    }
    local_10 = local_18;
    std::_Vector_base<mpr::Codec::BufferAreaInfo,std::allocator<mpr::Codec::BufferAreaInfo>>::
    ~_Vector_base((_Vector_base<mpr::Codec::BufferAreaInfo,std::allocator<mpr::Codec::BufferAreaInfo>>
                   *)&local_18);
    if (*param_11 == 0) {
      return;
    }
    bVar3 = 0;
    if (*(int *)(param_1 + 0x430) != 0) {
      bVar3 = param_8 & *(byte *)(param_1 + 0x43c) ^ 1;
    }
    iVar1 = FUN_0021406c(param_1,param_9,&local_19,bVar3,param_2,param_5,param_6,param_3,param_12);
    if (iVar1 != 0) goto LAB_002147b4;
    if (*(char *)(param_1 + 0x4a8) != '\0') {
      iVar1 = FUN_002136c0(param_1,param_10,0,param_2,param_3);
      goto LAB_002147b4;
    }
  }
  iVar1 = 0;
LAB_002147b4:
  if ((((param_8 & *param_11) != 0) && ((iVar1 == 0 & (*(byte *)(param_1 + 0x4a9) ^ 1)) != 0)) &&
     ((iVar1 = FUN_0021406c(param_1,param_9,&local_19,2,param_2,param_5,0,param_3,param_12),
      iVar1 == 0 && (*(char *)(param_1 + 0x4a8) != '\0')))) {
    FUN_002136c0(param_1,param_10,2,param_2,param_3);
  }
  return;
}

