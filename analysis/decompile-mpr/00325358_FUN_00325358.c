// FUN_00325358
// Ghidra address: 00325358

void FUN_00325358(long param_1,undefined8 param_2,ulong param_3,char param_4,undefined1 *param_5)

{
  int iVar1;
  uint uVar2;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  undefined8 uStack_10;
  undefined8 local_8;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  uStack_10 = 0;
  uVar2 = 1;
  local_8 = 0;
  FUN_002cd6d8(*(undefined8 *)(param_1 + 0x108),param_2,param_3,&local_28);
  iVar1 = FUN_00322428();
  local_30 = 0;
  do {
    if ((uint)local_8 < uVar2) {
      return;
    }
    if (iVar1 == 0) {
      FUN_002cd828(*(undefined8 *)(param_1 + 0x108),param_2,param_3 & 0xffffffff,uVar2,&local_30);
      iVar1 = FUN_00322428();
      if (iVar1 == 0) {
        if (local_30._1_1_ == param_4) {
          *param_5 = (char)uVar2;
          return;
        }
        iVar1 = 0;
        if ((uint)local_8 <= uVar2) {
          iVar1 = 4;
        }
      }
    }
    uVar2 = uVar2 + 1;
  } while( true );
}

