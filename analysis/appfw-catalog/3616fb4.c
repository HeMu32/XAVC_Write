// ELF VMA 0x3616fb4; Ghidra bias 0x100000

/* WARNING: Type propagation algorithm not settling */

byte appfw_3616fb4(undefined8 *param_1,undefined4 *param_2)

{
  long lVar1;
  uint uVar2;
  undefined4 uVar3;
  bool bVar4;
  byte bVar5;
  byte bVar6;
  char cVar7;
  char cVar8;
  char cVar9;
  byte bVar10;
  byte bVar11;
  ulong uVar12;
  undefined8 *puVar13;
  int *piVar14;
  undefined8 uVar15;
  undefined1 *puVar16;
  ulong uVar17;
  undefined8 uStack_2d8;
  undefined8 uStack_2d0;
  undefined8 uStack_2c8;
  undefined8 uStack_2c0;
  undefined8 uStack_2b8;
  undefined8 uStack_2b0;
  undefined1 auStack_298 [40];
  int aiStack_270 [10];
  undefined1 auStack_248 [40];
  undefined1 auStack_220 [40];
  undefined1 auStack_1f8 [40];
  undefined1 auStack_1d0 [40];
  undefined1 auStack_1a8 [40];
  int aiStack_180 [2];
  undefined1 auStack_178 [32];
  int iStack_158;
  undefined1 auStack_150 [40];
  undefined1 auStack_128 [40];
  undefined1 auStack_100 [40];
  int aiStack_d8 [10];
  undefined1 auStack_b0 [40];
  undefined1 auStack_88 [40];
  undefined1 auStack_60 [40];
  undefined1 auStack_38 [40];
  int iStack_10;
  int iStack_c;
  char cStack_8;
  
  uVar3 = *param_2;
  param_1 = (undefined8 *)*param_1;
  bVar5 = func_0x01815720(*param_1);
  bVar4 = true;
  bVar6 = func_0x01815720(param_1[1],uVar3);
  for (uVar17 = 0; lVar1 = *(long *)param_1[2],
      uVar12 = (((long *)param_1[2])[1] - lVar1 >> 3) * -0x3333333333333333,
      uVar17 <= uVar12 && uVar12 - uVar17 != 0; uVar17 = (ulong)((int)uVar17 + 1)) {
    uStack_2c0 = *(undefined8 *)(lVar1 + uVar17 * 0x28);
    func_0x03716114(&uStack_2b8,lVar1 + uVar17 * 0x28 + 8);
    cVar7 = func_0x01817ff0(&uStack_2c0,uVar3);
    if (cVar7 != '\0') {
      func_0x02681698(&uStack_2b8);
      goto LAB_0371621c;
    }
    func_0x02681698(&uStack_2b8);
    bVar4 = false;
  }
  if (!bVar4) {
    return 0;
  }
LAB_0371621c:
  bVar4 = true;
  for (uVar17 = 0; lVar1 = *(long *)param_1[3],
      uVar12 = (((long *)param_1[3])[1] - lVar1 >> 3) * -0x3333333333333333,
      uVar17 <= uVar12 && uVar12 - uVar17 != 0; uVar17 = (ulong)((int)uVar17 + 1)) {
    uStack_2c0 = *(undefined8 *)(lVar1 + uVar17 * 0x28);
    func_0x03716114(&uStack_2b8,lVar1 + uVar17 * 0x28 + 8);
    cVar7 = func_0x01817ff0(&uStack_2c0,uVar3);
    if (cVar7 != '\0') {
      func_0x02681698(&uStack_2b8);
      goto LAB_037162c0;
    }
    func_0x02681698(&uStack_2b8);
    bVar4 = false;
  }
  if (!bVar4) {
    return 0;
  }
LAB_037162c0:
  bVar4 = true;
  for (uVar17 = 0; lVar1 = *(long *)param_1[4],
      uVar12 = (((long *)param_1[4])[1] - lVar1 >> 3) * -0x5555555555555555,
      uVar17 <= uVar12 && uVar12 - uVar17 != 0; uVar17 = (ulong)((int)uVar17 + 1)) {
    puVar13 = (undefined8 *)(lVar1 + uVar17 * 0x18);
    uStack_2c0 = *puVar13;
    uStack_2b8 = puVar13[1];
    uStack_2b0 = puVar13[2];
    cVar7 = func_0x01815290(&uStack_2c0,uVar3);
    if (cVar7 != '\0') goto LAB_03716330;
    bVar4 = false;
  }
  if (!bVar4) {
    return 0;
  }
LAB_03716330:
  bVar4 = true;
  for (uVar17 = 0; lVar1 = *(long *)param_1[5],
      uVar12 = (((long *)param_1[5])[1] - lVar1 >> 3) * -0x5555555555555555,
      uVar17 <= uVar12 && uVar12 - uVar17 != 0; uVar17 = (ulong)((int)uVar17 + 1)) {
    puVar13 = (undefined8 *)(lVar1 + uVar17 * 0x18);
    uStack_2d8 = *puVar13;
    uStack_2d0 = puVar13[1];
    uStack_2c8 = puVar13[2];
    cVar7 = func_0x01815290(&uStack_2d8,uVar3);
    if (cVar7 != '\0') {
      puVar13 = (undefined8 *)(*(long *)param_1[6] + uVar17 * 0x18);
      uStack_2c0 = *puVar13;
      uStack_2b8 = puVar13[1];
      uStack_2b0 = puVar13[2];
      cVar7 = func_0x018185d0(&uStack_2c0,uVar3);
      if (cVar7 != '\0') goto LAB_037163d4;
    }
    bVar4 = false;
  }
  if (!bVar4) {
    return 0;
  }
LAB_037163d4:
  if (*(char *)param_1[7] == '\0') {
    bVar10 = 1;
  }
  else {
    uVar2 = *(uint *)((char *)param_1[7] + 4);
    bVar11 = bVar5;
    if ((uVar2 & 1) == 0) {
      bVar11 = 0;
    }
    bVar10 = bVar11 | bVar6;
    if ((uVar2 & 2) == 0) {
      bVar10 = bVar11;
    }
    if (bVar10 == 0) {
      return 0;
    }
  }
  for (uVar17 = 0; lVar1 = *(long *)param_1[8],
      uVar12 = (((long *)param_1[8])[1] - lVar1 >> 3) * -0x3333333333333333,
      uVar17 <= uVar12 && uVar12 - uVar17 != 0; uVar17 = (ulong)((int)uVar17 + 1)) {
    func_0x03715c80(&uStack_2c0,lVar1 + uVar17 * 0x28);
    cVar7 = func_0x01817f70(&uStack_2c0,uVar3);
    if (cVar7 != '\0') {
      func_0x02681698(&uStack_2b8);
      goto LAB_03716470;
    }
    func_0x02681698(&uStack_2b8);
    bVar10 = 0;
  }
  if (bVar10 == 0) {
    return 0;
  }
LAB_03716470:
  if (*(char *)param_1[9] != '\0') {
    if ((((*(uint *)((char *)param_1[9] + 4) >> 1 & 1) == 0) ||
        (cVar7 = func_0x01815420(param_1[10],uVar3), cVar7 == '\0')) ||
       (cVar7 = func_0x01815420(param_1[0xb],uVar3), cVar7 == '\0')) {
      bVar10 = 0;
    }
    else {
      bVar10 = func_0x01815420(param_1[0xc],uVar3);
    }
    if ((*(uint *)(param_1[9] + 4) >> 3 & 1) != 0) {
      cVar7 = func_0x01815420(param_1[0xd],uVar3);
      bVar11 = 0;
      if (cVar7 != '\0') {
        bVar11 = func_0x01815420(param_1[0xe],uVar3);
      }
      bVar10 = bVar10 | bVar11;
    }
    if ((*(uint *)(param_1[9] + 4) >> 4 & 1) != 0) {
      cVar7 = func_0x01815420(param_1[0xf],uVar3);
      bVar11 = 0;
      if (cVar7 != '\0') {
        bVar11 = func_0x01815420(param_1[0x10],uVar3);
      }
      bVar10 = bVar10 | bVar11;
    }
    if ((*(uint *)(param_1[9] + 4) & 1) != 0) {
      cVar7 = func_0x01815420(param_1[0x11],uVar3);
      bVar11 = 0;
      if (cVar7 != '\0') {
        bVar11 = func_0x01815420(param_1[0x12],uVar3);
      }
      bVar10 = bVar10 | bVar11;
    }
    if ((*(uint *)(param_1[9] + 4) >> 2 & 1) != 0) {
      cVar7 = func_0x01815420(param_1[0x13],uVar3);
      bVar11 = 0;
      if (cVar7 != '\0') {
        bVar11 = func_0x01815420(param_1[0x14],uVar3);
      }
      bVar10 = bVar10 | bVar11;
    }
    if (bVar10 == 0) {
      return 0;
    }
  }
  bVar4 = true;
  for (uVar17 = 0; lVar1 = *(long *)param_1[0x15],
      uVar12 = (((long *)param_1[0x15])[1] - lVar1 >> 3) * -0x5555555555555555,
      uVar17 <= uVar12 && uVar12 - uVar17 != 0; uVar17 = (ulong)((int)uVar17 + 1)) {
    puVar13 = (undefined8 *)(lVar1 + uVar17 * 0x18);
    uStack_2c0 = *puVar13;
    uStack_2b8 = puVar13[1];
    uStack_2b0 = puVar13[2];
    cVar7 = func_0x01815330(&uStack_2c0,uVar3);
    if (cVar7 != '\0') goto LAB_0371660c;
    bVar4 = false;
  }
  if (!bVar4) {
    return 0;
  }
LAB_0371660c:
  if (bVar5 == 0) {
    if (*(char *)param_1[0x18] != '\0') {
      return 0;
    }
  }
  else {
    bVar4 = true;
    for (uVar17 = 0; lVar1 = *(long *)param_1[0x16],
        uVar12 = (((long *)param_1[0x16])[1] - lVar1 >> 3) * -0x3333333333333333,
        uVar17 <= uVar12 && uVar12 - uVar17 != 0; uVar17 = (ulong)((int)uVar17 + 1)) {
      uStack_2c0 = *(undefined8 *)(lVar1 + uVar17 * 0x28);
      func_0x03715c8c(&uStack_2b8,lVar1 + uVar17 * 0x28 + 8);
      cVar7 = func_0x01816d00(&uStack_2c0,uVar3);
      if (cVar7 != '\0') {
        func_0x02681698(&uStack_2b8);
        goto LAB_0371668c;
      }
      func_0x02681698(&uStack_2b8);
      bVar4 = false;
    }
    if (!bVar4) {
      return 0;
    }
LAB_0371668c:
    bVar4 = true;
    for (uVar17 = 0; lVar1 = *(long *)param_1[0x17],
        uVar12 = (((long *)param_1[0x17])[1] - lVar1 >> 3) * -0x3333333333333333,
        uVar17 <= uVar12 && uVar12 - uVar17 != 0; uVar17 = (ulong)((int)uVar17 + 1)) {
      uStack_2c0 = *(undefined8 *)(lVar1 + uVar17 * 0x28);
      func_0x03715c8c(&uStack_2b8,lVar1 + uVar17 * 0x28 + 8);
      cVar7 = func_0x01816d00(&uStack_2c0,uVar3);
      if (cVar7 != '\0') {
        func_0x02681698(&uStack_2b8);
        goto LAB_03716710;
      }
      func_0x02681698(&uStack_2b8);
      bVar4 = false;
    }
    if (!bVar4) {
      return 0;
    }
  }
LAB_03716710:
  bVar4 = true;
  for (uVar17 = 0; lVar1 = *(long *)param_1[0x19],
      uVar12 = (((long *)param_1[0x19])[1] - lVar1 >> 3) * -0x5555555555555555,
      uVar17 <= uVar12 && uVar12 - uVar17 != 0; uVar17 = (ulong)((int)uVar17 + 1)) {
    puVar13 = (undefined8 *)(lVar1 + uVar17 * 0x18);
    uStack_2c0 = *puVar13;
    uStack_2b8 = puVar13[1];
    uStack_2b0 = puVar13[2];
    cVar7 = func_0x01815420(&uStack_2c0,uVar3);
    if (cVar7 != '\0') goto LAB_03716780;
    bVar4 = false;
  }
  if (!bVar4) {
    return 0;
  }
LAB_03716780:
  if (bVar6 != 0) {
    bVar4 = true;
    for (uVar17 = 0; lVar1 = *(long *)param_1[0x1a],
        uVar12 = (((long *)param_1[0x1a])[1] - lVar1 >> 3) * -0x3333333333333333,
        uVar17 <= uVar12 && uVar12 - uVar17 != 0; uVar17 = (ulong)((int)uVar17 + 1)) {
      func_0x03715c80(&uStack_2c0,lVar1 + uVar17 * 0x28);
      cVar7 = func_0x01817f70(&uStack_2c0,uVar3);
      if (cVar7 != '\0') {
        func_0x02681698(&uStack_2b8);
        goto LAB_037167f0;
      }
      func_0x02681698(&uStack_2b8);
      bVar4 = false;
    }
    if (!bVar4) {
      return 0;
    }
  }
LAB_037167f0:
  if (*(char *)param_1[0x1b] != '\0') {
    if (bVar6 == 0) {
      return 0;
    }
    uVar2 = *(uint *)((char *)param_1[0x1b] + 4);
    if ((uVar2 & 3) == 3) {
      cVar7 = func_0x01815420(param_1[0x1c],uVar3);
      if (cVar7 != '\0') goto LAB_037167fc;
LAB_03716954:
      uVar15 = param_1[0x1e];
    }
    else {
      if ((uVar2 & 1) == 0) {
        if ((uVar2 >> 1 & 1) != 0) {
          cVar7 = func_0x01815420(param_1[0x1d],uVar3);
          if (cVar7 == '\0') {
            return 0;
          }
          goto LAB_03716954;
        }
        uVar15 = param_1[0x1d];
      }
      else {
        uVar15 = param_1[0x1c];
      }
      cVar7 = func_0x01815420(uVar15,uVar3);
      if (cVar7 == '\0') {
        return 0;
      }
      uVar15 = param_1[0x1f];
    }
    cVar7 = func_0x01815420(uVar15,uVar3);
    if (cVar7 == '\0') {
      return 0;
    }
  }
LAB_037167fc:
  if ((((long *)param_1[0x20])[1] - *(long *)param_1[0x20] >> 4) * -0x1084210842108421 != 0) {
    if (bVar5 == 0) {
      if (bVar6 == 0) {
        return 0;
      }
      uVar17 = 0;
      do {
        lVar1 = *(long *)param_1[0x20];
        uVar12 = (((long *)param_1[0x20])[1] - lVar1 >> 4) * -0x1084210842108421;
        if (uVar12 < uVar17 || uVar12 - uVar17 == 0) {
          return 0;
        }
        func_0x03715d54(&uStack_2c0,lVar1 + uVar17 * 0x1f0);
        bVar10 = func_0x01817f70(auStack_178,uVar3);
        bVar11 = func_0x01817f70(auStack_128,uVar3);
        puVar16 = auStack_150;
        if ((bVar10 & bVar11) == 0) {
          if (bVar11 != 0) {
            puVar16 = auStack_100;
LAB_03716bac:
            cVar7 = func_0x01815720(puVar16,uVar3);
            goto joined_r0x03716bb4;
          }
          if (bVar10 != 0) goto LAB_03716bac;
        }
        else {
          if (aiStack_d8[0] == 2) {
            puVar16 = auStack_100;
          }
          else if (aiStack_d8[0] != 1) {
            cVar7 = func_0x01815720(auStack_100,uVar3);
            if (cVar7 == '\0') goto LAB_03716bac;
            goto LAB_03716a8c;
          }
          cVar7 = func_0x01815720(puVar16,uVar3);
joined_r0x03716bb4:
          if (cVar7 != '\0') goto LAB_03716a8c;
        }
        uVar17 = (ulong)((int)uVar17 + 1);
        func_0x03708c88(&uStack_2c0);
      } while( true );
    }
    uVar17 = 0;
    do {
      lVar1 = *(long *)param_1[0x20];
      uVar12 = (((long *)param_1[0x20])[1] - lVar1 >> 4) * -0x1084210842108421;
      if (uVar12 < uVar17 || uVar12 - uVar17 == 0) {
        return 0;
      }
      func_0x03715d54(&uStack_2c0,lVar1 + uVar17 * 0x1f0);
      cVar7 = func_0x01817f70(&uStack_2c0,uVar3);
      cVar8 = func_0x01817f70(aiStack_270,uVar3);
      cVar9 = func_0x01817f70(auStack_220,uVar3);
      if (cVar7 == '\0') {
        if (cVar8 != '\0') {
LAB_03716ab8:
          cVar7 = func_0x01815720(auStack_248,uVar3);
          if (cVar7 != '\0') goto LAB_03716a8c;
        }
        if (cVar9 != '\0') {
LAB_03716a48:
          puVar16 = auStack_1f8;
          goto LAB_03716a50;
        }
      }
      else {
        if (cVar8 != '\0' || cVar9 != '\0') {
          if (aiStack_180[0] == 0) {
            if (cVar8 != '\0') goto LAB_03716ab8;
            goto LAB_03716a48;
          }
          if (aiStack_180[0] != 1) {
            if (cVar8 != '\0') {
              cVar7 = func_0x01815720(auStack_248,uVar3);
              if (cVar7 != '\0') goto LAB_03716a8c;
              if (cVar9 == '\0') goto LAB_03716a68;
            }
            cVar7 = func_0x01815720(auStack_1f8,uVar3);
            if (cVar7 != '\0') goto LAB_03716a8c;
          }
        }
LAB_03716a68:
        puVar16 = auStack_298;
LAB_03716a50:
        cVar7 = func_0x01815720(puVar16,uVar3);
        if (cVar7 != '\0') goto LAB_03716a8c;
      }
      uVar17 = (ulong)((int)uVar17 + 1);
      func_0x03708c88(&uStack_2c0);
    } while( true );
  }
LAB_03716828:
  if ((((long *)param_1[0x21])[1] - *(long *)param_1[0x21] >> 6) * 0x2e8ba2e8ba2e8ba3 == 0) {
    if (bVar5 == 0) {
LAB_03716d38:
      return *(byte *)param_1[0x22] ^ 1;
    }
LAB_03716f1c:
    uVar17 = 0;
    bVar5 = 1;
    while( true ) {
      lVar1 = *(long *)param_1[0x23];
      uVar12 = (((long *)param_1[0x23])[1] - lVar1 >> 3) * -0x5555555555555555;
      if (uVar12 < uVar17 || uVar12 - uVar17 == 0) {
        return bVar5;
      }
      puVar13 = (undefined8 *)(lVar1 + uVar17 * 0x18);
      uStack_2c0 = *puVar13;
      uStack_2b8 = puVar13[1];
      uStack_2b0 = puVar13[2];
      bVar5 = func_0x01815420(&uStack_2c0,uVar3);
      if (bVar5 != 0) break;
      uVar17 = (ulong)((int)uVar17 + 1);
      bVar5 = 0;
    }
    return bVar5;
  }
  if (bVar5 == 0) {
    if (bVar6 != 0) {
      for (uVar17 = 0; lVar1 = *(long *)param_1[0x21],
          uVar12 = (((long *)param_1[0x21])[1] - lVar1 >> 6) * 0x2e8ba2e8ba2e8ba3,
          uVar17 <= uVar12 && uVar12 - uVar17 != 0; uVar17 = (ulong)((int)uVar17 + 1)) {
        func_0x03716058(&uStack_2c0,lVar1 + uVar17 * 0x2c0);
        bVar5 = func_0x01817f70(auStack_150,uVar3);
        bVar6 = func_0x01817f70(aiStack_d8,uVar3);
        if ((bVar5 & bVar6) == 0) {
          if (cStack_8 != '\0') {
            if (bVar6 != 0) {
LAB_03716d1c:
              cVar7 = func_0x01815720(auStack_b0,uVar3);
              if (cVar7 != '\0') goto LAB_03716d30;
LAB_03716edc:
              puVar16 = auStack_88;
              goto LAB_03716ee4;
            }
            if (bVar5 == 0) goto LAB_03716ef0;
LAB_03716d98:
            puVar16 = auStack_128;
LAB_03716da0:
            cVar7 = func_0x01815720(puVar16,uVar3);
            if (cVar7 == '\0') goto LAB_03716dac;
            goto LAB_03716d30;
          }
          if ((iStack_10 != 3) &&
             ((cVar7 = func_0x01817f70(auStack_60,uVar3), cVar7 != '\0' ||
              (cVar7 = func_0x01817f70(auStack_38,uVar3), cVar7 != '\0')))) {
            if (bVar6 != 0) goto LAB_03716edc;
            if (bVar5 == 0) goto LAB_03716ef0;
LAB_03716dac:
            puVar16 = auStack_100;
LAB_03716ee4:
            cVar7 = func_0x01815720(puVar16,uVar3);
            goto joined_r0x03716fa0;
          }
          if (bVar6 != 0) {
            puVar16 = auStack_b0;
            goto LAB_03716ee4;
          }
          if (bVar5 != 0) {
LAB_03716f0c:
            puVar16 = auStack_128;
            goto LAB_03716ee4;
          }
        }
        else {
          if (iStack_c == 2) {
            if (cStack_8 != '\0') goto LAB_03716d1c;
            if ((iStack_10 == 3) ||
               ((cVar7 = func_0x01817f70(auStack_60,uVar3), cVar7 == '\0' &&
                (cVar7 = func_0x01817f70(auStack_38,uVar3), cVar7 == '\0')))) {
              puVar16 = auStack_b0;
            }
            else {
              puVar16 = auStack_88;
            }
          }
          else {
            if (iStack_c != 1) {
              if (cStack_8 == '\0') {
                if ((iStack_10 != 3) &&
                   ((cVar7 = func_0x01817f70(auStack_60,uVar3), cVar7 != '\0' ||
                    (cVar7 = func_0x01817f70(auStack_38,uVar3), cVar7 != '\0')))) goto LAB_03716e28;
                cVar7 = func_0x01815720(auStack_b0,uVar3);
                if (cVar7 == '\0') goto LAB_03716f0c;
              }
              else {
                cVar7 = func_0x01815720(auStack_b0,uVar3);
                if ((cVar7 == '\0') && (cVar7 = func_0x01815720(auStack_128,uVar3), cVar7 == '\0'))
                {
LAB_03716e28:
                  puVar16 = auStack_88;
                  goto LAB_03716da0;
                }
              }
              goto LAB_03716d30;
            }
            if (cStack_8 != '\0') goto LAB_03716d98;
            if ((iStack_10 == 3) ||
               ((cVar7 = func_0x01817f70(auStack_60,uVar3), cVar7 == '\0' &&
                (cVar7 = func_0x01817f70(auStack_38,uVar3), cVar7 == '\0')))) {
              puVar16 = auStack_128;
            }
            else {
              puVar16 = auStack_100;
            }
          }
          cVar7 = func_0x01815720(puVar16,uVar3);
joined_r0x03716fa0:
          if (cVar7 != '\0') {
LAB_03716d30:
            func_0x03708d4c(&uStack_2c0);
            goto LAB_03716d38;
          }
        }
LAB_03716ef0:
        func_0x03708d4c(&uStack_2c0);
      }
    }
  }
  else {
    for (uVar17 = 0; lVar1 = *(long *)param_1[0x21],
        uVar12 = (((long *)param_1[0x21])[1] - lVar1 >> 6) * 0x2e8ba2e8ba2e8ba3,
        uVar17 <= uVar12 && uVar12 - uVar17 != 0; uVar17 = (ulong)((int)uVar17 + 1)) {
      func_0x03716058(&uStack_2c0,lVar1 + uVar17 * 0x2c0);
      cVar7 = func_0x01817f70(&uStack_2c0,uVar3);
      cVar8 = func_0x01817f70(auStack_248,uVar3);
      cVar9 = func_0x01817f70(auStack_1d0,uVar3);
      if (cVar7 == '\0') {
        if (cVar8 != '\0') {
LAB_03716c6c:
          cVar7 = func_0x01815720(auStack_220,uVar3);
          if ((cVar7 == '\0') && (cVar7 = func_0x01815720(auStack_1f8,uVar3), cVar7 == '\0'))
          goto LAB_03716c94;
          goto LAB_03716c14;
        }
LAB_03716c94:
        if (cVar9 != '\0') goto LAB_037168ec;
      }
      else {
        if (cVar8 == '\0' && cVar9 == '\0') {
LAB_03716bdc:
          cVar7 = func_0x01815720(auStack_298,uVar3);
          if (cVar7 != '\0') goto LAB_03716c14;
          piVar14 = aiStack_270;
        }
        else {
          if (iStack_158 != 0) {
            if (iStack_158 != 1) {
              if (cVar8 != '\0') {
                cVar7 = func_0x01815720(auStack_220,uVar3);
                if ((cVar7 != '\0') || (cVar7 = func_0x01815720(auStack_1f8,uVar3), cVar7 != '\0'))
                goto LAB_03716c14;
                if (cVar9 == '\0') goto LAB_03716bdc;
              }
              cVar7 = func_0x01815720(auStack_1a8,uVar3);
              if ((cVar7 != '\0') || (cVar7 = func_0x01815720(aiStack_180,uVar3), cVar7 != '\0'))
              goto LAB_03716c14;
            }
            goto LAB_03716bdc;
          }
          if (cVar8 != '\0') goto LAB_03716c6c;
LAB_037168ec:
          cVar7 = func_0x01815720(auStack_1a8,uVar3);
          if (cVar7 != '\0') goto LAB_03716c14;
          piVar14 = aiStack_180;
        }
        cVar7 = func_0x01815720(piVar14,uVar3);
        if (cVar7 != '\0') {
LAB_03716c14:
          func_0x03708d4c(&uStack_2c0);
          goto LAB_03716f1c;
        }
      }
      func_0x03708d4c(&uStack_2c0);
    }
  }
  return 0;
LAB_03716a8c:
  func_0x03708c88(&uStack_2c0);
  goto LAB_03716828;
}

