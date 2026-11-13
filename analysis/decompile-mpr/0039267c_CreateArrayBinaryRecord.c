// sidb::CreateArrayBinaryRecord
// Ghidra address: 0039267c

/* sidb::CreateArrayBinaryRecord(unsigned int, sidb::BinaryRecordType, unsigned int*, unsigned char
   const*, unsigned int, unsigned int*, unsigned int*, bool*) */

undefined8
sidb::CreateArrayBinaryRecord
          (uint param_1,uint param_2,uint *param_3,uchar *param_4,uint param_5,uint *param_6,
          uint *param_7,undefined1 *param_8)

{
  headerStructure *phVar1;
  int iVar2;
  uint uVar3;
  ushort uVar4;
  uint uVar5;
  ulong uVar6;
  undefined8 uVar7;
  headerStructure *this;
  uint uVar8;
  
  if ((param_6 == (uint *)0x0 || param_8 == (undefined1 *)0x0) || param_3 == (uint *)0x0) {
    return 0x407;
  }
  if (0x1000 < param_5) {
    return 0x403;
  }
  this = *(headerStructure **)(PTR_gp_db_004017c8 + (ulong)param_1 * 8);
  uVar5 = *param_3;
  iVar2 = *(int *)(this + 0x30);
  *param_8 = 1;
  if (*(uint *)(this + 0x44) < uVar5) {
    uVar7 = 0x403;
  }
  else {
    if (((uVar5 != 0) && (uVar6 = (ulong)(uVar5 * iVar2), (byte)this[uVar6 + 0x10004] == param_2))
       && (param_5 == (byte)this[uVar6 + 0x10005])) {
      uVar8 = 0;
      uVar6 = (ulong)*(ushort *)(this + uVar6 + 0x10006);
      uVar3 = 0;
      if (param_5 != 0) {
        uVar3 = *(uint *)(this + 0x40) / param_5;
      }
      for (; uVar3 != uVar8; uVar8 = uVar8 + 1) {
        if ((uVar6 & 1) == 0) {
          *param_6 = uVar5;
          *param_7 = uVar8;
          *param_8 = 0;
          uVar4 = sidbhash::binary_hash(param_4,param_5);
          sidbhash::regist((sidbhash *)(PTR_g_binaryArrayHash_00401cb0 + (ulong)param_1 * 0x1fe8),
                           uVar4,uVar8 & 0x7fff | *param_6 << 0xf);
          *param_6 = *param_3;
          goto LAB_003927a4;
        }
        uVar6 = uVar6 >> 1;
      }
    }
    uVar5 = headerStructure::FindNextIndex(this,*(uint *)(this + 0x7c44));
    *param_6 = uVar5;
    uVar7 = 0x402;
    if (uVar5 != 0xffffffff) {
      headerStructure::SetBitmap(this,uVar5);
      *(int *)(PTR_g_usedRecordNum_00402c18 + (ulong)param_1 * 4) =
           *(int *)(PTR_g_usedRecordNum_00402c18 + (ulong)param_1 * 4) + 1;
      uVar5 = *param_6;
      uVar6 = CalcChecksum((uchar *)(this + ((ulong)(uVar5 >> 0xd) + 0x10) * 0x400),0x400);
      *(int *)(this + ((ulong)(uVar5 >> 0xd) + 0x1f00) * 4) =
           (int)uVar6 + (int)(uVar6 / 0xfffffffb) * 5;
      uVar6 = CalcChecksum((uchar *)(this + 0x7c40),0x3bc);
      *(int *)(this + 0x7ffc) = (int)uVar6 + (int)(uVar6 / 0xfffffffb) * 5;
      SetFlushAreaHeader(param_1);
      *param_3 = *param_6;
      uVar4 = sidbhash::binary_hash(param_4,param_5);
      sidbhash::regist((sidbhash *)(PTR_g_binaryArrayHash_00401cb0 + (ulong)param_1 * 0x1fe8),uVar4,
                       *param_7 & 0x7fff | *param_6 << 0xf);
      uVar6 = (ulong)(*param_6 * *(int *)(this + 0x30));
      this[uVar6 + 0x10000] = (headerStructure)((byte)this[uVar6 + 0x10000] & 0xf0 | 3);
      this[uVar6 + 0x10004] = SUB41(param_2,0);
      this[uVar6 + 0x10005] = SUB41(param_5,0);
LAB_003927a4:
      phVar1 = this + (ulong)(*param_6 * *(int *)(this + 0x30)) + 0x10000;
      *(ushort *)(phVar1 + 6) = (ushort)(1 << (ulong)(*param_7 & 0x1f)) | *(ushort *)(phVar1 + 6);
      memcpy(phVar1 + (ulong)(param_5 * *param_7) + 0xc,param_4,(ulong)param_5);
      uVar5 = *(uint *)(this + 0x34);
      uVar6 = CalcChecksum((uchar *)phVar1,uVar5);
      uVar8 = *param_6;
      *(short *)(this + (ulong)uVar5 + (ulong)(uVar8 * *(int *)(this + 0x30)) + 0x10000) =
           (short)uVar6 + (short)(uVar6 / 0xfff1) * 0xf;
      SetFlushArea(param_1,uVar8);
      uVar7 = 0;
    }
  }
  return uVar7;
}

