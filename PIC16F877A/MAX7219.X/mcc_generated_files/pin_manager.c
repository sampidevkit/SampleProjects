#include "pin_manager.h"

void PIN_MANAGER_Initialize(void)
{
    PORTC=0b11111111;
    TRISC=0b10010010;
}