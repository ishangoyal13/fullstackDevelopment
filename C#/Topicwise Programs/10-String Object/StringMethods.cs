// C# Program to demonstrate differnt string methods
using System;
namespace StringMethodsApplication{
    class StringMethods{
        static void Main(string[] args){
            StringMethodsDemonstration.Demonstrate();

        }
    }
    class StringMethodsDemonstration{
        static public void Demonstrate(){
            string firstName="Pramesh",lastName="Karki";
            Console.WriteLine("String Methods Demonstration:");
            Console.WriteLine("First Name:{0}",firstName);
            Console.WriteLine("Last Name:{0}",lastName);
            Console.WriteLine("FirstName has {0} characters.",firstName.Length);
            Console.WriteLine("firstName.ToUpper():{0}",firstName.ToUpper());
            Console.WriteLine("firstName.ToLower():{0}",firstName.ToLower());
            Console.WriteLine("firstName.Contains('P'):{0}",firstName.Contains("P"));
            Console.WriteLine("firstName.Replace('p','k'):{0}",firstName.Replace("P","K"));
            string fullName=String.Concat(firstName," ",lastName);
            Console.WriteLine("Full Name:{0}",fullName);
            Console.WriteLine("firstName.Equals(lastName):{0}",firstName.Equals(lastName));
            Console.Read();
        }
    }
}
//Pramesh Karki