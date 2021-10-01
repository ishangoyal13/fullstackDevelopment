// C# Program to demonstrate Implicit Type Conversion
using System;
namespace TypeConversionApplication{
    class ImplicitConversion{
        //Main Method
        static void Main(string[] args){
            TypeConversion obj=new TypeConversion();
            obj.Convert();
            Console.Read();

        }
    }
    class TypeConversion{
        public void Convert(){
            // smaller->big
            int integerNumber=17;
            //Automatic type conversion
            long longNumber=integerNumber;
            //Automatic type conversion
           float floatNumber=integerNumber;
           //Display Result
           Console.WriteLine("Intger Number:"+integerNumber);
           Console.WriteLine("Long Number:"+longNumber);
           Console.WriteLine("Float Number:"+floatNumber);
        }
    }
}
//Pramesh Karki











