// std::deque<sidb::FlushInfo,std::allocator<sidb::FlushInfo>>::_M_new_elements_at_front
// Ghidra address: 003a9068

/* std::deque<sidb::FlushInfo, std::allocator<sidb::FlushInfo> >::_M_new_elements_at_front(unsigned
   long) */

void __thiscall
std::deque<sidb::FlushInfo,std::allocator<sidb::FlushInfo>>::_M_new_elements_at_front
          (deque<sidb::FlushInfo,std::allocator<sidb::FlushInfo>> *this,ulong param_1)

{
  long lVar1;
  void *pvVar2;
  ulong uVar3;
  ulong uVar4;
  
  lVar1 = operator-((_Deque_iterator *)(this + 0x30),(_Deque_iterator *)(this + 0x10));
  if (0xfffffffffffffffU - lVar1 < param_1) {
    std::__throw_length_error("deque::_M_new_elements_at_front");
  }
  uVar3 = param_1 + 0x1f >> 5;
  if ((ulong)(*(long *)(this + 0x28) - *(long *)this >> 3) < uVar3) {
    _M_reallocate_map(this,uVar3,true);
  }
  for (uVar4 = 1; uVar4 <= uVar3; uVar4 = uVar4 + 1) {
    lVar1 = *(long *)(this + 0x28);
    pvVar2 = operator_new(0x200);
    *(void **)(lVar1 + uVar4 * -8) = pvVar2;
  }
  return;
}

