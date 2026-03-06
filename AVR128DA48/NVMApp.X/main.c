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

static const uint8_t __attribute__((used, section(".datazone"))) DataZone[DATA_PAGE_SIZE*PROGMEM_PAGE_SIZE]={
    "If changing the location and size of the above memory areas, at build time,"
    " linker errors might occur. One is advised to throroughly check the length "
    "of each area. For example, the linker error below occurs when, erroneously, "
    "the \".rww_data\" overlapps the \".nrww_data\"\r\n"
};

static void Display_SystemInfo(void) // <editor-fold defaultstate="collapsed" desc="Display system info">
{
    printf("\r\r\r\rAVR APPLICATION" \
    "\r\nHwID: DM164151 - AVR128DA48 CURIOSITY NANO" \
    "\r\nMCU: AVR128DA48" \
    "\r\nRel: " __DATE__ "-" __TIME__);
} // </editor-fold>

static void PIT_UsrCb(void)
{
    LED0_Toggle();
}

static bool SW0_IsPressed(void)
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

int main(void)
{
    SYSTEM_Initialize();
    Display_SystemInfo();
    printf("\r\nData zone: %s", (const char *)DataZone);
    RTC_SetPITIsrCallback(PIT_UsrCb);

    while(1)
    {
        wdt_reset();

        if(SW0_IsPressed())
        {
            printf("\r\n[%u] SW0 is pressed", RTC_ReadCounter());
        }
    }

    return 0;
}