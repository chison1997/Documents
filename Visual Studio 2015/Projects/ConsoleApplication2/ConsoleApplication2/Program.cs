using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication2
{
    class Program
    {
        static void Main(string[] args)
        {
            /*
            int x;
             int y;

             x = 7;
             y = x + 3;
             Console.WriteLine(y);*/

            //string myFirstName;
            //myFirstName = "Bob";

            //string myFirstname = "Bob";
            //var myFirstname = "Bob";
            //string myFirstname;
            //var myFristName=""; 


            //Console.WriteLine(myFirstName);


            int x = 7;
            //string y= "Bob";
            string y = "5";

            string myFirstTry = x.ToString() + y;

            //int mySecondTry = x + y;
            int mySecondTry = x + int.Parse(y);
            Console.WriteLine(myFirstTry);


        

           
            Console.ReadLine();
            

        }
    }
}
