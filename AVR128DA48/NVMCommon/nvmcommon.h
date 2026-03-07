#ifndef NVMCOMMON_H
#define	NVMCOMMON_H

#include "nvm/nvm.h"

#define BOOT_BEGIN_ADDR     FLASHSTART
#define BOOT_PAGE_SIZE      40U // FUSE.BOOTSIZE in configure bits
#define BOOT_END_ADDR       ((BOOT_PAGE_SIZE*PROGMEM_PAGE_SIZE)+BOOT_BEGIN_ADDR-1)

#define APPCODE_BEGIN_ADDR  (BOOT_END_ADDR+1)
#define APPCODE_PAGE_SIZE   163U // FUSE.CODESIZE in configure bits
#define APPCODE_END_ADDR    ((APPCODE_PAGE_SIZE*PROGMEM_PAGE_SIZE)+APPCODE_BEGIN_ADDR-1)

#define APPDATA_BEGIN_ADDR  (APPCODE_END_ADDR+1)
#define APPDATA_PAGE_SIZE   53U
#define APPDATA_END_ADDR    FLASHEND

#define ENCKEY_ADDR         (APPDATA_BEGIN_ADDR+480U)

bool SW0_IsPressed(void);
void Display_SystemInfo(void);
void Display_EEPROM_Zone(void);
void Display_DATA_Zone(void);
void BLD_Jump2App(void);

#endif
