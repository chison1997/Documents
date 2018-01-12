using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication3
{
    class Program
    {
        static void Main(string[] args)
        {
            //int[] numbers = new int[5];
            //numbers[0] = 4;
            //numbers[1] = 8;
            //numbers[2] = 15;
            //numbers[3] = 16;
            //numbers[4] = 23;

            /*int[] numbers = new int[] { 4, 8, 15, 16, 23, 42 };
            foreach (int number in numbers)
                Console.WriteLine(number);*/

            //string zig = "You can get what you want out of life if you help enough other people get what they want.";
            //char[] charArray = zig.ToCharArray();
            //Array.Reverse(charArray);
            //foreach (char zigchar in charArray)
            //    Console.Write(zigchar);

            string biếnCủaTui = siêuBíMật("Vương Chí Sơn");
            Console.WriteLine(biếnCủaTui);
            Console.ReadLine();
         }

        private static string siêuBíMật()
            {
            return "Xin chào !";          
            }        
        private static string siêuBíMật(string tên)
        {
            return String.Format("Xin chào, {0}", tên);
        }
    }
}
