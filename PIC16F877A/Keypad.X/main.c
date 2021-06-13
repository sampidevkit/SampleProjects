#include "src/libcomp.h"

#define KEY_STRING_LEN  16

#define NOT_PRESS       0
#define NEW_KEY         1
#define CLEAR_KEY       2

static uint8_t KeyDecode(uint16_t keycode)
{
    static const uint8_t codec[]="147*2580369#";

    uint8_t i, j;

    for(i=0, j=255; i<12; i++) // 12 keys
    {
        if(keycode&1)
        {
            if(j==255)
                j=i;
            else
                return 0;
        }

        keycode>>=1;
    }

    if(j!=255)
        return codec[j];

    return 0;
}

uint8_t Keypad_GetString(uint8_t *pBuffer)
{
    static uint8_t idx=0;
    static uint16_t prvkey=0;
    uint16_t tmp=Keypad_Task();

    if(tmp>0)
    {
        if((prvkey!=tmp))
        {
            prvkey=tmp;
            pBuffer[idx]=KeyDecode(tmp);

            if(pBuffer[idx]=='*') // backspace
            {
                pBuffer[idx]=0x00;

                if(idx>0)
                    idx--;

                pBuffer[idx]=0x00;

                return NEW_KEY;
            }

            if(pBuffer[idx]=='#') // clear all
            {
                idx=0;
                prvkey=0;
                memset(pBuffer, 0x00, KEY_STRING_LEN);
                return CLEAR_KEY;
            }

            if(idx<KEY_STRING_LEN)
            {
                idx++;
                return NEW_KEY;
            }
            else
            {
                idx=0;
                prvkey=0;
                memset(pBuffer, 0x00, KEY_STRING_LEN);
                return CLEAR_KEY;
            }
        }
    }
    else
        prvkey=0;

    return NOT_PRESS;
}

void main(void)
{
    uint8_t pwbuf[KEY_STRING_LEN];

    SYSTEM_Initialize();
    Keypad_Init();
    TextLCD_Init(LCD1602);
    TextLCD_Puts(0, 1, "Type string:", LCD_PUT_STRING);
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
    memset(pwbuf, 0x00, KEY_STRING_LEN);

    while(1)
    {
        if(Keypad_GetString(&pwbuf)!=NOT_PRESS)
        {
            TextLCD_ClearLine(1);
            TextLCD_Puts(1, 0, pwbuf, KEY_STRING_LEN);
        }
    }
}