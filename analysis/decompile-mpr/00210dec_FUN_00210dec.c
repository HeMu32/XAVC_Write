// FUN_00210dec
// Ghidra address: 00210dec

undefined8 FUN_00210dec(long param_1,undefined8 param_2,undefined8 param_3)

{
  undefined2 local_8;
  undefined2 local_6;
  undefined1 local_4;
  undefined1 local_3;
  undefined1 local_2;
  undefined1 local_1;
  
  local_6 = 0xb00;
  local_4 = 4;
  local_3 = 0;
  local_2 = 0;
  local_1 = 0;
  local_8 = 0x2311;
  FUN_0020aff4(&local_8,8);
  FUN_00210c78(param_1,param_2,param_3,0);
  if (*(long *)(param_1 + 0x18) != 0) {
    local_4 = 4;
    local_6 = 0xb01;
    local_3 = 0;
    local_2 = 0;
    local_1 = 0;
    local_8 = 0x2311;
    FUN_0020aff4(&local_8,8);
    (**(code **)(param_1 + 0x18))(0x40000002,0,0,0,*(undefined8 *)(param_1 + 0x20));
  }
  local_3 = 0;
  local_4 = 4;
  local_2 = 0;
  local_8 = 0x2311;
  local_1 = 0;
  local_6 = 0xb0f;
  FUN_0020aff4(&local_8,8);
  return 0;
}

