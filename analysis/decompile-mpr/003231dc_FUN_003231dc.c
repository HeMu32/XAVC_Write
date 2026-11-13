// FUN_003231dc
// Ghidra address: 003231dc

ulong FUN_003231dc(long param_1,long param_2,uint param_3,long param_4,uint param_5)

{
  uint uVar1;
  ulong uVar2;
  ulong uVar3;
  short sVar4;
  undefined4 local_30;
  undefined4 local_2c;
  undefined8 local_28;
  char *local_20;
  ulong local_18;
  char *local_10;
  undefined8 local_8;
  
  local_30 = 0;
  if ((param_3 == 0 || param_2 == 0) && (param_5 == 0 || param_4 == 0)) {
    uVar2 = 3;
  }
  else {
    uVar3 = (ulong)param_3;
    FUN_002d3964(*(undefined8 *)(param_1 + 0xb0),1);
    uVar1 = FUN_00322428();
    uVar2 = (ulong)uVar1;
    if (uVar1 == 0) {
      local_28 = CONCAT35(local_28._5_3_,1);
      local_28 = CONCAT53(local_28._3_5_,0x40401);
      FUN_002d33f8(*(undefined8 *)(param_1 + 0xb0),1,&local_28);
      uVar1 = FUN_00322428();
      uVar2 = (ulong)uVar1;
      if (uVar1 == 0) {
        if (param_3 == 0 || param_2 == 0) {
          uVar3 = 0;
          sVar4 = 0;
        }
        else {
          local_28 = 1;
          local_20 = "Look Control data";
          local_18 = 0x12;
          local_10 = "application/octet-stream";
          local_8 = 0x19;
          FUN_002d39b4(*(undefined8 *)(param_1 + 0xb0),1,&local_28);
          uVar1 = FUN_00322428();
          if (uVar1 == 0) {
            local_20 = (char *)0x0;
            local_28 = 0x10001;
            FUN_002d3450(*(undefined8 *)(param_1 + 0xb0),1,&local_28,&local_30);
            uVar1 = FUN_00322428();
            if (uVar1 == 0) {
              local_20 = (char *)0x0;
              local_18 = (ulong)param_3;
              local_2c = 0;
              local_28 = 1;
              FUN_002d35a0(*(undefined8 *)(param_1 + 0xb0),1,local_30,&local_28,&local_2c);
              uVar1 = FUN_00322428();
              if (uVar1 == 0) {
                local_20 = (char *)(ulong)param_3;
                local_28 = param_2;
                FUN_002d390c(*(undefined8 *)(param_1 + 0xb0),1,&local_28);
                uVar1 = FUN_00322428();
              }
            }
          }
          sVar4 = 1;
          if (uVar1 != 0) {
            return (ulong)uVar1;
          }
        }
        if (param_4 != 0 && param_5 != 0) {
          local_28 = (ulong)(ushort)(sVar4 + 1U);
          local_20 = "Lens profile";
          local_18 = 0xd;
          local_10 = "application/octet-stream";
          local_8 = 0x19;
          FUN_002d39b4(*(undefined8 *)(param_1 + 0xb0),1,&local_28);
          uVar1 = FUN_00322428();
          uVar2 = (ulong)uVar1;
          if (uVar1 == 0) {
            local_20 = (char *)0x0;
            local_28 = (ulong)CONCAT12(1,sVar4 + 1U);
            FUN_002d3450(*(undefined8 *)(param_1 + 0xb0),1,&local_28,&local_30);
            uVar1 = FUN_00322428();
            uVar2 = (ulong)uVar1;
            if (uVar1 == 0) {
              local_18 = (ulong)param_5;
              local_2c = 0;
              local_28 = 1;
              local_20 = (char *)uVar3;
              FUN_002d35a0(*(undefined8 *)(param_1 + 0xb0),1,local_30,&local_28,&local_2c);
              uVar1 = FUN_00322428();
              uVar2 = (ulong)uVar1;
              if (uVar1 == 0) {
                local_20 = (char *)(ulong)param_5;
                local_28 = param_4;
                FUN_002d390c(*(undefined8 *)(param_1 + 0xb0),1,&local_28);
                uVar2 = FUN_00322428();
                return uVar2;
              }
            }
          }
        }
      }
    }
  }
  return uVar2;
}

