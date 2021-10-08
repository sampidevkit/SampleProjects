#ifndef BLD_NVM_PIC32_H
#define	BLD_NVM_PIC32_H

#include "Common/LibDef.h"
#include "BLD_Nvm_PIC32_Cfg.h"

#ifndef BLD_Nvm_SystemReboot
#define BLD_Nvm_SystemReboot() BootLoader_Deinitialize()
#endif

public int8_t BLD_Nvm_Write(uint32_t Addr, const uint8_t *pData, int Len);

#endif