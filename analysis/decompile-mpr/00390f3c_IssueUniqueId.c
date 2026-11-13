// sidb::IssueUniqueId
// Ghidra address: 00390f3c

/* sidb::IssueUniqueId(unsigned int, unsigned int*, bool) */

undefined4 sidb::IssueUniqueId(uint param_1,uint *param_2,bool param_3)

{
  normalLock *this;
  uint uVar1;
  byte bVar2;
  undefined *puVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  ulong uVar7;
  headerStructure *this_00;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 local_c;
  undefined1 local_b;
  undefined1 local_a;
  undefined1 local_9;
  uint local_8;
  uint uStack_4;
  
  if (param_3) {
    local_b = 0;
    local_c = 3;
    local_a = 0;
    local_10 = 0x2470;
    local_9 = 0;
    local_e = 0xd0;
    local_8 = param_1;
    FUN_003896c0(&local_10,0xc);
  }
  osal_thread_id();
  puVar3 = PTR_g_msidconv_00402dc8;
  uVar6 = 0x403;
  uVar4 = mpr::msidconv::GetSlotID((msidconv *)PTR_g_msidconv_00402dc8,param_1);
  if (param_2 != (uint *)0x0 && uVar4 != 0xffffffff) {
    if (uVar4 < 4) {
      uVar7 = (ulong)uVar4;
      bVar2 = puVar3[uVar7 * 0x80];
      if (bVar2 != 0) {
        uVar6 = 0x409;
        this = (normalLock *)(PTR_g_cancellock_00401410 + uVar7 * 0x40);
        this_00 = *(headerStructure **)(PTR_gp_db_004017c8 + uVar7 * 8);
        mpr::thread::normalLock::lock(this);
        *(int *)(PTR_g_GetRootSetCancelRequestCount_00401788 + uVar7 * 4) =
             *(int *)(PTR_g_GetRootSetCancelRequestCount_00401788 + uVar7 * 4) + 1;
        mpr::thread::normalLock::unlock(this);
        mpr::thread::rwLock::wrlock((rwLock *)PTR_g_rwlock_004023e0);
        if ((*(int *)(PTR_g_dbStatus_004029e8 + uVar7 * 4) - 2U < 2) &&
           (uVar6 = 0x408, PTR_gb_protected_00401e10[uVar7] == '\0')) {
          uVar6 = 0x402;
          uVar1 = *(uint *)(this_00 + 0x7c44);
          uVar5 = headerStructure::FindNextIndex(this_00,uVar1 + 1);
          if (uVar5 != 0xffffffff) {
            if (uVar5 < uVar1) {
              uVar1 = *(int *)(this_00 + 0x7c40) + 1;
              if ((uVar1 & 0x7fff) == 0) {
                uVar1 = 1;
              }
              *(uint *)(this_00 + 0x7c40) = uVar1;
            }
            *(uint *)(this_00 + 0x7c44) = uVar5;
            headerStructure::SetBitmap(this_00,uVar5);
            uVar7 = (ulong)uVar4;
            *(int *)(PTR_g_usedRecordNum_00402c18 + uVar7 * 4) =
                 *(int *)(PTR_g_usedRecordNum_00402c18 + uVar7 * 4) + 1;
            *(byte *)(*(long *)(PTR_gp_onmem_00401cf8 + uVar7 * 8) + (ulong)uVar5 * 4) =
                 *(byte *)(*(long *)(PTR_gp_onmem_00401cf8 + uVar7 * 8) + (ulong)uVar5 * 4) | 1;
            uVar7 = CalcChecksum((uchar *)(this_00 + ((ulong)(uVar5 >> 0xd) + 0x10) * 0x400),0x400);
            *(int *)(this_00 + ((ulong)(uVar5 >> 0xd) + 0x1f00) * 4) =
                 (int)uVar7 + (int)(uVar7 / 0xfffffffb) * 5;
            uVar7 = CalcChecksum((uchar *)(this_00 + 0x7c40),0x3bc);
            *(int *)(this_00 + 0x7ffc) = (int)uVar7 + (int)(uVar7 / 0xfffffffb) * 5;
            SetFlushAreaHeader(uVar4);
            uVar5 = uVar5 | *(int *)(this_00 + 0x7c40) << 0x11;
            uVar6 = 0;
            if (uVar5 == 0) {
              uVar6 = 0x407;
            }
            *param_2 = uVar5 | (uint)bVar2 << 0x18;
          }
        }
        mpr::thread::rwLock::unlock((rwLock *)PTR_g_rwlock_004023e0);
        mpr::thread::normalLock::lock(this);
        *(int *)(PTR_g_GetRootSetCancelRequestCount_00401788 + (ulong)uVar4 * 4) =
             *(int *)(PTR_g_GetRootSetCancelRequestCount_00401788 + (ulong)uVar4 * 4) + -1;
        mpr::thread::normalLock::unlock(this);
        goto LAB_00391018;
      }
    }
    local_b = 0;
    uVar6 = 0x407;
    local_c = 3;
    local_a = 0;
    local_10 = 0x2470;
    local_9 = 0;
    local_e = 0xd6;
    local_8 = 0;
    FUN_003896c0(&local_10,0xc);
  }
LAB_00391018:
  if (param_3) {
    local_b = 0;
    local_c = 2;
    local_a = 0;
    local_10 = 0x2470;
    local_9 = 0;
    local_e = 0xdf;
    uStack_4 = *param_2;
    local_8 = uVar6;
    FUN_003896c0(&local_10,0x10);
  }
  return uVar6;
}

