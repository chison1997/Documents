using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;


namespace WindowsFormsApplication4
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            

        }

        private void label2_Click(object sender, EventArgs e)
        {
            
        }

        private void trackBar1_Scroll(object sender, EventArgs e)
        {
            
            label2.Text = "" + trackBar1.Value;
        }

        private void trackBar2_Scroll(object sender, EventArgs e)
        {
            label8.Text = "" + trackBar2.Value;
        }

        private void trackBar3_Scroll_1(object sender, EventArgs e)
        {
            label9.Text = "" + trackBar3.Value;
        }
        
        private void label11_Click(object sender, EventArgs e)
        {

        }

        private void trackBar4_Scroll(object sender, EventArgs e)
        {
            label12.Text = "" + trackBar4.Value;
        }

        private void trackBar5_Scroll(object sender, EventArgs e)
        {
            label14.Text = "" + trackBar5.Value;
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void label5_Click(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void label4_Click(object sender, EventArgs e)
        {

        }

        private void label6_Click(object sender, EventArgs e)
        {

        }

        private void label7_Click(object sender, EventArgs e)
        {

        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            int đt0 = trackBar1.Value, tínhCách = trackBar2.Value, tiền = trackBar3.Value, quyềnLực = trackBar4.Value, họcTập = trackBar5.Value,
                IQ = int.Parse(textBox3.Text), EQ = int.Parse(textBox4.Text),
                dài = UInt16.Parse(textBox1.Text)/10, rộng = UInt16.Parse(textBox2.Text)/10;
            double CSĐT = đt0 + (dài * Math.Pow(2, rộng)) / 10 + tínhCách + tiền + quyềnLực + (IQ + EQ) / 10 + họcTập;
            MessageBox.Show("CSĐT của bạn là: " + CSĐT);
        }
    }
}
