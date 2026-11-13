// std::vector<void(*)(sidb::evtRecordChangedParam&),std::allocator<void(*)(sidb::evtRecordChangedParam&)>>::~vector
// Ghidra address: 0038995c

/* std::vector<void (*)(sidb::evtRecordChangedParam&), std::allocator<void
   (*)(sidb::evtRecordChangedParam&)> >::~vector() */

void __thiscall
std::
vector<void(*)(sidb::evtRecordChangedParam&),std::allocator<void(*)(sidb::evtRecordChangedParam&)>>
::~vector(vector<void(*)(sidb::evtRecordChangedParam&),std::allocator<void(*)(sidb::evtRecordChangedParam&)>>
          *this)

{
  if (*(void **)this != (void *)0x0) {
    operator_delete(*(void **)this);
    return;
  }
  return;
}

