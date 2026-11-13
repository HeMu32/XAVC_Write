// std::deque<sidb::FlushInfo,std::allocator<sidb::FlushInfo>>::_M_reallocate_map
// Ghidra address: 003a8d60

/* std::deque<sidb::FlushInfo, std::allocator<sidb::FlushInfo> >::_M_reallocate_map(unsigned long,
   bool) */

void __thiscall
std::deque<sidb::FlushInfo,std::allocator<sidb::FlushInfo>>::_M_reallocate_map
          (deque<sidb::FlushInfo,std::allocator<sidb::FlushInfo>> *this,ulong param_1,bool param_2)

{
  ulong uVar1;
  ulong uVar2;
  long *__dest;
  long lVar3;
  void *pvVar4;
  long *__src;
  size_t sVar5;
  long *__dest_00;
  long lVar6;
  long lVar7;
  
  __src = *(long **)(this + 0x28);
  uVar2 = *(ulong *)(this + 8);
  lVar6 = *(long *)(this + 0x48) - (long)__src >> 3;
  lVar3 = lVar6 + 1 + param_1;
  if ((ulong)(lVar3 * 2) < uVar2) {
    lVar7 = param_1 << 3;
    if (!param_2) {
      lVar7 = 0;
    }
    sVar5 = (*(long *)(this + 0x48) + 8) - (long)__src;
    __dest_00 = (long *)(*(long *)this + lVar7 + (uVar2 - lVar3 >> 1) * 8);
    if (__dest_00 < __src) {
      __dest = __dest_00;
      if ((long)sVar5 >> 3 == 0) goto LAB_003a8dec;
    }
    else {
      if ((long)sVar5 >> 3 == 0) goto LAB_003a8dec;
      __dest = (long *)((long)__dest_00 + ((lVar6 + 1) * 8 - sVar5));
    }
    memmove(__dest,__src,sVar5);
  }
  else {
    uVar1 = uVar2;
    if (uVar2 < param_1) {
      uVar1 = param_1;
    }
    uVar1 = uVar1 + uVar2 + 2;
    if (0x1fffffffffffffff < uVar1) {
      std::__throw_bad_alloc();
    }
    lVar7 = param_1 << 3;
    pvVar4 = operator_new(uVar1 * 8);
    if (!param_2) {
      lVar7 = 0;
    }
    sVar5 = (*(long *)(this + 0x48) + 8) - (long)*(void **)(this + 0x28);
    __dest_00 = (long *)((long)pvVar4 + lVar7 + (uVar1 - lVar3 >> 1) * 8);
    if ((long)sVar5 >> 3 != 0) {
      memmove(__dest_00,*(void **)(this + 0x28),sVar5);
    }
    operator_delete(*(void **)this);
    *(void **)this = pvVar4;
    *(ulong *)(this + 8) = uVar1;
  }
LAB_003a8dec:
  lVar3 = *__dest_00;
  *(long *)(this + 0x18) = lVar3;
  *(long *)(this + 0x20) = lVar3 + 0x200;
  *(long **)(this + 0x48) = __dest_00 + lVar6;
  lVar3 = __dest_00[lVar6];
  *(long *)(this + 0x38) = lVar3;
  *(long **)(this + 0x28) = __dest_00;
  *(long *)(this + 0x40) = lVar3 + 0x200;
  return;
}

