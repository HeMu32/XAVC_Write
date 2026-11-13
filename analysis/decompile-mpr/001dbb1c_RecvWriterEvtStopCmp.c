// mpr::RecvWriterEvtStopCmp
// Ghidra address: 001dbb1c

/* mpr::RecvWriterEvtStopCmp(unsigned long, unsigned int, int, void*, unsigned int, void*) */

void mpr::RecvWriterEvtStopCmp
               (ulong param_1,uint param_2,int param_3,void *param_4,uint param_5,void *param_6)

{
  undefined8 uVar1;
  undefined4 uVar2;
  int iVar3;
  RecMngInfo *pRVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  ThnmbnailControl *local_20;
  undefined2 local_18;
  undefined2 local_16;
  undefined1 local_14;
  undefined1 local_13;
  undefined1 local_12;
  undefined1 local_11;
  uint local_10;
  uint uStack_c;
  int local_8;
  undefined4 uStack_4;
  
  local_16 = 0x730;
  local_10 = (uint)param_1;
  local_14 = 1;
  local_13 = 0;
  local_12 = 0;
  local_11 = 0;
  uStack_4 = 0;
  local_18 = 0x2110;
  uStack_c = param_2;
  local_8 = param_3;
  FUN_001c9f24(&local_18,0x18,param_3,param_4,param_5);
  pRVar4 = (RecMngInfo *)
           SearchRecMngInfoList
                     ((RecMngInfo *)(PTR_s_recSequenceInfo_004019c0 + 8),
                      *(uint *)((long)param_4 + 0x18));
  if (pRVar4 == (RecMngInfo *)0x0) {
    uVar6 = 0xc;
    local_14 = 3;
    local_16 = 0x731;
    local_10 = *(uint *)((long)param_4 + 0x18);
LAB_001dbbc8:
    local_11 = 0;
    local_12 = 0;
    local_13 = 0;
    local_18 = 0x2110;
    FUN_001c9f24(&local_18,uVar6);
    uVar6 = FUN_001fdff4(*(undefined8 *)(PTR_s_movieRecInfo_00401670 + 0xa50),
                         *(undefined4 *)((long)param_4 + 0x18),0);
    iVar3 = 2;
LAB_001dbbe8:
    FUN_001fe0e8(uVar6,iVar3);
  }
  else {
    *(undefined4 *)(PTR_s_movieRecInfo_00401670 + 0x288) = *(undefined4 *)param_4;
    if (param_1 == *(uint *)(pRVar4 + 8)) {
      uVar2 = *(undefined4 *)((long)param_4 + 0x48);
      pRVar4[0x1c] = (RecMngInfo)0x1;
      uVar6 = *(undefined8 *)((long)param_4 + 0x2c);
      uVar1 = *(undefined8 *)((long)param_4 + 0x34);
      uVar7 = *(undefined8 *)((long)param_4 + 0x3c);
      *(undefined4 *)(pRVar4 + 0x28) = uVar2;
      uVar5 = *(undefined8 *)((long)param_4 + 0x10);
      *(int *)(pRVar4 + 0x18) = param_3;
      *(undefined8 *)(pRVar4 + 0x30) = uVar5;
      *(undefined8 *)(pRVar4 + 0x38) = *(undefined8 *)((long)param_4 + 8);
      *(undefined4 *)(pRVar4 + 0x40) = *(undefined4 *)((long)param_4 + 0x20);
      *(undefined4 *)(pRVar4 + 0x44) = *(undefined4 *)((long)param_4 + 0x24);
      *(undefined4 *)(pRVar4 + 0x48) = *(undefined4 *)((long)param_4 + 0x28);
      *(undefined8 *)(pRVar4 + 0x4c) = uVar6;
      *(undefined8 *)(pRVar4 + 0x54) = uVar1;
      uVar2 = *(undefined4 *)((long)param_4 + 0x44);
      *(undefined8 *)(pRVar4 + 0x5c) = uVar7;
      *(undefined4 *)(pRVar4 + 100) = uVar2;
      *(undefined8 *)(pRVar4 + 0x68) = *(undefined8 *)((long)param_4 + 0x4c);
      *(undefined4 *)(pRVar4 + 0x70) = *(undefined4 *)((long)param_4 + 0x54);
      *(undefined8 *)(pRVar4 + 0x74) = *(undefined8 *)((long)param_4 + 0x58);
      *(undefined4 *)(pRVar4 + 0x7c) = *(undefined4 *)((long)param_4 + 0x60);
      strncpy((char *)(pRVar4 + 0x80),(char *)((long)param_4 + 100),0x7f);
      *(undefined8 *)(pRVar4 + 0x100) = *(undefined8 *)((long)param_4 + 0xe4);
      *(undefined2 *)(pRVar4 + 0x108) = *(undefined2 *)((long)param_4 + 0xec);
      *(undefined8 *)(pRVar4 + 0x10c) = *(undefined8 *)((long)param_4 + 0xf0);
    }
    else {
      if (((byte)pRVar4[0x140] == 0) || (param_1 != *(uint *)(pRVar4 + 0x148))) {
        uVar6 = 0x10;
        local_14 = 2;
        local_16 = 0x732;
        local_10 = *(uint *)(pRVar4 + 8);
        uStack_c = (uint)(byte)pRVar4[0x140];
        goto LAB_001dbbc8;
      }
      uVar2 = *(undefined4 *)((long)param_4 + 0x48);
      pRVar4[0x15c] = (RecMngInfo)0x1;
      uVar6 = *(undefined8 *)((long)param_4 + 0x2c);
      uVar1 = *(undefined8 *)((long)param_4 + 0x34);
      uVar7 = *(undefined8 *)((long)param_4 + 0x3c);
      *(undefined4 *)(pRVar4 + 0x168) = uVar2;
      uVar5 = *(undefined8 *)((long)param_4 + 0x10);
      *(int *)(pRVar4 + 0x158) = param_3;
      *(undefined8 *)(pRVar4 + 0x170) = uVar5;
      *(undefined8 *)(pRVar4 + 0x178) = *(undefined8 *)((long)param_4 + 8);
      *(undefined4 *)(pRVar4 + 0x180) = *(undefined4 *)((long)param_4 + 0x20);
      *(undefined4 *)(pRVar4 + 0x184) = *(undefined4 *)((long)param_4 + 0x24);
      *(undefined4 *)(pRVar4 + 0x188) = *(undefined4 *)((long)param_4 + 0x28);
      *(undefined8 *)(pRVar4 + 0x18c) = uVar6;
      *(undefined8 *)(pRVar4 + 0x194) = uVar1;
      *(undefined8 *)(pRVar4 + 0x19c) = uVar7;
      uVar6 = *(undefined8 *)((long)param_4 + 0x58);
      *(undefined4 *)(pRVar4 + 0x1a4) = *(undefined4 *)((long)param_4 + 0x44);
      *(undefined8 *)(pRVar4 + 0x1a8) = *(undefined8 *)((long)param_4 + 0x4c);
      *(undefined4 *)(pRVar4 + 0x1b0) = *(undefined4 *)((long)param_4 + 0x54);
      *(undefined8 *)(pRVar4 + 0x1b4) = uVar6;
      *(undefined4 *)(pRVar4 + 0x1bc) = *(undefined4 *)((long)param_4 + 0x60);
      strncpy((char *)(pRVar4 + 0x1c0),(char *)((long)param_4 + 100),0x7f);
      *(undefined8 *)(pRVar4 + 0x240) = *(undefined8 *)((long)param_4 + 0xe4);
      *(undefined2 *)(pRVar4 + 0x248) = *(undefined2 *)((long)param_4 + 0xec);
      *(undefined8 *)(pRVar4 + 0x24c) = *(undefined8 *)((long)param_4 + 0xf0);
    }
    if ((pRVar4[0x1c] == (RecMngInfo)0x0) ||
       ((pRVar4[0x140] != (RecMngInfo)0x0 && (pRVar4[0x15c] == (RecMngInfo)0x0)))) {
LAB_001dbe9c:
      uVar6 = 8;
      local_14 = 4;
      local_16 = 0x73f;
    }
    else {
      pRVar4[0x8b8] = *(RecMngInfo *)((long)param_4 + 0x1c);
      local_20 = (ThnmbnailControl *)0x0;
      iVar3 = SearchThnmbnailControl(&local_20,(uchar)pRVar4[0x8b4]);
      if (iVar3 != 0) {
        local_13 = 0;
        local_12 = 0;
        local_14 = 3;
        local_11 = 0;
        local_18 = 0x2110;
        local_16 = 0x733;
        local_10 = (uint)(byte)pRVar4[0x8b4];
        FUN_001c9f24(&local_18,0xc);
        uVar6 = FUN_001fdff4(*(undefined8 *)(PTR_s_movieRecInfo_00401670 + 0xa50),
                             *(undefined4 *)((long)param_4 + 0x18),0);
        goto LAB_001dbbe8;
      }
      if (local_20[5] != (ThnmbnailControl)0x0) {
        ProcessWriterEvtStopCmp
                  ((MovieRecInfo *)PTR_s_movieRecInfo_00401670,
                   (RecSequenceInfo *)PTR_s_recSequenceInfo_004019c0,pRVar4,local_20);
        goto LAB_001dbe9c;
      }
      uVar6 = 0xc;
      local_14 = 3;
      local_16 = 0x734;
      local_10 = (uint)(byte)pRVar4[0x8b4];
    }
    local_11 = 0;
    local_12 = 0;
    local_13 = 0;
    local_18 = 0x2110;
    FUN_001c9f24(&local_18,uVar6);
  }
  return;
}

