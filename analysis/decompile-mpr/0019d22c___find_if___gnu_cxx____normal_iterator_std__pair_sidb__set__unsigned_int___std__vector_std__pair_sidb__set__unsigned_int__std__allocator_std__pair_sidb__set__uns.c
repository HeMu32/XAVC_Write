// std::__find_if<__gnu_cxx::__normal_iterator<std::pair<sidb::set*,unsigned_int>*,std::vector<std::pair<sidb::set*,unsigned_int>,std::allocator<std::pair<sidb::set*,unsigned_int>>>>,__gnu_cxx::__ops::_Iter_equals_val<std::pair<sidb::set*,unsigned_int>const>>
// Ghidra address: 0019d22c

/* __gnu_cxx::__normal_iterator<std::pair<sidb::set*, unsigned int>*,
   std::vector<std::pair<sidb::set*, unsigned int>, std::allocator<std::pair<sidb::set*, unsigned
   int> > > > std::__find_if<__gnu_cxx::__normal_iterator<std::pair<sidb::set*, unsigned int>*,
   std::vector<std::pair<sidb::set*, unsigned int>, std::allocator<std::pair<sidb::set*, unsigned
   int> > > >, __gnu_cxx::__ops::_Iter_equals_val<std::pair<sidb::set*, unsigned int> const>
   >(__gnu_cxx::__normal_iterator<std::pair<sidb::set*, unsigned int>*,
   std::vector<std::pair<sidb::set*, unsigned int>, std::allocator<std::pair<sidb::set*, unsigned
   int> > > >, __gnu_cxx::__normal_iterator<std::pair<sidb::set*, unsigned int>*,
   std::vector<std::pair<sidb::set*, unsigned int>, std::allocator<std::pair<sidb::set*, unsigned
   int> > > >, __gnu_cxx::__ops::_Iter_equals_val<std::pair<sidb::set*, unsigned int> const>,
   std::random_access_iterator_tag) */

pair * std::
       __find_if<__gnu_cxx::__normal_iterator<std::pair<sidb::set*,unsigned_int>*,std::vector<std::pair<sidb::set*,unsigned_int>,std::allocator<std::pair<sidb::set*,unsigned_int>>>>,__gnu_cxx::__ops::_Iter_equals_val<std::pair<sidb::set*,unsigned_int>const>>
                 (pair *param_1,pair *param_2,pair *param_3)

{
  bool bVar1;
  pair *ppVar2;
  long lVar3;
  
  for (lVar3 = (long)param_2 - (long)param_1 >> 6; 0 < lVar3; lVar3 = lVar3 + -1) {
    bVar1 = operator==(param_1,param_3);
    if (bVar1) {
      return param_1;
    }
    bVar1 = operator==(param_1 + 0x10,param_3);
    if (bVar1) {
      return param_1 + 0x10;
    }
    bVar1 = operator==(param_1 + 0x20,param_3);
    if (bVar1) {
      return param_1 + 0x20;
    }
    ppVar2 = param_1 + 0x30;
    param_1 = param_1 + 0x40;
    bVar1 = operator==(ppVar2,param_3);
    if (bVar1) {
      return ppVar2;
    }
  }
  lVar3 = (long)param_2 - (long)param_1 >> 4;
  ppVar2 = param_1;
  if (lVar3 != 2) {
    if (lVar3 != 3) {
      if (lVar3 != 1) {
        return param_2;
      }
      goto LAB_0019d2e8;
    }
    ppVar2 = param_1 + 0x10;
    bVar1 = operator==(param_1,param_3);
    if (bVar1) {
      return param_1;
    }
  }
  bVar1 = operator==(ppVar2,param_3);
  if (bVar1) {
    return ppVar2;
  }
  param_1 = ppVar2 + 0x10;
LAB_0019d2e8:
  bVar1 = operator==(param_1,param_3);
  if (!bVar1) {
    return param_2;
  }
  return param_1;
}

