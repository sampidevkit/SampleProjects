#include "mcc_generated_files/mcc.h"
#include "Debug.h"

void main(void)
{
    uint16_t Count=0;
    
    SYSTEM_Initialize();
    Debug_Init();

    while (1)
    {
        __delay_ms(500);
        __db("\nSoft UART, %s-%s, ", __DATE__, __TIME__);
        __db("%04X", Count++);
        __delay_ms(500);
    }
}