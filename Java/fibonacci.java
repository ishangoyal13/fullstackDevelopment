import java.util.Scanner;

public class fibonacci {

    public static void main(String[] args) {
        // write your code here
        System.out.println("Enter the number:-");
        Scanner scan = new Scanner(System.in);
        int number = scan.nextInt();
        int first_term = 0;
        int second_term = 1;
        int i=0;
        for (i=1;i<=number;i++){
            System.out.println(first_term+", ");
            int next_term = first_term+second_term;
            first_term = second_term;
            second_term = next_term;
        }
        scan.close();
    }
}
