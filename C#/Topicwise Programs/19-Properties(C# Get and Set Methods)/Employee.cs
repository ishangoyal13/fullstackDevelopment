// C# program to demonstrate encapsulation with get & set methods
using System;
namespace GetSetApplication {
    class MainClass {
        static void Main (string[] args) {
            Employee emp = new Employee ("Marvin", 456, 3000);
            emp.GiveBonus (1000);
            emp.DisplayStatus();
            emp.Name="Marv";
            Console.WriteLine("Employee Name:{0}",emp.Name);
            Console.Read ();
        }
    }
    class Employee {
        //Fields
        private string employeeName;
        private int employeeID;
        private float currentPayment;
        //  Parameterized constructor
        public Employee (string name, int id, float payment) {
            employeeName = name;
            employeeID = id;
            currentPayment =payment;
        }
        public void DisplayStatus(){
            Console.WriteLine("----Employee Status-------");
            Console.WriteLine("Employee Name:{0}",employeeName);
            Console.WriteLine("Employee ID:{0}",employeeID);
            Console.WriteLine("Current Payment:{0}",currentPayment);
        }
        public void GiveBonus (float bonusMoney) {
            currentPayment += bonusMoney;
        }
        //Properties
        public string Name {
            get { return employeeName; }
            set {
                if (value.Length > 15)
                    Console.WriteLine ("Error!Name must be less than 16 characters");
                employeeName = value;
            }
        }
        public int ID {
            get { return employeeID; }
            set { employeeID = value; }
        }
        public float Pay {
            get { return currentPayment; }
            set { currentPayment = value; }
        }
    }

}
//Pramesh Karki
