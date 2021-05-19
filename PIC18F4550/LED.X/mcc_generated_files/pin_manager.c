#include "pin_manager.h"

void PIN_MANAGER_Initialize(void)
{
    LATA=0b00000000;
    LATB=0b11111111;
    LATC=0b00000000;
    LATD=0b00000000;
    LATE=0b00000000;
    TRISA=0b01001111;
    TRISB=0b00000000;
    TRISC=0b11111111;
    TRISD=0b00000000;
    TRISE=0b00001111;
    ADCON0=0b00000000; // Turn off ADC module
    ADCON1=0b00001111; // All digital I/O
}