
public class Recursion_RemoveX {
	public static String removeX(String input){
		// Write your code here
        
        
        int len = input.length();
        
        String ans = "";
        
        if(len==0){
            return input;
        }
        
        if(input.charAt(0)=='x'){
            return removeX(input.substring(1,len));
        }
        
        ans = input.charAt(0) + removeX(input.substring(1,len));
        return ans;

	}

}
