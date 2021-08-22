#include <16F877A.h>
#device ADC=10
#use delay(crystal=20MHz)
#use FIXED_IO(D_outputs=PIN_D3, PIN_D2, PIN_D1, PIN_D0)
#use FIXED_IO(B_outputs=PIN_B7, PIN_B6, PIN_B5, PIN_B4, PIN_B3, PIN_B2, PIN_B1, PIN_B0)

#define BT_UP                       PIN_D6
#define BT_DOWN                     PIN_D7
#define BUTTON_DELAY_CYCLES         10

#include "../../Library/Buttons_CCS.c"

#define NUM_OF_7SEG_DIGIT           4
#define USE_LED_7SEG_CA             1 // Common anode
#define LED_7SEG_TOGGLE_COUNT       100

#define Led7Seg_Digit_Disable()     output_d(0x00)
#define Led7Seg_Segment_Disable()   output_b(0xFF)
#define Led7Seg_Segment_SetState(x) output_b(x)
#define Led7Seg_Digit_SetState(x)   output_d(~(1<<x))

#include "../../Library/Led7Seg_CCS.c"

#INT_TIMER1

void TMR1_Isr(void)
{
    set_timer1(55535); // ~2ms overflow
    Led7Seg_Tasks();
}

void main(void)
{
    signed int16 Count=9995;
    bt_t BtUp, BtDown;

    Button_Init(BtUp);
    Button_Init(BtDown);
    Led7Seg_Init();
    Led7Seg_DisplayInteger(Count);
    setup_timer_1(T1_INTERNAL|T1_DIV_BY_1);
    set_timer1(55535); // ~2ms overflow
    enable_interrupts(INT_TIMER1);
    enable_interrupts(PERIPH);
    enable_interrupts(GLOBAL);
    Led7Seg_SetDigitValue(0, 0b10001100); // P
    Led7Seg_SetDigitValue(1, 0b11001111); // I
    Led7Seg_SetDigitValue(2, 0b11000110); // C
    Led7Seg_SetDigitValue(3, 0b11000110); // C
    delay_ms(1000);
    Led7Seg_DisplayInteger(Count);
    
    while(TRUE)
    {
        if(Button_Is_Pressed(&BtUp, BT_UP))
        {
            if(++Count>9999)
                Count=0;

            Led7Seg_DisplayInteger(Count);
        }

        if(Button_Is_Pressed(&BtDown, BT_DOWN))
        {
            if(--Count<0)
                Count=9999;

            Led7Seg_DisplayInteger(Count);
        }
    }
}
