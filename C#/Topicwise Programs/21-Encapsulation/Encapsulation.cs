// Write a program in C# to demonstrate  the concept of member function and encapsulation
using System;
namespace EncapsulationProgram{
    class MainClass {
        static void Main (string[] args) {
            Person obj = new Person ();
            obj.Display ();
            obj.Walk ();
            obj.Laugh();
            Console.Read ();
        }
    }
    class Person {
        //Fields
        private string FirstName = "Pramesh", lastName = "Karki";
        private int age = 19;
        //Method
        public void Display () {
            Console.WriteLine ("Hello World!I am {0} {1}.I am {2} years old.", FirstName, lastName, age);

        }
        public void Walk () {
            Console.WriteLine ("Walking..");
        }
        public void Laugh(){
            Console.WriteLine("Laughing..");
        }
    }
}
//Pramesh Karki