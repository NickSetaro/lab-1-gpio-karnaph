#include <msp430.h>

#define light1 BIT0; //LED is .0 on board
#define light2 BIT0;

void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;       // stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;           // Disable the GPIO power-on default high-impedance mode

    P1DIR |= light1; // set LED as output
    P2DIR |= light2; // set switch as input

    unsigned int i;

    while(1)
    {
        P1OUT ^= light1;  // toggle LED on/off

        for(i=6000; i>0; i--) //countdown from 6000
            {

            if(i % 500 == 0)
                {
                P2OUT ^= light2; //the light toggles every 500 counts within the 6000 countdown
                }
            }
    }
}
