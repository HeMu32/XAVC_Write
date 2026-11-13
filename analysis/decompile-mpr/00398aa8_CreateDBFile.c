// sidb::CreateDBFile
// Ghidra address: 00398aa8

/* sidb::CreateDBFile(unsigned int, char, std::__cxx11::string, std::__cxx11::string,
   sidb::CreateDBFileConfig&) */

int sidb::CreateDBFile(uint param_1,char param_2,undefined8 param_3,undefined8 param_4,
                      undefined2 *param_5)

{
  string *this;
  int iVar1;
  uint uVar2;
  undefined *puVar3;
  undefined *puVar4;
  int iVar5;
  int iVar6;
  ulong uVar7;
  undefined8 uVar8;
  string *psVar9;
  ulong uVar10;
  undefined4 uVar11;
  size_t sVar12;
  int *piVar13;
  int *piVar14;
  long lVar15;
  long lVar16;
  uchar *__s;
  char local_d88 [7];
  signed local_d81;
  ulong local_d80;
  LocalTime aLStack_d78 [16];
  char local_d68 [24];
  UniversalGroupId aUStack_d50 [32];
  undefined1 auStack_d30 [32];
  undefined1 auStack_d10 [32];
  string asStack_cf0 [32];
  string asStack_cd0 [32];
  undefined2 local_cb0;
  undefined2 local_cae;
  undefined1 local_cac;
  undefined1 local_cab;
  undefined1 local_caa;
  undefined1 local_ca9;
  uint local_ca8;
  int local_ca4;
  char local_c90 [104];
  undefined2 local_c28;
  undefined2 local_c26;
  undefined1 local_c24;
  undefined1 local_c23;
  undefined1 local_c22;
  undefined1 local_c21;
  uint local_c20;
  
  local_c24 = 3;
  local_c28 = 0x2470;
  local_c26 = 0x40;
  local_c23 = 0;
  local_c22 = 0;
  local_c21 = 0;
  local_c20 = param_1;
  FUN_003896c0(&local_c28,0xc);
  puVar4 = PTR_g_msidconv_00402dc8;
  local_d68[0x14] = 0;
  local_c90[0] = '\0';
  local_c90[1] = '\0';
  local_c90[2] = '\0';
  local_c90[3] = '\0';
  local_c90[4] = '\0';
  local_c90[5] = '\0';
  local_c90[6] = '\0';
  local_c90[7] = '\0';
  local_c90[8] = '\0';
  local_c90[9] = '\0';
  local_c90[10] = '\0';
  local_c90[0xb] = '\0';
  local_c90[0xc] = '\0';
  local_c90[0xd] = '\0';
  local_c90[0xe] = '\0';
  local_c90[0xf] = '\0';
  local_d68[0x10] = '\0';
  local_d68[0x11] = '\0';
  local_d68[0x12] = '\0';
  local_d68[0x13] = '\0';
  local_c90[0x60] = '\0';
  local_c90[0x61] = '\0';
  local_c90[0x62] = '\0';
  local_c90[99] = '\0';
  local_c90[0x10] = '\0';
  local_c90[0x11] = '\0';
  local_c90[0x12] = '\0';
  local_c90[0x13] = '\0';
  local_c90[0x14] = '\0';
  local_c90[0x15] = '\0';
  local_c90[0x16] = '\0';
  local_c90[0x17] = '\0';
  local_c90[0x18] = '\0';
  local_c90[0x19] = '\0';
  local_c90[0x1a] = '\0';
  local_c90[0x1b] = '\0';
  local_c90[0x1c] = '\0';
  local_c90[0x1d] = '\0';
  local_c90[0x1e] = '\0';
  local_c90[0x1f] = '\0';
  local_c90[0x20] = '\0';
  local_c90[0x21] = '\0';
  local_c90[0x22] = '\0';
  local_c90[0x23] = '\0';
  local_c90[0x24] = '\0';
  local_c90[0x25] = '\0';
  local_c90[0x26] = '\0';
  local_c90[0x27] = '\0';
  local_c90[0x28] = '\0';
  local_c90[0x29] = '\0';
  local_c90[0x2a] = '\0';
  local_c90[0x2b] = '\0';
  local_c90[0x2c] = '\0';
  local_c90[0x2d] = '\0';
  local_c90[0x2e] = '\0';
  local_c90[0x2f] = '\0';
  local_c90[0x30] = '\0';
  local_c90[0x31] = '\0';
  local_c90[0x32] = '\0';
  local_c90[0x33] = '\0';
  local_c90[0x34] = '\0';
  local_c90[0x35] = '\0';
  local_c90[0x36] = '\0';
  local_c90[0x37] = '\0';
  local_c90[0x38] = '\0';
  local_c90[0x39] = '\0';
  local_c90[0x3a] = '\0';
  local_c90[0x3b] = '\0';
  local_c90[0x3c] = '\0';
  local_c90[0x3d] = '\0';
  local_c90[0x3e] = '\0';
  local_c90[0x3f] = '\0';
  local_c90[0x40] = '\0';
  local_c90[0x41] = '\0';
  local_c90[0x42] = '\0';
  local_c90[0x43] = '\0';
  local_c90[0x44] = '\0';
  local_c90[0x45] = '\0';
  local_c90[0x46] = '\0';
  local_c90[0x47] = '\0';
  local_c90[0x48] = '\0';
  local_c90[0x49] = '\0';
  local_c90[0x4a] = '\0';
  local_c90[0x4b] = '\0';
  local_c90[0x4c] = '\0';
  local_c90[0x4d] = '\0';
  local_c90[0x4e] = '\0';
  local_c90[0x4f] = '\0';
  local_c90[0x50] = '\0';
  local_c90[0x51] = '\0';
  local_c90[0x52] = '\0';
  local_c90[0x53] = '\0';
  local_c90[0x54] = '\0';
  local_c90[0x55] = '\0';
  local_c90[0x56] = '\0';
  local_c90[0x57] = '\0';
  local_c90[0x58] = '\0';
  local_c90[0x59] = '\0';
  local_c90[0x5a] = '\0';
  local_c90[0x5b] = '\0';
  local_c90[0x5c] = '\0';
  local_c90[0x5d] = '\0';
  local_c90[0x5e] = '\0';
  local_c90[0x5f] = '\0';
  local_d68[0] = '\0';
  local_d68[1] = '\0';
  local_d68[2] = '\0';
  local_d68[3] = '\0';
  local_d68[4] = '\0';
  local_d68[5] = '\0';
  local_d68[6] = '\0';
  local_d68[7] = '\0';
  local_d68[8] = '\0';
  local_d68[9] = '\0';
  local_d68[10] = '\0';
  local_d68[0xb] = '\0';
  local_d68[0xc] = '\0';
  local_d68[0xd] = '\0';
  local_d68[0xe] = '\0';
  local_d68[0xf] = '\0';
  mpr::msidconv::Set((msidconv *)PTR_g_msidconv_00402dc8,param_1,param_2,local_c90,local_d68);
  uVar7 = mpr::msidconv::GetSlotID((msidconv *)puVar4,param_1);
  uVar7 = uVar7 & 0xffffffff;
  iVar1 = *(int *)(param_5 + 4);
  osal_thread_id();
  __s = *(uchar **)(PTR_gp_db_004017c8 + uVar7 * 8);
  memset(&local_c28,0,0xc28);
  if (0xa00000 < *(uint *)(param_5 + 4)) {
    return 0x403;
  }
  uVar2 = *(uint *)(param_5 + 6);
  if (uVar2 < 0xa0) {
    return 0x403;
  }
  if (uVar2 < *(uint *)(param_5 + 8)) {
    return 0x403;
  }
  if (uVar2 < *(uint *)(param_5 + 10)) {
    return 0x403;
  }
  if (uVar2 < *(uint *)(param_5 + 0xc)) {
    return 0x403;
  }
  if (uVar2 < *(uint *)(param_5 + 0xe)) {
    return 0x403;
  }
  if (*(uint *)(param_5 + 4) < uVar2 * *(uint *)(param_5 + 0x10) + 0x10000) {
    return 0x403;
  }
  if ((*(uint *)(param_5 + 0x10) & 0x3f) != 0) {
    return 0x403;
  }
  mpr::thread::rwLock::wrlock((rwLock *)PTR_g_rwlock_004023e0);
  mpr::time::GetLTM(aLStack_d78);
  ConvDefStructLocalTime2SiDBUInt64(aLStack_d78,&local_d80,&local_d81);
  if (param_1 == *(uint *)PTR_g_pseudoMediaId_00401ef0) {
LAB_00398c64:
    *(undefined4 *)(PTR_g_dbStatus_004029e8 + uVar7 * 4) = 0;
  }
  else if (*(int *)(PTR_g_dbStatus_004029e8 + uVar7 * 4) != 0) {
    Fsys_Close(*(undefined8 *)(PTR_g_fsysHandle_00401688 + uVar7 * 8));
    goto LAB_00398c64;
  }
  puVar4 = PTR_g_pseudoMediaId_00401ef0;
  sVar12 = 0x17d00;
  if (param_1 != *(uint *)PTR_g_pseudoMediaId_00401ef0) {
    sVar12 = 0xa00000;
  }
  memset(__s,0,sVar12);
  puVar3 = PTR_g_macAddr_004018d0;
  uVar8 = *(undefined8 *)(PTR_g_magic_00402db0 + 8);
  *(undefined8 *)__s = *(undefined8 *)PTR_g_magic_00402db0;
  *(undefined8 *)(__s + 8) = uVar8;
  mpr::UniversalGroupId::UniversalGroupId(aUStack_d50,4,puVar3);
  mpr::UniversalGroupId::SetTimeInfo(aUStack_d50,aLStack_d78);
  mpr::UniversalGroupId::CreateUniversalGroupId(aUStack_d50,4,__s + 0x10);
  *(signed *)(__s + 0x21) = local_d81;
  *(int *)(__s + 0x24) = (int)local_d80;
  *(short *)(__s + 0x22) = (short)(local_d80 >> 0x20);
  *(undefined2 *)(__s + 0x28) = *param_5;
  *(short *)(__s + 0x2a) = (short)*(undefined4 *)(param_5 + 2);
  *(undefined4 *)(__s + 0x2c) = *(undefined4 *)(param_5 + 4);
  *(undefined4 *)(__s + 0x30) = *(undefined4 *)(param_5 + 6);
  *(undefined4 *)(__s + 0x34) = *(undefined4 *)(param_5 + 8);
  *(undefined4 *)(__s + 0x38) = *(undefined4 *)(param_5 + 10);
  *(undefined4 *)(__s + 0x3c) = *(undefined4 *)(param_5 + 0xc);
  *(undefined4 *)(__s + 0x40) = *(undefined4 *)(param_5 + 0xe);
  *(undefined4 *)(__s + 0x44) = *(undefined4 *)(param_5 + 0x10);
  __s[0x7c40] = '\x01';
  __s[0x7c41] = '\0';
  __s[0x7c42] = '\0';
  __s[0x7c43] = '\0';
  uVar8 = ConvDefStructLocalTime2SiDBUInt64(aLStack_d78);
  *(undefined8 *)(__s + 0x8018) = uVar8;
  *(ulong *)(__s + 0x4000) = *(ulong *)(__s + 0x4000) | 1;
  __s[0x1000a] = '\0';
  __s[0x10000] = __s[0x10000] & 0xf0 | 1;
  *(ushort *)(__s + 0x10008) = *(ushort *)(__s + 0x10008) & 1;
  __s[0x10008] = '\0';
  lVar16 = uVar7 * 0x1fe8;
  __s[0x10004] = 0xff;
  __s[0x10005] = 0xff;
  __s[0x10006] = 0xff;
  __s[0x10007] = 0xff;
  sVar12 = 800;
  if (param_1 != *(uint *)puVar4) {
    sVar12 = 0x3aa00;
  }
  memset(*(void **)(PTR_gp_onmem_00401cf8 + uVar7 * 8),0,sVar12);
  *(undefined4 *)(PTR_g_dbStatus_004029e8 + uVar7 * 4) = 0;
  PTR_gb_protected_00401e10[uVar7] = 0;
  *(undefined4 *)(PTR_g_usedRecordNum_00402c18 + uVar7 * 4) = 0;
  lVar15 = uVar7 * 0x20;
  FUN_00398a78(PTR_g_flushArea_set_00401ae0 + uVar7 * 0x30);
  sidbhash::clear((sidbhash *)(PTR_g_stringHash_00401bc8 + lVar16));
  sidbhash::clear((sidbhash *)(PTR_g_binaryHash_00402cc0 + lVar16));
  sidbhash::clear((sidbhash *)(PTR_g_binaryArrayHash_00401cb0 + lVar16));
  puVar4 = PTR_g_dbFilePath_abi_cxx11__00402068;
  this = (string *)(PTR_g_dbFilePath_abi_cxx11__00402068 + lVar15);
  local_d88[0] = param_2;
  FUN_003896b0(auStack_d30,local_d88,1);
  FUN_003896b0(auStack_d10,&DAT_003e61b0,1);
  FUN_001ac06c(asStack_cf0,auStack_d30,auStack_d10);
  psVar9 = (string *)std::__cxx11::string::append(asStack_cf0);
  std::__cxx11::string::string(asStack_cd0,psVar9);
  psVar9 = (string *)std::__cxx11::string::append(asStack_cd0);
  std::__cxx11::string::string((string *)&local_cb0,psVar9);
  std::__cxx11::string::operator=(this,(string *)&local_cb0);
  std::__cxx11::string::_M_dispose();
  std::__cxx11::string::_M_dispose();
  std::__cxx11::string::_M_dispose();
  std::__cxx11::string::_M_dispose();
  std::__cxx11::string::_M_dispose();
  uVar10 = CalcChecksum(__s,0x3ffc);
  *(int *)(__s + 0x3ffc) = (int)uVar10 + (int)(uVar10 / 0xfffffffb) * 5;
  uVar10 = CalcChecksum(__s + 0x7c40,0x3bc);
  *(int *)(__s + 0x7ffc) = (int)uVar10 + (int)(uVar10 / 0xfffffffb) * 5;
  uVar10 = CalcChecksum(__s + 0x8000,0x3ffc);
  *(int *)(__s + 0xbffc) = (int)uVar10 + (int)(uVar10 / 0xfffffffb) * 5;
  uVar10 = CalcChecksum(__s + 0xc000,0x3ffc);
  piVar13 = (int *)(__s + 0x4000);
  *(int *)(__s + 0xfffc) = (int)uVar10 + (int)(uVar10 / 0xfffffffb) * 5;
  piVar14 = (int *)(__s + 0x7c00);
  do {
    uVar10 = CalcChecksum((uchar *)piVar13,0x400);
    piVar13 = piVar13 + 0x100;
    *piVar14 = (int)uVar10 + (int)(uVar10 / 0xfffffffb) * 5;
    piVar14 = piVar14 + 1;
  } while ((int *)(__s + 0x7c00) != piVar13);
  if (param_1 == *(uint *)PTR_g_pseudoMediaId_00401ef0) {
    iVar5 = 0;
    *(undefined4 *)(PTR_g_dbStatus_004029e8 + uVar7 * 4) = 3;
  }
  else {
    iVar5 = mpr::fs::MkMultiDir(*(char **)(puVar4 + lVar15),0,true,true);
    if (iVar5 == 0) {
      iVar5 = Fsys_FindFirst(*(undefined8 *)(puVar4 + lVar15),0xffffff80,&local_c28);
      puVar3 = PTR_g_fsysHandle_00401688;
      uVar11 = 3;
      if (iVar5 != 0) {
        uVar11 = 7;
      }
      iVar5 = Fsys_Open(*(undefined8 *)(puVar4 + lVar15),PTR_g_fsysHandle_00401688 + uVar7 * 8,
                        uVar11);
      if (iVar5 == 0) {
        *(undefined4 *)(PTR_g_dbStatus_004029e8 + uVar7 * 4) = 3;
        iVar6 = Fsys_WriteAndFlush(*(undefined8 *)(puVar3 + uVar7 * 8),__s,iVar1);
        iVar5 = 0;
        if (iVar1 == iVar6) goto LAB_00399004;
        local_cae = 0x45;
        local_ca4 = iVar6;
      }
      else {
        local_cae = 0x44;
        local_ca4 = iVar5;
      }
    }
    else {
      local_cae = 0x43;
      local_ca4 = iVar5;
    }
    local_ca9 = 0;
    local_caa = 0;
    local_cab = 0;
    local_cac = 2;
    local_cb0 = 0x2470;
    iVar5 = 0x401;
    local_ca8 = param_1;
    FUN_003896c0((string *)&local_cb0,0x10);
  }
LAB_00399004:
  puVar4 = PTR_g_dbStatus_004029e8;
  if ((iVar5 != 0 && *(uint *)PTR_g_pseudoMediaId_00401ef0 != param_1) &&
     (*(int *)(PTR_g_dbStatus_004029e8 + uVar7 * 4) != 0)) {
    Fsys_Close(*(undefined8 *)(PTR_g_fsysHandle_00401688 + uVar7 * 8));
    *(undefined4 *)(puVar4 + uVar7 * 4) = 0;
  }
  mpr::thread::rwLock::unlock((rwLock *)PTR_g_rwlock_004023e0);
  local_cab = 0;
  local_caa = 0;
  local_cac = 3;
  local_ca9 = 0;
  local_cb0 = 0x2470;
  local_cae = 0x4f;
  local_ca8 = iVar5;
  FUN_003896c0((string *)&local_cb0,0xc);
  mpr::UniversalGroupId::~UniversalGroupId(aUStack_d50);
  return iVar5;
}

