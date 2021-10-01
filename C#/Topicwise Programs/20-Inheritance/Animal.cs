// C# program to demonstrate method overriding.
using System;
namespace InheritanceProgram {
    public class Animal {
        public virtual void Greet () {
            Console.WriteLine ("Hello!,I'm sort of animal.");
        }
    }
    public class Dog : Animal {
        //Overriding Base class Greet() method
        public override void Greet () {
            //Invoking base class method
            base.Greet();
            Console.WriteLine ("Hello!,I am dog");
        }
        static void Main (string[] args) {
            Dog obj = new Dog ();
            obj.Greet ();
            Console.ReadLine ();

        }
    }
}
//Pramesh Karki