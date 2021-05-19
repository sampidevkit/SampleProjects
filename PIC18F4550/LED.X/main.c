#include "mcc_generated_files/mcc.h"

#define TICK_PER_MS     15 // FOSC/4/TMR0_Prescaler/1000  
#define Tick_Reset(cxt) cxt.Over=1

typedef struct
{
    bool Over;
    uint16_t Begin;
    uint16_t End;
} tick_t;

bool Tick_Is_TimedOut(tick_t *pTick, uint16_t ms) // <editor-fold defaultstate="collapsed" desc="Check timeout">
{
    if(pTick->Over==1)
    {
        pTick->Begin=TMR0_ReadTimer();
        pTick->End=ms*TICK_PER_MS;
        pTick->Over=0;
    }

    if((TMR0_ReadTimer()-pTick->Begin)>=pTick->End)
        pTick->Over=1;

    return pTick->Over;
} // </editor-fold>

bool BT_UP_Is_Pressed(void) // <editor-fold defaultstate="collapsed" desc="Button UP">
{
    static bool prv=1;
    static uint8_t t=0;

    if(prv!=BT_UP_GetValue())
    {
        if(prv==1)
        {
            if(++t>100) // check 100 cycles
            {
                prv=0;
                return 1;
            }
        }
        else
            prv=1;
    }
    else if(t>0)
        t=0;

    return 0;
} // </editor-fold>

bool BT_DOWN_Is_Pressed(void) // <editor-fold defaultstate="collapsed" desc="Button DOWN">
{
    static bool prv=1;
    static uint8_t t=0;

    if(prv!=BT_DOWN_GetValue())
    {
        if(prv==1)
        {
            if(++t>100) // check 100 cycles
            {
                prv=0;
                return 1;
            }
        }
        else
            prv=1;
    }
    else if(t>0)
        t=0;

    return 0;
} // </editor-fold>

/* ************************************************************* Hieu Ung Led */

void SingleLED_Task(void) // <editor-fold defaultstate="collapsed" desc="Single LED task">
{
    static tick_t TickSLed={1, 0, 0};
    static uint8_t i=0, Next=0, left=0, right=0;

    if(Tick_Is_TimedOut(&TickSLed, 100))
    {
        i++;

        switch(Next)
        {
            case 0:
                LATD=0b00000001;
                Next=1;
                break;

            case 1:// Dich trai
                LATD<<=1;

                if(i==8)
                {
                    i=0;
                    Next=2;
                }
                break;

            case 2: // Dich phai
                LATD>>=1;

                if(i==8)
                {
                    i=0;
                    Next=3;
                }
                break;

            case 3: // Sang dan ben trai
                LATD=(unsigned char) (LATD<<1)|1;

                if(i==8)
                {
                    i=0;
                    Next=4;
                }
                break;

            case 4: // Tat dan ben trai
                LATD<<=1;

                if(i==8)
                {
                    i=0;
                    Next=5;
                }
                break;

            case 5: // Sang dan ben phai
                LATD=(LATD>>1)|0x80;

                if(i==8)
                {
                    i=0;
                    Next=6;
                }
                break;

            case 6: // Tat dan ben phai
                LATD>>=1;

                if(i==8)
                {
                    i=0;
                    Next=7;
                    left=0x80;
                    right=0x01;
                }
                break;

            case 7: // 2 ben dich vao trong
                LATD=left|right;
                left>>=1;
                right<<=1;

                if(i==4)
                {
                    i=0;
                    Next=8;
                    left=0b00010000;
                    right=0b00001000;
                }
                break;

            case 8: // 2 ben dich ra ngoai
                LATD=left|right;
                left<<=1;
                right>>=1;

                if(i==4)
                {
                    i=0;
                    Next=9;
                    left=0b10000000;
                    right=0b00000001;
                }
                break;

            case 9: // 2 ben sang dan vao trong
                LATD=left|right;
                left=(left>>1)|0x80;
                right=(uint8_t) (right<<1)|0x01;

                if(i==4)
                {
                    i=0;
                    Next=10;
                    left=0b11100000;
                    right=0b00000111;
                }
                break;

            case 10: // 2 ben tat dan ra ngoai
                LATD=left|right;
                left<<=1;
                right>>=1;

                if(i==4)
                {
                    i=0;
                    Next=11;
                    left=0b00010000;
                    right=0b00001000;
                }
                break;

            case 11: // 2 ben sang dan ra ngoai
                LATD=left|right;
                left=(uint8_t) (left<<1)|0b00010000;
                right=(right>>1)|0b00001000;

                if(i==4)
                {
                    i=0;
                    Next=12;
                    left=0b11110000;
                    right=0b00001111;
                }
                break;

            case 12: // 2 ben tat dan vao trong
                LATD=left|right;
                left=(left>>1)&0b11110000;
                right=(right<<1)&0b00001111;

                if(i==4)
                {
                    i=0;
                    Next=0;
                }
                break;

            default:
                break;
        }
    }
} // </editor-fold>

/* ***************************************************************** Quet Led */
static const uint8_t digit_CA[17]={
    0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xD8, 0x80, 0x90,
    0x88, 0x83, 0xC6, 0xA1, 0x86, 0x8E, 0x7F
}; //digit[16] is DOT

//static const uint8_t digit_CC[17]={
//    0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x27, 0x7F, 0x6F,
//    0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71, 0x80
//}; //digit[16] is DOT

void Display(uint8_t value) // <editor-fold defaultstate="collapsed" desc="Scan led">
{
    static bool digit_sel=0;
    static tick_t Tick7Seg={1, 0, 0};

    if(Tick_Is_TimedOut(&Tick7Seg, 10))
    {
        if(digit_sel==0)
        {
            DIGIT2_SetLow();
            digit_sel=1;
            LATB=digit_CA[value/10];
            DIGIT1_SetHigh();
        }
        else
        {
            DIGIT1_SetLow();
            digit_sel=0;
            LATB=digit_CA[value%10];
            DIGIT2_SetHigh();
        }
    }
} // </editor-fold>

void SegmentLED_Task(void) // <editor-fold defaultstate="collapsed" desc="Segment LED Task">
{
    static int8_t Count=95;

    if(BT_UP_Is_Pressed())
    {
        if(++Count>99)
            Count=0;
    }

    if(BT_DOWN_Is_Pressed())
    {
        if(--Count<0)
            Count=99;
    }

    Display((uint8_t) Count);
} // </editor-fold>

void main(void)
{
    SYSTEM_Initialize();
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_GlobalInterruptDisable();

    while(1)
    {
        SingleLED_Task();
        SegmentLED_Task();
    }
}