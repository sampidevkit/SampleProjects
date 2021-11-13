#ifndef BOOTLOADER_CFG_H
#define BOOTLOADER_CFG_H

#define __PROJECT_NAME__        "SAMPI BOOTLOADER"
#define __HARDWARE_ID__         "SAMM-Mx6-SD"
#define __WEBSITE__             "https://github.com/sampidevkit"
#define USE_BOOTLOADER_BUILTIN_EXCEPTION

/* **************************************************************** UART BLD */
//#define BLD_Trigger_GetState()  BUTTON_GetValue()
//#define BLD_Trigger_Init()      BUTTON_SetDigitalInput()
//#define BLD_Comm_Init()         UART2_Initialize()
//#define BLD_IsRxReady()         UART2_IsRxReady()
//#define BLD_IsTxReady()         UART2_IsTxReady()
//#define BLD_IsTxDone()          UART2_IsTxDone()
//#define BLD_Read()              UART2_Read()
//#define BLD_Write(b)            UART2_Write(b)

/* *************************************************************** SPI FLASH */


#define BLD_Trigger_GetState()  (Flash_ReadByte(0x00)==0x00)
#define BLD_Trigger_Init()      Flash_Init()
#define BLD_Comm_Init()         SPI_Init()
#define BLD_IsRxReady()         1
#define BLD_IsTxReady()         1
#define BLD_IsTxDone()          1
#define BLD_Read()              Flash_ReadHex()
#define BLD_Write(b)            

static inline unsigned char Flash_ReadHex(void) {
    static Addr = 0x04; // begin address of hex file

    return Flash_ReadByte(Addr++);
}

#endif