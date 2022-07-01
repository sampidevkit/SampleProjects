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

// get/set RA1 procedures
#define RA1_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define RA1_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define RA1_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define RA1_GetValue()              PORTAbits.RA1
#define RA1_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define RA1_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define RA1_SetPullup()             do { WPUAbits.WPUA1 = 1; } while(0)
#define RA1_ResetPullup()           do { WPUAbits.WPUA1 = 0; } while(0)
#define RA1_SetAnalogMode()         do { ANSELAbits.ANSA1 = 1; } while(0)
#define RA1_SetDigitalMode()        do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set RB1 procedures
#define RB1_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define RB1_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define RB1_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define RB1_GetValue()              PORTBbits.RB1
#define RB1_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define RB1_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define RB1_SetPullup()             do { WPUBbits.WPUB1 = 1; } while(0)
#define RB1_ResetPullup()           do { WPUBbits.WPUB1 = 0; } while(0)
#define RB1_SetAnalogMode()         do { ANSELBbits.ANSB1 = 1; } while(0)
#define RB1_SetDigitalMode()        do { ANSELBbits.ANSB1 = 0; } while(0)

// get/set RB2 procedures
#define RB2_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define RB2_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define RB2_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define RB2_GetValue()              PORTBbits.RB2
#define RB2_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define RB2_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define RB2_SetPullup()             do { WPUBbits.WPUB2 = 1; } while(0)
#define RB2_ResetPullup()           do { WPUBbits.WPUB2 = 0; } while(0)
#define RB2_SetAnalogMode()         do { ANSELBbits.ANSB2 = 1; } while(0)
#define RB2_SetDigitalMode()        do { ANSELBbits.ANSB2 = 0; } while(0)

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

// get/set I2C_VBUS aliases
#define I2C_VBUS_TRIS                 TRISCbits.TRISC2
#define I2C_VBUS_LAT                  LATCbits.LATC2
#define I2C_VBUS_PORT                 PORTCbits.RC2
#define I2C_VBUS_WPU                  WPUCbits.WPUC2
#define I2C_VBUS_OD                   ODCONCbits.ODCC2
#define I2C_VBUS_ANS                  ANSELCbits.ANSC2
#define I2C_VBUS_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define I2C_VBUS_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define I2C_VBUS_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define I2C_VBUS_GetValue()           PORTCbits.RC2
#define I2C_VBUS_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define I2C_VBUS_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define I2C_VBUS_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define I2C_VBUS_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define I2C_VBUS_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define I2C_VBUS_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define I2C_VBUS_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define I2C_VBUS_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set GND aliases
#define GND_TRIS                 TRISCbits.TRISC3
#define GND_LAT                  LATCbits.LATC3
#define GND_PORT                 PORTCbits.RC3
#define GND_WPU                  WPUCbits.WPUC3
#define GND_OD                   ODCONCbits.ODCC3
#define GND_ANS                  ANSELCbits.ANSC3
#define GND_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define GND_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define GND_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define GND_GetValue()           PORTCbits.RC3
#define GND_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define GND_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define GND_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define GND_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define GND_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define GND_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define GND_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define GND_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set RD2 procedures
#define RD2_SetHigh()            do { LATDbits.LATD2 = 1; } while(0)
#define RD2_SetLow()             do { LATDbits.LATD2 = 0; } while(0)
#define RD2_Toggle()             do { LATDbits.LATD2 = ~LATDbits.LATD2; } while(0)
#define RD2_GetValue()              PORTDbits.RD2
#define RD2_SetDigitalInput()    do { TRISDbits.TRISD2 = 1; } while(0)
#define RD2_SetDigitalOutput()   do { TRISDbits.TRISD2 = 0; } while(0)
#define RD2_SetPullup()             do { WPUDbits.WPUD2 = 1; } while(0)
#define RD2_ResetPullup()           do { WPUDbits.WPUD2 = 0; } while(0)
#define RD2_SetAnalogMode()         do { ANSELDbits.ANSD2 = 1; } while(0)
#define RD2_SetDigitalMode()        do { ANSELDbits.ANSD2 = 0; } while(0)

// get/set STT_LED_N aliases
#define STT_LED_N_TRIS                 TRISDbits.TRISD3
#define STT_LED_N_LAT                  LATDbits.LATD3
#define STT_LED_N_PORT                 PORTDbits.RD3
#define STT_LED_N_WPU                  WPUDbits.WPUD3
#define STT_LED_N_OD                   ODCONDbits.ODCD3
#define STT_LED_N_ANS                  ANSELDbits.ANSD3
#define STT_LED_N_SetHigh()            do { LATDbits.LATD3 = 1; } while(0)
#define STT_LED_N_SetLow()             do { LATDbits.LATD3 = 0; } while(0)
#define STT_LED_N_Toggle()             do { LATDbits.LATD3 = ~LATDbits.LATD3; } while(0)
#define STT_LED_N_GetValue()           PORTDbits.RD3
#define STT_LED_N_SetDigitalInput()    do { TRISDbits.TRISD3 = 1; } while(0)
#define STT_LED_N_SetDigitalOutput()   do { TRISDbits.TRISD3 = 0; } while(0)
#define STT_LED_N_SetPullup()          do { WPUDbits.WPUD3 = 1; } while(0)
#define STT_LED_N_ResetPullup()        do { WPUDbits.WPUD3 = 0; } while(0)
#define STT_LED_N_SetPushPull()        do { ODCONDbits.ODCD3 = 0; } while(0)
#define STT_LED_N_SetOpenDrain()       do { ODCONDbits.ODCD3 = 1; } while(0)
#define STT_LED_N_SetAnalogMode()      do { ANSELDbits.ANSD3 = 1; } while(0)
#define STT_LED_N_SetDigitalMode()     do { ANSELDbits.ANSD3 = 0; } while(0)

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