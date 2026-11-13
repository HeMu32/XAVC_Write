// sidb::sidb2defStruct_ColorPrimaries
// Ghidra address: 0038b164

/* sidb::sidb2defStruct_ColorPrimaries(sidb::ColorPrimaries) */

sidb * __thiscall sidb::sidb2defStruct_ColorPrimaries(sidb *this)

{
  bool bVar1;
  uint uVar2;
  sidb *psVar3;
  
  uVar2 = (uint)this;
  if (uVar2 == 0x33) {
    return this;
  }
  if (uVar2 < 0x34) {
    if (uVar2 == 0x31) {
      return this;
    }
    if (0x31 < uVar2) {
      return (sidb *)0x32;
    }
    bVar1 = uVar2 == 1;
    psVar3 = (sidb *)0x0;
  }
  else {
    if (uVar2 == 0x35) {
      return this;
    }
    if (uVar2 < 0x35) {
      return (sidb *)0x34;
    }
    if (uVar2 == 0x3f) {
      return (sidb *)0x3f;
    }
    psVar3 = (sidb *)0xf000;
    bVar1 = uVar2 == 0xfe;
  }
  if (!bVar1) {
    psVar3 = (sidb *)0xffff;
  }
  return psVar3;
}

