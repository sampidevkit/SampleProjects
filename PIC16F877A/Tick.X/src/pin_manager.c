#include "libcomp.h"
#include "pin_manager.h"

void PIN_MANAGER_Initialize(void)
{
    PORTA=0x00;
    PORTB=0x00;
    PORTC=0x00;
    PORTD=0x00;
    PORTE=0x00;

    TRISA=0xFF;
    TRISB=0xFF;
    TRISC=0xFF;
    TRISD=0xFF;
    TRISE=0x00;
    // Off ADC
    ADCON0=0x00;
    ADCON1=0x06;
    // No RBU
    OPTION_REG|=0b10000000;
}