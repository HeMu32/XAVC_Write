// sidb::SearchArrayBinaryRecord
// Ghidra address 0038e3c0; ELF VMA = Ghidra - 0x100000

/* sidb::SearchArrayBinaryRecord(unsigned int, sidb::BinaryRecordType, unsigned char const*,
   unsigned int, unsigned int*, unsigned int*) */

undefined4
sidb::SearchArrayBinaryRecord
          (uint param_1,uint param_2,uchar *param_3,uint param_4,uint *param_5,uint *param_6)

{
  uint uVar1;
  uint uVar2;
  char cVar3;
  ushort uVar4;
  int iVar5;
  undefined4 uVar6;
  ulong uVar7;
  headerStructure *this;
  long lVar8;
  ulong uVar9;
  
  if (param_5 == (uint *)0x0 || param_6 == (uint *)0x0) {
    return 0x407;
  }
  uVar6 = 0x403;
  if (param_4 < 0x1001) {
    uVar4 = sidbhash::binary_hash(param_3,param_4);
    lVar8 = *(long *)(PTR_g_binaryArrayHash_00401cb0 + ((ulong)param_1 * 0x3fd + (ulong)uVar4) * 8);
    uVar6 = 0x407;
    if (lVar8 != 0) {
      this = *(headerStructure **)(PTR_gp_db_004017c8 + (ulong)param_1 * 8);
      for (uVar9 = 0; uVar1 = *(uint *)(lVar8 + uVar9 * 4), uVar1 != 0xffffffff;
          uVar9 = (ulong)((int)uVar9 + 1)) {
        uVar2 = uVar1 >> 0xf;
        cVar3 = headerStructure::IsTrueBitmap(this,uVar2);
        if ((((cVar3 != '\0') &&
             (uVar7 = (ulong)(uVar2 * *(int *)(this + 0x30)),
             ((byte)this[uVar7 + 0x10000] & 0xf) == 3)) && ((byte)this[uVar7 + 0x10004] == param_2))
           && (param_4 == (byte)this[uVar7 + 0x10005])) {
          iVar5 = memcmp(param_3,this + (ulong)(param_4 * (uVar1 & 0x7fff)) + uVar7 + 0x1000c,
                         (ulong)(byte)param_4);
          if (iVar5 == 0) {
            *param_5 = uVar2;
            *param_6 = uVar1 & 0x7fff;
            return 0;
          }
        }
      }
      uVar6 = 0x401;
    }
  }
  return uVar6;
}

