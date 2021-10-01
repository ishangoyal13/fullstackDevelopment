//Multiple methods can have the same name as long as the numeber and or/type of parameters are different
using System;
namespace Program{
    class MethodOverloading{
        static void Main(string[] args){
            Console.WriteLine("2-int:"+sum(11,21));
            Console.WriteLine("3-int:"+sum(2,1,2));
            // Console.WriteLine("float:"+sum(21.21,222.2121));
        }
        // static double sum(double a,double b){
        //     return a+b;
        // }
        static int sum(int a,int b){
            return a+b;
        }
        static int sum(int a,int b,int c){
            return a+b+c;
        }
    }
}
//Pramesh Karki