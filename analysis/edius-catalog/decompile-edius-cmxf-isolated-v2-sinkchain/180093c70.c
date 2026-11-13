// FUN_180093c70
// VA 180093c70

BOOL FUN_180093c70(longlong *param_1)

{
  undefined8 *puVar1;
  BOOL BVar2;
  
  puVar1 = (undefined8 *)*param_1;
  if (puVar1 == (undefined8 *)0x0) {
    SetLastError(6);
    return 0;
  }
  BVar2 = FUN_18009f5a0(puVar1 + 1,(HANDLE)*puVar1);
  return BVar2;
}

