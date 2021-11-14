#ifndef BOOTLOADER_CFG_H
#define BOOTLOADER_CFG_H

#define __PROJECT_NAME__        "SAMPI BOOTLOADER"
#define __HARDWARE_ID__         "SAMM-Mx6-SD"
#define __WEBSITE__             "https://github.com/sampidevkit"
#define USE_BOOTLOADER_BUILTIN_EXCEPTION

/* ***************************************************************** UART BLD */
#define BLD_Trigger_GetState()  ICSP_PGD_GetValue()
#define BLD_Trigger_Init()      ICSP_PGD_SetDigitalInput()
#define BLD_Comm_Init()         UART3_Initialize()
#define BLD_IsRxReady()         UART3_IsRxReady()
#define BLD_IsTxReady()         UART3_IsTxReady()
#define BLD_IsTxDone()          UART3_IsTxDone()
#define BLD_Read()              UART3_Read()
#define BLD_Write(b)            UART3_Write(b)

#endif