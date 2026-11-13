// mpr::NotifyMovieRecMediaFull
// Ghidra address: 001da264

/* mpr::NotifyMovieRecMediaFull(unsigned int) */

undefined8 mpr::NotifyMovieRecMediaFull(uint param_1)

{
  RecMngInfo *pRVar1;
  byte bVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  char cVar6;
  undefined2 uVar7;
  int iVar8;
  int iVar9;
  MovieError_t *pMVar10;
  long lVar11;
  undefined8 uVar12;
  uint *puVar13;
  ulong uVar14;
  uint uVar15;
  uint *puVar16;
  uint local_20 [4];
  undefined8 local_10;
  undefined8 local_8;
  
  local_10 = 0x301602110;
  local_8 = CONCAT44(local_8._4_4_,param_1);
  FUN_001c9f24(&local_10,0xc);
  thread::normalLock::lock((normalLock *)PTR_s_integRecordMovieLock_00402670);
  if (PTR_s_movieRecInfo_00401670[0x58] == '\0') {
LAB_001da33c:
    cVar6 = '\0';
    uVar15 = 0xffffffff;
  }
  else {
    uVar15 = *(uint *)(PTR_s_movieRecInfo_00401670 + 0x14);
    if (param_1 == uVar15) {
      uVar15 = *(uint *)(PTR_s_movieRecInfo_00401670 + 0x18);
    }
    else if (param_1 != *(uint *)(PTR_s_movieRecInfo_00401670 + 0x18)) goto LAB_001da33c;
    if (uVar15 == 0xffffffff) {
      cVar6 = '\0';
    }
    else {
      cVar6 = FUN_0022c874(uVar15);
      if (cVar6 != '\0') {
        puVar13 = (uint *)(PTR_s_movieRecInfo_00401670 + 0x230);
        for (iVar8 = 0; iVar8 != *(int *)(PTR_s_movieRecInfo_00401670 + 0x240); iVar8 = iVar8 + 1) {
          if (param_1 == *puVar13) goto LAB_001da484;
          puVar13 = puVar13 + 1;
        }
        cVar6 = '\0';
LAB_001da484:
        puVar13 = (uint *)(PTR_s_movieRecInfo_00401670 + 0x260);
        for (iVar8 = 0; iVar8 != *(int *)(PTR_s_movieRecInfo_00401670 + 0x270); iVar8 = iVar8 + 1) {
          if (param_1 == *puVar13) {
            cVar6 = '\0';
            break;
          }
          puVar13 = puVar13 + 1;
        }
        puVar13 = (uint *)(PTR_s_movieRecInfo_00401670 + 0x274);
        for (iVar8 = 0; iVar8 != *(int *)(PTR_s_movieRecInfo_00401670 + 0x284); iVar8 = iVar8 + 1) {
          if (param_1 == *puVar13) goto LAB_001da4e4;
          puVar13 = puVar13 + 1;
        }
        if (cVar6 == '\0') {
LAB_001da4e4:
          thread::normalLock::unlock((normalLock *)PTR_s_integRecordMovieLock_00402670);
          uVar7 = 0x161;
          goto LAB_001da50c;
        }
      }
    }
  }
  puVar5 = PTR_s_thumbnailId_00402fd8;
  puVar4 = PTR_s_recSequenceInfo_004019c0;
  puVar3 = PTR_s_movieRecInfo_00401670;
  local_20[0] = 0;
  local_20[1] = 0;
  local_20[2] = 0;
  local_20[3] = 0;
  if (cVar6 == '\0') {
LAB_001da544:
    puVar3 = PTR_s_movieRecInfo_00401670;
    local_8 = 0;
    if ((PTR_s_movieRecInfo_00401670[100] == '\0') || (PTR_s_movieRecInfo_00401670[0x90] != '\0')) {
      uVar15 = 1;
      local_10 = (ulong)param_1;
    }
    else {
      local_10 = *(ulong *)(PTR_s_movieRecInfo_00401670 + 0x230);
      local_8 = *(undefined8 *)(PTR_s_movieRecInfo_00401670 + 0x238);
      uVar15 = *(uint *)(PTR_s_movieRecInfo_00401670 + 0x240);
    }
    iVar8 = CreateInternalStopSlotIdList
                      ((MovieRecInfo *)PTR_s_movieRecInfo_00401670,(uint *)&local_10,uVar15);
    if (iVar8 == 0) {
      puVar13 = (uint *)(puVar3 + 0x274);
      puVar16 = puVar13;
      for (uVar15 = 0; puVar4 = PTR_s_movieRecInfo_00401670, uVar15 < *(uint *)(puVar3 + 0x284);
          uVar15 = uVar15 + 1) {
        uVar12 = FUN_001fdff4(*(undefined8 *)(puVar3 + 0xa50),*puVar16,0);
        FUN_001fe3bc(uVar12,0);
        FUN_001fe0e8(uVar12,9);
        puVar16 = puVar16 + 1;
      }
      uVar15 = 0;
      uVar14 = 0;
      pRVar1 = (RecMngInfo *)(PTR_s_recSequenceInfo_004019c0 + 8);
      while( true ) {
        puVar3 = PTR_s_markerIdCut_004020c0;
        if (*(uint *)(puVar4 + 0x284) <= uVar15) break;
        lVar11 = SearchRecMngInfoList(pRVar1,*puVar13);
        if (lVar11 != 0) {
          local_20[uVar14] = *(uint *)(lVar11 + 8);
          uVar14 = (ulong)((uint)uVar14 + 1);
        }
        uVar15 = uVar15 + 1;
        puVar13 = puVar13 + 1;
      }
      if (*(uint *)(puVar4 + 0x284) + *(int *)(puVar4 + 0x270) < *(uint *)(puVar4 + 0x240)) {
        EnqueueExecEncCut(puVar4,local_20,uVar14,*PTR_s_markerIdCut_004020c0,0);
        bVar2 = *puVar3;
        cVar6 = bVar2 + 1;
        if (0xe < bVar2) {
          cVar6 = '\0';
        }
        *puVar3 = cVar6;
      }
      else {
        EnqueueExecEncStop((MovieRecInfo *)puVar4,local_20,(uint)uVar14,false);
      }
    }
  }
  else {
    local_8 = 0;
    local_10 = (ulong)uVar15;
    iVar8 = GetFilePathAndClipUmid
                      ((movieRecParam *)(PTR_s_movieRecInfo_00401670 + 0x58),(uint *)&local_10,1,
                       *PTR_s_thumbnailId_00402fd8,(RecSequenceInfo *)PTR_s_recSequenceInfo_004019c0
                       ,(bool)PTR_s_movieRecInfo_00401670[0xa58],true);
    iVar9 = SetThnmbnailControl((uint *)&local_10,1,*puVar5);
    if ((iVar9 != 0) || (iVar8 != 0)) goto LAB_001da544;
    UpdateStartSlotId((MovieRecInfo *)puVar3,param_1,uVar15);
    pMVar10 = (MovieError_t *)FUN_001fdff4(*(undefined8 *)(puVar3 + 0xa50),uVar15,0);
    FUN_001fe3bc(pMVar10,0);
    lVar11 = SearchRecMngInfoList((RecMngInfo *)(puVar4 + 8),param_1);
    puVar4 = PTR_s_markerIdThmReray_004019d0;
    local_20[0] = *(undefined4 *)(lVar11 + 8);
    EnqueueExecEncThm((MovieRecInfo *)puVar3,local_20,1,local_20,1,*puVar5,
                      *PTR_s_markerIdThmReray_004019d0,pMVar10);
    EnqueueExecEventMovieRecMediaChanged((MovieRecInfo *)puVar3,param_1,uVar15,0);
    cVar6 = *puVar5 + 1;
    bVar2 = *puVar4;
    if (0xfd < (byte)*puVar5) {
      cVar6 = '\0';
    }
    *puVar5 = cVar6;
    cVar6 = bVar2 + 1;
    if (0x16 < bVar2) {
      cVar6 = '\x10';
    }
    *puVar4 = cVar6;
  }
  thread::normalLock::unlock((normalLock *)PTR_s_integRecordMovieLock_00402670);
  uVar7 = 0x16f;
LAB_001da50c:
  local_10._0_4_ = CONCAT22(uVar7,0x2110);
  local_10 = (ulong)CONCAT24(4,(uint)local_10);
  FUN_001c9f24(&local_10,8);
  return 0;
}

