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

// get/set RTCC_INT aliases
#define RTCC_INT_TRIS                 TRISAbits.TRISA3
#define RTCC_INT_LAT                  LATAbits.LATA3
#define RTCC_INT_PORT                 PORTAbits.RA3
#define RTCC_INT_WPU                  WPUAbits.WPUA3
#define RTCC_INT_OD                   ODCONAbits.ODCA3
#define RTCC_INT_ANS                  ANSELAbits.ANSA3
#define RTCC_INT_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define RTCC_INT_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define RTCC_INT_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define RTCC_INT_GetValue()           PORTAbits.RA3
#define RTCC_INT_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define RTCC_INT_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define RTCC_INT_SetPullup()          do { WPUAbits.WPUA3 = 1; } while(0)
#define RTCC_INT_ResetPullup()        do { WPUAbits.WPUA3 = 0; } while(0)
#define RTCC_INT_SetPushPull()        do { ODCONAbits.ODCA3 = 0; } while(0)
#define RTCC_INT_SetOpenDrain()       do { ODCONAbits.ODCA3 = 1; } while(0)
#define RTCC_INT_SetAnalogMode()      do { ANSELAbits.ANSA3 = 1; } while(0)
#define RTCC_INT_SetDigitalMode()     do { ANSELAbits.ANSA3 = 0; } while(0)

// get/set FLASH_CS_N aliases
#define FLASH_CS_N_TRIS                 TRISBbits.TRISB0
#define FLASH_CS_N_LAT                  LATBbits.LATB0
#define FLASH_CS_N_PORT                 PORTBbits.RB0
#define FLASH_CS_N_WPU                  WPUBbits.WPUB0
#define FLASH_CS_N_OD                   ODCONBbits.ODCB0
#define FLASH_CS_N_ANS                  ANSELBbits.ANSB0
#define FLASH_CS_N_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define FLASH_CS_N_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define FLASH_CS_N_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define FLASH_CS_N_GetValue()           PORTBbits.RB0
#define FLASH_CS_N_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define FLASH_CS_N_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define FLASH_CS_N_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define FLASH_CS_N_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define FLASH_CS_N_SetPushPull()        do { ODCONBbits.ODCB0 = 0; } while(0)
#define FLASH_CS_N_SetOpenDrain()       do { ODCONBbits.ODCB0 = 1; } while(0)
#define FLASH_CS_N_SetAnalogMode()      do { ANSELBbits.ANSB0 = 1; } while(0)
#define FLASH_CS_N_SetDigitalMode()     do { ANSELBbits.ANSB0 = 0; } while(0)

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

// get/set VDDSS_EN_N aliases
#define VDDSS_EN_N_TRIS                 TRISDbits.TRISD0
#define VDDSS_EN_N_LAT                  LATDbits.LATD0
#define VDDSS_EN_N_PORT                 PORTDbits.RD0
#define VDDSS_EN_N_WPU                  WPUDbits.WPUD0
#define VDDSS_EN_N_OD                   ODCONDbits.ODCD0
#define VDDSS_EN_N_ANS                  ANSELDbits.ANSD0
#define VDDSS_EN_N_SetHigh()            do { LATDbits.LATD0 = 1; } while(0)
#define VDDSS_EN_N_SetLow()             do { LATDbits.LATD0 = 0; } while(0)
#define VDDSS_EN_N_Toggle()             do { LATDbits.LATD0 = ~LATDbits.LATD0; } while(0)
#define VDDSS_EN_N_GetValue()           PORTDbits.RD0
#define VDDSS_EN_N_SetDigitalInput()    do { TRISDbits.TRISD0 = 1; } while(0)
#define VDDSS_EN_N_SetDigitalOutput()   do { TRISDbits.TRISD0 = 0; } while(0)
#define VDDSS_EN_N_SetPullup()          do { WPUDbits.WPUD0 = 1; } while(0)
#define VDDSS_EN_N_ResetPullup()        do { WPUDbits.WPUD0 = 0; } while(0)
#define VDDSS_EN_N_SetPushPull()        do { ODCONDbits.ODCD0 = 0; } while(0)
#define VDDSS_EN_N_SetOpenDrain()       do { ODCONDbits.ODCD0 = 1; } while(0)
#define VDDSS_EN_N_SetAnalogMode()      do { ANSELDbits.ANSD0 = 1; } while(0)
#define VDDSS_EN_N_SetDigitalMode()     do { ANSELDbits.ANSD0 = 0; } while(0)

// get/set MCP970X aliases
#define MCP970X_TRIS                 TRISDbits.TRISD1
#define MCP970X_LAT                  LATDbits.LATD1
#define MCP970X_PORT                 PORTDbits.RD1
#define MCP970X_WPU                  WPUDbits.WPUD1
#define MCP970X_OD                   ODCONDbits.ODCD1
#define MCP970X_ANS                  ANSELDbits.ANSD1
#define MCP970X_SetHigh()            do { LATDbits.LATD1 = 1; } while(0)
#define MCP970X_SetLow()             do { LATDbits.LATD1 = 0; } while(0)
#define MCP970X_Toggle()             do { LATDbits.LATD1 = ~LATDbits.LATD1; } while(0)
#define MCP970X_GetValue()           PORTDbits.RD1
#define MCP970X_SetDigitalInput()    do { TRISDbits.TRISD1 = 1; } while(0)
#define MCP970X_SetDigitalOutput()   do { TRISDbits.TRISD1 = 0; } while(0)
#define MCP970X_SetPullup()          do { WPUDbits.WPUD1 = 1; } while(0)
#define MCP970X_ResetPullup()        do { WPUDbits.WPUD1 = 0; } while(0)
#define MCP970X_SetPushPull()        do { ODCONDbits.ODCD1 = 0; } while(0)
#define MCP970X_SetOpenDrain()       do { ODCONDbits.ODCD1 = 1; } while(0)
#define MCP970X_SetAnalogMode()      do { ANSELDbits.ANSD1 = 1; } while(0)
#define MCP970X_SetDigitalMode()     do { ANSELDbits.ANSD1 = 0; } while(0)

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
    Interrupt on Change Handler for the IOCAF3 pin functionality
 * @Example
    IOCAF3_ISR();
 */
void IOCAF3_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCAF3 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCAF3 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF3_SetInterruptHandler(MyInterruptHandler);

*/
void IOCAF3_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCAF3 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCAF3_SetInterruptHandler() method.
    This handler is called every time the IOCAF3 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF3_SetInterruptHandler(IOCAF3_InterruptHandler);

*/
extern void (*IOCAF3_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCAF3 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCAF3_SetInterruptHandler() method.
    This handler is called every time the IOCAF3 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF3_SetInterruptHandler(IOCAF3_DefaultInterruptHandler);

*/
void IOCAF3_DefaultInterruptHandler(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/