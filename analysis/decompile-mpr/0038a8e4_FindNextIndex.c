// sidb::headerStructure::FindNextIndex
// Ghidra address: 0038a8e4

/* sidb::headerStructure::FindNextIndex(unsigned int) */

int __thiscall sidb::headerStructure::FindNextIndex(headerStructure *this,uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar4 = *(uint *)(this + 0x44);
  uVar7 = 0;
  uVar6 = uVar4 >> 6;
  uVar2 = uVar6;
  if ((uVar4 & 0x3f) != 0) {
    uVar2 = uVar6 + 1;
  }
  do {
    if (uVar7 == uVar2) {
      return -1;
    }
    uVar1 = uVar7 + (param_1 >> 6);
    uVar5 = 0;
    if (uVar6 != 0) {
      uVar5 = uVar1 / uVar6;
    }
    if (*(ulong *)(this + ((ulong)(uVar1 - uVar5 * uVar6) + 0x800) * 8) != 0xffffffffffffffff) {
      uVar3 = param_1 & 0x3f;
      if (uVar7 != 0) {
        uVar3 = 0;
      }
      do {
        if ((*(ulong *)(this + ((ulong)(uVar1 - uVar5 * uVar6) + 0x800) * 8) >>
             ((ulong)uVar3 & 0x3f) & 1) == 0) {
          uVar3 = uVar3 + uVar1 * 0x40;
          uVar7 = 0;
          if (uVar4 != 0) {
            uVar7 = uVar3 / uVar4;
          }
          return uVar3 - uVar7 * uVar4;
        }
        uVar3 = uVar3 + 1;
      } while (uVar3 != 0x40);
    }
    uVar7 = uVar7 + 1;
  } while( true );
}

