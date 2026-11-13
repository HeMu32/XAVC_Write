// sidb::defStruct2sidb_CaptureGammaEquation
// Ghidra address: 0038ad84

/* sidb::defStruct2sidb_CaptureGammaEquation(DefStruct::RDD18Meta::CaptureGammaEquation) */

uint sidb::defStruct2sidb_CaptureGammaEquation(uint param_1)

{
  bool bVar1;
  uint uVar2;
  
  if (param_1 == 0x36) {
    return 0x36;
  }
  if (param_1 < 0x37) {
    if (param_1 == 0x17) {
      return 0x17;
    }
    if (param_1 < 0x18) {
      if (param_1 == 0x11) {
        return 0x11;
      }
      if (param_1 < 0x12) {
        if (param_1 == 2) {
          return 3;
        }
        if (param_1 < 3) {
          bVar1 = param_1 == 1;
          uVar2 = 2;
        }
        else {
          if (param_1 == 3) {
            return 4;
          }
          uVar2 = 5;
          bVar1 = param_1 == 4;
        }
        goto LAB_0038adc4;
      }
      if (param_1 == 0x14) {
        return 0x14;
      }
      if (param_1 < 0x15) {
        if (param_1 == 0x12) {
          return 0x12;
        }
        uVar2 = 0x13;
      }
      else {
        if (param_1 == 0x15) {
          return 0x15;
        }
        uVar2 = 0x16;
      }
    }
    else {
      if (param_1 == 0x30) {
        return 0x30;
      }
      if (param_1 < 0x31) {
        if (param_1 == 0x24) {
          return 0x24;
        }
        if (param_1 < 0x25) {
          if (param_1 == 0x18) {
            return 0x18;
          }
          uVar2 = 0x21;
        }
        else {
          if (param_1 == 0x25) {
            return 0x25;
          }
          uVar2 = 0x28;
        }
      }
      else {
        if (param_1 == 0x33) {
          return 0x33;
        }
        if (param_1 < 0x34) {
          if (param_1 == 0x31) {
            return 0x31;
          }
          uVar2 = 0x32;
        }
        else {
          if (param_1 == 0x34) {
            return 0x34;
          }
          uVar2 = 0x35;
        }
      }
    }
  }
  else {
    if (param_1 == 0x52) {
      return 0x52;
    }
    if (param_1 < 0x53) {
      if (param_1 == 0x45) {
        return 0x45;
      }
      if (param_1 < 0x46) {
        if (param_1 == 0x42) {
          return 0x42;
        }
        uVar2 = 0x41;
        if (0x42 < param_1) {
          if (param_1 == 0x43) {
            return 0x43;
          }
          uVar2 = 0x44;
        }
      }
      else {
        if (param_1 == 0x48) {
          return 0x48;
        }
        if (param_1 < 0x49) {
          if (param_1 == 0x46) {
            return 0x46;
          }
          uVar2 = 0x47;
        }
        else {
          if (param_1 == 0x49) {
            return 0x49;
          }
          uVar2 = 0x51;
        }
      }
    }
    else {
      if (param_1 == 0x61) {
        return 0x61;
      }
      if (param_1 < 0x62) {
        if (param_1 == 0x55) {
          return 0x55;
        }
        if (param_1 < 0x56) {
          if (param_1 == 0x53) {
            return 0x53;
          }
          uVar2 = 0x54;
        }
        else {
          if (param_1 == 0x56) {
            return 0x56;
          }
          uVar2 = 0x58;
        }
      }
      else {
        if (param_1 == 0x65) {
          return 0x65;
        }
        if (0x65 < param_1) {
          if (param_1 == 0xf000) {
            return 0xfe;
          }
          uVar2 = 0;
          bVar1 = param_1 == 0xffff;
          goto LAB_0038adc4;
        }
        if (param_1 == 0x62) {
          return 0x62;
        }
        uVar2 = 100;
      }
    }
  }
  bVar1 = param_1 == uVar2;
LAB_0038adc4:
  if (!bVar1) {
    uVar2 = 1;
  }
  return uVar2;
}

