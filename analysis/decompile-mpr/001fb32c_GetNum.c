// mpr::BaseList::GetNum
// Ghidra address: 001fb32c

/* mpr::BaseList::GetNum() const */

int __thiscall mpr::BaseList::GetNum(BaseList *this)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  uVar1 = *(uint *)(this + 0x14);
  uVar2 = *(uint *)(this + 0x18);
  if (uVar2 < uVar1) {
    iVar3 = (uVar2 - uVar1) + *(int *)(this + 0x10);
  }
  else {
    iVar3 = uVar2 - uVar1;
  }
  return iVar3;
}

