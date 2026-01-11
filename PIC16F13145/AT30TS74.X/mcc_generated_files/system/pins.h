/**
 * Generated Pins header File
 * 
 * @file pins.h
 * 
 * @defgroup  pinsdriver Pins Driver
 * 
 * @brief This is generated driver header for pins. 
 *        This header file provides APIs for all pins selected in the GUI.
 *
 * @version Driver Version  3.0.0
*/

/*
© [2026] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/

#ifndef PINS_H
#define PINS_H

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set IO_RB4 aliases
#define QWIIC_SDA_TRIS                 TRISBbits.TRISB4
#define QWIIC_SDA_LAT                  LATBbits.LATB4
#define QWIIC_SDA_PORT                 PORTBbits.RB4
#define QWIIC_SDA_WPU                  WPUBbits.WPUB4
#define QWIIC_SDA_OD                   ODCONBbits.ODCB4
#define QWIIC_SDA_ANS                  ANSELBbits.ANSB4
#define QWIIC_SDA_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define QWIIC_SDA_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define QWIIC_SDA_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define QWIIC_SDA_GetValue()           PORTBbits.RB4
#define QWIIC_SDA_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define QWIIC_SDA_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define QWIIC_SDA_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define QWIIC_SDA_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define QWIIC_SDA_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define QWIIC_SDA_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define QWIIC_SDA_SetAnalogMode()      do { ANSELBbits.ANSB4 = 1; } while(0)
#define QWIIC_SDA_SetDigitalMode()     do { ANSELBbits.ANSB4 = 0; } while(0)
// get/set IO_RB5 aliases
#define VSEN_EN_TRIS                 TRISBbits.TRISB5
#define VSEN_EN_LAT                  LATBbits.LATB5
#define VSEN_EN_PORT                 PORTBbits.RB5
#define VSEN_EN_WPU                  WPUBbits.WPUB5
#define VSEN_EN_OD                   ODCONBbits.ODCB5
#define VSEN_EN_ANS                  ANSELBbits.ANSB5
#define VSEN_EN_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define VSEN_EN_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define VSEN_EN_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define VSEN_EN_GetValue()           PORTBbits.RB5
#define VSEN_EN_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define VSEN_EN_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define VSEN_EN_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define VSEN_EN_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define VSEN_EN_SetPushPull()        do { ODCONBbits.ODCB5 = 0; } while(0)
#define VSEN_EN_SetOpenDrain()       do { ODCONBbits.ODCB5 = 1; } while(0)
#define VSEN_EN_SetAnalogMode()      do { ANSELBbits.ANSB5 = 1; } while(0)
#define VSEN_EN_SetDigitalMode()     do { ANSELBbits.ANSB5 = 0; } while(0)
// get/set IO_RB6 aliases
#define QWIIC_SCL_TRIS                 TRISBbits.TRISB6
#define QWIIC_SCL_LAT                  LATBbits.LATB6
#define QWIIC_SCL_PORT                 PORTBbits.RB6
#define QWIIC_SCL_WPU                  WPUBbits.WPUB6
#define QWIIC_SCL_OD                   ODCONBbits.ODCB6
#define QWIIC_SCL_ANS                  ANSELBbits.ANSB6
#define QWIIC_SCL_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define QWIIC_SCL_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define QWIIC_SCL_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define QWIIC_SCL_GetValue()           PORTBbits.RB6
#define QWIIC_SCL_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define QWIIC_SCL_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define QWIIC_SCL_SetPullup()          do { WPUBbits.WPUB6 = 1; } while(0)
#define QWIIC_SCL_ResetPullup()        do { WPUBbits.WPUB6 = 0; } while(0)
#define QWIIC_SCL_SetPushPull()        do { ODCONBbits.ODCB6 = 0; } while(0)
#define QWIIC_SCL_SetOpenDrain()       do { ODCONBbits.ODCB6 = 1; } while(0)
#define QWIIC_SCL_SetAnalogMode()      do { ANSELBbits.ANSB6 = 1; } while(0)
#define QWIIC_SCL_SetDigitalMode()     do { ANSELBbits.ANSB6 = 0; } while(0)
// get/set IO_RC2 aliases
#define LED_TRIS                 TRISCbits.TRISC2
#define LED_LAT                  LATCbits.LATC2
#define LED_PORT                 PORTCbits.RC2
#define LED_WPU                  WPUCbits.WPUC2
#define LED_OD                   ODCONCbits.ODCC2
#define LED_ANS                  ANSELCbits.ANSC2
#define LED_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define LED_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define LED_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define LED_GetValue()           PORTCbits.RC2
#define LED_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define LED_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define LED_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define LED_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define LED_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define LED_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define LED_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define LED_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)
// get/set IO_RC3 aliases
#define SW_TRIS                 TRISCbits.TRISC3
#define SW_LAT                  LATCbits.LATC3
#define SW_PORT                 PORTCbits.RC3
#define SW_WPU                  WPUCbits.WPUC3
#define SW_OD                   ODCONCbits.ODCC3
#define SW_ANS                  ANSELCbits.ANSC3
#define SW_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define SW_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define SW_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define SW_GetValue()           PORTCbits.RC3
#define SW_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define SW_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define SW_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define SW_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define SW_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define SW_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define SW_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define SW_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)
// get/set IO_RC4 aliases
#define DBG_TXD_TRIS                 TRISCbits.TRISC4
#define DBG_TXD_LAT                  LATCbits.LATC4
#define DBG_TXD_PORT                 PORTCbits.RC4
#define DBG_TXD_WPU                  WPUCbits.WPUC4
#define DBG_TXD_OD                   ODCONCbits.ODCC4
#define DBG_TXD_ANS                  ANSELCbits.ANSC4
#define DBG_TXD_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define DBG_TXD_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define DBG_TXD_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define DBG_TXD_GetValue()           PORTCbits.RC4
#define DBG_TXD_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define DBG_TXD_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define DBG_TXD_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define DBG_TXD_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define DBG_TXD_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define DBG_TXD_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define DBG_TXD_SetAnalogMode()      do { ANSELCbits.ANSC4 = 1; } while(0)
#define DBG_TXD_SetDigitalMode()     do { ANSELCbits.ANSC4 = 0; } while(0)
// get/set IO_RC5 aliases
#define DBG_RXD_TRIS                 TRISCbits.TRISC5
#define DBG_RXD_LAT                  LATCbits.LATC5
#define DBG_RXD_PORT                 PORTCbits.RC5
#define DBG_RXD_WPU                  WPUCbits.WPUC5
#define DBG_RXD_OD                   ODCONCbits.ODCC5
#define DBG_RXD_ANS                  ANSELCbits.ANSC5
#define DBG_RXD_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define DBG_RXD_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define DBG_RXD_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define DBG_RXD_GetValue()           PORTCbits.RC5
#define DBG_RXD_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define DBG_RXD_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define DBG_RXD_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define DBG_RXD_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define DBG_RXD_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define DBG_RXD_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define DBG_RXD_SetAnalogMode()      do { ANSELCbits.ANSC5 = 1; } while(0)
#define DBG_RXD_SetDigitalMode()     do { ANSELCbits.ANSC5 = 0; } while(0)
/**
 * @ingroup  pinsdriver
 * @brief GPIO and peripheral I/O initialization
 * @param none
 * @return none
 */
void PIN_MANAGER_Initialize (void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt on Change Handling routine
 * @param none
 * @return none
 */
void PIN_MANAGER_IOC(void);


#endif // PINS_H
/**
 End of File
*/