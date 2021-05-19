#include "libcomp.h"

void DbWriteStr(const char *pd)
{
    while(*pd!=0x00)
    {
        while(TXSTAbits.TRMT==0);
        TXREG=*pd;
        pd++;
    }
}

void DbBcd2Hex(uint8_t i)
{
    i&=0x0F;

    if(i<10)
        i+='0';
    else
    {
        i-=10;
        i+='A';
    }

    while(TXSTAbits.TRMT==0);
    TXREG=i;
}

void DbLong2Hex(int32_t v)
{
    uint8_t i, j;

    for(i=0; i<8; i++)
    {
        j=(uint8_t) (v>>28);
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

void DbShort2Hex(int16_t v)
{
    uint8_t i, j;

    for(i=0; i<4; i++)
    {
        j=(uint8_t) (v>>12);
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

void DbByte2Hex(int8_t v)
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
