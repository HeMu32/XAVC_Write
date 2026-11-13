// mpr::BaseList::Get
// Ghidra address: 001fb388

/* mpr::BaseList::Get(unsigned int, void**, unsigned int*) const */

undefined8 __thiscall mpr::BaseList::Get(BaseList *this,uint param_1,void **param_2,uint *param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined8 uVar4;
  
  iVar1 = *(int *)(this + 0x14);
  uVar3 = GetNum(this);
  if (param_1 < uVar3) {
    uVar3 = *(uint *)(this + 0x10);
    uVar2 = 0;
    if (uVar3 != 0) {
      uVar2 = (param_1 + iVar1) / uVar3;
    }
    uVar3 = (param_1 + iVar1) - uVar2 * uVar3;
    *param_2 = *(void **)(*(long *)(this + 8) + (ulong)uVar3 * 0x10);
    *param_3 = *(uint *)(*(long *)(this + 8) + (ulong)uVar3 * 0x10 + 8);
    uVar4 = 0;
  }
  else {
    uVar4 = 3;
  }
  return uVar4;
}

