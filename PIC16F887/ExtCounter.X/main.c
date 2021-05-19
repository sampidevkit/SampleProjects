#include <16F887.h>
#device ADC=10
#use delay(internal=8MHz)
#use FIXED_IO(D_outputs=PIN_D6,PIN_D5,PIN_D4,PIN_D3,PIN_D2,PIN_D1,PIN_D0)
#include <stdint.h>

volatile uint8_t PreCount=0; // present value
static uint8_t PrvCount=0; // previous value

#INT_EXT

void EXT_isr(void)
{
    PreCount++;
}

void display(uint8_t value)
{
    static const uint8_t digit_CC[18]={
        //0   1     2     3     4     5     6     7     8     9
        0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x27, 0x7F, 0x6F,
        //A   b     c     d     E     F     .     <Off>
        0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71, 0x80, 0x00
    }; //digit[16] is DOT

    value&=0x0F; // value=[0:F]
    output_d(digit_CC[value]);
}

void main(void)
{
    port_b_pullups(0x01);// prevent RB0 from float state
    display(PreCount);
    enable_interrupts(INT_EXT);
    enable_interrupts(GLOBAL);

    while(TRUE)
    {
        if(PrvCount!=PreCount)
        {
            display(PreCount);
            PrvCount=PreCount;
        }
    }

}
