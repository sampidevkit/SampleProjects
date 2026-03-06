#include "system/system.h"
#include <avr/wdt.h>
#include <util/delay.h>

#define BOOT_BEGIN_ADDR                 FLASHSTART
#define BOOT_PAGE_SIZE                  40U // FUSE.BOOTSIZE in configure bits
#define BOOT_END_ADDR                   20479U // (FUSE.BOOTSIZE*512)-1 in configure bits

#define APP_BEGIN_ADDR                  (BOOT_END_ADDR+1)
#define APP_PAGE_SIZE                   163U // FUSE.CODESIZE in configure bits
#define APP_END_ADDR                    83455U // (FUSE.CODESIZE*512)-1 in configure bits

#define DATA_BEGIN_ADDR                 (APP_END_ADDR+1)
#define DATA_PAGE_SIZE                  53U
#define DATA_END_ADDR                   FLASHEND

#define ENCKEY_ADDR                     (DATA_BEGIN_ADDR+480U)

#define FLASH_PACK_DATA_SIZE            (PROGMEM_PAGE_SIZE>>1U) // unit: Word
#define FLASH_DATA_INDEX_IN_PAGE        (FLASH_PACK_DATA_SIZE-1) // word index
#define FLASH_ERASE_PAGE_MASK           (~FLASH_DATA_INDEX_IN_PAGE)

static void BLD_Jump2App(void) // <editor-fold defaultstate="collapsed" desc="Jump to application">
{
    uint16_t opcode=FLASH_ReadWord(APP_BEGIN_ADDR);

    if(0xFFFF!=opcode)
    {
        printf("\r\nOpcode %04X", APP_BEGIN_ADDR>>1);
        printf(" : %04X", opcode);
        _delay_ms(100);

        NVMCTRL.CTRLB=NVMCTRL_BOOTRP_bm; // Enable Boot Section Lock
        pgm_jmp_far(APP_BEGIN_ADDR>>1); // Jump to application, located immediately after boot section
    }
} // </editor-fold>

static void Display_SystemInfo(void) // <editor-fold defaultstate="collapsed" desc="Display system info">
{
    printf("\r\r\r\rAVR BOOTLOADER" \
    "\r\nHwID: DM164151 - AVR128DA48 CURIOSITY NANO" \
    "\r\nMCU: AVR128DA48" \
    "\r\nRel: " __DATE__ "-" __TIME__);

    printf("\r\nRESET: %02X ", RSTCTRL_RSTFR);

    if(bit_is_set(RSTCTRL_RSTFR, 5))
        printf("UPDI ");

    if(bit_is_set(RSTCTRL_RSTFR, 4))
        printf("SW ");

    if(bit_is_set(RSTCTRL_RSTFR, 3))
        printf("WDT ");

    if(bit_is_set(RSTCTRL_RSTFR, 2))
        printf("MCLR ");

    if(bit_is_set(RSTCTRL_RSTFR, 1))
        printf("BOR ");

    if(bit_is_set(RSTCTRL_RSTFR, 0))
        printf("POD");
} // </editor-fold>

static void Display_EEPROM_Zone(void) // <editor-fold defaultstate="collapsed" desc="EEPROM data">
{
    for(uint16_t addr=EEPROM_START; addr<(EEPROM_END+1); addr++)
    {
        uint8_t data;

        wdt_reset();
        data=EEPROM_Read(addr);

        if(data==0xFF)
            continue;

        printf("\r\nEE %04X: %02X", addr, data);
    }
} // </editor-fold>

static void Display_DATA_Zone(void) // <editor-fold defaultstate="collapsed" desc="Data zone">
{
    for(uint32_t addr=DATA_BEGIN_ADDR; addr<(DATA_END_ADDR+1); addr+=2)
    {
        uint16_t data;
        uint16_t wordAddr;

        wdt_reset();
        data=FLASH_ReadWord(addr);

        if(data==0xFFFF)
            continue;

        wordAddr=(uint16_t) (addr>>1);
        printf("\r\nDT %04X: %04X", wordAddr, data);
    }
} // </editor-fold>

int main(void)
{
    SYSTEM_Initialize();
    Display_SystemInfo();
    Display_EEPROM_Zone();
    Display_DATA_Zone();
    BLD_Jump2App();
    printf("\r\nSleep from bootloader");
    _delay_ms(100);
    POWER_LowPowerModeEnter(POWER_PDOWN_MODE);
    return 0;
}