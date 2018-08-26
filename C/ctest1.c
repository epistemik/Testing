/* cTest1.c
	Index prints at each 1e7 for the Pentium3 */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(int argc, char* argv[])
	{
	int limit,   // the value to randomize and cast
		 target,  // the target value
		 num = -1 ; // initial value to start the loop
	long index = 1 ; // number of times through the loop

	// if no command line parameters, set a default target value
	if ( argc > 1 ) target = atoi(argv[1]) ;
	else target = 99 ;

	/* if only one command line parameter, set default limit to a value
		that can reach the target value after casting */
	if ( argc > 2 ) limit = atoi(argv[2]) ;
	else limit = target + 1 ;

	srand((unsigned int) time(0)) ; // randomize rand()

	while (num != target && index <= 20e7)
	  {
		num = (int)(rand() % limit) ;
		// print out result at each 1e7 times through the loop
		if (index % 10000000 == 0)
		  {
			printf("Index is %d \n", index) ;
			printf("Number is %d \n", num) ;
		  }
		index++ ;
	  }// endwhile

	if (index < 10e7)
		{
		printf("Final index is %d \n", index-1) ;
		printf("Final number is %d \n", num) ;
		}

	return 0 ;
}// main()
