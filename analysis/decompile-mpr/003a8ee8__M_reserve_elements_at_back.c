// std::deque<sidb::FlushInfo,std::allocator<sidb::FlushInfo>>::_M_reserve_elements_at_back
// Ghidra address: 003a8ee8

/* std::deque<sidb::FlushInfo, std::allocator<sidb::FlushInfo>
   >::_M_reserve_elements_at_back(unsigned long) */

void std::deque<sidb::FlushInfo,std::allocator<sidb::FlushInfo>>::_M_reserve_elements_at_back
               (ulong param_1)

{
  long lVar1;
  void *pvVar2;
  ulong in_x1;
  ulong uVar3;
  ulong uVar4;
  _Deque_iterator *this;
  
  this = (_Deque_iterator *)(param_1 + 0x30);
  uVar3 = (*(long *)(param_1 + 0x40) - *(long *)this >> 4) - 1;
  if (uVar3 < in_x1) {
    uVar3 = in_x1 - uVar3;
    lVar1 = operator-(this,(_Deque_iterator *)(param_1 + 0x10));
    if (0xfffffffffffffffU - lVar1 < uVar3) {
      std::__throw_length_error("deque::_M_new_elements_at_back");
    }
    uVar4 = uVar3 + 0x1f >> 5;
    _M_reserve_map_at_back((deque<sidb::FlushInfo,std::allocator<sidb::FlushInfo>> *)param_1,uVar4);
    for (uVar3 = 1; uVar3 <= uVar4; uVar3 = uVar3 + 1) {
      lVar1 = *(long *)(param_1 + 0x48);
      pvVar2 = operator_new(0x200);
      *(void **)(lVar1 + uVar3 * 8) = pvVar2;
    }
  }
  _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*>::operator+
            ((_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*> *)this,in_x1);
  return;
}

