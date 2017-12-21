using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO.Ports;
using System.Data.SqlClient;

namespace emre
{
    public partial class Form1 : Form
    {
        SerialPort port;
        int sayac = 0;
        public Form1()
        {
            InitializeComponent();

        }

        SqlConnection baglanti = new SqlConnection("Data Source=DESKTOP-GF0OH92;Initial Catalog=Arduino;Integrated Security=True");

        private void button1_Click(object sender, EventArgs e)
        {
            port = new SerialPort();
            string isim = comboBox1.Text;

            if (isim == "COM1" || isim == "COM2" || isim == "COM3" || isim == "COM4" || isim == "COM5" || isim == "COM6")
            {
                port.PortName = isim;
                port.BaudRate = 9600;
                port.Open();
                panel1.Visible = true;
                timer1.Enabled = true;
                panel2.Visible = true;
                if (port.IsOpen)
                {
                    label3.Text = "AÇIK";
                }
            }
            else { MessageBox.Show("Lütfen Port Seçiniz"); }
            button3.BackColor = Color.Red;
            button4.BackColor = Color.Gray;

        }

        private void Form1_Load(object sender, EventArgs e)
        {
            panel1.Visible = false;
            panel2.Visible = false;

        }

        private void button5_Click(object sender, EventArgs e)
        {
            port.Close();
            timer1.Enabled = false;
            panel1.Visible = false;
            label3.Text = "Kapalı";
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            string durum = port.ReadExisting();


            if (durum == "kapali")
            {

                button3.BackColor = Color.Gray;
                button4.BackColor = Color.Gray;
                listBox1.Items.Clear();
                listBox1.Items.Add("Kapı Kapalı");
            }

            if (durum == "a")
            {

                button3.BackColor = Color.Gray;
                button4.BackColor = Color.Green;
                sayac = sayac + 1;
                listBox1.Items.Add(DateTime.Now.ToString());
                baglanti.Open();
                string kayit = "insert into aracGiris(girisTarihi) values (@girisTarihi)";
                SqlCommand komut = new SqlCommand(kayit, baglanti);

                String tarih = Convert.ToString(DateTime.Now);
                komut.Parameters.AddWithValue("@girisTarihi", tarih);
                komut.ExecuteNonQuery();
                baglanti.Close();
            }
            if (durum == "b")
            {
                button3.BackColor = Color.Gray;
                button4.BackColor = Color.Green;
                sayac = sayac - 1;
                listBox2.Items.Add(DateTime.Now.ToString());

                baglanti.Open();
                string kayit2 = "insert into aracCikis(cikisTarihi) values (@cikisTarihi)";
                SqlCommand komut2 = new SqlCommand(kayit2, baglanti);

                String tarih2 = Convert.ToString(DateTime.Now);
                komut2.Parameters.AddWithValue("@cikisTarihi", tarih2);
                komut2.ExecuteNonQuery();
                baglanti.Close();
            }
            if (durum == "ak")
            {

                button3.BackColor = Color.Red;
                button4.BackColor = Color.Gray;

            }
            if (durum == "ka")
            {

                button3.BackColor = Color.Red;
                button4.BackColor = Color.Gray;

            }


            label5.Text = Convert.ToString(sayac);

            if (sayac <= 5)
            {
                label8.Text = "Az Yoğunlıkta";
            }
            else if (5 < sayac && sayac <= 10)
            {
                label8.Text = "Yoğun";
            }
            else if (10 < sayac && sayac < 15)
            {
                label8.Text = "Çok Yoğun";
            }
            else if (sayac == 15)
            {
                label8.Text = "Dolu";
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            listBox3.Items.Clear();
            listBox4.Items.Clear();

            string secili = dateTimePicker1.Value.ToString("dd.MM.yyyy");

          

            SqlCommand command = new SqlCommand("Select * from aracGiris where girisTarihi like '%"+secili+"%'", baglanti);
            
            baglanti.Open();

            SqlDataReader reader = command.ExecuteReader();

            while (reader.Read())
            {
                listBox3.Items.Add(reader["girisTarihi"].ToString());
            }

            baglanti.Close();


            SqlCommand command2 = new SqlCommand("Select * from aracCikis where cikisTarihi like '%"+secili+"%'", baglanti);

            baglanti.Open();

            SqlDataReader reader2 = command2.ExecuteReader();

            while (reader2.Read())
            {
                listBox4.Items.Add(reader2["cikisTarihi"].ToString());
            }
            baglanti.Close();


        }

    }


}