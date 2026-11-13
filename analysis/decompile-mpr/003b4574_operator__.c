// std::_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*>::operator++
// Ghidra address: 003b4574

/* std::_Deque_iterator<sidb::FlushInfo, sidb::FlushInfo&,
   sidb::FlushInfo*>::TEMPNAMEPLACEHOLDERVALUE() */

void __thiscall
std::_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*>::operator++
          (_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*> *this)

{
  long lVar1;
  
  lVar1 = *(long *)this;
  *(long *)this = lVar1 + 0x10;
  if (lVar1 + 0x10 == *(long *)(this + 0x10)) {
    lVar1 = *(long *)(*(long *)(this + 0x18) + 8);
    *(long *)(this + 0x18) = *(long *)(this + 0x18) + 8;
    *(long *)this = lVar1;
    *(long *)(this + 8) = lVar1;
    *(long *)(this + 0x10) = lVar1 + 0x200;
  }
  return;
}

