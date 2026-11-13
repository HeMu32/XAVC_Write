// FUN_003234f4
// Ghidra address: 003234f4

int FUN_003234f4(long param_1,long param_2,long param_3,long param_4,long *param_5,char param_6)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  long lVar5;
  long local_8;
  
  uVar1 = 0x69736f36;
  if (param_6 == '\0') {
    uVar1 = 0x69736f32;
  }
  uVar4 = *(undefined8 *)(param_1 + 0xb0);
  *param_5 = 0;
  local_8 = 0;
  FUN_002d3058(uVar4,uVar1);
  FUN_002d3080(*(undefined8 *)(param_1 + 0xb0),*(undefined8 *)(param_1 + 0xa0),param_2,&local_8);
  iVar2 = FUN_00322428();
  if (iVar2 == 0) {
    lVar5 = param_2 + local_8;
    FUN_002d411c(*(undefined8 *)(param_1 + 0xb0),*(undefined8 *)(param_1 + 0xa0),lVar5,&local_8);
    iVar2 = FUN_00322428();
    if (iVar2 == 0) {
      lVar5 = lVar5 + local_8;
      if (param_3 != 0 && param_4 != 0) {
        FUN_002d4260(*(undefined8 *)(param_1 + 0xb0),*(undefined8 *)(param_1 + 0xa0),lVar5,param_3,
                     param_4,&local_8);
        iVar3 = FUN_00322428();
        if (iVar3 != 0) {
          return iVar3;
        }
        lVar5 = lVar5 + local_8;
      }
      *param_5 = lVar5 - param_2;
    }
  }
  return iVar2;
}

