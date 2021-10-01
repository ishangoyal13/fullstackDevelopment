using System;
namespace GetSetMethod {
    class MainClass {
        static void Main (string[] args) {
            Person obj = new Person ();
            obj.Display ();
            obj.Name = "Pramesh Karki";
            obj.Age = 19;
            obj.Display ();

            Console.Read ();
        }
    }
    class Person {
        private string name;//field
        private int age;
        public Person () {
            name = "undefined";
            age = 0;
        }
        public void Display () {
            Console.WriteLine ("Name:{0}", name);
            Console.WriteLine ("Age:{0}", age);
        }
        public string Name {//Property
            get { return name; }
            set { name = value; }
        }
        public int Age {
            get { return age; }
            set { age = value; }
        }
    }
}

//Pramesh Karki