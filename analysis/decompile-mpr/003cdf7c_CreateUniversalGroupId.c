// mpr::UniversalGroupId::CreateUniversalGroupId
// Ghidra address: 003cdf7c

/* mpr::UniversalGroupId::CreateUniversalGroupId(mpr::UniversalGroupId::UniversalGroupIdGenMethod,
   unsigned char*) */

undefined8 __thiscall
mpr::UniversalGroupId::CreateUniversalGroupId(UniversalGroupId *this,int param_2,long param_3)

{
  byte bVar1;
  
  if (param_2 == 1) {
    FUN_003cda58(this + 0x10,param_3);
    FUN_003cd0b4(param_3 + 8,2);
    *(undefined2 *)(param_3 + 10) = *(undefined2 *)(this + 8);
    *(UniversalGroupId *)(param_3 + 0xc) = this[10];
    *(undefined2 *)(param_3 + 0xd) = *(undefined2 *)(this + 0xd);
    *(UniversalGroupId *)(param_3 + 0xf) = this[0xf];
  }
  else if (param_2 == 4) {
    FUN_003cd954(this + 0x10,param_3);
    FUN_003cd0b4(param_3 + 7,1);
    bVar1 = *(byte *)(param_3 + 7);
    *(byte *)(param_3 + 7) = bVar1 | 0xc0;
    if (*(int *)(this + 0x1c) == 0) {
      bVar1 = bVar1 & 0xdf | 0xc0;
    }
    else {
      bVar1 = bVar1 | 0xe0;
    }
    *(byte *)(param_3 + 7) = bVar1;
    *(undefined8 *)(param_3 + 8) = *(undefined8 *)(this + 8);
  }
  return 0;
}

