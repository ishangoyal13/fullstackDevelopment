// C# Program to demonstrate Explicit type Conversion
using System;
namespace TypeConversionApplication{
    class ExplicitConversion{
        //Main Method
        static void Main(string[] args){
            TypeConversion obj=new TypeConversion();
            obj.Convert();
            Console.Read();

        }
    }
    class TypeConversion{
        public void Convert(){
            // big->small
            double doubleNumber=12323.32322;
           //Explicit Conversion
           int intNumber=(int)doubleNumber;
           //Display result
           Console.WriteLine("Double Number:"+doubleNumber);
           Console.WriteLine("Int Number:"+intNumber);
        }
    }
}
//Pramesh Karki











