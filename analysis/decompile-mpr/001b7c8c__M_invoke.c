// std::_Function_handler<bool(sidb::DirNumberChangeCheckInfo),sidb::DirNumberChange>::_M_invoke
// Ghidra address: 001b7c8c

/* std::_Function_handler<bool (sidb::DirNumberChangeCheckInfo),
   sidb::DirNumberChange>::_M_invoke(std::_Any_data const&, sidb::DirNumberChangeCheckInfo&&) */

_Any_data std::_Function_handler<bool(sidb::DirNumberChangeCheckInfo),sidb::DirNumberChange>::
          _M_invoke(_Any_data *param_1,DirNumberChangeCheckInfo *param_2)

{
  _Any_data _Var1;
  short sVar2;
  _Any_data _Var3;
  
  _Var1 = *(_Any_data *)param_2;
  sVar2 = *(short *)(param_2 + 2);
  _Var3 = param_1[4];
  if (_Var3 == (_Any_data)0x0) {
    param_1[4] = (_Any_data)0x1;
    _Var3 = (_Any_data)0x1;
  }
  else if (*param_1 == _Var1) {
    _Var3 = (_Any_data)(*(short *)(param_1 + 2) != sVar2);
  }
  *param_1 = _Var1;
  *(short *)(param_1 + 2) = sVar2;
  return _Var3;
}

