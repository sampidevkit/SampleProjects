#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#define INPUT                       1
#define OUTPUT                      0

#define HIGH                        1
#define LOW                         0

#define ANALOG                      1
#define DIGITAL                     0

#define PULL_UP_ENABLED             1
#define PULL_UP_DISABLED            0

// get/set LED1 aliases
#define LED1_TRIS                TRISEbits.TRISE0
#define LED1_PORT                PORTEbits.RE0
#define LED1_SetHigh()           PORTEbits.RE0=1
#define LED1_SetLow()            PORTEbits.RE0=0
#define LED1_Toggle()            PORTEbits.RE0^=1
#define LED1_GetValue()          PORTEbits.RE0
#define LED1_SetDigitalInput()   TRISEbits.TRISE0=1
#define LED1_SetDigitalOutput()  TRISEbits.TRISE0=0

// get/set LED2 aliases
#define LED2_TRIS                TRISEbits.TRISE1
#define LED2_PORT                PORTEbits.RE1
#define LED2_SetHigh()           PORTEbits.RE1=1
#define LED2_SetLow()            PORTEbits.RE1=0
#define LED2_Toggle()            PORTEbits.RE1^=1
#define LED2_GetValue()          PORTEbits.RE1
#define LED2_SetDigitalInput()   TRISEbits.TRISE1=1
#define LED2_SetDigitalOutput()  TRISEbits.TRISE1=0

// get/set LED3 aliases
#define LED3_TRIS                TRISEbits.TRISE2
#define LED3_PORT                PORTEbits.RE2
#define LED3_SetHigh()           PORTEbits.RE2=1
#define LED3_SetLow()            PORTEbits.RE2=0
#define LED3_Toggle()            PORTEbits.RE2^=1
#define LED3_GetValue()          PORTEbits.RE2
#define LED3_SetDigitalInput()   TRISEbits.TRISE2=1
#define LED3_SetDigitalOutput()  TRISEbits.TRISE2=0

void PIN_MANAGER_Initialize(void);

#endif