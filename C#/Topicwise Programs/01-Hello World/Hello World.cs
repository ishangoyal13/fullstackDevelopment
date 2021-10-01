
//C# program to print Hello World!
using System;
//namespace declaration
namespace FirstApp
{   
    //Class declaration
    class  MainClass{
        // Main method
        public static void Main(string[] args){
            //Statement for printing
            Console.WriteLine("Hello World!");
            //To prevents the screen from running and closing quickly
            Console.Read();
        }
    }
    
}
// Pramesh Karki
// If you omit using System;,you would have to use System.Console.WriteLine("");to print output text.