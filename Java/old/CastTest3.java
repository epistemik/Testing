
/* Index prints at each 1e5 for the Sparc20 */

public class CastTest3
  {
   public static void main(String args[])
     {
      int num = -1 ;
      long index = 1 ;
      int limit ;
      int target ;
      
      if ( args.length > 0 ) target = Integer.parseInt(args[0]) ;
      else target = 99 ;

      if ( args.length > 1 ) limit = Integer.parseInt(args[1]) ;
      else limit = 100 ;
      
      
      while (num != target && index < 1e9)
        {
         num = (int)(Math.random() * limit) ;
         if (index % 1e5 == 0)
           {
            System.out.println("Index is " + index) ;
            System.out.println("Number is " + num + " \n") ;
           }
         index++ ;
        }
      System.out.println("Final index is " + (index-1)) ;
      System.out.println("Final number is " + num + " \n") ;
     }
     
  } // class CastTest3


