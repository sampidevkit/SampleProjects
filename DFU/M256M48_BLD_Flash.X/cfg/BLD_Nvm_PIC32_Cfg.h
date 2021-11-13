#ifndef BLD_NVM_PIC32_CFG_H
#define BLD_NVM_PIC32_CFG_H

#include <xc.h>

#define BLD_NVM_TARGET_DEVICE_PIC32MM0256GPM0XX
//#define BLD_NVM_TARGET_DEVICE_PIC32MM0128GPM0XX
//#define BLD_NVM_TARGET_DEVICE_PIC32MM0064GPM0XX

#define BLD_Nvm_Lock()                          FLASH_Lock()
#define BLD_Nvm_UnLock()                        FLASH_Unlock(FLASH_UNLOCK_KEY)
#define BLD_Nvm_ErasePage(addr)                 FLASH_ErasePage(addr)
#define BLD_Nvm_WriteDoubleWord(addr, Lsb, Msb) FLASH_WriteDoubleWord(addr, Lsb, Msb)

#define BLD_Nvm_SystemReboot()					BootLoader_Deinitialize() // UART Bootloader
//#define BLD_Nvm_SystemReboot()					do{Flash_WriteByte(0x00, 0xFF); BootLoader_Deinitialize();}while(0) // SPI Flash Bootloader

#if defined(BLD_NVM_TARGET_DEVICE_PIC32MM0256GPM0XX) // tested

#if defined(__32MM0256GPM028_H)
#define __BLD_NVM_TARGET_DEVICE_NAME__  "PIC32MM0256GPM028"
#elif defined(__32MM0256GPM036_H)
#define __BLD_NVM_TARGET_DEVICE_NAME__  "PIC32MM0256GPM036"
#elif defined(__32MM0256GPM048_H)
#define __BLD_NVM_TARGET_DEVICE_NAME__  "PIC32MM0256GPM048"
#elif defined(__32MM0256GPM064_H)
#define __BLD_NVM_TARGET_DEVICE_NAME__  "PIC32MM0256GPM064"
#else
#error "Target MCU is not supported"
#endif

// Bootloader size is fixed in 20480 bytes (20kB)
// Application size is 262144-20480=241664 bytes (236kB)
#define BLD_NVM_TARGET_DEVICE_PAGE_SIZE FLASH_ERASE_PAGE_SIZE_IN_PC_UNITS // (bytes)
#define APP_RESET_ADDRESS               0x9D000000
#define APP_BEGIN_ADDRESS               0x1D000000
#define APP_END_ADDRESS                 0x1D03AFFF
#define APP_SIZE_IN_PAGE                118 // (pages)
#define TARGET_PACK_BYTE_MASK           0xFFFFF800 // 2048 bytes/page
#define TARGET_PACK_IDX_MASK            0x7FF // 0 to 2047   

#elif defined(BLD_NVM_TARGET_DEVICE_PIC32MM0128GPM0XX) // not complete

#if defined(__32MM0128GPM028_H)
#define __BLD_NVM_TARGET_DEVICE_NAME__  "PIC32MM0256GPM028"
#elif defined(__32MM0128GPM036_H)
#define __BLD_NVM_TARGET_DEVICE_NAME__  "PIC32MM0256GPM036"
#elif defined(__32MM0128GPM048_H)
#define __BLD_NVM_TARGET_DEVICE_NAME__  "PIC32MM0256GPM048"
#elif defined(__32MM0128GPM064_H)
#define __BLD_NVM_TARGET_DEVICE_NAME__  "PIC32MM0256GPM064"
#else
#error "Target MCU is not supported"
#endif

// Bootloader size is fixed in 20480 bytes (20kB)
// Application size is 131072-20480=110592 bytes (108kB)
#define BLD_NVM_TARGET_DEVICE_PAGE_SIZE FLASH_ERASE_PAGE_SIZE_IN_PC_UNITS // (bytes)
#define APP_RESET_ADDRESS               0x9D000000
#define APP_BEGIN_ADDRESS               0x1D000000
#define APP_END_ADDRESS                 0x1D01AFFF
#define APP_SIZE_IN_PAGE                54 // (pages)
#define TARGET_PACK_BYTE_MASK           0xFFFFF800 // 2048 bytes/page
#define TARGET_PACK_IDX_MASK            0x7FF // 0 to 2047   

#elif defined(BLD_NVM_TARGET_DEVICE_PIC32MM0064GPM0XX) // not complete

#if defined(__32MM0064GPM028_H)
#define __BLD_NVM_TARGET_DEVICE_NAME__  "PIC32MM0064GPM028"
#elif defined(__32MM0064GPM036_H)
#define __BLD_NVM_TARGET_DEVICE_NAME__  "PIC32MM0064GPM036"
#elif defined(__32MM0064GPM048_H)
#define __BLD_NVM_TARGET_DEVICE_NAME__  "PIC32MM0064GPM048"
#elif defined(__32MM0064GPM064_H)
#define __BLD_NVM_TARGET_DEVICE_NAME__  "PIC32MM0064GPM064"
#else
#error "Target MCU is not supported"
#endif

// Bootloader size is fixed in 20480 bytes (20kB)
// Application size is 65536-20480=45056 bytes (44kB)
#define BLD_NVM_TARGET_DEVICE_PAGE_SIZE FLASH_ERASE_PAGE_SIZE_IN_PC_UNITS // (bytes)
#define APP_RESET_ADDRESS               0x9D000000
#define APP_BEGIN_ADDRESS               0x1D000000
#define APP_END_ADDRESS                 0x1D00AFFF
#define APP_SIZE_IN_PAGE                22 // (pages)
#define TARGET_PACK_BYTE_MASK           0xFFFFF800 // 2048 bytes/page
#define TARGET_PACK_IDX_MASK            0x7FF // 0 to 2047   

#endif
#endif