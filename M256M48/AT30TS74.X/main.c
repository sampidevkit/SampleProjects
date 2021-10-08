#include "mcc_generated_files/system.h"
#include "mcc_generated_files/watchdog.h"
#include "mcc_generated_files/drivers/i2c_simple_master.h"

#define TICK_PER_MS 12000

int main(void)
{
    uint32_t tick;

    SYSTEM_Initialize();
    tick=_CP0_GET_COUNT();

    while(1)
    {
        if((_CP0_GET_COUNT()-tick)>1000*TICK_PER_MS)
        {
            uint8_t data[2];
            uint8_t reg=0x00;

            WATCHDOG_TimerClear();
            i2c_writeNBytes(0x48, &reg, 1);
            i2c_readNBytes(0x48, &data[0], 2);

            int32_t tmp;
            float temper;

            tmp=data[0];
            tmp<<=8;
            tmp|=data[1];

            if(tmp&0x8000) // Temperature<0
            {
                tmp>>=7;// 9bit mode
                tmp-=512;
                temper=tmp;
                temper*=0.5f;
            }
            else // Temperature>0
            {
                tmp>>=7;
                temper=tmp;
                temper*=0.5f;
            }

            printf("\nT=%.1f%cC\n", temper, 0xB0);
            tick=_CP0_GET_COUNT();
        }
    }

    return 1;
}
