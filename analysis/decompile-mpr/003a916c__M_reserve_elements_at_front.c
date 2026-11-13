// std::deque<sidb::FlushInfo,std::allocator<sidb::FlushInfo>>::_M_reserve_elements_at_front
// Ghidra address: 003a916c

/* std::deque<sidb::FlushInfo, std::allocator<sidb::FlushInfo>
   >::_M_reserve_elements_at_front(unsigned long) */

void std::deque<sidb::FlushInfo,std::allocator<sidb::FlushInfo>>::_M_reserve_elements_at_front
               (ulong param_1)

{
  ulong in_x1;
  ulong uVar1;
  
  uVar1 = *(long *)(param_1 + 0x10) - *(long *)(param_1 + 0x18) >> 4;
  if (uVar1 < in_x1) {
    _M_new_elements_at_front
              ((deque<sidb::FlushInfo,std::allocator<sidb::FlushInfo>> *)param_1,in_x1 - uVar1);
  }
  _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*>::operator-
            ((_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*> *)(param_1 + 0x10),
             in_x1);
  return;
}

