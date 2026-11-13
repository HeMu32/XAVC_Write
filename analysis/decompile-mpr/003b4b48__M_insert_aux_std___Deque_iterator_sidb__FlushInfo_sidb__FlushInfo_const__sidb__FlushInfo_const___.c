// std::deque<sidb::FlushInfo,std::allocator<sidb::FlushInfo>>::_M_insert_aux<std::_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo_const&,sidb::FlushInfo_const*>>
// Ghidra address: 003b4b48

/* void std::deque<sidb::FlushInfo, std::allocator<sidb::FlushInfo>
   >::_M_insert_aux<std::_Deque_iterator<sidb::FlushInfo, sidb::FlushInfo const&, sidb::FlushInfo
   const*> >(std::_Deque_iterator<sidb::FlushInfo, sidb::FlushInfo&, sidb::FlushInfo*>,
   std::_Deque_iterator<sidb::FlushInfo, sidb::FlushInfo const&, sidb::FlushInfo const*>,
   std::_Deque_iterator<sidb::FlushInfo, sidb::FlushInfo const&, sidb::FlushInfo const*>, unsigned
   long) */

void __thiscall
std::deque<sidb::FlushInfo,std::allocator<sidb::FlushInfo>>::
_M_insert_aux<std::_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo_const&,sidb::FlushInfo_const*>>
          (deque<sidb::FlushInfo,std::allocator<sidb::FlushInfo>> *this,_Deque_iterator *param_2,
          undefined8 *param_3,undefined8 *param_4,long param_5)

{
  _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*> *this_00;
  _Deque_iterator *this_01;
  ulong uVar1;
  ulong uVar2;
  long lVar3;
  undefined8 local_1e0;
  undefined8 uStack_1d8;
  undefined8 local_1d0;
  undefined8 uStack_1c8;
  undefined8 local_1c0;
  undefined8 uStack_1b8;
  undefined8 local_1b0;
  undefined8 uStack_1a8;
  undefined8 local_1a0;
  undefined8 uStack_198;
  undefined8 local_190;
  undefined8 uStack_188;
  undefined8 local_180;
  undefined8 uStack_178;
  undefined8 local_170;
  undefined8 uStack_168;
  undefined8 local_160;
  undefined8 uStack_158;
  undefined8 local_150;
  undefined8 uStack_148;
  undefined8 local_140;
  undefined8 uStack_138;
  undefined8 local_130;
  undefined8 uStack_128;
  _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*> a_Stack_120 [32];
  undefined8 local_100;
  undefined8 uStack_f8;
  undefined8 local_f0;
  undefined8 uStack_e8;
  undefined8 local_e0;
  undefined8 uStack_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*> a_Stack_80 [32];
  _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*> a_Stack_60 [32];
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  undefined8 uStack_18;
  undefined8 local_10;
  undefined8 uStack_8;
  
  this_00 = (_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*> *)(this + 0x10);
  this_01 = (_Deque_iterator *)(this + 0x30);
  uVar1 = operator-(param_2,(_Deque_iterator *)this_00);
  uVar2 = operator-(this_01,(_Deque_iterator *)this_00);
  if (uVar1 < uVar2 >> 1) {
    _M_reserve_elements_at_front((ulong)this);
    _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*>::_Deque_iterator
              ((_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*> *)&local_160,
               (_Deque_iterator *)this_00);
    _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*>::operator+(this_00,uVar1);
    *(undefined8 *)param_2 = local_20;
    *(undefined8 *)(param_2 + 8) = uStack_18;
    *(undefined8 *)(param_2 + 0x10) = local_10;
    *(undefined8 *)(param_2 + 0x18) = uStack_8;
    if (param_5 <= (long)uVar1) {
      _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*>::operator+(this_00,param_5)
      ;
      _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*>::_Deque_iterator
                (a_Stack_80,(_Deque_iterator *)this_00);
      _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*>::_Deque_iterator
                (a_Stack_60,(_Deque_iterator *)&local_100);
      _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*>::_Deque_iterator
                ((_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*> *)&local_40,
                 (_Deque_iterator *)&local_180);
      FUN_003b49fc((_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo_const&,sidb::FlushInfo_const*> *
                   )&local_20,a_Stack_80,a_Stack_60,
                   (_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*> *)&local_40);
      *(undefined8 *)(this + 0x10) = local_180;
      *(undefined8 *)(this + 0x18) = uStack_178;
      *(undefined8 *)(this + 0x20) = local_170;
      *(undefined8 *)(this + 0x28) = uStack_168;
      _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*>::_Deque_iterator
                ((_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*> *)&local_e0,
                 (_Deque_iterator *)&local_100);
      _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*>::_Deque_iterator
                ((_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*> *)&local_c0,
                 param_2);
      _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*>::_Deque_iterator
                ((_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*> *)&local_a0,
                 (_Deque_iterator *)&local_160);
      _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo_const&,sidb::FlushInfo_const*>::
      _Deque_iterator((_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo_const&,sidb::FlushInfo_const*>
                       *)&local_20,(_Deque_iterator *)&local_e0);
      _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo_const&,sidb::FlushInfo_const*>::
      _Deque_iterator((_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo_const&,sidb::FlushInfo_const*>
                       *)&local_40,(_Deque_iterator *)&local_c0);
      _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*>::_Deque_iterator
                (a_Stack_60,(_Deque_iterator *)&local_a0);
      local_1c0 = local_20;
      uStack_1b8 = uStack_18;
      local_1b0 = local_10;
      uStack_1a8 = uStack_8;
      local_1e0 = local_40;
      uStack_1d8 = uStack_38;
      local_1d0 = local_30;
      uStack_1c8 = uStack_28;
      move<sidb::FlushInfo>(a_Stack_80,&local_1c0,&local_1e0,a_Stack_60);
      _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*>::operator-
                ((_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*> *)param_2,
                 param_5);
      goto LAB_003b4d50;
    }
    local_140 = *param_3;
    uStack_138 = param_3[1];
    local_130 = param_3[2];
    uStack_128 = param_3[3];
    _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo_const&,sidb::FlushInfo_const*>::operator+=
              ((_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo_const&,sidb::FlushInfo_const*> *)
               &local_140,param_5 - uVar1);
    _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*>::_Deque_iterator
              (a_Stack_120,(_Deque_iterator *)this_00);
    _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*>::_Deque_iterator
              ((_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*> *)&local_c0,
               param_2);
    _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*>::_Deque_iterator
              ((_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*> *)&local_a0,
               (_Deque_iterator *)&local_180);
    local_100 = *param_3;
    uStack_f8 = param_3[1];
    local_f0 = param_3[2];
    uStack_e8 = param_3[3];
    local_e0 = local_140;
    uStack_d8 = uStack_138;
    local_d0 = local_130;
    uStack_c8 = uStack_128;
    _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*>::_Deque_iterator
              (a_Stack_60,(_Deque_iterator *)a_Stack_120);
    _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*>::_Deque_iterator
              ((_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*> *)&local_40,
               (_Deque_iterator *)&local_c0);
    _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*>::_Deque_iterator
              ((_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*> *)&local_20,
               (_Deque_iterator *)&local_a0);
    FUN_003b49fc(a_Stack_80,a_Stack_60,
                 (_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*> *)&local_40,
                 (_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo_const&,sidb::FlushInfo_const*> *)
                 &local_20);
    _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*>::_Deque_iterator
              ((_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*> *)&local_20,
               (_Deque_iterator *)a_Stack_80);
    local_1c0 = local_100;
    uStack_1b8 = uStack_f8;
    local_1b0 = local_f0;
    uStack_1a8 = uStack_e8;
    local_1e0 = local_e0;
    uStack_1d8 = uStack_d8;
    local_1d0 = local_d0;
    uStack_1c8 = uStack_c8;
    FUN_003b45ac((_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*> *)&local_40,
                 &local_1c0,&local_1e0,
                 (_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo_const&,sidb::FlushInfo_const*> *)
                 &local_20);
    *(undefined8 *)(this + 0x10) = local_180;
    *(undefined8 *)(this + 0x18) = uStack_178;
    *(undefined8 *)(this + 0x20) = local_170;
    *(undefined8 *)(this + 0x28) = uStack_168;
    _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*>::_Deque_iterator
              ((_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*> *)&local_40,
               (_Deque_iterator *)&local_160);
    local_1c0 = local_140;
    uStack_1b8 = uStack_138;
    local_1b0 = local_130;
    uStack_1a8 = uStack_128;
  }
  else {
    _M_reserve_elements_at_back((ulong)this);
    _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*>::_Deque_iterator
              ((_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*> *)&local_180,
               this_01);
    lVar3 = uVar2 - uVar1;
    _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*>::operator-
              ((_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*> *)this_01,lVar3);
    *(undefined8 *)param_2 = local_20;
    *(undefined8 *)(param_2 + 8) = uStack_18;
    *(undefined8 *)(param_2 + 0x10) = local_10;
    *(undefined8 *)(param_2 + 0x18) = uStack_8;
    if (lVar3 <= param_5) {
      local_160 = *param_3;
      uStack_158 = param_3[1];
      local_150 = param_3[2];
      uStack_148 = param_3[3];
      _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo_const&,sidb::FlushInfo_const*>::operator+=
                ((_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo_const&,sidb::FlushInfo_const*> *)
                 &local_160,lVar3);
      _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*>::_Deque_iterator
                ((_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*> *)&local_140,
                 param_2);
      _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*>::_Deque_iterator
                (a_Stack_120,this_01);
      _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*>::_Deque_iterator
                ((_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*> *)&local_100,
                 this_01);
      local_c0 = local_160;
      uStack_b8 = uStack_158;
      local_b0 = local_150;
      uStack_a8 = uStack_148;
      local_a0 = *param_4;
      uStack_98 = param_4[1];
      local_90 = param_4[2];
      uStack_88 = param_4[3];
      _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*>::_Deque_iterator
                ((_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*> *)&local_20,
                 (_Deque_iterator *)&local_100);
      local_1c0 = local_c0;
      uStack_1b8 = uStack_b8;
      local_1b0 = local_b0;
      uStack_1a8 = uStack_a8;
      local_1e0 = local_a0;
      uStack_1d8 = uStack_98;
      local_1d0 = local_90;
      uStack_1c8 = uStack_88;
      FUN_003b45ac(a_Stack_80,&local_1c0,&local_1e0,
                   (_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo_const&,sidb::FlushInfo_const*> *
                   )&local_20);
      _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*>::_Deque_iterator
                (a_Stack_60,(_Deque_iterator *)&local_140);
      _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*>::_Deque_iterator
                ((_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*> *)&local_40,
                 (_Deque_iterator *)a_Stack_120);
      _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*>::_Deque_iterator
                ((_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*> *)&local_20,
                 (_Deque_iterator *)a_Stack_80);
      FUN_003b49fc((_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*> *)&local_e0,
                   a_Stack_60,
                   (_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*> *)&local_40,
                   (_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo_const&,sidb::FlushInfo_const*> *
                   )&local_20);
      *(undefined8 *)(this + 0x30) = local_1a0;
      *(undefined8 *)(this + 0x38) = uStack_198;
      *(undefined8 *)(this + 0x40) = local_190;
      *(undefined8 *)(this + 0x48) = uStack_188;
      _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*>::_Deque_iterator
                ((_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*> *)&local_40,
                 param_2);
      local_1c0 = *param_3;
      uStack_1b8 = param_3[1];
      local_1b0 = param_3[2];
      uStack_1a8 = param_3[3];
      local_1e0 = local_160;
      uStack_1d8 = uStack_158;
      local_1d0 = local_150;
      uStack_1c8 = uStack_148;
      goto LAB_003b4eb8;
    }
    _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*>::operator-
              ((_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*> *)this_01,param_5
              );
    _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*>::_Deque_iterator
              (a_Stack_80,(_Deque_iterator *)&local_100);
    _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*>::_Deque_iterator
              (a_Stack_60,this_01);
    _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*>::_Deque_iterator
              ((_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*> *)&local_40,
               this_01);
    FUN_003b49fc((_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo_const&,sidb::FlushInfo_const*> *)
                 &local_20,a_Stack_80,a_Stack_60,
                 (_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*> *)&local_40);
    *(undefined8 *)(this + 0x30) = local_1a0;
    *(undefined8 *)(this + 0x38) = uStack_198;
    *(undefined8 *)(this + 0x40) = local_190;
    *(undefined8 *)(this + 0x48) = uStack_188;
    _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*>::_Deque_iterator
              ((_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*> *)&local_e0,
               param_2);
    _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*>::_Deque_iterator
              ((_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*> *)&local_c0,
               (_Deque_iterator *)&local_100);
    _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*>::_Deque_iterator
              ((_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*> *)&local_a0,
               (_Deque_iterator *)&local_180);
    _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo_const&,sidb::FlushInfo_const*>::_Deque_iterator
              ((_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo_const&,sidb::FlushInfo_const*> *)
               &local_20,(_Deque_iterator *)&local_e0);
    _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo_const&,sidb::FlushInfo_const*>::_Deque_iterator
              ((_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo_const&,sidb::FlushInfo_const*> *)
               &local_40,(_Deque_iterator *)&local_c0);
    _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*>::_Deque_iterator
              (a_Stack_60,(_Deque_iterator *)&local_a0);
    local_1c0 = local_20;
    uStack_1b8 = uStack_18;
    local_1b0 = local_10;
    uStack_1a8 = uStack_8;
    local_1e0 = local_40;
    uStack_1d8 = uStack_38;
    local_1d0 = local_30;
    uStack_1c8 = uStack_28;
    move_backward<sidb::FlushInfo>(a_Stack_80,&local_1c0,&local_1e0,a_Stack_60);
    _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*>::_Deque_iterator
              ((_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*> *)&local_40,
               param_2);
LAB_003b4d50:
    local_1c0 = *param_3;
    uStack_1b8 = param_3[1];
    local_1b0 = param_3[2];
    uStack_1a8 = param_3[3];
  }
  local_1e0 = *param_4;
  uStack_1d8 = param_4[1];
  local_1d0 = param_4[2];
  uStack_1c8 = param_4[3];
LAB_003b4eb8:
  move<sidb::FlushInfo>
            ((_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo_const&,sidb::FlushInfo_const*> *)
             &local_20,&local_1c0,&local_1e0,
             (_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*> *)&local_40);
  return;
}

