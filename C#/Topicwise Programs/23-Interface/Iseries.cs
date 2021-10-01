// C# program to demonstrate interface
using System;
namespace InterfaceProgram {
    public class SeriesDemo {
        //Main method
        static void Main (string[] args) {
            ByTwos obj = new ByTwos ();
            for (int i = 0; i < 5; i++)
                Console.WriteLine ("Next value is {0}", obj.GetNext ());
            
            Console.WriteLine ("\nResetting");
            obj.Reset ();
            
            for (int i = 0; i < 5; i++)
                Console.WriteLine ("Next value is {0}", obj.GetNext ());
            
            Console.WriteLine ("\nStarting at 100");
            
            obj.SetStart (100);
            
            for (int i = 0; i < 5; i++)
                Console.WriteLine ("Next value is {0}", obj.GetNext ());
            Console.Read ();
        }
    }
    public interface Iseries {
        int GetNext ();
        void Reset ();
        void SetStart (int x);
    }
    class ByTwos : Iseries {
        int start;
        int val;
        public ByTwos () {
            start = 0;
            val = 0;
        }
        public int GetNext () {
            val += 2;
            return val;
        }
        public void Reset () {
            val = start;
        }
        public void SetStart (int x) {
            start = x;
            val = start;
        }
    }
}

//Pramesh Karki