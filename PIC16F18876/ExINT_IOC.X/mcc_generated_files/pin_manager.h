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
        Device            :  PIC16F18876
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

// get/set BLED aliases
#define BLED_TRIS                 TRISAbits.TRISA1
#define BLED_LAT                  LATAbits.LATA1
#define BLED_PORT                 PORTAbits.RA1
#define BLED_WPU                  WPUAbits.WPUA1
#define BLED_OD                   ODCONAbits.ODCA1
#define BLED_ANS                  ANSELAbits.ANSA1
#define BLED_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define BLED_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define BLED_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define BLED_GetValue()           PORTAbits.RA1
#define BLED_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define BLED_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define BLED_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define BLED_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define BLED_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define BLED_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define BLED_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define BLED_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

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

// get/set IOC aliases
#define IOC_TRIS                 TRISBbits.TRISB2
#define IOC_LAT                  LATBbits.LATB2
#define IOC_PORT                 PORTBbits.RB2
#define IOC_WPU                  WPUBbits.WPUB2
#define IOC_OD                   ODCONBbits.ODCB2
#define IOC_ANS                  ANSELBbits.ANSB2
#define IOC_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define IOC_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define IOC_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define IOC_GetValue()           PORTBbits.RB2
#define IOC_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define IOC_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define IOC_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define IOC_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define IOC_SetPushPull()        do { ODCONBbits.ODCB2 = 0; } while(0)
#define IOC_SetOpenDrain()       do { ODCONBbits.ODCB2 = 1; } while(0)
#define IOC_SetAnalogMode()      do { ANSELBbits.ANSB2 = 1; } while(0)
#define IOC_SetDigitalMode()     do { ANSELBbits.ANSB2 = 0; } while(0)

// get/set RLED aliases
#define RLED_TRIS                 TRISDbits.TRISD3
#define RLED_LAT                  LATDbits.LATD3
#define RLED_PORT                 PORTDbits.RD3
#define RLED_WPU                  WPUDbits.WPUD3
#define RLED_OD                   ODCONDbits.ODCD3
#define RLED_ANS                  ANSELDbits.ANSD3
#define RLED_SetHigh()            do { LATDbits.LATD3 = 1; } while(0)
#define RLED_SetLow()             do { LATDbits.LATD3 = 0; } while(0)
#define RLED_Toggle()             do { LATDbits.LATD3 = ~LATDbits.LATD3; } while(0)
#define RLED_GetValue()           PORTDbits.RD3
#define RLED_SetDigitalInput()    do { TRISDbits.TRISD3 = 1; } while(0)
#define RLED_SetDigitalOutput()   do { TRISDbits.TRISD3 = 0; } while(0)
#define RLED_SetPullup()          do { WPUDbits.WPUD3 = 1; } while(0)
#define RLED_ResetPullup()        do { WPUDbits.WPUD3 = 0; } while(0)
#define RLED_SetPushPull()        do { ODCONDbits.ODCD3 = 0; } while(0)
#define RLED_SetOpenDrain()       do { ODCONDbits.ODCD3 = 1; } while(0)
#define RLED_SetAnalogMode()      do { ANSELDbits.ANSD3 = 1; } while(0)
#define RLED_SetDigitalMode()     do { ANSELDbits.ANSD3 = 0; } while(0)

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


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCBF2 pin functionality
 * @Example
    IOCBF2_ISR();
 */
void IOCBF2_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCBF2 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCBF2 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF2_SetInterruptHandler(MyInterruptHandler);

*/
void IOCBF2_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCBF2 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCBF2_SetInterruptHandler() method.
    This handler is called every time the IOCBF2 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF2_SetInterruptHandler(IOCBF2_InterruptHandler);

*/
extern void (*IOCBF2_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCBF2 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCBF2_SetInterruptHandler() method.
    This handler is called every time the IOCBF2 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF2_SetInterruptHandler(IOCBF2_DefaultInterruptHandler);

*/
void IOCBF2_DefaultInterruptHandler(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/