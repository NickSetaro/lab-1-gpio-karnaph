#include <msp430.h> 


/**
 * main.c
 */

#define light1 BIT0;
#define light2 BIT6;

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
	P1DIR |=light1;
	P1DIR |=light2;

	unsigned int i;

	while(1){
	    P1OUT ^= light1;

	    for(i=6000; i>0; i--)
	    {

	        if (i % 500 ==0)
	        {
	            P1OUT ^= light2;
	        }
	    }
	}

	return 0;
}
