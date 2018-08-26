
/* Index prints at each 1e7 for the Pentium3
   Limit is 10e7 to test for an even distribution of random() numbers */

#include <iostream>
using namespace std;

public class Test
  {
   public static void main(String args[])
     {
      final int DEFAULT = 20 ;
      int num = -1 ;   // initial value to start the loop
      long index = 1 ; // number of times through the loop
      int limit ;      // the value to randomize and cast
      int target ;     // the target value

	    // if no command line parameters, set a default target value
      if ( args.length > 0 ) target = Integer.parseInt(args[0]) ;
      else target = DEFAULT ;

	    /* if only one command line parameter, set default limit to a value
	       that CAN'T reach the target value after casting */
      if ( args.length > 1 ) limit = Integer.parseInt(args[1]) ;
      else limit = target ;

	    // count will keep track of the number of casts to each possible value
      long[] count = new long[limit] ;

      // note start time
      Date startDate = new Date() ;
      System.out.println("Time: " + startDate.getTime()) ;
      
      while (num != target && index <= 10e7)
        {
         num = (int)(Math.random() * limit) ;
	       // print out result at each 1e7 times through the loop
         if (index % 1e7 == 0)
           {
            System.out.println("Index is " + index) ;
            System.out.println("Number is " + num) ;
           }
         index++ ;
         count[num]++ ;
        }// endwhile

	    /* print out the final values if the loop ended early,
	       i.e. by reaching the target value */
	    if (index < 10e7)
		   {
		    System.out.println("Final index is " + (index-1)) ;
    	    System.out.println("Final number is " + num + ". \n") ;
		   }

	    /* print out the final distribution of the cast values; they should be
	       present in about equal numbers if the random function really is random */
      try
        { for (int i = 0; i < limit; i++)
             System.out.println("Count [" + i + "] is " + count[i]) ; }
      catch (Exception e)
         { System.err.println("javaTestERROR: " + e) ; }

      // note end time
      Date endDate = new Date() ;
      System.out.println("Time: " + endDate.getTime()) ;

     }// main()

  } // class javaTest

/* Dec 20, 2000 -- run times of 75.03, 75.14, 75.09 sec
   Dec 21, 2000 -- run times of 74.59, 74.54, 74.53 sec */
