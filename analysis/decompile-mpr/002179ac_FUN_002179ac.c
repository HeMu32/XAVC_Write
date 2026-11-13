// FUN_002179ac
// Ghidra address: 002179ac

void FUN_002179ac(long param_1)

{
  undefined2 uVar1;
  int iVar2;
  normalLock *this;
  undefined1 auStack_98 [8];
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined8 local_18;
  undefined1 local_10;
  undefined8 local_8;
  
  local_50 = 0x402f02310;
  FUN_0021777c(&local_50,8);
  local_90 = *(undefined8 *)(param_1 + 0x70);
  uStack_88 = *(undefined8 *)(param_1 + 0x78);
  local_50 = *(undefined8 *)(param_1 + 0x18);
  local_48 = *(undefined4 *)(param_1 + 0x20);
  local_44 = *(undefined4 *)(param_1 + 0x24);
  local_40 = *(undefined4 *)(param_1 + 0x28);
  local_3c = *(undefined4 *)(param_1 + 0x2c);
  local_38 = *(undefined4 *)(param_1 + 0x30);
  local_34 = *(undefined4 *)(param_1 + 0x34);
  local_30 = *(undefined4 *)(param_1 + 0x38);
  local_2c = *(undefined4 *)(param_1 + 0x3c);
  local_28 = *(undefined4 *)(param_1 + 0x40);
  local_24 = *(undefined4 *)(param_1 + 0x44);
  local_20 = *(undefined4 *)(param_1 + 0x48);
  local_18 = *(undefined8 *)(param_1 + 0x50);
  local_10 = *(undefined1 *)(param_1 + 0x58);
  local_8 = *(undefined8 *)(param_1 + 0x60);
  iVar2 = FUN_00322b18(*(undefined8 *)(param_1 + 0x10),&local_50);
  if (iVar2 == 0) {
    iVar2 = FUN_0032a380(*(undefined8 *)(param_1 + 0x10),*(undefined8 *)(param_1 + 0x68),0,&local_90
                         ,auStack_98);
    if (iVar2 == 0) {
      if (*(long *)(param_1 + 0x90) != 0) {
        local_80 = 0;
        local_78 = 0;
        local_70 = 0;
        uStack_68 = 0;
        local_60 = 0;
        uStack_58 = 0;
        iVar2 = FUN_003292b0(*(undefined8 *)(param_1 + 0x10),&local_80);
        if (iVar2 == 0) {
          mpr::thread::normalLock::lock(*(normalLock **)(param_1 + 0x90));
          this = *(normalLock **)(param_1 + 0x90);
          *(ulong *)(this + 0x48) = local_80;
          *(undefined8 *)(this + 0x50) = local_78;
          *(undefined8 *)(this + 0x58) = local_70;
          *(undefined8 *)(this + 0x60) = uStack_68;
          *(undefined8 *)(this + 0x68) = local_60;
          *(undefined8 *)(this + 0x70) = uStack_58;
          this[0x40] = (normalLock)0x1;
          mpr::thread::normalLock::unlock(this);
        }
      }
      goto LAB_00217ac8;
    }
    uVar1 = 0x300;
  }
  else {
    uVar1 = 0x2f8;
  }
  local_80._0_4_ = CONCAT22(uVar1,0x2310);
  local_80 = (ulong)CONCAT24(3,(undefined4)local_80);
  local_78 = CONCAT44(local_78._4_4_,iVar2);
  FUN_0021777c(&local_80,0xc);
  FUN_001fe0e8(*(undefined8 *)(param_1 + 0x88),iVar2);
LAB_00217ac8:
  local_80 = 0x403082310;
  FUN_0021777c(&local_80,8);
  return;
}

