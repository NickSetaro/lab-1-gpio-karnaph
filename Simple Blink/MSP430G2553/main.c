#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
	P1DIR |= BIT0; //Sets P1 as output

	while (1)
	{
	    P1OUT ^= BIT0; //toggles LED
	    __delay_cycles(1000000); //delay so that doesn't blink too fast
	}

	return 0;
}
