// mpr::XavcOutBandParamDataBuffer::GetFreeArea
// Ghidra address: 00207a18

/* mpr::XavcOutBandParamDataBuffer::GetFreeArea(unsigned int, void**) */

void __thiscall
mpr::XavcOutBandParamDataBuffer::GetFreeArea
          (XavcOutBandParamDataBuffer *this,uint param_1,void **param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  void *pvVar4;
  undefined8 uVar5;
  
  *param_2 = (void *)0x0;
  uVar2 = RingBuffer::GetRemainSize(*(RingBuffer **)(this + 0x18));
  if (param_1 <= uVar2) {
    uVar5 = *(undefined8 *)(this + 8);
    iVar1 = *(int *)(this + 0x10);
    iVar3 = RingBuffer::GetWritePointer(*(RingBuffer **)(this + 0x18));
    uVar2 = (iVar1 + (int)uVar5) - iVar3;
    if (uVar2 < param_1) {
      uVar5 = RingBuffer::GetWritePointer(*(RingBuffer **)(this + 0x18));
      *(undefined8 *)(this + 0x20) = uVar5;
      *(uint *)(this + 0x28) = uVar2;
      UseMemory(this,uVar2);
    }
    uVar2 = RingBuffer::GetRemainSize(*(RingBuffer **)(this + 0x18));
    if (param_1 <= uVar2) {
      pvVar4 = (void *)RingBuffer::GetWritePointer(*(RingBuffer **)(this + 0x18));
      *param_2 = pvVar4;
    }
  }
  return;
}

