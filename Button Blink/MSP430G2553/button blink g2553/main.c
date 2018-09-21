#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer

    P1SEL = 0x00; //Sets P1 as GPIO

    P1DIR |= (0x01);    //Sets direction of P1 Bit 0 to Output
    P1DIR &= ~(BIT3);   //Sets direction of P1 Bit 1 to Input

    P1REN |= (BIT3);    //Enables the resistor for P1 Bit 1
    P1OUT |= (BIT3);    //Sets the resistor for P1 Bit 1 to Pull Up
    P1OUT &= ~(BIT0);   //Keeps the LED off when button is not pressed

    int number = P1IN & BIT3; //When the button is pushed, number equals 8(decimal) or 0x04(hex)

    while(1)
    {

       if(number == 0)

       {
           P1OUT ^= BIT0; //Blink LED
           __delay_cycles(1000000);
       }

       else

       {
           P1OUT &= ~BIT0;
       }

    }
    return 0;
}
