// FUN_0028b328
// Ghidra address: 0028b328

ulong FUN_0028b328(long param_1,undefined8 param_2,undefined4 param_3,void *param_4,
                  undefined4 param_5)

{
  uint uVar1;
  ulong uVar2;
  void *pvVar3;
  long *plVar4;
  undefined1 auStack_5f0 [1520];
  
  plVar4 = *(long **)(param_1 + 8);
  if (plVar4 == (long *)0x0) {
    uVar2 = FUN_0028b2fc();
    return uVar2;
  }
  pvVar3 = memcpy(auStack_5f0,param_4,0x5e8);
  uVar1 = (**(code **)(*plVar4 + 0xa0))(plVar4,param_2,param_3,pvVar3,param_5);
  uVar2 = 0;
  if (uVar1 != 0) {
    FUN_00290aa4(0,"xavcIfo_CommonMediaProfileParser.cpp",0x142,uVar1);
    uVar2 = (ulong)uVar1;
  }
  return uVar2;
}

