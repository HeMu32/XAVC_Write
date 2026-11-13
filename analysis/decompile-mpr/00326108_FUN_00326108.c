// FUN_00326108
// Ghidra address: 00326108

void FUN_00326108(undefined8 param_1,undefined8 param_2,undefined4 param_3,long param_4,
                 undefined4 *param_5,undefined4 *param_6,undefined8 param_7)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  undefined8 uStack_10;
  undefined8 local_8;
  
  iVar3 = (uint)*(ushort *)(param_4 + 0x2a) << 0x10;
  if (*(ushort *)(param_4 + 0x2a) == 0x5a0) {
    iVar3 = 0x7800000;
  }
  uVar1 = *(ushort *)(param_4 + 0x28);
  FUN_002d4900(param_2);
  iVar2 = FUN_00322428();
  if (iVar2 == 0) {
    local_58 = 0;
    uStack_50 = 0;
    local_8 = 0;
    local_48 = 0;
    uStack_40 = 0;
    local_38 = 0;
    uStack_30 = 0;
    local_28 = 0;
    uStack_20 = 0;
    local_18 = 0;
    uStack_10 = 0;
    FUN_003260b0(param_1,0,iVar3,(ulong)uVar1 << 0x10,*(undefined4 *)(param_4 + 0x24),&local_58);
    FUN_002d4964(param_2,&local_58,param_6);
    iVar2 = FUN_00322428();
    if ((((iVar2 == 0) &&
         (iVar3 = FUN_00323930(param_1,param_2,iVar3,(ulong)uVar1 << 0x10,
                               *(undefined4 *)(param_4 + 0x30),*param_6), iVar3 == 0)) &&
        (iVar3 = FUN_003239e8(param_1,param_2,*param_6,param_7), iVar3 == 0)) &&
       (iVar3 = FUN_00325eb0(param_1,param_2,param_3,0,param_4), iVar3 == 0)) {
      *param_5 = 0;
      FUN_00323cc0(param_1,param_2,0,param_4);
    }
  }
  return;
}

