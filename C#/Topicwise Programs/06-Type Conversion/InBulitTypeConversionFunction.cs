// C# Program to demonstrate inbuilt type conversion function
using System;
namespace TypeConversionApplication{
    class InBuiltTypeConversionFunction{
        //Main Method
        static void Main(string[] args){
            TypeConversion obj=new TypeConversion();
            obj.ConvertDataTypes();
            Console.Read();

        }
    }
    class TypeConversion{
        public void ConvertDataTypes(){
            //Initialize variables
            int intNumber=18;
            float floatNumber=12.11F;
            string stringNumber="17";
            double doubleNumber=5656.21122;
            bool booleanValue=true;
            // Type conversion using in built functions
            Console.WriteLine("Convert.ToString(intNumber):"+Convert.ToString(intNumber));
            Console.WriteLine("Convert.ToBoolean(intNumber):"+Convert.ToBoolean(intNumber));
            Console.WriteLine("Convert.ToDouble(intNumber):"+Convert.ToDouble(intNumber));
            Console.WriteLine("Convert.ToString(intNumber):"+Convert.ToString(intNumber));
            Console.WriteLine("Convert.ToInt32(booleanValue):"+Convert.ToInt32(booleanValue));
            Console.WriteLine("Convert.ToInt32(doubleNumber):"+Convert.ToInt32(doubleNumber));
            Console.WriteLine("Convert.ToInt32(floatNumber):"+Convert.ToInt32(floatNumber));
            Console.WriteLine("Convert.ToInt64(stringNumber):"+Convert.ToInt64(stringNumber));
            // Other methods are:ToChar(),ToByte(),ToDecimal(),ToInt16(),ToUInt32() etc
            
        }
    }
}
//Pramesh Karki











