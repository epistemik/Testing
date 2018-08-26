/* cTest2.c
	Index prints at each 1e7 for the Pentium3
	Limit is 10e7 to test for an even distribution of random() numbers */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[])
	{
	int limit,       // the value to randomize and cast
		 target,      // the target value
		 num = -1,    // initial value to start the loop
		 i ;
	long index = 1 ; // number of times through the loop
	long* count ;    // array to track the number of times each number appears

	// if no command line parameters, set a default target value
	if ( argc > 1 ) target = atoi(argv[1]) ;
	else target = 99 ;

	/* if only one command line parameter, set default limit to a number
		that can reach the target value after casting */
	if ( argc > 2 ) limit = atoi(argv[2]) ;
	else limit = target + 1 ;

	srand((unsigned int) time(0)) ; // randomize rand()

	// count will keep track of the number of casts to each possible value
	count = (long*) malloc(limit * sizeof(long)) ;

	while (num != target && index <= 10e7)
	  {
		num = (int)(rand() % limit) ;
		// print out result at each 1e7 times through the loop
		if (index % 10000000 == 0)
		  {
			printf("Index is %d \n", index) ;
			printf("Number is %d \n", num) ;
		  }
		index++ ;
		count[num]++ ;
	  }// endwhile

	/* print out the final values if the loop ended early,
		i.e. by reaching the target value */
	if (index < 10e7)
		{
		printf("Final index is %d \n", index-1) ;
		printf("Final number is %d \n", num) ;
		}
	/* print out the final distribution of the cast values; they should be
		present in about equal numbers if the random function really is random */
	for (i = 0; i < limit; i++)
		printf("Count [%d] is %d \n", i, count[i]) ;

	return 0 ;
}// main()

/* Sept 16, 2000 -- runs at 1e7 loops per ~3 sec  */
