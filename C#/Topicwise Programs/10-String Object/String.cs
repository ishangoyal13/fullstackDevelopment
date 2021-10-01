// Actually String  in C# is object of System.String class which contain Properties and Methods that can perform ceratain operations on strings.
using System;//i.e we are using Classes of System namespace
namespace Program{
    class String{
        static void Main(string[] args){
            // string firstName="Pramesh",lastName="Karki";
            string fullName="Pramesh Karki";
            //lenth property

            // The line below this will throw an error because currently I have C# 5 and Interpolation of string was introduced in C# 6 
            // Console.WriteLine($"The length of {fullName} if {fullName.length}");
            
            // Console.WriteLine("The length of "+fullName+" is: "+fullName.Length);

            // .ToLower() and .ToUpper() Method
            // Console.WriteLine("The Uppercase of "+fullName+" is: "+fullName.ToUpper());
            // Console.WriteLine("The Lowercase of "+fullName+" is: "+fullName.ToLower());

            //Concatenation Method
            // string concatenatedString=string.Concat(firstName,lastName);
            // Console.WriteLine("The Concatenated String is: "+concatenatedString);

            //Interpolation of String
            // It was introduced in C# 6
            // string interpolatedString=$"My Full Name is:{firstName} {lastName}";
            // Console.WriteLine(interpolatedString);


            //Acess String
            // Console.WriteLine("fullName[0]:"+fullName[0]);//In this way we can acess characters from the string using index number

            //To Find the index of particular character we have IndexOf() Method

            Console.WriteLine("The index of K ie.fullName.IndexOf('K'):"+fullName.IndexOf('K'));

            //  Substring()
            string lastName=fullName.Substring(fullName.IndexOf('K'));
            Console.WriteLine("Last Name:"+lastName);
            //In this way we can deal with Substring() method

            Console.Read();
        }
    }
}
//Pramesh Karki