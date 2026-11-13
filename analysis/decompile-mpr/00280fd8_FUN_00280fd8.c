// FUN_00280fd8
// Ghidra address: 00280fd8

ulong FUN_00280fd8(long param_1,undefined8 *param_2)

{
  long lVar1;
  ulong uVar2;
  undefined8 uVar3;
  undefined8 local_10;
  undefined8 uStack_8;
  
  lVar1 = *(long *)(param_1 + 8);
  local_10 = 0;
  uStack_8 = 0;
  *param_2 = 0;
  if (lVar1 == 0) {
    FUN_001aaa3c(0x2300,0xffffe700,0x28,*(undefined8 *)(param_1 + 0x18));
    uVar2 = 0xb;
  }
  else {
    uVar2 = Fsys_Seek(lVar1,0,1,&local_10);
    uVar3 = 0x1b2;
    if ((int)uVar2 == 0) {
      uVar2 = Fsys_Seek(*(undefined8 *)(param_1 + 8),0,2,param_2);
      uVar3 = 0x1b9;
      if ((int)uVar2 == 0) {
        uVar2 = Fsys_Seek(*(undefined8 *)(param_1 + 8),local_10,0,&uStack_8);
        if ((int)uVar2 == 0) {
          return uVar2 & 0xffffffff;
        }
        uVar3 = 0x1c0;
      }
    }
    uVar2 = FUN_00280ae8(uVar2,*(undefined8 *)(param_1 + 0x18),*(undefined8 *)(param_1 + 8),uVar3);
    uVar2 = uVar2 & 0xffffffff;
  }
  return uVar2;
}

