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
        Device            :  PIC16F15344
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

// get/set RA5 procedures
#define RA5_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define RA5_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define RA5_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define RA5_GetValue()              PORTAbits.RA5
#define RA5_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define RA5_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define RA5_SetPullup()             do { WPUAbits.WPUA5 = 1; } while(0)
#define RA5_ResetPullup()           do { WPUAbits.WPUA5 = 0; } while(0)
#define RA5_SetAnalogMode()         do { ANSELAbits.ANSA5 = 1; } while(0)
#define RA5_SetDigitalMode()        do { ANSELAbits.ANSA5 = 0; } while(0)

// get/set LED3 aliases
#define LED3_TRIS                 TRISBbits.TRISB4
#define LED3_LAT                  LATBbits.LATB4
#define LED3_PORT                 PORTBbits.RB4
#define LED3_WPU                  WPUBbits.WPUB4
#define LED3_OD                   ODCONBbits.ODCB4
#define LED3_ANS                  ANSELBbits.ANSB4
#define LED3_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define LED3_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define LED3_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define LED3_GetValue()           PORTBbits.RB4
#define LED3_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define LED3_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define LED3_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define LED3_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define LED3_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define LED3_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define LED3_SetAnalogMode()      do { ANSELBbits.ANSB4 = 1; } while(0)
#define LED3_SetDigitalMode()     do { ANSELBbits.ANSB4 = 0; } while(0)

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

// get/set LED4 aliases
#define LED4_TRIS                 TRISBbits.TRISB6
#define LED4_LAT                  LATBbits.LATB6
#define LED4_PORT                 PORTBbits.RB6
#define LED4_WPU                  WPUBbits.WPUB6
#define LED4_OD                   ODCONBbits.ODCB6
#define LED4_ANS                  ANSELBbits.ANSB6
#define LED4_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define LED4_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define LED4_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define LED4_GetValue()           PORTBbits.RB6
#define LED4_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define LED4_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define LED4_SetPullup()          do { WPUBbits.WPUB6 = 1; } while(0)
#define LED4_ResetPullup()        do { WPUBbits.WPUB6 = 0; } while(0)
#define LED4_SetPushPull()        do { ODCONBbits.ODCB6 = 0; } while(0)
#define LED4_SetOpenDrain()       do { ODCONBbits.ODCB6 = 1; } while(0)
#define LED4_SetAnalogMode()      do { ANSELBbits.ANSB6 = 1; } while(0)
#define LED4_SetDigitalMode()     do { ANSELBbits.ANSB6 = 0; } while(0)

// get/set RB7 procedures
#define RB7_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define RB7_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define RB7_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define RB7_GetValue()              PORTBbits.RB7
#define RB7_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define RB7_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define RB7_SetPullup()             do { WPUBbits.WPUB7 = 1; } while(0)
#define RB7_ResetPullup()           do { WPUBbits.WPUB7 = 0; } while(0)
#define RB7_SetAnalogMode()         do { ANSELBbits.ANSB7 = 1; } while(0)
#define RB7_SetDigitalMode()        do { ANSELBbits.ANSB7 = 0; } while(0)

// get/set LED2 aliases
#define LED2_TRIS                 TRISCbits.TRISC2
#define LED2_LAT                  LATCbits.LATC2
#define LED2_PORT                 PORTCbits.RC2
#define LED2_WPU                  WPUCbits.WPUC2
#define LED2_OD                   ODCONCbits.ODCC2
#define LED2_ANS                  ANSELCbits.ANSC2
#define LED2_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define LED2_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define LED2_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define LED2_GetValue()           PORTCbits.RC2
#define LED2_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define LED2_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define LED2_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define LED2_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define LED2_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define LED2_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define LED2_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define LED2_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set LED0 aliases
#define LED0_TRIS                 TRISCbits.TRISC3
#define LED0_LAT                  LATCbits.LATC3
#define LED0_PORT                 PORTCbits.RC3
#define LED0_WPU                  WPUCbits.WPUC3
#define LED0_OD                   ODCONCbits.ODCC3
#define LED0_ANS                  ANSELCbits.ANSC3
#define LED0_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define LED0_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define LED0_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define LED0_GetValue()           PORTCbits.RC3
#define LED0_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define LED0_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define LED0_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define LED0_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define LED0_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define LED0_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define LED0_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define LED0_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set RC4 procedures
#define RC4_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define RC4_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define RC4_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define RC4_GetValue()              PORTCbits.RC4
#define RC4_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define RC4_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define RC4_SetPullup()             do { WPUCbits.WPUC4 = 1; } while(0)
#define RC4_ResetPullup()           do { WPUCbits.WPUC4 = 0; } while(0)
#define RC4_SetAnalogMode()         do { ANSELCbits.ANSC4 = 1; } while(0)
#define RC4_SetDigitalMode()        do { ANSELCbits.ANSC4 = 0; } while(0)

// get/set LED1 aliases
#define LED1_TRIS                 TRISCbits.TRISC6
#define LED1_LAT                  LATCbits.LATC6
#define LED1_PORT                 PORTCbits.RC6
#define LED1_WPU                  WPUCbits.WPUC6
#define LED1_OD                   ODCONCbits.ODCC6
#define LED1_ANS                  ANSELCbits.ANSC6
#define LED1_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define LED1_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define LED1_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define LED1_GetValue()           PORTCbits.RC6
#define LED1_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define LED1_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define LED1_SetPullup()          do { WPUCbits.WPUC6 = 1; } while(0)
#define LED1_ResetPullup()        do { WPUCbits.WPUC6 = 0; } while(0)
#define LED1_SetPushPull()        do { ODCONCbits.ODCC6 = 0; } while(0)
#define LED1_SetOpenDrain()       do { ODCONCbits.ODCC6 = 1; } while(0)
#define LED1_SetAnalogMode()      do { ANSELCbits.ANSC6 = 1; } while(0)
#define LED1_SetDigitalMode()     do { ANSELCbits.ANSC6 = 0; } while(0)

// get/set LED5 aliases
#define LED5_TRIS                 TRISCbits.TRISC7
#define LED5_LAT                  LATCbits.LATC7
#define LED5_PORT                 PORTCbits.RC7
#define LED5_WPU                  WPUCbits.WPUC7
#define LED5_OD                   ODCONCbits.ODCC7
#define LED5_ANS                  ANSELCbits.ANSC7
#define LED5_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define LED5_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define LED5_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define LED5_GetValue()           PORTCbits.RC7
#define LED5_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define LED5_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define LED5_SetPullup()          do { WPUCbits.WPUC7 = 1; } while(0)
#define LED5_ResetPullup()        do { WPUCbits.WPUC7 = 0; } while(0)
#define LED5_SetPushPull()        do { ODCONCbits.ODCC7 = 0; } while(0)
#define LED5_SetOpenDrain()       do { ODCONCbits.ODCC7 = 1; } while(0)
#define LED5_SetAnalogMode()      do { ANSELCbits.ANSC7 = 1; } while(0)
#define LED5_SetDigitalMode()     do { ANSELCbits.ANSC7 = 0; } while(0)

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