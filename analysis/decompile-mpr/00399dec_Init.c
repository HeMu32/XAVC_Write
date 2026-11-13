// sidb::Init
// Ghidra address: 00399dec

/* sidb::Init(sidb::initParam const&) */

undefined8 sidb::Init(initParam *param_1)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined *puVar6;
  undefined *puVar7;
  int iVar8;
  void *pvVar9;
  size_t sVar10;
  long lVar11;
  undefined8 uVar12;
  int *piVar13;
  undefined8 *puVar15;
  uint uVar16;
  initParam *piVar17;
  long lVar18;
  int *piVar19;
  undefined2 local_b8;
  undefined2 local_b6;
  undefined1 local_b4;
  undefined1 local_b3;
  undefined1 local_b2;
  undefined1 local_b1;
  undefined4 local_b0;
  char local_a8 [24];
  undefined2 local_90;
  undefined2 local_8e;
  undefined1 local_8c;
  undefined1 local_8b;
  undefined1 local_8a;
  undefined1 local_89;
  undefined *local_80;
  char local_68 [104];
  int *piVar14;
  
  builtin_strncpy(local_68,"p$\x10",4);
  local_68[4] = '\x04';
  local_68[5] = '\0';
  local_68[6] = '\0';
  local_68[7] = '\0';
  FUN_003896c0(local_68,8);
  local_a8[0x14] = 0;
  local_a8[0x10] = '\0';
  local_a8[0x11] = '\0';
  local_a8[0x12] = '\0';
  local_a8[0x13] = '\0';
  local_68[0x60] = '\0';
  local_68[0x61] = '\0';
  local_68[0x62] = '\0';
  local_68[99] = '\0';
  local_68[0] = '\0';
  local_68[1] = '\0';
  local_68[2] = '\0';
  local_68[3] = '\0';
  local_68[4] = '\0';
  local_68[5] = '\0';
  local_68[6] = '\0';
  local_68[7] = '\0';
  local_68[8] = '\0';
  local_68[9] = '\0';
  local_68[10] = '\0';
  local_68[0xb] = '\0';
  local_68[0xc] = '\0';
  local_68[0xd] = '\0';
  local_68[0xe] = '\0';
  local_68[0xf] = '\0';
  local_68[0x10] = '\0';
  local_68[0x11] = '\0';
  local_68[0x12] = '\0';
  local_68[0x13] = '\0';
  local_68[0x14] = '\0';
  local_68[0x15] = '\0';
  local_68[0x16] = '\0';
  local_68[0x17] = '\0';
  local_68[0x18] = '\0';
  local_68[0x19] = '\0';
  local_68[0x1a] = '\0';
  local_68[0x1b] = '\0';
  local_68[0x1c] = '\0';
  local_68[0x1d] = '\0';
  local_68[0x1e] = '\0';
  local_68[0x1f] = '\0';
  local_68[0x20] = '\0';
  local_68[0x21] = '\0';
  local_68[0x22] = '\0';
  local_68[0x23] = '\0';
  local_68[0x24] = '\0';
  local_68[0x25] = '\0';
  local_68[0x26] = '\0';
  local_68[0x27] = '\0';
  local_68[0x28] = '\0';
  local_68[0x29] = '\0';
  local_68[0x2a] = '\0';
  local_68[0x2b] = '\0';
  local_68[0x2c] = '\0';
  local_68[0x2d] = '\0';
  local_68[0x2e] = '\0';
  local_68[0x2f] = '\0';
  local_68[0x30] = '\0';
  local_68[0x31] = '\0';
  local_68[0x32] = '\0';
  local_68[0x33] = '\0';
  local_68[0x34] = '\0';
  local_68[0x35] = '\0';
  local_68[0x36] = '\0';
  local_68[0x37] = '\0';
  local_68[0x38] = '\0';
  local_68[0x39] = '\0';
  local_68[0x3a] = '\0';
  local_68[0x3b] = '\0';
  local_68[0x3c] = '\0';
  local_68[0x3d] = '\0';
  local_68[0x3e] = '\0';
  local_68[0x3f] = '\0';
  local_68[0x40] = '\0';
  local_68[0x41] = '\0';
  local_68[0x42] = '\0';
  local_68[0x43] = '\0';
  local_68[0x44] = '\0';
  local_68[0x45] = '\0';
  local_68[0x46] = '\0';
  local_68[0x47] = '\0';
  local_68[0x48] = '\0';
  local_68[0x49] = '\0';
  local_68[0x4a] = '\0';
  local_68[0x4b] = '\0';
  local_68[0x4c] = '\0';
  local_68[0x4d] = '\0';
  local_68[0x4e] = '\0';
  local_68[0x4f] = '\0';
  local_68[0x50] = '\0';
  local_68[0x51] = '\0';
  local_68[0x52] = '\0';
  local_68[0x53] = '\0';
  local_68[0x54] = '\0';
  local_68[0x55] = '\0';
  local_68[0x56] = '\0';
  local_68[0x57] = '\0';
  local_68[0x58] = '\0';
  local_68[0x59] = '\0';
  local_68[0x5a] = '\0';
  local_68[0x5b] = '\0';
  local_68[0x5c] = '\0';
  local_68[0x5d] = '\0';
  local_68[0x5e] = '\0';
  local_68[0x5f] = '\0';
  local_a8[0] = '\0';
  local_a8[1] = '\0';
  local_a8[2] = '\0';
  local_a8[3] = '\0';
  local_a8[4] = '\0';
  local_a8[5] = '\0';
  local_a8[6] = '\0';
  local_a8[7] = '\0';
  local_a8[8] = '\0';
  local_a8[9] = '\0';
  local_a8[10] = '\0';
  local_a8[0xb] = '\0';
  local_a8[0xc] = '\0';
  local_a8[0xd] = '\0';
  local_a8[0xe] = '\0';
  local_a8[0xf] = '\0';
  if (*(long *)param_1 != 0) {
    std::
    vector<void(*)(sidb::evtRecordChangedParam&),std::allocator<void(*)(sidb::evtRecordChangedParam&)>>
    ::push_back((vector<void(*)(sidb::evtRecordChangedParam&),std::allocator<void(*)(sidb::evtRecordChangedParam&)>>
                 *)PTR_gp_evtRecordChangedFunc_vec_00402d58,
                (_func_void_evtRecordChangedParam_ptr *)param_1);
  }
  uVar16 = *(uint *)(param_1 + 8);
  if (uVar16 == 0) {
    uVar16 = 5;
    local_8b = 0;
    local_8c = 4;
    local_8a = 0;
    local_90 = 0x2470;
    local_89 = 0;
    local_8e = 0x11;
    FUN_003896c0(&local_90,8);
  }
  puVar4 = PTR_g_msidconv_00402dc8;
  for (piVar17 = param_1; puVar6 = PTR_g_msidconv_00402dc8, piVar17 != param_1 + (ulong)uVar16 * 4;
      piVar17 = piVar17 + 4) {
    mpr::msidconv::Set((msidconv *)puVar4,*(uint *)(piVar17 + 0xc),'\0',local_68,local_a8);
  }
  for (; puVar7 = PTR_g_dbStatus_004029e8, puVar5 = PTR_gp_onmem_00401cf8,
      puVar4 = PTR_gp_db_004017c8, uVar16 < 5; uVar16 = uVar16 + 1) {
    mpr::msidconv::Set((msidconv *)puVar6,0xffff,'\0',local_68,local_a8);
  }
  lVar18 = 0;
  puVar15 = (undefined8 *)(PTR_g_dbFilePath_abi_cxx11__00402068 + 8);
  *(undefined4 *)PTR_g_pseudoMediaId_00401ef0 = *(undefined4 *)(param_1 + 0x20);
  do {
    lVar11 = lVar18 * 4;
    *puVar15 = 0;
    *(undefined8 *)(puVar4 + lVar18 * 8) = 0;
    *(undefined8 *)(puVar5 + lVar18 * 8) = 0;
    *(undefined4 *)(puVar7 + lVar11) = 0;
    *(undefined4 *)(PTR_g_usedRecordNum_00402c18 + lVar11) = 0;
    PTR_gb_protected_00401e10[lVar18] = 0;
    *(undefined4 *)(PTR_g_GetRootSetCancelRequestCount_00401788 + lVar11) = 0;
    *(undefined1 *)puVar15[-1] = 0;
    lVar11 = lVar18 * 0x30;
    lVar18 = lVar18 + 1;
    FUN_00398a78(PTR_g_flushArea_set_00401ae0 + lVar11);
    puVar15 = puVar15 + 4;
  } while (lVar18 != 5);
  iVar8 = Backup_nread(0xa50000,PTR_g_macAddr_004018d0,6);
  puVar4 = PTR_gp_db_004017c8;
  uVar12 = 0x407;
  if (iVar8 == 6) {
    lVar18 = 0;
    piVar1 = (int *)(PTR_g_msidconv_00402dc8 + 0x7c);
    piVar2 = (int *)(PTR_g_msidconv_00402dc8 + 0x27c);
    piVar19 = piVar1;
    while( true ) {
      uVar3 = (uint)lVar18;
      uVar16 = 0;
      piVar13 = piVar1;
      do {
        piVar14 = piVar13 + 0x20;
        if (*piVar13 != 0xffff && *piVar13 != -1) {
          uVar16 = uVar16 + 1;
        }
        piVar13 = piVar14;
      } while (piVar14 != piVar2);
      if (uVar16 <= uVar3) {
        *PTR_sb_threadActive_00401998 = 1;
        mpr::ThreadInfo::GetThreadInfo(0x7c,(__osal_thread_info *)&local_90);
        local_80 = PTR_Thread_00401b48;
        osal_create_waitable_thread((__osal_thread_info *)&local_90,PTR_s_threadHandle_00401828);
        local_b3 = 0;
        local_b2 = 0;
        local_b4 = 3;
        local_b1 = 0;
        local_b8 = 0x2470;
        local_b0 = 0;
        local_b6 = 0x1f;
        FUN_003896c0(&local_b8,0xc);
        return 0;
      }
      lVar11 = lVar18 * 8;
      pvVar9 = *(void **)(puVar4 + lVar11);
      if (pvVar9 != (void *)0x0) {
        free(pvVar9);
        *(undefined8 *)(puVar4 + lVar11) = 0;
      }
      iVar8 = -1;
      if (uVar3 < 4) {
        iVar8 = *piVar19;
      }
      sVar10 = 0x17d00;
      if (iVar8 != *(int *)PTR_g_pseudoMediaId_00401ef0) {
        sVar10 = 0xa00000;
      }
      pvVar9 = malloc(sVar10);
      *(void **)(PTR_gp_db_004017c8 + lVar11) = pvVar9;
      puVar6 = PTR_gp_onmem_00401cf8;
      if (pvVar9 == (void *)0x0) break;
      if (*(void **)(PTR_gp_onmem_00401cf8 + lVar11) != (void *)0x0) {
        free(*(void **)(PTR_gp_onmem_00401cf8 + lVar11));
        *(undefined8 *)(puVar6 + lVar11) = 0;
      }
      iVar8 = -1;
      if (uVar3 < 4) {
        iVar8 = *piVar19;
      }
      if (*(int *)PTR_g_pseudoMediaId_00401ef0 == iVar8) {
        sVar10 = 800;
      }
      else {
        sVar10 = 0x3aa00;
      }
      pvVar9 = malloc(sVar10);
      *(void **)(PTR_gp_onmem_00401cf8 + lVar11) = pvVar9;
      if (pvVar9 == (void *)0x0) break;
      lVar18 = lVar18 + 1;
      piVar19 = piVar19 + 0x20;
    }
    uVar12 = 0x401;
  }
  return uVar12;
}

