// sidb::Load
// Ghidra address: 003992c8

/* sidb::Load(unsigned int, char, std::__cxx11::string, std::__cxx11::string, bool, bool) */

undefined4
sidb::Load(uint param_1,char param_2,undefined8 param_3,undefined8 *param_4,byte param_5,
          byte param_6)

{
  string *this;
  sidbhash *this_00;
  byte bVar1;
  bool bVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  char cVar6;
  ushort uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  string *psVar12;
  ulong uVar13;
  ulong uVar14;
  ulong uVar15;
  ulong uVar16;
  size_t sVar17;
  undefined8 uVar18;
  undefined4 uVar19;
  uint uVar20;
  headerStructure *this_01;
  ulong uVar21;
  long lVar22;
  int iVar23;
  int iVar24;
  headerStructure *phVar25;
  long lVar26;
  headerStructure *phVar27;
  char local_2cc0 [8];
  char local_2cb8 [24];
  evtRecordChangedParam aeStack_2ca0 [4];
  uint local_2c9c;
  undefined4 uStack_2c98;
  undefined4 local_2c94;
  undefined1 auStack_2c88 [32];
  uint local_2c68 [8];
  undefined2 local_2c48;
  undefined2 local_2c46;
  undefined1 local_2c44;
  undefined1 local_2c43;
  undefined1 local_2c42;
  undefined1 local_2c41;
  undefined4 local_2c40;
  undefined1 auStack_2c28 [3112];
  string asStack_2000 [4096];
  undefined2 local_1000;
  undefined2 local_ffe;
  undefined1 local_ffc;
  undefined1 local_ffb;
  undefined1 local_ffa;
  undefined1 local_ff9;
  uint local_ff8;
  uint local_ff4;
  uint local_ff0;
  undefined4 local_fec;
  
  local_ffc = 1;
  local_ffb = 0;
  local_ff4 = (uint)param_5;
  local_ffa = 0;
  local_ff0 = (uint)param_6;
  local_fec = 0;
  local_ff9 = 0;
  local_1000 = 0x2470;
  local_ffe = 0x50;
  local_ff8 = param_1;
  FUN_003896c0((string *)&local_1000,0x18);
  puVar5 = PTR_g_msidconv_00402dc8;
  local_2cb8[0x14] = 0;
  local_2cb8[0] = '\0';
  local_2cb8[1] = '\0';
  local_2cb8[2] = '\0';
  local_2cb8[3] = '\0';
  local_2cb8[4] = '\0';
  local_2cb8[5] = '\0';
  local_2cb8[6] = '\0';
  local_2cb8[7] = '\0';
  local_2cb8[8] = '\0';
  local_2cb8[9] = '\0';
  local_2cb8[10] = '\0';
  local_2cb8[0xb] = '\0';
  local_2cb8[0xc] = '\0';
  local_2cb8[0xd] = '\0';
  local_2cb8[0xe] = '\0';
  local_2cb8[0xf] = '\0';
  local_2cb8[0x10] = '\0';
  local_2cb8[0x11] = '\0';
  local_2cb8[0x12] = '\0';
  local_2cb8[0x13] = '\0';
  mpr::msidconv::Set((msidconv *)PTR_g_msidconv_00402dc8,param_1,param_2,(char *)*param_4,local_2cb8
                    );
  uVar8 = mpr::msidconv::GetSlotID((msidconv *)puVar5,param_1);
  uVar21 = (ulong)uVar8;
  evtRecordChangedParam::evtRecordChangedParam(aeStack_2ca0);
  osal_thread_id();
  memset(auStack_2c28,0,0xc28);
  puVar5 = PTR_g_dbFilePath_abi_cxx11__00402068;
  if (*(uint *)PTR_g_pseudoMediaId_00401ef0 == param_1 || uVar8 == 0xffffffff) {
    uVar19 = 0x403;
    if (uVar8 == 0xffffffff) goto LAB_00399d90;
    bVar2 = false;
    uVar19 = 0x403;
LAB_00399d68:
    puVar5 = PTR_g_dbStatus_004029e8;
    if (*(int *)(PTR_g_dbStatus_004029e8 + uVar21 * 4) != 0) {
      Fsys_Close(*(undefined8 *)(PTR_g_fsysHandle_00401688 + uVar21 * 8));
      *(undefined4 *)(puVar5 + uVar21 * 4) = 0;
    }
    if (!bVar2) goto LAB_00399d90;
  }
  else {
    this_01 = *(headerStructure **)(PTR_gp_db_004017c8 + uVar21 * 8);
    this = (string *)(PTR_g_dbFilePath_abi_cxx11__00402068 + uVar21 * 0x20);
    local_2cc0[0] = param_2;
    FUN_003896b0(auStack_2c88,local_2cc0,1);
    FUN_003896b0(local_2c68,&DAT_003e61b8,1);
    FUN_001ac06c((string *)&local_2c48,auStack_2c88,local_2c68);
    psVar12 = (string *)std::__cxx11::string::append((string *)&local_2c48);
    std::__cxx11::string::string(asStack_2000,psVar12);
    psVar12 = (string *)std::__cxx11::string::append(asStack_2000);
    std::__cxx11::string::string((string *)&local_1000,psVar12);
    std::__cxx11::string::operator=(this,(string *)&local_1000);
    std::__cxx11::string::_M_dispose();
    std::__cxx11::string::_M_dispose();
    std::__cxx11::string::_M_dispose();
    std::__cxx11::string::_M_dispose();
    std::__cxx11::string::_M_dispose();
    mpr::thread::rwLock::wrlock((rwLock *)PTR_g_rwlock_004023e0);
    PTR_gb_protected_00401e10[uVar21] = param_6;
    puVar3 = PTR_g_dbStatus_004029e8;
    puVar4 = PTR_g_fsysHandle_00401688;
    if (*(int *)(PTR_g_dbStatus_004029e8 + uVar21 * 4) != 2) {
      lVar22 = 0xa00000;
      if (param_5 != 0) {
        lVar22 = 0x10000;
      }
      if (*(int *)(PTR_g_dbStatus_004029e8 + uVar21 * 4) != 0) goto LAB_003996f8;
LAB_0039971c:
      iVar10 = Fsys_FindFirst(*(undefined8 *)(puVar5 + uVar21 * 0x20),0xffffff80,auStack_2c28);
      puVar4 = PTR_g_fsysHandle_00401688;
      uVar19 = 7;
      if ((iVar10 == 0) && (uVar19 = 3, param_6 != 0)) {
        uVar19 = 1;
      }
      uVar9 = Fsys_Open(*(undefined8 *)(puVar5 + uVar21 * 0x20),
                        PTR_g_fsysHandle_00401688 + (ulong)uVar8 * 8,uVar19);
      if (uVar9 == 0) {
        *(undefined4 *)(PTR_g_dbStatus_004029e8 + (ulong)uVar8 * 4) = 1;
        lVar26 = 0;
        do {
          uVar9 = Fsys_Read(*(undefined8 *)(puVar4 + (ulong)uVar8 * 8),this_01,lVar22);
          if ((int)uVar9 < 1) {
            if (uVar9 != 0) {
              local_ffe = 0x56;
              goto LAB_00399580;
            }
            if (lVar26 < 0x10000) {
              local_ff4 = 0;
              local_ffe = 0x57;
              goto LAB_003998f8;
            }
            break;
          }
          lVar26 = lVar26 + (int)uVar9;
        } while (lVar26 < lVar22);
        if ((param_5 & lVar26 != 0x10000) != 0) {
          local_ffc = 1;
          local_ff0 = (uint)lVar26;
          local_fec = 0;
          local_ffe = 0x58;
          uVar18 = 0x18;
          local_ff4 = uVar9;
          goto LAB_00399590;
        }
        if ((param_5 == 0) && (*(int *)(this_01 + 0x2c) != lVar26)) {
          local_ffe = 0x59;
          local_ff4 = uVar9;
LAB_003998f8:
          local_ff9 = 0;
          local_ffa = 0;
          local_ffb = 0;
          local_ffc = 1;
          local_1000 = 0x2470;
          local_ff0 = (uint)lVar26;
          local_fec = 0;
          local_ff8 = param_1;
          FUN_003896c0((string *)&local_1000,0x18);
LAB_0039990c:
          uVar19 = 0x406;
        }
        else {
          uVar19 = 0x405;
          *(uint *)(PTR_g_dbStatus_004029e8 + (ulong)uVar8 * 4) = (lVar22 != 0x10000) + 2;
          if (*(short *)(this_01 + 0x28) == 1) {
            uVar19 = 0x406;
            iVar10 = memcmp(this_01,PTR_g_magic_00402db0,0x10);
            if (iVar10 == 0) {
              uVar13 = CalcChecksum((uchar *)this_01,0x3ffc);
              uVar14 = CalcChecksum((uchar *)(this_01 + 0x7c40),0x3bc);
              uVar15 = CalcChecksum((uchar *)(this_01 + 0x8000),0x3ffc);
              uVar16 = CalcChecksum((uchar *)(this_01 + 0xc000),0x3ffc);
              if ((((*(int *)(this_01 + 0x3ffc) == (int)uVar13 + (int)(uVar13 / 0xfffffffb) * 5) &&
                   (*(int *)(this_01 + 0x7ffc) == (int)uVar14 + (int)(uVar14 / 0xfffffffb) * 5)) &&
                  (*(int *)(this_01 + 0xbffc) == (int)uVar15 + (int)(uVar15 / 0xfffffffb) * 5)) &&
                 (*(int *)(this_01 + 0xfffc) == (int)uVar16 + (int)(uVar16 / 0xfffffffb) * 5)) {
                phVar25 = this_01 + 0x4000;
                phVar27 = this_01 + 0x7c00;
                do {
                  uVar13 = CalcChecksum((uchar *)phVar25,0x400);
                  if (*(int *)phVar27 != (int)uVar13 + (int)(uVar13 / 0xfffffffb) * 5)
                  goto LAB_0039990c;
                  phVar25 = phVar25 + 0x400;
                  phVar27 = phVar27 + 4;
                } while (phVar25 != this_01 + 0x7c00);
                sVar17 = 800;
                if (param_1 != *(uint *)PTR_g_pseudoMediaId_00401ef0) {
                  sVar17 = 0x3aa00;
                }
                memset(*(void **)(PTR_gp_onmem_00401cf8 + (ulong)uVar8 * 8),0,sVar17);
                puVar5 = PTR_g_usedRecordNum_00402c18;
                uVar20 = *(uint *)(this_01 + 0x44);
                *(undefined4 *)(PTR_g_usedRecordNum_00402c18 + (ulong)uVar8 * 4) = 0;
                for (uVar9 = 0; uVar9 != uVar20; uVar9 = uVar9 + 1) {
                  cVar6 = headerStructure::IsTrueBitmap(this_01,uVar9);
                  if (cVar6 != '\0') {
                    *(int *)(puVar5 + (ulong)uVar8 * 4) = *(int *)(puVar5 + (ulong)uVar8 * 4) + 1;
                  }
                }
                lVar22 = (ulong)uVar8 * 0x1fe8;
                sidbhash::clear((sidbhash *)(PTR_g_stringHash_00401bc8 + lVar22));
                sidbhash::clear((sidbhash *)(PTR_g_binaryHash_00402cc0 + lVar22));
                sidbhash::clear((sidbhash *)(PTR_g_binaryArrayHash_00401cb0 + lVar22));
                if (param_5 == 0) goto LAB_00399634;
                iVar23 = 0;
                iVar24 = 0;
                iVar10 = 0;
                goto LAB_00399b78;
              }
            }
          }
        }
      }
      else {
        local_ffe = 0x55;
LAB_00399580:
        local_ffc = 2;
        uVar18 = 0x10;
        local_ff4 = uVar9;
LAB_00399590:
        local_ff9 = 0;
        local_ffa = 0;
        local_ffb = 0;
        local_1000 = 0x2470;
        uVar19 = 0x401;
        local_ff8 = param_1;
        FUN_003896c0((string *)&local_1000,uVar18);
      }
LAB_00399620:
      bVar2 = true;
      goto LAB_00399d68;
    }
    lVar22 = 0x10000;
    if (param_5 != 0) {
LAB_003996f8:
      Fsys_Close(*(undefined8 *)(PTR_g_fsysHandle_00401688 + (ulong)uVar8 * 8));
      *(undefined4 *)(PTR_g_dbStatus_004029e8 + (ulong)uVar8 * 4) = 0;
      goto LAB_0039971c;
    }
    iVar10 = *(int *)(this_01 + 0x2c);
    uVar9 = Fsys_Seek(*(undefined8 *)(PTR_g_fsysHandle_00401688 + uVar21 * 8),0x10000,0,0);
    if (uVar9 != 0) {
      local_ffe = 0x53;
      goto LAB_00399580;
    }
    uVar9 = Fsys_Read(*(undefined8 *)(puVar4 + uVar21 * 8),this_01 + 0x10000,iVar10 - 0x10000U);
    if ((long)(int)uVar9 != (ulong)(iVar10 - 0x10000U)) {
      uVar19 = 0x404;
      local_ffb = 0;
      local_ffa = 0;
      local_ff9 = 0;
      local_1000 = 0x2470;
      local_ffe = 0x54;
      local_ffc = 2;
      local_ff8 = param_1;
      local_ff4 = uVar9;
      FUN_003896c0((string *)&local_1000,0x10);
      goto LAB_00399620;
    }
    *(undefined4 *)(puVar3 + uVar21 * 4) = 3;
LAB_00399634:
    puVar4 = PTR_g_binaryHash_00402cc0;
    puVar5 = PTR_g_stringHash_00401bc8;
    iVar23 = 0;
    iVar24 = 0;
    iVar10 = 0;
    this_00 = (sidbhash *)(PTR_g_binaryArrayHash_00401cb0 + (ulong)uVar8 * 0x1fe8);
    for (uVar9 = 0; uVar9 < *(uint *)(this_01 + 0x44); uVar9 = uVar9 + 1) {
      cVar6 = headerStructure::IsTrueBitmap(this_01,uVar9);
      if (cVar6 != '\0') {
        uVar21 = (ulong)(uVar9 * *(int *)(this_01 + 0x30));
        switch((byte)this_01[uVar21 + 0x10000] & 0xf) {
        case 0:
          if ((*(ushort *)(this_01 + uVar21 + 0x10004) & 0xfffe) != 0) {
            iVar10 = iVar10 + 1;
            bVar1 = (byte)this_01[uVar21 + 0x10007] & 0xf;
            if (bVar1 == 1) {
              iVar24 = iVar24 + 1;
            }
            else if ((((byte)this_01[uVar21 + 0x10007] & 0xf) != 0) && (bVar1 < 4)) {
              iVar23 = iVar23 + 1;
            }
          }
          break;
        case 1:
          if ((((byte)this_01[uVar21 + 0x10008] & 1) != 0) &&
             (iVar11 = RestorateFilePath((fileStructure *)this_01,'\0',uVar9,(char *)asStack_2000,
                                         0x1000), iVar11 == 0)) {
            sVar17 = strnlen((char *)asStack_2000,0x106);
            uVar7 = sidbhash::string_hash((char *)asStack_2000,(uint)sVar17);
            puVar3 = puVar5;
LAB_00399c94:
            sidbhash::regist((sidbhash *)(puVar3 + (ulong)uVar8 * 0x1fe8),uVar7,uVar9);
          }
          break;
        case 2:
          if ((((byte)this_01[uVar21 + 0x10008] & 1) != 0) &&
             (iVar11 = RestorateBinaryRecord
                                 ((fileStructure *)this_01,uVar9,(uchar *)&local_1000,0x1000,
                                  local_2c68), iVar11 == 0)) {
            uVar7 = sidbhash::binary_hash((uchar *)&local_1000,local_2c68[0]);
            puVar3 = puVar4;
            goto LAB_00399c94;
          }
          break;
        case 3:
          uVar20 = 0;
          do {
            if ((((int)(uint)*(ushort *)(this_01 + uVar21 + 0x10006) >> (uVar20 & 0x1f) & 1U) != 0)
               && (iVar11 = RestorateArrayBinaryRecordForLoad
                                      ((fileStructure *)this_01,uVar9,uVar20,(uchar *)&local_1000,
                                       local_2c68), iVar11 == 0)) {
              uVar7 = sidbhash::binary_hash((uchar *)&local_1000,local_2c68[0]);
              sidbhash::regist(this_00,uVar7,uVar9);
            }
            uVar20 = uVar20 + 1;
          } while (uVar20 != 0x10);
        }
      }
    }
LAB_00399b78:
    if (((iVar10 != *(int *)(this_01 + 0x7c80)) || (iVar24 != *(int *)(this_01 + 0x7c84))) ||
       (iVar23 != *(int *)(this_01 + 0x7c88))) {
      *(int *)(this_01 + 0x7c80) = iVar10;
      *(int *)(this_01 + 0x7c84) = iVar24;
      *(int *)(this_01 + 0x7c88) = iVar23;
      uVar21 = CalcChecksum((uchar *)(this_01 + 0x7c40),0x3bc);
      *(int *)(this_01 + 0x7ffc) = (int)uVar21 + (int)(uVar21 / 0xfffffffb) * 5;
    }
    uVar19 = 0;
    FUN_00398a78(PTR_g_flushArea_set_00401ae0 + (ulong)uVar8 * 0x30);
    uStack_2c98 = 4;
    local_2c94 = 0xffffffff;
    local_2c9c = param_1;
    IssueCallbackRecordChanged(aeStack_2ca0);
  }
  mpr::thread::rwLock::unlock((rwLock *)PTR_g_rwlock_004023e0);
LAB_00399d90:
  local_2c44 = 3;
  local_2c43 = 0;
  local_2c48 = 0x2470;
  local_2c42 = 0;
  local_2c46 = 0x5f;
  local_2c41 = 0;
  local_2c40 = uVar19;
  FUN_003896c0((string *)&local_2c48,0xc);
  return uVar19;
}

