# Simple Blink

The LED output on the board toggles between on and off every 1000000 clock cycles. This is done in the program by setting P1.0 as an output, which is teh pin that powers the LED. Within the while loop, BIT0 is XOR'ed with P1OUT to toggle the switch. Then the delay cycles line delays the processors from starting the next step. 

The code for the G2553 and the F5529 are the same because the pin outs are the same. 
