// InfraMovieDecoderSeqDecOpen::SetParameter
// Ghidra address: 001e5f1c

/* InfraMovieDecoderSeqDecOpen::SetParameter(unsigned char const*) */

void __thiscall
InfraMovieDecoderSeqDecOpen::SetParameter(InfraMovieDecoderSeqDecOpen *this,uchar *param_1)

{
  long lVar1;
  
  (**(code **)(**(long **)(this + 0x10) + 0x60))(*(long **)(this + 0x10),0x1023,param_1,0x38);
  lVar1 = *(long *)(param_1 + 0x30);
  (**(code **)(**(long **)(this + 0x10) + 0x50))
            (*(long **)(this + 0x10),0x1072,*(undefined8 *)(lVar1 + 0x20));
  (**(code **)(**(long **)(this + 0x10) + 0x38))
            (*(long **)(this + 0x10),0x1073,*(undefined2 *)(lVar1 + 0x28));
  this[0x1b8] = *(InfraMovieDecoderSeqDecOpen *)(param_1 + 0x20);
  if (0 < *(int *)PTR_avbizPrintLevel_002b3710) {
    OBJAVBBCBASECLASS::BizPrintf
              (0x55,4,3,0x57,"[InfDecoder][*TEST*] MovieDecoderSeqDecOpen codecID : %x");
    return;
  }
  return;
}

