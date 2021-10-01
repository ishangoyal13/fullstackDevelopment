// switch Statement,while,do...while,for loop are similar to C Programming so skipped in this tutorial
//If you want to know Visit:www.w3schools.com

// foreach loop
using System;
namespace Program {
    class Loops {
        static void Main (string[] args) {
            string[] names = { "Ram", "Hari", "Rama", "Sita" };
            foreach (string i in names) {
                Console.WriteLine (i);
            }
            Console.Read ();
        }
    }
}

// Note:
// break statement:The break statement can  be used to jump out of a loop,switch statement.
//continue statement:The continue statement breaks one iteration (in the loop), if a specified condition occurs, and continues with the next iteration in the loop.

//Pramesh Karki