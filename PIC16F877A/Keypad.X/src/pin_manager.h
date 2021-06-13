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

// get/set KB_ROW0 aliases
#define KB_ROW0_TRIS                TRISBbits.TRISB0
#define KB_ROW0_SetHigh()           PORTBbits.RB0=1
#define KB_ROW0_SetLow()            PORTBbits.RB0=0
#define KB_ROW0_Toggle()            PORTBbits.RB0^=1
#define KB_ROW0_GetValue()          PORTBbits.RB0
#define KB_ROW0_SetDigitalInput()   TRISBbits.TRISB0=1
#define KB_ROW0_SetDigitalOutput()  TRISBbits.TRISB0=0

// get/set KB_ROW1 aliases
#define KB_ROW1_TRIS                TRISBbits.TRISB1
#define KB_ROW1_PORT                PORTBbits.RB1
#define KB_ROW1_SetHigh()           PORTBbits.RB1=1
#define KB_ROW1_SetLow()            PORTBbits.RB1=0
#define KB_ROW1_Toggle()            PORTBbits.RB1^=1
#define KB_ROW1_GetValue()          PORTBbits.RB1
#define KB_ROW1_SetDigitalInput()   TRISBbits.TRISB1=1
#define KB_ROW1_SetDigitalOutput()  TRISBbits.TRISB1=0

// get/set KB_ROW2 aliases
#define KB_ROW2_TRIS                TRISBbits.TRISB2
#define KB_ROW2_PORT                PORTBbits.RB2
#define KB_ROW2_SetHigh()           PORTBbits.RB2=1
#define KB_ROW2_SetLow()            PORTBbits.RB2=0
#define KB_ROW2_Toggle()            PORTBbits.RB2^=1
#define KB_ROW2_GetValue()          PORTBbits.RB2
#define KB_ROW2_SetDigitalInput()   TRISBbits.TRISB2=1
#define KB_ROW2_SetDigitalOutput()  TRISBbits.TRISB2=0

// get/set KB_ROW3 aliases
#define KB_ROW3_TRIS                TRISBbits.TRISB3
#define KB_ROW3_PORT                PORTBbits.RB3
#define KB_ROW3_SetHigh()           PORTBbits.RB3=1
#define KB_ROW3_SetLow()            PORTBbits.RB3=0
#define KB_ROW3_Toggle()            PORTBbits.RB3^=1
#define KB_ROW3_GetValue()          PORTBbits.RB3
#define KB_ROW3_SetDigitalInput()   TRISBbits.TRISB3=1
#define KB_ROW3_SetDigitalOutput()  TRISBbits.TRISB3=0

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

// get/set KB_COL0 aliases
#define KB_COL0_TRIS                TRISEbits.TRISE0
#define KB_COL0_PORT                PORTEbits.RE0
#define KB_COL0_SetHigh()           PORTEbits.RE0=1
#define KB_COL0_SetLow()            PORTEbits.RE0=0
#define KB_COL0_Toggle()            PORTEbits.RE0^=1
#define KB_COL0_GetValue()          PORTEbits.RE0
#define KB_COL0_SetDigitalInput()   TRISEbits.TRISE0=1
#define KB_COL0_SetDigitalOutput()  TRISEbits.TRISE0=0

// get/set KB_COL1 aliases
#define KB_COL1_TRIS                TRISEbits.TRISE1
#define KB_COL1_PORT                PORTEbits.RE1
#define KB_COL1_SetHigh()           PORTEbits.RE1=1
#define KB_COL1_SetLow()            PORTEbits.RE1=0
#define KB_COL1_Toggle()            PORTEbits.RE1^=1
#define KB_COL1_GetValue()          PORTEbits.RE1
#define KB_COL1_SetDigitalInput()   TRISEbits.TRISE1=1
#define KB_COL1_SetDigitalOutput()  TRISEbits.TRISE1=0

// get/set KB_COL2 aliases
#define KB_COL2_TRIS                TRISEbits.TRISE2
#define KB_COL2_PORT                PORTEbits.RE2
#define KB_COL2_SetHigh()           PORTEbits.RE2=1
#define KB_COL2_SetLow()            PORTEbits.RE2=0
#define KB_COL2_Toggle()            PORTEbits.RE2^=1
#define KB_COL2_GetValue()          PORTEbits.RE2
#define KB_COL2_SetDigitalInput()   TRISEbits.TRISE2=1
#define KB_COL2_SetDigitalOutput()  TRISEbits.TRISE2=0

void PIN_MANAGER_Initialize(void);

#endif