// C# program to demonstrate to multiple interface
using System;
namespace InterfaceProgram {
    public class MainClass {
        static void Main (string[] args) {
            Test obj=new Test();
            obj.Greet();
            obj.FirstMethod();
            obj.SecondMethod();

            Console.Read ();
        }
    }
    interface IFirstInterface{
        void FirstMethod();
    }
    interface ISecondInterface{
        void SecondMethod();
    }
    class TestClass{
        public void Greet(){
            Console.WriteLine("Demonstration of multiple interface");
        }
    }
    class Test:TestClass,IFirstInterface,ISecondInterface{
        public void FirstMethod(){
            Console.WriteLine("This is first method.");
        }
        public void SecondMethod(){
            Console.WriteLine("This is second method");
        }
    }
}

//Pramesh Karki