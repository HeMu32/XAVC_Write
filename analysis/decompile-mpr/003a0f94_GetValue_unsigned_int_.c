// sidb::GetValue<unsigned_int>
// Ghidra address: 003a0f94

/* int sidb::GetValue<unsigned int>(unsigned int, sidb::COL_ID, unsigned int, unsigned int*) */

int sidb::GetValue<unsigned_int>(uint param_1,int param_2,uint param_3,undefined4 *param_4)

{
  char cVar1;
  int iVar2;
  headerStructure *this;
  
  if (param_4 == (undefined4 *)0x0 || param_1 == 0xffffffff) {
    return 0x403;
  }
  this = *(headerStructure **)(PTR_gp_db_004017c8 + (ulong)param_1 * 8);
  cVar1 = headerStructure::IsTrueBitmap(this,param_3);
  iVar2 = 0x403;
  if (cVar1 != '\0') {
    if (param_2 < 0x5d) {
      iVar2 = recordStructureWithFunc<unsigned_int>::GetValue
                        ((recordStructureWithFunc<unsigned_int> *)
                         (this + (ulong)(param_3 * *(int *)(this + 0x30)) + 0x10000),param_2,param_3
                         ,param_4);
      return iVar2;
    }
    if (param_2 < 0x62) {
      iVar2 = recordStructureBinaryWithFunc<unsigned_int>::GetValue
                        ((recordStructureBinaryWithFunc<unsigned_int> *)
                         (this + (ulong)(param_3 * *(int *)(this + 0x30)) + 0x10000),this,param_2,
                         param_3,param_4);
      return iVar2;
    }
    if (param_2 == 99) {
      iVar2 = 0;
      *param_4 = *(undefined4 *)
                  (*(long *)(PTR_gp_onmem_00401cf8 + (ulong)param_1 * 8) + (ulong)param_3 * 4);
    }
  }
  return iVar2;
}

