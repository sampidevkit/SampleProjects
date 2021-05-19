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

// get/set DIGIT1 aliases
#define DIGIT1_TRIS                 TRISAbits.TRISA5
#define DIGIT1_LAT                  LATAbits.LATA5
#define DIGIT1_PORT                 PORTAbits.RA5
#define DIGIT1_SetHigh()            LATAbits.LATA5=1
#define DIGIT1_SetLow()             LATAbits.LATA5=0
#define DIGIT1_Toggle()             LATAbits.LATA5=~LATAbits.LATA5
#define DIGIT1_GetValue()           PORTAbits.RA5
#define DIGIT1_SetDigitalInput()    TRISAbits.TRISA5=1
#define DIGIT1_SetDigitalOutput()   TRISAbits.TRISA5=0

// get/set DIGIT2 aliases
#define DIGIT2_TRIS                 TRISAbits.TRISA4
#define DIGIT2_LAT                  LATAbits.LATA4
#define DIGIT2_PORT                 PORTAbits.RA4
#define DIGIT2_SetHigh()            LATAbits.LATA4=1
#define DIGIT2_SetLow()             LATAbits.LATA4=0
#define DIGIT2_Toggle()             LATAbits.LATA4=~LATAbits.LATA4
#define DIGIT2_GetValue()           PORTAbits.RA4
#define DIGIT2_SetDigitalInput()    TRISAbits.TRISA4=1
#define DIGIT2_SetDigitalOutput()   TRISAbits.TRISA4=0

// get/set BT_UP aliases
#define BT_UP_TRIS                  TRISEbits.TRISE2
#define BT_UP_LAT                   LATEbits.LATE2
#define BT_UP_PORT                  PORTEbits.RE2
#define BT_UP_SetHigh()             LATEbits.LATE2=1
#define BT_UP_SetLow()              LATEbits.LATE2=0
#define BT_UP_Toggle()              LATEbits.LATE2=~LATEbits.LATE2
#define BT_UP_GetValue()            PORTEbits.RE2
#define BT_UP_SetDigitalInput()     TRISEbits.TRISE2=1
#define BT_UP_SetDigitalOutput()    TRISEbits.TRISE2=0

// get/set BT_DOWN aliases
#define BT_DOWN_TRIS                TRISEbits.TRISE1
#define BT_DOWN_LAT                 LATEbits.LATE1
#define BT_DOWN_PORT                PORTEbits.RE1
#define BT_DOWN_SetHigh()           LATEbits.LATE1=1
#define BT_DOWN_SetLow()            LATEbits.LATE1=0
#define BT_DOWN_Toggle()            LATEbits.LATE1=~LATEbits.LATE1
#define BT_DOWN_GetValue()          PORTEbits.RE1
#define BT_DOWN_SetDigitalInput()   TRISEbits.TRISE1=1
#define BT_DOWN_SetDigitalOutput()  TRISEbits.TRISE1=0

void PIN_MANAGER_Initialize(void);

#endif