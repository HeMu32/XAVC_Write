// FUN_0032b470
// Ghidra address: 0032b470

int FUN_0032b470(void)

{
  _Rb_tree_node_base *p_Var1;
  int iVar2;
  
  iVar2 = 0;
  for (p_Var1 = DAT_004bcef0; p_Var1 != (_Rb_tree_node_base *)&DAT_004bcee0;
      p_Var1 = (_Rb_tree_node_base *)std::_Rb_tree_increment(p_Var1)) {
    iVar2 = iVar2 + *(int *)(p_Var1 + 0x28);
  }
  return iVar2;
}

