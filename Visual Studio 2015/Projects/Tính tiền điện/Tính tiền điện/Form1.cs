using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Tính_tiền_điện
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            //int sốĐiện = int.Parse(textBox2.Text) - int.Parse(textBox1.Text);
            //int tiền = 0;
            //if (sốĐiện <= 50) tiền = sốĐiện * 1484;   //Nấc 1
            //else if ((sốĐiện >= 51) && (sốĐiện <= 100)) tiền = 74200 + (sốĐiện - 50) * 1533;   //Nấc 2
            //else if ((sốĐiện >= 101) && (sốĐiện <= 200)) tiền = 150850 + (sốĐiện - 100) * 1786;  //Nấc 3
            //else if ((sốĐiện >= 201) && (sốĐiện <= 300)) tiền = 329450 + (sốĐiện - 200) * 2242;  //Nấc 4
            //else if ((sốĐiện >= 301) && (sốĐiện <= 400)) tiền = 553650 + (sốĐiện - 300) * 2503;  //Nấc 5
            //else tiền = 803950 + (sốĐiện - 400) * 2587;
            //label4.Text = tiền.ToString();

        }

        private void textBox1_TextChanged(object sender, EventArgs e) 
        {   
            
                //int sốĐiện = int.Parse(textBox2.Text) - int.Parse(textBox1.Text);
                //int tiền = 0;
                //if (sốĐiện <= 50) tiền = sốĐiện * 1484;   //Nấc 1
                //else if ((sốĐiện >= 51) && (sốĐiện <= 100)) tiền = 74200 + (sốĐiện - 50) * 1533;   //Nấc 2
                //else if ((sốĐiện >= 101) && (sốĐiện <= 200)) tiền = 150850 + (sốĐiện - 100) * 1786;  //Nấc 3
                //else if ((sốĐiện >= 201) && (sốĐiện <= 300)) tiền = 329450 + (sốĐiện - 200) * 2242;  //Nấc 4
                //else if ((sốĐiện >= 301) && (sốĐiện <= 400)) tiền = 553650 + (sốĐiện - 300) * 2503;  //Nấc 5
                //else tiền = 803950 + (sốĐiện - 400) * 2587;
                //label4.Text = tiền.ToString();
            
        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {
            if (textBox2.Text != "")
            {
                int sốĐiện = int.Parse(textBox2.Text) - int.Parse(textBox1.Text);
                int tiền = 0;
                if (sốĐiện >= 0)
                {
                    if (sốĐiện <= 50) tiền = sốĐiện * 1484;   //Nấc 1
                    else if ((sốĐiện >= 51) && (sốĐiện <= 100)) tiền = 74200 + (sốĐiện - 50) * 1533;   //Nấc 2
                    else if ((sốĐiện >= 101) && (sốĐiện <= 200)) tiền = 150850 + (sốĐiện - 100) * 1786;  //Nấc 3
                    else if ((sốĐiện >= 201) && (sốĐiện <= 300)) tiền = 329450 + (sốĐiện - 200) * 2242;  //Nấc 4
                    else if ((sốĐiện >= 301) && (sốĐiện <= 400)) tiền = 553650 + (sốĐiện - 300) * 2503;  //Nấc 5
                    else tiền = 803950 + (sốĐiện - 400) * 2587;
                }
                tiền = tiền * 110 / 100;
                label4.Text = tiền.ToString()+" VNĐ";
                label6.Text = đọcSố(tiền.ToString()) + " Đồng";
            }
        }

        private static string đọcSố(string s)
        {

            char[] x = s.ToCharArray();
            string kq = "";
            int chiềuDài = x.Length;
            for (int i = 0; i < chiềuDài; i++)
            {


                switch (x[i])
                {
                    case '0':
                        {
                            if (chiềuDài == 1) kq = " Không";
                            else if ((new[] {0,3,6,9}.Contains((chiềuDài-i)%12)) && ((x[i + 1] != '0') || (x[i + 2] != '0'))) kq += " Không";

                        }; break;
                    case '1':
                        {
                            if (((chiềuDài - i) % 12 != 11) && ((chiềuDài - i) % 12 != 8) && ((chiềuDài - i) % 12 != 5) && ((chiềuDài - i) % 12 != 2)) { if (((i > 0) && ((x[i - 1] == '1') || (x[i - 1] == '0'))) || ((chiềuDài - i) % 3 == 0) || (i == 0)) kq += " Một"; else kq += " Mốt"; }

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
           

            return kq ;
        }

        
    }
}
