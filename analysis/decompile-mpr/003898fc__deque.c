// std::deque<sidb::evtRecordChangedParam,std::allocator<sidb::evtRecordChangedParam>>::~deque
// Ghidra address: 003898fc

/* std::deque<sidb::evtRecordChangedParam, std::allocator<sidb::evtRecordChangedParam> >::~deque()
    */

void __thiscall
std::deque<sidb::evtRecordChangedParam,std::allocator<sidb::evtRecordChangedParam>>::~deque
          (deque<sidb::evtRecordChangedParam,std::allocator<sidb::evtRecordChangedParam>> *this)

{
  undefined8 *puVar1;
  long lVar2;
  
  puVar1 = *(undefined8 **)(this + 0x28);
  lVar2 = *(long *)(this + 0x48);
  if (*(long *)this != 0) {
    for (; puVar1 < (undefined8 *)(lVar2 + 8U); puVar1 = puVar1 + 1) {
      operator_delete((void *)*puVar1);
    }
    operator_delete(*(void **)this);
    return;
  }
  return;
}

