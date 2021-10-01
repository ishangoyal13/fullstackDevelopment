// Parameters->Function definition
// Arguements->Function call
// Information can be passed to methods as parameter
using System;
namespace Program{
    class ParameterAndArguements{
        static void Main(string[] args){
        //    DisplayName("Pramesh Karki");//"Pramesh Karki" was passed as function arguements 
        //    DisplayName("Lionel Messi");
        //    DisplayName("AB De Villiers");

        // DisplayName("Pramesh");
        // DisplayName("Maya");
        
        // DisplayName("Lionel","Messi");


        // Named Arguements
        //This way,the order of arguements doesnt matter
        // DisplayInfo(firstName:"Pramesh",gender:"Male",lastName:"Karki");
        DisplayInfo("Limbu");
        
        
        }
        //Difference Between parameters and Arguements
        // static void DisplayName(string name){//here name as function parameter
        //     Console.WriteLine("Name is:"+name);
        // }

        // Default Parameters
        // static void DisplayName(string firstName,string lastName="Karki"){
        //     // If we call the method without an arguement,it uses default value
        //     Console.WriteLine("Name is:"+firstName+" "+lastName);
        //     // NOTE:
        //     // A parameter with a default value,is often known as "Optional Parameter"
        // }



        // Named Arguements:
        static void DisplayInfo(string firstName="Pramesh",string gender="Male",string lastName="Karki"){
            Console.WriteLine(firstName);
            Console.WriteLine(gender);
            Console.WriteLine(lastName);
        }
    }
}

//Pramesh Karki