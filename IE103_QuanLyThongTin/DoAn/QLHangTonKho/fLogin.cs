using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace QLHangTonKho
{
    public partial class fLogin : Form
    {
        public fLogin()
        {
            InitializeComponent();
        }

        private void btnExit_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void fLogin_FormClosing(object sender, FormClosingEventArgs e)
        {
            if(MessageBox.Show("Bạn có thật sự muốn thoát chương trình?", "Thông báo", MessageBoxButtons.YesNo) == System.Windows.Forms.DialogResult.No)
            {
               e.Cancel = true;
            }    
        }

        private void btnLogin_Click(object sender, EventArgs e)
        {
            fQLHangTonKho f = new fQLHangTonKho();
            this.Hide();
            f.ShowDialog();
            this.Show();
        }

        private void fLogin_Load(object sender, EventArgs e)
        {

        }
    }
}
