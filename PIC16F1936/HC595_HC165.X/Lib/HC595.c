#include "HC595.h"

#define HC595_NMR_SetHigh() HC595_NMR_SetState(1)
#define HC595_NMR_SetLow()  HC595_NMR_SetState(0)
#define HC595_NOE_SetHigh() HC595_NOE_SetState(1)
#define HC595_NOE_SetLow()  HC595_NOE_SetState(0)
#define HC595_NCS_SetHigh() HC595_NCS_SetState(1)
#define HC595_NCS_SetLow()  HC595_NCS_SetState(0)

static uint8_t Hc595Buf[NUM_OF_74HC595];

public void HC595_Write(uint8_t Idx, uint8_t Value) // <editor-fold defaultstate="collapsed" desc="HC595 write">
{
    uint8_t i;

    if(Idx>=NUM_OF_74HC595)
        return;

    HC595_Spi_Open();
    Hc595Buf[Idx]=Value;
    HC595_NCS_SetLow();

    for(i=0; i<NUM_OF_74HC595; i++)
        HC595_Spi_Write(Hc595Buf[i]);

    HC595_NCS_SetHigh();
    HC595_Spi_Close();
} // </editor-fold>

public void HC595_Init(void) // <editor-fold defaultstate="collapsed" desc="HC595 init">
{
    uint8_t i;

    HC595_NCS_SetHigh();
    HC595_NMR_SetHigh(); // Running mode
    HC595_NOE_SetLow(); // Enbale
    memset(Hc595Buf, 0x00, NUM_OF_74HC595);

    for(i=0; i<NUM_OF_74HC595; i++)
        HC595_Write(i, 0x00);
} // </editor-fold>