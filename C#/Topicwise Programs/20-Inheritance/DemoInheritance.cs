// C# program to show execution stack of base class and child class constructor.
using System;
namespace InheritanceProgram {
    public class ParentClass {
        public ParentClass () {
            Console.WriteLine ("Parent Constructor");
        }
        public void Print () {
            Console.WriteLine ("I am a parent class.");
        }
    }
    public class ChildClass : ParentClass {
        public ChildClass () {
            Console.WriteLine ("Child Constructor");
        }
        public static void Main (string[] args) {
            ChildClass obj = new ChildClass ();
            obj.Print ();
            Console.Read ();
        }
    }

}
//Pramesh Karki