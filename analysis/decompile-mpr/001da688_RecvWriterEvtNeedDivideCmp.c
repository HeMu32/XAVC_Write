// mpr::RecvWriterEvtNeedDivideCmp
// Ghidra address: 001da688

/* mpr::RecvWriterEvtNeedDivideCmp(unsigned long, unsigned int, int, void*, unsigned int, void*) */

void mpr::RecvWriterEvtNeedDivideCmp
               (ulong param_1,uint param_2,int param_3,void *param_4,uint param_5,void *param_6)

{
  uint *puVar1;
  byte bVar2;
  byte bVar3;
  bool bVar4;
  undefined *puVar5;
  undefined *puVar6;
  undefined *puVar7;
  undefined *puVar8;
  char cVar9;
  undefined2 uVar10;
  int iVar11;
  int iVar12;
  int *piVar13;
  MovieError_t *pMVar14;
  long lVar15;
  undefined8 uVar16;
  char *pcVar17;
  uint uVar18;
  uint uVar19;
  ulong uVar20;
  uint local_28 [4];
  undefined8 local_18;
  undefined8 local_10;
  int local_8;
  undefined4 uStack_4;
  
  local_10 = CONCAT44(param_2,(int)param_1);
  local_18 = 0x107402110;
  uStack_4 = 0;
  local_8 = param_3;
  FUN_001c9f24(&local_18,0x18,param_3,0x740,param_5);
  puVar7 = PTR_s_thumbnailId_00402fd8;
  puVar6 = PTR_s_recSequenceInfo_004019c0;
  puVar5 = PTR_s_movieRecInfo_00401670;
  if ((PTR_s_movieRecInfo_00401670[100] != '\0') && (PTR_s_recSequenceInfo_004019c0[0x6b28] != '\0')
     ) {
    uVar10 = 0x741;
    goto LAB_001da754;
  }
  piVar13 = (int *)(PTR_s_movieRecInfo_00401670 + 0x230);
  for (uVar18 = 0; uVar18 != *(uint *)(PTR_s_movieRecInfo_00401670 + 0x240); uVar18 = uVar18 + 1) {
    if (*piVar13 == *(int *)param_4) {
      bVar4 = true;
      uVar18 = *(uint *)(PTR_s_movieRecInfo_00401670 + 0x240);
      goto LAB_001da784;
    }
    piVar13 = piVar13 + 1;
  }
  bVar4 = false;
LAB_001da784:
  piVar13 = (int *)(PTR_s_movieRecInfo_00401670 + 0x260);
  for (iVar11 = 0; iVar11 != *(int *)(PTR_s_movieRecInfo_00401670 + 0x270); iVar11 = iVar11 + 1) {
    if (*piVar13 == *(int *)param_4) {
      bVar4 = false;
      break;
    }
    piVar13 = piVar13 + 1;
  }
  piVar13 = (int *)(PTR_s_movieRecInfo_00401670 + 0x274);
  for (iVar11 = 0; iVar11 != *(int *)(PTR_s_movieRecInfo_00401670 + 0x284); iVar11 = iVar11 + 1) {
    if (*piVar13 == *(int *)param_4) goto LAB_001da7f8;
    piVar13 = piVar13 + 1;
  }
  if (!bVar4) {
LAB_001da7f8:
    uVar10 = 0x742;
    goto LAB_001da754;
  }
  puVar1 = (uint *)(PTR_s_movieRecInfo_00401670 + 0x230);
  iVar11 = GetFilePathAndClipUmid
                     ((movieRecParam *)(PTR_s_movieRecInfo_00401670 + 0x58),puVar1,uVar18,
                      *PTR_s_thumbnailId_00402fd8,(RecSequenceInfo *)PTR_s_recSequenceInfo_004019c0,
                      (bool)PTR_s_movieRecInfo_00401670[0xa58],false);
  if (iVar11 == 10) {
    local_28[0] = 0;
    local_28[1] = 0;
    local_28[2] = 0;
    local_28[3] = 0;
    if (puVar5[0x58] != '\0') {
      uVar18 = *(uint *)(puVar5 + 0x14);
      if (uVar18 == *(uint *)param_4) {
        uVar18 = *(uint *)(puVar5 + 0x18);
      }
      else if (*(uint *)param_4 != *(uint *)(puVar5 + 0x18)) goto LAB_001daa00;
      if ((uVar18 != 0xffffffff) &&
         (cVar9 = FUN_0022c874(uVar18), puVar7 = PTR_s_thumbnailId_00402fd8,
         puVar6 = PTR_s_recSequenceInfo_004019c0, puVar5 = PTR_s_movieRecInfo_00401670,
         cVar9 != '\0')) {
        local_10 = 0;
        local_18 = (ulong)uVar18;
        iVar11 = GetFilePathAndClipUmid
                           ((movieRecParam *)(PTR_s_movieRecInfo_00401670 + 0x58),(uint *)&local_18,
                            1,*PTR_s_thumbnailId_00402fd8,
                            (RecSequenceInfo *)PTR_s_recSequenceInfo_004019c0,
                            (bool)PTR_s_movieRecInfo_00401670[0xa58],true);
        iVar12 = SetThnmbnailControl((uint *)&local_18,1,*puVar7);
        if ((iVar12 == 0) && (iVar11 == 0)) {
          local_18 = 0x407432110;
          FUN_001c9f24(&local_18,8);
          UpdateStartSlotId((MovieRecInfo *)puVar5,*(uint *)param_4,uVar18);
          pMVar14 = (MovieError_t *)FUN_001fdff4(*(undefined8 *)(puVar5 + 0xa50),uVar18,0);
          FUN_001fe3bc(pMVar14,0);
          lVar15 = SearchRecMngInfoList((RecMngInfo *)(puVar6 + 8),*(uint *)param_4);
          puVar6 = PTR_s_markerIdThmReray_004019d0;
          local_28[0] = *(undefined4 *)(lVar15 + 8);
          EnqueueExecEncThm((MovieRecInfo *)puVar5,local_28,1,local_28,1,*puVar7,
                            *PTR_s_markerIdThmReray_004019d0,pMVar14);
          EnqueueExecEventMovieRecMediaChanged((MovieRecInfo *)puVar5,*(uint *)param_4,uVar18,0);
          cVar9 = *puVar7 + 1;
          bVar2 = *puVar6;
          if (0xfd < (byte)*puVar7) {
            cVar9 = '\0';
          }
          *puVar7 = cVar9;
          cVar9 = bVar2 + 1;
          if (0x16 < bVar2) {
            cVar9 = '\x10';
          }
          *puVar6 = cVar9;
          goto LAB_001da9d0;
        }
      }
    }
LAB_001daa00:
    local_18 = 0x407442110;
    FUN_001c9f24(&local_18,8);
    uVar16 = FUN_001fdff4(*(undefined8 *)(PTR_s_movieRecInfo_00401670 + 0xa50),
                          *(undefined4 *)param_4,0);
    iVar11 = 10;
LAB_001daa48:
    FUN_001fe0e8(uVar16,iVar11);
  }
  else {
    if (iVar11 != 0) {
      uVar10 = 0x745;
LAB_001daa74:
      local_18._0_4_ = CONCAT22(uVar10,0x2110);
      local_18 = (ulong)CONCAT24(3,(uint)local_18);
      local_10 = CONCAT44(local_10._4_4_,iVar11);
      FUN_001c9f24(&local_18,0xc);
      uVar16 = FUN_001fdff4(*(undefined8 *)(puVar5 + 0xa50),*(undefined4 *)param_4,0);
      goto LAB_001daa48;
    }
    iVar11 = SetThnmbnailControl(puVar1,*(uint *)(puVar5 + 0x240),*puVar7);
    puVar8 = PTR_s_thumbnailId_00402fd8;
    puVar7 = PTR_s_markerIdThmDivide_004022d8;
    if (iVar11 != 0) {
      uVar10 = 0x746;
      goto LAB_001daa74;
    }
    uVar20 = 0;
    local_18 = 0;
    local_10 = 0;
    pcVar17 = puVar6 + 8;
    uVar18 = *(uint *)puVar6;
    do {
      if (*pcVar17 != '\0') {
        *(uint *)((long)&local_18 + uVar20 * 4) = *(uint *)(pcVar17 + 8);
        uVar19 = (int)uVar20 + 1;
        uVar20 = (ulong)uVar19;
        if (uVar18 <= uVar19) break;
      }
      uVar19 = (uint)uVar20;
      pcVar17 = pcVar17 + 0x1ac8;
    } while (pcVar17 != puVar6 + 0x6b28);
    EnqueueExecEncThm((MovieRecInfo *)PTR_s_movieRecInfo_00401670,(uint *)&local_18,uVar19,
                      (uint *)&local_18,uVar19,*PTR_s_thumbnailId_00402fd8,
                      *PTR_s_markerIdThmDivide_004022d8,(MovieError_t *)0x0);
    bVar2 = *puVar8;
    cVar9 = bVar2 + 1;
    bVar3 = *puVar7;
    if (0xfd < bVar2) {
      cVar9 = '\0';
    }
    *puVar8 = cVar9;
    cVar9 = bVar3 + 1;
    if (0x1e < bVar3) {
      cVar9 = '\x18';
    }
    *puVar7 = cVar9;
  }
LAB_001da9d0:
  uVar10 = 0x74f;
LAB_001da754:
  local_18._0_4_ = CONCAT22(uVar10,0x2110);
  local_18 = CONCAT44(4,(uint)local_18);
  FUN_001c9f24(&local_18,8);
  return;
}

