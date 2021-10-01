using System;
namespace EnumApplication{
    public class MainClass {
        static void Main (string[] args) {
            Level myVar=Level.easy;
            int intEasy=(int)Level.easy;
            Console.WriteLine(myVar);
            Console.WriteLine(intEasy);
            Console.Read ();
        }
        enum Level{
        easy,
        medium,
        hard
    }
    }
    
}

//Pramesh Karki