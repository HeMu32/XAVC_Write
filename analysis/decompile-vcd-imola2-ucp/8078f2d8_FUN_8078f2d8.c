// FUN_8078f2d8
// Ghidra address: 8078f2d8

void FUN_8078f2d8(int param_1)

{
  char cVar1;
  char cVar2;
  ushort uVar3;
  int iVar4;
  undefined4 *puVar5;
  uint uVar6;
  int iVar7;
  undefined1 uVar8;
  undefined4 uVar9;
  int *piVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  undefined4 *puVar14;
  
  puVar14 = (undefined4 *)(param_1 + 0x1c);
  cVar1 = *(char *)(param_1 + 10);
  iVar4 = *(int *)(param_1 + 4);
  uVar6 = *(uint *)(param_1 + 0x10);
  if (cVar1 == '\0') {
    sony_ucp_write7(0xd03,0);
  }
  else {
    if (*(int *)(param_1 + 0x14) == 1) {
LAB_8078f360:
      (&DAT_807c0370)[iVar4 * 4] = 0;
    }
    else {
      if (*(int *)(param_1 + 0x14) != 0) {
        (&DAT_807c0371)[iVar4 * 4] = 0;
        goto LAB_8078f360;
      }
      iVar7 = iVar4 * 4;
      cVar2 = (&DAT_807c0371)[iVar7];
      (&DAT_807c0371)[iVar7] = cVar2 == '\0';
      (&DAT_807c0370)[iVar7] = cVar2 == '\0';
    }
    sony_ucp_write7(0xd03,(uint)(byte)(&DAT_807c0370)[iVar4 * 4]);
  }
  uVar13 = *(uint *)(param_1 + 0x24);
  uVar3 = *(ushort *)(param_1 + 8);
  FUN_80794048(*(undefined4 *)(param_1 + 0x7b0),*(undefined4 *)(param_1 + 0x7b4),0,0);
  FUN_80793ff8(0,*(undefined1 *)(param_1 + 0x1a),*(undefined1 *)(param_1 + 0x1b));
  FUN_807841d0(*(undefined4 *)(param_1 + 0x158),*(undefined4 *)(param_1 + 0x150),
               (uVar13 & 0x3fffff) >> 0x15,(uVar3 & 0x3f) >> 4,*(undefined4 *)(param_1 + 0xd4),
               *(undefined4 *)(param_1 + 0xd8),*(undefined4 *)(param_1 + 0xdc),
               *(undefined4 *)(param_1 + 0xe0),*(undefined4 *)(param_1 + 0xe4),
               *(undefined4 *)(param_1 + 0xec),*(undefined4 *)(param_1 + 0xe8),
               *(undefined4 *)(param_1 + 0xf0),*(undefined4 *)(param_1 + 0xf4),
               *(undefined4 *)(param_1 + 0xfc),*(undefined4 *)(param_1 + 0xf8),
               *(undefined4 *)(param_1 + 0x100),*(undefined4 *)(param_1 + 0x104),
               *(undefined4 *)(param_1 + 0x10c),*(undefined4 *)(param_1 + 0x108),
               *(undefined4 *)(param_1 + 0x110),uVar6);
  iVar7 = 0;
  do {
    uVar13 = sony_ucp_read7(0x400);
    iVar7 = iVar7 + 1;
    if ((uVar13 & 1) != 0) goto LAB_8078f474;
  } while (iVar7 != 0x30571);
  FUN_80747a30(0x400);
LAB_8078f474:
  sony_ucp_write7(0xd01,uVar6);
  sony_ucp_write7(0x400,(uint)*(ushort *)(param_1 + 8));
  sony_ucp_write7(0x401,*puVar14);
  sony_ucp_write7(0x401,*(undefined4 *)(param_1 + 0x20));
  sony_ucp_write7(0x40a,*(undefined4 *)(param_1 + 0x148));
  sony_ucp_write7(0x402,*(undefined4 *)(param_1 + 0x24));
  sony_ucp_write7(0x404,*(undefined4 *)(param_1 + 0xb0));
  sony_ucp_write7(0x404,*(undefined4 *)(param_1 + 0xb4));
  sony_ucp_write7(0x406,*(uint *)(param_1 + 0xb8) & 0x3ff);
  sony_ucp_write7(0x406,*(undefined4 *)(param_1 + 0xbc));
  sony_ucp_write7(0x40e,*(undefined4 *)(param_1 + 0x154));
  sony_ucp_write7(0x407,*(undefined4 *)(param_1 + 0xc0));
  sony_ucp_write7(0x408,*(undefined4 *)(param_1 + 0xc4));
  sony_ucp_write7(0x40c,*(undefined4 *)(param_1 + 0xcc));
  uVar13 = 0;
  if (*(uint *)(param_1 + 0xcc) >> 2 != 0) {
    iVar7 = 0;
    puVar5 = puVar14;
    do {
      sony_ucp_write7(0x492,(uint)*(byte *)(puVar5 + 0x50));
      iVar12 = 3;
      iVar11 = iVar7 * 0x10;
      piVar10 = &DAT_807b5670;
      do {
        uVar13 = (uint)*(byte *)((int)puVar14 + iVar11 + piVar10[1] + 0x148);
        sony_ucp_write7(0x493,(uint)*(byte *)((int)puVar14 + iVar11 + piVar10[3] + 0x148) << 0x18 |
                              (uint)*(byte *)((int)puVar14 + iVar11 + piVar10[2] + 0x148) << 0x10 |
                              uVar13 << 8 |
                              (uint)*(byte *)((int)puVar14 + iVar11 + *piVar10 + 0x148));
        iVar12 = iVar12 + -1;
        piVar10 = piVar10 + 4;
      } while (-1 < iVar12);
      iVar7 = iVar7 + 1;
      puVar5 = (undefined4 *)((int)puVar14 + iVar7);
    } while (iVar7 < 6);
    if (iVar7 < 8) {
      uVar13 = (int)puVar14 + iVar7;
      do {
        sony_ucp_write7(0x492,(uint)*(byte *)(uVar13 + 0x140));
        iVar12 = 0xf;
        iVar11 = iVar7 * 0x40;
        piVar10 = &DAT_807b5570;
        do {
          sony_ucp_write7(0x493,(uint)*(byte *)((int)puVar14 + iVar11 + piVar10[3] + 0x28) << 0x18 |
                                (uint)*(byte *)((int)puVar14 + iVar11 + piVar10[2] + 0x28) << 0x10 |
                                (uint)*(byte *)((int)puVar14 + iVar11 + piVar10[1] + 0x28) << 8 |
                                (uint)*(byte *)((int)puVar14 + iVar11 + *piVar10 + 0x28));
          iVar12 = iVar12 + -1;
          piVar10 = piVar10 + 4;
        } while (-1 < iVar12);
        iVar7 = iVar7 + 1;
        uVar13 = (int)puVar14 + iVar7;
      } while (iVar7 < 8);
    }
  }
  puVar5 = (undefined4 *)(param_1 + 0x34);
  iVar7 = 0x1e;
  do {
    sony_ucp_write7(0x40d,*puVar5);
    iVar7 = iVar7 + -1;
    puVar5 = puVar5 + 1;
  } while (-1 < iVar7);
  sony_ucp_write7(0x40f,*(undefined4 *)(param_1 + 200));
  if (uVar6 == 3) {
    sony_ucp_write7(0x419,(uint)((ulonglong)*(uint *)(param_1 + 0x114) * 0xaaaaaaab >> 0x20) &
                          0xfffffffe);
    uVar13 = 0xaaaa0000;
    sony_ucp_write7(0x41a,(uint)((ulonglong)*(uint *)(param_1 + 0x118) * 0xaaaaaaab >> 0x20) &
                          0xfffffffe);
    sony_ucp_write7(0x41b,(uint)((ulonglong)*(uint *)(param_1 + 0x11c) * 0xaaaaaaab >> 0x20) &
                          0xfffffffe);
    sony_ucp_write7(0x41c,(uint)((ulonglong)*(uint *)(param_1 + 0x120) * 0xaaaaaaab >> 0x20) &
                          0xfffffffe);
    uVar9 = *(undefined4 *)(param_1 + 0x13c);
  }
  else if (uVar6 == 2) {
    sony_ucp_write7(0x419,*(uint *)(param_1 + 0x114) >> 1);
    sony_ucp_write7(0x41a,*(uint *)(param_1 + 0x118) >> 1);
    sony_ucp_write7(0x41b,*(uint *)(param_1 + 0x11c) >> 1);
    sony_ucp_write7(0x41c,*(uint *)(param_1 + 0x120) >> 1);
    uVar9 = *(undefined4 *)(param_1 + 0x13c);
  }
  else if (uVar6 - 4 < 2) {
    sony_ucp_write7(0x419,*(uint *)(param_1 + 0x114) / 3 << 2);
    sony_ucp_write7(0x41a,*(uint *)(param_1 + 0x118) / 3 << 2);
    sony_ucp_write7(0x41b,*(uint *)(param_1 + 0x11c) / 3 << 2);
    sony_ucp_write7(0x41c,*(uint *)(param_1 + 0x120) / 3 << 2);
    uVar9 = *(undefined4 *)(param_1 + 0x13c);
    uVar13 = 0xaaaaaaab;
  }
  else {
    uVar13 = uVar6;
    if (uVar6 - 6 < 2) {
      sony_ucp_write7(0x419,*(int *)(param_1 + 0x114) << 1);
      sony_ucp_write7(0x41a,*(int *)(param_1 + 0x118) << 1);
      sony_ucp_write7(0x41b,*(int *)(param_1 + 0x11c) << 1);
      sony_ucp_write7(0x41c,*(int *)(param_1 + 0x120) << 1);
      uVar9 = *(undefined4 *)(param_1 + 0x13c);
    }
    else {
      sony_ucp_write7(0x419,*(undefined4 *)(param_1 + 0x114));
      sony_ucp_write7(0x41a,*(undefined4 *)(param_1 + 0x118));
      sony_ucp_write7(0x41b,*(undefined4 *)(param_1 + 0x11c));
      sony_ucp_write7(0x41c,*(undefined4 *)(param_1 + 0x120));
      uVar9 = *(undefined4 *)(param_1 + 0x13c);
    }
  }
  sony_ucp_write7(0x41d,uVar9);
  sony_ucp_write7(0x405,*(undefined4 *)(param_1 + 0x140));
  sony_ucp_write7(0x405,*(undefined4 *)(param_1 + 0x144));
  sony_ucp_write7(0x40e,*(undefined4 *)(param_1 + 0x154));
  if (uVar6 == 3) {
    *(uint *)(param_1 + 0x130) =
         (uint)((ulonglong)*(uint *)(param_1 + 0x130) * 0xaaaaaaab >> 0x20) & 0xfffffffe;
    uVar13 = (uint)((ulonglong)*(uint *)(param_1 + 0x124) * 0xaaaaaaab >> 0x20) & 0xfffffffe;
    *(uint *)(param_1 + 0x124) = uVar13;
    *(uint *)(param_1 + 0x128) =
         (uint)((ulonglong)*(uint *)(param_1 + 0x128) * 0xaaaaaaab >> 0x20) & 0xfffffffe;
    *(uint *)(param_1 + 300) =
         (uint)((ulonglong)*(uint *)(param_1 + 300) * 0xaaaaaaab >> 0x20) & 0xfffffffe;
  }
  else if (uVar6 == 2) {
    *(uint *)(param_1 + 0x124) = *(uint *)(param_1 + 0x124) >> 1;
    *(uint *)(param_1 + 0x128) = *(uint *)(param_1 + 0x128) >> 1;
    *(uint *)(param_1 + 300) = *(uint *)(param_1 + 300) >> 1;
    *(uint *)(param_1 + 0x130) = *(uint *)(param_1 + 0x130) >> 1;
  }
  iVar7 = FUN_80747d98(uVar13);
  iVar11 = FUN_80747da8();
  if (iVar7 - iVar11 == 1) {
    iVar7 = FUN_80747db0();
    if (iVar7 == 1) {
      uVar13 = *(uint *)(param_1 + 0x134);
      goto LAB_8078f784;
    }
    uVar9 = *(undefined4 *)(param_1 + 0x124);
  }
  else {
    uVar9 = *(undefined4 *)(param_1 + 0x124);
  }
  sony_ucp_write7(0x442,uVar9);
  sony_ucp_write7(0x443,*(undefined4 *)(param_1 + 0x128));
  sony_ucp_write7(0x444,*(undefined4 *)(param_1 + 300));
  sony_ucp_write7(0x445,*(undefined4 *)(param_1 + 0x130));
  uVar13 = *(uint *)(param_1 + 0x134);
LAB_8078f784:
  sony_ucp_write7(0x448,uVar13 >> 1);
  sony_ucp_write7(0x449,*(uint *)(param_1 + 0x138) >> 1);
  FUN_80788788(puVar14);
  uVar8 = 0xff;
  if (cVar1 != '\0') {
    uVar8 = (&DAT_807c0370)[iVar4 * 4];
  }
  FUN_80787558(uVar6,uVar8,param_1,0,0,0,0,0,0,0);
  FUN_8079d7d8();
  FUN_8077fdcc();
  sony_ucp_write7(0x41f,0);
  FUN_807466f4();
  FUN_8079d844();
  return;
}

