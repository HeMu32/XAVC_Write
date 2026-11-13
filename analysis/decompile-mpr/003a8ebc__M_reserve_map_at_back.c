// std::deque<sidb::FlushInfo,std::allocator<sidb::FlushInfo>>::_M_reserve_map_at_back
// Ghidra address: 003a8ebc

/* std::deque<sidb::FlushInfo, std::allocator<sidb::FlushInfo> >::_M_reserve_map_at_back(unsigned
   long) */

void __thiscall
std::deque<sidb::FlushInfo,std::allocator<sidb::FlushInfo>>::_M_reserve_map_at_back
          (deque<sidb::FlushInfo,std::allocator<sidb::FlushInfo>> *this,ulong param_1)

{
  if ((ulong)(*(long *)(this + 8) - (*(long *)(this + 0x48) - *(long *)this >> 3)) < param_1 + 1) {
    _M_reallocate_map(this,param_1,false);
    return;
  }
  return;
}

