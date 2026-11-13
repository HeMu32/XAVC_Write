// sidb::sidb2defStruct_CodingEquations
// Ghidra address: 0038b1c4

/* sidb::sidb2defStruct_CodingEquations(sidb::CodingEquations) */

sidb * __thiscall sidb::sidb2defStruct_CodingEquations(sidb *this)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = (uint)this;
  if (uVar1 == 3) {
    this = (sidb *)0x2;
  }
  else if (uVar1 < 4) {
    this = (sidb *)0x0;
    if (uVar1 != 1) {
      uVar2 = 0xffff;
      if (1 < uVar1) {
        uVar2 = 1;
      }
      return (sidb *)(ulong)uVar2;
    }
  }
  else if ((uVar1 != 0xf) && (this = (sidb *)0xf000, uVar1 != 0xfe)) {
    uVar2 = 5;
    if (uVar1 != 4) {
      uVar2 = 0xf;
    }
    return (sidb *)(ulong)uVar2;
  }
  return this;
}

