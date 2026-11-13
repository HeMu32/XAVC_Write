// FUN_1800b8db0
// VA 1800b8db0

uint FUN_1800b8db0(longlong param_1)

{
  DWORD DVar1;
  BOOL BVar2;
  
  DVar1 = 0;
  if ((((*(uint *)(param_1 + 0x38) & 0x40000000) != 0) &&
      (((*(int *)(param_1 + 0x50) == 0 || (DVar1 = FUN_1800b92c0(param_1,1), -1 < (int)DVar1)) &&
       (BVar2 = FUN_180093c70((longlong *)(param_1 + 0x28)), BVar2 == 0)))) &&
     (DVar1 = GetLastError(), 0 < (int)DVar1)) {
    return DVar1 & 0xffff | 0x80070000;
  }
  return DVar1;
}

