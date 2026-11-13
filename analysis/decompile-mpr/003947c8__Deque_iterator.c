// std::_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*>::_Deque_iterator
// Ghidra address: 003947c8

/* std::_Deque_iterator<sidb::FlushInfo, sidb::FlushInfo&,
   sidb::FlushInfo*>::_Deque_iterator(std::_Deque_iterator<sidb::FlushInfo, sidb::FlushInfo&,
   sidb::FlushInfo*> const&) */

void __thiscall
std::_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*>::_Deque_iterator
          (_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*> *this,
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

