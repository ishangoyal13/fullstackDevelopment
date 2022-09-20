
public class Recursion_ReplacePi {
	// Return the changed string
	public static String replace(String input){
		// Write your code here
        
        int len = input.length();
        String ans = "";
        
        if (len<=1){
            return input;
        }
        
        //starting k pis wala kaam
        
        if (input.charAt(0) == 'p' && input.charAt(1) == 'i'){
            ans =  "3.14" + replace(input.substring(2,len));
            return ans;
        }
        
        // remaining pis
        
        ans =  input.charAt(0) + replace(input.substring(1,len));
        return ans;
        
        //return input;
        
        
        

	}

}
