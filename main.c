
#include <xc.h>
#define _XTAL_FREQ 20000000

#pragma config FOSC = EXTRC     // Oscillator Selection bits (RC oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = ON         // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

unsigned char SSD[]={0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7c, 0x07, 0x7f, 0x6f};
unsigned int num = 99 ;
unsigned int i = 0 ;
unsigned int j = 0 ;
void main() {
    TRISB = 0; // All the pins of port B are configured as output pins 
    TRISC = 0 ; // All the pins of port C are configured as output pins 
    PORTC = 0 ;
    PORTB = 0 ;
     i = num/10 ; // number 76 is devided by 10 to get 10th power digit then i becomes 7
     j = num % 10 ; // number 76 is devided by 10 and reminder is equal to 6 then j becomes 6
  
    while(1)
    {
           
          PORTCbits.RC0 = 0 , PORTCbits.RC1 = 1 ;  // turn on the first SSD and turn off the second SSD
          PORTB = SSD[i];  // SSD array i position value assign to port B, ie possition 7 is equal to 0x07 (SSD value 7)
          __delay_ms(10);
          
          PORTCbits.RC1 = 0 , PORTCbits.RC0 = 1 ;
          PORTB = SSD[j];
          __delay_ms(10);
    }
}
