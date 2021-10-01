// Constructor With Parameters
using System;
namespace Program{
    class Person{
        string name,role,country;
        public Person(string givenName,string givenRole,string givenCountry){
            name=givenName;
            role=givenRole;
            country=givenCountry;
        }
        static void Main(string[] args){
            Person obj=new Person("Ab De Viliers","Batsman","South Africa");
            Console.WriteLine(obj.name);
            Console.WriteLine(obj.role);
            Console.WriteLine(obj.country);
            Console.Read();
        }
    }
} 
//Pramesh Karki