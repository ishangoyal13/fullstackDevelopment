// Constructors:A constructor is a special method that is used to initialize objects. The advantage of a constructor, is that it is called when an object of a class is created. It can be used to set initial values for fields:
using System;
namespace Program{
    class Person{
        string name;
        public Person(){
            name="Pramesh Karki";

        }
        static void Main(string[] args){
            Person obj=new Person();
            Console.WriteLine(obj.name);
            Console.Read();
        }
    }
}
//Pramesh Karki