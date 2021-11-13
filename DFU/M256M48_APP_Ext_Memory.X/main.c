#include "libcomp.h"

int main(void)
{
    SYSTEM_Initialize();
    BLD_Ext_Memory_Init();

    while(1)
    {
        WATCHDOG_TimerClear();
        BLD_Ext_Memory_Download_Tasks();

        if(BUTTON_GetValue()==0)
        {
            uint8_t c;

            printf("\nHex Data\n");

            do
            {
                WATCHDOG_TimerClear();
                c=BLD_Ext_Memory_ReadHex();
                printf("%c", c);
            }
            while((c!=0x00)&&(c!=0xFF));
        }
    }

    return 1;
}