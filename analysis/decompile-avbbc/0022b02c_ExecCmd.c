// ExecCmd_MC_DecOpen::ExecCmd
// Ghidra address: 0022b02c

/* ExecCmd_MC_DecOpen::ExecCmd(unsigned char const*) */

undefined8 ExecCmd_MC_DecOpen::ExecCmd(uchar *param_1)

{
  undefined *puVar1;
  uchar *puVar2;
  uchar *puVar3;
  undefined2 uVar4;
  uchar *local_8;
  
  (**(code **)(**(long **)(param_1 + 0x18) + 0xb0))(*(long **)(param_1 + 0x18),0x1023,&local_8);
  if (0 < *(int *)PTR_avbizPrintLevel_002b3710) {
    OBJAVBBCBASECLASS::BizPrintf
              (0x55,4,3,0x37,
               "[InfDecoder]ExecCmd_MC_DecOpen ExecCmd. %p, cid = 0x%x. prmAddr = 0x%x",local_8,
               (ulong)*(ushort *)(local_8 + 10),*(undefined8 *)(local_8 + 0x10));
  }
  if (0 < *(int *)PTR_avbizPrintLevel_002b3710) {
    OBJAVBBCBASECLASS::BizPrintf
              (0x55,4,3,0x3a,"[InfDecoder]ExecCmd_MC_DecOpen ExecCmd. prmSize = 0x%x. mid = 0x%x",
               (ulong)*(uint *)(local_8 + 0x18),(ulong)*(uint *)(local_8 + 0x2c));
  }
  puVar2 = local_8;
  uVar4 = InfraAvbbcMsgManager::ConvertCid(*(InfraAvbbcMsgManager **)(param_1 + 0x10),5);
  puVar3 = local_8;
  *(undefined2 *)puVar2 = uVar4;
  uVar4 = InfraAvbbcMsgManager::ConvertCmdMid(*(InfraAvbbcMsgManager **)(param_1 + 0x10),5,0x520);
  puVar1 = PTR_avbizPrintLevel_002b3710;
  *(undefined2 *)(puVar3 + 2) = uVar4;
  local_8[4] = '8';
  local_8[5] = '\0';
  if (0 < *(int *)puVar1) {
    OBJAVBBCBASECLASS::BizPrintf
              (0x55,4,3,0x41,"[InfDecoder]ExecCmd_MC_DecOpen ExecCmd. Msg = %p. osal_id = 0x%x",
               local_8,(ulong)*(uint *)(param_1 + 0xc));
  }
  InfraAvbbcLog::SetLog0
            (*(uint *)(param_1 + 8),0x201e841,*(uint *)(local_8 + 0x2c),*(uint *)(local_8 + 0x10),
             *(ushort *)(local_8 + 10));
  InfraAvbbcMsgManager::OsalSndMsg
            (*(InfraAvbbcMsgManager **)(param_1 + 0x10),0x805700f9,local_8,
             (uint)*(ushort *)(local_8 + 4));
  return 0;
}

