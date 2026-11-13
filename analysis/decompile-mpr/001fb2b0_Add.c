// mpr::BaseList::Add
// Ghidra address: 001fb2b0

/* mpr::BaseList::Add(void*, unsigned int) */

undefined8 __thiscall mpr::BaseList::Add(BaseList *this,void *param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  char cVar3;
  undefined8 uVar4;
  long lVar5;
  
  cVar3 = IsFull(this);
  if (cVar3 == '\0') {
    uVar1 = *(uint *)(this + 0x18);
    lVar5 = *(long *)(this + 8);
    iVar2 = *(int *)(this + 0x10);
    *(void **)(lVar5 + (ulong)uVar1 * 0x10) = param_1;
    *(uint *)(lVar5 + (ulong)uVar1 * 0x10 + 8) = param_2;
    if (uVar1 < iVar2 - 1U) {
      *(uint *)(this + 0x18) = uVar1 + 1;
    }
    else {
      *(undefined4 *)(this + 0x18) = 0;
    }
    uVar4 = 0;
  }
  else {
    uVar4 = 3;
  }
  return uVar4;
}

