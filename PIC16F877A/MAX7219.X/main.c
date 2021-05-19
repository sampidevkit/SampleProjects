#include "libcomp.h"

static const max7219_config_t LED0={
    0, // .ChipIdx,
    NO_DECODE_DIGIT7_0, // .Decode,
    MAX_ON, // .Intensity,
    DIGIT0_4, // .ScanLimit,
    NORMAL_MODE// .Shutdown
};

static const max7219_config_t LED1={
    1, // .ChipIdx,
    NO_DECODE_DIGIT7_0, // .Decode,
    MAX_ON, // .Intensity,
    DIGIT0_7, // .ScanLimit,
    NORMAL_MODE// .Shutdown
};

void main(void)
{
    uint16_t dis0_val=0;
    uint32_t dis1_val=0;
    static tick_timer_t Tick={1, 0, 0};

    SYSTEM_Initialize();
    Tick_Timer_Init();
    /* App init */
    MAX7219_Init();
    MAX7219_Config(&LED0);
    MAX7219_Config(&LED1);
    Enable_Peripheral_Interrupt();
    Enable_Global_Interrupt();

    while(1)
    {
        if(Tick_Timer_Is_Over_Ms(Tick, 1000))
        {
            STT_LED_Toggle();
            MAX7219_Display(&LED1, dis1_val);
            MAX7219_Display(&LED0, dis0_val);

            dis0_val+=8;
            dis1_val+=1024;
        }
    }
}
