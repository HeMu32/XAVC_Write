// std::_Vector_base<std::pair<sidb::set*,unsigned_int>,std::allocator<std::pair<sidb::set*,unsigned_int>>>::~_Vector_base
// Ghidra address: 001a4a14

/* std::_Vector_base<std::pair<sidb::set*, unsigned int>, std::allocator<std::pair<sidb::set*,
   unsigned int> > >::~_Vector_base() */

void __thiscall
std::
_Vector_base<std::pair<sidb::set*,unsigned_int>,std::allocator<std::pair<sidb::set*,unsigned_int>>>
::~_Vector_base(_Vector_base<std::pair<sidb::set*,unsigned_int>,std::allocator<std::pair<sidb::set*,unsigned_int>>>
                *this)

{
  if (*(void **)this != (void *)0x0) {
    operator_delete(*(void **)this);
    return;
  }
  return;
}

