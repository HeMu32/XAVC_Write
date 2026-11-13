// std::move_backward<sidb::FlushInfo>
// Ghidra address: 003ad2ec

/* std::_Deque_iterator<sidb::FlushInfo, sidb::FlushInfo&, sidb::FlushInfo*>
   std::move_backward<sidb::FlushInfo>(std::_Deque_iterator<sidb::FlushInfo, sidb::FlushInfo const&,
   sidb::FlushInfo const*>, std::_Deque_iterator<sidb::FlushInfo, sidb::FlushInfo const&,
   sidb::FlushInfo const*>, std::_Deque_iterator<sidb::FlushInfo, sidb::FlushInfo&,
   sidb::FlushInfo*>) */

_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*> *
std::move_backward<sidb::FlushInfo>
          (_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*> *param_1,
          _Deque_iterator *param_2,_Deque_iterator *param_3,
          _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*> *param_4)

{
  long lVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  
  for (lVar1 = operator-(param_3,param_2); 0 < lVar1; lVar1 = lVar1 - lVar4) {
    lVar3 = *(long *)param_3;
    lVar2 = *(long *)param_4;
    lVar4 = lVar3 - *(long *)(param_3 + 8) >> 4;
    lVar5 = lVar2 - *(long *)(param_4 + 8) >> 4;
    if (lVar4 == 0) {
      lVar4 = 0x20;
      lVar3 = *(long *)(*(long *)(param_3 + 0x18) + -8) + 0x200;
    }
    if (lVar5 == 0) {
      lVar5 = 0x20;
      lVar2 = *(long *)(*(long *)(param_4 + 0x18) + -8) + 0x200;
    }
    if (lVar1 < lVar4) {
      lVar4 = lVar1;
    }
    if (lVar5 < lVar4) {
      lVar4 = lVar5;
    }
    if (lVar4 * 0x10 != 0) {
      memmove((void *)(lVar2 + lVar4 * -0x10),(void *)(lVar3 + lVar4 * -0x10),lVar4 * 0x10);
    }
    _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo_const&,sidb::FlushInfo_const*>::operator+=
              ((_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo_const&,sidb::FlushInfo_const*> *)
               param_3,-lVar4);
    _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*>::operator+=(param_4,-lVar4);
  }
  _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*>::_Deque_iterator
            (param_1,(_Deque_iterator *)param_4);
  return param_1;
}

