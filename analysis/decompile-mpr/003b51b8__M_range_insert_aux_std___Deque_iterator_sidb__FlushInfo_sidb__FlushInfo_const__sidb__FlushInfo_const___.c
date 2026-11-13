// std::deque<sidb::FlushInfo,std::allocator<sidb::FlushInfo>>::_M_range_insert_aux<std::_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo_const&,sidb::FlushInfo_const*>>
// Ghidra address: 003b51b8

/* void std::deque<sidb::FlushInfo, std::allocator<sidb::FlushInfo>
   >::_M_range_insert_aux<std::_Deque_iterator<sidb::FlushInfo, sidb::FlushInfo const&,
   sidb::FlushInfo const*> >(std::_Deque_iterator<sidb::FlushInfo, sidb::FlushInfo&,
   sidb::FlushInfo*>, std::_Deque_iterator<sidb::FlushInfo, sidb::FlushInfo const&, sidb::FlushInfo
   const*>, std::_Deque_iterator<sidb::FlushInfo, sidb::FlushInfo const&, sidb::FlushInfo const*>,
   std::forward_iterator_tag) */

void std::deque<sidb::FlushInfo,std::allocator<sidb::FlushInfo>>::
     _M_range_insert_aux<std::_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo_const&,sidb::FlushInfo_const*>>
               (deque<sidb::FlushInfo,std::allocator<sidb::FlushInfo>> *param_1,
               _Deque_iterator *param_2,undefined8 *param_3,undefined8 *param_4)

{
  undefined8 uVar1;
  undefined8 local_120;
  undefined8 uStack_118;
  undefined8 local_110;
  undefined8 uStack_108;
  undefined8 local_100;
  undefined8 uStack_f8;
  undefined8 local_f0;
  undefined8 uStack_e8;
  undefined8 local_e0;
  undefined8 uStack_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
  _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*> a_Stack_c0 [32];
  _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*> a_Stack_a0 [96];
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  undefined8 uStack_18;
  undefined8 local_10;
  undefined8 uStack_8;
  
  local_20 = *param_3;
  uStack_18 = param_3[1];
  local_10 = param_3[2];
  uStack_8 = param_3[3];
  local_40 = *param_4;
  uStack_38 = param_4[1];
  local_30 = param_4[2];
  uStack_28 = param_4[3];
  uVar1 = operator-((_Deque_iterator *)&local_40,(_Deque_iterator *)&local_20);
  if (*(long *)param_2 == *(long *)(param_1 + 0x10)) {
    _M_reserve_elements_at_front((ulong)param_1);
    _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*>::_Deque_iterator
              (a_Stack_c0,(_Deque_iterator *)&local_e0);
    local_100 = *param_3;
    uStack_f8 = param_3[1];
    local_f0 = param_3[2];
    uStack_e8 = param_3[3];
    local_120 = *param_4;
    uStack_118 = param_4[1];
    local_110 = param_4[2];
    uStack_108 = param_4[3];
    FUN_003b45ac(a_Stack_a0,&local_100,&local_120,a_Stack_c0);
    *(undefined8 *)(param_1 + 0x10) = local_e0;
    *(undefined8 *)(param_1 + 0x18) = uStack_d8;
    *(undefined8 *)(param_1 + 0x20) = local_d0;
    *(undefined8 *)(param_1 + 0x28) = uStack_c8;
  }
  else if (*(long *)param_2 == *(long *)(param_1 + 0x30)) {
    _M_reserve_elements_at_back((ulong)param_1);
    _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*>::_Deque_iterator
              (a_Stack_c0,(_Deque_iterator *)(param_1 + 0x30));
    local_100 = *param_3;
    uStack_f8 = param_3[1];
    local_f0 = param_3[2];
    uStack_e8 = param_3[3];
    local_120 = *param_4;
    uStack_118 = param_4[1];
    local_110 = param_4[2];
    uStack_108 = param_4[3];
    FUN_003b45ac(a_Stack_a0,&local_100,&local_120,a_Stack_c0);
    *(undefined8 *)(param_1 + 0x30) = local_e0;
    *(undefined8 *)(param_1 + 0x38) = uStack_d8;
    *(undefined8 *)(param_1 + 0x40) = local_d0;
    *(undefined8 *)(param_1 + 0x48) = uStack_c8;
  }
  else {
    _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*>::_Deque_iterator
              (a_Stack_a0,param_2);
    local_100 = *param_3;
    uStack_f8 = param_3[1];
    local_f0 = param_3[2];
    uStack_e8 = param_3[3];
    local_120 = *param_4;
    uStack_118 = param_4[1];
    local_110 = param_4[2];
    uStack_108 = param_4[3];
    _M_insert_aux<std::_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo_const&,sidb::FlushInfo_const*>>
              (param_1,a_Stack_a0,&local_100,&local_120,uVar1);
  }
  return;
}

