// sidb::PartialUpdate_i<unsigned_short>
// Ghidra address: 00398678

/* int sidb::PartialUpdate_i<unsigned short>(unsigned int, unsigned int, sidb::COL_ID, unsigned
   short, bool, bool) */

int sidb::PartialUpdate_i<unsigned_short>
              (undefined4 param_1,uint param_2,int param_3,ushort param_4,char param_5,uint param_6)

{
  normalLock *this;
  recordStructureWithFunc<unsigned_short> *prVar1;
  uint uVar2;
  uint uVar3;
  char cVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined8 uVar8;
  headerStructure *this_00;
  ulong uVar9;
  signed local_25;
  uint local_24;
  ulong local_20;
  undefined2 local_18;
  undefined2 local_16;
  uint local_14;
  uint local_10;
  uint local_c;
  int local_8;
  uint uStack_4;
  
  if (param_5 != '\0') {
    local_16 = 0x100;
    local_14 = 1;
    local_18 = 0x2470;
    local_10 = param_1;
    local_c = param_2;
    local_8 = param_3;
    uStack_4 = (uint)param_4;
    FUN_003896c0(&local_18,0x18);
    local_14 = 3;
    local_16 = 0x101;
    local_18 = 0x2470;
    local_10 = param_6 & 0xff;
    FUN_003896c0(&local_18,0xc);
  }
  local_24 = 0xffffffff;
  iVar5 = GetMediaIdFromUniqueId(param_2,&local_24);
  if (iVar5 == 0) {
    uVar6 = mpr::msidconv::GetSlotID((msidconv *)PTR_g_msidconv_00402dc8,local_24);
    if (uVar6 != 0xffffffff) {
      uVar9 = (ulong)uVar6;
      this_00 = *(headerStructure **)(PTR_gp_db_004017c8 + uVar9 * 8);
      this = (normalLock *)(PTR_g_cancellock_00401410 + uVar9 * 0x40);
      iVar5 = *(int *)(this_00 + 0x30);
      mpr::thread::normalLock::lock(this);
      *(int *)(PTR_g_GetRootSetCancelRequestCount_00401788 + uVar9 * 4) =
           *(int *)(PTR_g_GetRootSetCancelRequestCount_00401788 + uVar9 * 4) + 1;
      mpr::thread::normalLock::unlock(this);
      mpr::thread::rwLock::wrlock((rwLock *)PTR_g_rwlock_004023e0);
      if (*(int *)(PTR_g_dbStatus_004029e8 + uVar9 * 4) == 3) {
        if (PTR_gb_protected_00401e10[uVar9] == '\0') {
          uVar2 = param_2 & 0x1ffff;
          cVar4 = headerStructure::IsTrueBitmap(this_00,uVar2);
          if ((cVar4 == '\0') || (0x61 < param_3)) {
            iVar5 = 0x403;
          }
          else {
            prVar1 = (recordStructureWithFunc<unsigned_short> *)
                     (this_00 + (ulong)(uVar2 * iVar5) + 0x10000);
            uVar7 = IsModificationTimeUpdated(param_3);
            if ((param_3 == 0x19) ||
               (iVar5 = recordStructureWithFunc<unsigned_short>::SetValue(prVar1,param_3,param_4),
               iVar5 == 0)) {
              uVar7 = param_6 & 0xff & uVar7 & 0xff;
              if (uVar7 != 0 || param_3 == 0x19) {
                local_25 = (signed)0x0;
                local_20 = 0;
                mpr::time::GetLTM((LocalTime *)&local_18);
                ConvDefStructLocalTime2SiDBUInt64((LocalTime *)&local_18,&local_20,&local_25);
                prVar1[0x18] = (recordStructureWithFunc<unsigned_short>)
                               ((byte)prVar1[0x18] & 1 | (char)local_25 << 1);
                *(uint *)(prVar1 + 0x18) =
                     *(uint *)(prVar1 + 0x18) & 0xff000000 |
                     *(uint *)(prVar1 + 0x18) & 0xfff | ((uint)(local_20 >> 0x20) & 0xfff) << 0xc;
                *(int *)(prVar1 + 0x1c) = (int)local_20;
                uVar8 = ConvDefStructLocalTime2SiDBUInt64((LocalTime *)&local_18);
                *(undefined8 *)(this_00 + 0x8018) = uVar8;
                uVar9 = CalcChecksum((uchar *)(this_00 + 0x8000),0x3ffc);
                *(int *)(this_00 + 0xbffc) = (int)uVar9 + (int)(uVar9 / 0xfffffffb) * 5;
              }
              uVar3 = *(uint *)(this_00 + 0x34);
              uVar9 = CalcChecksum((uchar *)prVar1,uVar3);
              *(short *)(this_00 +
                        (ulong)uVar3 + (ulong)(uVar2 * *(int *)(this_00 + 0x30)) + 0x10000) =
                   (short)uVar9 + (short)(uVar9 / 0xfff1) * 0xf;
              SetFlushArea(uVar6,uVar2);
              SetFlushAreaHeader(uVar6);
              iVar5 = 0;
              if (uVar7 != 0) {
                evtRecordChangedParam::evtRecordChangedParam((evtRecordChangedParam *)&local_18);
                local_14 = local_24;
                local_10 = 3;
                local_c = ContentTypeInternal2ContentType((byte)prVar1[7] & 0xf);
                local_8 = GetChangedParamTypeFromColId(param_3);
                uStack_4 = param_2;
                IssueCallbackRecordChanged((evtRecordChangedParam *)&local_18);
              }
            }
          }
        }
        else {
          iVar5 = 0x408;
        }
      }
      else {
        iVar5 = 0x409;
      }
      mpr::thread::rwLock::unlock((rwLock *)PTR_g_rwlock_004023e0);
      mpr::thread::normalLock::lock(this);
      *(int *)(PTR_g_GetRootSetCancelRequestCount_00401788 + (ulong)uVar6 * 4) =
           *(int *)(PTR_g_GetRootSetCancelRequestCount_00401788 + (ulong)uVar6 * 4) + -1;
      mpr::thread::normalLock::unlock(this);
      goto LAB_00398770;
    }
  }
  else {
    local_14 = 3;
    local_18 = 0x2470;
    local_16 = 0x107;
    local_10 = param_2;
    FUN_003896c0(&local_18,0xc);
  }
  iVar5 = 0x403;
LAB_00398770:
  if (param_5 != '\0') {
    local_14 = 3;
    local_18 = 0x2470;
    local_16 = 0x10f;
    local_10 = iVar5;
    FUN_003896c0(&local_18,0xc);
  }
  return iVar5;
}

