// FUN_003cd2ec
// Ghidra address: 003cd2ec

undefined8 FUN_003cd2ec(short param_1)

{
  bool bVar1;
  undefined8 uVar2;
  
  if (param_1 == 0x1e) {
    return 0x3f;
  }
  if (param_1 < 0x1f) {
    if (param_1 == -0x186) {
      return 0x1a;
    }
    if (param_1 < -0x185) {
      if (param_1 == -0x23a) {
        return 0x1d;
      }
      if (param_1 < -0x239) {
        if (param_1 == -0x294) {
          return 0x11;
        }
        if (param_1 < -0x293) {
          if (param_1 == -0x2d0) {
            return 0x12;
          }
          bVar1 = param_1 == -0x2b2;
          uVar2 = 0x1f;
        }
        else {
          if (param_1 == -0x276) {
            return 0x1e;
          }
          uVar2 = 0x10;
          bVar1 = param_1 == -600;
        }
      }
      else {
        if (param_1 == -0x1e0) {
          return 8;
        }
        if (param_1 < -0x1df) {
          if (param_1 == -0x21c) {
            return 9;
          }
          uVar2 = 0x1c;
          bVar1 = param_1 == -0x1fe;
        }
        else {
          if (param_1 == -0x1c2) {
            return 0x1b;
          }
          uVar2 = 7;
          bVar1 = param_1 == -0x1a4;
        }
      }
    }
    else {
      if (param_1 == -0xd2) {
        return 0xd;
      }
      if (param_1 < -0xd1) {
        if (param_1 == -300) {
          return 5;
        }
        if (param_1 < -299) {
          if (param_1 == -0x168) {
            return 6;
          }
          uVar2 = 0xf;
          bVar1 = param_1 == -0x14a;
        }
        else {
          if (param_1 == -0x10e) {
            return 0xe;
          }
          uVar2 = 4;
          bVar1 = param_1 == -0xf0;
        }
      }
      else {
        if (param_1 == -0x78) {
          return 2;
        }
        if (-0x78 < param_1) {
          if (param_1 == -0x3c) {
            return 1;
          }
          if (param_1 != -0x1e) {
            if (param_1 != -0x5a) {
              return 0;
            }
            return 0xb;
          }
          return 10;
        }
        if (param_1 == -0xb4) {
          return 3;
        }
        uVar2 = 0xc;
        bVar1 = param_1 == -0x96;
      }
    }
  }
  else {
    if (param_1 == 0x1a4) {
      return 0x19;
    }
    if (param_1 < 0x1a5) {
      if (param_1 == 0xd2) {
        return 0x3c;
      }
      if (param_1 < 0xd3) {
        if (param_1 == 0x78) {
          return 0x24;
        }
        if (param_1 < 0x79) {
          if (param_1 == 0x3c) {
            return 0x25;
          }
          uVar2 = 0x3e;
          bVar1 = param_1 == 0x5a;
        }
        else {
          if (param_1 == 0x96) {
            return 0x3d;
          }
          uVar2 = 0x23;
          bVar1 = param_1 == 0xb4;
        }
      }
      else {
        if (param_1 == 300) {
          return 0x21;
        }
        if (300 < param_1) {
          if (param_1 == 0x168) {
            return 0x20;
          }
          if (param_1 != 0x186) {
            if (param_1 != 0x14a) {
              return 0;
            }
            return 0x3a;
          }
          return 0x2f;
        }
        if (param_1 == 0xf0) {
          return 0x22;
        }
        uVar2 = 0x3b;
        bVar1 = param_1 == 0x10e;
      }
    }
    else {
      if (param_1 == 600) {
        return 0x16;
      }
      if (param_1 < 0x259) {
        if (param_1 == 0x1fe) {
          return 0x2d;
        }
        if (param_1 < 0x1ff) {
          if (param_1 == 0x1c2) {
            return 0x2e;
          }
          uVar2 = 0x18;
          bVar1 = param_1 == 0x1e0;
        }
        else {
          if (param_1 == 0x21c) {
            return 0x17;
          }
          uVar2 = 0x2c;
          bVar1 = param_1 == 0x23a;
        }
      }
      else {
        if (param_1 == 0x2b2) {
          return 0x2a;
        }
        if (0x2b2 < param_1) {
          if (param_1 == 0x2fd) {
            return 0x32;
          }
          if (param_1 != 0x30c) {
            if (param_1 != 0x2d0) {
              return 0;
            }
            return 0x14;
          }
          return 0x13;
        }
        if (param_1 == 0x276) {
          return 0x2b;
        }
        uVar2 = 0x15;
        bVar1 = param_1 == 0x294;
      }
    }
  }
  if (!bVar1) {
    return 0;
  }
  return uVar2;
}

