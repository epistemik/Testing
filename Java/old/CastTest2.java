
public class CastTest2
  {
   public static void main(String args[]) // constructor
     {
      int num = 0 ;
      long index = 0 ;
      
      while (num != 99 && index < 1e9)
        {
         num = (int)(Math.random() * 99) ;
         if (index == 1e5 || index == 1e6 || index == 1e7 || index == 1e8 )
           {
            System.out.println("Number is " + num) ;
            System.out.println("Index is " + index + " \n") ;
           }
         index++ ;
        }
      System.out.println("Final number is " + num) ;
     }
     
  } // class CastTest2


