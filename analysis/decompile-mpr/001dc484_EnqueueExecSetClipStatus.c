// mpr::EnqueueExecSetClipStatus
// Ghidra address: 001dc484

/* mpr::EnqueueExecSetClipStatus(mpr::MovieRecInfo&, mpr::RecSequenceInfo&, sidb::ClipStatus) */

void mpr::EnqueueExecSetClipStatus(long param_1,void *param_2,undefined4 param_3)

{
  undefined2 local_8ec8;
  undefined2 local_8ec6;
  undefined1 local_8ec4;
  undefined1 local_8ec3;
  undefined1 local_8ec2;
  undefined1 local_8ec1;
  undefined2 local_8ec0;
  undefined2 local_8ebe;
  undefined1 local_8ebc;
  undefined1 local_8ebb;
  undefined1 local_8eba;
  undefined1 local_8eb9;
  undefined4 local_8eb8 [8550];
  undefined4 local_920;
  undefined *local_8;
  
  local_8ebc = 3;
  local_8ebe = 0x1a00;
  local_8ec0 = 0x2110;
  local_8ebb = 0;
  local_8eba = 0;
  local_8eb9 = 0;
  local_8eb8[0] = param_3;
  FUN_001c9f24((exec_t *)&local_8ec0,0xc);
  local_8 = PTR_ExecSetClipStatus_004029a0;
  local_8ec0 = CONCAT11(local_8ec0._1_1_,*(undefined1 *)(param_1 + 0x1fe));
  memcpy(local_8eb8,param_2,0x8598);
  local_920 = param_3;
  execqueue<mpr::execRecMovie>::exec
            (*(execqueue<mpr::execRecMovie> **)PTR_sp_execRecMovie_00402340,(exec_t *)&local_8ec0);
  local_8ec8 = 0x2110;
  local_8ec3 = 0;
  local_8ec4 = 4;
  local_8ec2 = 0;
  local_8ec6 = 0x1a0f;
  local_8ec1 = 0;
  FUN_001c9f24(&local_8ec8,8);
  return;
}

