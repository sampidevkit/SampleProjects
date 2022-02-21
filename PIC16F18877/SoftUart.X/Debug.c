#include <xc.h>
#include "Debug.h"

#define __bit_delay() _delay((unsigned long)(104*SYS_CLOCK)/4000000) // 9600bps

void Debug_Init(void)
{
    ANSELBbits.ANSB5=0;
    ODCONBbits.ODCB5=1;
    LATBbits.LATB5=1;
    TRISBbits.TRISB5=0;
}

void Debug_Putc(char c)
{
    char i;

    LATBbits.LATB5=0;
    TRISBbits.TRISB5=0;
    __bit_delay();

    for(i=0; i<8; i++)
    {
        if(c&1)
            LATBbits.LATB5=1;
        else
            LATBbits.LATB5=0;

        c>>=1;
        __bit_delay();
    }

    LATBbits.LATB5=1;
    __bit_delay();
    TRISBbits.TRISB5=1;
}

void Debug_Puts(const char *s)
{
    while(*s!=0x00)
        Debug_Putc(*s++);
}

#ifdef USE_STDIO
void putch(char txData)
{
    Debug_Putc(txData);
}
#endif