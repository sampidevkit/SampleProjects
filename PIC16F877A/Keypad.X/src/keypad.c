#include "libcomp.h"
#include "keypad.h"

static uint8_t DoNext;

void Keypad_Init(void)
{
    DoNext=0;
}

static uint8_t GetRowValue(void)
{
    uint8_t value=!KB_ROW3_GetValue();

    value<<=1;
    value|=!KB_ROW2_GetValue();
    value<<=1;
    value|=!KB_ROW1_GetValue();
    value<<=1;
    value|=!KB_ROW0_GetValue();

    return value;
}

uint16_t Keypad_Task(void)
{
    static uint8_t Count=0;
    static uint16_t rslt=0;
    static key_t KeyLog, preKey;
    
    switch(DoNext)
    {
        case 1:
            preKey.val=0;
            KB_COL1_SetDigitalInput();
            KB_COL2_SetDigitalInput();
            KB_COL0_SetLow();
            DoNext=2;
            break;

        case 3:
            KB_COL0_SetDigitalInput();
            KB_COL2_SetDigitalInput();
            KB_COL1_SetLow();
            DoNext=4;
            break;

        case 5:
            KB_COL0_SetDigitalInput();
            KB_COL1_SetDigitalInput();
            KB_COL2_SetLow();
            DoNext=6;
            break;

        //case 0:
        //case 2:
        //case 4:
        //case 6:
        default:
            if(DoNext==2)
                preKey.Col0=GetRowValue();
            else if(DoNext==4)
                preKey.Col1=GetRowValue();
            else if(DoNext==6)
            {
                DoNext=0;
                preKey.Col2=GetRowValue();

                if(preKey.val>0)
                {
                    if(KeyLog.val==0)
                    {
                        Count=0;
                        KeyLog.val=preKey.val;
                    }
                    else if(preKey.val!=KeyLog.val)
                        KeyLog.val=0;
                    else if(Count<100) // press and hold >=100 operation cycles
                        Count++;
                    else
                        rslt=KeyLog.val;
                }
                else
                {
                    KeyLog.val=0;
                    rslt=0;
                }
                
                __delay_ms(5);// test only
            }
            // discharge
            KB_COL0_SetHigh();
            KB_COL1_SetHigh();
            KB_COL2_SetHigh();
            KB_COL0_SetDigitalOutput();
            KB_COL1_SetDigitalOutput();
            KB_COL2_SetDigitalOutput();
            DoNext++;
            break;
    }

    return rslt;
}