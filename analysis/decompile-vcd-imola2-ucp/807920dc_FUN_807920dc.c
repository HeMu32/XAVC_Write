// FUN_807920dc
// Ghidra address: 807920dc

uint FUN_807920dc(int param_1,uint *param_2,undefined4 *param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  char local_40 [4];
  uint local_3c;
  uint local_38 [2];
  
  FUN_8078e980();
  uVar4 = 0;
  FUN_807992fc();
  FUN_807992ec();
  local_40[0] = '\0';
  do {
    FUN_80794380(&local_3c);
    local_38[0] = local_3c;
    *param_2 = local_3c >> 8;
    uVar1 = FUN_8078f298(local_3c & 0xff);
    uVar2 = 0x40000000;
    if (uVar1 < 0x20) {
      uVar2 = 1 << (uVar1 & 0x1f);
    }
    uVar4 = uVar4 | uVar2;
    FUN_80792cf4(local_40,local_38);
    uVar2 = FUN_807985d0(*(undefined4 *)(param_1 + 4),0);
    *param_4 = *param_4 | uVar2;
  } while (local_40[0] == '\0');
  FUN_807991f4();
  uVar3 = FUN_8078e974();
  *param_3 = uVar3;
  FUN_8078e980();
  FUN_80787a24(*param_2,uVar4,*param_3);
  return uVar4;
}

