// std::vector<sidb::ContentTypeInternal,std::allocator<sidb::ContentTypeInternal>>::_M_emplace_back_aux<sidb::ContentTypeInternal_const&>
// Ghidra address: 003a8624

/* void std::vector<sidb::ContentTypeInternal, std::allocator<sidb::ContentTypeInternal>
   >::_M_emplace_back_aux<sidb::ContentTypeInternal const&>(sidb::ContentTypeInternal const&) */

void __thiscall
std::vector<sidb::ContentTypeInternal,std::allocator<sidb::ContentTypeInternal>>::
_M_emplace_back_aux<sidb::ContentTypeInternal_const&>
          (vector<sidb::ContentTypeInternal,std::allocator<sidb::ContentTypeInternal>> *this,
          ContentTypeInternal *param_1)

{
  void *__src;
  ulong uVar1;
  void *__dest;
  ulong uVar2;
  size_t __n;
  
  uVar1 = *(long *)(this + 8) - *(long *)this >> 2;
  uVar2 = uVar1;
  if (uVar1 == 0) {
    uVar2 = 1;
  }
  uVar2 = uVar1 + uVar2;
  if (uVar2 < uVar1 || 0x3fffffffffffffff < uVar2) {
    uVar2 = 0x3fffffffffffffff;
  }
  else {
    __dest = (void *)0x0;
    if (uVar2 == 0) goto LAB_003a867c;
  }
  __dest = operator_new(uVar2 << 2);
LAB_003a867c:
  __src = *(void **)this;
  __n = *(long *)(this + 8) - (long)__src;
  if ((long)__dest + __n != 0) {
    *(undefined4 *)((long)__dest + __n) = *(undefined4 *)param_1;
  }
  if ((long)__n >> 2 != 0) {
    memmove(__dest,__src,__n);
  }
  if (__src != (void *)0x0) {
    operator_delete(__src);
  }
  *(void **)this = __dest;
  *(size_t *)(this + 8) = (long)__dest + __n + 4;
  *(void **)(this + 0x10) = (void *)((long)__dest + uVar2 * 4);
  return;
}

