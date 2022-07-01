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
        Device            :  PIC16F1705
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

// get/set VIN_DIV aliases
#define VIN_DIV_TRIS                 TRISAbits.TRISA0
#define VIN_DIV_LAT                  LATAbits.LATA0
#define VIN_DIV_PORT                 PORTAbits.RA0
#define VIN_DIV_WPU                  WPUAbits.WPUA0
#define VIN_DIV_OD                   ODCONAbits.ODA0
#define VIN_DIV_ANS                  ANSELAbits.ANSA0
#define VIN_DIV_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define VIN_DIV_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define VIN_DIV_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define VIN_DIV_GetValue()           PORTAbits.RA0
#define VIN_DIV_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define VIN_DIV_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define VIN_DIV_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define VIN_DIV_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define VIN_DIV_SetPushPull()        do { ODCONAbits.ODA0 = 0; } while(0)
#define VIN_DIV_SetOpenDrain()       do { ODCONAbits.ODA0 = 1; } while(0)
#define VIN_DIV_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define VIN_DIV_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set VOUT_DIV aliases
#define VOUT_DIV_TRIS                 TRISAbits.TRISA1
#define VOUT_DIV_LAT                  LATAbits.LATA1
#define VOUT_DIV_PORT                 PORTAbits.RA1
#define VOUT_DIV_WPU                  WPUAbits.WPUA1
#define VOUT_DIV_OD                   ODCONAbits.ODA1
#define VOUT_DIV_ANS                  ANSELAbits.ANSA1
#define VOUT_DIV_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define VOUT_DIV_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define VOUT_DIV_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define VOUT_DIV_GetValue()           PORTAbits.RA1
#define VOUT_DIV_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define VOUT_DIV_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define VOUT_DIV_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define VOUT_DIV_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define VOUT_DIV_SetPushPull()        do { ODCONAbits.ODA1 = 0; } while(0)
#define VOUT_DIV_SetOpenDrain()       do { ODCONAbits.ODA1 = 1; } while(0)
#define VOUT_DIV_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define VOUT_DIV_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set IOUT_DIV aliases
#define IOUT_DIV_TRIS                 TRISAbits.TRISA2
#define IOUT_DIV_LAT                  LATAbits.LATA2
#define IOUT_DIV_PORT                 PORTAbits.RA2
#define IOUT_DIV_WPU                  WPUAbits.WPUA2
#define IOUT_DIV_OD                   ODCONAbits.ODA2
#define IOUT_DIV_ANS                  ANSELAbits.ANSA2
#define IOUT_DIV_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define IOUT_DIV_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define IOUT_DIV_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define IOUT_DIV_GetValue()           PORTAbits.RA2
#define IOUT_DIV_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define IOUT_DIV_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define IOUT_DIV_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define IOUT_DIV_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define IOUT_DIV_SetPushPull()        do { ODCONAbits.ODA2 = 0; } while(0)
#define IOUT_DIV_SetOpenDrain()       do { ODCONAbits.ODA2 = 1; } while(0)
#define IOUT_DIV_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define IOUT_DIV_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set STT_LED aliases
#define STT_LED_TRIS                 TRISAbits.TRISA5
#define STT_LED_LAT                  LATAbits.LATA5
#define STT_LED_PORT                 PORTAbits.RA5
#define STT_LED_WPU                  WPUAbits.WPUA5
#define STT_LED_OD                   ODCONAbits.ODA5
#define STT_LED_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define STT_LED_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define STT_LED_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define STT_LED_GetValue()           PORTAbits.RA5
#define STT_LED_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define STT_LED_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define STT_LED_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define STT_LED_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define STT_LED_SetPushPull()        do { ODCONAbits.ODA5 = 0; } while(0)
#define STT_LED_SetOpenDrain()       do { ODCONAbits.ODA5 = 1; } while(0)

// get/set RC0 procedures
#define RC0_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define RC0_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define RC0_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define RC0_GetValue()              PORTCbits.RC0
#define RC0_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define RC0_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define RC0_SetPullup()             do { WPUCbits.WPUC0 = 1; } while(0)
#define RC0_ResetPullup()           do { WPUCbits.WPUC0 = 0; } while(0)
#define RC0_SetAnalogMode()         do { ANSELCbits.ANSC0 = 1; } while(0)
#define RC0_SetDigitalMode()        do { ANSELCbits.ANSC0 = 0; } while(0)

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