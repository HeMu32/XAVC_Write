// std::copy<std::move_iterator<std::_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*>>,std::_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*>>
// Ghidra address: 003b4878

/* std::_Deque_iterator<sidb::FlushInfo, sidb::FlushInfo&, sidb::FlushInfo*>
   std::copy<std::move_iterator<std::_Deque_iterator<sidb::FlushInfo, sidb::FlushInfo&,
   sidb::FlushInfo*> >, std::_Deque_iterator<sidb::FlushInfo, sidb::FlushInfo&, sidb::FlushInfo*>
   >(std::move_iterator<std::_Deque_iterator<sidb::FlushInfo, sidb::FlushInfo&, sidb::FlushInfo*> >,
   std::move_iterator<std::_Deque_iterator<sidb::FlushInfo, sidb::FlushInfo&, sidb::FlushInfo*> >,
   std::_Deque_iterator<sidb::FlushInfo, sidb::FlushInfo&, sidb::FlushInfo*>) */

_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*> *
std::
copy<std::move_iterator<std::_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*>>,std::_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*>>
          (_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*> *param_1,
          _Deque_iterator *param_2,_Deque_iterator *param_3,_Deque_iterator *param_4)

{
  undefined8 uVar1;
  long lVar2;
  _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*> a_Stack_1c0 [32];
  _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*> a_Stack_1a0 [32];
  _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*> a_Stack_180 [32];
  _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*> a_Stack_160 [32];
  _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*> a_Stack_140 [32];
  _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*> a_Stack_120 [32];
  _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*> a_Stack_100 [32];
  _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*> a_Stack_e0 [32];
  _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*> a_Stack_c0 [32];
  _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*> a_Stack_a0 [32];
  _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*> a_Stack_80 [32];
  undefined8 *local_60 [4];
  _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*> a_Stack_40 [32];
  undefined8 *local_20 [4];
  
  _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*>::_Deque_iterator
            (a_Stack_1c0,param_2);
  _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*>::_Deque_iterator
            ((_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*> *)local_20,
             (_Deque_iterator *)a_Stack_1c0);
  _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*>::_Deque_iterator
            (a_Stack_1a0,(_Deque_iterator *)local_20);
  _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*>::_Deque_iterator
            (a_Stack_180,param_3);
  _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*>::_Deque_iterator
            ((_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*> *)local_20,
             (_Deque_iterator *)a_Stack_180);
  _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*>::_Deque_iterator
            (a_Stack_160,(_Deque_iterator *)local_20);
  _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*>::_Deque_iterator
            (a_Stack_140,param_4);
  _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*>::_Deque_iterator
            (a_Stack_a0,(_Deque_iterator *)a_Stack_1a0);
  _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*>::_Deque_iterator
            (a_Stack_80,(_Deque_iterator *)a_Stack_a0);
  _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*>::_Deque_iterator
            (a_Stack_e0,(_Deque_iterator *)a_Stack_160);
  _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*>::_Deque_iterator
            (a_Stack_c0,(_Deque_iterator *)a_Stack_e0);
  _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*>::_Deque_iterator
            (a_Stack_120,(_Deque_iterator *)a_Stack_140);
  _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*>::_Deque_iterator
            (a_Stack_100,(_Deque_iterator *)a_Stack_120);
  _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*>::_Deque_iterator
            ((_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*> *)local_20,
             (_Deque_iterator *)a_Stack_80);
  _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*>::_Deque_iterator
            (a_Stack_40,(_Deque_iterator *)a_Stack_c0);
  _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*>::_Deque_iterator
            ((_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*> *)local_60,
             (_Deque_iterator *)a_Stack_100);
  for (lVar2 = operator-((_Deque_iterator *)a_Stack_40,(_Deque_iterator *)local_20); 0 < lVar2;
      lVar2 = lVar2 + -1) {
    uVar1 = local_20[0][1];
    *local_60[0] = *local_20[0];
    local_60[0][1] = uVar1;
    _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*>::operator++
              ((_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*> *)local_20);
    _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*>::operator++
              ((_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*> *)local_60);
  }
  _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*>::_Deque_iterator
            (param_1,(_Deque_iterator *)local_60);
  return param_1;
}

