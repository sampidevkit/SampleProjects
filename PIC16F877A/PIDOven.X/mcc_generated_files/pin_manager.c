#include "pin_manager.h"

void PIN_MANAGER_Initialize(void)
{
    PORTA=0b11111111;
    PORTC=0b11111010;

    TRISA=0b11111111;
    TRISC=0b10111010;
}