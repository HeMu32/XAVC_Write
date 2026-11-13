// FUN_003466d4
// Ghidra address: 003466d4

string * FUN_003466d4(string *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  long lVar3;
  
  *(string **)param_1 = param_1 + 0x10;
  *(undefined8 *)(param_1 + 8) = 0;
  param_1[0x10] = (string)0x0;
  piVar2 = DAT_004bd448;
  for (lVar3 = ((long)DAT_004bd450 - (long)DAT_004bd448 >> 3) * -0x3333333333333333 >> 2; 0 < lVar3;
      lVar3 = lVar3 + -1) {
    iVar1 = *param_2;
    if (*piVar2 == iVar1) goto LAB_00346744;
    if (iVar1 == piVar2[10]) {
      piVar2 = piVar2 + 10;
      goto LAB_00346744;
    }
    if (iVar1 == piVar2[0x14]) {
      piVar2 = piVar2 + 0x14;
      goto LAB_00346744;
    }
    if (iVar1 == piVar2[0x1e]) {
      piVar2 = piVar2 + 0x1e;
      goto LAB_00346744;
    }
    piVar2 = piVar2 + 0x28;
  }
  lVar3 = ((long)DAT_004bd450 - (long)piVar2 >> 3) * -0x3333333333333333;
  if (lVar3 == 2) {
LAB_003467f0:
    if (*piVar2 == *param_2) goto LAB_00346744;
    piVar2 = piVar2 + 10;
  }
  else {
    if (lVar3 == 3) {
      if (*piVar2 == *param_2) goto LAB_00346744;
      piVar2 = piVar2 + 10;
      goto LAB_003467f0;
    }
    if (lVar3 != 1) {
      return param_1;
    }
  }
  if (*piVar2 != *param_2) {
    return param_1;
  }
LAB_00346744:
  if (piVar2 != DAT_004bd450) {
    std::__cxx11::string::append(param_1);
  }
  return param_1;
}

