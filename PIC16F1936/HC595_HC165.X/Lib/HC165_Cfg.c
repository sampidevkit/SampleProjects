#include "HC165.h"
#include "spi.h"
#include "pin_manager.h"

void HC165_Spi_Open(void)
{
    SPI_Open(MASTER3_CONFIG);
}

void HC165_Spi_Close(void)
{
    SPI_Close();
}

uint8_t HC165_Spi_Read(void)
{
    return SPI_ExchangeByte(0);
}

void HC165_NCS_SetState(bool x)
{
    if(x)
        IN_CS_SetHigh();
    else
        IN_CS_SetLow();
}

void HC165_NLD_SetState(bool x)
{
    if(x)
        IN_LD_SetHigh();
    else
        IN_LD_SetLow();
}
