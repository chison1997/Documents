using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Hello
{
    class Program
    {

        public static bool CheckTwoConsonant(String x)
        {
            String allConsonants = "qtrpsdđghklxcvbnm";
            if (String.IsNullOrEmpty(x) || x.Length < 3)
                return false;
            if ((!allConsonants.Contains(x[0]) || (!allConsonants.Contains(x[1]))))
                return false;

            String allTwoConsonants ="th tr ch gh kh nh ";

            return (allTwoConsonants.Contains(x[0].ToString() + x[1].ToString()));
            
        }

        static void Main(string[] args)
        {
            Console.WriteLine(CheckTwoConsonant("cki"));
            Console.ReadLine();
        }
    }
}
