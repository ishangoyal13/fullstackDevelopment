
public class Recursion_PairStar {
	// Return the updated string
		public static String addStars(String s) {
			// Write your code here
	        
	        int len = s.length();
	        String ans = "";
	        
	        if (len<=1){
	            return s;
	        }
	        
	        if (s.charAt(0)==s.charAt(1)){
	            ans = s.charAt(0) + "*" + addStars(s.substring(1,len));
	            return ans;
	        }
	        
	        ans = s.charAt(0) + addStars(s.substring(1,len));
	        return ans;

		}

}
