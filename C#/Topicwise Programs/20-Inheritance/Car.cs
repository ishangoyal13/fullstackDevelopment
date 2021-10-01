// C# program to demonstrate basic inheritance concept.
using System;
namespace InheritanceProgram {
   public class Car {
        public int maxSpeed;
        private int currSpeed;
        public Car (int max) {
            maxSpeed = max;
        }
        public Car () {
            maxSpeed = 55;
        }
        public int Speed {
            get { return currSpeed; }
            set {
                currSpeed = value;
                if (currSpeed > maxSpeed) {
                    currSpeed = maxSpeed;
                }
            }
        }
    }
    public class miniVan : Car {
        static void Main (string[] args) {
            Console.WriteLine ("Basic Inheritance:");
            miniVan myVan = new miniVan ();
            myVan.Speed = 33;
            Console.WriteLine ("My van is going at {0} MPH.", myVan.Speed);
            Console.WriteLine ("MaxSpeed:{0} MPH", myVan.maxSpeed);
            Console.Read ();
        }

    }
}
//Pramesh Karki