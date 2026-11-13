// ExecCmd_MC_DecOpen::ResCmd
// Ghidra address: 0022b180

/* ExecCmd_MC_DecOpen::ResCmd(unsigned char const*, unsigned short) */

undefined8 __thiscall
ExecCmd_MC_DecOpen::ResCmd(ExecCmd_MC_DecOpen *this,uchar *param_1,ushort param_2)

{
  undefined4 uVar1;
  undefined8 uVar2;
  
  if (param_2 == 0x851a) {
    InfraAvbbcLog::SetLog0(*(uint *)(this + 8),0x201e842,0,0,0);
    if (0 < *(int *)PTR_avbizPrintLevel_002b3710) {
      OBJAVBBCBASECLASS::BizPrintf(0x55,4,3,0x5a,"[InfDecoder]SeqDecOpen Continue");
    }
    uVar1 = InfraAvbbcErrConverter::Convert(5,*(uint *)(param_1 + 0x1c));
    *(undefined4 *)(param_1 + 0x1c) = uVar1;
    uVar2 = 0;
  }
  else {
    InfraAvbbcLog::SetLog3(*(uint *)(this + 8),0x201e8a8,0x5e,0x201e841,(uint)param_2);
    uVar2 = 1;
  }
  return uVar2;
}

