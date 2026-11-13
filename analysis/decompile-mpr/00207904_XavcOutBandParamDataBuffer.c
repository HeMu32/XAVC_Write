// mpr::XavcOutBandParamDataBuffer::XavcOutBandParamDataBuffer
// Ghidra address: 00207904

/* mpr::XavcOutBandParamDataBuffer::XavcOutBandParamDataBuffer(mpr::XavcOutBandParamDataBuffer::InitParam)
    */

void __thiscall
mpr::XavcOutBandParamDataBuffer::XavcOutBandParamDataBuffer
          (XavcOutBandParamDataBuffer *this,undefined8 param_2,undefined4 param_3)

{
  RingBuffer *pRVar1;
  
  *(undefined4 *)(this + 0x10) = param_3;
  *(undefined **)this = PTR_vtable_004014c8 + 0x10;
  *(undefined8 *)(this + 8) = param_2;
  pRVar1 = operator_new(0x48);
  RingBuffer::RingBuffer(pRVar1,param_2,param_3);
  *(RingBuffer **)(this + 0x18) = pRVar1;
  *(undefined8 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x28) = 0;
  return;
}

