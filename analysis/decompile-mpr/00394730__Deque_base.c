// std::_Deque_base<sidb::FlushInfo,std::allocator<sidb::FlushInfo>>::_Deque_base
// Ghidra address: 00394730

/* std::_Deque_base<sidb::FlushInfo, std::allocator<sidb::FlushInfo> >::_Deque_base() */

void __thiscall
std::_Deque_base<sidb::FlushInfo,std::allocator<sidb::FlushInfo>>::_Deque_base
          (_Deque_base<sidb::FlushInfo,std::allocator<sidb::FlushInfo>> *this)

{
  void *pvVar1;
  void *pvVar2;
  void *pvVar3;
  long lVar4;
  
  *(undefined8 *)this = 0;
  *(undefined8 *)(this + 0x10) = 0;
  *(undefined8 *)(this + 0x18) = 0;
  *(undefined8 *)(this + 0x20) = 0;
  *(undefined8 *)(this + 0x28) = 0;
  *(undefined8 *)(this + 8) = 8;
  *(undefined8 *)(this + 0x30) = 0;
  *(undefined8 *)(this + 0x38) = 0;
  *(undefined8 *)(this + 0x40) = 0;
  *(undefined8 *)(this + 0x48) = 0;
  pvVar2 = operator_new(0x40);
  lVar4 = *(long *)(this + 8);
  *(void **)this = pvVar2;
  pvVar3 = operator_new(0x200);
  lVar4 = (lVar4 - 1U >> 1) * 8;
  pvVar1 = (void *)((long)pvVar2 + lVar4);
  *(void **)((long)pvVar2 + lVar4) = pvVar3;
  *(void **)(this + 0x28) = pvVar1;
  *(void **)(this + 0x18) = pvVar3;
  *(long *)(this + 0x20) = (long)pvVar3 + 0x200;
  *(long *)(this + 0x40) = (long)pvVar3 + 0x200;
  *(void **)(this + 0x48) = pvVar1;
  *(void **)(this + 0x10) = pvVar3;
  *(void **)(this + 0x30) = pvVar3;
  *(void **)(this + 0x38) = pvVar3;
  return;
}

