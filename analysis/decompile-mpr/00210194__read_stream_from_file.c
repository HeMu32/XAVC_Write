// XavcsMovieReader::_read_stream_from_file
// Ghidra address: 00210194

/* XavcsMovieReader::_read_stream_from_file(void*, mpr::RingBuffer*, unsigned long, unsigned int,
   bool, mpr::BaseList*, unsigned int*) */

int XavcsMovieReader::_read_stream_from_file
              (void *param_1,RingBuffer *param_2,ulong param_3,uint param_4,bool param_5,
              BaseList *param_6,uint *param_7)

{
  uint uVar1;
  void *pvVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  BaseList *this;
  void *pvVar6;
  int iVar7;
  uint uVar8;
  ulong uVar9;
  int iVar10;
  long lVar11;
  int local_38;
  uint local_2c;
  void *local_28;
  undefined1 auStack_20 [8];
  undefined2 local_18;
  undefined2 local_16;
  undefined1 local_14;
  undefined1 local_13;
  undefined1 local_12;
  undefined1 local_11;
  int local_10;
  int local_c;
  uint local_8;
  int local_4;
  
  this = operator_new(0x20);
  mpr::BaseList::BaseList(this,2);
  local_2c = 0;
  local_28 = (void *)0x0;
  pvVar6 = (void *)mpr::RingBuffer::GetWritePointer(param_2);
  uVar9 = param_3 & 0xfffffffffffffe00;
  lVar11 = param_3 - uVar9;
  iVar10 = (int)lVar11;
  uVar8 = (param_4 + iVar10 & 0xfffffe00) + (uint)((lVar11 + (ulong)param_4 & 0x1ff) != 0) * 0x200;
  iVar3 = 0;
  if ((uVar8 & 0xfff) != 0) {
    iVar3 = 0x1000;
  }
  uVar1 = iVar3 + (uVar8 & 0xfffff000);
  mpr::RingBuffer::ConvertToBaseList(param_2,pvVar6,uVar1,this);
  iVar3 = mpr::BaseList::GetNum(this);
  uVar4 = Fsys_Seek(param_1,uVar9,0,auStack_20);
  iVar7 = (int)(param_3 >> 0x20);
  if (uVar4 != 0) {
    local_4 = 0;
    local_13 = 0;
    local_14 = 1;
    local_12 = 0;
    iVar5 = 2;
    local_18 = 0x2311;
    local_11 = 0;
    local_16 = 0x1b02;
    local_c = (int)uVar9;
    local_10 = iVar7;
    local_8 = uVar4;
    FUN_0020aff4(&local_18,0x18);
    goto LAB_002102a0;
  }
  if (iVar3 == 1) {
    mpr::BaseList::Get(this,0,&local_28,&local_2c);
    memset(local_28,0,(ulong)local_2c);
    iVar3 = Fsys_Read(param_1,local_28,uVar8);
    if (-1 < iVar3) {
      iVar5 = mpr::BaseList::Add(param_6,(void *)((long)local_28 + lVar11),param_4);
      if (iVar5 != 0) {
        local_16 = 0x1b08;
        local_c = iVar10 + (int)local_28;
        local_10 = (int)((ulong)((long)local_28 + lVar11) >> 0x20);
        local_8 = param_4;
        goto LAB_00210618;
      }
      goto LAB_0021072c;
    }
    local_16 = 0x1b04;
LAB_0021033c:
    local_11 = 0;
    local_12 = 0;
    local_13 = 0;
    local_14 = 1;
    local_18 = 0x2311;
    iVar5 = 2;
    local_10 = (int)((ulong)local_28 >> 0x20);
    local_c = (int)local_28;
    local_8 = uVar8;
    local_4 = iVar3;
    FUN_0020aff4(&local_18,0x18);
  }
  else {
    iVar5 = 2;
    if (iVar3 == 2) {
      iVar5 = 0;
      mpr::BaseList::Get(this,0,&local_28,&local_2c);
      memset(local_28,0,(ulong)local_2c);
      iVar3 = Fsys_Read(param_1,local_28,local_2c);
      if (iVar3 < 0) {
        local_13 = 0;
        local_12 = 0;
        iVar5 = 2;
        local_14 = 1;
        local_11 = 0;
        local_18 = 0x2311;
        local_16 = 0x1b0c;
        local_10 = (int)((ulong)local_28 >> 0x20);
        local_c = (int)local_28;
        local_8 = local_2c;
        local_4 = iVar3;
        FUN_0020aff4(&local_18,0x18);
      }
      if (iVar10 < iVar3) {
        pvVar6 = (void *)0x0;
        uVar4 = param_4;
        if ((uint)(iVar3 - iVar10) < param_4) {
          uVar4 = iVar3 - iVar10;
        }
        if (iVar5 == 0) {
          if (param_5) {
            pvVar6 = (void *)((long)local_28 + lVar11);
            if ((param_4 == uVar4) &&
               (iVar5 = mpr::BaseList::Add(param_6,pvVar6,param_4), iVar5 != 0)) {
              local_16 = 0x1b2b;
              local_8 = param_4;
              pvVar2 = pvVar6;
              goto LAB_002104c8;
            }
          }
          else {
            iVar5 = mpr::BaseList::Add(param_6,(void *)((long)local_28 + lVar11),uVar4);
            if (iVar5 != 0) {
              local_16 = 0x1b20;
              local_8 = uVar4;
              pvVar2 = (void *)CONCAT44((int)((ulong)((long)local_28 + lVar11) >> 0x20),
                                        iVar10 + (int)local_28);
LAB_002104c8:
              local_10 = (int)((ulong)pvVar2 >> 0x20);
              local_c = (int)pvVar2;
              local_11 = 0;
              local_12 = 0;
              local_13 = 0;
              local_14 = 1;
              local_18 = 0x2311;
              local_4 = iVar5;
              FUN_0020aff4(&local_18,0x18);
            }
          }
        }
      }
      else {
        local_13 = 0;
        uVar4 = 0;
        local_14 = 2;
        local_12 = 0;
        pvVar6 = (void *)0x0;
        local_18 = 0x2311;
        local_11 = 0;
        iVar5 = 2;
        local_16 = 0x1b21;
        local_10 = iVar3;
        local_c = iVar10;
        FUN_0020aff4(&local_18,0x10);
      }
      if (iVar5 == 0 && uVar4 < param_4) {
        uVar8 = uVar8 - iVar3;
        mpr::BaseList::Get(this,1,&local_28,&local_2c);
        memset(local_28,0,(ulong)local_2c);
        iVar3 = Fsys_Read(param_1,local_28,uVar8);
        if (iVar3 < 0) {
          local_16 = 0x1b24;
          goto LAB_0021033c;
        }
        if (param_5) {
          iVar5 = mpr::BaseList::Add(param_6,pvVar6,param_4);
          if (iVar5 != 0) {
            local_16 = 0x1b2a;
            local_10 = (int)((ulong)pvVar6 >> 0x20);
            local_c = (int)pvVar6;
            local_8 = param_4;
            goto LAB_00210618;
          }
        }
        else {
          iVar5 = mpr::BaseList::Add(param_6,local_28,param_4 - uVar4);
          if (iVar5 != 0) {
            local_16 = 0x1b28;
            local_10 = (int)((ulong)local_28 >> 0x20);
            local_c = (int)local_28;
            local_8 = param_4 - uVar4;
LAB_00210618:
            local_14 = 1;
            local_11 = 0;
            local_12 = 0;
            local_13 = 0;
            local_18 = 0x2311;
            local_4 = iVar5;
            FUN_0020aff4(&local_18,0x18);
            goto LAB_00210358;
          }
        }
LAB_0021072c:
        iVar5 = 0;
        mpr::RingBuffer::UseMemory(param_2,uVar1);
        *param_7 = (*param_7 - param_4) + uVar1;
        goto LAB_002102a0;
      }
      local_13 = 0;
      local_14 = 1;
      local_12 = 0;
      local_18 = 0x2311;
      local_11 = 0;
      local_16 = 0x1b29;
      local_4 = 0;
      local_10 = iVar5;
      local_c = iVar3;
      local_8 = param_4;
      FUN_0020aff4(&local_18,0x18);
      if (iVar5 == 0) goto LAB_0021072c;
    }
  }
LAB_00210358:
  local_13 = 0;
  local_14 = 1;
  local_12 = 0;
  local_18 = 0x2311;
  local_11 = 0;
  local_16 = 0x1b2c;
  local_38 = (int)param_3;
  local_c = local_38;
  local_10 = iVar7;
  local_8 = param_4;
  local_4 = iVar5;
  FUN_0020aff4(&local_18,0x18);
LAB_002102a0:
  mpr::BaseList::Clear(this);
  (**(code **)(*(long *)this + 8))(this);
  return iVar5;
}

