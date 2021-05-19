#include "mcc_generated_files/mcc.h"

#define __debug(msg, val)    do{DbWriteStr(msg); DbByte2Hex(val);}while(0)

void DbWriteStr(const char *pd)
{
    while(*pd!=0x00)
    {
        while(TXSTAbits.TRMT==0);
        TXREG=*pd;
        pd++;
    }
}

void DbByte2Hex(uint8_t v)
{
    uint8_t i, j;

    for(i=0; i<2; i++)
    {
        j=(uint8_t) (v>>4);
        j&=0x0F;

        if(j<10)
            j+='0';
        else
        {
            j-=10;
            j+='A';
        }

        while(TXSTAbits.TRMT==0);
        TXREG=j;
        v<<=4;
    }
}

void Display_State(uint8_t idx, bool stt)
{
    DbWriteStr("\nLED ");
    DbByte2Hex(idx);

    if(stt)
        DbWriteStr(": ON");
    else
        DbWriteStr(": OFF");
}

void processButtonTouch(enum mtouch_button_names button)
{
    switch(button)
    {
#if(MTOUCH_BUTTONS>=1)
        case Button0: LED0_SetLow();
            break;
#endif

#if(MTOUCH_BUTTONS>=2)
        case Button1: LED1_SetLow();
            break;
#endif

#if(MTOUCH_BUTTONS>=3)
        case Button2: LED2_SetLow();
            break;
#endif

#if(MTOUCH_BUTTONS>=4)
        case Button3: LED3_SetLow();
            break;
#endif

#if(MTOUCH_BUTTONS>=5)
        case Button4: LED4_SetLow();
            break;
#endif

#if(MTOUCH_BUTTONS>=6)
        case Button5: LED5_SetLow();
            break;
#endif

        default: break;
    }
}

void processButtonRelease(enum mtouch_button_names button)
{
    switch(button)
    {
#if(MTOUCH_BUTTONS>=1)
        case Button0: LED0_SetHigh();
            break;
#endif

#if(MTOUCH_BUTTONS>=2)
        case Button1: LED1_SetHigh();
            break;
#endif

#if(MTOUCH_BUTTONS>=3)
        case Button2: LED2_SetHigh();
            break;
#endif

#if(MTOUCH_BUTTONS>=4)
        case Button3: LED3_SetHigh();
            break;
#endif

#if(MTOUCH_BUTTONS>=5)
        case Button4: LED4_SetHigh();
            break;
#endif

#if(MTOUCH_BUTTONS>=6)
        case Button5: LED5_SetHigh();
            break;
#endif
        default: break;
    }
}

void main(void)
{
    SYSTEM_Initialize();
    DbWriteStr("\nSTART\n");
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
    MTOUCH_Button_SetPressedCallback(processButtonTouch);
    MTOUCH_Button_SetNotPressedCallback(processButtonRelease);

    while(1)
    {
        CLRWDT();
        MTOUCH_Service_Mainloop();
    }
}