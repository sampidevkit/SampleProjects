#include "AT30TS74.h"
#include "system/system.h"

bool AT30TS74_I2C_writeNByte(uint8_t slvAddr, const uint8_t *pD, uint8_t len)
{
    uint8_t i;

    printf("\r\nWrite 0x%02X: ", slvAddr);

    for(i=0; i<len; i++)
        printf("%02X ", pD[i]);

    I2C1_Host.Write(slvAddr, pD, len);
    while(!I2C1_Host.IsBusy());

    if(I2C1_Host.ErrorGet()==I2C_ERROR_NONE)
    {
        printf(", done");
        return 1;
    }

    printf(", error");
    return 0;
}

bool AT30TS74_I2C_readNByte(uint8_t slvAddr, uint8_t *pD, uint8_t len)
{
    uint8_t i;

    printf("\r\nRead 0x%02X: ", slvAddr);

    I2C1_Host.Read(slvAddr, pD, len);
    while(!I2C1_Host.IsBusy());

    if(I2C1_Host.ErrorGet()==I2C_ERROR_NONE)
    {
        for(i=0; i<len; i++)
            printf("%02X ", pD[i]);

        return 1;
    }

    printf("error");

    return 0;
}

