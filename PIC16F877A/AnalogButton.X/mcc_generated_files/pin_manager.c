#include "pin_manager.h"

void PIN_MANAGER_Initialize(void)
{
    PORTA=0b11111111;
    PORTC=0b11111110;
    PORTD=0b11000000;
    
    TRISA=0b11111111;
    TRISC=0b11111110;
    TRISD=0b11000000;
}

void PIN_MANAGER_IOC(void)
{
}