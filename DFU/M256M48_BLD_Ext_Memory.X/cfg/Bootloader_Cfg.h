#ifndef BOOTLOADER_CFG_H
#define BOOTLOADER_CFG_H

#define __PROJECT_NAME__        "SAMPI BOOTLOADER"
#define __HARDWARE_ID__         "SAMM-Mx6-SD"
#define __WEBSITE__             "https://github.com/sampidevkit"
#define USE_BOOTLOADER_BUILTIN_EXCEPTION

/* ********************************************************** External Memory */
#define BLD_Trigger_GetState()  (BLD_Ext_Memory_GetTriggerState()==BLD_FW_NEW_UPDATE)
#define BLD_Trigger_Init()      BLD_Ext_Memory_Init()
#define BLD_Comm_Init()         
#define BLD_IsRxReady()         1
#define BLD_IsTxReady()         1
#define BLD_IsTxDone()          1
#define BLD_Read()              BLD_Ext_Memory_ReadHex()
#define BLD_Write(b)            

#endif