/*
  generatePi.c
  author: Mark Sattolo <epistemik@gmail.com>

  The Nilakantha series.
  This is another infinite series to calculate pi that is fairly easy to understand.
  While somewhat more complicated, it converges on pi much quicker than the Leibniz formula.

  π = 3 + 4/(2*3*4) - 4/(4*5*6) + 4/(6*7*8) - 4/(8*9*10) + 4/(10*11*12) - 4/(12*13*14) ...

  For this formula, take three and start alternating between adding and subtracting fractions
  with numerators of 4 and denominators that are the product of three consecutive integers
  which increase with every new iteration.
  Each subsequent fraction begins its set of integers with the highest one used
  in the previous fraction.
  Carry this out even a few times and the results get fairly close to pi.
*/

// Compile with: "gcc -o genPi generatePi.c -lm"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DEFAULT 20

int main( int argc, char* argv[] )
{
	int steps ,   // number of members in the series -- from command line or default
	    limit ,   // for the loop
	    init ,		// initial value of the loop divisor
		  divisor , // for the loop calculation
		  i ;				// loop counter
	
	long double result = 0.0 , // value from the loop
                base = 3.0 ; // base value of result
	
	// check command line for number of steps requested
	if( argc > 1 ) {
	  steps = atoi( argv[1] );
	  if( steps < 1 ) {
	    printf("!! Number of steps must be an integer >= 1 !!\n");
	    steps = 1;
	  }
	}
	else {
			// if no command line parameters, use the default value
	    steps = DEFAULT;
	    printf("** usage: genPi <number of steps>\n\n");
	  }
	
	printf("Will use %d member(s) of the Nilakantha series to approximate pi.\n", steps);
  limit = steps - 1;
  
  for( i=1; i <= limit; i++ ) {
	  init = 2 * i;
	  divisor = init * (init + 1) * (init + 2);
	  result += pow((-1.0),(i+1)) * (4.0/divisor);
	}
  
	// print out the final value
	printf("Final approximation of pi = %.24Lg \n", (base + result));
  
	return 0;
	
}// main()

