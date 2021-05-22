#include "libcomp.h"

typedef struct
{
    uint16_t min;
    uint16_t max;
} range_t;

const range_t AdcRange[6]={
    // min, max, Rbottom=10KOhm
    {921, 940}, // button 1, RTop=1KOhm
    {830, 847}, // button 2, RTop=2.2KOhm
    {689, 703}, // button 3, RTop=4.7KOhm
    {506, 517}, // button 4, RTop=10KOhm
    {405, 413}, // button 5, RTop=15KOhm
    {316, 323} // button 6, RTop=22KOhm
};

bool ANALOGBUTTON_GetState(uint8_t Idx)
{
    uint16_t adcVal=ADC_GetValOnChannel(ADC_AN0);
    //__delay_us(100);
    if((adcVal>=AdcRange[Idx].min)&&(adcVal<=AdcRange[Idx].max))
        return 0;

    return 1;
}

bool BUTTON1_GetState(void)
{
    return ANALOGBUTTON_GetState(0);
}

bool BUTTON2_GetState(void)
{
    return ANALOGBUTTON_GetState(1);
}

bool BUTTON3_GetState(void)
{
    return ANALOGBUTTON_GetState(2);
}

bool BUTTON4_GetState(void)
{
    return ANALOGBUTTON_GetState(3);
}

bool BUTTON5_GetState(void)
{
    return ANALOGBUTTON_GetState(4);
}

bool BUTTON6_GetState(void)
{
    return ANALOGBUTTON_GetState(5);
}

void main(void)
{
    tick_timer_t Tick;
    button_t Bt1, Bt2, Bt3, Bt4, Bt5, Bt6;

    // System initialize
    SYSTEM_Initialize();
    Tick_Timer_Init();
    // Application initialize
    Button_Init(&Bt1, BUTTON1_GetState, TIME_MODE_EDGE_H2L, 250); // press and hold at least 250ms
    Button_Init(&Bt2, BUTTON2_GetState, TIME_MODE_EDGE_H2L, 250); // press and hold at least 250ms
    Button_Init(&Bt3, BUTTON3_GetState, TIME_MODE_EDGE_H2L, 250); // press and hold at least 250ms
    Button_Init(&Bt4, BUTTON4_GetState, TIME_MODE_EDGE_H2L, 250); // press and hold at least 250ms
    Button_Init(&Bt5, BUTTON5_GetState, TIME_MODE_EDGE_H2L, 250); // press and hold at least 250ms
    Button_Init(&Bt6, BUTTON6_GetState, TIME_MODE_EDGE_H2L, 1000); // press and hold at least 1000ms
    Tick_Timer_Reset(Tick);
    // Interrupt enable
    Enable_Peripheral_Interrupt();
    Enable_Global_Interrupt();

    while(1)
    {
        if(Tick_Timer_Is_Over_Ms(Tick, 500))
            STT_LED_Toggle();

        if(Button_Is_Pressed(&Bt1))
            LED1_Toggle();

        if(Button_Is_Pressed(&Bt2))
            LED2_Toggle();

        if(Button_Is_Pressed(&Bt3))
            LED3_Toggle();

        if(Button_Is_Pressed(&Bt4))
            LED4_Toggle();

        if(Button_Is_Pressed(&Bt5))
            LED5_Toggle();

        if(Button_Is_Pressed(&Bt6))
            LED6_Toggle();
    }
}
