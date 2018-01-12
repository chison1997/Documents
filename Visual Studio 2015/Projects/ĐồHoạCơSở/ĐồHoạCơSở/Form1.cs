using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ĐồHoạCơSở
{
    public partial class Form1 : Form
    {
        Pen pen = new Pen(Color.Red, 3f);
        
        Graphics grs;
        public Form1()
        {
            InitializeComponent();
            grs = panel1.CreateGraphics();
            
            


        }

        private void button1_Click(object sender, EventArgs e)
        {
            //Point pt1 = new Point(0,0), pt2 = new Point(100,100);
            //Pen pen = new Pen(Color.Red, 1f);
            //grs.DrawLine(pen, pt1, pt2);
            SolidBrush sbr = new SolidBrush(Color.Red);
            grs.FillRectangle(sbr, 20, 50, 100, 100);

        }
        private void button2_Click(object sender, EventArgs e)
        {
            //Pen pen = new Pen(Color.Red, 2f);
            //Point pt1 = new Point(10, 10);
            //Point pt2 = new Point(50, 100);
            //grs.DrawRectangle(pen, pt1.X, pt1.Y, 50, 100);
            SolidBrush sbr = new SolidBrush(Color.Blue);
            grs.FillEllipse(sbr, 20, 50, 100, 100);

        }
      
        private void panel1_MouseMove(object sender, MouseEventArgs e)
        {
            label1.Text = e.X.ToString() + ", " + e.Y.ToString();
        }

        private void panel1_MouseLeave(object sender, EventArgs e)
        {
            label1.Text = "";
        }

       
    }
}
