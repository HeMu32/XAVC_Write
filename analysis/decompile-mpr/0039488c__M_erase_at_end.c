// std::deque<sidb::FlushInfo,std::allocator<sidb::FlushInfo>>::_M_erase_at_end
// Ghidra address: 0039488c

/* std::deque<sidb::FlushInfo, std::allocator<sidb::FlushInfo>
   >::_M_erase_at_end(std::_Deque_iterator<sidb::FlushInfo, sidb::FlushInfo&, sidb::FlushInfo*>) */

void __thiscall
std::deque<sidb::FlushInfo,std::allocator<sidb::FlushInfo>>::_M_erase_at_end
          (deque<sidb::FlushInfo,std::allocator<sidb::FlushInfo>> *this,_Deque_iterator *param_2)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  long lVar3;
  _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*> a_Stack_40 [32];
  _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*> a_Stack_20 [32];
  
  _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*>::_Deque_iterator
            (a_Stack_20,param_2);
  _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*>::_Deque_iterator
            (a_Stack_40,(_Deque_iterator *)(this + 0x30));
  puVar2 = *(undefined8 **)(param_2 + 0x18);
  lVar3 = *(long *)(this + 0x48);
  while (puVar2 = puVar2 + 1, puVar2 < (undefined8 *)(lVar3 + 8U)) {
    operator_delete((void *)*puVar2);
  }
  uVar1 = *(undefined8 *)(param_2 + 8);
  *(undefined8 *)(this + 0x30) = *(undefined8 *)param_2;
  *(undefined8 *)(this + 0x38) = uVar1;
  uVar1 = *(undefined8 *)(param_2 + 0x18);
  *(undefined8 *)(this + 0x40) = *(undefined8 *)(param_2 + 0x10);
  *(undefined8 *)(this + 0x48) = uVar1;
  return;
}

