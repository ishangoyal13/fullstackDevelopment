// A property is like a combination of a variable and a method, and it has two methods: a get and a set method:
using System;
namespace PropertiesDemoApplication{
    class Properties{
        static void Main(string[] args){
            MyClass obj=new MyClass();
            Console.WriteLine(obj.Name);
            obj.Name="Pramesh Karki";
            Console.WriteLine(obj.Name);
            Console.Read();

        }
    }
    class MyClass{
        private string name="Pramesh";//private field
        public string Name{
            get{return name;}
            set{name=value;}
        }
    }
}
// Note:
// C# also provides a way to use short-hand / automatic properties, where you do not have to define the field for the property, and you only have to write get; and set; inside the property.
// public string Name{//Property
//     get;set;
// }
//In this way we can acess the private members of the class from outside the class
// Pramesh Karki