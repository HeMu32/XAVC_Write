// std::vector<void(*)(sidb::evtRecordChangedParam&),std::allocator<void(*)(sidb::evtRecordChangedParam&)>>::push_back
// Ghidra address: 0039461c

/* std::vector<void (*)(sidb::evtRecordChangedParam&), std::allocator<void
   (*)(sidb::evtRecordChangedParam&)> >::push_back(void (* const&)(sidb::evtRecordChangedParam&)) */

void __thiscall
std::
vector<void(*)(sidb::evtRecordChangedParam&),std::allocator<void(*)(sidb::evtRecordChangedParam&)>>
::push_back(vector<void(*)(sidb::evtRecordChangedParam&),std::allocator<void(*)(sidb::evtRecordChangedParam&)>>
            *this,_func_void_evtRecordChangedParam_ptr *param_1)

{
  undefined8 *puVar1;
  
  puVar1 = *(undefined8 **)(this + 8);
  if (puVar1 != *(undefined8 **)(this + 0x10)) {
    if (puVar1 != (undefined8 *)0x0) {
      *puVar1 = *(undefined8 *)param_1;
    }
    *(undefined8 **)(this + 8) = puVar1 + 1;
    return;
  }
  _M_emplace_back_aux<void(*const&)(sidb::evtRecordChangedParam&)>(this,param_1);
  return;
}

