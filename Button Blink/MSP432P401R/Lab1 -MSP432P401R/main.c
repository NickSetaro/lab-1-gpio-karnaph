#include <msp432.h>


/**
 * main.c
 */
void main(void)
{
	P1DIR |= 0x01;
	WDTCTL = WDTPW | WDTHOLD;
	while (1)
	{
	    P1OUT ^= 0x01;
	    __delay_cycles(250000);

	}

    	// stop watchdog timer
}
