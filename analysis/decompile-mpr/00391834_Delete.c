// sidb::Delete
// Ghidra address: 00391834

/* sidb::Delete(unsigned int, unsigned int, bool, bool) */

undefined4 sidb::Delete(uint param_1,uint param_2,bool param_3,bool param_4)

{
  normalLock *this;
  headerStructure *__s;
  byte bVar1;
  uint uVar2;
  headerStructure hVar3;
  char cVar4;
  int iVar5;
  uint uVar6;
  undefined8 uVar7;
  uint uVar8;
  uint uVar9;
  headerStructure *this_00;
  ulong uVar10;
  undefined4 uVar11;
  ulong uVar12;
  uint local_3c;
  LocalTime aLStack_38 [16];
  undefined2 local_28;
  undefined2 local_26;
  undefined1 local_24;
  undefined1 local_23;
  undefined1 local_22;
  undefined1 local_21;
  uint local_20;
  undefined2 local_18;
  undefined2 local_16;
  uint local_14;
  uint local_10;
  uint local_c;
  uint local_4;
  
  if (param_3) {
    local_14 = 2;
    local_18 = 0x2470;
    local_16 = 0x120;
    local_10 = param_1;
    local_c = param_2;
    FUN_003896c0((evtRecordChangedParam *)&local_18,0x10);
  }
  osal_thread_id();
  local_3c = 0xffffffff;
  evtRecordChangedParam::evtRecordChangedParam((evtRecordChangedParam *)&local_18);
  iVar5 = GetMediaIdFromUniqueId(param_2,&local_3c);
  if (iVar5 == 0) {
    uVar6 = mpr::msidconv::GetSlotID((msidconv *)PTR_g_msidconv_00402dc8,local_3c);
    uVar10 = (ulong)uVar6;
    if (uVar6 != 0xffffffff) {
      uVar12 = (ulong)uVar6;
      this_00 = *(headerStructure **)(PTR_gp_db_004017c8 + uVar12 * 8);
      this = (normalLock *)(PTR_g_cancellock_00401410 + uVar12 * 0x40);
      iVar5 = *(int *)(this_00 + 0x30);
      mpr::thread::normalLock::lock(this);
      *(int *)(PTR_g_GetRootSetCancelRequestCount_00401788 + uVar12 * 4) =
           *(int *)(PTR_g_GetRootSetCancelRequestCount_00401788 + uVar12 * 4) + 1;
      mpr::thread::normalLock::unlock(this);
      mpr::thread::rwLock::wrlock((rwLock *)PTR_g_rwlock_004023e0);
      if (*(int *)(PTR_g_dbStatus_004029e8 + uVar12 * 4) == 3) {
        if (PTR_gb_protected_00401e10[uVar12] == '\0') {
          uVar2 = param_2 & 0x1ffff;
          cVar4 = headerStructure::IsTrueBitmap(this_00,uVar2);
          if (cVar4 == '\0') {
LAB_00391a08:
            uVar11 = 0x403;
          }
          else {
            __s = this_00 + (ulong)(uVar2 * iVar5) + 0x10000;
            mpr::time::GetLTM(aLStack_38);
            uVar7 = ConvDefStructLocalTime2SiDBUInt64(aLStack_38);
            *(undefined8 *)(this_00 + 0x8018) = uVar7;
            uVar12 = CalcChecksum((uchar *)(this_00 + 0x8000),0x3ffc);
            *(int *)(this_00 + 0xbffc) = (int)uVar12 + (int)(uVar12 / 0xfffffffb) * 5;
            hVar3 = __s[7];
            if (param_4) {
              local_14 = local_3c;
              local_10 = 2;
              local_c = ContentTypeInternal2ContentType((byte)hVar3 & 0xf);
              local_4 = param_2;
            }
            bVar1 = (byte)hVar3 & 0xf;
            if (bVar1 == 1) {
              uVar8 = (uint)*(ushort *)(__s + 0x4a) | ((byte)__s[0x4c] >> 5 & 1) << 0x10;
              uVar9 = (uint)*(ushort *)(__s + 0x58) | ((byte)__s[0x5a] >> 3 & 1) << 0x10;
              if (uVar8 != 0) {
LAB_00391af8:
                DecrementArrayBinaryRecordRefCount(uVar6,(fileStructure *)this_00,uVar8);
              }
              if (uVar9 != 0) {
                DecrementArrayBinaryRecordRefCount(uVar6,(fileStructure *)this_00,uVar9);
              }
            }
            else {
              if (1 < (byte)(bVar1 - 2)) goto LAB_00391a08;
              uVar8 = (uint)*(ushort *)(__s + 0x5a) | ((byte)__s[0x5c] >> 5 & 1) << 0x10;
              if (uVar8 != 0) {
                uVar9 = 0;
                goto LAB_00391af8;
              }
            }
            DecrementContentNum(uVar10,(byte)__s[7] & 0xf);
            memset(__s,0,(ulong)*(uint *)(this_00 + 0x30));
            *(ulong *)(this_00 + (ulong)(uVar2 >> 6) * 8 + 0x4000) =
                 *(ulong *)(this_00 + (ulong)(uVar2 >> 6) * 8 + 0x4000) &
                 (1L << (param_2 & 0x3f) ^ 0xffffffffffffffffU);
            *(int *)(PTR_g_usedRecordNum_00402c18 + (ulong)uVar6 * 4) =
                 *(int *)(PTR_g_usedRecordNum_00402c18 + (ulong)uVar6 * 4) + -1;
            uVar12 = CalcChecksum((uchar *)(this_00 + ((ulong)(uVar2 >> 0xd) + 0x10) * 0x400),0x400)
            ;
            *(int *)(this_00 + ((ulong)(uVar2 >> 0xd) + 0x1f00) * 4) =
                 (int)uVar12 + (int)(uVar12 / 0xfffffffb) * 5;
            uVar12 = CalcChecksum((uchar *)(this_00 + 0x7c40),0x3bc);
            *(int *)(this_00 + 0x7ffc) = (int)uVar12 + (int)(uVar12 / 0xfffffffb) * 5;
            SetFlushAreaHeader(uVar6);
            SetFlushArea(uVar6,uVar2);
            uVar11 = 0;
            if (param_4) {
              IssueCallbackRecordChanged((evtRecordChangedParam *)&local_18);
            }
          }
        }
        else {
          uVar11 = 0x408;
        }
      }
      else {
        uVar11 = 0x409;
      }
      mpr::thread::rwLock::unlock((rwLock *)PTR_g_rwlock_004023e0);
      mpr::thread::normalLock::lock(this);
      *(int *)(PTR_g_GetRootSetCancelRequestCount_00401788 + uVar10 * 4) =
           *(int *)(PTR_g_GetRootSetCancelRequestCount_00401788 + uVar10 * 4) + -1;
      mpr::thread::normalLock::unlock(this);
      goto LAB_003918fc;
    }
  }
  else {
    local_23 = 0;
    local_24 = 3;
    local_22 = 0;
    local_28 = 0x2470;
    local_21 = 0;
    local_26 = 0x126;
    local_20 = param_2;
    FUN_003896c0(&local_28,0xc);
  }
  uVar11 = 0x403;
LAB_003918fc:
  if (param_3) {
    local_23 = 0;
    local_24 = 3;
    local_22 = 0;
    local_28 = 0x2470;
    local_21 = 0;
    local_26 = 0x12f;
    local_20 = uVar11;
    FUN_003896c0(&local_28,0xc);
  }
  return uVar11;
}

