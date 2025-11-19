#include "HC595.h"
#include "spi.h"
#include "pin_manager.h"

void HC595_Spi_Open(void)
{
    SPI_Open(MASTER0_CONFIG);
}

void HC595_Spi_Close(void)
{
    SPI_Close();
}

void HC595_Spi_Write(uint8_t b)
{
    SPI_ExchangeByte(b);
}

void HC595_NMR_SetState(bool x)
{

}

void HC595_NOE_SetState(bool x)
{

}

void HC595_NCS_SetState(bool x)
{
    if(x)
        OUT_CS_SetHigh();
    else
        OUT_CS_SetLow();
}
