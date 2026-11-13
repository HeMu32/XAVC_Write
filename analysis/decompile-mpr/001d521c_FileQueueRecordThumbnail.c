// mpr::FileQueueRecordThumbnail
// Ghidra address: 001d521c

/* mpr::FileQueueRecordThumbnail(void*) */

void mpr::FileQueueRecordThumbnail(void *param_1)

{
  uint uVar1;
  undefined1 uVar2;
  int iVar3;
  long lVar4;
  undefined2 local_98;
  undefined2 local_96;
  undefined1 local_94;
  undefined1 local_93;
  undefined1 local_92;
  undefined1 local_91;
  int local_90;
  short local_88 [2];
  undefined1 local_84;
  undefined1 local_83;
  undefined1 local_82;
  undefined1 local_81;
  
  local_83 = 0;
  local_84 = 4;
  local_82 = 0;
  local_88[0] = 0x2110;
  local_81 = 0;
  local_88[1] = 0x880;
  FUN_001c9f24(local_88,8);
  memset(local_88,0,0x88);
  uVar2 = 0;
  if (*(uint *)param_1 < 4) {
    uVar2 = PTR_g_msidconv_00401cd8[(ulong)*(uint *)param_1 * 0x80];
  }
  iVar3 = Fsys_GetDriveInfo(uVar2,local_88);
  if ((iVar3 == 0) && (local_88[0] != 0x40)) {
    RecordThumbnail((FilePathInfo *)((long)param_1 + 0x20),
                    *(record_xavc_thm_t **)((long)param_1 + 0x10),(uchar *)((long)param_1 + 0x652),
                    (uint *)(*(long *)((long)param_1 + 0x18) + 0xc));
  }
  else {
    local_93 = 0;
    local_94 = 3;
    local_92 = 0;
    local_98 = 0x2110;
    local_91 = 0;
    local_96 = 0x881;
    local_90 = iVar3;
    FUN_001c9f24(&local_98,0xc);
    FUN_001fe0e8(*(undefined8 *)((long)param_1 + 0x678),0xb);
  }
  thread::normalLock::lock((normalLock *)PTR_s_integRecordMovieLock_00402670);
  lVar4 = *(long *)((long)param_1 + 0x18);
  uVar1 = (uint)*(byte *)(lVar4 + 3) & (1 << (ulong)(*(uint *)param_1 & 0x1f) ^ 0xffffffffU);
  *(char *)(lVar4 + 3) = (char)uVar1;
  if (uVar1 == 0) {
    ClearUseThnmbnailWorkArea(*(uchar *)(lVar4 + 4));
    *(undefined1 *)(*(long *)((long)param_1 + 0x18) + 4) = 0;
  }
  thread::normalLock::unlock((normalLock *)PTR_s_integRecordMovieLock_00402670);
  local_93 = 0;
  local_92 = 0;
  local_94 = 4;
  local_91 = 0;
  local_98 = 0x2110;
  local_96 = 0x88f;
  FUN_001c9f24(&local_98,8);
  return;
}

