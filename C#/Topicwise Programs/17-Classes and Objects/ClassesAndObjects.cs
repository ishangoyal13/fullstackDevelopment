// Object Oriented Programming(OOP) In C#
// Procedural programming is about writing procedures or methods that perform operations on the data, while object-oriented programming is about creating objects that contain both data and methods.
// Classes and Objects are two main aspects of the object oriented programming

//Lets create a class and its Object

using System;
namespace Program{
    class Car{
        string color="red";//It is a field/attribute
        static void Main(string[] args){
            //Create object of the car class
           //We can create multiple object of one class
            Car obj=new Car();
            Car myObj=new Car();
            Console.WriteLine(obj.color);
            Console.WriteLine(myObj.color);
        }
    }
}