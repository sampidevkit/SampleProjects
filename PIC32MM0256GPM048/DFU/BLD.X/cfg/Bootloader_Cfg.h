#ifndef BOOTLOADER_CFG_H
#define BOOTLOADER_CFG_H

#define BLD_Trigger_GetState()  BUTTON_GetValue()
#define BLD_Trigger_Init()      BUTTON_SetDigitalInput()
#define BLD_Comm_Init()         

//#define BLD_DISABLE_CODE_PROTECT
#define USE_BOOTLOADER_BUILTIN_EXCEPTION

/* ************************************************************ UART BLD only */
#define BLD_IsRxReady()         UART2_IsRxReady()
#define BLD_IsTxReady()         UART2_IsTxReady()
#define BLD_IsTxDone()          UART2_IsTxDone()
#define BLD_Read()              UART2_Read()
#define BLD_Write(b)            UART2_Write(b)

#define __PROJECT_NAME__        "SAMPI BOOTLOADER"
#define __HARDWARE_ID__         "SAMM-Mx6-SD"
#define __WEBSITE__             "https://github.com/sampidevkit"

#endif