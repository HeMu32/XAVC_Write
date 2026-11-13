// sidb::RestorateUMID
// Ghidra address: 0038e698

/* sidb::RestorateUMID(unsigned char*, DefStruct::LocalTime const&, unsigned char const*, unsigned
   char) */

undefined8 sidb::RestorateUMID(uchar *param_1,LocalTime *param_2,uchar *param_3,uchar param_4)

{
  if (param_3 != (uchar *)0x0 && param_1 != (uchar *)0x0) {
    *(undefined2 *)(param_1 + 0xd) = *(undefined2 *)param_3;
    param_1[0xf] = param_3[2];
    FUN_003cd954(param_2,param_1 + 0x10);
    param_1[0x17] = param_4;
    return 0;
  }
  return 0x407;
}

