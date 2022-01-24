// PIC16F887 Configuration Bit Settings
// 'C' source line config statements
// CONFIG1
#pragma config FOSC = INTRC_NOCLKOUT// Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON       // RE3/MCLR pin function select bit (RE3/MCLR pin function is MCLR)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = ON       // Brown Out Reset Selection bits (BOR enabled)
#pragma config IESO = ON        // Internal External Switchover bit (Internal/External Switchover mode is enabled)
#pragma config FCMEN = ON       // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is enabled)
#pragma config LVP = ON         // Low Voltage Programming Enable bit (RB3/PGM pin has PGM function, low voltage programming enabled)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>

#define _XTAL_FREQ 4000000

void __interrupt() INTERRUPT_InterruptManager(void)
{
    if(INTCONbits.RBIF)
    {
        INTCONbits.RBIF=0;
        PORTD=PORTB;
    }
}

void main(void)
{
    OSCCON=0b01100000; // 4MHz internal
    ANSELH=0b00000000; // Turn off the ADC
    
    TRISB=0b11111111; // Input
    WPUB=0b11111111; // pullup-up
    OPTION_REGbits.nRBPU=0; // enable pull-up
    IOCB=0b11111111; // enable IOC
    
    INTCONbits.RBIE=1; // enable RB interrupt
    INTCONbits.RBIF=0; // clear RB interrupt flag
    INTCONbits.GIE=1; // enable global interrupt

    TRISD=0b00000000; // Output
    PORTD=PORTB;

    while(1)
    {
        SLEEP();
    }
}
