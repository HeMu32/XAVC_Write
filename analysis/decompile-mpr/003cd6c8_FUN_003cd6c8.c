// FUN_003cd6c8
// Ghidra address: 003cd6c8

void FUN_003cd6c8(short *param_1,char param_2,ushort *param_3)

{
  byte bVar1;
  char cVar2;
  short sVar3;
  ushort uVar4;
  char cVar5;
  short sVar6;
  short sVar7;
  char cVar8;
  undefined1 uVar9;
  char cVar10;
  ulong uVar11;
  int iVar12;
  
  sVar3 = *param_1;
  param_3[4] = param_1[5];
  *(char *)(param_3 + 3) = (char)param_1[4];
  sVar6 = param_1[3];
  cVar10 = *(char *)((long)param_1 + 7);
  *(char *)(param_3 + 2) = (char)sVar6;
  cVar2 = *(char *)((long)param_1 + 5);
  *(char *)((long)param_3 + 3) = cVar2;
  sVar7 = param_1[2];
  *(char *)(param_3 + 1) = (char)sVar7;
  uVar4 = param_1[1];
  iVar12 = sVar3 + 0x3c;
  if (param_2 == '\0') {
    iVar12 = (int)sVar3;
  }
  cVar8 = '\x01';
  *param_3 = uVar4;
  if (iVar12 < 0) {
    iVar12 = -iVar12;
    cVar8 = -1;
  }
  cVar5 = (char)(iVar12 / 0x3c);
  cVar10 = cVar10 - cVar8 * ((char)iVar12 + cVar5 * -0x3c);
  if (cVar10 < '<') {
    *(char *)((long)param_3 + 5) = cVar10;
  }
  else {
    *(char *)((long)param_3 + 5) = cVar10 + -0x3c;
    *(char *)(param_3 + 2) = (char)sVar6 + '\x01';
  }
  if (*(char *)((long)param_3 + 5) < '\0') {
    *(char *)((long)param_3 + 5) = *(char *)((long)param_3 + 5) + '<';
    *(char *)(param_3 + 2) = (char)param_3[2] + -1;
  }
  cVar10 = (char)param_3[2] - cVar8 * cVar5;
  if (cVar10 < '\x18') {
    *(char *)(param_3 + 2) = cVar10;
  }
  else {
    *(char *)(param_3 + 2) = cVar10 + -0x18;
    *(char *)((long)param_3 + 3) = cVar2 + '\x01';
  }
  if ((char)param_3[2] < '\0') {
    *(char *)(param_3 + 2) = (char)param_3[2] + '\x18';
    *(char *)((long)param_3 + 3) = *(char *)((long)param_3 + 3) + -1;
  }
  if (*(char *)((long)param_3 + 3) == '\0') {
    cVar10 = (char)sVar7 + -1;
    if (cVar10 == '\0') {
      *param_3 = uVar4 - 1;
      *(undefined1 *)(param_3 + 1) = 0xc;
    }
    else {
      *(char *)(param_3 + 1) = cVar10;
    }
    if ((byte)param_3[1] < 0xd) {
      uVar11 = 1L << ((ulong)(byte)param_3[1] & 0x3f);
      if ((uVar11 & 0x15aa) == 0) {
        if ((uVar11 & 0xa50) == 0) goto LAB_003cd7dc;
        uVar9 = 0x1e;
      }
      else {
        uVar9 = 0x1f;
      }
    }
    else {
LAB_003cd7dc:
      uVar4 = *param_3;
      if ((((uVar4 & 3) == 0) && ((short)uVar4 % 100 != 0)) || ((short)uVar4 % 400 == 0)) {
        uVar9 = 0x1d;
      }
      else {
        uVar9 = 0x1c;
      }
    }
    *(undefined1 *)((long)param_3 + 3) = uVar9;
  }
  bVar1 = (byte)param_3[1];
  cVar10 = *(char *)((long)param_3 + 3);
  if (bVar1 < 0xd) {
    uVar11 = 1L << ((ulong)bVar1 & 0x3f);
    if ((uVar11 & 0x15aa) == 0) {
      if ((uVar11 & 0xa50) == 0) goto LAB_003cd88c;
      if (cVar10 < '\x1f') goto LAB_003cd900;
      cVar10 = cVar10 + -0x1e;
      *(byte *)(param_3 + 1) = bVar1 + 1;
    }
    else {
      if (cVar10 < ' ') goto LAB_003cd900;
      cVar10 = cVar10 + -0x1f;
      *(byte *)(param_3 + 1) = bVar1 + 1;
    }
  }
  else {
LAB_003cd88c:
    uVar4 = *param_3;
    if ((((uVar4 & 3) == 0) && ((short)uVar4 % 100 != 0)) || ((short)uVar4 % 400 == 0)) {
      if (cVar10 < '\x1e') goto LAB_003cd900;
      cVar10 = cVar10 + -0x1d;
      *(byte *)(param_3 + 1) = bVar1 + 1;
    }
    else {
      if (cVar10 < '\x1d') goto LAB_003cd900;
      cVar10 = cVar10 + -0x1c;
      *(byte *)(param_3 + 1) = bVar1 + 1;
    }
  }
  *(char *)((long)param_3 + 3) = cVar10;
LAB_003cd900:
  if ('\f' < (char)param_3[1]) {
    *(char *)(param_3 + 1) = (char)param_3[1] + -0xc;
    *param_3 = *param_3 + 1;
  }
  return;
}

