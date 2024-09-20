using QLHangTonKho.DAO;
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
    public partial class fAdmin : Form
    {
        public fAdmin()
        {
            InitializeComponent();

            loadSPList();
        }

        void loadSPList()
        {
            string query = "select * from SANPHAM";
            DataProvider provider = new DataProvider();
            dtgvSP.DataSource = provider.ExecuteQuery(query);
        }

        private void tbSanPham_Click(object sender, EventArgs e)
        {

        }

        private void fAdmin_Load(object sender, EventArgs e)
        {

        }
    }
}
