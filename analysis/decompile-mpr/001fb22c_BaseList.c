// mpr::BaseList::BaseList
// Ghidra address: 001fb22c

/* mpr::BaseList::BaseList(unsigned int) */

void __thiscall mpr::BaseList::BaseList(BaseList *this,uint param_1)

{
  size_t __size;
  void *__s;
  
  __size = (ulong)(param_1 + 1) << 4;
  *(uint *)(this + 0x10) = param_1 + 1;
  *(undefined **)this = PTR_vtable_00402b60 + 0x10;
  __s = malloc(__size);
  *(void **)(this + 8) = __s;
  memset(__s,0,__size);
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x18) = 0;
  return;
}

