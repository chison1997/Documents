using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Globalization;

namespace DateAndTime
{
    class Program
    {
        static void Main(string[] args)
        {
            //DateTime myValue = DateTime.Now;

            //Console.WriteLine(myValue.ToShortTimeString());
            //Console.WriteLine(myValue.ToString());
            //Console.WriteLine(myValue.ToLongDateString());
            //Console.WriteLine(myValue.ToLongTimeString());
            //Console.WriteLine(myValue.AddDays(100).ToShortDateString());
            //Console.WriteLine(myValue.AddHours(300).ToShortTimeString());
            //Console.WriteLine(myValue.DayOfWeek.ToString());

            //DateTime myBirthDay = new DateTime(1997, 12, 1);
            //Console.WriteLine(myBirthDay.ToShortDateString());
            DateTime myBirthDay = DateTime.Parse("01/12/1997");
            TimeSpan myAge = DateTime.Now.Subtract(myBirthDay);
            Console.WriteLine(myAge.TotalDays);
            Console.ReadLine();
        }
    }
}
