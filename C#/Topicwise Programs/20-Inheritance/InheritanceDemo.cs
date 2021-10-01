// From Given Diagram:
using System;
namespace InheritanceDemoProgram {
    //Student class
    class Student {
        public string name;
        public virtual void Greet () { }
        public virtual void Display () { }

    }
    class UndergraduateStudent : Student { }
    class GraduateStudent : Student { }
    class FreshMan : UndergraduateStudent {
        public FreshMan () {
            name = "undefined";
        }
        public FreshMan (string givenName) {
            name = givenName;
        }
        public override void Greet () {
            Console.WriteLine ("\nHello There,I am FreshMan &");
        }
        public override void Display () {
            Console.WriteLine ("My Name is:{0}", name);
        }
        class Sophomore : UndergraduateStudent {
            public Sophomore () {
                name = "undefined";
            }
            public Sophomore (string givenName) {
                name = givenName;
            }
            public override void Greet () {
                Console.WriteLine ("\nHello There,I am Sophomore &");
            }
            public override void Display () {
                Console.WriteLine ("My Name is:{0}", name);
            }
        }
        class Junior : UndergraduateStudent {
            public Junior () {
                name = "undefined";
            }
            public Junior (string givenName) {
                name = givenName;
            }
            public override void Greet () {
                Console.WriteLine ("\nHello There,I am Junior &");
            }
            public override void Display () {
                Console.WriteLine ("My Name is:{0}", name);
            }
        }
        class Senior : UndergraduateStudent {
            public Senior () {
                name ="undefined";
            }
            public Senior (string givenName) {
                name = givenName;
            }
            public override void Greet () {
                Console.WriteLine ("\nHello There,I am Senior &");
            }
            public override void Display () {
                Console.WriteLine ("My Name is:{0}", name);
            }
        }
        class DoctoralStudent : GraduateStudent {
            public DoctoralStudent () {
                name = "undefined";
            }
            public DoctoralStudent (string givenName) {
                name = givenName;
            }
            public override void Greet () {
                Console.WriteLine ("\nHello There,I am DoctoralStudent &");
            }
            public override void Display () {
                Console.WriteLine ("My Name is:{0}", name);
            }
        }
        class MastersStudent : GraduateStudent {
            public MastersStudent () {
                name = "undefined";
            }
            public MastersStudent (string givenName) {
                name = givenName;
            }
            public override void Greet () {
                Console.WriteLine ("\nHello There,I am MastersStudent &");
            }
            public override void Display () {
                Console.WriteLine ("My Name is:{0}", name);
            }
        }

        class MainClass {
            static void Main (string[] args) {
                //For FreshMan
                FreshMan newFreshMan = new FreshMan ("John Doe");
                newFreshMan.Greet ();
                newFreshMan.Display ();

                //For Sophomore
                Sophomore newSophomore = new Sophomore ("John Smith");
                newSophomore.Greet ();
                newSophomore.Display ();

                //For Junior
                Junior newJunior = new Junior ("Harihar");
                newJunior.Greet ();
                newJunior.Display ();

                //For Senior
                Senior newSenior = new Senior ("Kale");
                newSenior.Greet ();
                newSenior.Display ();

                //For DoctoralStudent
                DoctoralStudent newDoctoralStudent = new DoctoralStudent ("Hari Ray");
                newDoctoralStudent.Greet ();
                newDoctoralStudent.Display ();

                //For MastersStudent
                MastersStudent newMastersStudent = new MastersStudent ("Ab De Villiers");
                newMastersStudent.Greet ();
                newMastersStudent.Display ();

                Console.ReadKey ();
            }
        }
    }
}

//Pramesh Karki