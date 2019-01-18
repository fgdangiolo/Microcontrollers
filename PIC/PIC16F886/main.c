
/****************************************************************
Example: Blinky
Microcontroller: PIC16F886
****************************************************************/

// CONFIG1
#pragma config FOSC = INTRC_NOCLKOUT// Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // RE3/MCLR pin function select bit (RE3/MCLR pin function is digital input, MCLR internally tied to VDD)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = ON       // Brown Out Reset Selection bits (BOR enabled)
#pragma config IESO = ON        // Internal External Switchover bit (Internal/External Switchover mode is enabled)
#pragma config FCMEN = ON       // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is enabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>

#define _XTAL_FREQ 4000000 // Clock frequency

#define     Config_LED_1    TRISAbits.TRISA0 
#define     LED_1           PORTAbits.RA0


/*************
  Prototipes
 *************/

void init_port(void); // Bit 0, Port A, as output

void main(void) {
    
    
    init_port();
    
    LED_1 = 0;
    
    while(1){
        
         LED_1 = !LED_1;        // The data "0" is sent to the RA0 bit
         __delay_ms(500);
         
             
    }
    
    return;
}

void init_port(void){
    
    Config_LED_1 = 0;   // Config Bit 0, Porta A, as output
            
    ANSEL=0;            //Analog Channel is disabled    
    
}