// FUN_001b8088
// Ghidra address: 001b8088

uint FUN_001b8088(byte param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (uint)param_1;
  uVar1 = param_1 - 0x30;
  if (9 < (uVar1 & 0xff)) {
    if ((param_1 - 0x61 & 0xff) < 0x1a) {
      uVar2 = param_1 - 0x20 & 0xff;
    }
    uVar1 = uVar2 - 0x37;
    if (5 < uVar2 - 0x41) {
      uVar1 = 0xffffffff;
    }
  }
  return uVar1;
}

