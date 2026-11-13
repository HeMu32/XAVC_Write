// FUN_180094630
// VA 180094630

undefined4 FUN_180094630(longlong *param_1,undefined8 param_2)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  
  puVar1 = (undefined8 *)*param_1;
  if (puVar1 == (undefined8 *)0x0) {
    SetLastError(6);
    return 0;
  }
  uVar2 = FUN_1800a03a0(puVar1 + 1,*puVar1,param_2);
  return uVar2;
}

