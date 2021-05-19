#ifndef MAX7219_CFG_H
#define MAX7219_CFG_H

#define NUM_OF_MAX7219              2
#define MAX7219_LOAD_Enable()       (PORTCbits.RC2=0)
#define MAX7219_LOAD_Disable()      (PORTCbits.RC2=1)

#ifndef USE_SW_SPI
#define MAX7219_Xfer(x)             SPI1_ExchangeByte(x)
#else
// This IO connects to CLK pin of MAX7219
#define MAX7219_CLK_SetHigh()       (PORTCbits.RC3=1)
#define MAX7219_CLK_SetLow()        (PORTCbits.RC3=0)
// This IO connects to DIN pin of MAX7219
#define MAX7219_DIN_SetHigh()       (PORTCbits.RC5=1)
#define MAX7219_DIN_SetLow()        (PORTCbits.RC5=0)
// This IO connects to DOUT pin of MAX7219
#define MAX7219_DOUT_GetValue()     PORTCbits.RC4
#endif

#endif