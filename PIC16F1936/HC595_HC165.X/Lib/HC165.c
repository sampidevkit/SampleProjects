#include "HC165.h"

#define HC165_NCS_SetHigh() HC165_NCS_SetState(1)
#define HC165_NCS_SetLow()  HC165_NCS_SetState(0)
#define HC165_NLD_SetHigh() HC165_NLD_SetState(1)
#define HC165_NLD_SetLow()  HC165_NLD_SetState(0)

static uint8_t Hc165Buf[NUM_OF_74HC165];

public uint8_t HC165_Read(uint8_t Idx) // <editor-fold defaultstate="collapsed" desc="HC165 read">
{
    uint8_t i;

    if(Idx>=NUM_OF_74HC165)
        return 0;

    HC165_NLD_SetLow();
    HC165_Spi_Open();
    HC165_NLD_SetHigh();
    HC165_NCS_SetLow();

    for(i=0; i<NUM_OF_74HC165; i++)
        Hc165Buf[i]=HC165_Spi_Read();

    HC165_NCS_SetHigh();
    HC165_Spi_Close();

    return Hc165Buf[Idx];
} // </editor-fold>

public void HC165_Init(void) // <editor-fold defaultstate="collapsed" desc="Init">
{
    uint8_t i;

    HC165_NLD_SetHigh();
    HC165_NCS_SetHigh();

    for(i=0; i<NUM_OF_74HC165; i++)
        Hc165Buf[i]=HC165_Read(i);
} // </editor-fold>
