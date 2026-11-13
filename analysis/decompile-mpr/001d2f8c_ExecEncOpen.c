// mpr::ExecEncOpen
// Ghidra address: 001d2f8c

/* mpr::ExecEncOpen(void*) */

void mpr::ExecEncOpen(void *param_1)

{
  BufferTable *__src;
  undefined *puVar1;
  char cVar2;
  int iVar3;
  normalLock *this;
  undefined8 uVar4;
  undefined4 local_170;
  undefined1 local_16c;
  undefined1 local_16b;
  undefined1 local_16a;
  undefined1 local_169;
  int local_168;
  undefined8 local_160;
  undefined8 uStack_158;
  undefined8 local_150;
  undefined8 uStack_148;
  undefined8 local_140;
  undefined8 uStack_138;
  undefined8 local_130;
  undefined8 local_128;
  undefined8 local_120;
  undefined8 uStack_118;
  AvbbcApi_EncOpen aAStack_98 [152];
  
  local_130 = 0x402502110;
  FUN_001c9f24((AvbbcApi_EncOpen *)&local_130,8);
  this = (normalLock *)PTR_s_integRecordMovieLock_00402670;
  local_160 = 0;
  uStack_158 = 0;
  local_150 = 0;
  uStack_148 = 0;
  local_140 = 0;
  uStack_138 = 0;
  thread::normalLock::lock((normalLock *)PTR_s_integRecordMovieLock_00402670);
  if (*(int *)((long)param_1 + 0x7b8) == 1) {
    local_130 = 0;
    local_128 = 0;
    iVar3 = Codec::EncClose((AvbbcApi_EncOpen *)&local_130,0x20,
                            *(undefined4 *)((long)param_1 + 0x780),1,0,&local_160);
    if (iVar3 != 0) {
      local_170._2_2_ = 0x251;
LAB_001d304c:
      local_169 = 0;
      local_16a = 0;
      local_16b = 0;
      local_16c = 3;
      local_170._0_2_ = 0x2110;
      local_168 = iVar3;
      FUN_001c9f24(&local_170,0xc);
      FUN_001fe21c(*(undefined8 *)((long)param_1 + 0x7a8),iVar3);
      FUN_001fe0e8(*(undefined8 *)((long)param_1 + 0x7b0),iVar3);
      goto LAB_001d3078;
    }
    local_170._2_2_ = 0x252;
LAB_001d30ac:
    local_169 = 0;
    local_16a = 0;
    local_16b = 0;
    local_16c = 4;
    local_170._0_2_ = 0x2110;
    FUN_001c9f24(&local_170,8);
  }
  else if (*(int *)((long)param_1 + 0x7b8) == 2) {
    local_130 = 0;
    local_128 = 0;
    local_120 = 0;
    uStack_118 = 0;
    iVar3 = Codec::EncClose2((AvbbcApi_EncOpen *)&local_130,0x20,
                             *(undefined4 *)((long)param_1 + 0x780),0x20,
                             *(undefined4 *)((long)param_1 + 0x79c),&local_160);
    if (iVar3 != 0) {
      local_170._2_2_ = 0x253;
      goto LAB_001d304c;
    }
    local_170._2_2_ = 0x254;
    goto LAB_001d30ac;
  }
  puVar1 = PTR_s_movieRecInfo_00401670;
  if (*(int *)((long)param_1 + 0x7b8) != 0) {
    DeleteUseStreamBufferArea
              ((RingBuffer **)(PTR_s_movieRecInfo_00401670 + 0xa10),
               (RingBuffer **)(PTR_s_movieRecInfo_00401670 + 0xa30));
    cVar2 = DmmMemInfo::FreeDmmMemory(*(int *)(puVar1 + 0x28c));
    if (cVar2 == '\0') {
      uVar4 = 0xc;
      local_130 = 0x302552110;
      local_128 = CONCAT44(local_128._4_4_,*(undefined4 *)(puVar1 + 0x28c));
    }
    else {
      __src = (BufferTable *)(puVar1 + 0x290);
      iVar3 = GetDmmModeId((MovieRecInfo *)puVar1);
      *(int *)(puVar1 + 0x28c) = iVar3;
      cVar2 = DmmMemInfo::AllocDmmMemory(iVar3,&local_170,__src);
      if (cVar2 != '\0') {
        GetStillBufConfig(__src);
        memcpy(param_1,__src,0x760);
        goto LAB_001d3228;
      }
      uVar4 = 0x10;
      local_130 = 0x202562110;
      local_128 = CONCAT44(0x11bd,*(undefined4 *)(puVar1 + 0x28c));
    }
    FUN_001c9f24((AvbbcApi_EncOpen *)&local_130,uVar4);
    FUN_001fe21c(*(undefined8 *)((long)param_1 + 0x7a8),2);
    FUN_001fe0e8(*(undefined8 *)((long)param_1 + 0x7b0),2);
    this = (normalLock *)PTR_s_integRecordMovieLock_00402670;
LAB_001d3078:
    thread::normalLock::unlock(this);
    return;
  }
LAB_001d3228:
  thread::normalLock::unlock((normalLock *)PTR_s_integRecordMovieLock_00402670);
  if (*(char *)((long)param_1 + 0x760) == '\0') {
    memset((AvbbcApi_EncOpen *)&local_130,0,0x98);
    SetEncOpenParam(param_1,(AvbbcApi_EncOpen *)&local_130);
    iVar3 = Codec::EncOpen((AvbbcApi_EncOpen *)&local_130,0x20,
                           *(undefined4 *)((long)param_1 + 0x780),1,0,&local_160);
    if (iVar3 == 0) {
      local_170._2_2_ = 600;
LAB_001d32ec:
      local_169 = 0;
      local_16a = 0;
      local_16b = 0;
      local_16c = 4;
      local_170._0_2_ = 0x2110;
      FUN_001c9f24(&local_170,8);
      local_130 = 0x3025f2110;
      local_128 = CONCAT44(local_128._4_4_,local_150._4_4_);
      FUN_001c9f24((AvbbcApi_EncOpen *)&local_130,0xc);
      return;
    }
    local_170._2_2_ = 599;
  }
  else {
    memset((AvbbcApi_EncOpen *)&local_130,0,0x130);
    SetEncOpenParam(param_1,(AvbbcApi_EncOpen *)&local_130);
    SetEncOpenParam2(param_1,aAStack_98);
    iVar3 = Codec::EncOpen2((AvbbcApi_EncOpen *)&local_130,0x20,
                            *(undefined4 *)((long)param_1 + 0x780),0x20,
                            *(undefined4 *)((long)param_1 + 0x79c),&local_160);
    if (iVar3 == 0) {
      local_170._2_2_ = 0x25a;
      goto LAB_001d32ec;
    }
    local_170._2_2_ = 0x259;
  }
  local_169 = 0;
  local_16a = 0;
  local_16b = 0;
  local_16c = 3;
  local_170._0_2_ = 0x2110;
  local_168 = iVar3;
  FUN_001c9f24(&local_170,0xc);
  FUN_001fe21c(*(undefined8 *)((long)param_1 + 0x7a8),iVar3);
  FUN_001fe0e8(*(undefined8 *)((long)param_1 + 0x7b0),iVar3);
  return;
}

