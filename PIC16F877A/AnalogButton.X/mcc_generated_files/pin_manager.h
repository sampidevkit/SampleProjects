#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UPABLED      1
#define PULL_UP_DISABLED     0

// get/set STT_LED aliases
#define STT_LED_SetHigh()               (PORTCbits.RC0 = 1)
#define STT_LED_SetLow()                (PORTCbits.RC0 = 0)
#define STT_LED_Toggle()                (PORTCbits.RC0 ^= 1)
#define STT_LED_GetValue()              PORTCbits.RC0
#define STT_LED_SetDigitalInput()       (TRISCbits.TRISC0 = 1)
#define STT_LED_SetDigitalOutput()      (TRISCbits.TRISC0 = 0)

// get/set LED1 aliases
#define LED1_SetHigh()            (PORTDbits.RD0 = 1)
#define LED1_SetLow()             (PORTDbits.RD0 = 0)
#define LED1_Toggle()             (PORTDbits.RD0 ^= 1)
#define LED1_GetValue()           PORTDbits.RD0
#define LED1_SetDigitalInput()    (TRISDbits.TRISD0 = 1)
#define LED1_SetDigitalOutput()   (TRISDbits.TRISD0 = 0)

// get/set LED2 aliases
#define LED2_SetHigh()            (PORTDbits.RD1 = 1)
#define LED2_SetLow()             (PORTDbits.RD1 = 0)
#define LED2_Toggle()             (PORTDbits.RD1 ^= 1)
#define LED2_GetValue()           PORTDbits.RD1
#define LED2_SetDigitalInput()    (TRISDbits.TRISD1 = 1)
#define LED2_SetDigitalOutput()   (TRISDbits.TRISD1 = 0)

// get/set LED3 aliases
#define LED3_SetHigh()            (PORTDbits.RD2 = 1)
#define LED3_SetLow()             (PORTDbits.RD2 = 0)
#define LED3_Toggle()             (PORTDbits.RD2 ^= 1)
#define LED3_GetValue()           PORTDbits.RD2
#define LED3_SetDigitalInput()    (TRISDbits.TRISD2 = 1)
#define LED3_SetDigitalOutput()   (TRISDbits.TRISD2 = 0)

// get/set LED4 aliases
#define LED4_SetHigh()            (PORTDbits.RD3 = 1)
#define LED4_SetLow()             (PORTDbits.RD3 = 0)
#define LED4_Toggle()             (PORTDbits.RD3 ^= 1)
#define LED4_GetValue()           PORTDbits.RD3
#define LED4_SetDigitalInput()    (TRISDbits.TRISD3 = 1)
#define LED4_SetDigitalOutput()   (TRISDbits.TRISD3 = 0)

// get/set LED5 aliases
#define LED5_SetHigh()            (PORTDbits.RD4 = 1)
#define LED5_SetLow()             (PORTDbits.RD4 = 0)
#define LED5_Toggle()             (PORTDbits.RD4 ^= 1)
#define LED5_GetValue()           PORTDbits.RD4
#define LED5_SetDigitalInput()    (TRISDbits.TRISD4 = 1)
#define LED5_SetDigitalOutput()   (TRISDbits.TRISD4 = 0)

// get/set LED6 aliases
#define LED6_SetHigh()            (PORTDbits.RD5 = 1)
#define LED6_SetLow()             (PORTDbits.RD5 = 0)
#define LED6_Toggle()             (PORTDbits.RD5 ^= 1)
#define LED6_GetValue()           PORTDbits.RD5
#define LED6_SetDigitalInput()    (TRISDbits.TRISD5 = 1)
#define LED6_SetDigitalOutput()   (TRISDbits.TRISD5 = 0)

void PIN_MANAGER_Initialize(void);
void PIN_MANAGER_IOC(void);

#endif