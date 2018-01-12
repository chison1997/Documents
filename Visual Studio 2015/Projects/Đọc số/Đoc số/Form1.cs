using System;
using System.Linq;
using System.Windows.Forms;

namespace Đoc_số
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            char[] x = textBox1.Text.ToCharArray();
            // char[] x = "299792458".ToCharArray();
            //string nhập;
            //Console.Write("Nhập Số :"); nhập = Console.ReadLine();
            //char[] x = nhập.ToCharArray();
            string kq = "";
            int chiềuDài = x.Length;
            for (int i = 0; i < chiềuDài; i++)
            {


                switch (x[i])
                {
                    case '0':
                        {
                            if (chiềuDài == 1) kq = " Không";
                            else if ((new[] { 0, 3, 6, 9 }.Contains((chiềuDài - i) % 12)) && ((x[i + 1] != '0') || (x[i + 2] != '0'))) kq += " Không";

                        }; break;
                    case '1':
                        {
                            if (((chiềuDài - i) % 12 != 11) && ((chiềuDài - i) % 12 != 8) && ((chiềuDài - i) % 12 != 5) && ((chiềuDài - i) % 12 != 2)) { if (((i > 0) && ((x[i - 1] == '1')||(x[i-1]=='0'))) || ((chiềuDài-i)%3== 0)||(i==0)) kq += " Một"; else kq += " Mốt"; }

                        }; break;
                    case '2': kq += " Hai"; break;
                    case '3': kq += " Ba"; break;
                    case '4': kq += " Bốn"; break;
                    case '5': kq += " Năm"; break;
                    case '6': kq += " Sáu"; break;
                    case '7': kq += " Bảy"; break;
                    case '8': kq += " Tám"; break;
                    case '9': kq += " Chín"; break;
                }
                switch ((chiềuDài - i) % 12)
                {
                    case 0:
                    case 3:
                    case 6:
                    case 9:

                        if ((x[i] != '0') || (x[i + 1] != '0') || (x[i + 2] != '0')) kq += " Trăm"; break;
                    //case 10|7|4|1:

                    //    {
                    //        if ((x[i] == '0') && (x[i + 1] != '0')) kq += " Linh";
                    //        if (x[1] == '1') kq += " Mười";
                    //        if ((x[i] != '0') && (x[i] != '1')) kq += " Mươi";
                    //    };  break; 


                    case 10: if ((x[i] != '0') || (x[i - 1] != '0') || (x[i - 2] != '0')) kq += " Tỉ,"; break;
                    case 7: if ((x[i] != '0') || (x[i - 1] != '0') || (x[i - 2] != '0')) kq += " Triệu,"; break;
                    case 4: if ((x[i] != '0') || (x[i - 1] != '0') || (x[i - 2] != '0')) kq += " Nghìn,"; break;
                    case 1: break;
                    default:
                        {

                            if ((x[i] == '0') && (x[i + 1] != '0')) kq += " Linh";
                            if (x[i] == '1') kq += " Mười";
                            if ((x[i] != '0') && (x[i] != '1')) kq += " Mươi";

                        }; break;

                }

            }
            textBox2.Text = kq+".";

        }
    }
}
