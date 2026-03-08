#include "system/system.h"
#include "../NVMCommon/nvmcommon.h"

int main(void)
{
    SYSTEM_Initialize();
    Display_SystemInfo();
    Display_EEPROM_Zone();
    Display_DATA_Zone();

    if(SW0_GetValue()!=0)
        BLD_Jump2App();

    printf("\r\nBootloader");

    while(1)
    {
        wdt_reset();

        if(SW0_IsPressed())
        {
            printf("\r\nSW0 is pressed");
            Test_AppData();
        }
    }

    printf("\r\nSleep from bootloader");
    _delay_ms(100);
    POWER_LowPowerModeEnter(POWER_PDOWN_MODE);

    return 0;
}
