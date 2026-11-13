// sidb::CreateBinaryRecord
// Ghidra address: 00392410

/* sidb::CreateBinaryRecord(unsigned int, unsigned char const*, unsigned int, unsigned int*) */

undefined8 sidb::CreateBinaryRecord(uint param_1,uchar *param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  undefined *puVar4;
  ushort uVar5;
  uint uVar6;
  ulong uVar7;
  undefined8 uVar8;
  ulong uVar9;
  ulong uVar10;
  headerStructure *this;
  uint uVar11;
  headerStructure *phVar12;
  headerStructure *phVar13;
  long lVar14;
  int local_4;
  
  puVar4 = PTR_g_usedRecordNum_00402c18;
  if (param_4 == (uint *)0x0) {
    uVar8 = 0x407;
  }
  else {
    uVar8 = 0x403;
    if (param_3 < 0x1001) {
      uVar10 = (ulong)param_1;
      uVar9 = 0;
      phVar12 = (headerStructure *)0x0;
      phVar13 = (headerStructure *)0x0;
      lVar14 = 0;
      this = *(headerStructure **)(PTR_gp_db_004017c8 + uVar10 * 8);
      bVar3 = 1;
      local_4 = 0;
      uVar2 = param_3;
      uVar11 = 0;
      while( true ) {
        if (uVar2 == 0) {
          if (phVar12 != (headerStructure *)0x0) {
            *(undefined4 *)(phVar12 + 4) = 0xffffffff;
            uVar2 = *(uint *)(this + 0x34);
            uVar9 = CalcChecksum((uchar *)phVar12,uVar2);
            *(short *)(this + (ulong)uVar2 + (ulong)(uVar11 * *(int *)(this + 0x30)) + 0x10000) =
                 (short)uVar9 + (short)(uVar9 / 0xfff1) * 0xf;
          }
          uVar5 = sidbhash::binary_hash(param_2,param_3);
          sidbhash::regist((sidbhash *)(PTR_g_binaryHash_00402cc0 + uVar10 * 0x1fe8),uVar5,*param_4)
          ;
          return 0;
        }
        lVar14 = lVar14 + uVar9;
        uVar1 = *(uint *)(this + 0x3c);
        if (uVar2 < *(uint *)(this + 0x3c)) {
          uVar1 = uVar2;
        }
        uVar9 = (ulong)uVar1;
        uVar2 = uVar2 - uVar1;
        uVar6 = headerStructure::FindNextIndex(this,*(uint *)(this + 0x7c44));
        if (uVar6 == 0xffffffff) break;
        headerStructure::SetBitmap(this,uVar6);
        *(int *)(puVar4 + uVar10 * 4) = *(int *)(puVar4 + uVar10 * 4) + 1;
        uVar7 = CalcChecksum((uchar *)(this + ((ulong)(uVar6 >> 0xd) + 0x10) * 0x400),0x400);
        *(int *)(this + ((ulong)(uVar6 >> 0xd) + 0x1f00) * 4) =
             (int)uVar7 + (int)(uVar7 / 0xfffffffb) * 5;
        SetFlushAreaHeader(param_1);
        if (local_4 == 0) {
          *param_4 = uVar6;
        }
        if (phVar13 != (headerStructure *)0x0) {
          *(uint *)phVar13 = uVar6;
        }
        if (phVar12 != (headerStructure *)0x0 && uVar11 != 0) {
          *(uint *)(phVar12 + 4) = uVar6;
          uVar11 = *(uint *)(this + 0x34);
          uVar7 = CalcChecksum((uchar *)phVar12,uVar11);
          *(short *)(phVar12 + uVar11) = (short)uVar7 + (short)(uVar7 / 0xfff1) * 0xf;
        }
        uVar7 = (ulong)(uVar6 * *(int *)(this + 0x30));
        phVar12 = this + uVar7 + 0x10000;
        phVar13 = phVar12 + 4;
        this[uVar7 + 0x10000] = (headerStructure)((byte)this[uVar7 + 0x10000] & 0xf0 | 2);
        memcpy(phVar12 + 10,param_2 + lVar14,(ulong)uVar1);
        uVar11 = *(ushort *)(phVar12 + 8) & 0xffff0001 | (uVar1 & 0x7fff) << 1;
        *(short *)(phVar12 + 8) = (short)uVar11;
        phVar12[8] = (headerStructure)((byte)uVar11 & 0xfe | bVar3);
        SetFlushArea(param_1,uVar6);
        local_4 = local_4 + 1;
        bVar3 = 0;
        uVar11 = uVar6;
      }
      return 0x402;
    }
  }
  return uVar8;
}

