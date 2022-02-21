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
        Device            :  PIC16F18877
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

// get/set RB4 procedures
#define RB4_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define RB4_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define RB4_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define RB4_GetValue()              PORTBbits.RB4
#define RB4_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define RB4_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define RB4_SetPullup()             do { WPUBbits.WPUB4 = 1; } while(0)
#define RB4_ResetPullup()           do { WPUBbits.WPUB4 = 0; } while(0)
#define RB4_SetAnalogMode()         do { ANSELBbits.ANSB4 = 1; } while(0)
#define RB4_SetDigitalMode()        do { ANSELBbits.ANSB4 = 0; } while(0)

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

// get/set RC2 procedures
#define RC2_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define RC2_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define RC2_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define RC2_GetValue()              PORTCbits.RC2
#define RC2_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define RC2_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define RC2_SetPullup()             do { WPUCbits.WPUC2 = 1; } while(0)
#define RC2_ResetPullup()           do { WPUCbits.WPUC2 = 0; } while(0)
#define RC2_SetAnalogMode()         do { ANSELCbits.ANSC2 = 1; } while(0)
#define RC2_SetDigitalMode()        do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set PULSE aliases
#define PULSE_TRIS                 TRISCbits.TRISC3
#define PULSE_LAT                  LATCbits.LATC3
#define PULSE_PORT                 PORTCbits.RC3
#define PULSE_WPU                  WPUCbits.WPUC3
#define PULSE_OD                   ODCONCbits.ODCC3
#define PULSE_ANS                  ANSELCbits.ANSC3
#define PULSE_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define PULSE_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define PULSE_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define PULSE_GetValue()           PORTCbits.RC3
#define PULSE_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define PULSE_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define PULSE_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define PULSE_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define PULSE_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define PULSE_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define PULSE_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define PULSE_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set UBT_N aliases
#define UBT_N_TRIS                 TRISDbits.TRISD3
#define UBT_N_LAT                  LATDbits.LATD3
#define UBT_N_PORT                 PORTDbits.RD3
#define UBT_N_WPU                  WPUDbits.WPUD3
#define UBT_N_OD                   ODCONDbits.ODCD3
#define UBT_N_ANS                  ANSELDbits.ANSD3
#define UBT_N_SetHigh()            do { LATDbits.LATD3 = 1; } while(0)
#define UBT_N_SetLow()             do { LATDbits.LATD3 = 0; } while(0)
#define UBT_N_Toggle()             do { LATDbits.LATD3 = ~LATDbits.LATD3; } while(0)
#define UBT_N_GetValue()           PORTDbits.RD3
#define UBT_N_SetDigitalInput()    do { TRISDbits.TRISD3 = 1; } while(0)
#define UBT_N_SetDigitalOutput()   do { TRISDbits.TRISD3 = 0; } while(0)
#define UBT_N_SetPullup()          do { WPUDbits.WPUD3 = 1; } while(0)
#define UBT_N_ResetPullup()        do { WPUDbits.WPUD3 = 0; } while(0)
#define UBT_N_SetPushPull()        do { ODCONDbits.ODCD3 = 0; } while(0)
#define UBT_N_SetOpenDrain()       do { ODCONDbits.ODCD3 = 1; } while(0)
#define UBT_N_SetAnalogMode()      do { ANSELDbits.ANSD3 = 1; } while(0)
#define UBT_N_SetDigitalMode()     do { ANSELDbits.ANSD3 = 0; } while(0)

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