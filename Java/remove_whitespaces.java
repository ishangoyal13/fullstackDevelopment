import java.util.Scanner;

class Main {
  public static void main(String[] args) {

    // create an object of Scanner
    Scanner scan = new Scanner(System.in);
    System.out.println("Enter the string");

    // take the input
    String input = scan.nextLine();
    System.out.println("Original String: " + input);

    // remove white spaces
    input = input.replaceAll("\\s", "");
    System.out.println("Final String: " + input);
    scan.close();
  }
}