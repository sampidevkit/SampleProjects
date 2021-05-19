#include "spi1.h"
#include <xc.h>

void SPI1_Initialize(void)
{
    SSPCONbits.SSPEN=0;
    SSPSTAT=0b01000000;
    SSPCON=0b00010010;
    SSPADD=0b00000000;
    SSPCONbits.SSPEN=1;
}

uint8_t SPI1_ExchangeByte(uint8_t data)
{
    SSPCONbits.WCOL=0;
    SSPBUF=data;
    while(!PIR1bits.SSPIF);
    PIR1bits.SSPIF=0;
    
    return SSPBUF;
}