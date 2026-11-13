// sidb::sidb2defStruct_AudioCodec
// Ghidra address: 0038b21c

/* sidb::sidb2defStruct_AudioCodec(sidb::AudioCodec) */

undefined4 __thiscall sidb::sidb2defStruct_AudioCodec(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 != 2) {
    uVar1 = 0xff;
    if (param_1 == 3) {
      uVar1 = 1;
    }
    return uVar1;
  }
  return 0;
}

