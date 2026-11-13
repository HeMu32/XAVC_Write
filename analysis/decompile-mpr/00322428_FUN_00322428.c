// FUN_00322428
// Ghidra address: 00322428

undefined8 FUN_00322428(uint param_1)

{
  bool bVar1;
  undefined8 uVar2;
  
  if (param_1 != 0x100) {
    if (param_1 < 0x101) {
      if (param_1 == 1) {
        return 3;
      }
      if (param_1 == 0) {
        return 0;
      }
      uVar2 = 2;
      bVar1 = param_1 == 2;
    }
    else {
      if (param_1 == 0x200) {
        return 4;
      }
      if (param_1 < 0x201) {
        uVar2 = 0xb;
        bVar1 = param_1 == 0x101;
      }
      else {
        uVar2 = 2;
        if (param_1 == 0x201) {
          return 2;
        }
        bVar1 = param_1 == 0x10000000;
      }
    }
    if (bVar1) {
      return uVar2;
    }
  }
  return 2;
}

