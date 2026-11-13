// sidb::Select
// Ghidra address: 0038f550

/* sidb::Select(unsigned int, unsigned int, sidb::recordInfo*, bool) */

int sidb::Select(uint param_1,uint param_2,recordInfo *param_3,bool param_4)

{
  uint uVar1;
  undefined *puVar2;
  byte bVar3;
  char cVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  ulong uVar8;
  undefined8 uVar9;
  ulong uVar10;
  fileStructure *pfVar11;
  byte local_11;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 local_c;
  undefined1 local_b;
  undefined1 local_a;
  undefined1 local_9;
  uint local_8;
  uint uStack_4;
  
  if (param_4) {
    local_b = 0;
    local_c = 2;
    local_a = 0;
    local_10 = 0x2470;
    local_9 = 0;
    local_e = 0x110;
    local_8 = param_1;
    uStack_4 = param_2;
    FUN_003896c0(&local_10,0x10);
  }
  local_11 = 0;
  iVar7 = 0x403;
  if (param_3 != (recordInfo *)0x0) {
    iVar5 = GetDriveLetterFromUniqueId(param_2,(char *)&local_11);
    bVar3 = local_11;
    if (iVar5 == 0) {
      uVar6 = mpr::msidconv::GetSlotIDFromDriveLetter((msidconv *)PTR_g_msidconv_00402dc8,local_11);
      puVar2 = PTR_gp_db_004017c8;
      if (uVar6 != 0xffffffff) {
        uVar10 = (ulong)uVar6;
        iVar7 = 0x409;
        pfVar11 = *(fileStructure **)(PTR_gp_db_004017c8 + uVar10 * 8);
        iVar5 = *(int *)(pfVar11 + 0x30);
        mpr::thread::rwLock::rdlock((rwLock *)PTR_g_rwlock_004023e0);
        if (*(int *)(PTR_g_dbStatus_004029e8 + uVar10 * 4) == 3) {
          uVar6 = param_2 & 0x1ffff;
          iVar7 = 0x402;
          cVar4 = headerStructure::IsTrueBitmap(*(headerStructure **)(puVar2 + uVar10 * 8),uVar6);
          if (cVar4 != '\0') {
            uVar1 = *(uint *)(pfVar11 + 0x34);
            uVar8 = CalcChecksum((uchar *)(pfVar11 + (ulong)(uVar6 * iVar5) + 0x10000),uVar1);
            iVar7 = 0x406;
            if ((uint)*(ushort *)
                       (pfVar11 + (ulong)uVar1 + (ulong)(uVar6 * *(int *)(pfVar11 + 0x30)) + 0x10000
                       ) == ((int)uVar8 + (int)(uVar8 / 0xfff1) * -0xfff1 & 0xffffU)) {
              iVar7 = ConvRecordStructure2RecordInfo
                                (pfVar11,local_11,uVar6,
                                 (recordStructure *)(pfVar11 + (ulong)(uVar6 * iVar5) + 0x10000),
                                 param_3);
              if (iVar7 == 0) {
                *(uint *)(param_3 + 4) = *(uint *)(param_3 + 4) | (uint)local_11 << 0x18;
                *(uint *)(param_3 + 8) = *(uint *)(param_3 + 8) | (uint)local_11 << 0x18;
                *(undefined4 *)(param_3 + 0x61c) =
                     *(undefined4 *)
                      (*(long *)(PTR_gp_onmem_00401cf8 + uVar10 * 8) + (ulong)uVar6 * 4);
              }
            }
          }
        }
        mpr::thread::rwLock::unlock((rwLock *)PTR_g_rwlock_004023e0);
        goto LAB_0038f600;
      }
      uVar9 = 0x10;
      local_c = 2;
      uStack_4 = (uint)bVar3;
      local_e = 0x116;
    }
    else {
      uVar9 = 0xc;
      local_c = 3;
      local_e = 0x115;
    }
    local_9 = 0;
    local_a = 0;
    local_b = 0;
    local_10 = 0x2470;
    local_8 = param_2;
    FUN_003896c0(&local_10,uVar9);
  }
LAB_0038f600:
  if (param_4) {
    local_b = 0;
    local_c = 3;
    local_a = 0;
    local_10 = 0x2470;
    local_9 = 0;
    local_e = 0x11f;
    local_8 = iVar7;
    FUN_003896c0(&local_10,0xc);
  }
  return iVar7;
}

