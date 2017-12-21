using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.SqlClient;

namespace emre
{
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
        }

        SqlConnection baglanti = new SqlConnection("Data Source=DESKTOP-GF0OH92;Initial Catalog=Arduino;Integrated Security=True");
        private void btnGiris_Click(object sender, EventArgs e)
        {
            baglanti.Open();
            SqlCommand komut = new SqlCommand("select * from kullanici where kadi='" + textBox1.Text + "' and sifre='" +textBox2.Text + "'", baglanti);
            SqlDataReader dr = komut.ExecuteReader();

            if (dr.Read())
            {
                Form1 frm1 = new Form1();
                frm1.Show();

                this.Hide();
            }
            else
            {
                MessageBox.Show("Kullanıcı Adı veya Şifre Yanlış");
            }
            
            baglanti.Close();
        }
    }
}
