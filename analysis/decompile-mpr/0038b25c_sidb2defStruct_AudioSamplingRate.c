// sidb::sidb2defStruct_AudioSamplingRate
// Ghidra address: 0038b25c

/* sidb::sidb2defStruct_AudioSamplingRate(sidb::AudioSamplingRate) */

undefined4 __thiscall sidb::sidb2defStruct_AudioSamplingRate(int param_1)

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

