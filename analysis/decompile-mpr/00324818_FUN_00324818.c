// FUN_00324818
// Ghidra address: 00324818

int FUN_00324818(undefined8 param_1,undefined8 param_2,long param_3)

{
  int iVar1;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 local_c;
  undefined1 local_b;
  undefined1 local_a;
  undefined1 local_9;
  int local_8;
  
  FUN_002c832c(param_2,param_3);
  iVar1 = FUN_00322428();
  if (iVar1 == 0) {
    FUN_002c846c(param_2,1,param_3 + 0x18);
    iVar1 = FUN_00322428();
    if (iVar1 == 0) {
      FUN_002c8510(param_2,1,param_3 + 0x1c);
      iVar1 = FUN_00322428();
      if (iVar1 == 0) {
        FUN_002c861c(param_2,1,param_3 + 0x44);
        iVar1 = FUN_00322428();
        if (iVar1 == 0) {
          return 0;
        }
        local_e = 0x203;
      }
      else {
        local_e = 0x202;
      }
    }
    else {
      local_e = 0x201;
    }
  }
  else {
    local_e = 0x200;
  }
  local_9 = 0;
  local_a = 0;
  local_b = 0;
  local_c = 3;
  local_10 = 0x2301;
  local_8 = iVar1;
  FUN_00322494(&local_10,0xc);
  return iVar1;
}

