/*
Task:
Create an interface “MyInterface” with two methods int add(int a,int b) and 
int multiply(int a,int b). Create a class “MyClass” that implements the given interface, do
necessary method overriding implementations. Provide a test class.
*/
using System;
namespace InterfaceProgram {
    public class MainClass {
        static void Main (string[] args) {
            MyClass obj = new MyClass ();
            Console.WriteLine ("add(2,8):{0}", obj.add (2, 8));
            Console.WriteLine ("multiply(9,8):{0}", obj.multiply (9, 8));
            Console.Read ();
        }
    }
    interface MyInterface {
        int add (int a, int b);
        int multiply (int a, int b);
    }
    class MyClass : MyInterface {
        public int add (int a, int b) {
            return a + b;

        }
        public int multiply (int a, int b) {
            return a * b;
        }
    }
}

//Pramesh Karki