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

// get/set STT_LED aliases
#define STT_LED_SetHigh()            (PORTCbits.RC0 = 1)
#define STT_LED_SetLow()             (PORTCbits.RC0 = 0)
#define STT_LED_Toggle()             (PORTCbits.RC0 ^= 1)
#define STT_LED_GetValue()           PORTCbits.RC0
#define STT_LED_SetDigitalInput()    (TRISCbits.TRISC0 = 1)
#define STT_LED_SetDigitalOutput()   (TRISCbits.TRISC0 = 0)

// get/set STT_LED aliases

#define NCS_SetHigh()               (PORTCbits.RC2 = 1)
#define NCS_SetLow()                (PORTCbits.RC2 = 0)
#define NCS_Toggle()                (PORTCbits.RC2 ^= 1)
#define NCS_GetValue()              PORTCbits.RC2
#define NCS_SetDigitalInput()       (TRISCbits.TRISC2 = 1)
#define NCS_SetDigitalOutput()      (TRISCbits.TRISC2 = 0)

// get/set SCK procedures
#define SCK_SetHigh()                   (PORTCbits.RC3 = 1)
#define SCK_SetLow()                    (PORTCbits.RC3 = 0)
#define SCK_Toggle()                    (PORTCbits.RC3 ^= 1)
#define SCK_GetValue()                  PORTCbits.RC3
#define SCK_SetDigitalInput()           (TRISCbits.TRISC3 = 1)
#define SCK_SetDigitalOutput()          (TRISCbits.TRISC3 = 0)

// get/set SDI procedures
#define SDI_SetHigh()                   (PORTCbits.RC4 = 1)
#define SDI_SetLow()                    (PORTCbits.RC4 = 0)
#define SDI_Toggle()                    (PORTCbits.RC4 ^= 1)
#define SDI_GetValue()                  PORTCbits.RC4
#define SDI_SetDigitalInput()           (TRISCbits.TRISC4 = 1)
#define SDI_SetDigitalOutput()          (TRISCbits.TRISC4 = 0)

// get/set SDO procedures
#define SDO_SetHigh()                   (PORTCbits.RC5 = 1)
#define SDO_SetLow()                    (PORTCbits.RC5 = 0)
#define SDO_Toggle()                    (PORTCbits.RC5 ^= 1)
#define SDO_GetValue()                  PORTCbits.RC5
#define SDO_SetDigitalInput()           (TRISCbits.TRISC5 = 1)
#define SDO_SetDigitalOutput()          (TRISCbits.TRISC5 = 0)

void PIN_MANAGER_Initialize(void);
void PIN_MANAGER_IOC(void);

#endif