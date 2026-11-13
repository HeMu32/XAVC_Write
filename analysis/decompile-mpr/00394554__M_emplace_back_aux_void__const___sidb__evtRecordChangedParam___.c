// std::vector<void(*)(sidb::evtRecordChangedParam&),std::allocator<void(*)(sidb::evtRecordChangedParam&)>>::_M_emplace_back_aux<void(*const&)(sidb::evtRecordChangedParam&)>
// Ghidra address: 00394554

/* void std::vector<void (*)(sidb::evtRecordChangedParam&), std::allocator<void
   (*)(sidb::evtRecordChangedParam&)> >::_M_emplace_back_aux<void (*
   const&)(sidb::evtRecordChangedParam&)>(void (* const&)(sidb::evtRecordChangedParam&)) */

void __thiscall
std::
vector<void(*)(sidb::evtRecordChangedParam&),std::allocator<void(*)(sidb::evtRecordChangedParam&)>>
::_M_emplace_back_aux<void(*const&)(sidb::evtRecordChangedParam&)>
          (vector<void(*)(sidb::evtRecordChangedParam&),std::allocator<void(*)(sidb::evtRecordChangedParam&)>>
           *this,_func_void_evtRecordChangedParam_ptr *param_1)

{
  void *__src;
  ulong uVar1;
  void *__dest;
  ulong uVar2;
  size_t __n;
  
  uVar1 = *(long *)(this + 8) - *(long *)this >> 3;
  uVar2 = uVar1;
  if (uVar1 == 0) {
    uVar2 = 1;
  }
  uVar2 = uVar1 + uVar2;
  if (uVar2 < uVar1 || 0x1fffffffffffffff < uVar2) {
    uVar2 = 0x1fffffffffffffff;
  }
  else {
    __dest = (void *)0x0;
    if (uVar2 == 0) goto LAB_003945ac;
  }
  __dest = operator_new(uVar2 << 3);
LAB_003945ac:
  __src = *(void **)this;
  __n = *(long *)(this + 8) - (long)__src;
  if ((long)__dest + __n != 0) {
    *(undefined8 *)((long)__dest + __n) = *(undefined8 *)param_1;
  }
  if ((long)__n >> 3 != 0) {
    memmove(__dest,__src,__n);
  }
  if (__src != (void *)0x0) {
    operator_delete(__src);
  }
  *(void **)this = __dest;
  *(size_t *)(this + 8) = (long)__dest + __n + 8;
  *(void **)(this + 0x10) = (void *)((long)__dest + uVar2 * 8);
  return;
}

