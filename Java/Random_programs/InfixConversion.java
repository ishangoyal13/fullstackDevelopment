import java.util.Scanner;
import java.util.Stack;

public class InfixConversion {
    public static int precedence(char op) {
        if(op=='+' || op=='-')
            return 1;
        return 2;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String infix = sc.nextLine();
        Stack<String> prefix = new Stack<>();
        Stack<String> postfix = new Stack<>();
        Stack<Character> operators = new Stack<>();

        for (int i = 0; i < infix.length(); i++) {
            char c = infix.charAt(i);
            if(c=='(') 
                operators.push(c);
            else if(c=='+' || c=='-' || c=='*' || c=='/') {
                while(!operators.isEmpty() && operators.peek()!='(' && precedence(c)<=precedence(operators.peek())) {
                    char op = operators.pop();
                    String postfixB = postfix.pop();
                    String postfixA = postfix.pop();
                    postfix.push(postfixA + postfixB + op);

                    String prefixB = prefix.pop();
                    String prefixA = prefix.pop();
                    prefix.push(op + prefixA + prefixB);
                }
                operators.push(c);
            }
            else if(c==')') {
                while(!operators.isEmpty() && operators.peek()!='(') {
                    char op = operators.pop();
                    String postfixB = postfix.pop();
                    String postfixA = postfix.pop();
                    postfix.push(postfixA + postfixB + op);

                    String prefixB = prefix.pop();
                    String prefixA = prefix.pop();
                    prefix.push(op + prefixA + prefixB);
                }
                if(!operators.isEmpty()) {
                    operators.pop();
                }
            }
            else {
                postfix.push(c+"");
                prefix.push(c+"");
            }
        }
        while(!operators.isEmpty()) {
            char op = operators.pop();
            String postfixB = postfix.pop();
            String postfixA = postfix.pop();
            postfix.push(postfixA + postfixB + op);

            String prefixB = prefix.pop();
            String prefixA = prefix.pop();
            prefix.push(op + prefixA + prefixB);
        }

        System.out.println(postfix.peek());
        System.out.println(prefix.peek());
    }
}
