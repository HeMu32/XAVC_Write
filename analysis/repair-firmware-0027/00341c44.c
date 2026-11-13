// FUN_00341c44
// Ghidra address 00341c44; ELF VMA = Ghidra - 0x100000

undefined8 FUN_00341c44(long param_1,ulong *param_2)

{
  int iVar1;
  ulong uVar2;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  undefined8 uStack_18;
  undefined8 local_10;
  undefined8 uStack_8;
  
  local_40 = 0;
  uStack_38 = 0;
  local_30 = 0;
  uStack_28 = 0;
  local_20 = 0;
  uStack_18 = 0;
  local_10 = 0;
  uStack_8 = 0;
  iVar1 = Fsys_Read(*(undefined8 *)(param_1 + 8),&local_40,8);
  if (iVar1 == 8) {
    uVar2 = FUN_00341c2c(param_1,&local_40);
    uVar2 = uVar2 & 0xffffffff;
    *param_2 = uVar2;
    *(undefined4 *)(param_2 + 1) = local_40._4_4_;
    if (uVar2 != 0) {
      if (uVar2 == 1) {
        iVar1 = Fsys_Read(*(undefined8 *)(param_1 + 8),&local_40,8);
        if (iVar1 != 8) {
          return 1;
        }
        uVar2 = FUN_00341c38(param_1,&local_40);
        *param_2 = uVar2;
        *(undefined4 *)((long)param_2 + 0xc) = 0x10;
      }
      else {
        *(undefined4 *)((long)param_2 + 0xc) = 8;
      }
      return 0;
    }
  }
  return 1;
}

