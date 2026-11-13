// FUN_002cedb8
// Ghidra address: 002cedb8

/* WARNING: Type propagation algorithm not settling */

int FUN_002cedb8(undefined8 *param_1,ulong param_2,uint param_3,int param_4,undefined4 *param_5,
                int *param_6)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  long lVar5;
  long lVar6;
  undefined1 local_b8 [8];
  undefined4 local_b0;
  undefined4 local_ac;
  uint local_a8 [4];
  long local_98;
  undefined8 local_90;
  ulong local_88;
  ulong local_80;
  long local_78;
  undefined8 local_70;
  undefined1 auStack_68 [4];
  uint local_64;
  undefined1 auStack_60 [4];
  uint local_5c;
  undefined1 auStack_58 [4];
  undefined4 local_54;
  long local_50;
  int local_48;
  uint local_44;
  undefined4 local_40;
  undefined8 local_38;
  undefined4 local_30;
  undefined2 local_2c;
  undefined4 local_28;
  undefined8 local_24;
  undefined8 uStack_1c;
  undefined8 local_10;
  undefined8 local_8;
  
  local_ac = 0;
  local_a8[0] = 0;
  local_a8[1] = 0;
  local_a8[2] = 0;
  local_a8[3] = 0;
  local_98 = 0;
  local_90 = 0;
  local_88 = 0;
  local_80 = 0;
  local_78 = 0;
  local_70 = 0;
  if (param_1 == (undefined8 *)0x0 || (int)param_2 == 0) {
    return 1;
  }
  if (param_3 == 0 || param_5 == (undefined4 *)0x0) {
    return 1;
  }
  iVar2 = FUN_002efdd8(param_1[0x38],param_2,&local_98);
  if (iVar2 != 0) {
    return iVar2;
  }
  if (local_98 == 0) {
    return 0x10000000;
  }
  if (*(long *)(local_98 + 0x100) != 0) {
    if (*(uint *)(local_98 + 0x118) < param_3) {
      return 0x200;
    }
    iVar2 = FUN_002e29c8(param_1,param_2 & 0xffffffff,&local_90);
    if (iVar2 != 0) {
      return iVar2;
    }
    iVar2 = FUN_002e0cb8(*param_1,param_1[1],local_98,param_3,local_90,&local_b0);
    if (iVar2 != 0) {
      return iVar2;
    }
    iVar2 = FUN_002e0dc4(*param_1,param_1[1],local_98,param_3,local_90,auStack_60,local_a8 + 2,
                         &local_88);
    if (iVar2 != 0) {
      return iVar2;
    }
    if (*(long *)(local_98 + 0xa0) == 0) {
      local_54 = 0;
    }
    else {
      iVar2 = FUN_002dea98(*param_1,param_1[1],local_98,param_3,local_90,auStack_58);
      if (iVar2 != 0) {
        return iVar2;
      }
    }
    if (*(long *)(local_98 + 0x160) == 0) {
      local_ac = 1;
    }
    else if (*(int *)(local_98 + 0x170) == 0) {
      local_ac = 0;
    }
    else {
      iVar2 = FUN_002e0368(*param_1,param_1[1],local_98,param_3,local_90,&local_ac);
      if (iVar2 != 0) {
        return iVar2;
      }
    }
    if (*(long *)(local_98 + 0x188) == 0) {
      local_b8[0] = 0;
    }
    else {
      iVar2 = FUN_002df530(*param_1,param_1[1],local_98,param_3,local_90,local_b8);
      if (iVar2 != 0) {
        return iVar2;
      }
    }
    iVar2 = FUN_002df810(*param_1,param_1[1],local_98,param_3,local_90,&local_48,local_a8,
                         local_a8 + 1);
    if (iVar2 != 0) {
      return iVar2;
    }
    if (local_48 != 0) {
      iVar2 = local_48;
      if (local_a8[0] < param_3) {
        if (local_44 == 0) {
          return 0x1000;
        }
        uVar1 = 0;
        if (local_44 != 0) {
          uVar1 = (param_3 - local_a8[0]) / local_44;
        }
        local_a8[0] = local_a8[0] + local_44 * uVar1;
        iVar2 = local_48 + uVar1;
      }
      iVar3 = FUN_002de204(*param_1,param_1[1],local_98,iVar2,local_90,&local_50);
      if (iVar3 != 0) {
        return iVar3;
      }
      lVar6 = local_50;
      if (local_a8[0] < param_3) {
        iVar3 = FUN_002e0b20(*param_1,param_1[1],local_98,local_a8[0],param_3 - local_a8[0],local_90
                             ,&local_78);
        if (iVar3 != 0) {
          return iVar3;
        }
        lVar6 = local_50 + local_78;
      }
      if ((param_4 == 0) || (uVar1 = local_44 + local_a8[0], uVar1 <= param_3)) {
        iVar3 = 0;
        lVar5 = 0;
      }
      else {
        iVar3 = uVar1 - param_3;
        iVar4 = FUN_002e0b20(*param_1,param_1[1],local_98,param_3,iVar3,local_90,&local_70);
        if (iVar4 != 0) {
          return iVar4;
        }
        if (local_a8[2] < param_3) {
          local_88 = local_88 + (ulong)(param_3 - local_a8[2]) * (ulong)local_5c;
        }
        iVar4 = FUN_002e0dc4(*param_1,param_1[1],local_98,uVar1 - 1,local_90,auStack_68,local_a8 + 3
                             ,&local_80);
        if (iVar4 != 0) {
          return iVar4;
        }
        if (local_a8[3] < uVar1) {
          local_80 = local_80 + (ulong)(uVar1 - local_a8[3]) * (ulong)local_64;
        }
        lVar5 = local_80 - local_88;
        if (local_80 <= local_88) {
          lVar5 = 0;
        }
      }
      iVar4 = FUN_002e2e14(param_3,local_90);
      if (iVar4 != 0) {
        return iVar4;
      }
      FUN_002dd7a4(*param_1,&local_38,0,0x38);
      iVar4 = FUN_002e2e2c(*param_1,param_1[1],param_4,local_98,local_90,iVar2,param_3,local_a8[0],
                           iVar3,&local_38);
      if (iVar4 == 0) {
        FUN_002dd7a4(*param_1,param_5,0,0x78);
        *(long *)(param_5 + 2) = lVar6;
        *param_5 = local_b0;
        param_5[4] = local_5c;
        param_5[5] = local_ac;
        *(undefined1 *)(param_5 + 6) = local_b8[0];
        param_5[7] = local_54;
        if ((*(long *)(local_98 + 0xa0) == 0) || (*(int *)(local_98 + 0xb0) != 1)) {
          param_5[8] = 0;
        }
        else {
          param_5[8] = 1;
        }
        *(long *)(param_5 + 0xc) = lVar5;
        param_5[9] = local_40;
        *(undefined8 *)(param_5 + 10) = local_70;
        param_5[0xe] = iVar3;
        *(undefined8 *)(param_5 + 0x10) = local_38;
        param_5[0x12] = local_30;
        *(undefined2 *)(param_5 + 0x13) = local_2c;
        param_5[0x14] = local_28;
        *(undefined8 *)(param_5 + 0x15) = local_24;
        *(undefined8 *)(param_5 + 0x17) = uStack_1c;
        *(undefined8 *)(param_5 + 0x1a) = local_10;
        *(undefined8 *)(param_5 + 0x1c) = local_8;
        if (param_6 != (int *)0x0) {
          *param_6 = iVar2;
          return 0;
        }
        return 0;
      }
      return iVar4;
    }
  }
  return 0x1000;
}

