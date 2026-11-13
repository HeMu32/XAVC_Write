// mpr::NotifyMovieRecMediaPullOut
// Ghidra address: 001cb608

/* mpr::NotifyMovieRecMediaPullOut(unsigned int) */

undefined8 mpr::NotifyMovieRecMediaPullOut(uint param_1)

{
  undefined *puVar1;
  long lVar2;
  undefined8 uVar3;
  uint *puVar4;
  uint uVar5;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 local_c;
  undefined1 local_b;
  undefined1 local_a;
  undefined1 local_9;
  uint local_8;
  
  local_c = 3;
  local_10 = 0x2110;
  local_b = 0;
  local_e = 0x1160;
  local_a = 0;
  local_9 = 0;
  local_8 = param_1;
  FUN_001c9f24(&local_10,0xc);
  thread::normalLock::lock((normalLock *)PTR_s_integRecordMovieLock_00402670);
  puVar1 = PTR_s_movieRecInfo_00401670;
  puVar4 = (uint *)(PTR_s_movieRecInfo_00401670 + 0x230);
  for (uVar5 = 0; uVar5 < *(uint *)(puVar1 + 0x240); uVar5 = uVar5 + 1) {
    if ((param_1 == *puVar4) && (lVar2 = *(long *)(puVar1 + 0xa50), lVar2 != 0)) {
      uVar3 = FUN_001fdff4(lVar2,param_1,0);
      FUN_001fe0e8(uVar3,0xb);
    }
    puVar4 = puVar4 + 1;
  }
  thread::normalLock::unlock((normalLock *)PTR_s_integRecordMovieLock_00402670);
  local_b = 0;
  local_a = 0;
  local_c = 4;
  local_9 = 0;
  local_10 = 0x2110;
  local_e = 0x116f;
  FUN_001c9f24(&local_10,8);
  return 0;
}

