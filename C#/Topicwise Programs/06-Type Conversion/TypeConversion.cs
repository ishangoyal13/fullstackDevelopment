// Type Casting
// Type casting is when you assign a value of type to another type.
// In C# There are two types of casting.
// 1.Implicit Casting(Automatically):
    // Converting a smaller type to larger type size.
    // char->int->long->float->double 
// 2.Explicit Casting(Manually)
    //Converting a larger type to a smaller size type
    // double->float->long->int->char

// EXAMPLES
 using System;
 namespace Program{
     class TypeConversion{
         static void Main(string[] args){
            //  int myInt=9;
            //  double MyDouble=myInt;
            //  -->Implicit casting  is done automatically when passing a smaller size type to a larger size type
            //  Console.WriteLine(myInt);
            //  Console.WriteLine(MyDouble);
            
            // -->Explicit Casting must be done manually by placing the type in paranthesis in front of the value.
            // float floatNumber=10.1010F;
            // int intNumber=(int) floatNumber;
            // Console.WriteLine(floatNumber);
            // Console.WriteLine(intNumber);


            // By using inbuilt function
            // It is also possible to convert data types explicitly by using built-in methods such as:
            // Convert.ToBoolean();
            // Convert.ToDouble();
            // Convert.ToString();
            // Convert.ToInt32(int);
            // Convert.ToInt64(long);

             int myInt=11;
             double myDouble=99.11110121;
             bool myBoolean=false;
             Console.WriteLine(Convert.ToString(myInt));
             Console.WriteLine(Convert.ToDouble(myInt));
             Console.WriteLine(Convert.ToInt32(myDouble));
             Console.WriteLine(Convert.ToString(myBoolean));
             Console.Read();
            //  Where Convert is the class of the System Namespace
         }
     }
 }   

 //Pramesh Karki