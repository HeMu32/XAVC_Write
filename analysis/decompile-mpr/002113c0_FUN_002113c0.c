// FUN_002113c0
// Ghidra address: 002113c0

int FUN_002113c0(undefined8 param_1,undefined8 param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  void *__ptr;
  undefined8 local_38;
  undefined2 local_30;
  undefined2 local_2e;
  undefined1 local_2c;
  undefined1 local_2b;
  undefined1 local_2a;
  undefined1 local_29;
  int local_28;
  undefined4 local_20;
  undefined4 uStack_1c;
  
  FUN_00194dd8(0x2311,0xe30,param_1);
  local_38 = 0;
  iVar2 = Fsys_Stat(param_1,&local_20);
  if (iVar2 == 0) {
    iVar2 = Fsys_Open(param_1,&local_38,1);
    uVar1 = local_20;
    if (iVar2 == 0) {
      __ptr = malloc(CONCAT44(uStack_1c,local_20));
      iVar2 = Fsys_Read(local_38,__ptr,uVar1);
      if (iVar2 < 0) {
        local_2b = 0;
        iVar3 = 0xb;
        local_2c = 3;
        local_2a = 0;
        local_30 = 0x2311;
        local_29 = 0;
        local_2e = 0xe33;
        local_28 = 0;
        FUN_0020aff4(&local_30,0xc);
      }
      else {
        iVar3 = FUN_00353e8c(param_2,__ptr,local_20);
        if (iVar3 != 0) {
          local_2b = 0;
          local_2c = 3;
          local_2a = 0;
          local_30 = 0x2311;
          local_29 = 0;
          local_2e = 0xe34;
          local_28 = iVar3;
          FUN_0020aff4(&local_30,0xc);
        }
      }
      free(__ptr);
      goto LAB_00211438;
    }
    local_2e = 0xe32;
  }
  else {
    local_2e = 0xe31;
  }
  local_29 = 0;
  local_2a = 0;
  local_2b = 0;
  local_2c = 3;
  local_30 = 0x2311;
  iVar3 = 0xb;
  local_28 = iVar2;
  FUN_0020aff4(&local_30,0xc);
LAB_00211438:
  local_28 = Fsys_Close(local_38);
  if (local_28 != 0) {
    local_2b = 0;
    local_2c = 3;
    local_2a = 0;
    iVar3 = 0xb;
    local_30 = 0x2311;
    local_29 = 0;
    local_2e = 0xe35;
    FUN_0020aff4(&local_30,0xc);
  }
  local_2c = 3;
  local_2b = 0;
  local_30 = 0x2311;
  local_2a = 0;
  local_2e = 0xe36;
  local_29 = 0;
  local_28 = iVar3;
  FUN_0020aff4(&local_30,0xc);
  return iVar3;
}

