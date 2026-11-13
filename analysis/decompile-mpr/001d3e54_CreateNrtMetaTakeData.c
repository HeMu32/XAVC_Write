// mpr::CreateNrtMetaTakeData
// Ghidra address: 001d3e54

/* mpr::CreateNrtMetaTakeData(mpr::MovieRecInfo&, mpr::RecMngInfo&, unsigned char*, unsigned int*)
    */

undefined8
mpr::CreateNrtMetaTakeData(MovieRecInfo *param_1,RecMngInfo *param_2,uchar *param_3,uint *param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  long *plVar4;
  undefined2 local_118;
  undefined2 local_116;
  undefined1 local_114;
  undefined1 local_113;
  undefined1 local_112;
  undefined1 local_111;
  undefined8 local_110;
  undefined8 uStack_108;
  undefined8 local_100;
  undefined8 uStack_f8;
  undefined4 local_e8;
  undefined2 local_e0;
  undefined2 local_de;
  undefined1 local_dc;
  undefined1 local_db;
  undefined1 local_da;
  undefined1 local_d9;
  undefined1 local_d8;
  undefined2 local_d6;
  undefined2 local_d4;
  undefined1 local_d2;
  undefined1 local_d1;
  undefined1 local_d0;
  undefined1 local_cf;
  undefined1 local_ce;
  undefined4 local_cc;
  undefined1 local_c8;
  undefined4 local_c4;
  undefined4 uStack_c0;
  undefined4 local_bc;
  undefined4 uStack_b8;
  undefined4 local_b4;
  undefined4 uStack_b0;
  undefined1 local_ac;
  undefined4 local_a8;
  undefined4 uStack_a4;
  undefined4 local_a0;
  undefined2 local_8c;
  undefined2 local_8a;
  undefined4 local_88;
  undefined1 local_84;
  undefined4 local_80;
  undefined1 local_7c;
  undefined1 local_78;
  undefined8 local_77;
  undefined8 uStack_6f;
  undefined8 local_67;
  undefined8 uStack_5f;
  undefined1 *local_50;
  undefined8 uStack_48;
  undefined1 local_40 [16];
  undefined4 local_30;
  undefined4 local_2c;
  undefined1 local_28;
  undefined1 *local_20;
  undefined8 uStack_18;
  undefined1 local_10 [16];
  
  local_de = 0x7e0;
  local_dc = 4;
  local_e0 = 0x2110;
  local_db = 0;
  local_da = 0;
  local_d9 = 0;
  FUN_001c9f24(&local_e0,8);
  plVar4 = operator_new(0x30);
  FUN_00352de0();
  iVar1 = *(int *)(param_2 + 0xad0);
  local_e8 = 3;
  local_110 = 0;
  uStack_108 = 0;
  local_100 = 0;
  uStack_f8 = 0;
  uVar3 = GetVideoCodec(*(undefined4 *)(param_1 + 0x1d0));
  SetNrtMetaTakeSetProfileParam
            (*(undefined4 *)(param_1 + 0x1d8),uVar3,param_2 + (ulong)(iVar1 - 1) * 0x28 + 0xad4,
             &local_110);
  FUN_00353198(plVar4,&local_110);
  FUN_00353554(plVar4,0,*(undefined4 *)(param_2 + 0x1a80),0);
  iVar1 = *(int *)(param_2 + 0x1a70);
  iVar2 = *(int *)(param_2 + 100);
  FUN_00353554(plVar4,iVar1 + iVar2 + -1,*(undefined4 *)(param_2 + 0x48),2);
  local_e0 = 0;
  local_de = 0;
  local_dc = 0;
  local_88 = 500;
  local_50 = local_40;
  local_db = 0;
  local_da = 0;
  local_d9 = 0;
  local_d8 = 0;
  local_d6 = 0;
  local_d4 = 0;
  local_d2 = 0;
  local_d1 = 0;
  local_d0 = 0;
  local_cf = 0;
  local_ce = 0;
  local_c8 = 0;
  local_ac = 0;
  local_8c = 0;
  local_8a = 0;
  local_84 = 0;
  local_7c = 0;
  local_c4 = 0;
  uStack_c0 = 0;
  local_bc = 0;
  uStack_b8 = 0;
  local_b4 = 0;
  uStack_b0 = 0;
  local_a8 = 0;
  uStack_a4 = 0;
  local_a0 = 0;
  local_80 = 0;
  uStack_48 = 0;
  local_40[0] = 0;
  local_78 = 0;
  local_77 = 0;
  uStack_6f = 0;
  local_67 = 0;
  uStack_5f = 0;
  local_20 = local_10;
  uStack_18 = 0;
  local_30 = 3;
  local_10[0] = 0;
  local_28 = 0;
  local_cc = 0;
  local_2c = 0;
  SetNrtMetaTakeSetRecordingInfoParam
            (*(undefined8 *)(param_2 + 0x1a84),*(undefined4 *)(param_2 + 0x1a8c),
             *(undefined8 *)(param_2 + 0x74),*(undefined4 *)(param_2 + 0x7c),iVar1 + iVar2,&local_e0
            );
  FUN_00353274(plVar4,&local_e0);
  FUN_0035353c(plVar4,param_3,0x200000,param_4);
  (**(code **)(*plVar4 + 8))(plVar4);
  local_114 = 4;
  local_118 = 0x2110;
  local_116 = 0x7ef;
  local_113 = 0;
  local_112 = 0;
  local_111 = 0;
  FUN_001c9f24(&local_118,8);
  std::__cxx11::string::_M_dispose();
  std::__cxx11::string::_M_dispose();
  return 0;
}

