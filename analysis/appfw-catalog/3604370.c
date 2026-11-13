// ELF VMA 0x3604370; Ghidra bias 0x100000

long appfw_3604370(ulong param_1,int param_2)

{
  long lVar1;
  
  if (param_2 == 0x39) {
    return (-(param_1 >> 0x1f & 1) & 0xffffffe000000000 | (param_1 & 0xffffffff) << 5) + 0x8b9a758;
  }
  switch(param_2) {
  case 0:
    return 0x8b9a180;
  case 1:
    return 0x8b9af10;
  case 2:
    return 0x8b9aed0;
  case 3:
    return 0x8b9aef0;
  case 4:
    return 0x8b9ac68;
  case 5:
    return 0x8b9abf8;
  case 6:
    return 0x8b9ac18;
  case 7:
    return 0x8b9abd8;
  case 8:
    return 0x8b9aeb0;
  case 9:
    return 0x8b9afc0;
  case 10:
    return 0x8b9afe0;
  case 0xb:
    return 0x8b9afa0;
  case 0xc:
    return 0x8b9a758;
  case 0xd:
    lVar1 = 0x8b9a758;
    break;
  case 0xe:
    lVar1 = 0x8b9a758;
    goto code_r0x037040c0;
  case 0xf:
    lVar1 = 0x8b9a758;
    goto code_r0x037040d0;
  case 0x10:
    lVar1 = 0x8b9a758;
    goto code_r0x037040e0;
  case 0x11:
    lVar1 = 0x8b9a758;
    goto code_r0x037040f0;
  case 0x12:
    lVar1 = 0x8b9a758;
    goto code_r0x03704100;
  case 0x13:
    lVar1 = 0x8b9a758;
    goto code_r0x03704110;
  case 0x14:
    lVar1 = 0x8b9a758;
    goto code_r0x03704120;
  case 0x15:
    return 0x8b9a878;
  case 0x16:
    return 0x8b9a898;
  case 0x17:
    return 0x8b9a8b8;
  case 0x18:
    return 0x8b9a8d8;
  case 0x19:
    return 0x8b9a8f8;
  case 0x1a:
    return 0x8b9af68;
  case 0x1b:
    return 0x8b9a938;
  case 0x1c:
    return 0x8b9a958;
  case 0x1d:
    return 0x8b9a978;
  case 0x1e:
    return 0x8b9a998;
  case 0x1f:
    return 0x8b9a9b8;
  case 0x20:
    return 0x8b9a9d8;
  case 0x21:
    return 0x8b9a9f8;
  case 0x22:
    return 0x8b9aa18;
  case 0x23:
    return 0x8b9aa38;
  case 0x24:
    return 0x8b9aa58;
  case 0x25:
    return 0x8b9aa78;
  case 0x26:
    return 0x8b9aa98;
  case 0x27:
    return 0x8b9aab8;
  case 0x28:
    return 0x8b9aad8;
  case 0x29:
    return 0x8b9aaf8;
  case 0x2a:
    return 0x8b9ab38;
  case 0x2b:
    return 0x8b9ab58;
  case 0x2c:
    return 0x8b9ab78;
  default:
    func_0x0374badc(&UNK_04d1dc96,0x411,&UNK_04d209c0);
    return 0;
  case 0x2e:
    return 0x8b9abb8;
  case 0x2f:
    return 0x8b9ad48;
  case 0x30:
    lVar1 = 0x8b9ad48;
    break;
  case 0x31:
    lVar1 = 0x8b9ad48;
code_r0x037040c0:
    return lVar1 + 0x40;
  case 0x32:
    lVar1 = 0x8b9ad48;
code_r0x037040d0:
    return lVar1 + 0x60;
  case 0x33:
    lVar1 = 0x8b9ad48;
code_r0x037040e0:
    return lVar1 + 0x80;
  case 0x34:
    lVar1 = 0x8b9ad48;
code_r0x037040f0:
    return lVar1 + 0xa0;
  case 0x35:
    lVar1 = 0x8b9ad48;
code_r0x03704100:
    return lVar1 + 0xc0;
  case 0x36:
    lVar1 = 0x8b9ad48;
code_r0x03704110:
    return lVar1 + 0xe0;
  case 0x37:
    lVar1 = 0x8b9ad48;
code_r0x03704120:
    return lVar1 + 0x100;
  }
  return lVar1 + 0x20;
}

