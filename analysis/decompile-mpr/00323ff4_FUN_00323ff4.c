// FUN_00323ff4
// Ghidra address: 00323ff4

undefined8 FUN_00323ff4(undefined8 param_1,undefined8 param_2,int param_3,long *param_4)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  long local_8;
  
  local_8 = 0;
  FUN_002d3080(param_2,0,0,&local_8);
  uVar3 = FUN_00322428();
  if ((int)uVar3 == 0) {
    lVar1 = local_8 + 4;
    local_8 = lVar1;
    FUN_002d411c(param_2,0,0,&local_8);
    uVar3 = FUN_00322428();
    lVar2 = local_8;
    if ((int)uVar3 == 0) {
      if (param_3 == 0x58415643) {
        FUN_002d95d8(param_2,1,0,0,0x6d646174,0,&local_8);
        uVar3 = FUN_00322428();
        if ((int)uVar3 == 0) {
          *param_4 = lVar2 + local_8 + lVar1;
        }
      }
      else {
        uVar3 = 3;
      }
    }
  }
  return uVar3;
}

