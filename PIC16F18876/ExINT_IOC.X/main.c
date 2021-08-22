#include <xc.h>
#include <stdint.h>

// CONFIG1
#pragma config FEXTOSC=OFF      // External Oscillator mode selection bits->Oscillator not enabled
#pragma config RSTOSC=HFINT1    // Power-up default value for COSC bits->HFINTOSC (1MHz)
#pragma config CLKOUTEN=OFF     // Clock Out Enable bit->CLKOUT function is disabled; i/o or oscillator function on OSC2
#pragma config CSWEN=ON         // Clock Switch Enable bit->Writing to NOSC and NDIV is allowed
#pragma config FCMEN=ON         // Fail-Safe Clock Monitor Enable bit->FSCM timer enabled
// CONFIG2
#pragma config MCLRE=ON         // Master Clear Enable bit->MCLR pin is Master Clear function
#pragma config PWRTE=OFF        // Power-up Timer Enable bit->PWRT disabled
#pragma config LPBOREN=OFF      // Low-Power BOR enable bit->ULPBOR disabled
#pragma config BOREN=ON         // Brown-out reset enable bits->Brown-out Reset Enabled, SBOREN bit is ignored
#pragma config BORV=LO          // Brown-out Reset Voltage Selection->Brown-out Reset Voltage (VBOR) set to 1.9V on LF, and 2.45V on F Devices
#pragma config ZCD=OFF          // Zero-cross detect disable->Zero-cross detect circuit is disabled at POR.
#pragma config PPS1WAY=ON       // Peripheral Pin Select one-way control->The PPSLOCK bit can be cleared and set only once in software
#pragma config STVREN=ON        // Stack Overflow/Underflow Reset Enable bit->Stack Overflow or Underflow will cause a reset
#pragma config DEBUG=OFF        // Background Debugger->Background Debugger disabled
// CONFIG3
#pragma config WDTCPS=WDTCPS_31 // WDT Period Select bits->Divider ratio 1:65536; software control of WDTPS
#pragma config WDTE=OFF         // WDT operating mode->WDT Disabled, SWDTEN is ignored
#pragma config WDTCWS=WDTCWS_7  // WDT Window Select bits->window always open (100%); software control; keyed access not required
#pragma config WDTCCS=SC        // WDT input clock selector->Software Control
// CONFIG4
#pragma config WRT=OFF          // UserNVM self-write protection bits->Write protection off
#pragma config SCANE=available  // Scanner Enable bit->Scanner module is available for use
#pragma config LVP=ON           // Low Voltage Programming Enable bit->Low Voltage programming enabled. MCLR/Vpp pin function is MCLR.
// CONFIG5
#pragma config CP=OFF           // UserNVM Program memory code protection bit->Program Memory code protection disabled
#pragma config CPD=OFF          // DataNVM code protection bit->Data EEPROM code protection disabled

void ExInterrupt_Handler(void)
{
    PIR0bits.INTF=0; // Clear the external interrupt flag
    // User's code
    LATAbits.LATA1^=1; // BLED Toggles

}

void IocInterrupt_Handler(void)
{
    if(IOCBFbits.IOCBF2==1) // interrupt on change for pin IOCBF2
    {
        IOCBFbits.IOCBF2=0; // Clear the interrupt on change flag for pin IOCBF2
        // User's code
        LATDbits.LATD3^=1; // RLED Toggles
    }
}

void __interrupt() INTERRUPT_InterruptManager(void)
{
    if((PIE0bits.INTE==1)&&(PIR0bits.INTF==1))
        ExInterrupt_Handler();

    if((PIE0bits.IOCIE==1)&&(PIR0bits.IOCIF==1))
        IocInterrupt_Handler();
}

void main(void)
{
    /* **************************************************** CAU HINH DAO DONG */
    OSCCON1=0x60; // NOSC HFINTOSC; NDIV 1; 
    OSCEN=0x00; // MFOEN disabled; LFOEN disabled; ADOEN disabled; SOSCEN disabled; EXTOEN disabled; HFOEN disabled; 
    OSCFRQ=0x06; // HFFRQ 32_MHz; 
    /* ********************************************************* CAU HINH I/O */
    // BLUE LED
    ANSELAbits.ANSA1=0; // A1 is digital I/O
    TRISAbits.TRISA1=0; // A1 is output
    LATDbits.LATD1=0; // A1 is low
    // RED LED
    ANSELDbits.ANSD3=0; // D3 is digital I/O
    ODCONDbits.ODCD3=1; // D3 is open-drain output (share with button)
    TRISDbits.TRISD3=0; // D3 is output
    LATDbits.LATD3=1; // D3 is high
    // INT0
    ANSELBbits.ANSB1=0; // B1 is digital I/O
    TRISBbits.TRISB1=1; // B1 is input
    WPUBbits.WPUB1=1; // B1 is pulled up
    // INT1
    ANSELBbits.ANSB2=0; // B2 is digital I/O
    TRISBbits.TRISB2=1; // B2 is input
    WPUBbits.WPUB2=1; // B2 is pulled up
    /* *************************************************** CAU HINH INTERRUPT */
    // External interrupt
    INTPPS=0x09; // RB1->EXT_INT:INT;
    INTCONbits.INTEDG=1; // Set the external interrupt as rising edge detection
    PIR0bits.INTF=0; // Clear the external interrupt flag
    PIE0bits.INTE=1; // Enable the external interrupt
    // Interrupt on change
    IOCBFbits.IOCBF2=0; // interrupt on change for group IOCBF - flag
    IOCBNbits.IOCBN2=1; // interrupt on change for group IOCBN - negative
    IOCBPbits.IOCBP2=0; // No interrupt on change for group IOCBP - positive
    PIE0bits.IOCIE=1; // Enable IOCI interrupt 

    INTCONbits.PEIE=1; // Enable peripheral interrupt
    INTCONbits.GIE=1; // Enable global interrupt

    while(1);
}