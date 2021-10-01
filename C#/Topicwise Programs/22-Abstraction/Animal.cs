// C# program to demonstrate Abstraction
using System;
namespace AbstractionProgram {
    //Abstract class
    public class MainClass {
    //    Main Method
        static void Main (string[] args) {
            Dog myDog=new Dog();
            myDog.AnimalSound();
            myDog.Sleep();

            Console.Read ();
        }
    }
    // Abstract class:- can contain both regular and abstract method
    abstract class Animal{
        // Abstract method(does not have a body)
        public abstract void AnimalSound();
        //Regular method
        public void Sleep(){
            Console.WriteLine("ZZZZZZZ");
        }
    }
    //Derived class(inherited from animal)
    class Dog:Animal{
        //Method overriding
        public override void AnimalSound(){
            Console.WriteLine("Dog Says:haau haau");
        }
    }
}

//Pramesh Karki