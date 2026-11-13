// FUN_00328170
// Ghidra address: 00328170

int FUN_00328170(long param_1,long param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  byte local_46 [2];
  undefined4 local_44;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined8 local_10;
  undefined8 local_8;
  
  iVar2 = FUN_00326468(param_1,*(undefined8 *)(param_1 + 0x108),param_1 + 0x1c8,param_1 + 300,
                       param_2);
  if ((iVar2 == 0) &&
     (iVar2 = FUN_00324cd4(param_1,*(undefined8 *)(param_1 + 0x108),param_1 + 0x280,param_1 + 0x154,
                           param_2 + 0x38), iVar2 == 0)) {
    local_46[0] = 0;
    local_46[1] = 0;
    local_44 = 0;
    local_40 = 0;
    local_38 = 0;
    local_20 = 0;
    local_1c = 0;
    local_18 = 0;
    local_10 = 0;
    local_8 = 0;
    if (*(char *)(param_1 + 0x275) == '\0') {
      iVar2 = FUN_00327b38(param_1);
    }
    else {
      iVar2 = FUN_00327e3c(param_1,*(undefined8 *)(param_1 + 0x108),param_1 + 0x1c8,param_1 + 0x88,
                           *(undefined4 *)(param_1 + 0x2f0),&local_20,local_46);
    }
    if (iVar2 == 0) {
      if (*(int *)(param_1 + 0x90) == 0) {
        iVar2 = FUN_00327f20(param_1,*(undefined8 *)(param_1 + 0x108),
                             *(undefined4 *)(param_1 + 0x284),*(undefined4 *)(param_1 + 0x308),
                             local_8,&local_44,&local_40,&local_38,local_46 + 1);
        if (iVar2 != 0) {
          return iVar2;
        }
      }
      else {
        local_40 = local_10;
        local_38 = local_8;
      }
      uVar4 = (undefined4)local_10;
      uVar3 = (undefined4)local_8;
      *(undefined4 *)(param_2 + 0x40) = uVar4;
      *(undefined4 *)(param_2 + 0x44) = uVar3;
      *(undefined4 *)(param_2 + 0x48) = uVar4;
      *(undefined4 *)(param_2 + 0x4c) = uVar3;
      *(undefined4 *)(param_2 + 0x50) = uVar4;
      *(undefined4 *)(param_2 + 0x54) = uVar3;
      *(int *)(param_2 + 0x58) = (int)local_40;
      cVar1 = *(char *)(param_1 + 0x300);
      *(int *)(param_2 + 0x5c) = (int)local_38;
      if (cVar1 != '\0') {
        *(int *)(param_2 + 0x50) = (int)*(undefined8 *)(param_1 + 0x2f8);
        *(undefined1 *)(param_1 + 0x300) = 0;
      }
      local_30 = 0;
      local_28 = 0;
      FUN_002cfce4(*(undefined8 *)(param_1 + 0x108),*(undefined4 *)(param_1 + 0x1c8),0);
      iVar2 = FUN_00322428();
      if (iVar2 == 0) {
        FUN_00326cfc(param_1,local_28,*(undefined4 *)(param_1 + 0x1cc),90000,&local_30);
        *(undefined8 *)(param_2 + 0x70) = local_30;
        *(undefined8 *)(param_2 + 0x78) = local_10;
        *(short *)(param_2 + 0x80) = (short)local_20;
        *(short *)(param_2 + 0x82) = (short)local_1c;
        *(undefined4 *)(param_1 + 0x2f0) = local_18;
        *(undefined4 *)(param_1 + 0x308) = local_44;
        *(undefined1 *)(param_2 + 0x90) = 0;
        *(undefined1 *)(param_2 + 0x9e) = 0;
        *(byte *)(param_2 + 0x91) = local_46[0] ^ 1;
        *(char *)(param_2 + 0x9f) = (char)*(undefined4 *)(param_1 + 0x280);
        return 0;
      }
      return iVar2;
    }
  }
  return iVar2;
}

