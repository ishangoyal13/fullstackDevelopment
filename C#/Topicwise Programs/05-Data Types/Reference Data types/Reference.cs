// String,Object and dynamic are reference data types in c#
using System;
namespace ReferenceVariableProgram{
    class MainClass {
        static void Main (string[] args) {
            string myName="Pramesh Karki",tempName;
            tempName=myName;
            tempName="Temp Name";
            Console.WriteLine(tempName);
            Console.WriteLine(myName);

            Console.Read ();
        }
    }
}

//Pramesh Karki