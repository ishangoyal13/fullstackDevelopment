// Introduction:
// Arrays are used to store multiple values in a single variable, instead of declaring separate variables for each value.
// To declare an array, define the variable type with square brackets:
    //  string[] countryName;




using System;
using System.Linq;
namespace Program{
    class Array{
        static void Main(string[] args){
            //Create an array of string
            // string[] countryName={"Nepal","Australia","Argentina","Pakistan"};
           
           
            // // Display Array of string
            // foreach(string element in countryName){
            //     Console.WriteLine(element);
            // }
           
            //Create an array of integers
            //int[] numbers={34,23,42,12,31,345,3453,2131,131,1};
            
            
            // Acessing first element of array
            // Console.WriteLine(numbers[0]);

            // //Changing first element of array
            // numbers[0]=111;

            //     // Display array of intgers
            //  foreach(int element in numbers){
            //      Console.WriteLine(element);
            //  }
       
            //  Array Length
            // Console.WriteLine("The length of an array i.e numbers.length is: "+numbers.Length);

            //  Sort Array
            // Array.Sort(numbers);
            // for(int i=0;i<numbers.Length;i++)
            // {
            //     Console.WriteLine(i);
            // }

            // System.Linq namespace
            //   Console.WriteLine("numbers.Min():"+numbers.Min());
            //   Console.WriteLine("numbers.Max():"+numbers.Max());
            //   Console.WriteLine("numbers.Sum():"+numbers.Sum());

           //Create an array by different ways
          // If you are familiar with C#, you might have seen arrays created with the new keyword, and perhaps you have seen arrays with a specified size as well.
         
          //Create an Array for four elements,and add values later as shown below        
        //  string[] names=new string[4];
        //  names=new string[] {"Pramesh","Rita","Hari","Messi"};
       
        //  Create an Array for four elements and add values right away
        // string[] names=new string[4]{"Messi","AB","Maxwell","Pramesh"};

        //Create an Array for four elements withut specifying size
        // string[] names=new string[] {"Hello","Hi","Namaste","Darsan"};
       
         //Create an Array for four elements,omitting the new keyword and without specifying the size
        //  string[] names={"Pramesh","Hari"}; 
       
        //  NOTE:
        // If you declare an array and initialize it later,you have to use new keyword

        //Declare an Array;
        string[] names;
        //Add values using new
        names=new string[]{"Pramesh","Ram","Thapa"};
      
       foreach(string element in names){
       Console.WriteLine(element);
        }



            Console.Read();
        }
    }
}
//Pramesh karki