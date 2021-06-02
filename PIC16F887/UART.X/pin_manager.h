#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#include <xc.h>

#define INPUT                       1
#define OUTPUT                      0

#define HIGH                        1
#define LOW                         0

#define ANALOG                      1
#define DIGITAL                     0

#define PULL_UP_ENABLED             1
#define PULL_UP_DISABLED            0

// get/set LEDx aliases
#define LED_SetHigh(x)              PORTD|=(1<<x)
#define LED_SetLow(x)               PORTD&=~(1<<x)
#define LED_Toggle(x)               PORTD^=(1<<x)
#define LED_GetValue(x)             ((PORTD>>x)&1)
#define LED_SetDigitalInput()       TRISD|=(1<<x)
#define LED_SetDigitalOutput()      TRISD&=~(1<<x)

// get/set MCU_TX procedures
#define MCU_TX_SetHigh()            PORTCbits.RC6=1
#define MCU_TX_SetLow()             PORTCbits.RC6=0
#define MCU_TX_Toggle()             PORTCbits.RC6^=1
#define MCU_TX_GetValue()           PORTCbits.RC6
#define MCU_TX_SetDigitalInput()    TRISCbits.TRISC6=1
#define MCU_TX_SetDigitalOutput()   TRISCbits.TRISC6=0

// get/set MCU_RX procedures
#define MCU_RX_SetHigh()            PORTCbits.RC7=1
#define MCU_RX_SetLow()             PORTCbits.RC7=0
#define MCU_RX_Toggle()             PORTCbits.RC7^=1
#define MCU_RX_GetValue()           PORTCbits.RC7
#define MCU_RX_SetDigitalInput()    TRISCbits.TRISC7=1
#define MCU_RX_SetDigitalOutput()   TRISCbits.TRISC7=0

void PIN_MANAGER_Initialize(void);

#endif