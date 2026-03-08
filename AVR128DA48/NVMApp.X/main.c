#include "system/system.h"
#include "../NVMCommon/nvmcommon.h"

static const char DataZone[APPDATA_PAGE_SIZE*PROGMEM_PAGE_SIZE] __at(APPDATA_BEGIN_ADDR)={
};

static void PIT_UsrCb(void)
{
    LED0_Toggle();
}

int main(void)
{
    SYSTEM_Initialize();
    Display_SystemInfo();
    RTC_SetPITIsrCallback(PIT_UsrCb);
    printf("\r\nApplication");

    while(1)
    {
        wdt_reset();

        if(SW0_IsPressed())
        {
            printf("\r\nSW0 is pressed");
            Test_AppData();
        }
    }

    return 0;
}