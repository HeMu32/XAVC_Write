// std::deque<sidb::FlushInfo,std::allocator<sidb::FlushInfo>>::~deque
// Ghidra address: 003947e4

/* std::deque<sidb::FlushInfo, std::allocator<sidb::FlushInfo> >::~deque() */

void __thiscall
std::deque<sidb::FlushInfo,std::allocator<sidb::FlushInfo>>::~deque
          (deque<sidb::FlushInfo,std::allocator<sidb::FlushInfo>> *this)

{
  undefined8 *puVar1;
  long lVar2;
  _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*> a_Stack_40 [32];
  _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*> a_Stack_20 [32];
  
  _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*>::_Deque_iterator
            (a_Stack_40,(_Deque_iterator *)(this + 0x10));
  _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*>::_Deque_iterator
            (a_Stack_20,(_Deque_iterator *)(this + 0x30));
  if (*(long *)this != 0) {
    lVar2 = *(long *)(this + 0x48);
    for (puVar1 = *(undefined8 **)(this + 0x28); puVar1 < (undefined8 *)(lVar2 + 8U);
        puVar1 = puVar1 + 1) {
      operator_delete((void *)*puVar1);
    }
    operator_delete(*(void **)this);
  }
  return;
}

