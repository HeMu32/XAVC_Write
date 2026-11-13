// FUN_00328fa8
// Ghidra address: 00328fa8

int FUN_00328fa8(long param_1,long param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  uint local_b0;
  byte local_ac;
  int local_a8;
  uint local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 uStack_90;
  undefined2 local_8c;
  undefined2 local_8a;
  uint local_88;
  undefined4 uStack_84;
  undefined4 local_80;
  undefined1 local_7c;
  undefined1 local_7b;
  undefined1 local_7a;
  undefined4 local_78;
  undefined4 local_74;
  undefined2 local_70;
  undefined2 local_6e;
  undefined1 local_6c;
  undefined1 local_6b;
  undefined1 local_6a;
  undefined1 local_69;
  int local_68;
  int local_64;
  uint local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_4c;
  undefined2 local_48;
  undefined2 local_46;
  undefined4 local_3c;
  
  local_a8 = 0x61766331;
  uVar5 = 1;
  local_7c = 3;
  local_a4 = 100000;
  local_7b = 3;
  local_7a = 1;
  local_9c = 0x1df853;
  local_a0 = 0;
  local_88 = 1;
  uStack_84 = 0;
  local_98 = 90000;
  local_80 = 1;
  local_94 = 0xbbb;
  uStack_90 = 0xbbb;
  local_78 = 0;
  local_8c = 0xf00;
  local_8a = 0x870;
  local_74 = 0xff;
  local_b0 = 0x20102;
  local_ac = 2;
  iVar2 = FUN_00326468(param_1,*(undefined8 *)(param_1 + 0x108),param_1 + 0x1c8,param_1 + 300,
                       &local_a8);
  if (iVar2 == 0) {
    iVar2 = FUN_00324db0(param_1,*(undefined8 *)(param_1 + 0x108),param_1 + 0x280,param_1 + 0x154,
                         &local_b0);
    if (iVar2 == 0) {
      FUN_00328c80(param_1,*(undefined8 *)(param_1 + 0x178),param_2);
      FUN_0032266c(&local_70);
      local_64 = local_a8;
      local_46 = local_8c;
      local_48 = local_8a;
      local_4c = local_9c;
      local_5c = local_a4;
      local_58 = *(undefined4 *)(param_1 + 0x268);
      local_54 = *(undefined4 *)(param_1 + 0x26c);
      local_3c = local_74;
      iVar2 = FUN_003256fc(param_1,&local_70,param_2 + 0x28);
      if (local_88 < 5) {
        uVar5 = (uint)(byte)(&UNK_003db730)[local_88];
      }
      *(uint *)(param_2 + 0x18) = uVar5;
      *(short *)(param_2 + 0x2c) = (short)(local_a4 / 1000);
      uVar4 = 0xff;
      *(uint *)(param_2 + 0xc) = (uint)(local_a8 == 0x68766331);
      uVar5 = *(int *)(param_1 + 0x268) - 1;
      if (uVar5 < 3) {
        uVar4 = (uint)(byte)(&DAT_003db740)[uVar5];
      }
      *(uint *)(param_2 + 0x1c) = uVar4;
      uVar3 = FUN_003222fc(local_9c);
      *(undefined4 *)(param_2 + 0x24) = uVar3;
      *(undefined4 *)(param_2 + 0x10) = local_74;
      uVar3 = FUN_003223a8(local_8c,local_8a);
      *(undefined4 *)(param_2 + 0x14) = uVar3;
      uVar4 = 0xff;
      uVar5 = *(int *)(param_1 + 0x26c) - 8;
      if (uVar5 < 5) {
        uVar4 = (uint)(byte)(&DAT_003db738)[uVar5];
      }
      uVar3 = *(undefined4 *)(param_1 + 0x1d0);
      *(uint *)(param_2 + 0x20) = uVar4;
      *(undefined4 *)(param_2 + 0x30) = uVar3;
      uVar3 = 0;
      if (((local_b0 >> 8 & 1) == 0) && (uVar3 = 0xff, (local_b0 & 0x200) != 0)) {
        uVar3 = 1;
      }
      iVar1 = *(int *)(param_1 + 0x280);
      uVar4 = 0xff;
      *(undefined4 *)(param_2 + 0x38) = uVar3;
      uVar5 = iVar1 * (uint)local_ac - 1;
      if ((uVar5 & 0xff) < 4) {
        uVar4 = (uint)(byte)(&DAT_003db750)[(byte)uVar5];
      }
      *(uint *)(param_2 + 0x40) = uVar4;
      *(int *)(param_2 + 0x44) = iVar1;
      uVar3 = 1;
      if (((local_b0 & 1) == 0) && (uVar3 = 0, (local_b0 & 2) == 0)) {
        uVar3 = 0xff;
      }
      iVar1 = *(int *)(param_1 + 0x16c);
      *(undefined4 *)(param_2 + 0x34) = uVar3;
      uVar3 = 0;
      if ((iVar1 != 48000) && (uVar3 = 0xff, iVar1 == 96000)) {
        uVar3 = 1;
      }
      *(undefined4 *)(param_2 + 0x3c) = uVar3;
      return iVar2;
    }
    local_6e = 0x205;
  }
  else {
    local_6e = 0x204;
  }
  local_69 = 0;
  local_6a = 0;
  local_6b = 0;
  local_6c = 3;
  local_70 = 0x2301;
  local_68 = iVar2;
  FUN_00322494(&local_70,0xc);
  return iVar2;
}

