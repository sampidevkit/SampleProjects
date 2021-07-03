#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set LM35 aliases
#define LM35_SetHigh()                (PORTAbits.RA0 = 1)
#define LM35_SetLow()                 (PORTAbits.RA0 = 0)
#define LM35_Toggle()                 (PORTAbits.RA0 ^= 1)
#define LM35_GetValue()               PORTAbits.RA0
#define LM35_SetDigitalInput()        (TRISAbits.TRISA0 = 1)
#define LM35_SetDigitalOutput()       (TRISAbits.TRISA0 = 0)

void PIN_MANAGER_Initialize(void);
void PIN_MANAGER_IOC(void);

#endif