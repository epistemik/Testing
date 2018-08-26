
/* Index prints at each 1e7 for the Pentium3
   Limit is 10e7 to test for an even distribution of random() numbers */

import java.util.Date ;

public class javaTest
  {
   public static void main(String args[])
     {
      final int DEFAULT = 20 ;
      long index = 1 ; // number of times through the loop
      int num = -1 ,   // initial value to start the loop
          limit ,      // the value to randomize and cast
          target ;     // the target value

      // if no command line parameters, set a default target value
      if( args.length > 0 )
        target = Integer.parseInt(args[0]) ;
      else
          target = DEFAULT ;

      /* if only one command line parameter, set default limit to a value
         that CAN'T reach the target value after casting */
      if( args.length > 1 )
        limit = Integer.parseInt(args[1]) ;
      else
          limit = target ;

      // count will keep track of the number of casts to each possible value
      long[] count = new long[limit] ;

      // note start time
      Date startDate = new Date() ;
      long startTime = startDate.getTime() ;
      System.out.println("Start Time: " + startTime ) ;

      while( num != target && index <= 10e7 )
        {
         num = (int)(Math.random() * limit) ;
         // print out result at each 1e7 times through the loop
         if( index % 1e7 == 0 )
           {
            System.out.println("Index is " + index) ;
            System.out.println("Number is " + num) ;
           }
         index++ ;
         count[num]++ ;
        }// endwhile

        /* print out the final values if the loop ended early,
           i.e. by reaching the target value */
        if( index < 10e7 )
           {
            System.out.println("Final index is " + (index-1)) ;
            System.out.println("Final number is " + num + ". \n") ;
           }

      /* print out the final distribution of the cast values; they should be
         present in about equal numbers if the Math.random() really is random */
      try
        { for (int i = 0; i < limit; i++)
             System.out.println("Count [" + i + "] is " + count[i]) ; }
      catch( Exception e )
         { System.err.println("javaTestERROR: " + e) ; }

      // note end time and calculate running time
      Date endDate = new Date() ;
      long endTime = endDate.getTime() ;
      System.out.println("Finish Time: " + endTime ) ;
      double duration = (double)( (endTime - startTime)/1000.0 ) ;
      System.out.println("Program Run Time: " + duration ) ;

     }// main()

  } // class javaTest

/* Dec 20, 2000 -- run times of 75.03, 75.14, 75.09 sec
   Dec 21, 2000 -- run times of 74.59, 74.54, 74.53 sec
   Nov 28, 2001 -- run times of 180.73, 181.12, 180.89 sec on Sun Ultra-10
   ------------------------------------------------------------------------
   New version
   Dec 2, 2001 -- run time of 78.27 */
