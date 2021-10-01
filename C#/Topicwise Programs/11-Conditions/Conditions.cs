// Conditional Statements:
// C# has the following conditional statements:

// Use if to specify a block of code to be executed, if a specified condition is true
// Use else to specify a block of code to be executed, if the same condition is false
// Use else if to specify a new condition to test, if the first condition is false
// Use switch to specify many alternative blocks of code to be executed

using System;
namespace Program{
    class Condition{
        static void Main(string[] args){
            Console.Write("Enter Your Age:");
            int age=Convert.ToInt32(Console.ReadLine());
             if(age>18){
                 Console.WriteLine("Congratulations!!!You Can Vote.");
             }else{
                 Console.WriteLine("Sorry You Cannt Vote");
             }
            
             Console.Read();
        }
    }

}
//Similarly you can demonstrate if statement,else statement,else if statement,switch statement and ternary operator. 
//Pramesh Karki