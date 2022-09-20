
import java.lang.*;
public class Recursion_StringToInteger { 

		public static int convertStringToInt(String input){
			// Write your code here
	        
	        int len = input.length();
	        int ans = 0;
	        
	        if (len==1){
	            int c = input.charAt(0);
	            return c-48;
	            //return Character.getNumericValue(input);
	        }
	        
	        int b = input.charAt(0);
	        int f = b-48;
	        
	        ans = convertStringToInt(input.substring(1,len));
	        
	        return f* (int) Math.pow(10,len-1) + ans;
	        

		}
}
