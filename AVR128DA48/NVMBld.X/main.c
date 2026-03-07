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
            uint16_t key=FLASH_ReadWord(APPDATA_BEGIN_ADDR);

            printf("\r\nSW0 is pressed");

            if(key==0xFFFF)
            {
                printf("\r\nWrite Key @ %04X", (APPDATA_BEGIN_ADDR>>1));
                //FLASH_PageErase(FLASH_ErasePageAddressGet(APPDATA_BEGIN_ADDR));
                FLASH_Write(APPDATA_BEGIN_ADDR, 0x55AA);
            }
            else
            {
                printf("\r\nRead Key @ %04X: %04X", (APPDATA_BEGIN_ADDR>>1), key);
            }
        }
    }

    printf("\r\nSleep from bootloader");
    _delay_ms(100);
    POWER_LowPowerModeEnter(POWER_PDOWN_MODE);

    return 0;
}
