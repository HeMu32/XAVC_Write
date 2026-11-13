// FUN_00329664
// Ghidra address: 00329664

void FUN_00329664(undefined8 param_1,undefined8 param_2,uint param_3,uint param_4,long param_5)

{
  int iVar1;
  long lVar2;
  uint *puVar3;
  int *piVar4;
  undefined8 uVar5;
  uint *puVar6;
  uint uVar7;
  ulong uVar8;
  ulong uVar9;
  uint uVar10;
  uint uVar11;
  uint local_a4;
  uint local_a0;
  undefined1 local_9c;
  undefined1 local_9b;
  undefined1 local_9a;
  undefined1 local_99;
  uint local_98;
  uint *local_90;
  uint *local_88;
  uint *local_80;
  undefined2 local_78;
  undefined2 local_76;
  undefined1 local_74;
  undefined1 local_73;
  undefined1 local_72;
  undefined1 local_71;
  uint local_70;
  uint local_6c;
  undefined8 local_68;
  undefined8 uStack_60;
  uint *local_58;
  undefined8 uStack_50;
  
  local_74 = 2;
  local_78 = 0x2301;
  local_76 = 0x300;
  local_73 = 0;
  local_72 = 0;
  local_71 = 0;
  local_70 = param_3;
  local_6c = param_4;
  FUN_00322494(&local_78,0x10);
  if (9 < param_4) {
    param_4 = 10;
  }
  uVar7 = 1;
  local_90 = (uint *)0x0;
  local_88 = (uint *)0x0;
  local_80 = (uint *)0x0;
  uVar10 = 0;
  do {
    if (param_4 < uVar7) {
      local_73 = 0;
      local_72 = 0;
      uVar5 = 0x10;
      local_74 = 2;
      local_71 = 0;
      local_78 = 0x2301;
      local_76 = 0x305;
      puVar3 = (uint *)&local_78;
      local_70 = uVar10;
      local_6c = param_4;
LAB_00329754:
      FUN_00322494(puVar3,uVar5);
      FUN_00329320(param_5,*(undefined8 *)(param_5 + 0x10));
      local_70 = 0;
      *(undefined8 *)(param_5 + 0x10) = 0;
      *(long *)(param_5 + 0x18) = param_5 + 8;
      *(long *)(param_5 + 0x20) = param_5 + 8;
      *(undefined8 *)(param_5 + 0x28) = 0;
      uStack_60 = &local_70;
      local_68 = 0;
      uStack_50 = 0;
      local_58 = uStack_60;
      FUN_0032936c(&local_78,param_5);
      FUN_00329320(&local_78,local_68);
LAB_00329798:
      local_73 = 0;
      local_74 = 4;
      local_72 = 0;
      local_78 = 0x2301;
      local_71 = 0;
      local_76 = 0x30f;
      FUN_00322494(&local_78,8);
      if (local_90 != (uint *)0x0) {
        operator_delete(local_90);
      }
      return;
    }
    memset(&local_78,0,0x78);
    iVar1 = FUN_002cedb8(param_2,param_3,uVar7,0,&local_78,0);
    if (iVar1 != 0) {
      local_a0 = 0x3012301;
      local_98 = uVar7;
LAB_0032974c:
      local_99 = 0;
      local_9a = 0;
      local_9b = 0;
      local_9c = 3;
      uVar5 = 0xc;
      puVar3 = &local_a0;
      goto LAB_00329754;
    }
    uVar11 = uStack_60._4_4_;
    if ((uVar7 != 1) && (uVar11 = uVar10, uVar10 == uStack_60._4_4_)) {
      puVar6 = local_90;
      puVar3 = local_90;
      if (local_90 != local_88) {
        while (puVar3 = puVar3 + 1, local_88 != puVar3) {
          if (*puVar3 < *puVar6) {
            puVar6 = puVar3;
          }
        }
      }
      lVar2 = (long)local_88 - (long)local_90;
      uVar7 = *puVar6;
      for (uVar8 = 0; uVar8 < (ulong)(lVar2 >> 2); uVar8 = (ulong)((int)uVar8 + 1)) {
        piVar4 = (int *)FUN_002278e0(&local_90,uVar8);
        *piVar4 = *piVar4 - uVar7;
        piVar4 = (int *)FUN_002278e0(&local_90,uVar8);
        *piVar4 = *piVar4 + 1;
      }
      for (uVar8 = 0; uVar9 = (long)local_88 - (long)local_90 >> 2, uVar8 < uVar9;
          uVar8 = (ulong)((int)uVar8 + 1)) {
        puVar3 = (uint *)FUN_002278e0(&local_90,uVar8);
        local_a4 = *puVar3;
        if (uVar9 == local_a4) {
          local_a4 = 0;
        }
        piVar4 = (int *)FUN_002278e0(&local_90,uVar8);
        local_a0 = ((int)uVar8 - *piVar4) + 1;
        FUN_0032954c(param_5,&local_a4,&local_a0);
        local_74 = 2;
        local_73 = 0;
        local_78 = 0x2301;
        local_72 = 0;
        local_76 = 0x306;
        local_71 = 0;
        local_70 = local_a4;
        local_6c = local_a0;
        FUN_00322494(&local_78,0x10);
      }
      goto LAB_00329798;
    }
    if ((uint)local_68 == 0) {
      local_98 = 0;
      local_a0 = 0x3042301;
      goto LAB_0032974c;
    }
    local_a0 = 0;
    if ((uint)local_68 != 0) {
      local_a0 = uStack_60._4_4_ / (uint)local_68;
    }
    local_a0 = local_a0 + uVar7;
    if (local_88 == local_80) {
      FUN_0022cbfc(&local_90,&local_a0);
    }
    else {
      if (local_88 != (uint *)0x0) {
        *local_88 = local_a0;
      }
      local_88 = local_88 + 1;
    }
    uVar7 = uVar7 + 1;
    uVar10 = uVar11;
  } while( true );
}

