// FUN_00324550
// Ghidra address: 00324550

void FUN_00324550(undefined8 param_1,undefined8 param_2,long param_3,uint *param_4,
                 undefined4 *param_5,undefined4 *param_6,undefined4 *param_7)

{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  ushort uVar7;
  uint uVar8;
  undefined4 *puVar9;
  undefined1 local_90;
  undefined1 local_8f;
  undefined8 local_88;
  ulong local_80;
  long lStack_78;
  undefined1 local_70;
  undefined1 local_6f;
  undefined1 local_6e;
  int local_6c;
  int iStack_68;
  int local_64;
  undefined1 *local_60;
  undefined4 local_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  undefined8 uStack_18;
  undefined8 local_10;
  undefined4 local_8;
  
  uVar3 = *(uint *)(param_3 + 0x48);
  if (*(char *)(param_3 + 0x4c) == '\0') {
    uVar2 = uVar3;
    uVar3 = 1;
  }
  else {
    uVar2 = 1;
  }
  puVar1 = param_6 + uVar3;
  puVar9 = param_5;
  do {
    if (puVar1 == param_6) {
      local_50 = 0;
      uStack_48 = 0;
      local_40 = 0;
      uStack_38 = 0;
      *param_4 = uVar3;
      iVar5 = FUN_00323e08(param_1,*(undefined4 *)(param_3 + 0x3c),uVar2,&local_50);
      if (iVar5 != 0) {
        return;
      }
      if (*(char *)(param_3 + 0x4c) == '\0') {
        local_50 = CONCAT44(local_50._4_4_,*param_5);
      }
      else {
        local_50 = (ulong)local_50._4_4_ << 0x20;
      }
      FUN_002d3cd4(param_2,&local_50);
      FUN_00322428();
      return;
    }
    FUN_002d4900(param_2,puVar9);
    iVar5 = FUN_00322428();
    if (iVar5 != 0) {
      return;
    }
    local_88 = (ulong)(ushort)uVar2 << 0x20;
    FUN_00323da0(param_1,*(undefined4 *)(param_3 + 0x3c),(long)&local_88 + 6);
    uVar6 = FUN_00323db8(param_1,*(undefined4 *)(param_3 + 0x3c));
    local_50 = 0;
    uStack_48 = 0;
    local_40 = 0;
    uStack_38 = 0;
    local_10 = 0;
    local_30 = 0;
    uStack_28 = 0;
    local_8 = 0;
    local_20 = 0;
    uStack_18 = 0;
    FUN_0032453c(param_1,uVar6,*puVar9,&local_50);
    FUN_002d4a48(param_2,&local_50,param_6);
    iVar5 = FUN_00322428();
    if (iVar5 != 0) {
      return;
    }
    iVar5 = FUN_003239e8(param_1,param_2,*param_6,&local_88);
    if (iVar5 != 0) {
      return;
    }
    FUN_002d5aa0(param_2,*param_6,&local_88,param_7);
    iVar5 = FUN_00322428();
    if (iVar5 != 0) {
      return;
    }
    uVar4 = *(uint *)(param_3 + 0x3c);
    local_80 = 0;
    lStack_78 = 0;
    if ((uVar4 >> 1 & 1) == 0) {
      local_90 = 0x11;
      local_6e = 0;
      local_8f = 0x90;
      local_70 = 0x40;
      local_6f = 5;
      local_6c = *(int *)(param_3 + 0x48) * 0x300;
      iStack_68 = *(int *)(param_3 + 0x44) * 1000;
      local_64 = *(int *)(param_3 + 0x40) * 1000;
      local_58 = 2;
      local_60 = &local_90;
      FUN_002d6f4c(param_2,*param_6,*param_7,&local_70);
    }
    else {
      if ((uVar4 >> 8 & 1) == 0) {
        if ((uVar4 >> 9 & 1) != 0) {
          uVar8 = 0x6970636d;
          goto LAB_003246b0;
        }
      }
      else {
        uVar8 = 0x74776f73;
LAB_003246b0:
        local_80 = (ulong)uVar8;
      }
      uVar7 = 24000;
      if ((((uVar4 >> 0x10 & 1) == 0) && (uVar7 = 48000, (uVar4 >> 0x11 & 1) == 0)) &&
         (uVar7 = 0x7700, (uVar4 & 0x40000) == 0)) {
        uVar7 = 0xee00;
      }
      lStack_78 = (ulong)uVar7 << 0x20;
      FUN_002d6568(param_2,*param_6,*param_7,0x31,&local_80);
    }
    iVar5 = FUN_00322428();
    param_6 = param_6 + 1;
    puVar9 = puVar9 + 1;
    if (iVar5 != 0) {
      return;
    }
  } while( true );
}

