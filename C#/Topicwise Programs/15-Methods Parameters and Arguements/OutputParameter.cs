using System;
namespace CalculatorApplication {
    class NumberManipulator {
        public void GetValues (out int x, out int y,out int z) {
            Console.Write ("Enter the first value:");
            x = Convert.ToInt32 (Console.ReadLine ());
            Console.Write ("Enter the second value:");
            y = Convert.ToInt32 (Console.ReadLine ());
            Console.WriteLine("Enter the third value:");
            z=Convert.ToInt32(Console.ReadLine());
        }
        static void Main (string[] args) {
            NumberManipulator n = new NumberManipulator ();
            int a, b,c;
            n.GetValues (out a, out b,out c);
            Console.WriteLine ("a:{0}\nb:{1}\nc:{2}", a, b,c);

            Console.ReadKey ();
        }
    }
}

//Pramesh Karki