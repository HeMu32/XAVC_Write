// mpr::Codec::DecOpen
// Ghidra address: 00385b14

/* WARNING: Restarted to delay deadcode elimination for space: ram */
/* mpr::Codec::DecOpen(AvbbcApi_DecOpen*, mpr::Codec::CodecType, mpr::Codec::FileFormat, unsigned
   int, PayloadCodec*) */

int mpr::Codec::DecOpen(ulong *param_1,undefined4 param_2,undefined4 param_3,uint param_4,
                       PayloadCodec *param_5)

{
  ulong uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  char cVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  int iVar7;
  undefined2 local_40;
  undefined2 local_3e;
  undefined1 local_3c;
  undefined1 local_3b;
  undefined1 local_3a;
  undefined1 local_39;
  uint local_38;
  undefined2 local_30;
  undefined2 local_2e;
  undefined1 local_2c;
  undefined1 local_2b;
  undefined1 local_2a;
  undefined1 local_29;
  int local_28;
  void *local_8;
  
  local_2e = 0x1010;
  local_2c = 4;
  local_2b = 0;
  local_2a = 0;
  local_29 = 0;
  local_30 = 0x22a0;
  FUN_00380f88((PayloadMpr *)&local_30,8);
  if (*(long *)PTR_sp_callbackForPlayMovie_004021c0 == 0) {
    iVar7 = 2;
    local_2c = 4;
    local_2e = 0x1011;
    local_2b = 0;
    local_2a = 0;
    local_29 = 0;
    local_30 = 0x22a0;
    FUN_00380f88((PayloadMpr *)&local_30,8);
  }
  else {
    thread::normalLock::lock((normalLock *)PTR_s_apiLock_00401350);
    DAT_004bdc48 = param_1[8];
    DAT_004bdc50 = (uint)(ushort)param_1[9];
    DAT_004bdc58 = ChangeVirtToPhysAddr(param_1 + 8);
    DAT_004bdc30 = param_1[10];
    DAT_004bdc38 = (uint)(ushort)param_1[0xb];
    DAT_004bdc40 = ChangeVirtToPhysAddr(param_1 + 10);
    DAT_004bdba8 = param_1[0xf];
    DAT_004bdbb0 = (uint)(ushort)param_1[0x10];
    DAT_004bdbb8 = ChangeVirtToPhysAddr(param_1 + 0xf);
    DAT_004bdb40 = param_1[4];
    DAT_004bdb48 = (uint)(ushort)param_1[5];
    DAT_004bdb50 = ChangeVirtToPhysAddr(param_1 + 4);
    DAT_004bdb28 = param_1[6];
    DAT_004bdb30 = (uint)(ushort)param_1[7];
    DAT_004bdb38 = ChangeVirtToPhysAddr(param_1 + 6);
    DAT_004bd8e0 = *param_1;
    DAT_004bd8e8 = (ulong)(uint)param_1[1];
    DAT_004bd8f0 = ChangeVirtToPhysAddr(param_1);
    DAT_004bd8c8 = param_1[2];
    DAT_004bd8d0 = (ulong)(uint)param_1[3];
    DAT_004bd8d8 = ChangeVirtToPhysAddr(param_1 + 2);
    DAT_004bd8f8 = (undefined4 *)param_1[0xc];
    DAT_004bd900 = 0x20;
    DAT_004bd908 = ChangeVirtToPhysAddr(param_1 + 0xc);
    DAT_004bdac8 = (undefined4 *)param_1[0xd];
    DAT_004bdad0 = 0x2e0;
    DAT_004bdad8 = ChangeVirtToPhysAddr(param_1 + 0xd);
    puVar3 = DAT_004bdac8;
    puVar2 = DAT_004bd8f8;
    uVar1 = DAT_004bd8e0;
    DAT_004bdb08 = DAT_004bdc48;
    DAT_004bdb00 = DAT_004bdc30;
    DAT_004bdab8 = DAT_004bdba8;
    DAT_004bda58 = DAT_004bdb40;
    DAT_004bda50 = DAT_004bdb28;
    DAT_004bd9d8 = DAT_004bdac8 + 3;
    DAT_004bd9b8 = DAT_004bdac8 + 4;
    DAT_004bd948 = DAT_004bdac8 + 0xb6;
    DAT_004bd8b0 = DAT_004bdac8 + 1;
    DAT_004bd890 = DAT_004bdac8 + 2;
    DAT_004bd9e8 = DAT_004bd8f8 + 2;
    DAT_004bd9c8 = DAT_004bd8f8 + 3;
    DAT_004bd958 = DAT_004bd8f8 + 4;
    DAT_004bd8a0 = DAT_004bd8f8 + 1;
    DAT_004bd8c0 = DAT_004bd8f8;
    DAT_004bdd58 = DAT_004bd8e0;
    DAT_004bdd50 = DAT_004bd8c8;
    DAT_004bdb90 = DAT_004bdac8 + 0xa8;
    DAT_004bdc28 = DAT_004bdac8 + 0xa9;
    DataSynchronizationBarrier(3,3,0);
    DAT_004bdac8[3] = 0;
    DataSynchronizationBarrier(3,3,0);
    puVar3[4] = 0;
    DataSynchronizationBarrier(3,3,0);
    puVar3[0xb6] = 0;
    DataSynchronizationBarrier(3,3,0);
    puVar3[1] = 0;
    DataSynchronizationBarrier(3,3,0);
    puVar3[2] = -(uint)(DAT_004bd8d0 == 0);
    DataSynchronizationBarrier(3,3,0);
    puVar2[2] = 0;
    DataSynchronizationBarrier(3,3,0);
    puVar2[3] = 0;
    DataSynchronizationBarrier(3,3,0);
    puVar2[4] = 0;
    DataSynchronizationBarrier(3,3,0);
    *puVar2 = 0;
    DataSynchronizationBarrier(3,3,0);
    puVar2[1] = 0;
    *puVar3 = 0;
    DAT_004bd858 = CalcAddress(uVar1 - 1,(BufferAreaInfo *)&DAT_004bd8e0);
    uVar6 = 0;
    if (DAT_004bd8d0 != 0) {
      uVar6 = CalcAddress(DAT_004bd8c8 - 1,(BufferAreaInfo *)&DAT_004bd8c8);
    }
    DAT_004bd850 = DAT_004bd858;
    DAT_004bdafc = 0;
    DAT_004bdaf8 = 0;
    DataSynchronizationBarrier(3,3,0);
    DAT_004bd840 = uVar6;
    DAT_004bd848 = uVar6;
    *DAT_004bdb90 = 0;
    DataSynchronizationBarrier(3,3,0);
    *DAT_004bdc28 = 0;
    uVar5 = 0x1620;
    if (param_4 < 2) {
      uVar5 = 0x220;
    }
    CreateMessage(uVar5,0,param_2,param_3,param_4 * 0x90,(PayloadMpr *)&local_30,0,0,0);
    memcpy(local_8,param_1,(ulong)param_4 * 0x90);
    local_3b = 0;
    local_3a = 0;
    local_3c = 3;
    local_39 = 0;
    local_40 = 0x22a0;
    local_3e = 0x1012;
    local_38 = (uint)(byte)param_1[0xe];
    FUN_00380f88(&local_40,0xc);
    cVar4 = SendMsgToAvbbc((PayloadMpr *)&local_30,param_5);
    iVar7 = (uint)(cVar4 == '\0') << 1;
    thread::normalLock::unlock((normalLock *)PTR_s_apiLock_00401350);
  }
  local_2c = 3;
  local_2b = 0;
  local_30 = 0x22a0;
  local_2a = 0;
  local_2e = 0x101f;
  local_29 = 0;
  local_28 = iVar7;
  FUN_00380f88((PayloadMpr *)&local_30,0xc);
  return iVar7;
}

