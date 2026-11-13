// FUN_00327714
// Ghidra address: 00327714

int FUN_00327714(long param_1,ulong *param_2)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  long lVar5;
  ulong uVar6;
  uint uVar7;
  ulong uVar8;
  ulong uVar9;
  uint local_30;
  undefined4 uStack_2c;
  ulong local_28;
  ulong local_20;
  ulong local_18;
  ulong local_10;
  ulong local_8;
  
  uVar8 = param_2[1];
  *(ulong *)(param_1 + 0x88) = *param_2;
  *(ulong *)(param_1 + 0x90) = uVar8;
  *(undefined8 *)(param_1 + 0x97) = *(undefined8 *)((long)param_2 + 0xf);
  uVar8 = *param_2;
  local_30 = 1;
  uStack_2c = 1;
  local_28 = uVar8;
  iVar3 = FUN_00327330(param_1,*(undefined8 *)(param_1 + 0x108),param_2,param_1 + 0x1c8,&local_30);
  if (iVar3 == 0) {
    uVar9 = uVar8;
    if ((*(char *)(param_1 + 0x275) == '\0') || (local_30 == 1)) {
      if (*(char *)((long)param_2 + 0x16) != '\0') {
        iVar3 = FUN_00327690(param_1,*(undefined8 *)(param_1 + 0x108),
                             *(undefined4 *)(param_1 + 0x1c8),local_30,&local_28);
        if (iVar3 != 0) {
          return iVar3;
        }
        uVar9 = local_28;
        if ((int)param_2[1] != 1) {
          uVar9 = uVar8;
        }
      }
    }
    else {
      uVar7 = local_30;
      uVar4 = FUN_00322250(*(undefined4 *)(param_1 + 0x1d4));
      if ((int)param_2[2] == 0) {
        uVar2 = 0;
        if (uVar4 != 0) {
          uVar2 = (uVar7 - 1) / uVar4;
        }
        local_30 = uVar2 * uVar4 + 1;
        FUN_00327690(param_1,*(undefined8 *)(param_1 + 0x108),*(undefined4 *)(param_1 + 0x1c8),
                     local_30,&local_28);
      }
      else if (param_2[1] == 1) {
        local_30 = uVar7 + uVar4;
        if (*(uint *)(param_1 + 0x1d0) < uVar7 + uVar4) {
          local_30 = *(uint *)(param_1 + 0x1d0);
        }
        FUN_00327690(param_1,*(undefined8 *)(param_1 + 0x108),*(undefined4 *)(param_1 + 0x1c8),
                     local_30,&local_28);
        uVar9 = local_28;
      }
    }
    iVar3 = FUN_00327588(param_1,*(undefined8 *)(param_1 + 0x108),local_28,
                         *(int *)((long)param_2 + 0xc) != 1,param_1 + 0x280,&uStack_2c);
    if (iVar3 == 0) {
      if (uVar9 < 90000) {
        lVar5 = 90000;
      }
      else {
        uVar1 = *(undefined4 *)(param_1 + 0x1cc);
        uVar9 = uVar9 - 90000;
        uVar6 = FUN_0032637c(param_1,*(undefined4 *)(param_1 + 0x1d4));
        uVar6 = uVar6 & 0xffffffff;
        FUN_00326cfc(param_1,uVar9,90000,uVar1,&local_20);
        uVar8 = 0;
        if (uVar6 != 0) {
          uVar8 = local_20 / uVar6;
        }
        local_20 = uVar8 * uVar6;
        FUN_00326cfc(param_1,local_20,uVar1,90000,&local_18);
        if (local_18 < uVar9) {
          FUN_00326cfc(param_1,uVar9,90000,uVar1,&local_10);
          uVar8 = 0;
          if (uVar6 != 0) {
            uVar8 = local_10 / uVar6;
          }
          local_10 = uVar6 + uVar8 * uVar6;
          FUN_00326cfc(param_1,local_10,uVar1,90000,&local_8);
          if (uVar9 == local_8) {
            local_18 = uVar9;
          }
        }
        lVar5 = local_18 + 90000;
      }
      *(long *)(param_1 + 0x2f8) = lVar5;
      *(undefined1 *)(param_1 + 0x300) = 1;
      if ((*(char *)(param_1 + 0x275) != '\0') && ((int)param_2[1] == 1)) {
        *(undefined1 *)(param_1 + 0x300) = 0;
      }
      *(uint *)(param_1 + 0x2c0) = local_30;
      *(undefined4 *)(param_1 + 0x2d8) = uStack_2c;
      *(undefined4 *)(param_1 + 0x2dc) = uStack_2c;
      *(undefined4 *)(param_1 + 0x2e0) = uStack_2c;
      *(undefined4 *)(param_1 + 0x2e4) = uStack_2c;
      *(undefined4 *)(param_1 + 0x2e8) = uStack_2c;
      *(uint *)(param_1 + 0x2ec) = local_30;
      *(uint *)(param_1 + 0x2f0) = local_30;
      *(undefined4 *)(param_1 + 0x308) = uStack_2c;
    }
  }
  return iVar3;
}

