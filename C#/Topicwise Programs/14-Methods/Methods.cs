// A method is a block of code which only runs when it is called.

// You can pass data, known as parameters, into a method.

// Methods are used to perform certain actions, and they are also known as functions.

// Why use methods? To reuse code: define the code once, and use it many times.

using System;
namespace Program{
// namespace is the container for other classes and namespaces
    class Methods{
        static void Main(string[] args){
            //C# Program exection starts from Main method which is already predefined in C#
        myMethod();
        myMethod();
        myMethod();
        myMethod();

        }
        static void myMethod(){
            // Where static means that the method belongs to the "Methods" class not an object of the "Methods" Class.
            Console.WriteLine("I just got executed");
        }
    }

}

//Pramesh Karki