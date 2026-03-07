#include "nvmcommon.h"
#include "system/system.h"

bool SW0_IsPressed(void)
{
    static bool prv=0;
    static int cnt=0;
    bool pre=(SW0_GetValue()==0);

    if(prv!=pre)
    {
        if(++cnt>1000)
        {
            prv=pre;
            return !prv;
        }
    }
    else
        cnt=0;

    return 0;
}

void Display_SystemInfo(void) // <editor-fold defaultstate="collapsed" desc="Display system info">
{
#if defined(__APPLICATION__)
    printf("\r\r\r\rAVR APPLICATION"
#else
    printf("\r\r\r\rAVR BOOTLOADER"
#endif
            "\r\nHwID: DM164151 - AVR128DA48 CURIOSITY NANO"
            "\r\nMCU: AVR128DA48"
            "\r\nRel: " __DATE__ "-" __TIME__);

#if !defined(__APPLICATION__)
    printf("\r\nBoot: %04X", BOOT_BEGIN_ADDR>>1);
    printf(" - %04X", (uint16_t) (BOOT_END_ADDR>>1));
    printf(" : %ld bytes", ((uint32_t) BOOT_PAGE_SIZE*(uint32_t) PROGMEM_PAGE_SIZE));

    printf("\r\nCode: %04X", APPCODE_BEGIN_ADDR>>1);
    printf(" - %04X", (uint16_t) (APPCODE_END_ADDR>>1));
    printf(" : %ld bytes", ((uint32_t) APPCODE_PAGE_SIZE*(uint32_t) PROGMEM_PAGE_SIZE));

    printf("\r\nData: %04X", APPDATA_BEGIN_ADDR>>1);
    printf(" - %04X", (uint16_t) (APPDATA_END_ADDR>>1));
    printf(" : %ld bytes", ((uint32_t) APPDATA_PAGE_SIZE*(uint32_t) PROGMEM_PAGE_SIZE));

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
#endif
} // </editor-fold>

void Display_EEPROM_Zone(void) // <editor-fold defaultstate="collapsed" desc="EEPROM data">
{
    bool skip=0;
    uint8_t data;
    uint16_t addr;

    printf("\r\nEEPROM: ");

    for(addr=EEPROM_START; addr<(EEPROM_END+1); addr++)
    {
        uint8_t d=EEPROM_Read(addr);

        wdt_reset();

        if(skip==0)
        {
            data=d;
            skip=1;
            printf("\r\nEE %04X", addr);
        }

        if(data!=d)
        {
            skip=0;
            printf(" - %04X : %02X", addr, data);
        }
    }

    if(skip==1)
        printf(" - %04X : %02X", addr, data);
} // </editor-fold>

void Display_DATA_Zone(void) // <editor-fold defaultstate="collapsed" desc="Data zone">
{
    bool skip=0;
    uint16_t data;
    uint16_t wordAddr;

    printf("\r\nAPPDATA: ");

    for(uint32_t addr=APPDATA_BEGIN_ADDR; addr<(APPDATA_END_ADDR+1); addr+=2)
    {
        uint16_t d=FLASH_ReadWord(addr);

        wordAddr=(uint16_t) (addr>>1);
        wdt_reset();

        if(skip==0)
        {
            data=d;
            skip=1;
            printf("\r\nDT %04X", wordAddr);
        }

        if(data!=d)
        {
            skip=0;
            printf(" - %04X : %04X", wordAddr, data);
        }
    }

    if(skip==1)
        printf(" - %04X : %04X", wordAddr, data);
} // </editor-fold>

void BLD_Jump2App(void) // <editor-fold defaultstate="collapsed" desc="Jump to application">
{
    uint16_t opcode=FLASH_ReadWord(APPCODE_BEGIN_ADDR);

    if(0xFFFF!=opcode)
    {
        printf("\r\nOpcode %04X", APPCODE_BEGIN_ADDR>>1);
        printf(" : %04X", opcode);
        _delay_ms(100);

        NVMCTRL.CTRLB=NVMCTRL_BOOTRP_bm; // Enable Boot Section Lock
        pgm_jmp_far(APPCODE_BEGIN_ADDR>>1); // Jump to application, located immediately after boot section
    }
} // </editor-fold>
