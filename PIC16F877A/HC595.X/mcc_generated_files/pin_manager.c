#include "pin_manager.h"

void PIN_MANAGER_Initialize(void)
{
    PORTC=0b11111111;
    TRISC=0b11010010;
}

void PIN_MANAGER_IOC(void)
{
}