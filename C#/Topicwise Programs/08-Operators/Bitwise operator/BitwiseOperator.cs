// C# program to demonstrate bitwise operator.
using System;
namespace BitwiseOperatorProgram {
    class MainClass {
        static void Main (string[] args) {
            BitwiseOperator obj=new BitwiseOperator();
            obj.GetNumbers();
            obj.PerformOperation();
            Console.Read();

        }
    }
    class BitwiseOperator{
        int number1,number2;
        public void GetNumbers(){
            Console.Write("Enter any two number to perform bitwise operation between them:");
            number1=Convert.ToInt32(Console.ReadLine());
            number2=Convert.ToInt32(Console.ReadLine());
        }
        public void PerformOperation(){
            Console.WriteLine("------Bitwise Operations------");
            // Binary AND operation
            Console.WriteLine("{0}&{1}:{2}",number1,number2,(number1&number2));
            //  Binary OR operation
            Console.WriteLine("{0}|{1}:{2}",number1,number2,(number1|number2));
            // Binary X-OR operation
            Console.WriteLine("{0}^{1}:{2}",number1,number2,(number1^number2));
            //Complement
            Console.WriteLine("~({0}):{1}",number1,~number1);
            // Binary left shift operation
            Console.WriteLine("{0}<<2:{1}",number2,(number2<<2));
            // Binary right shift operation
            Console.WriteLine("{0}>>2:{1}",number1,(number1>>2));
        }
    }
}
//Pramesh Karki