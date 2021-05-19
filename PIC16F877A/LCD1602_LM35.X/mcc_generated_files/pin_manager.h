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
#define STT_LED_SetHigh()               (PORTCbits.RC0 = 1)
#define STT_LED_SetLow()                (PORTCbits.RC0 = 0)
#define STT_LED_Toggle()                (PORTCbits.RC0 ^= 1)
#define STT_LED_GetValue()              PORTCbits.RC0
#define STT_LED_SetDigitalInput()       (TRISCbits.TRISC0 = 1)
#define STT_LED_SetDigitalOutput()      (TRISCbits.TRISC0 = 0)

// get/set TEXTLCD_RS aliases
#define TEXTLCD_RS_SetHigh()            (PORTDbits.RD0 = 1)
#define TEXTLCD_RS_SetLow()             (PORTDbits.RD0 = 0)
#define TEXTLCD_RS_Toggle()             (PORTDbits.RD0 ^= 1)
#define TEXTLCD_RS_GetValue()           PORTDbits.RD0
#define TEXTLCD_RS_SetDigitalInput()    (TRISDbits.TRISD0 = 1)
#define TEXTLCD_RS_SetDigitalOutput()   (TRISDbits.TRISD0 = 0)

// get/set TEXTLCD_EN aliases
#define TEXTLCD_EN_SetHigh()            (PORTDbits.RD1 = 1)
#define TEXTLCD_EN_SetLow()             (PORTDbits.RD1 = 0)
#define TEXTLCD_EN_Toggle()             (PORTDbits.RD1 ^= 1)
#define TEXTLCD_EN_GetValue()           PORTDbits.RD1
#define TEXTLCD_EN_SetDigitalInput()    (TRISDbits.TRISD1 = 1)
#define TEXTLCD_EN_SetDigitalOutput()   (TRISDbits.TRISD1 = 0)

// get/set TEXTLCD_D4 aliases
#define TEXTLCD_D4_SetHigh()            (PORTDbits.RD2 = 1)
#define TEXTLCD_D4_SetLow()             (PORTDbits.RD2 = 0)
#define TEXTLCD_D4_Toggle()             (PORTDbits.RD2 ^= 1)
#define TEXTLCD_D4_GetValue()           PORTDbits.RD2
#define TEXTLCD_D4_SetDigitalInput()    (TRISDbits.TRISD2 = 1)
#define TEXTLCD_D4_SetDigitalOutput()   (TRISDbits.TRISD2 = 0)

// get/set TEXTLCD_D5 aliases
#define TEXTLCD_D5_SetHigh()            (PORTDbits.RD3 = 1)
#define TEXTLCD_D5_SetLow()             (PORTDbits.RD3 = 0)
#define TEXTLCD_D5_Toggle()             (PORTDbits.RD3 ^= 1)
#define TEXTLCD_D5_GetValue()           PORTDbits.RD3
#define TEXTLCD_D5_SetDigitalInput()    (TRISDbits.TRISD3 = 1)
#define TEXTLCD_D5_SetDigitalOutput()   (TRISDbits.TRISD3 = 0)

// get/set TEXTLCD_D6 aliases
#define TEXTLCD_D6_SetHigh()            (PORTDbits.RD4 = 1)
#define TEXTLCD_D6_SetLow()             (PORTDbits.RD4 = 0)
#define TEXTLCD_D6_Toggle()             (PORTDbits.RD4 ^= 1)
#define TEXTLCD_D6_GetValue()           PORTDbits.RD4
#define TEXTLCD_D6_SetDigitalInput()    (TRISDbits.TRISD4 = 1)
#define TEXTLCD_D6_SetDigitalOutput()   (TRISDbits.TRISD4 = 0)

// get/set TEXTLCD_D7 aliases
#define TEXTLCD_D7_SetHigh()            (PORTDbits.RD5 = 1)
#define TEXTLCD_D7_SetLow()             (PORTDbits.RD5 = 0)
#define TEXTLCD_D7_Toggle()             (PORTDbits.RD5 ^= 1)
#define TEXTLCD_D7_GetValue()           PORTDbits.RD5
#define TEXTLCD_D7_SetDigitalInput()    (TRISDbits.TRISD5 = 1)
#define TEXTLCD_D7_SetDigitalOutput()   (TRISDbits.TRISD5 = 0)

// get/set LM35_1 aliases
#define LM35_1_SetHigh()                (PORTAbits.RA0 = 1)
#define LM35_1_SetLow()                 (PORTAbits.RA0 = 0)
#define LM35_1_Toggle()                 (PORTAbits.RA0 ^= 1)
#define LM35_1_GetValue()               PORTAbits.RA0
#define LM35_1_SetDigitalInput()        (TRISAbits.TRISA0 = 1)
#define LM35_1_SetDigitalOutput()       (TRISAbits.TRISA0 = 0)

// get/set LM35_2 aliases
#define LM35_2_SetHigh()                (PORTAbits.RA1 = 1)
#define LM35_2_SetLow()                 (PORTAbits.RA1 = 0)
#define LM35_2_Toggle()                 (PORTAbits.RA1 ^= 1)
#define LM35_2_GetValue()               PORTAbits.RA1
#define LM35_2_SetDigitalInput()        (TRISAbits.TRISA1 = 1)
#define LM35_2_SetDigitalOutput()       (TRISAbits.TRISA1 = 0)

// get/set LM35_3 aliases
#define LM35_3_SetHigh()                (PORTAbits.RA3 = 1)
#define LM35_3_SetLow()                 (PORTAbits.RA3 = 0)
#define LM35_3_Toggle()                 (PORTAbits.RA3 ^= 1)
#define LM35_3_GetValue()               PORTAbits.RA3
#define LM35_3_SetDigitalInput()        (TRISAbits.TRISA3 = 1)
#define LM35_3_SetDigitalOutput()       (TRISAbits.TRISA3 = 0)

void PIN_MANAGER_Initialize(void);
void PIN_MANAGER_IOC(void);

#endif