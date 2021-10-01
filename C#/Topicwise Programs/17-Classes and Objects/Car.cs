//Create a class with three members:two fields and one method
using System;
namespace Program{
    class Car{
        public string color="red";//Fields
        public int maxSpeed=200;//Fields
        public void display(){//Method
            Console.WriteLine("This is car");
        }
    }
    class CarClass{
        static void Main(){
            Car obj=new Car();//Creating Object
            Console.WriteLine(obj.color);
            Console.WriteLine(obj.maxSpeed);
            obj.display();
        }
    }
}