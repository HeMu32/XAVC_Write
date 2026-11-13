// FUN_00323600
// Ghidra address: 00323600

void FUN_00323600(long param_1,long param_2,undefined8 *param_3,undefined8 *param_4,long *param_5,
                 undefined8 *param_6,undefined8 *param_7)

{
  int iVar1;
  long local_20;
  undefined8 local_18;
  undefined8 local_10;
  undefined8 local_8;
  
  local_18 = 0;
  local_20 = 0;
  FUN_002d4514(*(undefined8 *)(param_1 + 0xb0),*(undefined8 *)(param_1 + 0xa0),param_2,&local_20);
  iVar1 = FUN_00322428();
  if (iVar1 == 0) {
    param_2 = param_2 + local_20;
    local_8 = 0;
    local_10 = 0;
    FUN_002d3a14(*(undefined8 *)(param_1 + 0xb0),*(undefined8 *)(param_1 + 0xa0),param_2,&local_20,
                 &local_10);
    iVar1 = FUN_00322428();
    if (iVar1 == 0) {
      *param_3 = local_18;
      *param_4 = 0x24;
      *param_5 = param_2;
      *param_6 = local_10;
      *param_7 = local_8;
    }
  }
  return;
}

