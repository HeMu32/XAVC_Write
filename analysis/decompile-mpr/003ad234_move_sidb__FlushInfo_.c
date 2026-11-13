// std::move<sidb::FlushInfo>
// Ghidra address: 003ad234

/* std::_Deque_iterator<sidb::FlushInfo, sidb::FlushInfo&, sidb::FlushInfo*>
   std::move<sidb::FlushInfo>(std::_Deque_iterator<sidb::FlushInfo, sidb::FlushInfo const&,
   sidb::FlushInfo const*>, std::_Deque_iterator<sidb::FlushInfo, sidb::FlushInfo const&,
   sidb::FlushInfo const*>, std::_Deque_iterator<sidb::FlushInfo, sidb::FlushInfo&,
   sidb::FlushInfo*>) */

_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*> *
std::move<sidb::FlushInfo>
          (_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*> *param_1,
          _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo_const&,sidb::FlushInfo_const*> *param_2,
          _Deque_iterator *param_3,
          _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*> *param_4)

{
  long lVar1;
  long lVar2;
  long lVar3;
  
  for (lVar1 = operator-(param_3,(_Deque_iterator *)param_2); 0 < lVar1; lVar1 = lVar1 - lVar3) {
    lVar2 = *(long *)(param_4 + 0x10) - (long)*(void **)param_4 >> 4;
    lVar3 = *(long *)(param_2 + 0x10) - (long)*(void **)param_2 >> 4;
    if (lVar2 < lVar3) {
      lVar3 = lVar2;
    }
    if (lVar1 < lVar3) {
      lVar3 = lVar1;
    }
    if (lVar3 << 4 != 0) {
      memmove(*(void **)param_4,*(void **)param_2,lVar3 << 4);
    }
    _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo_const&,sidb::FlushInfo_const*>::operator+=
              (param_2,lVar3);
    _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*>::operator+=(param_4,lVar3);
  }
  _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*>::_Deque_iterator
            (param_1,(_Deque_iterator *)param_4);
  return param_1;
}

