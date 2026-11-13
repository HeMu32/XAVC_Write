// FUN_00215df8
// Ghidra address: 00215df8

void FUN_00215df8(uint *param_1)

{
  AudioSampleInfo *pAVar1;
  undefined8 *puVar2;
  long lVar3;
  long lVar4;
  undefined4 *puVar5;
  uint *puVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  undefined2 uVar10;
  int iVar11;
  undefined1 *puVar12;
  void *pvVar13;
  uint *puVar14;
  long lVar15;
  long lVar16;
  uint uVar17;
  undefined8 uVar18;
  undefined8 *puVar19;
  uint *puVar20;
  XavcOutBandParamDataBuffer *pXVar21;
  BaseList *pBVar22;
  OutBandParamInfo *pOVar23;
  uint *puVar24;
  void *pvVar25;
  RingBuffer *pRVar26;
  BaseList *pBVar27;
  BaseList *pBVar28;
  BaseList *pBVar29;
  undefined8 uVar30;
  signalLock *this;
  uint *puVar31;
  ulong uVar32;
  long lVar33;
  undefined8 uVar34;
  long *plVar35;
  libXavcMp4 *plVar36;
  undefined1 *puVar37;
  undefined1 uVar38;
  uint uVar39;
  long *local_138;
  undefined4 local_128;
  int local_124;
  int local_120;
  uint local_11c;
  uint local_118;
  uint local_114;
  int local_110 [2];
  void *local_108;
  undefined4 local_100;
  uint local_fc;
  int local_f8 [2];
  uint *local_f0;
  uint local_e8;
  AudioSampleInfo local_e4 [4];
  int local_e0 [2];
  long local_d8;
  undefined1 auStack_d0 [72];
  short local_88 [8];
  long lStack_78;
  undefined1 auStack_70 [112];
  
  lVar3 = *(long *)(param_1 + 10);
  puVar5 = *(undefined4 **)(param_1 + 0xc);
  puVar20 = *(uint **)(param_1 + 0xe);
  pXVar21 = *(XavcOutBandParamDataBuffer **)(param_1 + 0x10);
  uVar38 = 0;
  pBVar22 = *(BaseList **)(param_1 + 0x12);
  pOVar23 = *(OutBandParamInfo **)(param_1 + 0x14);
  plVar36 = *(libXavcMp4 **)(param_1 + 4);
  uVar7 = param_1[0x16];
  lVar4 = *(long *)(param_1 + 6);
  puVar6 = *(uint **)(param_1 + 8);
  puVar24 = *(uint **)(param_1 + 0x18);
  pvVar25 = *(void **)(param_1 + 0x1a);
  pRVar26 = *(RingBuffer **)(param_1 + 0x1c);
  pBVar27 = *(BaseList **)(param_1 + 0x1e);
  puVar37 = *(undefined1 **)(param_1 + 0x24);
  pBVar28 = *(BaseList **)(param_1 + 0x20);
  uVar34 = *(undefined8 *)(param_1 + 0x2a);
  pBVar29 = *(BaseList **)(param_1 + 0x22);
  uVar30 = *(undefined8 *)(param_1 + 0x26);
  this = *(signalLock **)(param_1 + 0x28);
  if (*param_1 < 4) {
    uVar38 = PTR_g_msidconv_00401cd8[(ulong)*param_1 * 0x80];
  }
  memset(local_88,0,0x88);
  local_e0[0] = Fsys_GetDriveInfo(uVar38,local_88);
  if ((local_e0[0] == 0) && (local_88[0] != 0x40)) {
    local_118 = 0;
    local_114 = 0;
    local_110[0] = 0;
    local_108 = (void *)0x0;
    local_108 = operator_new__(0x3c00);
    puVar12 = auStack_d0;
    do {
      *(undefined4 *)(puVar12 + -0x10) = 0;
      *(undefined8 *)(puVar12 + -8) = 0;
      *(undefined4 *)(puVar12 + -0x18) = 1;
      *(undefined4 *)(puVar12 + -0x14) = 0;
      puVar12 = puVar12 + 0x18;
    } while (auStack_70 != puVar12);
    local_138 = &local_d8;
    for (plVar35 = local_138; plVar35 != &lStack_78; plVar35 = plVar35 + 3) {
      pvVar13 = operator_new__(0x1e00);
      *plVar35 = (long)pvVar13;
      FUN_0020b11c(plVar35 + -2);
    }
    local_fc = 0;
    local_100 = 1;
    local_f8[0] = 0;
    local_f0 = (uint *)0x0;
    local_f0 = operator_new__(0x1680);
    iVar11 = FUN_00328170(plVar36,lVar4);
    if (iVar11 == 0) {
      if (*(char *)(lVar4 + 0x91) == '\0') {
        *puVar37 = 1;
      }
      do {
        local_118 = 0;
        local_114 = 0;
        local_110[0] = 0;
        memset(local_108,0,0x3c00);
        iVar11 = FUN_00326d20(plVar36,(VideoSampleInfo *)&local_118,&local_114,local_110,local_108,0
                             );
        if (iVar11 != 0) {
          uVar10 = 0x1a05;
          goto LAB_00216024;
        }
        puVar14 = (uint *)((long)local_108 + 0x38);
        uVar17 = 0;
        while (puVar14 != (uint *)((long)local_108 + (ulong)local_114 * 0x40 + 0x38)) {
          puVar31 = puVar14 + 0x10;
          uVar39 = *puVar14;
          puVar14 = puVar31;
          if (uVar17 < uVar39) {
            uVar17 = uVar39;
          }
        }
        do {
          for (uVar39 = 0; uVar39 < *(byte *)(lVar4 + 0x9f); uVar39 = uVar39 + 1 & 0xff) {
            lVar33 = (ulong)uVar39 * 0x18;
            pAVar1 = (AudioSampleInfo *)&local_e8 + lVar33;
            FUN_0020b11c(pAVar1);
            iVar11 = FUN_00328bf0(plVar36,uVar17,uVar39,pAVar1,
                                  (AudioSampleInfo *)&local_e8 + lVar33 + 4,
                                  (AudioSampleInfo *)&local_e8 + lVar33 + 8,
                                  (&local_d8)[(long)(int)uVar39 * 3]);
            if (iVar11 != 0) {
              uVar18 = 0x10;
              local_124 = 2;
              local_128 = 0x1a062311;
              local_11c = uVar39;
              goto LAB_002161a0;
            }
          }
        } while ((local_e8 & 0xb) == 0);
        local_100 = 1;
        local_fc = 0;
        local_f8[0] = 0;
        memset(local_f0,0,0x1680);
        iVar11 = FUN_0032843c(plVar36,uVar17,(MetadataSampleInfo *)&local_100,&local_fc,local_f8,
                              local_f0);
        if (iVar11 != 0) {
          uVar10 = 0x1a07;
          goto LAB_00216024;
        }
        if (local_fc != 0) {
          puVar14 = local_f0;
          do {
            if (puVar14 == local_f0 + (ulong)local_fc * 6) goto LAB_002162ac;
            uVar17 = *puVar14;
            puVar14 = puVar14 + 6;
          } while (uVar17 < 0x10000);
          local_fc = 0;
          local_f8[0] = 0;
        }
LAB_002162ac:
        iVar11 = XavcsMovieReader::_make_outband_param_info
                           (plVar36,(VideoSampleInfo *)&local_118,pXVar21,pBVar22,pOVar23,uVar7,
                            puVar24);
        if (iVar11 != 0) {
          uVar10 = 0x1a08;
          goto LAB_00216024;
        }
        iVar11 = XavcsMovieReader::_read_stream_data
                           (pvVar25,*(uchar *)(lVar4 + 0x9f),(VideoSampleInfo *)&local_118,
                            (AudioSampleInfo *)&local_e8,(MetadataSampleInfo *)&local_100,puVar20,
                            pRVar26,pBVar27,pBVar28,pBVar29);
        if (iVar11 != 0) {
          uVar10 = 0x1a09;
          goto LAB_00216024;
        }
        uVar39 = puVar6[1];
        uVar17 = uVar39 + local_114;
        if (0xef < uVar17) {
          iVar11 = 5;
          goto LAB_002161b4;
        }
        *puVar6 = local_118;
        puVar6[1] = uVar17;
        puVar6[2] = puVar6[2] + local_110[0];
        uVar32 = 0;
        while (uVar17 = (uint)uVar32, uVar17 < local_114) {
          puVar19 = (undefined8 *)(*(long *)(puVar6 + 4) + (ulong)(uVar17 + uVar39) * 0x40);
          puVar2 = (undefined8 *)((long)local_108 + uVar32 * 0x40);
          uVar18 = puVar2[1];
          *puVar19 = *puVar2;
          puVar19[1] = uVar18;
          uVar18 = puVar2[3];
          puVar19[2] = puVar2[2];
          puVar19[3] = uVar18;
          uVar18 = puVar2[5];
          puVar19[4] = puVar2[4];
          puVar19[5] = uVar18;
          uVar18 = puVar2[7];
          puVar19[6] = puVar2[6];
          puVar19[7] = uVar18;
          uVar32 = (ulong)(uVar17 + 1);
        }
        for (uVar17 = 0; uVar17 < *(byte *)(lVar4 + 0x9f); uVar17 = uVar17 + 1 & 0xff) {
          lVar33 = lVar3 + (ulong)uVar17 * 0x18;
          iVar8 = *(int *)(lVar3 + 4);
          lVar15 = (long)(int)uVar17;
          lVar16 = lVar15 * 0x18;
          *(undefined4 *)(lVar3 + (ulong)uVar17 * 0x18) =
               *(undefined4 *)((AudioSampleInfo *)&local_e8 + lVar16);
          iVar9 = local_e0[lVar15 * 6];
          *(int *)(lVar33 + 4) = *(int *)(lVar33 + 4) + *(int *)(local_e4 + lVar16);
          *(int *)(lVar33 + 8) = *(int *)(lVar33 + 8) + iVar9;
          uVar32 = 0;
          while (uVar39 = (uint)uVar32, uVar39 < *(uint *)(local_e4 + lVar16)) {
            puVar19 = (undefined8 *)((&local_d8)[lVar15 * 3] + uVar32 * 0x20);
            puVar2 = (undefined8 *)(*(long *)(lVar33 + 0x10) + (ulong)(uVar39 + iVar8) * 0x20);
            uVar18 = puVar19[1];
            *puVar2 = *puVar19;
            puVar2[1] = uVar18;
            uVar18 = puVar19[3];
            puVar2[2] = puVar19[2];
            puVar2[3] = uVar18;
            uVar32 = (ulong)(uVar39 + 1);
          }
        }
        iVar8 = puVar5[1];
        *puVar5 = local_100;
        puVar5[1] = local_fc + iVar8;
        puVar5[2] = puVar5[2] + local_f8[0];
        for (uVar17 = 0; uVar17 < local_fc; uVar17 = uVar17 + 1) {
          puVar19 = (undefined8 *)(*(long *)(puVar5 + 4) + (ulong)(uVar17 + iVar8) * 0x18);
          puVar14 = local_f0 + (ulong)uVar17 * 6;
          uVar18 = *(undefined8 *)(puVar14 + 2);
          *puVar19 = *(undefined8 *)puVar14;
          puVar19[1] = uVar18;
          puVar19[2] = *(undefined8 *)(puVar14 + 4);
        }
        if ((((local_118 & 1) != 0) && ((local_e8 & 1) != 0)) || ((local_118 >> 4 & 1) != 0))
        goto LAB_002161b4;
      } while( true );
    }
    uVar10 = 0x1a04;
LAB_00216024:
    local_124 = 3;
    local_128 = CONCAT22(uVar10,0x2311);
    uVar18 = 0xc;
LAB_002161a0:
    local_120 = iVar11;
    FUN_0020aff4(&local_128,uVar18);
    FUN_001fe0e8(uVar34,0xb);
LAB_002161b4:
    if (local_108 != (void *)0x0) {
      operator_delete__(local_108);
    }
    for (; local_138 != plVar35; local_138 = local_138 + 3) {
      if ((void *)*local_138 != (void *)0x0) {
        operator_delete__((void *)*local_138);
      }
    }
    if (local_f0 != (uint *)0x0) {
      operator_delete__(local_f0);
    }
    mpr::thread::signalLock::lock(this);
    local_128 = 0x40000004;
    local_124 = iVar11;
    FUN_00212de8(uVar30,&local_128);
    mpr::thread::signalLock::signal(this);
    mpr::thread::signalLock::unlock(this);
  }
  else {
    local_e4[1] = (AudioSampleInfo)0x0;
    local_e4[0] = (AudioSampleInfo)0x3;
    local_e4[2] = (AudioSampleInfo)0x0;
    local_e4[3] = (AudioSampleInfo)0x0;
    local_e8 = 0x1a022311;
    FUN_0020aff4(&local_e8,0xc);
    FUN_001fe0e8(uVar34,0xb);
  }
  return;
}

