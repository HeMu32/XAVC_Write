// sidb::defStruct2sidb_ColorPrimaries
// Ghidra address: 0038af9c

/* sidb::defStruct2sidb_ColorPrimaries(DefStruct::RDD18Meta::ColorPrimaries) */

uint sidb::defStruct2sidb_ColorPrimaries(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  if (param_1 == 0x34) {
    return 0x34;
  }
  if (param_1 < 0x35) {
    if (param_1 == 0x31) {
      return 0x31;
    }
    if (param_1 < 0x32) {
      if (param_1 != 0) {
        return 0x3f;
      }
      return 1;
    }
    if (param_1 == 0x32) {
      return 0x32;
    }
    uVar2 = 0x33;
    uVar1 = uVar2;
  }
  else {
    if (param_1 == 0x3f) {
      return 0x3f;
    }
    if (param_1 < 0x40) {
      uVar2 = 0x35;
      uVar1 = uVar2;
    }
    else {
      if (param_1 == 0xf000) {
        return 0xfe;
      }
      uVar2 = 0xffff;
      uVar1 = 0;
    }
  }
  if (param_1 != uVar2) {
    return 0x3f;
  }
  return uVar1;
}

