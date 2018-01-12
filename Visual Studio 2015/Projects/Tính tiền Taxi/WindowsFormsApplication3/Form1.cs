using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApplication3
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            //string s = textBox1.Text;
            //switch (s)
            //{
            //case "0":
            //     MessageBox.Show("Không"); break;
            //case "1" :
            //     MessageBox.Show("Một"); break;
            //case "2":
            //     MessageBox.Show("Hai"); break;
            //case "3":
            //     MessageBox.Show("Ba"); break; 
            //case "4":
            //     MessageBox.Show("Bốn"); break; 
            //case "5":
            //     MessageBox.Show("Năm"); break; 
            //case "6":
            //     MessageBox.Show("Sáu"); break; 
            //case "7":
            //     MessageBox.Show("Bảy"); break; 
            //case "8":
            //     MessageBox.Show("Tám"); break; 
            //case "9":
            //     MessageBox.Show("Chín"); break; 
            //default:
            //     MessageBox.Show("Mình chưa được dạy số này");break; 
            
            
            }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            //string sGiatri = textBox1.Text;
            uint iSoKm = 0;
            if (textBox1.Text != "")
            {
                try { iSoKm = uint.Parse(textBox1.Text);  } catch (Exception ex) { MessageBox.Show(ex.Message); }
                finally
                {
                    uint iTienPhaiTra = 0;
                    for (int i = 1; i <= iSoKm; i++)
                    {
                        if (i == 1) { iTienPhaiTra = 12000; continue; }
                        else if ((i >= 2) && (i <= 5)) { iTienPhaiTra += 12000 * 95 / 100; continue; }
                        else if ((i >= 6) && (i <= 10)) { iTienPhaiTra += 12000 * 90 / 100; continue; }
                        else { iTienPhaiTra = iTienPhaiTra + ((iSoKm - 10) * 12000 * 85 / 100); break; }
                       
                    }
                    textBox2.Text = iTienPhaiTra.ToString();
                }
            }
        }
                 
           
            
        

        private void Form1_Load(object sender, EventArgs e)
        {

        }
    }
    }

