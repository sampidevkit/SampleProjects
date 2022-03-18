#include "mcc_generated_files/mcc.h"

bool Button_is_pressed(void) // <editor-fold defaultstate="collapsed" desc="Check button">
{
    static bool prv_state=1;
    static uint16_t count=0;

    if(prv_state!=BT_N_GetValue())
    {
        if(prv_state==1)
        {
            if(++count>200) // check in 200 cycles
            {
                prv_state=0;
                return 1;
            }
        }
        else
            prv_state=1;
    }
    else
        count=0;

    return 0;
} // </editor-fold>

uint16_t Random(uint16_t min, uint16_t max) // <editor-fold defaultstate="collapsed" desc="Get random number">
{
    uint32_t rnd=(uint32_t)TMR0_ReadTimer();

    rnd*=((max-min)+1);
    rnd/=65536;
    rnd+=min;

    return (uint16_t) rnd;
} // </editor-fold>

void main(void)
{
    SYSTEM_Initialize();
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
    printf("\nINTERNAL EEPROM DEMO\n");

    while(1)
    {
        CLRWDT();

        if(Button_is_pressed())
        {
            uint8_t data1, data2;
            uint16_t addr;

            BLED_SetHigh();
            data1=(uint8_t) Random(0, 255);
            addr=Random(0xF000, 0xF0FF);
            DATAEE_WriteByte(addr, data1);
            //__delay_ms(5);
            printf("\nEEPROM write at ");
            printf("%04X: %02X ", addr, data1);
            data2=DATAEE_ReadByte(addr);

            if(data1!=data2)
                printf("# %02X", data2);
            else
                printf("success");

            BLED_SetLow();
        }
        
        __delay_ms(1);
    }
}