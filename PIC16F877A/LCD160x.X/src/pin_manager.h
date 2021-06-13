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

// get/set LCD_RS aliases
#define LCD_RS_TRIS                 TRISDbits.TRISD0
#define LCD_RS_PORT                 PORTDbits.RD0
#define LCD_RS_SetHigh()            PORTDbits.RD0=1
#define LCD_RS_SetLow()             PORTDbits.RD0=0
#define LCD_RS_Toggle()             PORTDbits.RD0^=1
#define LCD_RS_GetValue()           PORTDbits.RD0
#define LCD_RS_SetDigitalInput()    TRISDbits.TRISD0=1
#define LCD_RS_SetDigitalOutput()   TRISDbits.TRISD0=0

// get/set LCD_EN aliases
#define LCD_EN_TRIS                 TRISDbits.TRISD1
#define LCD_EN_PORT                 PORTDbits.RD1
#define LCD_EN_SetHigh()            PORTDbits.RD1=1
#define LCD_EN_SetLow()             PORTDbits.RD1=0
#define LCD_EN_Toggle()             PORTDbits.RD1^=1
#define LCD_EN_GetValue()           PORTDbits.RD1
#define LCD_EN_SetDigitalInput()    TRISDbits.TRISD1=1
#define LCD_EN_SetDigitalOutput()   TRISDbits.TRISD1=0

// get/set LCD_D4 aliases
#define LCD_D4_TRIS                 TRISDbits.TRISD2
#define LCD_D4_PORT                 PORTDbits.RD2
#define LCD_D4_SetHigh()            PORTDbits.RD2=1
#define LCD_D4_SetLow()             PORTDbits.RD2=0
#define LCD_D4_Toggle()             PORTDbits.RD2^=1
#define LCD_D4_GetValue()           PORTDbits.RD2
#define LCD_D4_SetDigitalInput()    TRISDbits.TRISD2=1
#define LCD_D4_SetDigitalOutput()   TRISDbits.TRISD2=0

// get/set LCD_D5 aliases
#define LCD_D5_TRIS                 TRISDbits.TRISD3
#define LCD_D5_PORT                 PORTDbits.RD3
#define LCD_D5_SetHigh()            PORTDbits.RD3=1
#define LCD_D5_SetLow()             PORTDbits.RD3=0
#define LCD_D5_Toggle()             PORTDbits.RD3^=1
#define LCD_D5_GetValue()           PORTDbits.RD3
#define LCD_D5_SetDigitalInput()    TRISDbits.TRISD3=1
#define LCD_D5_SetDigitalOutput()   TRISDbits.TRISD3=0

// get/set LCD_D6 aliases
#define LCD_D6_TRIS                 TRISDbits.TRISD4
#define LCD_D6_PORT                 PORTDbits.RD4
#define LCD_D6_SetHigh()            PORTDbits.RD4=1
#define LCD_D6_SetLow()             PORTDbits.RD4=0
#define LCD_D6_Toggle()             PORTDbits.RD4^=1
#define LCD_D6_GetValue()           PORTDbits.RD4
#define LCD_D6_SetDigitalInput()    TRISDbits.TRISD4=1
#define LCD_D6_SetDigitalOutput()   TRISDbits.TRISD4=0

// get/set LCD_D7 aliases
#define LCD_D7_TRIS                 TRISDbits.TRISD5
#define LCD_D7_PORT                 PORTDbits.RD5
#define LCD_D7_SetHigh()            PORTDbits.RD5=1
#define LCD_D7_SetLow()             PORTDbits.RD5=0
#define LCD_D7_Toggle()             PORTDbits.RD5^=1
#define LCD_D7_GetValue()           PORTDbits.RD5
#define LCD_D7_SetDigitalInput()    TRISDbits.TRISD5=1
#define LCD_D7_SetDigitalOutput()   TRISDbits.TRISD5=0

void PIN_MANAGER_Initialize(void);

#endif