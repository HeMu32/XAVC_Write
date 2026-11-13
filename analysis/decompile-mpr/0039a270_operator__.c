// std::_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo_const&,sidb::FlushInfo_const*>::operator+=
// Ghidra address: 0039a270

/* std::_Deque_iterator<sidb::FlushInfo, sidb::FlushInfo const&, sidb::FlushInfo
   const*>::TEMPNAMEPLACEHOLDERVALUE(long) */

void __thiscall
std::_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo_const&,sidb::FlushInfo_const*>::operator+=
          (_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo_const&,sidb::FlushInfo_const*> *this,
          long param_1)

{
  ulong uVar1;
  ulong uVar2;
  long lVar3;
  
  uVar1 = param_1 + (*(long *)this - *(long *)(this + 8) >> 4);
  if (0x1f < uVar1) {
    uVar2 = (long)uVar1 >> 5;
    if ((long)uVar1 < 1) {
      uVar2 = ~(~uVar1 >> 5);
    }
    lVar3 = *(long *)(*(long *)(this + 0x18) + uVar2 * 8);
    *(long *)(this + 0x10) = lVar3 + 0x200;
    *(ulong *)(this + 0x18) = *(long *)(this + 0x18) + uVar2 * 8;
    *(ulong *)this = lVar3 + (uVar1 + uVar2 * -0x20) * 0x10;
    *(long *)(this + 8) = lVar3;
    return;
  }
  *(long *)this = *(long *)this + param_1 * 0x10;
  return;
}

