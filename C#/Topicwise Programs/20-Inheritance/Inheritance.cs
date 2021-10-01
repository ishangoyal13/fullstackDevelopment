using System;
namespace InheritanceProgram {
    class Vehicle { //Base class(parent)
        public string brand = "Ford"; //Vehicle field
        public void horn () { //Vehicle method
            Console.WriteLine ("Tuttt,Tuuuuuuut!");
        }

    }

    class Car : Vehicle { //Derived class(child)
        public string modelName = "Mustang"; //Car field

    }
    class Program {
        static void Main (string[] args) {
            //Create a myCar Object
            Car myCar = new Car ();
            //Call the horn() method(from the vehicle class )on the myCar object
            myCar.horn ();
            // Display the value of the brand field (from the Vehicle class) and the value of the modelName from the Car class
            Console.WriteLine (myCar.brand + " " + myCar.modelName);

        }
    }
}
// Note:
// The sealed Keyword
// If you don't want other classes to inherit from a class, use the sealed keyword
//Pramesh Karki