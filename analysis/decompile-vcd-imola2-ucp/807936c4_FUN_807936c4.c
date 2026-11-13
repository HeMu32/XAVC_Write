// FUN_807936c4
// Ghidra address: 807936c4

void FUN_807936c4(uint *param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  char cVar6;
  undefined2 uVar7;
  undefined2 uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  undefined1 uVar16;
  undefined1 uVar17;
  undefined2 uVar18;
  uint local_50;
  undefined2 local_40;
  
  uVar18 = 0;
  uVar17 = 0;
  uVar16 = 0;
  uVar2 = 0;
  uVar15 = 5;
  uVar3 = 0;
  uVar4 = 0;
  uVar1 = 0;
  uVar9 = FUN_8079408c(1);
  uVar9 = uVar9 & 1;
  local_40 = 0;
  uVar7 = local_40;
  local_40 = 0;
  uVar8 = 0;
  if (uVar9 == 0) {
LAB_8079373c:
    local_40 = uVar7;
    uVar18 = uVar8;
    *(undefined1 *)((int)param_1 + 0x12) = uVar1;
  }
  else {
    cVar6 = FUN_8079408c(8);
    if (cVar6 == -1) {
      uVar7 = FUN_8079408c(0x10);
      uVar8 = FUN_8079408c(0x10);
      uVar1 = 0xff;
      goto LAB_8079373c;
    }
    *(char *)((int)param_1 + 0x12) = cVar6;
  }
  uVar10 = FUN_8079408c(1);
  uVar11 = (uVar10 & 1) << 1;
  local_50 = uVar9 | uVar11;
  if ((uVar10 & 1) != 0) {
    uVar10 = FUN_8079408c(1);
    local_50 = uVar9 | uVar11 | (uVar10 & 1) << 8;
  }
  uVar10 = FUN_8079408c(1);
  uVar9 = (uVar10 & 1) << 2;
  uVar1 = 0;
  uVar5 = 0;
  uVar11 = local_50 | uVar9;
  if ((uVar10 & 1) != 0) {
    uVar15 = FUN_8079408c(3);
    uVar15 = uVar15 & 0xff;
    uVar11 = FUN_8079408c(1);
    uVar10 = FUN_8079408c(1);
    local_50 = local_50 | uVar9 | (uVar11 & 1) << 9 | (uVar10 & 1) << 3;
    if ((uVar10 & 1) == 0) {
      *(undefined1 *)((int)param_1 + 0xd) = 0;
      goto LAB_8079378c;
    }
    uVar4 = FUN_8079408c(8);
    uVar1 = FUN_8079408c(8);
    uVar5 = FUN_8079408c(8);
    uVar11 = local_50;
  }
  local_50 = uVar11;
  uVar17 = uVar5;
  uVar16 = uVar1;
  *(undefined1 *)((int)param_1 + 0xd) = uVar4;
LAB_8079378c:
  uVar9 = FUN_8079408c(1);
  if ((uVar9 & 1) != 0) {
    uVar2 = FUN_80794188();
    uVar3 = FUN_80794188();
  }
  uVar11 = FUN_8079408c(1);
  *param_1 = *param_1 & 0xfffffffe | uVar11 & 1;
  if ((uVar11 & 1) != 0) {
    uVar11 = FUN_8079408c(0x20);
    param_1[1] = uVar11;
    uVar11 = FUN_8079408c(0x20);
    param_1[2] = uVar11;
    uVar11 = FUN_8079408c(1);
    *param_1 = *param_1 & 0xfffffffd | (uVar11 & 1) << 1;
  }
  uVar1 = FUN_8079408c(1);
  uVar11 = FUN_8078f254(uVar1);
  uVar11 = uVar11 & 1;
  if (uVar11 != 0) {
    FUN_80793c2c(param_1,1);
  }
  uVar1 = FUN_8079408c(1);
  uVar10 = FUN_8078f25c(uVar1);
  uVar10 = uVar10 & 1;
  if (uVar10 != 0) {
    FUN_80793c2c(param_1,0);
  }
  if (uVar11 != 0 || uVar10 != 0) {
    FUN_8079408c(1);
  }
  uVar12 = FUN_8079408c(1);
  *param_1 = *param_1 & 0xfffffffb | (uVar12 & 1) << 2;
  uVar12 = FUN_8079408c(1);
  if ((uVar12 & 1) != 0) {
    FUN_8079408c(1);
    FUN_80794188();
    FUN_80794188();
    FUN_80794188();
    FUN_80794188();
    uVar13 = FUN_80794188();
    param_1[6] = param_1[6] & 0xffffffe0 | uVar13 & 0x1f;
    iVar14 = FUN_80794188();
    *param_1 = *param_1 & 0x7ffffff | iVar14 << 0x1b;
  }
  param_1[4] = param_1[4] & 0xc0ffffff | ((local_50 & 3) >> 1) << 0x18 |
               ((local_50 & 0x10f) >> 8) << 0x19 | ((local_50 & 7) >> 2) << 0x1a |
               (local_50 >> 9) << 0x1b | (uVar9 & 1) << 0x1c | (uVar12 & 1) << 0x1d;
  param_1[3] = param_1[3] & 0xffffff1f | (uVar15 & 7) << 5;
  *param_1 = *param_1 & 0xffffff87 | uVar11 << 4 | uVar10 << 3 | ((local_50 & 0xf) >> 3) << 5 |
             (local_50 & 1) << 6;
  *(undefined1 *)((int)param_1 + 0x11) = uVar3;
  *(undefined1 *)((int)param_1 + 0xe) = uVar16;
  *(undefined1 *)(param_1 + 4) = uVar2;
  *(undefined2 *)(param_1 + 5) = local_40;
  *(undefined2 *)((int)param_1 + 0x16) = uVar18;
  *(undefined1 *)((int)param_1 + 0xf) = uVar17;
  return;
}

