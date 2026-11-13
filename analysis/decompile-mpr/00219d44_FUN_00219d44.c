// FUN_00219d44
// Ghidra address: 00219d44

void FUN_00219d44(long param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  timespec tStack_38;
  timespec tStack_28;
  undefined2 local_18;
  undefined2 local_16;
  undefined1 local_14;
  undefined1 local_13;
  undefined1 local_12;
  undefined1 local_11;
  undefined4 local_10;
  int iStack_c;
  uint local_8;
  undefined4 uStack_4;
  
  uVar4 = mpr::RingBuffer::GetReadPointer(*(RingBuffer **)(param_1 + 0x20));
  if (*(long *)(param_1 + 0x10) == 0) {
    local_13 = 0;
    local_14 = 3;
    local_12 = 0;
    local_18 = 0x2310;
    local_11 = 0;
    local_16 = 0x330;
    local_10 = *(undefined4 *)(param_1 + 0x2c);
    FUN_0021777c(&local_18,0xc);
    FUN_001fe0e8(*(undefined8 *)(param_1 + 0x48),2);
  }
  else {
    uVar5 = *(undefined8 *)(*(long *)(param_1 + 0x10) + 0x10);
    clock_gettime(0,&tStack_38);
    if (*(char *)(param_1 + 0x30) == '\0') {
      iVar2 = Fsys_Write(uVar5,uVar4,*(undefined4 *)(param_1 + 0x18));
    }
    else {
      iVar2 = Fsys_WriteAndFlush(uVar5);
    }
    clock_gettime(0,&tStack_28);
    if ((long)iVar2 != (ulong)*(uint *)(param_1 + 0x18)) {
      uStack_4 = 0;
      local_13 = 0;
      local_14 = 1;
      local_12 = 0;
      local_18 = 0x2310;
      local_11 = 0;
      local_16 = 0x338;
      local_10 = *(undefined4 *)(param_1 + 0x2c);
      iStack_c = iVar2;
      local_8 = *(uint *)(param_1 + 0x18);
      FUN_0021777c(&local_18,0x18);
      FUN_001fe0e8(*(undefined8 *)(param_1 + 0x48),0xb);
    }
    cVar1 = FUN_001fe4d0(*(undefined8 *)(param_1 + 0x48),&tStack_38,&tStack_28,(long)iVar2);
    if (cVar1 != '\0') {
      local_13 = 0;
      local_14 = 3;
      local_12 = 0;
      local_18 = 0x2310;
      local_11 = 0;
      local_16 = 0x340;
      local_10 = *(undefined4 *)(param_1 + 0x2c);
      FUN_0021777c(&local_18,0xc);
      FUN_001fe0e8(*(undefined8 *)(param_1 + 0x48),2);
    }
    mpr::RingBuffer::FreeMemory(*(RingBuffer **)(param_1 + 0x20),*(uint *)(param_1 + 0x18));
    uVar3 = mpr::RingBuffer::GetUsedSize(*(RingBuffer **)(param_1 + 0x20));
    FUN_00219b80(param_1 + 0x34,uVar3);
  }
  return;
}

