// FUN_003256fc
// Ghidra address: 003256fc

undefined1  [16] FUN_003256fc(undefined8 param_1,ulong param_2,uint *param_3)

{
  uint *puVar1;
  int *piVar2;
  ushort uVar3;
  short sVar4;
  uint uVar5;
  undefined1 auVar6 [16];
  uint uVar7;
  undefined8 uVar8;
  undefined1 auVar9 [16];
  
  if (*(int *)(param_2 + 0xc) != 0x61766331) {
    if (*(int *)(param_2 + 0xc) == 0x68766331) {
      if (*(int *)(param_2 + 0x18) == 1) {
        sVar4 = *(short *)(param_2 + 0x2a);
        if (sVar4 == 0xf00) {
          uVar7 = *(uint *)(param_2 + 0x24);
          if (uVar7 == 0x320000) {
LAB_00325c6c:
            uVar7 = 0x2299;
            goto LAB_00325774;
          }
          if (uVar7 < 0x320001) {
            if (((uVar7 == 0x190000) || (param_2 = 0x1df853, uVar7 == 0x1df853)) ||
               (param_2 = 0x17f9dc, uVar7 == 0x17f9dc)) {
              uVar7 = 0x2296;
              goto LAB_00325774;
            }
          }
          else {
            if ((uVar7 == 0x640000) || (param_2 = 0x77e14f, uVar7 == 0x77e14f)) {
              uVar7 = 0x229c;
              goto LAB_00325774;
            }
            param_2 = 0x3bf0a6;
            if (uVar7 == 0x3bf0a6) goto LAB_00325c6c;
          }
        }
        else if (sVar4 == 0x1e00) {
          piVar2 = (int *)(param_2 + 0x14);
          param_2 = 200000;
          if (*piVar2 == 200000) {
            uVar7 = 0x22b4;
            goto LAB_00325774;
          }
          param_2 = 400000;
          if (*piVar2 == 400000) {
            uVar7 = 0x22b7;
            goto LAB_00325774;
          }
        }
        else if (sVar4 == 0x780) {
          if (((*(int *)(param_2 + 0x14) == 9000) &&
              (piVar2 = (int *)(param_2 + 0x24), *piVar2 != 0x320000)) &&
             (param_2 = 0x3bf0a6, *piVar2 != 0x3bf0a6)) {
            uVar7 = 0x278;
          }
          else {
            uVar7 = 0x27b;
          }
          goto LAB_00325774;
        }
      }
      else if (*(int *)(param_2 + 0x18) == 2) {
        if (*(short *)(param_2 + 0x2a) == 0xf00) {
          uVar7 = *(uint *)(param_2 + 0x24);
          if (uVar7 == 0x320000) {
LAB_00325d18:
            uVar7 = 0x2499;
            goto LAB_00325774;
          }
          if (uVar7 < 0x320001) {
            if (((uVar7 == 0x190000) || (param_2 = 0x1df853, uVar7 == 0x1df853)) ||
               (param_2 = 0x17f9dc, uVar7 == 0x17f9dc)) {
              uVar7 = 0x2496;
              goto LAB_00325774;
            }
          }
          else {
            if ((uVar7 == 0x640000) || (param_2 = 0x77e14f, uVar7 == 0x77e14f)) {
              uVar7 = 0x249c;
              goto LAB_00325774;
            }
            param_2 = 0x3bf0a6;
            if (uVar7 == 0x3bf0a6) goto LAB_00325d18;
          }
        }
        else if (*(short *)(param_2 + 0x2a) == 0x1e00) {
          piVar2 = (int *)(param_2 + 0x14);
          param_2 = 260000;
          if (*piVar2 == 260000) {
            uVar7 = 0x24b4;
            goto LAB_00325774;
          }
          param_2 = 520000;
          if (*piVar2 == 520000) {
            uVar7 = 0x24b7;
            goto LAB_00325774;
          }
        }
      }
    }
    goto LAB_00325720;
  }
  uVar3 = *(ushort *)(param_2 + 0x2a);
  if (uVar3 == 0x5a0) goto LAB_0032582c;
  if (uVar3 < 0x5a1) {
    if (uVar3 == 800) {
      uVar7 = 0x2a;
    }
    else if (uVar3 == 0x500) {
      uVar7 = *(uint *)(param_2 + 0x24);
      param_2 = 0x77e14f;
      if (uVar7 == 0x77e14f) {
LAB_003258a8:
        uVar7 = 0x2a;
        goto LAB_003258ac;
      }
      if (uVar7 < 0x77e150) {
        if (uVar7 == 0x640000) goto LAB_003258a8;
      }
      else if ((uVar7 == 0xc80000) || (param_2 = 0xefc29f, uVar7 == 0xefc29f)) goto LAB_0032584c;
LAB_0032582c:
      uVar7 = 0x28;
    }
    else {
      if (uVar3 != 0x280) goto LAB_00325720;
      piVar2 = (int *)(param_2 + 0x24);
      if ((*piVar2 == 0x320000) || (param_2 = 0x3bf0a6, *piVar2 == 0x3bf0a6)) {
        uVar7 = 0x401f;
      }
      else {
        uVar7 = 0x401e;
      }
    }
LAB_00325770:
    uVar7 = uVar7 | 0x14d0000;
    goto LAB_00325774;
  }
  if ((uVar3 == 0xf00) || (uVar3 == 0x1000)) {
    uVar7 = *(uint *)(param_2 + 0x24);
    if (uVar7 == 0x3bf0a6) {
LAB_00325a58:
      if (*(int *)(param_2 + 0x34) != 0) goto LAB_00325b3c;
      if ((*(long *)(param_2 + 0x18) == 0xa00000002) &&
         (puVar1 = (uint *)(param_2 + 0x14), param_2 = (ulong)*puVar1, *puVar1 == 200000)) {
        uVar7 = 0x34;
        goto LAB_003258a0;
      }
      uVar7 = 0x34;
    }
    else {
      if (uVar7 < 0x3bf0a7) {
        if (uVar7 == 0x320000) goto LAB_00325a58;
      }
      else if ((uVar7 == 0x640000) || (uVar7 == 0x77e14f)) {
        if ((*(long *)(param_2 + 0x18) == 0xa00000002) &&
           (puVar1 = (uint *)(param_2 + 0x14), param_2 = (ulong)*puVar1, *puVar1 == 280000)) {
          uVar7 = 0x3c;
          goto LAB_003258a0;
        }
        uVar7 = 0x3c;
        goto LAB_003258ac;
      }
      if (*(int *)(param_2 + 0x34) != 0) {
        uVar8 = 3;
        if (*(int *)(param_2 + 0x34) != 1) goto LAB_00325724;
        uVar7 = *(uint *)(param_2 + 0x14);
        param_2 = 0x5dc00;
        if (uVar7 != 0x5dc00) {
          if (uVar7 < 0x5dc01) {
            param_2 = 250000;
            if (uVar7 != 250000) {
              param_2 = 300000;
              if (uVar7 != 300000) {
                uVar5 = 240000;
                goto LAB_00325aec;
              }
              if (uVar3 == 0x1000) goto LAB_00325b3c;
            }
          }
          else {
            param_2 = 480000;
            if (uVar7 != 480000) {
              if (480000 < uVar7) {
                param_2 = 500000;
                if ((uVar7 != 500000) && (param_2 = 600000, uVar7 != 600000)) goto LAB_00325720;
LAB_00325b3c:
                uVar7 = 0x1034;
                goto LAB_003258cc;
              }
              uVar5 = 400000;
LAB_00325aec:
              param_2 = (ulong)uVar5;
              if (uVar7 != uVar5) goto LAB_00325720;
            }
          }
        }
        uVar7 = 0x1033;
        goto LAB_003258cc;
      }
      if ((*(long *)(param_2 + 0x18) == 0xa00000002) &&
         (piVar2 = (int *)(param_2 + 0x14), param_2 = 140000, *piVar2 == 100000 || *piVar2 == 140000
         )) {
        uVar7 = 0x33;
LAB_003258a0:
        uVar7 = uVar7 | 0x17a0000;
        goto LAB_00325774;
      }
LAB_0032584c:
      uVar7 = 0x33;
    }
LAB_003258ac:
    uVar7 = uVar7 | 0x1640000;
  }
  else {
    if (uVar3 != 0x780) goto LAB_00325720;
    uVar7 = *(uint *)(param_2 + 0x24);
    if (uVar7 != 0x3bf0a6) {
      if (uVar7 < 0x3bf0a7) {
        if (uVar7 == 0x320000) goto LAB_00325870;
      }
      else if ((uVar7 == 0x640000) || (uVar7 == 0x77e14f)) goto LAB_0032584c;
      uVar7 = *(uint *)(param_2 + 0x14);
      if (uVar7 == 26000) goto LAB_00325958;
      if (uVar7 < 0x6591) {
        if (uVar7 == 12000) {
LAB_00325918:
          uVar7 = 0x28;
          goto LAB_003258ac;
        }
        if (uVar7 < 0x2ee1) {
          param_2 = 6000;
          if ((uVar7 == 6000) || (param_2 = 9000, uVar7 == 9000)) {
            uVar7 = 0x29;
            goto LAB_00325770;
          }
        }
        else {
          if ((uVar7 == 21000) || (uVar7 == 25000)) goto LAB_00325958;
          param_2 = 16000;
          if (uVar7 == 16000) goto LAB_00325918;
        }
        goto LAB_00325720;
      }
      if (uVar7 == 89000) {
LAB_003259a4:
        uVar7 = 0x1029;
        goto LAB_003258cc;
      }
      if (uVar7 < 0x15ba9) {
        if (((uVar7 == 50000) || (uVar7 == 60000)) || (uVar7 == 40000)) {
LAB_00325958:
          param_2 = *(ulong *)(param_2 + 0x18);
          uVar7 = 0x29;
          if (param_2 != 0xa00000002) goto LAB_003258ac;
          goto LAB_003258a0;
        }
      }
      else {
        if (uVar7 == 100000) goto LAB_00325958;
        param_2 = 0x1b198;
        if ((uVar7 == 0x1b198) || (param_2 = 93000, uVar7 == 93000)) goto LAB_003259a4;
      }
LAB_00325720:
      uVar8 = 3;
LAB_00325724:
      auVar9._8_8_ = param_2;
      auVar9._0_8_ = uVar8;
      return auVar9;
    }
LAB_00325870:
    if (*(int *)(param_2 + 0x34) == 0) {
      if ((*(long *)(param_2 + 0x18) != 0xa00000002) ||
         (puVar1 = (uint *)(param_2 + 0x14), param_2 = (ulong)*puVar1, *puVar1 != 50000))
      goto LAB_003258a8;
      uVar7 = 0x2a;
      goto LAB_003258a0;
    }
    if (*(int *)(param_2 + 0x14) != 0x36330) {
      uVar8 = 0;
      uVar7 = *(int *)(param_2 + 0x14) - 0x2d2a8;
      param_2 = (ulong)uVar7;
      if (uVar7 == 0) {
        *param_3 = 0x7a102a;
        return ZEXT416(0x7a102a) << 0x40;
      }
      goto LAB_00325724;
    }
    uVar7 = 0x1032;
    param_2 = 0x36330;
LAB_003258cc:
    uVar7 = uVar7 | 0x7a0000;
  }
LAB_00325774:
  *param_3 = uVar7;
  auVar6._8_8_ = 0;
  auVar6._0_8_ = param_2;
  return auVar6 << 0x40;
}

