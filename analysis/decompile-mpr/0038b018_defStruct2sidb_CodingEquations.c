// sidb::defStruct2sidb_CodingEquations
// Ghidra address: 0038b018

/* sidb::defStruct2sidb_CodingEquations(DefStruct::RDD18Meta::CodingEquations) */

undefined8 sidb::defStruct2sidb_CodingEquations(uint param_1)

{
  if (param_1 == 2) {
    return 3;
  }
  if (param_1 < 3) {
    if (param_1 == 0) {
      return 1;
    }
    if (param_1 == 1) {
      return 2;
    }
  }
  else {
    if (param_1 == 0xf000) {
      return 0xfe;
    }
    if (param_1 == 0xffff) {
      return 0;
    }
    if (param_1 == 5) {
      return 4;
    }
  }
  return 0xf;
}

