// ELF VMA 0x3155838; Ghidra bias 0x100000

undefined1  [16]
appfw_3155838(undefined4 *param_1,undefined4 param_2,undefined4 param_3,char param_4,char param_5)

{
  short *psVar1;
  int iVar2;
  undefined1 uVar3;
  short sVar4;
  undefined4 uVar5;
  short *psVar6;
  int *piVar7;
  int *piVar8;
  ulong uVar9;
  ulong uVar10;
  undefined1 auVar11 [16];
  undefined8 uStack_a040;
  undefined4 uStack_a038;
  undefined4 uStack_a020;
  int iStack_a01c;
  undefined4 uStack_3d8;
  undefined4 uStack_3d4;
  undefined1 uStack_3c2;
  short sStack_3c0;
  undefined1 auStack_3be [398];
  short asStack_230 [16];
  undefined1 uStack_210;
  int aiStack_20c [100];
  undefined1 auStack_7c [4];
  undefined4 uStack_78;
  undefined1 uStack_6c;
  undefined4 uStack_68;
  undefined1 uStack_64;
  undefined4 uStack_60;
  undefined1 uStack_54;
  uint uStack_50;
  undefined1 uStack_4c;
  undefined1 uStack_4b;
  undefined1 uStack_40;
  undefined4 uStack_3c;
  undefined1 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  int iStack_2c;
  undefined1 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  int iStack_18;
  undefined4 uStack_14;
  undefined1 uStack_c;
  undefined1 uStack_b;
  
  func_0x01815020(&uStack_a020,0,0xa020);
  uStack_a020 = *param_1;
  iStack_a01c = (param_4 != '\0') + 0x14;
  if (*(char *)(param_1 + 0xd1) != '\0') {
    psVar6 = &sStack_3c0;
    do {
      *psVar6 = 0;
      psVar1 = psVar6 + 2;
      *(undefined1 *)(psVar6 + 1) = 0;
      *(undefined1 *)((long)psVar6 + 3) = 0;
      psVar6 = psVar1;
    } while ((short *)(auStack_3be + 0x18e) != psVar1);
    psVar6 = (short *)(param_1 + 0x6c);
    uVar10 = 0;
    do {
      uVar9 = uVar10;
      if (*psVar6 != 0) {
        sVar4 = psVar6[1];
        uVar3 = *(undefined1 *)((long)psVar6 + 3);
        uVar9 = (ulong)((int)uVar10 + 1);
        (&sStack_3c0)[uVar10 * 2] = *psVar6;
        auStack_3be[uVar10 * 4] = (char)sVar4;
        auStack_3be[uVar10 * 4 + 1] = uVar3;
      }
      psVar6 = psVar6 + 2;
      uVar10 = uVar9;
    } while (psVar6 != (short *)(param_1 + 0xd0));
    if (sStack_3c0 != 0) {
      uStack_3c2 = 1;
    }
  }
  if (*(char *)((long)param_1 + 0x345) != '\0') {
    piVar8 = aiStack_20c;
    do {
      piVar7 = piVar8 + 1;
      *piVar8 = 1;
      piVar8 = piVar7;
    } while ((int *)auStack_7c != piVar7);
    piVar8 = param_1 + 1;
    uVar10 = 0;
    do {
      uVar9 = uVar10;
      if (*piVar8 != 1) {
        uVar9 = (ulong)((int)uVar10 + 1);
        aiStack_20c[uVar10] = *piVar8;
      }
      piVar8 = piVar8 + 1;
      uVar10 = uVar9;
    } while (param_1 + 0x65 != piVar8);
    if (aiStack_20c[0] != 1) {
      uStack_210 = 1;
    }
  }
  if (*(char *)((long)param_1 + 0x346) != '\0') {
    auStack_7c[0] = 1;
    if (param_1[0x65] == 0) {
      uStack_78 = 1;
    }
    else if (param_1[0x65] == 1) {
      uStack_78 = 2;
    }
    else {
      auStack_7c[0] = 0;
    }
  }
  if ((*(char *)((long)param_1 + 0x347) != '\0') && (param_1[0x65] == 0)) {
    uStack_6c = 1;
    switch(param_1[0x66]) {
    case 0:
      uStack_68 = 2;
      break;
    case 1:
      uStack_68 = 1;
      break;
    case 2:
      uStack_68 = 4;
      break;
    case 3:
      uStack_68 = 8;
      break;
    case 4:
      uStack_68 = 0x10;
      break;
    case 5:
      uStack_68 = 10;
      break;
    case 6:
      uStack_68 = 0x12;
      break;
    case 7:
      uStack_68 = 0x1a;
      break;
    default:
      uStack_6c = 0;
    }
  }
  if ((*(char *)(param_1 + 0xd2) != '\0') && (param_1[0x65] == 1)) {
    uStack_64 = 1;
    switch(param_1[0x67]) {
    case 0:
      uStack_60 = 1;
      break;
    case 1:
      uStack_60 = 2;
      break;
    case 2:
      uStack_60 = 4;
      break;
    case 3:
      uStack_60 = 8;
      break;
    case 4:
      uStack_60 = 0x10;
      break;
    case 5:
      uStack_60 = 0x20;
      break;
    case 6:
      uStack_60 = 0x40;
      break;
    default:
      uStack_64 = 0;
    }
  }
  if (*(char *)((long)param_1 + 0x34b) != '\0') {
    if (*(char *)(param_1 + 0x68) != '\0') {
      uStack_50 = 1;
    }
    if (*(char *)((long)param_1 + 0x1a1) != '\0') {
      uStack_50 = uStack_50 | 2;
    }
    if (*(char *)((long)param_1 + 0x1a2) != '\0') {
      uStack_50 = uStack_50 | 4;
    }
    if (*(char *)((long)param_1 + 0x1a3) != '\0') {
      uStack_50 = uStack_50 | 8;
    }
    if (*(char *)(param_1 + 0x69) != '\0') {
      uStack_50 = uStack_50 | 0x10;
    }
    if (*(char *)((long)param_1 + 0x1a5) != '\0') {
      uStack_50 = uStack_50 | 0x20;
    }
    if (uStack_50 != 0) {
      uStack_54 = 1;
    }
  }
  if (*(char *)((long)param_1 + 0x34a) != '\0') {
    uStack_4c = 1;
    if (param_1[0x6a] == 0) {
      uStack_4b = 1;
    }
    else if (param_1[0x6a] != 1) {
      uStack_4c = 0;
    }
  }
  if (*(char *)((long)param_1 + 0x349) != '\0') {
    uStack_40 = 1;
    switch(param_1[0x6b]) {
    case 0:
      uStack_3c = 0xffff;
      break;
    case 1:
      uStack_3c = 1;
      break;
    case 2:
      uStack_3c = 2;
      break;
    case 3:
      uStack_3c = 0xffff0000;
      break;
    default:
      uStack_40 = 0;
    }
  }
  if (*(char *)(param_1 + 0xd3) != '\0') {
    iVar2 = param_1[0xd4];
    if (iVar2 == 1) {
      iStack_2c = 8;
    }
    else if (iVar2 == 0) {
      iStack_2c = 0x1b;
    }
    else if (iVar2 == 2) {
      iStack_2c = 4;
    }
    if (iStack_2c != 0) {
      uStack_38 = 1;
      if ((param_1[0xd6] != 0) && (uStack_34 = 1, param_1[0xd6] != 1)) {
        uStack_34 = 2;
      }
      if (param_1[0xd7] == 0) {
        uVar5 = 2;
      }
      else {
        uVar5 = 1;
        if (param_1[0xd7] != 1) goto LAB_03255da4;
      }
      uStack_30 = uVar5;
    }
  }
LAB_03255da4:
  if (*(char *)((long)param_1 + 0x34d) != '\0') {
    if (param_1[0xd5] == 0) {
      iStack_18 = 3;
      if (param_5 == '\0') {
        iStack_18 = 1;
      }
    }
    else if (param_1[0xd5] == 1) {
      iStack_18 = 4;
    }
    if (iStack_18 != 0) {
      uStack_28 = 1;
      switch(param_1[0xdb]) {
      case 0:
        break;
      case 1:
        uStack_14 = 1;
        break;
      default:
        uStack_14 = 2;
        break;
      case 3:
        uStack_14 = 3;
      }
      if (param_1[0xd8] != 0) {
        uStack_24 = 1;
      }
      if ((param_1[0xd9] != 0) && (uStack_20 = 1, param_1[0xd9] != 1)) {
        uStack_20 = 2;
      }
      if (param_1[0xda] == 0) {
        uVar5 = 2;
      }
      else {
        uVar5 = 1;
        if (param_1[0xda] != 1) goto LAB_03255ea0;
      }
      uStack_1c = uVar5;
    }
  }
LAB_03255ea0:
  if (*(char *)((long)param_1 + 0x34e) != '\0') {
    uStack_c = 1;
    if (param_1[0xd0] == 0) {
      uStack_b = 1;
    }
    else if (param_1[0xd0] != 1) {
      uStack_c = 0;
    }
  }
  uStack_a040 = 0;
  uStack_a038 = 0;
  uStack_3d8 = param_2;
  uStack_3d4 = param_3;
  func_0x036a964c(&uStack_a020,&uStack_a040);
  auVar11._4_4_ = (undefined4)uStack_a040;
  auVar11._0_4_ = uStack_a038;
  auVar11._8_4_ = uStack_a040._4_4_;
  auVar11._12_4_ = 0;
  return auVar11;
}

