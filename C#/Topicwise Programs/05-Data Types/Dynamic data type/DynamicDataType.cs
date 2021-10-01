// C# program to demonstrate dynamic data type
using System;
namespace DynamicDataTypeApplication {
    class MainClass {
        static void Main (string[] args) {
            dynamic myVariable = 1;
            Console.WriteLine ("myVariable:{0}", myVariable);
            Console.WriteLine("Its type:{0}",myVariable.GetType());
            myVariable = "Pramesh Karki";
            Console.WriteLine ("myVariable:{0}", myVariable);
            Console.WriteLine("Its type:{0}",myVariable.GetType());
            Console.Read ();
        }
    }
}

//Pramesh Karki