// mpr::BaseList::GetSize
// Ghidra address: 001fb698

/* mpr::BaseList::GetSize() const */

int __thiscall mpr::BaseList::GetSize(BaseList *this)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint local_4;
  
  local_4 = *(uint *)(this + 0x14);
  iVar3 = GetNum(this);
  iVar4 = 0;
  while (iVar3 = iVar3 + -1, iVar3 != -1) {
    uVar1 = *(uint *)(this + 0x10);
    iVar4 = iVar4 + *(int *)(*(long *)(this + 8) + (ulong)local_4 * 0x10 + 8);
    uVar2 = 0;
    if (uVar1 != 0) {
      uVar2 = (local_4 + 1) / uVar1;
    }
    local_4 = (local_4 + 1) - uVar2 * uVar1;
  }
  return iVar4;
}

