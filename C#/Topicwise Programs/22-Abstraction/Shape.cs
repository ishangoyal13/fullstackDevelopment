// C# program to demonstrate Abstract class and Abstract method.
using System;
namespace AbstractionProgram {
    public class RectangleTester {
        //Main method
        static void Main (string[] args) {
            Rectangle obj = new Rectangle (10, 7);
            //To demonstrate polymorphism
            // Shape obj=new Rectangle(11,2);
            double area = obj.Area ();
            Console.WriteLine ("Rectangle Area:{0}", area);
            Circle circleObj = new Circle (2.1);
            double circleArea = circleObj.Area ();
            Console.WriteLine ("Circle Area:{0}", circleArea);
            Console.Read ();
        }
    }
    //Abstract class
    abstract class Shape {
        //Abstract method
        public abstract double Area ();
    }
    //Child class of abstract class
    class Rectangle : Shape {
        private double length, width;
        public Rectangle (double l = 0, double b = 0) {
            length = l;
            width = b;
        }
        //Overriding abstract method
        public override double Area () {
            return (width * length);
        }
    }
    class Circle : Shape {
        const double PI = 3.1417;
        private double radius;
        public Circle (double r = 0) {
            radius = r;
        }
        //Overriding abstract method
        public override double Area () {
            return (PI * Math.Pow (radius, 2));
        }
    }
}
//Pramesh Karki