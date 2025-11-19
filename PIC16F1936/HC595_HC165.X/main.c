#include "mcc_generated_files/mcc.h"
#include "HC595.h"
#include "HC165.h"

void main(void)
{
    SYSTEM_Initialize();
    HC595_Init();
    HC165_Init();
    HC595_Write(0, 0x55);
    HC595_Write(1, 0x55);
    __delay_ms(1000);

    while(1)
    {
        uint8_t i;

        for(i=0; i<NUM_OF_74HC595; i++)
            HC595_Write(i, HC165_Read(i));
    }
}
