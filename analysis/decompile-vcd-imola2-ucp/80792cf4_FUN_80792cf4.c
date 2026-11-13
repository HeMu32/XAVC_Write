// FUN_80792cf4
// Ghidra address: 80792cf4

void FUN_80792cf4(undefined1 *param_1,undefined1 *param_2)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = FUN_8078f298(*param_2);
  uVar2 = FUN_8078f264(*param_2,uVar1);
  if (0x1f < uVar1) goto switchD_80792d4c_caseD_0;
  switch(uVar1) {
  default:
    goto switchD_80792d4c_caseD_0;
  case 1:
  case 5:
    FUN_80791484(uVar1,uVar2,1,1,1);
    *param_1 = 1;
    goto switchD_80792d4c_caseD_0;
  case 6:
    FUN_80799028();
    break;
  case 7:
    FUN_80792e90();
    break;
  case 8:
    FUN_80793420();
    break;
  case 9:
    FUN_80792dd4(&switchD_80792d4c::switchdataD_807afde0 + uVar1,uVar2);
    break;
  case 0x1f:
    *param_1 = 1;
switchD_80792d4c_caseD_0:
  }
  return;
}

