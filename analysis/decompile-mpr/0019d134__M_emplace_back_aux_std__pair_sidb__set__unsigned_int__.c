// std::vector<std::pair<sidb::set*,unsigned_int>,std::allocator<std::pair<sidb::set*,unsigned_int>>>::_M_emplace_back_aux<std::pair<sidb::set*,unsigned_int>>
// Ghidra address: 0019d134

/* void std::vector<std::pair<sidb::set*, unsigned int>, std::allocator<std::pair<sidb::set*,
   unsigned int> > >::_M_emplace_back_aux<std::pair<sidb::set*, unsigned int>
   >(std::pair<sidb::set*, unsigned int>&&) */

void __thiscall
std::vector<std::pair<sidb::set*,unsigned_int>,std::allocator<std::pair<sidb::set*,unsigned_int>>>::
_M_emplace_back_aux<std::pair<sidb::set*,unsigned_int>>
          (vector<std::pair<sidb::set*,unsigned_int>,std::allocator<std::pair<sidb::set*,unsigned_int>>>
           *this,pair *param_1)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  ulong uVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  long lVar8;
  undefined8 *puVar9;
  ulong uVar10;
  
  uVar5 = *(long *)(this + 8) - *(long *)this >> 4;
  uVar10 = uVar5;
  if (uVar5 == 0) {
    uVar10 = 1;
  }
  uVar10 = uVar5 + uVar10;
  if (uVar10 < 0x1000000000000000 && uVar5 <= uVar10) {
    puVar6 = (undefined8 *)0x0;
    if (uVar10 == 0) goto LAB_0019d188;
  }
  else {
    uVar10 = 0xfffffffffffffff;
  }
  puVar6 = operator_new(uVar10 << 4);
LAB_0019d188:
  puVar2 = *(undefined8 **)this;
  puVar3 = *(undefined8 **)(this + 8);
  lVar8 = (long)puVar3 - (long)puVar2;
  puVar1 = (undefined8 *)((long)puVar6 + lVar8);
  puVar7 = puVar6;
  puVar9 = puVar2;
  if (puVar1 != (undefined8 *)0x0) {
    uVar4 = *(undefined8 *)(param_1 + 8);
    *puVar1 = *(undefined8 *)param_1;
    puVar1[1] = uVar4;
  }
  for (; puVar3 != puVar9; puVar9 = puVar9 + 2) {
    if (puVar7 != (undefined8 *)0x0) {
      uVar4 = puVar9[1];
      *puVar7 = *puVar9;
      puVar7[1] = uVar4;
    }
    puVar7 = puVar7 + 2;
  }
  if (puVar2 != (undefined8 *)0x0) {
    operator_delete(puVar2);
  }
  *(undefined8 **)this = puVar6;
  *(long *)(this + 8) = (long)puVar6 + lVar8 + 0x10;
  *(undefined8 **)(this + 0x10) = puVar6 + uVar10 * 2;
  return;
}

