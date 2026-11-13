// FUN_0032b4b8
// Ghidra address: 0032b4b8

int FUN_0032b4b8(long *param_1)

{
  int iVar1;
  _Rb_tree_node_base *p_Var2;
  int iVar3;
  
  iVar3 = 0;
  for (p_Var2 = DAT_004bcef0; p_Var2 != (_Rb_tree_node_base *)&DAT_004bcee0;
      p_Var2 = (_Rb_tree_node_base *)std::_Rb_tree_increment(p_Var2)) {
    iVar1 = (**(code **)(*param_1 + 0x38))(param_1,*(undefined4 *)(p_Var2 + 0x20));
    iVar3 = iVar3 + iVar1 * *(int *)(p_Var2 + 0x28);
  }
  return iVar3;
}

