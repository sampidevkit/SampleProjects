/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC16LF18877
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.31 and above
        MPLAB 	          :  MPLAB X 5.45	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

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
#define STT_LED_TRIS                 TRISAbits.TRISA1
#define STT_LED_LAT                  LATAbits.LATA1
#define STT_LED_PORT                 PORTAbits.RA1
#define STT_LED_WPU                  WPUAbits.WPUA1
#define STT_LED_OD                   ODCONAbits.ODCA1
#define STT_LED_ANS                  ANSELAbits.ANSA1
#define STT_LED_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define STT_LED_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define STT_LED_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define STT_LED_GetValue()           PORTAbits.RA1
#define STT_LED_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define STT_LED_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define STT_LED_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define STT_LED_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define STT_LED_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define STT_LED_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define STT_LED_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define STT_LED_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set I2C_VBUS aliases
#define I2C_VBUS_TRIS                 TRISAbits.TRISA2
#define I2C_VBUS_LAT                  LATAbits.LATA2
#define I2C_VBUS_PORT                 PORTAbits.RA2
#define I2C_VBUS_WPU                  WPUAbits.WPUA2
#define I2C_VBUS_OD                   ODCONAbits.ODCA2
#define I2C_VBUS_ANS                  ANSELAbits.ANSA2
#define I2C_VBUS_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define I2C_VBUS_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define I2C_VBUS_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define I2C_VBUS_GetValue()           PORTAbits.RA2
#define I2C_VBUS_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define I2C_VBUS_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define I2C_VBUS_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define I2C_VBUS_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define I2C_VBUS_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define I2C_VBUS_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define I2C_VBUS_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define I2C_VBUS_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set RB3 procedures
#define RB3_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define RB3_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define RB3_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define RB3_GetValue()              PORTBbits.RB3
#define RB3_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define RB3_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define RB3_SetPullup()             do { WPUBbits.WPUB3 = 1; } while(0)
#define RB3_ResetPullup()           do { WPUBbits.WPUB3 = 0; } while(0)
#define RB3_SetAnalogMode()         do { ANSELBbits.ANSB3 = 1; } while(0)
#define RB3_SetDigitalMode()        do { ANSELBbits.ANSB3 = 0; } while(0)

// get/set RB5 procedures
#define RB5_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define RB5_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define RB5_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define RB5_GetValue()              PORTBbits.RB5
#define RB5_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define RB5_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define RB5_SetPullup()             do { WPUBbits.WPUB5 = 1; } while(0)
#define RB5_ResetPullup()           do { WPUBbits.WPUB5 = 0; } while(0)
#define RB5_SetAnalogMode()         do { ANSELBbits.ANSB5 = 1; } while(0)
#define RB5_SetDigitalMode()        do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set RD6 procedures
#define RD6_SetHigh()            do { LATDbits.LATD6 = 1; } while(0)
#define RD6_SetLow()             do { LATDbits.LATD6 = 0; } while(0)
#define RD6_Toggle()             do { LATDbits.LATD6 = ~LATDbits.LATD6; } while(0)
#define RD6_GetValue()              PORTDbits.RD6
#define RD6_SetDigitalInput()    do { TRISDbits.TRISD6 = 1; } while(0)
#define RD6_SetDigitalOutput()   do { TRISDbits.TRISD6 = 0; } while(0)
#define RD6_SetPullup()             do { WPUDbits.WPUD6 = 1; } while(0)
#define RD6_ResetPullup()           do { WPUDbits.WPUD6 = 0; } while(0)
#define RD6_SetAnalogMode()         do { ANSELDbits.ANSD6 = 1; } while(0)
#define RD6_SetDigitalMode()        do { ANSELDbits.ANSD6 = 0; } while(0)

// get/set I2C_INT aliases
#define I2C_INT_TRIS                 TRISDbits.TRISD7
#define I2C_INT_LAT                  LATDbits.LATD7
#define I2C_INT_PORT                 PORTDbits.RD7
#define I2C_INT_WPU                  WPUDbits.WPUD7
#define I2C_INT_OD                   ODCONDbits.ODCD7
#define I2C_INT_ANS                  ANSELDbits.ANSD7
#define I2C_INT_SetHigh()            do { LATDbits.LATD7 = 1; } while(0)
#define I2C_INT_SetLow()             do { LATDbits.LATD7 = 0; } while(0)
#define I2C_INT_Toggle()             do { LATDbits.LATD7 = ~LATDbits.LATD7; } while(0)
#define I2C_INT_GetValue()           PORTDbits.RD7
#define I2C_INT_SetDigitalInput()    do { TRISDbits.TRISD7 = 1; } while(0)
#define I2C_INT_SetDigitalOutput()   do { TRISDbits.TRISD7 = 0; } while(0)
#define I2C_INT_SetPullup()          do { WPUDbits.WPUD7 = 1; } while(0)
#define I2C_INT_ResetPullup()        do { WPUDbits.WPUD7 = 0; } while(0)
#define I2C_INT_SetPushPull()        do { ODCONDbits.ODCD7 = 0; } while(0)
#define I2C_INT_SetOpenDrain()       do { ODCONDbits.ODCD7 = 1; } while(0)
#define I2C_INT_SetAnalogMode()      do { ANSELDbits.ANSD7 = 1; } while(0)
#define I2C_INT_SetDigitalMode()     do { ANSELDbits.ANSD7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/