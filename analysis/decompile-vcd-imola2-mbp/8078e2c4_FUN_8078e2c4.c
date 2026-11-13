// FUN_8078e2c4
// Ghidra address: 8078e2c4

void FUN_8078e2c4(uint *param_1)

{
  char cVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  uint *puVar7;
  uint uVar8;
  char *pcVar9;
  uint uVar10;
  uint uVar11;
  int local_38;
  
  uVar11 = 0;
  FUN_8078def8(param_1 + 0x1c);
  *(undefined1 *)(param_1 + 0x19) = 0x10;
  local_38 = 0;
  *(undefined1 *)((int)param_1 + 0x6b) = 0x10;
  *(undefined1 *)((int)param_1 + 0x65) = 0x10;
  *(undefined1 *)((int)param_1 + 0x66) = 0x10;
  *(undefined1 *)((int)param_1 + 0x67) = 0x10;
  *(undefined1 *)(param_1 + 0x1a) = 0x10;
  *(undefined1 *)((int)param_1 + 0x69) = 0x10;
  *(undefined1 *)((int)param_1 + 0x6a) = 0x10;
  *param_1 = 0;
  do {
    uVar6 = 2;
    if (uVar11 != 3) {
      uVar6 = 6;
    }
    iVar5 = 1 << (uVar11 * 2 + 4 & 0x1f);
    uVar10 = 0;
    if (uVar6 != 0) {
      pcVar9 = (char *)((int)param_1 + uVar11 * 6 + 0x58);
      do {
        iVar3 = FUN_8079408c(1);
        *param_1 = *param_1 | iVar3 << (local_38 + uVar10 & 0x1f);
        if (iVar3 == 0) {
          uVar4 = FUN_80794188();
          FUN_8078e898(param_1,uVar11,uVar10,uVar4);
        }
        else {
          cVar2 = '\b';
          if (1 < uVar11) {
            cVar2 = FUN_807941d8();
            cVar2 = cVar2 + '\b';
            *pcVar9 = cVar2;
          }
          uVar8 = 0;
          if (iVar5 != -0x40) {
            puVar7 = param_1 + (uVar11 * 6 + uVar10) * 0x10 + 0x1c;
            do {
              uVar8 = uVar8 + 1;
              cVar1 = FUN_807941d8();
              cVar2 = cVar2 + cVar1;
              *(char *)puVar7 = cVar2;
              puVar7 = (uint *)((int)puVar7 + 1);
            } while (uVar8 < iVar5 + 0x40U);
          }
        }
        uVar10 = uVar10 + 1;
        pcVar9 = pcVar9 + 1;
      } while (uVar10 < uVar6);
    }
    uVar11 = uVar11 + 1;
    local_38 = local_38 + 6;
  } while (uVar11 < 4);
  return;
}

