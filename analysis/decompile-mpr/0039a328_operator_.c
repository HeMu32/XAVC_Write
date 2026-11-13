// std::_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*>::operator+
// Ghidra address: 0039a328

/* std::_Deque_iterator<sidb::FlushInfo, sidb::FlushInfo&,
   sidb::FlushInfo*>::TEMPNAMEPLACEHOLDERVALUE(long) const */

void __thiscall
std::_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*>::operator+
          (_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*> *this,long param_1)

{
  _Deque_iterator *p_Var1;
  _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*> *in_x8;
  _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*> a_Stack_20 [32];
  
  _Deque_iterator(a_Stack_20,(_Deque_iterator *)this);
  p_Var1 = (_Deque_iterator *)operator+=(a_Stack_20,param_1);
  _Deque_iterator(in_x8,p_Var1);
  return;
}

