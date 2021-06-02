#include <xc.h>
#include "uart.h"

typedef struct
{
    uint8_t Head;
    uint8_t Tail;
    uint8_t Remain;
    uint8_t Data[UART_TX_BUFFER_SIZE];
} uart_tx_buff_t;

typedef struct
{
    uint8_t Head;
    uint8_t Tail;
    uint8_t Count;
    uint8_t Data[UART_RX_BUFFER_SIZE];
} uart_rx_buff_t;

volatile uart_tx_buff_t TxBuffer;
volatile uart_rx_buff_t RxBuffer;

void UART_Initialize(void)
{
    // disable interrupts before changing states
    PIE1bits.RCIE=0;
    PIE1bits.TXIE=0;
    // SPEN enabled; RX9 8-bit; CREN enabled; ADDEN disabled; SREN disabled; 
    RCSTA=0x90;
    // TX9 8-bit; TX9D 0; SENDB sync_break_complete; TXEN enabled; SYNC asynchronous; BRGH hi_speed; CSRC slave; 
    TXSTA=0x24;
    // SPBRG 51; 
    SPBRG=0x33;
    // SPBRGH 0; 
    SPBRGH=0x00;
    // initializing the driver state
    TxBuffer.Head=0;
    TxBuffer.Tail=0;
    TxBuffer.Remain=UART_TX_BUFFER_SIZE;
    RxBuffer.Head=0;
    RxBuffer.Tail=0;
    RxBuffer.Count=0;
    // enable receive interrupt
    PIE1bits.RCIE=1;
}

uint8_t UART_is_tx_ready(void)
{
    return TxBuffer.Remain;
}

uint8_t UART_is_rx_ready(void)
{
    return RxBuffer.Count;
}

bool UART_is_tx_done(void)
{
    return TXSTAbits.TRMT;
}

uint8_t UART_Read(void)
{
    uint8_t readValue=0;

    while(0==RxBuffer.Count)
        CLRWDT();

    readValue=RxBuffer.Data[RxBuffer.Tail++];

    if(UART_RX_BUFFER_SIZE<=RxBuffer.Tail)
        RxBuffer.Tail=0;

    PIE1bits.RCIE=0;
    RxBuffer.Count--;
    PIE1bits.RCIE=1;

    return readValue;
}

void UART_Write(uint8_t txData)
{
    while(0==TxBuffer.Remain)
        CLRWDT();

    if(0==PIE1bits.TXIE)
        TXREG=txData;
    else
    {
        PIE1bits.TXIE=0;
        TxBuffer.Data[TxBuffer.Head++]=txData;

        if(UART_TX_BUFFER_SIZE<=TxBuffer.Head)
            TxBuffer.Head=0;

        TxBuffer.Remain--;
    }

    PIE1bits.TXIE=1;
}

char getch(void)
{
    return UART_Read();
}

void putch(char txData)
{
    while(!UART_is_tx_ready());
    CLRWDT();
    UART_Write(txData);
}

void UART_Transmit_ISR(void)
{
    PIR1bits.TXIF=0;
    
    if(UART_TX_BUFFER_SIZE>TxBuffer.Remain)
    {
        TXREG=TxBuffer.Data[TxBuffer.Tail++];

        if(UART_TX_BUFFER_SIZE<=TxBuffer.Tail)
            TxBuffer.Tail=0;

        TxBuffer.Remain++;
    }
    else
        PIE1bits.TXIE=0;
}

void UART_Receive_ISR(void)
{
    PIR1bits.RCIF=0;

    if(RCSTAbits.FERR) // frame error
        return;

    if(RCSTAbits.OERR) // overrun error
    {
        RCSTAbits.CREN=0;
        RCSTAbits.CREN=1;
    }

    RxBuffer.Data[RxBuffer.Head++]=RCREG;

    if(UART_RX_BUFFER_SIZE<=RxBuffer.Head)
        RxBuffer.Head=0;

    RxBuffer.Count++;
}