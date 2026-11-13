// sidb::GetValue<unsigned_char>
// Ghidra address: 0039c254

/* int sidb::GetValue<unsigned char>(unsigned int, sidb::COL_ID, unsigned int, unsigned char*) */

int sidb::GetValue<unsigned_char>(uint param_1,int param_2,uint param_3,long param_4)

{
  char cVar1;
  int iVar2;
  headerStructure *this;
  
  if (param_4 == 0 || param_1 == 0xffffffff) {
    return 0x403;
  }
  this = *(headerStructure **)(PTR_gp_db_004017c8 + (ulong)param_1 * 8);
  cVar1 = headerStructure::IsTrueBitmap(this,param_3);
  if (cVar1 == '\0') {
    return 0x403;
  }
  if (param_2 < 0x5d) {
    iVar2 = recordStructureWithFunc<unsigned_char>::GetValue
                      ((recordStructureWithFunc<unsigned_char> *)
                       (this + (ulong)(param_3 * *(int *)(this + 0x30)) + 0x10000),param_2,param_3,
                       param_4);
    return iVar2;
  }
  if (param_2 < 0x62) {
    iVar2 = recordStructureBinaryWithFunc<unsigned_char>::GetValue
                      ((recordStructureBinaryWithFunc<unsigned_char> *)
                       (this + (ulong)(param_3 * *(int *)(this + 0x30)) + 0x10000),this,param_2,
                       param_3,param_4);
    return iVar2;
  }
  iVar2 = onMemoryColumnWithFunc<unsigned_char>::GetValue
                    ((onMemoryColumnWithFunc<unsigned_char> *)
                     (*(long *)(PTR_gp_onmem_00401cf8 + (ulong)param_1 * 8) + (ulong)param_3 * 4),
                     param_2,param_4);
  return iVar2;
}

