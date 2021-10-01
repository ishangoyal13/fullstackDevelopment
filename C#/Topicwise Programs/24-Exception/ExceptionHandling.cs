//C# program to demonstrate exception handling
using System;
namespace ExcepionProgram {
    public class MainClass {
        static void Main (string[] args) {
            try {
                Console.Write ("Enter first Number:");
                int lhs = Convert.ToInt32 (Console.ReadLine ());
                Console.Write ("Enter second Number:");
                int rhs = Convert.ToInt32 (Console.ReadLine ());
                int result = lhs / rhs;
                Console.WriteLine ("Result:{0}", result);

            } 
            catch (DivideByZeroException ex) {
                Console.WriteLine ("Divide by zero exception:{0}", ex.Message);
            }catch(Exception E){
                Console.WriteLine("Exception:{0}",E.Message);
            } finally {
                Console.WriteLine ("Finally Block");
            }
            Console.Read ();
        }
    }
}
//Pramesh Karki