// mpr::XavcOutBandParamDataBuffer::UseMemory
// Ghidra address: 00207a10

/* mpr::XavcOutBandParamDataBuffer::UseMemory(unsigned int) */

void __thiscall
mpr::XavcOutBandParamDataBuffer::UseMemory(XavcOutBandParamDataBuffer *this,uint param_1)

{
  RingBuffer::UseMemory(*(RingBuffer **)(this + 0x18),param_1);
  return;
}

