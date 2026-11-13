// mpr::FileQueueStopCmp
// Ghidra address: 001d5390

/* mpr::FileQueueStopCmp(void*) */

void mpr::FileQueueStopCmp(void *param_1)

{
  undefined1 uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  ThnmbnailControl *pTVar5;
  ThnmbnailControl *pTVar6;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined2 local_98;
  undefined2 uStack_96;
  undefined1 uStack_94;
  undefined1 uStack_93;
  undefined1 uStack_92;
  undefined1 uStack_91;
  int local_90;
  int iStack_8c;
  short local_88 [2];
  undefined1 local_84;
  undefined1 local_83;
  undefined1 local_82;
  undefined1 local_81;
  
  local_84 = 4;
  local_83 = 0;
  local_88[0] = 0x2110;
  local_82 = 0;
  local_88[1] = 0x850;
  local_81 = 0;
  FUN_001c9f24(local_88,8);
  memset(local_88,0,0x88);
  uVar1 = 0;
  if (*(uint *)param_1 < 4) {
    uVar1 = PTR_g_msidconv_00401cd8[(ulong)*(uint *)param_1 * 0x80];
  }
  iVar2 = Fsys_GetDriveInfo(uVar1,local_88);
  if ((iVar2 == 0) && (local_88[0] != 0x40)) {
    Fsys_Open((long)param_1 + 0x21c,&local_a8,0xe);
    Fsys_Write(local_a8,*(undefined8 *)((long)param_1 + 0x648),
               *(undefined4 *)((long)param_1 + 0x650));
    Fsys_Close(local_a8);
    iVar2 = FUN_002819f8(*(undefined4 *)param_1,(long)param_1 + 0xd88);
    if (iVar2 != 0) {
      uStack_93 = 0;
      uStack_92 = 0;
      uStack_94 = 2;
      uStack_91 = 0;
      local_98 = 0x2110;
      uStack_96 = 0x862;
      local_90 = *(int *)param_1;
      iStack_8c = iVar2;
      FUN_001c9f24(&local_98,0x10);
    }
    if (*(char *)((long)param_1 + 0x670) != '\0') {
      FUN_00281bb8(*(undefined4 *)param_1,(long)param_1 + 0x678);
      Fsys_Open((long)param_1 + 0x428,&local_a0,0xe);
      Fsys_Write(local_a0,*(undefined8 *)((long)param_1 + 0xd68),
                 *(undefined4 *)((long)param_1 + 0xd70));
      Fsys_Close(local_a0);
      Fsys_Open((long)param_1 + 0x52e,&local_98,0xe);
      Fsys_Write(CONCAT17(uStack_91,
                          CONCAT16(uStack_92,
                                   CONCAT15(uStack_93,
                                            CONCAT14(uStack_94,CONCAT22(uStack_96,local_98))))),
                 *(undefined8 *)((long)param_1 + 0xd78),*(undefined4 *)((long)param_1 + 0xd80));
      Fsys_Close(CONCAT17(uStack_91,
                          CONCAT16(uStack_92,
                                   CONCAT15(uStack_93,
                                            CONCAT14(uStack_94,CONCAT22(uStack_96,local_98))))));
    }
    if ((*(char *)((long)param_1 + 0x148e) != '\0') && (*(char *)((long)param_1 + 0x14a9) != '\0'))
    {
      CopyCubeFile(*(uint *)param_1,(char *)((long)param_1 + 0x148f),
                   (char *)((long)param_1 + 0x14a9));
    }
    if (*(char *)((long)param_1 + 0xd84) != '\0') {
      RecordThumbnail((FilePathInfo *)((long)param_1 + 0x10),
                      *(record_xavc_thm_t **)((long)param_1 + 0x660),
                      (uchar *)((long)param_1 + 0x1584),
                      (uint *)(*(long *)((long)param_1 + 0x668) + 0xc));
    }
    UpdateMovieContentsForSidb(*(uint *)param_1,(movie_stopCmp_t *)((long)param_1 + 0x10));
    if (*(char *)((long)param_1 + 0x15a6) != '\0') {
      uVar3 = 0xffffffff;
      if (*(uint *)param_1 < 4) {
        uVar3 = *(uint *)(PTR_g_msidconv_00401cd8 + (ulong)*(uint *)param_1 * 0x80 + 0x7c);
      }
      iVar2 = sidb::Flush(uVar3);
      if (iVar2 != 0) {
        uStack_93 = 0;
        uStack_92 = 0;
        uStack_94 = 2;
        uStack_91 = 0;
        local_98 = 0x2110;
        uStack_96 = 0x863;
        local_90 = *(int *)param_1;
        iStack_8c = iVar2;
        FUN_001c9f24(&local_98,0x10);
      }
      uVar4 = 0xffffffff;
      if (*(uint *)param_1 < 4) {
        uVar4 = *(undefined4 *)(PTR_g_msidconv_00401cd8 + (ulong)*(uint *)param_1 * 0x80 + 0x7c);
      }
      FUN_0023ae28(uVar4);
    }
    FUN_0022d23c(0);
    FUN_0022bc00(*(undefined4 *)param_1,0);
    FUN_00231b90(0);
  }
  else {
    uStack_93 = 0;
    uStack_94 = 3;
    uStack_92 = 0;
    local_98 = 0x2110;
    uStack_91 = 0;
    uStack_96 = 0x861;
    local_90 = iVar2;
    FUN_001c9f24(&local_98,0xc);
    FUN_001fe0e8(*(undefined8 *)((long)param_1 + 0x15a8),0xb);
  }
  if (*(void **)((long)param_1 + 0x648) != (void *)0x0) {
    operator_delete__(*(void **)((long)param_1 + 0x648));
  }
  if (*(void **)((long)param_1 + 0x658) != (void *)0x0) {
    operator_delete__(*(void **)((long)param_1 + 0x658));
  }
  if (*(char *)((long)param_1 + 0x670) != '\0') {
    if (*(void **)((long)param_1 + 0xd68) != (void *)0x0) {
      operator_delete__(*(void **)((long)param_1 + 0xd68));
    }
    if (*(void **)((long)param_1 + 0xd78) != (void *)0x0) {
      operator_delete__(*(void **)((long)param_1 + 0xd78));
    }
  }
  thread::normalLock::lock((normalLock *)PTR_s_integRecordMovieLock_00402670);
  if (*(char *)((long)param_1 + 0xd84) != '\0') {
    *(byte *)(*(long *)((long)param_1 + 0x668) + 3) =
         *(byte *)(*(long *)((long)param_1 + 0x668) + 3) &
         ((byte)(1 << (ulong)(*(uint *)param_1 & 0x1f)) ^ 0xff);
  }
  pTVar5 = *(ThnmbnailControl **)((long)param_1 + 0x668);
  uVar3 = (uint)(byte)pTVar5[2] & (1 << (ulong)(*(uint *)param_1 & 0x1f) ^ 0xffffffffU);
  pTVar5[2] = SUB41(uVar3,0);
  if (uVar3 == 0) {
    ClearThnmbnailControl(pTVar5);
  }
  if (*(char *)((long)param_1 + 0x15c0) != '\0') {
    pTVar5 = (ThnmbnailControl *)(PTR_s_thnmbnailControl_00401948 + 0x40);
    pTVar6 = (ThnmbnailControl *)PTR_s_thnmbnailControl_00401948;
    do {
      if (*pTVar6 != (ThnmbnailControl)0x0) {
        uVar3 = (uint)(byte)pTVar6[3] & (1 << (ulong)(*(uint *)param_1 & 0x1f) ^ 0xffffffffU);
        pTVar6[3] = SUB41(uVar3,0);
        if (uVar3 == 0) {
          ClearUseThnmbnailWorkArea((uchar)pTVar6[4]);
          pTVar6[4] = (ThnmbnailControl)0x0;
        }
        uVar3 = (uint)(byte)pTVar6[2] & (1 << (ulong)(*(uint *)param_1 & 0x1f) ^ 0xffffffffU);
        pTVar6[2] = SUB41(uVar3,0);
        if (uVar3 == 0) {
          ClearThnmbnailControl(pTVar6);
        }
      }
      pTVar6 = pTVar6 + 0x10;
    } while (pTVar5 != pTVar6);
  }
  thread::normalLock::unlock((normalLock *)PTR_s_integRecordMovieLock_00402670);
  uStack_93 = 0;
  uStack_92 = 0;
  uStack_94 = 4;
  uStack_91 = 0;
  local_98 = 0x2110;
  uStack_96 = 0x85f;
  FUN_001c9f24(&local_98,8);
  return;
}

