// mpr::ExecEncClose
// Ghidra address: 001d06b4

/* mpr::ExecEncClose(void*) */

void mpr::ExecEncClose(void *param_1)

{
  uint uVar1;
  undefined *puVar2;
  char cVar3;
  int iVar4;
  long lVar5;
  undefined2 local_60;
  undefined2 local_5e;
  undefined1 local_5c;
  undefined1 local_5b;
  undefined1 local_5a;
  undefined1 local_59;
  int local_58;
  long local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  undefined8 uStack_18;
  undefined8 local_10;
  undefined8 uStack_8;
  
  local_30 = 0x402802110;
  lVar5 = 0;
  FUN_001c9f24(&local_30,8);
  local_30 = 0;
  uStack_28 = 0;
  iVar4 = 0;
  local_20 = 0;
  uStack_18 = 0;
  local_10 = 0;
  uStack_8 = 0;
  thread::normalLock::lock((normalLock *)PTR_s_integRecordMovieLock_00402670);
  puVar2 = PTR_s_movieRecInfo_00401670;
  while (uVar1 = (uint)lVar5, lVar5 = lVar5 + 1, uVar1 < *(uint *)puVar2) {
    local_50 = (ulong)local_50._1_7_ << 8;
    GetRecordCounter(*(uint *)(puVar2 + lVar5 * 4),(uchar *)&local_50);
    iVar4 = iVar4 + (uint)(byte)local_50;
  }
  if (*(int *)((long)param_1 + 0x24) == 0) {
    if (iVar4 != 0) {
      local_50 = (ulong)local_50._1_7_ << 8;
      iVar4 = iVar4 + -1;
      GetRecordCounter(*(uint *)((long)param_1 + 0x20),(uchar *)&local_50);
      SetRecordCounter(*(uint *)((long)param_1 + 0x20),(byte)local_50 + 0xff);
      goto LAB_001d0790;
    }
LAB_001d0828:
    local_50 = 0;
    local_48 = 0;
    if (*(char *)param_1 == '\0') {
      iVar4 = Codec::EncClose(&local_50,0x20,*(undefined4 *)((long)param_1 + 4),1,0,&local_30);
      if (iVar4 != 0) {
        local_5e = 0x283;
        goto LAB_001d087c;
      }
      local_5e = 0x284;
LAB_001d0910:
      local_59 = 0;
      local_5a = 0;
      local_5b = 0;
      local_5c = 4;
      local_60 = 0x2110;
      FUN_001c9f24(&local_60,8);
    }
    else {
      local_40 = 0;
      uStack_38 = 0;
      iVar4 = Codec::EncClose2(&local_50,0x20,*(undefined4 *)((long)param_1 + 4),0x20,
                               *(undefined4 *)((long)param_1 + 8),&local_30);
      if (iVar4 == 0) {
        local_5e = 0x286;
        goto LAB_001d0910;
      }
      local_5e = 0x285;
LAB_001d087c:
      local_59 = 0;
      local_5a = 0;
      local_5b = 0;
      local_5c = 3;
      local_60 = 0x2110;
      local_58 = iVar4;
      FUN_001c9f24(&local_60,0xc);
      FUN_001fe0e8(*(undefined8 *)((long)param_1 + 0x28),iVar4);
      FUN_001fe0e8(*(undefined8 *)((long)param_1 + 0x30),iVar4);
    }
    DeleteUseStreamBufferArea
              (*(RingBuffer ***)((long)param_1 + 0x10),*(RingBuffer ***)((long)param_1 + 0x18));
    cVar3 = DmmMemInfo::FreeDmmMemory(*(int *)((long)param_1 + 0xc));
    if (cVar3 != '\0') goto LAB_001d07c8;
    local_50 = 0x302872110;
    local_48 = CONCAT44(local_48._4_4_,*(undefined4 *)((long)param_1 + 0xc));
  }
  else {
LAB_001d0790:
    if (iVar4 == 0) goto LAB_001d0828;
    local_48 = CONCAT44(local_48._4_4_,iVar4);
    local_50 = 0x302812110;
  }
  FUN_001c9f24(&local_50,0xc);
LAB_001d07c8:
  puVar2 = PTR_s_integRecordMovieLock_00402670;
  *(undefined4 *)(PTR_s_movieRecInfo_00401670 + 0xa74) = 0;
  thread::normalLock::unlock((normalLock *)puVar2);
  local_50 = 0x3028f2110;
  local_48 = CONCAT44(local_48._4_4_,local_20._4_4_);
  FUN_001c9f24(&local_50,0xc);
  return;
}

