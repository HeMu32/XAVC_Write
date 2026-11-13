// FUN_0038e6f0
// Ghidra address: 0038e6f0

void FUN_0038e6f0(undefined8 param_1,LocalTime *param_2,undefined8 param_3,undefined8 param_4,
                 uchar *param_5,uchar *param_6,uchar param_7)

{
  int iVar1;
  
  iVar1 = sidb::RestorateArrayBinaryRecord(param_1,2,param_3,param_4,param_6,0x20);
  if (iVar1 == 0) {
    sidb::RestorateUMID(param_6,param_2,param_5,param_7);
    return;
  }
  return;
}

