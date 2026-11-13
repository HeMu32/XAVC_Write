// std::_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo_const&,sidb::FlushInfo_const*>::_Deque_iterator
// Ghidra address: 00394908

/* std::_Deque_iterator<sidb::FlushInfo, sidb::FlushInfo const&, sidb::FlushInfo
   const*>::_Deque_iterator(std::_Deque_iterator<sidb::FlushInfo, sidb::FlushInfo&,
   sidb::FlushInfo*> const&) */

void __thiscall
std::_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo_const&,sidb::FlushInfo_const*>::_Deque_iterator
          (_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo_const&,sidb::FlushInfo_const*> *this,
          _Deque_iterator *param_1)

{
  undefined8 uVar1;
  
  *(undefined8 *)this = *(undefined8 *)param_1;
  *(undefined8 *)(this + 8) = *(undefined8 *)(param_1 + 8);
  uVar1 = *(undefined8 *)(param_1 + 0x18);
  *(undefined8 *)(this + 0x10) = *(undefined8 *)(param_1 + 0x10);
  *(undefined8 *)(this + 0x18) = uVar1;
  return;
}

