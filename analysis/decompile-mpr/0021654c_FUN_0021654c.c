// FUN_0021654c
// Ghidra address: 0021654c

int FUN_0021654c(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  void *pvVar2;
  undefined4 local_84;
  undefined2 local_80;
  undefined2 local_7e;
  undefined1 local_7c;
  undefined1 local_7b;
  undefined1 local_7a;
  undefined1 local_79;
  int local_78;
  undefined1 auStack_70 [32];
  undefined1 auStack_50 [80];
  
  FUN_00194dd8(0x2311,0xe80,param_1);
  pvVar2 = operator_new__(0x200000);
  local_84 = 0x200000;
  FUN_00341acc(auStack_50);
  iVar1 = Fsys_Stat(param_1,auStack_70);
  if (iVar1 == 0) {
    iVar1 = FUN_00342210(auStack_50,param_1,pvVar2,0x200000,&local_84);
    if (iVar1 == 0) {
      iVar1 = FUN_00353e8c(param_2,pvVar2,local_84);
      if (iVar1 != 0) {
        local_7b = 0;
        local_7c = 3;
        local_7a = 0;
        local_80 = 0x2311;
        local_79 = 0;
        local_7e = 0xe83;
        local_78 = iVar1;
        FUN_0020aff4(&local_80,0xc);
      }
      goto LAB_002165e4;
    }
    local_78 = 0;
    local_7e = 0xe82;
  }
  else {
    local_7e = 0xe81;
    local_78 = iVar1;
  }
  local_79 = 0;
  local_7a = 0;
  local_7b = 0;
  local_7c = 3;
  local_80 = 0x2311;
  iVar1 = 0xb;
  FUN_0020aff4(&local_80,0xc);
LAB_002165e4:
  operator_delete__(pvVar2);
  local_7b = 0;
  local_7c = 3;
  local_7a = 0;
  local_80 = 0x2311;
  local_79 = 0;
  local_7e = 0xe84;
  local_78 = iVar1;
  FUN_0020aff4(&local_80,0xc);
  FUN_00341b6c(auStack_50);
  return iVar1;
}

