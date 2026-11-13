// std::deque<sidb::FlushInfo,std::allocator<sidb::FlushInfo>>::operator=
// Ghidra address: 003b537c

/* std::deque<sidb::FlushInfo, std::allocator<sidb::FlushInfo>
   >::TEMPNAMEPLACEHOLDERVALUE(std::deque<sidb::FlushInfo, std::allocator<sidb::FlushInfo> > const&)
    */

deque<sidb::FlushInfo,std::allocator<sidb::FlushInfo>> * __thiscall
std::deque<sidb::FlushInfo,std::allocator<sidb::FlushInfo>>::operator=
          (deque<sidb::FlushInfo,std::allocator<sidb::FlushInfo>> *this,deque *param_1)

{
  _Deque_iterator *p_Var1;
  _Deque_iterator *p_Var2;
  _Deque_iterator *p_Var3;
  ulong uVar4;
  ulong uVar5;
  undefined8 *puVar6;
  long lVar7;
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
  long *plStack_128;
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
  long *local_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  long local_78;
  long local_70;
  long *plStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  undefined8 uStack_18;
  undefined8 local_10;
  undefined8 uStack_8;
  
  if (param_1 != (deque *)this) {
    p_Var1 = (_Deque_iterator *)(this + 0x10);
    p_Var2 = (_Deque_iterator *)(param_1 + 0x30);
    p_Var3 = (_Deque_iterator *)(param_1 + 0x10);
    uVar4 = operator-((_Deque_iterator *)(this + 0x30),p_Var1);
    uVar5 = operator-(p_Var2,p_Var3);
    if (uVar4 < uVar5) {
      _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo_const&,sidb::FlushInfo_const*>::
      _Deque_iterator((_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo_const&,sidb::FlushInfo_const*>
                       *)&local_40,p_Var3);
      local_20 = local_40;
      uStack_18 = uStack_38;
      local_10 = local_30;
      uStack_8 = uStack_28;
      puVar6 = (undefined8 *)
               _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo_const&,sidb::FlushInfo_const*>::
               operator+=((_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo_const&,sidb::FlushInfo_const*>
                           *)&local_20,uVar4);
      local_160 = *puVar6;
      uStack_158 = puVar6[1];
      local_150 = puVar6[2];
      uStack_148 = puVar6[3];
      _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo_const&,sidb::FlushInfo_const*>::
      _Deque_iterator((_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo_const&,sidb::FlushInfo_const*>
                       *)&local_120,p_Var3);
      _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*>::_Deque_iterator
                ((_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*> *)&local_40,
                 p_Var1);
      local_180 = local_120;
      uStack_178 = uStack_118;
      local_170 = local_110;
      uStack_168 = uStack_108;
      local_1a0 = local_160;
      uStack_198 = uStack_158;
      local_190 = local_150;
      uStack_188 = uStack_148;
      move<sidb::FlushInfo>
                ((_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo_const&,sidb::FlushInfo_const*> *)
                 &local_20,&local_180,&local_1a0,
                 (_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo_const&,sidb::FlushInfo_const*> *)
                 &local_40);
      _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo_const&,sidb::FlushInfo_const*>::
      _Deque_iterator((_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo_const&,sidb::FlushInfo_const*>
                       *)&local_140,(_Deque_iterator *)(this + 0x30));
      _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo_const&,sidb::FlushInfo_const*>::
      _Deque_iterator((_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo_const&,sidb::FlushInfo_const*>
                       *)&local_100,p_Var2);
      local_e0 = local_140;
      uStack_d8 = uStack_138;
      local_d0 = local_130;
      local_c8 = plStack_128;
      local_c0 = local_160;
      uStack_b8 = uStack_158;
      local_b0 = local_150;
      uStack_a8 = uStack_148;
      local_a0 = local_100;
      uStack_98 = uStack_f8;
      local_90 = local_f0;
      uStack_88 = uStack_e8;
      _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo_const&,sidb::FlushInfo_const*>::
      _Deque_iterator((_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo_const&,sidb::FlushInfo_const*>
                       *)&local_20,p_Var1);
      lVar7 = operator-((_Deque_iterator *)&local_e0,(_Deque_iterator *)&local_20);
      local_80 = local_e0;
      local_78 = *local_c8;
      local_70 = *local_c8 + 0x200;
      plStack_68 = local_c8;
      local_60 = local_c0;
      uStack_58 = uStack_b8;
      local_50 = local_b0;
      uStack_48 = uStack_a8;
      local_40 = local_a0;
      uStack_38 = uStack_98;
      local_30 = local_90;
      uStack_28 = uStack_88;
      _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*>::_Deque_iterator
                ((_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*> *)&local_20,
                 (_Deque_iterator *)&local_80);
      local_180 = local_60;
      uStack_178 = uStack_58;
      local_170 = local_50;
      uStack_168 = uStack_48;
      local_1a0 = local_40;
      uStack_198 = uStack_38;
      local_190 = local_30;
      uStack_188 = uStack_28;
      _M_range_insert_aux<std::_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo_const&,sidb::FlushInfo_const*>>
                (this,(_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo_const&,sidb::FlushInfo_const*>
                       *)&local_20,&local_180,&local_1a0,0);
      _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*>::_Deque_iterator
                ((_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*> *)&local_20,
                 p_Var1);
      _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*>::operator+
                ((_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*> *)&local_20,
                 lVar7);
    }
    else {
      _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo_const&,sidb::FlushInfo_const*>::
      _Deque_iterator((_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo_const&,sidb::FlushInfo_const*>
                       *)&local_80,p_Var3);
      _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo_const&,sidb::FlushInfo_const*>::
      _Deque_iterator((_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo_const&,sidb::FlushInfo_const*>
                       *)&local_20,p_Var2);
      _Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*>::_Deque_iterator
                ((_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*> *)&local_60,
                 p_Var1);
      local_180 = local_80;
      uStack_178 = local_78;
      local_170 = local_70;
      uStack_168 = plStack_68;
      local_1a0 = local_20;
      uStack_198 = uStack_18;
      local_190 = local_10;
      uStack_188 = uStack_8;
      move<sidb::FlushInfo>
                ((_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo_const&,sidb::FlushInfo_const*> *)
                 &local_40,&local_180,&local_1a0,
                 (_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*> *)&local_60);
      _M_erase_at_end(this,(_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo_const&,sidb::FlushInfo_const*>
                            *)&local_40);
    }
  }
  return this;
}

