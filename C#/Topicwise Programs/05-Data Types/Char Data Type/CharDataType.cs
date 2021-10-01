// C# Program to demonstrate different in built function of char data type
using System;
namespace DataTypeFunctions{
    class CharDataType{
        static void Main(string[] args){
            CharDataTypeFunctions.Demonstrate();
            Console.Read();
            }
    }
    class CharDataTypeFunctions{
         public static void Demonstrate(){
             char myChar='p';
             Console.WriteLine("Char data type functionality:");
             Console.WriteLine("char.IsDigit(myChar):{0}",char.IsDigit(myChar));
             Console.WriteLine("char.IsLetter(myChar):{0}",char.IsLetter(myChar));
             Console.WriteLine("char.IsWhiteSpace('Hello There!',5):{0}",char.IsWhiteSpace("Hello There!",5));
             Console.WriteLine("char.IsWhiteSpace('Hello There!',6):{0}",char.IsWhiteSpace("Hello There!",6));
             Console.WriteLine("char.IsPunctuation('?'):{0}",char.IsPunctuation(myChar));

         }
    }
}
//Pramesh Karki