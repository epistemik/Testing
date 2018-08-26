
/* Index prints at each 1e7 for the Pentium3
   Limit is 10e7 to test for an even distribution of random() numbers
   Compile with 'g++ -lrt -o test Test.cpp' */

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

const int START = 20 ;

using namespace std;

class Test
{
 private:
  long num    , // initial value to start the loop
       target ;
  long index ; // number of times through the loop

 public:
  Test() : num(-1), index(1)
  {
	 // cout << "Test(): num = " << num << endl;
	 // cout << "Test(): index = " << index << endl;
	}
  
  void go( long target, long limit )
  {
	 // cout << "go(): target = " << target << endl;
	 // cout << "go(): limit = " << limit << endl;

    // create the clock
    timespec ts;
    ts.tv_sec = 0;
    ts.tv_nsec = 0;

    time_t startTime, endTime ;
		srand( time(NULL) );

	  // count will keep track of the number of casts to each possible value
    long* count = new long[ limit ];

    // note start time
		time( &startTime );
    cout << "Start Time: " << ctime( &startTime ) << endl;
    clock_settime( CLOCK_PROCESS_CPUTIME_ID, &ts );
    
    while( num != target  &&  index <= 100000000L )
    {
      num = (long)( rand() % limit ) ;
	    // print out result at each 1e7 times through the loop
      if( index % 10000000L == 0 )
      {
        cout << "Index is " << index << endl;
        cout << "Number is " << num << endl;
      }
      index++ ;
      count[num]++ ;
    }

	  /* print out the final values if the loop ended early,
	     i.e. by reaching the target value */
	  if( index < 100000000L )
		{
		  cout << "Final index is " << (index-1) ;
    	cout << "Final number is " << num << ". \n" ;
		}

	  /* print out the final distribution of the cast values; they should be
	     present in about equal numbers if the random function really is random */
    for( int i = 0; i < limit; i++ )
       cout << "Count [" << i << "] is " << count[i] << endl; 

    // note end time
    clock_gettime( CLOCK_PROCESS_CPUTIME_ID, &ts );
		time( &endTime );
    cout << "End Time: " << ctime( &endTime ) << endl;
    //cout << "Elapsed Time: " << difftime( endTime, startTime ) << endl;
    cout << "Time taken is: " << ts.tv_sec << "." << ts.tv_nsec << " secs" << endl;

  }// go()

};// class Test

int main( int argc, char* argv[] )
{
	long targ, // the target value
	     lim ; // the value to randomize and cast
	
  Test t ;
	/*
  cout << "main(): START = " << START << endl;
  cout << "main(): RAND_MAX = " << RAND_MAX << endl;
  cout << "main(): sizeof(int) = " << sizeof(int) << endl;
  cout << "main(): sizeof(long) = " << sizeof(long) << endl;
  cout << "main(): sizeof(long long) = " << sizeof(long long) << endl;
	*/
	// if no command line parameters, set a default target value
  if( argc > 1 )
    targ = atol( argv[1] );
  else
      targ = START ;
  //cout << "main(): targ = " << targ << endl;

	/* if only one command line parameter, set default limit to a value
	   that CAN'T reach the target value after casting */
  if( argc > 2 )
    lim = atol( argv[2] );
  else
      lim = targ ;
  //cout << "main(): lim = " << lim << endl;

  t.go( targ, lim );
  
}// main()

/* Dec 20, 2000 -- run times of 75.03, 75.14, 75.09 sec
   Dec 21, 2000 -- run times of 74.59, 74.54, 74.53 sec */
