public class HelloRecursive {
    private void hello(int n) {
        System.out.println(n);
        if (n < 1) {
            System.out.println("End");
        } else {
            hello(n-1);
        }
    }
    public static void main(String[] args) {
        HelloRecursive hr = new HelloRecursive();
        hr.hello(100);
    }
}
