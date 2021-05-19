#include <xc.h>
#include "eusart.h"

void EUSART_Initialize(void)
{
    // disable interrupts before changing states
    PIE1bits.RCIE=0;
    PIE1bits.TXIE=0;
    RCSTA=0b10000000;
    TXSTA=0b10100000;
    SPBRG=15;
}

bool EUSART_is_tx_ready(void)
{
    return (bool) (PIR1bits.TXIF&&TXSTAbits.TXEN);
}

bool EUSART_is_rx_ready(void)
{
    return (bool) (PIR1bits.RCIF);
}

bool EUSART_is_tx_done(void)
{
    return TXSTAbits.TRMT;
}

uint8_t EUSART_Read(void)
{
    while(!PIR1bits.RCIF);

    if(1==RCSTAbits.OERR)
    {
        RCSTAbits.CREN=0;
        RCSTAbits.CREN=1;
    }

    return RCREG;
}

void EUSART_Write(uint8_t txData)
{
    while(0==PIR1bits.TXIF);
    TXREG=txData; // Write the data byte to the USART.
}