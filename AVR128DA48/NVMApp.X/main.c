#include "system/system.h"
#include "../NVMCommon/nvmcommon.h"

static const char DataZone[APPDATA_PAGE_SIZE*PROGMEM_PAGE_SIZE] __at(APPDATA_BEGIN_ADDR) ={
};

static void PIT_UsrCb(void)
{
    LED0_Toggle();
}

int main(void)
{
    SYSTEM_Initialize();
    Display_SystemInfo();
    //printf("\r\nData zone: %s", (const char *)DataZone);
    RTC_SetPITIsrCallback(PIT_UsrCb);

    while(1)
    {
        wdt_reset();

        if(SW0_IsPressed())
        {
            uint16_t key=FLASH_ReadWord(APPDATA_BEGIN_ADDR);
            
            printf("\r\n[%u] SW0 is pressed", RTC_ReadCounter());
            
            if(key==0xFFFF)
            {
                printf("\r\nWrite Key @ %04X", (APPDATA_BEGIN_ADDR>>1));
                DISABLE_INTERRUPTS();
                FLASH_PageErase(FLASH_ErasePageAddressGet(APPDATA_BEGIN_ADDR));
                FLASH_Write(APPDATA_BEGIN_ADDR, 0x55AA);
                ENABLE_INTERRUPTS();
            }
            else
            {
                printf("\r\nRead Key @ %04X: %04X", (APPDATA_BEGIN_ADDR>>1), key);
            }
        }
    }

    return 0;
}