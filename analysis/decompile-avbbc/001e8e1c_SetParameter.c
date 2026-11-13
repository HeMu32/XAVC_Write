// InfraMovieDecoderSeqDecOpenAstra::SetParameter
// Ghidra address: 001e8e1c

/* InfraMovieDecoderSeqDecOpenAstra::SetParameter(unsigned char const*) */

void __thiscall
InfraMovieDecoderSeqDecOpenAstra::SetParameter
          (InfraMovieDecoderSeqDecOpenAstra *this,uchar *param_1)

{
  byte bVar1;
  char cVar2;
  UcsMgr *this_00;
  ExecCmd_MC_DecOpen *this_01;
  ExecCmd_SRC_CommandAck *this_02;
  ExecCmd_SRC_CommandComp *this_03;
  long lVar3;
  
  (**(code **)(**(long **)(this + 0x10) + 0x60))(*(long **)(this + 0x10),0x1023,param_1,0x38);
  lVar3 = *(long *)(param_1 + 0x30);
  this[0x1b8] = *(InfraMovieDecoderSeqDecOpenAstra *)(param_1 + 0x20);
  if (0 < *(int *)PTR_avbizPrintLevel_002b3710) {
    OBJAVBBCBASECLASS::BizPrintf
              (0x55,4,3,0x3f,"[InfDecoder][*TEST*] MovieDecoderSeqDecOpen codecID : %x");
  }
  *(undefined1 *)(lVar3 + 0x74) = 3;
  *(undefined1 *)(lVar3 + 0x75) = 0;
  InfraAvbbcLog::SetLog0(0xe,0x2010006,0x43,(uint)*(byte *)(lVar3 + 0x70),0);
  this_00 = (UcsMgr *)UcsMgr::getInstance();
  bVar1 = UcsMgr::GetSaUseCase(this_00);
  *(byte *)(lVar3 + 0x76) = bVar1;
  InfraAvbbcLog::SetLog0(0xe,0x2010006,0x47,(uint)bVar1,0);
  this_01 = operator_new(0x28);
  ExecCmd_MC_DecOpen::ExecCmd_MC_DecOpen
            (this_01,*(InfraAvbbcMsgManager **)(this + 8),*(ParameterControl **)(this + 0x10),
             *(uint *)(this + 0x2c),0x103f);
  this_02 = operator_new(0x28);
  ExecCmd_SRC_CommandAck::ExecCmd_SRC_CommandAck
            (this_02,*(InfraAvbbcMsgManager **)(this + 8),*(uint *)(this + 0x2c),
             *(ParameterControl **)(this + 0x10),0x103f,0x851b);
  this_03 = operator_new(0x20);
  ExecCmd_SRC_CommandComp::ExecCmd_SRC_CommandComp
            (this_03,*(InfraAvbbcMsgManager **)(this + 8),*(uint *)(this + 0x2c),0,0x111);
  InfraAvbbcSeqBase::SetNextStatus((InfraAvbbcSeqBase *)this,1,0);
  InfraAvbbcSeqBase::SetNextStatus((InfraAvbbcSeqBase *)this,2,1);
  InfraAvbbcSeqBase::SetNextStatus((InfraAvbbcSeqBase *)this,3,2);
  InfraAvbbcSeqBase::SetNextStatus((InfraAvbbcSeqBase *)this,0xffff,3);
  InfraAvbbcSeqBase::SetExecCmd((InfraAvbbcSeqBase *)this,1,(IExecCmdIf *)this_01);
  InfraAvbbcSeqBase::SetExecCmd((InfraAvbbcSeqBase *)this,2,(IExecCmdIf *)this_02);
  InfraAvbbcSeqBase::SetExecCmd((InfraAvbbcSeqBase *)this,3,(IExecCmdIf *)this_03);
  (**(code **)(**(long **)(this + 0x10) + 0x50))
            (*(long **)(this + 0x10),0x1072,*(undefined8 *)(lVar3 + 0x20));
  (**(code **)(**(long **)(this + 0x10) + 0x38))
            (*(long **)(this + 0x10),0x1073,*(undefined2 *)(lVar3 + 0x28));
  cVar2 = ExcludionEnvironmentUtil::IsSetAdjustOn();
  if (cVar2 != '\0') {
    *(undefined1 *)(lVar3 + 0x77) = 1;
  }
  ExcludionEnvironmentUtil::SendCodecDiag(3,*(undefined8 *)(this + 8));
  return;
}

