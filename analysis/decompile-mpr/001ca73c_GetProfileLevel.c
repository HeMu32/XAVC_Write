// mpr::GetProfileLevel
// Ghidra address: 001ca73c

/* mpr::GetProfileLevel(libXavcMp4::CodecSpecifcInfo) */

undefined1  [16] mpr::GetProfileLevel(uint param_1)

{
  bool bVar1;
  int iVar2;
  ulong uVar3;
  undefined8 uVar4;
  undefined1 auVar5 [16];
  
  uVar3 = 0x24b7;
  uVar4 = 0x3b;
  if (param_1 == 0x24b7) goto LAB_001ca928;
  if (param_1 < 0x24b8) {
    uVar3 = 0x2278;
    uVar4 = 0x2c;
    if (param_1 == 0x2278) goto LAB_001ca928;
    if (param_1 < 0x2279) {
      uVar3 = 0x2196;
      uVar4 = 0x22;
      if (param_1 == 0x2196) goto LAB_001ca928;
      if (0x2196 < param_1) {
        uVar3 = 0x21b4;
        uVar4 = 0x27;
        if (param_1 == 0x21b4) goto LAB_001ca928;
        if (param_1 < 0x21b5) {
          uVar3 = 0x2199;
          uVar4 = 0x24;
          if (param_1 == 0x2199) goto LAB_001ca928;
          uVar4 = 0x26;
          uVar3 = 0x219c;
        }
        else {
          uVar3 = 0x21b7;
          uVar4 = 0x28;
          if (param_1 == 0x21b7) goto LAB_001ca928;
          uVar4 = 0x29;
          uVar3 = 0x21ba;
        }
        goto LAB_001ca7c0;
      }
      uVar4 = 0x2d;
      if (param_1 == 0x27b) goto LAB_001ca928;
      if (0x27b < param_1) {
        uVar3 = 0x2178;
        uVar4 = 0x20;
        if (param_1 == 0x2178) goto LAB_001ca928;
        uVar4 = 0x21;
        uVar3 = 0x217b;
        goto LAB_001ca7c0;
      }
      uVar4 = 0x1f;
      if (param_1 == 0x178) goto LAB_001ca928;
      bVar1 = param_1 == 0x278;
      uVar4 = 0x2b;
    }
    else {
      uVar3 = 0x22b7;
      uVar4 = 0x38;
      if (param_1 == 0x22b7) goto LAB_001ca928;
      if (param_1 < 0x22b8) {
        uVar3 = 0x2299;
        uVar4 = 0x32;
        if (param_1 == 0x2299) goto LAB_001ca928;
        if (param_1 < 0x229a) {
          uVar3 = 0x227b;
          uVar4 = 0x2e;
          if (param_1 == 0x227b) goto LAB_001ca928;
          uVar4 = 0x2f;
          uVar3 = 0x2296;
        }
        else {
          uVar3 = 0x229c;
          uVar4 = 0x35;
          if (param_1 == 0x229c) goto LAB_001ca928;
          uVar4 = 0x37;
          uVar3 = 0x22b4;
        }
      }
      else {
        uVar3 = 0x2499;
        uVar4 = 0x33;
        if (param_1 == 0x2499) goto LAB_001ca928;
        if (param_1 < 0x249a) {
          uVar3 = 0x22ba;
          uVar4 = 0x39;
          if (param_1 == 0x22ba) goto LAB_001ca928;
          uVar4 = 0x30;
          uVar3 = 0x2496;
        }
        else {
          uVar3 = 0x249c;
          uVar4 = 0x36;
          if (param_1 == 0x249c) goto LAB_001ca928;
          uVar4 = 0x3a;
          uVar3 = 0x24b4;
        }
      }
LAB_001ca7c0:
      bVar1 = param_1 == (uint)uVar3;
    }
    if (bVar1) goto LAB_001ca928;
  }
  else {
    uVar4 = 0x10;
    uVar3 = 0x1640028;
    if (param_1 == 0x1640028) goto LAB_001ca928;
    if (0x1640028 < param_1) {
      uVar4 = 0x16;
      uVar3 = 0x164003c;
      if (param_1 == 0x164003c) goto LAB_001ca928;
      if (param_1 < 0x164003d) {
        uVar4 = 0x13;
        uVar3 = 0x1640032;
        if (param_1 == 0x1640032) goto LAB_001ca928;
        if (param_1 < 0x1640033) {
          uVar4 = 0x11;
          iVar2 = 0x1640029;
          uVar3 = 0x1640029;
          if (param_1 == 0x1640029) goto LAB_001ca928;
          uVar4 = 0x12;
        }
        else {
          uVar4 = 0x14;
          uVar3 = 0x1640033;
          iVar2 = 0x1640033;
          if (param_1 == 0x1640033) goto LAB_001ca928;
          uVar4 = 0x15;
        }
      }
      else {
        uVar4 = 0x1b;
        uVar3 = 0x17a0033;
        if (param_1 == 0x17a0033) goto LAB_001ca928;
        if (0x17a0033 < param_1) {
          uVar4 = 0x1c;
          uVar3 = 0x17a0034;
          if (param_1 == 0x17a0034) goto LAB_001ca928;
          uVar4 = 0x1d;
          uVar3 = 0x17a003c;
          goto LAB_001ca7c0;
        }
        uVar4 = 0x18;
        uVar3 = 0x17a0029;
        iVar2 = 0x17a0029;
        if (param_1 == 0x17a0029) goto LAB_001ca928;
        uVar4 = 0x19;
      }
LAB_001ca980:
      uVar3 = (ulong)(iVar2 + 1);
      goto LAB_001ca7c0;
    }
    uVar4 = 4;
    uVar3 = 0x14d0028;
    if (param_1 == 0x14d0028) goto LAB_001ca928;
    if (0x14d0028 < param_1) {
      uVar4 = 0;
      uVar3 = 0x14d4015;
      if (param_1 == 0x14d4015) goto LAB_001ca928;
      if (param_1 < 0x14d4016) {
        uVar4 = 5;
        iVar2 = 0x14d0029;
        uVar3 = 0x14d0029;
        if (param_1 == 0x14d0029) goto LAB_001ca928;
        uVar4 = 6;
      }
      else {
        uVar4 = 1;
        iVar2 = 0x14d401e;
        uVar3 = 0x14d401e;
        if (param_1 == 0x14d401e) goto LAB_001ca928;
        uVar4 = 2;
      }
      goto LAB_001ca980;
    }
    uVar4 = 0x1a;
    uVar3 = 0x7a1032;
    if (param_1 == 0x7a1032) goto LAB_001ca928;
    if (param_1 < 0x7a1033) {
      uVar4 = 0x18;
      uVar3 = (ulong)(param_1 - 0x7a1029);
      if (param_1 - 0x7a1029 == 0) goto LAB_001ca928;
      uVar4 = 0x19;
      param_1 = param_1 - 0x7a102a;
    }
    else {
      uVar4 = 0x1b;
      uVar3 = (ulong)(param_1 - 0x7a1033);
      if (param_1 - 0x7a1033 == 0) goto LAB_001ca928;
      uVar4 = 0x1c;
      param_1 = param_1 - 0x7a1034;
    }
    uVar3 = (ulong)param_1;
    if (param_1 == 0) goto LAB_001ca928;
  }
  uVar4 = 0x3d;
LAB_001ca928:
  auVar5._8_8_ = uVar3;
  auVar5._0_8_ = uVar4;
  return auVar5;
}

