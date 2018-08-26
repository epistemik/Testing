/* cTest.c
	Index prints at each 1e7 for the Pentium3
	Limit is 10e7 to test for an even distribution of random() numbers */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys\timeb.h>

#define DEFAULT 20

int main(int argc, char* argv[])
  {
	struct timeb t;
	int limit,       // the value to randomize and cast
		 target,      // the target value
		 num = -1,    // initial value to start the loop
		 i ;
	long index = 1 ; // number of times through the loop
	long* count ;    // array to track the number of times each number appears

	// if no command line parameters, set a default target value
	if ( argc > 1 ) target = atoi(argv[1]) ;
	else target = DEFAULT ;

	/* if only one command line parameter, set default limit to a number
		that can't reach the target value after casting */
	if ( argc > 2 ) limit = atoi(argv[2]) ;
	else limit = target ;

	srand((unsigned int) time(0)) ; // randomize rand()

	// count will keep track of the number of casts to each possible value
	count = (long*) calloc(limit, sizeof(long)) ;
	// malloc doesn't zero count[0] and count[1] properly
	if (count == NULL)
	  fprintf(stderr, "Could not allocate memory! \n") ;

	// note the start time
	ftime(&t);
	printf("Seconds: %ld.%d\n", t.time, t.millitm);
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

	// note the end time
	ftime(&t);
	printf("Seconds: %ld.%d\n", t.time, t.millitm);
	return 0 ;
  }// main()

/*Dec 20, 2000:
	compiled at command line with bccr ('cTest.exe') - run time is ~30.3 sec
	compiled from IDE with make or build ('cProj.exe') - run time is ~17.0 sec!! 
  Dec 21, 2000:
	compiled at command line with bccr ('cTest.exe') - run time is ~30.2 sec
	compiled from IDE with make or build ('cProj.exe') - run time is ~16.8 sec!! */
