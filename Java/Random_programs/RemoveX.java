import java.util.Scanner;

public class Main
{
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		String input = s.nextLine();
		System.out.println(removeX(input));
	}
	public static String removeX(String input){
		// Write your code here
        
        // bass case 
        if(input.length() == 0)
            return input;
        
        // small calculation
        String ans= "";
        if(input.charAt(0) != 'x')
            ans = ans + input.charAt(0);
        
        // recursive call
        String smallans = removeX(input.substring(1));
        return ans+smallans;

	}
}
