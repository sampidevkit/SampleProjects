#include "pin_manager.h"

void PIN_MANAGER_Initialize(void)
{
    PORTB=0;
    PORTD=0;
    
    TRISB=0;
    TRISD=0;
}

void PIN_MANAGER_IOC(void)
{
}