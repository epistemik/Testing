
/* Index prints at each 1e7 for the Pentium3
   Limit is 10e7 to test for an even distribution of random() numbers */

public class CastTest5
  {
   public static void main(String args[])
     {
      int num = -1 ; // initial value to start the loop
      long index = 1 ; // number of times through the loop
      int limit ;  // the value to randomize and cast
      int target ; // the target value

	  // if no command line parameters, set a default target value
      if ( args.length > 0 ) target = Integer.parseInt(args[0]) ;
      else target = 99 ;

	  /* if only one command line parameter, set default limit to a value 
	     that can reach the target value after casting */
      if ( args.length > 1 ) limit = Integer.parseInt(args[1]) ;
      else limit = target + 1 ;

	   // count will keep track of the number of casts to each possible value
      long[] count = new long[limit] ;

      while (num != target && index <= 10e7)
        {
         num = (int)(Math.random() * limit) ;
	// print out result at each 1e7 times through the loop
         if (index % 1e7 == 0)
           {
            System.out.println("Index is " + index) ;
            System.out.println("Number is " + num + " \n") ;
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
             System.out.println("Count [" + i + "] is " + count[i] + ". \n") ; }
      catch (Exception e)
         { System.err.println("CastTest5Error: " + e) ; }

     }// main()

  } // class CastTest5

/* Sept 16, 2000 -- performance of 1e7 loops per ~ 7.4 sec */

