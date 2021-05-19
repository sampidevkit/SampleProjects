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
#define STT_LED_SetHigh()                   (PORTCbits.RC0 = 1)
#define STT_LED_SetLow()                    (PORTCbits.RC0 = 0)
#define STT_LED_Toggle()                    (PORTCbits.RC0 ^= 1)
#define STT_LED_GetValue()                  PORTCbits.RC0
#define STT_LED_SetDigitalInput()           (TRISCbits.TRISC0 = 1)
#define STT_LED_SetDigitalOutput()          (TRISCbits.TRISC0 = 0)

// get/set PWM1 aliases
#define PWM1_SetHigh()                      (PORTCbits.RC2 = 1)
#define PWM1_SetLow()                       (PORTCbits.RC2 = 0)
#define PWM1_Toggle()                       (PORTCbits.RC2 ^= 1)
#define PWM1_GetValue()                     PORTCbits.RC2
#define PWM1_SetDigitalInput()              (TRISCbits.TRISC2 = 1)
#define PWM1_SetDigitalOutput()             (TRISCbits.TRISC2 = 0)

// get/set THERMAL_SENSOR aliases
#define THERMAL_SENSOR_SetHigh()            (PORTAbits.RA0 = 1)
#define THERMAL_SENSOR_SetLow()             (PORTAbits.RA0 = 0)
#define THERMAL_SENSOR_Toggle()             (PORTAbits.RA0 ^= 1)
#define THERMAL_SENSOR_GetValue()           PORTAbits.RA0
#define THERMAL_SENSOR_SetDigitalInput()    (TRISAbits.TRISA0 = 1)
#define THERMAL_SENSOR_SetDigitalOutput()   (TRISAbits.TRISA0 = 0)

void PIN_MANAGER_Initialize(void);

#endif