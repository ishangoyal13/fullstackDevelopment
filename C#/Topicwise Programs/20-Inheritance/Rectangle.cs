// C# program to invoke the base class parameterized constructor using child class object. 
using System;
namespace RectangleApplication {
    public class ExecuteRectangle {
        static void Main (string[] args) {
            TableTop obj = new TableTop (4.5, 7.5);
            // Rectangle obj = new TableTop (4.5, 7.5);  //Both Works
            obj.Display ();
            Console.Read ();
        }
    }
    //Base class
    public class Rectangle {
        protected double length, width;
        public Rectangle (double l, double w) {
            length = l;
            width = w;
        }
        public double GetArea () {
            return length * width;
        }
        public virtual void  Display () {
            Console.WriteLine ("Length:{0}", length);
            Console.WriteLine ("Width:{0}", width);
            Console.WriteLine ("Area:{0}", GetArea ());
        }
    }
    //Child Class
    public class TableTop : Rectangle {
        private double cost;
        //This constructor initializes the base class fields 
        public TableTop (double l, double w) : base (l, w) { }
        public double GetCost () {
            cost = GetArea () * 70;
            return cost;
        }
        //Overriding Display method
        public override void Display () {
            //To call the base class Display Method
            base.Display ();
            Console.WriteLine ("Cost:{0}", GetCost ());
        }
    }
}
//Pramesh Karki