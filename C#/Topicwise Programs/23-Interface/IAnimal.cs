// C# program to demonstrate interface
using System;
namespace InterfaceProgram {
    // Main Class
    public class MainClass {
        static void Main (string[] args) {
            Dog myDog=new Dog();
            myDog.AnimalSound();
            myDog.Sleep();

            Console.Read ();
        }
    }
    //Interface
    interface IAnimal{
        void AnimalSound();
        void Sleep();
    }
    //Implementing Inheritance
    class Dog:IAnimal{
        public void AnimalSound(){
            Console.WriteLine("Dog Says:Haau Haau");
        }
        public void Sleep(){
            Console.WriteLine("Dog Says:ZzZZzzZZZZZZzzzzZZZZZ");
        }
    }
}

//Pramesh Karki