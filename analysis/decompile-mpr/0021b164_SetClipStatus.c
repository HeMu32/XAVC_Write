// XavcsMovieWriter::SetClipStatus
// Ghidra address: 0021b164

/* XavcsMovieWriter::SetClipStatus(sidb::ClipStatus) */

void __thiscall XavcsMovieWriter::SetClipStatus(XavcsMovieWriter *this,undefined4 param_2)

{
  undefined2 local_8;
  undefined2 local_6;
  undefined1 local_4;
  undefined1 local_3;
  undefined1 local_2;
  undefined1 local_1;
  
  local_6 = 0xa00;
  local_4 = 4;
  local_8 = 0x2310;
  local_3 = 0;
  local_2 = 0;
  local_1 = 0;
  FUN_0021777c(&local_8,8);
  mpr::thread::normalLock::lock((normalLock *)(this + 0x2c28));
  *(undefined4 *)(this + 0x2c24) = param_2;
  this[0x2c20] = (XavcsMovieWriter)0x1;
  mpr::thread::normalLock::unlock((normalLock *)(this + 0x2c28));
  local_4 = 4;
  local_8 = 0x2310;
  local_6 = 0xa0f;
  local_3 = 0;
  local_2 = 0;
  local_1 = 0;
  FUN_0021777c(&local_8,8);
  return;
}

