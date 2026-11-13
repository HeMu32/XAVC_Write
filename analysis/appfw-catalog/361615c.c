// ELF VMA 0x361615c; Ghidra bias 0x100000

/* WARNING: Type propagation algorithm not settling */

byte appfw_361615c(undefined8 *param_1,undefined4 param_2)

{
  long lVar1;
  uint uVar2;
  bool bVar3;
  byte bVar4;
  byte bVar5;
  char cVar6;
  char cVar7;
  char cVar8;
  byte bVar9;
  byte bVar10;
  ulong uVar11;
  undefined8 *puVar12;
  int *piVar13;
  undefined8 uVar14;
  undefined1 *puVar15;
  ulong uVar16;
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
  
  bVar4 = func_0x01815720(*param_1);
  bVar3 = true;
  bVar5 = func_0x01815720(param_1[1],param_2);
  for (uVar16 = 0; lVar1 = *(long *)param_1[2],
      uVar11 = (((long *)param_1[2])[1] - lVar1 >> 3) * -0x3333333333333333,
      uVar16 <= uVar11 && uVar11 - uVar16 != 0; uVar16 = (ulong)((int)uVar16 + 1)) {
    uStack_2c0 = *(undefined8 *)(lVar1 + uVar16 * 0x28);
    func_0x03716114(&uStack_2b8,lVar1 + uVar16 * 0x28 + 8);
    cVar6 = func_0x01817ff0(&uStack_2c0,param_2);
    if (cVar6 != '\0') {
      func_0x02681698(&uStack_2b8);
      goto LAB_0371621c;
    }
    func_0x02681698(&uStack_2b8);
    bVar3 = false;
  }
  if (!bVar3) {
    return 0;
  }
LAB_0371621c:
  bVar3 = true;
  for (uVar16 = 0; lVar1 = *(long *)param_1[3],
      uVar11 = (((long *)param_1[3])[1] - lVar1 >> 3) * -0x3333333333333333,
      uVar16 <= uVar11 && uVar11 - uVar16 != 0; uVar16 = (ulong)((int)uVar16 + 1)) {
    uStack_2c0 = *(undefined8 *)(lVar1 + uVar16 * 0x28);
    func_0x03716114(&uStack_2b8,lVar1 + uVar16 * 0x28 + 8);
    cVar6 = func_0x01817ff0(&uStack_2c0,param_2);
    if (cVar6 != '\0') {
      func_0x02681698(&uStack_2b8);
      goto LAB_037162c0;
    }
    func_0x02681698(&uStack_2b8);
    bVar3 = false;
  }
  if (!bVar3) {
    return 0;
  }
LAB_037162c0:
  bVar3 = true;
  for (uVar16 = 0; lVar1 = *(long *)param_1[4],
      uVar11 = (((long *)param_1[4])[1] - lVar1 >> 3) * -0x5555555555555555,
      uVar16 <= uVar11 && uVar11 - uVar16 != 0; uVar16 = (ulong)((int)uVar16 + 1)) {
    puVar12 = (undefined8 *)(lVar1 + uVar16 * 0x18);
    uStack_2c0 = *puVar12;
    uStack_2b8 = puVar12[1];
    uStack_2b0 = puVar12[2];
    cVar6 = func_0x01815290(&uStack_2c0,param_2);
    if (cVar6 != '\0') goto LAB_03716330;
    bVar3 = false;
  }
  if (!bVar3) {
    return 0;
  }
LAB_03716330:
  bVar3 = true;
  for (uVar16 = 0; lVar1 = *(long *)param_1[5],
      uVar11 = (((long *)param_1[5])[1] - lVar1 >> 3) * -0x5555555555555555,
      uVar16 <= uVar11 && uVar11 - uVar16 != 0; uVar16 = (ulong)((int)uVar16 + 1)) {
    puVar12 = (undefined8 *)(lVar1 + uVar16 * 0x18);
    uStack_2d8 = *puVar12;
    uStack_2d0 = puVar12[1];
    uStack_2c8 = puVar12[2];
    cVar6 = func_0x01815290(&uStack_2d8,param_2);
    if (cVar6 != '\0') {
      puVar12 = (undefined8 *)(*(long *)param_1[6] + uVar16 * 0x18);
      uStack_2c0 = *puVar12;
      uStack_2b8 = puVar12[1];
      uStack_2b0 = puVar12[2];
      cVar6 = func_0x018185d0(&uStack_2c0,param_2);
      if (cVar6 != '\0') goto LAB_037163d4;
    }
    bVar3 = false;
  }
  if (!bVar3) {
    return 0;
  }
LAB_037163d4:
  if (*(char *)param_1[7] == '\0') {
    bVar9 = 1;
  }
  else {
    uVar2 = *(uint *)((char *)param_1[7] + 4);
    bVar10 = bVar4;
    if ((uVar2 & 1) == 0) {
      bVar10 = 0;
    }
    bVar9 = bVar10 | bVar5;
    if ((uVar2 & 2) == 0) {
      bVar9 = bVar10;
    }
    if (bVar9 == 0) {
      return 0;
    }
  }
  for (uVar16 = 0; lVar1 = *(long *)param_1[8],
      uVar11 = (((long *)param_1[8])[1] - lVar1 >> 3) * -0x3333333333333333,
      uVar16 <= uVar11 && uVar11 - uVar16 != 0; uVar16 = (ulong)((int)uVar16 + 1)) {
    func_0x03715c80(&uStack_2c0,lVar1 + uVar16 * 0x28);
    cVar6 = func_0x01817f70(&uStack_2c0,param_2);
    if (cVar6 != '\0') {
      func_0x02681698(&uStack_2b8);
      goto LAB_03716470;
    }
    func_0x02681698(&uStack_2b8);
    bVar9 = 0;
  }
  if (bVar9 == 0) {
    return 0;
  }
LAB_03716470:
  if (*(char *)param_1[9] != '\0') {
    if ((((*(uint *)((char *)param_1[9] + 4) >> 1 & 1) == 0) ||
        (cVar6 = func_0x01815420(param_1[10],param_2), cVar6 == '\0')) ||
       (cVar6 = func_0x01815420(param_1[0xb],param_2), cVar6 == '\0')) {
      bVar9 = 0;
    }
    else {
      bVar9 = func_0x01815420(param_1[0xc],param_2);
    }
    if ((*(uint *)(param_1[9] + 4) >> 3 & 1) != 0) {
      cVar6 = func_0x01815420(param_1[0xd],param_2);
      bVar10 = 0;
      if (cVar6 != '\0') {
        bVar10 = func_0x01815420(param_1[0xe],param_2);
      }
      bVar9 = bVar9 | bVar10;
    }
    if ((*(uint *)(param_1[9] + 4) >> 4 & 1) != 0) {
      cVar6 = func_0x01815420(param_1[0xf],param_2);
      bVar10 = 0;
      if (cVar6 != '\0') {
        bVar10 = func_0x01815420(param_1[0x10],param_2);
      }
      bVar9 = bVar9 | bVar10;
    }
    if ((*(uint *)(param_1[9] + 4) & 1) != 0) {
      cVar6 = func_0x01815420(param_1[0x11],param_2);
      bVar10 = 0;
      if (cVar6 != '\0') {
        bVar10 = func_0x01815420(param_1[0x12],param_2);
      }
      bVar9 = bVar9 | bVar10;
    }
    if ((*(uint *)(param_1[9] + 4) >> 2 & 1) != 0) {
      cVar6 = func_0x01815420(param_1[0x13],param_2);
      bVar10 = 0;
      if (cVar6 != '\0') {
        bVar10 = func_0x01815420(param_1[0x14],param_2);
      }
      bVar9 = bVar9 | bVar10;
    }
    if (bVar9 == 0) {
      return 0;
    }
  }
  bVar3 = true;
  for (uVar16 = 0; lVar1 = *(long *)param_1[0x15],
      uVar11 = (((long *)param_1[0x15])[1] - lVar1 >> 3) * -0x5555555555555555,
      uVar16 <= uVar11 && uVar11 - uVar16 != 0; uVar16 = (ulong)((int)uVar16 + 1)) {
    puVar12 = (undefined8 *)(lVar1 + uVar16 * 0x18);
    uStack_2c0 = *puVar12;
    uStack_2b8 = puVar12[1];
    uStack_2b0 = puVar12[2];
    cVar6 = func_0x01815330(&uStack_2c0,param_2);
    if (cVar6 != '\0') goto LAB_0371660c;
    bVar3 = false;
  }
  if (!bVar3) {
    return 0;
  }
LAB_0371660c:
  if (bVar4 == 0) {
    if (*(char *)param_1[0x18] != '\0') {
      return 0;
    }
  }
  else {
    bVar3 = true;
    for (uVar16 = 0; lVar1 = *(long *)param_1[0x16],
        uVar11 = (((long *)param_1[0x16])[1] - lVar1 >> 3) * -0x3333333333333333,
        uVar16 <= uVar11 && uVar11 - uVar16 != 0; uVar16 = (ulong)((int)uVar16 + 1)) {
      uStack_2c0 = *(undefined8 *)(lVar1 + uVar16 * 0x28);
      func_0x03715c8c(&uStack_2b8,lVar1 + uVar16 * 0x28 + 8);
      cVar6 = func_0x01816d00(&uStack_2c0,param_2);
      if (cVar6 != '\0') {
        func_0x02681698(&uStack_2b8);
        goto LAB_0371668c;
      }
      func_0x02681698(&uStack_2b8);
      bVar3 = false;
    }
    if (!bVar3) {
      return 0;
    }
LAB_0371668c:
    bVar3 = true;
    for (uVar16 = 0; lVar1 = *(long *)param_1[0x17],
        uVar11 = (((long *)param_1[0x17])[1] - lVar1 >> 3) * -0x3333333333333333,
        uVar16 <= uVar11 && uVar11 - uVar16 != 0; uVar16 = (ulong)((int)uVar16 + 1)) {
      uStack_2c0 = *(undefined8 *)(lVar1 + uVar16 * 0x28);
      func_0x03715c8c(&uStack_2b8,lVar1 + uVar16 * 0x28 + 8);
      cVar6 = func_0x01816d00(&uStack_2c0,param_2);
      if (cVar6 != '\0') {
        func_0x02681698(&uStack_2b8);
        goto LAB_03716710;
      }
      func_0x02681698(&uStack_2b8);
      bVar3 = false;
    }
    if (!bVar3) {
      return 0;
    }
  }
LAB_03716710:
  bVar3 = true;
  for (uVar16 = 0; lVar1 = *(long *)param_1[0x19],
      uVar11 = (((long *)param_1[0x19])[1] - lVar1 >> 3) * -0x5555555555555555,
      uVar16 <= uVar11 && uVar11 - uVar16 != 0; uVar16 = (ulong)((int)uVar16 + 1)) {
    puVar12 = (undefined8 *)(lVar1 + uVar16 * 0x18);
    uStack_2c0 = *puVar12;
    uStack_2b8 = puVar12[1];
    uStack_2b0 = puVar12[2];
    cVar6 = func_0x01815420(&uStack_2c0,param_2);
    if (cVar6 != '\0') goto LAB_03716780;
    bVar3 = false;
  }
  if (!bVar3) {
    return 0;
  }
LAB_03716780:
  if (bVar5 != 0) {
    bVar3 = true;
    for (uVar16 = 0; lVar1 = *(long *)param_1[0x1a],
        uVar11 = (((long *)param_1[0x1a])[1] - lVar1 >> 3) * -0x3333333333333333,
        uVar16 <= uVar11 && uVar11 - uVar16 != 0; uVar16 = (ulong)((int)uVar16 + 1)) {
      func_0x03715c80(&uStack_2c0,lVar1 + uVar16 * 0x28);
      cVar6 = func_0x01817f70(&uStack_2c0,param_2);
      if (cVar6 != '\0') {
        func_0x02681698(&uStack_2b8);
        goto LAB_037167f0;
      }
      func_0x02681698(&uStack_2b8);
      bVar3 = false;
    }
    if (!bVar3) {
      return 0;
    }
  }
LAB_037167f0:
  if (*(char *)param_1[0x1b] != '\0') {
    if (bVar5 == 0) {
      return 0;
    }
    uVar2 = *(uint *)((char *)param_1[0x1b] + 4);
    if ((uVar2 & 3) == 3) {
      cVar6 = func_0x01815420(param_1[0x1c],param_2);
      if (cVar6 != '\0') goto LAB_037167fc;
LAB_03716954:
      uVar14 = param_1[0x1e];
    }
    else {
      if ((uVar2 & 1) == 0) {
        if ((uVar2 >> 1 & 1) != 0) {
          cVar6 = func_0x01815420(param_1[0x1d],param_2);
          if (cVar6 == '\0') {
            return 0;
          }
          goto LAB_03716954;
        }
        uVar14 = param_1[0x1d];
      }
      else {
        uVar14 = param_1[0x1c];
      }
      cVar6 = func_0x01815420(uVar14,param_2);
      if (cVar6 == '\0') {
        return 0;
      }
      uVar14 = param_1[0x1f];
    }
    cVar6 = func_0x01815420(uVar14,param_2);
    if (cVar6 == '\0') {
      return 0;
    }
  }
LAB_037167fc:
  if ((((long *)param_1[0x20])[1] - *(long *)param_1[0x20] >> 4) * -0x1084210842108421 != 0) {
    if (bVar4 == 0) {
      if (bVar5 == 0) {
        return 0;
      }
      uVar16 = 0;
      do {
        lVar1 = *(long *)param_1[0x20];
        uVar11 = (((long *)param_1[0x20])[1] - lVar1 >> 4) * -0x1084210842108421;
        if (uVar11 < uVar16 || uVar11 - uVar16 == 0) {
          return 0;
        }
        func_0x03715d54(&uStack_2c0,lVar1 + uVar16 * 0x1f0);
        bVar9 = func_0x01817f70(auStack_178,param_2);
        bVar10 = func_0x01817f70(auStack_128,param_2);
        puVar15 = auStack_150;
        if ((bVar9 & bVar10) == 0) {
          if (bVar10 != 0) {
            puVar15 = auStack_100;
LAB_03716bac:
            cVar6 = func_0x01815720(puVar15,param_2);
            goto joined_r0x03716bb4;
          }
          if (bVar9 != 0) goto LAB_03716bac;
        }
        else {
          if (aiStack_d8[0] == 2) {
            puVar15 = auStack_100;
          }
          else if (aiStack_d8[0] != 1) {
            cVar6 = func_0x01815720(auStack_100,param_2);
            if (cVar6 == '\0') goto LAB_03716bac;
            goto LAB_03716a8c;
          }
          cVar6 = func_0x01815720(puVar15,param_2);
joined_r0x03716bb4:
          if (cVar6 != '\0') goto LAB_03716a8c;
        }
        uVar16 = (ulong)((int)uVar16 + 1);
        func_0x03708c88(&uStack_2c0);
      } while( true );
    }
    uVar16 = 0;
    do {
      lVar1 = *(long *)param_1[0x20];
      uVar11 = (((long *)param_1[0x20])[1] - lVar1 >> 4) * -0x1084210842108421;
      if (uVar11 < uVar16 || uVar11 - uVar16 == 0) {
        return 0;
      }
      func_0x03715d54(&uStack_2c0,lVar1 + uVar16 * 0x1f0);
      cVar6 = func_0x01817f70(&uStack_2c0,param_2);
      cVar7 = func_0x01817f70(aiStack_270,param_2);
      cVar8 = func_0x01817f70(auStack_220,param_2);
      if (cVar6 == '\0') {
        if (cVar7 != '\0') {
LAB_03716ab8:
          cVar6 = func_0x01815720(auStack_248,param_2);
          if (cVar6 != '\0') goto LAB_03716a8c;
        }
        if (cVar8 != '\0') {
LAB_03716a48:
          puVar15 = auStack_1f8;
          goto LAB_03716a50;
        }
      }
      else {
        if (cVar7 != '\0' || cVar8 != '\0') {
          if (aiStack_180[0] == 0) {
            if (cVar7 != '\0') goto LAB_03716ab8;
            goto LAB_03716a48;
          }
          if (aiStack_180[0] != 1) {
            if (cVar7 != '\0') {
              cVar6 = func_0x01815720(auStack_248,param_2);
              if (cVar6 != '\0') goto LAB_03716a8c;
              if (cVar8 == '\0') goto LAB_03716a68;
            }
            cVar6 = func_0x01815720(auStack_1f8,param_2);
            if (cVar6 != '\0') goto LAB_03716a8c;
          }
        }
LAB_03716a68:
        puVar15 = auStack_298;
LAB_03716a50:
        cVar6 = func_0x01815720(puVar15,param_2);
        if (cVar6 != '\0') goto LAB_03716a8c;
      }
      uVar16 = (ulong)((int)uVar16 + 1);
      func_0x03708c88(&uStack_2c0);
    } while( true );
  }
LAB_03716828:
  if ((((long *)param_1[0x21])[1] - *(long *)param_1[0x21] >> 6) * 0x2e8ba2e8ba2e8ba3 == 0) {
    if (bVar4 == 0) {
LAB_03716d38:
      return *(byte *)param_1[0x22] ^ 1;
    }
LAB_03716f1c:
    uVar16 = 0;
    bVar4 = 1;
    while( true ) {
      lVar1 = *(long *)param_1[0x23];
      uVar11 = (((long *)param_1[0x23])[1] - lVar1 >> 3) * -0x5555555555555555;
      if (uVar11 < uVar16 || uVar11 - uVar16 == 0) {
        return bVar4;
      }
      puVar12 = (undefined8 *)(lVar1 + uVar16 * 0x18);
      uStack_2c0 = *puVar12;
      uStack_2b8 = puVar12[1];
      uStack_2b0 = puVar12[2];
      bVar4 = func_0x01815420(&uStack_2c0,param_2);
      if (bVar4 != 0) break;
      uVar16 = (ulong)((int)uVar16 + 1);
      bVar4 = 0;
    }
    return bVar4;
  }
  if (bVar4 == 0) {
    if (bVar5 != 0) {
      for (uVar16 = 0; lVar1 = *(long *)param_1[0x21],
          uVar11 = (((long *)param_1[0x21])[1] - lVar1 >> 6) * 0x2e8ba2e8ba2e8ba3,
          uVar16 <= uVar11 && uVar11 - uVar16 != 0; uVar16 = (ulong)((int)uVar16 + 1)) {
        func_0x03716058(&uStack_2c0,lVar1 + uVar16 * 0x2c0);
        bVar4 = func_0x01817f70(auStack_150,param_2);
        bVar5 = func_0x01817f70(aiStack_d8,param_2);
        if ((bVar4 & bVar5) == 0) {
          if (cStack_8 != '\0') {
            if (bVar5 != 0) {
LAB_03716d1c:
              cVar6 = func_0x01815720(auStack_b0,param_2);
              if (cVar6 != '\0') goto LAB_03716d30;
LAB_03716edc:
              puVar15 = auStack_88;
              goto LAB_03716ee4;
            }
            if (bVar4 == 0) goto LAB_03716ef0;
LAB_03716d98:
            puVar15 = auStack_128;
LAB_03716da0:
            cVar6 = func_0x01815720(puVar15,param_2);
            if (cVar6 == '\0') goto LAB_03716dac;
            goto LAB_03716d30;
          }
          if ((iStack_10 != 3) &&
             ((cVar6 = func_0x01817f70(auStack_60,param_2), cVar6 != '\0' ||
              (cVar6 = func_0x01817f70(auStack_38,param_2), cVar6 != '\0')))) {
            if (bVar5 != 0) goto LAB_03716edc;
            if (bVar4 == 0) goto LAB_03716ef0;
LAB_03716dac:
            puVar15 = auStack_100;
LAB_03716ee4:
            cVar6 = func_0x01815720(puVar15,param_2);
            goto joined_r0x03716fa0;
          }
          if (bVar5 != 0) {
            puVar15 = auStack_b0;
            goto LAB_03716ee4;
          }
          if (bVar4 != 0) {
LAB_03716f0c:
            puVar15 = auStack_128;
            goto LAB_03716ee4;
          }
        }
        else {
          if (iStack_c == 2) {
            if (cStack_8 != '\0') goto LAB_03716d1c;
            if ((iStack_10 == 3) ||
               ((cVar6 = func_0x01817f70(auStack_60,param_2), cVar6 == '\0' &&
                (cVar6 = func_0x01817f70(auStack_38,param_2), cVar6 == '\0')))) {
              puVar15 = auStack_b0;
            }
            else {
              puVar15 = auStack_88;
            }
          }
          else {
            if (iStack_c != 1) {
              if (cStack_8 == '\0') {
                if ((iStack_10 != 3) &&
                   ((cVar6 = func_0x01817f70(auStack_60,param_2), cVar6 != '\0' ||
                    (cVar6 = func_0x01817f70(auStack_38,param_2), cVar6 != '\0'))))
                goto LAB_03716e28;
                cVar6 = func_0x01815720(auStack_b0,param_2);
                if (cVar6 == '\0') goto LAB_03716f0c;
              }
              else {
                cVar6 = func_0x01815720(auStack_b0,param_2);
                if ((cVar6 == '\0') && (cVar6 = func_0x01815720(auStack_128,param_2), cVar6 == '\0')
                   ) {
LAB_03716e28:
                  puVar15 = auStack_88;
                  goto LAB_03716da0;
                }
              }
              goto LAB_03716d30;
            }
            if (cStack_8 != '\0') goto LAB_03716d98;
            if ((iStack_10 == 3) ||
               ((cVar6 = func_0x01817f70(auStack_60,param_2), cVar6 == '\0' &&
                (cVar6 = func_0x01817f70(auStack_38,param_2), cVar6 == '\0')))) {
              puVar15 = auStack_128;
            }
            else {
              puVar15 = auStack_100;
            }
          }
          cVar6 = func_0x01815720(puVar15,param_2);
joined_r0x03716fa0:
          if (cVar6 != '\0') {
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
    for (uVar16 = 0; lVar1 = *(long *)param_1[0x21],
        uVar11 = (((long *)param_1[0x21])[1] - lVar1 >> 6) * 0x2e8ba2e8ba2e8ba3,
        uVar16 <= uVar11 && uVar11 - uVar16 != 0; uVar16 = (ulong)((int)uVar16 + 1)) {
      func_0x03716058(&uStack_2c0,lVar1 + uVar16 * 0x2c0);
      cVar6 = func_0x01817f70(&uStack_2c0,param_2);
      cVar7 = func_0x01817f70(auStack_248,param_2);
      cVar8 = func_0x01817f70(auStack_1d0,param_2);
      if (cVar6 == '\0') {
        if (cVar7 != '\0') {
LAB_03716c6c:
          cVar6 = func_0x01815720(auStack_220,param_2);
          if ((cVar6 == '\0') && (cVar6 = func_0x01815720(auStack_1f8,param_2), cVar6 == '\0'))
          goto LAB_03716c94;
          goto LAB_03716c14;
        }
LAB_03716c94:
        if (cVar8 != '\0') goto LAB_037168ec;
      }
      else {
        if (cVar7 == '\0' && cVar8 == '\0') {
LAB_03716bdc:
          cVar6 = func_0x01815720(auStack_298,param_2);
          if (cVar6 != '\0') goto LAB_03716c14;
          piVar13 = aiStack_270;
        }
        else {
          if (iStack_158 != 0) {
            if (iStack_158 != 1) {
              if (cVar7 != '\0') {
                cVar6 = func_0x01815720(auStack_220,param_2);
                if ((cVar6 != '\0') || (cVar6 = func_0x01815720(auStack_1f8,param_2), cVar6 != '\0')
                   ) goto LAB_03716c14;
                if (cVar8 == '\0') goto LAB_03716bdc;
              }
              cVar6 = func_0x01815720(auStack_1a8,param_2);
              if ((cVar6 != '\0') || (cVar6 = func_0x01815720(aiStack_180,param_2), cVar6 != '\0'))
              goto LAB_03716c14;
            }
            goto LAB_03716bdc;
          }
          if (cVar7 != '\0') goto LAB_03716c6c;
LAB_037168ec:
          cVar6 = func_0x01815720(auStack_1a8,param_2);
          if (cVar6 != '\0') goto LAB_03716c14;
          piVar13 = aiStack_180;
        }
        cVar6 = func_0x01815720(piVar13,param_2);
        if (cVar6 != '\0') {
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

