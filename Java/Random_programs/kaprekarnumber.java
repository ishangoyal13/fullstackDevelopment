import java.util.Scanner;

class Main
{
    public static void main(String[] args)
    {
     
        Scanner in=new Scanner(System.in);
		int k=in.nextInt(),c=0;
		for(int i=0;i<k;i++)
        { int n=in.nextInt();
         c=0;
          if (n == 1)   
          {System.out.println(1);
          }
         if(n==1)
           continue;
	        int sq_n = n * n;   
	        int count_digits = 0;   
	        while (sq_n != 0)   
	        {   
	            count_digits++;   
	            sq_n /= 10;   
	        }   
	        sq_n = n*n;   
	        for (int r_digits=1; r_digits<count_digits; r_digits++)   
	        {   
	             int eq_parts = (int) Math.pow(10, r_digits);   
	            if (eq_parts == n)   
	                continue;   
	             int sum = sq_n/eq_parts + sq_n % eq_parts;   
	             if (sum == n)   
	             { System.out.println(1); 
	             c++;
	             }
	        }
	        
	if(c==0)
	     System.out.println(0);
        }
      
    }
}