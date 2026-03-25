#include "mcc_generated_files/mcc.h"
#include <avr/wdt.h>
#include <util/delay.h>

int main(void)
{
    SYSTEM_Initialize();
    uint16_t register_address_var=0x0447U; // PORTC TOGGLE REGISTER
    volatile uint8_t *register_pointer;
    register_pointer=(volatile uint8_t *)register_address_var;
    printf("\r\nREGISTER ACCESS TEST");

    while(1)
    {
        wdt_reset();
        *register_pointer|=0x40;
        _delay_ms(100);
    }
}
