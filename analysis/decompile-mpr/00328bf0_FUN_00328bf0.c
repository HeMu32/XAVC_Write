// FUN_00328bf0
// Ghidra address: 00328bf0

undefined8
FUN_00328bf0(long param_1,undefined8 param_2,byte param_3,uint *param_4,undefined4 *param_5,
            undefined4 *param_6,undefined8 param_7)

{
  undefined8 uVar1;
  
  if (*(int *)(param_1 + 0x90) != 1) {
    uVar1 = FUN_00328990(param_1,param_2,*(undefined4 *)(param_1 + (ulong)param_3 * 4 + 0x284),
                         param_1 + (ulong)param_3 * 4 + 0x2d8,param_4,param_5,param_6,param_7);
    return uVar1;
  }
  printf("[%s] Play [CODING_TYPE_ONLY_I]\n","GetAudioSampleInfo");
  *param_5 = 0;
  *param_6 = 0;
  *param_4 = *param_4 | 1;
  return 0;
}

