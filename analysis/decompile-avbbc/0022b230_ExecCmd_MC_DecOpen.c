// ExecCmd_MC_DecOpen::ExecCmd_MC_DecOpen
// Ghidra address: 0022b230

/* ExecCmd_MC_DecOpen::ExecCmd_MC_DecOpen(InfraAvbbcMsgManager*, AvbbcParamCtrl::ParameterControl*,
   unsigned int, unsigned int) */

void __thiscall
ExecCmd_MC_DecOpen::ExecCmd_MC_DecOpen
          (ExecCmd_MC_DecOpen *this,InfraAvbbcMsgManager *param_1,ParameterControl *param_2,
          uint param_3,uint param_4)

{
  ExecCmd_Base::ExecCmd_Base((ExecCmd_Base *)this,param_1,param_3);
  *(ParameterControl **)(this + 0x18) = param_2;
  *(uint *)(this + 0x20) = param_4;
  *(undefined **)this = PTR_vtable_002b32e0 + 0x10;
  return;
}

