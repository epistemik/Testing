
public class CastTest
  {
   public static void main(String args[]) // constructor
     {
      int num = -1, target, limit ;

      if ( args.length > 0 ) target = Integer.parseInt(args[0]) ;
      else target = 99 ;

      if ( args.length > 1 ) limit = Integer.parseInt(args[1]) ;
      else limit = target + 1 ;

      while (num != target)
        {
         num = (int)(Math.random() * limit) ;
      	 System.out.println("Next number: " + num) ;
      	}
     }
     
  } // class CastTest


